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
enum yytokentype
{
  NAME = 1636,
  UMINUS = 1637,
  COMMA = 1552,
  KW_OR = 1592,
  KW_AND = 1547,
  KW_USING = 1483,
  MATCHES = 1361,
  POWER = 1469,
  LESS_THAN = 1465,
  GREATER_THAN = 1379,
  EQUAL = 1542,
  GREATER_THAN_EQ = 1278,
  LESS_THAN_EQ = 1336,
  NOT_EQUAL = 1410,
  PLUS = 1578,
  MINUS = 1565,
  DIVIDE = 1498,
  MULTIPLY = 1470,
  MOD = 1566,
  COMMAND = 1343,
  NUMBER_VALUE = 1638,
  CHAR_VALUE = 1639,
  INT_VALUE = 1640,
  NAMED_GEN = 1641,
  CLINE = 1642,
  SQLLINE = 1643,
  KW_CSTART = 1644,
  KW_CEND = 1645,
  USER_DTYPE = 1646,
  SQL_TEXT = 1647,
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
  TERMINATE_REPORT = 1015,
  TO_MAIN_CAPTION = 1016,
  CLEARSTAT = 1017,
  TO_MENUITEM = 1018,
  ID_TO_INT = 1019,
  TO_STATUSBOX = 1020,
  ASCII_HEIGHT_ALL = 1021,
  ASCII_WIDTH_ALL = 1022,
  IMPORT_DATATYPE = 1023,
  UP_BY = 1024,
  PAGE_TRAILER_SIZE = 1025,
  PAGE_HEADER_SIZE = 1026,
  FIRST_PAGE_HEADER_SIZE = 1027,
  BYTES_USE_AS_IMAGE = 1028,
  BYTES_USE_AS_ASCII = 1029,
  DOWN_BY = 1030,
  CLOSE_STATUSBOX = 1031,
  MODIFY_NEXT_SIZE = 1032,
  LOCK_MODE_PAGE = 1033,
  LOCK_MODE_ROW = 1034,
  TO_PIPE = 1035,
  TO_PRINTER = 1036,
  STATUSBOX = 1037,
  CONNECT_TO = 1038,
  FORMHANDLER_INPUT = 1039,
  UNITS_YEAR = 1040,
  UNITS_MONTH = 1041,
  UNITS_DAY = 1042,
  UNITS_HOUR = 1043,
  UNITS_MINUTE = 1044,
  UNITS_SECOND = 1045,
  NO_NEW_LINES = 1046,
  FIELDTOWIDGET = 1047,
  WITH_HOLD = 1048,
  SHOW_MENU = 1049,
  CWIS = 1050,
  CREATE_IDX = 1051,
  FORM_IS_COMPILED = 1052,
  PDF_REPORT = 1053,
  IMPORT_FUNCTION = 1054,
  PROMPT_MANY = 1055,
  POINTS = 1056,
  MM = 1057,
  INCHES = 1058,
  PREPEND = 1059,
  MEMBER_OF = 1060,
  MEMBER_FUNCTION = 1061,
  APPEND = 1062,
  TEMPLATE = 1063,
  END_TEMPLATE = 1064,
  SQLSICS = 1065,
  CREATE_SCHEMA = 1066,
  SQLSIRR = 1067,
  UPDATESTATS_T = 1068,
  SQLSICR = 1069,
  WHENEVER_SQLSUCCESS = 1070,
  WHENEVER_SQLWARNING = 1071,
  START_EXTERN = 1072,
  WHENEVER_ANY_ERROR = 1073,
  WHENEVER_NOT_FOUND = 1074,
  CONTINUE_CONSTRUCT = 1075,
  FOUNCONSTR = 1076,
  SQLSIDR = 1077,
  WHENEVER_SQLERROR = 1078,
  CREATE_TEMP_TABLE = 1079,
  CURRENT_WINDOW_IS = 1080,
  FIRST_PAGE_HEADER = 1081,
  ORDER_EXTERNAL_BY = 1082,
  SCROLL_CURSOR_FOR = 1083,
  SCROLL_CURSOR = 1084,
  SQL_INTERRUPT_OFF = 1085,
  STOP_ALL_EXTERNAL = 1086,
  WITH_CHECK_OPTION = 1087,
  WITH_GRANT_OPTION = 1088,
  SQLSLMNW = 1089,
  ADDCONSTUNIQ = 1090,
  CONTINUE_DISPLAY = 1091,
  CONTINUE_FOREACH = 1092,
  OUTPUT_TO_REPORT = 1093,
  SQL_INTERRUPT_ON = 1094,
  WHENEVER_SUCCESS = 1095,
  WHENEVER_WARNING = 1096,
  WHERE_CURRENT_OF = 1097,
  WITHOUT_DEFAULTS = 1098,
  FOCONSTR = 1099,
  SCALED_BY = 1100,
  CONTINUE_PROMPT = 1101,
  PDF_FUNCTION = 1102,
  DEFER_INTERRUPT = 1103,
  DISPLAY_BY_NAME = 1104,
  NOT_NULL_UNIQUE = 1105,
  SKIP_TO_TOP = 1106,
  TOP_OF_PAGE = 1107,
  SKIP_TO = 1108,
  SKIP_BY = 1109,
  WITHOUT_WAITING = 1110,
  BEFCONSTRUCT = 1111,
  SQLSLMW = 1112,
  WHENEVER_ERROR_CONTINUE = 1113,
  WHENEVER_ERROR = 1114,
  AFTCONSTRUCT = 1115,
  ALL_PRIVILEGES = 1116,
  CLOSE_DATABASE = 1117,
  CONTINUE_INPUT = 1118,
  CONTINUE_WHILE = 1119,
  CREATE_SYNONYM = 1120,
  DROP_TABLE = 1121,
  EXIT_CONSTRUCT = 1122,
  INEXCLUSIVE = 1123,
  REPORT_TO_PRINTER = 1124,
  REPORT_TO_PIPE = 1125,
  SET_SESSION_TO = 1126,
  UPDATESTATS = 1127,
  WITHOUT_HEAD = 1128,
  CLEARSCR = 1129,
  WITH_B_LOG = 1130,
  AUTHORIZATION = 1131,
  BOTTOM_MARGIN = 1132,
  CLOSE_SESSION = 1133,
  CONTINUE_CASE = 1134,
  CONTINUE_MENU = 1135,
  DISPLAY_ARRAY = 1136,
  END_SQL = 1137,
  DOLLAR = 1138,
  END_CONSTRUCT = 1139,
  FIELD_TOUCHED = 1140,
  FINISH_REPORT = 1141,
  INFACC = 1142,
  INPUT_NO_WRAP = 1143,
  LOCKMODEPAGE = 1144,
  SETPMOFF = 1145,
  UNCONSTRAINED = 1146,
  PAGE_TRAILER = 1147,
  SETPMON = 1148,
  BEFGROUP = 1149,
  CLOSE_WINDOW = 1150,
  COMMENT_LINE = 1151,
  CONTINUE_FOR = 1152,
  CREATE_DB = 1153,
  CREATE_TABLE = 1154,
  DEFAULT_NULL = 1155,
  DELETE_USING = 1156,
  DISPLAY_FORM = 1157,
  END_FUNCTION = 1158,
  EXIT_DISPLAY = 1159,
  EXIT_FOREACH = 1160,
  EXIT_PROGRAM = 1161,
  INFCOLS = 1162,
  LOCKMODEROW = 1163,
  ON_EVERY_ROW = 1164,
  OPEN_SESSION = 1165,
  RIGHT_MARGIN = 1166,
  SELECT_USING = 1167,
  START_REPORT = 1168,
  UNLOCK_TABLE = 1169,
  UPDATE_USING = 1170,
  ACL_BUILTIN = 1171,
  AFTGROUP = 1172,
  INFIDX = 1173,
  INFSTAT = 1174,
  LEFT_MARGIN = 1175,
  PAGE_HEADER = 1176,
  ROLLBACK_W = 1177,
  SET_SESSION = 1178,
  SQLSEOFF = 1179,
  WITH_A_LOG = 1180,
  BEFDISP = 1181,
  BEFORE_MENU = 1182,
  CREATE_VIEW = 1183,
  DEFINE_TYPE = 1184,
  DELETE_FROM = 1185,
  END_DISPLAY = 1186,
  END_REPORT = 1187,
  END_FOREACH = 1188,
  END_FOR = 1189,
  END_GLOBALS = 1190,
  EXIT_PROMPT = 1191,
  EXTENT_SIZE = 1192,
  FOREIGN_KEY = 1193,
  HIDE_OPTION = 1194,
  HIDE_WINDOW = 1195,
  INSERT_INTO = 1196,
  IS_NOT_NULL = 1197,
  MOVE_WINDOW = 1198,
  NEXT_OPTION = 1199,
  NOT_MATCHES = 1200,
  ON_LAST_ROW = 1201,
  OPEN_WINDOW = 1202,
  OPEN_STATUSBOX = 1203,
  PAGE_LENGTH = 1204,
  PAGE_WIDTH = 1205,
  PRIMARY_KEY = 1206,
  PROMPT_LINE = 1207,
  RECORD_LIKE = 1208,
  ROLLFORWARD = 1209,
  SETBL = 1210,
  SHOW_OPTION = 1211,
  SHOW_WINDOW = 1212,
  SQLSEON = 1213,
  TO_DATABASE = 1214,
  USE_SESSION = 1215,
  WITH_NO_LOG = 1216,
  AFTDISP = 1217,
  BEFFIELD = 1218,
  INSHARE = 1219,
  UNLOCKTAB = 1220,
  AFTFIELD = 1221,
  ATTRIBUTES = 1222,
  BEFINP = 1223,
  BEGIN_WORK = 1224,
  CLEARWIN = 1225,
  CLOSE_FORM = 1226,
  DEFER_QUIT = 1227,
  DESCENDING = 1228,
  DROP_INDEX = 1229,
  END_PROMPT = 1230,
  END_RECORD = 1231,
  ERROR_LINE = 1232,
  EXIT_INPUT = 1233,
  EXIT_WHILE = 1234,
  FOR_UPDATE_OF = 1235,
  FOR_UPDATE = 1236,
  GET_FLDBUF = 1237,
  INITIALIZE = 1238,
  INPUT_WRAP = 1239,
  LOCK_TABLE = 1240,
  MSG_LINE = 1241,
  NOT_EXISTS = 1242,
  ON_ANY_KEY = 1243,
  REFERENCES = 1244,
  RENCOL = 1245,
  SET_CURSOR = 1246,
  SMALLFLOAT = 1247,
  SQLSUCCESS = 1248,
  TOP_MARGIN = 1249,
  WITH_ARRAY = 1250,
  ACCEPTKEY = 1251,
  ACCEPT = 1252,
  AFTINP = 1253,
  CLEARFORMTODEFAULTS = 1254,
  CLEARFORM = 1255,
  CLEAR_X_FORM = 1256,
  COMMIT_W = 1257,
  NEXTPAGE = 1258,
  PREVPAGE = 1259,
  CTRL_KEY = 1260,
  INFTABS = 1261,
  NEXTFIELD = 1262,
  NEXTFORM = 1263,
  RENTAB = 1264,
  ASCENDING = 1265,
  ASSOCIATE = 1266,
  CHARACTER = 1267,
  CONSTRUCT = 1268,
  DELIMITER = 1269,
  DOWNSHIFT = 1270,
  DROP_VIEW = 1271,
  END_INPUT = 1272,
  END_WHILE = 1273,
  EXCLUSIVE = 1274,
  EXIT_CASE = 1275,
  EXIT_MENU = 1276,
  FORM_LINE = 1277,
  INTERRUPT = 1279,
  INTO_TEMP = 1280,
  INVISIBLE = 1281,
  IN_MEMORY = 1282,
  LINKED_TO = 1283,
  LOAD_FROM = 1284,
  LOCKTAB = 1285,
  MENU_LINE = 1286,
  OPEN_FORM = 1287,
  OTHERWISE = 1288,
  PRECISION = 1289,
  PRIOR = 1290,
  PROCEDURE = 1291,
  REPORT_TO = 1292,
  RETURNING = 1293,
  UNDERLINE = 1294,
  UNLOAD_TO = 1295,
  BEFROW = 1296,
  UNLOAD_T = 1297,
  VARIABLE = 1298,
  ABSOLUTE = 1299,
  AFTROW = 1300,
  BUFFERED = 1301,
  CONSTANT = 1302,
  CONST = 1303,
  CONTINUE = 1304,
  DATABASE = 1305,
  DATETIME = 1306,
  DEFAULTS = 1307,
  DISTINCT = 1308,
  END_CASE = 1309,
  END_MAIN = 1310,
  END_MENU = 1311,
  END_TYPE = 1312,
  EXIT_FOR = 1313,
  EXTERNAL = 1314,
  FRACTION = 1315,
  FUNCTION = 1316,
  GROUP_BY = 1317,
  INTERVAL = 1318,
  KWMESSAGE = 1319,
  NOT_LIKE = 1320,
  NOT_NULL = 1321,
  PASSWORD = 1322,
  PREVIOUS = 1323,
  READONLY = 1324,
  REGISTER = 1325,
  RELATIVE = 1326,
  RESOURCE = 1327,
  SMALLINT = 1328,
  VALIDATE = 1329,
  WHENEVER = 1330,
  WITH_LOG = 1331,
  WORDWRAP = 1332,
  BY_NAME = 1333,
  IN_FILE = 1334,
  IS_NULL = 1335,
  AVERAGE = 1337,
  BETWEEN = 1338,
  CAPTION = 1339,
  CLIPPED = 1340,
  CLOSE_BRACKET = 1341,
  COLUMNS = 1342,
  COMMENT = 1344,
  CONNECT = 1345,
  CURRENT = 1346,
  DBYNAME = 1347,
  DECIMAL = 1348,
  DECLARE = 1349,
  DEFAULT = 1350,
  DISPLAY = 1351,
  ENDCODE = 1352,
  EXECUTE = 1353,
  FOREACH = 1354,
  FOREIGN = 1355,
  GLOBALS = 1356,
  INFIELD = 1357,
  INTEGER = 1358,
  KWWINDOW = 1359,
  MAGENTA = 1360,
  NUMERIC = 1362,
  OPTIONS = 1363,
  PERCENT = 1364,
  PREPARE = 1365,
  PROGRAM = 1366,
  RECOVER = 1367,
  REVERSE = 1368,
  SECTION = 1369,
  SESSION = 1370,
  SYNONYM = 1371,
  THRU = 1372,
  TRAILER = 1373,
  UPSHIFT = 1374,
  VARCHAR = 1375,
  WAITING = 1376,
  CLOSE_SHEV = 1377,
  CLOSE_SQUARE = 1378,
  KW_FALSE = 1380,
  NOT_IN = 1381,
  ONKEY = 1382,
  OPEN_BRACKET = 1383,
  BORDER = 1384,
  BOTTOM = 1385,
  COLUMN = 1386,
  COMMIT = 1387,
  CREATE = 1388,
  CURSOR = 1389,
  DEFINE = 1390,
  DELETE = 1391,
  DOUBLE = 1392,
  END_IF = 1393,
  ESCAPE = 1394,
  EXISTS = 1395,
  EXTEND = 1396,
  EXTENT = 1397,
  FINISH = 1398,
  FORMAT = 1399,
  HAVING = 1400,
  HEADER = 1401,
  INSERT = 1402,
  LOCATE = 1403,
  MARGIN = 1404,
  MEMORY = 1405,
  MINUTE = 1406,
  MODIFY = 1407,
  NORMAL = 1408,
  EQUAL_EQUAL = 1409,
  OPEN_SHEV = 1411,
  OPEN_SQUARE = 1412,
  OPTION = 1413,
  OUTPUT = 1414,
  PROMPT = 1415,
  PUBLIC = 1416,
  RECORD = 1417,
  REPORT = 1418,
  RETURN = 1419,
  REVOKE = 1420,
  SCHEMA = 1421,
  SCROLL_USING = 1422,
  SCROLL = 1423,
  SECOND = 1424,
  SELECT = 1425,
  SERIAL = 1426,
  SETL = 1427,
  SHARED = 1428,
  SPACES = 1429,
  UNIQUE = 1430,
  UNLOCK = 1431,
  UPDATE = 1432,
  VALUES = 1433,
  YELLOW = 1434,
  AFTER = 1435,
  KWLINE = 1436,
  KW_NULL = 1437,
  KW_TRUE = 1438,
  SINGLE_KEY = 1439,
  ALTER = 1440,
  ARRAY = 1441,
  ASCII = 1442,
  AUDIT = 1443,
  BLACK = 1444,
  BLINK = 1445,
  CHECK = 1446,
  CLEAR = 1447,
  CLOSE = 1448,
  CODE_C = 1449,
  COUNT = 1450,
  DEFER = 1451,
  ERROR = 1452,
  EVERY = 1453,
  FETCH = 1454,
  FIRST = 1455,
  FLOAT = 1456,
  FLUSH = 1457,
  FOUND = 1458,
  GRANT = 1459,
  GREEN = 1460,
  GROUP = 1461,
  INDEX = 1462,
  KWFORM = 1463,
  LABEL = 1464,
  LOCAL = 1466,
  MONEY = 1467,
  MONTH = 1468,
  ORDER = 1471,
  OUTER = 1472,
  PAUSE = 1473,
  PRINT_IMAGE = 1474,
  PRINT_FILE = 1475,
  PRINT = 1476,
  RIGHT = 1477,
  DOUBLE_COLON = 1478,
  SEMICOLON = 1479,
  SLEEP = 1480,
  TUPLE = 1481,
  UNION = 1482,
  WHERE = 1484,
  WHILE = 1485,
  WHITE = 1486,
  CCODE = 1487,
  ANSI = 1488,
  BLUE = 1489,
  BOLD = 1490,
  BYTE = 1491,
  FCALL = 1492,
  CASE = 1493,
  CHAR = 1494,
  CYAN = 1495,
  DATE = 1496,
  DESC = 1497,
  DOWN = 1499,
  TAB = 1500,
  DROP = 1501,
  ELSE = 1502,
  EXEC = 1503,
  EXIT = 1504,
  FREE = 1505,
  FROM = 1506,
  GOTO = 1507,
  HELP_FILE = 1508,
  LANG_FILE = 1509,
  HELP = 1510,
  HIDE = 1511,
  HOUR = 1512,
  INTO = 1513,
  LAST = 1514,
  LEFT = 1515,
  LIKE = 1516,
  MAIN = 1517,
  MENU = 1518,
  MODE = 1519,
  NEED = 1520,
  NEXT = 1521,
  NOCR = 1522,
  OPEN = 1523,
  QUIT = 1524,
  REAL = 1525,
  ROWS = 1526,
  SHOW = 1527,
  SIZE = 1528,
  SKIP = 1529,
  SOME = 1530,
  STEP = 1531,
  STOP = 1532,
  TEMP = 1533,
  TEXT = 1534,
  THEN = 1535,
  USER = 1536,
  WAIT = 1537,
  WHEN = 1538,
  WITH = 1539,
  WORK = 1540,
  YEAR = 1541,
  KW_IS = 1543,
  XSET = 1544,
  ADD = 1545,
  ALL = 1546,
  ANY = 1548,
  ASC = 1549,
  AVG = 1550,
  COLON = 1551,
  DAY = 1553,
  DBA = 1554,
  DEC = 1555,
  DIM = 1556,
  FKEY = 1557,
  FOR = 1558,
  KEY = 1559,
  KWNO = 1560,
  LET = 1561,
  LOG = 1562,
  XMAX = 1563,
  XMIN = 1564,
  NOT = 1567,
  PAD = 1568,
  PUT = 1569,
  RED = 1570,
  ROW = 1571,
  RUN = 1572,
  SQL = 1573,
  SUM = 1574,
  TOP = 1575,
  USE = 1576,
  ATSIGN = 1577,
  AS_TIFF = 1579,
  AS_GIF = 1580,
  AS_PNG = 1581,
  AS_JPEG = 1582,
  AS = 1583,
  AT = 1584,
  BY = 1585,
  DOT = 1586,
  GO = 1587,
  IF = 1588,
  IN = 1589,
  OF = 1590,
  ON = 1591,
  TO = 1593,
  UP = 1594,
  FONT_NAME = 1595,
  FONT_SIZE = 1596,
  PAPER_SIZE_IS_LETTER = 1597,
  PAPER_SIZE_IS_LEGAL = 1598,
  PAPER_SIZE_IS_A5 = 1599,
  PAPER_SIZE_IS_A4 = 1600,
  PAPER_SIZE_IS_LETTER_L = 1601,
  PAPER_SIZE_IS_LEGAL_L = 1602,
  PAPER_SIZE_IS_A5_L = 1603,
  PAPER_SIZE_IS_A4_L = 1604,
  FORMHANDLER = 1605,
  END_FORMHANDLER = 1606,
  BEFORE_EVENT = 1607,
  BEFORE_OPEN_FORM = 1608,
  AFTER_EVENT = 1609,
  BEFORE_CLOSE_FORM = 1610,
  BEFORE_ANY = 1611,
  AFTER_ANY = 1612,
  MENUHANDLER = 1613,
  END_MENUHANDLER = 1614,
  BEFORE_SHOW_MENU = 1615,
  DISABLE_PROGRAM = 1616,
  DISABLE_ALL = 1617,
  BUTTONS = 1618,
  CHECK_MENUITEM = 1619,
  DISABLE_FORM = 1620,
  DISABLE_MENUITEMS = 1621,
  DISABLE = 1622,
  ENABLE_FORM = 1623,
  ENABLE_MENUITEMS = 1624,
  ENABLE = 1625,
  KWFIELD = 1626,
  ICON = 1627,
  MESSAGEBOX = 1628,
  TO_DEFAULTS = 1629,
  UNCHECK_MENUITEM = 1630,
  BEFORE = 1631,
  INPUT = 1632,
  END = 1633,
  INT_TO_ID = 1634
};
#endif
#define NAME 1636
#define UMINUS 1637
#define COMMA 1552
#define KW_OR 1592
#define KW_AND 1547
#define KW_USING 1483
#define MATCHES 1361
#define POWER 1469
#define LESS_THAN 1465
#define GREATER_THAN 1379
#define EQUAL 1542
#define GREATER_THAN_EQ 1278
#define LESS_THAN_EQ 1336
#define NOT_EQUAL 1410
#define PLUS 1578
#define MINUS 1565
#define DIVIDE 1498
#define MULTIPLY 1470
#define MOD 1566
#define COMMAND 1343
#define NUMBER_VALUE 1638
#define CHAR_VALUE 1639
#define INT_VALUE 1640
#define NAMED_GEN 1641
#define CLINE 1642
#define SQLLINE 1643
#define KW_CSTART 1644
#define KW_CEND 1645
#define USER_DTYPE 1646
#define SQL_TEXT 1647
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
#define TERMINATE_REPORT 1015
#define TO_MAIN_CAPTION 1016
#define CLEARSTAT 1017
#define TO_MENUITEM 1018
#define ID_TO_INT 1019
#define TO_STATUSBOX 1020
#define ASCII_HEIGHT_ALL 1021
#define ASCII_WIDTH_ALL 1022
#define IMPORT_DATATYPE 1023
#define UP_BY 1024
#define PAGE_TRAILER_SIZE 1025
#define PAGE_HEADER_SIZE 1026
#define FIRST_PAGE_HEADER_SIZE 1027
#define BYTES_USE_AS_IMAGE 1028
#define BYTES_USE_AS_ASCII 1029
#define DOWN_BY 1030
#define CLOSE_STATUSBOX 1031
#define MODIFY_NEXT_SIZE 1032
#define LOCK_MODE_PAGE 1033
#define LOCK_MODE_ROW 1034
#define TO_PIPE 1035
#define TO_PRINTER 1036
#define STATUSBOX 1037
#define CONNECT_TO 1038
#define FORMHANDLER_INPUT 1039
#define UNITS_YEAR 1040
#define UNITS_MONTH 1041
#define UNITS_DAY 1042
#define UNITS_HOUR 1043
#define UNITS_MINUTE 1044
#define UNITS_SECOND 1045
#define NO_NEW_LINES 1046
#define FIELDTOWIDGET 1047
#define WITH_HOLD 1048
#define SHOW_MENU 1049
#define CWIS 1050
#define CREATE_IDX 1051
#define FORM_IS_COMPILED 1052
#define PDF_REPORT 1053
#define IMPORT_FUNCTION 1054
#define PROMPT_MANY 1055
#define POINTS 1056
#define MM 1057
#define INCHES 1058
#define PREPEND 1059
#define MEMBER_OF 1060
#define MEMBER_FUNCTION 1061
#define APPEND 1062
#define TEMPLATE 1063
#define END_TEMPLATE 1064
#define SQLSICS 1065
#define CREATE_SCHEMA 1066
#define SQLSIRR 1067
#define UPDATESTATS_T 1068
#define SQLSICR 1069
#define WHENEVER_SQLSUCCESS 1070
#define WHENEVER_SQLWARNING 1071
#define START_EXTERN 1072
#define WHENEVER_ANY_ERROR 1073
#define WHENEVER_NOT_FOUND 1074
#define CONTINUE_CONSTRUCT 1075
#define FOUNCONSTR 1076
#define SQLSIDR 1077
#define WHENEVER_SQLERROR 1078
#define CREATE_TEMP_TABLE 1079
#define CURRENT_WINDOW_IS 1080
#define FIRST_PAGE_HEADER 1081
#define ORDER_EXTERNAL_BY 1082
#define SCROLL_CURSOR_FOR 1083
#define SCROLL_CURSOR 1084
#define SQL_INTERRUPT_OFF 1085
#define STOP_ALL_EXTERNAL 1086
#define WITH_CHECK_OPTION 1087
#define WITH_GRANT_OPTION 1088
#define SQLSLMNW 1089
#define ADDCONSTUNIQ 1090
#define CONTINUE_DISPLAY 1091
#define CONTINUE_FOREACH 1092
#define OUTPUT_TO_REPORT 1093
#define SQL_INTERRUPT_ON 1094
#define WHENEVER_SUCCESS 1095
#define WHENEVER_WARNING 1096
#define WHERE_CURRENT_OF 1097
#define WITHOUT_DEFAULTS 1098
#define FOCONSTR 1099
#define SCALED_BY 1100
#define CONTINUE_PROMPT 1101
#define PDF_FUNCTION 1102
#define DEFER_INTERRUPT 1103
#define DISPLAY_BY_NAME 1104
#define NOT_NULL_UNIQUE 1105
#define SKIP_TO_TOP 1106
#define TOP_OF_PAGE 1107
#define SKIP_TO 1108
#define SKIP_BY 1109
#define WITHOUT_WAITING 1110
#define BEFCONSTRUCT 1111
#define SQLSLMW 1112
#define WHENEVER_ERROR_CONTINUE 1113
#define WHENEVER_ERROR 1114
#define AFTCONSTRUCT 1115
#define ALL_PRIVILEGES 1116
#define CLOSE_DATABASE 1117
#define CONTINUE_INPUT 1118
#define CONTINUE_WHILE 1119
#define CREATE_SYNONYM 1120
#define DROP_TABLE 1121
#define EXIT_CONSTRUCT 1122
#define INEXCLUSIVE 1123
#define REPORT_TO_PRINTER 1124
#define REPORT_TO_PIPE 1125
#define SET_SESSION_TO 1126
#define UPDATESTATS 1127
#define WITHOUT_HEAD 1128
#define CLEARSCR 1129
#define WITH_B_LOG 1130
#define AUTHORIZATION 1131
#define BOTTOM_MARGIN 1132
#define CLOSE_SESSION 1133
#define CONTINUE_CASE 1134
#define CONTINUE_MENU 1135
#define DISPLAY_ARRAY 1136
#define END_SQL 1137
#define DOLLAR 1138
#define END_CONSTRUCT 1139
#define FIELD_TOUCHED 1140
#define FINISH_REPORT 1141
#define INFACC 1142
#define INPUT_NO_WRAP 1143
#define LOCKMODEPAGE 1144
#define SETPMOFF 1145
#define UNCONSTRAINED 1146
#define PAGE_TRAILER 1147
#define SETPMON 1148
#define BEFGROUP 1149
#define CLOSE_WINDOW 1150
#define COMMENT_LINE 1151
#define CONTINUE_FOR 1152
#define CREATE_DB 1153
#define CREATE_TABLE 1154
#define DEFAULT_NULL 1155
#define DELETE_USING 1156
#define DISPLAY_FORM 1157
#define END_FUNCTION 1158
#define EXIT_DISPLAY 1159
#define EXIT_FOREACH 1160
#define EXIT_PROGRAM 1161
#define INFCOLS 1162
#define LOCKMODEROW 1163
#define ON_EVERY_ROW 1164
#define OPEN_SESSION 1165
#define RIGHT_MARGIN 1166
#define SELECT_USING 1167
#define START_REPORT 1168
#define UNLOCK_TABLE 1169
#define UPDATE_USING 1170
#define ACL_BUILTIN 1171
#define AFTGROUP 1172
#define INFIDX 1173
#define INFSTAT 1174
#define LEFT_MARGIN 1175
#define PAGE_HEADER 1176
#define ROLLBACK_W 1177
#define SET_SESSION 1178
#define SQLSEOFF 1179
#define WITH_A_LOG 1180
#define BEFDISP 1181
#define BEFORE_MENU 1182
#define CREATE_VIEW 1183
#define DEFINE_TYPE 1184
#define DELETE_FROM 1185
#define END_DISPLAY 1186
#define END_REPORT 1187
#define END_FOREACH 1188
#define END_FOR 1189
#define END_GLOBALS 1190
#define EXIT_PROMPT 1191
#define EXTENT_SIZE 1192
#define FOREIGN_KEY 1193
#define HIDE_OPTION 1194
#define HIDE_WINDOW 1195
#define INSERT_INTO 1196
#define IS_NOT_NULL 1197
#define MOVE_WINDOW 1198
#define NEXT_OPTION 1199
#define NOT_MATCHES 1200
#define ON_LAST_ROW 1201
#define OPEN_WINDOW 1202
#define OPEN_STATUSBOX 1203
#define PAGE_LENGTH 1204
#define PAGE_WIDTH 1205
#define PRIMARY_KEY 1206
#define PROMPT_LINE 1207
#define RECORD_LIKE 1208
#define ROLLFORWARD 1209
#define SETBL 1210
#define SHOW_OPTION 1211
#define SHOW_WINDOW 1212
#define SQLSEON 1213
#define TO_DATABASE 1214
#define USE_SESSION 1215
#define WITH_NO_LOG 1216
#define AFTDISP 1217
#define BEFFIELD 1218
#define INSHARE 1219
#define UNLOCKTAB 1220
#define AFTFIELD 1221
#define ATTRIBUTES 1222
#define BEFINP 1223
#define BEGIN_WORK 1224
#define CLEARWIN 1225
#define CLOSE_FORM 1226
#define DEFER_QUIT 1227
#define DESCENDING 1228
#define DROP_INDEX 1229
#define END_PROMPT 1230
#define END_RECORD 1231
#define ERROR_LINE 1232
#define EXIT_INPUT 1233
#define EXIT_WHILE 1234
#define FOR_UPDATE_OF 1235
#define FOR_UPDATE 1236
#define GET_FLDBUF 1237
#define INITIALIZE 1238
#define INPUT_WRAP 1239
#define LOCK_TABLE 1240
#define MSG_LINE 1241
#define NOT_EXISTS 1242
#define ON_ANY_KEY 1243
#define REFERENCES 1244
#define RENCOL 1245
#define SET_CURSOR 1246
#define SMALLFLOAT 1247
#define SQLSUCCESS 1248
#define TOP_MARGIN 1249
#define WITH_ARRAY 1250
#define ACCEPTKEY 1251
#define ACCEPT 1252
#define AFTINP 1253
#define CLEARFORMTODEFAULTS 1254
#define CLEARFORM 1255
#define CLEAR_X_FORM 1256
#define COMMIT_W 1257
#define NEXTPAGE 1258
#define PREVPAGE 1259
#define CTRL_KEY 1260
#define INFTABS 1261
#define NEXTFIELD 1262
#define NEXTFORM 1263
#define RENTAB 1264
#define ASCENDING 1265
#define ASSOCIATE 1266
#define CHARACTER 1267
#define CONSTRUCT 1268
#define DELIMITER 1269
#define DOWNSHIFT 1270
#define DROP_VIEW 1271
#define END_INPUT 1272
#define END_WHILE 1273
#define EXCLUSIVE 1274
#define EXIT_CASE 1275
#define EXIT_MENU 1276
#define FORM_LINE 1277
#define INTERRUPT 1279
#define INTO_TEMP 1280
#define INVISIBLE 1281
#define IN_MEMORY 1282
#define LINKED_TO 1283
#define LOAD_FROM 1284
#define LOCKTAB 1285
#define MENU_LINE 1286
#define OPEN_FORM 1287
#define OTHERWISE 1288
#define PRECISION 1289
#define PRIOR 1290
#define PROCEDURE 1291
#define REPORT_TO 1292
#define RETURNING 1293
#define UNDERLINE 1294
#define UNLOAD_TO 1295
#define BEFROW 1296
#define UNLOAD_T 1297
#define VARIABLE 1298
#define ABSOLUTE 1299
#define AFTROW 1300
#define BUFFERED 1301
#define CONSTANT 1302
#define CONST 1303
#define CONTINUE 1304
#define DATABASE 1305
#define DATETIME 1306
#define DEFAULTS 1307
#define DISTINCT 1308
#define END_CASE 1309
#define END_MAIN 1310
#define END_MENU 1311
#define END_TYPE 1312
#define EXIT_FOR 1313
#define EXTERNAL 1314
#define FRACTION 1315
#define FUNCTION 1316
#define GROUP_BY 1317
#define INTERVAL 1318
#define KWMESSAGE 1319
#define NOT_LIKE 1320
#define NOT_NULL 1321
#define PASSWORD 1322
#define PREVIOUS 1323
#define READONLY 1324
#define REGISTER 1325
#define RELATIVE 1326
#define RESOURCE 1327
#define SMALLINT 1328
#define VALIDATE 1329
#define WHENEVER 1330
#define WITH_LOG 1331
#define WORDWRAP 1332
#define BY_NAME 1333
#define IN_FILE 1334
#define IS_NULL 1335
#define AVERAGE 1337
#define BETWEEN 1338
#define CAPTION 1339
#define CLIPPED 1340
#define CLOSE_BRACKET 1341
#define COLUMNS 1342
#define COMMENT 1344
#define CONNECT 1345
#define CURRENT 1346
#define DBYNAME 1347
#define DECIMAL 1348
#define DECLARE 1349
#define DEFAULT 1350
#define DISPLAY 1351
#define ENDCODE 1352
#define EXECUTE 1353
#define FOREACH 1354
#define FOREIGN 1355
#define GLOBALS 1356
#define INFIELD 1357
#define INTEGER 1358
#define KWWINDOW 1359
#define MAGENTA 1360
#define NUMERIC 1362
#define OPTIONS 1363
#define PERCENT 1364
#define PREPARE 1365
#define PROGRAM 1366
#define RECOVER 1367
#define REVERSE 1368
#define SECTION 1369
#define SESSION 1370
#define SYNONYM 1371
#define THRU 1372
#define TRAILER 1373
#define UPSHIFT 1374
#define VARCHAR 1375
#define WAITING 1376
#define CLOSE_SHEV 1377
#define CLOSE_SQUARE 1378
#define KW_FALSE 1380
#define NOT_IN 1381
#define ONKEY 1382
#define OPEN_BRACKET 1383
#define BORDER 1384
#define BOTTOM 1385
#define COLUMN 1386
#define COMMIT 1387
#define CREATE 1388
#define CURSOR 1389
#define DEFINE 1390
#define DELETE 1391
#define DOUBLE 1392
#define END_IF 1393
#define ESCAPE 1394
#define EXISTS 1395
#define EXTEND 1396
#define EXTENT 1397
#define FINISH 1398
#define FORMAT 1399
#define HAVING 1400
#define HEADER 1401
#define INSERT 1402
#define LOCATE 1403
#define MARGIN 1404
#define MEMORY 1405
#define MINUTE 1406
#define MODIFY 1407
#define NORMAL 1408
#define EQUAL_EQUAL 1409
#define OPEN_SHEV 1411
#define OPEN_SQUARE 1412
#define OPTION 1413
#define OUTPUT 1414
#define PROMPT 1415
#define PUBLIC 1416
#define RECORD 1417
#define REPORT 1418
#define RETURN 1419
#define REVOKE 1420
#define SCHEMA 1421
#define SCROLL_USING 1422
#define SCROLL 1423
#define SECOND 1424
#define SELECT 1425
#define SERIAL 1426
#define SETL 1427
#define SHARED 1428
#define SPACES 1429
#define UNIQUE 1430
#define UNLOCK 1431
#define UPDATE 1432
#define VALUES 1433
#define YELLOW 1434
#define AFTER 1435
#define KWLINE 1436
#define KW_NULL 1437
#define KW_TRUE 1438
#define SINGLE_KEY 1439
#define ALTER 1440
#define ARRAY 1441
#define ASCII 1442
#define AUDIT 1443
#define BLACK 1444
#define BLINK 1445
#define CHECK 1446
#define CLEAR 1447
#define CLOSE 1448
#define CODE_C 1449
#define COUNT 1450
#define DEFER 1451
#define ERROR 1452
#define EVERY 1453
#define FETCH 1454
#define FIRST 1455
#define FLOAT 1456
#define FLUSH 1457
#define FOUND 1458
#define GRANT 1459
#define GREEN 1460
#define GROUP 1461
#define INDEX 1462
#define KWFORM 1463
#define LABEL 1464
#define LOCAL 1466
#define MONEY 1467
#define MONTH 1468
#define ORDER 1471
#define OUTER 1472
#define PAUSE 1473
#define PRINT_IMAGE 1474
#define PRINT_FILE 1475
#define PRINT 1476
#define RIGHT 1477
#define DOUBLE_COLON 1478
#define SEMICOLON 1479
#define SLEEP 1480
#define TUPLE 1481
#define UNION 1482
#define WHERE 1484
#define WHILE 1485
#define WHITE 1486
#define CCODE 1487
#define ANSI 1488
#define BLUE 1489
#define BOLD 1490
#define BYTE 1491
#define FCALL 1492
#define CASE 1493
#define CHAR 1494
#define CYAN 1495
#define DATE 1496
#define DESC 1497
#define DOWN 1499
#define TAB 1500
#define DROP 1501
#define ELSE 1502
#define EXEC 1503
#define EXIT 1504
#define FREE 1505
#define FROM 1506
#define GOTO 1507
#define HELP_FILE 1508
#define LANG_FILE 1509
#define HELP 1510
#define HIDE 1511
#define HOUR 1512
#define INTO 1513
#define LAST 1514
#define LEFT 1515
#define LIKE 1516
#define MAIN 1517
#define MENU 1518
#define MODE 1519
#define NEED 1520
#define NEXT 1521
#define NOCR 1522
#define OPEN 1523
#define QUIT 1524
#define REAL 1525
#define ROWS 1526
#define SHOW 1527
#define SIZE 1528
#define SKIP 1529
#define SOME 1530
#define STEP 1531
#define STOP 1532
#define TEMP 1533
#define TEXT 1534
#define THEN 1535
#define USER 1536
#define WAIT 1537
#define WHEN 1538
#define WITH 1539
#define WORK 1540
#define YEAR 1541
#define KW_IS 1543
#define XSET 1544
#define ADD 1545
#define ALL 1546
#define ANY 1548
#define ASC 1549
#define AVG 1550
#define COLON 1551
#define DAY 1553
#define DBA 1554
#define DEC 1555
#define DIM 1556
#define FKEY 1557
#define FOR 1558
#define KEY 1559
#define KWNO 1560
#define LET 1561
#define LOG 1562
#define XMAX 1563
#define XMIN 1564
#define NOT 1567
#define PAD 1568
#define PUT 1569
#define RED 1570
#define ROW 1571
#define RUN 1572
#define SQL 1573
#define SUM 1574
#define TOP 1575
#define USE 1576
#define ATSIGN 1577
#define AS_TIFF 1579
#define AS_GIF 1580
#define AS_PNG 1581
#define AS_JPEG 1582
#define AS 1583
#define AT 1584
#define BY 1585
#define DOT 1586
#define GO 1587
#define IF 1588
#define IN 1589
#define OF 1590
#define ON 1591
#define TO 1593
#define UP 1594
#define FONT_NAME 1595
#define FONT_SIZE 1596
#define PAPER_SIZE_IS_LETTER 1597
#define PAPER_SIZE_IS_LEGAL 1598
#define PAPER_SIZE_IS_A5 1599
#define PAPER_SIZE_IS_A4 1600
#define PAPER_SIZE_IS_LETTER_L 1601
#define PAPER_SIZE_IS_LEGAL_L 1602
#define PAPER_SIZE_IS_A5_L 1603
#define PAPER_SIZE_IS_A4_L 1604
#define FORMHANDLER 1605
#define END_FORMHANDLER 1606
#define BEFORE_EVENT 1607
#define BEFORE_OPEN_FORM 1608
#define AFTER_EVENT 1609
#define BEFORE_CLOSE_FORM 1610
#define BEFORE_ANY 1611
#define AFTER_ANY 1612
#define MENUHANDLER 1613
#define END_MENUHANDLER 1614
#define BEFORE_SHOW_MENU 1615
#define DISABLE_PROGRAM 1616
#define DISABLE_ALL 1617
#define BUTTONS 1618
#define CHECK_MENUITEM 1619
#define DISABLE_FORM 1620
#define DISABLE_MENUITEMS 1621
#define DISABLE 1622
#define ENABLE_FORM 1623
#define ENABLE_MENUITEMS 1624
#define ENABLE 1625
#define KWFIELD 1626
#define ICON 1627
#define MESSAGEBOX 1628
#define TO_DEFAULTS 1629
#define UNCHECK_MENUITEM 1630
#define BEFORE 1631
#define INPUT 1632
#define END 1633
#define INT_TO_ID 1634




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

extern int lineno;
extern int read_glob_var;
extern int modlevel;
extern int charno;
extern int last_var_found;
extern int varcnt;
extern int in_record;
extern int rep_type;
extern int yylineno;
extern int compiling_system_4gl;

int sql_mode = 0;

char menuhandler[256];
char last_var[256];
char larr[4096] = "";
char larr2[4096] = "";
char clobber[64] = "";
char dtypelist[2048];
char curr_func[256] = "Module";
char where_having[1024];
char menu[2048];
char varstring[100];
char infilename[132] = "";
char hdr_dbname[64] = "";
char current_upd_table[64] = "";

int in_define = 0;
int rordcnt;
int racnt = 0;
int ccode = 0;
int errbomb = 0;
int glob_only = 0;
int inp_flags = 0;
int lcnt;
int vcnt;
int rcnt;
int lastlineno = 0;
int cnt;
int mcnt = 0;
int inrec = 0;
int iskey = 0;
int insql = 0;
int menu_cnt = 0;
int chk4var = 0;
int menu_cmd_cnt[20] =
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int in_sql = 0;
int continue_cmd[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
int in_cmd[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int fcall_cnt = 0;

struct rep_structure rep_struct;
struct pdf_rep_structure pdf_rep_struct;
struct form_attr form_attrib;
char *make_sql_string (char *first, ...);

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
#line 195 "fgl.yacc"
typedef union YYSTYPE
{



  //char  str[3100];  /* This would core A4GL_dump in CygWin on call to */
  char str[1024];		/* This would core A4GL_dump in CygWin on call to */
  /* yyparse in y.tab.c - 3100 in maximum. */
  /* Was: char    str[20000]; */

  struct expr_str *ptr;
  char *sql_string;
  struct generic_entry_list *list;
  struct generic_entry *entry;
  struct generic_entry_ident *ident;
  struct generic_entry_variable *variable;
  struct generic_entry_literal *literal;
  int integer_val;
  float float_val;
}
YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1528 "y.tab.c"
# define yystype YYSTYPE	/* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1540 "y.tab.c"

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
#   include <stdlib.h>		/* INFRINGES ON USER NAME SPACE */
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
#define YYLAST   8465

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  650
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  827
/* YYNRULES -- Number of rules. */
#define YYNRULES  1925
/* YYNRULES -- Number of states. */
#define YYNSTATES  3176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1647

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short yytranslate[] = {
  0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 1, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42,
  43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
  53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
  63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
  73, 74, 75, 76, 77, 78, 79, 80, 81, 82,
  83, 84, 85, 86, 87, 88, 89, 90, 91, 92,
  93, 94, 95, 96, 97, 98, 99, 100, 101, 102,
  103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
  113, 114, 115, 116, 117, 118, 119, 120, 121, 122,
  123, 124, 125, 126, 127, 128, 129, 130, 131, 132,
  133, 134, 135, 136, 137, 138, 139, 140, 141, 142,
  143, 144, 145, 146, 147, 148, 149, 150, 151, 152,
  153, 154, 155, 156, 157, 158, 159, 160, 161, 162,
  163, 164, 165, 166, 167, 168, 169, 170, 171, 172,
  173, 174, 175, 176, 177, 178, 179, 180, 181, 182,
  183, 184, 185, 186, 187, 188, 189, 190, 191, 192,
  193, 194, 195, 196, 197, 198, 199, 200, 201, 202,
  203, 204, 205, 206, 207, 208, 209, 210, 211, 212,
  213, 214, 215, 216, 217, 218, 219, 220, 221, 222,
  223, 224, 225, 226, 227, 228, 229, 230, 231, 232,
  233, 234, 235, 236, 237, 238, 239, 240, 241, 242,
  243, 244, 245, 246, 247, 248, 249, 250, 251, 252,
  253, 254, 255, 256, 257, 258, 259, 260, 261, 262,
  263, 264, 265, 266, 267, 268, 269, 270, 271, 272,
  273, 274, 275, 276, 277, 278, 279, 280, 281, 282,
  283, 284, 285, 286, 287, 288, 289, 290, 291, 292,
  293, 294, 295, 296, 297, 298, 299, 300, 301, 302,
  303, 304, 305, 306, 307, 308, 309, 310, 14, 311,
  312, 313, 314, 315, 316, 317, 318, 319, 320, 321,
  322, 323, 324, 325, 326, 327, 328, 329, 330, 331,
  332, 333, 334, 335, 336, 337, 338, 339, 340, 341,
  342, 343, 344, 345, 346, 347, 348, 349, 350, 351,
  352, 353, 354, 355, 356, 357, 358, 359, 360, 361,
  362, 363, 364, 365, 366, 367, 15, 368, 369, 370,
  371, 372, 373, 22, 374, 375, 376, 377, 378, 379,
  380, 381, 382, 383, 384, 385, 386, 387, 388, 389,
  390, 9, 391, 392, 393, 394, 395, 396, 397, 398,
  399, 400, 401, 402, 403, 404, 405, 406, 407, 12,
  408, 409, 410, 411, 412, 413, 414, 415, 416, 417,
  418, 419, 420, 421, 422, 423, 424, 425, 426, 427,
  428, 429, 430, 431, 432, 433, 434, 435, 436, 437,
  16, 438, 439, 440, 441, 442, 443, 444, 445, 446,
  447, 448, 449, 450, 451, 452, 453, 454, 455, 456,
  457, 458, 459, 460, 461, 462, 463, 464, 465, 466,
  467, 468, 469, 470, 471, 472, 473, 474, 475, 476,
  477, 478, 479, 480, 481, 482, 483, 484, 485, 486,
  487, 488, 489, 490, 491, 11, 492, 493, 494, 10,
  20, 495, 496, 497, 498, 499, 500, 501, 502, 503,
  504, 505, 506, 8, 507, 508, 509, 510, 511, 512,
  513, 514, 515, 516, 517, 518, 519, 520, 19, 521,
  522, 523, 524, 525, 526, 527, 528, 529, 530, 531,
  532, 533, 534, 535, 536, 537, 538, 539, 540, 541,
  542, 543, 544, 545, 546, 547, 548, 549, 550, 551,
  552, 553, 554, 555, 556, 557, 558, 559, 560, 561,
  562, 563, 13, 564, 565, 566, 567, 7, 568, 569,
  570, 571, 5, 572, 573, 574, 575, 576, 577, 578,
  579, 580, 581, 582, 583, 18, 21, 584, 585, 586,
  587, 588, 589, 590, 591, 592, 593, 594, 17, 595,
  596, 597, 598, 599, 600, 601, 602, 603, 604, 605,
  606, 607, 6, 608, 609, 610, 611, 612, 613, 614,
  615, 616, 617, 618, 619, 620, 621, 622, 623, 624,
  625, 626, 627, 628, 629, 630, 631, 632, 633, 634,
  635, 636, 637, 638, 639, 640, 641, 642, 643, 644,
  645, 646, 647, 648, 649, 2, 3, 4, 23, 24,
  25, 26, 27, 28, 29, 30, 31, 32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] = {
  0, 0, 3, 5, 7, 13, 15, 17, 19, 21,
  25, 27, 31, 35, 37, 40, 42, 44, 46, 48,
  50, 52, 54, 56, 57, 59, 60, 66, 73, 75,
  79, 81, 83, 85, 87, 89, 91, 93, 95, 97,
  99, 101, 103, 105, 107, 109, 111, 112, 114, 115,
  121, 123, 127, 129, 131, 134, 137, 140, 143, 146,
  149, 152, 155, 159, 160, 168, 177, 184, 186, 193,
  194, 195, 205, 206, 207, 208, 217, 218, 219, 230,
  231, 232, 242, 243, 244, 245, 260, 261, 264, 265,
  268, 270, 271, 273, 275, 279, 281, 283, 285, 287,
  291, 292, 299, 300, 306, 308, 311, 313, 316, 318,
  319, 320, 324, 325, 326, 330, 331, 336, 337, 342,
  345, 348, 351, 353, 356, 359, 363, 365, 367, 369,
  372, 374, 376, 379, 381, 383, 384, 385, 391, 399,
  408, 409, 412, 414, 418, 420, 424, 428, 430, 433,
  434, 439, 440, 445, 446, 450, 451, 455, 456, 460,
  462, 466, 468, 472, 474, 476, 478, 480, 482, 484,
  489, 490, 495, 497, 499, 500, 502, 504, 507, 508,
  509, 515, 517, 519, 521, 525, 526, 529, 534, 539,
  544, 549, 552, 553, 558, 560, 562, 564, 567, 569,
  571, 575, 576, 578, 579, 587, 588, 601, 603, 605,
  607, 609, 611, 617, 621, 623, 625, 626, 631, 632,
  638, 639, 647, 649, 653, 655, 657, 658, 660, 661,
  662, 667, 669, 671, 673, 678, 683, 690, 692, 695,
  697, 699, 701, 703, 708, 715, 717, 722, 729, 731,
  733, 735, 737, 739, 741, 743, 746, 749, 751, 753,
  758, 760, 762, 763, 767, 771, 772, 775, 777, 779,
  781, 783, 785, 787, 790, 791, 794, 795, 799, 800,
  804, 806, 807, 811, 813, 815, 817, 819, 821, 823,
  826, 828, 829, 831, 832, 838, 840, 842, 844, 849,
  854, 861, 863, 865, 867, 869, 874, 881, 883, 888,
  895, 897, 899, 901, 903, 905, 908, 911, 913, 918,
  919, 927, 928, 941, 942, 947, 948, 954, 956, 960,
  963, 965, 969, 971, 972, 975, 978, 980, 983, 989,
  994, 997, 1002, 1008, 1012, 1013, 1014, 1026, 1027, 1030,
  1032, 1033, 1036, 1038, 1041, 1042, 1046, 1047, 1051, 1052,
  1056, 1061, 1067, 1069, 1071, 1073, 1075, 1077, 1079, 1081,
  1083, 1085, 1087, 1089, 1091, 1093, 1095, 1097, 1099, 1101,
  1103, 1106, 1108, 1110, 1112, 1114, 1117, 1119, 1121, 1123,
  1126, 1129, 1131, 1133, 1135, 1137, 1139, 1141, 1143, 1145,
  1147, 1149, 1151, 1154, 1156, 1158, 1160, 1164, 1166, 1170,
  1172, 1176, 1178, 1180, 1182, 1185, 1187, 1189, 1193, 1198,
  1203, 1206, 1209, 1211, 1213, 1215, 1217, 1219, 1223, 1225,
  1228, 1231, 1233, 1234, 1238, 1241, 1244, 1246, 1250, 1255,
  1260, 1266, 1272, 1274, 1276, 1279, 1282, 1287, 1292, 1295,
  1298, 1303, 1308, 1310, 1313, 1316, 1319, 1322, 1325, 1328,
  1331, 1334, 1337, 1340, 1343, 1346, 1349, 1352, 1353, 1354,
  1355, 1362, 1363, 1364, 1373, 1374, 1375, 1382, 1383, 1384,
  1391, 1392, 1393, 1400, 1401, 1402, 1409, 1415, 1421, 1427,
  1435, 1436, 1440, 1442, 1444, 1449, 1454, 1459, 1464, 1469,
  1474, 1476, 1478, 1480, 1482, 1487, 1492, 1495, 1498, 1501,
  1504, 1507, 1509, 1511, 1514, 1516, 1518, 1520, 1523, 1528,
  1535, 1542, 1546, 1552, 1558, 1562, 1564, 1566, 1570, 1572,
  1576, 1577, 1578, 1590, 1591, 1594, 1595, 1596, 1597, 1606,
  1607, 1608, 1619, 1620, 1622, 1623, 1625, 1627, 1630, 1631,
  1635, 1636, 1640, 1641, 1643, 1645, 1648, 1649, 1653, 1654,
  1658, 1662, 1664, 1669, 1673, 1675, 1679, 1681, 1685, 1687,
  1691, 1693, 1696, 1697, 1701, 1702, 1706, 1707, 1712, 1713,
  1718, 1719, 1724, 1727, 1731, 1733, 1737, 1739, 1741, 1743,
  1745, 1747, 1749, 1753, 1755, 1757, 1762, 1769, 1774, 1778,
  1785, 1789, 1796, 1798, 1800, 1802, 1804, 1806, 1808, 1809,
  1812, 1814, 1816, 1818, 1823, 1825, 1827, 1829, 1834, 1838,
  1845, 1849, 1856, 1858, 1860, 1863, 1865, 1867, 1869, 1871,
  1873, 1875, 1877, 1879, 1881, 1883, 1885, 1887, 1889, 1891,
  1893, 1895, 1897, 1899, 1901, 1903, 1905, 1907, 1909, 1911,
  1913, 1915, 1917, 1919, 1921, 1923, 1925, 1927, 1929, 1931,
  1933, 1935, 1937, 1939, 1941, 1943, 1945, 1947, 1949, 1952,
  1955, 1957, 1961, 1963, 1966, 1969, 1972, 1977, 1980, 1983,
  1988, 1989, 1998, 1999, 2001, 2003, 2005, 2006, 2008, 2011,
  2012, 2014, 2017, 2018, 2020, 2023, 2024, 2026, 2030, 2031,
  2034, 2035, 2043, 2044, 2045, 2049, 2050, 2051, 2059, 2065,
  2068, 2071, 2072, 2078, 2083, 2085, 2089, 2093, 2097, 2098,
  2101, 2102, 2104, 2106, 2109, 2110, 2115, 2116, 2121, 2122,
  2126, 2127, 2131, 2132, 2136, 2137, 2141, 2142, 2146, 2147,
  2152, 2153, 2158, 2160, 2164, 2166, 2168, 2170, 2174, 2176,
  2178, 2180, 2184, 2186, 2190, 2193, 2198, 2200, 2202, 2204,
  2205, 2210, 2216, 2223, 2224, 2235, 2239, 2241, 2243, 2246,
  2249, 2250, 2253, 2254, 2258, 2260, 2261, 2265, 2268, 2269,
  2273, 2275, 2279, 2281, 2285, 2286, 2289, 2291, 2293, 2295,
  2297, 2299, 2301, 2303, 2305, 2307, 2309, 2311, 2313, 2315,
  2317, 2319, 2321, 2323, 2325, 2326, 2327, 2335, 2337, 2339,
  2342, 2345, 2348, 2352, 2357, 2358, 2362, 2363, 2365, 2367,
  2370, 2372, 2374, 2376, 2378, 2379, 2381, 2383, 2386, 2389,
  2391, 2393, 2395, 2397, 2399, 2401, 2403, 2405, 2407, 2409,
  2411, 2413, 2415, 2416, 2418, 2420, 2422, 2424, 2426, 2427,
  2428, 2429, 2430, 2444, 2446, 2447, 2448, 2455, 2458, 2460,
  2463, 2466, 2468, 2470, 2473, 2475, 2477, 2479, 2480, 2484,
  2487, 2489, 2490, 2491, 2492, 2507, 2508, 2514, 2516, 2517,
  2521, 2522, 2530, 2531, 2537, 2539, 2542, 2543, 2545, 2547,
  2549, 2550, 2552, 2554, 2557, 2560, 2563, 2565, 2567, 2569,
  2571, 2575, 2577, 2579, 2580, 2581, 2589, 2591, 2594, 2595,
  2599, 2600, 2605, 2608, 2609, 2612, 2614, 2616, 2618, 2620,
  2622, 2624, 2626, 2627, 2631, 2632, 2634, 2636, 2638, 2640,
  2643, 2646, 2649, 2655, 2657, 2659, 2661, 2666, 2671, 2673,
  2675, 2677, 2679, 2682, 2685, 2689, 2696, 2698, 2702, 2704,
  2706, 2708, 2712, 2719, 2721, 2723, 2725, 2727, 2730, 2731,
  2733, 2735, 2739, 2741, 2745, 2747, 2751, 2753, 2757, 2759,
  2761, 2763, 2765, 2769, 2771, 2775, 2777, 2781, 2783, 2785,
  2787, 2791, 2794, 2795, 2797, 2799, 2804, 2806, 2810, 2812,
  2816, 2824, 2825, 2833, 2834, 2841, 2845, 2847, 2851, 2853,
  2856, 2862, 2863, 2871, 2872, 2875, 2876, 2878, 2884, 2887,
  2893, 2894, 2900, 2907, 2912, 2913, 2915, 2917, 2922, 2923,
  2926, 2927, 2933, 2938, 2941, 2943, 2947, 2950, 2953, 2956,
  2959, 2962, 2965, 2967, 2970, 2973, 2976, 2979, 2982, 2985,
  2988, 2991, 2994, 2996, 2998, 3000, 3002, 3004, 3006, 3012,
  3014, 3016, 3019, 3024, 3026, 3027, 3038, 3044, 3045, 3047,
  3048, 3051, 3053, 3056, 3057, 3061, 3063, 3064, 3069, 3070,
  3073, 3075, 3079, 3081, 3083, 3087, 3092, 3097, 3100, 3102,
  3104, 3106, 3107, 3109, 3117, 3120, 3123, 3126, 3129, 3132,
  3134, 3137, 3138, 3142, 3143, 3147, 3148, 3152, 3153, 3157,
  3158, 3162, 3163, 3168, 3169, 3174, 3176, 3178, 3180, 3182,
  3184, 3186, 3187, 3192, 3193, 3195, 3196, 3201, 3203, 3206,
  3209, 3212, 3213, 3215, 3217, 3220, 3223, 3224, 3227, 3231,
  3235, 3241, 3242, 3245, 3250, 3252, 3254, 3256, 3258, 3260,
  3261, 3263, 3265, 3269, 3272, 3278, 3281, 3287, 3293, 3299,
  3305, 3311, 3317, 3318, 3321, 3323, 3326, 3329, 3332, 3335,
  3338, 3341, 3343, 3346, 3349, 3352, 3355, 3357, 3360, 3363,
  3366, 3369, 3371, 3373, 3375, 3376, 3379, 3382, 3385, 3388,
  3391, 3394, 3397, 3400, 3403, 3405, 3407, 3409, 3411, 3413,
  3415, 3417, 3419, 3422, 3425, 3428, 3431, 3434, 3436, 3438,
  3440, 3441, 3445, 3448, 3449, 3450, 3451, 3452, 3453, 3454,
  3470, 3471, 3474, 3477, 3478, 3480, 3481, 3482, 3483, 3484,
  3485, 3486, 3502, 3505, 3506, 3507, 3508, 3519, 3520, 3522,
  3526, 3530, 3533, 3538, 3542, 3546, 3550, 3552, 3554, 3556,
  3558, 3560, 3562, 3563, 3564, 3572, 3573, 3574, 3583, 3587,
  3590, 3591, 3593, 3595, 3599, 3602, 3605, 3607, 3609, 3613,
  3615, 3617, 3620, 3622, 3626, 3628, 3632, 3634, 3636, 3638,
  3640, 3642, 3644, 3646, 3649, 3654, 3656, 3660, 3662, 3666,
  3669, 3674, 3676, 3680, 3682, 3685, 3690, 3692, 3696, 3698,
  3700, 3702, 3705, 3708, 3713, 3716, 3721, 3723, 3727, 3729,
  3731, 3733, 3736, 3738, 3740, 3742, 3744, 3746, 3749, 3756,
  3763, 3764, 3766, 3767, 3769, 3772, 3774, 3775, 3781, 3782,
  3788, 3790, 3791, 3795, 3797, 3801, 3803, 3807, 3809, 3811,
  3812, 3813, 3819, 3822, 3824, 3825, 3826, 3830, 3831, 3832,
  3836, 3838, 3840, 3842, 3844, 3846, 3848, 3851, 3854, 3859,
  3863, 3867, 3869, 3873, 3876, 3878, 3880, 3881, 3883, 3885,
  3887, 3889, 3890, 3892, 3896, 3897, 3901, 3903, 3905, 3907,
  3909, 3911, 3913, 3915, 3917, 3919, 3921, 3923, 3925, 3933,
  3934, 3936, 3938, 3940, 3942, 3946, 3948, 3950, 3952, 3955,
  3956, 3960, 3962, 3966, 3968, 3972, 3974, 3976, 3983, 3984,
  3988, 3990, 3994, 3995, 3997, 4002, 4008, 4011, 4013, 4015,
  4020, 4022, 4026, 4031, 4036, 4038, 4042, 4044, 4046, 4048,
  4051, 4053, 4058, 4059, 4061, 4062, 4064, 4066, 4069, 4071,
  4073, 4075, 4080, 4084, 4086, 4088, 4090, 4093, 4095, 4097,
  4100, 4103, 4105, 4109, 4112, 4115, 4117, 4121, 4123, 4126,
  4131, 4133, 4136, 4138, 4142, 4147, 4148, 4150, 4151, 4153,
  4154, 4156, 4158, 4162, 4164, 4168, 4170, 4173, 4175, 4179,
  4182, 4185, 4186, 4189, 4191, 4193, 4195, 4201, 4205, 4211,
  4215, 4217, 4221, 4223, 4225, 4226, 4228, 4232, 4236, 4240,
  4247, 4252, 4257, 4263, 4265, 4267, 4269, 4271, 4273, 4275,
  4277, 4279, 4281, 4283, 4285, 4286, 4288, 4290, 4292, 4294,
  4296, 4298, 4300, 4305, 4311, 4313, 4319, 4325, 4327, 4329,
  4331, 4336, 4338, 4343, 4345, 4353, 4355, 4357, 4359, 4364,
  4371, 4372, 4375, 4380, 4382, 4384, 4386, 4388, 4390, 4392,
  4394, 4398, 4400, 4402, 4406, 4408, 4409, 4413, 4419, 4421,
  4424, 4427, 4432, 4436, 4438, 4440, 4442, 4444, 4446, 4448,
  4451, 4454, 4455, 4459, 4460, 4464, 4466, 4468, 4470, 4472,
  4474, 4476, 4478, 4483, 4485, 4487, 4489, 4491, 4493, 4495,
  4497, 4502, 4504, 4506, 4508, 4510, 4512, 4514, 4516, 4518,
  4520, 4522, 4524, 4526, 4528, 4530, 4532, 4534, 4538, 4539,
  4548, 4549, 4559, 4560, 4568, 4569, 4579, 4580, 4582, 4585,
  4587, 4591, 4593, 4597, 4603, 4605, 4607, 4609, 4611, 4614,
  4615, 4616, 4625, 4631, 4633, 4635, 4642, 4643, 4647, 4649,
  4653, 4658, 4660, 4661, 4664, 4669, 4676, 4677, 4679, 4681,
  4683, 4685, 4689, 4691, 4694, 4697, 4699, 4701, 4704, 4707,
  4709, 4711, 4713, 4716, 4721, 4725, 4728, 4732, 4736, 4740,
  4742, 4744, 4746, 4748, 4750, 4752, 4758, 4764, 4770, 4776,
  4782, 4787, 4792, 4796, 4801, 4803, 4807, 4808, 4810, 4816,
  4824, 4830, 4831, 4834, 4836, 4838, 4839, 4843, 4845, 4849,
  4851, 4853, 4855, 4856, 4860, 4862, 4864, 4866, 4868, 4873,
  4880, 4882, 4884, 4887, 4891, 4893, 4895, 4897, 4899, 4901,
  4903, 4905, 4907, 4913, 4919, 4924, 4925, 4930, 4932, 4935,
  4937, 4939, 4941, 4944, 4947, 4948, 4949, 4957, 4958, 4961,
  4964, 4972, 4978, 4980, 4984, 4986, 4990, 4992, 4996, 4998,
  5002, 5004, 5008, 5010, 5012, 5014, 5017, 5020, 5022, 5024,
  5026, 5029, 5034, 5038, 5041, 5045, 5049, 5053, 5055, 5057,
  5059, 5061, 5063, 5065, 5071, 5077, 5083, 5089, 5095, 5100,
  5105, 5109, 5114, 5116, 5118, 5122, 5124, 5127, 5129, 5131,
  5133, 5137, 5143, 5145, 5147, 5149, 5151, 5155, 5158, 5161,
  5164, 5166, 5169, 5172, 5175, 5178, 5181, 5183, 5187, 5190,
  5192, 5195, 5197, 5200, 5202, 5203, 5204, 5211, 5212, 5215,
  5216, 5218, 5220, 5223, 5226, 5228, 5230, 5235, 5239, 5241,
  5245, 5247, 5250, 5256, 5259, 5262, 5268, 5269, 5272, 5274,
  5276, 5279, 5286, 5293, 5295, 5296, 5298, 5301, 5303, 5306,
  5307, 5310, 5312, 5314, 5316, 5318, 5320, 5322, 5324, 5326,
  5328, 5330, 5332, 5334, 5336, 5338, 5340, 5342, 5344, 5346,
  5348, 5350, 5352, 5354, 5356, 5358, 5360, 5362, 5364, 5366,
  5368, 5370, 5372, 5374, 5376, 5378, 5380, 5382, 5384, 5386,
  5388, 5390, 5392, 5394, 5396, 5398, 5400, 5402, 5404, 5406,
  5408, 5410, 5412, 5414, 5416, 5418, 5420, 5422, 5424, 5426,
  5428, 5430, 5432, 5434, 5436, 5438, 5440, 5442, 5444, 5446,
  5448, 5450, 5452, 5454, 5456, 5458, 5460, 5462, 5464, 5466,
  5468, 5470, 5472, 5474, 5476, 5478
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] = {
  1009, 0, -1, 181, -1, 178, -1, 105, 655, 407,
  577, 656, -1, 119, -1, 1075, -1, 25, -1, 657,
  -1, 656, 5, 657, -1, 919, -1, 411, 658, 372,
  -1, 658, 659, 658, -1, 25, -1, 660, 25, -1,
  1075, -1, 17, -1, 18, -1, 20, -1, 19, -1,
  21, -1, 17, -1, 18, -1, -1, 662, -1, -1,
  255, 411, 663, 664, 372, -1, 550, 411, 25, 5,
  25, 372, -1, 665, -1, 664, 5, 665, -1, 471,
  -1, 512, -1, 518, -1, 487, -1, 390, -1, 587,
  -1, 509, -1, 461, -1, 397, -1, 472, -1, 326,
  -1, 513, -1, 436, -1, 313, -1, 575, -1, 79,
  -1, -1, 667, -1, -1, 255, 411, 668, 669, 372,
  -1, 670, -1, 669, 5, 670, -1, 665, -1, 412,
  -1, 585, 24, -1, 184, 906, -1, 310, 906, -1,
  265, 906, -1, 318, 906, -1, 274, 906, -1, 240,
  906, -1, 515, 672, -1, 851, 325, 1075, -1, -1,
  270, 411, 1461, 372, 325, 673, 1094, -1, 85, 411,
  919, 5, 24, 5, 24, 372, -1, 387, 411, 911,
  372, 325, 1075, -1, 1212, -1, 173, 411, 870, 372,
  325, 1075, -1, -1, -1, 1075, 571, 919, 411, 674,
  688, 372, 675, 686, -1, -1, -1, -1, 919, 411,
  676, 688, 677, 372, 678, 686, -1, -1, -1, 455,
  1408, 605, 1408, 411, 679, 688, 680, 372, 686, -1,
  -1, -1, 919, 502, 919, 411, 681, 688, 682, 372,
  686, -1, -1, -1, -1, 346, 691, 571, 692, 439,
  655, 407, 411, 683, 688, 684, 372, 685, 687, -1,
  -1, 325, 1094, -1, -1, 325, 1094, -1, 143, -1,
  -1, 689, -1, 690, -1, 689, 5, 690, -1, 820,
  -1, 24, -1, 919, -1, 919, -1, 919, 602, 919,
  -1, -1, 516, 827, 694, 697, 701, 698, -1, -1,
  516, 695, 696, 699, 698, -1, 703, -1, 696, 703,
  -1, 705, -1, 697, 705, -1, 341, -1, -1, -1,
  320, 700, 1471, -1, -1, -1, 320, 702, 1471, -1,
  -1, 560, 827, 704, 1471, -1, -1, 560, 827, 706,
  1471, -1, 259, 916, -1, 183, 914, -1, 64, 914,
  -1, 150, -1, 166, 1414, -1, 475, 913, -1, 29,
  709, 30, -1, 710, -1, 712, -1, 711, -1, 710,
  711, -1, 28, -1, 713, -1, 712, 713, -1, 27,
  -1, 374, -1, -1, -1, 301, 716, 718, 717, 719,
  -1, 365, 1075, 607, 720, 960, 987, 661, -1, 1075,
  607, 720, 960, 528, 1461, 987, 661, -1, -1, 722,
  172, -1, 721, -1, 720, 5, 721, -1, 919, -1,
  919, 602, 919, -1, 919, 602, 20, -1, 723, -1,
  722, 723, -1, -1, 251, 729, 724, 1471, -1, -1,
  254, 730, 725, 1471, -1, -1, 988, 726, 1471, -1,
  -1, 148, 727, 1471, -1, -1, 144, 728, 1471, -1,
  923, -1, 729, 5, 923, -1, 923, -1, 730, 5,
  923, -1, 73, -1, 74, -1, 75, -1, 76, -1,
  77, -1, 78, -1, 411, 820, 733, 372, -1, -1,
  5, 774, 608, 777, -1, 136, -1, 260, -1, -1,
  736, -1, 737, -1, 736, 737, -1, -1, -1, 418,
  738, 740, 739, 1181, -1, 787, -1, 1451, -1, 743,
  -1, 740, 5, 743, -1, -1, 742, 919, -1, 334,
  741, 786, 24, -1, 334, 741, 786, 919, -1, 334,
  741, 786, 925, -1, 334, 741, 786, 25, -1, 747,
  763, -1, -1, 741, 334, 744, 745, -1, 25, -1,
  24, -1, 925, -1, 18, 25, -1, 741, -1, 746,
  -1, 747, 5, 746, -1, -1, 517, -1, -1, 468,
  439, 755, 407, 750, 606, 763, -1, -1, 299, 748,
  752, 25, 753, 283, 439, 754, 407, 751, 606, 763,
  -1, 411, -1, 438, -1, 372, -1, 406, -1, 25,
  -1, 756, 5, 756, 5, 756, -1, 756, 5, 756,
  -1, 756, -1, 25, -1, -1, 444, 758, 740, 264,
  -1, -1, 241, 759, 741, 602, 20, -1, -1, 315,
  760, 741, 239, 411, 761, 372, -1, 762, -1, 761,
  5, 762, -1, 741, -1, 765, -1, -1, 39, -1,
  -1, -1, 766, 768, 767, 764, -1, 749, -1, 757,
  -1, 517, -1, 517, 411, 25, 372, -1, 404, 411,
  25, 372, -1, 404, 411, 25, 5, 25, 372, -1,
  388, -1, 599, 741, -1, 360, -1, 490, -1, 70,
  -1, 378, -1, 378, 411, 25, 372, -1, 378, 411,
  25, 5, 25, 372, -1, 493, -1, 493, 411, 25,
  372, -1, 493, 411, 25, 5, 25, 372, -1, 483,
  -1, 280, -1, 519, -1, 514, -1, 61, -1, 62,
  -1, 556, -1, 338, 772, -1, 350, 773, -1, 769,
  -1, 31, -1, 538, 770, 602, 771, -1, 741, -1,
  741, -1, -1, 774, 608, 777, -1, 782, 608, 785,
  -1, -1, 775, 776, -1, 563, -1, 494, -1, 572,
  -1, 534, -1, 434, -1, 451, -1, 347, 779, -1,
  -1, 778, 776, -1, -1, 411, 781, 372, -1, -1,
  411, 25, 372, -1, 25, -1, -1, 783, 784, 780,
  -1, 563, -1, 494, -1, 572, -1, 534, -1, 434,
  -1, 451, -1, 347, 779, -1, 784, -1, -1, 13,
  -1, -1, 217, 919, 788, 599, 789, -1, 791, -1,
  794, -1, 517, -1, 517, 411, 25, 372, -1, 404,
  411, 25, 372, -1, 404, 411, 25, 5, 25, 372,
  -1, 388, -1, 360, -1, 490, -1, 378, -1, 378,
  411, 25, 372, -1, 378, 411, 25, 5, 25, 372,
  -1, 493, -1, 493, 411, 25, 372, -1, 493, 411,
  25, 5, 25, 372, -1, 483, -1, 280, -1, 519,
  -1, 514, -1, 556, -1, 338, 772, -1, 350, 773,
  -1, 790, -1, 538, 770, 602, 771, -1, -1, 468,
  439, 755, 407, 792, 606, 789, -1, -1, 299, 748,
  752, 25, 753, 283, 439, 754, 407, 793, 606, 789,
  -1, -1, 444, 795, 797, 264, -1, -1, 241, 796,
  919, 602, 20, -1, 798, -1, 797, 5, 798, -1,
  799, 789, -1, 800, -1, 799, 5, 800, -1, 919,
  -1, -1, 600, 910, -1, 51, 919, -1, 49, -1,
  608, 1461, -1, 608, 490, 919, 641, 1461, -1, 608,
  490, 919, 370, -1, 53, 919, -1, 137, 845, 1094,
  809, -1, 381, 845, 825, 801, 809, -1, 190, 916,
  809, -1, -1, -1, 169, 806, 1101, 608, 919, 602,
  20, 808, 661, 807, 810, -1, -1, 449, 911, -1,
  661, -1, -1, 811, 219, -1, 812, -1, 811, 812,
  -1, -1, 332, 813, 1471, -1, -1, 328, 814, 1471,
  -1, -1, 988, 815, 1471, -1, 479, 845, 826, 661,
  -1, 479, 845, 826, 661, 46, -1, 267, -1, 266,
  -1, 193, -1, 345, -1, 155, -1, 192, -1, 309,
  -1, 308, -1, 224, -1, 152, -1, 151, -1, 125,
  -1, 185, -1, 108, -1, 124, -1, 168, -1, 134,
  -1, 194, -1, 194, 827, -1, 830, -1, 829, -1,
  834, -1, 862, -1, 820, 821, -1, 863, -1, 865,
  -1, 831, -1, 18, 820, -1, 17, 820, -1, 836,
  -1, 844, -1, 838, -1, 456, -1, 731, -1, 839,
  -1, 840, -1, 841, -1, 842, -1, 843, -1, 845,
  -1, 845, 824, -1, 827, -1, 464, -1, 823, -1,
  824, 5, 823, -1, 827, -1, 825, 5, 827, -1,
  827, -1, 826, 5, 827, -1, 820, -1, 17, -1,
  18, -1, 584, 820, -1, 465, -1, 408, -1, 411,
  820, 372, -1, 423, 411, 1388, 372, -1, 275, 411,
  1388, 372, -1, 828, 925, -1, 828, 25, -1, 24,
  -1, 925, -1, 25, -1, 833, -1, 1075, -1, 1075,
  401, 1075, -1, 832, -1, 414, 820, -1, 373, 820,
  -1, 1184, -1, -1, 488, 835, 1184, -1, 7, 820,
  -1, 6, 820, -1, 820, -1, 837, 5, 820, -1,
  605, 411, 1388, 372, -1, 409, 411, 1388, 372, -1,
  605, 411, 845, 837, 372, -1, 409, 411, 845, 837,
  372, -1, 367, -1, 230, -1, 9, 820, -1, 233,
  820, -1, 9, 820, 422, 24, -1, 233, 820, 422,
  24, -1, 538, 820, -1, 352, 820, -1, 538, 820,
  422, 24, -1, 352, 820, 422, 24, -1, 371, -1,
  8, 820, -1, 17, 820, -1, 18, 820, -1, 20,
  820, -1, 19, 820, -1, 21, 820, -1, 10, 820,
  -1, 13, 820, -1, 437, 820, -1, 11, 820, -1,
  12, 820, -1, 16, 820, -1, 15, 820, -1, 14,
  820, -1, -1, -1, -1, 919, 411, 847, 688, 848,
  372, -1, -1, -1, 919, 502, 919, 411, 849, 688,
  850, 372, -1, -1, -1, 519, 411, 852, 820, 853,
  372, -1, -1, -1, 494, 411, 854, 820, 855, 372,
  -1, -1, -1, 572, 411, 856, 820, 857, 372, -1,
  -1, -1, 563, 411, 858, 820, 859, 372, -1, 350,
  411, 866, 372, 861, -1, 338, 411, 24, 372, 860,
  -1, 338, 411, 25, 372, 860, -1, 338, 411, 25,
  571, 25, 372, 860, -1, -1, 1368, 608, 1369, -1,
  773, -1, 851, -1, 270, 411, 1461, 372, -1, 80,
  411, 911, 372, -1, 52, 411, 911, 372, -1, 387,
  411, 911, 372, -1, 173, 411, 870, 372, -1, 40,
  411, 870, 372, -1, 864, -1, 846, -1, 1364, -1,
  519, -1, 403, 411, 820, 372, -1, 303, 411, 820,
  372, -1, 469, 820, -1, 424, 732, -1, 820, 89,
  -1, 820, 90, -1, 820, 91, -1, 24, -1, 867,
  -1, 18, 867, -1, 869, -1, 868, -1, 25, -1,
  25, 25, -1, 25, 25, 571, 25, -1, 25, 25,
  571, 25, 571, 25, -1, 25, 25, 571, 25, 571,
  23, -1, 25, 571, 25, -1, 25, 571, 25, 571,
  25, -1, 25, 571, 25, 571, 23, -1, 25, 571,
  23, -1, 23, -1, 25, -1, 25, 18, 25, -1,
  911, -1, 870, 5, 911, -1, -1, -1, 577, 1075,
  13, 827, 608, 827, 874, 872, 1471, 873, 222, -1,
  -1, 553, 827, -1, -1, -1, -1, 384, 876, 913,
  877, 1270, 878, 1471, 221, -1, -1, -1, 620, 919,
  880, 735, 881, 1019, 883, 882, 888, 621, -1, -1,
  893, -1, -1, 884, -1, 885, -1, 884, 885, -1,
  -1, 622, 886, 1471, -1, -1, 623, 887, 1471, -1,
  -1, 889, -1, 890, -1, 889, 890, -1, -1, 624,
  891, 1471, -1, -1, 625, 892, 1471, -1, 894, 898,
  305, -1, 72, -1, 72, 895, 528, 896, -1, 72,
  365, 897, -1, 1075, -1, 895, 5, 1075, -1, 919,
  -1, 896, 5, 919, -1, 1075, -1, 897, 5, 1075,
  -1, 899, -1, 898, 899, -1, -1, 626, 900, 1471,
  -1, -1, 627, 901, 1471, -1, -1, 646, 896, 902,
  1471, -1, -1, 462, 896, 903, 1471, -1, -1, 607,
  896, 904, 1471, -1, 527, 912, -1, 536, 18, 25,
  -1, 536, -1, 482, 17, 25, -1, 482, -1, 25,
  -1, 1075, -1, 24, -1, 924, -1, 827, -1, 908,
  5, 908, -1, 909, -1, 919, -1, 649, 411, 919,
  372, -1, 919, 602, 649, 411, 919, 372, -1, 919,
  439, 658, 407, -1, 919, 602, 20, -1, 919, 439,
  658, 407, 602, 20, -1, 919, 602, 919, -1, 919,
  439, 658, 407, 602, 919, -1, 920, -1, 920, -1,
  920, -1, 920, -1, 920, -1, 920, -1, -1, 532,
  25, -1, 1470, -1, 921, -1, 1470, -1, 330, 411,
  922, 372, -1, 1078, -1, 24, -1, 919, -1, 919,
  439, 658, 407, -1, 919, 602, 20, -1, 919, 439,
  658, 407, 602, 20, -1, 919, 602, 919, -1, 919,
  439, 658, 407, 602, 919, -1, 1075, -1, 23, -1,
  602, 25, -1, 354, -1, 473, -1, 474, -1, 371,
  -1, 475, -1, 334, -1, 301, -1, 477, -1, 440,
  -1, 518, -1, 429, -1, 573, -1, 377, -1, 470,
  -1, 463, -1, 541, -1, 380, -1, 339, -1, 478,
  -1, 302, -1, 520, -1, 261, -1, 575, -1, 637,
  -1, 521, -1, 303, -1, 523, -1, 385, -1, 423,
  -1, 563, -1, 494, -1, 572, -1, 456, -1, 359,
  -1, 374, -1, 419, -1, 361, -1, 422, -1, 403,
  -1, 368, -1, 326, -1, 540, -1, 519, -1, 529,
  1453, -1, 634, 929, -1, 930, -1, 929, 5, 930,
  -1, 919, -1, 645, 929, -1, 636, 929, -1, 637,
  1461, -1, 635, 916, 641, 1461, -1, 639, 929, -1,
  640, 1461, -1, 638, 916, 641, 1461, -1, -1, 643,
  935, 825, 940, 942, 944, 936, 938, -1, -1, 937,
  -1, 631, -1, 632, -1, -1, 939, -1, 325, 1075,
  -1, -1, 941, -1, 370, 825, -1, -1, 943, -1,
  642, 25, -1, -1, 945, -1, 633, 25, 946, -1,
  -1, 380, 25, -1, -1, 604, 827, 557, 948, 1471,
  949, 421, -1, -1, -1, 524, 950, 1471, -1, -1,
  -1, 43, 951, 827, 557, 952, 1471, 949, -1, 87,
  919, 411, 25, 372, -1, 36, 919, -1, 56, 919,
  -1, -1, 271, 1106, 956, 608, 464, -1, 271, 1106,
  538, 957, -1, 958, -1, 957, 5, 958, -1, 770,
  602, 1360, -1, 770, 602, 20, -1, -1, 961, 305,
  -1, -1, 131, -1, 962, -1, 961, 962, -1, -1,
  251, 976, 963, 1471, -1, -1, 254, 977, 964, 1471,
  -1, -1, 332, 965, 1471, -1, -1, 328, 966, 1471,
  -1, -1, 988, 967, 1471, -1, -1, 286, 968, 1471,
  -1, -1, 256, 969, 1471, -1, -1, 646, 974, 970,
  1471, -1, -1, 462, 972, 971, 1471, -1, 973, -1,
  972, 5, 973, -1, 430, -1, 419, -1, 975, -1,
  974, 5, 975, -1, 430, -1, 419, -1, 911, -1,
  976, 5, 911, -1, 911, -1, 977, 5, 911, -1,
  295, 980, -1, 296, 919, 641, 980, -1, 543, -1,
  355, -1, 911, -1, -1, 647, 983, 982, 959, -1,
  365, 1094, 960, 918, 661, -1, 1094, 960, 528, 1461,
  918, 661, -1, -1, 468, 1101, 960, 528, 919, 602,
  20, 918, 984, 661, -1, 450, 1461, 986, -1, 609,
  -1, 521, -1, 57, 25, -1, 63, 25, -1, -1,
  532, 25, -1, -1, 410, 989, 995, -1, 276, -1,
  -1, 578, 991, 995, -1, 284, 997, -1, -1, 578,
  994, 995, -1, 997, -1, 411, 996, 372, -1, 997,
  -1, 996, 5, 997, -1, -1, 998, 999, -1, 576,
  -1, 293, -1, 311, -1, 285, -1, 466, -1, 422,
  -1, 609, -1, 532, -1, 521, -1, 446, -1, 419,
  -1, 522, -1, 537, -1, 501, -1, 291, -1, 292,
  -1, 24, -1, 491, -1, -1, -1, 580, 1002, 1099,
  1003, 13, 845, 1004, -1, 464, -1, 826, -1, 200,
  1075, -1, 189, 1075, -1, 203, 1075, -1, 431, 1075,
  314, -1, 431, 1075, 366, 907, -1, -1, 1011, 1010,
  1014, -1, -1, 1012, -1, 1013, -1, 1012, 1013, -1,
  954, -1, 1018, -1, 1034, -1, 1020, -1, -1, 1015,
  -1, 1017, -1, 1015, 1017, -1, 47, 919, -1, 1022,
  -1, 1028, -1, 1040, -1, 1194, -1, 1204, -1, 1061,
  -1, 1451, -1, 879, -1, 708, -1, 953, -1, 714,
  -1, 708, -1, 1451, -1, -1, 708, -1, 1451, -1,
  736, -1, 348, -1, 41, -1, -1, -1, -1, -1,
  1021, 1023, 919, 411, 1024, 1092, 372, 1025, 735, 1026,
  1019, 1471, 1027, -1, 191, -1, -1, -1, 539, 1029,
  735, 1030, 1471, 342, -1, 446, 822, -1, 845, -1,
  845, 825, -1, 337, 1372, -1, 1035, -1, 1036, -1,
  1035, 1036, -1, 1037, -1, 1018, -1, 1033, -1, -1,
  386, 1038, 1039, -1, 735, 223, -1, 907, -1, -1,
  -1, -1, 94, 919, 93, 919, 411, 1041, 1092, 372,
  1042, 735, 1043, 1019, 1471, 1027, -1, -1, 540, 1045,
  1060, 1051, 1046, -1, 343, -1, -1, 215, 1048, 1471,
  -1, -1, 22, 1052, 1053, 1054, 918, 1049, 1471, -1,
  -1, 22, 1052, 918, 1050, 1471, -1, 1047, -1, 1051,
  1047, -1, -1, 990, -1, 24, -1, 1075, -1, -1,
  1075, -1, 24, -1, 232, 1058, -1, 244, 1059, -1,
  227, 1059, -1, 567, -1, 24, -1, 1075, -1, 1058,
  -1, 1059, 5, 1058, -1, 1075, -1, 24, -1, -1,
  -1, 628, 919, 1062, 735, 1063, 1064, 629, -1, 1065,
  -1, 1064, 1065, -1, -1, 630, 1066, 1471, -1, -1,
  607, 919, 1067, 1471, -1, 1071, 1069, -1, -1, 662,
  1073, -1, 1074, -1, 1070, -1, 941, -1, 943, -1,
  945, -1, 937, -1, 939, -1, -1, 351, 1072, 826,
  -1, -1, 46, -1, 46, -1, 1076, -1, 1078, -1,
  171, 1078, -1, 1078, 602, -1, 1077, 1082, -1, 1077,
  919, 439, 1086, 407, -1, 1083, -1, 919, -1, 1079,
  -1, 919, 438, 1081, 406, -1, 919, 438, 1081, 406,
  -1, 1075, -1, 24, -1, 20, -1, 919, -1, 919,
  1085, -1, 919, 1085, -1, 439, 1086, 407, -1, 439,
  1086, 407, 439, 1086, 407, -1, 1087, -1, 1086, 5,
  1087, -1, 658, -1, 1089, -1, 1091, -1, 1089, 602,
  1090, -1, 1089, 602, 919, 439, 1086, 407, -1, 919,
  -1, 1080, -1, 20, -1, 919, -1, 919, 1085, -1,
  -1, 1093, -1, 1095, -1, 1093, 5, 1095, -1, 1096,
  -1, 1094, 5, 1096, -1, 919, -1, 919, 602, 919,
  -1, 1075, -1, 1075, 401, 1075, -1, 24, -1, 925,
  -1, 25, -1, 1098, -1, 1097, 5, 1098, -1, 1075,
  -1, 1075, 401, 1075, -1, 1100, -1, 1099, 5, 1100,
  -1, 1088, -1, 1075, -1, 1103, -1, 1102, 5, 1103,
  -1, 1075, 1104, -1, -1, 569, -1, 520, -1, 919,
  439, 1086, 407, -1, 1107, -1, 1106, 5, 1107, -1,
  1075, -1, 1075, 401, 1075, -1, 235, 915, 600, 909,
  561, 1463, 666, -1, -1, 600, 411, 827, 5, 827,
  372, 1110, -1, -1, 550, 411, 827, 5, 827, 372,
  -1, 236, 919, 1109, -1, 919, -1, 319, 917, 1114,
  -1, 1115, -1, 528, 827, -1, 1116, 1117, 1122, 8,
  1112, -1, -1, 600, 1118, 411, 827, 5, 827, 372,
  -1, -1, 538, 920, -1, -1, 331, -1, 198, 1414,
  247, 1446, 1121, -1, 545, 912, -1, 545, 912, 8,
  845, 825, -1, -1, 599, 558, 1408, 354, 1408, -1,
  599, 558, 1408, 5, 354, 1408, -1, 599, 1408, 5,
  1408, -1, -1, 631, -1, 632, -1, 71, 1446, 1124,
  1125, -1, -1, 599, 1446, -1, -1, 599, 558, 1408,
  8, 1408, -1, 558, 1408, 8, 1408, -1, 392, 1127,
  -1, 1128, -1, 1127, 5, 1128, -1, 184, 906, -1,
  265, 906, -1, 310, 906, -1, 318, 906, -1, 274,
  906, -1, 240, 906, -1, 992, -1, 419, 993, -1,
  430, 993, -1, 543, 993, -1, 355, 993, -1, 532,
  993, -1, 530, 907, -1, 531, 907, -1, 381, 662,
  -1, 647, 662, -1, 272, -1, 176, -1, 132, -1,
  109, -1, 127, -1, 118, -1, 1413, 394, 1132, 528,
  1130, -1, 1075, -1, 24, -1, 383, 1132, -1, 383,
  1132, 8, 1094, -1, 920, -1, -1, 442, 1141, 661,
  577, 1136, 1075, 918, 661, 1134, 1137, -1, 442, 1141,
  661, 325, 1075, -1, -1, 517, -1, -1, 1138, 263,
  -1, 1139, -1, 1138, 1139, -1, -1, 988, 1140, 1471,
  -1, 826, -1, -1, 586, 912, 1143, 1144, -1, -1,
  528, 1145, -1, 1146, -1, 1145, 5, 1146, -1, 1400,
  -1, 464, -1, 201, 1149, 69, -1, 201, 1149, 608,
  1148, -1, 201, 1149, 68, 1148, -1, 201, 1149, -1,
  24, -1, 924, -1, 919, -1, -1, 460, -1, 126,
  1149, 1150, 411, 845, 1032, 372, -1, 174, 1149, -1,
  48, 1149, -1, 1185, 1193, -1, 427, 42, -1, 427,
  1156, -1, 1157, -1, 1156, 1157, -1, -1, 114, 1158,
  1471, -1, -1, 180, 1159, 1471, -1, -1, 209, 1160,
  1471, -1, -1, 197, 1161, 1471, -1, -1, 234, 1162,
  1471, -1, -1, 182, 1075, 1163, 1471, -1, -1, 205,
  1075, 1164, 1471, -1, 1175, -1, 1177, -1, 1176, -1,
  1166, -1, 1202, -1, 1169, -1, -1, 542, 827, 1167,
  463, -1, -1, 463, -1, -1, 551, 827, 1170, 1168,
  -1, 139, -1, 611, 1189, -1, 142, 1189, -1, 141,
  1189, -1, -1, 1172, -1, 1173, -1, 1172, 1173, -1,
  1182, 1174, -1, -1, 600, 1189, -1, 500, 1171, 1181,
  -1, 499, 1408, 1181, -1, 498, 1180, 1179, 1178, 1181,
  -1, -1, 133, 820, -1, 133, 820, 5, 820, -1,
  595, -1, 596, -1, 597, -1, 598, -1, 1075, -1,
  -1, 503, -1, 1183, -1, 1182, 5, 1183, -1, 827,
  1216, -1, 591, 411, 820, 372, 1201, -1, 45, 1201,
  -1, 477, 411, 20, 372, 1201, -1, 393, 411, 20,
  372, 1201, -1, 368, 411, 820, 372, 1201, -1, 570,
  411, 820, 372, 1201, -1, 583, 411, 820, 372, 1201,
  -1, 582, 411, 820, 372, 1201, -1, -1, 441, 1186,
  -1, 1187, -1, 1186, 1187, -1, 208, 25, -1, 199,
  25, -1, 282, 25, -1, 165, 25, -1, 237, 25,
  -1, 157, -1, 324, 24, -1, 324, 1075, -1, 158,
  24, -1, 140, 24, -1, 1192, -1, 1188, 1192, -1,
  1190, 89, -1, 1190, 91, -1, 1190, 90, -1, 1190,
  -1, 925, -1, 25, -1, -1, 441, 1188, -1, 208,
  1189, -1, 199, 1189, -1, 282, 1189, -1, 165, 1189,
  -1, 237, 1189, -1, 238, 1189, -1, 610, 24, -1,
  611, 1189, -1, 615, -1, 612, -1, 613, -1, 614,
  -1, 619, -1, 616, -1, 617, -1, 618, -1, 58,
  1189, -1, 59, 1189, -1, 60, 1189, -1, 324, 24,
  -1, 158, 24, -1, 380, -1, 54, -1, 55, -1,
  -1, 495, 601, 1102, -1, 115, 1102, -1, -1, -1,
  -1, -1, -1, -1, 445, 1195, 919, 411, 1196, 1092,
  372, 1197, 735, 1198, 1154, 1199, 1155, 1200, 220, -1,
  -1, 507, 820, -1, 497, 1203, -1, -1, 1130, -1,
  -1, -1, -1, -1, -1, -1, 86, 1205, 919, 411,
  1206, 1092, 372, 1207, 735, 1208, 1211, 1209, 1155, 1210,
  220, -1, 1191, 1193, -1, -1, -1, -1, 135, 411,
  24, 5, 1213, 688, 1214, 372, 1215, 686, -1, -1,
  364, -1, 364, 199, 25, -1, 364, 199, 1075, -1,
  589, 827, -1, 589, 827, 325, 1075, -1, 589, 827,
  143, -1, 589, 827, 559, -1, 589, 827, 526, -1,
  1219, -1, 154, -1, 304, -1, 262, -1, 1226, -1,
  1221, -1, -1, -1, 187, 1222, 1357, 411, 1223, 1230,
  372, -1, -1, -1, 112, 1224, 1357, 411, 1225, 1230,
  372, 1227, -1, 84, 1228, 372, -1, 35, 920, -1,
  -1, 249, -1, 1229, -1, 1228, 5, 1229, -1, 919,
  569, -1, 919, 520, -1, 919, -1, 1231, -1, 1230,
  5, 1231, -1, 1310, -1, 1308, -1, 101, 919, -1,
  160, -1, 33, 919, 1234, -1, 1235, -1, 1234, 5,
  1235, -1, 1236, -1, 1239, -1, 1242, -1, 1247, -1,
  1248, -1, 1246, -1, 1245, -1, 566, 1237, -1, 566,
  411, 1238, 372, -1, 1231, -1, 1231, 646, 919, -1,
  1237, -1, 1238, 5, 1237, -1, 523, 1241, -1, 523,
  411, 1240, 372, -1, 1241, -1, 1240, 5, 1241, -1,
  919, -1, 435, 1244, -1, 435, 411, 1243, 372, -1,
  1244, -1, 1243, 5, 1244, -1, 1231, -1, 66, -1,
  67, -1, 65, 25, -1, 37, 1314, -1, 37, 411,
  1249, 372, -1, 38, 1250, -1, 38, 411, 1249, 372,
  -1, 1314, -1, 1249, 5, 1314, -1, 919, -1, 246,
  -1, 212, -1, 145, 1253, -1, 122, -1, 110, -1,
  100, -1, 98, -1, 102, -1, 159, 1414, -1, 211,
  1252, 440, 1408, 608, 1408, -1, 279, 912, 440, 1408,
  608, 1408, -1, -1, 1414, -1, -1, 827, -1, 504,
  827, -1, 210, -1, -1, 229, 1257, 1357, 1260, 1258,
  -1, -1, 460, 1259, 411, 1262, 372, -1, 1394, -1,
  -1, 411, 1261, 372, -1, 1360, -1, 1261, 5, 1360,
  -1, 1263, -1, 1262, 5, 1263, -1, 1400, -1, 464,
  -1, -1, -1, 481, 1265, 1267, 1266, 1268, -1, 1272,
  913, -1, 913, -1, -1, -1, 535, 1269, 1097, -1,
  -1, -1, 535, 1271, 1097, -1, 482, -1, 536, -1,
  543, -1, 355, -1, 322, -1, 376, -1, 358, 827,
  -1, 331, 827, -1, 218, 1357, 130, 913, -1, 218,
  1357, 1330, -1, 495, 601, 1276, -1, 1277, -1, 1276,
  5, 1277, -1, 1278, 1279, -1, 25, -1, 1360, -1,
  -1, 569, -1, 520, -1, 257, -1, 290, -1, -1,
  307, -1, 337, 1446, 1282, -1, -1, 1413, 1285, 1286,
  -1, 1315, -1, 1319, -1, 1281, -1, 1415, -1, 1280,
  -1, 1273, -1, 1274, -1, 1264, -1, 1256, -1, 1255,
  -1, 1384, -1, 1430, -1, 486, 1289, 607, 1357, 608,
  1294, 1288, -1, -1, 121, -1, 149, -1, 1290, -1,
  1291, -1, 1290, 5, 1291, -1, 452, -1, 430, -1,
  419, -1, 459, 1292, -1, -1, 411, 1293, 372, -1,
  1360, -1, 1293, 5, 1360, -1, 1295, -1, 1294, 5,
  1295, -1, 443, -1, 1358, -1, 216, 1357, 1297, 599,
  1394, 1299, -1, -1, 411, 1298, 372, -1, 1360, -1,
  1298, 5, 1360, -1, -1, 120, -1, 473, 411, 1333,
  372, -1, 226, 411, 1303, 372, 1302, -1, 277, 1304,
  -1, 1305, -1, 1357, -1, 1357, 411, 1305, 372, -1,
  1360, -1, 1305, 5, 1360, -1, 457, 411, 1307, 372,
  -1, 239, 411, 1307, 372, -1, 1360, -1, 1307, 5,
  1360, -1, 1306, -1, 1301, -1, 1300, -1, 380, 1363,
  -1, 188, -1, 919, 1349, 1311, 1312, -1, -1, 1309,
  -1, -1, 1313, -1, 1314, -1, 1313, 1314, -1, 353,
  -1, 138, -1, 1302, -1, 473, 411, 1333, 372, -1,
  99, 1316, 1318, -1, 1317, -1, 1358, -1, 1319, -1,
  1318, 1319, -1, 1296, -1, 1287, -1, 428, 1333, -1,
  349, 1322, -1, 1399, -1, 1322, 5, 1399, -1, 507,
  1333, -1, 528, 1325, -1, 1326, -1, 1325, 5, 1326,
  -1, 1327, -1, 496, 1327, -1, 496, 411, 1328, 372,
  -1, 1357, -1, 1357, 1362, -1, 1326, -1, 1328, 5,
  1326, -1, 1324, 1330, 1331, 1332, -1, -1, 1323, -1,
  -1, 1321, -1, -1, 1320, -1, 1334, -1, 1333, 6,
  1334, -1, 1335, -1, 1334, 7, 1335, -1, 1336, -1,
  584, 1336, -1, 1347, -1, 411, 1333, 372, -1, 423,
  1395, -1, 275, 1395, -1, -1, 422, 1340, -1, 1404,
  -1, 919, -1, 1404, -1, 1400, 605, 411, 1342, 372,
  -1, 1400, 605, 1395, -1, 1400, 409, 411, 1342, 372,
  -1, 1400, 409, 1395, -1, 1343, -1, 1342, 5, 1343,
  -1, 1450, -1, 1363, -1, -1, 584, -1, 1400, 1344,
  367, -1, 1400, 1344, 230, -1, 1400, 1346, 1400, -1,
  1400, 1344, 369, 1400, 7, 1400, -1, 1400, 538, 1339,
  1338, -1, 1400, 352, 1339, 1338, -1, 1400, 1344, 9,
  1339, 1338, -1, 13, -1, 16, -1, 11, -1, 12,
  -1, 233, -1, 9, -1, 15, -1, 14, -1, 1345,
  -1, 1341, -1, 1337, -1, -1, 567, -1, 340, -1,
  457, -1, 1350, -1, 1351, -1, 1353, -1, 517, -1,
  517, 411, 1354, 372, -1, 391, 411, 1355, 1352, 372,
  -1, 453, -1, 378, 411, 1355, 1352, 372, -1, 493,
  411, 1355, 1352, 372, -1, 519, -1, 388, -1, 360,
  -1, 338, 1370, 608, 1371, -1, 338, -1, 350, 1370,
  608, 1371, -1, 350, -1, 350, 1370, 411, 25, 372,
  608, 1371, -1, 556, -1, 514, -1, 404, -1, 404,
  411, 25, 372, -1, 404, 411, 25, 5, 25, 372,
  -1, -1, 5, 1356, -1, 483, 411, 1355, 372, -1,
  547, -1, 280, -1, 483, -1, 44, -1, 25, -1,
  25, -1, 25, -1, 24, 602, 919, -1, 24, -1,
  919, -1, 919, 571, 919, -1, 919, -1, -1, 439,
  25, 407, -1, 439, 25, 5, 25, 407, -1, 1361,
  -1, 594, 1361, -1, 919, 1359, -1, 1357, 602, 919,
  1359, -1, 1357, 602, 20, -1, 919, -1, 24, -1,
  391, -1, 925, -1, 25, -1, 1365, -1, 376, 1367,
  -1, 376, 1366, -1, -1, 1370, 608, 1371, -1, -1,
  1368, 608, 1368, -1, 563, -1, 494, -1, 572, -1,
  534, -1, 434, -1, 451, -1, 347, -1, 347, 411,
  25, 372, -1, 563, -1, 494, -1, 572, -1, 534,
  -1, 434, -1, 451, -1, 347, -1, 347, 411, 25,
  372, -1, 563, -1, 494, -1, 572, -1, 534, -1,
  434, -1, 451, -1, 347, -1, 563, -1, 494, -1,
  572, -1, 534, -1, 434, -1, 451, -1, 347, -1,
  919, -1, 24, -1, 1413, 484, 913, -1, -1, 1413,
  379, 913, 417, 577, 1382, 1375, 1379, -1, -1, 1413,
  379, 913, 417, 81, 577, 1383, 1376, 1379, -1, -1,
  1413, 379, 913, 116, 1383, 1377, 1379, -1, -1, 1413,
  379, 913, 117, 81, 577, 1383, 1378, 1379, -1, -1,
  269, -1, 268, 1380, -1, 1381, -1, 1380, 5, 1381,
  -1, 919, -1, 919, 602, 919, -1, 24, 602, 919,
  602, 919, -1, 1383, -1, 1256, -1, 1132, -1, 1385,
  -1, 1385, 1379, -1, -1, -1, 452, 1396, 1386, 1397,
  1387, 1393, 1329, 1391, -1, 452, 1396, 1397, 1329, 1391,
  -1, 1390, -1, 1408, -1, 452, 1396, 1397, 1393, 1329,
  1391, -1, -1, 506, 1348, 1389, -1, 1275, -1, 312,
  1392, 1227, -1, 1275, 312, 1392, 1227, -1, 919, -1,
  -1, 535, 1097, -1, 452, 1396, 1397, 1329, -1, 411,
  452, 1396, 1397, 1329, 372, -1, -1, 567, -1, 340,
  -1, 457, -1, 1398, -1, 1397, 5, 1398, -1, 1400,
  -1, 1400, 1470, -1, 1400, 926, -1, 1400, -1, 1401,
  -1, 18, 1401, -1, 17, 1401, -1, 1402, -1, 1450,
  -1, 1395, -1, 594, 919, -1, 594, 919, 602, 919,
  -1, 1401, 19, 1400, -1, 1401, 1422, -1, 1401, 20,
  1400, -1, 1401, 17, 1400, -1, 1401, 18, 1400, -1,
  1363, -1, 465, -1, 408, -1, 558, -1, 20, -1,
  45, -1, 570, 411, 1348, 1400, 372, -1, 582, 411,
  1348, 1400, 372, -1, 583, 411, 1348, 1400, 372, -1,
  591, 411, 1348, 1400, 372, -1, 477, 411, 1348, 1400,
  372, -1, 919, 411, 1403, 372, -1, 519, 411, 1403,
  372, -1, 411, 1400, 372, -1, 424, 411, 1423, 372,
  -1, 1400, -1, 1403, 5, 1400, -1, -1, 1363, -1,
  1413, 327, 1412, 1407, 1389, -1, 1413, 316, 1412, 1407,
  229, 1357, 1409, -1, 1413, 316, 1412, 1407, 1075, -1,
  -1, 302, 1408, -1, 24, -1, 1075, -1, -1, 411,
  1410, 372, -1, 1411, -1, 1410, 5, 1411, -1, 919,
  -1, 24, -1, 1075, -1, -1, 248, 1414, 577, -1,
  920, -1, 1420, -1, 1419, -1, 1416, -1, 297, 1417,
  608, 1417, -1, 278, 1417, 602, 1418, 608, 1418, -1,
  919, -1, 919, -1, 202, 770, -1, 273, 770, 1421,
  -1, 252, -1, 156, -1, 73, -1, 74, -1, 75,
  -1, 76, -1, 77, -1, 78, -1, 376, 5, 1370,
  608, 1371, -1, 1360, 5, 1370, 608, 1371, -1, 376,
  1370, 608, 1371, -1, -1, 590, 1425, 1426, 170, -1,
  1427, -1, 1426, 1427, -1, 32, -1, 1428, -1, 1429,
  -1, 171, 1450, -1, 535, 1097, -1, -1, -1, 459,
  1357, 1431, 565, 1434, 1432, 1433, -1, -1, 130, 913,
  -1, 507, 1333, -1, 411, 1438, 372, 13, 411, 1439,
  372, -1, 20, 13, 411, 1439, 372, -1, 1435, -1,
  20, 13, 1439, -1, 1437, -1, 1435, 5, 1437, -1,
  1360, -1, 1436, 13, 1440, -1, 1436, -1, 1438, 5,
  1436, -1, 1440, -1, 1439, 5, 1440, -1, 464, -1,
  1441, -1, 1442, -1, 18, 1442, -1, 17, 1442, -1,
  1444, -1, 1443, -1, 1395, -1, 594, 919, -1, 594,
  919, 602, 919, -1, 1442, 19, 1442, -1, 1442, 1422,
  -1, 1442, 20, 1442, -1, 1442, 17, 1442, -1, 1442,
  18, 1442, -1, 1363, -1, 465, -1, 408, -1, 558,
  -1, 20, -1, 45, -1, 570, 411, 1348, 1441, 372,
  -1, 582, 411, 1348, 1441, 372, -1, 583, 411, 1348,
  1441, 372, -1, 591, 411, 1348, 1441, 372, -1, 477,
  411, 1348, 1441, 372, -1, 919, 411, 1445, 372, -1,
  519, 411, 1445, 372, -1, 411, 1441, 372, -1, 424,
  411, 1423, 372, -1, 1450, -1, 1441, -1, 1445, 5,
  1441, -1, 1447, -1, 171, 1448, -1, 1448, -1, 1084,
  -1, 919, -1, 1448, 602, 1449, -1, 24, 602, 1448,
  602, 1449, -1, 20, -1, 1105, -1, 919, -1, 1447,
  -1, 1447, 401, 1447, -1, 107, 1452, -1, 111, 1452,
  -1, 106, 1452, -1, 146, -1, 147, 1452, -1, 104,
  1452, -1, 129, 1452, -1, 128, 1452, -1, 103, 1452,
  -1, 336, -1, 603, 608, 1453, -1, 529, 1453, -1,
  554, -1, 515, 1454, -1, 919, -1, 571, 919, -1,
  919, -1, -1, -1, 508, 1456, 827, 1457, 1471, 306,
  -1, -1, 641, 1461, -1, -1, 644, -1, 162, -1,
  258, 914, -1, 50, 914, -1, 288, -1, 287, -1,
  289, 916, 1458, 1459, -1, 474, 1461, 1459, -1, 911,
  -1, 1461, 5, 911, -1, 83, -1, 113, 914, -1,
  827, 548, 5, 827, 373, -1, 490, 827, -1, 245,
  914, -1, 82, 1466, 8, 1467, 1465, -1, -1, 528,
  827, -1, 919, -1, 919, -1, 228, 914, -1, 231,
  914, 608, 827, 5, 827, -1, 231, 914, 601, 827,
  5, 827, -1, 26, -1, -1, 1473, -1, 1474, 1181,
  -1, 1472, -1, 1473, 1472, -1, -1, 1475, 1476, -1,
  651, -1, 652, -1, 653, -1, 654, -1, 671, -1,
  693, -1, 707, -1, 708, -1, 714, -1, 715, -1,
  734, -1, 802, -1, 803, -1, 804, -1, 805, -1,
  816, -1, 817, -1, 818, -1, 819, -1, 871, -1,
  875, -1, 905, -1, 927, -1, 928, -1, 931, -1,
  932, -1, 933, -1, 934, -1, 947, -1, 955, -1,
  978, -1, 979, -1, 981, -1, 985, -1, 1000, -1,
  1001, -1, 1005, -1, 1006, -1, 1007, -1, 1008, -1,
  1016, -1, 1031, -1, 1044, -1, 1055, -1, 1056, -1,
  1057, -1, 1068, -1, 1108, -1, 1111, -1, 1113, -1,
  1119, -1, 1120, -1, 1123, -1, 1126, -1, 1129, -1,
  1131, -1, 1133, -1, 1135, -1, 1142, -1, 1147, -1,
  1151, -1, 1152, -1, 1153, -1, 1165, -1, 1217, -1,
  1218, -1, 1220, -1, 1232, -1, 1233, -1, 1251, -1,
  1254, -1, 1283, -1, 1284, -1, 1373, -1, 1374, -1,
  1405, -1, 1406, -1, 1424, -1, 1451, -1, 1455, -1,
  1460, -1, 1462, -1, 1464, -1, 1468, -1, 1469, -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] = {
  0, 898, 898, 901, 904, 910, 916, 923, 927, 927,
  933, 951, 952, 953, 954, 955, 969, 970, 971, 972,
  973, 978, 979, 990, 993, 996, 996, 1000, 1003, 1004,
  1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019,
  1020, 1021, 1022, 1023, 1024, 1025, 1028, 1029, 1032, 1032,
  1040, 1041, 1044, 1050, 1052, 1063, 1065, 1067, 1069, 1073,
  1075, 1137, 1141, 1145, 1145, 1156, 1160, 1164, 1165, 1168,
  1174, 1168, 1187, 1192, 1196, 1187, 1208, 1212, 1208, 1220,
  1225, 1220, 1244, 1251, 1255, 1243, 1281, 1281, 1285, 1286,
  1287, 1292, 1295, 1300, 1304, 1312, 1315, 1315, 1321, 1325,
  1340, 1338, 1356, 1356, 1371, 1371, 1374, 1374, 1378, 1381,
  1381, 1381, 1388, 1389, 1388, 1396, 1396, 1407, 1407, 1426,
  1429, 1432, 1435, 1438, 1441, 1454, 1459, 1459, 1460, 1460,
  1463, 1468, 1468, 1472, 1482, 1496, 1500, 1495, 1510, 1516,
  1524, 1525, 1528, 1528, 1531, 1535, 1540, 1547, 1547, 1551,
  1551, 1558, 1558, 1563, 1563, 1568, 1568, 1573, 1573, 1586,
  1587, 1595, 1596, 1613, 1616, 1619, 1622, 1625, 1628, 1634,
  1645, 1650, 1663, 1667, 1682, 1683, 1687, 1687, 1691, 1691,
  1691, 1692, 1693, 1698, 1698, 1701, 1701, 1710, 1711, 1712,
  1715, 1719, 1720, 1720, 1737, 1737, 1737, 1737, 1741, 1748,
  1749, 1752, 1752, 1755, 1755, 1764, 1761, 1777, 1777, 1779,
  1779, 1781, 1783, 1785, 1787, 1790, 1794, 1794, 1795, 1795,
  1799, 1799, 1811, 1811, 1816, 1820, 1822, 1823, 1826, 1826,
  1826, 1830, 1831, 1832, 1833, 1840, 1841, 1842, 1843, 1846,
  1847, 1848, 1849, 1853, 1858, 1863, 1867, 1870, 1874, 1875,
  1876, 1877, 1878, 1879, 1880, 1881, 1884, 1885, 1886, 1918,
  1922, 1924, 1926, 1926, 1933, 1937, 1937, 1941, 1942, 1943,
  1944, 1945, 1946, 1947, 1953, 1953, 1956, 1958, 1964, 1966,
  1972, 1980, 1980, 1983, 1984, 1985, 1986, 1987, 1988, 1989,
  1995, 1998, 1998, 2011, 2011, 2018, 2019, 2020, 2022, 2023,
  2025, 2027, 2028, 2029, 2030, 2035, 2041, 2047, 2048, 2050,
  2052, 2053, 2054, 2055, 2056, 2057, 2060, 2061, 2068, 2076,
  2076, 2084, 2081, 2096, 2096, 2098, 2098, 2106, 2106, 2109,
  2112, 2113, 2118, 2130, 2134, 2137, 2140, 2141, 2142, 2143,
  2144, 2149, 2156, 2162, 2167, 2171, 2167, 2182, 2184, 2189,
  2194, 2194, 2198, 2198, 2201, 2201, 2207, 2207, 2213, 2213,
  2229, 2232, 2246, 2248, 2250, 2252, 2254, 2256, 2258, 2264,
  2266, 2270, 2272, 2274, 2276, 2278, 2280, 2282, 2288, 2303,
  2306, 2319, 2320, 2321, 2322, 2323, 2327, 2328, 2329, 2333,
  2338, 2345, 2346, 2347, 2348, 2349, 2350, 2351, 2352, 2353,
  2354, 2359, 2359, 2364, 2364, 2367, 2373, 2381, 2387, 2397,
  2398, 2406, 2413, 2417, 2427, 2431, 2436, 2441, 2443, 2453,
  2466, 2474, 2487, 2492, 2498, 2503, 2508, 2509, 2515, 2586,
  2592, 2597, 2605, 2605, 2620, 2624, 2631, 2634, 2642, 2653,
  2663, 2669, 2678, 2683, 2691, 2694, 2697, 2702, 2709, 2714,
  2719, 2724, 2734, 2742, 2750, 2755, 2759, 2764, 2768, 2772,
  2779, 2782, 2785, 2789, 2793, 2797, 2801, 2809, 2819, 2824,
  2817, 2840, 2845, 2840, 2862, 2862, 2862, 2865, 2865, 2865,
  2868, 2868, 2868, 2871, 2871, 2871, 2874, 2880, 2886, 2892,
  2902, 2902, 2906, 2910, 2911, 2917, 2918, 2923, 2926, 2930,
  2934, 2935, 2938, 2943, 2949, 2953, 2957, 2960, 2966, 2969,
  2972, 2987, 2990, 2996, 2997, 2998, 3002, 3003, 3004, 3005,
  3006, 3008, 3009, 3010, 3012, 3013, 3017, 3018, 3023, 3024,
  3036, 3040, 3035, 3048, 3051, 3065, 3069, 3074, 3064, 3094,
  3100, 3094, 3114, 3114, 3116, 3117, 3121, 3121, 3125, 3125,
  3130, 3130, 3137, 3138, 3142, 3142, 3146, 3146, 3151, 3151,
  3158, 3162, 3163, 3164, 3169, 3169, 3172, 3172, 3176, 3176,
  3180, 3180, 3184, 3184, 3189, 3189, 3194, 3194, 3199, 3199,
  3204, 3204, 3220, 3237, 3238, 3239, 3240, 3241, 3242, 3245,
  3245, 3248, 3250, 3253, 3256, 3258, 3259, 3260, 3262, 3264,
  3266, 3268, 3272, 3279, 3281, 3287, 3292, 3297, 3302, 3302,
  3305, 3311, 3316, 3319, 3326, 3326, 3328, 3329, 3331, 3333,
  3335, 3337, 3341, 3350, 3350, 3357, 3358, 3359, 3360, 3361,
  3362, 3363, 3364, 3365, 3366, 3367, 3368, 3369, 3370, 3371,
  3372, 3373, 3374, 3375, 3376, 3377, 3378, 3379, 3380, 3381,
  3382, 3383, 3384, 3385, 3386, 3387, 3388, 3389, 3390, 3391,
  3392, 3393, 3394, 3395, 3396, 3397, 3398, 3399, 3411, 3424,
  3431, 3431, 3435, 3440, 3446, 3450, 3454, 3460, 3464, 3468,
  3474, 3474, 3482, 3483, 3487, 3487, 3491, 3492, 3495, 3498,
  3498, 3501, 3503, 3503, 3506, 3508, 3508, 3509, 3511, 3511,
  3520, 3518, 3530, 3530, 3530, 3533, 3535, 3533, 3542, 3545,
  3551, 3562, 3562, 3566, 3572, 3572, 3576, 3577, 3588, 3589,
  3591, 3593, 3598, 3598, 3602, 3601, 3608, 3607, 3613, 3613,
  3618, 3618, 3624, 3624, 3629, 3629, 3634, 3634, 3639, 3639,
  3644, 3644, 3652, 3653, 3661, 3662, 3667, 3668, 3677, 3678,
  3685, 3686, 3694, 3695, 3704, 3709, 3714, 3715, 3716, 3720,
  3719, 3730, 3735, 3740, 3740, 3751, 3756, 3757, 3758, 3759,
  3762, 3762, 3768, 3768, 3770, 3773, 3773, 3775, 3779, 3779,
  3782, 3783, 3786, 3786, 3791, 3791, 3794, 3795, 3796, 3797,
  3798, 3799, 3800, 3801, 3802, 3803, 3804, 3805, 3806, 3807,
  3808, 3809, 3810, 3814, 3832, 3832, 3832, 3858, 3869, 3876,
  3882, 3888, 3894, 3905, 3928, 3927, 3944, 3944, 3948, 3949,
  3957, 3958, 3959, 3960, 3967, 3968, 3970, 3971, 3975, 3980,
  3981, 3982, 3983, 3984, 3985, 3986, 3987, 3988, 3989, 3990,
  3993, 3993, 3995, 3995, 3995, 3997, 4001, 4001, 4010, 4015,
  4031, 4037, 4009, 4051, 4065, 4075, 4064, 4088, 4095, 4095,
  4100, 4105, 4110, 4111, 4114, 4114, 4114, 4117, 4117, 4125,
  4131, 4145, 4149, 4162, 4144, 4180, 4180, 4193, 4204, 4203,
  4215, 4211, 4228, 4225, 4238, 4238, 4240, 4241, 4243, 4244,
  4247, 4248, 4249, 4251, 4256, 4261, 4267, 4269, 4270, 4273,
  4274, 4277, 4279, 4288, 4294, 4288, 4305, 4306, 4310, 4310,
  4320, 4320, 4332, 4335, 4339, 4343, 4348, 4352, 4353, 4354,
  4355, 4356, 4360, 4360, 4362, 4362, 4365, 4374, 4422, 4422,
  4425, 4429, 4434, 4475, 4476, 4477, 4480, 4494, 4506, 4506,
  4511, 4512, 4518, 4574, 4630, 4635, 4642, 4647, 4655, 4661,
  4690, 4693, 4694, 4735, 4736, 4740, 4741, 4745, 4798, 4802,
  4805, 4811, 4822, 4829, 4837, 4837, 4840, 4841, 4842, 4843,
  4844, 4847, 4850, 4856, 4859, 4863, 4867, 4874, 4879, 4886,
  4889, 4895, 4897, 4897, 4897, 4901, 4921, 4928, 4935, 4938,
  4952, 4959, 4960, 4963, 4964, 4968, 4974, 4979, 4985, 4986,
  4991, 4995, 4995, 4999, 5000, 5003, 5004, 5008, 5016, 5019,
  5025, 5026, 5028, 5030, 5034, 5034, 5035, 5040, 5048, 5049,
  5054, 5055, 5057, 5070, 5072, 5073, 5075, 5078, 5081, 5084,
  5087, 5090, 5093, 5097, 5101, 5105, 5108, 5112, 5115, 5116,
  5117, 5120, 5123, 5126, 5129, 5132, 5135, 5138, 5154, 5162,
  5162, 5164, 5171, 5178, 5193, 5191, 5211, 5216, 5217, 5221,
  5222, 5224, 5225, 5227, 5227, 5235, 5244, 5244, 5254, 5255,
  5258, 5259, 5262, 5266, 5280, 5285, 5290, 5295, 5305, 5305,
  5309, 5312, 5312, 5314, 5324, 5333, 5340, 5342, 5346, 5349,
  5349, 5353, 5352, 5356, 5355, 5359, 5358, 5362, 5361, 5365,
  5364, 5367, 5367, 5383, 5382, 5404, 5405, 5406, 5407, 5408,
  5409, 5412, 5412, 5418, 5418, 5421, 5421, 5431, 5432, 5433,
  5440, 5452, 5453, 5456, 5457, 5460, 5463, 5463, 5468, 5472,
  5477, 5483, 5484, 5485, 5489, 5490, 5491, 5492, 5496, 5506,
  5508, 5513, 5516, 5521, 5527, 5534, 5541, 5550, 5557, 5564,
  5571, 5578, 5587, 5587, 5589, 5589, 5592, 5593, 5594, 5595,
  5596, 5597, 5598, 5599, 5600, 5601, 5604, 5604, 5607, 5608,
  5609, 5610, 5613, 5613, 5616, 5616, 5619, 5620, 5621, 5622,
  5623, 5624, 5625, 5626, 5628, 5629, 5630, 5631, 5633, 5634,
  5635, 5636, 5638, 5639, 5640, 5641, 5642, 5643, 5644, 5645,
  5649, 5655, 5663, 5674, 5683, 5694, 5698, 5702, 5708, 5673,
  5721, 5724, 5732, 5744, 5746, 5751, 5759, 5769, 5772, 5776,
  5784, 5750, 5793, 5797, 5801, 5805, 5797, 5815, 5816, 5817,
  5818, 5823, 5825, 5828, 5832, 5835, 5842, 5847, 5848, 5849,
  5854, 5855, 5861, 5861, 5861, 5866, 5866, 5866, 5877, 5878,
  5884, 5885, 5891, 5892, 5897, 5898, 5899, 5903, 5906, 5912,
  5915, 5923, 5924, 5930, 5937, 5940, 5949, 5952, 5955, 5958,
  5961, 5964, 5967, 5974, 5977, 5984, 5987, 5993, 5996, 6003,
  6006, 6013, 6014, 6019, 6023, 6026, 6032, 6035, 6041, 6048,
  6049, 6053, 6059, 6062, 6069, 6070, 6077, 6080, 6085, 6096,
  6097, 6098, 6099, 6100, 6101, 6102, 6103, 6104, 6107, 6110,
  6116, 6116, 6122, 6122, 6133, 6146, 6156, 6156, 6161, 6161,
  6165, 6169, 6170, 6176, 6177, 6182, 6186, 6193, 6196, 6203,
  6207, 6202, 6219, 6223, 6230, 6234, 6234, 6247, 6251, 6251,
  6266, 6268, 6270, 6272, 6274, 6276, 6278, 6280, 6286, 6296,
  6303, 6308, 6309, 6313, 6315, 6316, 6319, 6320, 6321, 6324,
  6329, 6336, 6337, 6343, 6356, 6356, 6361, 6366, 6371, 6372,
  6375, 6376, 6381, 6386, 6390, 6395, 6396, 6400, 6407, 6411,
  6412, 6417, 6419, 6423, 6424, 6428, 6429, 6430, 6431, 6435,
  6436, 6441, 6442, 6447, 6448, 6453, 6454, 6459, 6464, 6465,
  6470, 6471, 6475, 6476, 6481, 6488, 6493, 6498, 6502, 6503,
  6508, 6509, 6515, 6517, 6522, 6523, 6529, 6532, 6535, 6542,
  6544, 6556, 6561, 6562, 6565, 6567, 6574, 6577, 6583, 6587,
  6591, 6594, 6601, 6608, 6613, 6617, 6618, 6624, 6627, 6638,
  6645, 6651, 6654, 6661, 6668, 6674, 6675, 6681, 6682, 6683,
  6686, 6687, 6692, 6692, 6696, 6704, 6705, 6708, 6711, 6716,
  6717, 6722, 6725, 6731, 6734, 6740, 6743, 6749, 6752, 6759,
  6760, 6789, 6790, 6795, 6796, 6800, 6805, 6808, 6811, 6814,
  6820, 6821, 6825, 6828, 6831, 6832, 6837, 6840, 6843, 6846,
  6849, 6852, 6855, 6861, 6862, 6863, 6864, 6865, 6867, 6869,
  6870, 6875, 6878, 6882, 6888, 6889, 6890, 6891, 6903, 6904,
  6905, 6909, 6910, 6915, 6917, 6918, 6919, 6921, 6922, 6923,
  6924, 6926, 6927, 6929, 6930, 6932, 6933, 6934, 6935, 6937,
  6941, 6942, 6948, 6950, 6951, 6952, 6953, 6958, 6962, 6966,
  6970, 6971, 6975, 6976, 6986, 6994, 6995, 6996, 7000, 7003,
  7008, 7013, 7018, 7026, 7030, 7034, 7035, 7036, 7041, 7044,
  7047, 7051, 7052, 7056, 7057, 7061, 7061, 7061, 7061, 7061,
  7061, 7062, 7065, 7070, 7070, 7070, 7070, 7070, 7070, 7072,
  7075, 7081, 7081, 7081, 7081, 7081, 7081, 7081, 7082, 7082,
  7082, 7082, 7082, 7082, 7082, 7084, 7085, 7088, 7097, 7097,
  7102, 7102, 7108, 7108, 7113, 7113, 7120, 7121, 7122, 7125,
  7125, 7128, 7129, 7130, 7135, 7138, 7144, 7147, 7155, 7168,
  7169, 7166, 7187, 7197, 7200, 7205, 7217, 7220, 7224, 7227,
  7228, 7234, 7237, 7238, 7247, 7256, 7261, 7262, 7263, 7264,
  7272, 7275, 7281, 7284, 7287, 7293, 7302, 7305, 7308, 7314,
  7320, 7323, 7326, 7329, 7335, 7337, 7339, 7341, 7343, 7345,
  7346, 7347, 7348, 7349, 7350, 7351, 7353, 7355, 7357, 7359,
  7361, 7363, 7365, 7366, 7371, 7372, 7378, 7379, 7382, 7391,
  7395, 7402, 7402, 7406, 7406, 7411, 7411, 7415, 7415, 7419,
  7425, 7425, 7428, 7428, 7434, 7441, 7442, 7443, 7447, 7448,
  7451, 7452, 7456, 7462, 7472, 7473, 7481, 7482, 7483, 7484,
  7485, 7486, 7490, 7491, 7492, 7496, 7496, 7508, 7509, 7513,
  7514, 7515, 7519, 7525, 7612, 7617, 7612, 7628, 7633, 7640,
  7649, 7659, 7670, 7673, 7696, 7699, 7705, 7708, 7713, 7716,
  7724, 7731, 7743, 7747, 7755, 7758, 7761, 7769, 7774, 7779,
  7783, 7787, 7795, 7796, 7797, 7798, 7799, 7800, 7801, 7802,
  7803, 7804, 7805, 7806, 7807, 7808, 7809, 7810, 7811, 7812,
  7813, 7814, 7818, 7824, 7825, 7837, 7849, 7849, 7853, 7854,
  7855, 7856, 7860, 7861, 7862, 7867, 7881, 7932, 7934, 7936,
  7938, 7942, 7947, 7949, 7951, 7953, 7957, 7960, 7965, 7970,
  7974, 7983, 7984, 7988, 8000, 8003, 7999, 8022, 8022, 8026,
  8027, 8030, 8031, 8032, 8033, 8034, 8035, 8036, 8041, 8042,
  8046, 8049, 8054, 8058, 8063, 8067, 8072, 8076, 8079, 8083,
  8086, 8091, 8095, 8106, 8112, 8112, 8113, 8114, 8121, 8130,
  8130, 8132, 8133, 8134, 8135, 8136, 8137, 8138, 8139, 8140,
  8141, 8142, 8143, 8144, 8145, 8146, 8147, 8148, 8149, 8150,
  8151, 8152, 8153, 8154, 8155, 8156, 8157, 8158, 8159, 8160,
  8161, 8162, 8163, 8164, 8165, 8166, 8167, 8168, 8169, 8170,
  8171, 8172, 8173, 8174, 8175, 8176, 8177, 8178, 8179, 8180,
  8181, 8182, 8183, 8184, 8185, 8186, 8187, 8188, 8189, 8190,
  8191, 8192, 8193, 8194, 8195, 8196, 8197, 8198, 8199, 8200,
  8201, 8202, 8203, 8204, 8205, 8206, 8207, 8208, 8209, 8210,
  8211, 8212, 8213, 8214, 8215, 8216
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] = {
  "$end", "error", "$undefined", "NAME", "UMINUS", "COMMA", "KW_OR",
  "KW_AND", "KW_USING", "MATCHES", "POWER", "LESS_THAN", "GREATER_THAN",
  "EQUAL", "GREATER_THAN_EQ", "LESS_THAN_EQ", "NOT_EQUAL", "PLUS",
  "MINUS", "DIVIDE", "MULTIPLY", "MOD", "COMMAND", "NUMBER_VALUE",
  "CHAR_VALUE", "INT_VALUE", "NAMED_GEN", "CLINE", "SQLLINE", "KW_CSTART",
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "ALTER_TABLE", "NEWFORMATSHARED",
  "CREATE_DATABASE", "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT",
  "DROP_CONSTRAINT", "AS_STATIC", "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION",
  "EVERY_ROW", "ELIF", "DOUBLE_PRECISION", "COUNT_MULTIPLY",
  "WAIT_FOR_KEY", "AT_TERMINATION_CALL", "TERMINATE_REPORT",
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
  "op_exclusive", "set_database_cmd", "sql_cmd", "@162", "sql_commands",
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
static const unsigned short yytoknum[] = {
  0, 256, 1635, 1636, 1637, 1552, 1592, 1547, 1483, 1361,
  1469, 1465, 1379, 1542, 1278, 1336, 1410, 1578, 1565, 1498,
  1470, 1566, 1343, 1638, 1639, 1640, 1641, 1642, 1643, 1644,
  1645, 1646, 1647, 1000, 1001, 1002, 1003, 1004, 1005, 1006,
  1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016,
  1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026,
  1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036,
  1037, 1038, 1039, 1040, 1041, 1042, 1043, 1044, 1045, 1046,
  1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056,
  1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066,
  1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076,
  1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086,
  1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096,
  1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106,
  1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116,
  1117, 1118, 1119, 1120, 1121, 1122, 1123, 1124, 1125, 1126,
  1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134, 1135, 1136,
  1137, 1138, 1139, 1140, 1141, 1142, 1143, 1144, 1145, 1146,
  1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156,
  1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166,
  1167, 1168, 1169, 1170, 1171, 1172, 1173, 1174, 1175, 1176,
  1177, 1178, 1179, 1180, 1181, 1182, 1183, 1184, 1185, 1186,
  1187, 1188, 1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196,
  1197, 1198, 1199, 1200, 1201, 1202, 1203, 1204, 1205, 1206,
  1207, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216,
  1217, 1218, 1219, 1220, 1221, 1222, 1223, 1224, 1225, 1226,
  1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235, 1236,
  1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245, 1246,
  1247, 1248, 1249, 1250, 1251, 1252, 1253, 1254, 1255, 1256,
  1257, 1258, 1259, 1260, 1261, 1262, 1263, 1264, 1265, 1266,
  1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276,
  1277, 1279, 1280, 1281, 1282, 1283, 1284, 1285, 1286, 1287,
  1288, 1289, 1290, 1291, 1292, 1293, 1294, 1295, 1296, 1297,
  1298, 1299, 1300, 1301, 1302, 1303, 1304, 1305, 1306, 1307,
  1308, 1309, 1310, 1311, 1312, 1313, 1314, 1315, 1316, 1317,
  1318, 1319, 1320, 1321, 1322, 1323, 1324, 1325, 1326, 1327,
  1328, 1329, 1330, 1331, 1332, 1333, 1334, 1335, 1337, 1338,
  1339, 1340, 1341, 1342, 1344, 1345, 1346, 1347, 1348, 1349,
  1350, 1351, 1352, 1353, 1354, 1355, 1356, 1357, 1358, 1359,
  1360, 1362, 1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370,
  1371, 1372, 1373, 1374, 1375, 1376, 1377, 1378, 1380, 1381,
  1382, 1383, 1384, 1385, 1386, 1387, 1388, 1389, 1390, 1391,
  1392, 1393, 1394, 1395, 1396, 1397, 1398, 1399, 1400, 1401,
  1402, 1403, 1404, 1405, 1406, 1407, 1408, 1409, 1411, 1412,
  1413, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 1422,
  1423, 1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, 1432,
  1433, 1434, 1435, 1436, 1437, 1438, 1439, 1440, 1441, 1442,
  1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450, 1451, 1452,
  1453, 1454, 1455, 1456, 1457, 1458, 1459, 1460, 1461, 1462,
  1463, 1464, 1466, 1467, 1468, 1471, 1472, 1473, 1474, 1475,
  1476, 1477, 1478, 1479, 1480, 1481, 1482, 1484, 1485, 1486,
  1487, 1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496,
  1497, 1499, 1500, 1501, 1502, 1503, 1504, 1505, 1506, 1507,
  1508, 1509, 1510, 1511, 1512, 1513, 1514, 1515, 1516, 1517,
  1518, 1519, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527,
  1528, 1529, 1530, 1531, 1532, 1533, 1534, 1535, 1536, 1537,
  1538, 1539, 1540, 1541, 1543, 1544, 1545, 1546, 1548, 1549,
  1550, 1551, 1553, 1554, 1555, 1556, 1557, 1558, 1559, 1560,
  1561, 1562, 1563, 1564, 1567, 1568, 1569, 1570, 1571, 1572,
  1573, 1574, 1575, 1576, 1577, 1579, 1580, 1581, 1582, 1583,
  1584, 1585, 1586, 1587, 1588, 1589, 1590, 1591, 1593, 1594,
  1595, 1596, 1597, 1598, 1599, 1600, 1601, 1602, 1603, 1604,
  1605, 1606, 1607, 1608, 1609, 1610, 1611, 1612, 1613, 1614,
  1615, 1616, 1617, 1618, 1619, 1620, 1621, 1622, 1623, 1624,
  1625, 1626, 1627, 1628, 1629, 1630, 1631, 1632, 1633, 1634
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] = {
  0, 650, 651, 652, 653, 654, 655, 655, 656, 656,
  657, 658, 658, 658, 658, 658, 659, 659, 659, 659,
  659, 660, 660, 661, 661, 663, 662, 662, 664, 664,
  665, 665, 665, 665, 665, 665, 665, 665, 665, 665,
  665, 665, 665, 665, 665, 665, 666, 666, 668, 667,
  669, 669, 670, 670, 670, 670, 670, 670, 670, 670,
  670, 671, 672, 673, 672, 672, 672, 672, 672, 674,
  675, 672, 676, 677, 678, 672, 679, 680, 672, 681,
  682, 672, 683, 684, 685, 672, 686, 686, 687, 687,
  687, 688, 688, 689, 689, 690, 691, 691, 692, 692,
  694, 693, 695, 693, 696, 696, 697, 697, 698, 699,
  700, 699, 701, 702, 701, 704, 703, 706, 705, 707,
  707, 707, 707, 707, 707, 708, 709, 709, 710, 710,
  711, 712, 712, 713, 714, 716, 717, 715, 718, 718,
  719, 719, 720, 720, 721, 721, 721, 722, 722, 724,
  723, 725, 723, 726, 723, 727, 723, 728, 723, 729,
  729, 730, 730, 731, 731, 731, 731, 731, 731, 732,
  733, 733, 734, 734, 735, 735, 736, 736, 738, 739,
  737, 737, 737, 740, 740, 742, 741, 743, 743, 743,
  743, 743, 744, 743, 745, 745, 745, 745, 746, 747,
  747, 748, 748, 750, 749, 751, 749, 752, 752, 753,
  753, 754, 755, 755, 755, 756, 758, 757, 759, 757,
  760, 757, 761, 761, 762, 763, 764, 764, 766, 767,
  765, 768, 768, 768, 768, 768, 768, 768, 768, 768,
  768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
  768, 768, 768, 768, 768, 768, 768, 768, 768, 769,
  770, 771, 772, 772, 773, 775, 774, 776, 776, 776,
  776, 776, 776, 776, 778, 777, 779, 779, 780, 780,
  781, 783, 782, 784, 784, 784, 784, 784, 784, 784,
  785, 786, 786, 788, 787, 789, 789, 789, 789, 789,
  789, 789, 789, 789, 789, 789, 789, 789, 789, 789,
  789, 789, 789, 789, 789, 789, 789, 789, 790, 792,
  791, 793, 791, 795, 794, 796, 794, 797, 797, 798,
  799, 799, 800, 801, 801, 801, 801, 801, 801, 801,
  801, 802, 803, 804, 806, 807, 805, 808, 808, 809,
  810, 810, 811, 811, 813, 812, 814, 812, 815, 812,
  816, 816, 817, 817, 817, 817, 817, 817, 817, 817,
  817, 818, 818, 818, 818, 818, 818, 818, 818, 819,
  819, 820, 820, 820, 820, 820, 820, 820, 820, 820,
  820, 821, 821, 821, 821, 821, 821, 821, 821, 821,
  821, 822, 822, 823, 823, 824, 824, 825, 825, 826,
  826, 827, 828, 828, 829, 829, 829, 829, 829, 829,
  830, 830, 831, 831, 831, 831, 832, 832, 833, 834,
  834, 834, 835, 834, 836, 836, 837, 837, 838, 838,
  838, 838, 839, 839, 840, 840, 840, 840, 840, 840,
  840, 840, 841, 842, 843, 843, 843, 843, 843, 843,
  844, 844, 844, 844, 844, 844, 844, 845, 847, 848,
  846, 849, 850, 846, 852, 853, 851, 854, 855, 851,
  856, 857, 851, 858, 859, 851, 851, 851, 851, 851,
  860, 860, 861, 862, 862, 862, 862, 862, 862, 862,
  862, 862, 863, 863, 864, 864, 864, 864, 865, 865,
  865, 866, 866, 867, 867, 867, 868, 868, 868, 868,
  868, 868, 868, 868, 868, 868, 869, 869, 870, 870,
  872, 873, 871, 874, 874, 876, 877, 878, 875, 880,
  881, 879, 882, 882, 883, 883, 884, 884, 886, 885,
  887, 885, 888, 888, 889, 889, 891, 890, 892, 890,
  893, 894, 894, 894, 895, 895, 896, 896, 897, 897,
  898, 898, 900, 899, 901, 899, 902, 899, 903, 899,
  904, 899, 905, 906, 906, 906, 906, 906, 906, 907,
  907, 908, 909, 910, 911, 911, 911, 911, 911, 911,
  911, 911, 912, 913, 914, 915, 916, 917, 918, 918,
  919, 920, 921, 921, 922, 922, 923, 923, 923, 923,
  923, 923, 924, 925, 925, 926, 926, 926, 926, 926,
  926, 926, 926, 926, 926, 926, 926, 926, 926, 926,
  926, 926, 926, 926, 926, 926, 926, 926, 926, 926,
  926, 926, 926, 926, 926, 926, 926, 926, 926, 926,
  926, 926, 926, 926, 926, 926, 926, 926, 927, 928,
  929, 929, 930, 931, 932, 932, 932, 933, 933, 933,
  935, 934, 936, 936, 937, 937, 938, 938, 939, 940,
  940, 941, 942, 942, 943, 944, 944, 945, 946, 946,
  948, 947, 949, 950, 949, 951, 952, 949, 953, 953,
  954, 956, 955, 955, 957, 957, 958, 958, 959, 959,
  960, 960, 961, 961, 963, 962, 964, 962, 965, 962,
  966, 962, 967, 962, 968, 962, 969, 962, 970, 962,
  971, 962, 972, 972, 973, 973, 974, 974, 975, 975,
  976, 976, 977, 977, 978, 979, 980, 980, 980, 982,
  981, 983, 983, 984, 983, 985, 986, 986, 986, 986,
  987, 987, 989, 988, 988, 991, 990, 992, 994, 993,
  995, 995, 996, 996, 998, 997, 999, 999, 999, 999,
  999, 999, 999, 999, 999, 999, 999, 999, 999, 999,
  999, 999, 999, 1000, 1002, 1003, 1001, 1004, 1004, 1005,
  1006, 1007, 1008, 1008, 1010, 1009, 1011, 1011, 1012, 1012,
  1013, 1013, 1013, 1013, 1014, 1014, 1015, 1015, 1016, 1017,
  1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017,
  1018, 1018, 1019, 1019, 1019, 1020, 1021, 1021, 1023, 1024,
  1025, 1026, 1022, 1027, 1029, 1030, 1028, 1031, 1032, 1032,
  1033, 1034, 1035, 1035, 1036, 1036, 1036, 1038, 1037, 1039,
  1039, 1041, 1042, 1043, 1040, 1045, 1044, 1046, 1048, 1047,
  1049, 1047, 1050, 1047, 1051, 1051, 1052, 1052, 1053, 1053,
  1054, 1054, 1054, 1055, 1056, 1057, 1058, 1058, 1058, 1059,
  1059, 1060, 1060, 1062, 1063, 1061, 1064, 1064, 1066, 1065,
  1067, 1065, 1068, 1069, 1069, 1069, 1069, 1070, 1070, 1070,
  1070, 1070, 1072, 1071, 1073, 1073, 1074, 1075, 1076, 1076,
  1077, 1078, 1078, 1078, 1078, 1078, 1079, 1080, 1081, 1081,
  1082, 1082, 1083, 1084, 1085, 1085, 1086, 1086, 1087, 1088,
  1089, 1089, 1089, 1089, 1089, 1090, 1090, 1091, 1092, 1092,
  1093, 1093, 1094, 1094, 1095, 1095, 1096, 1096, 1096, 1096,
  1096, 1097, 1097, 1098, 1098, 1099, 1099, 1100, 1101, 1102,
  1102, 1103, 1104, 1104, 1104, 1105, 1106, 1106, 1107, 1107,
  1108, 1109, 1109, 1110, 1110, 1111, 1112, 1113, 1114, 1114,
  1115, 1116, 1116, 1117, 1117, 1118, 1118, 1119, 1120, 1120,
  1121, 1121, 1121, 1121, 1122, 1122, 1122, 1123, 1124, 1124,
  1125, 1125, 1125, 1126, 1127, 1127, 1128, 1128, 1128, 1128,
  1128, 1128, 1128, 1128, 1128, 1128, 1128, 1128, 1128, 1128,
  1128, 1128, 1128, 1128, 1128, 1128, 1128, 1128, 1129, 1130,
  1130, 1131, 1131, 1132, 1134, 1133, 1135, 1136, 1136, 1137,
  1137, 1138, 1138, 1140, 1139, 1141, 1143, 1142, 1144, 1144,
  1145, 1145, 1146, 1146, 1147, 1147, 1147, 1147, 1148, 1148,
  1149, 1150, 1150, 1151, 1152, 1153, 1154, 1155, 1155, 1156,
  1156, 1158, 1157, 1159, 1157, 1160, 1157, 1161, 1157, 1162,
  1157, 1163, 1157, 1164, 1157, 1165, 1165, 1165, 1165, 1165,
  1165, 1167, 1166, 1168, 1168, 1170, 1169, 1169, 1169, 1169,
  1169, 1171, 1171, 1172, 1172, 1173, 1174, 1174, 1175, 1176,
  1177, 1178, 1178, 1178, 1179, 1179, 1179, 1179, 1180, 1181,
  1181, 1182, 1182, 1183, 1184, 1184, 1184, 1184, 1184, 1184,
  1184, 1184, 1185, 1185, 1186, 1186, 1187, 1187, 1187, 1187,
  1187, 1187, 1187, 1187, 1187, 1187, 1188, 1188, 1189, 1189,
  1189, 1189, 1190, 1190, 1191, 1191, 1192, 1192, 1192, 1192,
  1192, 1192, 1192, 1192, 1192, 1192, 1192, 1192, 1192, 1192,
  1192, 1192, 1192, 1192, 1192, 1192, 1192, 1192, 1192, 1192,
  1193, 1193, 1193, 1195, 1196, 1197, 1198, 1199, 1200, 1194,
  1201, 1201, 1202, 1203, 1203, 1205, 1206, 1207, 1208, 1209,
  1210, 1204, 1211, 1213, 1214, 1215, 1212, 1216, 1216, 1216,
  1216, 1217, 1217, 1217, 1217, 1217, 1218, 1219, 1219, 1219,
  1220, 1220, 1222, 1223, 1221, 1224, 1225, 1221, 1226, 1226,
  1227, 1227, 1228, 1228, 1229, 1229, 1229, 1230, 1230, 1231,
  1231, 1232, 1232, 1233, 1234, 1234, 1235, 1235, 1235, 1235,
  1235, 1235, 1235, 1236, 1236, 1237, 1237, 1238, 1238, 1239,
  1239, 1240, 1240, 1241, 1242, 1242, 1243, 1243, 1244, 1245,
  1245, 1246, 1247, 1247, 1248, 1248, 1249, 1249, 1250, 1251,
  1251, 1251, 1251, 1251, 1251, 1251, 1251, 1251, 1251, 1251,
  1252, 1252, 1253, 1253, 1254, 1255, 1257, 1256, 1259, 1258,
  1258, 1260, 1260, 1261, 1261, 1262, 1262, 1263, 1263, 1265,
  1266, 1264, 1267, 1267, 1268, 1269, 1268, 1270, 1271, 1270,
  1272, 1272, 1272, 1272, 1272, 1272, 1272, 1272, 1273, 1274,
  1275, 1276, 1276, 1277, 1278, 1278, 1279, 1279, 1279, 1280,
  1281, 1282, 1282, 1283, 1285, 1284, 1286, 1286, 1286, 1286,
  1286, 1286, 1286, 1286, 1286, 1286, 1286, 1286, 1287, 1288,
  1288, 1289, 1289, 1290, 1290, 1291, 1291, 1291, 1291, 1292,
  1292, 1293, 1293, 1294, 1294, 1295, 1295, 1296, 1297, 1297,
  1298, 1298, 1299, 1299, 1300, 1301, 1302, 1303, 1304, 1304,
  1305, 1305, 1306, 1306, 1307, 1307, 1308, 1308, 1308, 1309,
  1309, 1310, 1311, 1311, 1312, 1312, 1313, 1313, 1314, 1314,
  1314, 1314, 1315, 1316, 1317, 1318, 1318, 1319, 1319, 1320,
  1321, 1322, 1322, 1323, 1324, 1325, 1325, 1326, 1326, 1326,
  1327, 1327, 1328, 1328, 1329, 1330, 1330, 1331, 1331, 1332,
  1332, 1333, 1333, 1334, 1334, 1335, 1335, 1336, 1336, 1337,
  1337, 1338, 1338, 1339, 1339, 1340, 1341, 1341, 1341, 1341,
  1342, 1342, 1343, 1343, 1344, 1344, 1345, 1345, 1345, 1345,
  1345, 1345, 1345, 1346, 1346, 1346, 1346, 1346, 1346, 1346,
  1346, 1347, 1347, 1347, 1348, 1348, 1348, 1348, 1349, 1349,
  1349, 1350, 1350, 1351, 1351, 1351, 1351, 1351, 1351, 1351,
  1351, 1351, 1351, 1351, 1351, 1351, 1351, 1351, 1351, 1351,
  1352, 1352, 1353, 1353, 1353, 1353, 1353, 1354, 1355, 1356,
  1357, 1357, 1357, 1357, 1358, 1359, 1359, 1359, 1360, 1360,
  1361, 1361, 1361, 1362, 1363, 1363, 1363, 1363, 1363, 1364,
  1365, 1366, 1366, 1367, 1367, 1368, 1368, 1368, 1368, 1368,
  1368, 1368, 1368, 1369, 1369, 1369, 1369, 1369, 1369, 1369,
  1369, 1370, 1370, 1370, 1370, 1370, 1370, 1370, 1371, 1371,
  1371, 1371, 1371, 1371, 1371, 1372, 1372, 1373, 1375, 1374,
  1376, 1374, 1377, 1374, 1378, 1374, 1379, 1379, 1379, 1380,
  1380, 1381, 1381, 1381, 1382, 1382, 1383, 1383, 1384, 1386,
  1387, 1385, 1388, 1389, 1389, 1390, 1391, 1391, 1391, 1391,
  1391, 1392, 1393, 1393, 1394, 1395, 1396, 1396, 1396, 1396,
  1397, 1397, 1398, 1398, 1398, 1399, 1400, 1400, 1400, 1401,
  1401, 1401, 1401, 1401, 1402, 1402, 1402, 1402, 1402, 1402,
  1402, 1402, 1402, 1402, 1402, 1402, 1402, 1402, 1402, 1402,
  1402, 1402, 1402, 1402, 1403, 1403, 1404, 1404, 1405, 1406,
  1406, 1407, 1407, 1408, 1408, 1409, 1409, 1410, 1410, 1411,
  1412, 1412, 1413, 1413, 1414, 1415, 1415, 1415, 1416, 1416,
  1417, 1418, 1419, 1420, 1421, 1421, 1422, 1422, 1422, 1422,
  1422, 1422, 1423, 1423, 1423, 1425, 1424, 1426, 1426, 1427,
  1427, 1427, 1428, 1429, 1431, 1432, 1430, 1433, 1433, 1433,
  1434, 1434, 1434, 1434, 1435, 1435, 1436, 1437, 1438, 1438,
  1439, 1439, 1440, 1440, 1441, 1441, 1441, 1442, 1442, 1442,
  1442, 1442, 1443, 1443, 1443, 1443, 1443, 1443, 1443, 1443,
  1443, 1443, 1443, 1443, 1443, 1443, 1443, 1443, 1443, 1443,
  1443, 1443, 1444, 1445, 1445, 1446, 1447, 1447, 1448, 1448,
  1448, 1448, 1449, 1449, 1449, 1450, 1450, 1451, 1451, 1451,
  1451, 1451, 1451, 1451, 1451, 1451, 1452, 1452, 1452, 1452,
  1452, 1453, 1453, 1454, 1456, 1457, 1455, 1458, 1458, 1459,
  1459, 1460, 1460, 1460, 1460, 1460, 1460, 1460, 1461, 1461,
  1462, 1462, 1463, 1463, 1464, 1464, 1465, 1465, 1466, 1467,
  1468, 1469, 1469, 1470, 1471, 1471, 1472, 1473, 1473, 1475,
  1474, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476,
  1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476,
  1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476,
  1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476,
  1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476,
  1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476,
  1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476,
  1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476, 1476,
  1476, 1476, 1476, 1476, 1476, 1476
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] = {
  0, 2, 1, 1, 5, 1, 1, 1, 1, 3,
  1, 3, 3, 1, 2, 1, 1, 1, 1, 1,
  1, 1, 1, 0, 1, 0, 5, 6, 1, 3,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 0, 1, 0, 5,
  1, 3, 1, 1, 2, 2, 2, 2, 2, 2,
  2, 2, 3, 0, 7, 8, 6, 1, 6, 0,
  0, 9, 0, 0, 0, 8, 0, 0, 10, 0,
  0, 9, 0, 0, 0, 14, 0, 2, 0, 2,
  1, 0, 1, 1, 3, 1, 1, 1, 1, 3,
  0, 6, 0, 5, 1, 2, 1, 2, 1, 0,
  0, 3, 0, 0, 3, 0, 4, 0, 4, 2,
  2, 2, 1, 2, 2, 3, 1, 1, 1, 2,
  1, 1, 2, 1, 1, 0, 0, 5, 7, 8,
  0, 2, 1, 3, 1, 3, 3, 1, 2, 0,
  4, 0, 4, 0, 3, 0, 3, 0, 3, 1,
  3, 1, 3, 1, 1, 1, 1, 1, 1, 4,
  0, 4, 1, 1, 0, 1, 1, 2, 0, 0,
  5, 1, 1, 1, 3, 0, 2, 4, 4, 4,
  4, 2, 0, 4, 1, 1, 1, 2, 1, 1,
  3, 0, 1, 0, 7, 0, 12, 1, 1, 1,
  1, 1, 5, 3, 1, 1, 0, 4, 0, 5,
  0, 7, 1, 3, 1, 1, 0, 1, 0, 0,
  4, 1, 1, 1, 4, 4, 6, 1, 2, 1,
  1, 1, 1, 4, 6, 1, 4, 6, 1, 1,
  1, 1, 1, 1, 1, 2, 2, 1, 1, 4,
  1, 1, 0, 3, 3, 0, 2, 1, 1, 1,
  1, 1, 1, 2, 0, 2, 0, 3, 0, 3,
  1, 0, 3, 1, 1, 1, 1, 1, 1, 2,
  1, 0, 1, 0, 5, 1, 1, 1, 4, 4,
  6, 1, 1, 1, 1, 4, 6, 1, 4, 6,
  1, 1, 1, 1, 1, 2, 2, 1, 4, 0,
  7, 0, 12, 0, 4, 0, 5, 1, 3, 2,
  1, 3, 1, 0, 2, 2, 1, 2, 5, 4,
  2, 4, 5, 3, 0, 0, 11, 0, 2, 1,
  0, 2, 1, 2, 0, 3, 0, 3, 0, 3,
  4, 5, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 1, 1, 1, 1, 2, 1, 1, 1, 2,
  2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 2, 1, 1, 1, 3, 1, 3, 1,
  3, 1, 1, 1, 2, 1, 1, 3, 4, 4,
  2, 2, 1, 1, 1, 1, 1, 3, 1, 2,
  2, 1, 0, 3, 2, 2, 1, 3, 4, 4,
  5, 5, 1, 1, 2, 2, 4, 4, 2, 2,
  4, 4, 1, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 0, 0, 0,
  6, 0, 0, 8, 0, 0, 6, 0, 0, 6,
  0, 0, 6, 0, 0, 6, 5, 5, 5, 7,
  0, 3, 1, 1, 4, 4, 4, 4, 4, 4,
  1, 1, 1, 1, 4, 4, 2, 2, 2, 2,
  2, 1, 1, 2, 1, 1, 1, 2, 4, 6,
  6, 3, 5, 5, 3, 1, 1, 3, 1, 3,
  0, 0, 11, 0, 2, 0, 0, 0, 8, 0,
  0, 10, 0, 1, 0, 1, 1, 2, 0, 3,
  0, 3, 0, 1, 1, 2, 0, 3, 0, 3,
  3, 1, 4, 3, 1, 3, 1, 3, 1, 3,
  1, 2, 0, 3, 0, 3, 0, 4, 0, 4,
  0, 4, 2, 3, 1, 3, 1, 1, 1, 1,
  1, 1, 3, 1, 1, 4, 6, 4, 3, 6,
  3, 6, 1, 1, 1, 1, 1, 1, 0, 2,
  1, 1, 1, 4, 1, 1, 1, 4, 3, 6,
  3, 6, 1, 1, 2, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
  1, 3, 1, 2, 2, 2, 4, 2, 2, 4,
  0, 8, 0, 1, 1, 1, 0, 1, 2, 0,
  1, 2, 0, 1, 2, 0, 1, 3, 0, 2,
  0, 7, 0, 0, 3, 0, 0, 7, 5, 2,
  2, 0, 5, 4, 1, 3, 3, 3, 0, 2,
  0, 1, 1, 2, 0, 4, 0, 4, 0, 3,
  0, 3, 0, 3, 0, 3, 0, 3, 0, 4,
  0, 4, 1, 3, 1, 1, 1, 3, 1, 1,
  1, 3, 1, 3, 2, 4, 1, 1, 1, 0,
  4, 5, 6, 0, 10, 3, 1, 1, 2, 2,
  0, 2, 0, 3, 1, 0, 3, 2, 0, 3,
  1, 3, 1, 3, 0, 2, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 0, 7, 1, 1, 2,
  2, 2, 3, 4, 0, 3, 0, 1, 1, 2,
  1, 1, 1, 1, 0, 1, 1, 2, 2, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 13, 1, 0, 0, 6, 2, 1, 2,
  2, 1, 1, 2, 1, 1, 1, 0, 3, 2,
  1, 0, 0, 0, 14, 0, 5, 1, 0, 3,
  0, 7, 0, 5, 1, 2, 0, 1, 1, 1,
  0, 1, 1, 2, 2, 2, 1, 1, 1, 1,
  3, 1, 1, 0, 0, 7, 1, 2, 0, 3,
  0, 4, 2, 0, 2, 1, 1, 1, 1, 1,
  1, 1, 0, 3, 0, 1, 1, 1, 1, 2,
  2, 2, 5, 1, 1, 1, 4, 4, 1, 1,
  1, 1, 2, 2, 3, 6, 1, 3, 1, 1,
  1, 3, 6, 1, 1, 1, 1, 2, 0, 1,
  1, 3, 1, 3, 1, 3, 1, 3, 1, 1,
  1, 1, 3, 1, 3, 1, 3, 1, 1, 1,
  3, 2, 0, 1, 1, 4, 1, 3, 1, 3,
  7, 0, 7, 0, 6, 3, 1, 3, 1, 2,
  5, 0, 7, 0, 2, 0, 1, 5, 2, 5,
  0, 5, 6, 4, 0, 1, 1, 4, 0, 2,
  0, 5, 4, 2, 1, 3, 2, 2, 2, 2,
  2, 2, 1, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 1, 1, 1, 1, 1, 1, 5, 1,
  1, 2, 4, 1, 0, 10, 5, 0, 1, 0,
  2, 1, 2, 0, 3, 1, 0, 4, 0, 2,
  1, 3, 1, 1, 3, 4, 4, 2, 1, 1,
  1, 0, 1, 7, 2, 2, 2, 2, 2, 1,
  2, 0, 3, 0, 3, 0, 3, 0, 3, 0,
  3, 0, 4, 0, 4, 1, 1, 1, 1, 1,
  1, 0, 4, 0, 1, 0, 4, 1, 2, 2,
  2, 0, 1, 1, 2, 2, 0, 2, 3, 3,
  5, 0, 2, 4, 1, 1, 1, 1, 1, 0,
  1, 1, 3, 2, 5, 2, 5, 5, 5, 5,
  5, 5, 0, 2, 1, 2, 2, 2, 2, 2,
  2, 1, 2, 2, 2, 2, 1, 2, 2, 2,
  2, 1, 1, 1, 0, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 1, 1, 1, 1, 1, 1,
  1, 1, 2, 2, 2, 2, 2, 1, 1, 1,
  0, 3, 2, 0, 0, 0, 0, 0, 0, 15,
  0, 2, 2, 0, 1, 0, 0, 0, 0, 0,
  0, 15, 2, 0, 0, 0, 10, 0, 1, 3,
  3, 2, 4, 3, 3, 3, 1, 1, 1, 1,
  1, 1, 0, 0, 7, 0, 0, 8, 3, 2,
  0, 1, 1, 3, 2, 2, 1, 1, 3, 1,
  1, 2, 1, 3, 1, 3, 1, 1, 1, 1,
  1, 1, 1, 2, 4, 1, 3, 1, 3, 2,
  4, 1, 3, 1, 2, 4, 1, 3, 1, 1,
  1, 2, 2, 4, 2, 4, 1, 3, 1, 1,
  1, 2, 1, 1, 1, 1, 1, 2, 6, 6,
  0, 1, 0, 1, 2, 1, 0, 5, 0, 5,
  1, 0, 3, 1, 3, 1, 3, 1, 1, 0,
  0, 5, 2, 1, 0, 0, 3, 0, 0, 3,
  1, 1, 1, 1, 1, 1, 2, 2, 4, 3,
  3, 1, 3, 2, 1, 1, 0, 1, 1, 1,
  1, 0, 1, 3, 0, 3, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 7, 0,
  1, 1, 1, 1, 3, 1, 1, 1, 2, 0,
  3, 1, 3, 1, 3, 1, 1, 6, 0, 3,
  1, 3, 0, 1, 4, 5, 2, 1, 1, 4,
  1, 3, 4, 4, 1, 3, 1, 1, 1, 2,
  1, 4, 0, 1, 0, 1, 1, 2, 1, 1,
  1, 4, 3, 1, 1, 1, 2, 1, 1, 2,
  2, 1, 3, 2, 2, 1, 3, 1, 2, 4,
  1, 2, 1, 3, 4, 0, 1, 0, 1, 0,
  1, 1, 3, 1, 3, 1, 2, 1, 3, 2,
  2, 0, 2, 1, 1, 1, 5, 3, 5, 3,
  1, 3, 1, 1, 0, 1, 3, 3, 3, 6,
  4, 4, 5, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
  1, 1, 4, 5, 1, 5, 5, 1, 1, 1,
  4, 1, 4, 1, 7, 1, 1, 1, 4, 6,
  0, 2, 4, 1, 1, 1, 1, 1, 1, 1,
  3, 1, 1, 3, 1, 0, 3, 5, 1, 2,
  2, 4, 3, 1, 1, 1, 1, 1, 1, 2,
  2, 0, 3, 0, 3, 1, 1, 1, 1, 1,
  1, 1, 4, 1, 1, 1, 1, 1, 1, 1,
  4, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 3, 0, 8,
  0, 9, 0, 7, 0, 9, 0, 1, 2, 1,
  3, 1, 3, 5, 1, 1, 1, 1, 2, 0,
  0, 8, 5, 1, 1, 6, 0, 3, 1, 3,
  4, 1, 0, 2, 4, 6, 0, 1, 1, 1,
  1, 3, 1, 2, 2, 1, 1, 2, 2, 1,
  1, 1, 2, 4, 3, 2, 3, 3, 3, 1,
  1, 1, 1, 1, 1, 5, 5, 5, 5, 5,
  4, 4, 3, 4, 1, 3, 0, 1, 5, 7,
  5, 0, 2, 1, 1, 0, 3, 1, 3, 1,
  1, 1, 0, 3, 1, 1, 1, 1, 4, 6,
  1, 1, 2, 3, 1, 1, 1, 1, 1, 1,
  1, 1, 5, 5, 4, 0, 4, 1, 2, 1,
  1, 1, 2, 2, 0, 0, 7, 0, 2, 2,
  7, 5, 1, 3, 1, 3, 1, 3, 1, 3,
  1, 3, 1, 1, 1, 2, 2, 1, 1, 1,
  2, 4, 3, 2, 3, 3, 3, 1, 1, 1,
  1, 1, 1, 5, 5, 5, 5, 5, 4, 4,
  3, 4, 1, 1, 3, 1, 2, 1, 1, 1,
  3, 5, 1, 1, 1, 1, 3, 2, 2, 2,
  1, 2, 2, 2, 2, 2, 1, 3, 2, 1,
  2, 1, 2, 1, 0, 0, 6, 0, 2, 0,
  1, 1, 2, 2, 1, 1, 4, 3, 1, 3,
  1, 2, 5, 2, 2, 5, 0, 2, 1, 1,
  2, 6, 6, 1, 0, 1, 2, 1, 2, 0,
  2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] = {
  816, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1790, 0, 0, 0, 867, 178, 840, 845, 176, 181,
  820, 0, 814, 817, 818, 821, 823, 866, 822, 861,
  862, 864, 182, 133, 130, 0, 126, 128, 127, 131,
  1833, 710, 610, 1796, 0, 0, 1799, 0, 1795, 1792,
  1789, 1787, 1788, 1794, 1793, 1791, 293, 1596, 1595, 860,
  174, 185, 177, 182, 1, 824, 819, 865, 863, 841,
  125, 129, 132, 1803, 1800, 0, 1801, 1798, 0, 0,
  589, 0, 0, 175, 870, 934, 590, 868, 622, 927,
  0, 928, 935, 933, 185, 179, 198, 0, 183, 199,
  228, 0, 847, 1215, 0, 0, 846, 134, 1203, 854,
  0, 0, 837, 839, 836, 838, 815, 825, 826, 848,
  829, 830, 831, 834, 832, 833, 835, 1802, 1797, 0,
  929, 869, 0, 0, 942, 940, 941, 931, 930, 291,
  185, 1139, 192, 186, 185, 191, 225, 0, 709, 0,
  0, 0, 0, 174, 539, 903, 827, 0, 325, 311,
  201, 262, 281, 302, 304, 301, 0, 323, 0, 310,
  303, 307, 313, 297, 312, 185, 314, 294, 317, 295,
  296, 939, 938, 0, 21, 22, 13, 0, 948, 0,
  15, 0, 946, 0, 292, 0, 184, 1140, 180, 0,
  198, 200, 258, 252, 253, 241, 218, 249, 201, 220,
  262, 281, 239, 242, 237, 0, 216, 0, 248, 240,
  245, 251, 233, 250, 185, 254, 185, 231, 232, 229,
  257, 0, 0, 0, 0, 855, 174, 174, 0, 0,
  202, 0, 315, 0, 0, 316, 0, 0, 0, 0,
  0, 0, 0, 0, 260, 0, 936, 0, 16, 17,
  19, 18, 20, 0, 14, 0, 944, 0, 623, 187,
  190, 0, 188, 189, 0, 195, 194, 193, 196, 185,
  0, 185, 255, 256, 0, 0, 185, 0, 0, 0,
  0, 238, 226, 1216, 0, 0, 1204, 1839, 540, 904,
  849, 0, 207, 208, 0, 274, 276, 271, 272, 268,
  270, 267, 269, 266, 0, 276, 287, 288, 284, 286,
  283, 285, 278, 0, 0, 0, 327, 0, 330, 332,
  215, 0, 214, 0, 0, 185, 11, 12, 947, 0,
  932, 624, 197, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 185, 227, 230, 958, 708, 871, 958, 0,
  1837, 1839, 1139, 1692, 842, 0, 958, 0, 0, 263,
  0, 0, 273, 290, 264, 289, 0, 282, 0, 305,
  0, 299, 0, 324, 0, 329, 319, 0, 0, 308,
  298, 261, 318, 0, 0, 0, 0, 0, 243, 0,
  235, 217, 203, 0, 246, 234, 259, 964, 0, 959,
  960, 958, 0, 856, 1838, 1836, 0, 0, 0, 0,
  0, 0, 0, 0, 1820, 0, 1305, 1304, 0, 1306,
  0, 375, 1303, 1245, 0, 5, 1302, 376, 373, 0,
  378, 172, 467, 1117, 0, 0, 1312, 122, 372, 371,
  1237, 366, 0, 1262, 1811, 0, 377, 344, 0, 3,
  2, 0, 374, 1242, 0, 0, 367, 364, 379, 0,
  0, 0, 0, 1310, 1300, 370, 0, 0, 0, 0,
  0, 0, 0, 0, 1299, 0, 0, 0, 173, 1239,
  363, 362, 0, 0, 1815, 1814, 0, 0, 0, 135,
  1238, 369, 368, 0, 0, 365, 922, 467, 0, 535,
  0, 0, 0, 467, 0, 0, 0, 467, 803, 1213,
  0, 0, 1121, 0, 1804, 0, 102, 0, 0, 875,
  0, 0, 0, 0, 804, 0, 0, 1715, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 680, 0, 0,
  1841, 1842, 1843, 1844, 1845, 1846, 1847, 1848, 1849, 1850,
  1851, 1852, 1853, 1854, 1855, 1856, 1857, 1858, 1859, 1860,
  1861, 1862, 1863, 1864, 1865, 1866, 1867, 1868, 1869, 1870,
  1871, 1872, 1873, 1874, 1875, 1876, 1877, 1878, 1879, 1880,
  1881, 1882, 1883, 1884, 1885, 1886, 1887, 913, 1888, 1889,
  1890, 1891, 1892, 1893, 1894, 1895, 1896, 1897, 1898, 1899,
  1900, 1901, 1902, 1903, 1904, 1108, 1110, 1105, 1107, 1106,
  1109, 1905, 1906, 1236, 1907, 1241, 1240, 1908, 1909, 1910,
  1911, 1912, 1913, 1914, 1915, 1916, 1917, 1364, 1918, 1919,
  1920, 1921, 1922, 1923, 1924, 1925, 1840, 843, 544, 844,
  0, 908, 0, 906, 0, 326, 209, 210, 0, 275,
  280, 0, 0, 0, 0, 328, 331, 0, 213, 0,
  945, 219, 0, 185, 0, 0, 0, 0, 0, 1217,
  0, 0, 1205, 0, 0, 1249, 611, 612, 828, 1080,
  1085, 1813, 604, 121, 0, 0, 1779, 1778, 1018, 1775,
  1777, 1828, 0, 1256, 0, 1252, 1261, 7, 0, 6,
  0, 1821, 1081, 0, 1173, 1172, 1120, 1171, 1119, 0,
  0, 422, 424, 0, 1210, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1563, 0, 0, 0, 416,
  0, 0, 0, 0, 415, 0, 0, 432, 0, 503,
  0, 0, 0, 0, 0, 0, 0, 411, 1313, 0,
  382, 381, 388, 428, 425, 383, 501, 493, 384, 386,
  500, 387, 934, 423, 426, 431, 1301, 502, 1694, 1307,
  123, 0, 1084, 120, 0, 810, 23, 606, 380, 0,
  809, 1077, 811, 0, 1311, 897, 896, 899, 895, 898,
  1830, 0, 893, 0, 605, 991, 894, 1824, 0, 1812,
  119, 988, 711, 986, 0, 602, 1807, 757, 756, 0,
  758, 594, 754, 0, 0, 1001, 607, 1361, 0, 0,
  1053, 1051, 0, 1045, 1047, 1046, 1044, 1043, 0, 0,
  0, 1042, 0, 784, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1032, 1023, 1024, 0, 1065,
  409, 23, 857, 401, 1818, 0, 1809, 124, 603, 0,
  1050, 1049, 1214, 1212, 1138, 0, 1683, 1684, 1139, 1227,
  1139, 1122, 1123, 1126, 1141, 1314, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 61, 0, 934, 0, 67,
  0, 100, 582, 668, 0, 1111, 1008, 1115, 0, 0,
  1066, 1231, 0, 0, 1118, 672, 669, 670, 0, 674,
  675, 0, 677, 678, 0, 673, 968, 970, 0, 0,
  969, 759, 966, 720, 962, 926, 0, 0, 0, 0,
  684, 685, 0, 0, 924, 920, 921, 917, 918, 919,
  912, 916, 915, 0, 0, 0, 0, 0, 0, 548,
  550, 542, 545, 546, 910, 1839, 905, 907, 850, 0,
  277, 279, 306, 300, 0, 0, 309, 0, 224, 0,
  222, 244, 236, 228, 247, 965, 174, 961, 872, 174,
  0, 0, 0, 1289, 1290, 0, 0, 0, 1263, 1264,
  1266, 1267, 1268, 1272, 1271, 1269, 1270, 0, 0, 1776,
  943, 0, 1020, 0, 0, 1255, 1254, 0, 1248, 0,
  1541, 1542, 0, 1082, 0, 23, 1168, 1170, 1169, 390,
  389, 0, 0, 1145, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 430, 1571, 1569, 1570, 1566, 1568, 1565,
  1567, 1559, 0, 0, 0, 0, 0, 429, 0, 0,
  507, 506, 0, 0, 477, 474, 483, 0, 480, 0,
  0, 414, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 163,
  164, 165, 166, 167, 168, 508, 509, 510, 443, 0,
  0, 442, 452, 0, 0, 394, 0, 0, 395, 385,
  391, 393, 396, 397, 398, 399, 400, 392, 421, 420,
  468, 0, 0, 978, 0, 0, 349, 24, 343, 0,
  0, 1074, 0, 0, 0, 0, 0, 0, 0, 995,
  1693, 0, 0, 185, 0, 0, 0, 1809, 0, 0,
  0, 0, 0, 136, 0, 0, 1005, 997, 998, 1003,
  1362, 1363, 923, 333, 407, 0, 536, 587, 586, 584,
  1026, 588, 1031, 1027, 1030, 777, 0, 1028, 1029, 778,
  1036, 1040, 1033, 1034, 1038, 1039, 1037, 1035, 1041, 0,
  812, 0, 0, 0, 404, 405, 402, 403, 0, 0,
  0, 767, 766, 765, 1810, 1817, 23, 1134, 1135, 1136,
  1137, 1131, 1129, 1228, 1143, 1128, 1124, 0, 0, 1125,
  1805, 0, 0, 0, 0, 96, 0, 97, 0, 0,
  0, 72, 0, 0, 0, 109, 104, 0, 902, 0,
  901, 0, 467, 1113, 0, 953, 954, 977, 949, 950,
  805, 975, 1068, 1233, 0, 1235, 1234, 1719, 0, 0,
  0, 1717, 1720, 1721, 700, 0, 0, 0, 689, 720,
  720, 718, 0, 0, 721, 0, 25, 688, 691, 0,
  698, 694, 925, 914, 1690, 1691, 1681, 1681, 0, 0,
  1597, 0, 185, 1315, 0, 0, 1316, 1359, 185, 0,
  1360, 0, 1636, 0, 1329, 0, 1375, 1374, 1373, 1371,
  1372, 1370, 1368, 1365, 1438, 1437, 1366, 1367, 1376, 1606,
  1369, 1697, 1696, 1695, 1377, 1839, 1839, 561, 552, 543,
  0, 547, 1839, 909, 174, 0, 320, 212, 0, 185,
  221, 204, 1218, 174, 1206, 1429, 0, 1428, 0, 0,
  1430, 1292, 0, 1298, 1294, 1291, 0, 0, 0, 0,
  0, 0, 1288, 1284, 1418, 1417, 1416, 1260, 1259, 0,
  1283, 1279, 0, 1275, 1273, 0, 615, 0, 614, 0,
  1019, 0, 0, 1017, 1782, 1784, 1783, 1780, 1829, 1826,
  1253, 0, 0, 0, 1246, 467, 341, 0, 528, 1211,
  0, 0, 0, 0, 1636, 0, 0, 0, 0, 0,
  525, 511, 516, 0, 512, 515, 514, 0, 0, 0,
  0, 0, 0, 417, 0, 170, 0, 433, 0, 0,
  0, 0, 0, 0, 0, 0, 435, 434, 453, 444,
  459, 462, 463, 460, 466, 465, 464, 454, 455, 457,
  456, 458, 445, 449, 467, 461, 448, 467, 91, 0,
  427, 0, 1243, 1010, 1078, 1079, 1076, 1075, 0, 900,
  0, 0, 591, 0, 0, 0, 989, 987, 0, 713,
  714, 0, 0, 1808, 1816, 0, 0, 598, 0, 600,
  755, 0, 140, 0, 999, 1006, 0, 0, 1014, 0,
  336, 0, 0, 0, 0, 23, 1052, 1337, 0, 0,
  802, 789, 800, 801, 787, 788, 796, 791, 795, 790,
  799, 794, 797, 793, 798, 786, 792, 785, 784, 1025,
  813, 410, 0, 1057, 0, 1819, 768, 769, 360, 0,
  1139, 0, 1142, 1127, 1839, 0, 0, 0, 0, 0,
  0, 0, 62, 91, 0, 0, 115, 110, 0, 105,
  0, 112, 106, 886, 878, 884, 0, 1112, 0, 1114,
  1116, 0, 0, 957, 0, 0, 0, 0, 1067, 1232,
  1785, 1722, 973, 1723, 971, 1716, 1718, 1839, 671, 676,
  679, 692, 690, 608, 0, 0, 0, 736, 774, 734,
  730, 728, 772, 0, 0, 760, 0, 722, 732, 967,
  963, 0, 0, 0, 0, 697, 0, 0, 0, 0,
  0, 0, 0, 1544, 0, 1433, 1434, 1702, 1398, 1455,
  0, 0, 1700, 0, 0, 1638, 1639, 1637, 1619, 1724,
  0, 1381, 1387, 1386, 1385, 1389, 0, 1382, 1383, 0,
  1607, 1618, 549, 551, 0, 0, 564, 556, 558, 0,
  553, 554, 0, 0, 572, 574, 0, 0, 570, 911,
  851, 211, 0, 0, 223, 1174, 873, 1152, 1406, 1408,
  0, 1296, 0, 0, 0, 0, 0, 1286, 0, 0,
  1536, 1534, 1521, 1523, 1519, 0, 1518, 0, 1527, 1514,
  1535, 0, 1526, 1511, 1517, 1533, 1525, 1422, 1508, 1509,
  1510, 0, 1281, 1277, 0, 0, 1265, 613, 0, 0,
  0, 0, 0, 1825, 4, 8, 10, 1540, 1543, 0,
  467, 0, 499, 496, 495, 498, 494, 0, 419, 505,
  490, 490, 0, 513, 0, 517, 0, 281, 1210, 0,
  1564, 497, 1210, 504, 418, 265, 0, 1210, 478, 475,
  484, 1210, 481, 1210, 1210, 1210, 0, 0, 0, 0,
  0, 0, 0, 0, 469, 92, 93, 95, 471, 0,
  0, 0, 1007, 0, 0, 0, 0, 0, 0, 0,
  185, 712, 0, 595, 597, 0, 0, 157, 155, 0,
  0, 137, 0, 147, 153, 720, 142, 144, 0, 1004,
  1015, 1016, 0, 408, 335, 340, 593, 334, 0, 337,
  342, 1338, 537, 585, 583, 784, 779, 780, 1056, 1058,
  0, 406, 361, 1132, 1130, 1229, 1230, 0, 0, 1223,
  0, 0, 0, 98, 0, 0, 73, 79, 69, 1839,
  1839, 108, 103, 117, 113, 0, 107, 775, 887, 608,
  1839, 877, 876, 885, 1009, 0, 0, 955, 956, 951,
  976, 467, 0, 0, 1663, 1554, 1557, 1664, 1561, 1555,
  1661, 0, 0, 1073, 1660, 0, 0, 1662, 0, 0,
  0, 0, 0, 1779, 1556, 1069, 1070, 1659, 1558, 1651,
  1072, 1646, 1649, 1650, 0, 0, 0, 702, 695, 693,
  0, 23, 0, 750, 724, 752, 726, 1839, 1839, 1839,
  1839, 784, 745, 744, 740, 742, 749, 748, 738, 746,
  719, 723, 1839, 608, 45, 43, 40, 34, 38, 42,
  37, 30, 39, 33, 36, 31, 41, 32, 44, 35,
  0, 28, 0, 699, 1682, 0, 1680, 1636, 1678, 1623,
  1624, 1616, 1602, 1617, 0, 0, 0, 1048, 1432, 1435,
  0, 0, 0, 0, 1456, 1349, 1321, 1705, 1704, 1703,
  0, 0, 0, 0, 1344, 0, 1343, 0, 1345, 1340,
  1341, 1342, 1333, 1330, 0, 0, 1388, 0, 0, 0,
  1611, 1608, 1609, 563, 568, 0, 0, 1839, 1839, 541,
  555, 578, 566, 580, 1839, 1839, 576, 560, 571, 842,
  321, 205, 0, 1200, 1219, 842, 0, 1207, 1200, 0,
  0, 1293, 0, 0, 0, 0, 0, 1461, 1463, 1465,
  1503, 1502, 1501, 1467, 1484, 1295, 0, 1545, 0, 1407,
  0, 1410, 1548, 0, 1414, 0, 1285, 0, 0, 1587,
  1585, 1586, 1582, 1584, 1581, 1583, 0, 0, 0, 0,
  0, 0, 0, 0, 1420, 0, 1423, 1424, 0, 1280,
  0, 1274, 1276, 1781, 0, 0, 0, 1827, 0, 0,
  1257, 858, 0, 529, 0, 1640, 1642, 487, 0, 488,
  0, 527, 0, 524, 521, 492, 486, 1148, 1572, 1147,
  0, 169, 1146, 0, 0, 0, 1149, 0, 1151, 1150,
  1144, 446, 447, 451, 436, 0, 439, 450, 0, 438,
  0, 0, 91, 0, 0, 0, 0, 1308, 1832, 1831,
  592, 0, 0, 46, 0, 717, 716, 715, 1309, 0,
  0, 720, 1839, 1839, 149, 616, 159, 151, 161, 141,
  148, 1839, 0, 0, 0, 0, 0, 0, 0, 1839,
  0, 782, 608, 0, 1806, 0, 91, 0, 63, 0,
  0, 0, 76, 0, 91, 91, 116, 111, 1839, 1839,
  101, 784, 888, 882, 890, 889, 879, 533, 937, 0,
  0, 1648, 1647, 1560, 0, 1636, 0, 0, 1504, 0,
  1504, 1504, 1504, 1504, 1652, 0, 0, 0, 0, 0,
  0, 1706, 1707, 1708, 1709, 1710, 1711, 1655, 1786, 974,
  972, 705, 703, 0, 682, 696, 609, 761, 0, 0,
  1839, 0, 1839, 737, 735, 731, 729, 773, 0, 1839,
  0, 1839, 733, 23, 0, 26, 0, 1685, 0, 1606,
  0, 0, 1615, 1598, 1614, 1436, 0, 1400, 0, 1348,
  1443, 0, 0, 1701, 0, 1698, 1620, 0, 1347, 1346,
  1334, 1332, 0, 1391, 0, 1384, 0, 0, 0, 0,
  565, 562, 557, 559, 0, 1839, 1839, 573, 575, 1839,
  1839, 0, 0, 1198, 1199, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1197, 0, 0, 1185,
  1186, 1187, 1184, 1189, 1190, 1191, 1188, 1175, 1166, 0,
  0, 1222, 0, 1839, 0, 1161, 0, 0, 0, 0,
  0, 0, 0, 1153, 1154, 0, 1086, 0, 1297, 0,
  1470, 0, 1484, 1469, 1466, 0, 1431, 0, 1498, 1495,
  1496, 1493, 1500, 1499, 1494, 1497, 1676, 0, 1676, 1485,
  0, 0, 0, 1549, 0, 1550, 0, 0, 0, 0,
  1413, 1287, 1412, 1404, 0, 0, 0, 1538, 1530, 1530,
  0, 0, 1530, 1537, 0, 1554, 1419, 1421, 1425, 1426,
  1282, 1278, 1022, 0, 985, 9, 0, 1250, 859, 1083,
  0, 0, 1455, 1626, 646, 631, 644, 650, 665, 630,
  642, 625, 658, 661, 664, 628, 659, 637, 641, 652,
  663, 660, 662, 653, 635, 633, 657, 639, 638, 626,
  627, 629, 632, 643, 655, 634, 667, 645, 649, 651,
  666, 640, 654, 656, 636, 647, 648, 1644, 1643, 0,
  490, 518, 0, 274, 479, 476, 485, 482, 0, 441,
  440, 470, 94, 472, 347, 1244, 0, 0, 1823, 0,
  0, 990, 47, 0, 599, 601, 596, 770, 158, 156,
  0, 1839, 0, 0, 0, 1839, 154, 143, 0, 146,
  145, 0, 996, 1000, 339, 0, 1339, 0, 784, 781,
  23, 1133, 0, 1224, 68, 0, 0, 99, 66, 91,
  74, 80, 0, 118, 114, 776, 1839, 892, 608, 891,
  0, 530, 0, 807, 808, 806, 0, 0, 1672, 0,
  0, 0, 1506, 1507, 1505, 0, 1674, 0, 0, 0,
  0, 0, 0, 0, 1071, 1657, 1658, 1654, 1656, 0,
  1839, 701, 686, 683, 0, 751, 725, 753, 727, 743,
  741, 747, 739, 762, 29, 27, 0, 1679, 1632, 1603,
  1604, 1600, 1606, 0, 1399, 1636, 1402, 0, 1323, 1318,
  1317, 1320, 0, 1632, 0, 0, 1736, 1725, 1732, 0,
  1734, 1335, 1331, 0, 1390, 0, 0, 1612, 1610, 569,
  567, 579, 581, 577, 0, 0, 228, 1192, 1193, 1194,
  1196, 1179, 1177, 1176, 1180, 1181, 1178, 1195, 1182, 1183,
  1167, 982, 1202, 979, 0, 0, 1220, 0, 1165, 1164,
  1159, 1157, 1156, 1160, 1158, 1162, 1163, 1155, 1208, 1409,
  1468, 1462, 1464, 1474, 1471, 1677, 1473, 0, 1479, 1471,
  0, 1477, 1676, 1487, 1486, 0, 1488, 0, 1405, 1411,
  1552, 1545, 1415, 1594, 1592, 1593, 1589, 1591, 1588, 1590,
  1520, 0, 1522, 0, 0, 0, 0, 1528, 1532, 0,
  1512, 1427, 1021, 1258, 1251, 1247, 1641, 0, 1444, 1445,
  1447, 1450, 1457, 0, 0, 1504, 1628, 1622, 1579, 1577,
  1578, 1574, 1576, 1573, 1575, 491, 489, 0, 523, 522,
  171, 437, 0, 0, 23, 0, 0, 1013, 0, 48,
  993, 0, 23, 160, 150, 0, 618, 620, 162, 152,
  770, 0, 338, 538, 783, 1054, 0, 0, 64, 0,
  77, 86, 0, 70, 883, 880, 534, 1839, 952, 1562,
  0, 0, 0, 0, 1673, 0, 0, 1671, 0, 0,
  0, 0, 1653, 1670, 0, 704, 681, 687, 608, 1689,
  0, 1687, 0, 0, 1606, 1606, 1599, 1401, 0, 1403,
  1397, 0, 1322, 0, 1699, 0, 0, 1738, 0, 1727,
  0, 0, 0, 1392, 1395, 1379, 1393, 1396, 0, 853,
  852, 322, 206, 984, 983, 981, 0, 1201, 1087, 1091,
  1093, 0, 1097, 0, 1095, 1099, 1088, 1089, 0, 874,
  0, 1676, 1491, 0, 1480, 1483, 1482, 1490, 0, 1471,
  0, 0, 1546, 1551, 0, 1539, 1531, 1515, 1513, 0,
  1516, 0, 1448, 0, 1553, 1451, 0, 1458, 1459, 1631,
  1250, 0, 0, 0, 0, 520, 519, 473, 348, 345,
  0, 1011, 0, 0, 0, 992, 771, 138, 617, 23,
  1002, 1059, 65, 1225, 82, 0, 0, 75, 86, 86,
  1839, 531, 0, 0, 0, 0, 1669, 1675, 1665, 1666,
  1667, 1668, 706, 763, 0, 1686, 1633, 1626, 1605, 1601,
  0, 1324, 0, 1626, 0, 0, 1761, 1762, 1759, 0,
  0, 1742, 1758, 0, 0, 1760, 0, 0, 0, 0,
  0, 1779, 1757, 1749, 1733, 1740, 1743, 1744, 1748, 1747,
  1772, 0, 0, 0, 0, 1726, 1735, 0, 1737, 1336,
  0, 1380, 1378, 1613, 980, 1839, 1839, 1101, 1839, 1103,
  1839, 1839, 1090, 1221, 1209, 1472, 1475, 0, 1478, 1476,
  1492, 0, 0, 0, 1529, 1452, 0, 1446, 1440, 1441,
  1645, 0, 1460, 1454, 1629, 1354, 1350, 1351, 1356, 1355,
  1627, 1250, 0, 350, 1012, 1822, 0, 0, 0, 0,
  0, 0, 53, 0, 52, 0, 50, 0, 0, 139,
  1063, 1055, 0, 1061, 86, 91, 86, 87, 81, 71,
  881, 0, 1635, 0, 1714, 0, 1839, 23, 1688, 1625,
  1634, 1328, 0, 1325, 1327, 1621, 1746, 1745, 0, 1743,
  0, 1504, 0, 1504, 1504, 1504, 1504, 1750, 0, 0,
  0, 0, 0, 0, 1753, 1739, 0, 1728, 1729, 0,
  1394, 1092, 1094, 1839, 1098, 1839, 1096, 1100, 1481, 1489,
  1547, 1524, 0, 1449, 0, 1439, 0, 1358, 1357, 1353,
  1630, 1580, 356, 354, 346, 0, 352, 358, 55, 60,
  57, 59, 56, 58, 54, 0, 49, 0, 619, 621,
  1839, 1060, 1062, 1226, 83, 78, 532, 1712, 1713, 702,
  764, 0, 1319, 1731, 1770, 0, 0, 1773, 0, 0,
  0, 0, 0, 0, 0, 1741, 1755, 1756, 1752, 1754,
  0, 1102, 1104, 1453, 1442, 1352, 1839, 1839, 351, 353,
  1839, 51, 0, 1064, 0, 707, 1326, 1771, 0, 0,
  1769, 0, 0, 0, 0, 1751, 1768, 0, 357, 355,
  359, 0, 84, 1767, 1774, 1763, 1764, 1765, 1766, 1730,
  994, 88, 90, 0, 85, 89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] = {
  -1, 550, 551, 552, 553, 708, 1724, 1725, 188, 263,
  189, 1126, 1127, 1612, 1950, 3004, 2481, 2482, 2873, 3005,
  3006, 554, 895, 2515, 2185, 2889, 1553, 2183, 2751, 2519,
  2885, 2184, 2752, 3015, 3144, 3171, 2887, 3174, 1774, 1775,
  1776, 1226, 1842, 555, 1237, 900, 1235, 1561, 1852, 1558,
  1850, 1855, 2189, 1236, 1849, 1562, 2188, 556, 16, 35,
  36, 37, 38, 39, 113, 559, 824, 1492, 1153, 1801,
  1805, 1806, 1802, 1803, 2491, 2495, 2161, 2153, 2152, 2154,
  2157, 1108, 1060, 1756, 560, 82, 83, 18, 61, 141,
  95, 254, 97, 98, 199, 277, 99, 100, 241, 227,
  676, 2302, 304, 658, 1672, 331, 332, 228, 286, 279,
  281, 979, 980, 145, 354, 146, 147, 292, 229, 230,
  1478, 392, 242, 245, 243, 244, 313, 369, 370, 372,
  377, 661, 246, 247, 322, 374, 195, 19, 79, 177,
  178, 179, 667, 2301, 180, 250, 239, 325, 326, 327,
  328, 1505, 561, 562, 563, 564, 781, 2993, 2724, 1128,
  3084, 3085, 3086, 3137, 3136, 3140, 565, 566, 567, 568,
  757, 1109, 862, 1195, 1196, 1163, 859, 1164, 759, 760,
  761, 762, 763, 764, 765, 1063, 1110, 2125, 1111, 1112,
  1113, 1114, 1115, 1116, 1117, 713, 766, 1458, 2130, 2132,
  2722, 767, 1429, 2114, 1428, 2113, 1432, 2117, 1430, 2115,
  2097, 2106, 768, 769, 770, 771, 1413, 1414, 1415, 1416,
  1397, 569, 2757, 3021, 2531, 570, 832, 1507, 2169, 114,
  236, 364, 1328, 961, 962, 963, 1325, 1326, 1659, 1660,
  1661, 2007, 2008, 1329, 1330, 1655, 2011, 2003, 1667, 1668,
  2014, 2015, 2299, 2295, 2296, 571, 1170, 84, 1473, 1474,
  1817, 864, 814, 867, 691, 803, 786, 825, 1911, 85,
  692, 686, 1377, 2156, 86, 773, 2457, 572, 573, 916,
  917, 574, 575, 576, 577, 924, 2562, 945, 2776, 946,
  1591, 947, 1908, 948, 2234, 949, 1615, 578, 1587, 2233,
  2560, 2559, 3026, 115, 20, 579, 1144, 1479, 1480, 1605,
  1275, 1606, 1607, 2240, 2242, 1920, 1919, 1932, 1918, 1917,
  2251, 2249, 1924, 1925, 1928, 1929, 1914, 1916, 580, 581,
  822, 582, 1271, 931, 3027, 583, 1203, 2732, 1608, 1921,
  1858, 2191, 855, 1180, 1528, 1826, 2170, 1827, 1176, 1527,
  584, 585, 909, 1576, 2535, 586, 587, 588, 589, 21,
  65, 22, 23, 24, 116, 117, 590, 118, 25, 648,
  26, 119, 120, 157, 366, 1334, 2019, 2810, 121, 153,
  297, 591, 2092, 27, 28, 29, 30, 31, 60, 87,
  122, 411, 1343, 2025, 592, 904, 1862, 1565, 1860, 2890,
  2526, 1566, 1859, 2194, 2528, 593, 594, 595, 797, 798,
  1239, 123, 237, 365, 652, 653, 965, 1332, 596, 950,
  951, 597, 828, 1283, 952, 774, 89, 90, 91, 92,
  1246, 183, 137, 93, 697, 134, 191, 192, 1247, 1248,
  1869, 1249, 408, 409, 933, 410, 934, 1583, 1584, 1250,
  1251, 1124, 2632, 2633, 2815, 1386, 812, 813, 598, 1139,
  2875, 599, 2503, 600, 1157, 1158, 1159, 1498, 1496, 601,
  602, 1782, 1812, 603, 1012, 1383, 604, 856, 857, 605,
  872, 606, 1961, 607, 2881, 608, 1830, 3011, 3012, 3013,
  3100, 861, 609, 1252, 1578, 1895, 1896, 610, 1466, 690,
  1024, 611, 612, 613, 2027, 2636, 2826, 2827, 2955, 2956,
  2960, 2958, 2961, 3063, 3065, 614, 615, 1241, 1570, 616,
  1243, 880, 881, 882, 1219, 617, 618, 619, 1540, 1211,
  875, 198, 883, 884, 775, 2028, 2343, 2344, 2327, 716,
  717, 2023, 2328, 2331, 124, 152, 358, 989, 1677, 2345,
  2830, 1033, 620, 873, 125, 149, 355, 986, 1675, 2332,
  2828, 2024, 899, 2176, 2747, 3014, 1214, 621, 622, 623,
  624, 625, 784, 1780, 710, 1729, 626, 2695, 704, 705,
  2089, 1362, 627, 628, 998, 999, 1000, 1374, 1714, 1001,
  1711, 1371, 1002, 1686, 1363, 1003, 1004, 1005, 1006, 1680,
  1354, 629, 793, 776, 630, 1306, 1307, 1630, 2590, 2793,
  2272, 2587, 3032, 3033, 1308, 1640, 2280, 1993, 2602, 2802,
  1822, 2168, 1994, 1309, 1310, 2706, 2986, 2987, 2988, 3079,
  1311, 1312, 1161, 631, 632, 958, 1313, 1314, 2952, 1646,
  1647, 1648, 1996, 2282, 2805, 2806, 1315, 1971, 2266, 2790,
  1364, 1365, 1350, 2048, 1678, 2049, 1366, 2053, 1367, 2076,
  1368, 2077, 2397, 2398, 1681, 1316, 1624, 1625, 1968, 1317,
  2982, 2857, 2978, 1974, 2412, 2698, 2699, 2700, 2976, 2413,
  1975, 2858, 2983, 2036, 2037, 2038, 2039, 2040, 2832, 2654,
  2965, 2041, 2833, 2834, 2371, 2042, 2372, 2043, 2545, 1707,
  1708, 1709, 2684, 1710, 2394, 2388, 2846, 2050, 2807, 2375,
  2596, 2052, 2855, 1897, 777, 1898, 2203, 1051, 2098, 2715,
  2066, 2680, 59, 633, 634, 2582, 2785, 2259, 2784, 1651,
  2001, 2002, 2263, 1962, 1318, 1963, 1982, 2593, 1405, 1958,
  1959, 2707, 2860, 2783, 2586, 1899, 1638, 2094, 2095, 2979,
  2044, 1901, 1902, 2547, 2656, 635, 636, 1617, 1960, 2577,
  2780, 2781, 1286, 637, 779, 1320, 1321, 1633, 2274, 1322,
  1323, 1979, 3054, 2541, 638, 912, 1260, 1261, 1262, 1263,
  1324, 1983, 2799, 2945, 2597, 2598, 2599, 2600, 2798, 2934,
  2935, 2936, 2937, 2938, 2939, 3118, 698, 1580, 700, 1387,
  1903, 63, 48, 77, 74, 640, 886, 1544, 1147, 1205,
  641, 865, 642, 2143, 643, 1723, 702, 1389, 644, 645,
  42, 359, 360, 361, 362, 363, 646
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2622
static const short yypact[] = {
  2144, 860, 295, 596, 596, 596, 596, 596, 596, 596,
  -2622, 596, 295, 1347, -2622, -2622, -2622, 1308, -2622, -2622,
  -2622, 290, -2622, 2144, -2622, -2622, -2622, -2622, -2622, 2609,
  -2622, -2622, -2622, -2622, -2622, 363, 298, -2622, 391, -2622,
  -2622, -2622, -2622, -2622, 295, 53, -2622, -197, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  1479, 475, -2622, -2622, -2622, 347, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, 295, -2622, -2622, 53, -138,
  -2622, 295, 680, 1308, -2622, 520, -2622, -2622, -2622, -2622,
  1102, 306, -2622, -2622, -2622, 915, 599, 295, -2622, -2622,
  935, 295, -2622, -2622, 295, 295, -2622, -2622, -2622, -2622,
  295, 295, -2622, -2622, -2622, -2622, -2622, 347, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 7884,
  306, -2622, 288, 315, -2622, -2622, 506, -2622, -2622, 957,
  475, 477, -2622, -2622, -2622, -2622, -2622, 3342, -2622, 295,
  577, 904, 295, 1308, -2622, -2622, -2622, 295, -2622, -2622,
  531, 1297, -2622, -2622, 648, -2622, 677, -2622, 571, -2622,
  -2622, 699, -2622, 715, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, 723, -2622, -2622, -2622, 315, 1704, 1118,
  -2622, 233, -2622, 315, -2622, 227, -2622, -2622, -2622, 171,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 531, -2622,
  1297, -2622, -2622, 747, -2622, 751, -2622, 768, -2622, -2622,
  801, -2622, 805, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, 814, 1212, 295, 838, -2622, 1308, 1308, 851, 295,
  -2622, 609, -2622, 645, 1465, -2622, 668, 1478, 1258, 1263,
  295, 1266, 1275, 1283, -2622, 716, -2622, 1006, -2622, -2622,
  -2622, -2622, -2622, 315, -2622, 315, 883, 249, -2622, -2622,
  -2622, 1300, -2622, -2622, 1311, -2622, -2622, -2622, -2622, -2622,
  609, -2622, -2622, -2622, 1334, 1338, 475, 1266, 1360, 1367,
  778, -2622, 1358, -2622, 1036, 994, -2622, 1071, -2622, -2622,
  -2622, 818, -2622, -2622, 1391, -2622, 1013, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, 1478, 1013, -2622, -2622, -2622, -2622,
  -2622, -2622, 1039, 196, 204, 796, -2622, 6594, -2622, -2622,
  -2622, 1073, 1458, 250, 1123, -2622, -2622, 1704, -2622, 315,
  -2622, -2622, -2622, 902, 1496, 1310, 264, 343, 842, 1146,
  352, 1184, -2622, -2622, -2622, 295, -2622, -2622, 295, 1226,
  -2622, 3633, 477, 4733, 2309, 344, 295, 1558, -5, -2622,
  1465, 1546, -2622, -2622, -2622, -2622, 1559, -2622, 1602, -2622,
  1604, -2622, 295, -2622, 295, -2622, -2622, 1266, 1606, -2622,
  -2622, -2622, -2622, 276, 1613, -5, 1225, 1610, -2622, 1612,
  -2622, -2622, -2622, 1615, -2622, -2622, -2622, 1043, 1274, 1644,
  -2622, 295, 1284, -2622, -2622, -2622, 295, 287, 295, 295,
  287, 287, 922, 295, -2622, 295, -2622, -2622, 295, -2622,
  892, -2622, -2622, -2622, 287, -2622, -2622, -2622, -2622, 295,
  -2622, -2622, -2622, -2622, 82, 82, 7065, -2622, -2622, -2622,
  -2622, -2622, 287, -2622, -2622, 287, -2622, -2622, 295, -2622,
  -2622, 287, -2622, -2622, 289, 287, -2622, -2622, 7065, 287,
  289, 295, 289, 287, -2622, -2622, 180, 287, 287, 180,
  287, 295, 180, 287, -2622, 287, 287, 287, -2622, -2622,
  -2622, -2622, 289, 287, -2622, -2622, 287, 51, 295, -2622,
  -2622, -2622, -2622, 287, 922, -2622, -2622, -2622, 287, -2622,
  6482, 289, 7065, -2622, 56, 56, 287, -2622, -2622, 1182,
  289, 1210, 7065, 7065, -2622, 1392, 7065, 287, 53, -2622,
  7065, 287, 7065, 289, -2622, 287, 7065, -2622, 7065, 82,
  295, 287, 295, 56, 287, 295, 56, -2622, 295, 299,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 137, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 628, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 728, -2622,
  295, -2622, 616, -2622, 1285, -2622, -2622, -2622, 1375, -2622,
  -2622, 1293, 1294, 1299, 1307, -2622, -2622, 1049, 1676, 1312,
  -2622, -2622, 1402, -2622, 1319, 1320, 1088, 1325, 295, -2622,
  295, 1328, -2622, 279, 1290, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, 1101, 1409, 1273, -2622, 1106, -2622,
  1113, -2622, 1709, -157, 374, -2622, -2622, -2622, 1321, -2622,
  1468, -2622, 1259, 216, -2622, -2622, -2622, 1451, -2622, 7065,
  7065, -2622, -2622, 1323, 1229, 1326, 1329, 1330, 1332, 1340,
  1341, 1343, 1345, 1346, 7065, 1541, 1348, 1349, 1351, -2622,
  7065, 7065, 1352, 1354, -2622, 7065, 1362, -2622, 1364, 1366,
  1370, 1377, 1378, 1381, 1384, 7065, 1385, 5962, -2622, 90,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, 741, -2622, 1331, -2622, -2622, -2622, -2622, -2622,
  -2622, 289, -2622, -2622, 1468, -2622, 209, -2622, -2622, 1492,
  -2622, 122, -2622, 1361, -2622, -2622, -2622, -2622, 1761, -2622,
  -2622, -212, -2622, 1147, -2622, 1169, 1761, -2622, 1194, -2622,
  -2622, 1401, 121, -2622, 1363, -2622, 1163, -2622, -2622, 1396,
  -2622, -97, -2622, 1168, 603, -235, -2622, 1503, 7065, 7065,
  -2622, 1807, 287, -2622, -2622, -2622, -2622, -2622, 346, 346,
  346, -2622, 346, -2622, 346, 346, 1242, 209, 1242, 1242,
  1224, 1224, 1242, 1242, 209, -2622, 1817, -2622, 24, 1818,
  -2622, 209, -2622, 6465, -2622, 81, 63, -2622, -2622, 7065,
  -2622, -2622, -2622, -2622, -2622, 1005, -2622, -2622, 477, 1462,
  477, 7065, -2622, 69, -2622, -2622, 7065, 1413, 1416, 1419,
  1424, 1500, 1433, 1210, 1366, -2622, 1508, 864, 1277, -2622,
  1286, -2622, -2622, -2622, 1260, -2622, 1837, -2622, 1839, 295,
  -2622, -7, 95, 1296, -2622, -2622, 1845, -2622, 1213, 1845,
  1850, 1220, 1845, 1850, 7065, 1845, -2622, -2622, 216, 289,
  -2622, -2622, 1455, 294, -2622, -2622, 1453, 289, 7065, 1456,
  -2622, -2622, 1841, 1843, 1816, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, 1287, 1287, 287, 287, 287, 4949, -2622,
  -2622, 1800, 728, -2622, -2622, 780, -2622, -2622, -2622, 1434,
  -2622, -2622, -2622, -2622, 7884, 1266, -2622, 1435, -2622, 389,
  -2622, -2622, -2622, -2622, -2622, -2622, 1308, -2622, -2622, 1308,
  844, 193, 1851, -2622, -2622, 252, 203, 546, 1870, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 1520, 1409, 1113,
  -2622, 922, -238, 1131, 295, -2622, -2622, 295, -2622, 1303,
  1276, 1313, 1471, -2622, 1476, 84, -2622, -2622, -2622, 2540,
  2540, 56, 7065, -2622, 56, 56, 56, 56, 1429, 7065,
  1152, 1460, 7065, 5962, 1481, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, 1288, 56, 1873, 7065, 4090, 5962, 1429, 7065,
  -2622, 5962, 1878, 382, -2622, -2622, -2622, 7065, -2622, 7065,
  7065, 5962, 7065, 7065, 7065, 7065, 7065, 7065, 7065, 7065,
  7065, 7065, 7065, 7065, 7065, 7065, 7065, 7065, 7065, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 7065,
  7065, -2622, -2622, 1495, 7065, -2622, 7065, 1497, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, 295, 289, -2622, 1295, 1498, -2622, -2622, -2622, 922,
  1305, -2622, 1305, 1210, 180, 7065, 7065, 7065, 1504, -2622,
  -2622, 289, 289, -2622, 1306, 1210, 56, 1280, 295, 315,
  49, 51, 289, -2622, 1318, 7065, 1586, -2622, -2622, 1380,
  -2622, -2622, 1818, 129, -2622, 216, -2622, -2622, 1921, 1922,
  -2622, -2622, -2622, -2622, -2622, -2622, 1177, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 6482,
  -2622, 1224, 7065, 441, -2622, -2622, 1937, -2622, 56, 1920,
  1925, -2622, -2622, -2622, -2622, -2622, 130, -2622, -2622, -2622,
  -2622, 1813, -2622, 1753, -2622, -2622, -2622, 7065, 82, -2622,
  -2622, 295, 1930, 56, 56, -2622, 1386, -2622, 56, 1353,
  289, -2622, 295, 295, 7065, 457, -2622, 1400, -2622, 257,
  -2622, 1493, -2622, 1502, 7065, 1033, -2622, -2622, 1365, -2622,
  1969, -2622, 1448, -2622, 289, -2622, -2622, -2622, 922, 289,
  184, -2622, -2622, -2622, -2622, 295, 56, 56, 238, 294,
  1853, 1563, 289, 216, -2622, 1459, -2622, -2622, 1984, 1972,
  1618, -2622, -2622, -2622, -2622, -2622, 1699, 1699, 258, 1474,
  -2622, 295, -2622, -2622, 1468, 1468, -2622, -2622, -2622, 295,
  -2622, 295, 529, 1468, -2622, 688, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 1262,
  -2622, -2622, -2622, -2622, -2622, 192, 192, 687, 911, -2622,
  748, -2622, 780, -2622, 1308, 1981, -2622, -2622, 1981, -2622,
  -2622, -2622, -2622, 1308, -2622, -2622, 1468, -2622, 683, 1596,
  -2622, -2622, 683, -2622, -2622, -2622, 1598, 1603, 581, 1619,
  1623, 1430, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 295,
  -2622, -2622, 581, 1369, -2622, 279, -2622, 1638, 306, 1411,
  -2622, 1210, 1466, -2622, -2622, 1578, -2622, -2622, -2622, 1501,
  -2622, 295, 295, 295, -2622, -2622, -2622, 423, -2622, 5962,
  1654, 1666, 424, 426, 529, 1667, 4664, 1668, -68, 1442,
  -2622, -2622, 139, 1673, -2622, -2622, -2622, 5079, 2021, 1541,
  1675, 1677, 5120, -2622, 1680, 3512, 1685, -2622, 7065, 7065,
  7065, 5379, 7065, 5404, 5490, 5530, 6065, 6159, 6189, 6273,
  3226, 6305, 1599, 6386, 3347, 3266, 3962, 2540, 2540, 2240,
  4519, 6075, 5576, 5691, 1429, 5962, 5860, 1429, 7065, 1648,
  -2622, 295, -2622, 1463, -2622, -2622, -2622, -2622, 1461, -2622,
  2056, 2058, -2622, 2059, 1505, 7065, -2622, -2622, 1472, 2062,
  -2622, 1616, 1469, 1850, -2622, 1698, 428, -2622, 1671, -2622,
  -2622, 1477, 1301, 295, -2622, -2622, 1672, 287, 929, 7065,
  -2622, 295, 295, 7065, 93, 209, 2074, 1552, 2065, 2066,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 1682, -2622,
  -2622, -2622, 289, 1585, 6465, -2622, -2622, -2622, 2049, 7065,
  477, 928, -2622, -2622, 1797, 2100, 2101, 433, 438, 295,
  1736, 1210, -2622, 7065, 1700, 1701, -2622, -2622, 1768, -2622,
  7065, 486, -2622, 1537, -2622, -2622, 275, -2622, 7065, -2622,
  -2622, 1510, 288, -2622, 1215, 295, 2103, 763, -2622, -2622,
  1718, -2622, 1720, 2118, -2622, -2622, -2622, 138, -2622, 1850,
  1850, 1482, -2622, 1593, 1600, 56, 56, -2622, -2622, -2622,
  -2622, -2622, -2622, 542, 620, -2622, 1056, -2622, -2622, -2622,
  -2622, 56, 1993, 2122, 2106, -2622, 1210, 758, 268, 147,
  2051, 43, 1182, -2622, 133, -2622, -2622, -2622, 1722, 78,
  1468, 248, -2622, 1534, 1527, -2622, -2622, -2622, -2622, -2622,
  580, -2622, -2622, -2622, -2622, 1727, 1536, 2136, -2622, 1533,
  -2622, -2622, -2622, -2622, 289, 127, -2622, -2622, -2622, 1523,
  911, -2622, 295, 295, -2622, -2622, 295, 587, -2622, -2622,
  -2622, -2622, 1738, 1744, -2622, 1717, -2622, 1724, -2622, 1748,
  447, -2622, 7141, 458, 94, 94, 460, -2622, 94, 7141,
  -2622, -2622, 1554, 1554, -2622, 1750, -2622, 1755, 1756, -2622,
  1758, 1759, -2622, 1764, -2622, -2622, -2622, 725, -2622, -2622,
  -2622, 462, -2622, -2622, 466, 295, -2622, -2622, 1131, 2164,
  1210, 315, 7065, -2622, 2172, -2622, -2622, -2622, -2622, 581,
  -2622, 56, -2622, -2622, -2622, -2622, -2622, 7729, -2622, -2622,
  1541, 1541, 2154, -2622, 2156, 1620, 1544, -2622, 1229, 1812,
  -2622, -2622, 1229, -2622, -2622, -2622, 1820, 1229, 5962, 5962,
  5962, 1229, 5962, 1229, 1229, 1229, 2169, 2171, 2173, 7065,
  1824, 2175, 7065, 1830, -2622, 2196, -2622, 5962, -2622, 1601,
  581, 236, -2622, 1210, 7065, 7065, 7065, 6552, 2201, 151,
  -2622, -2622, 1210, -2622, 1617, 295, 295, -2622, -2622, 295,
  295, -2622, 993, -2622, -2622, 819, -2622, 1626, 7065, -2622,
  -2622, -2622, 2200, -2622, -2622, -2622, -2622, -2622, 295, 1850,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  289, -2622, -2622, 4207, -2622, -2622, -2622, 1906, 2197, -2622,
  1897, 1904, 1792, 1630, 1908, 1827, -2622, -2622, -2622, 554,
  1894, -2622, -2622, -2622, -2622, 1768, -2622, -2622, -2622, 239,
  726, -2622, -2622, -2622, 1984, 7065, 1834, -2622, 1802, -2622,
  -2622, -2622, 2811, 2811, -2622, 1101, -2622, -2622, 1554, -2622,
  -2622, 7354, 1831, -2622, -2622, 1832, 1835, -2622, 1838, 1846,
  1859, 1860, 295, -34, -2622, 2247, -2622, -2622, -2622, -2622,
  -2622, 2547, -2622, -2622, 922, 289, 289, 155, 1621, -2622,
  2220, 209, 295, -2622, 2257, -2622, 2272, 1072, 1072, 1072,
  1072, 1682, -2622, -2622, 2273, -2622, -2622, -2622, 2275, -2622,
  -2622, -2622, 1072, 65, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  468, -2622, 2249, -2622, -2622, 1468, -2622, 529, -2622, -2622,
  -2622, -2622, -2622, -2622, 1705, 1719, 174, -2622, 133, -2622,
  94, 1696, 287, 7141, -2622, -2622, 1886, -2622, -2622, -2622,
  295, 295, 7729, 1735, -2622, 7065, -2622, 7065, -2622, -2622,
  -2622, -2622, -2622, -2622, 287, 94, -2622, 1468, 1027, 1702,
  1708, 2297, -2622, 2298, -2622, 289, 295, 827, 827, -2622,
  -2622, 2302, -2622, 2302, 632, 632, 2302, -2622, -2622, 2309,
  -2622, -2622, 1783, 52, -2622, 2309, 1422, -2622, 52, 94,
  683, -2622, 1901, 6197, 1901, 7181, 179, 2313, -2622, -2622,
  -2622, -2622, -2622, -2622, 259, -2622, 1468, 442, 1950, 2318,
  1723, -2622, -2622, 469, -2622, 581, -2622, 482, 191, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, 1716, -111, 2301, 2301,
  2303, 2301, 2301, 2307, -2622, 189, -2622, 683, 295, -2622,
  581, -2622, -2622, 1731, 1210, 2326, 278, -2622, 295, 483,
  -2622, 7065, 1964, -2622, 163, -2622, 4016, -2622, 1729, -2622,
  1967, -2622, 2327, -2622, 1780, -2622, -2622, -2622, -2622, -2622,
  1749, -2622, -2622, 1986, 1987, 1988, -2622, 1991, -2622, -2622,
  -2622, -2622, -2622, -2622, 5962, 484, -2622, -2622, 493, -2622,
  1995, 7065, 7065, 2348, 494, 1210, 2366, -2622, -2622, -2622,
  -2622, 7065, 1825, 2117, 7065, -2622, -2622, -2622, -2622, 1254,
  2007, 819, 1171, 1171, 2375, -87, -2622, 2377, -2622, -2622,
  -2622, 1171, 295, 1864, 1397, 2398, 295, -74, 289, 2184,
  496, -2622, 1593, 7065, -2622, 2401, 7065, 289, -2622, 892,
  295, 289, -2622, 2035, 7065, 7065, -2622, -2622, 554, 1894,
  -2622, 1682, -2622, -2622, 1336, -2622, -2622, 1858, -2622, 315,
  6881, 2023, 2023, -2622, 1806, 529, 2046, 66, 533, 7729,
  533, 533, 533, 533, 1821, 7729, 763, 7729, 7729, 7729,
  7729, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, 2001, 966, -2622, -2622, -2622, 1822, 56,
  1072, 56, 1072, -2622, -2622, -2622, -2622, -2622, 542, 1072,
  620, 1072, -2622, 209, 1993, -2622, 2053, 2016, 7729, 1262,
  147, 147, -2622, -2622, -2622, -2622, 511, -2622, 1976, -2622,
  2425, 94, -102, -2622, 1828, -2622, 2430, 150, -2622, -2622,
  1914, -2622, 522, -2622, 1833, -2622, 295, 295, 1533, 289,
  -2622, 2302, -2622, -2622, 295, 632, 632, -2622, -2622, 632,
  2248, 1844, 1852, -2622, -2622, 82, 82, 82, 2427, 82,
  82, 82, 82, 82, 82, 2428, -2622, 2429, 82, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 1783, -2622, 289,
  1856, -2622, 2032, 2248, 2436, -2622, 2443, 2444, 2446, 2447,
  2449, 2450, 1372, 1422, -2622, 2032, -2622, 524, -2622, 2025,
  -2622, 224, 273, -2622, -2622, 7141, -2622, 7141, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, 210, 2057, 210, -2622,
  2067, 614, 7729, -2622, 2454, -2622, 2207, 94, 1467, 94,
  -2622, -2622, -2622, -2622, 1793, 2460, 1793, -2622, 2481, 2481,
  526, 2121, 2481, -2622, 2123, -2622, -2622, -2622, 683, -2622,
  -2622, -2622, -2622, 1210, -2622, -2622, 581, 2241, 1984, -2622,
  7729, 220, 1982, 550, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 1847,
  1541, 1923, 1551, -2622, -2622, -2622, -2622, -2622, 7065, -2622,
  -2622, -2622, -2622, -2622, 2052, -2622, 262, 1210, -2622, 2493,
  2089, -2622, -2622, 2132, -2622, -2622, -2622, 1975, -2622, -2622,
  295, 1171, 315, 1470, 295, 1171, -2622, -2622, 56, -2622,
  -2622, 7065, -2622, -2622, -2622, 56, 2118, 2287, -2622, -2622,
  209, 5962, 2485, -2622, -2622, 216, 2105, -2622, -2622, 7065,
  -2622, -2622, 2138, -2622, -2622, -2622, 726, -2622, 1593, -2622,
  7065, -2622, 296, -2622, 1818, -2622, 1793, 7729, -2622, 342,
  2508, 2142, -2622, -2622, -2622, 7729, -2622, 527, 7729, 7729,
  7729, 7729, 295, 528, -2622, -2622, -2622, -2622, -2622, 7065,
  2094, -2622, 2191, -2622, 2498, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, 295, -2622, 111, -2622,
  -2622, -2622, 1262, 94, -2622, 529, 2399, 532, -2622, -2622,
  -2622, -2622, 295, 1989, 2509, 94, -2622, -2622, 2516, 2510,
  -2622, -2622, -2622, 94, -2622, 117, 1924, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, 2334, 7884, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, 357, 2522, -2622, 289, 1167, -2622, 2334, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, 2313, -2622, -2622, 2107, -2622, -2622, 202, -2622, 2107,
  202, -2622, 210, -2622, -2622, 7729, -2622, 305, -2622, -2622,
  -2622, 2092, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, 2160, -2622, 2511, 2161, 2162, 2512, -2622, -2622, 2166,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 285, 2534, -2622,
  -2622, 295, 2195, 295, 1939, 533, 2233, -2622, 2140, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 1566, -2622, -2622,
  -2622, 5962, 2180, 56, 209, 2199, 1210, -2622, 7065, -2622,
  2004, 2530, 209, -2622, -2622, 463, -2622, -2622, -2622, -2622,
  107, 2186, 1850, -2622, -2622, -2622, 2198, 2203, 2074, 2145,
  -2622, 2238, 2204, -2622, -2622, -2622, -2622, 2347, -2622, -2622,
  163, 1554, 1971, 1554, -2622, 2205, 7729, -2622, 2210, 2215,
  2216, 2217, -2622, -2622, 2034, -2622, -2622, -2622, 1593, -2622,
  534, -2622, 289, 2068, 1262, 1262, -2622, -2622, 7729, -2622,
  -2622, 94, -2622, 2183, -2622, 2068, 7400, -2622, 537, 131,
  94, 7498, 289, -2622, -2622, 314, -2622, -2622, 295, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, 289, 2522, -2622, -2622,
  -2622, 289, -2622, 289, -2622, -2622, 1876, -2622, 2378, -2622,
  2379, 189, -2622, 540, -2622, -2622, -2622, -2622, 543, 2107,
  2588, 2572, -2622, -2622, 1992, -2622, -2622, -2622, -2622, 2230,
  -2622, 220, -2622, 220, -2622, -2622, 7729, -2622, 2176, -2622,
  2241, 162, 268, 295, 2580, -2622, -2622, -2622, -2622, -2622,
  1210, -2622, 2235, 7878, 2221, -2622, -2622, -2622, 2010, 209,
  -2622, 26, -2622, -2622, -2622, 2234, 216, -2622, 2238, 2238,
  726, -2622, 2237, 2018, 1793, 2019, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, 295, -2622, 2118, 550, -2622, -2622,
  163, -2622, 7556, 550, 7827, 7827, -2622, -2622, -2622, 7296,
  2222, -2622, -2622, 2223, 2224, -2622, 2226, 2236, 2239, 2243,
  295, 508, -2622, -2622, 2640, -2622, -2622, 2566, -2622, -2622,
  -2622, 94, 2633, 287, 7141, -2622, -2622, 7658, -2622, 2118,
  117, -2622, -2622, -2622, -2622, 1631, 1631, -2622, 1631, -2622,
  1631, 1631, -2622, -2622, -2622, -2622, -2622, 198, -2622, -2622,
  -2622, 7729, 2244, 1793, -2622, -2622, 544, -2622, 2643, -2622,
  -2622, 7141, -2622, -2622, -2622, -2622, 2647, -2622, 370, -2622,
  -2622, 2241, 2284, 1185, -2622, -2622, 346, 346, 346, 346,
  346, 346, -2622, 2635, -2622, 552, -2622, 7065, 1488, -2622,
  -2622, -2622, 869, -2622, 2238, 7065, 2238, 2074, -2622, -2622,
  -2622, 2435, -2622, 1793, -2622, 1793, 138, 209, -2622, -2622,
  -2622, -2622, 559, -2622, -2622, -2622, 2566, 2566, 570, 2289,
  66, 533, 7778, 533, 533, 533, 533, 2060, 7778, 7498,
  7827, 7827, 7827, 7827, -2622, -2622, 2253, -2622, 2425, 2289,
  -2622, -2622, -2622, 1631, -2622, 1631, -2622, -2622, -2622, -2622,
  -2622, -2622, 220, -2622, 7729, 2425, 162, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, 992, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, 7878, -2622, 2661, -2622, -2622,
  896, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 155,
  -2622, 7556, -2622, -2622, -2622, 2300, 7778, -2622, 590, 7778,
  7778, 7778, 7778, 295, 604, -2622, 2269, 2269, 2190, 2370,
  7498, -2622, -2622, -2622, -2622, -2622, 1054, 1054, -2622, -2622,
  1054, -2622, 7065, -2622, 2304, -2622, -2622, -2622, 2306, 7778,
  -2622, 2310, 2311, 2312, 2314, -2622, -2622, 607, -2622, -2622,
  -2622, 2315, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, 186, -2622, 216, -2622, 2074
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] = {
  -2622, -2622, -2622, -2622, -2622, 491, -2622, 593, -183, -2622,
  -2622, -847, -439, -2622, -2622, -1553, -2622, -2622, -2622, -2622,
  -420, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -1847, -2622, -1534, -2622,
  557, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 830, -2622,
  -2622, -2622, -2622, 1454, -2622, 1129, -2622, -2622, -56, -2622,
  -2622, 2655, -2622, 2654, 2330, -2622, -2622, -2622, -2622, -2622,
  901, 536, -2622, 898, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -114, 991, 385, -2622, -2622,
  2416, 105, -2622, 2563, -2622, -2622, 2560, -2622, 2497, -2622,
  -2622, -2622, 2426, 2316, 1371, 2420, -303, -2622, -2622, -2622,
  -2622, -2622, 1379, -975, -2622, -2622, -2622, -2622, -2622, -2622,
  -137, 2356, 2500, -199, 959, -2622, 2349, 254, -2622, 2408,
  -2622, -2622, -2622, -2622, 2410, -2622, -2622, -2622, -2622, -321,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 2343, -2622,
  2344, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -895,
  -2622, -2622, -358, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  1742, -2622, -2622, 1195, -2622, -887, -807, 135, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 958, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -396, -2622, -2622, -2622, -2622,
  -2622, 2214, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -1705, -2622, -2622, -2622, -2622, -2622, -2622, 1333, -2622, -2622,
  -246, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, 1770, -2622, -2622, -2622, -2622,
  1075, -2622, -2622, -2622, -2622, -2622, -1336, -2622, -2622, 1074,
  -2622, -2622, -2622, -2622, -2622, -2622, -811, -514, 954, 1240,
  -2622, -465, 633, -809, 1272, -2622, 384, -2622, -1829, -2,
  -402, -2622, -2622, -1754, 492, 1355, -2622, -2622, -2622, 712,
  1480, -2622, -2622, -2622, -2622, -2622, -2622, 510, -2622, 185,
  -2622, 1483, -2622, 1155, -2622, 840, -2622, -2622, -2622, -360,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 960, -2622,
  -1221, -2622, 1148, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, 504, -2622, 503, -2622, -2622, -2622, -2622,
  1608, -2622, -2622, -2622, -2622, -2622, -2622, 20, -1474, -2622,
  -2622, -2622, -2622, 340, -2622, -1294, -2622, -841, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, 2738, -2622, -2622, -2622, 2645, 2734, -497,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 128, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, 2739, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, 1201, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -423, 2290,
  -2622, -2622, -2622, -2622, -2622, 2119, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, 1829, -2622, -2622, -64, -2622,
  -2622, 1197, -2622, -2622, -2622, -695, -188, 2514, -2622, -2622,
  -2622, -2622, 2, -2622, -710, 2095, 1507, -2108, 870, -2622,
  1202, 1862, 153, -31, -2622, -2622, -2622, 1646, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, 1607, -2622,
  1170, -2622, -343, -2622, -2622, -2622, -2622, -2622, -2622, -219,
  -2622, -2622, -2622, -2622, -2622, -2622, 579, -2622, 1670, -39,
  -2622, -2622, -2622, -2622, -2622, 455, -2622, -23, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, 1926, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -322, -2622, 1587, 1745, -2622, -2622, 467, -2622, -379,
  -2622, -2622, 478, 785, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, 669, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2613, -2622, 1815,
  1058, -977, -2622, -2622, -2622, 1464, -2622, -1318, -2622, -2622,
  -2622, -1324, -2622, -2622, -1306, -2622, -2622, -2622, -2622, 1491,
  -2622, -2622, -2622, -2622, -2622, -2622, 874, -2622, -2622, -2622,
  -2622, -2622, -2622, -264, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -232, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -2622, 852, -2622, -2622, -2622, -98, -2622, -2622, -2622, -2622,
  -2622, -2622, 479, -2622, -2622, 824, -2622, 1172, -2622, -2622,
  -2622, -2622, -2622, -2622, -964, -2622, -2622, -2622, -2622, -1333,
  -2622, -2622, -2622, -2622, -2622, -2622, -1930, 160, -2622, -1659,
  446, -2622, -2622, -1667, 507, 509, 829, -2622, -2354, -2034,
  -2622, -2622, 205, -100, -2622, -2622, -2622, -2622, -1954, -2622,
  -2622, -2622, -1361, -2622, -2622, -869, -2622, -703, 1577, 200,
  -1408, 823, -2622, 74, -2622, -2622, -2622, -2622, -678, -2622,
  -1646, -2321, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2057,
  -2622, 584, -2622, -1260, -2622, 1915, -2622, -2622, -723, 12,
  -2622, -1384, 13, 284, 606, -1610, -1380, -1955, 470, -195,
  -1367, -267, -2622, 666, 54, -2622, -2622, 1595, -496, -2622,
  -2622, -21, 1932, -2622, 523, -2622, -2622, -1246, 292, -2622,
  -2622, -2622, -1379, -153, -2622, -2622, -2622, 1628, -2622, -2622,
  -2622, -2622, -2622, -2622, -2622, -2622, -2300, 89, -2622, -2621,
  -1941, -1781, -1399, -2622, -2622, -158, -432, -406, -490, 1173,
  -896, 35, 2380, 62, -2622, -2622, -2622, -2622, -2622, 1746,
  -2622, -502, -2622, -2622, -2622, -2622, -2622, -2622, -2622, -2622,
  -324, 1246, 2533, -2622, -2622, -2622, -2622
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1836
static const short yytable[] = {
  41, 1010, 1175, 1025, 257, 267, 385, 1022, 1341, 112,
  56, 58, 283, 866, 1193, 685, 699, 130, 1804, 1846,
  1373, 1162, 2058, 1166, 1737, 878, 1351, 2276, 1172, 1173,
  2193, 1174, 820, 1177, 1178, 32, 2099, 1268, 255, 235,
  415, 920, 73, 76, 923, 1712, 2158, 2067, 1593, 1594,
  778, 1278, 1687, 778, 1713, 1634, 802, 1052, 32, 1951,
  2506, 112, 1206, 787, 69, 2682, 718, 778, 1198, 1487,
  1198, 778, 827, 127, 1217, 40, 76, 40, 804, 40,
  337, 1125, 40, 778, 668, 787, 1198, 290, 136, 1273,
  1020, 815, 40, 687, 787, 143, 687, 687, 699, 148,
  126, 826, 150, 151, 2253, 268, 830, 714, 154, 155,
  687, 829, 1198, 268, 868, 1118, 2410, 863, 1020, 40,
  40, 869, 298, 299, 1965, 815, 1142, 1257, 687, 815,
  1396, 687, 2005, 815, 1499, 1192, 1253, 687, 1199, 787,
  128, 687, 787, 40, 1200, 687, 1288, 231, 1290, 687,
  234, 393, 126, 687, 687, 238, 687, 1744, 944, 687,
  914, 687, 687, 687, 1745, 831, 96, 2329, 2410, 687,
  2594, 2145, 687, 40, 1020, 1020, 40, 40, 1500, 687,
  1501, -1834, 1502, 935, 687, 2355, 1020, 2985, 40, 274,
  1130, 1131, 687, 272, 268, 275, 276, 2355, 2231, 139,
  40, 378, 2579, 687, 795, 1009, 40, 687, 1972, 380,
  1900, 687, 268, 2395, 1876, 2759, 1257, 687, 1269, 40,
  687, 268, 1875, 1876, 40, 268, 1875, 1876, 40, 40,
  2355, 295, 2204, 268, 2395, 1876, 40, 301, 265, 268,
  926, 927, 40, 1499, 1020, 96, 40, 2984, 329, 200,
  268, 269, 270, 40, 265, 388, 2548, 2549, 2550, 2551,
  876, 2943, 40, 2192, -1834, 40, 1258, 2725, 2358, 397,
  2359, 2360, 2361, 2362, 2363, 2364, 2051, 2054, 40, 1563,
  2054, 265, 2358, 265, 2359, 2360, 2361, 2362, 2363, 2364,
  64, 1969, 876, 1155, 40, 2797, 2504, 1563, 3038, 1273,
  2385, 265, 1598, 2578, 1741, 2837, 2270, 557, 647, 1020,
  2841, 40, 181, 40, 40, 40, 990, 991, 1254, 2950,
  1381, 40, 268, 926, 927, 40, 34, 2013, 1804, 3172,
  2016, 291, 184, 185, 2659, 1424, 1184, 1185, 1190, 936,
  186, 40, 1149, 2510, 992, 993, 994, 2761, 399, 1294,
  2585, 81, 2492, 407, 1585, 1258, 407, 403, 2589, 1538,
  412, 1382, 1581, 1015, 407, 1156, 2351, 656, 654, 695,
  2096, 1167, 40, 695, 1619, 1620, 1, 2215, 3080, 1017,
  329, 2146, 329, 101, 343, 936, 345, 81, 102, 1135,
  1191, 96, 936, 70, 1339, 1373, 1136, 1229, 639, 649,
  712, 657, 62, 1296, 1977, 133, 817, 81, 1181, 407,
  81, 78, 1016, 681, 683, 1188, 688, 689, 33, 782,
  696, 701, 2350, 703, 2353, 1274, 706, 724, 1731, 1731,
  868, 1198, 791, 103, 104, 2951, 1602, 689, 1731, 81,
  391, 105, 2539, 1198, 772, 258, 259, 260, 261, 262,
  3, 4, 2030, 5, 6, 1506, 689, 391, 7, 81,
  81, 129, 937, 2030, 936, 2055, 772, 2078, 62, 689,
  81, 2080, 1564, 2254, 2379, 8, 9, 684, 1356, 805,
  258, 259, 260, 261, 262, 2970, 81, 2379, 2406, 2468,
  1564, 1357, 2365, 10, 11, 821, 823, 2386, 2468, 2406,
  1978, 2508, 696, 1742, 684, 1150, 2365, 938, 687, 3157,
  772, 3173, 821, 821, 2206, 2493, 2583, 81, 1379, 1255,
  772, 772, 2227, 897, 772, 2786, 76, 2603, 772, 2377,
  772, 2686, 2766, 2766, 772, 1403, 772, 2791, 915, 2904,
  915, 821, 2941, 915, 821, 2967, 915, 2330, 2967, 3072,
  1573, 2356, 1256, 868, 830, 868, 1212, 3095, 1215, -1834,
  2804, 2595, 2267, 2383, 3111, 1878, 1398, 2505, 379, 1400,
  1401, 1398, 40, 3024, 1878, 3049, 381, 2258, 1878, 1380,
  1879, 758, 2760, 1818, 2163, 1973, 1878, 2283, 1420, 1879,
  903, 1628, 1629, 1879, 818, 3149, 2650, 1910, 2473, 1302,
  1639, 1879, 1201, 788, 1352, 699, 40, 40, 938, 3149,
  1820, 2366, 3049, 1289, 1369, 2096, 2726, 684, 1861, 1305,
  1966, 2051, 389, 2662, 75, 2366, 1302, 2247, 2839, 40,
  1259, 687, 687, 687, 939, 2265, 398, 1468, 2944, 2731,
  266, 3055, 2513, 1679, 1483, 2538, 2782, 860, 964, 1482,
  2521, 2522, 3071, 1336, 2205, 2006, 340, 879, 885, 1143,
  2046, 901, -1834, 1358, 928, 905, 2352, 907, 2367, 1218,
  2291, 911, 1337, 913, 2906, 1621, 985, 1530, 407, 2232,
  939, 1864, 2367, 670, 271, 2404, 820, 939, 2046, 2059,
  1202, 2411, 271, 696, 2949, 106, 2851, 1463, 1488, 2755,
  819, 2574, 3107, 2758, 3108, 819, 2264, 1204, 1021, 1359,
  1746, 1469, 2842, 40, 995, 400, 2697, 772, 772, 1259,
  1957, 107, 1548, 699, 404, 1360, 187, 2908, 2909, 1503,
  1132, 1770, 772, 1535, 1773, 2275, 2733, 1504, 772, 772,
  2738, 1750, 819, 772, 2046, 2046, 1018, 796, -1834, 2381,
  733, 2862, 2090, 772, 2400, 2716, 2046, 2658, 1398, 939,
  2661, 1340, 2401, 1550, 1589, 1590, 1532, 929, 940, 941,
  942, 1910, 1356, 271, 81, 737, 2060, 1557, 978, 943,
  1872, 1873, 1021, 1874, 40, 1357, 268, 1875, 1876, 40,
  1402, 271, 108, 2061, 2135, 1732, 1735, 2368, 1736, 2540,
  271, 382, 996, 2090, 271, 1840, 1854, 1356, 1877, 94,
  1841, 2368, 271, -1834, -1834, -1834, -1834, -1834, 271, 2031,
  1357, 1345, 2227, 2227, 2162, 2537, 772, 772, 1168, 271,
  2045, 1992, 2056, 2910, 2079, 1794, 2062, 1641, 2081, 1543,
  2255, 2380, 2546, 2369, 2663, 997, 1568, 140, 2546, 1900,
  2555, 2556, 2557, 2558, 2382, 2407, 2469, 2369, 81, 746,
  2948, 772, 2703, 2588, 2370, 2470, 2475, 772, 2509, 1635,
  2878, 810, 1342, 2542, -1834, 1344, 2063, 2813, 2370, 772,
  816, 2374, 1169, 2584, 772, 1719, 109, 33, 34, 1227,
  3077, 2096, 2017, 2762, 2604, -1834, 2649, 2525, 2687, 2767,
  2773, 271, 1984, 131, 2792, 2064, 2905, 1245, 138, 2942,
  684, 1985, 2968, 2074, 2065, 2969, 3073, 707, 40, 3048,
  140, 2975, 772, 2977, 3096, 918, 2814, 1976, 921, 81,
  2487, 3112, 43, 142, 695, 1986, 772, -1834, 1987, 3078,
  144, -1834, 3113, 1378, 953, 193, 694, 133, 40, 2903,
  1274, 650, 751, 1835, 40, 954, 1988, 1372, 132, 133,
  1346, 1922, 3150, 860, 753, 754, 1486, 110, 1152, 2669,
  194, 2672, 1923, 756, 651, 111, 3156, 1547, 780, 3169,
  197, 2664, 1345, 2665, 2171, 2750, 1636, 1955, 232, 1353,
  2543, 17, 789, 1361, 1370, 1361, 794, 233, 1197, 1730,
  2580, 2581, 1819, 1359, 860, 2666, 696, 955, 808, 696,
  251, 1385, 1388, 1393, 17, 703, 879, 1234, 1533, 1360,
  302, 1220, 956, 258, 259, 260, 261, 262, 2685, 821,
  772, 2689, 821, 821, 821, 821, 1347, 772, 1359, 1926,
  772, 3018, 3019, 2096, -1542, 2704, 1560, 303, 240, 1662,
  1927, 821, 1654, 772, 1360, 1845, 2705, 772, 1769, 248,
  383, 1772, 1989, 81, 2237, 772, 2348, 772, 772, -1834,
  772, 772, 772, 772, 772, 772, 772, 772, 772, 772,
  772, 772, 772, 772, 772, 772, 772, 3116, 249, 3119,
  3120, 3121, 3122, 695, -1834, 1809, 1637, 772, 772, 81,
  2544, 2892, 772, 1373, 772, 2075, 401, 1642, 3125, 1933,
  252, 44, 957, 2399, -1834, 2893, 1990, 2895, 1643, 1459,
  1954, 1346, 135, 1991, 2907, 45, 253, 696, 40, 256,
  1913, 1915, 3101, 772, 772, 772, 2913, 1797, 3039, 1878,
  1644, 1798, 3133, 264, 821, 1598, 1485, 1645, 1489, 821,
  46, 1384, 1120, 772, 1879, 1627, 1349, 40, 284, -1834,
  902, 1631, 285, 2269, 906, 2159, 3059, 3103, 910, 3105,
  2096, 1880, -1834, 687, 1881, 2787, 1407, 1408, 2765, 132,
  133, 2768, 2769, 2770, 2771, 2281, 2933, 1882, 1182, 1183,
  772, 2933, 1186, 1187, 1663, 2803, 821, 1347, 1010, 47,
  2389, 1510, 2391, 2392, 2408, 2788, 870, 287, 40, 2818,
  1662, 3138, 288, 1664, 1665, 772, 289, 830, 1834, 1545,
  1670, 821, 821, 650, 2085, 293, 821, 1883, 1884, 1676,
  1554, 1555, 772, 1666, 876, 1867, 40, 294, 868, -1834,
  1885, 40, 772, 1121, 1799, 966, 651, 1800, 80, 296,
  40, 3030, 2257, 305, 919, 1348, 696, 922, -1834, -1834,
  925, 3117, 300, 915, 821, 821, 2093, 3117, 1598, 1598,
  1470, 1471, 1472, -1834, 2484, 1231, 314, 3058, -1834, 1602,
  40, 2819, 1886, 323, 1238, 2136, 40, 2137, 324, 1623,
  1494, 330, 1021, 1021, 2284, 687, 2148, 1632, 2840, 1632,
  333, 1021, 132, 133, 2933, 2933, -1834, 1595, 334, 2933,
  1596, 1284, 1597, 40, 3075, -1834, 687, 1349, 335, -1834,
  3082, 1887, 339, -1834, 3083, 341, -1834, 1531, -1834, 1464,
  -1834, 40, 1598, 1888, 2091, 3148, 342, 2933, 3151, 3152,
  3153, 3154, 1599, -1834, 1021, 1889, 1890, 2820, -1834, 2821,
  959, 960, 879, 81, 1891, 1663, 1361, 1892, -1834, 346,
  2527, 1930, 40, 347, 2822, 271, 1232, 1370, 3164, 1556,
  1361, 57, 2823, 40, 1664, 1665, 2824, -1834, 336, 1571,
  352, 81, -1834, 2911, 1600, 350, -1834, -1834, 1601, 1726,
  1727, 1728, 351, 2534, 1666, 81, 2645, 353, 40, 2897,
  -1834, 2825, 1602, 1602, -1834, 357, 2573, 3010, 356, -1834,
  -1834, 3, 4, -1834, 5, 6, 368, 2499, 40, 7,
  367, 2096, -1834, 40, 371, -1834, 772, 772, 772, 2693,
  772, 81, 2933, 694, 2691, 40, 8, 9, 2933, 2933,
  2933, 2933, 2933, 2933, 978, 1797, 1642, -1834, -1834, 1798,
  376, -1834, -1834, 2989, 10, 11, 772, 1643, 81, 1779,
  1409, 1598, 1511, 387, -1834, 1410, 1602, 1412, 1512, 1513,
  1514, 1572, 133, 772, 1690, 2200, 81, 887, 1409, 1644,
  386, 3104, -1834, 1410, 1411, 1412, 1645, 2670, 1515, 2980,
  2736, 1807, 1020, 40, 40, 390, 40, 772, 2228, 1814,
  1815, 772, 821, 80, 394, 40, 2933, 81, 3098, 2933,
  2933, 2933, 2933, 3082, 40, 3036, 3037, 3083, 1603, 3087,
  2933, 395, 2300, 3029, 1225, 12, 40, 888, 2333, 3035,
  1649, 1650, 772, 2086, -1834, 1657, 1658, 772, 3010, 2933,
  1026, 1027, 1028, 81, 1376, 3034, 40, 1843, 2105, 396,
  273, 772, 1799, 402, 278, 1800, 405, 1999, 772, 40,
  1810, 1811, 2334, 81, 830, 889, 772, 2103, 413, 2104,
  868, 660, 1868, 1245, 2718, 1893, 2719, 1598, 655, 2335,
  2336, -1834, 3, 4, 662, 5, 6, 2337, 2402, 2865,
  7, 2866, 868, 821, 821, 1602, 1516, 940, 941, 1517,
  1207, 1208, 1209, 1210, 3069, 2201, 2202, 8, 9, 821,
  1788, 3087, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087,
  1088, 2338, 1465, 1518, 1465, 10, 11, 663, 1021, 664,
  2339, 669, 2540, 671, 1813, 674, 673, 675, 1472, 2476,
  677, 2812, 687, 1519, -265, 678, 679, 2000, 687, 680,
  81, 3126, 3127, 3128, 3129, 974, 682, 968, 969, 2340,
  2012, 2012, 890, 2745, 2012, 970, 971, 2744, 2989, 1197,
  687, 972, 1089, 1090, 1091, 1092, 1093, 1094, 1520, 973,
  1893, 975, 2047, 2047, 976, 977, 2047, 1893, 1095, 1096,
  1097, 981, 982, 693, 983, 1853, 12, 984, 1521, 1522,
  988, 1007, 1604, 1008, 2341, 1011, 711, 2980, 2701, 1523,
  1691, 1602, 133, 2082, 1524, 1013, 1385, 1014, -1834, 1023,
  772, 258, 259, 260, 261, 262, 15, 1361, 1019, 821,
  731, -265, 1122, 783, 1031, 1893, 1032, 1034, 891, 1129,
  1035, 1036, 732, 1037, 3034, -1834, 2342, 1137, -265, 800,
  801, 1038, 1039, 1525, 1040, 807, 1041, 1042, 809, 1053,
  1054, 2836, 1055, 1058, 2836, 1059, 1134, 772, 1692, 1138,
  772, 1140, 2458, 1062, 2565, 1064, 2567, 1065, 1361, 892,
  1693, 1066, 772, 772, 772, 772, 1526, 2047, 1067, 1068,
  1694, -265, 1069, 2150, 1807, 1070, 1072, 2155, 2155, 715,
  715, 1133, 1141, 1145, 1146, 2748, 772, 1148, 1695, 1151,
  1160, -1834, 306, -1834, 1595, 1165, 2167, 1596, 1696, 1597,
  1179, 1697, 1189, 1192, 1221, 315, 1213, 1222, -1834, 1098,
  1223, -265, 1099, 1230, 1698, 1224, -1834, 2303, 2304, 1598,
  -1834, 2305, 2306, 2307, 1228, 1242, 1234, 893, 1233, 1599,
  1265, -1834, 1244, 1264, 1266, 1198, 1272, 2087, 830, 830,
  -265, 1267, 1282, 772, 1276, -1834, 1280, 1279, 1281, -265,
  1893, 1893, 1327, 1335, 1338, 1375, 1355, 2869, 1392, 1893,
  1391, 1404, 1394, 1699, 1393, 2877, 748, 1395, 1044, 88,
  2214, 1600, 1418, 1421, 715, 1601, 1419, 15, 1426, 307,
  2940, 2059, 696, 1461, 930, 2940, 1454, 2692, 1457, 1462,
  2238, 894, 316, 1700, 1481, 1475, 308, 1495, 1497, 2138,
  2139, 1472, 2142, 1701, 1204, 1493, 2617, 2618, 2619, 317,
  2621, 2622, 2623, 2624, 2625, 2626, 687, 687, 1508, 2629,
  1509, 2308, 1534, 2165, 1702, 1536, 1539, 1703, 2309, 1704,
  1537, 1100, 1541, 1021, 1546, 750, 1567, 1549, 1551, 309,
  1560, 182, 190, 647, 752, 1569, 1101, 1574, 2047, 647,
  1102, 1893, 318, 1602, 1575, 1045, 1577, 1705, 2273, 1632,
  1893, 2727, 2310, 772, 1274, 772, 1706, 1611, 2060, 1499,
  2819, 2311, 1046, 2047, 2701, 1021, 2740, 1613, 1614, 310,
  2197, 1616, 1622, 2742, 2012, 2061, 1671, 1682, 1103, 1684,
  1717, 2532, 319, 1718, 1685, 1715, 190, 1721, 2940, 2940,
  2312, 2313, 190, 2940, 1720, 1603, 1733, 2047, 311, 1722,
  1688, 1893, 3009, 1893, 1689, 1047, 1104, 312, 1734, 1738,
  1740, 320, 2219, 2220, 2047, 1747, 1749, 1751, 2062, 1752,
  321, 2940, 1754, 1361, 649, 1105, 2820, 1757, 2821, 1778,
  649, 1784, 1781, 1785, 1786, 2314, 1787, 1790, 930, 1783,
  1793, 2836, 1934, 2822, 1789, 1048, 1370, 1792, 1361, 1273,
  1791, 2823, 1795, 1808, 1796, 2824, 1726, 1821, 2063, 772,
  1823, 1824, 190, 1825, 190, 1832, 2221, 2222, 2223, 2224,
  2225, 2226, 1829, -1834, 1049, 1838, 1839, 2315, 1844, 1851,
  2825, 1847, 1848, 1050, 1119, 1857, 1871, 2064, 1865, 1904,
  2278, 1905, 2279, 1906, 943, 1910, 2065, 1952, 1912, 772,
  772, 1953, 1964, 1970, 3057, 1981, 1980, 1106, 1995, 772,
  2673, 1998, 772, 1997, 2009, 2020, 2940, 2485, 2701, 2396,
  2701, 2021, 2940, 2940, 2940, 2940, 2940, 2940, 2022, 2029,
  1807, 2068, 2500, 2316, 2502, 2026, 2069, 2070, 190, 2071,
  2072, 772, 2084, 1, 772, 2073, 3017, 2088, 2517, 2100,
  3110, 2101, 772, 772, 2108, 3088, 3089, 3090, 3091, 3092,
  3093, 2102, 2111, 2121, 2708, 2122, 2126, 2123, 772, 2127,
  2, 2131, 2129, 2133, 1107, 2047, 2144, 1893, 2166, 1604,
  3053, 1333, 2174, 1893, 1893, 1893, 1893, 1893, 1893, 2149,
  2940, 2175, 2177, 2940, 2940, 2940, 2940, 2674, 2164, 2178,
  2871, 2179, 2180, 2181, 2940, -1834, 1010, 821, 2182, 821,
  2198, 2199, 2207, 2208, 2675, 2236, 2209, 3, 4, 2210,
  5, 6, 2216, 2940, 942, 7, 1893, 2211, 2868, 709,
  1087, 1088, 2239, 2221, 2222, 2223, 2224, 2225, 2226, 2047,
  2212, 2213, 8, 9, 2256, 2047, 2478, 2241, 2248, 2483,
  2250, 2709, 2260, 930, 2606, 2607, 2000, 2676, 3052, 3053,
  10, 11, 2610, 785, 2811, 2268, 2261, 2271, 2710, 790,
  2277, 792, 2288, 2289, 2286, 799, 1935, 2294, 799, 2735,
  2287, 799, 2349, 1089, 1090, 1091, 1092, 1093, 1094, 1936,
  2357, 811, 2376, 2377, 2384, 2378, 2387, 2677, 2390, 1095,
  1096, 1097, 2393, -1780, 2403, 860, 2409, 2459, 1, 2460,
  858, 2711, 2221, 2222, 2223, 2224, 2225, 2226, 871, 874,
  877, 2462, 2461, 1893, 898, 1893, 2678, 2463, 2464, 2465,
  2466, 12, 908, 2467, 2653, 2679, 2653, 2471, 2474, 2701,
  1893, 2477, 2480, 2479, 2994, 2047, 2671, 2047, 932, 2486,
  2490, 2712, 2494, 1937, 49, 50, 51, 52, 53, 54,
  1938, 55, 2498, 2317, 2318, 2319, 2320, 2321, 2322, 2323,
  2324, 2325, 2326, 2501, 1361, -1834, 2512, 2520, 1893, 1021,
  2713, 2530, 3, 4, 2536, 5, 6, 2107, 2538, 2714,
  7, 2109, 2561, 2552, 2564, 2575, 2112, 2576, 2585, 1939,
  2116, 2355, 2118, 2119, 2120, 2410, 2592, 8, 9, -1834,
  2655, 2605, 2655, 2221, 2222, 2223, 2224, 2225, 2226, 2601,
  2615, 2620, 2627, 2628, 1940, 10, 11, 2634, 2616, 2635,
  2638, 1029, 1030, 3175, 1941, 1942, 772, 2639, 2657, 2640,
  1098, 2641, 2642, 1099, 2643, 2644, 1043, 2205, 2660, 2667,
  1943, 13, 1056, 1057, 1346, 2681, 2683, 1061, 2155, 1973,
  2694, 2737, 2155, 2688, 2717, 2690, 821, 1071, 2728, 772,
  2729, 2723, 1944, 821, 2730, 1945, 1946, 2731, 2743, 2746,
  2753, 1947, 2749, 2763, 2764, -1834, 937, 772, 2778, 2789,
  930, 2800, 2796, 2801, 2782, 2809, 2808, 2816, 772, 2831,
  14, 2374, 2844, 2847, 2848, 1893, 2845, 2849, 2850, 2853,
  2861, 868, 932, 1893, 2856, 2863, 1893, 1893, 1893, 1893,
  2772, 2864, 2867, 2870, 2874, 2876, 2884, 772, 2880, 1086,
  1087, 1088, 15, 2886, 2217, 2218, 2219, 2220, 1948, -1834,
  2882, 1652, 1653, 715, 2779, 2883, 2888, 2896, 1669, 2894,
  1949, 2047, 2898, 3050, 3051, 3052, 3053, 2899, 2900, 2901,
  2273, 2902, 1100, 2047, 2912, 2971, 2411, 2972, 2963, 2964,
  2973, 2047, 2974, 1623, 2981, 2992, 3016, 1101, 2995, 3022,
  1123, 1102, 3008, 1089, 1090, 1091, 1092, 1093, 1094, 687,
  2221, 2222, 2223, 2224, 2225, 2226, 3023, 3025, 930, 1095,
  1096, 1097, 3007, 3040, 3041, 3042, 2741, 3043, 1, 2221,
  2222, 2223, 2224, 2225, 2226, 3049, 3056, 3044, 3074, 1103,
  3045, 3070, 3076, 1154, 3046, 696, 3081, 3106, 696, 3094,
  2653, 3114, 3123, 1893, 3130, 2756, 3142, 1171, 1171, 1171,
  2516, 1171, 3147, 1171, 1171, 3141, 3162, 1104, 3163, 88,
  88, 2405, 3165, 3166, 3167, 2190, 3168, 3170, 2472, 1559,
  1856, 71, 72, 558, 2774, 1021, 1105, 2151, 2497, 2854,
  2160, 2859, 348, 196, 201, 280, 344, 349, 406, 1673,
  282, 672, 3, 4, 2110, 5, 6, 2720, 1674, 659,
  7, 821, 877, 375, 373, 665, 772, 3139, 666, 1831,
  2128, 2835, 1331, 1240, 2835, 2010, 2655, 8, 9, 896,
  2140, 2018, 1743, 1816, 2563, 1588, 1909, 2777, 2235, 3145,
  2147, 1592, 2569, 2571, 1931, 10, 11, 932, 1123, 1490,
  2879, 66, 156, 67, 1893, 2829, 1277, 1863, 68, 1866,
  1098, 967, 806, 1099, 1399, 987, 2230, 1870, 1106, 338,
  1610, 1406, 1285, 1285, 1417, 2954, 1893, 2817, 1477, 2047,
  1837, 1270, 1967, 3102, 2931, 2554, 1529, 1422, 2047, 2931,
  2648, 1425, 1467, 2962, 1542, 2630, 2953, 1216, 1427, 1431,
  2647, 1433, 1434, 2346, 1435, 1436, 1437, 1438, 1439, 1440,
  1441, 1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450,
  1451, 1874, 1390, 1907, 268, 1875, 1876, 40, 2134, 1716,
  2262, 1452, 1453, 1683, 3135, 1107, 1455, 3146, 1456, 1021,
  2285, 1021, 3060, 2347, 1893, 2668, 1877, 2852, 2702, 2047,
  2057, 2859, 2651, 2872, 2354, 2838, 2652, 3068, 1626, 2373,
  2932, 2843, 2608, 1319, 2990, 2932, 2991, 2795, 2591, 3134,
  2696, 2553, 1618, 3028, 2794, 2966, 1287, 3115, 1586, 2946,
  3124, 2083, 1100, 1484, 414, 0, 0, 0, 0, 0,
  0, 0, 2779, 0, 0, 2655, 0, 1101, 0, 0,
  1893, 1102, 2931, 2931, 0, 0, 0, 2931, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 3047, 0,
  0, 0, 1894, 0, 0, 0, 0, 0, 0, 2047,
  0, 0, 1893, 0, 0, 2931, 13, 0, 1623, 1103,
  0, 1460, 0, 0, 0, 0, 0, 0, 0, 88,
  0, 88, 877, 799, 0, 696, 0, 0, 0, 1893,
  1476, 811, 0, 0, 877, 0, 0, 1104, 190, 1893,
  0, 1491, 695, 0, 0, 0, 0, 0, 2932, 2932,
  0, 0, 0, 2932, 932, 14, 1105, 0, 0, 0,
  0, 0, 0, 0, 0, 772, 3099, 0, 0, 0,
  0, 0, 0, 772, 0, 0, 0, 0, 0, 0,
  88, 2932, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1894, 2047, 0,
  2931, 2835, 0, 0, 1894, 0, 2931, 2931, 2931, 2931,
  2931, 2931, 0, 0, 0, 0, 0, 0, 0, 1552,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1021, 0, 1893, 0, 2047, 0, 0, 0, 1106, 0,
  0, 0, 0, 1579, 0, 0, 0, 0, 1582, 0,
  0, 0, 1894, 0, 0, 2186, 2187, 0, 0, 0,
  0, 1609, 932, 0, 0, 0, 2196, 0, 0, 1893,
  0, 0, 0, 0, 2931, 0, 2932, 2931, 2931, 2931,
  2931, 3155, 2932, 2932, 2932, 2932, 2932, 2932, 2931, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  772, 0, 3097, 0, 0, 1107, 0, 2931, 0, 0,
  0, 0, 0, 0, 0, 0, 1656, 0, 0, 0,
  0, 0, 0, 2243, 2244, 2245, 2246, 0, 0, 0,
  1758, 1759, 1760, 0, 1762, 0, 0, 0, 2252, 0,
  0, 0, 0, 0, 0, 0, 0, 1878, 0, 0,
  2932, 0, 0, 2932, 2932, 2932, 2932, 0, 0, 0,
  1777, 0, 1879, 0, 2932, 0, 0, 0, 0, 0,
  877, 0, 0, 0, 0, 0, 0, 0, 0, 1880,
  0, 0, 1881, 2932, 0, 0, 0, 1894, 1894, 0,
  0, 0, 0, 0, 0, 1882, 1894, 1078, 1079, 1080,
  1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 0, 0,
  0, 0, 0, 2292, 2293, 0, 0, 0, 0, 0,
  2297, 2298, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1884, 3161, 0, 0,
  0, 1833, 1083, 1084, 1085, 1086, 1087, 1088, 1885, 0,
  0, 0, 0, 0, 0, 1777, 0, 0, 0, 1089,
  1090, 1091, 1092, 1093, 1094, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1095, 1096, 1097, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1894, 0,
  1886, 0, 0, 0, 0, 0, 0, 1894, 0, 1089,
  1090, 1091, 1092, 1093, 1094, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1095, 1096, 1097, 0, 0,
  0, 1828, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1887,
  1836, 0, 0, 202, 0, 0, 0, 0, 0, 0,
  877, 1888, 0, 0, 0, 0, 0, 0, 1894, 0,
  1894, 0, 0, 1889, 1890, 0, 0, 0, 2488, 2489,
  0, 182, 1891, 203, 204, 1892, 0, 2496, 0, 0,
  0, 0, 205, 271, 0, 2507, 0, 0, 0, 0,
  1089, 1090, 1091, 1092, 1093, 1094, 0, 0, 0, 0,
  1894, 0, 0, 0, 2523, 2524, 1095, 1096, 1097, 0,
  0, 0, 0, 0, 0, 877, 1956, 877, 0, 0,
  0, 871, 0, 0, 0, 0, 1098, 0, 0, 1099,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 2004, 0, 0, 2566, 0, 2568, 0,
  0, 0, 0, 0, 0, 2570, 1098, 2572, 0, 1099,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 2124, 0, 0, 2124, 0, 0, 1755, 1073, 1074,
  1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084,
  1085, 1086, 1087, 1088, 0, 0, 0, 0, 0, 0,
  0, 2611, 2612, 0, 0, 2613, 2614, 0, 0, 877,
  190, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1894, 0, 0, 0, 0, 0,
  1894, 1894, 1894, 1894, 1894, 1894, 0, 1098, 1100, 2637,
  1099, 0, 0, 206, 0, 1089, 1090, 1091, 1092, 1093,
  1094, 0, 0, 1101, 0, 0, 0, 1102, 0, 0,
  0, 1095, 1096, 1097, 0, 0, 0, 0, 0, 0,
  877, 0, 877, 1894, 0, 0, 0, 0, 1100, 0,
  0, 877, 207, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1101, 0, 1103, 0, 1102, 0, 0,
  0, 208, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, -1835, 0, 209, 0, 2172,
  715, 715, 715, 1104, 715, 715, 715, 715, 715, 715,
  0, 0, 0, 715, 0, 1103, -1835, 0, 0, 0,
  210, 0, 1105, 0, 0, 0, 0, 0, 2195, 0,
  0, 0, 211, 0, 0, 0, 0, 0, 0, 1100,
  0, 0, 212, 1104, 0, -1835, 0, 0, 0, 0,
  1894, 0, 1894, 0, 1101, 0, 0, 0, 1102, 0,
  213, 1894, 1105, 1894, 0, 0, 0, 1894, 0, 0,
  214, 0, 0, 0, 2229, 1582, 0, 2734, 0, 0,
  0, 2739, 1098, 0, 0, 1099, 215, -1835, 0, 0,
  0, 0, 0, 0, 0, 0, 1103, 0, 0, 0,
  0, 0, 0, 0, 1106, 1894, 0, 0, 0, 0,
  0, 0, 2754, 0, 0, 0, 0, -1835, 0, 0,
  0, -1835, 0, 0, 1104, 0, 216, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1105, 1106, -1835, 2775, 0, 0, 0,
  217, 0, 0, -1835, 0, -1835, 0, 0, 0, 0,
  0, 0, 0, 0, -1835, 218, 0, 0, 0, 0,
  -1835, 1107, 219, 0, 2290, 220, 0, 0, -1835, 0,
  0, 0, -1835, 0, 0, 0, 0, 0, -1835, 0,
  0, 0, -1835, -1835, -1835, -1835, 221, 0, 0, 222,
  0, 223, 0, 0, 1100, 0, 0, -1835, 0, 0,
  930, 1107, 0, 1777, 1777, 0, 0, 0, 0, 1101,
  224, 0, 0, 1102, -1835, 1106, 0, -1835, 0, -1835,
  0, 0, 1894, 0, 0, 0, -1835, 0, 225, 0,
  1894, 0, 0, 1894, 1894, 1894, 1894, 0, 0, -1835,
  0, 0, 0, 877, 0, 2511, 0, 0, 1777, -1835,
  0, 1103, 0, 0, 0, 0, 1777, 1777, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, -1835, -1835,
  0, 226, 0, 0, 0, 0, 0, 0, 0, 1104,
  0, 0, 1107, -1835, 0, 0, 0, 0, 0, 0,
  0, -1835, 0, 0, 877, -1835, 0, 0, 1105, 0,
  0, 0, 0, 0, -1835, -1835, -1835, 0, 0, 1084,
  1085, 1086, 1087, 1088, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1582, 0, 0,
  0, 0, 0, 2891, 0, 0, 2514, 0, 709, 0,
  2518, 0, 1894, 0, 0, 1894, 0, 1894, 0, 0,
  1894, 0, 0, 2529, 0, 0, 0, 0, 190, 0,
  0, 0, 0, 0, 0, 1089, 1090, 1091, 1092, 1093,
  1094, 0, 40, -1835, 0, 0, 0, 0, 0, 0,
  1106, 1095, 1096, 1097, -1835, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, -1835, 1073, 1074, 1075, 1076,
  1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086,
  1087, 1088, 0, 0, 0, 0, 0, 1107, 2609, 0,
  0, 1894, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 3020, 0, 0, 0,
  0, 0, 0, 1894, 0, 0, 0, 0, 0, 0,
  0, 1894, 0, 0, 0, 0, 1894, -1835, 2631, 0,
  0, 0, 0, 1089, 1090, 1091, 1092, 1093, 1094, 0,
  0, 2646, 0, 0, 0, 0, 0, 0, 0, 1095,
  1096, 1097, 0, 0, 0, 0, 1894, 0, 0, 0,
  0, 0, 1098, -1835, 0, 1099, 0, 0, 0, 0,
  0, 3061, 3062, 0, 3064, 0, 3066, 3067, 0, 0,
  2721, 1894, 2173, 1073, 1074, 1075, 1076, 1077, 1078, 1079,
  1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 0,
  0, 0, 877, 0, 0, 0, 0, 0, 0, 0,
  -1835, 930, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, -1835, -1835, -1835, -1835, -1835, -1835,
  -1835, 1777, -1835, -1835, 0, 0, 0, 1894, 0, 1894,
  1894, 0, 3109, 0, 1894, 0, 0, 2414, 0, -1835,
  1089, 1090, 1091, 1092, 1093, 1094, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1095, 1096, 1097, 1894,
  0, 0, 1894, 0, 0, 0, 877, 0, 0, 3131,
  0, 3132, 0, 0, 1100, 0, 0, 2415, 2416, 2417,
  1098, 190, 1894, 1099, 0, 0, 1894, 0, 0, 1101,
  0, 0, 0, 1102, 0, 0, 1894, 0, 0, 0,
  0, 0, 2418, 0, 932, 0, 3143, 0, 0, 0,
  2419, 0, 0, 0, 0, 2420, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  2421, 1103, 0, 0, 0, 2422, 0, 2423, 0, 0,
  0, 0, 3158, 3159, 2424, 0, 3160, 2425, 0, 0,
  2426, 0, 0, 2427, 0, 0, 2428, 1894, 0, 1104,
  0, 2429, 0, 1894, 1894, 1894, 1894, 1894, 1894, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1105, 2430,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1894,
  0, 0, 0, 0, 0, 2431, 0, 1098, 2432, 2433,
  1099, 0, 1100, 0, 0, 2434, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 2435, 1101, 0, 0,
  0, 1102, 1423, 2631, 0, 0, 1894, 0, 0, 0,
  0, 1894, 2436, 0, 1894, 1894, 1894, 1894, 0, 2437,
  0, 0, 0, 0, 0, 1894, 2438, 0, 0, 2439,
  2440, 2441, 0, 2442, 2443, 0, 0, 0, 0, 1103,
  1106, 0, 0, 0, 1894, 0, 0, 0, 0, 0,
  2444, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1104, 930, 0,
  0, 0, 0, 0, 2445, 2446, 2447, 2448, 0, 2449,
  1088, 0, 0, 0, 0, 0, 1105, 0, 0, 0,
  0, 0, 0, 0, 0, 877, 2450, 2451, 0, 1100,
  0, 0, 0, 0, 0, 0, 0, 1107, 0, 0,
  0, 0, 0, 0, 1101, 0, 0, 0, 1102, 2452,
  0, 0, 0, 0, 0, 0, 0, 0, 2453, 2454,
  0, 2455, 1089, 1090, 1091, 1092, 1093, 1094, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1095, 1096,
  1097, 1582, 0, 0, 0, 0, 1103, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1106, 0,
  0, 1582, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1104, 2631, 0, 0, 0, 0,
  2957, 0, 2959, 2456, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1105, 0, 0, 0, 0, 0, 0,
  1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082,
  1083, 1084, 1085, 1086, 1087, 1088, 0, 0, 0, 0,
  0, 877, 0, 0, 0, 1107, 0, 0, 0, 877,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 932, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1089, 1090, 1091,
  1092, 1093, 1094, 0, 0, 1106, 0, 0, 0, 1098,
  0, 0, 1099, 1095, 1096, 1097, 0, 1777, 0, 0,
  0, 0, 1, 0, 0, 0, 416, 0, 417, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  418, 419, 0, 420, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 421, 0, 0,
  0, 0, 0, 0, 422, 0, 0, 0, 0, 0,
  0, 0, 1107, 0, 0, 423, 424, 425, 0, 0,
  0, 0, 0, 0, 0, 1171, 1171, 1171, 1171, 1171,
  1171, 426, 0, 427, 428, 429, 3, 4, 430, 5,
  6, 431, 0, 432, 7, 433, 434, 0, 0, 0,
  0, 0, 435, 0, 0, 436, 0, 437, 438, 439,
  0, 8, 9, 0, 0, 0, 0, 440, 0, 441,
  442, 1100, 443, 0, 444, 445, 0, 0, 446, 10,
  11, 0, 0, 447, 448, 449, 1101, 450, 451, 0,
  1102, 0, 452, 453, 1098, 454, 0, 1099, 0, 455,
  0, 456, 457, 0, 0, 0, 0, 458, 0, 0,
  0, 459, 0, 0, 460, 0, 461, 0, 462, 0,
  463, 0, 464, 465, 0, 466, 467, 468, 1103, 0,
  0, 469, 0, 470, 471, 0, 472, 0, 0, 0,
  0, 0, 0, 0, 473, 474, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1104, 475, 0, 0,
  476, 477, 0, 0, 478, 479, 0, 0, 480, 481,
  0, 0, 0, 0, 0, 1105, 0, 482, 483, 484,
  0, 485, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 486, 487, 488, 0, 489, 0, 0, 0, 490,
  491, 0, 932, 0, 492, 0, 0, 0, 0, 0,
  0, 0, 493, 0, 0, 0, 1100, 0, 0, 0,
  494, 495, 496, 0, 0, 0, 0, 0, 497, 498,
  0, 1101, 0, 0, 499, 1102, 1739, 500, 0, 0,
  0, 501, 502, 0, 0, 0, 0, 0, 1291, 0,
  0, 0, 503, 0, 0, 0, 0, 1106, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  504, 0, 0, 1103, 0, 0, 0, 0, 505, 0,
  0, 0, 0, 0, 506, 1073, 1074, 1075, 1076, 1077,
  1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087,
  1088, 1104, 0, 0, 0, 0, 0, 107, 0, 0,
  0, 0, 0, 0, 507, 0, 508, 509, 0, 0,
  1105, 0, 0, 0, 1107, 510, 1073, 1074, 1075, 1076,
  1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086,
  1087, 1088, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1292, 1089, 1090, 1091, 1092, 1093, 1094, 0, 1293,
  0, 0, 0, 0, 511, 1294, 0, 1295, 1095, 1096,
  1097, 0, 0, 0, 0, 512, 0, 0, 1296, 513,
  0, 0, 0, 514, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1089, 1090, 1091, 1092, 1093, 1094, 0,
  0, 0, 1106, 0, 0, 0, 1297, 515, 516, 1095,
  1096, 1097, 517, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1298, 0, 518, 0, 0, 1299, 0, 0,
  519, 520, 521, 522, 0, 0, 0, 523, 0, 1300,
  0, 524, 0, 0, 0, 0, 1301, 0, 525, 526,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  527, 0, 528, 0, 0, 0, 0, 0, 0, 1107,
  0, 0, 0, 529, 0, 530, 0, 0, 531, 0,
  0, 0, 0, 0, 532, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1098,
  533, 0, 1099, 534, 0, 0, 0, 0, 0, 535,
  0, 0, 536, 537, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 538, 0, 0,
  0, 0, 0, 0, 539, 0, 0, 0, 0, 0,
  1098, 0, 0, 1099, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 540, 541, 542,
  543, 544, 545, 546, 0, 0, 547, 0, 548, 0,
  549, 0, 0, 0, 0, 1073, 1074, 1075, 1076, 1077,
  1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087,
  1088, 1302, 0, 0, 0, 0, 0, 0, 1303, 0,
  1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082,
  1083, 1084, 1085, 1086, 1087, 1088, 0, 0, 0, 0,
  1304, 1100, 0, 0, 0, 1305, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1101, 0, 0, 0,
  1102, 1748, 1089, 1090, 1091, 1092, 1093, 1094, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1095, 1096,
  1097, 0, 1100, 0, 0, 0, 0, 1089, 1090, 1091,
  1092, 1093, 1094, 0, 0, 0, 0, 1101, 1103, 0,
  0, 1102, 1753, 1095, 1096, 1097, 1073, 1074, 1075, 1076,
  1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086,
  1087, 1088, 0, 0, 0, 0, 1104, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1103,
  0, 0, 0, 0, 0, 1105, 1073, 1074, 1075, 1076,
  1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086,
  1087, 1088, 0, 0, 0, 0, 0, 1104, 0, 0,
  0, 0, 0, 1089, 1090, 1091, 1092, 1093, 1094, 0,
  0, 0, 0, 0, 0, 0, 1105, 0, 0, 1095,
  1096, 1097, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080,
  1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 0, 0,
  0, 0, 0, 1089, 1090, 1091, 1092, 1093, 1094, 1098,
  0, 0, 1099, 0, 0, 0, 0, 1106, 0, 1095,
  1096, 1097, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1098, 0, 0, 1099, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1089,
  1090, 1091, 1092, 1093, 1094, 0, 0, 0, 1106, 0,
  0, 0, 0, 0, 0, 1095, 1096, 1097, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1107, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1073, 1074, 1075,
  1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085,
  1086, 1087, 1088, 0, 0, 0, 0, 0, 0, 0,
  1098, 0, 0, 1099, 0, 1107, 0, 0, 0, 0,
  0, 1100, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1101, 0, 0, 0,
  1102, 1761, 0, 0, 0, 0, 1100, 0, 0, 0,
  1098, 0, 0, 1099, 1089, 1090, 1091, 1092, 1093, 1094,
  0, 1101, 0, 0, 0, 1102, 1763, 0, 0, 0,
  1095, 1096, 1097, 0, 0, 0, 0, 0, 1103, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1098, 0, 0, 1099,
  0, 0, 0, 1103, 0, 0, 1104, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1105, 0, 0, 0, 0,
  0, 1104, 1100, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1101, 0, 0,
  1105, 1102, 1764, 0, 0, 0, 1073, 1074, 1075, 1076,
  1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086,
  1087, 1088, 1100, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1101, 0, 1103,
  0, 1102, 1765, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1106, 0, 0,
  0, 1098, 0, 0, 1099, 0, 0, 1104, 1100, 0,
  0, 0, 0, 1089, 1090, 1091, 1092, 1093, 1094, 1103,
  0, 0, 1106, 1101, 0, 0, 1105, 1102, 0, 1095,
  1096, 1097, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1104, 1073, 1074,
  1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084,
  1085, 1086, 1087, 1088, 1107, 1103, 1105, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1767, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1107,
  0, 0, 0, 1104, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1106, 0,
  0, 0, 1105, 0, 0, 1089, 1090, 1091, 1092, 1093,
  1094, 0, 0, 1100, 0, 0, 0, 0, 0, 0,
  0, 1095, 1096, 1097, 0, 0, 0, 0, 1101, 0,
  0, 0, 1102, 0, 0, 0, 0, 0, 1106, 0,
  0, 0, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081,
  1082, 1083, 1084, 1085, 1086, 1087, 1088, 0, 0, 0,
  1098, 0, 0, 1099, 0, 1107, 0, 0, 0, 0,
  1103, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1768, 1106, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1104, 0,
  0, 0, 0, 0, 0, 1107, 0, 0, 1089, 1090,
  1091, 1092, 1093, 1094, 0, 0, 0, 1105, 1089, 1090,
  1091, 1092, 1093, 1094, 1095, 1096, 1097, 0, 0, 0,
  0, 0, 0, 0, 1095, 1096, 1097, 1075, 1076, 1077,
  1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087,
  1088, 1107, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1098, 0, 0, 1099, 0, 0, 1076, 1077,
  1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087,
  1088, 0, 1100, 0, 1872, 1873, 0, 1874, 0, 0,
  268, 1875, 1876, 40, 0, 0, 0, 1101, 0, 1106,
  0, 1102, 1089, 1090, 1091, 1092, 1093, 1094, 0, 0,
  0, 0, 1877, 0, 0, 0, 0, 0, 1095, 1096,
  1097, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1089, 1090, 1091, 1092, 1093, 1094, 0, 1103,
  0, 0, 0, 0, 0, 0, 0, 0, 1095, 1096,
  1097, 0, 1771, 1077, 1078, 1079, 1080, 1081, 1082, 1083,
  1084, 1085, 1086, 1087, 1088, 1098, 1107, 1104, 1099, 0,
  0, 0, 0, 0, 0, 1098, 0, 0, 1099, 0,
  0, 0, 0, 0, 1100, 0, 1105, 1079, 1080, 1081,
  1082, 1083, 1084, 1085, 1086, 1087, 1088, 0, 0, 1101,
  0, 0, 0, 1102, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1089, 1090, 1091, 1092,
  1093, 1094, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1095, 1096, 1097, 0, 0, 0, 695, 0,
  0, 1103, 0, 0, 0, 0, 0, 0, 1089, 1090,
  1091, 1092, 1093, 1094, 0, 0, 0, 0, 0, 1098,
  0, 0, 1099, 0, 1095, 1096, 1097, 0, 1106, 1104,
  1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1100, 1105, 1098,
  0, 0, 1099, 0, 0, 0, 0, 1100, 0, 0,
  0, 0, 1101, 0, 0, 0, 1102, 0, 0, 0,
  0, 0, 1101, 0, 0, 0, 1102, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1089,
  1090, 1091, 1092, 1093, 1094, 1107, 0, 0, 0, 0,
  0, 0, 2032, 0, 1103, 1095, 1096, 1097, 0, 0,
  0, 0, 719, 720, 1103, 0, 0, 0, 268, 721,
  722, 40, 0, 0, 0, 0, 0, 0, 0, 0,
  1106, 0, 1104, 1098, 0, 723, 1099, 0, 0, 0,
  724, 1100, 1104, 0, 0, 0, 0, 725, 0, 0,
  0, 1105, 0, 0, 0, 0, 1101, 0, 0, 0,
  1102, 1105, 0, 0, 0, 1098, 0, 0, 1099, 0,
  0, 1100, 0, 0, 0, 726, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1101, 0, 0, 0,
  1102, 0, 0, 0, 0, 0, 0, 1107, 1103, 719,
  720, 0, 0, 1878, 0, 268, 721, 722, 40, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1879, 0,
  0, 833, 723, 0, 0, 0, 1104, 724, 1103, 384,
  834, 0, 0, 1106, 725, 1880, 0, 0, 2033, 835,
  0, 0, 0, 1106, 836, 1105, 1098, 0, 0, 1099,
  2034, 1882, 0, 0, 0, 1100, 1104, 0, 0, 0,
  0, 0, 726, 0, 0, 0, 81, 0, 727, 0,
  1101, 0, 0, 0, 1102, 1105, 0, 0, 0, 2205,
  0, 0, 0, 0, 0, 0, 0, 1100, 837, 0,
  0, 0, 1884, 0, 0, 0, 838, 0, 0, 0,
  1107, 0, 1101, 0, 1885, 0, 1102, 0, 0, 0,
  1107, 0, 1103, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1766, 0, 1106, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1104, 0, 0, 0, 1103, 0, 1886, 0, 0, 0,
  0, 0, 839, 81, 0, 727, 0, 1106, 0, 1105,
  0, 0, 0, 0, 0, 728, 0, 0, 1100, 0,
  729, 0, 1104, 0, 0, 0, 0, 840, 0, 0,
  0, 0, 0, 1101, 841, 1887, 842, 1102, 0, 0,
  0, 1105, 0, 0, 1107, 0, 843, 1888, 730, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1889,
  1890, 2035, 0, 0, 0, 0, 0, 0, 1891, 0,
  0, 1892, 844, 0, 1107, 1103, 0, 0, 0, 271,
  845, 0, 0, 731, 0, 0, 0, 0, 0, 0,
  0, 1106, 0, 0, 0, 732, 0, 0, 0, 0,
  0, 0, 728, 1104, 0, 0, 0, 729, 0, 0,
  0, 0, 0, 733, 0, 158, 0, 846, 734, 0,
  0, 735, 1105, 1106, 0, 0, 0, 0, 0, 0,
  0, 0, 736, 0, 0, 730, 0, 0, 737, 0,
  0, 0, 0, 847, 0, 0, 0, 0, 738, 0,
  0, 0, 0, 739, 159, 0, 740, 0, 1107, 741,
  0, 0, 0, 0, 0, 0, 0, 0, 742, 743,
  731, 0, 0, 160, 0, 0, 0, 0, 719, 720,
  0, 848, 732, 0, 268, 721, 722, 40, 0, 0,
  1107, 0, 849, 0, 0, 0, 0, 0, 0, 0,
  733, 723, 0, 0, 1106, 734, 724, 0, 735, 1194,
  744, 0, 161, 725, 745, 0, 0, 0, 0, 736,
  0, 0, 746, 0, 162, 737, 0, 0, 0, 0,
  0, 0, 0, 747, 163, 738, 0, 0, 0, 748,
  739, 726, 0, 740, 0, 0, 741, 0, 0, 0,
  0, 0, 164, 0, 0, 742, 743, 0, 0, 0,
  0, 0, 165, 0, 749, 0, 0, 0, 0, 0,
  0, 1107, 0, 0, 0, 0, 0, 0, 166, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 850, 851, 852, 0, 0, 744, 0, 0,
  0, 745, 0, 0, 0, 853, 0, 0, 750, 746,
  0, 0, 0, 0, 0, 751, 0, 752, 167, 0,
  747, 0, 2141, 0, 0, 0, 748, 753, 754, 755,
  0, 0, 81, 0, 727, 0, 756, 0, 0, 0,
  0, 0, 168, 0, 0, 0, 0, 271, 0, 0,
  0, 749, 0, 0, 0, 0, 0, 169, 0, 0,
  0, 0, 719, 720, 170, 0, 0, 171, 268, 721,
  722, 40, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 723, 0, 0, 172, 0,
  724, 173, 0, 174, 0, 750, 0, 725, 0, 0,
  0, 0, 751, 0, 752, 0, 0, 0, 0, 854,
  0, 0, 175, 0, 753, 754, 755, 0, 0, 0,
  0, 0, 0, 756, 0, 726, 0, 0, 0, 0,
  176, 728, 0, 0, 271, 0, 729, 0, 1872, 1873,
  0, 1874, 0, 0, 268, 1875, 1876, 40, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 730, 0, 1877, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1872, 1873,
  0, 1874, 0, 0, 268, 1875, 1876, 40, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 731,
  0, 0, 0, 0, 0, 0, 1877, 0, 0, 0,
  0, 732, 0, 0, 0, 0, 81, 0, 727, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 733,
  0, 0, 0, 0, 734, 0, 0, 735, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 736, 0,
  0, 0, 0, 0, 737, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 738, 0, 0, 0, 0, 739,
  0, 0, 740, 0, 0, 741, 0, 0, 0, 0,
  0, 0, 0, 0, 742, 743, 0, 0, 0, 0,
  0, 0, 695, 2914, 2915, 0, 2916, 0, 0, 268,
  1875, 1876, 40, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 728, 0, 0, 0, 0,
  729, 2917, 0, 0, 0, 2533, 744, 0, 0, 0,
  745, 0, 695, 0, 0, 0, 0, 0, 746, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 730, 747,
  0, 1872, 1873, 0, 1874, 748, 0, 268, 1875, 1876,
  40, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1877,
  749, 0, 0, 731, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 732, 2032, 2914, 2915, 0,
  2916, 0, 0, 268, 1875, 1876, 40, 0, 0, 0,
  0, 0, 0, 733, 0, 0, 0, 0, 734, 0,
  0, 735, 0, 0, 750, 2917, 0, 0, 0, 0,
  0, 751, 736, 752, 0, 0, 2032, 0, 737, 0,
  0, 0, 0, 753, 754, 755, 0, 695, 738, 0,
  0, 0, 756, 739, 0, 0, 740, 0, 0, 741,
  0, 0, 0, 271, 0, 0, 0, 0, 742, 743,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 2914, 2915, 1878, 2916, 0,
  0, 268, 1875, 1876, 40, 695, 0, 0, 0, 0,
  744, 0, 1879, 0, 745, 0, 0, 0, 0, 0,
  0, 0, 746, 2917, 0, 0, 0, 0, 0, 1880,
  0, 0, 2033, 747, 0, 0, 0, 1878, 0, 748,
  0, 0, 0, 0, 2034, 1882, 0, 0, 0, 0,
  0, 695, 1879, 1872, 1873, 0, 1874, 0, 0, 268,
  1875, 1876, 40, 0, 749, 0, 0, 0, 0, 1880,
  0, 0, 2033, 0, 0, 0, 0, 0, 0, 0,
  0, 1877, 0, 0, 2034, 1882, 1884, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1885, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 750, 0,
  0, 0, 0, 0, 0, 751, 0, 752, 0, 0,
  0, 0, 0, 0, 0, 0, 1884, 753, 754, 755,
  0, 0, 0, 0, 0, 0, 756, 0, 1885, 0,
  1886, 0, 0, 0, 0, 0, 0, 271, 0, 695,
  0, 0, 1878, 0, 0, 2914, 2915, 0, 2916, 0,
  0, 268, 1875, 1876, 40, 0, 0, 1879, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1887,
  1886, 0, 0, 2917, 2918, 0, 0, 2947, 0, 0,
  0, 1888, 0, 0, 0, 0, 0, 0, 0, 0,
  2920, 0, 0, 1889, 1890, 2035, 0, 695, 0, 0,
  1878, 0, 1891, 0, 0, 1892, 0, 0, 0, 1887,
  0, 0, 0, 271, 0, 1879, 1872, 1873, 2205, 1874,
  0, 1888, 268, 1875, 1876, 40, 0, 0, 0, 0,
  2921, 2922, 1880, 1889, 1890, 1881, 0, 0, 0, 0,
  0, 0, 1891, 2923, 1877, 1892, 1878, 0, 1882, 0,
  0, 0, 0, 271, 0, 0, 0, 0, 0, 0,
  0, 1879, 0, 0, 0, 2914, 2915, 0, 2916, 0,
  0, 268, 1875, 1876, 40, 0, 2205, 0, 2918, 0,
  0, 2919, 0, 0, 0, 2924, 0, 0, 0, 1884,
  0, 0, 0, 2917, 2920, 0, 0, 0, 0, 695,
  0, 1885, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 2916, 0, 0,
  268, 1875, 1876, 40, 2925, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 2921, 2922, 2926, 0, 0, 0,
  0, 0, 2917, 1886, 1878, 0, 0, 2923, 2927, 2928,
  0, 0, 0, 0, 0, 0, 0, 2929, 0, 1879,
  2930, 0, 0, 0, 0, 0, 0, 0, 271, 0,
  695, 0, 0, 0, 0, 0, 2918, 0, 0, 2947,
  0, 0, 1887, 0, 0, 0, 0, 0, 0, 2924,
  0, 0, 2920, 0, 1888, 0, 0, 0, 0, 0,
  0, 0, 1878, 0, 0, 0, 1889, 1890, 0, 0,
  0, 0, 0, 0, 0, 1891, 0, 1879, 1892, 695,
  0, 0, 0, 0, 0, 0, 271, 1934, 2925, 0,
  0, 0, 2921, 2922, 1880, 0, 0, 1881, 0, 0,
  2926, 0, 0, 0, 0, 2923, 0, 0, 0, 0,
  1882, 0, 2927, 2928, 0, 0, 0, 0, 0, 0,
  0, 2929, 0, 0, 2930, 0, 0, 0, 695, 0,
  0, 0, 271, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 2924, 0, 0,
  3031, 1884, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1885, 1878, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1879,
  0, 0, 0, 0, 0, 0, 2925, 0, 0, 0,
  0, 0, 2996, 0, 0, 0, 2918, 0, 2926, 2947,
  0, 0, 0, 0, 0, 1886, 0, 0, 0, 0,
  2927, 2928, 2920, 0, 0, 0, 0, 0, 0, 2929,
  0, 0, 2930, 0, 0, 0, 0, 0, 0, 0,
  271, 0, 0, 0, 0, 1878, 0, 0, 0, 0,
  2205, 0, 0, 0, 1887, 0, 0, 0, 2997, 0,
  1879, 0, 0, 2922, 0, 158, 1888, 0, 0, 0,
  0, 0, 0, 0, 0, 2923, 0, 1880, 1889, 1890,
  1881, 0, 0, 2998, 0, 0, 0, 1891, 0, 0,
  1892, 0, 2999, 1882, 1878, 0, 0, 0, 271, 0,
  0, 0, 0, 0, 159, 0, 0, 0, 0, 1879,
  0, 0, 0, 0, 0, 0, 0, 2924, 0, 0,
  0, 0, 0, 160, 0, 0, 2918, 0, 3000, 2947,
  0, 1935, 0, 0, 1884, 0, 3001, 0, 0, 0,
  0, 0, 2920, 1878, 1936, 0, 1885, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 2925, 0, 1879, 0,
  0, 0, 161, 0, 0, 0, 0, 0, 2926, 0,
  0, 0, 0, 0, 162, 2918, 0, 0, 2947, 0,
  2927, 2928, 0, 2922, 163, 0, 0, 0, 1886, 2929,
  0, 2920, 2930, 0, 0, 2923, 0, 0, 0, 0,
  271, 0, 164, 0, 0, 0, 0, 0, 1937, 0,
  0, 0, 165, 0, 0, 1938, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1887, 166, 0,
  3002, 0, 2922, 0, 0, 0, 0, 2924, 0, 1888,
  0, 0, 0, 0, 2923, 0, 0, 0, 0, 0,
  0, 1889, 1890, 0, 1939, 0, 0, 0, 0, 0,
  1891, 0, 0, 1892, 0, 0, 0, 0, 167, 0,
  0, 271, 0, 0, 0, 0, 2925, 0, 0, 1940,
  0, 0, 0, 0, 0, 0, 2924, 0, 2926, 1941,
  1942, 0, 168, 0, 0, 0, 0, 0, 0, 0,
  2927, 2928, 0, 0, 0, 1943, 0, 169, 0, 2929,
  0, 0, 2930, 0, 170, 0, 0, 171, 0, 0,
  271, 0, 0, 0, 0, 2925, 0, 1944, 0, 0,
  1945, 1946, 0, 0, 0, 0, 1947, 2926, 172, 0,
  0, 173, 0, 174, 0, 0, 0, 0, 0, 2927,
  2928, 0, 0, 0, 0, 0, 0, 0, 2929, 0,
  0, 2930, 175, 0, 0, 0, 0, 0, 0, 271,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  176, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1948, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 3003, 0, 1949
};

static const short yycheck[] = {
  2, 696, 843, 713, 187, 193, 327, 710, 983, 65,
  12, 13, 211, 515, 861, 417, 422, 81, 1492, 1553,
  997, 828, 1689, 832, 1404, 521, 990, 1982, 839, 840,
  1859, 842, 497, 844, 845, 0, 1741, 924, 175, 153,
  362, 543, 44, 45, 546, 1369, 1800, 1693, 1269, 1270,
  452, 938, 1358, 455, 1372, 1301, 479, 735, 23, 1612,
  2168, 117, 869, 465, 29, 2386, 445, 469, 5, 20,
  5, 473, 504, 75, 5, 26, 78, 26, 480, 26,
  263, 784, 26, 485, 387, 487, 5, 224, 90, 5,
  24, 493, 26, 417, 496, 97, 420, 421, 504, 101,
  65, 503, 104, 105, 1933, 23, 508, 25, 110, 111,
  434, 507, 5, 23, 516, 25, 5, 513, 24, 26,
  26, 517, 236, 237, 81, 527, 5, 32, 452, 531,
  1025, 455, 5, 535, 5, 5, 143, 461, 57, 541,
  78, 465, 544, 26, 63, 469, 955, 149, 957, 473,
  152, 339, 117, 477, 478, 157, 480, 18, 597, 483,
  539, 485, 486, 487, 25, 508, 61, 115, 5, 493,
  20, 20, 496, 26, 24, 24, 26, 26, 49, 503,
  51, 43, 53, 46, 508, 6, 24, 25, 26, 18,
  68, 69, 516, 195, 23, 24, 25, 6, 43, 94,
  26, 5, 2259, 527, 24, 695, 26, 531, 130, 5,
  1577, 535, 23, 24, 25, 2536, 32, 541, 928, 26,
  544, 23, 24, 25, 26, 23, 24, 25, 26, 26,
  6, 233, 1878, 23, 24, 25, 26, 239, 5, 23,
  24, 25, 26, 5, 24, 140, 26, 2860, 250, 144,
  23, 24, 25, 26, 5, 5, 2210, 2211, 2212, 2213,
  24, 130, 26, 24, 72, 26, 171, 5, 9, 5,
  11, 12, 13, 14, 15, 16, 1684, 1685, 26, 22,
  1688, 5, 9, 5, 11, 12, 13, 14, 15, 16,
  0, 1624, 24, 528, 26, 2595, 370, 22, 2919, 5,
  411, 5, 276, 2258, 372, 2659, 1973, 363, 364, 24,
  5, 26, 24, 26, 26, 26, 37, 38, 325, 5,
  558, 26, 23, 24, 25, 26, 28, 1663, 1802, 143,
  1666, 226, 17, 18, 2368, 1058, 850, 851, 314, 255,
  25, 26, 439, 2172, 65, 66, 67, 5, 5, 216,
  452, 171, 439, 355, 170, 171, 358, 5, 460, 1206,
  358, 599, 1258, 520, 366, 600, 2033, 372, 366, 171,
  1737, 25, 26, 171, 116, 117, 29, 411, 2991, 5,
  382, 1789, 384, 36, 279, 255, 281, 171, 41, 601,
  366, 286, 255, 30, 5, 1372, 608, 893, 363, 364,
  439, 406, 17, 229, 156, 439, 355, 171, 847, 411,
  171, 608, 569, 411, 416, 854, 418, 419, 27, 458,
  422, 423, 2032, 425, 2034, 131, 428, 45, 5, 5,
  832, 5, 471, 86, 87, 121, 410, 439, 5, 171,
  335, 94, 376, 5, 446, 17, 18, 19, 20, 21,
  103, 104, 5, 106, 107, 1165, 458, 352, 111, 171,
  171, 599, 325, 5, 255, 5, 468, 5, 83, 471,
  171, 5, 215, 5, 5, 128, 129, 330, 226, 481,
  17, 18, 19, 20, 21, 2839, 171, 5, 5, 5,
  215, 239, 233, 146, 147, 497, 498, 608, 5, 5,
  252, 5, 504, 571, 330, 602, 233, 370, 832, 3130,
  512, 325, 514, 515, 1881, 602, 5, 171, 1008, 526,
  522, 523, 1901, 525, 526, 2582, 528, 5, 530, 5,
  532, 5, 5, 5, 536, 1037, 538, 5, 540, 5,
  542, 543, 5, 545, 546, 5, 548, 495, 5, 5,
  1245, 372, 559, 955, 956, 957, 878, 5, 880, 421,
  443, 411, 1970, 372, 5, 376, 1031, 641, 372, 1034,
  1035, 1036, 26, 2894, 376, 5, 372, 1957, 376, 1011,
  391, 446, 2537, 490, 1805, 507, 376, 1995, 1053, 391,
  528, 1294, 1295, 391, 543, 5, 372, 532, 2132, 452,
  1303, 391, 521, 468, 411, 1011, 26, 26, 370, 5,
  1505, 352, 5, 956, 411, 1982, 354, 330, 343, 486,
  577, 2029, 372, 9, 571, 352, 452, 1921, 2662, 26,
  535, 955, 956, 957, 550, 1968, 372, 1133, 507, 532,
  407, 2941, 2176, 1346, 1146, 372, 535, 512, 650, 1145,
  2184, 2185, 2973, 974, 452, 528, 407, 522, 523, 538,
  594, 526, 524, 411, 365, 530, 2033, 532, 409, 600,
  2006, 536, 975, 538, 2782, 417, 678, 1191, 680, 524,
  550, 1568, 409, 407, 602, 407, 1151, 550, 594, 347,
  609, 528, 602, 695, 2802, 348, 411, 1129, 649, 2528,
  649, 2254, 3023, 407, 3025, 649, 1966, 644, 710, 457,
  571, 1134, 407, 26, 435, 372, 496, 719, 720, 535,
  452, 374, 1224, 1129, 372, 473, 411, 2784, 2785, 600,
  608, 1454, 734, 1198, 1457, 1981, 2490, 608, 740, 741,
  2494, 1419, 649, 745, 594, 594, 372, 567, 22, 2055,
  368, 2705, 1729, 755, 2078, 2460, 594, 2367, 1223, 550,
  2370, 372, 2080, 1228, 1266, 1267, 325, 468, 631, 632,
  633, 532, 226, 602, 171, 393, 434, 320, 673, 642,
  17, 18, 784, 20, 26, 239, 23, 24, 25, 26,
  1036, 602, 445, 451, 558, 372, 372, 538, 372, 2207,
  602, 5, 523, 1780, 602, 372, 320, 226, 45, 334,
  372, 538, 602, 621, 622, 623, 624, 625, 602, 372,
  239, 138, 2201, 2202, 5, 2205, 828, 829, 482, 602,
  372, 1640, 372, 2788, 372, 407, 494, 149, 372, 1218,
  372, 372, 2209, 584, 230, 566, 1242, 5, 2215, 2216,
  2217, 2218, 2219, 2220, 372, 372, 372, 584, 171, 477,
  2801, 863, 312, 2271, 605, 372, 372, 869, 372, 340,
  407, 487, 986, 340, 320, 989, 534, 520, 605, 881,
  496, 439, 536, 372, 886, 1381, 539, 27, 28, 891,
  520, 2258, 305, 2539, 372, 341, 372, 2191, 372, 372,
  372, 602, 322, 223, 372, 563, 372, 909, 602, 372,
  330, 331, 372, 188, 572, 372, 372, 25, 26, 411,
  5, 2851, 924, 2853, 372, 541, 569, 1630, 544, 171,
  2151, 372, 336, 334, 171, 355, 938, 305, 358, 569,
  5, 215, 372, 1007, 316, 439, 24, 439, 26, 2778,
  131, 607, 570, 25, 26, 327, 376, 411, 438, 439,
  277, 419, 372, 828, 582, 583, 1149, 620, 365, 2377,
  13, 2379, 430, 591, 630, 628, 372, 1223, 455, 372,
  503, 367, 138, 369, 1825, 2519, 457, 229, 411, 991,
  457, 0, 469, 995, 996, 997, 473, 93, 863, 1395,
  2260, 2261, 1504, 457, 869, 2372, 1008, 379, 485, 1011,
  439, 1013, 1014, 571, 23, 1017, 881, 560, 577, 473,
  411, 886, 394, 17, 18, 19, 20, 21, 2389, 1031,
  1032, 2392, 1034, 1035, 1036, 1037, 353, 1039, 457, 419,
  1042, 2888, 2889, 2410, 602, 495, 560, 438, 517, 462,
  430, 1053, 365, 1055, 473, 1551, 506, 1059, 1454, 411,
  264, 1457, 482, 171, 1911, 1067, 2030, 1069, 1070, 343,
  1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081,
  1082, 1083, 1084, 1085, 1086, 1087, 1088, 3041, 411, 3043,
  3044, 3045, 3046, 171, 462, 1497, 567, 1099, 1100, 171,
  567, 2760, 1104, 2080, 1106, 380, 264, 419, 3049, 1611,
  411, 515, 484, 2077, 560, 2761, 536, 2763, 430, 1121,
  1616, 277, 20, 543, 2783, 529, 411, 1129, 26, 406,
  1595, 1596, 263, 1135, 1136, 1137, 2795, 144, 2919, 376,
  452, 148, 3072, 25, 1146, 276, 1148, 459, 1150, 1151,
  554, 20, 411, 1155, 391, 1292, 473, 26, 411, 263,
  527, 1298, 411, 1972, 531, 172, 2947, 3014, 535, 3016,
  2537, 408, 276, 1497, 411, 2583, 24, 25, 2545, 438,
  439, 2548, 2549, 2550, 2551, 1994, 2796, 424, 848, 849,
  1192, 2801, 852, 853, 607, 2603, 1198, 353, 1893, 603,
  2069, 24, 2071, 2072, 2091, 2585, 24, 439, 26, 42,
  462, 219, 411, 626, 627, 1217, 411, 1619, 1540, 1221,
  1334, 1223, 1224, 607, 1720, 411, 1228, 464, 465, 1343,
  1232, 1233, 1234, 646, 24, 20, 26, 25, 1640, 607,
  477, 26, 1244, 502, 251, 629, 630, 254, 24, 411,
  26, 2910, 1955, 608, 542, 411, 1258, 545, 626, 627,
  548, 3042, 411, 1265, 1266, 1267, 1731, 3048, 276, 276,
  1135, 1136, 1137, 219, 20, 411, 608, 2944, 646, 410,
  26, 114, 519, 25, 24, 1781, 26, 1783, 25, 1291,
  1155, 25, 1294, 1295, 1997, 1619, 1792, 1299, 2665, 1301,
  25, 1303, 438, 439, 2914, 2915, 410, 251, 25, 2919,
  254, 24, 256, 26, 2981, 144, 1640, 473, 602, 148,
  328, 558, 439, 251, 332, 25, 254, 1192, 256, 24,
  276, 26, 276, 570, 1730, 3116, 25, 2947, 3119, 3120,
  3121, 3122, 286, 172, 1346, 582, 583, 180, 276, 182,
  622, 623, 1217, 171, 591, 607, 1358, 594, 286, 25,
  24, 305, 26, 25, 197, 602, 502, 1369, 3149, 1234,
  1372, 24, 205, 26, 626, 627, 209, 305, 372, 1244,
  602, 171, 328, 2791, 328, 25, 332, 607, 332, 1391,
  1392, 1393, 25, 2200, 646, 171, 24, 39, 26, 2766,
  328, 234, 410, 410, 332, 411, 2253, 2881, 372, 629,
  630, 103, 104, 342, 106, 107, 25, 20, 26, 111,
  602, 2788, 251, 26, 411, 254, 1428, 1429, 1430, 2406,
  1432, 171, 3042, 24, 2398, 26, 128, 129, 3048, 3049,
  3050, 3051, 3052, 3053, 1339, 144, 419, 276, 621, 148,
  411, 624, 625, 2861, 146, 147, 1458, 430, 171, 1461,
  18, 276, 285, 5, 410, 23, 410, 25, 291, 292,
  293, 438, 439, 1475, 44, 1871, 171, 85, 18, 452,
  407, 3015, 410, 23, 24, 25, 459, 20, 311, 2856,
  20, 1493, 24, 26, 26, 372, 26, 1499, 1904, 1501,
  1502, 1503, 1504, 24, 602, 26, 3116, 171, 20, 3119,
  3120, 3121, 3122, 328, 26, 2914, 2915, 332, 462, 2993,
  3130, 25, 2019, 2907, 24, 217, 26, 135, 2025, 2913,
  268, 269, 1534, 1721, 462, 624, 625, 1539, 3012, 3149,
  89, 90, 91, 171, 24, 2912, 26, 1549, 1747, 239,
  195, 1553, 251, 407, 199, 254, 372, 24, 1560, 26,
  631, 632, 140, 171, 1966, 173, 1568, 23, 342, 25,
  1972, 25, 1574, 1575, 23, 1577, 25, 276, 20, 157,
  158, 410, 103, 104, 25, 106, 107, 165, 2084, 23,
  111, 25, 1994, 1595, 1596, 410, 419, 631, 632, 422,
  595, 596, 597, 598, 2971, 1872, 1873, 128, 129, 1611,
  1475, 3085, 13, 14, 15, 16, 17, 18, 19, 20,
  21, 199, 1130, 446, 1132, 146, 147, 25, 1630, 25,
  208, 25, 3040, 20, 1499, 25, 411, 25, 1503, 2135,
  25, 2616, 1966, 466, 347, 602, 372, 1649, 1972, 5,
  171, 3050, 3051, 3052, 3053, 606, 372, 372, 283, 237,
  1662, 1663, 270, 2510, 1666, 372, 372, 2508, 3076, 1534,
  1994, 372, 73, 74, 75, 76, 77, 78, 501, 372,
  1682, 5, 1684, 1685, 372, 283, 1688, 1689, 89, 90,
  91, 372, 372, 421, 606, 1560, 217, 372, 521, 522,
  372, 411, 646, 602, 282, 599, 434, 3074, 2411, 532,
  280, 410, 439, 1715, 537, 602, 1718, 8, 646, 460,
  1722, 17, 18, 19, 20, 21, 418, 1729, 407, 1731,
  338, 434, 401, 461, 411, 1737, 507, 411, 346, 247,
  411, 411, 350, 411, 3111, 114, 324, 600, 451, 477,
  478, 411, 411, 576, 411, 483, 411, 411, 486, 411,
  411, 2657, 411, 411, 2660, 411, 5, 1769, 338, 600,
  1772, 577, 2096, 411, 2239, 411, 2241, 411, 1780, 387,
  350, 411, 1784, 1785, 1786, 1787, 609, 1789, 411, 411,
  360, 494, 411, 1795, 1796, 411, 411, 1799, 1800, 444,
  445, 440, 401, 440, 641, 2515, 1808, 411, 378, 641,
  307, 180, 347, 182, 251, 8, 1818, 254, 388, 256,
  578, 391, 5, 5, 411, 347, 364, 411, 197, 230,
  411, 534, 233, 325, 404, 411, 205, 54, 55, 276,
  209, 58, 59, 60, 411, 8, 560, 455, 571, 286,
  5, 220, 13, 557, 641, 5, 401, 1722, 2260, 2261,
  563, 641, 46, 1865, 411, 234, 25, 411, 25, 572,
  1872, 1873, 72, 439, 439, 5, 25, 2724, 602, 1881,
  577, 452, 411, 453, 571, 2732, 494, 411, 347, 60,
  1892, 328, 411, 20, 539, 332, 608, 418, 20, 434,
  2796, 347, 1904, 608, 549, 2801, 411, 2403, 411, 411,
  1912, 519, 434, 483, 608, 411, 451, 331, 538, 1784,
  1785, 1786, 1787, 493, 644, 607, 2305, 2306, 2307, 451,
  2309, 2310, 2311, 2312, 2313, 2314, 2260, 2261, 17, 2318,
  18, 158, 5, 1808, 514, 25, 133, 517, 165, 519,
  25, 352, 199, 1955, 24, 563, 463, 571, 605, 494,
  560, 132, 133, 2019, 572, 463, 367, 602, 1970, 2025,
  371, 1973, 494, 410, 5, 434, 528, 547, 1980, 1981,
  1982, 2477, 199, 1985, 131, 1987, 556, 528, 434, 5,
  114, 208, 451, 1995, 2697, 1997, 2498, 25, 380, 534,
  1865, 302, 528, 2505, 2006, 451, 25, 411, 409, 411,
  372, 2199, 534, 602, 411, 646, 187, 439, 2914, 2915,
  237, 238, 193, 2919, 558, 462, 372, 2029, 563, 528,
  411, 2033, 2879, 2035, 411, 494, 437, 572, 372, 372,
  372, 563, 19, 20, 2046, 372, 25, 372, 494, 372,
  572, 2947, 372, 2055, 2019, 456, 180, 372, 182, 411,
  2025, 5, 599, 5, 5, 282, 561, 5, 713, 608,
  372, 2967, 79, 197, 602, 534, 2078, 608, 2080, 5,
  464, 205, 411, 411, 607, 209, 2088, 535, 534, 2091,
  25, 25, 263, 411, 265, 46, 73, 74, 75, 76,
  77, 78, 517, 306, 563, 5, 5, 324, 372, 341,
  234, 411, 411, 572, 759, 578, 13, 563, 608, 401,
  1985, 401, 1987, 5, 642, 532, 572, 5, 528, 2131,
  2132, 25, 81, 411, 2943, 608, 602, 538, 411, 2141,
  347, 5, 2144, 607, 621, 407, 3042, 2149, 2851, 2075,
  2853, 407, 3048, 3049, 3050, 3051, 3052, 3053, 441, 411,
  2162, 411, 2164, 380, 2166, 441, 411, 411, 339, 411,
  411, 2173, 8, 29, 2176, 411, 2886, 5, 2180, 25,
  3027, 25, 2184, 2185, 372, 2996, 2997, 2998, 2999, 3000,
  3001, 571, 372, 24, 347, 24, 372, 24, 2200, 24,
  56, 5, 372, 602, 605, 2207, 5, 2209, 8, 646,
  20, 965, 306, 2215, 2216, 2217, 2218, 2219, 2220, 602,
  3116, 24, 325, 3119, 3120, 3121, 3122, 434, 602, 325,
  2726, 439, 602, 325, 3130, 341, 2931, 2239, 411, 2241,
  406, 439, 411, 411, 451, 25, 411, 103, 104, 411,
  106, 107, 5, 3149, 633, 111, 2258, 411, 2723, 430,
  20, 21, 5, 73, 74, 75, 76, 77, 78, 2271,
  411, 411, 128, 129, 25, 2277, 2141, 5, 5, 2144,
  5, 434, 577, 928, 2286, 2287, 2288, 494, 19, 20,
  146, 147, 2294, 464, 2615, 599, 577, 411, 451, 470,
  565, 472, 5, 5, 602, 476, 313, 5, 479, 2492,
  602, 482, 411, 73, 74, 75, 76, 77, 78, 326,
  7, 492, 372, 5, 608, 602, 25, 534, 25, 89,
  90, 91, 25, 602, 8, 2200, 372, 608, 29, 372,
  511, 494, 73, 74, 75, 76, 77, 78, 519, 520,
  521, 571, 25, 2355, 525, 2357, 563, 608, 372, 372,
  372, 217, 533, 372, 2366, 572, 2368, 372, 20, 3072,
  2372, 5, 255, 548, 2870, 2377, 2378, 2379, 549, 372,
  5, 534, 5, 390, 4, 5, 6, 7, 8, 9,
  397, 11, 528, 610, 611, 612, 613, 614, 615, 616,
  617, 618, 619, 5, 2406, 221, 5, 372, 2410, 2411,
  563, 553, 103, 104, 608, 106, 107, 1748, 372, 572,
  111, 1752, 421, 602, 602, 372, 1757, 411, 452, 436,
  1761, 6, 1763, 1764, 1765, 5, 608, 128, 129, 191,
  2366, 608, 2368, 73, 74, 75, 76, 77, 78, 535,
  606, 24, 24, 24, 461, 146, 147, 601, 606, 427,
  24, 719, 720, 3173, 471, 472, 2468, 24, 411, 25,
  230, 25, 25, 233, 25, 25, 734, 452, 411, 25,
  487, 337, 740, 741, 277, 25, 5, 745, 2490, 507,
  249, 2493, 2494, 372, 571, 372, 2498, 755, 5, 2501,
  411, 449, 509, 2505, 372, 512, 513, 532, 221, 24,
  372, 518, 407, 5, 372, 421, 325, 2519, 20, 120,
  1165, 5, 13, 13, 535, 191, 602, 5, 2530, 422,
  386, 439, 372, 372, 372, 2537, 25, 25, 372, 5,
  601, 2943, 713, 2545, 349, 312, 2548, 2549, 2550, 2551,
  2552, 411, 372, 354, 550, 25, 411, 2559, 372, 19,
  20, 21, 418, 325, 17, 18, 19, 20, 575, 222,
  372, 1325, 1326, 1218, 2576, 372, 372, 372, 1332, 608,
  587, 2583, 372, 17, 18, 19, 20, 372, 372, 372,
  2592, 557, 352, 2595, 411, 7, 528, 25, 220, 220,
  608, 2603, 372, 2605, 428, 25, 372, 367, 373, 372,
  781, 371, 602, 73, 74, 75, 76, 77, 78, 2943,
  73, 74, 75, 76, 77, 78, 608, 608, 1273, 89,
  90, 91, 411, 411, 411, 411, 2501, 411, 29, 73,
  74, 75, 76, 77, 78, 5, 13, 411, 5, 409,
  411, 407, 5, 824, 411, 2657, 372, 222, 2660, 24,
  2662, 372, 602, 2665, 411, 2530, 5, 838, 839, 840,
  2179, 842, 372, 844, 845, 3095, 372, 437, 372, 850,
  851, 2088, 372, 372, 372, 1855, 372, 372, 2131, 1235,
  1561, 36, 38, 363, 2559, 2697, 456, 1796, 2162, 2701,
  1802, 2703, 286, 140, 144, 208, 280, 287, 352, 1338,
  210, 395, 103, 104, 1755, 106, 107, 2463, 1339, 370,
  111, 2723, 893, 315, 314, 382, 2728, 3085, 384, 1534,
  1772, 2657, 962, 904, 2660, 1660, 2662, 128, 129, 525,
  1786, 1667, 1409, 1503, 2234, 1265, 1591, 2562, 1908, 3109,
  1790, 1268, 2248, 2250, 1606, 146, 147, 928, 929, 1151,
  2740, 23, 117, 29, 2766, 2637, 937, 1566, 29, 1572,
  230, 652, 482, 233, 1032, 680, 1906, 1575, 538, 265,
  1273, 1039, 953, 954, 1042, 2816, 2788, 2634, 1142, 2791,
  1544, 929, 1622, 3012, 2796, 2216, 1189, 1055, 2800, 2801,
  2345, 1059, 1132, 2826, 1217, 2327, 2808, 881, 1063, 1067,
  2343, 1069, 1070, 2028, 1072, 1073, 1074, 1075, 1076, 1077,
  1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087,
  1088, 20, 1017, 1587, 23, 24, 25, 26, 1780, 1375,
  1966, 1099, 1100, 1352, 3076, 605, 1104, 3111, 1106, 2851,
  1998, 2853, 2950, 2029, 2856, 2376, 45, 2697, 2412, 2861,
  1688, 2863, 2355, 2728, 2035, 2660, 2357, 2967, 1291, 2046,
  2796, 2671, 2288, 958, 2862, 2801, 2863, 2593, 2272, 3074,
  2410, 2215, 1287, 2904, 2592, 2831, 954, 3040, 1260, 2800,
  3048, 1718, 352, 1147, 361, -1, -1, -1, -1, -1,
  -1, -1, 2904, -1, -1, 2831, -1, 367, -1, -1,
  2912, 371, 2914, 2915, -1, -1, -1, 2919, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 2930, -1,
  -1, -1, 1577, -1, -1, -1, -1, -1, -1, 2941,
  -1, -1, 2944, -1, -1, 2947, 337, -1, 2950, 409,
  -1, 1122, -1, -1, -1, -1, -1, -1, -1, 1130,
  -1, 1132, 1133, 1134, -1, 2967, -1, -1, -1, 2971,
  1141, 1142, -1, -1, 1145, -1, -1, 437, 1149, 2981,
  -1, 1152, 171, -1, -1, -1, -1, -1, 2914, 2915,
  -1, -1, -1, 2919, 1165, 386, 456, -1, -1, -1,
  -1, -1, -1, -1, -1, 3007, 3008, -1, -1, -1,
  -1, -1, -1, 3015, -1, -1, -1, -1, -1, -1,
  1191, 2947, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 1682, 3040, -1,
  3042, 2967, -1, -1, 1689, -1, 3048, 3049, 3050, 3051,
  3052, 3053, -1, -1, -1, -1, -1, -1, -1, 1230,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  3072, -1, 3074, -1, 3076, -1, -1, -1, 538, -1,
  -1, -1, -1, 1254, -1, -1, -1, -1, 1259, -1,
  -1, -1, 1737, -1, -1, 1849, 1850, -1, -1, -1,
  -1, 1272, 1273, -1, -1, -1, 1860, -1, -1, 3111,
  -1, -1, -1, -1, 3116, -1, 3042, 3119, 3120, 3121,
  3122, 3123, 3048, 3049, 3050, 3051, 3052, 3053, 3130, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  3142, -1, 3007, -1, -1, 605, -1, 3149, -1, -1,
  -1, -1, -1, -1, -1, -1, 1327, -1, -1, -1,
  -1, -1, -1, 1917, 1918, 1919, 1920, -1, -1, -1,
  1428, 1429, 1430, -1, 1432, -1, -1, -1, 1932, -1,
  -1, -1, -1, -1, -1, -1, -1, 376, -1, -1,
  3116, -1, -1, 3119, 3120, 3121, 3122, -1, -1, -1,
  1458, -1, 391, -1, 3130, -1, -1, -1, -1, -1,
  1381, -1, -1, -1, -1, -1, -1, -1, -1, 408,
  -1, -1, 411, 3149, -1, -1, -1, 1872, 1873, -1,
  -1, -1, -1, -1, -1, 424, 1881, 11, 12, 13,
  14, 15, 16, 17, 18, 19, 20, 21, -1, -1,
  -1, -1, -1, 2007, 2008, -1, -1, -1, -1, -1,
  2014, 2015, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 465, 3142, -1, -1,
  -1, 1539, 16, 17, 18, 19, 20, 21, 477, -1,
  -1, -1, -1, -1, -1, 1553, -1, -1, -1, 73,
  74, 75, 76, 77, 78, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 89, 90, 91, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 1973, -1,
  519, -1, -1, -1, -1, -1, -1, 1982, -1, 73,
  74, 75, 76, 77, 78, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 89, 90, 91, -1, -1,
  -1, 1532, 15, 16, 17, 18, 19, 20, 21, 558,
  1541, -1, -1, 31, -1, -1, -1, -1, -1, -1,
  1551, 570, -1, -1, -1, -1, -1, -1, 2033, -1,
  2035, -1, -1, 582, 583, -1, -1, -1, 2152, 2153,
  -1, 1572, 591, 61, 62, 594, -1, 2161, -1, -1,
  -1, -1, 70, 602, -1, 2169, -1, -1, -1, -1,
  73, 74, 75, 76, 77, 78, -1, -1, -1, -1,
  2075, -1, -1, -1, 2188, 2189, 89, 90, 91, -1,
  -1, -1, -1, -1, -1, 1616, 1617, 1618, -1, -1,
  -1, 1622, -1, -1, -1, -1, 230, -1, -1, 233,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 1654, -1, -1, 2240, -1, 2242, -1,
  -1, -1, -1, -1, -1, 2249, 230, 2251, -1, 233,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, 1769, -1, -1, 1772, -1, -1, 5, 6, 7,
  8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
  18, 19, 20, 21, -1, -1, -1, -1, -1, -1,
  -1, 2295, 2296, -1, -1, 2299, 2300, -1, -1, 1720,
  1721, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 2209, -1, -1, -1, -1, -1,
  2215, 2216, 2217, 2218, 2219, 2220, -1, 230, 352, 2333,
  233, -1, -1, 241, -1, 73, 74, 75, 76, 77,
  78, -1, -1, 367, -1, -1, -1, 371, -1, -1,
  -1, 89, 90, 91, -1, -1, -1, -1, -1, -1,
  1781, -1, 1783, 2258, -1, -1, -1, -1, 352, -1,
  -1, 1792, 280, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 367, -1, 409, -1, 371, -1, -1,
  -1, 299, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 22, -1, 315, -1, 1830,
  2305, 2306, 2307, 437, 2309, 2310, 2311, 2312, 2313, 2314,
  -1, -1, -1, 2318, -1, 409, 43, -1, -1, -1,
  338, -1, 456, -1, -1, -1, -1, -1, 1859, -1,
  -1, -1, 350, -1, -1, -1, -1, -1, -1, 352,
  -1, -1, 360, 437, -1, 72, -1, -1, -1, -1,
  2355, -1, 2357, -1, 367, -1, -1, -1, 371, -1,
  378, 2366, 456, 2368, -1, -1, -1, 2372, -1, -1,
  388, -1, -1, -1, 1905, 1906, -1, 2491, -1, -1,
  -1, 2495, 230, -1, -1, 233, 404, 114, -1, -1,
  -1, -1, -1, -1, -1, -1, 409, -1, -1, -1,
  -1, -1, -1, -1, 538, 2410, -1, -1, -1, -1,
  -1, -1, 2526, -1, -1, -1, -1, 144, -1, -1,
  -1, 148, -1, -1, 437, -1, 444, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 456, 538, 172, 2560, -1, -1, -1,
  468, -1, -1, 180, -1, 182, -1, -1, -1, -1,
  -1, -1, -1, -1, 191, 483, -1, -1, -1, -1,
  197, 605, 490, -1, 2005, 493, -1, -1, 205, -1,
  -1, -1, 209, -1, -1, -1, -1, -1, 215, -1,
  -1, -1, 219, 220, 221, 222, 514, -1, -1, 517,
  -1, 519, -1, -1, 352, -1, -1, 234, -1, -1,
  2515, 605, -1, 2131, 2132, -1, -1, -1, -1, 367,
  538, -1, -1, 371, 251, 538, -1, 254, -1, 256,
  -1, -1, 2537, -1, -1, -1, 263, -1, 556, -1,
  2545, -1, -1, 2548, 2549, 2550, 2551, -1, -1, 276,
  -1, -1, -1, 2084, -1, 2173, -1, -1, 2176, 286,
  -1, 409, -1, -1, -1, -1, 2184, 2185, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 305, 306,
  -1, 599, -1, -1, -1, -1, -1, -1, -1, 437,
  -1, -1, 605, 320, -1, -1, -1, -1, -1, -1,
  -1, 328, -1, -1, 2135, 332, -1, -1, 456, -1,
  -1, -1, -1, -1, 341, 342, 343, -1, -1, 17,
  18, 19, 20, 21, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 2168, -1, -1,
  -1, -1, -1, 2757, -1, -1, 2177, -1, 2179, -1,
  2181, -1, 2657, -1, -1, 2660, -1, 2662, -1, -1,
  2665, -1, -1, 2194, -1, -1, -1, -1, 2199, -1,
  -1, -1, -1, -1, -1, 73, 74, 75, 76, 77,
  78, -1, 26, 410, -1, -1, -1, -1, -1, -1,
  538, 89, 90, 91, 421, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 462, 6, 7, 8, 9,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, -1, -1, -1, -1, -1, 605, 2289, -1,
  -1, 2766, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 2890, -1, -1, -1,
  -1, -1, -1, 2788, -1, -1, -1, -1, -1, -1,
  -1, 2796, -1, -1, -1, -1, 2801, 524, 2329, -1,
  -1, -1, -1, 73, 74, 75, 76, 77, 78, -1,
  -1, 2342, -1, -1, -1, -1, -1, -1, -1, 89,
  90, 91, -1, -1, -1, -1, 2831, -1, -1, -1,
  -1, -1, 230, 560, -1, 233, -1, -1, -1, -1,
  -1, 2955, 2956, -1, 2958, -1, 2960, 2961, -1, -1,
  2468, 2856, 5, 6, 7, 8, 9, 10, 11, 12,
  13, 14, 15, 16, 17, 18, 19, 20, 21, -1,
  -1, -1, 2403, -1, -1, -1, -1, -1, -1, -1,
  607, 2886, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 621, 622, 623, 624, 625, 626,
  627, 2519, 629, 630, -1, -1, -1, 2912, -1, 2914,
  2915, -1, 3026, -1, 2919, -1, -1, 261, -1, 646,
  73, 74, 75, 76, 77, 78, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 89, 90, 91, 2944,
  -1, -1, 2947, -1, -1, -1, 2477, -1, -1, 3063,
  -1, 3065, -1, -1, 352, -1, -1, 301, 302, 303,
  230, 2492, 2967, 233, -1, -1, 2971, -1, -1, 367,
  -1, -1, -1, 371, -1, -1, 2981, -1, -1, -1,
  -1, -1, 326, -1, 2515, -1, 3100, -1, -1, -1,
  334, -1, -1, -1, -1, 339, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  354, 409, -1, -1, -1, 359, -1, 361, -1, -1,
  -1, -1, 3136, 3137, 368, -1, 3140, 371, -1, -1,
  374, -1, -1, 377, -1, -1, 380, 3042, -1, 437,
  -1, 385, -1, 3048, 3049, 3050, 3051, 3052, 3053, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 456, 403,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 3074,
  -1, -1, -1, -1, -1, 419, -1, 230, 422, 423,
  233, -1, 352, -1, -1, 429, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 440, 367, -1, -1,
  -1, 371, 372, 2634, -1, -1, 3111, -1, -1, -1,
  -1, 3116, 456, -1, 3119, 3120, 3121, 3122, -1, 463,
  -1, -1, -1, -1, -1, 3130, 470, -1, -1, 473,
  474, 475, -1, 477, 478, -1, -1, -1, -1, 409,
  538, -1, -1, -1, 3149, -1, -1, -1, -1, -1,
  494, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 437, 3173, -1,
  -1, -1, -1, -1, 518, 519, 520, 521, -1, 523,
  21, -1, -1, -1, -1, -1, 456, -1, -1, -1,
  -1, -1, -1, -1, -1, 2726, 540, 541, -1, 352,
  -1, -1, -1, -1, -1, -1, -1, 605, -1, -1,
  -1, -1, -1, -1, 367, -1, -1, -1, 371, 563,
  -1, -1, -1, -1, -1, -1, -1, -1, 572, 573,
  -1, 575, 73, 74, 75, 76, 77, 78, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 89, 90,
  91, 2782, -1, -1, -1, -1, 409, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 538, -1,
  -1, 2802, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 437, 2816, -1, -1, -1, -1,
  2821, -1, 2823, 637, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 456, -1, -1, -1, -1, -1, -1,
  6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
  16, 17, 18, 19, 20, 21, -1, -1, -1, -1,
  -1, 2862, -1, -1, -1, 605, -1, -1, -1, 2870,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 2886, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 73, 74, 75,
  76, 77, 78, -1, -1, 538, -1, -1, -1, 230,
  -1, -1, 233, 89, 90, 91, -1, 3015, -1, -1,
  -1, -1, 29, -1, -1, -1, 33, -1, 35, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  47, 48, -1, 50, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 64, -1, -1,
  -1, -1, -1, -1, 71, -1, -1, -1, -1, -1,
  -1, -1, 605, -1, -1, 82, 83, 84, -1, -1,
  -1, -1, -1, -1, -1, 2996, 2997, 2998, 2999, 3000,
  3001, 98, -1, 100, 101, 102, 103, 104, 105, 106,
  107, 108, -1, 110, 111, 112, 113, -1, -1, -1,
  -1, -1, 119, -1, -1, 122, -1, 124, 125, 126,
  -1, 128, 129, -1, -1, -1, -1, 134, -1, 136,
  137, 352, 139, -1, 141, 142, -1, -1, 145, 146,
  147, -1, -1, 150, 151, 152, 367, 154, 155, -1,
  371, -1, 159, 160, 230, 162, -1, 233, -1, 166,
  -1, 168, 169, -1, -1, -1, -1, 174, -1, -1,
  -1, 178, -1, -1, 181, -1, 183, -1, 185, -1,
  187, -1, 189, 190, -1, 192, 193, 194, 409, -1,
  -1, 198, -1, 200, 201, -1, 203, -1, -1, -1,
  -1, -1, -1, -1, 211, 212, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 437, 224, -1, -1,
  227, 228, -1, -1, 231, 232, -1, -1, 235, 236,
  -1, -1, -1, -1, -1, 456, -1, 244, 245, 246,
  -1, 248, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, 258, 259, 260, -1, 262, -1, -1, -1, 266,
  267, -1, 3173, -1, 271, -1, -1, -1, -1, -1,
  -1, -1, 279, -1, -1, -1, 352, -1, -1, -1,
  287, 288, 289, -1, -1, -1, -1, -1, 295, 296,
  -1, 367, -1, -1, 301, 371, 372, 304, -1, -1,
  -1, 308, 309, -1, -1, -1, -1, -1, 99, -1,
  -1, -1, 319, -1, -1, -1, -1, 538, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  337, -1, -1, 409, -1, -1, -1, -1, 345, -1,
  -1, -1, -1, -1, 351, 6, 7, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  21, 437, -1, -1, -1, -1, -1, 374, -1, -1,
  -1, -1, -1, -1, 381, -1, 383, 384, -1, -1,
  456, -1, -1, -1, 605, 392, 6, 7, 8, 9,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, 202, 73, 74, 75, 76, 77, 78, -1, 210,
  -1, -1, -1, -1, 431, 216, -1, 218, 89, 90,
  91, -1, -1, -1, -1, 442, -1, -1, 229, 446,
  -1, -1, -1, 450, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 73, 74, 75, 76, 77, 78, -1,
  -1, -1, 538, -1, -1, -1, 257, 474, 475, 89,
  90, 91, 479, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, 273, -1, 491, -1, -1, 278, -1, -1,
  497, 498, 499, 500, -1, -1, -1, 504, -1, 290,
  -1, 508, -1, -1, -1, -1, 297, -1, 515, 516,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  527, -1, 529, -1, -1, -1, -1, -1, -1, 605,
  -1, -1, -1, 540, -1, 542, -1, -1, 545, -1,
  -1, -1, -1, -1, 551, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 230,
  577, -1, 233, 580, -1, -1, -1, -1, -1, 586,
  -1, -1, 589, 590, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 604, -1, -1,
  -1, -1, -1, -1, 611, -1, -1, -1, -1, -1,
  230, -1, -1, 233, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 634, 635, 636,
  637, 638, 639, 640, -1, -1, 643, -1, 645, -1,
  647, -1, -1, -1, -1, 6, 7, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  21, 452, -1, -1, -1, -1, -1, -1, 459, -1,
  6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
  16, 17, 18, 19, 20, 21, -1, -1, -1, -1,
  481, 352, -1, -1, -1, 486, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 367, -1, -1, -1,
  371, 372, 73, 74, 75, 76, 77, 78, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 89, 90,
  91, -1, 352, -1, -1, -1, -1, 73, 74, 75,
  76, 77, 78, -1, -1, -1, -1, 367, 409, -1,
  -1, 371, 372, 89, 90, 91, 6, 7, 8, 9,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, -1, -1, -1, -1, 437, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 409,
  -1, -1, -1, -1, -1, 456, 6, 7, 8, 9,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, -1, -1, -1, -1, -1, 437, -1, -1,
  -1, -1, -1, 73, 74, 75, 76, 77, 78, -1,
  -1, -1, -1, -1, -1, -1, 456, -1, -1, 89,
  90, 91, 6, 7, 8, 9, 10, 11, 12, 13,
  14, 15, 16, 17, 18, 19, 20, 21, -1, -1,
  -1, -1, -1, 73, 74, 75, 76, 77, 78, 230,
  -1, -1, 233, -1, -1, -1, -1, 538, -1, 89,
  90, 91, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 230, -1, -1, 233, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 73,
  74, 75, 76, 77, 78, -1, -1, -1, 538, -1,
  -1, -1, -1, -1, -1, 89, 90, 91, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 605, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 6, 7, 8,
  9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
  19, 20, 21, -1, -1, -1, -1, -1, -1, -1,
  230, -1, -1, 233, -1, 605, -1, -1, -1, -1,
  -1, 352, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 367, -1, -1, -1,
  371, 372, -1, -1, -1, -1, 352, -1, -1, -1,
  230, -1, -1, 233, 73, 74, 75, 76, 77, 78,
  -1, 367, -1, -1, -1, 371, 372, -1, -1, -1,
  89, 90, 91, -1, -1, -1, -1, -1, 409, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 230, -1, -1, 233,
  -1, -1, -1, 409, -1, -1, 437, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 456, -1, -1, -1, -1,
  -1, 437, 352, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 367, -1, -1,
  456, 371, 372, -1, -1, -1, 6, 7, 8, 9,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, 352, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 367, -1, 409,
  -1, 371, 372, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 538, -1, -1,
  -1, 230, -1, -1, 233, -1, -1, 437, 352, -1,
  -1, -1, -1, 73, 74, 75, 76, 77, 78, 409,
  -1, -1, 538, 367, -1, -1, 456, 371, -1, 89,
  90, 91, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 437, 6, 7,
  8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
  18, 19, 20, 21, 605, 409, 456, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 422, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 605,
  -1, -1, -1, 437, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 538, -1,
  -1, -1, 456, -1, -1, 73, 74, 75, 76, 77,
  78, -1, -1, 352, -1, -1, -1, -1, -1, -1,
  -1, 89, 90, 91, -1, -1, -1, -1, 367, -1,
  -1, -1, 371, -1, -1, -1, -1, -1, 538, -1,
  -1, -1, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, -1, -1, -1,
  230, -1, -1, 233, -1, 605, -1, -1, -1, -1,
  409, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 422, 538, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 437, -1,
  -1, -1, -1, -1, -1, 605, -1, -1, 73, 74,
  75, 76, 77, 78, -1, -1, -1, 456, 73, 74,
  75, 76, 77, 78, 89, 90, 91, -1, -1, -1,
  -1, -1, -1, -1, 89, 90, 91, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  21, 605, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, 230, -1, -1, 233, -1, -1, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  21, -1, 352, -1, 17, 18, -1, 20, -1, -1,
  23, 24, 25, 26, -1, -1, -1, 367, -1, 538,
  -1, 371, 73, 74, 75, 76, 77, 78, -1, -1,
  -1, -1, 45, -1, -1, -1, -1, -1, 89, 90,
  91, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, 73, 74, 75, 76, 77, 78, -1, 409,
  -1, -1, -1, -1, -1, -1, -1, -1, 89, 90,
  91, -1, 422, 10, 11, 12, 13, 14, 15, 16,
  17, 18, 19, 20, 21, 230, 605, 437, 233, -1,
  -1, -1, -1, -1, -1, 230, -1, -1, 233, -1,
  -1, -1, -1, -1, 352, -1, 456, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, -1, -1, 367,
  -1, -1, -1, 371, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 73, 74, 75, 76,
  77, 78, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, 89, 90, 91, -1, -1, -1, 171, -1,
  -1, 409, -1, -1, -1, -1, -1, -1, 73, 74,
  75, 76, 77, 78, -1, -1, -1, -1, -1, 230,
  -1, -1, 233, -1, 89, 90, 91, -1, 538, 437,
  14, 15, 16, 17, 18, 19, 20, 21, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 352, 456, 230,
  -1, -1, 233, -1, -1, -1, -1, 352, -1, -1,
  -1, -1, 367, -1, -1, -1, 371, -1, -1, -1,
  -1, -1, 367, -1, -1, -1, 371, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 73,
  74, 75, 76, 77, 78, 605, -1, -1, -1, -1,
  -1, -1, 275, -1, 409, 89, 90, 91, -1, -1,
  -1, -1, 17, 18, 409, -1, -1, -1, 23, 24,
  25, 26, -1, -1, -1, -1, -1, -1, -1, -1,
  538, -1, 437, 230, -1, 40, 233, -1, -1, -1,
  45, 352, 437, -1, -1, -1, -1, 52, -1, -1,
  -1, 456, -1, -1, -1, -1, 367, -1, -1, -1,
  371, 456, -1, -1, -1, 230, -1, -1, 233, -1,
  -1, 352, -1, -1, -1, 80, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 367, -1, -1, -1,
  371, -1, -1, -1, -1, -1, -1, 605, 409, 17,
  18, -1, -1, 376, -1, 23, 24, 25, 26, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 391, -1,
  -1, 109, 40, -1, -1, -1, 437, 45, 409, 5,
  118, -1, -1, 538, 52, 408, -1, -1, 411, 127,
  -1, -1, -1, 538, 132, 456, 230, -1, -1, 233,
  423, 424, -1, -1, -1, 352, 437, -1, -1, -1,
  -1, -1, 80, -1, -1, -1, 171, -1, 173, -1,
  367, -1, -1, -1, 371, 456, -1, -1, -1, 452,
  -1, -1, -1, -1, -1, -1, -1, 352, 176, -1,
  -1, -1, 465, -1, -1, -1, 184, -1, -1, -1,
  605, -1, 367, -1, 477, -1, 371, -1, -1, -1,
  605, -1, 409, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 422, -1, 538, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  437, -1, -1, -1, 409, -1, 519, -1, -1, -1,
  -1, -1, 240, 171, -1, 173, -1, 538, -1, 456,
  -1, -1, -1, -1, -1, 270, -1, -1, 352, -1,
  275, -1, 437, -1, -1, -1, -1, 265, -1, -1,
  -1, -1, -1, 367, 272, 558, 274, 371, -1, -1,
  -1, 456, -1, -1, 605, -1, 284, 570, 303, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 582,
  583, 584, -1, -1, -1, -1, -1, -1, 591, -1,
  -1, 594, 310, -1, 605, 409, -1, -1, -1, 602,
  318, -1, -1, 338, -1, -1, -1, -1, -1, -1,
  -1, 538, -1, -1, -1, 350, -1, -1, -1, -1,
  -1, -1, 270, 437, -1, -1, -1, 275, -1, -1,
  -1, -1, -1, 368, -1, 241, -1, 355, 373, -1,
  -1, 376, 456, 538, -1, -1, -1, -1, -1, -1,
  -1, -1, 387, -1, -1, 303, -1, -1, 393, -1,
  -1, -1, -1, 381, -1, -1, -1, -1, 403, -1,
  -1, -1, -1, 408, 280, -1, 411, -1, 605, 414,
  -1, -1, -1, -1, -1, -1, -1, -1, 423, 424,
  338, -1, -1, 299, -1, -1, -1, -1, 17, 18,
  -1, 419, 350, -1, 23, 24, 25, 26, -1, -1,
  605, -1, 430, -1, -1, -1, -1, -1, -1, -1,
  368, 40, -1, -1, 538, 373, 45, -1, 376, 464,
  465, -1, 338, 52, 469, -1, -1, -1, -1, 387,
  -1, -1, 477, -1, 350, 393, -1, -1, -1, -1,
  -1, -1, -1, 488, 360, 403, -1, -1, -1, 494,
  408, 80, -1, 411, -1, -1, 414, -1, -1, -1,
  -1, -1, 378, -1, -1, 423, 424, -1, -1, -1,
  -1, -1, 388, -1, 519, -1, -1, -1, -1, -1,
  -1, 605, -1, -1, -1, -1, -1, -1, 404, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, 530, 531, 532, -1, -1, 465, -1, -1,
  -1, 469, -1, -1, -1, 543, -1, -1, 563, 477,
  -1, -1, -1, -1, -1, 570, -1, 572, 444, -1,
  488, -1, 490, -1, -1, -1, 494, 582, 583, 584,
  -1, -1, 171, -1, 173, -1, 591, -1, -1, -1,
  -1, -1, 468, -1, -1, -1, -1, 602, -1, -1,
  -1, 519, -1, -1, -1, -1, -1, 483, -1, -1,
  -1, -1, 17, 18, 490, -1, -1, 493, 23, 24,
  25, 26, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 40, -1, -1, 514, -1,
  45, 517, -1, 519, -1, 563, -1, 52, -1, -1,
  -1, -1, 570, -1, 572, -1, -1, -1, -1, 647,
  -1, -1, 538, -1, 582, 583, 584, -1, -1, -1,
  -1, -1, -1, 591, -1, 80, -1, -1, -1, -1,
  556, 270, -1, -1, 602, -1, 275, -1, 17, 18,
  -1, 20, -1, -1, 23, 24, 25, 26, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 303, -1, 45, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 17, 18,
  -1, 20, -1, -1, 23, 24, 25, 26, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 338,
  -1, -1, -1, -1, -1, -1, 45, -1, -1, -1,
  -1, 350, -1, -1, -1, -1, 171, -1, 173, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 368,
  -1, -1, -1, -1, 373, -1, -1, 376, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 387, -1,
  -1, -1, -1, -1, 393, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 403, -1, -1, -1, -1, 408,
  -1, -1, 411, -1, -1, 414, -1, -1, -1, -1,
  -1, -1, -1, -1, 423, 424, -1, -1, -1, -1,
  -1, -1, 171, 17, 18, -1, 20, -1, -1, 23,
  24, 25, 26, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 270, -1, -1, -1, -1,
  275, 45, -1, -1, -1, 464, 465, -1, -1, -1,
  469, -1, 171, -1, -1, -1, -1, -1, 477, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 303, 488,
  -1, 17, 18, -1, 20, 494, -1, 23, 24, 25,
  26, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 45,
  519, -1, -1, 338, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 350, 275, 17, 18, -1,
  20, -1, -1, 23, 24, 25, 26, -1, -1, -1,
  -1, -1, -1, 368, -1, -1, -1, -1, 373, -1,
  -1, 376, -1, -1, 563, 45, -1, -1, -1, -1,
  -1, 570, 387, 572, -1, -1, 275, -1, 393, -1,
  -1, -1, -1, 582, 583, 584, -1, 171, 403, -1,
  -1, -1, 591, 408, -1, -1, 411, -1, -1, 414,
  -1, -1, -1, 602, -1, -1, -1, -1, 423, 424,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, 17, 18, 376, 20, -1,
  -1, 23, 24, 25, 26, 171, -1, -1, -1, -1,
  465, -1, 391, -1, 469, -1, -1, -1, -1, -1,
  -1, -1, 477, 45, -1, -1, -1, -1, -1, 408,
  -1, -1, 411, 488, -1, -1, -1, 376, -1, 494,
  -1, -1, -1, -1, 423, 424, -1, -1, -1, -1,
  -1, 171, 391, 17, 18, -1, 20, -1, -1, 23,
  24, 25, 26, -1, 519, -1, -1, -1, -1, 408,
  -1, -1, 411, -1, -1, -1, -1, -1, -1, -1,
  -1, 45, -1, -1, 423, 424, 465, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 477, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, 563, -1,
  -1, -1, -1, -1, -1, 570, -1, 572, -1, -1,
  -1, -1, -1, -1, -1, -1, 465, 582, 583, 584,
  -1, -1, -1, -1, -1, -1, 591, -1, 477, -1,
  519, -1, -1, -1, -1, -1, -1, 602, -1, 171,
  -1, -1, 376, -1, -1, 17, 18, -1, 20, -1,
  -1, 23, 24, 25, 26, -1, -1, 391, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 558,
  519, -1, -1, 45, 408, -1, -1, 411, -1, -1,
  -1, 570, -1, -1, -1, -1, -1, -1, -1, -1,
  424, -1, -1, 582, 583, 584, -1, 171, -1, -1,
  376, -1, 591, -1, -1, 594, -1, -1, -1, 558,
  -1, -1, -1, 602, -1, 391, 17, 18, 452, 20,
  -1, 570, 23, 24, 25, 26, -1, -1, -1, -1,
  464, 465, 408, 582, 583, 411, -1, -1, -1, -1,
  -1, -1, 591, 477, 45, 594, 376, -1, 424, -1,
  -1, -1, -1, 602, -1, -1, -1, -1, -1, -1,
  -1, 391, -1, -1, -1, 17, 18, -1, 20, -1,
  -1, 23, 24, 25, 26, -1, 452, -1, 408, -1,
  -1, 411, -1, -1, -1, 519, -1, -1, -1, 465,
  -1, -1, -1, 45, 424, -1, -1, -1, -1, 171,
  -1, 477, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 20, -1, -1,
  23, 24, 25, 26, 558, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 464, 465, 570, -1, -1, -1,
  -1, -1, 45, 519, 376, -1, -1, 477, 582, 583,
  -1, -1, -1, -1, -1, -1, -1, 591, -1, 391,
  594, -1, -1, -1, -1, -1, -1, -1, 602, -1,
  171, -1, -1, -1, -1, -1, 408, -1, -1, 411,
  -1, -1, 558, -1, -1, -1, -1, -1, -1, 519,
  -1, -1, 424, -1, 570, -1, -1, -1, -1, -1,
  -1, -1, 376, -1, -1, -1, 582, 583, -1, -1,
  -1, -1, -1, -1, -1, 591, -1, 391, 594, 171,
  -1, -1, -1, -1, -1, -1, 602, 79, 558, -1,
  -1, -1, 464, 465, 408, -1, -1, 411, -1, -1,
  570, -1, -1, -1, -1, 477, -1, -1, -1, -1,
  424, -1, 582, 583, -1, -1, -1, -1, -1, -1,
  -1, 591, -1, -1, 594, -1, -1, -1, 171, -1,
  -1, -1, 602, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 519, -1, -1,
  464, 465, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 477, 376, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, 391,
  -1, -1, -1, -1, -1, -1, 558, -1, -1, -1,
  -1, -1, 184, -1, -1, -1, 408, -1, 570, 411,
  -1, -1, -1, -1, -1, 519, -1, -1, -1, -1,
  582, 583, 424, -1, -1, -1, -1, -1, -1, 591,
  -1, -1, 594, -1, -1, -1, -1, -1, -1, -1,
  602, -1, -1, -1, -1, 376, -1, -1, -1, -1,
  452, -1, -1, -1, 558, -1, -1, -1, 240, -1,
  391, -1, -1, 465, -1, 241, 570, -1, -1, -1,
  -1, -1, -1, -1, -1, 477, -1, 408, 582, 583,
  411, -1, -1, 265, -1, -1, -1, 591, -1, -1,
  594, -1, 274, 424, 376, -1, -1, -1, 602, -1,
  -1, -1, -1, -1, 280, -1, -1, -1, -1, 391,
  -1, -1, -1, -1, -1, -1, -1, 519, -1, -1,
  -1, -1, -1, 299, -1, -1, 408, -1, 310, 411,
  -1, 313, -1, -1, 465, -1, 318, -1, -1, -1,
  -1, -1, 424, 376, 326, -1, 477, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, 558, -1, 391, -1,
  -1, -1, 338, -1, -1, -1, -1, -1, 570, -1,
  -1, -1, -1, -1, 350, 408, -1, -1, 411, -1,
  582, 583, -1, 465, 360, -1, -1, -1, 519, 591,
  -1, 424, 594, -1, -1, 477, -1, -1, -1, -1,
  602, -1, 378, -1, -1, -1, -1, -1, 390, -1,
  -1, -1, 388, -1, -1, 397, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, 558, 404, -1,
  412, -1, 465, -1, -1, -1, -1, 519, -1, 570,
  -1, -1, -1, -1, 477, -1, -1, -1, -1, -1,
  -1, 582, 583, -1, 436, -1, -1, -1, -1, -1,
  591, -1, -1, 594, -1, -1, -1, -1, 444, -1,
  -1, 602, -1, -1, -1, -1, 558, -1, -1, 461,
  -1, -1, -1, -1, -1, -1, 519, -1, 570, 471,
  472, -1, 468, -1, -1, -1, -1, -1, -1, -1,
  582, 583, -1, -1, -1, 487, -1, 483, -1, 591,
  -1, -1, 594, -1, 490, -1, -1, 493, -1, -1,
  602, -1, -1, -1, -1, 558, -1, 509, -1, -1,
  512, 513, -1, -1, -1, -1, 518, 570, 514, -1,
  -1, 517, -1, 519, -1, -1, -1, -1, -1, 582,
  583, -1, -1, -1, -1, -1, -1, -1, 591, -1,
  -1, 594, 538, -1, -1, -1, -1, -1, -1, 602,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  556, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 575, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, 585, -1, 587
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] = {
  0, 29, 56, 103, 104, 106, 107, 111, 128, 129,
  146, 147, 217, 337, 386, 418, 708, 736, 737, 787,
  954, 1009, 1011, 1012, 1013, 1018, 1020, 1033, 1034, 1035,
  1036, 1037, 1451, 27, 28, 709, 710, 711, 712, 713,
  26, 919, 1470, 336, 515, 529, 554, 603, 1452, 1452,
  1452, 1452, 1452, 1452, 1452, 1452, 919, 24, 919, 1372,
  1038, 738, 737, 1451, 0, 1010, 1013, 1018, 1036, 1451,
  30, 711, 713, 919, 1454, 571, 919, 1453, 608, 788,
  24, 171, 735, 736, 907, 919, 924, 1039, 1075, 1076,
  1077, 1078, 1079, 1083, 334, 740, 741, 742, 743, 746,
  747, 36, 41, 86, 87, 94, 348, 374, 445, 539,
  620, 628, 708, 714, 879, 953, 1014, 1015, 1017, 1021,
  1022, 1028, 1040, 1061, 1194, 1204, 1451, 919, 1453, 599,
  1078, 223, 438, 439, 1085, 20, 919, 1082, 602, 741,
  5, 739, 334, 919, 5, 763, 765, 766, 919, 1205,
  919, 919, 1195, 1029, 919, 919, 1017, 1023, 241, 280,
  299, 338, 350, 360, 378, 388, 404, 444, 468, 483,
  490, 493, 514, 517, 519, 538, 556, 789, 790, 791,
  794, 24, 1075, 1081, 17, 18, 25, 411, 658, 660,
  1075, 1086, 1087, 439, 13, 786, 743, 503, 1181, 744,
  741, 746, 31, 61, 62, 70, 241, 280, 299, 315,
  338, 350, 360, 378, 388, 404, 444, 468, 483, 490,
  493, 514, 517, 519, 538, 556, 599, 749, 757, 768,
  769, 919, 411, 93, 919, 735, 880, 1062, 919, 796,
  517, 748, 772, 774, 775, 773, 782, 783, 411, 411,
  795, 439, 411, 411, 741, 770, 406, 658, 17, 18,
  19, 20, 21, 659, 25, 5, 407, 1086, 23, 24,
  25, 602, 919, 925, 18, 24, 25, 745, 925, 759,
  748, 760, 772, 773, 411, 411, 758, 439, 411, 411,
  770, 741, 767, 411, 25, 919, 411, 1030, 735, 735,
  411, 919, 411, 438, 752, 608, 347, 434, 451, 494,
  534, 563, 572, 776, 608, 347, 434, 451, 494, 534,
  563, 572, 784, 25, 25, 797, 798, 799, 800, 919,
  25, 755, 756, 25, 25, 602, 372, 658, 1087, 439,
  407, 25, 25, 741, 752, 741, 25, 25, 740, 755,
  25, 25, 602, 39, 764, 1206, 372, 411, 1196, 1471,
  1472, 1473, 1474, 1475, 881, 1063, 1024, 602, 25, 777,
  778, 411, 779, 784, 785, 779, 411, 780, 5, 372,
  5, 372, 5, 264, 5, 789, 407, 5, 5, 372,
  372, 741, 771, 1086, 602, 25, 239, 5, 372, 5,
  372, 264, 407, 5, 372, 372, 771, 919, 1092, 1093,
  1095, 1041, 1092, 342, 1472, 1181, 33, 35, 47, 48,
  50, 64, 71, 82, 83, 84, 98, 100, 101, 102,
  105, 108, 110, 112, 113, 119, 122, 124, 125, 126,
  134, 136, 137, 139, 141, 142, 145, 150, 151, 152,
  154, 155, 159, 160, 162, 166, 168, 169, 174, 178,
  181, 183, 185, 187, 189, 190, 192, 193, 194, 198,
  200, 201, 203, 211, 212, 224, 227, 228, 231, 232,
  235, 236, 244, 245, 246, 248, 258, 259, 260, 262,
  266, 267, 271, 279, 287, 288, 289, 295, 296, 301,
  304, 308, 309, 319, 337, 345, 351, 381, 383, 384,
  392, 431, 442, 446, 450, 474, 475, 479, 491, 497,
  498, 499, 500, 504, 508, 515, 516, 527, 529, 540,
  542, 545, 551, 577, 580, 586, 589, 590, 604, 611,
  634, 635, 636, 637, 638, 639, 640, 643, 645, 647,
  651, 652, 653, 654, 671, 693, 707, 708, 714, 715,
  734, 802, 803, 804, 805, 816, 817, 818, 819, 871,
  875, 905, 927, 928, 931, 932, 933, 934, 947, 955,
  978, 979, 981, 985, 1000, 1001, 1005, 1006, 1007, 1008,
  1016, 1031, 1044, 1055, 1056, 1057, 1068, 1071, 1108, 1111,
  1113, 1119, 1120, 1123, 1126, 1129, 1131, 1133, 1135, 1142,
  1147, 1151, 1152, 1153, 1165, 1166, 1169, 1175, 1176, 1177,
  1202, 1217, 1218, 1219, 1220, 1221, 1226, 1232, 1233, 1251,
  1254, 1283, 1284, 1373, 1374, 1405, 1406, 1413, 1424, 1451,
  1455, 1460, 1462, 1464, 1468, 1469, 1476, 708, 1019, 1451,
  607, 630, 1064, 1065, 1092, 20, 372, 406, 753, 776,
  25, 781, 25, 25, 25, 798, 800, 792, 756, 25,
  407, 20, 753, 411, 25, 25, 750, 25, 602, 372,
  5, 1092, 372, 919, 330, 920, 921, 1470, 919, 919,
  1149, 914, 920, 914, 24, 171, 919, 1084, 1446, 1447,
  1448, 919, 1466, 919, 1228, 1229, 919, 25, 655, 1075,
  1224, 914, 1149, 845, 25, 925, 1189, 1190, 1189, 17,
  18, 24, 25, 40, 45, 52, 80, 173, 270, 275,
  303, 338, 350, 368, 373, 376, 387, 393, 403, 408,
  411, 414, 423, 424, 465, 469, 477, 488, 494, 519,
  563, 570, 572, 582, 583, 584, 591, 820, 827, 828,
  829, 830, 831, 832, 833, 834, 846, 851, 862, 863,
  864, 865, 919, 925, 1075, 1184, 1253, 1364, 920, 1414,
  1414, 806, 1149, 914, 1222, 1075, 916, 920, 827, 1414,
  1075, 1149, 1075, 1252, 1414, 24, 567, 1058, 1059, 1075,
  914, 914, 1058, 915, 920, 919, 1059, 914, 1414, 914,
  916, 1075, 1106, 1107, 912, 920, 916, 355, 543, 649,
  911, 919, 980, 919, 716, 917, 920, 1446, 1072, 845,
  920, 1132, 876, 109, 118, 127, 132, 176, 184, 240,
  265, 272, 274, 284, 310, 318, 355, 381, 419, 430,
  530, 531, 532, 543, 647, 992, 1127, 1128, 1075, 826,
  827, 1141, 822, 845, 911, 1461, 1461, 913, 920, 845,
  24, 1075, 1130, 1203, 1075, 1180, 24, 1075, 1408, 827,
  1171, 1172, 1173, 1182, 1183, 827, 1456, 85, 135, 173,
  270, 346, 387, 455, 519, 672, 851, 919, 1075, 1212,
  695, 827, 912, 1453, 1045, 827, 912, 827, 1075, 1002,
  912, 827, 1425, 827, 1189, 919, 929, 930, 916, 929,
  1461, 916, 929, 1461, 935, 929, 24, 25, 365, 468,
  925, 983, 1075, 1094, 1096, 46, 255, 325, 370, 550,
  631, 632, 633, 642, 662, 937, 939, 941, 943, 945,
  1069, 1070, 1074, 316, 327, 379, 394, 484, 1285, 622,
  623, 883, 884, 885, 919, 1066, 629, 1065, 372, 283,
  372, 372, 372, 372, 606, 5, 372, 283, 741, 761,
  762, 372, 372, 606, 372, 919, 1207, 1095, 372, 1197,
  37, 38, 65, 66, 67, 435, 523, 566, 1234, 1235,
  1236, 1239, 1242, 1245, 1246, 1247, 1248, 411, 602, 1448,
  1085, 599, 1124, 602, 8, 520, 569, 5, 372, 407,
  24, 919, 1357, 460, 1150, 1094, 89, 90, 91, 820,
  820, 411, 507, 1201, 411, 411, 411, 411, 411, 411,
  411, 411, 411, 820, 347, 434, 451, 494, 534, 563,
  572, 1367, 1368, 411, 411, 411, 820, 820, 411, 411,
  732, 820, 411, 835, 411, 411, 411, 411, 411, 411,
  411, 820, 411, 6, 7, 8, 9, 10, 11, 12,
  13, 14, 15, 16, 17, 18, 19, 20, 21, 73,
  74, 75, 76, 77, 78, 89, 90, 91, 230, 233,
  352, 367, 371, 409, 437, 456, 538, 605, 731, 821,
  836, 838, 839, 840, 841, 842, 843, 844, 25, 925,
  411, 502, 401, 1075, 1101, 1357, 661, 662, 809, 247,
  68, 69, 608, 440, 5, 601, 608, 600, 600, 1109,
  577, 401, 5, 538, 956, 440, 641, 1458, 411, 439,
  602, 641, 365, 718, 1075, 528, 600, 1114, 1115, 1116,
  307, 1282, 826, 825, 827, 8, 913, 25, 482, 536,
  906, 1075, 906, 906, 906, 997, 998, 906, 906, 578,
  993, 662, 993, 993, 907, 907, 993, 993, 662, 5,
  314, 366, 5, 661, 464, 823, 824, 827, 5, 57,
  63, 521, 609, 986, 644, 1459, 826, 595, 596, 597,
  598, 1179, 1181, 364, 1216, 1181, 1173, 5, 600, 1174,
  827, 411, 411, 411, 411, 24, 691, 919, 411, 1408,
  325, 411, 502, 571, 560, 696, 703, 694, 24, 1060,
  1075, 1167, 8, 1170, 13, 919, 1080, 1088, 1089, 1091,
  1099, 1100, 1143, 143, 325, 526, 559, 32, 171, 535,
  1426, 1427, 1428, 1429, 557, 5, 641, 641, 825, 1094,
  1101, 982, 401, 5, 131, 960, 411, 1075, 825, 411,
  25, 25, 46, 1073, 24, 1075, 1412, 1412, 913, 1132,
  913, 99, 202, 210, 216, 218, 229, 257, 273, 278,
  290, 297, 452, 459, 481, 486, 1255, 1256, 1264, 1273,
  1274, 1280, 1281, 1286, 1287, 1296, 1315, 1319, 1384, 1385,
  1415, 1416, 1419, 1420, 1430, 886, 887, 72, 882, 893,
  894, 885, 1067, 1471, 1025, 439, 789, 756, 439, 5,
  372, 763, 735, 1042, 735, 138, 277, 353, 411, 473,
  1302, 1314, 411, 919, 1250, 25, 226, 239, 411, 457,
  473, 919, 1231, 1244, 1300, 1301, 1306, 1308, 1310, 411,
  919, 1241, 411, 1231, 1237, 5, 24, 922, 1078, 1448,
  1446, 558, 599, 1125, 20, 919, 1105, 1449, 919, 1467,
  1229, 577, 602, 571, 411, 411, 809, 870, 911, 820,
  911, 911, 870, 1461, 452, 1388, 820, 24, 25, 18,
  23, 24, 25, 866, 867, 868, 869, 820, 411, 608,
  911, 20, 820, 372, 1388, 820, 20, 1184, 854, 852,
  858, 820, 856, 820, 820, 820, 820, 820, 820, 820,
  820, 820, 820, 820, 820, 820, 820, 820, 820, 820,
  820, 820, 820, 820, 411, 820, 820, 411, 847, 919,
  1075, 608, 411, 1446, 24, 924, 1148, 1148, 1408, 1058,
  827, 827, 827, 908, 909, 411, 1075, 1107, 770, 957,
  958, 608, 1408, 1461, 1459, 919, 658, 20, 649, 919,
  980, 1075, 717, 607, 827, 331, 1118, 538, 1117, 5,
  49, 51, 53, 600, 608, 801, 1094, 877, 17, 18,
  24, 285, 291, 292, 293, 311, 419, 422, 446, 466,
  501, 521, 522, 532, 537, 576, 609, 999, 994, 1128,
  907, 827, 325, 577, 5, 911, 25, 25, 661, 133,
  1178, 199, 1183, 1189, 1457, 919, 24, 870, 1461, 571,
  911, 605, 1075, 676, 919, 919, 827, 320, 699, 703,
  560, 697, 705, 22, 215, 1047, 1051, 463, 845, 463,
  1168, 827, 438, 1085, 602, 5, 1003, 528, 1144, 1075,
  1447, 1450, 1075, 1097, 1098, 170, 1427, 948, 930, 1461,
  1461, 940, 941, 960, 960, 251, 254, 256, 276, 286,
  328, 332, 410, 462, 646, 959, 961, 962, 988, 1075,
  1096, 528, 663, 25, 380, 946, 302, 1407, 1407, 116,
  117, 417, 528, 919, 1316, 1317, 1358, 770, 1357, 1357,
  1257, 770, 919, 1417, 1417, 340, 457, 567, 1396, 1357,
  1265, 149, 419, 430, 452, 459, 1289, 1290, 1291, 268,
  269, 1379, 1471, 1471, 365, 895, 1075, 624, 625, 888,
  889, 890, 462, 607, 626, 627, 646, 898, 899, 1471,
  735, 25, 754, 754, 762, 1208, 735, 1198, 1304, 1357,
  1249, 1314, 411, 1249, 411, 411, 1243, 1244, 411, 411,
  44, 280, 338, 350, 360, 378, 388, 391, 404, 453,
  483, 493, 514, 517, 519, 547, 556, 1349, 1350, 1351,
  1353, 1240, 1241, 1237, 1238, 646, 1235, 372, 602, 1408,
  558, 439, 528, 1465, 656, 657, 919, 919, 919, 1225,
  845, 5, 372, 372, 372, 372, 372, 1396, 372, 372,
  372, 372, 571, 867, 18, 25, 571, 372, 372, 25,
  1368, 372, 372, 372, 372, 5, 733, 372, 820, 820,
  820, 372, 820, 372, 372, 372, 422, 422, 422, 845,
  1388, 422, 845, 1388, 688, 689, 690, 820, 411, 919,
  1223, 599, 1121, 608, 5, 5, 5, 561, 827, 602,
  5, 464, 608, 372, 407, 411, 607, 144, 148, 251,
  254, 719, 722, 723, 988, 720, 721, 919, 411, 920,
  631, 632, 1122, 827, 919, 919, 909, 910, 490, 1461,
  809, 535, 1270, 25, 25, 411, 995, 997, 1075, 517,
  1136, 823, 46, 820, 1181, 25, 1075, 1471, 5, 5,
  372, 372, 692, 919, 372, 1408, 688, 411, 411, 704,
  700, 341, 698, 827, 320, 701, 705, 578, 990, 1052,
  1048, 343, 1046, 1047, 825, 608, 1081, 20, 919, 1090,
  1100, 13, 17, 18, 20, 24, 25, 45, 376, 391,
  408, 411, 424, 464, 465, 477, 519, 558, 570, 582,
  583, 591, 594, 919, 925, 1145, 1146, 1363, 1365, 1395,
  1400, 1401, 1402, 1450, 401, 401, 5, 1471, 942, 943,
  532, 918, 528, 911, 976, 911, 977, 969, 968, 966,
  965, 989, 419, 430, 972, 973, 419, 430, 974, 975,
  305, 962, 967, 1461, 79, 313, 326, 390, 397, 436,
  461, 471, 472, 487, 509, 512, 513, 518, 575, 587,
  664, 665, 5, 25, 1408, 229, 1075, 452, 1389, 1390,
  1408, 1132, 1383, 1385, 81, 81, 577, 1130, 1318, 1319,
  411, 1297, 130, 507, 1323, 1330, 1357, 156, 252, 1421,
  602, 608, 1386, 1431, 322, 331, 355, 358, 376, 482,
  536, 543, 913, 1267, 1272, 411, 1292, 607, 5, 24,
  919, 1380, 1381, 897, 1075, 5, 528, 891, 892, 621,
  890, 896, 919, 896, 900, 901, 896, 305, 899, 1026,
  407, 407, 441, 1191, 1211, 1043, 441, 1154, 1185, 411,
  5, 372, 275, 411, 423, 584, 1333, 1334, 1335, 1336,
  1337, 1341, 1345, 1347, 1400, 372, 594, 919, 1303, 1305,
  1357, 1360, 1361, 1307, 1360, 5, 372, 1307, 1333, 347,
  434, 451, 494, 534, 563, 572, 1370, 1370, 411, 411,
  411, 411, 411, 411, 188, 380, 1309, 1311, 5, 372,
  5, 372, 919, 1449, 8, 1408, 1086, 827, 5, 1230,
  1231, 845, 1032, 911, 1397, 1398, 1400, 860, 1368, 860,
  25, 25, 571, 23, 25, 773, 861, 1201, 372, 1201,
  774, 372, 1201, 855, 853, 859, 1201, 857, 1201, 1201,
  1201, 24, 24, 24, 820, 837, 372, 24, 837, 372,
  848, 5, 849, 602, 1230, 558, 1408, 1408, 827, 827,
  908, 490, 827, 1463, 5, 20, 1360, 958, 1408, 602,
  919, 720, 728, 727, 729, 919, 923, 730, 923, 172,
  723, 726, 5, 960, 602, 827, 8, 919, 1271, 878,
  996, 997, 1075, 5, 306, 24, 1213, 325, 325, 439,
  602, 325, 411, 677, 681, 674, 1471, 1471, 706, 702,
  698, 991, 24, 918, 1053, 1075, 1471, 827, 406, 439,
  845, 1401, 1401, 1366, 1370, 452, 1400, 411, 411, 411,
  411, 411, 411, 411, 919, 411, 5, 17, 18, 19,
  20, 73, 74, 75, 76, 77, 78, 1422, 1447, 1075,
  1098, 43, 524, 949, 944, 945, 25, 661, 919, 5,
  963, 5, 964, 1471, 1471, 1471, 1471, 995, 5, 971,
  5, 970, 1471, 918, 5, 372, 25, 1357, 1396, 1377,
  577, 577, 1256, 1382, 1383, 1319, 1298, 1360, 599, 913,
  1333, 411, 1260, 919, 1418, 1417, 1397, 565, 827, 827,
  1266, 913, 1293, 1360, 1357, 1291, 602, 602, 5, 5,
  1075, 896, 1471, 1471, 5, 903, 904, 1471, 1471, 902,
  1019, 793, 751, 54, 55, 58, 59, 60, 158, 165,
  199, 208, 237, 238, 282, 324, 380, 610, 611, 612,
  613, 614, 615, 616, 617, 618, 619, 1188, 1192, 115,
  495, 1193, 1209, 1019, 140, 157, 158, 165, 199, 208,
  237, 282, 324, 1186, 1187, 1199, 1193, 1305, 1314, 411,
  1395, 1333, 1400, 1395, 1336, 6, 372, 7, 9, 11,
  12, 13, 14, 15, 16, 233, 352, 409, 538, 584,
  605, 1344, 1346, 1361, 439, 1359, 372, 5, 602, 5,
  372, 1244, 372, 372, 608, 411, 608, 25, 1355, 1355,
  25, 1355, 1355, 25, 1354, 24, 1363, 1312, 1313, 1314,
  1241, 1237, 1408, 8, 407, 657, 5, 372, 825, 372,
  5, 528, 1324, 1329, 261, 301, 302, 303, 326, 334,
  339, 354, 359, 361, 368, 371, 374, 377, 380, 385,
  403, 419, 422, 423, 429, 440, 456, 463, 470, 473,
  474, 475, 477, 478, 494, 518, 519, 520, 521, 523,
  540, 541, 563, 572, 573, 575, 637, 926, 1470, 608,
  372, 25, 571, 608, 372, 372, 372, 372, 5, 372,
  372, 372, 690, 688, 20, 372, 1408, 5, 827, 548,
  255, 666, 667, 827, 20, 919, 372, 960, 1471, 1471,
  5, 724, 439, 602, 5, 725, 1471, 721, 528, 20,
  919, 5, 919, 1112, 370, 641, 1097, 1471, 5, 372,
  918, 820, 5, 688, 1075, 673, 655, 919, 1075, 679,
  372, 688, 688, 1471, 1471, 995, 1050, 24, 1054, 1075,
  553, 874, 1086, 464, 826, 1004, 608, 1396, 372, 376,
  1360, 1423, 340, 457, 567, 1348, 1400, 1403, 1348, 1348,
  1348, 1348, 602, 1403, 1146, 1400, 1400, 1400, 1400, 951,
  950, 421, 936, 937, 602, 911, 1471, 911, 1471, 973,
  1471, 975, 1471, 661, 665, 372, 411, 1409, 1397, 1379,
  1383, 1383, 1375, 5, 372, 452, 1394, 1261, 1360, 460,
  1258, 1394, 608, 1387, 20, 411, 1360, 1434, 1435, 1436,
  1437, 535, 1268, 5, 372, 608, 919, 919, 1381, 1075,
  919, 1471, 1471, 1471, 1471, 606, 606, 1189, 1189, 1189,
  24, 1189, 1189, 1189, 1189, 1189, 1189, 24, 24, 1189,
  1192, 1075, 1102, 1103, 601, 427, 1155, 1471, 24, 24,
  25, 25, 25, 25, 25, 24, 1075, 1187, 1155, 372,
  372, 1334, 1335, 919, 1339, 1363, 1404, 411, 1395, 1339,
  411, 1395, 9, 230, 367, 369, 1400, 25, 1302, 1360,
  20, 919, 1360, 347, 434, 451, 494, 534, 563, 572,
  1371, 25, 1371, 5, 1352, 1352, 5, 372, 372, 1352,
  372, 1314, 1408, 1231, 249, 1227, 1398, 496, 1325, 1326,
  1327, 1357, 1330, 312, 495, 506, 1275, 1391, 347, 434,
  451, 494, 534, 563, 572, 1369, 860, 571, 23, 25,
  777, 820, 850, 449, 808, 5, 354, 1408, 5, 411,
  372, 532, 987, 923, 1471, 658, 20, 919, 923, 1471,
  1461, 827, 1461, 221, 997, 661, 24, 1214, 1094, 407,
  688, 678, 682, 372, 1471, 918, 827, 872, 407, 1371,
  1397, 5, 1370, 5, 372, 1400, 5, 372, 1400, 1400,
  1400, 1400, 919, 372, 827, 1471, 938, 939, 20, 919,
  1410, 1411, 535, 1393, 1378, 1376, 1379, 1360, 1396, 120,
  1299, 5, 372, 1259, 1418, 1393, 13, 1436, 1438, 1432,
  5, 13, 1269, 1360, 443, 1294, 1295, 1358, 602, 191,
  1027, 789, 763, 520, 569, 1104, 5, 1102, 42, 114,
  180, 182, 197, 205, 209, 234, 1156, 1157, 1210, 1027,
  1200, 422, 1338, 1342, 1343, 1363, 1450, 1338, 1342, 1339,
  1400, 5, 407, 1359, 372, 25, 1356, 372, 372, 25,
  372, 411, 1327, 5, 919, 1362, 349, 1321, 1331, 919,
  1392, 601, 1348, 312, 411, 23, 25, 372, 911, 661,
  354, 1408, 827, 668, 550, 1110, 25, 661, 407, 987,
  372, 1134, 372, 372, 411, 680, 325, 686, 372, 675,
  1049, 1471, 1329, 1370, 608, 1370, 372, 1400, 372, 372,
  372, 372, 557, 918, 5, 372, 1097, 1329, 1379, 1379,
  1397, 1360, 411, 1329, 17, 18, 20, 45, 408, 411,
  424, 464, 465, 477, 519, 558, 570, 582, 583, 591,
  594, 919, 1363, 1395, 1439, 1440, 1441, 1442, 1443, 1444,
  1450, 5, 372, 130, 507, 1433, 1437, 411, 1440, 1097,
  5, 121, 1288, 919, 1103, 1158, 1159, 1075, 1161, 1075,
  1160, 1162, 1157, 220, 220, 1340, 1404, 5, 372, 372,
  1338, 7, 25, 608, 372, 1326, 1328, 1326, 1322, 1399,
  1400, 428, 1320, 1332, 1227, 25, 1276, 1277, 1278, 1360,
  1389, 1392, 25, 807, 1408, 373, 184, 240, 265, 274,
  310, 318, 412, 585, 665, 669, 670, 411, 602, 661,
  988, 1137, 1138, 1139, 1215, 683, 372, 1094, 686, 686,
  1471, 873, 372, 608, 1371, 608, 952, 984, 1411, 1391,
  1329, 464, 1262, 1263, 1400, 1391, 1442, 1442, 1439, 1441,
  411, 411, 411, 411, 411, 411, 411, 919, 411, 5,
  17, 18, 19, 20, 1422, 1436, 13, 913, 1333, 1441,
  1295, 1471, 1471, 1163, 1471, 1164, 1471, 1471, 1343, 1400,
  407, 1371, 5, 372, 5, 1333, 5, 520, 569, 1279,
  1227, 372, 328, 332, 810, 811, 812, 988, 906, 906,
  906, 906, 906, 906, 24, 5, 372, 827, 20, 919,
  1140, 263, 1139, 686, 688, 686, 222, 1371, 1371, 1471,
  661, 5, 372, 372, 372, 1423, 1348, 1441, 1445, 1348,
  1348, 1348, 1348, 602, 1445, 1440, 1442, 1442, 1442, 1442,
  411, 1471, 1471, 1326, 1399, 1277, 814, 813, 219, 812,
  815, 670, 5, 1471, 684, 949, 1263, 372, 1441, 5,
  372, 1441, 1441, 1441, 1441, 919, 372, 1439, 1471, 1471,
  1471, 827, 372, 372, 1441, 372, 372, 372, 372, 372,
  372, 685, 143, 325, 687, 1094
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h>		/* INFRINGES ON USER NAME SPACE */
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
#  include <stdio.h>		/* INFRINGES ON USER NAME SPACE */
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
  for ( /* Nothing. */ ; bottom <= top; ++bottom)
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
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
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
yysymprint (FILE * yyoutput, int yytype, YYSTYPE * yyvaluep)
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
yydestruct (int yytype, YYSTYPE * yyvaluep)
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
int
yyparse (void *YYPARSE_PARAM)
# else
int
yyparse (YYPARSE_PARAM)
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
  short yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     A4GL_action routines.  */
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
		    &yyvs1, yysize * sizeof (*yyvsp), &yystacksize);

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
	if (!yyptr)
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

  /* If the proper A4GL_action on seeing token YYTOKEN is to reduce or to
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
| yydefault -- do the default A4GL_action for the current state.  |
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
  yyval = yyvsp[1 - yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
    case 2:
#line 898 "fgl.yacc"
      {
	print_screen_mode (0);
      }
      break;

    case 3:
#line 901 "fgl.yacc"
      {
	print_screen_mode (1);
      }
      break;

    case 4:
#line 905 "fgl.yacc"
      {
	print_start_server (yyvsp[-3].str, yyvsp[0].str);
      }
      break;

    case 5:
#line 911 "fgl.yacc"
      {
	print_stop_external ();
      }
      break;

    case 6:
#line 916 "fgl.yacc"
      {
	if (scan_variable (yyvsp[0].str) != 2)
	  {
	    char buff[256];
	    strcpy (buff, "START EXTERNAL ..ON must be an integer");
	    a4gl_yyerror (buff);
	    YYERROR;
	  }
      }
      break;

    case 9:
#line 928 "fgl.yacc"
      {
	sprintf (yyval.str, "%s%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 10:
#line 933 "fgl.yacc"
      {
	print_remote_func (yyvsp[0].str);
	sprintf (yyval.str, "unregister_func(\"%s\",%s%s);\n", yyvsp[0].str,
		 (char *) get_namespace (yyvsp[0].str), yyvsp[0].str);
	addmap ("Call Remote", yyvsp[0].str, curr_func, yylineno, infilename);
      }
      break;

    case 11:
#line 951 "fgl.yacc"
      {
	sprintf (yyval.str, "(%s)", yyvsp[-1].str);
      }
      break;

    case 12:
#line 952 "fgl.yacc"
      {
	sprintf (yyval.str, "%s%s%s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 13:
#line 953 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", atoi (yyvsp[0].str));
      }
      break;

    case 14:
#line 954 "fgl.yacc"
      {
	sprintf (yyval.str, "(%s%s)", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 15:
#line 955 "fgl.yacc"
      {
	int a;
	a = scan_variable (yyvsp[0].str) & 15;
	if (a != 1 && a != 2)
	  {

	    a4gl_yyerror
	      ("Only INTEGER/SMALLINT variables may be used as subscripts");
	    YYERROR;
	    /* error processing */ ;
	  }
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 16:
#line 969 "fgl.yacc"
      {
	strcpy (yyval.str, "+");
      }
      break;

    case 17:
#line 970 "fgl.yacc"
      {
	strcpy (yyval.str, "-");
      }
      break;

    case 18:
#line 971 "fgl.yacc"
      {
	strcpy (yyval.str, "*");
      }
      break;

    case 19:
#line 972 "fgl.yacc"
      {
	strcpy (yyval.str, "/");
      }
      break;

    case 20:
#line 973 "fgl.yacc"
      {
	strcpy (yyval.str, "%");
      }
      break;

    case 21:
#line 978 "fgl.yacc"
      {
	strcpy (yyval.str, "+");
      }
      break;

    case 22:
#line 979 "fgl.yacc"
      {
	strcpy (yyval.str, "-");
      }
      break;

    case 23:
#line 990 "fgl.yacc"
      {
 A4GL_debug ("Using default attribute of WHITE");
	sprintf (yyval.str, "%d", 0);
      }
      break;

    case 24:
#line 993 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 25:
#line 996 "fgl.yacc"
      {
	start_state ("attribute", 1);
      }
      break;

    case 26:
#line 996 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[-1].str);
 A4GL_debug ("Got Attributes : %s", yyvsp[-1].str);
	start_state ("attribute", 0);
      }
      break;

    case 28:
#line 1003 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 29:
#line 1004 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", atoi (yyvsp[-2].str) | atoi (yyvsp[0].str));
      }
      break;

    case 30:
#line 1010 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("BLACK"));
      }
      break;

    case 31:
#line 1011 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("BLUE"));
      }
      break;

    case 32:
#line 1012 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("CYAN"));
      }
      break;

    case 33:
#line 1013 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("GREEN"));
      }
      break;

    case 34:
#line 1014 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("MAGENTA"));
      }
      break;

    case 35:
#line 1015 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("RED"));
      }
      break;

    case 36:
#line 1016 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("WHITE"));
      }
      break;

    case 37:
#line 1017 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("YELLOW"));
      }
      break;

    case 38:
#line 1018 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("REVERSE"));
      }
      break;

    case 39:
#line 1019 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("BLINK"));
      }
      break;

    case 40:
#line 1020 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("UNDERLINE"));
      }
      break;

    case 41:
#line 1021 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("BOLD"));
      }
      break;

    case 42:
#line 1022 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("NORMAL"));
      }
      break;

    case 43:
#line 1023 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("INVISIBLE"));
      }
      break;

    case 44:
#line 1024 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", attr_code ("DIM"));
      }
      break;

    case 45:
#line 1025 "fgl.yacc"
      {
	inp_flags = inp_flags | 0x1;
	strcpy (yyval.str, "0");
      }
      break;

    case 48:
#line 1032 "fgl.yacc"
      {
 A4GL_debug ("win_attributes_def");
	start_state ("attribute", 1);
 A4GL_debug ("Started states");
	form_attrib.attrib = 0;
      }
      break;

    case 49:
#line 1036 "fgl.yacc"
      {
	start_state ("attribute", 0);
	strcpy (yyval.str, "");
      }
      break;

    case 50:
#line 1040 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 51:
#line 1041 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 52:
#line 1045 "fgl.yacc"
      {
/*printf("Window attribute = %s\n",$<str>1);*/
	form_attrib.attrib = form_attrib.attrib | atoi (yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
      }
      break;

    case 53:
#line 1051 "fgl.yacc"
      {
	form_attrib.border = 1;
      }
      break;

    case 54:
#line 1053 "fgl.yacc"
      {
	int a;
	char *buff;
	a = form_attrib.attrib & 255;
	if (strlen (yyvsp[0].str) > 2)
	  {
	    buff = yyvsp[0].str;
	    form_attrib.attrib = form_attrib.attrib + buff[1];
	  }
	else
	  {
	    form_attrib.attrib = form_attrib.attrib + ' ';
	  }
      }
      break;

    case 55:
#line 1064 "fgl.yacc"
      {
	form_attrib.comment_line = atoi (yyvsp[0].str);
      }
      break;

    case 56:
#line 1066 "fgl.yacc"
      {
	form_attrib.form_line = atoi (yyvsp[0].str);
      }
      break;

    case 57:
#line 1068 "fgl.yacc"
      {
	form_attrib.error_line = atoi (yyvsp[0].str);
      }
      break;

    case 58:
#line 1070 "fgl.yacc"
      {
	form_attrib.menu_line = atoi (yyvsp[0].str);
 A4GL_debug ("Set menu line to %s", yyvsp[0].str);
      }
      break;

    case 59:
#line 1074 "fgl.yacc"
      {
	form_attrib.message_line = atoi (yyvsp[0].str);
      }
      break;

    case 60:
#line 1076 "fgl.yacc"
      {
	form_attrib.prompt_line = atoi (yyvsp[0].str);
      }
      break;

    case 61:
#line 1137 "fgl.yacc"
      {
	strcpy (yyval.str, "CALL");
      }
      break;

    case 62:
#line 1141 "fgl.yacc"
      {
 A4GL_debug ("print_expr (3)");
	print_expr (yyvsp[-2].ptr);
	print_pop_variable (yyvsp[0].str);
      }
      break;

    case 63:
#line 1145 "fgl.yacc"
      {
	print_getfldbuf (yyvsp[-2].str);
      }
      break;

    case 64:
#line 1148 "fgl.yacc"
      {
	print_returning ();
      }
      break;

    case 65:
#line 1156 "fgl.yacc"
      {
	print_form_is_compiled (yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str);
      }
      break;

    case 66:
#line 1161 "fgl.yacc"
      {
	print_field_func ('I', yyvsp[-3].str, yyvsp[0].str);
      }
      break;

    case 68:
#line 1165 "fgl.yacc"
      {
	print_field_func ('T', yyvsp[-3].str, yyvsp[0].str);
      }
      break;

    case 69:
#line 1168 "fgl.yacc"
      {
	new_counter ();
	addmap ("Call", yyvsp[-3].str, curr_func, yylineno, infilename);
      }
      break;

    case 70:
#line 1174 "fgl.yacc"
      {
	int a;
	dump_expr (yyvsp[-1].ptr);
	a = get_counter_val ();
	drop_counter ();
 A4GL_debug ("Printing call_func_call...");
	print_class_func_call (yyvsp[-6].str, yyvsp[-4].str, yyvsp[-1].ptr,
			       a);
      }
      break;

    case 71:
#line 1183 "fgl.yacc"
      {
	print_returning ();
	strcpy (yyval.str, yyvsp[-4].str);	/* ? */
      }
      break;

    case 72:
#line 1187 "fgl.yacc"
      {
	new_counter ();
	addmap ("Call", yyvsp[-1].str, curr_func, yylineno, infilename);
      }
      break;

    case 73:
#line 1192 "fgl.yacc"
      {
 A4GL_debug ("Got args");
      }
      break;

    case 74:
#line 1196 "fgl.yacc"
      {
	int a;
	dump_expr (yyvsp[-2].ptr);
	a = get_counter_val ();
	drop_counter ();
	print_func_call (yyvsp[-5].str, yyvsp[-2].ptr, a);
      }
      break;

    case 75:
#line 1204 "fgl.yacc"
      {
	print_returning ();
	strcpy (yyval.str, yyvsp[-3].str);	/* ? */
      }
      break;

    case 76:
#line 1208 "fgl.yacc"
      {
	A4GLSQL_set_status (0, 0);
	new_counter ();
      }
      break;

    case 77:
#line 1212 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
	drop_counter ();
      }
      break;

    case 78:
#line 1214 "fgl.yacc"
      {
	print_expr ((struct expr_str *) yyvsp[-3].ptr);
	print_call_shared (yyvsp[-6].str, yyvsp[-8].str,
			   atoi (yyvsp[-2].str));
	print_returning ();
	print_end_call_shared ();
      }
      break;

    case 79:
#line 1220 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\",\"%s\"", yyvsp[-3].str, yyvsp[-1].str);
	A4GLSQL_set_status (0, 0);
	new_counter ();
      }
      break;

    case 80:
#line 1225 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
	drop_counter ();
      }
      break;

    case 81:
#line 1228 "fgl.yacc"
      {
	char buff[256];
	char *ptr;
 A4GL_debug ("STR6 = %s", yyvsp[-4].str);
	strcpy (buff, yyvsp[-4].str);
	ptr = strchr (buff, ',');
	*ptr = 0;
	ptr++;
	print_expr ((struct expr_str *) yyvsp[-3].ptr);
	print_call_shared (buff, ptr, atoi (yyvsp[-2].str));
	print_returning ();
	print_end_call_shared ();
      }
      break;

    case 82:
#line 1244 "fgl.yacc"
      {
	char buff[256];
	new_counter ();
	sprintf (buff, "%s:%s(%p)", yyvsp[-6].str, yyvsp[-4].str,
		 yyvsp[-2].str);
	addmap ("External", buff, curr_func, yylineno, infilename);
      }
      break;

    case 83:
#line 1251 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
	drop_counter ();
      }
      break;

    case 84:
#line 1255 "fgl.yacc"
      {
 A4GL_debug ("print_expr (6)");
	print_expr (yyvsp[-2].ptr);
      }
      break;

    case 85:
#line 1259 "fgl.yacc"
      {
	/* int cnt; */
	char fname[64];

	if (strcmp (yyvsp[0].str, "WITHOUT WAITING") == 0)
	  {
	    strcpy (fname, "1,");
	    strcat (fname, yyvsp[-10].str);
	  }
	else
	  {
	    strcpy (fname, "0,");
	    strcat (fname, yyvsp[-10].str);
	  }

	print_call_external (yyvsp[-12].str, fname, yyvsp[-8].str,
			     atoi (yyvsp[-3].str));

	if (strcmp (yyvsp[0].str, "WITHOUT WAITING") != 0)
	  {
	    print_returning ();
	  }
	print_end_call_external ();
      }
      break;

    case 86:
#line 1281 "fgl.yacc"
      {
	start_bind ('i', 0);
	strcpy (yyval.str, "0");
      }
      break;

    case 87:
#line 1281 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 88:
#line 1285 "fgl.yacc"
      {
	start_bind ('i', 0);
	strcpy (yyval.str, "0");
      }
      break;

    case 89:
#line 1286 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 90:
#line 1287 "fgl.yacc"
      {
	strcpy (yyval.str, "WITHOUT WAITING");
      }
      break;

    case 91:
#line 1292 "fgl.yacc"
      {
	yyval.ptr = new_expr ("");
      }
      break;

    case 92:
#line 1295 "fgl.yacc"
      {
	yyval.ptr = yyvsp[0].ptr;
      }
      break;

    case 93:
#line 1301 "fgl.yacc"
      {
	yyval.ptr = yyvsp[0].ptr;
      }
      break;

    case 94:
#line 1304 "fgl.yacc"
      {
	yyval.ptr = append_expr_expr (yyvsp[-2].ptr, yyvsp[0].ptr);
      }
      break;

    case 97:
#line 1316 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 98:
#line 1322 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 99:
#line 1325 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.%s\"", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 100:
#line 1340 "fgl.yacc"
      {
	push_blockcommand ("CASE");
	setinc (1);
 A4GL_incprint ();
	print_case (1);
	setinc (1);
      }
      break;

    case 101:
#line 1350 "fgl.yacc"
      {
	print_after_when (0);
	pop_blockcommand ("CASE");
      }
      break;

    case 102:
#line 1356 "fgl.yacc"
      {
	push_blockcommand ("CASE");
	setinc (1);
 A4GL_incprint ();
	print_case (0);
	setinc (1);
      }
      break;

    case 103:
#line 1365 "fgl.yacc"
      {
	print_after_when (0);
	pop_blockcommand ("CASE");
      }
      break;

    case 108:
#line 1378 "fgl.yacc"
      {
	setinc (-1);
 A4GL_incprint ();
      }
      break;

    case 110:
#line 1381 "fgl.yacc"
      {
 A4GL_incprint ();
      }
      break;

    case 111:
#line 1383 "fgl.yacc"
      {
 A4GL_incprint ();
	print_after_when (0);
      }
      break;

    case 113:
#line 1389 "fgl.yacc"
      {
 A4GL_incprint ();
      }
      break;

    case 114:
#line 1391 "fgl.yacc"
      {
 A4GL_incprint ();
	print_after_when (0);
      }
      break;

    case 115:
#line 1396 "fgl.yacc"
      {
	print_when (0);

 A4GL_incprint ();
      }
      break;

    case 116:
#line 1401 "fgl.yacc"
      {
 A4GL_incprint ();
	print_after_when (1);
	setinc (-1);
      }
      break;

    case 117:
#line 1407 "fgl.yacc"
      {
 A4GL_incprint ();
	print_when (1);
      }
      break;

    case 118:
#line 1411 "fgl.yacc"
      {
 A4GL_incprint ();
	print_after_when (1);
	setinc (-1);
      }
      break;

    case 119:
#line 1426 "fgl.yacc"
      {
	print_close ('F', yyvsp[0].str);
      }
      break;

    case 120:
#line 1429 "fgl.yacc"
      {
	print_close ('W', yyvsp[0].str);
      }
      break;

    case 121:
#line 1432 "fgl.yacc"
      {
	print_close ('W', yyvsp[0].str);
      }
      break;

    case 122:
#line 1435 "fgl.yacc"
      {
	print_close ('D', 0);
      }
      break;

    case 123:
#line 1438 "fgl.yacc"
      {
	print_close ('S', yyvsp[0].str);
      }
      break;

    case 124:
#line 1441 "fgl.yacc"
      {
	print_close ('C', yyvsp[0].str);
      }
      break;

    case 130:
#line 1463 "fgl.yacc"
      {
 A4GL_lex_printc ("%s", yyvsp[0].str);
      }
      break;

    case 133:
#line 1472 "fgl.yacc"
      {
 A4GL_lex_printc ("%s\n", yyvsp[0].str);
      }
      break;

    case 134:
#line 1482 "fgl.yacc"
      {
/* This aint used - its filtered by the lexer first... */
 A4GL_lex_printc ("FIXME : Comment : %s\n");
      }
      break;

    case 135:
#line 1496 "fgl.yacc"
      {
	push_blockcommand ("CONSTRUCT");
      }
      break;

    case 136:
#line 1500 "fgl.yacc"
      {
	print_construct_1 ();
      }
      break;

    case 137:
#line 1503 "fgl.yacc"
      {
	print_construct_2 (yyvsp[-2].str);
      }
      break;

    case 138:
#line 1511 "fgl.yacc"
      {
	print_construct_3 (1, yyvsp[-5].str, yyvsp[0].str);
	strcpy (yyval.str, "form_loop(&_inp_io[0])");	/* FIXME */
	reset_constr ();
      }
      break;

    case 139:
#line 1517 "fgl.yacc"
      {
	print_construct_3 (0, yyvsp[-7].str, yyvsp[0].str);
	strcpy (yyval.str, "form_loop(&_inp_io[0])");	/* FIXME */
	reset_constr ();
      }
      break;

    case 144:
#line 1532 "fgl.yacc"
      {
	push_construct ("", yyval.str);
      }
      break;

    case 145:
#line 1536 "fgl.yacc"
      {
	sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str);
	push_construct (yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 146:
#line 1541 "fgl.yacc"
      {
	push_construct (yyvsp[-2].str, "*");
      }
      break;

    case 149:
#line 1551 "fgl.yacc"
      {
	print_befaft_field_1 (yyvsp[0].str);
      }
      break;

    case 150:
#line 1554 "fgl.yacc"
      {
	print_befaft_field_2 ();

      }
      break;

    case 151:
#line 1558 "fgl.yacc"
      {
	print_befaft_field_1 (yyvsp[0].str);
      }
      break;

    case 152:
#line 1560 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 153:
#line 1563 "fgl.yacc"
      {
	print_onkey_1 (yyvsp[0].str);
      }
      break;

    case 154:
#line 1565 "fgl.yacc"
      {
	print_onkey_2 ();
      }
      break;

    case 155:
#line 1568 "fgl.yacc"
      {
	print_befaft_field_1 ("AFTER_INP");
      }
      break;

    case 156:
#line 1570 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 157:
#line 1573 "fgl.yacc"
      {
	print_befaft_field_1 ("BEFORE_INP");
      }
      break;

    case 158:
#line 1576 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 159:
#line 1586 "fgl.yacc"
      {
	sprintf (yyval.str, "BEF_FIELD_CHK(%s)", yyvsp[0].str);
      }
      break;

    case 160:
#line 1587 "fgl.yacc"
      {
	char buff[80];
	sprintf (buff, "BEF_FIELD_CHK(%s)", yyvsp[0].str);
 A4GL_generate_or (yyval.str, yyvsp[-2].str, buff);
      }
      break;

    case 161:
#line 1595 "fgl.yacc"
      {
	sprintf (yyval.str, "AFT_FIELD_CHK(%s)", yyvsp[0].str);
      }
      break;

    case 162:
#line 1596 "fgl.yacc"
      {
	char buff[80];
	sprintf (buff, "AFT_FIELD_CHK(%s)", yyvsp[0].str);
 A4GL_generate_or (yyval.str, yyvsp[-2].str, buff);
      }
      break;

    case 163:
#line 1613 "fgl.yacc"
      {
	yyval.ptr = new_expr ("pushop(OP_YEAR);");
      }
      break;

    case 164:
#line 1616 "fgl.yacc"
      {
	yyval.ptr = new_expr ("pushop(OP_MONTH);");
      }
      break;

    case 165:
#line 1619 "fgl.yacc"
      {
	yyval.ptr = new_expr ("pushop(OP_DAY);");
      }
      break;

    case 166:
#line 1622 "fgl.yacc"
      {
	yyval.ptr = new_expr ("pushop(OP_HOUR);");
      }
      break;

    case 167:
#line 1625 "fgl.yacc"
      {
	yyval.ptr = new_expr ("pushop(OP_MINUTE);");
      }
      break;

    case 168:
#line 1628 "fgl.yacc"
      {
	yyval.ptr = new_expr ("pushop(OP_SECOND);");
      }
      break;

    case 169:
#line 1637 "fgl.yacc"
      {
	yyval.ptr = append_expr_expr (yyvsp[-2].ptr, yyvsp[-1].ptr);
      }
      break;

    case 170:
#line 1645 "fgl.yacc"
      {
	char buff[50];
	sprintf (buff, "push_int(%d);", (19 * 16) + 10);
	yyval.ptr = new_expr (buff);
      }
      break;

    case 171:
#line 1650 "fgl.yacc"
      {
	char buff[50];
	sprintf (buff, "push_int(%d);",
		 (atoi (yyvsp[-2].str) * 16) + atoi (yyvsp[0].str));
	yyval.ptr = new_expr (buff);
      }
      break;

    case 172:
#line 1663 "fgl.yacc"
      {
	print_defer (0);
      }
      break;

    case 173:
#line 1667 "fgl.yacc"
      {
	print_defer (1);
      }
      break;

    case 174:
#line 1682 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 175:
#line 1683 "fgl.yacc"
      {
	strcpy (yyval.str, "");
	lastlineno = yylineno;
      }
      break;

    case 178:
#line 1691 "fgl.yacc"
      {
	dtypelist[0] = 0;
 A4GL_lex_printcomment ("/* define */\n");
      }
      break;

    case 179:
#line 1691 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*end def */\n");
      }
      break;

    case 185:
#line 1701 "fgl.yacc"
      {
	in_define = 1;
      }
      break;

    case 186:
#line 1701 "fgl.yacc"
      {
	in_define = 0;
	strcpy (yyval.str, yyvsp[0].str);
	set_yytext (yyval.str);
	if (A4GL_bad_identifiers (yyval.str))
	  {
	    a4gl_yyerror
	      ("You can't use this identifier as it is a reserved word in the target language");
	  }
      }
      break;

    case 187:
#line 1710 "fgl.yacc"
      {
	add_constant ('c', yyvsp[0].str, yyvsp[-2].str);
	addmap ("Constant", yyvsp[-2].str, curr_func, yylineno, infilename);
      }
      break;

    case 188:
#line 1711 "fgl.yacc"
      {
	add_constant ('C', yyvsp[0].str, yyvsp[-2].str);
	addmap ("Constant", yyvsp[-2].str, curr_func, yylineno, infilename);
      }
      break;

    case 189:
#line 1712 "fgl.yacc"
      {
	add_constant ('f', yyvsp[0].str, yyvsp[-2].str);
	addmap ("Constant", yyvsp[-2].str, curr_func, yylineno, infilename);
      }
      break;

    case 190:
#line 1715 "fgl.yacc"
      {
	add_constant ('i', yyvsp[0].str, yyvsp[-2].str);
	addmap ("Constant", yyvsp[-2].str, curr_func, yylineno, infilename);
      }
      break;

    case 192:
#line 1720 "fgl.yacc"
      {
      }
      break;

    case 193:
#line 1720 "fgl.yacc"
      {
	char buff[20];
	strncpy (buff, yyvsp[0].str, 3);
	if (buff[0] == '"')
	  {
	    add_constant ('c', yyvsp[0].str, yyvsp[-3].str);
	  }
	else
	  {
	    if (strchr (yyvsp[0].str, '.'))
	      add_constant ('f', yyvsp[0].str, yyvsp[-3].str);
	    else
	      add_constant ('i', yyvsp[0].str, yyvsp[-3].str);
	  }

	addmap ("Constant", yyvsp[-3].str, curr_func, yylineno, infilename);
      }
      break;

    case 197:
#line 1737 "fgl.yacc"
      {
	sprintf (yyval.str, "-%p", yyvsp[0].str);
      }
      break;

    case 198:
#line 1741 "fgl.yacc"
      {
/*AF CygWin FIX */
	push_name (yyval.str, 0);
	addmap ("Define", yyvsp[0].str, curr_func, yylineno, infilename);
      }
      break;

    case 203:
#line 1755 "fgl.yacc"
      {
 A4GL_debug ("defines array %s", yyvsp[-1].str);
	push_type (0, 0, yyvsp[-1].str);
      }
      break;

    case 205:
#line 1764 "fgl.yacc"
      {
	push_associate (yyvsp[-5].str, yyvsp[-1].str);
	push_type (0, 0, yyvsp[-1].str);
      }
      break;

    case 206:
#line 1768 "fgl.yacc"
      {
	/* void pop_associate (char *a); */
	pop_associate (0);

      }
      break;

    case 212:
#line 1784 "fgl.yacc"
      {
	sprintf (yyval.str, "%s][%s][%s", yyvsp[-4].str, yyvsp[-2].str,
		 yyvsp[0].str);
 A4GL_debug ("Triplet");
      }
      break;

    case 213:
#line 1786 "fgl.yacc"
      {
	sprintf (yyval.str, "%s][%s", yyvsp[-2].str, yyvsp[0].str);
 A4GL_debug ("double");
      }
      break;

    case 214:
#line 1787 "fgl.yacc"
      {
 A4GL_debug ("Single");
      }
      break;

    case 216:
#line 1794 "fgl.yacc"
      {
	push_record ();
	in_record++;
      }
      break;

    case 217:
#line 1794 "fgl.yacc"
      {
	pop_record ();
	in_record--;
      }
      break;

    case 218:
#line 1795 "fgl.yacc"
      {
	in_record++;
	push_record ();
 A4GL_debug ("Like\n");
      }
      break;

    case 219:
#line 1796 "fgl.yacc"
      {
 A4GL_debug ("Link Table : %s\n", yyvsp[-2].str);
	push_rectab (yyvsp[-2].str);
	pop_record ();
	in_record--;
      }
      break;

    case 220:
#line 1799 "fgl.yacc"
      {
	push_record ();
 A4GL_debug ("Like\n");
      }
      break;

    case 221:
#line 1801 "fgl.yacc"
      {
 A4GL_debug ("Table:%s\n", yyvsp[-4].str);
	add_link_to (yyvsp[-4].str, yyvsp[-1].str);
 A4GL_debug ("Push record...\n");
	push_rectab (yyvsp[-4].str);
	pop_record ();
      }
      break;

    case 223:
#line 1811 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 228:
#line 1826 "fgl.yacc"
      {
	start_state ("dtype", 1);
      }
      break;

    case 229:
#line 1826 "fgl.yacc"
      {
	start_state ("dtype", 0);
      }
      break;

    case 233:
#line 1832 "fgl.yacc"
      {
	push_type ("char", "1", 0);
      }
      break;

    case 234:
#line 1833 "fgl.yacc"
      {
/* char buff[80]; */
	if (atoi (yyvsp[-1].str) == 4)
	  {
	    addmap ("size=4", "----", curr_func, yylineno, infilename);
	  }
	push_type ("char", yyvsp[-1].str, 0);
      }
      break;

    case 235:
#line 1840 "fgl.yacc"
      {
	push_type ("char", yyvsp[-1].str, 0);
      }
      break;

    case 236:
#line 1841 "fgl.yacc"
      {
	push_type ("char", yyvsp[-3].str, 0);
      }
      break;

    case 237:
#line 1842 "fgl.yacc"
      {
	push_type ("long", 0, 0);
      }
      break;

    case 238:
#line 1843 "fgl.yacc"
      {
 A4GL_debug ("Using specified type...");
	push_dim (yyvsp[0].str);
      }
      break;

    case 239:
#line 1846 "fgl.yacc"
      {
	push_type ("int", 0, 0);
      }
      break;

    case 240:
#line 1847 "fgl.yacc"
      {
	push_type ("form", 0, 0);
      }
      break;

    case 241:
#line 1848 "fgl.yacc"
      {
	push_type ("form", 0, 0);
      }
      break;

    case 242:
#line 1849 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "%d", 16 * 256 + 2);
	push_type ("fgldecimal", buff, 0);
      }
      break;

    case 243:
#line 1853 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "%d", atoi (yyvsp[-1].str) * 256 + 2);
	push_type ("fgldecimal", buff, 0);
      }
      break;

    case 244:
#line 1858 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "%d",
		 atoi (yyvsp[-3].str) * 256 + atoi (yyvsp[-1].str));
	push_type ("fgldecimal", buff, 0);
      }
      break;

    case 245:
#line 1863 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "%d", 16 * 256 + 2);
	push_type ("fglmoney", buff, 0);
      }
      break;

    case 246:
#line 1867 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "%d", atoi (yyvsp[-1].str) * 256 + 2);
	push_type ("fglmoney", buff, 0);
      }
      break;

    case 247:
#line 1870 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "%d",
		 atoi (yyvsp[-3].str) * 256 + atoi (yyvsp[-1].str));
	push_type ("fglmoney", buff, 0);
      }
      break;

    case 248:
#line 1874 "fgl.yacc"
      {
	push_type ("double", 0, 0);
      }
      break;

    case 249:
#line 1875 "fgl.yacc"
      {
	push_type ("float", 0, 0);
      }
      break;

    case 250:
#line 1876 "fgl.yacc"
      {
	push_type ("fgldate", 0, 0);
      }
      break;

    case 251:
#line 1877 "fgl.yacc"
      {
	push_type ("fglbyte", 0, 0);
      }
      break;

    case 252:
#line 1878 "fgl.yacc"
      {
	push_type ("fglbyte", 0, 0);
      }
      break;

    case 253:
#line 1879 "fgl.yacc"
      {
	push_type ("fgltext", 0, 0);
      }
      break;

    case 254:
#line 1880 "fgl.yacc"
      {
	push_type ("fgltext", 0, 0);
      }
      break;

    case 255:
#line 1881 "fgl.yacc"
      {
	push_type ("struct_dtime", yyvsp[0].str, 0);
      }
      break;

    case 256:
#line 1884 "fgl.yacc"
      {
	push_type ("struct_ival", yyvsp[0].str, 0);
      }
      break;

    case 257:
#line 1885 "fgl.yacc"
      {
	push_like (yyvsp[0].str);
 A4GL_lex_printcomment ("/*added(XXXXX)\n */");
      }
      break;

    case 258:
#line 1886 "fgl.yacc"
      {
	char buff[256];
	strcpy (buff, yyvsp[0].str);
 A4GL_debug ("Got a rogue datatype");

	if (A4GL_find_datatype (upshift (buff)))
	  {
	    char *(*function) (void);
	    A4GL_debug ("Checking ...");
	    function = A4GL_get_datatype_function_n (upshift (buff), "OUTPUT");
	    A4GL_debug ("Got function as %p", function);

	    /*  warning: comparison between pointer and integer */
	    if ((int) function != -1 && (int) function != 0)
	      {
	 A4GL_debug ("call returns %s\n", function ());
		strcpy (buff, function ());
	 A4GL_debug ("Set up buff as %s");
		push_type (function (), 0, 0);
	 A4GL_debug ("Pushed type : %s\n", function ());
	      }
	  }
	else
	  {
	    /* yyerror("Unknown datatype : %s",$<str>1); */
	    a4gl_yyerror ("Unknown datatype.");
	  }
      }
      break;

    case 259:
#line 1918 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*column like(ZZZ)\n*/");
	sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str);
 A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");
      }
      break;

    case 260:
#line 1922 "fgl.yacc"
      {
 A4GL_debug ("--->%s\n", yyvsp[0].str);
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 261:
#line 1924 "fgl.yacc"
      {
 A4GL_debug ("--->%s\n", yyvsp[0].str);
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 262:
#line 1926 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 263:
#line 1928 "fgl.yacc"
      {
 A4GL_debug ("Real datetime %s to %s\n", yyvsp[-2].str, yyvsp[0].str);
	sprintf (yyval.str, "%d",
		 (atoi (yyvsp[-2].str) * 16) + atoi (yyvsp[0].str));
      }
      break;

    case 264:
#line 1933 "fgl.yacc"
      {
	sprintf (yyval.str, "%d",
		 (atoi (yyvsp[-2].str) * 16) + atoi (yyvsp[0].str));
      }
      break;

    case 265:
#line 1937 "fgl.yacc"
      {
	start_state ("dtime_val", 1);
      }
      break;

    case 266:
#line 1937 "fgl.yacc"
      {
	start_state ("dtime_val", 0);
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 267:
#line 1941 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 268:
#line 1942 "fgl.yacc"
      {
	strcpy (yyval.str, "2");
      }
      break;

    case 269:
#line 1943 "fgl.yacc"
      {
	strcpy (yyval.str, "3");
      }
      break;

    case 270:
#line 1944 "fgl.yacc"
      {
	strcpy (yyval.str, "4");
      }
      break;

    case 271:
#line 1945 "fgl.yacc"
      {
	strcpy (yyval.str, "5");
      }
      break;

    case 272:
#line 1946 "fgl.yacc"
      {
	strcpy (yyval.str, "6");
      }
      break;

    case 273:
#line 1948 "fgl.yacc"
      {
 A4GL_debug ("opt_frac returns %s", yyvsp[0].str);
	sprintf (yyval.str, "%d", atoi (yyvsp[0].str) + 6);
      }
      break;

    case 274:
#line 1953 "fgl.yacc"
      {
	start_state ("dtime_val", 1);
      }
      break;

    case 275:
#line 1953 "fgl.yacc"
      {
 A4GL_debug ("Got end");
	start_state ("dtime_val", 0);
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 276:
#line 1956 "fgl.yacc"
      {
 A4GL_debug ("Nothing in fraction - assume 2");
	strcpy (yyval.str, "2");
      }
      break;

    case 277:
#line 1958 "fgl.yacc"
      {
 A4GL_debug ("Read fraction .. ");
 A4GL_debug ("    %s", yyvsp[-1].str);
	strcpy (yyval.str, yyvsp[-1].str);
      }
      break;

    case 278:
#line 1964 "fgl.yacc"
      {
 A4GL_debug ("Nothing in fraction - assume 2");
	strcpy (yyval.str, "2");
      }
      break;

    case 279:
#line 1966 "fgl.yacc"
      {
 A4GL_debug ("    %s", yyvsp[-1].str);
	strcpy (yyval.str, yyvsp[-1].str);
      }
      break;

    case 280:
#line 1972 "fgl.yacc"
      {
	if (atoi (yyvsp[0].str) > 5)
	  {
	    a4gl_yyerror ("Fraction values are between 0 and 5");
	    YYERROR;
	  }
      }
      break;

    case 281:
#line 1980 "fgl.yacc"
      {
	start_state ("interval_val", 1);
      }
      break;

    case 282:
#line 1980 "fgl.yacc"
      {
	start_state ("interval_val", 0);
	sprintf (yyval.str, "%d",
		 atoi (yyvsp[0].str) * 16 + atoi (yyvsp[-1].str));
      }
      break;

    case 283:
#line 1983 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 284:
#line 1984 "fgl.yacc"
      {
	strcpy (yyval.str, "2");
      }
      break;

    case 285:
#line 1985 "fgl.yacc"
      {
	strcpy (yyval.str, "3");
      }
      break;

    case 286:
#line 1986 "fgl.yacc"
      {
	strcpy (yyval.str, "4");
      }
      break;

    case 287:
#line 1987 "fgl.yacc"
      {
	strcpy (yyval.str, "5");
      }
      break;

    case 288:
#line 1988 "fgl.yacc"
      {
	strcpy (yyval.str, "6");
      }
      break;

    case 289:
#line 1990 "fgl.yacc"
      {
 A4GL_debug ("opt_frac returns %s", yyvsp[0].str);
	sprintf (yyval.str, "%d", atoi (yyvsp[0].str) + 6);
      }
      break;

    case 293:
#line 2011 "fgl.yacc"
      {
	dim_set_name (yyvsp[0].str);
      }
      break;

    case 297:
#line 2020 "fgl.yacc"
      {
	dim_push_type ("char", "1", 0);
      }
      break;

    case 298:
#line 2022 "fgl.yacc"
      {
	dim_push_type ("char", yyvsp[-1].str, 0);
      }
      break;

    case 299:
#line 2024 "fgl.yacc"
      {
	dim_push_type ("char", yyvsp[-1].str, 0);
      }
      break;

    case 300:
#line 2026 "fgl.yacc"
      {
	dim_push_type ("char", yyvsp[-3].str, 0);
      }
      break;

    case 301:
#line 2027 "fgl.yacc"
      {
	dim_push_type ("long", 0, 0);
      }
      break;

    case 302:
#line 2028 "fgl.yacc"
      {
	dim_push_type ("integer", 0, 0);
      }
      break;

    case 303:
#line 2029 "fgl.yacc"
      {
	dim_push_type ("FORM", 0, 0);
      }
      break;

    case 304:
#line 2030 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "%d", 16 * 256 + 2);
	dim_push_type ("fgldecimal", buff, 0);
      }
      break;

    case 305:
#line 2035 "fgl.yacc"
      {

	char buff[256];
	sprintf (buff, "%d", atoi (yyvsp[-1].str) * 256 + 2);
	dim_push_type ("fgldecimal", buff, 0);
      }
      break;

    case 306:
#line 2042 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "%d",
		 atoi (yyvsp[-3].str) * 256 + atoi (yyvsp[-1].str));
	dim_push_type ("fgldecimal", buff, 0);
      }
      break;

    case 307:
#line 2047 "fgl.yacc"
      {
	dim_push_type ("fglmoney", 0, 0);
      }
      break;

    case 308:
#line 2049 "fgl.yacc"
      {
	dim_push_type ("fglmoney", 0, 0);
      }
      break;

    case 309:
#line 2051 "fgl.yacc"
      {
	dim_push_type ("fglmoney", 0, 0);
      }
      break;

    case 310:
#line 2052 "fgl.yacc"
      {
	dim_push_type ("double", 0, 0);
      }
      break;

    case 311:
#line 2053 "fgl.yacc"
      {
	dim_push_type ("float", 0, 0);
      }
      break;

    case 312:
#line 2054 "fgl.yacc"
      {
	dim_push_type ("fgldate", 0, 0);
      }
      break;

    case 313:
#line 2055 "fgl.yacc"
      {
	dim_push_type ("fglbyte", 0, 0);
      }
      break;

    case 314:
#line 2056 "fgl.yacc"
      {
	dim_push_type ("fgltext", 0, 0);
      }
      break;

    case 315:
#line 2057 "fgl.yacc"
      {
	dim_push_type ("struct_dtime", yyvsp[0].str, 0);
      }
      break;

    case 316:
#line 2060 "fgl.yacc"
      {
	dim_push_type ("struct_ival", 0, 0);
      }
      break;

    case 317:
#line 2062 "fgl.yacc"
      {
	dim_push_like (yyvsp[0].str);
 A4GL_lex_printcomment ("/*added(XXXXX)\n */");
      }
      break;

    case 318:
#line 2068 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*column like(ZZZ)\n*/");
	sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str);
 A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");
      }
      break;

    case 319:
#line 2076 "fgl.yacc"
      {
	dim_push_type (0, 0, yyvsp[-1].str);
      }
      break;

    case 321:
#line 2084 "fgl.yacc"
      {
	dim_push_associate (yyvsp[-5].str, yyvsp[-1].str);
	dim_push_type (0, 0, yyvsp[-1].str);
      }
      break;

    case 322:
#line 2088 "fgl.yacc"
      {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate (0);
      }
      break;

    case 323:
#line 2096 "fgl.yacc"
      {
	dim_push_record ();
      }
      break;

    case 324:
#line 2097 "fgl.yacc"
      {
	dim_pop_record ();
      }
      break;

    case 325:
#line 2098 "fgl.yacc"
      {
	dim_push_record ();
 A4GL_debug ("Like\n");
      }
      break;

    case 326:
#line 2099 "fgl.yacc"
      {
 A4GL_debug ("Table:%s\n", yyvsp[-2].str);
	dim_push_rectab (yyvsp[-2].str);
	dim_pop_record ();
      }
      break;

    case 332:
#line 2118 "fgl.yacc"
      {
	dim_push_name (yyval.str, 0);
      }
      break;

    case 333:
#line 2130 "fgl.yacc"
      {
	print_display_line ();
	strcpy (yyval.str, A4GL_get_display_str (0, 0, 0));
      }
      break;

    case 334:
#line 2134 "fgl.yacc"
      {
	strcpy (yyval.str, A4GL_get_display_str (1, 0, 0));	/* FIXME */
      }
      break;

    case 335:
#line 2137 "fgl.yacc"
      {
	strcpy (yyval.str, "#error not implemented yet");
      }
      break;

    case 336:
#line 2140 "fgl.yacc"
      {
	strcpy (yyval.str, A4GL_get_display_str (4, 0, 0));
      }
      break;

    case 337:
#line 2141 "fgl.yacc"
      {
	strcpy (yyval.str, A4GL_get_display_str (2, yyvsp[0].str, 0));
      }
      break;

    case 338:
#line 2142 "fgl.yacc"
      {
	strcpy (yyval.str, A4GL_get_display_str (3, yyvsp[0].str, yyvsp[-2].str));
      }
      break;

    case 339:
#line 2143 "fgl.yacc"
      {
	strcpy (yyval.str, A4GL_get_display_str (5, yyvsp[-1].str, 0));
      }
      break;

    case 340:
#line 2144 "fgl.yacc"
      {
	strcpy (yyval.str, "#error not implemented yet");
      }
      break;

    case 341:
#line 2150 "fgl.yacc"
      {
	print_display_by_name (yyvsp[0].str);
      }
      break;

    case 342:
#line 2157 "fgl.yacc"
      {
	print_display (yyvsp[-1].str, yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 343:
#line 2162 "fgl.yacc"
      {
	print_display_form (yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 344:
#line 2167 "fgl.yacc"
      {
	push_blockcommand ("DISPLAY");
      }
      break;

    case 345:
#line 2171 "fgl.yacc"
      {
	print_display_array_p1 (yyvsp[-6].str, yyvsp[-4].str, yyvsp[-1].str,
				yyvsp[0].str);
      }
      break;

    case 346:
#line 2174 "fgl.yacc"
      {
	add_continue_blockcommand ("DISPLAY");
	print_display_array_p2 ();
	pop_blockcommand ("DISPLAY");
      }
      break;

    case 347:
#line 2182 "fgl.yacc"
      {
	strcpy (yyval.str, "0,0");
      }
      break;

    case 348:
#line 2184 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 349:
#line 2189 "fgl.yacc"
      {
	sprintf (yyval.str, "0x%lx", atol (yyvsp[0].str));
      }
      break;

    case 354:
#line 2201 "fgl.yacc"
      {
	print_befaft_field_1 ("AFT_ROW");
      }
      break;

    case 355:
#line 2204 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 356:
#line 2207 "fgl.yacc"
      {
	print_befaft_field_1 ("BEF_ROW");
      }
      break;

    case 357:
#line 2210 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 358:
#line 2213 "fgl.yacc"
      {
	print_onkey_1 (yyvsp[0].str);
      }
      break;

    case 359:
#line 2216 "fgl.yacc"
      {
	print_onkey_2 ();
      }
      break;

    case 360:
#line 2229 "fgl.yacc"
      {
	print_error (yyvsp[0].str, 0);
      }
      break;

    case 361:
#line 2232 "fgl.yacc"
      {
	print_error (yyvsp[-1].str, 1);
      }
      break;

    case 362:
#line 2247 "fgl.yacc"
      {
	if (in_command ("WHILE"))
	  {
	    exit_loop ("WHILE");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 363:
#line 2249 "fgl.yacc"
      {
	if (in_command ("INPUT"))
	  {
	    exit_loop ("INPUT");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 364:
#line 2251 "fgl.yacc"
      {
	if (in_command ("FOREACH"))
	  {
	    exit_loop ("FOREACH");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 365:
#line 2253 "fgl.yacc"
      {
	if (in_command ("FOR"))
	  {
	    exit_loop ("FOR");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 366:
#line 2255 "fgl.yacc"
      {
	if (in_command ("CONSTRUCT"))
	  {
	    exit_loop ("CONSTRUCT");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 367:
#line 2257 "fgl.yacc"
      {
	if (in_command ("DISPLAY"))
	  {
	    exit_loop ("DISPLAY");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 368:
#line 2258 "fgl.yacc"
      {
	if (in_command ("MENU"))
	  {
	    exit_loop ("MENU");
	    /* lex_printc("cmd_no=-3;continue;\n"); */
	  }
	else
	  YYERROR;
      }
      break;

    case 369:
#line 2265 "fgl.yacc"
      {
	if (in_command ("CASE"))
	  {
	    exit_loop ("CASE");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 370:
#line 2267 "fgl.yacc"
      {
	if (in_command ("PROMPT"))
	  {
	    exit_loop ("PROMPT");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 371:
#line 2271 "fgl.yacc"
      {
	if (in_command ("WHILE"))
	  {
	    continue_loop ("WHILE");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 372:
#line 2273 "fgl.yacc"
      {
	if (in_command ("INPUT"))
	  {
	    continue_loop ("INPUT");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 373:
#line 2275 "fgl.yacc"
      {
	if (in_command ("FOREACH"))
	  {
	    continue_loop ("FOREACH");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 374:
#line 2277 "fgl.yacc"
      {
	if (in_command ("FOR"))
	  {
	    continue_loop ("FOR");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 375:
#line 2279 "fgl.yacc"
      {
	if (in_command ("CONSTRUCT"))
	  {
	    continue_loop ("CONSTRUCT");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 376:
#line 2281 "fgl.yacc"
      {
	if (in_command ("DISPLAY"))
	  {
	    continue_loop ("DISPLAY");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 377:
#line 2283 "fgl.yacc"
      {
	if (in_command ("MENU"))
	  {
	    continue_loop ("MENU");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 378:
#line 2289 "fgl.yacc"
      {
	if (in_command ("PROMPT"))
	  {
	    continue_loop ("PROMPT");
	  }
	else
	  {
	    YYERROR;
	  }
      }
      break;

    case 379:
#line 2303 "fgl.yacc"
      {
	print_exit_program (0);
      }
      break;

    case 380:
#line 2306 "fgl.yacc"
      {
	print_exit_program (1);
      }
      break;

    case 385:
#line 2323 "fgl.yacc"
      {
	dec_counter ();
	yyval.ptr = append_expr_expr (yyvsp[-1].ptr, yyvsp[0].ptr);
      }
      break;

    case 388:
#line 2329 "fgl.yacc"
      {
 A4GL_debug ("Got literal ptr=%p", yyvsp[0].ptr);
      }
      break;

    case 389:
#line 2333 "fgl.yacc"
      {
	yyval.ptr = new_expr ("push_int(0);");
	yyval.ptr = append_expr_expr (yyval.ptr, yyvsp[0].ptr);
	yyval.ptr = append_expr (yyval.ptr, "pushop(OP_SUB);");
      }
      break;

    case 390:
#line 2338 "fgl.yacc"
      {
	yyval.ptr = yyvsp[0].ptr;
      }
      break;

    case 394:
#line 2348 "fgl.yacc"
      {
	yyval.ptr = new_expr ("add_spaces();");
      }
      break;

    case 401:
#line 2359 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 402:
#line 2359 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 404:
#line 2364 "fgl.yacc"
      {
	yyval.ptr = new_expr ("push_null()");
      }
      break;

    case 405:
#line 2368 "fgl.yacc"
      {
	/*set_counter(0); */
	sprintf (yyval.str, "%d", get_counter_val ());
 A4GL_lex_printcomment ("/*L1 %s*/\n", yyval.str);
      }
      break;

    case 406:
#line 2374 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
 A4GL_lex_printcomment ("/*L2 %s*/\n", yyval.str);
      }
      break;

    case 407:
#line 2382 "fgl.yacc"
      {
	/*set_counter(0); */
	sprintf (yyval.str, "%d", get_counter_val ());
 A4GL_lex_printcomment ("/*L1 %s*/\n", yyval.str);
      }
      break;

    case 408:
#line 2388 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
 A4GL_lex_printcomment ("/*L2 %s*/\n", yyval.str);
      }
      break;

    case 409:
#line 2397 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
      }
      break;

    case 410:
#line 2399 "fgl.yacc"
      {
	print_op ("OP_CONCAT");
	dec_counter ();
	sprintf (yyval.str, "%d", get_counter_val ());
      }
      break;

    case 411:
#line 2406 "fgl.yacc"
      {
 A4GL_debug ("Print expr (2)");
	print_expr (yyvsp[0].ptr);
      }
      break;

    case 412:
#line 2414 "fgl.yacc"
      {
	strcpy (yyval.str, "+");
      }
      break;

    case 413:
#line 2418 "fgl.yacc"
      {
	strcpy (yyval.str, "-");
      }
      break;

    case 414:
#line 2427 "fgl.yacc"
      {

	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_NOT);");
      }
      break;

    case 415:
#line 2432 "fgl.yacc"
      {
	yyval.ptr = new_expr ("push_int(1);");
	inc_counter ();
      }
      break;

    case 416:
#line 2437 "fgl.yacc"
      {
	inc_counter ();
	yyval.ptr = new_expr ("push_int(0);");
      }
      break;

    case 417:
#line 2441 "fgl.yacc"
      {
	yyval.ptr = yyvsp[-1].ptr;
      }
      break;

    case 418:
#line 2443 "fgl.yacc"
      {
	char buff[256];
	int n;
	yyval.ptr = new_expr (yyvsp[-1].sql_string);
	append_expr (yyval.ptr, "{");
	n = print_bind_expr (yyval.ptr, 'i');
	sprintf (buff, "push_binding(ibind,%d);}", n);
	append_expr (yyval.ptr, buff);
	append_expr (yyval.ptr, "pushop(OP_EXISTS);");
      }
      break;

    case 419:
#line 2453 "fgl.yacc"
      {
	char buff[256];
	int n;
	yyval.ptr = new_expr (yyvsp[-1].sql_string);
	append_expr (yyval.ptr, "{");
	n = print_bind_expr (yyval.ptr, 'i');
	sprintf (buff, "push_binding(ibind,%d);}", n);
	append_expr (yyval.ptr, buff);
	append_expr (yyval.ptr, "pushop(OP_NOTEXISTS);");
      }
      break;

    case 420:
#line 2467 "fgl.yacc"
      {
 A4GL_debug ("init expr %s %s", yyvsp[-1].str, yyvsp[0].str);
	sprintf (yyval.str, "%s%p", yyvsp[-1].str, yyvsp[0].str);
	sprintf (yyval.str, "%s", A4GL_get_push_literal ('D', yyval.str));
	yyval.ptr = new_expr (yyval.str);
	inc_counter ();
      }
      break;

    case 421:
#line 2475 "fgl.yacc"
      {
 A4GL_debug ("init expr int %s %d", yyvsp[-1].str, atoi (yyvsp[0].str));
	sprintf (yyval.str, "%s%p", yyvsp[-1].str, yyvsp[0].str);
	sprintf (yyval.str, "%s", A4GL_get_push_literal ('L', yyval.str));
	yyval.ptr = new_expr (yyval.str);
	inc_counter ();
      }
      break;

    case 422:
#line 2487 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", A4GL_get_push_literal ('S', yyvsp[0].str));
	yyval.ptr = new_expr (yyval.str);
	inc_counter ();
      }
      break;

    case 423:
#line 2493 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", A4GL_get_push_literal ('D', yyvsp[0].str));
	yyval.ptr = new_expr (yyval.str);
	inc_counter ();
      }
      break;

    case 424:
#line 2499 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", A4GL_get_push_literal ('L', yyvsp[0].str));
	yyval.ptr = new_expr (yyval.str);
	inc_counter ();
      }
      break;

    case 427:
#line 2509 "fgl.yacc"
      {
	sprintf (yyval.str, "%s\n%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 428:
#line 2515 "fgl.yacc"
      {
	int a;
	int incvcnt;
	int flg = 0;
	void *p1;

	if (strchr (yyvsp[0].str, '\n') == 0)
	  {
	    //printf("Finding %s",$<str>1);
	    a = scan_variable (yyvsp[0].str);
	    //printf(" a=%d\n",a);
	  }
	else
	  {
	    printf ("Its a thru - setting a to -2\n");
	    a = -2;
	  }

	if (a >= 0)
	  {
	    if (A4GL_aubit_strcasecmp (yyvsp[0].str, "today") == 0)
	      {
		flg = 1;
		strcpy (yyval.str, "push_today();");
	      }

	    if (A4GL_aubit_strcasecmp (yyvsp[0].str, "time") == 0)
	      {
		flg = 1;
		strcpy (yyval.str, "push_time();");
	      }

	    if (A4GL_aubit_strcasecmp (yyvsp[0].str, "pageno") == 0)
	      {
		flg = 1;
		strcpy (yyval.str, "push_variable(&rep.page_no,2);");
	      }
	    if (A4GL_aubit_strcasecmp (yyvsp[0].str, "lineno") == 0)
	      {
		flg = 1;
		strcpy (yyval.str, "push_variable(&rep.line_no,2);");
	      }

	    if (flg == 0)
	      {
		sprintf (yyval.str, "push_variable(&%s,0x%x);", yyvsp[0].str,
			 (int) scan_variable (yyvsp[0].str));
	      }
	    p1 = new_expr (yyval.str);
	    yyval.ptr = p1;
	    inc_counter ();
	  }



	if (a == -1)
	  {
	    sprintf (yyval.str, "push_char(%s);", yyvsp[0].str);
	    inc_counter ();
	    p1 = new_expr (yyval.str);
	    yyval.ptr = p1;
	    inc_counter ();
	  }


	if (a == -2)
	  {
	    p1 = new_expr ("");
	    incvcnt = print_push_rec (yyvsp[0].str, &p1);
	    inc_counter_by (incvcnt);
	    yyval.ptr = p1;
	  }




      }
      break;

    case 429:
#line 2587 "fgl.yacc"
      {
	sprintf (yyval.str, "%sset_column(&rep);", ispdf ());
	yyval.ptr = append_expr (yyvsp[0].ptr, yyval.str);
      }
      break;

    case 430:
#line 2593 "fgl.yacc"
      {
	sprintf (yyval.str, "%sset_column(&rep);", ispdf ());
	yyval.ptr = append_expr (yyvsp[0].ptr, yyval.str);
      }
      break;

    case 431:
#line 2597 "fgl.yacc"
      {
	if (!in_command ("REPORT"))
	  {
	    a4gl_yyerror ("This can only be done in a report!");
	    YYERROR;
	  }
	insql = 0;
	yyval.ptr = new_expr (yyvsp[0].str);
      }
      break;

    case 432:
#line 2605 "fgl.yacc"
      {
	insql = 1;
	set_ingroup ();
      }
      break;

    case 433:
#line 2605 "fgl.yacc"
      {
	char buff[256];
	if (!in_command ("REPORT"))
	  {
	    a4gl_yyerror ("This can only be done in a report!");
	    YYERROR;
	  }
	insql = 0;
 A4GL_lex_printcomment ("/* rep_Agg = %s\n*/", yyvsp[0].str);
	strcpy (buff, yyvsp[0].str);
 A4GL_debug ("report aggregate :  %s", buff);
	yyval.ptr = new_expr (buff);
      }
      break;

    case 434:
#line 2621 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_AND);");
      }
      break;

    case 435:
#line 2625 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_OR);");
      }
      break;

    case 436:
#line 2631 "fgl.yacc"
      {
	yyval.ptr = yyvsp[0].ptr;
      }
      break;

    case 437:
#line 2634 "fgl.yacc"
      {
 A4GL_debug ("Adding to list...");
	yyval.ptr = append_expr_expr (yyvsp[-2].ptr, yyvsp[0].ptr);
      }
      break;

    case 438:
#line 2642 "fgl.yacc"
      {
	char buff[256];
	int n;
	yyval.ptr = new_expr (yyvsp[-1].sql_string);
	append_expr (yyval.ptr, "{");
	n = print_bind_expr (yyval.ptr, 'i');
	sprintf (buff, "push_binding(ibind,%d);}", n);
	append_expr (yyval.ptr, buff);
	append_expr (yyval.ptr, "pushop(OP_IN_SELECT);");
      }
      break;

    case 439:
#line 2653 "fgl.yacc"
      {
	char buff[256];
	int n;
	yyval.ptr = new_expr (yyvsp[-1].sql_string);
	append_expr (yyval.ptr, "{");
	n = print_bind_expr (yyval.ptr, 'i');
	sprintf (buff, "push_binding(ibind,%d);}", n);
	append_expr (yyval.ptr, buff);
	append_expr (yyval.ptr, "pushop(OP_NOTIN_SELECT);");
      }
      break;

    case 440:
#line 2663 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "push_int(%d);", length_expr (yyvsp[-1].ptr));
	yyval.ptr = append_expr (yyvsp[-1].ptr, buff);
	append_expr (yyval.ptr, "pushop(OP_IN);");
      }
      break;

    case 441:
#line 2669 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "push_int(%d);", length_expr (yyvsp[-1].ptr));
	yyval.ptr = append_expr (yyvsp[-1].ptr, buff);
	append_expr (yyval.ptr, "pushop(OP_NOTIN);");
      }
      break;

    case 442:
#line 2679 "fgl.yacc"
      {
	strcpy (yyval.str, "pushop(OP_ISNULL);");
	yyval.ptr = new_expr (yyval.str);
      }
      break;

    case 443:
#line 2684 "fgl.yacc"
      {
	strcpy (yyval.str, "pushop(OP_ISNOTNULL);");
	yyval.ptr = new_expr (yyval.str);
      }
      break;

    case 444:
#line 2691 "fgl.yacc"
      {
	yyval.ptr =
	  append_expr (yyvsp[0].ptr,
		       "push_char(\"\\\\\");pushop(OP_MATCHES);");
      }
      break;

    case 445:
#line 2694 "fgl.yacc"
      {
	yyval.ptr =
	  append_expr (yyvsp[0].ptr,
		       "push_char(\"\\\\\");pushop(OP_MATCHES);pushop(OP_NOT);");
      }
      break;

    case 446:
#line 2697 "fgl.yacc"
      {
	char buff[40];
	sprintf (buff, "push_char(%s);pushop(OP_MATCHES);", yyvsp[0].str);
	yyval.ptr = append_expr (yyvsp[-2].ptr, buff);
      }
      break;

    case 447:
#line 2702 "fgl.yacc"
      {
	char buff[40];
	sprintf (buff, "push_char(%s);pushop(OP_MATCHES);pushop(OP_NOT);",
		 yyvsp[0].str);
	yyval.ptr = append_expr (yyvsp[-2].ptr, buff);
      }
      break;

    case 448:
#line 2709 "fgl.yacc"
      {
	char buff[40];
	sprintf (buff, "push_char(\"\\\\\");pushop(OP_LIKE);");
	yyval.ptr = append_expr (yyvsp[0].ptr, buff);
      }
      break;

    case 449:
#line 2714 "fgl.yacc"
      {
	char buff[40];
	sprintf (buff, "push_char(\"\\\\\");pushop(OP_LIKE);pushop(OP_NOT);");
	yyval.ptr = append_expr (yyvsp[0].ptr, buff);
      }
      break;

    case 450:
#line 2719 "fgl.yacc"
      {
	char buff[40];
	sprintf (buff, "push_char(%s);pushop(OP_LIKE);", yyvsp[0].str);
	yyval.ptr = append_expr (yyvsp[-2].ptr, buff);
      }
      break;

    case 451:
#line 2724 "fgl.yacc"
      {
	char buff[40];
	sprintf (buff, "push_char(%s);pushop(OP_LIKE);pushop(OP_NOT);",
		 yyvsp[0].str);
	yyval.ptr = append_expr (yyvsp[-2].ptr, buff);
      }
      break;

    case 452:
#line 2735 "fgl.yacc"
      {
	strcpy (yyval.str, "pushop(OP_CLIP);");
	yyval.ptr = new_expr (yyval.str);
	inc_counter ();
      }
      break;

    case 453:
#line 2743 "fgl.yacc"
      {
	sprintf (yyval.str, "%s pushop(OP_USING);", yyvsp[0].str);
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_USING);");
      }
      break;

    case 454:
#line 2751 "fgl.yacc"
      {
 A4GL_debug ("PLUS in math_expr $<ptr>2 = %p", yyvsp[0].ptr);
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_ADD);");
      }
      break;

    case 455:
#line 2756 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_SUB);");
      }
      break;

    case 456:
#line 2760 "fgl.yacc"
      {
	sprintf (yyval.str, "%s pushop(OP_MULT);", yyvsp[0].str);
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_MULT);");
      }
      break;

    case 457:
#line 2765 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_DIV);");
      }
      break;

    case 458:
#line 2769 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_MOD);");
      }
      break;

    case 459:
#line 2773 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_POWER);");
      }
      break;

    case 460:
#line 2779 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_EQUAL);");
      }
      break;

    case 461:
#line 2782 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_EQUAL);");
      }
      break;

    case 462:
#line 2786 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_LESS_THAN);");
      }
      break;

    case 463:
#line 2790 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_GREATER_THAN);");
      }
      break;

    case 464:
#line 2794 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_NOT_EQUAL);");
      }
      break;

    case 465:
#line 2798 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_LESS_THAN_EQ);");
      }
      break;

    case 466:
#line 2802 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "pushop(OP_GREATER_THAN_EQ);");
      }
      break;

    case 467:
#line 2809 "fgl.yacc"
      {
	reset_counter ();
      }
      break;

    case 468:
#line 2819 "fgl.yacc"
      {
	addmap ("Call", yyvsp[-1].str, curr_func, yylineno, infilename);
	new_counter ();
      }
      break;

    case 469:
#line 2824 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
 A4GL_lex_printcomment ("/*function_call_expr2 %s*/\n", yyval.str);
	drop_counter ();
      }
      break;

    case 470:
#line 2830 "fgl.yacc"
      {
	int cnt;
	cnt = 1;
 A4GL_debug ("Print expr (1)");
	/* print_expr($<ptr>4); */

	strcpy (yyval.str,
	 A4GL_expr_for_call (yyvsp[-5].str, yyvsp[-1].str, lastlineno,
			       infilename));
	yyval.ptr = append_expr (yyvsp[-2].ptr, yyval.str);
	inc_counter ();
      }
      break;

    case 471:
#line 2840 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\",\"%s\"", yyvsp[-3].str, yyvsp[-1].str);
 A4GL_debug ("NEWFORMAT : %s\n", yyval.str);
	A4GLSQL_set_status (0, 0);
	new_counter ();
      }
      break;

    case 472:
#line 2845 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
	drop_counter ();
      }
      break;

    case 473:
#line 2848 "fgl.yacc"
      {
	char buff[256];
	char *ptr;
	strcpy (buff, yyvsp[-3].str);
	ptr = strchr (buff, ',');
	*ptr = 0;
	ptr++;
	sprintf (yyval.str,
		 "{int _retvars;\n_retvars=call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");pop_args(_retvars);push_null();}\n}\n}\n",
		 buff, ptr, atoi (yyvsp[-1].str), lastlineno, infilename);
	yyval.ptr = append_expr (yyvsp[-2].ptr, yyval.str);
      }
      break;

    case 474:
#line 2862 "fgl.yacc"
      {
	inc_counter ();
	chk4var = 1;
      }
      break;

    case 475:
#line 2862 "fgl.yacc"
      {
	chk4var = 0;
      }
      break;

    case 476:
#line 2862 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[-2].ptr, "aclfgl_date(1);");
	inc_counter ();
      }
      break;

    case 477:
#line 2865 "fgl.yacc"
      {
	inc_counter ();
	chk4var = 1;
      }
      break;

    case 478:
#line 2865 "fgl.yacc"
      {
	chk4var = 0;
      }
      break;

    case 479:
#line 2865 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[-2].ptr, "aclfgl_month(1);");
	inc_counter ();
      }
      break;

    case 480:
#line 2868 "fgl.yacc"
      {
	inc_counter ();
	chk4var = 1;
      }
      break;

    case 481:
#line 2868 "fgl.yacc"
      {
	chk4var = 0;
      }
      break;

    case 482:
#line 2868 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[-2].ptr, "aclfgl_day(1);");
	inc_counter ();
      }
      break;

    case 483:
#line 2871 "fgl.yacc"
      {
	inc_counter ();
	chk4var = 1;
      }
      break;

    case 484:
#line 2871 "fgl.yacc"
      {
	chk4var = 0;
      }
      break;

    case 485:
#line 2871 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[-2].ptr, "aclfgl_year(1);");
	inc_counter ();
      }
      break;

    case 486:
#line 2874 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "acli_interval(%s,%s);", yyvsp[-2].str, yyvsp[0].str);
	yyval.ptr = new_expr (buff);
	inc_counter ();
      }
      break;

    case 487:
#line 2880 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "acli_datetime(%s,%s);", yyvsp[-2].str, yyvsp[0].str);
	yyval.ptr = new_expr (buff);
	inc_counter ();
      }
      break;

    case 488:
#line 2886 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "acli_datetime(\"%s\",%s);", yyvsp[-2].str,
		 yyvsp[0].str);
	yyval.ptr = new_expr (buff);
	inc_counter ();
      }
      break;

    case 489:
#line 2892 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "acli_datetime(\"%s:%s\",%s);", yyvsp[-4].str,
		 yyvsp[-2].str, yyvsp[0].str);
	yyval.ptr = new_expr (buff);
	inc_counter ();
      }
      break;

    case 490:
#line 2902 "fgl.yacc"
      {
	strcpy (yyval.str, "-1,-1");
      }
      break;

    case 491:
#line 2903 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 494:
#line 2911 "fgl.yacc"
      {
	sprintf (yyval.str,
		 "{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
		 yyvsp[-1].str, lastlineno, infilename);
	yyval.ptr = new_expr (yyval.str);

      }
      break;

    case 495:
#line 2917 "fgl.yacc"
      {
	sprintf (yyval.str, "push_int(fgl_fieldnametoid(\"\",%s));",
		 yyvsp[-1].str);
	yyval.ptr = new_expr (yyval.str);
      }
      break;

    case 496:
#line 2918 "fgl.yacc"
      {
	sprintf (yyval.str, "push_int(fgl_fieldnametoid(\"\",%s));",
		 yyvsp[-1].str);
	yyval.ptr = new_expr (yyval.str);
	addmap ("Get Field", yyvsp[-1].str, curr_func, yylineno, infilename);
      }
      break;

    case 497:
#line 2923 "fgl.yacc"
      {
	sprintf (yyval.str, "push_int(fgl_infield(%s));", yyvsp[-1].str);
	yyval.ptr = new_expr (yyval.str);
      }
      break;

    case 498:
#line 2927 "fgl.yacc"
      {
	sprintf (yyval.str, "push_int(fgl_fieldtouched(%s,0,0));",
		 yyvsp[-1].str);
	yyval.ptr = new_expr (yyval.str);
      }
      break;

    case 499:
#line 2931 "fgl.yacc"
      {
	sprintf (yyval.str, "push_int(!fgl_fieldtouched(%s,0,0));",
		 yyvsp[-1].str);
	yyval.ptr = new_expr (yyval.str);
      }
      break;

    case 502:
#line 2938 "fgl.yacc"
      {
	inc_counter ();
	sprintf (yyval.str, "push_current(%s);", yyvsp[0].str);
	yyval.ptr = new_expr (yyval.str);
      }
      break;

    case 503:
#line 2943 "fgl.yacc"
      {
	inc_counter ();
	strcpy (yyval.str, "push_today();");
	yyval.ptr = new_expr (yyval.str);
      }
      break;

    case 504:
#line 2950 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[-1].ptr, "upshift_stk();");
      }
      break;

    case 505:
#line 2954 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[-1].ptr, "downshift_stk();");
      }
      break;

    case 506:
#line 2957 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "push_ascii();");
      }
      break;

    case 507:
#line 2960 "fgl.yacc"
      {
	yyval.ptr = append_expr (yyvsp[0].ptr, "aclfgli_extend();");
      }
      break;

    case 508:
#line 2966 "fgl.yacc"
      {
	yyval.ptr =
	  append_expr (yyvsp[-1].ptr, "push_double(-1);pushop(OP_MULT);");
      }
      break;

    case 509:
#line 2969 "fgl.yacc"
      {
	yyval.ptr =
	  append_expr (yyvsp[-1].ptr,
		       "push_double(-28.3465);pushop(OP_MULT);");
      }
      break;

    case 510:
#line 2972 "fgl.yacc"
      {
	yyval.ptr =
	  append_expr (yyvsp[-1].ptr, "push_double(-72.0);pushop(OP_MULT);");
      }
      break;

    case 511:
#line 2987 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 512:
#line 2990 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 513:
#line 2996 "fgl.yacc"
      {
	sprintf (yyval.str, "-%s", yyvsp[0].str);
      }
      break;

    case 514:
#line 2997 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 515:
#line 2998 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 517:
#line 3003 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 518:
#line 3004 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s:%s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[0].str);
      }
      break;

    case 519:
#line 3005 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s:%s:%s", yyvsp[-5].str, yyvsp[-4].str,
		 yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 520:
#line 3006 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s:%s:%s", yyvsp[-5].str, yyvsp[-4].str,
		 yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 521:
#line 3008 "fgl.yacc"
      {
	sprintf (yyval.str, "%s:%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 522:
#line 3009 "fgl.yacc"
      {
	sprintf (yyval.str, "%s:%s:%s", yyvsp[-4].str, yyvsp[-2].str,
		 yyvsp[0].str);
      }
      break;

    case 523:
#line 3010 "fgl.yacc"
      {
	sprintf (yyval.str, "%s:%s:%s", yyvsp[-4].str, yyvsp[-2].str,
		 yyvsp[0].str);
      }
      break;

    case 524:
#line 3012 "fgl.yacc"
      {
	sprintf (yyval.str, "%s:%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 525:
#line 3013 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 527:
#line 3019 "fgl.yacc"
      {
	sprintf (yyval.str, "%s-%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 529:
#line 3024 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 530:
#line 3036 "fgl.yacc"
      {
	print_for_start (yyvsp[-5].str);
	push_blockcommand ("FOR");
      }
      break;

    case 531:
#line 3040 "fgl.yacc"
      {
 A4GL_debug ("For_cmds\n");
      }
      break;

    case 532:
#line 3041 "fgl.yacc"
      {

	pop_blockcommand ("FOR");
	print_for_end ();
 A4GL_lex_printcomment (" /*END FOR*/\n");
      }
      break;

    case 533:
#line 3048 "fgl.yacc"
      {
	print_for_default_step ();
      }
      break;

    case 535:
#line 3065 "fgl.yacc"
      {
	push_blockcommand ("FOREACH");
      }
      break;

    case 536:
#line 3069 "fgl.yacc"
      {
	print_foreach_start ();
 A4GL_lex_printcomment (" /* foreach */\n");
      }
      break;

    case 537:
#line 3074 "fgl.yacc"
      {
	print_foreach_next (yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 538:
#line 3078 "fgl.yacc"
      {
	add_continue_blockcommand ("FOREACH");
	print_foreach_end ();
	pop_blockcommand ("FOREACH");
      }
      break;

    case 539:
#line 3094 "fgl.yacc"
      {
	sprintf (curr_func, "%s", yyvsp[0].str);
	print_formhandler (yyvsp[0].str);
	start_state ("formhandler", 1);
	push_blockcommand ("FORMHANDLER");
      }
      break;

    case 540:
#line 3100 "fgl.yacc"
      {
	print_variables ();
	print_getwin ();
      }
      break;

    case 541:
#line 3108 "fgl.yacc"
      {
	pop_blockcommand ("FORMHANDLER");
	print_end_formhandler ();
	start_state ("formhandler", 0);
      }
      break;

    case 548:
#line 3125 "fgl.yacc"
      {
	print_event ('B');
      }
      break;

    case 549:
#line 3127 "fgl.yacc"
      {
	print_event_2 ();
      }
      break;

    case 550:
#line 3130 "fgl.yacc"
      {
	print_event ('b');
      }
      break;

    case 551:
#line 3132 "fgl.yacc"
      {
	print_event_2 ();
      }
      break;

    case 556:
#line 3146 "fgl.yacc"
      {
	print_event ('A');
      }
      break;

    case 557:
#line 3148 "fgl.yacc"
      {
	print_event_2 ();
      }
      break;

    case 558:
#line 3151 "fgl.yacc"
      {
	print_event ('a');
      }
      break;

    case 559:
#line 3153 "fgl.yacc"
      {
	print_event_2 ();
      }
      break;

    case 572:
#line 3184 "fgl.yacc"
      {
	print_gtk_field ('B', 0);
      }
      break;

    case 573:
#line 3186 "fgl.yacc"
      {
	print_gtk_field_2 ();
      }
      break;

    case 574:
#line 3189 "fgl.yacc"
      {
	print_gtk_field ('A', 0);
      }
      break;

    case 575:
#line 3191 "fgl.yacc"
      {
	print_gtk_field_2 ();
      }
      break;

    case 576:
#line 3194 "fgl.yacc"
      {
	print_gtk_field ('b', yyvsp[0].str);
      }
      break;

    case 577:
#line 3196 "fgl.yacc"
      {
	print_gtk_field_2 ();
      }
      break;

    case 578:
#line 3199 "fgl.yacc"
      {
	print_gtk_field ('a', yyvsp[0].str);
      }
      break;

    case 579:
#line 3201 "fgl.yacc"
      {
	print_gtk_field_2 ();
      }
      break;

    case 580:
#line 3204 "fgl.yacc"
      {
	print_gtk_field ('o', yyvsp[0].str);
      }
      break;

    case 581:
#line 3206 "fgl.yacc"
      {
	print_gtk_field_2 ();
      }
      break;

    case 582:
#line 3221 "fgl.yacc"
      {
	//print_niy("Free Cursor");
 A4GL_lex_printcomment (" /* FIXME: Not implemented: Free Cursor */\n");;

	strcpy (yyval.str, "");
      }
      break;

    case 583:
#line 3237 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", -1 - (atoi (yyvsp[0].str)));
      }
      break;

    case 584:
#line 3238 "fgl.yacc"
      {
	strcpy (yyval.str, "-1");
      }
      break;

    case 585:
#line 3239 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", atoi (yyvsp[0].str) + 1);
      }
      break;

    case 586:
#line 3240 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 587:
#line 3241 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 588:
#line 3242 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 592:
#line 3250 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 594:
#line 3256 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\",1", yyvsp[0].str);
      }
      break;

    case 595:
#line 3258 "fgl.yacc"
      {
	sprintf (yyval.str, "int_to_id(%s)", yyvsp[-1].str);
      }
      break;

    case 596:
#line 3259 "fgl.yacc"
      {
	sprintf (yyval.str, "int_to_id(%s.%s)", yyvsp[-5].str, yyvsp[-1].str);
      }
      break;

    case 597:
#line 3261 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\",%s", yyvsp[-3].str, yyvsp[-1].str);
      }
      break;

    case 598:
#line 3263 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.*\",1", yyvsp[-2].str);
      }
      break;

    case 599:
#line 3265 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.*\",%s", yyvsp[-5].str, yyvsp[-3].str);
      }
      break;

    case 600:
#line 3267 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.%s\",1", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 601:
#line 3269 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.%s\",%s", yyvsp[-5].str, yyvsp[0].str,
		 yyvsp[-3].str);
      }
      break;

    case 602:
#line 3272 "fgl.yacc"
      {
	print_pushchar (yyvsp[0].str);
	addmap ("Cursor", last_var, curr_func, yylineno, infilename);
      }
      break;

    case 603:
#line 3279 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 604:
#line 3281 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
	addmap ("Window", last_var, curr_func, yylineno, infilename);
      }
      break;

    case 605:
#line 3287 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
	addmap ("Open Window", last_var, curr_func, yylineno, infilename);
      }
      break;

    case 606:
#line 3292 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
	addmap ("Form", last_var, curr_func, yylineno, infilename);
      }
      break;

    case 607:
#line 3297 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
	addmap ("Open Form", last_var, curr_func, yylineno, infilename);
      }
      break;

    case 608:
#line 3302 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 609:
#line 3302 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 610:
#line 3305 "fgl.yacc"
      {
	strcpy (yyval.str, downshift (yyvsp[0].str));
      }
      break;

    case 611:
#line 3311 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 612:
#line 3316 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s_%s\"", clobber, downshift (yyvsp[0].str));
	strcpy (last_var, downshift (yyvsp[0].str));
      }
      break;

    case 613:
#line 3320 "fgl.yacc"
      {
	sprintf (yyval.str, "aclfgli_str_to_id(%s)", yyvsp[-1].str);
	sprintf (last_var, "->%s", yyvsp[-1].str);
      }
      break;

    case 616:
#line 3328 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\",1", yyvsp[0].str);
      }
      break;

    case 617:
#line 3330 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\",%s", yyvsp[-3].str, yyvsp[-1].str);
      }
      break;

    case 618:
#line 3332 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.*\",1", yyvsp[-2].str);
      }
      break;

    case 619:
#line 3334 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.*\",%s", yyvsp[-5].str, yyvsp[-3].str);
      }
      break;

    case 620:
#line 3336 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.%s\",1", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 621:
#line 3338 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s.%s\",%s", yyvsp[-5].str, yyvsp[0].str,
		 yyvsp[-3].str);
      }
      break;

    case 622:
#line 3341 "fgl.yacc"
      {
 A4GL_debug ("Scanvar=%d", scan_variable (yyvsp[0].str) & 15);
	if ((scan_variable (yyvsp[0].str) & 15) != 0)
	  {
	    a4gl_yyerror ("Only a character variable can be used for this");
	    YYERROR;
	  }
      }
      break;

    case 624:
#line 3350 "fgl.yacc"
      {
	sprintf (yyval.str, ".%s", yyvsp[0].str);
      }
      break;

    case 668:
#line 3411 "fgl.yacc"
      {
	char buff[256];
	print_goto (yyvsp[0].str);
      }
      break;

    case 669:
#line 3425 "fgl.yacc"
      {
	print_gui_do_menuitems (yyvsp[0].str, 'C');
      }
      break;

    case 671:
#line 3432 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 672:
#line 3435 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 673:
#line 3441 "fgl.yacc"
      {
	print_gui_do_menuitems (yyvsp[0].str, 'U');
      }
      break;

    case 674:
#line 3447 "fgl.yacc"
      {
	print_gui_do_menuitems (yyvsp[0].str, 'D');
      }
      break;

    case 675:
#line 3451 "fgl.yacc"
      {
	print_gui_do_fields (yyvsp[0].str, 'D');
      }
      break;

    case 676:
#line 3455 "fgl.yacc"
      {
	print_gui_do_form (yyvsp[-2].str, yyvsp[0].str, 'D');
      }
      break;

    case 677:
#line 3461 "fgl.yacc"
      {
	print_gui_do_menuitems (yyvsp[0].str, 'E');
      }
      break;

    case 678:
#line 3465 "fgl.yacc"
      {
	print_gui_do_fields (yyvsp[0].str, 'E');
      }
      break;

    case 679:
#line 3469 "fgl.yacc"
      {
	print_gui_do_form (yyvsp[-2].str, yyvsp[0].str, 'E');
      }
      break;

    case 680:
#line 3474 "fgl.yacc"
      {
	start_state ("messagebox", 1);
      }
      break;

    case 681:
#line 3479 "fgl.yacc"
      {
	start_state ("messagebox", 0);
      }
      break;

    case 700:
#line 3520 "fgl.yacc"
      {
	print_if_start ();
      }
      break;

    case 701:
#line 3525 "fgl.yacc"
      {
	print_if_end ();
      }
      break;

    case 703:
#line 3530 "fgl.yacc"
      {
	print_if_else ();
      }
      break;

    case 705:
#line 3533 "fgl.yacc"
      {
	print_if_else ();
      }
      break;

    case 706:
#line 3535 "fgl.yacc"
      {

	print_if_start ();
      }
      break;

    case 707:
#line 3538 "fgl.yacc"
      {
	print_if_end ();
      }
      break;

    case 708:
#line 3542 "fgl.yacc"
      {
	print_import (yyvsp[-3].str, atoi (yyvsp[-1].str));
      }
      break;

    case 709:
#line 3545 "fgl.yacc"
      {
	print_import_legacy (yyvsp[0].str);
      }
      break;

    case 710:
#line 3551 "fgl.yacc"
      {
	add_ex_dtype (yyvsp[0].str);
      }
      break;

    case 711:
#line 3562 "fgl.yacc"
      {
 A4GL_debug ("init to\n");
      }
      break;

    case 712:
#line 3563 "fgl.yacc"
      {
	print_init ();
      }
      break;

    case 713:
#line 3566 "fgl.yacc"
      {
	print_init_table (yyvsp[0].str);
      }
      break;

    case 715:
#line 3572 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 716:
#line 3576 "fgl.yacc"
      {
	setrecord (yyval.str, yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 717:
#line 3577 "fgl.yacc"
      {
	setrecord (yyval.str, yyvsp[-2].str, 0);
      }
      break;

    case 720:
#line 3591 "fgl.yacc"
      {
	sprintf (yyval.str, "0");
      }
      break;

    case 721:
#line 3593 "fgl.yacc"
      {
	sprintf (yyval.str, "1");
      }
      break;

    case 724:
#line 3602 "fgl.yacc"
      {
	print_befaft_field_1 (yyvsp[0].str);
      }
      break;

    case 725:
#line 3604 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 726:
#line 3608 "fgl.yacc"
      {
	print_befaft_field_1 (yyvsp[0].str);
      }
      break;

    case 727:
#line 3610 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 728:
#line 3613 "fgl.yacc"
      {
	print_befaft_field_1 ("AFT_ROW");
      }
      break;

    case 729:
#line 3615 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 730:
#line 3618 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* before row */ \n");
	print_befaft_field_1 ("BEF_ROW");
      }
      break;

    case 731:
#line 3621 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 732:
#line 3624 "fgl.yacc"
      {
	print_onkey_1 (yyvsp[0].str);
      }
      break;

    case 733:
#line 3626 "fgl.yacc"
      {
	print_onkey_2 ();
      }
      break;

    case 734:
#line 3629 "fgl.yacc"
      {
	print_befaft_field_1 ("AFTER_INP");
      }
      break;

    case 735:
#line 3631 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 736:
#line 3634 "fgl.yacc"
      {
	print_befaft_field_1 ("BEFORE_INP");
      }
      break;

    case 737:
#line 3636 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 738:
#line 3639 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* before insert/delete */ \n");
	print_befaft_field_1 (yyvsp[0].str);
      }
      break;

    case 739:
#line 3641 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 740:
#line 3644 "fgl.yacc"
      {
	print_befaft_field_1 (yyvsp[0].str);
      }
      break;

    case 741:
#line 3646 "fgl.yacc"
      {
	print_befaft_field_2 ();
      }
      break;

    case 742:
#line 3652 "fgl.yacc"
      {
	sprintf (yyval.str, "(%s)", yyvsp[0].str);
      }
      break;

    case 743:
#line 3653 "fgl.yacc"
      {
	char buff[256];
	sprintf (buff, "(%s)", yyvsp[0].str);
 A4GL_generate_or (yyval.str, yyvsp[-2].str, buff);
      }
      break;

    case 744:
#line 3661 "fgl.yacc"
      {
	strcpy (yyval.str, "AFT_INSERT");
      }
      break;

    case 745:
#line 3662 "fgl.yacc"
      {
	strcpy (yyval.str, "AFT_DELETE");
      }
      break;

    case 746:
#line 3667 "fgl.yacc"
      {
	sprintf (yyval.str, "(%s)", yyvsp[0].str);
      }
      break;

    case 747:
#line 3668 "fgl.yacc"
      {
	char buff[80];
	sprintf (buff, "(%s)", yyvsp[0].str);
 A4GL_generate_or (yyval.str, yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 748:
#line 3677 "fgl.yacc"
      {
	strcpy (yyval.str, "BEF_INSERT");
      }
      break;

    case 749:
#line 3678 "fgl.yacc"
      {
	strcpy (yyval.str, "BEF_DELETE");
      }
      break;

    case 750:
#line 3685 "fgl.yacc"
      {
	sprintf (yyval.str, "BEF_FIELD_CHK(%s)", yyvsp[0].str);
      }
      break;

    case 751:
#line 3686 "fgl.yacc"
      {
	char buff[80];
	sprintf (buff, "BEF_FIELD_CHK(%s)", yyvsp[0].str);
 A4GL_generate_or (yyval.str, yyvsp[-2].str, buff);
      }
      break;

    case 752:
#line 3694 "fgl.yacc"
      {
	sprintf (yyval.str, "AFT_FIELD_CHK(%s)", yyvsp[0].str);
      }
      break;

    case 753:
#line 3695 "fgl.yacc"
      {
	char buff[80];
	sprintf (buff, "AFT_FIELD_CHK(%s)", yyvsp[0].str);
 A4GL_generate_or (yyval.str, yyvsp[-2].str, buff);
      }
      break;

    case 754:
#line 3704 "fgl.yacc"
      {
	print_next_field (yyvsp[0].str);
      }
      break;

    case 755:
#line 3709 "fgl.yacc"
      {
	print_next_form_field (yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 756:
#line 3714 "fgl.yacc"
      {
	sprintf (yyval.str, "\"+\",0");
      }
      break;

    case 757:
#line 3715 "fgl.yacc"
      {
	sprintf (yyval.str, "\"-\",0");
      }
      break;

    case 759:
#line 3720 "fgl.yacc"
      {
	print_input_1 ();
      }
      break;

    case 760:
#line 3723 "fgl.yacc"
      {
	print_input_2 (yyvsp[-2].str);
      }
      break;

    case 761:
#line 3731 "fgl.yacc"
      {
	print_input (1, yyvsp[-2].str, yyvsp[-1].str, 0);
	strcpy (yyval.str, A4GL_get_formloop_str (0));
      }
      break;

    case 762:
#line 3736 "fgl.yacc"
      {
	print_input (0, yyvsp[-4].str, yyvsp[-1].str, yyvsp[-2].str);
	strcpy (yyval.str, A4GL_get_formloop_str (0));
      }
      break;

    case 763:
#line 3740 "fgl.yacc"
      {
	inp_flags = 0;
      }
      break;

    case 764:
#line 3742 "fgl.yacc"
      {
	strcpy (yyval.str,
		print_input_array (yyvsp[-8].str, yyvsp[-2].str,
				   yyvsp[-7].str, yyvsp[-5].str,
				   yyvsp[0].str));
      }
      break;

    case 765:
#line 3751 "fgl.yacc"
      {
	print_scroll (yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 766:
#line 3756 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 767:
#line 3757 "fgl.yacc"
      {
	strcpy (yyval.str, "-1");
      }
      break;

    case 768:
#line 3758 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 769:
#line 3759 "fgl.yacc"
      {
	sprintf (yyval.str, "-%s", yyvsp[0].str);
      }
      break;

    case 770:
#line 3762 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 772:
#line 3768 "fgl.yacc"
      {
	iskey = 1;
      }
      break;

    case 773:
#line 3768 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
	iskey = 0;
      }
      break;

    case 774:
#line 3770 "fgl.yacc"
      {
	strcpy (yyval.str, "->ANY");
      }
      break;

    case 775:
#line 3773 "fgl.yacc"
      {
	iskey = 1;
      }
      break;

    case 776:
#line 3773 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
	iskey = 0;
      }
      break;

    case 777:
#line 3775 "fgl.yacc"
      {
	sprintf (yyval.str, "key_val(\"%s\")", yyvsp[0].str);
	iskey = 0;
      }
      break;

    case 778:
#line 3779 "fgl.yacc"
      {
	start_state ("keymode", 1);
	iskey = 1;
      }
      break;

    case 779:
#line 3779 "fgl.yacc"
      {
	sprintf (yyval.str, "key_val(\"%s\")", yyvsp[0].str);
	iskey = 0;
	start_state ("keymode", 0);
      }
      break;

    case 780:
#line 3782 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 781:
#line 3783 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[-1].str);
      }
      break;

    case 783:
#line 3786 "fgl.yacc"
      {
	sprintf (yyval.str, "%s||%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 784:
#line 3791 "fgl.yacc"
      {
	start_state ("keymode", 1);
      }
      break;

    case 785:
#line 3791 "fgl.yacc"
      {
	start_state ("keymode", 0);
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 790:
#line 3798 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 791:
#line 3799 "fgl.yacc"
      {
	strcpy (yyval.str, "escape");
      }
      break;

    case 792:
#line 3800 "fgl.yacc"
      {
	strcpy (yyval.str, "up");
      }
      break;

    case 793:
#line 3801 "fgl.yacc"
      {
	strcpy (yyval.str, "help");
      }
      break;

    case 794:
#line 3802 "fgl.yacc"
      {
	strcpy (yyval.str, "down");
      }
      break;

    case 795:
#line 3803 "fgl.yacc"
      {
	strcpy (yyval.str, "return");
      }
      break;

    case 796:
#line 3804 "fgl.yacc"
      {
	strcpy (yyval.str, "delete");
      }
      break;

    case 797:
#line 3805 "fgl.yacc"
      {
	strcpy (yyval.str, "tab");
      }
      break;

    case 798:
#line 3806 "fgl.yacc"
      {
	strcpy (yyval.str, "left");
      }
      break;

    case 799:
#line 3807 "fgl.yacc"
      {
	strcpy (yyval.str, "right");
      }
      break;

    case 800:
#line 3808 "fgl.yacc"
      {
	strcpy (yyval.str, "nextpage");
      }
      break;

    case 801:
#line 3809 "fgl.yacc"
      {
	strcpy (yyval.str, "prevpage");
      }
      break;

    case 802:
#line 3810 "fgl.yacc"
      {
	rm_quotes (yyvsp[0].str);
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 803:
#line 3814 "fgl.yacc"
      {
	char buff[256];
 A4GL_debug ("Label : %s\n", get_idents (0));
	strcpy (buff, get_idents (0));
 A4GL_convlower (buff);
	print_label (buff);
      }
      break;

    case 804:
#line 3832 "fgl.yacc"
      {
	chk4var = 1;
      }
      break;

    case 805:
#line 3832 "fgl.yacc"
      {
	chk4var = 0;
	expand_obind ();
 A4GL_lex_printcomment ("/*let3*/\n");
      }
      break;

    case 806:
#line 3835 "fgl.yacc"
      {
	int to_vars;

 A4GL_debug ("/*processing let*/\n");
	expand_obind ();
	to_vars = how_many_in_bind ('o');
	if (to_vars >= 1)
	  {

	    if (!print_let_manyvars (yyvsp[0].str))
	      {
		a4gl_yyerror
		  ("Number of variables in let not equal to number of values\n");
		YYERROR;
	      }

	  }
	else
	  {
	    print_bind_pop1 ('o');
	  }

      }
      break;

    case 807:
#line 3858 "fgl.yacc"
      {
	int to_vars;
	int cnt;
	expand_obind ();
	to_vars = how_many_in_bind ('o');
	for (cnt = 0; cnt <= to_vars; cnt++)
	  {
	    print_push_null ();
	  }
	sprintf (yyval.str, "%d", to_vars + 1);

      }
      break;

    case 809:
#line 3876 "fgl.yacc"
      {
	if (!print_linked_cmd ('S', yyvsp[0].str))
	  a4gl_yyerror ("Not a linked variable");
      }
      break;

    case 810:
#line 3882 "fgl.yacc"
      {
	if (!print_linked_cmd ('D', yyvsp[0].str))
	  a4gl_yyerror ("Not a linked variable");
      }
      break;

    case 811:
#line 3888 "fgl.yacc"
      {
	if (!print_linked_cmd ('U', yyvsp[0].str))
	  a4gl_yyerror ("Not a linked variable");
      }
      break;

    case 812:
#line 3894 "fgl.yacc"
      {
	int vtype;
	vtype = scan_variable (yyvsp[-1].str);
	if (vtype != 11 && vtype != 12)
	  {
	    a4gl_yyerror ("Only Byte & Text may be located...");
	    YYERROR;
	  }
	print_locate ('M', yyvsp[-1].str, "0");


      }
      break;

    case 813:
#line 3905 "fgl.yacc"
      {
	int vtype;
	vtype = scan_variable (yyvsp[-2].str);
	if (vtype != 11 && vtype != 12)
	  {
	    a4gl_yyerror ("Only Byte & Text may be located...");
	    YYERROR;
	  }

	print_locate ('F', yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 814:
#line 3928 "fgl.yacc"
      {
	if (glob_only == 1)
	  {
	    A4GL_debug ("Read globals section so Im done\n");
	    YYACCEPT;
	  }

	set_4gl_vars ();

	set_current_variable_scope ('g');
	print_variables ();
	set_current_variable_scope ('G');
	print_variables ();
	set_current_variable_scope ('m');
	print_variables ();
	print_module_variable_init ();
	set_current_variable_scope ('m');
      }
      break;

    case 817:
#line 3944 "fgl.yacc"
      {
      }
      break;

    case 824:
#line 3967 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 828:
#line 3975 "fgl.yacc"
      {
	print_at_termination (yyvsp[0].str);
      }
      break;

    case 846:
#line 4001 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 847:
#line 4002 "fgl.yacc"
      {
	strcpy (yyval.str, "static ");
      }
      break;

    case 848:
#line 4010 "fgl.yacc"
      {
	clr_variable ();
	lastlineno = yylineno;
	clr_function_constants ();
      }
      break;

    case 849:
#line 4015 "fgl.yacc"
      {
	if (is_builtin_func (yyvsp[-1].str) && !compiling_system_4gl)
	  {
	    a4gl_yyerror
	      ("You can't use this name - this is the name of a builtin Aubit4GL function");
	  }

	if (strcmp (yyvsp[-3].str, "static ") != 0)
	  {
	    // We don't export static functions
	    variable_action (-1, yyvsp[-1].str, "", "", "add_function");
	  }
	sprintf (curr_func, "%s", yyvsp[-1].str);
	addmap ("Declare Function", curr_func, "MODULE", yylineno,
		infilename);
	print_func_start (yyvsp[-3].str, yyvsp[-1].str, 0);
	printDeclareFunctionStack (yyvsp[-1].str);
	cnt = 0;
      }
      break;

    case 850:
#line 4031 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* new function %s parameters*/\n", yyvsp[-1].str);
	push_blockcommand ("FUNC");
 A4GL_lex_printcomment ("/* define section */\n");
      }
      break;

    case 851:
#line 4037 "fgl.yacc"
      {
	int c;
 A4GL_lex_printcomment ("/*end of define section */\n");
	print_variables ();
	c = print_param ('f');
	printPushFunction ();
	print_func_args (c);
      }
      break;

    case 853:
#line 4052 "fgl.yacc"
      {
	printPopFunction ();
	print_func_defret0 ();
	pop_blockcommand ("FUNC");
	print_func_end ();
	clr_function_constants ();
 A4GL_lex_printcomment ("/*end function*/\n");
      }
      break;

    case 854:
#line 4065 "fgl.yacc"
      {
	lastlineno = yylineno;
	variable_action (-1, yyvsp[0].str, "", "", "add_function");
	sprintf (curr_func, "MAIN");
	clr_variable ();
	push_blockcommand ("MAIN");
	addmap ("MAIN", curr_func, "MODULE", yylineno, infilename);
	print_main_1 ();
      }
      break;

    case 855:
#line 4075 "fgl.yacc"
      {
	print_variables ();
	printDeclareFunctionStack ("MAIN");
	print_fgllib_start (hdr_dbname);
	printInitFunctionStack ();
	printPushFunction ();
      }
      break;

    case 856:
#line 4082 "fgl.yacc"
      {
	pop_blockcommand ("MAIN");
	print_main_end ();
 A4GL_lex_printcomment ("/*end main */\n");
      }
      break;

    case 857:
#line 4089 "fgl.yacc"
      {
	printPopFunction ();
	print_return (atoi (yyvsp[0].str));
      }
      break;

    case 858:
#line 4095 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 859:
#line 4095 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* Got expr list */");
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 860:
#line 4100 "fgl.yacc"
      {
	open_db (yyvsp[0].str);
	strcpy (hdr_dbname, yyvsp[0].str);
	lastlineno = yylineno;
      }
      break;

    case 861:
#line 4105 "fgl.yacc"
      {
      }
      break;

    case 867:
#line 4117 "fgl.yacc"
      {
	strcpy (curr_func, "[Globals]");
	set_current_variable_scope ('g');
 A4GL_lex_printcomment ("/* start of globals */\n");
      }
      break;

    case 869:
#line 4125 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* end of globals */");
 A4GL_debug ("end of globals\n");
	lastlineno = yylineno;
	set_current_variable_scope ('m');
      }
      break;

    case 870:
#line 4131 "fgl.yacc"
      {
	char b[256];
	lastlineno = yylineno;
	strcpy (b, yyvsp[0].str);
	set_current_variable_scope ('G');
	tr_glob_fname (b);
 A4GL_debug ("Reading globals file %s\n", b);
	rm_quote (b);
	read_glob (b);
	set_current_variable_scope ('m');
      }
      break;

    case 871:
#line 4145 "fgl.yacc"
      {
	addmap ("Define Member Function", curr_func, "MODULE", yylineno,
		infilename);
      }
      break;

    case 872:
#line 4149 "fgl.yacc"
      {
	char buff[80];
	sprintf (buff, "%s_%s_%d", yyvsp[-4].str, yyvsp[-6].str,
		 atoi (yyvsp[-1].str));
	sprintf (curr_func, "%s", buff);
	print_func_start ("", buff, 1);
	printDeclareFunctionStack (buff);

	cnt = 0;
 A4GL_lex_printcomment ("/* new function %s parameters*/\n", yyvsp[-1].str);
	push_blockcommand ("FUNC");
 A4GL_lex_printcomment ("/* define section */\n");
      }
      break;

    case 873:
#line 4162 "fgl.yacc"
      {
	print_variables ();
 A4GL_lex_printcomment ("/*end of define section */\n");
	print_param ('f');
	printPushFunction ();
	print_func_args (atoi (yyvsp[-3].str));
      }
      break;

    case 875:
#line 4180 "fgl.yacc"
      {
	start_state ("menu", 1);
	menu_cnt = npush_menu ();
	menu_cmd_cnt[menu_cnt] = 1;
	push_blockcommand ("MENU");
	print_menu_1 ();
      }
      break;

    case 876:
#line 4187 "fgl.yacc"
      {
	start_state ("menu", 0);
      }
      break;

    case 877:
#line 4193 "fgl.yacc"
      {
	print_end_menu_1 ();
	add_continue_blockcommand ("MENU");
	print_end_menu_2 ();
	pop_blockcommand ("MENU");
	pop_menu ();
      }
      break;

    case 878:
#line 4204 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* Block%d_m2 (Before menu) */", menu_cnt);
	print_menu_block (-2);
      }
      break;

    case 879:
#line 4208 "fgl.yacc"
      {
	print_menu_block_end ();
      }
      break;

    case 880:
#line 4215 "fgl.yacc"
      {
 A4GL_debug ("Menu=%d menu cnt=%d", menu_cnt, menu_cmd_cnt[menu_cnt]);
	push_command (menu_cnt, menu_cmd_cnt[menu_cnt], yyvsp[-3].str,
		      yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
 A4GL_lex_printcomment ("/* Block%d_%d */", menu_cnt,
			  menu_cmd_cnt[menu_cnt] - 1);
	print_menu_block (menu_cmd_cnt[menu_cnt] - 1);
	menu_cmd_cnt[menu_cnt]++;
      }
      break;

    case 881:
#line 4222 "fgl.yacc"
      {
	print_menu_block_end ();
      }
      break;

    case 882:
#line 4228 "fgl.yacc"
      {
	push_command (menu_cnt, menu_cmd_cnt[menu_cnt], yyvsp[-1].str, "\"\"",
		      "\"\"", 0);
	print_menu_block (menu_cmd_cnt[menu_cnt] - 1);
	menu_cmd_cnt[menu_cnt]++;
      }
      break;

    case 883:
#line 4233 "fgl.yacc"
      {
	print_menu_block_end ();
      }
      break;

    case 886:
#line 4240 "fgl.yacc"
      {
	strcpy (yyval.str, "\"EMPTY\"");
      }
      break;

    case 887:
#line 4241 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 888:
#line 4243 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 889:
#line 4244 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 890:
#line 4247 "fgl.yacc"
      {
	strcpy (yyval.str, "\"\"");
      }
      break;

    case 891:
#line 4248 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 892:
#line 4249 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 893:
#line 4251 "fgl.yacc"
      {
	print_option_op ('N', yyvsp[0].str);
      }
      break;

    case 894:
#line 4256 "fgl.yacc"
      {
	print_option_op ('S', yyvsp[0].str);
      }
      break;

    case 895:
#line 4261 "fgl.yacc"
      {
	print_option_op ('H', yyvsp[0].str);
      }
      break;

    case 896:
#line 4268 "fgl.yacc"
      {
	sprintf (yyval.str, "MENU_ALL");
      }
      break;

    case 900:
#line 4275 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 901:
#line 4277 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
	push_menu_title (yyval.str);
      }
      break;

    case 902:
#line 4279 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
	push_menu_title (yyval.str);
      }
      break;

    case 903:
#line 4288 "fgl.yacc"
      {
	strcpy (menuhandler, yyvsp[0].str);
	sprintf (curr_func, "%s", yyvsp[0].str);
	print_gtk_menuhandler_1 (yyvsp[0].str);
	push_blockcommand ("MENUH");
      }
      break;

    case 904:
#line 4294 "fgl.yacc"
      {
	print_variables ();
      }
      break;

    case 905:
#line 4298 "fgl.yacc"
      {
	pop_blockcommand ("MENUH");
	print_gtk_menuhandler_end ();
      }
      break;

    case 908:
#line 4310 "fgl.yacc"
      {

	print_gtk_menuhandler_bsm ();

	push_blockcommand ("BSM");
      }
      break;

    case 909:
#line 4315 "fgl.yacc"
      {
	pop_blockcommand ("BSM");
	print_gtk_menuhandler_bsm_end ();

      }
      break;

    case 910:
#line 4320 "fgl.yacc"
      {
	print_gtk_menuhandler_on (yyvsp[0].str);
	push_blockcommand ("ON");
      }
      break;

    case 911:
#line 4323 "fgl.yacc"
      {
	pop_blockcommand ("ON");
	print_gtk_menuhandler_on_end ();
      }
      break;

    case 912:
#line 4332 "fgl.yacc"
      {
	start_state ("message", 0);
      }
      break;

    case 913:
#line 4335 "fgl.yacc"
      {
	print_message (0, "0", 0);
	start_state ("message", 0);
      }
      break;

    case 914:
#line 4339 "fgl.yacc"
      {
	print_message (0, yyvsp[-1].str, atoi (yyvsp[0].str));
	start_state ("message", 0);
      }
      break;

    case 915:
#line 4343 "fgl.yacc"
      {
	print_message (0, "0", atoi (yyvsp[0].str));
	start_state ("message", 0);
      }
      break;

    case 922:
#line 4360 "fgl.yacc"
      {
	start_state ("message", 1);
      }
      break;

    case 924:
#line 4362 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 925:
#line 4362 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 926:
#line 4365 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 927:
#line 4375 "fgl.yacc"
      {
	char buff[256];
	char buff2[256];
	int n;

	if (strcmp (yyvsp[0].str, "status") == 0)
	  {
	    strcpy (yyvsp[0].str, "a4gl_status");
	  }
	if (strncmp (yyvsp[0].str, "sqlca.", 6) == 0)
	  {
	    char xbuff[256];
	    char xbuff2[256];
	    strcpy (xbuff, "a4gl_sqlca.");
	    strcpy (xbuff2, yyvsp[0].str);
	    strcat (xbuff, &xbuff2[6]);
	    strcpy (yyvsp[0].str, xbuff);
	  }
	strcpy (buff, yyvsp[0].str);
 A4GL_lex_printcomment ("/* .. var %s*/", buff);
	if (buff[0] != ' ')
	  addmap ("Use Variable", buff, curr_func, yylineno, infilename);

	if (strncmp (buff, " ASSOCIATE_", 11) != 0)
	  {
	    A4GL_convlower (buff);
	  }

	strcpy (yyval.str, buff);
 A4GL_debug ("Checking variable '%s'", buff);
	n = scan_variable (buff);

 A4GL_debug ("scan variable returns -> %d\n", n);

	if (n == -1 && buff[0] != ' ')
	  {
	    sprintf (buff2, "'%s' does not represent a defined variable (1)",
		     buff);
	    a4gl_yyerror (buff2);
	    exit (0);
	  }
	if (strstr (buff, ".*") && n != -2)
	  {
	    char *ptr;
	    printf ("WARNING : Using a .* on a non-record - %s\n",
		    yyvsp[0].str);
	    ptr = strstr (buff, ".*");
	    *ptr = 0;
	    strcpy (yyval.str, buff);
	  }

	mcnt = 0;
      }
      break;

    case 929:
#line 4422 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 931:
#line 4429 "fgl.yacc"
      {
	sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str);
 A4GL_lex_printcomment ("/* record building -> %s */\n", yyval.str);
      }
      break;

    case 932:
#line 4434 "fgl.yacc"
      {

	int type, arrsize, size, level;
	char buff[256];
	char buff2[256];
	char arrbuff[256];

 A4GL_lex_printcomment ("/* OPEN_SQUARE.. */\n");

	if (strcmp (yyvsp[-4].str, "sqlca") == 0)
	  {
	    strcpy (yyvsp[-4].str, "a4gl_sqlca");
	  }
	sprintf (buff, "%s.%s", yyvsp[-4].str, yyvsp[-3].str);
	if (scan_variable (buff) == -1)
	  {
	    sprintf (buff2, "'%s' does not represent a defined variable (2)",
		     buff);
	    a4gl_yyerror (buff2);
	    YYERROR;
	  }

 A4GL_lex_printcomment ("/*variable with [...]*/");
	get_variable_dets (buff, &type, &arrsize, &size, &level, arrbuff);
 A4GL_lex_printcomment ("/* Arrsize = %d size = %d*/", arrsize, size);

	if (arrsize > 0)
	  {
	    A4GL_debug ("Is array...");
	    sprintf (yyval.str, "%s[%s]", buff,
		     change_arr_elem (yyvsp[-1].str));
	    lex_printcomment
	      ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n",
	       yyval.str, num_arr_elem (yyvsp[-1].str),
	       num_arr_elem (arrbuff));
	  }
	else
	  {
	    A4GL_debug ("Is string...");
	    sprintf (yyval.str, " substr(%s , %d , %s , 0 ) /*1*/", buff,
		     (int) scan_variable (buff), yyvsp[-1].str);

	    addmap ("Use Variable", buff, curr_func, yylineno, infilename);
	    A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
	  }

	mcnt++;
      }
      break;

    case 936:
#line 4481 "fgl.yacc"
      {
	char buff2[256];
	if (scan_variable (yyvsp[-3].str) == -1)
	  {
	    sprintf (buff2, "'%s' does not represent a defined variable (3)",
		     yyvsp[-3].str);
	    a4gl_yyerror (buff2);
	    YYERROR;
	  }

 A4GL_lex_printcomment ("/*Associative Variable : %s*/\n", yyvsp[-1].str);
	sprintf (yyval.str, " ASSOCIATE_%s(%s,1)", upshift (yyvsp[-3].str),
		 yyvsp[-1].str);
      }
      break;

    case 937:
#line 4495 "fgl.yacc"
      {
	char buff2[256];
	if (scan_variable (yyvsp[-3].str) == -1)
	  {
	    sprintf (buff2, "'%s' does not represent a defined variable (4)",
		     yyvsp[-3].str);
	    a4gl_yyerror (buff2);
	    YYERROR;
	  }
 A4GL_lex_printcomment ("/*Associative Variable : %s*/\n", yyvsp[-1].str);
	sprintf (yyval.str, " ASSOCIATE_%s(%s,0)", upshift (yyvsp[-3].str),
		 yyvsp[-1].str);
      }
      break;

    case 942:
#line 4519 "fgl.yacc"
      {
	int type, arrsize, size, level;
	char buff2[256];
	char arrbuff[256];
	printf ("ARRAY (array_r_variable) : %s %s", yyvsp[-1].str,
		yyvsp[0].str);
 A4GL_lex_printcomment ("/*array variable nnn */");
	get_variable_dets (yyvsp[-1].str, &type, &arrsize, &size, &level,
			   arrbuff);
 A4GL_lex_printcomment ("/*here %s %x */", yyvsp[-1].str, type);
	if (scan_variable (yyvsp[-1].str) == -1)
	  {
	    sprintf (buff2, "'%s' does not represent a defined variable (7)",
		     yyvsp[-1].str);
	    a4gl_yyerror (buff2);
	    YYERROR;

	  }


 A4GL_debug ("Type=%d (%d) arrsize=%d", type, type & 0xffff, arrsize);

	if (strchr (yyvsp[0].str, ':'))
	  {
	    char lbuff[256];
	    char rbuff[256];
	    char tmpbuff[256];
	    char *ptr;
	    strcpy (lbuff, yyvsp[0].str);
	    strcpy (rbuff, strchr (yyvsp[0].str, ':') + 1);
	    ptr = strchr (lbuff, ':');
	    *ptr = 0;
	    sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str,
		     change_arr_elem (lbuff));
	    sprintf (yyval.str, " substr(%s,%d,%s,0) /*2*/", tmpbuff,
		     (int) scan_variable (tmpbuff), rbuff);
	  }
	else
	  {

	    if ((type & (0xffff != 0)) || (arrsize > 0))
	      {
	 A4GL_lex_printcomment ("/* changing optbase for array: %s */\n",
				  yyvsp[0].str);
		sprintf (yyval.str, "%s[%s]", yyvsp[-1].str,
			 change_arr_elem (yyvsp[0].str));
	 A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
	      }
	    else
	      {
		sprintf (yyval.str, " substr(%s,0x%x,%s,0)/*3*/",
			 yyvsp[-1].str, (int) scan_variable (yyvsp[-1].str),
			 yyvsp[0].str);
		addmap ("Use Variable", yyvsp[-1].str, curr_func, yylineno,
			infilename);
	 A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
		dec_counter ();
		mcnt--;
	      }
	  }

	mcnt++;
      }
      break;

    case 943:
#line 4575 "fgl.yacc"
      {
	int type, arrsize, size, level;
	char buff2[256];
	char arrbuff[256];
	printf ("ARRAY (array_r_variable) : %s %s", yyvsp[-1].str,
		yyvsp[0].str);
 A4GL_lex_printcomment ("/*array variable nnn */");
	get_variable_dets (yyvsp[-1].str, &type, &arrsize, &size, &level,
			   arrbuff);
 A4GL_lex_printcomment ("/*here %s %x */", yyvsp[-1].str, type);
	if (scan_variable (yyvsp[-1].str) == -1)
	  {
	    sprintf (yyval.str, "%s%s", yyvsp[-1].str, yyvsp[0].str);
	  }
	else
	  {


	    A4GL_debug ("Type=%d (%d) arrsize=%d", type, type & 0xffff, arrsize);

	    if (strchr (yyvsp[0].str, ':'))
	      {
		char lbuff[256];
		char rbuff[256];
		char tmpbuff[256];
		char *ptr;
		strcpy (lbuff, yyvsp[0].str);
		strcpy (rbuff, strchr (yyvsp[0].str, ':') + 1);
		ptr = strchr (lbuff, ':');
		*ptr = 0;
		sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str,
			 change_arr_elem (lbuff));
		sprintf (yyval.str, " substr(%s,%d,%s,0) /*2*/", tmpbuff,
			 (int) scan_variable (tmpbuff), rbuff);
	      }
	    else
	      {

		if ((type & (0xffff != 0)) || (arrsize > 0))
		  {
		    lex_printcomment
		      ("/* changing optbase for array: %s */\n",
		       yyvsp[0].str);
		    sprintf (yyval.str, "%s[%s]", yyvsp[-1].str,
			     change_arr_elem (yyvsp[0].str));
		    A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
		  }
		else
		  {
		    sprintf (yyval.str, " substr(%s,0x%x,%s,0)/*3*/",
			     yyvsp[-1].str,
			     (int) scan_variable (yyvsp[-1].str),
			     yyvsp[0].str);
		    addmap ("Use Variable", yyvsp[-1].str, curr_func,
			    yylineno, infilename);
		    A4GL_lex_printcomment ("/*character variable %s*/\n",
				      yyval.str);
		    dec_counter ();
		    mcnt--;
		  }
	      }
	  }

	mcnt++;
      }
      break;

    case 944:
#line 4630 "fgl.yacc"
      {
 A4GL_debug ("---> Subscript or substring");
	strcpy (yyval.str, yyvsp[-1].str);
      }
      break;

    case 945:
#line 4635 "fgl.yacc"
      {
 A4GL_debug ("---> Subscript & substring");
	sprintf (yyval.str, "%s:%s", yyvsp[-4].str, yyvsp[-1].str);
      }
      break;

    case 946:
#line 4643 "fgl.yacc"
      {
 A4GL_debug ("List element");
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 947:
#line 4648 "fgl.yacc"
      {
 A4GL_debug ("List element continues");
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 948:
#line 4656 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 949:
#line 4662 "fgl.yacc"
      {
	char buff[256];
	if (strcmp (yyvsp[0].str, "status") == 0)
	  {
	    strcpy (yyvsp[0].str, "a4gl_status");
	  }
	if (strncmp (yyvsp[0].str, "sqlca.", 6) == 0)
	  {
	    char xbuff[256];
	    char xbuff2[256];
	    strcpy (xbuff, "a4gl_sqlca.");
	    strcpy (xbuff2, yyvsp[0].str);
	    strcat (xbuff, &xbuff2[6]);
	    strcpy (yyvsp[0].str, xbuff);
	  }
	strcpy (buff, yyvsp[0].str);
	addmap ("Let Variable", buff, curr_func, yylineno, infilename);
	if (strncmp (buff, " ASSOCIATE_", 11) != 0)
	  {
	    A4GL_convlower (buff);
	  }
	strcpy (yyval.str, buff);
 A4GL_lex_printcomment ("/* %s */\n", yyvsp[0].str);
	if (scan_variable (buff) == -1 && buff[0] != ' ')
	  {
	    A4GL_lex_printcomment ("/*NOt a variable*/");
	    sprintf (buff, "%s is not a variable", yyvsp[0].str);
	    a4gl_yyerror (buff);
	  }

	mcnt = 0;
      }
      break;

    case 950:
#line 4690 "fgl.yacc"
      {
 A4GL_debug ("Array..");
      }
      break;

    case 951:
#line 4693 "fgl.yacc"
      {
	sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 952:
#line 4695 "fgl.yacc"
      {
	int a;
	int b;
	char buff[256];
	char buff2[256];
 A4GL_lex_printcomment ("/*array variable .let. */");
	if (strcmp (yyvsp[-5].str, "status") == 0)
	  {
	    strcpy (yyvsp[-5].str, "a4gl_status");
	  }
	if (strcmp (yyvsp[-5].str, "sqlca") == 0)
	  {
	    strcpy (yyvsp[-5].str, "a4gl_sqlca");
	  }
	sprintf (yyval.str, "%s.%s", yyvsp[-5].str, yyvsp[-3].str);

	if (scan_variable (yyval.str) == -1)
	  {
	    sprintf (buff2, "'%s' does not represent a defined variable (5)",
		     yyval.str);
	    a4gl_yyerror (buff2);
	    YYERROR;
	  }

 A4GL_debug ("?1arrvar=%s", yyval.str);
	b = isarrvariable (yyval.str);
	a = scan_variable (yyval.str);

 A4GL_lex_printcomment ("/*a=%x b=%x */\n", a, b);

	if (b != 0)
	  {
	    sprintf (yyval.str, "%s.%s[%s-1] ", yyvsp[-5].str, yyvsp[-3].str,
		     yyvsp[-1].str);
	    A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
	  }
	else
	  {
	    sprintf (buff, "%s.%s", yyvsp[-5].str, yyvsp[-3].str);
	    sprintf (yyval.str, " let_substr(%s,%d,%s,0)", buff, a,
		     yyvsp[-1].str);
	    addmap ("Let Variable", buff, curr_func, yylineno, infilename);
	    A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
	  }

	mcnt++;

      }
      break;

    case 957:
#line 4746 "fgl.yacc"
      {
/*OPEN_SQUARE num_list CLOSE_SQUARE*/
	int a;
	int b;
	char buff2[256];
 A4GL_lex_printcomment ("/*.let. array variable */");

 A4GL_debug ("?2 arrvar=%s", yyvsp[-1].str);
	if (strchr (yyvsp[0].str, ':'))
	  {
	    char lbuff[256];
	    char rbuff[256];
	    char tmpbuff[256];
	    char *ptr;
	    strcpy (lbuff, yyvsp[0].str);
	    strcpy (rbuff, strchr (yyvsp[0].str, ':') + 1);
	    ptr = strchr (lbuff, ':');
	    *ptr = 0;
	    sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str,
		     change_arr_elem (lbuff));
	    sprintf (yyval.str, " let_substr(%s,%d,%s,0)", tmpbuff,
		     (int) scan_variable (tmpbuff), rbuff);
	  }
	else
	  {
	    b = isarrvariable (yyvsp[-1].str);
	    a = scan_variable (yyvsp[-1].str);

	    if (a == -1)
	      {
		sprintf (buff2,
			 "'%s' does not represent a defined variable (6)",
			 yyvsp[-1].str);
		a4gl_yyerror (buff2);
		YYERROR;
	      }


	    A4GL_debug ("/*a=%d b=%d*/\n", a, b);

	    if (b != 0)
	      {
		sprintf (yyval.str, "%s[%s]", yyvsp[-1].str,
			 A4GL_decode_array_string (yyvsp[0].str));
	 A4GL_debug ("/* array variable %s*/\n", yyval.str);
	      }
	    else
	      {
		sprintf (yyval.str, " let_substr(%s,%d,%s,0)", yyvsp[-1].str,
			 (int) scan_variable (yyvsp[-1].str), yyvsp[0].str);

		addmap ("Let Variable", yyvsp[-1].str, curr_func, yylineno,
			infilename);
	 A4GL_debug ("/*character variable %s*/\n", yyval.str);
	      }
	  }
	mcnt++;

      }
      break;

    case 958:
#line 4798 "fgl.yacc"
      {
	start_bind ('f', 0);
	start_bind ('O', 0);
	strcpy (yyval.str, "0");
      }
      break;

    case 960:
#line 4805 "fgl.yacc"
      {
	start_bind ('f', yyvsp[0].str);
	start_bind ('O', yyvsp[0].str);
	sprintf (yyval.str, "1");
      }
      break;

    case 961:
#line 4811 "fgl.yacc"
      {
	int c;
	c = add_bind ('f', yyvsp[0].str);
	c = add_bind ('O', yyvsp[0].str);
	sprintf (yyval.str, "%d", c);
      }
      break;

    case 962:
#line 4822 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*STarted bind %s*/\n", yyvsp[0].str);
	start_bind ('i', yyvsp[0].str);
 A4GL_lex_printcomment ("/*STarted bind 2*/\n");
	strcpy (yyval.str, "");
      }
      break;

    case 963:
#line 4829 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* Added */\n");
	add_bind ('i', yyvsp[0].str);
	strcpy (yyval.str, "");
      }
      break;

    case 965:
#line 4837 "fgl.yacc"
      {
	sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[-1].str);
      }
      break;

    case 966:
#line 4840 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* Variable */\n");
      }
      break;

    case 967:
#line 4841 "fgl.yacc"
      {
 A4GL_debug ("Got an ibind thru...");
	sprintf (yyval.str, "%s\n%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 969:
#line 4843 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 970:
#line 4844 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 971:
#line 4847 "fgl.yacc"
      {
	start_bind ('o', yyvsp[0].str);
      }
      break;

    case 972:
#line 4850 "fgl.yacc"
      {
	add_bind ('o', yyvsp[0].str);
	strcpy (yyval.str, "");
      }
      break;

    case 973:
#line 4856 "fgl.yacc"
      {
	addmap ("OBIND", yyvsp[0].str, curr_func, yylineno, infilename);
      }
      break;

    case 974:
#line 4859 "fgl.yacc"
      {
 A4GL_debug ("Got an obind thru...");
	sprintf (yyval.str, "%s\n%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 975:
#line 4863 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* start obind with  %s*/\n", yyvsp[0].str);
	start_bind ('o', yyvsp[0].str);
      }
      break;

    case 976:
#line 4867 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* add to obind %s */\n", yyvsp[0].str);
	add_bind ('o', yyvsp[0].str);
	strcpy (yyval.str, "");
      }
      break;

    case 977:
#line 4874 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* Read variable %s*/\n", yyvsp[0].str);
      }
      break;

    case 978:
#line 4879 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* use_arr_var */\n");
	start_arr_bind ('o', yyvsp[0].str);
 A4GL_lex_printcomment ("/* use_arr_var complete */\n");
      }
      break;

    case 979:
#line 4886 "fgl.yacc"
      {
	start_bind ('O', yyvsp[0].str);
      }
      break;

    case 980:
#line 4889 "fgl.yacc"
      {
	add_bind ('O', yyvsp[0].str);
	strcpy (yyval.str, "");
      }
      break;

    case 985:
#line 4902 "fgl.yacc"
      {
	int type, arrsize, size, level;
	char arrbuff[256];
 A4GL_lex_printcomment ("/*..array_r_varid..*/");

	printf ("Got array %s %s\n", yyvsp[-3].str, yyvsp[-1].str);
	if (get_variable_dets
	    (yyvsp[-3].str, &type, &arrsize, &size, &level, arrbuff) >= 0)
	  {
	    // Its a variable
	    printf ("gvd = true\n");
	    sprintf (yyval.str, "%s[%s]", yyvsp[-3].str,
		     subtract_one (yyvsp[-1].str));
	  }
	else
	  {
	    // Its an sql identifier or similar
	    printf ("gvd = false\n");
	    sprintf (yyval.str, "%s[%s]", yyvsp[-3].str, yyvsp[-1].str);
	  }
	printf ("All done - ARRAY (array_r_varid) : %s\n", yyval.str);
      }
      break;

    case 986:
#line 4921 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*STarted bind %s*/\n", yyvsp[0].str);
	start_bind ('N', yyvsp[0].str);
 A4GL_lex_printcomment ("/*STarted bind 2*/\n");
	strcpy (yyval.str, "");
      }
      break;

    case 987:
#line 4928 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* Added */\n");
	add_bind ('N', yyvsp[0].str);
	strcpy (yyval.str, "");
      }
      break;

    case 988:
#line 4935 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 989:
#line 4938 "fgl.yacc"
      {
	sprintf (yyval.str, "%s\n%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 990:
#line 4952 "fgl.yacc"
      {
	form_attrib.iswindow = 1;
	print_open_window (yyvsp[-5].str, yyvsp[-1].str);
	sprintf (yyval.str, "open window");
      }
      break;

    case 995:
#line 4969 "fgl.yacc"
      {
	print_niy ("OPEN_STATUSBOX");
      }
      break;

    case 996:
#line 4974 "fgl.yacc"
      {
	addmap ("Call Formhandler", yyvsp[0].str, curr_func, yylineno,
		infilename);
      }
      break;

    case 997:
#line 4980 "fgl.yacc"
      {
	print_open_form (yyvsp[0].str, yyvsp[-1].str, yyvsp[-1].str);
      }
      break;

    case 999:
#line 4987 "fgl.yacc"
      {
	form_attrib.iswindow = 0;
	strcpy (yyval.str, "open_form(%s);");
      }
      break;

    case 1000:
#line 4992 "fgl.yacc"
      {
	sprintf (yyval.str, "open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",
		 yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[0].str,
		 yyvsp[0].str);
      }
      break;

    case 1001:
#line 4995 "fgl.yacc"
      {
	strcpy (yyval.str, "0,0");
      }
      break;

    case 1002:
#line 4996 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,2", yyvsp[-5].str);
      }
      break;

    case 1003:
#line 4999 "fgl.yacc"
      {
	strcpy (yyval.str, "\"\"");
      }
      break;

    case 1004:
#line 5000 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1005:
#line 5003 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1006:
#line 5004 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1007:
#line 5009 "fgl.yacc"
      {
	print_open_session (yyvsp[-3].str, yyvsp[-1].str, yyvsp[0].str);

      }
      break;

    case 1008:
#line 5016 "fgl.yacc"
      {
	print_open_cursor (yyvsp[0].str, "0");
      }
      break;

    case 1009:
#line 5019 "fgl.yacc"
      {
	print_open_cursor (yyvsp[-3].str, yyvsp[0].str);	/* CHANGED from $<str>4 */
      }
      break;

    case 1010:
#line 5025 "fgl.yacc"
      {
	sprintf (yyval.str, "0,0");
      }
      break;

    case 1011:
#line 5027 "fgl.yacc"
      {
	sprintf (yyval.str, "%s, %s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1012:
#line 5029 "fgl.yacc"
      {
	sprintf (yyval.str, "%s, %s", yyvsp[-3].str, yyvsp[0].str);
      }
      break;

    case 1013:
#line 5031 "fgl.yacc"
      {
	sprintf (yyval.str, "%s, %s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1014:
#line 5034 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1015:
#line 5034 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1016:
#line 5035 "fgl.yacc"
      {
	strcpy (yyval.str, "2");
      }
      break;

    case 1017:
#line 5040 "fgl.yacc"
      {
	print_open_session (yyvsp[-1].str, yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1018:
#line 5048 "fgl.yacc"
      {
	strcpy (yyval.str, "\"default_conn\"");
      }
      break;

    case 1019:
#line 5049 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1020:
#line 5054 "fgl.yacc"
      {
	sprintf (yyval.str, "0,0");
      }
      break;

    case 1021:
#line 5056 "fgl.yacc"
      {
	sprintf (yyval.str, "%s, %s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1022:
#line 5058 "fgl.yacc"
      {
	sprintf (yyval.str, "%s, %s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1026:
#line 5075 "fgl.yacc"
      {
	print_options ('C', yyvsp[0].str);
      }
      break;

    case 1027:
#line 5078 "fgl.yacc"
      {
	print_options ('E', yyvsp[0].str);
      }
      break;

    case 1028:
#line 5081 "fgl.yacc"
      {
	print_options ('F', yyvsp[0].str);
      }
      break;

    case 1029:
#line 5084 "fgl.yacc"
      {
 A4GL_lex_printc ("set_option_value('M',%s);\n", yyvsp[0].str);
      }
      break;

    case 1030:
#line 5087 "fgl.yacc"
      {
	print_options ('m', yyvsp[0].str);
      }
      break;

    case 1031:
#line 5090 "fgl.yacc"
      {
	print_options ('P', yyvsp[0].str);
      }
      break;

    case 1032:
#line 5093 "fgl.yacc"
      {
	print_options ('A', yyvsp[0].str);
	iskey = 0;
      }
      break;

    case 1033:
#line 5097 "fgl.yacc"
      {
	print_options ('D', yyvsp[0].str);
	iskey = 0;
      }
      break;

    case 1034:
#line 5101 "fgl.yacc"
      {
	print_options ('I', yyvsp[0].str);
	iskey = 0;
      }
      break;

    case 1035:
#line 5105 "fgl.yacc"
      {
	print_options ('N', yyvsp[0].str);
      }
      break;

    case 1036:
#line 5108 "fgl.yacc"
      {
	print_options ('p', yyvsp[0].str);
	iskey = 0;
      }
      break;

    case 1037:
#line 5112 "fgl.yacc"
      {
	print_options ('H', yyvsp[0].str);
      }
      break;

    case 1038:
#line 5115 "fgl.yacc"
      {
	print_set_helpfile (yyvsp[0].str);
      }
      break;

    case 1039:
#line 5116 "fgl.yacc"
      {
	print_set_langfile (yyvsp[0].str);
      }
      break;

    case 1040:
#line 5117 "fgl.yacc"
      {
	print_options ('d', yyvsp[0].str);
      }
      break;

    case 1041:
#line 5120 "fgl.yacc"
      {
	print_options ('i', yyvsp[0].str);
      }
      break;

    case 1042:
#line 5123 "fgl.yacc"
      {
	print_options ('W', "1");
      }
      break;

    case 1043:
#line 5126 "fgl.yacc"
      {
	print_options ('W', "0");
      }
      break;

    case 1044:
#line 5129 "fgl.yacc"
      {
	print_options ('f', "1");
      }
      break;

    case 1045:
#line 5132 "fgl.yacc"
      {
	print_options ('f', "0");
      }
      break;

    case 1046:
#line 5135 "fgl.yacc"
      {
	print_options ('S', "1");
      }
      break;

    case 1047:
#line 5138 "fgl.yacc"
      {
	print_options ('S', "0");
      }
      break;

    case 1048:
#line 5155 "fgl.yacc"
      {
	print_prepare (yyvsp[-2].str, yyvsp[0].str);
	addmap ("Prepare", yyvsp[-2].str, curr_func, yylineno, infilename);
	print_undo_use (yyvsp[-4].str);
      }
      break;

    case 1051:
#line 5165 "fgl.yacc"
      {

	print_execute (yyvsp[0].str, 0);

	addmap ("Execute", yyvsp[0].str, curr_func, yylineno, infilename);
      }
      break;

    case 1052:
#line 5172 "fgl.yacc"
      {
	addmap ("Execute", yyvsp[-2].str, curr_func, yylineno, infilename);
	print_execute (yyvsp[-2].str, 1);
      }
      break;

    case 1054:
#line 5193 "fgl.yacc"
      {
	push_blockcommand ("PROMPT");

	print_prompt_1 (yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str,
			yyvsp[0].str);
      }
      break;

    case 1055:
#line 5198 "fgl.yacc"
      {
	if (strcmp (yyvsp[-5].str, "1") == 0)
	  {
	    print_prompt_forchar ();
	  }
	add_continue_blockcommand ("PROMPT");
	print_prompt_end (yyvsp[-4].str);
	pop_blockcommand ("PROMPT");
 A4GL_lex_printcomment ("/* END OF PROMPT */");
      }
      break;

    case 1056:
#line 5211 "fgl.yacc"
      {
	print_niy ("GUI PROMPT");
      }
      break;

    case 1057:
#line 5216 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1058:
#line 5217 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1059:
#line 5221 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1063:
#line 5227 "fgl.yacc"
      {
	print_onkey_1 (yyvsp[0].str);
      }
      break;

    case 1064:
#line 5229 "fgl.yacc"
      {
	print_onkey_2_prompt ();
      }
      break;

    case 1066:
#line 5244 "fgl.yacc"
      {
	start_bind ('i', 0);
      }
      break;

    case 1067:
#line 5248 "fgl.yacc"
      {
	print_put (yyvsp[-2].str);
      }
      break;

    case 1068:
#line 5254 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1069:
#line 5255 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1070:
#line 5258 "fgl.yacc"
      {
	push_gen (PUTVAL, yyvsp[0].str);
      }
      break;

    case 1071:
#line 5259 "fgl.yacc"
      {
	push_gen (PUTVAL, yyvsp[0].str);
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1072:
#line 5262 "fgl.yacc"
      {
	char buff[256];
	strcpy (buff, yyvsp[0].sql_string);
	strcpy (yyval.str, buff);
      }
      break;

    case 1074:
#line 5281 "fgl.yacc"
      {
	addmap ("Start Report", yyvsp[-1].str, curr_func, yylineno,
		infilename);
	print_start_report ("P", "\"lp\"", yyvsp[-1].str);
      }
      break;

    case 1075:
#line 5286 "fgl.yacc"
      {
	addmap ("Start Report", yyvsp[-2].str, curr_func, yylineno,
		infilename);
	print_start_report ("F", yyvsp[0].str, yyvsp[-2].str);
      }
      break;

    case 1076:
#line 5291 "fgl.yacc"
      {
	addmap ("Start Report", yyvsp[-2].str, curr_func, yylineno,
		infilename);
	print_start_report ("P", yyvsp[0].str, yyvsp[-2].str);
      }
      break;

    case 1077:
#line 5296 "fgl.yacc"
      {
	addmap ("Start Report", yyvsp[0].str, curr_func, yylineno,
		infilename);
	print_start_report ("", "\"\"", yyvsp[0].str);
      }
      break;

    case 1083:
#line 5318 "fgl.yacc"
      {
	addmap ("Output to report", yyvsp[-5].str, curr_func, yylineno,
		infilename);
	print_output_to_report (yyvsp[-5].str, yyvsp[-1].str);
      }
      break;

    case 1084:
#line 5325 "fgl.yacc"
      {
	addmap ("Finish Report", yyvsp[0].str, curr_func, yylineno,
		infilename);
	print_finish_report (yyvsp[0].str);
      }
      break;

    case 1085:
#line 5334 "fgl.yacc"
      {
	addmap ("Finish Report", yyvsp[0].str, curr_func, yylineno,
		infilename);
	print_terminate_report (yyvsp[0].str);
      }
      break;

    case 1086:
#line 5340 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1087:
#line 5342 "fgl.yacc"
      {
	print_format_every_row ();
      }
      break;

    case 1091:
#line 5353 "fgl.yacc"
      {
	push_report_block ("FIRST", 'P');
      }
      break;

    case 1092:
#line 5354 "fgl.yacc"
      {
	print_rep_ret (0);
      }
      break;

    case 1093:
#line 5356 "fgl.yacc"
      {
	push_report_block ("TRAILER", 'T');
      }
      break;

    case 1094:
#line 5357 "fgl.yacc"
      {
	print_rep_ret (0);
      }
      break;

    case 1095:
#line 5359 "fgl.yacc"
      {
	push_report_block ("HEADER", 'p');
      }
      break;

    case 1096:
#line 5360 "fgl.yacc"
      {
	print_rep_ret (0);
      }
      break;

    case 1097:
#line 5362 "fgl.yacc"
      {
	push_report_block ("EVERY", 'E');
      }
      break;

    case 1098:
#line 5363 "fgl.yacc"
      {
	print_rep_ret (0);
      }
      break;

    case 1099:
#line 5365 "fgl.yacc"
      {
	push_report_block ("LAST", 'L');
      }
      break;

    case 1100:
#line 5366 "fgl.yacc"
      {
	print_rep_ret (0);
      }
      break;

    case 1101:
#line 5367 "fgl.yacc"
      {
	int a;
	char buff[80];
 A4GL_debug ("rordcnt=%d", rordcnt);
	a = scan_orderby (yyvsp[0].str, rordcnt);
	if (a < 0)
	  {
	    sprintf (buff, "%s is not in the order by list", yyvsp[0].str);
	    a4gl_yyerror (buff);
	    YYERROR;
	  }
	sprintf (buff, "%d", a + 1);
	push_report_block (buff, 'B');
	set_curr_block (a + 1);
      }
      break;

    case 1102:
#line 5381 "fgl.yacc"
      {
	print_rep_ret (0);
      }
      break;

    case 1103:
#line 5383 "fgl.yacc"
      {
	int a;
	char buff[80];

 A4GL_debug ("rordcnt=%d", rordcnt);
	a = scan_orderby (yyvsp[0].str, rordcnt);
	if (a < 0)
	  {
	    sprintf (buff, "%s is not in the order by list", yyvsp[0].str);
	    a4gl_yyerror (buff);
	    YYERROR;
	  }

	sprintf (buff, "%d", a + 1);
	push_report_block (buff, 'A');
	set_curr_block (a + 1);

      }
      break;

    case 1104:
#line 5400 "fgl.yacc"
      {
	print_rep_ret (0);
      }
      break;

    case 1111:
#line 5412 "fgl.yacc"
      {
	start_state ("skip", 1);
      }
      break;

    case 1112:
#line 5412 "fgl.yacc"
      {
	print_need_lines ();
	start_state ("skip", 0);
      }
      break;

    case 1113:
#line 5418 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1114:
#line 5418 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1115:
#line 5421 "fgl.yacc"
      {
	start_state ("KWLINE", 1);
      }
      break;

    case 1116:
#line 5421 "fgl.yacc"
      {
	char buff[256];
	strcpy (buff, yyvsp[0].str);
	if (buff[0] == '1')
	  {
	    print_skip_lines ();
	  }
	else
	  {
	    if (rep_type != REP_TYPE_PDF)
	      {
		a4gl_yyerror ("SKIP BY is only in PDF reports");
		YYERROR;
	      }
	    print_skip_by (yyvsp[-2].str);
	  }
	start_state ("KWLINE", 0);
      }
      break;

    case 1117:
#line 5431 "fgl.yacc"
      {
	print_skip_top ();
      }
      break;

    case 1118:
#line 5432 "fgl.yacc"
      {
	print_niy ("FONT SIZE");
      }
      break;

    case 1119:
#line 5433 "fgl.yacc"
      {
	if (rep_type != REP_TYPE_PDF)
	  {
	    a4gl_yyerror ("SKIP BY is only in PDF reports");
	    YYERROR;
	  }
	print_skip_by (yyvsp[0].str);
      }
      break;

    case 1120:
#line 5440 "fgl.yacc"
      {
	if (rep_type != REP_TYPE_PDF)
	  {
	    a4gl_yyerror ("SKIP TO is only in PDF reports");
	    YYERROR;
	  }
	print_skip_to (yyvsp[0].str);
      }
      break;

    case 1121:
#line 5452 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1127:
#line 5463 "fgl.yacc"
      {
	print_niy ("PRINT AT...");
      }
      break;

    case 1128:
#line 5468 "fgl.yacc"
      {
	print_report_print (0, yyvsp[0].str, 0);
      }
      break;

    case 1129:
#line 5472 "fgl.yacc"
      {
	print_report_print_file (yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1130:
#line 5477 "fgl.yacc"
      {
	print_report_print_img (yyvsp[-1].str, yyvsp[-3].str, yyvsp[-2].str,
				yyvsp[0].str);
      }
      break;

    case 1131:
#line 5483 "fgl.yacc"
      {
	strcpy (yyval.str, A4GL_get_default_scaling ());
      }
      break;

    case 1132:
#line 5484 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
	strcat (yyval.str, yyvsp[0].str);
      }
      break;

    case 1133:
#line 5485 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1134:
#line 5489 "fgl.yacc"
      {
	strcpy (yyval.str, "tiff");
      }
      break;

    case 1135:
#line 5490 "fgl.yacc"
      {
	strcpy (yyval.str, "gif");
      }
      break;

    case 1136:
#line 5491 "fgl.yacc"
      {
	strcpy (yyval.str, "png");
      }
      break;

    case 1137:
#line 5492 "fgl.yacc"
      {
	strcpy (yyval.str, "jpeg");
      }
      break;

    case 1138:
#line 5496 "fgl.yacc"
      {
	int vtype;
	vtype = scan_variable (yyvsp[0].str);
	if (vtype != 11 && vtype != 12)
	  {
	    a4gl_yyerror ("Only Blobs may be printed...");
	    YYERROR;
	  }
      }
      break;

    case 1139:
#line 5506 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1140:
#line 5508 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1141:
#line 5513 "fgl.yacc"
      {
	print_report_print (1, 0, yyvsp[0].str);
      }
      break;

    case 1142:
#line 5516 "fgl.yacc"
      {
	print_report_print (1, 0, yyvsp[0].str);	/* changed from $<str>1 */
      }
      break;

    case 1143:
#line 5521 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1144:
#line 5528 "fgl.yacc"
      {
	int a;
	a = add_report_agg ('S', yyvsp[-2].ptr, yyvsp[0].ptr, racnt);
	sprintf (yyval.str, "push_double(_g%d);\n", racnt);
	racnt += a;
      }
      break;

    case 1145:
#line 5535 "fgl.yacc"
      {
	int a;
	a = add_report_agg ('C', 0, yyvsp[0].ptr, racnt);
	sprintf (yyval.str, "push_int(_g%d);\n", racnt);
	racnt += a;
      }
      break;

    case 1146:
#line 5542 "fgl.yacc"
      {
	int a;
	a = add_report_agg ('C', 0, yyvsp[0].ptr, racnt);
	sprintf (yyval.str, "push_int(_g%d);\n", racnt);
	racnt += a;
      }
      break;

    case 1147:
#line 5551 "fgl.yacc"
      {
	int a;
	a = add_report_agg ('P', yyvsp[-2].ptr, yyvsp[0].ptr, racnt);
	sprintf (yyval.str, "push_double((double)_g%d/(double)_g%d);\n",
		 racnt, racnt + 1);
	racnt += a;
      }
      break;

    case 1148:
#line 5558 "fgl.yacc"
      {
	int a;
	a = add_report_agg ('A', yyvsp[-2].ptr, yyvsp[0].ptr, racnt);
	sprintf (yyval.str, "push_double(_g%d/(double)_g%d);\n", racnt,
		 racnt + 1);
	racnt += a;
      }
      break;

    case 1149:
#line 5565 "fgl.yacc"
      {
	int a;
	a = add_report_agg ('A', yyvsp[-2].ptr, yyvsp[0].ptr, racnt);
	sprintf (yyval.str, "push_double(_g%d/_g%d);\n", racnt, racnt + 1);
	racnt += a;
      }
      break;

    case 1150:
#line 5572 "fgl.yacc"
      {
	int a;
	a = add_report_agg ('N', yyvsp[-2].ptr, yyvsp[0].ptr, racnt);
	sprintf (yyval.str, "push_double(_g%d);\n", racnt);
	racnt += a;
      }
      break;

    case 1151:
#line 5579 "fgl.yacc"
      {
	int a;
	a = add_report_agg ('X', yyvsp[-2].ptr, yyvsp[0].ptr, racnt);
	sprintf (yyval.str, "push_double(_g%d);\n", racnt);
	racnt += a;
      }
      break;

    case 1156:
#line 5592 "fgl.yacc"
      {
	rep_struct.left_margin = atoi (yyvsp[0].str);
      }
      break;

    case 1157:
#line 5593 "fgl.yacc"
      {
	rep_struct.right_margin = atoi (yyvsp[0].str);
      }
      break;

    case 1158:
#line 5594 "fgl.yacc"
      {
	rep_struct.top_margin = atoi (yyvsp[0].str);
      }
      break;

    case 1159:
#line 5595 "fgl.yacc"
      {
	rep_struct.bottom_margin = atoi (yyvsp[0].str);
      }
      break;

    case 1160:
#line 5596 "fgl.yacc"
      {
	rep_struct.page_length = atoi (yyvsp[0].str);
      }
      break;

    case 1161:
#line 5597 "fgl.yacc"
      {
	rep_struct.output_mode = 'P';
	strcpy (rep_struct.output_loc, "\"lp\"");
      }
      break;

    case 1162:
#line 5598 "fgl.yacc"
      {
	rep_struct.output_mode = 'F';
	strcpy (rep_struct.output_loc, yyvsp[0].str);
      }
      break;

    case 1163:
#line 5599 "fgl.yacc"
      {
	rep_struct.output_mode = 'F';
	strcpy (rep_struct.output_loc, yyvsp[0].str);
      }
      break;

    case 1164:
#line 5600 "fgl.yacc"
      {
	rep_struct.output_mode = 'P';
	strcpy (rep_struct.output_loc, yyvsp[0].str);
      }
      break;

    case 1165:
#line 5601 "fgl.yacc"
      {
	strcpy (rep_struct.top_of_page, yyvsp[0].str);
      }
      break;

    case 1168:
#line 5607 "fgl.yacc"
      {
	sprintf (yyval.str, "-%f", atof (yyvsp[-1].str));
      }
      break;

    case 1169:
#line 5608 "fgl.yacc"
      {
	sprintf (yyval.str, "-%f", atof (yyvsp[-1].str) * 72.0);
      }
      break;

    case 1170:
#line 5609 "fgl.yacc"
      {
	sprintf (yyval.str, "-%f", atof (yyvsp[-1].str) * 2.83465);
      }
      break;

    case 1171:
#line 5610 "fgl.yacc"
      {
	sprintf (yyval.str, "%f", atof (yyvsp[0].str));
      }
      break;

    case 1176:
#line 5619 "fgl.yacc"
      {
	pdf_rep_struct.left_margin = atof (yyvsp[0].str);
 A4GL_debug ("Left margin=%s\n", yyvsp[0].str);
      }
      break;

    case 1177:
#line 5620 "fgl.yacc"
      {
	pdf_rep_struct.right_margin = atof (yyvsp[0].str);
      }
      break;

    case 1178:
#line 5621 "fgl.yacc"
      {
	pdf_rep_struct.top_margin = atof (yyvsp[0].str);
      }
      break;

    case 1179:
#line 5622 "fgl.yacc"
      {
	pdf_rep_struct.bottom_margin = atof (yyvsp[0].str);
      }
      break;

    case 1180:
#line 5623 "fgl.yacc"
      {
	pdf_rep_struct.page_length = atof (yyvsp[0].str);
      }
      break;

    case 1181:
#line 5624 "fgl.yacc"
      {
	pdf_rep_struct.page_width = atof (yyvsp[0].str);
      }
      break;

    case 1182:
#line 5625 "fgl.yacc"
      {
	strcpy (pdf_rep_struct.font_name, yyvsp[0].str);
      }
      break;

    case 1183:
#line 5626 "fgl.yacc"
      {
	pdf_rep_struct.font_size = atof (yyvsp[0].str);
      }
      break;

    case 1184:
#line 5628 "fgl.yacc"
      {
	pdf_rep_struct.paper_size = 1;
      }
      break;

    case 1185:
#line 5629 "fgl.yacc"
      {
	pdf_rep_struct.paper_size = 2;
      }
      break;

    case 1186:
#line 5630 "fgl.yacc"
      {
	pdf_rep_struct.paper_size = 3;
      }
      break;

    case 1187:
#line 5631 "fgl.yacc"
      {
	pdf_rep_struct.paper_size = 5;
      }
      break;

    case 1188:
#line 5633 "fgl.yacc"
      {
	pdf_rep_struct.paper_size = -1;
      }
      break;

    case 1189:
#line 5634 "fgl.yacc"
      {
	pdf_rep_struct.paper_size = -2;
      }
      break;

    case 1190:
#line 5635 "fgl.yacc"
      {
	pdf_rep_struct.paper_size = -3;
      }
      break;

    case 1191:
#line 5636 "fgl.yacc"
      {
	pdf_rep_struct.paper_size = -5;
      }
      break;

    case 1195:
#line 5641 "fgl.yacc"
      {
	pdf_rep_struct.output_mode = 'F';
	strcpy (pdf_rep_struct.output_loc, yyvsp[0].str);
      }
      break;

    case 1196:
#line 5642 "fgl.yacc"
      {
	pdf_rep_struct.output_mode = 'P';
	strcpy (pdf_rep_struct.output_loc, yyvsp[0].str);
      }
      break;

    case 1200:
#line 5649 "fgl.yacc"
      {
	int a;
	a = print_bind ('O');
	print_order_by_type (2);
	sprintf (yyval.str, "%d", a);
      }
      break;

    case 1201:
#line 5656 "fgl.yacc"
      {
	int a;
	a = print_bind ('O');
	print_order_by_type (1);
	sprintf (yyval.str, "%d", a);
 A4GL_debug ("Order by Gives :%d\n", a);
      }
      break;

    case 1202:
#line 5663 "fgl.yacc"
      {
	int a;
	a = print_bind ('O');
	print_order_by_type (2);
	sprintf (yyval.str, "%d", a);
 A4GL_debug ("Order by Gives :%d\n", a);
      }
      break;

    case 1203:
#line 5674 "fgl.yacc"
      {
	rep_type = REP_TYPE_NORMAL;
	clr_function_constants ();
	clr_variable ();
	lastlineno = yylineno;
	init_report_structure (&rep_struct);
      }
      break;

    case 1204:
#line 5683 "fgl.yacc"
      {
	inc_report_cnt ();
	sprintf (curr_func, "%s", yyvsp[-1].str);
	addmap ("Define Report", curr_func, "MODULE", yylineno, infilename);
	variable_action (-1, yyvsp[-1].str, "", "", "add_function");
	set_curr_rep_name (yyvsp[-1].str);
	print_report_1 (yyvsp[-1].str);
	push_blockcommand ("REPORT");
      }
      break;

    case 1205:
#line 5694 "fgl.yacc"
      {
	lastlineno = yylineno;
      }
      break;

    case 1206:
#line 5698 "fgl.yacc"
      {
	print_variables ();
      }
      break;

    case 1207:
#line 5702 "fgl.yacc"
      {
	print_report_2 (0, yyvsp[0].str);
	rordcnt = atoi (yyvsp[0].str);
 A4GL_debug ("SET rordcnt=%d %s", rordcnt, yyvsp[0].str);
      }
      break;

    case 1208:
#line 5708 "fgl.yacc"
      {
	print_report_ctrl ();
      }
      break;

    case 1209:
#line 5713 "fgl.yacc"
      {
	pop_blockcommand ("REPORT");
	print_report_end ();
      }
      break;

    case 1210:
#line 5721 "fgl.yacc"
      {
	strcpy (yyval.str, "");
	yyval.ptr = 0;
      }
      break;

    case 1211:
#line 5724 "fgl.yacc"
      {
	yyval.ptr = yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
      }
      break;

    case 1212:
#line 5733 "fgl.yacc"
      {
	if (!in_command ("REPORT"))
	  {
	    a4gl_yyerror ("PAUSE can only be used in reportes");
	    YYERROR;
	  }

	print_pause (yyvsp[0].str);
      }
      break;

    case 1213:
#line 5744 "fgl.yacc"
      {
	strcpy (yyval.str, "\"\"");
      }
      break;

    case 1215:
#line 5751 "fgl.yacc"
      {
	rep_type = REP_TYPE_PDF;
	clr_function_constants ();
	clr_variable ();
	lastlineno = yylineno;
	pdf_init_report_structure (&pdf_rep_struct);
      }
      break;

    case 1216:
#line 5759 "fgl.yacc"
      {
	inc_report_cnt ();
	variable_action (-1, yyvsp[-1].str, "", "", "add_function");
	sprintf (curr_func, "%s", yyvsp[-1].str);
	addmap ("Define PDF Report", curr_func, "MODULE", yylineno,
		infilename);
	set_curr_rep_name (yyvsp[-1].str);
	print_report_1 (yyvsp[-1].str);
	push_blockcommand ("REPORT");
      }
      break;

    case 1217:
#line 5769 "fgl.yacc"
      {
	lastlineno = yylineno;
      }
      break;

    case 1218:
#line 5772 "fgl.yacc"
      {
	print_variables ();
      }
      break;

    case 1219:
#line 5776 "fgl.yacc"
      {
//print_variables();
	resize_paper (&pdf_rep_struct);
	print_report_2 (1, yyvsp[0].str);
 A4GL_debug ("SET rordcnt=%d (%s)", rordcnt, yyvsp[0].str);
	rordcnt = atoi (yyvsp[0].str);
      }
      break;

    case 1220:
#line 5784 "fgl.yacc"
      {
	print_report_ctrl ();
      }
      break;

    case 1221:
#line 5787 "fgl.yacc"
      {
	pop_blockcommand ("REPORT");
	print_report_end ();
      }
      break;

    case 1222:
#line 5793 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1223:
#line 5797 "fgl.yacc"
      {
	new_counter ();
	addmap ("CALL", yyvsp[-1].str, curr_func, yylineno, infilename);
      }
      break;

    case 1224:
#line 5801 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", get_counter_val ());
	drop_counter ();
      }
      break;

    case 1225:
#line 5805 "fgl.yacc"
      {
	print_pdf_call (yyvsp[-5].str, yyvsp[-2].ptr, yyvsp[-1].str);
      }
      break;

    case 1226:
#line 5809 "fgl.yacc"
      {
	print_returning ();
      }
      break;

    case 1227:
#line 5815 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1228:
#line 5816 "fgl.yacc"
      {
	strcpy (yyval.str, "rep.right_margin");
      }
      break;

    case 1229:
#line 5817 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 1230:
#line 5818 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 1231:
#line 5823 "fgl.yacc"
      {
	print_system_run (0, 0);
      }
      break;

    case 1232:
#line 5825 "fgl.yacc"
      {
	print_system_run (1, yyvsp[0].str);
      }
      break;

    case 1233:
#line 5828 "fgl.yacc"
      {
	print_system_run (2, 0);
      }
      break;

    case 1234:
#line 5832 "fgl.yacc"
      {
	print_system_run (0, 0);
      }
      break;

    case 1235:
#line 5835 "fgl.yacc"
      {
	print_system_run (0, 0);
/* FIXME */
      }
      break;

    case 1236:
#line 5842 "fgl.yacc"
      {
	print_exec_sql (yyvsp[0].str);
      }
      break;

    case 1237:
#line 5847 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 1238:
#line 5848 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 1239:
#line 5849 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 1240:
#line 5854 "fgl.yacc"
      {
	print_exec_sql (yyvsp[0].str);
      }
      break;

    case 1241:
#line 5855 "fgl.yacc"
      {
	print_exec_sql (yyvsp[0].sql_string);
	free (yyvsp[0].sql_string);
      }
      break;

    case 1242:
#line 5861 "fgl.yacc"
      {
	insql = 1;
      }
      break;

    case 1243:
#line 5861 "fgl.yacc"
      {
	insql = 0;
      }
      break;

    case 1244:
#line 5861 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-6].str, " ", yyvsp[-4].str, " ",
			   yyvsp[-3].str, yyvsp[-1].sql_string, yyvsp[0].str,
			   0);
	free (yyvsp[-1].sql_string);
      }
      break;

    case 1245:
#line 5866 "fgl.yacc"
      {
	insql = 1;
      }
      break;

    case 1246:
#line 5866 "fgl.yacc"
      {
	insql = 0;
      }
      break;

    case 1247:
#line 5866 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-7].str, " ", yyvsp[-5].str, " ",
			   yyvsp[-4].str, yyvsp[-2].sql_string, yyvsp[-1].str,
			   " ", yyvsp[0].str, 0);
	free (yyvsp[-2].sql_string);

      }
      break;

    case 1248:
#line 5877 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1249:
#line 5878 "fgl.yacc"
      {
	a4gl_yyerror
	  ("You cannot create a database from within Aubit4gl....");
      }
      break;

    case 1250:
#line 5884 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1251:
#line 5886 "fgl.yacc"
      {
	sprintf (yyval.str, " %s ", yyvsp[0].str);
      }
      break;

    case 1253:
#line 5893 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1254:
#line 5897 "fgl.yacc"
      {
	sprintf (yyval.str, "%s ASC", yyvsp[-1].str);
      }
      break;

    case 1255:
#line 5898 "fgl.yacc"
      {
	sprintf (yyval.str, "%s DESC", yyvsp[-1].str);
      }
      break;

    case 1257:
#line 5903 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1258:
#line 5906 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1259:
#line 5912 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1260:
#line 5915 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1261:
#line 5923 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1263:
#line 5930 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].str, " ", yyvsp[-1].str, " ",
			   yyvsp[0].sql_string, 0);
	print_exec_sql (yyval.sql_string);
      }
      break;

    case 1264:
#line 5937 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1265:
#line 5940 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1266:
#line 5949 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1267:
#line 5952 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1268:
#line 5955 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1269:
#line 5958 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1270:
#line 5961 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1271:
#line 5964 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1272:
#line 5967 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1273:
#line 5974 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("ADD ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1274:
#line 5977 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("ADD (", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1275:
#line 5984 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1276:
#line 5987 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, " BEFORE ", yyvsp[0].str, 0);
      }
      break;

    case 1277:
#line 5993 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1278:
#line 5996 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1279:
#line 6003 "fgl.yacc"
      {
	sprintf (yyval.str, "DROP %s", yyvsp[0].str);
      }
      break;

    case 1280:
#line 6006 "fgl.yacc"
      {
	sprintf (yyval.str, "DROP (%s)", yyvsp[-1].str);
      }
      break;

    case 1282:
#line 6014 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1284:
#line 6023 "fgl.yacc"
      {
	sprintf (yyval.str, "MODIFY %s", yyvsp[0].sql_string);
      }
      break;

    case 1285:
#line 6026 "fgl.yacc"
      {
	sprintf (yyval.str, "MODIFY (%s)", yyvsp[-1].sql_string);
      }
      break;

    case 1286:
#line 6032 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1287:
#line 6035 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1288:
#line 6041 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1289:
#line 6048 "fgl.yacc"
      {
	strcpy (yyval.str, "LOCK MODE PAGE");
      }
      break;

    case 1290:
#line 6049 "fgl.yacc"
      {
	strcpy (yyval.str, "LOCK MODE ROW");
      }
      break;

    case 1291:
#line 6053 "fgl.yacc"
      {
	sprintf (yyval.str, "MODIFT NEXT SIZE %d", atoi (yyvsp[0].str));
      }
      break;

    case 1292:
#line 6059 "fgl.yacc"
      {
	sprintf (yyval.str, "ADD CONSTRAINT %s", yyvsp[0].sql_string);
      }
      break;

    case 1293:
#line 6062 "fgl.yacc"
      {
	sprintf (yyval.str, "ADD CONSTRAINT (%s)", yyvsp[-1].sql_string);
      }
      break;

    case 1295:
#line 6070 "fgl.yacc"
      {
	sprintf (yyval.str, "ADD CONSTRAINT (%s)", yyvsp[-1].sql_string);
      }
      break;

    case 1296:
#line 6077 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1297:
#line 6080 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1301:
#line 6098 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s /*FIXME */", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1307:
#line 6104 "fgl.yacc"
      {
	print_set_conn (yyvsp[0].str);
      }
      break;

    case 1308:
#line 6107 "fgl.yacc"
      {
	print_set_options ("conn", yyvsp[-4].str, yyvsp[-2].str,
			   yyvsp[0].str);
      }
      break;

    case 1309:
#line 6110 "fgl.yacc"
      {
	print_set_options ("stmt", yyvsp[-4].str, yyvsp[-2].str,
			   yyvsp[0].str);
      }
      break;

    case 1310:
#line 6116 "fgl.yacc"
      {
	strcpy (yyval.str, "\"default\"");
      }
      break;

    case 1312:
#line 6122 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1314:
#line 6133 "fgl.yacc"
      {
	print_sleep ();
      }
      break;

    case 1315:
#line 6147 "fgl.yacc"
      {
	print_sql_commit (0);
      }
      break;

    case 1316:
#line 6156 "fgl.yacc"
      {
	insql = 1;
	start_bind ('i', 0);
      }
      break;

    case 1317:
#line 6156 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-4].str, " ", yyvsp[-2].str, " ",
			   yyvsp[-1].str, " ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1318:
#line 6161 "fgl.yacc"
      {
	insql = 1;
      }
      break;

    case 1319:
#line 6161 "fgl.yacc"
      {
	insql = 0;
	//printf("Value = %s\n",$<sql_string>4);
	yyval.sql_string =
	  make_sql_string (yyvsp[-4].str, " (", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1320:
#line 6166 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1321:
#line 6169 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1322:
#line 6171 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1324:
#line 6178 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1325:
#line 6182 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
      }
      break;

    case 1326:
#line 6186 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
      }
      break;

    case 1327:
#line 6193 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1328:
#line 6196 "fgl.yacc"
      {
	yyval.sql_string = strdup ("NULL");
      }
      break;

    case 1329:
#line 6203 "fgl.yacc"
      {
	print_fetch_1 ();
      }
      break;

    case 1330:
#line 6207 "fgl.yacc"
      {
	print_fetch_2 ();
      }
      break;

    case 1331:
#line 6211 "fgl.yacc"
      {
	print_fetch_3 (yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1332:
#line 6220 "fgl.yacc"
      {
	sprintf (yyval.str, "%s, %s", yyvsp[0].str, yyvsp[-1].str);
	addmap ("Fetch Cursor", yyvsp[0].str, curr_func, yylineno,
		infilename);
      }
      break;

    case 1333:
#line 6224 "fgl.yacc"
      {
	sprintf (yyval.str, "%s, %d, 1", yyvsp[0].str, FETCH_RELATIVE);

	addmap ("Fetch Cursor", yyvsp[0].str, curr_func, yylineno,
		infilename);
      }
      break;

    case 1334:
#line 6230 "fgl.yacc"
      {
 A4GL_debug ("no into\n");
	strcpy (yyval.str, "0,0");
      }
      break;

    case 1335:
#line 6234 "fgl.yacc"
      {
 A4GL_debug ("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
	start_bind ('o', 0);
      }
      break;

    case 1336:
#line 6240 "fgl.yacc"
      {
	int no;
	no = print_bind ('o');
	sprintf (yyval.str, "%d,obind", no);
      }
      break;

    case 1337:
#line 6247 "fgl.yacc"
      {
 A4GL_debug ("no into\n");
	strcpy (yyval.str, "0,0");
      }
      break;

    case 1338:
#line 6251 "fgl.yacc"
      {
 A4GL_debug ("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
	start_bind ('o', 0);
      }
      break;

    case 1339:
#line 6256 "fgl.yacc"
      {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
      }
      break;

    case 1340:
#line 6266 "fgl.yacc"
      {
	sprintf (yyval.str, "%d,1", FETCH_ABSOLUTE);
      }
      break;

    case 1341:
#line 6269 "fgl.yacc"
      {
	sprintf (yyval.str, "%d,-1", FETCH_ABSOLUTE);
      }
      break;

    case 1342:
#line 6271 "fgl.yacc"
      {
	sprintf (yyval.str, "%d,1", FETCH_RELATIVE);
      }
      break;

    case 1343:
#line 6273 "fgl.yacc"
      {
	sprintf (yyval.str, "%d,-1", FETCH_RELATIVE);
      }
      break;

    case 1344:
#line 6275 "fgl.yacc"
      {
	sprintf (yyval.str, "%d,-1", FETCH_RELATIVE);
      }
      break;

    case 1345:
#line 6277 "fgl.yacc"
      {
	sprintf (yyval.str, "%d,0", FETCH_RELATIVE);
      }
      break;

    case 1346:
#line 6279 "fgl.yacc"
      {
	sprintf (yyval.str, "%d,pop_int()", FETCH_RELATIVE);
      }
      break;

    case 1347:
#line 6281 "fgl.yacc"
      {
	sprintf (yyval.str, "%d,pop_int()", FETCH_ABSOLUTE);
      }
      break;

    case 1348:
#line 6287 "fgl.yacc"
      {

	rm_quotes (yyvsp[0].str);
	sprintf (yyval.str, " %s %s %s %s ", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1349:
#line 6297 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].str, " ", yyvsp[-1].str, " ",
			   yyvsp[0].sql_string, 0);
      }
      break;

    case 1350:
#line 6304 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1352:
#line 6310 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1356:
#line 6319 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1359:
#line 6324 "fgl.yacc"
      {
	print_sql_commit (-1);
      }
      break;

    case 1360:
#line 6329 "fgl.yacc"
      {
	print_sql_commit (1);
      }
      break;

    case 1361:
#line 6336 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1362:
#line 6337 "fgl.yacc"
      {
	strcpy (yyval.str, "EXCLUSIVE");
      }
      break;

    case 1363:
#line 6344 "fgl.yacc"
      {
	if (strcmp (yyvsp[-1].str, "?") == 0)
	  {
	    print_init_conn (0);
	  }
	else
	  {
	    print_init_conn (yyvsp[-1].str);
	  }
      }
      break;

    case 1364:
#line 6356 "fgl.yacc"
      {
	insql = 1;
      }
      break;

    case 1365:
#line 6356 "fgl.yacc"
      {
	print_undo_use (yyvsp[-2].str);
	insql = 0;
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1366:
#line 6361 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*  schema */\n");
	print_exec_sql (yyvsp[0].sql_string);
	strcpy (yyval.str, "Schema");
      }
      break;

    case 1367:
#line 6366 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*  schema  2*/\n");
	print_exec_sql (yyvsp[0].sql_string);
	strcpy (yyval.str, "Schema Element");
      }
      break;

    case 1369:
#line 6372 "fgl.yacc"
      {
	print_exec_sql (yyvsp[0].str);
      }
      break;

    case 1371:
#line 6376 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*  delete 1 */\n");
	print_exec_sql_bound (yyvsp[0].str);
	strcpy (yyval.str, "Delete where current...");
      }
      break;

    case 1372:
#line 6381 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*  delete 2 */\n");
	print_exec_sql_bound (yyvsp[0].sql_string);
	strcpy (yyval.str, "Delete where ...");
      }
      break;

    case 1373:
#line 6386 "fgl.yacc"
      {
	strcpy (yyval.str, "Fetch");
 A4GL_lex_printcomment ("/*  fetch */\n");
      }
      break;

    case 1374:
#line 6390 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/*  insert */\n");
	print_exec_sql_bound (yyvsp[0].sql_string);
	strcpy (yyval.str, "insert");
      }
      break;

    case 1376:
#line 6396 "fgl.yacc"
      {
	print_do_select (yyvsp[0].sql_string);
	strcpy (yyval.str, "select");
      }
      break;

    case 1377:
#line 6400 "fgl.yacc"
      {
	print_exec_sql_bound (yyvsp[0].sql_string);
	strcpy (yyval.str, "update");
      }
      break;

    case 1378:
#line 6408 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s %s %s %s", yyvsp[-6].str,
		 yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1379:
#line 6411 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1380:
#line 6413 "fgl.yacc"
      {
	sprintf (yyval.str, " %s ", yyvsp[0].str);
      }
      break;

    case 1381:
#line 6418 "fgl.yacc"
      {
	sprintf (yyval.str, " %s ", yyvsp[0].str);
      }
      break;

    case 1384:
#line 6425 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1388:
#line 6432 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1389:
#line 6435 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1390:
#line 6437 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1392:
#line 6443 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1394:
#line 6449 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1397:
#line 6459 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-5].str, " ", yyvsp[-4].str, " ",
			   yyvsp[-3].str, " ", yyvsp[-2].str, " ",
			   yyvsp[-1].sql_string, " ", yyvsp[0].str, 0);
      }
      break;

    case 1398:
#line 6464 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1399:
#line 6466 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1401:
#line 6472 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1402:
#line 6475 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1404:
#line 6481 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("CHECK(", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1405:
#line 6489 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str,
		 yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1406:
#line 6494 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1409:
#line 6504 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1411:
#line 6510 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1412:
#line 6516 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1413:
#line 6518 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1415:
#line 6524 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1416:
#line 6529 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1417:
#line 6532 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1418:
#line 6535 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1419:
#line 6543 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1420:
#line 6545 "fgl.yacc"
      {
	sprintf (yyval.str, " %s", yyvsp[0].str);
      }
      break;

    case 1421:
#line 6556 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].str, " ", yyvsp[-2].str, " ",
			   yyvsp[-1].str, " ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1422:
#line 6561 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1424:
#line 6565 "fgl.yacc"
      {
	yyval.sql_string = strdup ("");
      }
      break;

    case 1425:
#line 6567 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1426:
#line 6574 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1427:
#line 6577 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].sql_string, yyvsp[0].sql_string, 0);
      }
      break;

    case 1428:
#line 6583 "fgl.yacc"
      {
	sprintf (yyval.str, " %s ", yyvsp[0].str);
	yyval.sql_string = strdup (yyval.str);
      }
      break;

    case 1429:
#line 6587 "fgl.yacc"
      {
	sprintf (yyval.str, " %s ", yyvsp[0].str);
	yyval.sql_string = strdup (yyval.str);
      }
      break;

    case 1430:
#line 6591 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1431:
#line 6594 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].str, " ", yyvsp[-2].str, " ",
			   yyvsp[-1].sql_string, " ", yyvsp[0].str, 0);
      }
      break;

    case 1432:
#line 6602 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].str, " ", yyvsp[-1].str, " ",
			   yyvsp[0].str, 0);
      }
      break;

    case 1433:
#line 6609 "fgl.yacc"
      {
	sprintf (yyval.str, " %s", yyvsp[0].str);
      }
      break;

    case 1436:
#line 6618 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].sql_string, " ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1437:
#line 6624 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1438:
#line 6627 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1439:
#line 6638 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].str, " ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1440:
#line 6645 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("GROUP BY ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1441:
#line 6651 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1442:
#line 6654 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1443:
#line 6661 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("WHERE ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1444:
#line 6668 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1446:
#line 6675 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1447:
#line 6681 "fgl.yacc"
      {
	sprintf (yyval.str, " %s ", yyvsp[0].str);
      }
      break;

    case 1448:
#line 6682 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s ", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1449:
#line 6683 "fgl.yacc"
      {
	sprintf (yyval.str, " %s (%s) ", yyvsp[-3].str, yyvsp[-1].str);
      }
      break;

    case 1451:
#line 6687 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1453:
#line 6692 "fgl.yacc"
      {
	sprintf (yyval.str, " %s,%s ", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1454:
#line 6699 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].str, " ", yyvsp[-2].sql_string, " ",
			   yyvsp[-1].sql_string, " ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1455:
#line 6704 "fgl.yacc"
      {
	yyval.sql_string = strdup ("");
      }
      break;

    case 1456:
#line 6705 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1457:
#line 6708 "fgl.yacc"
      {
	yyval.sql_string = strdup ("");
      }
      break;

    case 1458:
#line 6711 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1459:
#line 6716 "fgl.yacc"
      {
	yyval.sql_string = strdup ("");
      }
      break;

    case 1460:
#line 6717 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1461:
#line 6722 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1462:
#line 6725 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, " OR ", yyvsp[0].sql_string,
			   0);
      }
      break;

    case 1463:
#line 6731 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1464:
#line 6734 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, " AND ", yyvsp[0].sql_string,
			   0);
      }
      break;

    case 1465:
#line 6740 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1466:
#line 6743 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].str, " ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1467:
#line 6749 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1468:
#line 6752 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].str, yyvsp[-1].sql_string, yyvsp[0].str,
			   0);
      }
      break;

    case 1469:
#line 6759 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].str, " ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1470:
#line 6760 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].str, " ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1471:
#line 6789 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1472:
#line 6791 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1476:
#line 6805 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-4].sql_string, " IN (", yyvsp[-1].str, ")",
			   0);
      }
      break;

    case 1477:
#line 6808 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, " ", yyvsp[-1].str, " ",
			   yyvsp[0].sql_string, 0);
      }
      break;

    case 1478:
#line 6811 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-4].sql_string, " NOT IN (", yyvsp[-1].str,
			   ")", 0);
      }
      break;

    case 1479:
#line 6814 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, " ", yyvsp[-1].str, " ",
			   yyvsp[0].sql_string, 0);
      }
      break;

    case 1481:
#line 6822 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1482:
#line 6825 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].sql_string);
      }
      break;

    case 1484:
#line 6831 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1486:
#line 6837 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, yyvsp[-1].str, " IS NULL",
			   0);
      }
      break;

    case 1487:
#line 6840 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, yyvsp[-1].str,
			   " IS NOT NULL", 0);
      }
      break;

    case 1488:
#line 6843 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, " ", yyvsp[-1].str, " ",
			   yyvsp[0].sql_string, 0);
      }
      break;

    case 1489:
#line 6846 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-5].sql_string, yyvsp[-4].str, " BETWEEN ",
			   yyvsp[-2].sql_string, " AND ", yyvsp[0].sql_string,
			   0);
      }
      break;

    case 1490:
#line 6849 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].sql_string, " ", yyvsp[-2].str, " ",
			   yyvsp[-1].str, yyvsp[0].str, 0);
      }
      break;

    case 1491:
#line 6852 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].sql_string, " ", yyvsp[-2].str, " ",
			   yyvsp[-1].str, yyvsp[0].str, 0);
      }
      break;

    case 1492:
#line 6855 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-4].sql_string, yyvsp[-3].str, " MATCHES ",
			   yyvsp[-1].str, yyvsp[0].str, 0);
      }
      break;

    case 1494:
#line 6862 "fgl.yacc"
      {
	strcpy (yyval.str, "!=");
      }
      break;

    case 1499:
#line 6869 "fgl.yacc"
      {
	strcpy (yyval.str, "<=");
      }
      break;

    case 1500:
#line 6870 "fgl.yacc"
      {
	strcpy (yyval.str, ">=");
      }
      break;

    case 1501:
#line 6875 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1502:
#line 6878 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1503:
#line 6882 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1504:
#line 6888 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1505:
#line 6889 "fgl.yacc"
      {
	strcpy (yyval.str, " ALL ");
      }
      break;

    case 1506:
#line 6890 "fgl.yacc"
      {
	strcpy (yyval.str, " DISTINCT ");
      }
      break;

    case 1507:
#line 6891 "fgl.yacc"
      {
	ansi_violation ("Use DISTINCT not UNIQUE", 0);
	strcpy (yyval.str, " DISTINCT ");
      }
      break;

    case 1512:
#line 6911 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1513:
#line 6916 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str,
		 yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1514:
#line 6917 "fgl.yacc"
      {
	strcpy (yyval.str, "SERIAL");
      }
      break;

    case 1516:
#line 6920 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str,
		 yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1520:
#line 6925 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1522:
#line 6928 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1524:
#line 6931 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s %s %s %s", yyvsp[-6].str,
		 yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1528:
#line 6936 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1529:
#line 6938 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s %s %s", yyvsp[-5].str,
		 yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1530:
#line 6941 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1531:
#line 6942 "fgl.yacc"
      {
	sprintf (yyval.str, ",%s", yyvsp[0].str);
      }
      break;

    case 1532:
#line 6949 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1536:
#line 6954 "fgl.yacc"
      {
	sprintf (yyval.str, " %s", yyvsp[0].str);
      }
      break;

    case 1540:
#line 6970 "fgl.yacc"
      {
	sprintf (yyval.str, "\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),
		 yyvsp[-1].str, yyvsp[0].str);
	addmap ("Use Table", yyval.str, curr_func, yylineno, infilename);
      }
      break;

    case 1541:
#line 6971 "fgl.yacc"
      {
	sprintf (yyval.str, " %s", A4GL_strip_quotes (yyvsp[0].str));
	addmap ("Use Table", yyval.str, curr_func, yylineno, infilename);
      }
      break;

    case 1542:
#line 6975 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
	addmap ("Use Table", yyvsp[0].str, curr_func, yylineno, infilename);
      }
      break;

    case 1543:
#line 6976 "fgl.yacc"
      {
	sprintf (yyval.str, " %s%s%s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
	addmap ("Use Table", yyval.str, curr_func, yylineno, infilename);
      }
      break;

    case 1545:
#line 6994 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1546:
#line 6995 "fgl.yacc"
      {
	sprintf (yyval.str, "[%s]", yyvsp[-1].str);
      }
      break;

    case 1547:
#line 6996 "fgl.yacc"
      {
	sprintf (yyval.str, "[%s,%s]", yyvsp[-3].str, yyvsp[-1].str);
      }
      break;

    case 1548:
#line 7000 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1549:
#line 7003 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1550:
#line 7009 "fgl.yacc"
      {
	addmap ("Use Column", yyvsp[-1].str, curr_func, yylineno, infilename);
	sprintf (yyval.str, "%s%s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1551:
#line 7014 "fgl.yacc"
      {
	sprintf (yyval.str, "%s.%s%s", yyvsp[-3].str, yyvsp[-1].str,
		 yyvsp[0].str);
	addmap ("Use Column", yyval.str, curr_func, yylineno, infilename);
      }
      break;

    case 1552:
#line 7019 "fgl.yacc"
      {
	sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str);
	addmap ("Use Column", yyval.str, curr_func, yylineno, infilename);
      }
      break;

    case 1554:
#line 7030 "fgl.yacc"
      {
	strcpy (yyval.str, convstrsql (yyvsp[0].str));
 A4GL_debug ("Set $<str>$ to %s\n", yyval.str);
      }
      break;

    case 1559:
#line 7045 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1560:
#line 7048 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s ", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1561:
#line 7051 "fgl.yacc"
      {
	strcpy (yyval.str, " YEAR TO SECOND ");
      }
      break;

    case 1562:
#line 7053 "fgl.yacc"
      {
	sprintf (yyval.str, " %s %s %s", yyvsp[-2].str, yyvsp[-1].str,
		 yyvsp[0].str);
      }
      break;

    case 1563:
#line 7056 "fgl.yacc"
      {
	strcpy (yyval.str, "1,10");
      }
      break;

    case 1564:
#line 7058 "fgl.yacc"
      {
	sprintf (yyval.str, " %s ,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1565:
#line 7061 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1566:
#line 7061 "fgl.yacc"
      {
	strcpy (yyval.str, "2");
      }
      break;

    case 1567:
#line 7061 "fgl.yacc"
      {
	strcpy (yyval.str, "3");
      }
      break;

    case 1568:
#line 7061 "fgl.yacc"
      {
	strcpy (yyval.str, "4");
      }
      break;

    case 1569:
#line 7061 "fgl.yacc"
      {
	strcpy (yyval.str, "5");
      }
      break;

    case 1570:
#line 7061 "fgl.yacc"
      {
	strcpy (yyval.str, "6");
      }
      break;

    case 1571:
#line 7062 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", 6 + 2);
      }
      break;

    case 1572:
#line 7065 "fgl.yacc"
      {
	sprintf (yyval.str, "%d", atoi (yyvsp[-1].str) + 6);
      }
      break;

    case 1573:
#line 7070 "fgl.yacc"
      {
	strcpy (yyval.str, "4");
      }
      break;

    case 1574:
#line 7070 "fgl.yacc"
      {
	strcpy (yyval.str, "7");
      }
      break;

    case 1575:
#line 7070 "fgl.yacc"
      {
	strcpy (yyval.str, "10");
      }
      break;

    case 1576:
#line 7070 "fgl.yacc"
      {
	strcpy (yyval.str, "13");
      }
      break;

    case 1577:
#line 7070 "fgl.yacc"
      {
	strcpy (yyval.str, "16");
      }
      break;

    case 1578:
#line 7070 "fgl.yacc"
      {
	strcpy (yyval.str, "19");
      }
      break;

    case 1579:
#line 7072 "fgl.yacc"
      {
	strcpy (yyval.str, "25");
      }
      break;

    case 1580:
#line 7075 "fgl.yacc"
      {
	strcpy (yyval.str, "25");
      }
      break;

    case 1595:
#line 7084 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1596:
#line 7085 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1597:
#line 7089 "fgl.yacc"
      {
	print_flush_cursor (yyvsp[0].str);
	addmap ("Flush Cursor", yyvsp[0].str, curr_func, yylineno,
		infilename);
	print_undo_use (yyvsp[-2].str);
      }
      break;

    case 1598:
#line 7097 "fgl.yacc"
      {
	insql = 0;
	chk4var = 0;
      }
      break;

    case 1599:
#line 7097 "fgl.yacc"
      {
	print_declare (yyvsp[0].str, yyvsp[-2].sql_string, yyvsp[-5].str, 0,
		       0);
	addmap ("Declare Cursor", yyvsp[-5].str, curr_func, yylineno,
		infilename);
	print_undo_use (yyvsp[-7].str);
      }
      break;

    case 1600:
#line 7102 "fgl.yacc"
      {
	insql = 0;
	chk4var = 0;
      }
      break;

    case 1601:
#line 7102 "fgl.yacc"
      {
	print_declare (yyvsp[0].str, yyvsp[-2].sql_string, yyvsp[-6].str, 2,
		       0);
	addmap ("Declare Cursor", yyvsp[-6].str, curr_func, yylineno,
		infilename);
	print_undo_use (yyvsp[-8].str);
      }
      break;

    case 1602:
#line 7108 "fgl.yacc"
      {
	insql = 0;
	chk4var = 0;
      }
      break;

    case 1603:
#line 7108 "fgl.yacc"
      {
	print_declare (yyvsp[0].str, yyvsp[-2].sql_string, yyvsp[-4].str, 0,
		       1);
	addmap ("Declare Cursor", yyvsp[-4].str, curr_func, yylineno,
		infilename);
	print_undo_use (yyvsp[-6].str);
      }
      break;

    case 1604:
#line 7113 "fgl.yacc"
      {
	insql = 0;
	chk4var = 0;
      }
      break;

    case 1605:
#line 7113 "fgl.yacc"
      {
	print_declare (yyvsp[0].str, yyvsp[-2].sql_string, yyvsp[-6].str, 2,
		       1);
	addmap ("Declare Cursor", yyvsp[-6].str, curr_func, yylineno,
		infilename);
	print_undo_use (yyvsp[-8].str);
      }
      break;

    case 1606:
#line 7120 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1607:
#line 7121 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1608:
#line 7122 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1612:
#line 7129 "fgl.yacc"
      {
	sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1613:
#line 7130 "fgl.yacc"
      {
	sprintf (yyval.str, "\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),
		 yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1614:
#line 7135 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1615:
#line 7138 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (print_curr_spec (1, yyvsp[0].sql_string), 0);
      }
      break;

    case 1616:
#line 7144 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (print_curr_spec (2, yyvsp[0].str), 0);
      }
      break;

    case 1617:
#line 7147 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1618:
#line 7156 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[-1].sql_string;
	if (atoi (yyvsp[0].str))
	  {
	    printf
	      ("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	  }
      }
      break;

    case 1619:
#line 7168 "fgl.yacc"
      {
	start_bind ('i', 0);
      }
      break;

    case 1620:
#line 7169 "fgl.yacc"
      {
 A4GL_debug ("Got select list...\n");
      }
      break;

    case 1621:
#line 7172 "fgl.yacc"
      {
	char *ptr;
	ptr =
	  make_sql_string ("SELECT ", yyvsp[-6].str, yyvsp[-4].sql_string,
			   " ", yyvsp[-2].sql_string, " ",
			   yyvsp[-1].sql_string, " ", yyvsp[0].sql_string, 0);

	yyval.sql_string = strdup (print_select_all (ptr));
	free (ptr);
	free (yyvsp[-4].sql_string);
	free (yyvsp[-2].sql_string);
	free (yyvsp[-1].sql_string);
	free (yyvsp[0].sql_string);
      }
      break;

    case 1622:
#line 7187 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("push_char(\"", yyvsp[-4].str, " ", yyvsp[-3].str,
			   " ", yyvsp[-2].sql_string, " ",
			   yyvsp[-1].sql_string, " ", yyvsp[0].sql_string,
			   "\");", 0);
	free (yyvsp[-2].sql_string);
	free (yyvsp[-1].sql_string);
	free (yyvsp[0].sql_string);
      }
      break;

    case 1623:
#line 7197 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1624:
#line 7200 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1625:
#line 7208 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-5].str, " ", yyvsp[-4].str, " ",
			   yyvsp[-3].sql_string, " ", yyvsp[-2].sql_string,
			   " ", yyvsp[-1].sql_string, " ",
			   yyvsp[0].sql_string, 0);
	free (yyvsp[-3].sql_string);
	free (yyvsp[-1].sql_string);
	free (yyvsp[0].sql_string);
      }
      break;

    case 1626:
#line 7217 "fgl.yacc"
      {
	yyval.sql_string = strdup ("");
      }
      break;

    case 1627:
#line 7220 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* UNION */");
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].str, " ", yyvsp[-1].str, " ",
			   yyvsp[0].sql_string, 0);
      }
      break;

    case 1628:
#line 7224 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1629:
#line 7227 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].str, " ", yyvsp[-1].str, " ",
			   yyvsp[0].str, 0);
      }
      break;

    case 1630:
#line 7228 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].str, " ", yyvsp[-2].str, " ",
			   yyvsp[-1].str, " ", yyvsp[0].str, 0);
      }
      break;

    case 1632:
#line 7237 "fgl.yacc"
      {
	start_bind ('o', 0);
	yyval.sql_string = make_sql_string ("", 0);
      }
      break;

    case 1633:
#line 7238 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (A4GL_get_into_part (get_bind_cnt ('o')), 0);

      }
      break;

    case 1634:
#line 7247 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].str, " ", yyvsp[-2].str, " ",
			   yyvsp[-1].sql_string, " ", yyvsp[0].sql_string, 0);
	free (yyvsp[-1].sql_string);
	free (yyvsp[0].sql_string);

      }
      break;

    case 1635:
#line 7256 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("(", yyvsp[-4].str, " ", yyvsp[-3].str, " ",
			   yyvsp[-2].sql_string, " ", yyvsp[-1].sql_string,
			   ")", 0);
      }
      break;

    case 1636:
#line 7261 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1637:
#line 7262 "fgl.yacc"
      {
	strcpy (yyval.str, "ALL");
      }
      break;

    case 1638:
#line 7263 "fgl.yacc"
      {
	strcpy (yyval.str, "DISTINCT");
      }
      break;

    case 1639:
#line 7264 "fgl.yacc"
      {
	strcpy (yyval.str, "DISTINCT");
	ansi_violation ("Use DISTINCT not UNIQUE", 0);
	strcpy (yyval.str, "DISTINCT ");

      }
      break;

    case 1640:
#line 7272 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1641:
#line 7275 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1642:
#line 7281 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1643:
#line 7284 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].sql_string, yyvsp[0].str, 0);
      }
      break;

    case 1644:
#line 7287 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].sql_string, yyvsp[0].str, 0);
      }
      break;

    case 1645:
#line 7293 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1646:
#line 7302 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1647:
#line 7305 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("-", yyvsp[0].sql_string, 0);
      }
      break;

    case 1648:
#line 7308 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("+", yyvsp[0].sql_string, 0);
      }
      break;

    case 1649:
#line 7314 "fgl.yacc"
      {
	if (strlen (current_upd_table))
	  {
	    push_gen (UPDVAL, yyvsp[0].sql_string);
	  }
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1650:
#line 7320 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1651:
#line 7323 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1652:
#line 7326 "fgl.yacc"
      {
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1653:
#line 7329 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string (yyvsp[-2].str, ".", yyvsp[0].str);
      }
      break;

    case 1654:
#line 7336 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, "/", yyvsp[0].sql_string, 0);
      }
      break;

    case 1655:
#line 7338 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].sql_string, yyvsp[0].str, 0);
      }
      break;

    case 1656:
#line 7340 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, "*", yyvsp[0].sql_string, 0);
      }
      break;

    case 1657:
#line 7342 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, "+", yyvsp[0].sql_string, 0);
      }
      break;

    case 1658:
#line 7344 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, "-", yyvsp[0].sql_string, 0);
      }
      break;

    case 1659:
#line 7345 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string (yyvsp[0].str, 0);
      }
      break;

    case 1660:
#line 7346 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("TRUE", 0);
      }
      break;

    case 1661:
#line 7347 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("FALSE", 0);
      }
      break;

    case 1662:
#line 7348 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("USER", 0);
      }
      break;

    case 1663:
#line 7349 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("*", 0);
      }
      break;

    case 1664:
#line 7350 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("COUNT(*)", 0);
      }
      break;

    case 1665:
#line 7352 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("AVERAGE(", yyvsp[-2].str, yyvsp[-1].sql_string,
			   ")", 0);
      }
      break;

    case 1666:
#line 7354 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("MAX(", yyvsp[-2].str, yyvsp[-1].sql_string, ")",
			   0);
      }
      break;

    case 1667:
#line 7356 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("MIN(", yyvsp[-2].str, yyvsp[-1].sql_string, ")",
			   0);
      }
      break;

    case 1668:
#line 7358 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("SUM(", yyvsp[-2].str, yyvsp[-1].sql_string, ")",
			   0);
      }
      break;

    case 1669:
#line 7360 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("COUNT(", yyvsp[-2].str, yyvsp[-1].sql_string, ")",
			   0);
      }
      break;

    case 1670:
#line 7362 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].str, "(", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1671:
#line 7364 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("DATE(", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1672:
#line 7365 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("(", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1673:
#line 7367 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("EXTEND(", yyvsp[-1].str, ")", 0);
      }
      break;

    case 1674:
#line 7371 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1675:
#line 7372 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1678:
#line 7382 "fgl.yacc"
      {

	print_unload (yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].sql_string);
	print_undo_use (yyvsp[-4].str);
      }
      break;

    case 1679:
#line 7391 "fgl.yacc"
      {
	print_load (yyvsp[-4].str, yyvsp[-3].str, yyvsp[-1].str,
		    yyvsp[0].str);
	print_undo_use (yyvsp[-6].str);
      }
      break;

    case 1680:
#line 7395 "fgl.yacc"
      {
	print_load_str (yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
	print_undo_use (yyvsp[-4].str);
      }
      break;

    case 1681:
#line 7402 "fgl.yacc"
      {
	strcpy (yyval.str, "\"|\"");
      }
      break;

    case 1682:
#line 7402 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1684:
#line 7406 "fgl.yacc"
      {
	if ((scan_variable (yyvsp[0].str) & 15) != 0)
	  {
	    a4gl_yyerror ("Variable must be of type char for a delimiter..");
	    YYERROR;
	  }
      }
      break;

    case 1685:
#line 7411 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1686:
#line 7411 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,0", yyvsp[-1].str);
      }
      break;

    case 1688:
#line 7415 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1689:
#line 7419 "fgl.yacc"
      {
	sprintf (yyval.str, "\"%s\"", yyvsp[0].str);
      }
      break;

    case 1692:
#line 7428 "fgl.yacc"
      {
	strcpy (yyval.str, "");
      }
      break;

    case 1693:
#line 7428 "fgl.yacc"
      {
	print_use_session (yyvsp[0].str);
	strcpy (yyval.str, A4GL_get_undo_use ());
      }
      break;

    case 1698:
#line 7447 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1699:
#line 7448 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s %s %s", yyvsp[-5].str, yyvsp[-4].str,
		 yyvsp[-3].str, yyvsp[-2].str);
      }
      break;

    case 1702:
#line 7456 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1703:
#line 7462 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s %s",
		 yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1706:
#line 7481 "fgl.yacc"
      {
	strcpy (yyval.str, "UNITS YEAR");
      }
      break;

    case 1707:
#line 7482 "fgl.yacc"
      {
	strcpy (yyval.str, "UNITS MONTH");
      }
      break;

    case 1708:
#line 7483 "fgl.yacc"
      {
	strcpy (yyval.str, "UNITS DAY");
      }
      break;

    case 1709:
#line 7484 "fgl.yacc"
      {
	strcpy (yyval.str, "UNITS HOUR");
      }
      break;

    case 1710:
#line 7485 "fgl.yacc"
      {
	strcpy (yyval.str, "UNITS MINUTE");
      }
      break;

    case 1711:
#line 7486 "fgl.yacc"
      {
	strcpy (yyval.str, "UNITS SECOND");
      }
      break;

    case 1712:
#line 7490 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str,
		 yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1713:
#line 7491 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str,
		 yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1714:
#line 7492 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s %s %s", yyvsp[-3].str, yyvsp[-2].str,
		 yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1715:
#line 7496 "fgl.yacc"
      {
	sql_mode = 1;
	start_bind ('i', 0);
	start_bind ('o', 0);
      }
      break;

    case 1716:
#line 7500 "fgl.yacc"
      {
	sql_mode = 0;
	print_sql_block_cmd (yyvsp[-1].str);
      }
      break;

    case 1718:
#line 7509 "fgl.yacc"
      {
	sprintf (yyval.str, "%s %s", yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1720:
#line 7514 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1721:
#line 7515 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1722:
#line 7519 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].sql_string);
      }
      break;

    case 1723:
#line 7525 "fgl.yacc"
      {
	strcpy (yyval.str, A4GL_get_into_part (get_bind_cnt ('o')));
      }
      break;

    case 1724:
#line 7612 "fgl.yacc"
      {
	strcpy (current_upd_table, yyvsp[0].str);
	pop_all_gen (UPDCOL, "!");
	pop_all_gen (UPDVAL, "!");
	pop_all_gen (UPDVAL2, "!");
	yyval.sql_string = strdup ("");
      }
      break;

    case 1725:
#line 7617 "fgl.yacc"
      {
	strcpy (current_upd_table, "");
	dump_updvals ();
      }
      break;

    case 1726:
#line 7620 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-6].str, " ", yyvsp[-5].str, " ",
			   yyvsp[-3].str, " ", yyvsp[-2].sql_string, " ",
			   yyvsp[0].sql_string, 0);
	printf ("-->%s\n", yyval.sql_string);
      }
      break;

    case 1727:
#line 7628 "fgl.yacc"
      {
	pop_all_gen (UPDCOL, "!");
	pop_all_gen (UPDVAL, "!");
	pop_all_gen (UPDVAL2, "!");
	yyval.sql_string = strdup ("");
      }
      break;

    case 1728:
#line 7633 "fgl.yacc"
      {
	pop_all_gen (UPDCOL, "!");
	pop_all_gen (UPDVAL, "!");
	pop_all_gen (UPDVAL2, "!");
	rm_quotes (yyvsp[0].str);
	sprintf (yyval.str, "%s %s", yyvsp[-1].str, yyvsp[0].str);
	yyval.sql_string = make_sql_string (yyval.str, 0);
      }
      break;

    case 1729:
#line 7640 "fgl.yacc"
      {
	pop_all_gen (UPDCOL, "!");
	pop_all_gen (UPDVAL, "!");
	pop_all_gen (UPDVAL2, "!");
	yyval.sql_string = make_sql_string ("WHERE ", yyvsp[0].sql_string, 0);
      }
      break;

    case 1730:
#line 7649 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("(", yyvsp[-5].str, ")=(", yyvsp[-1].sql_string,
			   ")", 0);

	if (A4GL_isyes (acl_getenv ("FIXUPDATE")))
	  {
	    yyval.sql_string = strdup (fix_update_expr (0));
	    ansi_violation ("Update (..)=(..)", 0);
	  }
	else
	  {
	    ansi_violation ("Update (..)=(..)", 1);
	  }
      }
      break;

    case 1731:
#line 7659 "fgl.yacc"
      {
	printf ("SYNTAX 1\n");
	yyval.sql_string =
	  make_sql_string ("*=(", yyvsp[-1].sql_string, ")", 0);
	push_gen (UPDCOL, "*");
	if (A4GL_isyes (acl_getenv ("FIXUPDATE")))
	  {
	    yyval.sql_string = strdup (fix_update_expr (1));
	    ansi_violation ("Update (..)=(..)", 0);
	  }
	else
	  {
	    ansi_violation ("Update (..)=(..)", 1);
	  }
      }
      break;

    case 1732:
#line 7670 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1733:
#line 7673 "fgl.yacc"
      {
	char *ptr;

	printf ("SYNTAX 2\n");
	ptr = yyvsp[0].sql_string;
	push_gen (UPDCOL, "*");

	if (ptr[0] == '(')
	  {
	    yyval.sql_string =
	      make_sql_string (yyvsp[-2].str, " ", yyvsp[-1].str, " ",
			       yyvsp[0].sql_string, 0);
	  }
	else
	  {
	    yyval.sql_string =
	      make_sql_string (yyvsp[-2].str, yyvsp[-1].str, "(",
			       yyvsp[0].sql_string, ")", 0);
	  }

	if (A4GL_isyes (acl_getenv ("FIXUPDATE")))
	  {
	    yyval.sql_string = strdup (fix_update_expr (1));
	    ansi_violation ("Update (..)=(..)", 0);
	  }
	else
	  {
	    ansi_violation ("Update (..)=(..)", 1);
	  }
      }
      break;

    case 1734:
#line 7696 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1735:
#line 7699 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1737:
#line 7708 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].str, "=", yyvsp[0].sql_string, 0);
      }
      break;

    case 1738:
#line 7713 "fgl.yacc"
      {
	push_gen (UPDCOL, yyvsp[0].str);
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1739:
#line 7716 "fgl.yacc"
      {
	push_gen (UPDCOL, yyvsp[0].str);
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1740:
#line 7724 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
	if (gen_cnt (UPDVAL2))
	  {
	    //pop_gen(UPDVAL);
	    copy_gen (UPDVAL, UPDVAL2);
	  }
      }
      break;

    case 1741:
#line 7731 "fgl.yacc"
      {
	if (gen_cnt (UPDVAL2))
	  {
	    //pop_gen(UPDVAL);
	    copy_gen (UPDVAL, UPDVAL2);
	  }
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1742:
#line 7743 "fgl.yacc"
      {
	push_gen (UPDVAL, "NULL");
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1743:
#line 7747 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1744:
#line 7755 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1745:
#line 7758 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("-", yyvsp[0].sql_string, 0);
      }
      break;

    case 1746:
#line 7761 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("+", yyvsp[0].sql_string, 0);
      }
      break;

    case 1747:
#line 7769 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
	printf ("Upd 1 ** %s\n", yyvsp[0].sql_string);

      }
      break;

    case 1748:
#line 7774 "fgl.yacc"
      {
	printf ("COMPLEX PUSH - (%s)\n", yyvsp[0].sql_string);
	push_gen (UPDVAL, yyvsp[0].sql_string);
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1749:
#line 7779 "fgl.yacc"
      {
	push_gen (UPDVAL, yyvsp[0].sql_string);
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1750:
#line 7783 "fgl.yacc"
      {
	push_gen (UPDVAL, yyvsp[-1].sql_string);
	yyval.sql_string = strdup (yyvsp[0].str);
      }
      break;

    case 1751:
#line 7787 "fgl.yacc"
      {
	push_gen (UPDVAL, yyvsp[-3].sql_string);
	yyval.sql_string = make_sql_string (yyvsp[-2].str, ".", yyvsp[0].str);
      }
      break;

    case 1752:
#line 7795 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, "/", yyvsp[0].sql_string, 0);
      }
      break;

    case 1753:
#line 7796 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-1].sql_string, yyvsp[0].str, 0);
      }
      break;

    case 1754:
#line 7797 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, "*", yyvsp[0].sql_string, 0);
      }
      break;

    case 1755:
#line 7798 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, "+", yyvsp[0].sql_string, 0);
      }
      break;

    case 1756:
#line 7799 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, "-", yyvsp[0].sql_string, 0);
      }
      break;

    case 1757:
#line 7800 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string (yyvsp[0].str, 0);
      }
      break;

    case 1758:
#line 7801 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("TRUE", 0);
      }
      break;

    case 1759:
#line 7802 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("FALSE", 0);
      }
      break;

    case 1760:
#line 7803 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("USER", 0);
      }
      break;

    case 1761:
#line 7804 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("*", 0);
      }
      break;

    case 1762:
#line 7805 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("COUNT(*)", 0);
      }
      break;

    case 1763:
#line 7806 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("AVERAGE(", yyvsp[-2].str, yyvsp[-1].sql_string,
			   ")", 0);
      }
      break;

    case 1764:
#line 7807 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("MAX(", yyvsp[-2].str, yyvsp[-1].sql_string, ")",
			   0);
      }
      break;

    case 1765:
#line 7808 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("MIN(", yyvsp[-2].str, yyvsp[-1].sql_string, ")",
			   0);
      }
      break;

    case 1766:
#line 7809 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("SUM(", yyvsp[-2].str, yyvsp[-1].sql_string, ")",
			   0);
      }
      break;

    case 1767:
#line 7810 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("COUNT(", yyvsp[-2].str, yyvsp[-1].sql_string, ")",
			   0);
      }
      break;

    case 1768:
#line 7811 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-3].str, "(", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1769:
#line 7812 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("DATE(", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1770:
#line 7813 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string ("(", yyvsp[-1].sql_string, ")", 0);
      }
      break;

    case 1771:
#line 7814 "fgl.yacc"
      {
	yyval.sql_string = make_sql_string ("EXTEND(", yyvsp[-1].str, ")", 0);
      }
      break;

    case 1772:
#line 7818 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1773:
#line 7824 "fgl.yacc"
      {
	yyval.sql_string = yyvsp[0].sql_string;
      }
      break;

    case 1774:
#line 7825 "fgl.yacc"
      {
	yyval.sql_string =
	  make_sql_string (yyvsp[-2].sql_string, ",", yyvsp[0].sql_string, 0);
      }
      break;

    case 1775:
#line 7838 "fgl.yacc"
      {
	if (scan_variable (yyvsp[0].str) != -1)
	  {
	    print_push_variable (yyvsp[0].str);
	    strcpy (yyval.str, "?");
	  }
      }
      break;

    case 1776:
#line 7849 "fgl.yacc"
      {
	strcpy (yyval.str, yyvsp[0].str);
      }
      break;

    case 1780:
#line 7855 "fgl.yacc"
      {
	sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1781:
#line 7856 "fgl.yacc"
      {
	sprintf (yyval.str, "\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),
		 yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1785:
#line 7868 "fgl.yacc"
      {
	if (scan_variable (yyvsp[0].str) != -1
	    && (!system_var (yyvsp[0].str)))
	  {
	    int z = 0, a = 0;
	    a = get_bind_cnt ('i');
	    z = add_bind ('i', yyvsp[0].str);
	    z -= a;
	    yyval.sql_string = strdup (A4GL_set_var_sql (z));

	  }
	else
	  {
	    yyval.sql_string = strdup (yyvsp[0].str);
	  }
      }
      break;

    case 1786:
#line 7882 "fgl.yacc"
      {
	char r1[256];
	char r2[256];
	char buff[256];
	char was_str[40000];
	char *ptr1;
	char *ptr2;
	int aa;
	int z = 0, a = 0;
	struct variable *v_r;
	struct variable *v_1;
	struct variable *v_2;
	struct variable *v_loop;
	strcpy (was_str, "");


	split_record (yyvsp[0].str, &v_r, &v_1, &v_2);

	v_loop = v_1;

	while (1)
	  {
	    //strcpy(kp,was_str);
	    sprintf (buff, "%s.%s", r1, v_loop->names.name);

	    if (scan_variable (buff) != -1 && (!system_var (buff)))
	      {
		a = get_bind_cnt ('i');
		z = add_bind ('i', buff);
		z -= a;
	      }

	    for (a = 0; a < z; a++)
	      {
		if (strlen (was_str))
		  {
		    strcat (was_str, ",");
		  }
		strcat (was_str, "?");
	      }
	    v_loop = get_next_variable (v_r, v_loop, v_2);
	  }
	yyval.sql_string = strdup (was_str);
      }
      break;

    case 1787:
#line 7933 "fgl.yacc"
      {
	set_whenever (WHEN_NOTFOUND | atoi (yyvsp[0].str), 0);
      }
      break;

    case 1788:
#line 7935 "fgl.yacc"
      {
	set_whenever (WHEN_SQLERROR | atoi (yyvsp[0].str), 0);
      }
      break;

    case 1789:
#line 7937 "fgl.yacc"
      {
	set_whenever (WHEN_ANYERROR | atoi (yyvsp[0].str), 0);
      }
      break;

    case 1790:
#line 7938 "fgl.yacc"
      {
	set_whento ("");
	set_whenever (WHEN_ERROR + WHEN_CONTINUE, 0);
      }
      break;

    case 1791:
#line 7943 "fgl.yacc"
      {
 A4GL_debug ("Whenever error...%d %d", WHEN_ERROR, atoi (yyvsp[0].str));
	set_whenever (WHEN_ERROR + atoi (yyvsp[0].str), 0);
      }
      break;

    case 1792:
#line 7948 "fgl.yacc"
      {
	set_whenever (WHEN_SQLWARNING | atoi (yyvsp[0].str), 0);
      }
      break;

    case 1793:
#line 7950 "fgl.yacc"
      {
	set_whenever (WHEN_WARNING | atoi (yyvsp[0].str), 0);
      }
      break;

    case 1794:
#line 7952 "fgl.yacc"
      {
	set_whenever (WHEN_SUCCESS | atoi (yyvsp[0].str), 0);
      }
      break;

    case 1795:
#line 7954 "fgl.yacc"
      {
	set_whenever (WHEN_SQLSUCCESS | atoi (yyvsp[0].str), 0);
      }
      break;

    case 1796:
#line 7957 "fgl.yacc"
      {
	set_whento ("");
	sprintf (yyval.str, "%d", WHEN_CONTINUE);
      }
      break;

    case 1797:
#line 7961 "fgl.yacc"
      {
	set_whento (yyvsp[0].str);
	sprintf (yyval.str, "%d", WHEN_GOTO);
      }
      break;

    case 1798:
#line 7966 "fgl.yacc"
      {
	set_whento (yyvsp[0].str);
	sprintf (yyval.str, "%d", WHEN_GOTO);
      }
      break;

    case 1799:
#line 7971 "fgl.yacc"
      {
	set_whento ("");
	sprintf (yyval.str, "%d", WHEN_STOP);
      }
      break;

    case 1800:
#line 7975 "fgl.yacc"
      {
	set_whento (yyvsp[0].str);
	sprintf (yyval.str, "%d", WHEN_CALL);
      }
      break;

    case 1802:
#line 7985 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 1804:
#line 8000 "fgl.yacc"
      {
	print_while_1 ();
	push_blockcommand ("WHILE");
      }
      break;

    case 1805:
#line 8003 "fgl.yacc"
      {
	print_while_2 ();
      }
      break;

    case 1806:
#line 8007 "fgl.yacc"
      {
	print_while_3 ();
	pop_blockcommand ("WHILE");
      }
      break;

    case 1809:
#line 8026 "fgl.yacc"
      {
	strcpy (yyval.str, "0");
      }
      break;

    case 1810:
#line 8027 "fgl.yacc"
      {
	strcpy (yyval.str, "1");
      }
      break;

    case 1811:
#line 8030 "fgl.yacc"
      {
	print_clr_window ("\"screen\"");
      }
      break;

    case 1812:
#line 8031 "fgl.yacc"
      {
	print_clr_window (yyvsp[0].str);
      }
      break;

    case 1813:
#line 8032 "fgl.yacc"
      {
	print_clr_window (yyvsp[0].str);
      }
      break;

    case 1814:
#line 8033 "fgl.yacc"
      {
	print_clr_form (0, 0, "0");
      }
      break;

    case 1815:
#line 8034 "fgl.yacc"
      {
	print_clr_form (0, 0, "1");
      }
      break;

    case 1816:
#line 8035 "fgl.yacc"
      {
	print_clr_form (yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1817:
#line 8036 "fgl.yacc"
      {
	print_clr_fields (yyvsp[-1].str, yyvsp[0].str);
      }
      break;

    case 1818:
#line 8041 "fgl.yacc"
      {
	sprintf (yyval.str, "%s", yyvsp[0].str);
      }
      break;

    case 1819:
#line 8042 "fgl.yacc"
      {
	sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
      }
      break;

    case 1820:
#line 8046 "fgl.yacc"
      {
	print_current_window ("\"screen\"");
      }
      break;

    case 1821:
#line 8050 "fgl.yacc"
      {
	print_current_window (yyvsp[0].str);
      }
      break;

    case 1822:
#line 8054 "fgl.yacc"
      {
	sprintf (yyval.str, "cr_window");
	reset_attrib (&form_attrib);
      }
      break;

    case 1823:
#line 8058 "fgl.yacc"
      {
	sprintf (yyval.str, "cr_window_form");
	reset_attrib (&form_attrib);
      }
      break;

    case 1824:
#line 8063 "fgl.yacc"
      {
	print_show_window (yyvsp[0].str);
	addmap ("Show Window", yyvsp[0].str, curr_func, yylineno, infilename);
      }
      break;

    case 1825:
#line 8067 "fgl.yacc"
      {
	print_show_menu (yyvsp[-3].str, yyvsp[-1].str);
	addmap ("Call Menuhandler", yyvsp[-1].str, curr_func, yylineno,
		infilename);
      }
      break;

    case 1826:
#line 8072 "fgl.yacc"
      {

	print_def_mn_file ();

      }
      break;

    case 1828:
#line 8080 "fgl.yacc"
      {
	addmap ("Use Menu", yyvsp[0].str, curr_func, yylineno, infilename);
      }
      break;

    case 1830:
#line 8086 "fgl.yacc"
      {
	print_hide_window (yyvsp[0].str);
      }
      break;

    case 1831:
#line 8092 "fgl.yacc"
      {
	print_move_window (yyvsp[-4].str, 0);
      }
      break;

    case 1832:
#line 8096 "fgl.yacc"
      {
	print_move_window (yyvsp[-4].str, 1);
      }
      break;

    case 1837:
#line 8114 "fgl.yacc"
      {
	chk4var = 0;
 A4GL_lex_printcomment ("/* [Comm:%s] */\n", yyval.str);
	if (acl_getenv ("INCLINES"))
	  A4GL_lex_printc ("{debug(\"Line %d %s:%s\");}", lastlineno, infilename,
		      convstrsql (larr));
 A4GL_prchkerr (lastlineno, infilename);
	lastlineno = yylineno;
      }
      break;

    case 1838:
#line 8121 "fgl.yacc"
      {
 A4GL_lex_printcomment ("/* [COMM:%s] */\n", yyvsp[0].str);
	chk4var = 0;
	if (acl_getenv ("INCLINES"))
	  A4GL_lex_printc ("{debug(\"Line %d %s:%s\");}", lastlineno, infilename,
		      convstrsql (larr));
	if (A4GL_aubit_strcasecmp (yyval.str, "whenever") != 0)
	  A4GL_prchkerr (lastlineno, infilename);
	lastlineno = yylineno;
      }
      break;

    case 1839:
#line 8130 "fgl.yacc"
      {
	print_cmd_start ();
      }
      break;

    case 1840:
#line 8130 "fgl.yacc"
      {
	print_cmd_end ();
      }
      break;


    }

/* Line 991 of yacc.c.  */
#line 16765 "y.tab.c"

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
			const char *yyq = !yycount ? ", expecting " : " or ";
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
  yyerrstatus = 3;		/* Each real token shifted decrements this.  */

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


#line 8225 "fgl.yacc"

/* programmer routines */
/*
# include "lex.yy.c"
# include "lexify.c"
*/

void
set_clobber (char *c)
{
  char *ptr;
  char *ptr2;
  ptr = strrchr (c, '/');
  if (ptr)
    {
      strcpy (clobber, ptr + 1);
      return;
    }

/* Do dos mode ? */
  ptr = strrchr (c, '\\');
  if (ptr)
    {
      strcpy (clobber, ptr + 1);
      return;
    }

  strcpy (clobber, c);
}

char *
get_hdrdbname (void)
{
  return hdr_dbname;
}

void
set_hdrdbname (char *s)
{
  strcpy (hdr_dbname, s);
}

//use this set_str() if YYPURE and YYLEX_PARAM are not set
//void
//set_str(char *s)
//      strcpy(yylval.str,s);
//}

//use this set_str() if YYPURE and YYLEX_PARAM are set
void
set_str (void *p, char *s)
{
  YYSTYPE *y;
  y = (YYSTYPE *) p;
  strcpy (y->str, s);
}


/* ====================== last.reqd =============================== */


/* ===================== EOF (fgl.yacc) =========================== */
