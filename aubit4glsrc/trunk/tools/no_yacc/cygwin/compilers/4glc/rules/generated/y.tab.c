/* A Bison parser, made from fgl.yacc
   by GNU bison 1.33.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	NAMED_GEN	257
# define	COMMA	1536
# define	OR	1575
# define	AND	1531
# define	USING	1465
# define	MATCHES	1344
# define	POWER	1451
# define	LESS_THAN	1447
# define	GREATER_THAN	1362
# define	EQUAL	1526
# define	GREATER_THAN_EQ	1262
# define	LESS_THAN_EQ	1319
# define	NOT_EQUAL	1393
# define	MINUS	1549
# define	PLUS	1561
# define	DIVIDE	1480
# define	MULTIPLY	1452
# define	MOD	1550
# define	NUMBER_VALUE	258
# define	SQLERROR	259
# define	SQLWARNING	260
# define	CHAR_VALUE	261
# define	INT_VALUE	262
# define	CLINE	263
# define	SQLLINE	264
# define	KW_CSTART	265
# define	KW_CEND	266
# define	NEWFORMATSHARED	1000
# define	WAIT_FOR_KEY	1001
# define	AT_TERMINATION_CALL	1002
# define	TO_MAIN_CAPTION	1003
# define	CLEARSTAT	1004
# define	TO_MENUITEM	1005
# define	ID_TO_INT	1006
# define	TO_STATUSBOX	1007
# define	ASCII_HEIGHT_ALL	1008
# define	ASCII_WIDTH_ALL	1009
# define	UP_BY	1010
# define	PAGE_TRAILER_SIZE	1011
# define	PAGE_HEADER_SIZE	1012
# define	FIRST_PAGE_HEADER_SIZE	1013
# define	BYTES_USE_AS_IMAGE	1014
# define	BYTES_USE_AS_ASCII	1015
# define	DOWN_BY	1016
# define	CLOSE_STATUSBOX	1017
# define	ADD_CONSTRAINT	1018
# define	DROP_CONSTRAINT	1019
# define	MODIFY_NEXT_SIZE	1020
# define	LOCK_MODE_PAGE	1021
# define	LOCK_MODE_ROW	1022
# define	TO_PIPE	1023
# define	TO_PRINTER	1024
# define	STATUSBOX	1025
# define	CONNECT_TO	1026
# define	FORMHANDLER_INPUT	1027
# define	UNITS_YEAR	1028
# define	UNITS_MONTH	1029
# define	UNITS_DAY	1030
# define	UNITS_HOUR	1031
# define	UNITS_MINUTE	1032
# define	UNITS_SECOND	1033
# define	NO_NEW_LINES	1034
# define	FIELDTOWIDGET	1035
# define	WITH_HOLD	1036
# define	SHOW_MENU	1037
# define	CWIS	1038
# define	CREATE_IDX	1039
# define	FORM_IS_COMPILED	1040
# define	PDF_REPORT	1041
# define	IMPORT_FUNCTION	1042
# define	PROMPT_MANY	1043
# define	POINTS	1044
# define	MM	1045
# define	INCHES	1046
# define	PREPEND	1047
# define	MEMBER_OF	1048
# define	MEMBER_FUNCTION	1049
# define	APPEND	1050
# define	TEMPLATE	1051
# define	END_TEMPLATE	1052
# define	SQLSICS	1053
# define	CREATE_SCHEMA	1054
# define	SQLSIRR	1055
# define	UPDATESTATS_T	1056
# define	SQLSICR	1057
# define	WHENEVER_SQLSUCCESS	1058
# define	WHENEVER_SQLWARNING	1059
# define	START_EXTERN	1060
# define	WHENEVER_ANY_ERROR	1061
# define	WHENEVER_NOT_FOUND	1062
# define	CONTINUE_CONSTRUCT	1063
# define	FOUNCONSTR	1064
# define	SQLSIDR	1065
# define	WHENEVER_SQLERROR	1066
# define	CREATE_TEMP_TABLE	1067
# define	CURRENT_WINDOW_IS	1068
# define	FIRST_PAGE_HEADER	1069
# define	ORDER_EXTERNAL_BY	1070
# define	SCROLL_CURSOR_FOR	1071
# define	SCROLL_CURSOR	1072
# define	SQL_INTERRUPT_OFF	1073
# define	STOP_ALL_EXTERNAL	1074
# define	WITH_CHECK_OPTION	1075
# define	WITH_GRANT_OPTION	1076
# define	SQLSLMNW	1077
# define	ADDCONSTUNIQ	1078
# define	CONTINUE_DISPLAY	1079
# define	CONTINUE_FOREACH	1080
# define	OUTPUT_TO_REPORT	1081
# define	SQL_INTERRUPT_ON	1082
# define	WHENEVER_SUCCESS	1083
# define	WHENEVER_WARNING	1084
# define	WHERE_CURRENT_OF	1085
# define	WITHOUT_DEFAULTS	1086
# define	FOCONSTR	1087
# define	SCALED_BY	1088
# define	CONTINUE_PROMPT	1089
# define	PDF_FUNCTION	1090
# define	DEFER_INTERRUPT	1091
# define	DISPLAY_BY_NAME	1092
# define	NOT_NULL_UNIQUE	1093
# define	SKIP_TO_TOP	1094
# define	TOP_OF_PAGE	1095
# define	SKIP_TO	1096
# define	SKIP_BY	1097
# define	WITHOUT_WAITING	1098
# define	BEFCONSTRUCT	1099
# define	SQLSLMW	1100
# define	WHENEVER_ERROR_CONTINUE	1101
# define	WHENEVER_ERROR	1102
# define	AFTCONSTRUCT	1103
# define	ALL_PRIVILEGES	1104
# define	CLOSE_DATABASE	1105
# define	CONTINUE_INPUT	1106
# define	CONTINUE_WHILE	1107
# define	CREATE_SYNONYM	1108
# define	DROP_TABLE	1109
# define	EXIT_CONSTRUCT	1110
# define	INEXCLUSIVE	1111
# define	REPORT_TO_PRINTER	1112
# define	REPORT_TO_PIPE	1113
# define	SET_SESSION_TO	1114
# define	UPDATESTATS	1115
# define	WITHOUT_HEAD	1116
# define	CLEARSCR	1117
# define	WITH_B_LOG	1118
# define	AUTHORIZATION	1119
# define	BOTTOM_MARGIN	1120
# define	CLOSE_SESSION	1121
# define	CONTINUE_CASE	1122
# define	CONTINUE_MENU	1123
# define	DISPLAY_ARRAY	1124
# define	END_CONSTRUCT	1125
# define	FIELD_TOUCHED	1126
# define	FINISH_REPORT	1127
# define	INFACC	1128
# define	INPUT_NO_WRAP	1129
# define	LOCKMODEPAGE	1130
# define	SETPMOFF	1131
# define	UNCONSTRAINED	1132
# define	PAGE_TRAILER	1133
# define	SETPMON	1134
# define	BEFGROUP	1135
# define	CLOSE_WINDOW	1136
# define	COMMENT_LINE	1137
# define	CONTINUE_FOR	1138
# define	CREATE_DB	1139
# define	CREATE_TABLE	1140
# define	DEFAULT_NULL	1141
# define	DELETE_USING	1142
# define	DISPLAY_FORM	1143
# define	END_FUNCTION	1144
# define	EXIT_DISPLAY	1145
# define	EXIT_FOREACH	1146
# define	EXIT_PROGRAM	1147
# define	INFCOLS	1148
# define	LOCKMODEROW	1149
# define	ON_EVERY_ROW	1150
# define	OPEN_SESSION	1151
# define	RIGHT_MARGIN	1152
# define	SELECT_USING	1153
# define	START_REPORT	1154
# define	UNLOCK_TABLE	1155
# define	UPDATE_USING	1156
# define	ACL_BUILTIN	1157
# define	AFTGROUP	1158
# define	INFIDX	1159
# define	INFSTAT	1160
# define	LEFT_MARGIN	1161
# define	PAGE_HEADER	1162
# define	ROLLBACK_W	1163
# define	SET_SESSION	1164
# define	SQLSEOFF	1165
# define	WITH_A_LOG	1166
# define	ALTER_TABLE	1167
# define	BEFDISP	1168
# define	BEFORE_MENU	1169
# define	CREATE_VIEW	1170
# define	DEFINE_TYPE	1171
# define	DELETE_FROM	1172
# define	END_DISPLAY	1173
# define	END_REPORT	1174
# define	END_FOREACH	1175
# define	END_GLOBALS	1176
# define	EXIT_PROMPT	1177
# define	EXTENT_SIZE	1178
# define	FOREIGN_KEY	1179
# define	HIDE_OPTION	1180
# define	HIDE_WINDOW	1181
# define	INSERT_INTO	1182
# define	IS_NOT_NULL	1183
# define	MOVE_WINDOW	1184
# define	NEXT_OPTION	1185
# define	NOT_MATCHES	1186
# define	ON_LAST_ROW	1187
# define	OPEN_WINDOW	1188
# define	OPEN_STATUSBOX	1189
# define	PAGE_LENGTH	1190
# define	PAGE_WIDTH	1191
# define	PRIMARY_KEY	1192
# define	PROMPT_LINE	1193
# define	RECORD_LIKE	1194
# define	ROLLFORWARD	1195
# define	SETBL	1196
# define	SHOW_OPTION	1197
# define	SHOW_WINDOW	1198
# define	SQLSEON	1199
# define	TO_DATABASE	1200
# define	USE_SESSION	1201
# define	WITH_NO_LOG	1202
# define	AFTDISP	1203
# define	BEFFIELD	1204
# define	INSHARE	1205
# define	UNLOCKTAB	1206
# define	AFTFIELD	1207
# define	ATTRIBUTES	1208
# define	BEFINP	1209
# define	BEGIN_WORK	1210
# define	CLEARWIN	1211
# define	CLOSE_FORM	1212
# define	DEFER_QUIT	1213
# define	DESCENDING	1214
# define	DROP_INDEX	1215
# define	END_PROMPT	1216
# define	END_RECORD	1217
# define	ERROR_LINE	1218
# define	EXIT_INPUT	1219
# define	EXIT_WHILE	1220
# define	FOR_UPDATE_OF	1221
# define	FOR_UPDATE	1222
# define	GET_FLDBUF	1223
# define	INITIALIZE	1224
# define	INPUT_WRAP	1225
# define	LOCK_TABLE	1226
# define	MSG_LINE	1227
# define	NOT_EXISTS	1228
# define	ON_ANY_KEY	1229
# define	REFERENCES	1230
# define	RENCOL	1231
# define	SET_CURSOR	1232
# define	SMALLFLOAT	1233
# define	SQLSUCCESS	1234
# define	TOP_MARGIN	1235
# define	WITH_ARRAY	1236
# define	ACCEPTKEY	1237
# define	ACCEPT	1238
# define	AFTINP	1239
# define	CLEARFORM	1240
# define	COMMIT_W	1241
# define	NEXTPAGE	1242
# define	PREVPAGE	1243
# define	CTRL_KEY	1244
# define	INFTABS	1245
# define	NEXTFIELD	1246
# define	NEXTFORM	1247
# define	RENTAB	1248
# define	ASCENDING	1249
# define	ASSOCIATE	1250
# define	CHARACTER	1251
# define	CONSTRUCT	1252
# define	DELIMITER	1253
# define	DOWNSHIFT	1254
# define	DROP_VIEW	1255
# define	END_INPUT	1256
# define	END_WHILE	1257
# define	EXCLUSIVE	1258
# define	EXIT_CASE	1259
# define	EXIT_MENU	1260
# define	FORM_LINE	1261
# define	INTERRUPT	1263
# define	INTO_TEMP	1264
# define	INVISIBLE	1265
# define	IN_MEMORY	1266
# define	LINKED_TO	1267
# define	LOAD_FROM	1268
# define	LOCKTAB	1269
# define	MENU_LINE	1270
# define	OPEN_FORM	1271
# define	OTHERWISE	1272
# define	PRECISION	1273
# define	PROCEDURE	1274
# define	REPORT_TO	1275
# define	RETURNING	1276
# define	UNDERLINE	1277
# define	UNLOAD_TO	1278
# define	BEFROW	1279
# define	UNLOAD_T	1280
# define	VARIABLE	1281
# define	ABSOLUTE	1282
# define	AFTROW	1283
# define	BUFFERED	1284
# define	CONSTANT	1285
# define	CONST	1286
# define	CONTINUE	1287
# define	DATABASE	1288
# define	DATETIME	1289
# define	DEFAULTS	1290
# define	DISTINCT	1291
# define	END_CASE	1292
# define	END_MAIN	1293
# define	END_MENU	1294
# define	END_TYPE	1295
# define	EXIT_FOR	1296
# define	EXTERNAL	1297
# define	FRACTION	1298
# define	FUNCTION	1299
# define	GROUP_BY	1300
# define	INTERVAL	1301
# define	KWMESSAGE	1302
# define	NOT_LIKE	1303
# define	NOT_NULL	1304
# define	PASSWORD	1305
# define	PREVIOUS	1306
# define	READONLY	1307
# define	REGISTER	1308
# define	RELATIVE	1309
# define	RESOURCE	1310
# define	SMALLINT	1311
# define	VALIDATE	1312
# define	WHENEVER	1313
# define	WITH_LOG	1314
# define	WORDWRAP	1315
# define	BY_NAME	1316
# define	IN_FILE	1317
# define	IS_NULL	1318
# define	AVERAGE	1320
# define	BETWEEN	1321
# define	CAPTION	1322
# define	CLIPPED	1323
# define	CLOSE_BRACKET	1324
# define	COLUMNS	1325
# define	COMMAND	1326
# define	COMMENT	1327
# define	CONNECT	1328
# define	CURRENT	1329
# define	DBYNAME	1330
# define	DECIMAL	1331
# define	DECLARE	1332
# define	DEFAULT	1333
# define	DISPLAY	1334
# define	ENDCODE	1335
# define	EXECUTE	1336
# define	FOREACH	1337
# define	FOREIGN	1338
# define	GLOBALS	1339
# define	INFIELD	1340
# define	INTEGER	1341
# define	KWWINDOW	1342
# define	MAGENTA	1343
# define	NUMERIC	1345
# define	OPTIONS	1346
# define	PERCENT	1347
# define	PREPARE	1348
# define	PROGRAM	1349
# define	RECOVER	1350
# define	REVERSE	1351
# define	SECTION	1352
# define	SESSION	1353
# define	SYNONYM	1354
# define	THRU	1355
# define	TRAILER	1356
# define	UPSHIFT	1357
# define	VARCHAR	1358
# define	WAITING	1359
# define	CLOSE_SHEV	1360
# define	CLOSE_SQUARE	1361
# define	KW_FALSE	1363
# define	NOT_IN	1364
# define	ON_KEY	1365
# define	OPEN_BRACKET	1366
# define	BORDER	1367
# define	BOTTOM	1368
# define	COLUMN	1369
# define	COMMIT	1370
# define	CREATE	1371
# define	CURSOR	1372
# define	DEFINE	1373
# define	DELETE	1374
# define	DOUBLE	1375
# define	END_IF	1376
# define	ESCAPE	1377
# define	EXISTS	1378
# define	EXTEND	1379
# define	EXTENT	1380
# define	FINISH	1381
# define	FORMAT	1382
# define	HAVING	1383
# define	HEADER	1384
# define	INSERT	1385
# define	LOCATE	1386
# define	MARGIN	1387
# define	MEMORY	1388
# define	MINUTE	1389
# define	MODIFY	1390
# define	NORMAL	1391
# define	EQUAL_EQUAL	1392
# define	OPEN_SHEV	1394
# define	OPEN_SQUARE	1395
# define	OPTION	1396
# define	OUTPUT	1397
# define	PROMPT	1398
# define	PUBLIC	1399
# define	RECORD	1400
# define	REPORT	1401
# define	RETURN	1402
# define	REVOKE	1403
# define	SCHEMA	1404
# define	SCROLL	1405
# define	SECOND	1406
# define	SELECT	1407
# define	SERIAL	1408
# define	SETL	1409
# define	SHARED	1410
# define	SPACES	1411
# define	UNIQUE	1412
# define	UNLOCK	1413
# define	UPDATE	1414
# define	VALUES	1415
# define	YELLOW	1416
# define	AFTER	1417
# define	KWLINE	1418
# define	KW_NULL	1419
# define	KW_TRUE	1420
# define	SINGLE_KEY	1421
# define	ALTER	1422
# define	ARRAY	1423
# define	ASCII	1424
# define	AUDIT	1425
# define	BLACK	1426
# define	BLINK	1427
# define	CHECK	1428
# define	CLEAR	1429
# define	CLOSE	1430
# define	CODE_C	1431
# define	COUNT	1432
# define	DEFER	1433
# define	ERROR	1434
# define	EVERY	1435
# define	FETCH	1436
# define	FIRST	1437
# define	FLOAT	1438
# define	FLUSH	1439
# define	FOUND	1440
# define	GRANT	1441
# define	GREEN	1442
# define	GROUP	1443
# define	INDEX	1444
# define	KWFORM	1445
# define	LABEL	1446
# define	LOCAL	1448
# define	MONEY	1449
# define	MONTH	1450
# define	ORDER	1453
# define	OUTER	1454
# define	PAUSE	1455
# define	PRINT_IMAGE	1456
# define	PRINT_FILE	1457
# define	PRINT	1458
# define	RIGHT	1459
# define	SEMICOLON	1460
# define	SLEEP	1461
# define	SPACE	1462
# define	TUPLE	1463
# define	UNION	1464
# define	WHERE	1466
# define	WHILE	1467
# define	WHITE	1468
# define	CCODE	1469
# define	ANSI	1470
# define	BLUE	1471
# define	BOLD	1472
# define	BYTE	1473
# define	FCALL	1474
# define	CASE	1475
# define	CHAR	1476
# define	CYAN	1477
# define	DATE	1478
# define	DESC	1479
# define	DOWN	1481
# define	TAB	1482
# define	DROP	1483
# define	ELSE	1484
# define	EXEC	1485
# define	EXIT	1486
# define	FREE	1487
# define	FROM	1488
# define	GOTO	1489
# define	HELP_FILE	1490
# define	LANG_FILE	1491
# define	HELP	1492
# define	HIDE	1493
# define	HOUR	1494
# define	INTO	1495
# define	LAST	1496
# define	LEFT	1497
# define	LIKE	1498
# define	MAIN	1499
# define	MENU	1500
# define	MODE	1501
# define	MOVE	1502
# define	NEED	1503
# define	NEXT	1504
# define	NOCR	1505
# define	OPEN	1506
# define	QUIT	1507
# define	REAL	1508
# define	ROWS	1509
# define	SHOW	1510
# define	SIZE	1511
# define	SKIP	1512
# define	SOME	1513
# define	STEP	1514
# define	STOP	1515
# define	TEMP	1516
# define	TEXT	1517
# define	THEN	1518
# define	USER	1519
# define	VIEW	1520
# define	WAIT	1521
# define	WHEN	1522
# define	WITH	1523
# define	WORK	1524
# define	YEAR	1525
# define	KW_IS	1527
# define	XSET	1528
# define	ADD	1529
# define	ALL	1530
# define	ANY	1532
# define	ASC	1533
# define	AVG	1534
# define	COLON	1535
# define	DAY	1537
# define	DBA	1538
# define	DEC	1539
# define	DIM	1540
# define	FKEY	1541
# define	FOR	1542
# define	KEY	1543
# define	KWNO	1544
# define	LET	1545
# define	LOG	1546
# define	XMAX	1547
# define	XMIN	1548
# define	NOT	1551
# define	PAD	1552
# define	PUT	1553
# define	RED	1554
# define	ROW	1555
# define	RUN	1556
# define	SQL	1557
# define	SUM	1558
# define	TOP	1559
# define	USE	1560
# define	AS_TIFF	1562
# define	AS_GIF	1563
# define	AS_PNG	1564
# define	AS_JPEG	1565
# define	AS	1566
# define	AT	1567
# define	BY	1568
# define	DOT	1569
# define	GO	1570
# define	IF	1571
# define	IN	1572
# define	OF	1573
# define	ON	1574
# define	TO	1576
# define	UP	1577
# define	FONT_NAME	1578
# define	FONT_SIZE	1579
# define	PAPER_SIZE_IS_LETTER	1580
# define	PAPER_SIZE_IS_LEGAL	1581
# define	PAPER_SIZE_IS_A4	1582
# define	FORMHANDLER	1583
# define	END_FORMHANDLER	1584
# define	BEFORE_EVENT	1585
# define	BEFORE_OPEN_FORM	1586
# define	AFTER_EVENT	1587
# define	BEFORE_CLOSE_FORM	1588
# define	BEFORE_ANY	1589
# define	AFTER_ANY	1590
# define	MENUHANDLER	1591
# define	END_MENUHANDLER	1592
# define	BEFORE_SHOW_MENU	1593
# define	DISABLE_PROGRAM	1594
# define	DISABLE_ALL	1595
# define	BUTTONS	1596
# define	CHECK_MENUITEM	1597
# define	DISABLE_FORM	1598
# define	DISABLE_MENUITEMS	1599
# define	DISABLE	1600
# define	ENABLE_FORM	1601
# define	ENABLE_MENUITEMS	1602
# define	ENABLE	1603
# define	KWFIELD	1604
# define	ICON	1605
# define	MESSAGEBOX	1606
# define	TO_DEFAULTS	1607
# define	UNCHECK_MENUITEM	1608
# define	BEFORE	1609
# define	INPUT	1610
# define	END	1611
# define	INT_TO_ID	1612

#line 2 "fgl.yacc"

//#include "../libincl/compiler.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void *new_expr(char *value) ;
void *append_expr(void *orig_ptr,char *value);
void *append_expr_expr(void *orig_ptr,void *second_ptr);

int in_define=0;
#include "../../lib/libincl/dbform.h"
#include "../../lib/libincl/report.h"
#include "../../lib/libincl/oform.h"
#include "../../lib/libincl/attributes.h"
#include "../../lib/libincl/debug.h"
#include "../../lib/libincl/errors.h"
//#include "../libincl/screen.h"
#include "../../lib/libincl/constats.h"
#include "../../lib/libincl/prompt.h"
#include "../print_protos.h"
extern int lineno;
extern int read_glob_var;
extern int modlevel;
extern int charno;
extern int last_var_found;
extern int varcnt;
int rordcnt;
char menuhandler[256];
char *downshift(char *);
char *convstrsql(char *);
char last_var [256];
char larr[4096]="";
char larr2[4096]="";
char clobber[64]="";
extern int in_record;
int racnt=0;
int ccode=0;
int errbomb=0;
int glob_only=0;
int inp_flags=0;
char dtypelist[2048];
char curr_func[256]="Module";
struct rep_structure rep_struct;
struct pdf_rep_structure pdf_rep_struct;
extern int rep_type;
char where_having[1024];
char menu[2048];
char varstring[100];
char infilename[132]="";
int lcnt;
int vcnt;

struct form_attr form_attrib;

extern int yylineno;
int rcnt;
int lastlineno=0;
int cnt;
int mcnt=0;
int inrec=0;
int iskey=0;
int insql=0;
int menu_cnt=0;
int chk4var=0;
int menu_cmd_cnt[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int in_sql=0;
char hdr_dbname[64]="";
#define INCASE 0
#define INCONSTRUCT 1
#define INDISPLAY 2
#define INFOR 3
#define INFOREACH 4
#define ININPUT 5
#define INMENU 6
#define INPROMPT 7
#define INWHILE 8
#define INIF 9
#define UPDCOL 0
#define UPDVAL 1
#define SELINTO 2
#define PUTVAL 3
int continue_cmd[]={0,1,1,1,1,1,1,1,1,0};
int in_cmd[]={0,0,0,0,0,0,0,0,0,0};
int fcall_cnt=0;


#line 92 "fgl.yacc"
#ifndef YYSTYPE
typedef union	  {
// This would core dump in CygWin on call to yyparse in y.tab.c - 3100 in maximum:
//	char	str[20000];
	char	str[3100];
	struct expr_str *ptr;
	} yystype;
# define YYSTYPE yystype
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		2947
#define	YYFLAG		-32768
#define	YYNTBASE	627

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 1612 ? yytranslate[x] : 1393)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const short yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   626,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,    13,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,    14,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,     8,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,    11,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,    15,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,    10,   472,   473,
     474,     9,    19,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,     7,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
      18,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,    12,   546,   547,   548,
     549,     6,   550,   551,   552,   553,     4,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,    16,
      20,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,    17,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,     5,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     4,    10,    12,    14,    16,    18,    22,
      24,    28,    31,    33,    36,    38,    41,    44,    47,    50,
      53,    55,    57,    58,    60,    61,    67,    74,    76,    80,
      82,    84,    86,    88,    90,    92,    94,    96,    98,   100,
     102,   104,   106,   108,   110,   112,   113,   115,   116,   122,
     124,   128,   130,   132,   135,   138,   141,   144,   147,   150,
     153,   156,   160,   161,   169,   174,   181,   183,   190,   191,
     192,   193,   202,   203,   204,   215,   216,   217,   225,   226,
     227,   228,   243,   244,   247,   248,   251,   253,   254,   256,
     258,   262,   264,   268,   270,   272,   274,   276,   277,   284,
     285,   291,   293,   296,   298,   301,   303,   304,   305,   309,
     310,   311,   315,   316,   321,   322,   327,   330,   333,   336,
     338,   341,   344,   348,   350,   352,   354,   357,   359,   361,
     364,   366,   368,   369,   370,   376,   384,   393,   394,   397,
     399,   403,   405,   409,   413,   415,   418,   419,   424,   425,
     430,   431,   435,   436,   440,   441,   445,   447,   451,   453,
     457,   459,   461,   463,   465,   467,   469,   471,   473,   474,
     476,   478,   481,   482,   486,   488,   490,   492,   496,   497,
     500,   505,   510,   515,   518,   519,   524,   526,   528,   530,
     533,   535,   537,   541,   542,   544,   545,   553,   554,   567,
     569,   571,   573,   575,   577,   583,   587,   589,   591,   592,
     597,   598,   604,   605,   613,   615,   619,   621,   623,   624,
     627,   629,   631,   633,   638,   643,   650,   652,   655,   657,
     659,   661,   663,   668,   675,   677,   682,   689,   691,   693,
     695,   697,   699,   701,   703,   706,   709,   711,   716,   718,
     720,   721,   725,   729,   730,   733,   735,   737,   739,   741,
     743,   745,   748,   749,   752,   753,   757,   758,   762,   764,
     765,   769,   771,   773,   775,   777,   779,   781,   784,   786,
     787,   789,   790,   796,   798,   800,   802,   807,   812,   819,
     821,   823,   825,   827,   832,   839,   841,   846,   853,   855,
     857,   859,   861,   863,   866,   869,   871,   876,   877,   885,
     886,   899,   900,   905,   906,   912,   914,   918,   921,   923,
     927,   929,   930,   933,   936,   938,   941,   947,   952,   955,
     960,   966,   970,   971,   972,   983,   985,   986,   989,   991,
     994,   995,   999,  1000,  1004,  1005,  1009,  1014,  1020,  1022,
    1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,  1042,
    1044,  1046,  1048,  1050,  1052,  1054,  1056,  1059,  1061,  1063,
    1065,  1067,  1070,  1072,  1074,  1076,  1079,  1082,  1084,  1086,
    1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1103,  1105,
    1107,  1109,  1111,  1115,  1117,  1121,  1122,  1124,  1126,  1130,
    1132,  1136,  1138,  1139,  1141,  1143,  1145,  1148,  1150,  1152,
    1156,  1161,  1166,  1171,  1174,  1177,  1180,  1183,  1185,  1187,
    1189,  1193,  1195,  1198,  1201,  1203,  1204,  1208,  1211,  1214,
    1216,  1220,  1225,  1230,  1236,  1242,  1244,  1246,  1249,  1252,
    1255,  1258,  1260,  1263,  1266,  1269,  1272,  1275,  1278,  1281,
    1284,  1287,  1290,  1293,  1296,  1299,  1302,  1303,  1304,  1305,
    1312,  1313,  1314,  1321,  1322,  1323,  1330,  1331,  1332,  1339,
    1340,  1341,  1348,  1349,  1350,  1357,  1359,  1364,  1369,  1374,
    1379,  1384,  1386,  1388,  1390,  1392,  1397,  1402,  1407,  1412,
    1415,  1418,  1421,  1422,  1423,  1436,  1437,  1440,  1441,  1442,
    1443,  1452,  1453,  1454,  1465,  1466,  1468,  1469,  1471,  1473,
    1476,  1477,  1481,  1482,  1486,  1487,  1489,  1491,  1494,  1495,
    1499,  1500,  1504,  1508,  1510,  1515,  1519,  1521,  1525,  1527,
    1531,  1533,  1537,  1539,  1542,  1543,  1547,  1548,  1552,  1553,
    1558,  1559,  1564,  1565,  1570,  1573,  1577,  1579,  1583,  1585,
    1587,  1589,  1591,  1593,  1595,  1599,  1601,  1603,  1608,  1615,
    1620,  1624,  1631,  1635,  1642,  1644,  1646,  1648,  1650,  1652,
    1654,  1656,  1657,  1660,  1664,  1666,  1670,  1672,  1677,  1679,
    1681,  1682,  1683,  1685,  1690,  1694,  1701,  1705,  1712,  1714,
    1716,  1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,
    1737,  1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,
    1757,  1759,  1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,
    1777,  1779,  1781,  1783,  1785,  1787,  1789,  1791,  1793,  1795,
    1797,  1799,  1801,  1803,  1805,  1807,  1810,  1813,  1815,  1819,
    1821,  1824,  1827,  1830,  1835,  1838,  1841,  1846,  1847,  1856,
    1857,  1859,  1861,  1862,  1865,  1866,  1869,  1870,  1873,  1874,
    1878,  1879,  1882,  1883,  1891,  1892,  1893,  1897,  1903,  1904,
    1910,  1915,  1917,  1921,  1925,  1929,  1930,  1933,  1934,  1936,
    1938,  1941,  1942,  1947,  1948,  1953,  1954,  1958,  1959,  1963,
    1964,  1968,  1969,  1973,  1974,  1978,  1979,  1984,  1985,  1990,
    1992,  1996,  1998,  2000,  2002,  2006,  2008,  2010,  2012,  2016,
    2018,  2022,  2025,  2030,  2032,  2034,  2036,  2037,  2042,  2048,
    2055,  2056,  2067,  2071,  2073,  2075,  2078,  2081,  2082,  2085,
    2086,  2090,  2092,  2093,  2097,  2100,  2101,  2105,  2107,  2111,
    2113,  2117,  2118,  2121,  2123,  2125,  2127,  2129,  2131,  2133,
    2135,  2137,  2139,  2141,  2143,  2145,  2147,  2149,  2151,  2154,
    2158,  2159,  2160,  2168,  2170,  2172,  2175,  2178,  2181,  2185,
    2190,  2191,  2192,  2202,  2203,  2205,  2207,  2210,  2213,  2215,
    2217,  2219,  2221,  2223,  2225,  2227,  2229,  2231,  2233,  2235,
    2236,  2238,  2240,  2242,  2245,  2246,  2247,  2248,  2249,  2263,
    2265,  2266,  2268,  2272,  2273,  2274,  2281,  2285,  2286,  2288,
    2291,  2292,  2294,  2296,  2299,  2301,  2303,  2305,  2307,  2308,
    2312,  2315,  2317,  2318,  2319,  2320,  2335,  2336,  2342,  2344,
    2345,  2349,  2350,  2358,  2359,  2365,  2367,  2370,  2371,  2373,
    2375,  2377,  2378,  2380,  2382,  2385,  2388,  2391,  2393,  2395,
    2397,  2399,  2403,  2405,  2407,  2408,  2409,  2417,  2419,  2422,
    2423,  2427,  2428,  2433,  2434,  2440,  2448,  2449,  2453,  2454,
    2455,  2457,  2459,  2461,  2464,  2469,  2477,  2479,  2481,  2483,
    2488,  2493,  2495,  2497,  2499,  2501,  2504,  2506,  2510,  2514,
    2521,  2523,  2527,  2529,  2531,  2535,  2537,  2539,  2541,  2546,
    2554,  2556,  2558,  2560,  2562,  2565,  2566,  2568,  2570,  2574,
    2576,  2580,  2582,  2586,  2588,  2592,  2594,  2598,  2600,  2602,
    2604,  2606,  2610,  2612,  2614,  2618,  2620,  2622,  2624,  2628,
    2631,  2632,  2634,  2636,  2641,  2643,  2647,  2649,  2653,  2661,
    2662,  2670,  2671,  2678,  2682,  2684,  2688,  2690,  2693,  2699,
    2700,  2708,  2709,  2712,  2713,  2715,  2721,  2724,  2730,  2731,
    2737,  2744,  2749,  2750,  2752,  2754,  2759,  2760,  2763,  2764,
    2770,  2775,  2778,  2780,  2784,  2787,  2790,  2793,  2796,  2799,
    2802,  2804,  2807,  2810,  2813,  2816,  2819,  2822,  2825,  2828,
    2831,  2833,  2835,  2837,  2839,  2841,  2843,  2849,  2851,  2853,
    2856,  2861,  2863,  2864,  2875,  2881,  2882,  2884,  2885,  2888,
    2890,  2893,  2894,  2898,  2900,  2901,  2906,  2907,  2910,  2912,
    2916,  2918,  2920,  2924,  2929,  2934,  2937,  2939,  2941,  2943,
    2945,  2946,  2948,  2949,  2950,  2951,  2962,  2965,  2968,  2972,
    2975,  2977,  2980,  2981,  2985,  2986,  2990,  2991,  2995,  2996,
    3000,  3001,  3005,  3006,  3011,  3012,  3017,  3019,  3021,  3023,
    3025,  3027,  3029,  3030,  3035,  3036,  3038,  3039,  3044,  3046,
    3049,  3052,  3055,  3056,  3058,  3060,  3063,  3067,  3068,  3071,
    3075,  3079,  3085,  3086,  3089,  3094,  3096,  3098,  3100,  3102,
    3104,  3105,  3107,  3109,  3113,  3116,  3122,  3128,  3134,  3140,
    3146,  3152,  3158,  3159,  3162,  3164,  3167,  3170,  3173,  3176,
    3179,  3182,  3184,  3187,  3190,  3193,  3196,  3198,  3201,  3204,
    3207,  3210,  3212,  3214,  3216,  3217,  3220,  3223,  3226,  3229,
    3232,  3235,  3238,  3241,  3244,  3246,  3248,  3250,  3253,  3256,
    3259,  3262,  3265,  3267,  3269,  3271,  3272,  3276,  3279,  3280,
    3281,  3282,  3283,  3284,  3299,  3300,  3303,  3305,  3306,  3311,
    3314,  3315,  3317,  3318,  3319,  3320,  3321,  3322,  3337,  3340,
    3341,  3342,  3343,  3354,  3355,  3357,  3361,  3365,  3368,  3373,
    3377,  3381,  3385,  3387,  3389,  3391,  3393,  3395,  3397,  3401,
    3402,  3403,  3411,  3412,  3413,  3422,  3423,  3425,  3427,  3431,
    3434,  3437,  3439,  3441,  3443,  3447,  3449,  3451,  3454,  3456,
    3458,  3460,  3463,  3465,  3467,  3469,  3471,  3473,  3476,  3483,
    3490,  3491,  3493,  3494,  3496,  3499,  3505,  3506,  3509,  3512,
    3514,  3522,  3524,  3530,  3534,  3536,  3540,  3542,  3546,  3548,
    3552,  3554,  3558,  3560,  3562,  3564,  3566,  3567,  3573,  3574,
    3580,  3582,  3583,  3587,  3589,  3593,  3595,  3599,  3601,  3605,
    3607,  3609,  3610,  3611,  3617,  3620,  3622,  3623,  3624,  3628,
    3629,  3630,  3634,  3636,  3638,  3640,  3642,  3644,  3647,  3650,
    3652,  3656,  3661,  3665,  3667,  3672,  3674,  3678,  3679,  3681,
    3685,  3687,  3691,  3694,  3696,  3698,  3699,  3701,  3703,  3705,
    3707,  3708,  3710,  3714,  3715,  3719,  3721,  3723,  3725,  3727,
    3729,  3731,  3733,  3735,  3737,  3739,  3741,  3743,  3745,  3753,
    3754,  3756,  3758,  3760,  3762,  3766,  3768,  3770,  3772,  3775,
    3776,  3780,  3782,  3786,  3788,  3792,  3794,  3796,  3803,  3804,
    3808,  3810,  3814,  3815,  3817,  3822,  3828,  3831,  3833,  3835,
    3840,  3842,  3846,  3851,  3856,  3858,  3862,  3864,  3866,  3868,
    3871,  3873,  3878,  3879,  3881,  3882,  3885,  3887,  3889,  3891,
    3896,  3900,  3902,  3904,  3906,  3909,  3911,  3913,  3915,  3918,
    3921,  3923,  3927,  3930,  3933,  3935,  3939,  3941,  3944,  3949,
    3951,  3954,  3956,  3960,  3965,  3966,  3968,  3969,  3971,  3972,
    3974,  3976,  3980,  3982,  3986,  3988,  3991,  3993,  3997,  4000,
    4003,  4008,  4012,  4013,  4015,  4017,  4019,  4021,  4023,  4026,
    4028,  4030,  4036,  4040,  4046,  4050,  4052,  4056,  4057,  4059,
    4063,  4067,  4071,  4075,  4082,  4088,  4090,  4092,  4094,  4096,
    4098,  4100,  4102,  4104,  4106,  4108,  4110,  4112,  4114,  4116,
    4117,  4119,  4121,  4123,  4125,  4127,  4131,  4133,  4135,  4137,
    4139,  4141,  4146,  4152,  4154,  4160,  4166,  4168,  4170,  4172,
    4177,  4179,  4184,  4186,  4194,  4196,  4198,  4200,  4205,  4212,
    4213,  4216,  4221,  4223,  4225,  4227,  4230,  4232,  4234,  4236,
    4238,  4240,  4244,  4248,  4250,  4252,  4254,  4255,  4259,  4265,
    4268,  4274,  4279,  4281,  4283,  4285,  4287,  4289,  4292,  4295,
    4298,  4301,  4303,  4306,  4309,  4310,  4314,  4315,  4319,  4321,
    4323,  4325,  4327,  4329,  4331,  4333,  4335,  4337,  4339,  4341,
    4343,  4345,  4347,  4349,  4351,  4353,  4355,  4357,  4359,  4361,
    4363,  4365,  4367,  4369,  4371,  4373,  4375,  4377,  4379,  4383,
    4384,  4393,  4394,  4404,  4405,  4413,  4414,  4424,  4425,  4427,
    4430,  4432,  4436,  4438,  4442,  4448,  4450,  4452,  4454,  4456,
    4459,  4460,  4461,  4470,  4476,  4478,  4480,  4488,  4489,  4493,
    4495,  4499,  4501,  4502,  4506,  4507,  4510,  4512,  4516,  4522,
    4530,  4531,  4533,  4535,  4537,  4539,  4543,  4545,  4548,  4550,
    4554,  4557,  4561,  4565,  4569,  4571,  4573,  4575,  4577,  4579,
    4581,  4586,  4592,  4598,  4604,  4610,  4616,  4621,  4628,  4632,
    4634,  4638,  4639,  4641,  4647,  4655,  4656,  4659,  4661,  4663,
    4664,  4668,  4670,  4674,  4676,  4678,  4680,  4681,  4685,  4687,
    4692,  4694,  4698,  4703,  4706,  4708,  4710,  4712,  4717,  4724,
    4726,  4728,  4731,  4735,  4737,  4739,  4741,  4743,  4745,  4747,
    4749,  4751,  4752,  4754,  4758,  4760,  4763,  4767,  4773,  4777,
    4780,  4783,  4788,  4790,  4792,  4795,  4797,  4799,  4803,  4807,
    4811,  4815,  4820,  4825,  4832,  4834,  4837,  4839,  4841,  4843,
    4847,  4853,  4855,  4857,  4859,  4861,  4865,  4868,  4871,  4874,
    4876,  4879,  4882,  4885,  4888,  4891,  4893,  4897,  4900,  4902,
    4905,  4907,  4910,  4912,  4913,  4914,  4921,  4922,  4925,  4926,
    4928,  4930,  4933,  4936,  4939,  4944,  4948,  4950,  4954,  4956,
    4959,  4965,  4968,  4971,  4977,  4978,  4981,  4983,  4985,  4988,
    4995,  5002,  5004,  5005,  5007,  5009,  5012,  5014,  5017,  5019,
    5021,  5023,  5025,  5027,  5029,  5031,  5033,  5035,  5037,  5039,
    5041,  5043,  5045,  5047,  5049,  5051,  5053,  5055,  5057,  5059,
    5061,  5063,  5065,  5067,  5069,  5071,  5073,  5075,  5077,  5079,
    5081,  5083,  5085,  5087,  5089,  5091,  5093,  5095,  5097,  5099,
    5101,  5103,  5105,  5107,  5109,  5111,  5113,  5115,  5117,  5119,
    5121,  5123,  5125,  5127,  5129,  5131,  5133,  5135,  5137,  5139,
    5141,  5143,  5145,  5147,  5149,  5151,  5153,  5155,  5157,  5159,
    5161,  5163,  5165,  5167,  5169,  5171,  5173
};
static const short yyrhs[] =
{
     164,     0,   161,     0,    90,   630,   388,   559,   631,     0,
     104,     0,  1019,     0,    25,     0,   632,     0,   631,     4,
     632,     0,   874,     0,   392,   633,   352,     0,   633,   634,
       0,    25,     0,   635,    25,     0,  1019,     0,    17,   633,
       0,    16,   633,     0,    19,   633,     0,    18,   633,     0,
      20,   633,     0,    17,     0,    16,     0,     0,   637,     0,
       0,   238,   392,   638,   639,   352,     0,   531,   392,    25,
       4,    25,   352,     0,   640,     0,   639,     4,   640,     0,
     451,     0,   492,     0,   498,     0,   467,     0,   371,     0,
     569,     0,   489,     0,   441,     0,   378,     0,   452,     0,
     306,     0,   493,     0,   417,     0,   294,     0,   557,     0,
      64,     0,     0,   642,     0,     0,   238,   392,   643,   644,
     352,     0,   645,     0,   644,     4,   645,     0,   640,     0,
     393,     0,   567,    24,     0,   167,   861,     0,   291,   861,
       0,   248,   861,     0,   299,   861,     0,   257,   861,     0,
     223,   861,     0,   495,   647,     0,   813,   305,  1019,     0,
       0,   253,   392,  1378,   352,   305,   648,  1036,     0,    70,
     392,   874,   352,     0,   368,   392,   866,   352,   305,  1019,
       0,  1154,     0,   156,   392,   866,   352,   305,  1019,     0,
       0,     0,     0,   874,   392,   649,   661,   650,   352,   651,
     659,     0,     0,     0,   435,  1342,   586,  1342,   392,   652,
     661,   653,   352,   659,     0,     0,     0,    30,   392,   654,
     661,   655,   352,   659,     0,     0,     0,     0,   326,   664,
     553,   665,   420,   630,   388,   392,   656,   661,   657,   352,
     658,   660,     0,     0,   305,  1036,     0,     0,   305,  1036,
       0,   128,     0,     0,   662,     0,   663,     0,   662,     4,
     663,     0,  1019,     0,  1393,     4,  1019,     0,   784,     0,
      24,     0,   874,     0,   874,     0,     0,   496,   791,   667,
     670,   674,   671,     0,     0,   496,   668,   669,   672,   671,
       0,   676,     0,   669,   676,     0,   678,     0,   670,   678,
       0,   321,     0,     0,     0,   301,   673,  1388,     0,     0,
       0,   301,   675,  1388,     0,     0,   542,   791,   677,  1388,
       0,     0,   542,   791,   679,  1388,     0,   242,   871,     0,
     166,   869,     0,    47,   869,     0,   135,     0,   151,  1348,
       0,   455,   868,     0,    28,   682,    29,     0,   683,     0,
     685,     0,   684,     0,   683,   684,     0,    27,     0,   686,
       0,   685,   686,     0,    26,     0,   355,     0,     0,     0,
     282,   689,   691,   690,   692,     0,   345,  1019,   588,   693,
     909,   936,   636,     0,  1019,   588,   693,   909,   508,  1378,
     936,   636,     0,     0,   695,   155,     0,   694,     0,   693,
       4,   694,     0,   874,     0,   874,   583,   874,     0,   874,
     583,    19,     0,   696,     0,   695,   696,     0,     0,   234,
     702,   697,  1388,     0,     0,   237,   703,   698,  1388,     0,
       0,   937,   699,  1388,     0,     0,   133,   700,  1388,     0,
       0,   129,   701,  1388,     0,   880,     0,   702,     4,   880,
       0,   880,     0,   703,     4,   880,     0,    58,     0,    59,
       0,    60,     0,    61,     0,    62,     0,    63,     0,   121,
       0,   243,     0,     0,   707,     0,   708,     0,   707,   708,
       0,     0,   399,   709,   710,     0,   755,     0,  1368,     0,
     713,     0,   710,     4,   713,     0,     0,   712,   874,     0,
     314,   711,   754,    24,     0,   314,   711,   754,   882,     0,
     314,   711,   754,    25,     0,   717,   733,     0,     0,   711,
     314,   714,   715,     0,    25,     0,    24,     0,   882,     0,
      16,    25,     0,   711,     0,   716,     0,   717,     4,   716,
       0,     0,   497,     0,     0,   448,   420,   725,   388,   720,
     587,   733,     0,     0,   280,   718,   722,    25,   723,   266,
     420,   724,   388,   721,   587,   733,     0,   392,     0,   419,
       0,   352,     0,   387,     0,    25,     0,   726,     4,   726,
       4,   726,     0,   726,     4,   726,     0,   726,     0,    25,
       0,     0,   425,   728,   710,   247,     0,     0,   224,   729,
     711,   583,    19,     0,     0,   296,   730,   711,   222,   392,
     731,   352,     0,   732,     0,   731,     4,   732,     0,   711,
       0,   734,     0,     0,   735,   736,     0,   719,     0,   727,
       0,   497,     0,   497,   392,    25,   352,     0,   385,   392,
      25,   352,     0,   385,   392,    25,     4,    25,   352,     0,
     369,     0,   580,   711,     0,   340,     0,   470,     0,    55,
       0,   359,     0,   359,   392,    25,   352,     0,   359,   392,
      25,     4,    25,   352,     0,   473,     0,   473,   392,    25,
     352,     0,   473,   392,    25,     4,    25,   352,     0,   463,
       0,   263,     0,   499,     0,   494,     0,    44,     0,    45,
       0,   537,     0,   318,   740,     0,   330,   741,     0,   737,
       0,   518,   738,   583,   739,     0,   711,     0,   711,     0,
       0,   742,   589,   745,     0,   750,   589,   753,     0,     0,
     743,   744,     0,   545,     0,   474,     0,   554,     0,   514,
       0,   415,     0,   431,     0,   327,   747,     0,     0,   746,
     744,     0,     0,   392,   749,   352,     0,     0,   392,    25,
     352,     0,    25,     0,     0,   751,   752,   748,     0,   545,
       0,   474,     0,   554,     0,   514,     0,   415,     0,   431,
       0,   327,   747,     0,   752,     0,     0,    12,     0,     0,
     201,   874,   756,   580,   757,     0,   759,     0,   762,     0,
     497,     0,   497,   392,    25,   352,     0,   385,   392,    25,
     352,     0,   385,   392,    25,     4,    25,   352,     0,   369,
       0,   340,     0,   470,     0,   359,     0,   359,   392,    25,
     352,     0,   359,   392,    25,     4,    25,   352,     0,   473,
       0,   473,   392,    25,   352,     0,   473,   392,    25,     4,
      25,   352,     0,   463,     0,   263,     0,   499,     0,   494,
       0,   537,     0,   318,   740,     0,   330,   741,     0,   758,
       0,   518,   738,   583,   739,     0,     0,   448,   420,   725,
     388,   760,   587,   757,     0,     0,   280,   718,   722,    25,
     723,   266,   420,   724,   388,   761,   587,   757,     0,     0,
     425,   763,   765,   247,     0,     0,   224,   764,   874,   583,
      19,     0,   766,     0,   765,     4,   766,     0,   767,   757,
       0,   768,     0,   767,     4,   768,     0,   874,     0,     0,
     581,   865,     0,    35,   874,     0,    33,     0,   589,  1378,
       0,   589,   470,   874,   617,  1378,     0,   589,   470,   874,
     350,     0,    37,   874,     0,   122,   807,  1036,   773,     0,
     362,   807,   789,   769,   773,     0,   173,   871,   773,     0,
       0,     0,   154,   771,  1043,   589,   874,   583,    19,   636,
     772,   774,     0,   636,     0,     0,   775,   203,     0,   776,
       0,   775,   776,     0,     0,   312,   777,  1388,     0,     0,
     308,   778,  1388,     0,     0,   937,   779,  1388,     0,   459,
     807,   790,   636,     0,   459,   807,   790,   636,    31,     0,
     250,     0,   249,     0,   176,     0,   325,     0,   140,     0,
     175,     0,   290,     0,   289,     0,   207,     0,   137,     0,
     136,     0,   110,     0,   168,     0,    93,     0,   109,     0,
     153,     0,   119,     0,   177,     0,   177,   791,     0,   794,
       0,   793,     0,   796,     0,   822,     0,   784,   785,     0,
     823,     0,   825,     0,   795,     0,    16,   784,     0,    17,
     784,     0,   798,     0,   806,     0,   800,     0,   436,     0,
     704,     0,   801,     0,   802,     0,   803,     0,   804,     0,
     805,     0,     0,   788,     0,   791,     0,   444,     0,   787,
       0,   788,     4,   787,     0,   791,     0,   789,     4,   791,
       0,     0,  1395,     0,   791,     0,  1395,     4,   791,     0,
     791,     0,   790,     4,   791,     0,   784,     0,     0,   792,
       0,    17,     0,    16,     0,   566,   784,     0,   445,     0,
     389,     0,   392,   784,   352,     0,    17,   392,   784,   352,
       0,   404,   392,  1324,   352,     0,   258,   392,  1324,   352,
       0,   792,   882,     0,   792,    25,     0,   449,    25,     0,
     449,  1019,     0,    24,     0,   882,     0,    25,     0,  1019,
     382,  1019,     0,  1019,     0,   395,   784,     0,   353,   784,
       0,  1128,     0,     0,   468,   797,  1128,     0,     6,   784,
       0,     5,   784,     0,   784,     0,   799,     4,   784,     0,
     586,   392,  1324,   352,     0,   390,   392,  1324,   352,     0,
     586,   392,   807,   799,   352,     0,   390,   392,   807,   799,
     352,     0,   347,     0,   213,     0,     8,   784,     0,   216,
     784,     0,   518,   784,     0,   332,   784,     0,   351,     0,
       7,   784,     0,    17,   784,     0,    16,   784,     0,    19,
     784,     0,    18,   784,     0,    20,   784,     0,     9,   784,
       0,    12,   784,     0,   418,   784,     0,    10,   784,     0,
      11,   784,     0,    15,   784,     0,    14,   784,     0,    13,
     784,     0,     0,     0,     0,   874,   392,   809,   661,   810,
     352,     0,     0,     0,    30,   392,   811,   661,   812,   352,
       0,     0,     0,   499,   392,   814,   784,   815,   352,     0,
       0,     0,   474,   392,   816,   784,   817,   352,     0,     0,
       0,   554,   392,   818,   784,   819,   352,     0,     0,     0,
     545,   392,   820,   784,   821,   352,     0,   813,     0,   253,
     392,  1378,   352,     0,    65,   392,   866,   352,     0,    36,
     392,   866,   352,     0,   368,   392,   866,   352,     0,   156,
     392,   866,   352,     0,   824,     0,   808,     0,  1300,     0,
     499,     0,   384,   392,   784,   352,     0,   284,   392,   784,
     352,     0,   449,   392,    25,   352,     0,   449,   392,  1019,
     352,     0,   784,    74,     0,   784,    75,     0,   784,    76,
       0,     0,     0,   559,  1019,    12,   791,   589,   791,   829,
     827,  1388,   828,   624,   559,     0,     0,   534,   791,     0,
       0,     0,     0,   365,   831,   868,   832,  1203,   833,  1388,
     205,     0,     0,     0,   596,   874,   835,   706,   836,   965,
     838,   837,   843,   597,     0,     0,   848,     0,     0,   839,
       0,   840,     0,   839,   840,     0,     0,   598,   841,  1388,
       0,     0,   599,   842,  1388,     0,     0,   844,     0,   845,
       0,   844,   845,     0,     0,   600,   846,  1388,     0,     0,
     601,   847,  1388,     0,   849,   853,   286,     0,    57,     0,
      57,   850,   508,   851,     0,    57,   345,   852,     0,  1019,
       0,   850,     4,  1019,     0,   874,     0,   851,     4,   874,
       0,  1019,     0,   852,     4,  1019,     0,   854,     0,   853,
     854,     0,     0,   602,   855,  1388,     0,     0,   603,   856,
    1388,     0,     0,   622,   851,   857,  1388,     0,     0,   442,
     851,   858,  1388,     0,     0,   588,   851,   859,  1388,     0,
     507,   867,     0,   516,    16,    25,     0,   516,     0,   462,
      17,    25,     0,   462,     0,    25,     0,  1019,     0,    24,
       0,   881,     0,   791,     0,   863,     4,   863,     0,   864,
       0,   874,     0,   625,   392,   874,   352,     0,   874,   583,
     625,   392,   874,   352,     0,   874,   420,   633,   388,     0,
     874,   583,    19,     0,   874,   420,   633,   388,   583,    19,
       0,   874,   583,   874,     0,   874,   420,   633,   388,   583,
     874,     0,   875,     0,   875,     0,   875,     0,   875,     0,
     875,     0,   875,     0,   875,     0,     0,   512,    25,     0,
     878,  1387,   879,     0,   883,     0,   878,   876,   879,     0,
    1387,     0,   310,   392,   877,   352,     0,  1021,     0,    24,
       0,     0,     0,   874,     0,   874,   420,   633,   388,     0,
     874,   583,    19,     0,   874,   420,   633,   388,   583,    19,
       0,   874,   583,   874,     0,   874,   420,   633,   388,   583,
     874,     0,  1019,     0,    21,     0,   583,    25,     0,   334,
       0,   453,     0,   454,     0,   351,     0,   455,     0,   314,
       0,   282,     0,   457,     0,   421,     0,   498,     0,   410,
       0,   555,     0,   358,     0,   556,     0,   359,     0,   450,
       0,   443,     0,   521,     0,   361,     0,   319,     0,   458,
       0,   283,     0,   500,     0,   244,     0,   557,     0,   613,
       0,   501,     0,   284,     0,   503,     0,   366,     0,   404,
       0,   545,     0,   474,     0,   554,     0,   520,     0,   436,
       0,   339,     0,   355,     0,   499,     0,   537,     0,   400,
       0,   341,     0,   403,     0,   384,     0,   509,  1370,     0,
     610,   886,     0,   887,     0,   886,     4,   887,     0,   874,
       0,   621,   886,     0,   612,   886,     0,   613,  1378,     0,
     611,   871,   617,  1378,     0,   615,   886,     0,   616,  1378,
       0,   614,   871,   617,  1378,     0,     0,   619,   892,   789,
     895,   896,   897,   893,   894,     0,     0,   607,     0,   608,
       0,     0,   305,  1019,     0,     0,   350,   789,     0,     0,
     618,    25,     0,     0,   609,    25,   898,     0,     0,   361,
      25,     0,     0,   585,   791,   538,   900,  1388,   901,   402,
       0,     0,     0,   504,   902,  1388,     0,    72,   874,   392,
      25,   352,     0,     0,   254,  1048,   905,   589,   444,     0,
     254,  1048,   518,   906,     0,   907,     0,   906,     4,   907,
       0,   738,   583,  1297,     0,   738,   583,    19,     0,     0,
     910,   286,     0,     0,   116,     0,   911,     0,   910,   911,
       0,     0,   234,   925,   912,  1388,     0,     0,   237,   926,
     913,  1388,     0,     0,   312,   914,  1388,     0,     0,   308,
     915,  1388,     0,     0,   937,   916,  1388,     0,     0,   269,
     917,  1388,     0,     0,   239,   918,  1388,     0,     0,   622,
     923,   919,  1388,     0,     0,   442,   921,   920,  1388,     0,
     922,     0,   921,     4,   922,     0,   411,     0,   400,     0,
     924,     0,   923,     4,   924,     0,   411,     0,   400,     0,
     866,     0,   925,     4,   866,     0,   866,     0,   926,     4,
     866,     0,   276,   929,     0,   277,   874,   617,   929,     0,
     524,     0,   335,     0,   866,     0,     0,   623,   932,   931,
     908,     0,   345,  1036,   909,   873,   636,     0,  1036,   909,
     508,  1378,   873,   636,     0,     0,   448,  1043,   909,   508,
     874,   583,    19,   873,   933,   636,     0,   430,  1378,   935,
       0,   590,     0,   501,     0,    40,    25,     0,    46,    25,
       0,     0,   512,    25,     0,     0,   391,   938,   944,     0,
     259,     0,     0,   560,   940,   944,     0,   267,   946,     0,
       0,   560,   943,   944,     0,   946,     0,   392,   945,   352,
       0,   946,     0,   945,     4,   946,     0,     0,   947,   948,
       0,   558,     0,   274,     0,   292,     0,   268,     0,   446,
       0,   403,     0,   590,     0,   501,     0,   427,     0,   502,
       0,   517,     0,   481,     0,   272,     0,   273,     0,    24,
       0,   471,   874,     0,   471,   874,   553,     0,     0,     0,
     562,   951,  1041,   952,    12,   807,   953,     0,   444,     0,
     790,     0,   183,  1019,     0,   172,  1019,     0,   186,  1019,
       0,   412,  1019,   295,     0,   412,  1019,   346,   862,     0,
       0,     0,   965,  1357,   979,   965,   959,   706,   965,   960,
     961,     0,     0,   962,     0,   964,     0,   962,   964,     0,
      32,   874,     0,   967,     0,   973,     0,   985,     0,  1138,
       0,  1147,     0,  1006,     0,  1368,     0,   834,     0,   681,
       0,   903,     0,   687,     0,     0,   681,     0,  1368,     0,
     328,     0,   472,   328,     0,     0,     0,     0,     0,   966,
     968,   874,   392,   969,  1034,   352,   970,   706,   971,   965,
    1388,   972,     0,   174,     0,     0,   874,     0,  1398,     4,
     874,     0,     0,     0,   519,   974,   706,   975,  1388,   322,
       0,   427,   807,   786,     0,     0,   789,     0,   317,  1308,
       0,     0,   980,     0,   981,     0,   980,   981,     0,   982,
       0,   681,     0,  1368,     0,   978,     0,     0,   367,   983,
     984,     0,   706,   206,     0,   862,     0,     0,     0,     0,
      79,   874,    78,   874,   392,   986,  1034,   352,   987,   706,
     988,   965,  1388,   972,     0,     0,   520,   990,  1005,   996,
     991,     0,   323,     0,     0,   199,   993,  1388,     0,     0,
     354,   997,   998,   999,   873,   994,  1388,     0,     0,   354,
     997,   873,   995,  1388,     0,   992,     0,   996,   992,     0,
       0,   939,     0,    24,     0,  1019,     0,     0,  1019,     0,
      24,     0,   215,  1003,     0,   227,  1004,     0,   210,  1004,
       0,   549,     0,    24,     0,  1019,     0,  1003,     0,  1004,
       4,  1003,     0,  1019,     0,    24,     0,     0,     0,   604,
     874,  1007,   706,  1008,  1009,   605,     0,  1010,     0,  1009,
    1010,     0,     0,   606,  1011,  1388,     0,     0,   588,   874,
    1012,  1388,     0,     0,  1015,   636,  1018,  1014,  1017,     0,
    1015,   895,   896,   897,   893,   894,  1017,     0,     0,   331,
    1016,   790,     0,     0,     0,    31,     0,  1020,     0,  1021,
       0,   626,  1021,     0,  1021,   878,   583,  1025,     0,  1021,
     878,   583,   874,   420,  1028,   388,     0,  1026,     0,   874,
       0,  1022,     0,   874,   419,  1024,   387,     0,   874,   419,
    1024,   387,     0,  1019,     0,    24,     0,    19,     0,   874,
       0,   874,  1027,     0,  1021,     0,  1399,     4,  1021,     0,
     420,  1028,   388,     0,   420,  1028,   388,   420,  1028,   388,
       0,  1029,     0,  1028,     4,  1029,     0,   633,     0,  1401,
       0,  1400,     4,  1401,     0,   633,     0,  1031,     0,  1033,
       0,  1031,   878,   583,  1032,     0,  1031,   878,   583,   874,
     420,  1028,   388,     0,   874,     0,  1023,     0,    19,     0,
     874,     0,   874,  1027,     0,     0,  1035,     0,  1037,     0,
    1035,     4,  1037,     0,  1038,     0,  1402,     4,  1038,     0,
    1038,     0,  1036,     4,  1038,     0,   874,     0,   874,   583,
     874,     0,  1019,     0,  1019,   382,  1019,     0,    24,     0,
     882,     0,    25,     0,  1040,     0,  1039,     4,  1040,     0,
    1019,     0,  1042,     0,  1041,     4,  1042,     0,  1030,     0,
    1019,     0,  1045,     0,  1044,     4,  1045,     0,  1019,  1046,
       0,     0,   551,     0,   500,     0,   874,   420,  1028,   388,
       0,  1049,     0,  1048,     4,  1049,     0,  1019,     0,  1019,
     382,  1019,     0,   218,   870,   581,   864,   543,  1380,   641,
       0,     0,   581,   392,   791,     4,   791,   352,  1052,     0,
       0,   531,   392,   791,     4,   791,   352,     0,   219,   874,
    1051,     0,   874,     0,   300,   872,  1056,     0,  1057,     0,
     508,   791,     0,  1058,  1059,  1064,     7,  1054,     0,     0,
     581,  1060,   392,   791,     4,   791,   352,     0,     0,   518,
     875,     0,     0,   311,     0,   181,  1348,   230,  1363,  1063,
       0,   526,   867,     0,   526,   867,     7,   807,   789,     0,
       0,   580,   539,  1342,   334,  1342,     0,   580,   539,  1342,
       4,   334,  1342,     0,   580,  1342,     4,  1342,     0,     0,
     607,     0,   608,     0,    56,  1363,  1066,  1067,     0,     0,
     580,  1363,     0,     0,   580,   539,  1342,     7,  1342,     0,
     539,  1342,     7,  1342,     0,   373,  1069,     0,  1070,     0,
    1069,     4,  1070,     0,   167,   861,     0,   248,   861,     0,
     291,   861,     0,   299,   861,     0,   257,   861,     0,   223,
     861,     0,   941,     0,   400,   942,     0,   411,   942,     0,
     524,   942,     0,   335,   942,     0,   512,   942,     0,   510,
     862,     0,   511,   862,     0,   362,   637,     0,   623,   637,
       0,   255,     0,   159,     0,   117,     0,    94,     0,   112,
       0,   103,     0,  1347,   375,  1074,   508,  1072,     0,  1019,
       0,    24,     0,   364,  1074,     0,   364,  1074,     7,  1036,
       0,   875,     0,     0,   423,  1083,   636,   559,  1078,  1019,
     873,   636,  1076,  1079,     0,   423,  1083,   636,   305,  1019,
       0,     0,   497,     0,     0,  1080,   246,     0,  1081,     0,
    1080,  1081,     0,     0,   937,  1082,  1388,     0,   790,     0,
       0,   568,   867,  1085,  1086,     0,     0,   508,  1087,     0,
    1088,     0,  1087,     4,  1088,     0,  1336,     0,   444,     0,
     184,  1091,    54,     0,   184,  1091,   589,  1090,     0,   184,
    1091,    53,  1090,     0,   184,  1091,     0,  1363,     0,    24,
       0,   881,     0,   874,     0,     0,   440,     0,     0,     0,
       0,   111,  1091,  1092,   392,  1094,   807,  1095,   977,  1096,
     352,     0,   157,  1091,     0,  1129,  1137,     0,   408,   460,
     570,     0,   408,  1100,     0,  1101,     0,  1100,  1101,     0,
       0,    99,  1102,  1388,     0,     0,   163,  1103,  1388,     0,
       0,   192,  1104,  1388,     0,     0,   180,  1105,  1388,     0,
       0,   217,  1106,  1388,     0,     0,   165,  1019,  1107,  1388,
       0,     0,   188,  1019,  1108,  1388,     0,  1119,     0,  1121,
       0,  1120,     0,  1110,     0,  1145,     0,  1113,     0,     0,
     523,   791,  1111,   443,     0,     0,   443,     0,     0,   532,
     791,  1114,  1112,     0,   124,     0,   592,  1133,     0,   127,
    1133,     0,   126,  1133,     0,     0,  1116,     0,  1117,     0,
    1116,  1117,     0,  1126,  1118,  1125,     0,     0,   581,  1133,
       0,   480,  1115,  1125,     0,   479,  1342,  1125,     0,   478,
    1124,  1123,  1122,  1125,     0,     0,   118,   784,     0,   118,
     784,     4,   784,     0,   576,     0,   577,     0,   578,     0,
     579,     0,  1019,     0,     0,   482,     0,  1127,     0,  1126,
       4,  1127,     0,   791,  1158,     0,   573,   392,   784,   352,
    1144,     0,   457,   392,    19,   352,  1144,     0,   374,   392,
      19,   352,  1144,     0,   348,   392,   784,   352,  1144,     0,
     552,   392,   784,   352,  1144,     0,   565,   392,   784,   352,
    1144,     0,   564,   392,   784,   352,  1144,     0,     0,   422,
    1130,     0,  1131,     0,  1130,  1131,     0,   191,    25,     0,
     182,    25,     0,   265,    25,     0,   150,    25,     0,   220,
      25,     0,   142,     0,   304,    24,     0,   304,  1019,     0,
     143,    24,     0,   125,    24,     0,  1136,     0,  1132,  1136,
       0,  1134,    74,     0,  1134,    76,     0,  1134,    75,     0,
    1134,     0,   882,     0,    25,     0,     0,   422,  1132,     0,
     191,  1133,     0,   182,  1133,     0,   265,  1133,     0,   150,
    1133,     0,   220,  1133,     0,   221,  1133,     0,   591,    24,
       0,   592,  1133,     0,   595,     0,   593,     0,   594,     0,
      41,  1133,     0,    42,  1133,     0,    43,  1133,     0,   304,
      24,     0,   143,    24,     0,   361,     0,    38,     0,    39,
       0,     0,   475,   582,  1044,     0,   100,  1044,     0,     0,
       0,     0,     0,     0,   426,  1139,   874,   392,  1140,  1034,
     352,  1141,   706,  1098,  1142,  1099,  1143,   204,     0,     0,
     487,   784,     0,  1388,     0,     0,  1388,   504,  1405,  1388,
       0,   477,  1146,     0,     0,  1072,     0,     0,     0,     0,
       0,     0,    71,  1148,   874,   392,  1149,  1034,   352,  1150,
     706,  1153,  1151,  1099,  1152,   204,     0,  1135,  1137,     0,
       0,     0,     0,   120,   392,    24,     4,  1155,   661,  1156,
     352,  1157,   659,     0,     0,   344,     0,   344,   182,    25,
       0,   344,   182,  1019,     0,   571,   791,     0,   571,   791,
     305,  1019,     0,   571,   791,   128,     0,   571,   791,   541,
       0,   571,   791,   506,     0,  1161,     0,   139,     0,   285,
       0,   245,     0,   874,     0,  1163,     0,    69,  1169,   352,
       0,     0,     0,   170,  1164,  1292,   392,  1165,  1171,   352,
       0,     0,     0,    97,  1166,  1292,   392,  1167,  1171,   352,
    1168,     0,     0,   232,     0,  1170,     0,  1169,     4,  1170,
       0,   874,   551,     0,   874,   500,     0,   874,     0,   874,
       0,  1172,     0,  1171,     4,  1172,     0,  1243,     0,  1241,
       0,    86,   874,     0,   145,     0,   229,     0,   195,     0,
     130,  1176,     0,   107,     0,    95,     0,    85,     0,    83,
       0,    87,     0,   144,  1348,     0,   194,  1175,   421,  1342,
     589,  1342,     0,   262,   867,   421,  1342,   589,  1342,     0,
       0,  1348,     0,     0,   791,     0,   483,   791,     0,   439,
    1292,   547,  1180,  1179,     0,     0,   115,   868,     0,   487,
    1265,     0,  1181,     0,   392,  1185,   352,    12,   392,  1186,
     352,     0,  1182,     0,    19,    12,   392,  1186,   352,     0,
      19,    12,  1186,     0,  1184,     0,  1182,     4,  1184,     0,
    1297,     0,  1183,    12,  1187,     0,  1183,     0,  1185,     4,
    1183,     0,  1187,     0,  1186,     4,  1187,     0,  1336,     0,
     444,     0,  1331,     0,   193,     0,     0,   212,  1190,  1292,
    1193,  1191,     0,     0,   440,  1192,   392,  1195,   352,     0,
    1330,     0,     0,   392,  1194,   352,     0,  1297,     0,  1194,
       4,  1297,     0,  1297,     0,  1194,     4,  1297,     0,  1196,
       0,  1195,     4,  1196,     0,  1336,     0,   444,     0,     0,
       0,   461,  1198,  1200,  1199,  1201,     0,  1205,   868,     0,
     868,     0,     0,     0,   515,  1202,  1036,     0,     0,     0,
     515,  1204,  1036,     0,   462,     0,   516,     0,   524,     0,
     335,     0,   357,     0,   338,   791,     0,   311,   791,     0,
    1019,     0,  1409,     4,  1019,     0,   202,  1292,   115,   868,
       0,   202,  1292,  1262,     0,  1411,     0,  1410,   486,  1283,
    1411,     0,  1330,     0,   392,  1410,   352,     0,     0,  1208,
       0,   475,   582,  1209,     0,  1210,     0,  1209,     4,  1210,
       0,  1211,  1212,     0,    25,     0,  1297,     0,     0,   551,
       0,   500,     0,   240,     0,   271,     0,     0,   288,     0,
     317,  1363,  1215,     0,     0,  1347,  1218,  1219,     0,  1247,
       0,  1251,     0,  1214,     0,  1349,     0,  1213,     0,  1216,
       0,  1206,     0,  1207,     0,  1197,     0,  1189,     0,  1188,
       0,  1320,     0,  1178,     0,   466,  1222,   588,  1292,   589,
    1227,  1221,     0,     0,   106,     0,   134,     0,  1223,     0,
    1224,     0,  1223,     4,  1224,     0,   432,     0,   411,     0,
     400,     0,   439,  1225,     0,     0,   392,  1226,   352,     0,
    1297,     0,  1226,     4,  1297,     0,  1228,     0,  1227,     4,
    1228,     0,   424,     0,  1294,     0,   200,  1292,  1230,   580,
    1330,  1232,     0,     0,   392,  1231,   352,     0,  1297,     0,
    1231,     4,  1297,     0,     0,   105,     0,   453,   392,  1265,
     352,     0,   209,   392,  1236,   352,  1235,     0,   260,  1237,
       0,  1238,     0,  1292,     0,  1292,   392,  1238,   352,     0,
    1297,     0,  1238,     4,  1297,     0,   437,   392,  1240,   352,
       0,   222,   392,  1240,   352,     0,  1297,     0,  1240,     4,
    1297,     0,  1239,     0,  1234,     0,  1233,     0,   361,  1299,
       0,   171,     0,  1297,  1284,  1244,  1245,     0,     0,  1242,
       0,     0,  1246,  1245,     0,   333,     0,   123,     0,  1235,
       0,   453,   392,  1265,   352,     0,    84,  1248,  1250,     0,
    1249,     0,  1294,     0,  1251,     0,  1250,  1251,     0,  1229,
       0,  1220,     0,  1336,     0,   409,  1265,     0,   329,  1254,
       0,  1335,     0,  1254,     4,  1335,     0,   487,  1265,     0,
     508,  1257,     0,  1258,     0,  1257,     4,  1258,     0,  1259,
       0,   476,  1259,     0,   476,   392,  1260,   352,     0,  1292,
       0,  1292,  1298,     0,  1258,     0,  1260,     4,  1258,     0,
    1256,  1262,  1263,  1264,     0,     0,  1255,     0,     0,  1253,
       0,     0,  1252,     0,  1266,     0,  1265,     5,  1266,     0,
    1267,     0,  1266,     6,  1267,     0,  1268,     0,   566,  1268,
       0,  1282,     0,   392,  1265,   352,     0,   404,  1331,     0,
     258,  1331,     0,  1336,  1281,  1271,  1331,     0,  1331,  1281,
    1336,     0,     0,  1272,     0,  1273,     0,   549,     0,   533,
       0,   550,     0,   403,  1276,     0,  1338,     0,  1338,     0,
    1336,   586,   392,  1278,   352,     0,  1336,   586,  1331,     0,
    1336,   390,   392,  1278,   352,     0,  1336,   390,  1331,     0,
    1338,     0,  1278,     4,  1338,     0,     0,   566,     0,  1336,
    1279,   347,     0,  1336,  1279,   213,     0,  1336,  1281,  1336,
       0,  1336,  1281,  1331,     0,  1336,  1279,   349,  1336,     6,
    1336,     0,  1336,  1279,   518,  1275,  1274,     0,    12,     0,
      15,     0,    10,     0,    11,     0,   216,     0,   332,     0,
       8,     0,   518,     0,    14,     0,    13,     0,  1280,     0,
    1277,     0,  1270,     0,  1269,     0,     0,   549,     0,   320,
       0,   437,     0,  1415,     0,  1367,     0,   553,   874,   874,
       0,  1367,     0,  1285,     0,  1286,     0,  1288,     0,   497,
       0,   497,   392,  1289,   352,     0,   372,   392,  1290,  1287,
     352,     0,   433,     0,   359,   392,  1290,  1287,   352,     0,
     473,   392,  1290,  1287,   352,     0,   499,     0,   369,     0,
     340,     0,   318,  1306,   589,  1307,     0,   318,     0,   330,
    1306,   589,  1307,     0,   330,     0,   330,  1306,   392,    25,
     352,   589,  1307,     0,   537,     0,   494,     0,   385,     0,
     385,   392,    25,   352,     0,   385,   392,    25,     4,    25,
     352,     0,     0,     4,  1291,     0,   463,   392,  1290,   352,
       0,   528,     0,   263,     0,   463,     0,   401,   302,     0,
      25,     0,    25,     0,    25,     0,    24,     0,  1295,     0,
    1293,   553,  1295,     0,    24,   583,  1295,     0,   874,     0,
     874,     0,   874,     0,     0,   420,    25,   388,     0,   420,
      25,     4,    25,   388,     0,   874,  1296,     0,  1292,   878,
     583,   874,  1296,     0,  1292,   878,   583,    19,     0,   874,
       0,    24,     0,   372,     0,   882,     0,    25,     0,    17,
     882,     0,    17,    25,     0,    16,   882,     0,    16,    25,
       0,  1301,     0,   357,  1303,     0,   357,  1302,     0,     0,
    1306,   589,  1307,     0,     0,  1304,   589,  1305,     0,   545,
       0,   474,     0,   554,     0,   514,     0,   415,     0,   431,
       0,   327,     0,   545,     0,   474,     0,   554,     0,   514,
       0,   415,     0,   431,     0,   327,     0,   545,     0,   474,
       0,   554,     0,   514,     0,   415,     0,   431,     0,   327,
       0,   545,     0,   474,     0,   554,     0,   514,     0,   415,
       0,   431,     0,   327,     0,   874,     0,    24,     0,  1347,
     464,   868,     0,     0,  1347,   360,   868,   398,   559,  1318,
    1311,  1315,     0,     0,  1347,   360,   868,   398,    66,   559,
    1319,  1312,  1315,     0,     0,  1347,   360,   868,   101,  1319,
    1313,  1315,     0,     0,  1347,   360,   868,   102,    66,   559,
    1319,  1314,  1315,     0,     0,   252,     0,   251,  1316,     0,
    1317,     0,  1316,     4,  1317,     0,   874,     0,   874,   583,
     874,     0,    24,   583,   874,   583,   874,     0,  1319,     0,
    1189,     0,  1074,     0,  1321,     0,  1321,  1315,     0,     0,
       0,   432,  1332,  1333,  1322,  1329,  1323,  1261,  1327,     0,
     432,  1332,  1333,  1261,  1327,     0,  1326,     0,  1342,     0,
     432,   878,  1332,  1333,  1329,  1261,  1327,     0,     0,   486,
    1283,  1325,     0,  1208,     0,   293,  1328,  1168,     0,   874,
       0,     0,   293,  1328,  1168,     0,     0,   515,  1039,     0,
    1414,     0,  1418,     4,  1414,     0,   432,   878,  1332,  1333,
    1261,     0,   392,   432,   878,  1332,  1333,  1261,   352,     0,
       0,   549,     0,   320,     0,   437,     0,  1334,     0,  1333,
       4,  1334,     0,  1336,     0,  1336,  1387,     0,  1336,     0,
    1336,    18,  1336,     0,  1336,  1356,     0,  1336,    19,  1336,
       0,  1336,    17,  1336,     0,  1336,    16,  1336,     0,  1367,
       0,  1299,     0,   445,     0,   389,     0,   539,     0,    19,
       0,   457,   392,    19,   352,     0,   552,   392,  1283,  1336,
     352,     0,   564,   392,  1283,  1336,   352,     0,   565,   392,
    1283,  1336,   352,     0,   573,   392,  1283,  1336,   352,     0,
     457,   392,  1283,  1336,   352,     0,   874,   392,  1337,   352,
       0,   499,   878,   392,   878,  1337,   352,     0,   392,  1336,
     352,     0,  1336,     0,  1337,     4,  1336,     0,     0,  1299,
       0,  1347,   307,  1346,  1341,  1325,     0,  1347,   297,  1346,
    1341,   212,  1292,  1343,     0,     0,   283,  1342,     0,    24,
       0,  1019,     0,     0,   392,  1344,   352,     0,  1345,     0,
    1344,     4,  1345,     0,   874,     0,    24,     0,  1019,     0,
       0,   231,  1348,   559,     0,   875,     0,   432,  1332,  1420,
    1421,     0,  1334,     0,  1420,     4,  1334,     0,  1256,  1422,
    1263,  1264,     0,   487,  1265,     0,  1354,     0,  1353,     0,
    1350,     0,   278,  1351,   589,  1351,     0,   261,  1351,   583,
    1352,   589,  1352,     0,   874,     0,   874,     0,   185,   738,
       0,   256,   738,  1355,     0,   235,     0,   141,     0,    58,
       0,    59,     0,    60,     0,    61,     0,    62,     0,    63,
       0,     0,  1358,     0,    81,  1359,    82,     0,  1360,     0,
    1359,  1360,     0,   874,    12,  1362,     0,   874,   420,   388,
      12,  1362,     0,   317,    12,  1361,     0,   423,    24,     0,
      73,    24,     0,   423,    25,     4,    24,     0,    24,     0,
      25,     0,   353,   874,     0,   874,     0,  1361,     0,  1362,
      17,  1362,     0,  1362,    16,  1362,     0,  1362,   586,  1362,
       0,   392,  1362,   352,     0,    80,  1361,   589,  1362,     0,
      77,  1361,   589,  1362,     0,   575,  1362,   543,  1361,   588,
    1362,     0,  1364,     0,   626,  1365,     0,  1365,     0,  1047,
       0,   874,     0,  1365,   583,  1366,     0,    24,   583,  1365,
     583,  1366,     0,    19,     0,  1047,     0,   874,     0,  1364,
       0,  1364,   382,  1364,     0,    92,  1369,     0,    96,  1369,
       0,    91,  1369,     0,   131,     0,   132,  1369,     0,    89,
    1369,     0,   114,  1369,     0,   113,  1369,     0,    88,  1369,
       0,   316,     0,   584,   589,  1370,     0,   509,  1370,     0,
     535,     0,   495,  1371,     0,   874,     0,   553,   874,     0,
     874,     0,     0,     0,   488,  1373,   791,  1374,  1388,   287,
       0,     0,   617,  1378,     0,     0,   620,     0,   147,     0,
     241,   869,     0,    34,   869,     0,   270,  1376,     0,   270,
     871,  1375,  1376,     0,   454,  1378,  1376,     0,   866,     0,
    1378,     4,   866,     0,    68,     0,    98,   869,     0,   791,
     529,     4,   791,   353,     0,   470,   791,     0,   228,   869,
       0,    67,  1383,     7,  1384,  1382,     0,     0,   508,   791,
       0,   874,     0,   874,     0,   211,   869,     0,   214,   869,
     589,   791,     4,   791,     0,   214,   869,   582,   791,     4,
     791,     0,     3,     0,     0,  1390,     0,  1391,     0,  1391,
     482,     0,  1389,     0,  1390,  1389,     0,  1392,     0,   627,
       0,   628,     0,   629,     0,   646,     0,   666,     0,   680,
       0,   681,     0,   687,     0,   688,     0,   705,     0,   770,
       0,   780,     0,   781,     0,   782,     0,   783,     0,   826,
       0,   830,     0,   860,     0,   884,     0,   885,     0,   888,
       0,   889,     0,   890,     0,   891,     0,   899,     0,   904,
       0,   927,     0,   928,     0,   930,     0,   934,     0,   949,
       0,   950,     0,   954,     0,   955,     0,   956,     0,   957,
       0,   963,     0,   976,     0,   989,     0,  1000,     0,  1001,
       0,  1002,     0,  1013,     0,  1050,     0,  1053,     0,  1055,
       0,  1061,     0,  1062,     0,  1065,     0,  1068,     0,  1071,
       0,  1073,     0,  1075,     0,  1077,     0,  1084,     0,  1089,
       0,  1093,     0,  1097,     0,  1109,     0,  1159,     0,  1160,
       0,  1162,     0,  1173,     0,  1174,     0,  1177,     0,  1216,
       0,  1217,     0,  1309,     0,  1310,     0,  1339,     0,  1340,
       0,  1368,     0,  1372,     0,  1377,     0,  1379,     0,  1381,
       0,  1385,     0,  1386,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   754,   757,   762,   768,   774,   781,   785,   785,   791,
     801,   803,   804,   805,   806,   820,   822,   823,   824,   825,
     828,   829,   833,   834,   837,   837,   841,   844,   845,   851,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   861,
     862,   863,   864,   865,   866,   869,   870,   873,   873,   881,
     882,   885,   891,   893,   904,   906,   908,   910,   914,   916,
     964,   967,   972,   972,   979,   982,   986,   987,   991,   991,
     991,   991,  1012,  1012,  1012,  1025,  1025,  1025,  1048,  1048,
    1048,  1048,  1085,  1085,  1089,  1090,  1091,  1095,  1099,  1104,
    1108,  1114,  1118,  1124,  1127,  1127,  1133,  1141,  1141,  1159,
    1159,  1175,  1175,  1178,  1178,  1181,  1185,  1185,  1185,  1192,
    1192,  1192,  1200,  1200,  1211,  1211,  1223,  1226,  1229,  1232,
    1235,  1238,  1245,  1250,  1250,  1251,  1251,  1254,  1259,  1259,
    1263,  1267,  1274,  1274,  1274,  1288,  1295,  1303,  1304,  1307,
    1307,  1310,  1314,  1319,  1326,  1326,  1329,  1329,  1337,  1337,
    1342,  1342,  1347,  1347,  1352,  1352,  1364,  1366,  1373,  1375,
    1385,  1389,  1392,  1395,  1398,  1401,  1407,  1411,  1419,  1420,
    1423,  1424,  1427,  1427,  1429,  1430,  1433,  1433,  1436,  1436,
    1439,  1441,  1444,  1448,  1449,  1449,  1465,  1466,  1466,  1466,
    1470,  1477,  1478,  1481,  1481,  1483,  1483,  1489,  1489,  1505,
    1505,  1507,  1507,  1509,  1511,  1513,  1515,  1518,  1522,  1522,
    1523,  1523,  1527,  1527,  1539,  1539,  1544,  1548,  1550,  1550,
    1553,  1555,  1556,  1557,  1564,  1565,  1566,  1567,  1568,  1569,
    1570,  1571,  1575,  1580,  1585,  1589,  1592,  1596,  1597,  1598,
    1599,  1600,  1601,  1602,  1603,  1606,  1607,  1614,  1619,  1621,
    1623,  1623,  1630,  1634,  1634,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1649,  1649,  1652,  1654,  1660,  1662,  1668,  1676,
    1676,  1679,  1680,  1681,  1682,  1683,  1684,  1685,  1691,  1694,
    1694,  1697,  1697,  1704,  1706,  1707,  1709,  1710,  1712,  1714,
    1715,  1716,  1717,  1722,  1728,  1734,  1735,  1737,  1739,  1740,
    1741,  1742,  1743,  1744,  1747,  1748,  1754,  1762,  1762,  1767,
    1767,  1783,  1783,  1785,  1785,  1793,  1793,  1796,  1799,  1800,
    1803,  1807,  1811,  1814,  1817,  1818,  1819,  1820,  1821,  1826,
    1831,  1835,  1838,  1838,  1838,  1853,  1858,  1858,  1862,  1862,
    1864,  1864,  1871,  1871,  1877,  1877,  1886,  1889,  1896,  1898,
    1900,  1902,  1904,  1906,  1908,  1914,  1916,  1920,  1922,  1924,
    1926,  1928,  1930,  1932,  1938,  1943,  1947,  1953,  1955,  1956,
    1957,  1958,  1962,  1963,  1964,  1967,  1972,  1977,  1979,  1980,
    1981,  1982,  1983,  1984,  1985,  1986,  1987,  1992,  1992,  1996,
    1996,  1999,  2005,  2013,  2019,  2026,  2027,  2030,  2032,  2037,
    2038,  2046,  2052,  2052,  2055,  2059,  2068,  2074,  2080,  2086,
    2087,  2088,  2098,  2110,  2120,  2130,  2134,  2137,  2144,  2151,
    2158,  2221,  2270,  2277,  2282,  2289,  2289,  2302,  2308,  2316,
    2319,  2326,  2338,  2348,  2354,  2362,  2368,  2375,  2381,  2386,
    2391,  2398,  2405,  2412,  2418,  2422,  2426,  2430,  2434,  2440,
    2445,  2449,  2454,  2459,  2464,  2469,  2477,  2484,  2484,  2484,
    2507,  2507,  2507,  2528,  2528,  2528,  2533,  2533,  2533,  2537,
    2537,  2537,  2541,  2541,  2541,  2548,  2550,  2557,  2558,  2563,
    2566,  2570,  2571,  2574,  2579,  2585,  2590,  2595,  2598,  2603,
    2607,  2611,  2617,  2617,  2617,  2630,  2633,  2637,  2637,  2637,
    2637,  2660,  2660,  2660,  2680,  2680,  2682,  2683,  2686,  2687,
    2690,  2690,  2696,  2696,  2703,  2704,  2707,  2708,  2711,  2711,
    2717,  2717,  2724,  2727,  2729,  2730,  2734,  2735,  2738,  2738,
    2741,  2742,  2745,  2746,  2749,  2749,  2755,  2755,  2760,  2760,
    2765,  2765,  2770,  2770,  2778,  2787,  2789,  2790,  2791,  2792,
    2793,  2796,  2796,  2799,  2801,  2804,  2806,  2808,  2809,  2810,
    2812,  2814,  2816,  2818,  2822,  2828,  2832,  2834,  2840,  2845,
    2850,  2855,  2855,  2858,  2861,  2865,  2870,  2873,  2881,  2881,
    2883,  2889,  2893,  2894,  2896,  2898,  2900,  2902,  2906,  2915,
    2915,  2921,  2923,  2924,  2925,  2926,  2927,  2928,  2929,  2930,
    2931,  2932,  2933,  2934,  2935,  2936,  2937,  2938,  2939,  2940,
    2941,  2942,  2943,  2944,  2945,  2946,  2947,  2948,  2949,  2950,
    2951,  2952,  2953,  2954,  2955,  2956,  2957,  2958,  2959,  2960,
    2961,  2962,  2963,  2964,  2965,  2967,  2974,  2980,  2981,  2985,
    2990,  2996,  3000,  3004,  3010,  3014,  3018,  3024,  3024,  3032,
    3033,  3033,  3036,  3037,  3040,  3040,  3042,  3042,  3044,  3044,
    3046,  3046,  3049,  3049,  3062,  3062,  3062,  3066,  3074,  3074,
    3078,  3084,  3084,  3088,  3089,  3094,  3095,  3097,  3099,  3104,
    3104,  3106,  3106,  3113,  3113,  3119,  3119,  3124,  3124,  3130,
    3130,  3135,  3135,  3140,  3140,  3145,  3145,  3150,  3150,  3157,
    3159,  3166,  3168,  3172,  3174,  3182,  3184,  3190,  3192,  3199,
    3201,  3210,  3215,  3220,  3221,  3222,  3225,  3225,  3235,  3241,
    3246,  3246,  3256,  3262,  3263,  3264,  3265,  3268,  3268,  3271,
    3271,  3273,  3277,  3277,  3279,  3283,  3283,  3285,  3286,  3289,
    3289,  3294,  3294,  3296,  3297,  3298,  3299,  3300,  3301,  3302,
    3303,  3304,  3305,  3306,  3307,  3308,  3309,  3310,  3314,  3317,
    3324,  3324,  3324,  3347,  3351,  3355,  3361,  3367,  3374,  3385,
    3399,  3399,  3399,  3411,  3413,  3415,  3416,  3419,  3425,  3426,
    3427,  3428,  3429,  3430,  3431,  3432,  3433,  3434,  3435,  3438,
    3438,  3438,  3441,  3441,  3446,  3446,  3446,  3446,  3446,  3473,
    3481,  3482,  3483,  3486,  3486,  3486,  3504,  3509,  3509,  3514,
    3519,  3520,  3533,  3535,  3538,  3538,  3538,  3538,  3541,  3541,
    3552,  3557,  3579,  3579,  3579,  3579,  3606,  3606,  3614,  3623,
    3623,  3632,  3632,  3646,  3646,  3659,  3659,  3661,  3662,  3664,
    3665,  3668,  3669,  3670,  3672,  3677,  3682,  3687,  3690,  3691,
    3694,  3695,  3698,  3699,  3706,  3706,  3706,  3722,  3723,  3727,
    3727,  3738,  3738,  3750,  3750,  3756,  3765,  3765,  3767,  3770,
    3770,  3772,  3795,  3796,  3798,  3803,  3842,  3843,  3844,  3847,
    3861,  3873,  3873,  3877,  3878,  3884,  3937,  3943,  3953,  3958,
    3966,  3971,  3979,  3984,  3988,  3995,  4000,  4022,  4025,  4026,
    4064,  4065,  4068,  4070,  4073,  4127,  4131,  4134,  4139,  4150,
    4154,  4163,  4169,  4178,  4178,  4181,  4182,  4186,  4187,  4188,
    4191,  4194,  4200,  4206,  4210,  4217,  4222,  4229,  4232,  4238,
    4240,  4240,  4240,  4243,  4257,  4263,  4271,  4274,  4278,  4286,
    4287,  4290,  4291,  4294,  4301,  4305,  4312,  4313,  4318,  4322,
    4322,  4326,  4326,  4330,  4331,  4334,  4342,  4346,  4352,  4353,
    4355,  4357,  4361,  4361,  4362,  4366,  4374,  4376,  4380,  4382,
    4384,  4387,  4389,  4390,  4392,  4395,  4398,  4401,  4404,  4407,
    4410,  4414,  4418,  4422,  4425,  4429,  4432,  4433,  4434,  4437,
    4440,  4443,  4446,  4449,  4452,  4455,  4464,  4472,  4472,  4474,
    4481,  4489,  4495,  4495,  4515,  4521,  4522,  4526,  4527,  4529,
    4530,  4532,  4532,  4540,  4548,  4548,  4558,  4560,  4563,  4563,
    4567,  4567,  4572,  4577,  4582,  4587,  4596,  4600,  4600,  4604,
    4607,  4607,  4609,  4609,  4609,  4609,  4625,  4632,  4634,  4637,
    4641,  4641,  4643,  4643,  4647,  4647,  4650,  4650,  4653,  4653,
    4656,  4656,  4659,  4659,  4674,  4674,  4694,  4695,  4696,  4697,
    4698,  4699,  4701,  4701,  4707,  4707,  4710,  4710,  4720,  4721,
    4722,  4729,  4741,  4742,  4745,  4746,  4749,  4752,  4752,  4757,
    4761,  4766,  4771,  4773,  4774,  4777,  4779,  4780,  4781,  4785,
    4795,  4797,  4801,  4805,  4810,  4815,  4823,  4830,  4837,  4844,
    4851,  4858,  4867,  4867,  4869,  4869,  4871,  4873,  4874,  4875,
    4876,  4877,  4878,  4879,  4880,  4881,  4884,  4884,  4887,  4888,
    4889,  4890,  4893,  4893,  4896,  4896,  4898,  4900,  4901,  4902,
    4903,  4904,  4905,  4906,  4907,  4908,  4909,  4910,  4911,  4912,
    4913,  4914,  4915,  4916,  4917,  4921,  4927,  4934,  4943,  4943,
    4943,  4943,  4943,  4943,  4980,  4981,  4986,  4986,  4986,  4991,
    5003,  5004,  5008,  5008,  5008,  5008,  5008,  5008,  5043,  5046,
    5046,  5046,  5046,  5064,  5066,  5067,  5068,  5070,  5072,  5074,
    5078,  5082,  5089,  5094,  5095,  5096,  5099,  5101,  5107,  5110,
    5110,  5110,  5111,  5111,  5111,  5115,  5117,  5122,  5123,  5127,
    5129,  5130,  5132,  5134,  5136,  5140,  5142,  5147,  5149,  5155,
    5157,  5158,  5159,  5160,  5161,  5162,  5163,  5164,  5167,  5170,
    5175,  5176,  5181,  5182,  5183,  5191,  5196,  5197,  5202,  5210,
    5212,  5213,  5216,  5218,  5221,  5221,  5228,  5230,  5236,  5236,
    5240,  5240,  5244,  5244,  5244,  5246,  5256,  5256,  5263,  5263,
    5266,  5269,  5270,  5274,  5276,  5280,  5282,  5286,  5288,  5292,
    5294,  5297,  5297,  5297,  5312,  5317,  5324,  5327,  5327,  5339,
    5342,  5342,  5354,  5357,  5359,  5361,  5363,  5365,  5367,  5371,
    5373,  5376,  5386,  5390,  5392,  5396,  5398,  5402,  5402,  5404,
    5409,  5411,  5415,  5417,  5418,  5421,  5422,  5423,  5426,  5430,
    5437,  5439,  5444,  5458,  5458,  5463,  5468,  5474,  5475,  5478,
    5479,  5483,  5490,  5497,  5501,  5511,  5512,  5516,  5523,  5528,
    5529,  5533,  5536,  5539,  5541,  5545,  5546,  5547,  5548,  5552,
    5553,  5557,  5559,  5563,  5565,  5569,  5571,  5575,  5580,  5581,
    5585,  5587,  5591,  5592,  5596,  5602,  5607,  5612,  5616,  5618,
    5622,  5624,  5629,  5632,  5636,  5638,  5643,  5645,  5646,  5650,
    5653,  5658,  5663,  5664,  5667,  5668,  5672,  5675,  5677,  5678,
    5683,  5688,  5693,  5697,  5699,  5703,  5705,  5711,  5716,  5722,
    5727,  5729,  5733,  5738,  5742,  5744,  5748,  5750,  5751,  5754,
    5755,  5760,  5760,  5763,  5775,  5776,  5779,  5780,  5783,  5784,
    5788,  5790,  5794,  5796,  5800,  5802,  5806,  5808,  5813,  5815,
    5819,  5822,  5826,  5828,  5829,  5831,  5835,  5837,  5844,  5849,
    5853,  5858,  5861,  5863,  5865,  5870,  5872,  5876,  5877,  5881,
    5884,  5886,  5888,  5890,  5892,  5897,  5899,  5900,  5901,  5902,
    5903,  5904,  5905,  5906,  5907,  5911,  5913,  5914,  5915,  5917,
    5918,  5919,  5920,  5925,  5930,  5934,  5936,  5939,  5941,  5942,
    5945,  5947,  5951,  5954,  5955,  5956,  5958,  5959,  5960,  5961,
    5963,  5964,  5966,  5967,  5969,  5970,  5971,  5972,  5974,  5978,
    5979,  5982,  5985,  5986,  5987,  5988,  5992,  5996,  6000,  6004,
    6009,  6012,  6013,  6017,  6019,  6023,  6028,  6029,  6030,  6033,
    6038,  6043,  6052,  6057,  6058,  6059,  6060,  6061,  6063,  6065,
    6067,  6069,  6072,  6075,  6079,  6080,  6084,  6085,  6089,  6089,
    6089,  6089,  6089,  6089,  6089,  6090,  6090,  6090,  6090,  6090,
    6090,  6090,  6093,  6093,  6093,  6093,  6093,  6093,  6093,  6094,
    6094,  6094,  6094,  6094,  6094,  6094,  6096,  6097,  6100,  6109,
    6109,  6115,  6115,  6121,  6121,  6127,  6127,  6137,  6138,  6139,
    6142,  6142,  6145,  6146,  6147,  6151,  6153,  6158,  6162,  6166,
    6177,  6177,  6177,  6191,  6200,  6201,  6203,  6212,  6213,  6217,
    6218,  6223,  6225,  6226,  6230,  6231,  6234,  6236,  6240,  6245,
    6250,  6251,  6252,  6253,  6256,  6258,  6261,  6262,  6266,  6270,
    6273,  6275,  6277,  6279,  6281,  6282,  6283,  6284,  6285,  6286,
    6287,  6289,  6291,  6293,  6295,  6297,  6299,  6301,  6303,  6306,
    6307,  6309,  6310,  6313,  6321,  6326,  6326,  6330,  6330,  6335,
    6335,  6339,  6339,  6343,  6349,  6349,  6352,  6352,  6358,  6360,
    6365,  6367,  6371,  6383,  6387,  6389,  6390,  6393,  6395,  6398,
    6399,  6401,  6408,  6418,  6420,  6427,  6429,  6430,  6431,  6432,
    6433,  6437,  6438,  6441,  6447,  6448,  6451,  6456,  6457,  6460,
    6463,  6465,  6467,  6469,  6473,  6476,  6477,  6478,  6480,  6482,
    6484,  6487,  6490,  6492,  6498,  6509,  6510,  6513,  6515,  6516,
    6517,  6520,  6522,  6523,  6526,  6542,  6619,  6621,  6623,  6625,
    6629,  6634,  6636,  6638,  6640,  6644,  6647,  6652,  6657,  6661,
    6670,  6671,  6675,  6679,  6679,  6679,  6694,  6694,  6697,  6701,
    6706,  6710,  6711,  6712,  6715,  6718,  6723,  6724,  6728,  6731,
    6736,  6740,  6745,  6749,  6754,  6758,  6761,  6765,  6768,  6773,
    6777,  6783,  6785,  6785,  6786,  6786,  6787,  6794,  6803,  6804,
    6806,  6807,  6808,  6809,  6810,  6811,  6812,  6813,  6814,  6815,
    6816,  6817,  6818,  6819,  6820,  6821,  6822,  6823,  6824,  6825,
    6826,  6827,  6828,  6829,  6830,  6831,  6832,  6833,  6834,  6835,
    6836,  6837,  6838,  6839,  6840,  6841,  6842,  6843,  6844,  6845,
    6846,  6847,  6848,  6849,  6850,  6851,  6852,  6853,  6854,  6855,
    6856,  6857,  6858,  6859,  6860,  6861,  6862,  6863,  6864,  6865,
    6866,  6867,  6868,  6869,  6870,  6871,  6872,  6873,  6874,  6875,
    6876,  6877,  6878,  6879,  6880,  6881,  6882
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "NAMED_GEN", "COMMA", "OR", "AND", "USING", 
  "MATCHES", "POWER", "LESS_THAN", "GREATER_THAN", "EQUAL", 
  "GREATER_THAN_EQ", "LESS_THAN_EQ", "NOT_EQUAL", "MINUS", "PLUS", 
  "DIVIDE", "MULTIPLY", "MOD", "NUMBER_VALUE", "SQLERROR", "SQLWARNING", 
  "CHAR_VALUE", "INT_VALUE", "CLINE", "SQLLINE", "KW_CSTART", "KW_CEND", 
  "NEWFORMATSHARED", "WAIT_FOR_KEY", "AT_TERMINATION_CALL", 
  "TO_MAIN_CAPTION", "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", 
  "TO_STATUSBOX", "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "UP_BY", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "DOWN_BY", 
  "CLOSE_STATUSBOX", "ADD_CONSTRAINT", "DROP_CONSTRAINT", 
  "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", "LOCK_MODE_ROW", "TO_PIPE", 
  "TO_PRINTER", "STATUSBOX", "CONNECT_TO", "FORMHANDLER_INPUT", 
  "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE", 
  "UNITS_SECOND", "NO_NEW_LINES", "FIELDTOWIDGET", "WITH_HOLD", 
  "SHOW_MENU", "CWIS", "CREATE_IDX", "FORM_IS_COMPILED", "PDF_REPORT", 
  "IMPORT_FUNCTION", "PROMPT_MANY", "POINTS", "MM", "INCHES", "PREPEND", 
  "MEMBER_OF", "MEMBER_FUNCTION", "APPEND", "TEMPLATE", "END_TEMPLATE", 
  "SQLSICS", "CREATE_SCHEMA", "SQLSIRR", "UPDATESTATS_T", "SQLSICR", 
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
  "DISPLAY_ARRAY", "END_CONSTRUCT", "FIELD_TOUCHED", "FINISH_REPORT", 
  "INFACC", "INPUT_NO_WRAP", "LOCKMODEPAGE", "SETPMOFF", "UNCONSTRAINED", 
  "PAGE_TRAILER", "SETPMON", "BEFGROUP", "CLOSE_WINDOW", "COMMENT_LINE", 
  "CONTINUE_FOR", "CREATE_DB", "CREATE_TABLE", "DEFAULT_NULL", 
  "DELETE_USING", "DISPLAY_FORM", "END_FUNCTION", "EXIT_DISPLAY", 
  "EXIT_FOREACH", "EXIT_PROGRAM", "INFCOLS", "LOCKMODEROW", 
  "ON_EVERY_ROW", "OPEN_SESSION", "RIGHT_MARGIN", "SELECT_USING", 
  "START_REPORT", "UNLOCK_TABLE", "UPDATE_USING", "ACL_BUILTIN", 
  "AFTGROUP", "INFIDX", "INFSTAT", "LEFT_MARGIN", "PAGE_HEADER", 
  "ROLLBACK_W", "SET_SESSION", "SQLSEOFF", "WITH_A_LOG", "ALTER_TABLE", 
  "BEFDISP", "BEFORE_MENU", "CREATE_VIEW", "DEFINE_TYPE", "DELETE_FROM", 
  "END_DISPLAY", "END_REPORT", "END_FOREACH", "END_GLOBALS", 
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
  "AFTINP", "CLEARFORM", "COMMIT_W", "NEXTPAGE", "PREVPAGE", "CTRL_KEY", 
  "INFTABS", "NEXTFIELD", "NEXTFORM", "RENTAB", "ASCENDING", "ASSOCIATE", 
  "CHARACTER", "CONSTRUCT", "DELIMITER", "DOWNSHIFT", "DROP_VIEW", 
  "END_INPUT", "END_WHILE", "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", 
  "FORM_LINE", "INTERRUPT", "INTO_TEMP", "INVISIBLE", "IN_MEMORY", 
  "LINKED_TO", "LOAD_FROM", "LOCKTAB", "MENU_LINE", "OPEN_FORM", 
  "OTHERWISE", "PRECISION", "PROCEDURE", "REPORT_TO", "RETURNING", 
  "UNDERLINE", "UNLOAD_TO", "BEFROW", "UNLOAD_T", "VARIABLE", "ABSOLUTE", 
  "AFTROW", "BUFFERED", "CONSTANT", "CONST", "CONTINUE", "DATABASE", 
  "DATETIME", "DEFAULTS", "DISTINCT", "END_CASE", "END_MAIN", "END_MENU", 
  "END_TYPE", "EXIT_FOR", "EXTERNAL", "FRACTION", "FUNCTION", "GROUP_BY", 
  "INTERVAL", "KWMESSAGE", "NOT_LIKE", "NOT_NULL", "PASSWORD", "PREVIOUS", 
  "READONLY", "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", "VALIDATE", 
  "WHENEVER", "WITH_LOG", "WORDWRAP", "BY_NAME", "IN_FILE", "IS_NULL", 
  "AVERAGE", "BETWEEN", "CAPTION", "CLIPPED", "CLOSE_BRACKET", "COLUMNS", 
  "COMMAND", "COMMENT", "CONNECT", "CURRENT", "DBYNAME", "DECIMAL", 
  "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", "EXECUTE", "FOREACH", 
  "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", "KWWINDOW", "MAGENTA", 
  "NUMERIC", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", "RECOVER", 
  "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", "TRAILER", 
  "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", "CLOSE_SQUARE", 
  "KW_FALSE", "NOT_IN", "ON_KEY", "OPEN_BRACKET", "BORDER", "BOTTOM", 
  "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", "DOUBLE", 
  "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", "FORMAT", 
  "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", "MINUTE", 
  "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", 
  "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "RETURN", "REVOKE", 
  "SCHEMA", "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", "SHARED", 
  "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", "AFTER", 
  "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", "ASCII", 
  "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", "COUNT", 
  "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", "FOUND", 
  "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", "MONEY", 
  "MONTH", "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", "PRINT_FILE", 
  "PRINT", "RIGHT", "SEMICOLON", "SLEEP", "SPACE", "TUPLE", "UNION", 
  "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", 
  "FCALL", "CASE", "CHAR", "CYAN", "DATE", "DESC", "DOWN", "TAB", "DROP", 
  "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", "HELP_FILE", 
  "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", "LEFT", "LIKE", 
  "MAIN", "MENU", "MODE", "MOVE", "NEED", "NEXT", "NOCR", "OPEN", "QUIT", 
  "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", "TEMP", 
  "TEXT", "THEN", "USER", "VIEW", "WAIT", "WHEN", "WITH", "WORK", "YEAR", 
  "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", 
  "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", 
  "XMIN", "NOT", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", 
  "USE", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", "BY", 
  "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "UP", "FONT_NAME", 
  "FONT_SIZE", "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", 
  "PAPER_SIZE_IS_A4", "FORMHANDLER", "END_FORMHANDLER", "BEFORE_EVENT", 
  "BEFORE_OPEN_FORM", "AFTER_EVENT", "BEFORE_CLOSE_FORM", "BEFORE_ANY", 
  "AFTER_ANY", "MENUHANDLER", "END_MENUHANDLER", "BEFORE_SHOW_MENU", 
  "DISABLE_PROGRAM", "DISABLE_ALL", "BUTTONS", "CHECK_MENUITEM", 
  "DISABLE_FORM", "DISABLE_MENUITEMS", "DISABLE", "ENABLE_FORM", 
  "ENABLE_MENUITEMS", "ENABLE", "KWFIELD", "ICON", "MESSAGEBOX", 
  "TO_DEFAULTS", "UNCHECK_MENUITEM", "BEFORE", "INPUT", "END", 
  "INT_TO_ID", "'@'", "pause_screen_cmd", "start_rpc_cmd", "stop_rpc_cmd", 
  "valid_port", "remote_func_list", "remote_func", "arr_expr", "arr_next", 
  "arr_int_sign", "opt_attributes", "attributes_def", "@1", "attribs_sec", 
  "attribute", "win_attributes", "win_attributes_def", "@2", 
  "wattribs_sec", "wattribute", "call_cmd", "call_ext", "@3", "@4", "@5", 
  "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "opt_return", 
  "opt_return_remote", "opt_func_call_args", "func_call_args", "func_arg", 
  "remote_host_name", "remote_func_name", "case_cmd", "@14", "@15", 
  "when_unit", "when_unit_expr", "end_case_command", 
  "op_otherwise_command", "@16", "op_otherwise_command_expr", "@17", 
  "when_command", "@18", "when_command_expr", "@19", "close_cmd", 
  "code_cmd", "emb_code", "sql_code", "sql_code_part", "c_code", 
  "c_code_part", "comment_cmd", "construct_cmd", "@20", "@21", 
  "constr_rest", "end_constr", "constr_col_list", "constr_col", 
  "constr_extra_commands", "constr_extra_command", "@22", "@23", "@24", 
  "@25", "@26", "bef_c_field_list", "aft_c_field_list", "interval_expr", 
  "defer_cmd", "define_section", "define_multiple", "define_set", "@27", 
  "def_part", "define_ident", "@28", "def_part2", "@29", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "array_variable", "@30", 
  "@31", "assoc_open_bracket", "assoc_close_bracket", "number_arr_assoc", 
  "number_arr_list", "number_value_arr", "record_variable", "@32", "@33", 
  "@34", "link_to_pk_list", "link_to_pk", "dtype_ident", "dtype2", "@35", 
  "dtype", "like_var", "tab_name", "col_name", "datetime_qual", 
  "interval_qual", "dtime_start", "@36", "dtime_val", "dtime_end", "@37", 
  "opt_frac", "opt_unit_size", "dtfrac", "int_start", "@38", 
  "int_start_unit", "int_end", "op_equal", "dim_section", "@39", 
  "dim_dtype", "dim_like_var", "dim_array_variable", "@40", "@41", 
  "dim_record_variable", "@42", "@43", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_cmd", "@44", 
  "@45", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@46", "@47", "@48", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "report_only_expr", 
  "@49", "and_or_expr", "inexpr_list", "in_expr", "null_expr", 
  "string_match_expr", "clip_expr", "using_expr", "math_expr", 
  "comparison_expr", "reset_cnt", "function_call_expr2", "@50", "@51", 
  "@52", "@53", "function_callb", "@54", "@55", "@56", "@57", "@58", 
  "@59", "@60", "@61", "function_call_expr", "builtin_expr", 
  "builtin_funcs", "pdf_expr", "for_cmd", "@62", "@63", "for_step", 
  "foreach_cmd", "@64", "@65", "@66", "formhandler_def", "@67", "@68", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@69", 
  "@70", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@71", "@72", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@73", "@74", "@75", 
  "@76", "@77", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "setident", "unsetident", "field_name2", "cvariable", 
  "real_number", "reserved_word", "goto_cmd", "check_menu_cmd", 
  "menu_item_list", "menu_item", "uncheck_menu_cmd", "disable_cmd", 
  "enable_cmd", "msg_box_cmd", "@78", "op_disable_msg", 
  "op_returning_msg", "op_caption", "op_icon", "op_buttons", "op_def_but", 
  "if_cmd", "@79", "op_else", "@80", "import_m", "init_cmd", "@81", 
  "init_tab_list", "init_tab", "end_input", "opt_defs", "field_commands", 
  "field_command", "@82", "@83", "@84", "@85", "@86", "@87", "@88", "@89", 
  "@90", "a_ins_or_delete_row", "a_ins_or_delete", "b_ins_or_delete_row", 
  "b_ins_or_delete", "bef_field_list", "aft_field_list", "next_field_cmd", 
  "next_form_cmd", "next_field", "input_cmd", "@91", "inp_rest", "@92", 
  "scroll_cmd", "up_or_down", "op_help", "on_key_command", "@93", 
  "key_val", "@94", "accept_key", "single_key_val", "@95", "key_do", 
  "key_value_list", "key_value", "@96", "key_value_1", "label_cmd", 
  "let_cmd", "@97", "@98", "op_expr_null", "linked_cmd", "linked_del_cmd", 
  "linked_upd_cmd", "locate_cmd", "module", "@99", "@100", 
  "func_main_def", "func_or_main2", "at_term_cmd", "func_or_main", 
  "op_code", "ldeffunction", "func_def", "@101", "@102", "@103", "@104", 
  "end_func_command", "main_def", "@105", "@106", "return_cmd", 
  "op_fgl_expr_list", "db_section", "globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@107", 
  "glob_section", "mem_func_def", "@108", "@109", "@110", "menu_cmd", 
  "@111", "end_menu_command", "menu_block_command", "@112", "@113", 
  "@114", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@115", "@116", "menu_handler_elements", 
  "menu_handler_element", "@117", "@118", "message_cmd", "@119", 
  "msg_start", "@120", "msg_end", "op_msg_wait", "variable", "var_int", 
  "var", "assoc_var_read", "assoc_var_write", "assoc_sub", "dot_part_var", 
  "array_r_variable", "arr_subscripts", "num_list", "num_list_element", 
  "let_variable", "let_var", "let_var_dot", "let_array_r_variable", 
  "op_param_var_list", "fparam_var_list", "ibind_var_list", 
  "func_def_var", "ibind_var", "obind_var_list", "obind_var", 
  "obind_var_let_list", "obind_let_var", "use_arr_var", 
  "obind_var_list_ord", "obind_var_ord", "optional_asc_desc", 
  "array_r_varid", "init_bind_var_list", "init_bind_var", 
  "open_window_cmd", "op_at_statusbox", "op_size_statusbox", 
  "open_statusbox_cmd", "formhandler_name", "open_form_cmd", 
  "open_form_rest", "open_form_gui", "op_at_gui", "op_like_gui", 
  "op_absolute", "open_session_cmd", "open_cursor_cmd", "user_details", 
  "op_disable", "connect_cmd", "op_connect_as", "con_user_details", 
  "options_cmd", "opt_options", "opt_allopts", "prepare_cmd", 
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@121", 
  "gui_prompt_cmd", "opt_char", "prompt_key_sec", "prompt_key_clause", 
  "on_key_command_prompt", "@122", "prompt_title", "put_cmd", "@123", 
  "put_from", "put_val_list", "put_val", "start_cmd", "rout", "rep_name", 
  "op_values", "output_cmd", "@124", "@125", "@126", "finish_cmd", 
  "report_section", "format_section", "format_actions", "format_action", 
  "@127", "@128", "@129", "@130", "@131", "@132", "@133", "report_cmd", 
  "need_command", "@134", "op_lines", "skip_command", "@135", 
  "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@136", "@137", "@138", "@139", "@140", 
  "rep_where", "pause_command", "pause_msg", "pdf_report_def", "@142", 
  "@143", "@144", "@145", "@146", "pdf_report_section", "pdf_functions", 
  "@147", "@148", "@149", "op_wordwrap", "run_cmd", "drops_cmd", 
  "drops_c", "create_cmd", "create_c_1", "@150", "@151", "@152", "@153", 
  "op_no_log", "idx_column_list", "idx_column", "table_element_list", 
  "table_element", "upd_stats_cmd", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "update_statement", "where_upd", 
  "set_clause_list", "special_upd_clause", "upd_columns", 
  "upd_column_name", "col_1", "upd_col_list", "upd_val_list", "upd_val", 
  "rollback_statement", "insert_statement", "@154", "ins_2", "@155", 
  "op_insert_column_list", "insert_column_list", "insert_value_list", 
  "insert_value", "fetch_statement", "@156", "@157", "fetch_part", 
  "opt_into_fetch_part", "@158", "opt_foreach_into_fetch_part", "@159", 
  "fetch_place", "delete_statement_position", "delete_statement_search", 
  "order_by_clause", "sort_specification_list", "sort_specification", 
  "sort_spec", "op_asc_desc", "begin_statement", "commit_statement", 
  "op_exclusive", "set_database_cmd", "sql_cmd", "@160", "sql_commands", 
  "privilege_definition", "op_with_grant_option", "privileges", 
  "action_list", "action", "op_grant_column_list", "grant_column_list", 
  "grantee_list", "grantee", "view_definition", "op_view_column_list", 
  "view_column_list", "op_with_check_option", 
  "check_constraint_definition", "referential_constraint_definition", 
  "references_specification", "references_columns", 
  "referenced_table_and_columns", "references_column_list", 
  "unique_constraint_definition", "unique_column_list", 
  "table_constraint_definition", "default_clause", "column_definiton", 
  "op_default_clause", "op_column_constraint_list", "column_constraint", 
  "schema", "schema_authorization_clause", 
  "schema_authorization_identifier", "schema_element_list", 
  "schema_element", "having_clause", "group_by_clause", 
  "column_specification_list", "where_clause", "from_clause", 
  "table_reference_list", "table_reference", "tname", "tname_list", 
  "table_expression", "op_where_clause", "op_group_by_clause", 
  "op_having_clause", "search_condition", "boolean_term", 
  "boolean_factor", "boolean_primary", "exists_predicate", 
  "quantified_predicate", "quantifier", "all", "some", "op_escape", 
  "pattern", "escape_character", "in_predicate", "in_value_list", 
  "op_not", "comparison_predicate", "comp_op", "predicate", "op_all", 
  "data_type", "char_string_type", "exact_numeric_type", "op_scale", 
  "approx_numeric_type", "length", "precision", "scale", "table_name", 
  "db_name", "authorization_identifier", "table_identifier", "col_arr", 
  "column_name", "correlation_name", "literal", "curr_v_clause", 
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", 
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@161", 
  "@162", "@163", "@164", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all", "cursor_specification_sel", 
  "select_statement_full", "select_statement", "@165", "@166", 
  "in_select_statement", "select_statement2", "select_statement2_1", 
  "sel_p2", "tmp_tabname", "opt_into_sel", "query_specification", 
  "subquery", "op_ad", "select_list", "value_expression_pls", 
  "column_specification", "value_expression", "value_expr_list", 
  "value_specification", "unload_cmd", "load_cmd", "opt_delim", 
  "char_or_var", "opt_col_list", "col_list", "simple_column_name", 
  "ufile", "opt_use", "conn_id", "misc_sql", "rename_stmt", "rentabname", 
  "rencolname", "unlock_stmt", "lock_stmt", "share_or_exclusive", 
  "units_qual", "op_template", "template_m", "template_list", 
  "template_item", "template_single_value", "template_value", "var_ident", 
  "var2", "var3", "aft_dot", "var_ident_ibind", "whenever_cmd", "when_do", 
  "label_goto", "function_name_when", "while_cmd", "@167", "@168", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "fld_list", 
  "current_win_cmd", "window_type", "show_cmd", "op_mnfile", "menu_name", 
  "menu_handler", "hide_cmd", "move_cmd", "NAMED", "commands", 
  "all_commands", "command1", "commands_all", "commands_all1", NULL
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,   627,   627,   628,   629,   630,   630,   631,   631,   632,
     633,   633,   633,   633,   633,   634,   634,   634,   634,   634,
     635,   635,   636,   636,   638,   637,   637,   639,   639,   640,
     640,   640,   640,   640,   640,   640,   640,   640,   640,   640,
     640,   640,   640,   640,   640,   641,   641,   643,   642,   644,
     644,   645,   645,   645,   645,   645,   645,   645,   645,   645,
     646,   647,   648,   647,   647,   647,   647,   647,   649,   650,
     651,   647,   652,   653,   647,   654,   655,   647,   656,   657,
     658,   647,   659,   659,   660,   660,   660,   661,   661,   662,
     662,  1393,  1393,   663,   664,   664,   665,   667,   666,   668,
     666,   669,   669,   670,   670,   671,   672,   673,   672,   674,
     675,   674,   677,   676,   679,   678,   680,   680,   680,   680,
     680,   680,   681,   682,   682,   683,   683,   684,   685,   685,
     686,   687,   689,   690,   688,   691,   691,   692,   692,   693,
     693,   694,   694,   694,   695,   695,   697,   696,   698,   696,
     699,   696,   700,   696,   701,   696,   702,   702,   703,   703,
     704,   704,   704,   704,   704,   704,   705,   705,   706,   706,
     707,   707,   709,   708,   708,   708,   710,   710,   712,   711,
     713,   713,   713,   713,   714,   713,   715,   715,   715,   715,
     716,   717,   717,   718,   718,   720,   719,   721,   719,   722,
     722,   723,   723,   724,   725,   725,   725,   726,   728,   727,
     729,   727,   730,   727,   731,   731,   732,   733,   735,   734,
     736,   736,   736,   736,   736,   736,   736,   736,   736,   736,
     736,   736,   736,   736,   736,   736,   736,   736,   736,   736,
     736,   736,   736,   736,   736,   736,   736,   737,   738,   739,
     740,   740,   741,   743,   742,   744,   744,   744,   744,   744,
     744,   744,   746,   745,   747,   747,   748,   748,   749,   751,
     750,   752,   752,   752,   752,   752,   752,   752,   753,   754,
     754,   756,   755,   757,   757,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   758,   760,   759,   761,
     759,   763,   762,   764,   762,   765,   765,   766,   767,   767,
     768,   769,   769,   769,   769,   769,   769,   769,   769,   770,
     770,   770,   771,   772,   770,   773,   774,   774,   775,   775,
     777,   776,   778,   776,   779,   776,   780,   780,   781,   781,
     781,   781,   781,   781,   781,   781,   781,   782,   782,   782,
     782,   782,   782,   782,   782,   783,   783,   784,   784,   784,
     784,   784,   784,   784,   784,   784,   784,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   786,   786,   787,
     787,   788,   788,   789,   789,  1394,  1394,  1395,  1395,   790,
     790,   791,  1396,  1396,   792,   792,   793,   793,   793,   793,
     793,   793,   793,   794,   794,   795,   795,   795,   795,   795,
     795,   795,   796,   796,   796,   797,   796,   798,   798,   799,
     799,   800,   800,   800,   800,   801,   801,   802,   802,   802,
     802,   803,   804,   805,   805,   805,   805,   805,   805,   806,
     806,   806,   806,   806,   806,   806,   807,   809,   810,   808,
     811,   812,   808,   814,   815,   813,   816,   817,   813,   818,
     819,   813,   820,   821,   813,   822,   822,   822,   822,   822,
     822,   822,   822,   823,   823,   824,   824,   824,   824,   825,
     825,   825,   827,   828,   826,   829,   829,   831,   832,   833,
     830,   835,   836,   834,   837,   837,   838,   838,   839,   839,
     841,   840,   842,   840,   843,   843,   844,   844,   846,   845,
     847,   845,   848,   849,   849,   849,   850,   850,   851,   851,
     852,   852,   853,   853,   855,   854,   856,   854,   857,   854,
     858,   854,   859,   854,   860,   861,   861,   861,   861,   861,
     861,   862,   862,   863,   864,   865,   866,   866,   866,   866,
     866,   866,   866,   866,   867,  1397,   868,   869,   870,   871,
     872,   873,   873,   874,   874,   875,   876,   876,   877,   877,
     878,   879,   880,   880,   880,   880,   880,   880,   881,   882,
     882,   883,   883,   883,   883,   883,   883,   883,   883,   883,
     883,   883,   883,   883,   883,   883,   883,   883,   883,   883,
     883,   883,   883,   883,   883,   883,   883,   883,   883,   883,
     883,   883,   883,   883,   883,   883,   883,   883,   883,   883,
     883,   883,   883,   883,   883,   884,   885,   886,   886,   887,
     888,   889,   889,   889,   890,   890,   890,   892,   891,   893,
     893,   893,   894,   894,   895,   895,   896,   896,   897,   897,
     898,   898,   900,   899,   901,   902,   901,   903,   905,   904,
     904,   906,   906,   907,   907,   908,   908,   909,   909,   910,
     910,   912,   911,   913,   911,   914,   911,   915,   911,   916,
     911,   917,   911,   918,   911,   919,   911,   920,   911,   921,
     921,   922,   922,   923,   923,   924,   924,   925,   925,   926,
     926,   927,   928,   929,   929,   929,   931,   930,   932,   932,
     933,   932,   934,   935,   935,   935,   935,   936,   936,   938,
     937,   937,   940,   939,   941,   943,   942,   944,   944,   945,
     945,   947,   946,   948,   948,   948,   948,   948,   948,   948,
     948,   948,   948,   948,   948,   948,   948,   948,   949,   949,
     951,   952,   950,   953,   953,   954,   955,   956,   957,   957,
     959,   960,   958,   961,   961,   962,   962,   963,   964,   964,
     964,   964,   964,   964,   964,   964,   964,   964,   964,   965,
     965,   965,   966,   966,   968,   969,   970,   971,   967,   972,
    1398,  1398,  1398,   974,   975,   973,   976,   977,   977,   978,
     979,   979,   980,   980,   981,   981,   981,   981,   983,   982,
     984,   984,   986,   987,   988,   985,   990,   989,   991,   993,
     992,   994,   992,   995,   992,   996,   996,   997,   997,   998,
     998,   999,   999,   999,  1000,  1001,  1002,  1003,  1003,  1003,
    1004,  1004,  1005,  1005,  1007,  1008,  1006,  1009,  1009,  1011,
    1010,  1012,  1010,  1014,  1013,  1013,  1016,  1015,  1017,  1018,
    1018,  1019,  1020,  1020,  1021,  1021,  1021,  1021,  1021,  1022,
    1023,  1024,  1024,  1025,  1025,  1026,  1399,  1399,  1027,  1027,
    1028,  1028,  1029,  1400,  1400,  1401,  1030,  1031,  1031,  1031,
    1031,  1031,  1032,  1032,  1033,  1034,  1034,  1035,  1035,  1402,
    1402,  1036,  1036,  1037,  1037,  1038,  1038,  1038,  1038,  1038,
    1039,  1039,  1040,  1041,  1041,  1042,  1043,  1044,  1044,  1045,
    1046,  1046,  1046,  1047,  1048,  1048,  1049,  1049,  1050,  1051,
    1051,  1052,  1052,  1053,  1054,  1055,  1056,  1056,  1057,  1058,
    1058,  1059,  1059,  1060,  1060,  1061,  1062,  1062,  1063,  1063,
    1063,  1063,  1064,  1064,  1064,  1065,  1066,  1066,  1067,  1067,
    1067,  1068,  1069,  1069,  1070,  1070,  1070,  1070,  1070,  1070,
    1070,  1070,  1070,  1070,  1070,  1070,  1070,  1070,  1070,  1070,
    1070,  1070,  1070,  1070,  1070,  1070,  1071,  1072,  1072,  1073,
    1073,  1074,  1076,  1075,  1077,  1078,  1078,  1079,  1079,  1080,
    1080,  1082,  1081,  1083,  1085,  1084,  1086,  1086,  1087,  1087,
    1088,  1088,  1089,  1089,  1089,  1089,  1403,  1090,  1090,  1091,
    1092,  1092,  1094,  1095,  1096,  1093,  1097,  1098,  1099,  1099,
    1100,  1100,  1102,  1101,  1103,  1101,  1104,  1101,  1105,  1101,
    1106,  1101,  1107,  1101,  1108,  1101,  1109,  1109,  1109,  1109,
    1109,  1109,  1111,  1110,  1112,  1112,  1114,  1113,  1113,  1113,
    1113,  1113,  1115,  1115,  1116,  1116,  1117,  1118,  1118,  1119,
    1120,  1121,  1122,  1122,  1122,  1123,  1123,  1123,  1123,  1124,
    1125,  1125,  1126,  1126,  1127,  1128,  1128,  1128,  1128,  1128,
    1128,  1128,  1129,  1129,  1130,  1130,  1131,  1131,  1131,  1131,
    1131,  1131,  1131,  1131,  1131,  1131,  1132,  1132,  1133,  1133,
    1133,  1133,  1134,  1134,  1135,  1135,  1136,  1136,  1136,  1136,
    1136,  1136,  1136,  1136,  1136,  1136,  1136,  1136,  1136,  1136,
    1136,  1136,  1136,  1136,  1136,  1137,  1137,  1137,  1139,  1140,
    1141,  1142,  1143,  1138,  1144,  1144,  1404,  1405,  1404,  1145,
    1146,  1146,  1148,  1149,  1150,  1151,  1152,  1147,  1153,  1155,
    1156,  1157,  1154,  1158,  1158,  1158,  1158,  1159,  1159,  1159,
    1159,  1159,  1160,  1161,  1161,  1161,  1406,  1162,  1163,  1164,
    1165,  1163,  1166,  1167,  1163,  1168,  1168,  1169,  1169,  1170,
    1170,  1170,  1407,  1171,  1171,  1172,  1172,  1173,  1173,  1174,
    1174,  1174,  1174,  1174,  1174,  1174,  1174,  1174,  1174,  1174,
    1175,  1175,  1176,  1176,  1177,  1178,  1179,  1179,  1179,  1180,
    1180,  1180,  1181,  1181,  1182,  1182,  1183,  1184,  1185,  1185,
    1186,  1186,  1187,  1187,  1187,  1188,  1190,  1189,  1192,  1191,
    1191,  1193,  1193,  1408,  1408,  1194,  1194,  1195,  1195,  1196,
    1196,  1198,  1199,  1197,  1200,  1200,  1201,  1202,  1201,  1203,
    1204,  1203,  1205,  1205,  1205,  1205,  1205,  1205,  1205,  1409,
    1409,  1206,  1207,  1410,  1410,  1411,  1411,  1412,  1412,  1208,
    1209,  1209,  1210,  1211,  1211,  1212,  1212,  1212,  1213,  1214,
    1215,  1215,  1216,  1218,  1217,  1219,  1219,  1219,  1219,  1219,
    1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1220,  1221,
    1221,  1222,  1222,  1223,  1223,  1224,  1224,  1224,  1224,  1225,
    1225,  1226,  1226,  1227,  1227,  1228,  1228,  1229,  1230,  1230,
    1231,  1231,  1232,  1232,  1233,  1234,  1235,  1236,  1237,  1237,
    1238,  1238,  1239,  1239,  1240,  1240,  1241,  1241,  1241,  1242,
    1242,  1243,  1244,  1244,  1245,  1245,  1246,  1246,  1246,  1246,
    1247,  1248,  1249,  1250,  1250,  1251,  1251,  1413,  1252,  1253,
    1254,  1254,  1255,  1256,  1257,  1257,  1258,  1258,  1258,  1259,
    1259,  1260,  1260,  1261,  1262,  1262,  1263,  1263,  1264,  1264,
    1265,  1265,  1266,  1266,  1267,  1267,  1268,  1268,  1269,  1269,
    1270,  1270,  1271,  1271,  1271,  1272,  1273,  1273,  1274,  1275,
    1276,  1277,  1277,  1277,  1277,  1278,  1278,  1279,  1279,  1280,
    1280,  1280,  1280,  1280,  1280,  1281,  1281,  1281,  1281,  1281,
    1281,  1281,  1281,  1281,  1281,  1282,  1282,  1282,  1282,  1283,
    1283,  1283,  1283,  1414,  1415,  1416,  1416,  1284,  1284,  1284,
    1285,  1285,  1286,  1286,  1286,  1286,  1286,  1286,  1286,  1286,
    1286,  1286,  1286,  1286,  1286,  1286,  1286,  1286,  1286,  1287,
    1287,  1288,  1288,  1288,  1288,  1288,  1289,  1290,  1291,  1292,
    1292,  1292,  1292,  1293,  1294,  1295,  1296,  1296,  1296,  1297,
    1297,  1297,  1298,  1299,  1299,  1299,  1299,  1299,  1299,  1299,
    1299,  1299,  1300,  1301,  1302,  1302,  1303,  1303,  1304,  1304,
    1304,  1304,  1304,  1304,  1304,  1305,  1305,  1305,  1305,  1305,
    1305,  1305,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1307,
    1307,  1307,  1307,  1307,  1307,  1307,  1308,  1308,  1309,  1311,
    1310,  1312,  1310,  1313,  1310,  1314,  1310,  1315,  1315,  1315,
    1316,  1316,  1317,  1317,  1317,  1318,  1318,  1319,  1319,  1320,
    1322,  1323,  1321,  1324,  1325,  1325,  1326,  1327,  1327,  1327,
    1327,  1328,  1417,  1417,  1329,  1329,  1418,  1418,  1330,  1331,
    1332,  1332,  1332,  1332,  1333,  1333,  1334,  1334,  1335,  1336,
    1336,  1336,  1336,  1336,  1336,  1336,  1336,  1336,  1336,  1336,
    1336,  1336,  1336,  1336,  1336,  1336,  1336,  1336,  1336,  1337,
    1337,  1338,  1338,  1339,  1340,  1341,  1341,  1342,  1342,  1343,
    1343,  1344,  1344,  1345,  1346,  1346,  1347,  1347,  1348,  1419,
    1420,  1420,  1421,  1422,  1349,  1349,  1349,  1350,  1350,  1351,
    1352,  1353,  1354,  1355,  1355,  1356,  1356,  1356,  1356,  1356,
    1356,  1357,  1357,  1358,  1359,  1359,  1360,  1360,  1360,  1361,
    1361,  1361,  1361,  1361,  1362,  1362,  1362,  1362,  1362,  1362,
    1362,  1362,  1362,  1362,  1363,  1364,  1364,  1365,  1365,  1365,
    1365,  1366,  1366,  1366,  1367,  1367,  1368,  1368,  1368,  1368,
    1368,  1368,  1368,  1368,  1368,  1369,  1369,  1369,  1369,  1369,
    1370,  1370,  1371,  1373,  1374,  1372,  1375,  1375,  1376,  1376,
    1377,  1377,  1377,  1377,  1377,  1377,  1378,  1378,  1379,  1379,
    1380,  1380,  1381,  1381,  1382,  1382,  1383,  1384,  1385,  1386,
    1386,  1387,  1388,  1388,  1389,  1389,  1390,  1390,  1391,  1392,
    1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1392,  1392,  1392,  1392
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     1,     5,     1,     1,     1,     1,     3,     1,
       3,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     0,     1,     0,     5,     6,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     5,     1,
       3,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     0,     7,     4,     6,     1,     6,     0,     0,
       0,     8,     0,     0,    10,     0,     0,     7,     0,     0,
       0,    14,     0,     2,     0,     2,     1,     0,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     0,     6,     0,
       5,     1,     2,     1,     2,     1,     0,     0,     3,     0,
       0,     3,     0,     4,     0,     4,     2,     2,     2,     1,
       2,     2,     3,     1,     1,     1,     2,     1,     1,     2,
       1,     1,     0,     0,     5,     7,     8,     0,     2,     1,
       3,     1,     3,     3,     1,     2,     0,     4,     0,     4,
       0,     3,     0,     3,     0,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     0,     3,     1,     1,     1,     3,     0,     2,
       4,     4,     4,     2,     0,     4,     1,     1,     1,     2,
       1,     1,     3,     0,     1,     0,     7,     0,    12,     1,
       1,     1,     1,     1,     5,     3,     1,     1,     0,     4,
       0,     5,     0,     7,     1,     3,     1,     1,     0,     2,
       1,     1,     1,     4,     4,     6,     1,     2,     1,     1,
       1,     1,     4,     6,     1,     4,     6,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     4,     1,     1,
       0,     3,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     0,     2,     0,     3,     0,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       1,     0,     5,     1,     1,     1,     4,     4,     6,     1,
       1,     1,     1,     4,     6,     1,     4,     6,     1,     1,
       1,     1,     1,     2,     2,     1,     4,     0,     7,     0,
      12,     0,     4,     0,     5,     1,     3,     2,     1,     3,
       1,     0,     2,     2,     1,     2,     5,     4,     2,     4,
       5,     3,     0,     0,    10,     1,     0,     2,     1,     2,
       0,     3,     0,     3,     0,     3,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     3,     1,     3,     0,     1,     1,     3,     1,
       3,     1,     0,     1,     1,     1,     2,     1,     1,     3,
       4,     4,     4,     2,     2,     2,     2,     1,     1,     1,
       3,     1,     2,     2,     1,     0,     3,     2,     2,     1,
       3,     4,     4,     5,     5,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     0,
       0,     6,     0,     0,     6,     1,     4,     4,     4,     4,
       4,     1,     1,     1,     1,     4,     4,     4,     4,     2,
       2,     2,     0,     0,    12,     0,     2,     0,     0,     0,
       8,     0,     0,    10,     0,     1,     0,     1,     1,     2,
       0,     3,     0,     3,     0,     1,     1,     2,     0,     3,
       0,     3,     3,     1,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     0,     3,     0,     3,     0,     4,
       0,     4,     0,     4,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     4,     6,     4,
       3,     6,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     3,     1,     3,     1,     4,     1,     1,
       0,     0,     1,     4,     3,     6,     3,     6,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     3,     1,
       2,     2,     2,     4,     2,     2,     4,     0,     8,     0,
       1,     1,     0,     2,     0,     2,     0,     2,     0,     3,
       0,     2,     0,     7,     0,     0,     3,     5,     0,     5,
       4,     1,     3,     3,     3,     0,     2,     0,     1,     1,
       2,     0,     4,     0,     4,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     4,     0,     4,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       3,     2,     4,     1,     1,     1,     0,     4,     5,     6,
       0,    10,     3,     1,     1,     2,     2,     0,     2,     0,
       3,     1,     0,     3,     2,     0,     3,     1,     3,     1,
       3,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       0,     0,     7,     1,     1,     2,     2,     2,     3,     4,
       0,     0,     9,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     2,     0,     0,     0,     0,    13,     1,
       0,     1,     3,     0,     0,     6,     3,     0,     1,     2,
       0,     1,     1,     2,     1,     1,     1,     1,     0,     3,
       2,     1,     0,     0,     0,    14,     0,     5,     1,     0,
       3,     0,     7,     0,     5,     1,     2,     0,     1,     1,
       1,     0,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     3,     1,     1,     0,     0,     7,     1,     2,     0,
       3,     0,     4,     0,     5,     7,     0,     3,     0,     0,
       1,     1,     1,     2,     4,     7,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     2,     1,     3,     3,     6,
       1,     3,     1,     1,     3,     1,     1,     1,     4,     7,
       1,     1,     1,     1,     2,     0,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     3,     2,
       0,     1,     1,     4,     1,     3,     1,     3,     7,     0,
       7,     0,     6,     3,     1,     3,     1,     2,     5,     0,
       7,     0,     2,     0,     1,     5,     2,     5,     0,     5,
       6,     4,     0,     1,     1,     4,     0,     2,     0,     5,
       4,     2,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     5,     1,     1,     2,
       4,     1,     0,    10,     5,     0,     1,     0,     2,     1,
       2,     0,     3,     1,     0,     4,     0,     2,     1,     3,
       1,     1,     3,     4,     4,     2,     1,     1,     1,     1,
       0,     1,     0,     0,     0,    10,     2,     2,     3,     2,
       1,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     4,     0,     4,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     1,     0,     4,     1,     2,
       2,     2,     0,     1,     1,     2,     3,     0,     2,     3,
       3,     5,     0,     2,     4,     1,     1,     1,     1,     1,
       0,     1,     1,     3,     2,     5,     5,     5,     5,     5,
       5,     5,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     1,     1,     1,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     0,     3,     2,     0,     0,
       0,     0,     0,    14,     0,     2,     1,     0,     4,     2,
       0,     1,     0,     0,     0,     0,     0,    14,     2,     0,
       0,     0,    10,     0,     1,     3,     3,     2,     4,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     3,     0,
       0,     7,     0,     0,     8,     0,     1,     1,     3,     2,
       2,     1,     1,     1,     3,     1,     1,     2,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     6,     6,
       0,     1,     0,     1,     2,     5,     0,     2,     2,     1,
       7,     1,     5,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     0,     5,     0,     5,
       1,     0,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     0,     0,     5,     2,     1,     0,     0,     3,     0,
       0,     3,     1,     1,     1,     1,     1,     2,     2,     1,
       3,     4,     3,     1,     4,     1,     3,     0,     1,     3,
       1,     3,     2,     1,     1,     0,     1,     1,     1,     1,
       0,     1,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     0,
       1,     1,     1,     1,     3,     1,     1,     1,     2,     0,
       3,     1,     3,     1,     3,     1,     1,     6,     0,     3,
       1,     3,     0,     1,     4,     5,     2,     1,     1,     4,
       1,     3,     4,     4,     1,     3,     1,     1,     1,     2,
       1,     4,     0,     1,     0,     2,     1,     1,     1,     4,
       3,     1,     1,     1,     2,     1,     1,     1,     2,     2,
       1,     3,     2,     2,     1,     3,     1,     2,     4,     1,
       2,     1,     3,     4,     0,     1,     0,     1,     0,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     2,     2,
       4,     3,     0,     1,     1,     1,     1,     1,     2,     1,
       1,     5,     3,     5,     3,     1,     3,     0,     1,     3,
       3,     3,     3,     6,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     1,     5,     5,     1,     1,     1,     4,
       1,     4,     1,     7,     1,     1,     1,     4,     6,     0,
       2,     4,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     0,     3,     5,     2,
       5,     4,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       8,     0,     9,     0,     7,     0,     9,     0,     1,     2,
       1,     3,     1,     3,     5,     1,     1,     1,     1,     2,
       0,     0,     8,     5,     1,     1,     7,     0,     3,     1,
       3,     1,     0,     3,     0,     2,     1,     3,     5,     7,
       0,     1,     1,     1,     1,     3,     1,     2,     1,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     5,     5,     5,     4,     6,     3,     1,
       3,     0,     1,     5,     7,     0,     2,     1,     1,     0,
       3,     1,     3,     1,     1,     1,     0,     3,     1,     4,
       1,     3,     4,     2,     1,     1,     1,     4,     6,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     1,     2,     3,     5,     3,     2,
       2,     4,     1,     1,     2,     1,     1,     3,     3,     3,
       3,     4,     4,     6,     1,     2,     1,     1,     1,     3,
       5,     1,     1,     1,     1,     3,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     1,     3,     2,     1,     2,
       1,     2,     1,     0,     0,     6,     0,     2,     0,     1,
       1,     2,     2,     2,     4,     3,     1,     3,     1,     2,
       5,     2,     2,     5,     0,     2,     1,     1,     2,     6,
       6,     1,     0,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
     789,     0,     0,     0,     0,     0,     0,     0,     0,  1699,
       0,   790,  1661,   791,   130,   127,     0,   123,   125,   124,
     128,  1705,   580,   580,  1708,     0,  1704,  1701,  1698,  1696,
    1697,  1703,  1702,  1700,   580,   810,  1662,   122,   126,   129,
     614,   597,   612,   618,   596,   610,   591,   627,   632,   594,
     628,   603,   605,   609,   620,   634,   631,   633,   621,   601,
     599,   626,   607,   606,   592,   593,   595,   598,   611,   623,
     600,   629,   613,   617,   619,   625,   608,   630,   622,   624,
     602,   604,   615,   616,  1712,     0,   574,  1709,   580,  1710,
    1707,   580,     0,     0,   580,  1664,   580,   818,   815,   817,
     789,   811,   812,   814,   816,  1741,   581,  1711,  1706,     0,
     580,     0,  1663,  1665,  1547,  1546,   809,   168,   770,   813,
     573,  1672,  1673,     0,     0,  1668,     0,     0,   580,   580,
     580,  1675,  1676,  1666,     0,   551,   580,   172,   580,     0,
     169,   170,   174,   821,   877,   552,   819,   588,   871,   872,
     878,   876,   175,   168,  1670,  1669,     0,     0,     0,  1674,
       0,     0,   580,   580,   580,   580,   281,   178,   873,   820,
     171,   580,   580,   885,     0,   789,     0,   580,   580,  1680,
       0,  1678,  1677,  1679,  1667,     0,   178,   173,   190,   580,
     176,   191,   218,   882,   881,     0,    21,    20,    12,   580,
     892,     0,    14,     0,   890,   580,   771,  1671,  1682,  1681,
       0,     0,   279,   178,   184,   179,   178,   183,   217,     0,
     879,     0,   580,   580,   580,   580,   580,    11,    13,   580,
     888,   883,   884,   874,   773,   580,   313,   299,   193,   250,
     269,   290,   292,   289,     0,   311,     0,   298,   291,   295,
     301,   285,   300,   178,   302,   282,   305,   283,   284,   280,
       0,   177,     0,   190,   192,   241,   242,   230,   210,   238,
     193,   212,   250,   269,   228,   231,   226,     0,   208,     0,
     237,   229,   234,   240,   222,   239,   178,   243,   178,   220,
     221,   219,   246,    10,    16,    15,    18,    17,    19,   891,
     580,   580,  1162,   580,   580,   792,   131,  1148,     0,   803,
     580,   580,   786,   788,   785,   787,   772,   774,   775,   794,
     778,   779,   780,   783,   781,   782,   784,  1683,   580,   194,
       0,   303,     0,     0,   304,     0,     0,     0,     0,   580,
       0,     0,     0,   248,     0,   589,   180,   182,     0,   181,
       0,   187,   186,   185,   188,   178,     0,   178,   244,   245,
       0,     0,   178,     0,     0,     0,     0,   227,     0,     0,
     580,     0,     0,   580,   793,   168,   501,   854,   776,   580,
       0,   199,   200,     0,   262,   264,   259,   260,   256,   258,
     255,   257,   254,     0,   264,   275,   276,   272,   274,   271,
     273,   266,     0,     0,     0,   315,     0,   318,   320,   207,
       0,   206,     0,     0,   178,   590,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   178,   889,   875,     0,
       0,   580,     0,   804,   168,   168,     0,     0,     0,   251,
       0,     0,   261,   278,   252,   277,     0,   270,     0,   293,
       0,   287,   580,   312,   580,   317,   307,     0,     0,   296,
     286,   249,   306,     0,     0,     0,     0,   232,     0,   224,
     209,   195,     0,   235,   223,   247,  1163,     0,     0,  1149,
    1636,   502,   855,   795,   314,   201,   202,     0,   263,   268,
       0,     0,     0,     0,   316,   319,     0,   205,     0,   211,
       0,   178,     0,     0,     0,     0,   580,   667,   822,   580,
     580,   580,   580,   580,   580,  1728,   580,  1215,  1214,   580,
    1216,   580,   361,  1213,  1192,   580,     4,  1212,   362,   359,
     580,   364,   166,   456,  1068,     0,     0,  1222,   119,   358,
     357,  1183,   352,   580,  1208,  1720,   580,   363,   332,   580,
       2,     1,   580,   360,  1189,   580,   580,   353,   350,   365,
     580,   580,   580,   580,   580,  1210,   356,   580,   580,   580,
     580,   580,   580,   580,   580,  1209,   580,   580,   580,   167,
    1185,   349,   348,   580,   580,  1718,   580,   580,   132,  1184,
     355,   354,   580,   580,   351,   866,   456,   580,   497,     0,
     580,   580,   456,   580,   580,   580,   456,   580,  1160,   580,
     580,  1072,   580,  1713,   580,    99,   580,   580,   826,   580,
     580,   580,   580,   760,   580,   580,   580,     0,   580,   580,
     580,   580,   580,   580,   580,   647,   580,   580,  1749,  1750,
    1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,
    1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,
    1791,    22,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,
    1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,  1059,  1061,
    1056,  1058,  1057,  1060,  1808,  1809,  1182,  1810,  1187,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1303,  1820,
    1821,  1822,  1823,  1824,  1825,  1826,     0,  1746,  1743,  1744,
    1748,   789,     0,   580,     0,   265,   267,   294,   288,     0,
       0,   297,     0,   216,     0,   214,   233,   225,   218,   236,
     913,     0,   906,   907,   580,     0,   777,  1722,   567,     0,
     118,     0,   580,  1688,  1687,   966,  1684,  1686,  1736,     0,
    1201,     0,  1197,  1207,     6,     0,     5,   580,  1729,  1029,
    1030,   580,  1123,  1122,  1071,  1121,  1070,   580,   580,   417,
     419,     0,     0,     0,     0,     0,     0,   618,     0,   580,
    1516,     0,     0,   634,   408,   580,   580,   621,   407,   580,
     598,   425,   623,   484,   622,     0,   624,     0,     0,   580,
       0,   401,  1223,     0,   368,   367,   374,   369,   482,   475,
     370,   372,   481,   373,   877,   418,   421,   424,  1211,   483,
    1638,  1217,   120,   580,  1036,   117,   580,   766,    22,   569,
     366,     0,   765,  1025,   767,     0,  1221,   848,   847,   850,
     846,   849,  1738,     0,   844,     0,   568,   939,   845,  1732,
       0,  1721,   116,   936,   668,   934,     0,   564,  1719,  1716,
    1723,   714,   713,     0,   715,   556,   711,     0,   580,   949,
     570,  1300,   580,   580,  1001,   999,   580,   993,   995,   994,
     992,   991,   580,   580,   580,   990,   580,   741,   580,   580,
       0,     0,     0,     0,   580,   580,     0,     0,     0,   980,
     971,   972,     0,  1013,   399,    22,   387,  1726,     0,  1718,
     121,   566,   580,   758,   998,   997,  1161,  1159,  1089,     0,
    1627,  1628,  1090,  1173,  1090,  1073,  1074,  1077,  1092,  1224,
     580,     0,     0,     0,     0,     0,   580,     0,   580,     0,
      60,     0,     0,    66,     0,    97,   544,   635,   580,  1062,
     956,  1066,     0,   580,  1014,  1177,     0,  1069,   639,   636,
     637,     0,   641,   642,     0,   644,   645,   580,   640,   917,
     919,   580,   580,   918,   716,   915,   677,   911,     0,   580,
       0,   869,    23,   656,   580,   580,   580,   580,   580,     0,
     805,  1747,  1745,   506,   580,   859,     0,   857,     0,     0,
     308,   204,     0,   178,   213,   196,   580,  1164,   580,     0,
    1150,     0,   581,   576,   580,  1685,   580,   580,   968,   580,
     580,  1200,  1199,   580,  1188,     0,  1489,  1495,     0,     0,
    1490,  1031,     0,    22,  1118,  1120,  1119,   375,   580,   376,
     460,   580,   580,   580,   580,     0,   580,   580,   423,  1524,
    1522,  1523,  1519,  1521,  1518,  1520,  1512,     0,   580,     0,
     580,     0,   422,     0,   415,   580,   416,     0,     0,   466,
     463,   472,   580,   469,   580,   580,   406,   580,   580,   580,
     580,   580,   580,   580,   580,   580,   580,   580,   580,   580,
     580,   580,   580,   580,   160,   161,   162,   163,   164,   165,
     489,   490,   491,   436,   580,   580,   435,   441,     0,   580,
     380,   580,     0,   381,   371,   377,   379,   382,   383,   384,
     385,   386,   378,   414,   413,   457,   580,   926,     0,     0,
     335,   331,   580,   580,  1022,   580,   580,   580,   580,   580,
     580,     0,   943,  1637,   580,   580,   178,     0,   580,   580,
    1718,   580,   580,   580,   580,   580,   133,     0,   580,   953,
     945,   946,   951,  1301,  1302,   867,   321,   393,   580,   498,
     549,   548,   546,   974,   550,   979,   975,   978,   734,     0,
     976,   977,   735,   984,   988,   981,   982,   986,   987,   985,
     983,   989,     0,   768,   580,   580,     0,   390,   806,   391,
     388,   389,   580,     0,     0,   724,   723,   722,  1725,    22,
     759,  1085,  1086,  1087,  1088,  1082,  1091,  1080,  1174,  1094,
    1079,  1075,   580,     0,  1090,  1714,    75,   580,     0,   580,
     580,    94,     0,    95,   580,     0,   580,    68,   580,   106,
     101,     0,   853,     0,   852,     0,   456,  1064,   580,   900,
     901,   925,   896,   897,   761,   923,  1016,  1179,   580,  1181,
    1180,   662,   580,   580,   580,   654,   677,   677,   675,   580,
     580,   678,     0,    24,   655,     0,   870,   863,     0,   658,
    1634,  1635,  1625,  1625,     0,     0,  1548,   580,   178,  1245,
     580,   580,  1246,  1298,   178,   580,  1299,   580,  1590,   580,
    1261,     0,  1317,  1315,  1314,  1313,  1311,  1312,  1309,  1307,
    1310,  1304,  1376,  1375,  1305,  1306,  1316,  1557,  1308,  1646,
    1645,  1644,   510,   512,   504,   507,   508,   861,  1636,   856,
     858,   796,   203,     0,     0,   215,   914,   168,   908,   823,
     168,   580,   575,     0,     0,   967,   580,     0,   965,  1691,
    1693,  1692,  1689,  1737,  1734,  1198,   580,   580,  1193,   580,
    1032,   329,     0,    87,     0,     0,     0,     0,  1590,     0,
       0,     0,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,   426,   580,   580,   580,     0,   580,     0,     0,
       0,   428,   427,   442,   437,   448,   451,   452,   449,   455,
     454,   453,   444,   443,   446,   445,   447,   438,   440,   456,
     450,   439,   456,    87,   420,   580,  1190,   958,  1027,  1028,
    1024,  1023,     0,   851,     0,     0,   553,     0,     0,   580,
     937,   935,     0,   670,   671,     0,     0,  1717,  1724,     0,
       0,   560,     0,   562,   712,     0,   137,   580,   947,   954,
       0,   580,   962,   580,   324,   580,   580,   580,   580,    22,
    1000,  1269,     0,     0,   757,   746,   755,   756,   744,   745,
     748,   751,   747,   754,   750,   752,   753,   743,   749,   742,
     741,   973,   769,   400,   580,  1005,   580,  1727,   725,   726,
     346,   580,  1090,   580,  1093,  1078,  1076,  1636,    87,     0,
       0,     0,     0,   580,     0,   580,    61,    87,   112,   107,
       0,   102,   580,   109,   103,   829,   837,   835,     0,  1063,
     580,  1065,  1067,     0,   580,   904,     0,   580,     0,   580,
    1015,  1178,  1636,   638,   643,   646,   656,   571,     0,   580,
     580,   693,   731,   691,   687,   685,   729,     0,     0,   717,
       0,   679,   689,   916,   912,   580,     0,     0,   868,   657,
       0,   649,   580,     0,   580,   580,     0,     0,   580,  1494,
       0,  1371,  1372,  1651,  1338,  1394,   580,     0,  1649,     0,
       0,  1592,  1593,  1591,   580,     0,   580,  1321,  1327,  1326,
    1325,  1329,     0,  1322,  1323,   580,  1558,  1569,  1636,  1636,
     523,   514,   505,     0,   509,  1636,   860,   168,   309,   197,
    1124,   168,  1102,   579,     0,   578,   580,   933,     0,   580,
     580,  1733,     3,     7,     9,  1495,  1492,   580,  1491,   456,
     409,   461,    88,    89,    93,   478,   477,   480,   476,   580,
     412,   486,  1154,  1531,  1529,  1530,  1526,  1528,  1525,  1527,
    1517,   479,  1154,   485,   411,   487,   488,  1154,   467,   464,
     473,  1154,   470,  1154,  1154,  1154,   580,     0,   580,     0,
     458,     0,   580,   580,   955,   580,   580,   580,   580,   580,
       0,   580,   178,   669,   580,   557,   559,   580,   580,   154,
     152,   580,   580,   134,     0,   144,   150,   677,   139,   141,
     580,   952,   963,   964,     0,   394,   323,   328,   555,   322,
     580,   325,   330,  1270,   499,   547,   545,   741,   736,   737,
    1004,  1006,   580,   392,   347,  1083,  1081,  1175,  1176,     0,
      76,    64,  1169,     0,     0,     0,    96,     0,     0,    69,
    1636,  1636,   105,   100,   114,   110,     0,   104,  1636,   732,
     838,   571,   828,   827,   836,   957,   580,     0,   580,   924,
     456,     0,     0,  1609,  1503,  1506,  1514,  1504,  1607,   580,
    1021,  1606,   598,   629,  1608,     0,     0,     0,     0,  1688,
    1505,  1017,  1018,  1605,  1511,  1020,  1694,  1604,   664,   658,
       0,    22,   580,   707,   681,   709,   683,  1636,  1636,  1636,
    1636,   741,   702,   701,   697,   699,   706,   705,   695,   703,
     676,   680,  1636,   571,    44,    42,    39,    33,    37,    41,
      36,    29,    38,    32,    35,    30,    40,    31,    43,    34,
       0,    27,     0,   864,   660,   650,   651,   652,  1626,   580,
     580,  1623,  1574,  1575,  1567,  1553,  1568,     0,     0,   580,
     996,  1370,  1373,   580,     0,   580,   580,  1395,  1282,  1251,
    1654,  1653,  1652,   580,   580,  1570,  1594,  1596,   580,   580,
    1275,   580,  1276,  1272,  1273,  1274,  1265,  1262,   580,   580,
    1328,   580,     0,     0,  1562,  1559,  1560,   511,   513,   580,
       0,   526,   518,   520,     0,   515,   516,   580,   580,   534,
     536,   580,     0,   532,   862,   797,     0,     0,     0,  1145,
    1165,   824,     0,  1151,  1145,   577,  1690,   580,     0,  1735,
     580,     0,     0,     0,   592,  1496,     0,  1203,  1358,  1357,
    1356,  1206,  1205,   580,     0,  1033,     0,   580,     0,   580,
    1098,  1097,  1096,     0,     0,     0,  1099,     0,  1101,  1100,
    1095,   429,     0,   432,     0,   431,     0,     0,     0,   580,
       0,  1218,  1740,  1739,   554,   580,     0,    45,   580,   674,
     673,   672,  1219,   580,     0,   677,  1636,  1636,   146,   582,
     156,   148,   158,   138,   145,  1636,   580,     0,   580,     0,
     580,     0,   580,  1636,     0,   739,   571,   580,  1715,     0,
      87,   580,    62,   580,   580,    72,     0,   113,   108,  1636,
    1636,    98,   830,   741,   839,   833,   841,   840,   495,   880,
     902,   903,   898,   580,  1510,  1509,  1508,  1507,  1538,  1536,
    1537,  1533,  1535,  1532,  1534,  1513,     0,     0,  1449,     0,
    1449,  1449,  1449,  1449,   580,   580,   580,   580,   580,   580,
    1655,  1656,  1657,  1658,  1659,  1660,  1600,   580,   665,     0,
     649,   572,   718,     0,   580,  1636,   580,  1636,   694,   692,
     688,   686,   730,     0,  1636,     0,  1636,   690,    22,     0,
      25,     0,     0,   659,   580,   868,  1629,  1590,  1557,   580,
     580,  1566,  1549,  1565,  1374,     0,  1340,     0,  1281,     0,
     580,   621,   580,  1382,  1400,  1402,  1404,  1448,  1447,  1446,
    1445,  1406,     0,  1427,   580,     0,  1650,     0,  1647,   580,
    1584,  1597,     0,   580,  1226,  1229,  1231,     0,  1234,  1236,
    1278,  1277,  1266,  1264,     0,  1331,     0,  1324,   580,   580,
     580,   525,   530,   580,   580,  1636,  1636,   503,   517,   540,
     528,   542,  1636,  1636,   538,   522,   533,   789,     0,   218,
    1143,  1144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1142,     0,     0,  1135,  1136,  1134,  1125,
    1116,   580,     0,  1168,     0,   789,     0,  1111,     0,     0,
       0,     0,     0,     0,   580,  1103,  1104,     0,  1037,   970,
     580,     8,   580,   580,   580,   580,     0,  1499,   580,  1195,
       0,  1483,  1470,  1472,  1468,     0,  1467,     0,  1476,     0,
    1463,  1484,     0,  1475,  1460,  1466,  1482,  1474,  1362,  1457,
    1458,  1459,   580,   462,    90,   580,  1394,  1577,  1155,   468,
     465,   474,   471,   580,   434,   433,   459,    22,  1191,     0,
     580,  1731,     0,     0,   938,    46,     0,   561,   563,   558,
     727,   155,   153,   580,  1636,   580,   580,   580,  1636,   151,
     140,   580,   143,   142,   580,   944,   948,   327,   580,  1271,
       0,   741,   738,    22,  1084,    82,  1170,    67,   580,     0,
      65,    87,    70,   115,   111,   733,  1636,   843,   571,   842,
     580,   492,   580,   763,   764,   762,     0,  1618,     0,  1451,
    1452,  1450,   580,   580,   580,   580,   580,   580,  1619,     0,
    1019,  1603,  1602,  1599,  1601,  1695,  1636,   663,   652,     0,
     708,   682,   710,   684,   700,   698,   704,   696,   719,    28,
      26,   661,   653,   865,   580,  1624,   580,  1554,  1555,  1551,
    1557,   580,  1339,   580,  1342,     0,  1409,   580,     0,  1427,
    1408,  1405,   580,   580,  1441,  1437,  1438,  1435,  1444,  1443,
    1436,  1439,  1440,  1442,   580,     0,  1428,     0,     0,   580,
       0,  1255,  1248,  1247,  1250,   580,  1595,   580,  1571,   580,
    1238,     0,   580,   580,  1225,   580,   580,  1267,  1263,   580,
    1330,   580,     0,  1563,  1561,   580,   527,   524,   519,   521,
     580,  1636,  1636,   535,   537,  1636,  1636,   310,   198,  1137,
    1138,  1139,  1141,  1129,  1127,  1126,  1130,  1131,  1128,  1140,
    1132,  1133,  1117,   930,  1147,   927,   580,     0,  1166,  1636,
    1115,  1114,  1109,  1107,  1106,  1110,  1108,  1112,  1113,  1105,
    1152,   969,     0,  1347,  1350,     0,  1354,     0,     0,     0,
    1204,  1196,  1194,   580,     0,     0,     0,     0,     0,  1485,
       0,     0,     0,  1360,     0,  1363,  1364,   808,  1034,   580,
    1383,  1384,  1386,  1389,  1396,   580,     0,  1449,  1579,  1573,
     430,   333,     0,   580,   961,   580,    47,   941,     0,    22,
     157,   147,     0,   584,   586,   159,   149,   727,     0,   326,
     500,   740,  1002,   580,    77,     0,    63,     0,    73,    82,
     834,   831,   496,  1636,     0,  1545,  1543,  1544,  1540,  1542,
    1539,  1541,  1515,  1610,     0,   580,     0,     0,     0,     0,
     580,  1616,   666,   648,   571,  1633,     0,  1631,  1584,  1557,
    1557,  1550,  1341,  1590,  1343,  1337,  1590,  1407,  1401,  1403,
    1411,  1621,  1424,  1621,  1422,  1430,  1429,   580,  1621,   580,
    1416,  1415,  1417,     0,  1413,  1414,  1432,  1431,   580,  1252,
       0,  1648,   922,  1585,   920,     0,   580,  1243,  1233,  1240,
    1244,  1242,   580,     0,  1227,  1228,  1235,  1237,   580,  1332,
    1335,  1319,  1333,  1336,   580,   531,   529,   541,   543,   539,
       0,   932,   931,   929,   580,  1146,  1042,  1044,   580,  1048,
     580,  1046,  1050,     0,  1039,  1040,     0,     0,     0,     0,
     580,   580,  1353,  1352,  1344,     0,  1497,  1501,  1496,     0,
       0,     0,  1487,  1479,  1479,     0,     0,  1479,  1486,     0,
    1503,  1359,  1367,   580,  1366,     0,  1368,  1361,  1364,     0,
     580,  1387,   580,  1502,  1390,   580,  1397,  1398,  1581,  1195,
     580,   580,   336,   580,   959,     0,     0,     0,   940,   728,
     135,   583,    22,   950,  1007,    83,  1171,    78,     0,    71,
    1636,   493,   899,  1615,     0,  1611,  1612,  1613,  1614,  1620,
     720,   580,  1630,     0,  1556,  1552,   580,   580,     0,  1622,
    1425,     0,     0,     0,  1419,  1410,  1256,   580,   580,  1577,
       0,  1242,   580,  1239,     0,  1268,   580,  1320,  1318,  1564,
     799,   798,   928,  1636,  1636,  1052,  1636,  1054,  1636,  1636,
    1038,  1041,  1167,   825,  1153,  1345,  1351,  1355,     0,  1500,
    1469,     0,  1471,     0,     0,     0,     0,  1477,  1481,     0,
    1461,  1346,  1348,   580,  1365,  1035,  1391,     0,  1385,  1379,
    1380,  1598,   580,  1399,  1393,  1580,  1293,  1289,  1290,  1295,
    1294,  1578,   342,   340,   334,     0,   338,   344,   960,  1730,
     580,   580,   580,   580,   580,   580,    52,     0,    51,     0,
      49,   580,   580,   136,  1011,  1003,     0,  1009,    82,    87,
      82,   832,     0,  1617,    22,  1632,  1577,     0,     0,  1621,
    1423,  1421,   580,  1621,  1434,  1260,     0,  1257,  1259,   921,
    1572,  1232,  1241,   580,  1334,  1043,  1045,  1636,  1049,  1636,
    1047,  1051,  1498,     0,  1488,  1480,  1464,  1462,     0,  1465,
     580,     0,   580,  1388,   580,  1378,   580,  1297,  1296,  1292,
    1636,  1636,   337,   339,  1636,    54,    59,    56,    58,    55,
      57,    53,     0,    48,     0,   585,   587,  1636,  1008,  1010,
    1172,    79,    74,     0,   721,  1576,  1588,     0,  1426,  1433,
    1418,  1420,   580,  1249,     0,  1053,  1055,     0,  1478,     0,
    1369,  1392,  1381,  1291,   343,   341,   345,    50,   580,  1012,
       0,   494,  1589,  1258,  1230,  1473,  1349,     0,    80,   942,
      84,    86,   580,    81,    85,     0,     0,     0
};

static const short yydefgoto[] =
{
     638,   639,   640,   775,  1642,  1643,   200,   227,   201,  1150,
    1002,  1576,  1850,  2818,  2274,  2275,  2696,  2819,  2820,   641,
     960,  2308,  1527,  2026,  2539,  2311,  2708,  1518,  2019,  2829,
    2930,  2940,  2534,  2943,  1651,  1652,  1653,  1252,  1755,   642,
    1261,   964,  1259,  1533,  1763,  1530,  1761,  1766,  2030,  1260,
    1760,  1534,  2029,   643,   644,    16,    17,    18,    19,    20,
     645,   646,   888,  1466,  1176,  1713,  1717,  1718,  1714,  1715,
    2284,  2288,  2005,  1997,  1996,  1998,  2001,  1133,   647,   139,
     140,   141,   167,   187,   343,   189,   190,   262,   353,   191,
     192,   330,   289,   504,  1927,   383,   487,  1353,   410,   411,
     290,   362,   355,   357,   744,   745,   217,   218,   219,   291,
     292,  1452,   462,   331,   334,   332,   333,   392,   439,   440,
     442,   447,   490,   335,   336,   401,   444,   260,   142,   185,
     255,   256,   257,   496,  1926,   258,   339,   328,   404,   405,
     406,   407,  1479,   648,   843,  2692,  1151,  2804,  2805,  2806,
    2881,  2880,  2884,   649,   650,   651,   652,   821,  1134,  1218,
    1219,  1220,  1186,   923,  1187,   823,   824,   825,   826,   827,
    1088,  1135,  1972,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
     781,   828,  1433,  1976,  1383,  1956,   829,  1404,  1964,  1403,
    1963,  1407,  1967,  1405,  1965,   830,   831,   832,   833,   653,
    2543,  2832,  2321,   654,   896,  1481,  2013,   314,   434,   731,
    1621,  1344,  1345,  1346,  1618,  1619,  1914,  1915,  1916,  2165,
    2166,  1622,  1623,  1910,  2169,  2161,  1922,  1923,  2172,  2173,
    2435,  2431,  2432,   655,  1193,   143,  1447,  1448,  1729,   927,
     876,   930,   757,   865,   848,   889,  1811,   144,   758,  1032,
    1634,    85,   120,  2000,   145,   835,    86,   656,   657,   979,
     980,   658,   659,   660,   661,   987,  1857,  2105,  1003,  1299,
    1581,  2103,   662,  1552,  2079,  2346,   315,   663,  1167,  1453,
    1454,  1569,  1292,  1570,  1571,  2085,  2087,  1820,  1819,  1832,
    1818,  1817,  2096,  2094,  1824,  1825,  1828,  1829,  1814,  1816,
     664,   665,   886,   666,  1288,   994,  2834,   667,  1227,  2519,
    1572,  1821,  1770,  2033,   919,  1203,  1500,  1738,  2014,  1739,
    1199,  1499,   668,   669,   973,  1548,  2325,   670,   671,   672,
     673,  2945,   153,   234,   316,   317,   674,   318,    12,   319,
     320,   379,   733,  1627,  2177,  2751,   321,   375,   480,   675,
    2498,    99,   100,   101,   102,   103,   117,   146,   322,   754,
    1631,  2205,   676,   968,  1773,  1537,  1768,  2710,  2316,  1538,
    1771,  2036,  2318,   677,   678,   679,   859,   860,  1263,   323,
     435,   732,  1016,  1017,  1348,  1625,   680,  1578,   681,   892,
    1853,  1297,   836,   148,   149,   150,  1270,   195,   233,   151,
     173,   203,   204,  1271,  1272,  2042,  1273,   751,   752,   996,
     753,   997,  2603,  2604,  1274,  1275,  1148,  2454,  2455,  2633,
     764,   874,   875,   682,  1162,  2698,   683,  2296,   684,  1180,
    1181,  1182,  1472,  1470,   685,   686,  1694,  1724,   687,  1038,
    1368,   688,   920,   921,   689,   936,   690,  1864,   691,  2704,
     692,  1742,  2825,  2826,  2827,  2897,   925,   693,  1276,  1550,
    1801,  1802,   694,  1440,   780,  1052,   695,  1649,  2252,  2679,
     696,  1933,  2458,  2644,  2645,  2753,  2754,  2758,  2756,  2759,
    2857,  2859,   697,   698,  1265,  1542,   699,  1267,   944,   945,
     946,  1244,   700,   701,   702,  1512,  1235,   939,  1237,   947,
     948,   837,  1934,  2215,  2216,  2199,   784,   785,  1929,  2200,
    2203,   324,   373,   509,  1360,  2217,  2648,  1960,   703,   937,
     325,   370,   506,  1357,  2204,  2646,  1930,   963,  2020,  2535,
    2828,  1239,   704,   705,   706,   707,   708,   846,  1692,   777,
    1647,  2482,   771,   772,  1946,  1947,   709,   710,   855,   838,
     711,  1322,  2414,  2144,  2145,  2146,  2147,  2148,  2411,  2608,
    2609,  1323,  1324,  1596,  2403,  2600,  2135,  2400,  2846,  2847,
    1325,  1606,  2152,  1897,  2418,  2618,  1734,  2012,  1898,  1326,
    1327,  2508,  2797,  2798,  2799,  2879,  1328,  1329,  1184,   712,
     713,  1009,  1331,  1332,  2748,  1612,  1613,  1614,  1900,  2154,
    2621,  2622,  1333,  1874,  2115,  2575,  1948,  1949,  2676,  2472,
    2781,  2473,  1950,  2475,  1951,  2495,  1952,  2496,  2677,  2678,
    1334,  1590,  1591,  1871,  1335,  2793,  2686,  2789,  1877,  2256,
    2500,  2501,  2502,  2787,  2257,  1878,  2687,  2794,  2123,  2124,
    2125,  2126,  2127,  2128,  2593,  2594,  2595,  2844,  2733,  2910,
    2129,  2728,  2398,  2130,  2399,  2131,  2332,  2248,  2249,  2250,
    2774,  2251,  2669,  2663,  2865,  1953,  1049,  2623,  1050,  2227,
    2149,  2684,  1803,   839,  1804,  2055,  1076,  1077,  1670,  2056,
    2552,   116,   714,   715,  2370,  2570,  2108,  2569,  1617,  1905,
    1906,  2112,  1865,  1336,  1866,  2140,  2605,  1389,  1861,  1862,
    2509,  2689,  2408,  2374,  2132,  1604,  1885,  1886,  2790,  2133,
    2339,  2730,   716,   717,  1583,  1863,  2365,  2566,  2567,  1302,
     718,   841,  1338,  1339,  1599,  2137,  1340,  1341,  1882,  2076,
      35,    36,    94,    95,   132,   133,   765,  1806,   767,  1372,
    1807,   719,    26,    90,    87,   720,   950,  1517,  1170,   880,
     721,   928,   722,  1987,   723,  1641,   769,  1374,   724,   725,
     106,   726,   727,   728,   729,   730
};

static const short yypact[] =
{
    1127,   786,   421,   421,   421,   421,   421,   421,   421,-32768,
     421,-32768,   189,-32768,-32768,-32768,   273,   381,-32768,   266,
  -32768,-32768, 31302, 30709,-32768,  -243,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768, 30839,   679,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   411,-32768,-32768, 31302,-32768,
  -32768, 30709,   408,   111, 29737,-32768, 27603,-32768,-32768,-32768,
    1127,   679,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   150,
   26779,    59,-32768,-32768,-32768,-32768,-32768,  4380,-32768,-32768,
  -32768,-32768,-32768,   415,   796,-32768,   150,   150, 31302, 26779,
   26779,-32768,-32768,    69,   431,-32768, 31302,-32768, 31302,   294,
    1334,-32768,-32768,-32768,   464,-32768,-32768,-32768,-32768,  -103,
  -32768,-32768,-32768,  1334,-32768,-32768,   697,   129,   137,-32768,
      65,    76, 26779, 26779, 26779, 26779,-32768,   424,  -103,-32768,
  -32768, 11747, 10501,-32768,   174,  1127,   737, 26779, 26779,-32768,
     150,   218,   218,    69,    69,   264,-32768,   790,   534, 31302,
  -32768,-32768,   850,-32768,-32768,   485,-32768,-32768,-32768, 10501,
    1115,   854,-32768,    91,-32768, 25639,-32768,-32768,    69,    69,
     293,  1948,   863,   424,-32768,-32768,-32768,-32768,-32768,  4207,
  -32768,   384, 10501, 10501, 10501, 10501, 10501,-32768,-32768, 10501,
     466,-32768,   470,-32768,  1945, 26779,-32768,-32768,   434,   636,
  -32768,-32768,   515,-32768,   529,-32768,   517,-32768,-32768,   552,
  -32768,   580,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
      95,-32768,    55,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
     434,-32768,   636,-32768,-32768,   583,-32768,   592,-32768,   574,
  -32768,-32768,   605,-32768,   611,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  1045,  1045,-32768,-32768,-32768,-32768,
   10501, 10501,-32768, 31302, 31302,-32768,-32768,-32768,   695,-32768,
   31302, 31302,-32768,-32768,-32768,-32768,-32768,  1945,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,    69, 31302,-32768,
    -106,-32768,   445,   689,-32768,   454,   985,  1030,  1035, 31302,
    1036,  1043,  1044,-32768,   488,-32768,-32768,-32768,  1072,-32768,
    1074,-32768,-32768,-32768,-32768,-32768,  -106,-32768,-32768,-32768,
    1076,  1080,   424,  1036,  1081,  1090,   533,-32768,   142,   144,
   31302,   729,  1046, 31302,-32768,  1334,-32768,-32768,-32768, 31302,
     544,-32768,-32768,  1098,-32768,   752,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,   985,   752,-32768,-32768,-32768,-32768,-32768,
  -32768,   753,   143,   207,   195,-32768,  4094,-32768,-32768,-32768,
     740,  1125,   208,   794,-32768,-32768,-32768,   570,  1129,   937,
     214,   215,   223,   772,   216,   809,-32768,-32768,-32768,   770,
    1140, 31302,   774,-32768,  1334,  1334,   775,  1150,   412,-32768,
     689,  1145,-32768,-32768,-32768,-32768,  1146,-32768,  1148,-32768,
    1152,-32768, 31302,-32768, 31302,-32768,-32768,  1036,  1153,-32768,
  -32768,-32768,-32768,  1156,   412,   787,  1155,-32768,  1163,-32768,
  -32768,-32768,  1164,-32768,-32768,-32768,-32768,   839,   800,-32768,
   22317,-32768,-32768,-32768,-32768,-32768,-32768,   929,-32768,-32768,
     844,   845,   846,   847,-32768,-32768,   615,  1202,   855,-32768,
     942,-32768,   857,   859,   625,   862, 30969,-32768,-32768, 30969,
   31302,-32768,-32768, 11955, 31302,-32768, 31302,-32768,-32768, 31302,
  -32768, 13645,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   31302,-32768,-32768,-32768,-32768,    73,    73,  4052,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768, 31302,
  -32768,-32768,-32768,-32768,-32768, 30111,-32768,-32768,-32768,  4052,
  -32768, 30111, 31302, 30111,   801,-32768,-32768, 11279,-32768,-32768,
   11279,-32768, 31302, 11279,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768, 30111,-32768,    21, 30319, 31302,-32768,-32768,
  -32768,-32768,-32768, 11955,-32768,-32768,-32768,-32768,-32768,  4728,
   30111,  6751,-32768, 30579, 30579,-32768,-32768, 31302,  4734, 30111,
   12085,  4052,  6751,-32768, 28684,  4052,-32768, 30709,-32768,  6751,
  -32768,  6751, 30111,-32768,-32768,  6751,  6751,    73, 31302,-32768,
   31302, 30579,-32768, 31302, 30579,-32768, 31302, 10859,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,   372,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   472,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,   895,-32768, 15024,   747,
  -32768,  1127,    93, 30969,   810,-32768,-32768,-32768,-32768,  1948,
    1036,-32768,   813,-32768,   217,-32768,-32768,-32768,-32768,-32768,
     652,   886,  1238,-32768, 30969,   892,-32768,-32768,-32768,   231,
  -32768,   664, 27786,   828,-32768,   669,-32768,   667,-32768,  1256,
    -225,   220,-32768,-32768,-32768,   876,-32768, 27969,-32768,-32768,
     826, 11071,-32768,-32768,-32768,  1037,-32768,  6751,  7097,-32768,
  -32768,   875,   881,   887,   888,   898,   899,   900,   904,  6751,
    1042,   906,   907,   909,-32768,  6751,  6751,   910,-32768, 13437,
     912,-32768,   914,   486,   917,   918,   919,   921,   922,  6751,
     923, 29881,-32768,    96,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,   366,-32768,   890,-32768,-32768,-32768,
  -32768,-32768,-32768, 30111,-32768,-32768, 27969,-32768,   -62,-32768,
  -32768,  1057,-32768,    80,-32768,   915,-32768,-32768,-32768,-32768,
    1312,-32768,-32768,   256,-32768,   749,-32768,   750,  1312,-32768,
     776,-32768,-32768,   958,    98,-32768,   916,-32768,-32768,   724,
  -32768,-32768,-32768,   950,-32768,  -198,-32768,   726, 29981,  -207,
  -32768,  1064,  6751,  6751,-32768,  1338,-32768,-32768,-32768,-32768,
  -32768,-32768, 13307, 13307, 13307,-32768, 13307,-32768, 13307, 13307,
     793,   -62,   793,   793, 12293, 12293,   793,   793,   -62,-32768,
    1356,-32768,     8,  1359,-32768,   -62,  3691,-32768,    50,    39,
  -32768,-32768,  6751,   812,-32768,-32768,-32768,-32768,-32768,   471,
  -32768,-32768,   884,  1026,   884,  4052,-32768,    47,-32768,-32768,
    6751,   980,   982,   986,   987,   988, 28094,   992, 12085,  1002,
  -32768,  1094,  1009,-32768,   860,-32768,-32768,-32768, 12423,-32768,
    1396,-32768,  1394, 31302,-32768,    17,   871,-32768,-32768,  1410,
  -32768,   803,  1410,  1413,   804,  1410,  1413,  6751,  1410,-32768,
  -32768, 11071, 30111,-32768,-32768,  1049,   250,-32768,  1040,  6751,
    1041,  1387,-32768,   821, 12631, 12631,-32768,-32768,-32768,  2450,
  -32768,-32768,-32768,   320, 31302,-32768,  -165,-32768,  1088,  1403,
  -32768,-32768,  1403,-32768,-32768,-32768, 31302,-32768, 31302,  1091,
  -32768,  1050,-32768,-32768, 27786,   667, 10501, 11955,  -271, 25764,
   31302,-32768,-32768, 31302,-32768,   891,   866,   893,  1060,   905,
  -32768,-32768,  1069,   105,-32768,-32768,-32768,   134,  6751,   134,
  -32768, 30579, 30579, 30579, 30579,  1031,  6751,  6751, 29881,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,   873, 30579,  1445,
    6751,  3777, 29881,  1031,-32768, 13775,-32768,  1466,   955,-32768,
  -32768,-32768,  6751,-32768,  6751,  6751, 29881,  6751,  6751,  6751,
    6751,  6751,  6751,  6751,  6751,  6751,  6751,  6751,  6751,  6751,
    6751,  6751,  6751,  6751,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  6751,  6751,-32768,-32768,  1095,  6751,
  -32768,  6751,  1096,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768, 30111,-32768,   894,  1102,
  -32768,-32768, 11955, 12761,-32768, 12761, 12085, 11279,  6751,  6751,
    6751,  1105,-32768,-32768, 30111, 30111,-32768,   897, 12085, 30579,
     870, 31302, 10501, 10631, 30319, 30111,-32768,   924,  6751,  1187,
  -32768,-32768,   984,-32768,-32768,  1359,    64,-32768, 11071,-32768,
  -32768,  1483,  1487,-32768,-32768,-32768,-32768,-32768,-32768,   271,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,  4728,-32768, 12293,  6751,  -123,-32768,-32768,-32768,
    1502,-32768, 30579,  1486,  1488,-32768,-32768,-32768,-32768,   132,
  -32768,-32768,-32768,-32768,-32768,  1399,-32768,-32768,  1339,-32768,
  -32768,-32768,  6751,    73,   884,-32768,-32768, 31302,  1499, 30579,
   30579,-32768,   971,-32768, 30579,   943, 30111,-32768,  6751,   -52,
  -32768,   989,-32768,    61,-32768,  1097,-32768,  1100,  6751,   540,
  -32768,-32768,  -103,-32768,  1540,-32768,  1038,-32768, 30111,-32768,
  -32768,-32768, 31302, 30579, 30579,   164,   250,  1431,    25, 30111,
   11071,-32768,  1047,-32768,  1544,  1524,-32768,-32768,  1525,   945,
  -32768,-32768,  1274,  1274,   155,  1054,-32768, 31302,-32768,-32768,
   27969, 27969,-32768,-32768,-32768, 31302,-32768, 31302,   353, 27969,
  -32768,   532,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,   736,-32768,-32768,
  -32768,-32768,-32768,-32768,  1506,   320,-32768,-32768, 18951,-32768,
  -32768,-32768,-32768,  1176,  1183,-32768,-32768,  1334,-32768,-32768,
    1334, 28277,-32768,   993,   158,-32768, 12085,  1068,-32768,-32768,
     828,-32768,-32768,-32768,  1067,-32768, 31302, 31302,-32768, 31302,
  -32768,-32768, 28933,  4052,  1225,  1227,  1228,   248,   353,  1229,
   29157, 29240,  1077,  1231,  1233, 29319,-32768,  1234,  1237,  1257,
    1258,   912,-32768,  6751,  6751,  6751, 29348,  6751, 29420, 29715,
   29787,  8402,  2957,  5602,  5602,  5818,  2982,  2982,  2982,  2982,
    2982,  2982,   134,   134,  1194,  1194,  1194, 29881, 29881,  1031,
   29881, 29881,  1031,  4052,-32768, 31302,-32768,  1028,-32768,-32768,
  -32768,-32768,  1027,-32768,  1611,  1615,-32768,  1617,  1083,  6751,
  -32768,-32768,  1052,  1620,-32768,  1184,  1051,  1413,-32768,  1275,
     362,-32768,  1241,-32768,-32768,  1053,   880, 31302,-32768,-32768,
    1247,-32768,   420,  6751,-32768, 31302, 31302,  6751, 30449,   -62,
    1625,  1130,  1621,  1622,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    1262,-32768,-32768,-32768, 30111,  1158,  5352,-32768,-32768,-32768,
    1619,  6751,   884, 13983,-32768,-32768,-32768, 22878,  4052,  1304,
    1653,  1306,   249, 31302,  1308, 12085,-32768,  4052,-32768,-32768,
    1340,-32768,  6751,   130,-32768,-32768,  1107,-32768,    84,-32768,
    6751,-32768,-32768,  1073, 11747,-32768,  1082, 31302,  1656,  8523,
  -32768,-32768, 21756,-32768,  1413,  1413,   821,  1157,  1165, 30579,
   30579,-32768,-32768,-32768,-32768,-32768,-32768,   403,   419,-32768,
     683,-32768,-32768,-32768,-32768, 30579,  1440,  1667,-32768,-32768,
    1647,   430, 12085,  1468, 11409,  1246,  1635,    83, 12969,-32768,
       7,-32768,-32768,-32768,  1289,    29, 27969,   114,-32768,  1108,
    1111,-32768,-32768,-32768, 10253,  1136,   538,-32768,-32768,-32768,
  -32768,  1311,  1116,  1701,-32768, 28460,-32768,-32768, 17268, 17268,
    4864,   410,-32768,   380,-32768, 18951,-32768,  1334,-32768,-32768,
    1285,  1334,  1288,-32768,  1364,  -103, 25764,-32768,  1704, 12085,
    6751,-32768,  1719,-32768,-32768,-32768,-32768, 26987,-32768,-32768,
  -32768,-32768,  1720,-32768, 29881,-32768,-32768,-32768,-32768, 10253,
  -32768,-32768,  1240,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,  1240,-32768,-32768,-32768,-32768,  1240, 29881, 29881,
   29881,  1240, 29881,  1240,  1240,  1240,  6751,  1373,  6751,  1379,
  -32768,  1149, 26987, 11617,-32768, 12085,  6751,  6751,  6751,  5713,
    1731, 25514,-32768,-32768, 12085,-32768,  1154, 31302, 31302,-32768,
  -32768, 31302, 31302,-32768,   967,-32768,-32768,   259,-32768,  1161,
    6751,-32768,-32768,-32768,  1729,-32768,-32768,-32768,-32768,-32768,
   31302,  1413,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768, 30111,-32768,-32768,   444,-32768,-32768,-32768,  1452,
  -32768,-32768,-32768,  1435,  1436,  1325,-32768,  1450,  1365,-32768,
   19512, 23439,-32768,-32768,-32768,-32768,  1340,-32768, 20073,-32768,
  -32768,  4510,-32768,-32768,-32768,  1544,  6751,  1372, 25889,-32768,
  -32768,   104,   110,-32768,   664,-32768,  1078,-32768,-32768, 10253,
  -32768,-32768,  1368,  1370,-32768,  1371,  1376,  1377,  1380,  -146,
  -32768,  1761,-32768,-32768,-32768,  2034,  1391,-32768,  1277,   945,
    1754,   -62, 31302,-32768,  1779,-32768,  1780, 15585, 15585, 15585,
   15585,  1262,-32768,-32768,  1781,-32768,-32768,-32768,  1787,-32768,
  -32768,-32768, 15585,   106,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
     261,-32768,  1768,-32768,  1437,-32768,-32768,  1492,-32768, 27969,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,  1242,  1245,     2,
  -32768,     7,-32768, 27969,  1219,-32768,  7949,-32768,-32768,  1408,
  -32768,-32768,-32768, 31302, 31302,  1801,-32768,  2009, 25389,  6751,
  -32768,  6751,-32768,-32768,-32768,-32768,-32768,-32768,-32768, 27969,
  -32768, 27969,  -124,  1223,  1224,  1804,-32768,-32768,-32768, 30111,
     135,-32768,-32768,-32768,  1212,   410,-32768, 31302, 31302,-32768,
  -32768, 31302,   -46,-32768,-32768,-32768,  1226,  1230,  1556,    26,
  -32768,-32768,  1819,-32768,    26,-32768,  1236, 12085,  1805,-32768,
   31302,  1422,  1428,  1430,  1432,  -159,   263,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  3189,-32768,  1473,  6751,   146,  6751,
  -32768,-32768,-32768,  1474,  1475,  1476,-32768,  1477,-32768,-32768,
  -32768, 29881,   265,-32768,   274,-32768,  1478,  1812,   287, 12085,
    1829,-32768,-32768,-32768,-32768,  6751,  1307,  1597,  6751,-32768,
  -32768,-32768,-32768, 26014,  1489,   259, 16707, 16707,  1835,  -172,
  -32768,  1840,-32768,-32768,-32768, 16707, 31302,  1337, 26139,  1842,
   31302,  -135, 11071, 24000,   312,-32768,  1157,  6751,-32768,  1496,
    4052, 30111,-32768, 13645, 30111,-32768,  1497,-32768,-32768, 19512,
   23439,-32768,-32768,  1262,-32768,-32768,  5088,-32768,  1318,-32768,
  -32768,  1433,-32768,  6059,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,  1266,  1124,    56,  1467,
     409,   409,   409,   409, 10253,  8523, 10253, 10253, 10253, 10253,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768, 11955,-32768,  1454,
     430,-32768,-32768,  1280, 30579, 15585, 30579, 15585,-32768,-32768,
  -32768,-32768,-32768,   403, 15585,   419, 15585,-32768,   -62,  1440,
  -32768,  1516,  1833,-32768, 30111,-32768,  1479,   353,   736,  1246,
    1246,-32768,-32768,-32768,-32768,   315,-32768,  1438,-32768,  1480,
    7375,  1480,  8827,  1868,  1870,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,   190,  2511, 27969,   322,-32768,  1291,-32768, 10253,
    1363,-32768,  1862, 27969,    51,-32768,  1878,  1871,-32768,-32768,
  -32768,-32768,  1369,-32768,   319,-32768,  1296,-32768, 31302, 31302,
   28460,  1882,-32768, 30111, 31302, 20634, 20634,-32768,-32768,  1883,
  -32768,  1883, 17829, 17829,  1883,-32768,-32768,  1127,  1948,-32768,
  -32768,-32768,    73,    73,    73,  1864,    73,    73,    73,    73,
      73,    73,  1866,-32768,  1869,    73,-32768,-32768,-32768,  1556,
  -32768, 30111,  1315,-32768,  1493,  1127,  1876,-32768,  1879,  1877,
    1880,  1884,  1886,  1887, 13099,  1819,-32768,  1493,-32768,-32768,
   12085,-32768, 27969, 27969, 27969,  7949,  1889,-32768, 26987,  1676,
    1336,-32768,  1078,  1078,-32768,  1535,-32768,  1536,  1538,  1629,
  -32768,  1549,  1550,-32768,  1553,-32768,-32768,-32768,    66,-32768,
  -32768,-32768,  6405,-32768,-32768, 27112,  1447,   407, 29881,-32768,
  -32768,-32768,-32768,  6751,-32768,-32768,-32768,   -62,-32768,   240,
   12085,-32768,  1932,  1558,-32768,-32768,  1596,-32768,-32768,-32768,
    1444,-32768,-32768, 31302, 16707, 10501, 26264, 31302, 16707,-32768,
  -32768, 30579,-32768,-32768,  6751,-32768,-32768,-32768, 30579,  1625,
    1752,-32768,-32768,   -62, 29881,  1654,-32768,-32768, 11071,  1570,
  -32768,  4052,-32768,-32768,-32768,-32768, 20073,-32768,  1157,-32768,
    6751,-32768, 10501,-32768,  1359,-32768,  1401,-32768,  1608,-32768,
  -32768,-32768, 10253,-32768, 10253, 10253, 10253, 10253,  2034,   323,
  -32768,  1634,  1634,  1690,  1690,-32768, 24561,-32768,  1492,  1949,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768, 31302,-32768, 10253,-32768,-32768,-32768,
     736, 27969,-32768,-32768,  1859,  1545,-32768,-32768,   160,  3586,
  -32768,-32768,  7949,  7949,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768, 10253,  1575,-32768,  1578,   374,  7671,
     330,-32768,-32768,-32768,-32768, 31302,-32768, 30111,-32768,  9105,
  -32768,   331,-32768,  7949,-32768, 27969,  9401,-32768,-32768, 27969,
  -32768, 31177,  1389,-32768,-32768, 30111,-32768,  1883,-32768,-32768,
   31302, 17829, 17829,-32768,-32768, 17829, 25122,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,  -188,  1970,-32768, 30111,   635,-32768, 25122,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,  1624,  1974,-32768,   351,-32768,   352,   173,   166,
  -32768,-32768,-32768, 26389,  1390,  -160,  1956,  1956,  1957,-32768,
    1956,  1956,  1958,-32768,   156,-32768,   566,  1544,-32768, 27295,
    1983,-32768,-32768,  7069,  1660, 31302,  1409,   409,-32768,-32768,
   29881,-32768,  1658, 12085,-32768,  6751,-32768,  1459,  1969,   -62,
  -32768,-32768,   371,-32768,-32768,-32768,-32768,   120,  1644,  1413,
  -32768,-32768,-32768, 11071,-32768,  1648,  1625,  1607,-32768,  1654,
  -32768,-32768,-32768, 14463,   167,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  1259, 10253,  1265,  1330,  1419,  1542,
   10253,-32768,-32768,-32768,  1157,-32768,   354,-32768,    79,   736,
     736,-32768,-32768,   353,-32768,-32768,   353,-32768,  1870,-32768,
    2034,   226,-32768,   226,-32768,-32768,-32768, 10253,   156,  9679,
  -32768,-32768,-32768,  1480,-32768,-32768,-32768,  2034, 27969,-32768,
    1610,-32768,-32768,  1999,-32768,  1498,  8245,-32768,  2000,-32768,
  -32768,  2034, 27969,  1993,-32768,  1868,-32768,-32768, 11071,-32768,
  -32768,   286,-32768,-32768, 31302,-32768,-32768,-32768,-32768,-32768,
    1834,-32768,-32768,-32768, 30111,  1970,-32768,-32768, 30111,-32768,
   30111,-32768,-32768,  1441,  1471,-32768,  1803,  1834,  1809,  1755,
   27969, 27969,-32768,-32768,-32768,  1989,-32768,-32768,  1598,  1401,
    1995,  1401,-32768,  2018,  2018,   357,  1671,  2018,-32768,  1678,
  -32768,-32768,-32768, 27969,-32768,  1639,-32768,-32768,   566,  1680,
   27112,-32768, 27112,-32768,-32768, 10253,-32768,  1626,-32768,  1676,
   27478, 11409,   494, 12085,-32768,  1685,   457,  1657,-32768,-32768,
  -32768,  1482,   -62,-32768,    14,  1625,-32768,-32768,  1702,-32768,
   20073,-32768,-32768,-32768,   360,-32768,-32768,-32768,-32768,  2034,
  -32768, 31302,-32768,  1498,-32768,-32768, 10253, 10253,   361,-32768,
  -32768,   364,  2116,  1663,-32768,-32768,-32768,  9975, 30111,   407,
     367,  1124,  9401,-32768,  1664,  1625, 31177,-32768,-32768,-32768,
  -32768,-32768,-32768, 16146, 16146,-32768, 16146,-32768, 16146, 16146,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1669,-32768,
  -32768,  1708,-32768,  2036,  1711,  1721,  2049,-32768,-32768,  1723,
  -32768,-32768,  1686,  7949,-32768,-32768,-32768,   379,-32768,  2076,
  -32768,  2034,  7949,-32768,-32768,-32768,-32768,  2077,-32768,  -156,
  -32768,-32768,-32768,-32768,-32768,   557,-32768,-32768,-32768,-32768,
   13307, 13307, 13307, 13307, 13307, 13307,-32768,  2058,-32768,   389,
  -32768,  6751, 26514,-32768,-32768,-32768,    34,-32768,  1654,  4052,
    1654,-32768,  1461,-32768,   -62,-32768,   407,   146,   146,   156,
  -32768,-32768, 10253,   156,-32768,-32768,   393,-32768,  2034,-32768,
  -32768,-32768,-32768,  9401,-32768,-32768,-32768, 16146,-32768, 16146,
  -32768,-32768,-32768,  1494,-32768,-32768,-32768,-32768,  1734,-32768,
   27969,   182, 27112,-32768, 10253,  1868, 27478,-32768,-32768,-32768,
   18390, 18390,-32768,-32768, 18390,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,   457,-32768,  2085,-32768,-32768, 21195,-32768,-32768,
  -32768,-32768,-32768,  1531,-32768,-32768,-32768,  1747,-32768,  2034,
  -32768,-32768,  9975,-32768,   394,-32768,-32768,  1401,-32768,   395,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  6751,-32768,
    1749,-32768,-32768,-32768,-32768,-32768,-32768,  1750,-32768,-32768,
     113,-32768, 11071,-32768,  1625,  2103,  2104,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,    82,-32768,   168,  -194,-32768,-32768,  -654,
     -51,-32768,-32768, -1503,-32768,-32768,-32768,-32768,  -786,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768, -2354,-32768, -1400,-32768,   152,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,   344,-32768,-32768,-32768,-32768,   852,
  -32768,   582,-32768,-32768,     4,-32768,-32768,  2096,-32768,  2097,
      43,-32768,-32768,-32768,-32768,-32768,   417,   112,-32768,   405,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -136,
  -32768,  1980,-32768,  1764,  -129,-32768,  1914,-32768,-32768,  1912,
  -32768,  1860,-32768,-32768,-32768,  1773,  1677,  1109,  1777,  -296,
  -32768,-32768,-32768,-32768,-32768,  1121,  -738,-32768,-32768,-32768,
  -32768,  -216,  1727,  1873,  1881,-32768,-32768,  1706,-32768,-32768,
    1762,-32768,-32768,-32768,-32768,  1765,-32768,-32768,-32768,-32768,
    -403,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1703,
  -32768,  1705,-32768,-32768,-32768,-32768,  -950,-32768,-32768,  -648,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,  2331,-32768,-32768,
     654,-32768,  -952,  -869,  -301,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,   473,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    -541,-32768,-32768,-32768,-32768,-32768,  1548,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,   818,-32768,-32768,-32768,-32768,   251,-32768,
  -32768,-32768,-32768,-32768, -1499,-32768,-32768,   242,-32768,-32768,
  -32768,-32768,-32768,-32768,  -890,  -585,   467,   691,-32768,  -552,
    -247,  -876,   782,-32768,   204,-32768, -1711,   -22,   369,-32768,
  -32768,  1218,  1137, -1653,  -375,   797,-32768,-32768,-32768,   340,
     889,-32768,-32768,-32768,-32768,-32768,    90,  -175,   902,   627,
     375,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
     483,-32768, -1246,-32768,   619,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,    97,-32768,    99,-32768,-32768,
  -32768,-32768,  1017,-32768,-32768,-32768,-32768,-32768,-32768,  -335,
   -1418,-32768,-32768,-32768,-32768,   -16,-32768, -1596,-32768,  -886,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,  1888,   -98,-32768,
  -32768,-32768,-32768,-32768,-32768,  -454,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  2094,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   658,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,  -520,  1631,-32768,-32768,
  -32768,-32768,-32768,  1181,-32768,-32768,-32768,-32768,-32768,-32768,
      94,-32768,  1343,-32768,  -116,-32768,-32768,   663,-32768,-32768,
     939,  -293,  1981,-32768,-32768,-32768,-32768,  -237,-32768,  -775,
    1185,   925,-32768,  -526,-32768,   670,  1235,  -238,  -415,-32768,
    -990,-32768,  1055,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,  1010,-32768,   633,-32768,  -459,-32768,-32768,
  -32768,-32768,-32768,-32768,  -603,-32768,-32768,-32768,-32768,-32768,
  -32768,   169,-32768,  1084,   269,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,    12,-32768,  -412,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    1290,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -891,-32768,
     994,  1160,-32768,-32768,    22,-32768,  -469,-32768,-32768,    41,
     308,-32768,-32768,-32768,-32768,-32768,-32768,  -652,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,  -446,-32768,  1207,   561,    27,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768, -2065,  -161,-32768, -2376,
   -2253,-32768,   387,-32768,-32768,-32768,-32768,-32768,-32768,  -653,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,  -616,-32768,-32768,-32768,-32768,-32768,  1253,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,   368,-32768,-32768,
  -32768,  -483,-32768,-32768,-32768,-32768,-32768,-32768,  -381,-32768,
  -32768,  -599,-32768,    53,-32768,-32768,-32768,-32768,  -404,-32768,
  -32768,-32768,-32768,-32768, -1406,-32768,-32768,-32768,-32768,-32768,
  -32768, -2451,  -224,-32768, -2339,    23,-32768,-32768, -2068,  -102,
    -101,   159,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,  -300,-32768,-32768,   153,-32768, -1872,-32768,-32768,-32768,
   -2360,-32768,-32768, -1552,-32768,  -733,-32768,   977,  -513,  -372,
   -1532,-32768, -2155,-32768,-32768,-32768,-32768,-32768,-32768, -1180,
   -2249,-32768,-32768,-32768,-32768,-32768,-32768,-32768, -2008,-32768,
     127,-32768, -1183,-32768,  1281,-32768,-32768,  -946,  -400,-32768,
   -2504,-32768,  -276,   161, -2057, -1363, -1633,   154,  -580,   539,
    -260, -2371,-32768,-32768,   996,  -331,-32768,-32768,  -424,  1297,
  -32768,   241,-32768,-32768, -1261,  -100,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,  2209,   601,   678,  -502,  -504,  -556,   668,
  -32768,    11,  1464,   -33,-32768,-32768,-32768,-32768,-32768,  -494,
  -32768,  -589,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    -723,  1066,  1580,-32768,-32768,-32768
};


#define	YYLAST		31915


static const short yytable[] =
{
      84,    89,   118,   455,    11,   221,  1053,   368,   369,   766,
    1025,    13,    93,  1195,  1196,   929,  1197,   175,  1200,  1201,
    1189,  1198,   168,  1185,  -580,  1659,  1958,  1001,   294,   295,
     296,   297,   298,  1690,   884,  1285,  1033,   344,   188,    98,
    1557,  1558,   983,  1222,  1048,   986,   104,  1294,  1716,  1371,
     864,  1242,  2378,  1240,  1222,   893,  1600,   212,   108,  2002,
    2035,   926,  2376,  1229,  2380,   932,   107,   786,  1473,    89,
     366,   350,    93,  1851,   115,  2328,   345,   206,  2410,   351,
     352,   162,   163,  2139,   188,   162,   163,   263,   131,   766,
    1223,   891,   162,   163,   345,   229,  1224,  1474,   782,  1475,
    2367,  1476,  1165,  1381,    11,    98,   159,   131,   131,  1290,
    1222,    13,   104,  1149,   166,  1954,   345,   345,  1750,   346,
     347,  1143,  2098,   110,  1222,   345,  2201,  1759,   152,  2044,
    1304,   345,  1306,  1153,  1154,  2046,  1215,  1397,   895,  2163,
     131,   131,   131,   131,  1875,  1277,   229,   448,   229,  1868,
    2139,   152,  1111,  1112,  1113,   131,   131,  2478,   977,   367,
    1954,   497,   229,  2617,   152,  2382,  2412,   215,  1473,  1990,
    2655,   229,  1781,  1782,   121,   122,   998,   345,  2382,    11,
    2670,  1785,  1504,   232,  1872,  2709,    13,  2382,  2334,  2335,
    2336,  2337,  1114,  1115,  1116,  1117,  1118,  1119,  2384,   452,
    2385,  2386,  2387,  2388,  2389,  2390,  1035,  1310,  1120,  1121,
    1122,   450,   458,   131,  1312,  2297,  1286,  2734,   466,   468,
     472,  1023,  1172,   123,  1043,  2092,   417,   213,   419,  2786,
    2740,  2788,  2660,   188,   105,  2850,   822,  2493,   312,   433,
    2175,  2941,  1781,  1782,  2512,   326,  2064,   345,  2285,  1529,
    2670,  1785,  1222,  1222,  1290,  1880,  1585,  1586,   850,  1559,
    1535,  2226,  1560,  2006,  1561,  2099,  2739,  2228,  1366,  2263,
      34,  1216,   755,  1562,  1036,  1041,  1608,   313,  2263,   942,
    2898,   371,   372,  1535,  1562,   461,   381,  1609,   376,   377,
    2746,  2228,    14,  1562,  1563,  1484,  1716,   461,   481,   482,
     924,  1178,    37,  1213,  2775,  2303,   380,  2779,  1610,  1367,
     943,   949,  2631,   382,   965,  1611,  2301,   408,   969,  2371,
     971,   312,  1278,  2419,   975,   976,  1042,  2560,   326,  1207,
    1208,  -580,  2905,  1564,  2598,  2612,  1020,  1565,  2582,  2671,
    2584,  2116,  2596,   998,  2877,  2615,    91,  1123,   429,  1881,
    1124,   432,  2610,  1516,  1214,  2651,  2651,   436,  2721,  2610,
     313,  2776,  2571,  2632,  2560,  2839,  1291,  2155,  2839,   966,
     998,  2742,   743,   970,  1179,  1291,  2329,   974,   222,   223,
     224,   225,   226,  2872,  2836,  1173,   152,   222,   223,   224,
     225,   226,  2747,  2892, -1493,  2878,  1917,  2912,  2742,  2650,
     222,   223,   224,   225,   226,  1566,  2391,  1772,    15,   478,
    2770,  2286,  2772,  1480,   105,  1536,  1566,   179,  2942,  2171,
     109,  2921,  2174,  1014, -1495,  1566,  2729,  2494,  2729,  2661,
     408,  1765,   408,  2729,  1318,  1228,  1505,  2315,  1536,   154,
    1349,  1015,   453,   165,  1021,   152,   152,   134,  2017,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  2114,  1125,  1567,  2908,  1000,
     470,  2007,  2911,  1321,  2900,  1387,  2902,  2914,  1363,   230,
    -580,  1126,  2298,  1687,   750,  1127,  1689,   750,   756,  2852,
    1258,   763,   768,  2330,   770,   449,  1018,   773,  2906,  2907,
     169,  2202,  1114,  1115,  1116,  1117,  1118,  1119,   779,  1384,
    1385,  1386,  2577,  1786,   999,   834,  1876,  1029,  1120,  1121,
    1122,  1834,  2392,  1279,  1128,  2654,  1393,   779,  1787,  1732,
     427,   111,   428,   766,  2920,  1365,  2735,   834,  2413,  1485,
     779,  1031,  1918,  1486,  1487,  1488,  1637,  2743,  1305,  2610,
     867,  1225,  1129,  1587,  2656,  2712,  1919,  1920,  1280,   451,
     459,  2724,  2725,  1489,   885,   887,   467,   469,   473,  1024,
    1130,   763,  1044,   124,  2513,  1510,  1921,  1594,  1595,   834,
    1457,   885,   885,  1786,   967,   933,  1605,  2585,  1775,   834,
     834,   924,   962,   834,  2407,    89,  2359,   834,  1787,   834,
    1658,  1754,  2401,   834,   834,  2331,   978,  2541,   978,   885,
     998,   978,   885,  2100,   978,  2229,  1166,  2264,  1810,   180,
    2306,  1746,   884,  2138,  2810,  1221,  2265,  1255,  1243,  1502,
    2520,   924,  2518,  1013,  2525,  2691,  1000,  1443,   348,  2268,
    1226,   878,  1869,  2164,   943,  1477,  1371,  1568,   766,  1245,
    1437,   164,  1131,  1478,  2255,   164,   348,  1123,  2377,   878,
    1124,  1522,   164,  1000,  2302,  2427,  1607,  2372,  2935,  1155,
    1507,  2420,  1532,  1601,  1490,  2561,  1458,  -654,   348,   348,
    2811,  1014,  2599,  2613,  2729,  2610,  2113,   348,  2729,  2672,
    2474,  2476,  2476,   348,  1554,  1555,  1954,  1521,  1491,  1015,
    2505,   176,  1524,  2652,  2653,  2812,  2722,     1,  2393,  2777,
     125,   750,  2833,  2840,  2813,  2871,  2841,  1492,   177,  2851,
    1132,  2586,   999,  2587,  2875,  1540,   178,   157,   158,  2329,
    1896,  2873,   750,  2568,  2636,    11,   293,    21,   186,   348,
     763,  2893,    13,  1364,  2366,  2913,  2934,  2936,  2814,  2280,
    1706,  1835,  1493,  1562,  2373,  1047,  2815,   205,  1145,  2701,
    2882,   207,  2402,  1836,   485,   834,   834,     2,     3,  1004,
       4,     5,  1494,  1495,  1515,     6,  1125,   834,  1439,  1005,
    1439,   210,   872,   834,   834,   171,   172,   842,  1496,   879,
    1602,  1126,     7,     8,   213,  1127,  2610,   834,  2637,   486,
    2638,   851,  2802,  1822,   164,   856,  2803,   160,   161,   348,
       9,    10,    14,    15,  1823,  2639,  1562,   870,   844,  1826,
     155,   156,  1917,  2640,  1047,  1442,  2673,  2641,  1837,  1497,
    1827,   853,  1006,   981,  1128,  1838,   984,  1456,  1158,  2572,
     181,   182,   183,   184,   211,  1159,  2330,  1007,   214,  1889,
    2816,  2015,  2642,  2720,   216,   208,   209,  1444,  1445,  1446,
    1204,  1498,  1129,  1879,  1646,  2802,  1648,  1211,  -629,  2803,
     834,   834,   220,  1890,  1839,   259,  1891,  1468,  1090,   228,
    1130,   235,  2506,   171,   172,  1566,   300,  2619,  1686,  1731,
     301,  1688,  2588,  2507,   743,  1892,  1205,  1206,  1840,  2674,
    1209,  1210,  1603,  1000,   834,  -629,  -629,   337,  1841,  1842,
     834,  2538,   840,   327,  1503,   840,    22,  1559,  1342,  1343,
    1560,   338,  1561,   834,  1843,   849,  2368,  2369,   834,   840,
      23,   329,  1608,   840,  1253,  2664,  1008,   340,  2666,  2667,
     866,   943,  1562,  1609,   341,   840,  1844,   849,  1566,  1845,
    1846,  1269,  1563,   877,   849,  1847,    24,  1528,  2331,  1544,
     172,   890,  1131,  -253,  1610,   834,   894,  1543,  1918,  1830,
     982,  1611,   342,   985,   931,   360,   988,   834,  1460,  -654,
    -654,  -654,  1919,  1920,   361,   877,  1833,  1615,  1616,   877,
    -654,  1564,  1347,   877,   363,  1565,    96,   364,   849,  2118,
    1893,   849,  1921,   365,  1356,    25,   750,  1813,  1815,  1709,
    1912,  1913,   763,  1710,  1848,   763,   385,  1370,  1373,  2675,
    1961,   770,  2153,   374,  2817,  1962,  1849,  1722,  1723,  1966,
    1132,  1968,  1969,  1970,   384,  1638,   834,  1855,  1856,   885,
     885,   885,   885,   393,   834,   834,    97,  1231,  1232,  1233,
    1234,  -253,  2484,  2485,  1894,   402,   885,   349,   834,   354,
     403,   409,  1895,   224,   225,   226,  2736,  -253,   412,   413,
     834,   414,   834,   834,  1566,   834,   834,   834,   834,   834,
     834,   834,   834,   834,   834,   834,   834,   834,   834,   834,
     834,   834,  1593,  2837,  2838,  2643,  1709,   415,  1597,   416,
    1710,   420,   834,   834,   386,   421,   424,   834,  1955,   834,
    -253,  1054,  1055,  1056,  1711,   425,   426,  1712,  2766,  2767,
     387,   430,  2003,   438,   431,  1567,  2106,   437,   456,   457,
     763,   222,   223,   224,   225,   226,   834,   834,   834,  1562,
    2066,  2067,  2068,  2069,   441,   446,   460,   885,  1700,  1459,
    -253,  1463,   885,   463,   464,     1,   834,  2082,  2800,   465,
     471,   474,   476,   388,  2141,   477,   479,   483,  2156,   484,
     489,   491,  1725,   492,  2324,   499,  1446,   493,   498,   501,
     502,  -253,  2070,  2071,  2072,  2073,  2074,  2075,   503,   505,
    -253,   507,   508,   834,  1758,   734,   735,   736,   737,   738,
     885,  1711,   739,   389,  1712,  1221,   740,   741,   742,   746,
    2726,   747,   748,  2727,   749,     2,     3,  1010,     4,     5,
     834,  1630, -1220,     6,  1632,  1519,  1562,   885,   885,  1012,
    1019,  1764,   885,  1022,   390,  1026,   834,  2299,  1027,  2043,
       7,     8,  1028,   391,  1030,  1635,   834,  1034,  1036,  1037,
    1039,  1858,  1114,  1115,  1116,  1117,  1118,  1119,     9,    10,
     978,   885,   885,  1040,  1045,   931,  1051,  1060,  1120,  1121,
    1122,  1566,  1146,  1061,  2807,  2066,  2067,  2068,  2069,  1062,
    1063,  2066,  2067,  2068,  2069,  1589,  2824,  1152,  1047,  1047,
    1064,  1065,  1066,  1598,   760,  1598,  1067,  1047,  1078,  1079,
    2497,  1080,  1083,   798,  1087,  1568,  1089,   778,  1938,  1091,
    1092,  1093,   394,  1094,  1095,  1097,  1157,  2070,  2071,  2072,
    2073,  2074,  2075,  2070,  2071,  2072,  2073,  2074,  2075,   802,
    1160,  1161,   783,   783,   845,  1163,  1156,  1168,  2474,  1939,
    1164,  1169,  1171,  1174,  2800,  1188,  2066,  2067,  2068,  2069,
     862,   863,  1183,  1202,  1644,  1645,   869,  1645,  1566,   871,
    1212,   834,  1980,  1215,  1981,  1230,  1236,   174,   152,  1069,
    1238,   152,  1246,  1992,  1247,   931,   894,   931,  1248,  1249,
    1250,   834,   834,   834,  1254,   834,   174,  2807,  2070,  2071,
    2072,  2073,  2074,  2075,  1090,  1982,  1983,  1446,  1986,  1256,
     395,  1257,  1258,  1266,  1663,  2048,  1268,  1123,  2824,  1281,
    1124,   834,  1401,  1691,  1282,  2531,   396,  1222,  1296,  2009,
    1283,  1284,     2,     3,   783,     4,     5,   834,  1352,  2901,
       6,  1289,  1293,  1295,   993,  2066,  2067,  2068,  2069,  1298,
    1351,  2438,  1361,  1359,  2358,  1719, -1493,     7,     8,  1377,
    1376,   834,  1378,  1726,  1727,   834,   885,  1070,  1379,   397,
     147,  1380,  1392,  1388,  1394,     9,    10,    27,    28,    29,
      30,    31,    32,  1071,    33,  2038,  2327,  2070,  2071,  2072,
    2073,  2074,  2075,  1435,   834,  1400,  1455,  1429,  1432,   834,
     878,  1925,  1664,  2049,  1436,  1931,   834,  1449,  1469,   398,
    1482,  1756,  1471,  1483,  1834,   834,  1506,   815,  1665,  2050,
     834,  1508,  1467,  1509,   194,   202,  1072,  1511,   834,   817,
     818,  1513,  2503,  1520,  1523,  1269,  1125,  1799,   820,  1525,
     399,  1532,  2350,  2536,  2352,   136,  2614,   885,   885,   400,
    1539,  1126,   202,  1541,  1547,  1127,  1549,  1291,  1473,  1577,
    1579,  1666,  2051,   885,  1580,  1575,  1073,  1582,  2066,  2067,
    2068,  2069,  1588,  1620,  1628,   202,   202,   202,   202,   202,
    2636,  1629,   202,  2345,  1047,  1640,  1636,  1655,   993,  1656,
    1657,  1660,  1799,  1671,  1128,  1672,  1674,  1074,  2150,  1675,
    2151,  1667,  2052,  1904,  2180,  2181,  1075,  2182,  2183,  2184,
    2070,  2071,  2072,  2073,  2074,  2075,  2219,  1639,  1693,  1676,
    1677,  2713,  1129,  2511,  1370,  1696,  1695,  2715,   834,  1697,
    1144,  1698,  1668,  2053,  1702,  1945,  1699,  1705,  1703,  1290,
    1130,  1669,  2054,  1707,  2637,  1701,  2638,  1799,   152,  1720,
    1704,  1708,   152,   202,   202,  1733,  1735,  1736,  2269,  2532,
    1744,  2639,  2068,  2069,  1737,  1741,  1751,  1752,  1753,  2640,
    1757,  1762,  1776,  2641,   834,  1778,   834,  1769,  1780,  1810,
    1945,  1852,  1854,  1812,   834,   834,   834,   834,  1318,  1945,
    1859,  1873,  2716,  1888,  2271,  1994,  1719,  2276,  2642,  1999,
    1999,  1883,  2070,  2071,  2072,  2073,  2074,  2075,   834,  2185,
    1884,  1867,  2527,  1899,  1901,  1902,  2186,  1928,  2011,  2529,
    1932,  1937,  1131,  2439,  2440,  2441,  1935,  2443,  2444,  2445,
    2446,  2447,  2448,  1940,  1957,  1973,  2451,  1959,  2545,   759,
     759,  1975,  1977,   137,  1835,  1988,  2010,  1993,  2187,  2018,
    2021,  2022,   924,   759,  2008,  2023,  1836,  2188,  2070,  2071,
    2072,  2073,  2074,  2075,   834,  2024,  2041,  2025,  2705,  2039,
    2058,   759,  -580,  2060,   759,  2065,  2503,  1799,  2061,  2062,
     759,  2717,  2063,  2077,   759,  2437,  2189,  2190,   759,  2081,
    1132,  2078,   759,  2084,  2086,  2093,   759,   759,   993,   759,
    2083,  2095,   759,  2101,   759,   759,   759,  2104,  2102,  2117,
    2134,  2109,   759,   759,  2110,  2139,  2158,  2159,  2160,  2167,
     759,  1837,  2220,  2178,  2222,   759,  2546,  2179,  1838, -1689,
    2223,  2191,  2224,   759,  2225,  2253,  2259,  2260,  2261,  2262,
    2266,  2267,  2547,  2270,   759,  2273,  2272,  1047,   759,  2283,
    1721,  2279,   759,  2745,  2287,  2291,  2294,   759,  2305,  2312,
     759,  1945,  2320,  2322,  1799,  2326,  2347,  1839,  2361,  2333,
    2192,  2136,  1598,  2349,   776,  2700,  1945,   834,  2360,   834,
    2373,  2364,  2375,  2382,  2409,  2548,  2383,  1945,  2407,  1047,
    2405,  1840,  2415,  2416,  2417,  2421,  2425,  2430,  2442,  2471,
    2449,  1841,  1842,  2450,  2718,  2170,  2170,  2456,   847,  2170,
    2460,  2457,  2462,  2461,   852,  2463,   854,  1843,  2481,  2464,
     861,  2465,  2466,   861,  2479,  2549,   861,  2193,  1644,  2483,
    2885,  2886,  2887,  2888,  2889,  2890,   873,  2486,  2487,  1844,
    2488,  2489,  1845,  1846,  1876,   834,  2515,   834,  1847,  2514,
    2782,  2490,  2491,   922,  2206,  2492,  2550,  2503,  2517,  2503,
    2516,   935,   938,   941,   894,  2551,  2518,  2530,  2537,  2533,
    2553,  2207,  2208,   834,  2574,   972,   834,  2581,  2564,  2209,
    2583,  2278,  2624,     1,  2634,   931,  2649,  2377,  2650,  2659,
     995,  2662,  2665,  2668,  1719,   993,  2293,  2682,  2295,  2685,
    2697,  2690,  2693,  2528,  2699,   834,  2703,  1848,   834,  2707,
    2706,  2210,  2737,  2738,  2742,  2744,  2255,  2762,  2750,  1849,
    2211,  2760,   105,  2764,  2768,  2673,   302,   303,  2226,  2542,
    2771,   834,  2773,  2778,   304,  2066,  2067,  2068,  2069,  2544,
    2780,  2783,  2785,     2,     3,  2792,     4,     5,  2809,  2212,
     783,     6,  1799,  1799,  1799,  1799,  1799,  1799,  2823,  2821,
    2066,  2067,  2068,  2069,  2830,   763,  2853,  2862,     7,     8,
    2863,  2864,   885,  2866,   885,  2822,  2843,  2070,  2071,  2072,
    2073,  2074,  2075,  2867,  2868,  2869,     9,    10,  2870,  2436,
    2874,  2876,  2891,  2917,  2213,  2903,  2918,   993,  1805,  2928,
    2931,  2522,  2070,  2071,  2072,  2073,  2074,  2075,  1799,  2932,
    1799,  2938,  2939,  2946,  2947,  2309,  2927,  2459,  2221,  2254,
    2031,  1531,  1945,    38,   759,  1767,    39,  1799,  2290,  2004,
     170,  1945,  2842,  2214,   995,  1995,   422,   261,   264,   418,
     356,  1354,  2066,  2067,  2068,  2069,  2422,  2423,  1904,  2503,
     423,   500,  2170,  1887,  1355,   358,   488,  2194,  2195,  2196,
    2197,  2198,  1086,   475,   359,   494,   445,  2883,   443,   495,
    1743,  1974,   961,  1624,  2176,  1984,  2168,  2944,  1728,  1362,
    2348,  1553,   236,  2563,  2070,  2071,  2072,  2073,  2074,  2075,
    2904,    11,  2694,  1809,  2080,  1991,  1147,  1556,    13,  1831,
    2354,  1464,  2702,  2763,  2356,   119,  1774,  1350,  1887,  2363,
    1945,  1945,  1945,  1799,   868,   378,  1945,  1777,  1545,    11,
     299,   237,  2849,  1358,  2695,  1574,    13,  1779,  2635,  2752,
    1451,  1870,  1501,  2899,   759,   759,   759,  1287,   238,  2470,
     834,  1177,  2761,  1047,  2340,  1241,  1514,  2469,   894,  1441,
    2452,   834,  2218,  2795,   931,  1194,  1194,  1194,  1402,  1194,
    1375,  1194,  1194,  1978,  2616,  2480,  2111,   147,   147,  2933,
    2923,  1999,  1330,  2854,  2524,  1999,   239,   931,  2765,   885,
    2157,  2919,   834,   305,  2784,  2681,   885,  2477,   240,  2504,
    2578,  2381,  2579,  2731,  1592,  2394,  2769,  2424,   241,   834,
    1337,  2801,  2723,  2406,  2922,  2714,  2404,  2835,   834,  1584,
     306,   941,  1303,   113,  1936,  2601,     0,   242,  1011,     0,
    1799,  1264,  1799,  1799,  1799,  1799,     0,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2057,     0,
       0,     0,     0,   244,   995,  1147,     0,     0,     0,     0,
       0,     0,  2565,     0,  1799,     0,  1800,  1301,  1301,  1945,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1799,  1799,  2808,     0,     0,     0,     0,     0,     0,     0,
       0,   307,  1799,   245,     0,     0,     0,  1799,     0,   202,
       0,     0,     0,  2136,     0,     0,     0,  1799,     0,     0,
       0,  1799,     0,  1945,  1799,     0,   246,  1945,     0,  1589,
       0,  1800,     0,     0,     0,     0,     0,     0,  2626,     0,
       0,   247,     0,     0,  1626,     0,     0,   308,   248,     0,
       0,   249,     0,     0,     0,     0,     0,     0,  1399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,   252,     0,     0,
       0,     0,     0,     0,     0,     0,  1800,     0,     0,     0,
       0,  2658,     0,     0,   309,     0,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1047,   894,   894,
       0,  2683,     0,  2688,     0,   254,     0,     0,     0,  1434,
    1546,     0,     0,   834,     0,     0,   147,     0,   147,   941,
     861,     0,     0,     0,     0,     0,     0,  1450,   873,     0,
       0,   941,     0,     0,     0,   202,     0,     0,  1465,  2384,
    2894,  2385,  2386,  2387,  2388,  2389,  2390,  2066,  2067,  2068,
    2069,   995,     0,  1799,  1307,     0,     0,     0,  1799,     0,
       0,   310,     0,     0,     0,     0,     0,     0,     0,   311,
       0,     0,     0,     0,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,     0,  1799,     0,  1799,     0,  2070,
    2071,  2072,  2073,  2074,  2075,     0,  1945,     0,  2045,  2047,
       0,     0,     0,  1749,  1799,     0,  1800,     0,     0,     0,
    1945,     0,     0,     0,     0,     0,     0,     0,     0,  1526,
       0,     0,  2749,  2338,  1805,  2341,  2342,  2343,  2344,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1808,     0,
       0,  1551,     0,     0,     0,     0,     0,  2937,  1945,  1945,
       0,     0,  1573,   995,     0,  1308,     0,     0,     0,     0,
       0,     0,     0,  1309,     0,     0,     0,     0,     0,     0,
    1310,  1047,  1311,     0,     0,     0,     0,     0,  1047,  2379,
    1047,     0,  1312,  1799,     0,     0,     0,     0,  1945,     0,
       0,     0,     0,  1800,     0,     0,     0,     0,  1887,     0,
       0,     0,     0,     0,  1907,  1908,     0,     0,     0,   759,
    1313,  1924,     0,     0,     0,     0,     0,     0,     0,  2565,
       0,     0,     0,     0,  1799,  1799,  1314,     0,     0,   941,
       0,  1315,     0,     0,     0,  1799,     0,     0,     0,     0,
    1799,  1316,     0,     0,  1589,     0,     0,  2391,  1317,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1799,     0,     0,     0,     0,     0,   593,     0,     0,
    1799,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   931,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   834,
    2896,     0,     0,   759,     0,     0,     0,   834,     0,   993,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1799,     0,     0,     0,   759,     0,  2027,  2028,     0,     0,
       0,  1799,     0,     0,  2032,     0,     0,     0,     0,     0,
       0,     0,     0,  2392,     0,     0,     0,  1740,  1945,     0,
    1047,     0,  1799,   174,  1945,     0,  1748,     0,     0,     0,
       0,  1800,  1800,  1800,  1800,  1800,  1800,     0,   941,     0,
       0,  2554,     0,  2556,  2557,  2558,  2559,     0,     0,     0,
       0,     0,  1318,  2088,  2089,  2090,  2091,   194,     0,  1319,
    1799,     0,     0,     0,     0,     0,     0,     0,  2097,     0,
       0,  2395,     0,     0,     0,  1887,   834,     0,     0,     0,
       0,  1320,     0,     0,     0,     0,  1321,  1800,     0,  1800,
       0,     0,     0,     0,     0,   941,     0,   941,     0,     0,
       0,   935,     0,  2580,     0,     0,  1800,     0,  2597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2611,     0,
       0,     0,     0,     0,     0,  2611,     0,     0,     0,     0,
       0,     0,     0,  1911,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,     0,   783,
     783,   783,   941,   783,   783,   783,   783,   783,   783,     0,
       0,     0,   783,     0,     0,     0,     0,     0,  1109,  1110,
    1111,  1112,  1113,     0,     0,     0,     0,     0,     0,     0,
       0,  2059,     0,     0,     0,  1114,  1115,  1116,  1117,  1118,
    1119,     0,  1800,     0,     0,     0,     0,     0,     0,  2393,
       0,  1120,  1121,  1122,     0,     0,   941,     0,   941,     0,
    1114,  1115,  1116,  1117,  1118,  1119,     0,   941,     0,     0,
       0,     0,     0,     0,     0,     0,  1120,  1121,  1122,     0,
       0,     0,  2281,  2282,     0,     0,     0,     0,     0,     0,
       0,  2289,     0,     0,     0,     0,     0,  2396,  2107,  2300,
       0,     0,     0,     0,     0,  2016,     0,   759,     0,     0,
       0,     0,     0,   759,  2338,  2313,  2314,  2397,     0,  2719,
       0,     0,     0,     0,     0,   993,     0,     0,     0,     0,
       0,     0,     0,     0,  2037,     0,   759,     0,  1057,  1059,
       0,     0,     0,     0,     0,     0,  2732,     0,  2057,  1800,
    1068,  1800,  1800,  1800,  1800,     0,  1081,  1082,     0,     0,
       0,     0,     0,     0,     0,  2741,     0,     0,     0,     0,
    1096,  2351,     0,  2353,     0,     0,     0,     0,     0,     0,
    2355,     0,  2357,  1800,     0,     0,     0,     0,     0,     0,
    1123,  2230,     0,  1124,     0,     0,     0,     0,     0,  1800,
    1800,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1800,     0,     0,     0,  1123,  1800,     0,  1124,     0,
       0,     0,     0,     0,     0,     0,  1800,     0,     0,     0,
    1800,     0,     0,  1800,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2791,     0,     0,     0,     0,     0,
       0,  2428,  2429,     0,     0,     0,     0,     0,  2433,  2434,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1887,  1887,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2848,     0,     0,     0,
     941,  2611,     0,     0,     0,     0,     0,     0,     0,  1125,
       0,  1800,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1126,     0,     0,     0,  1127,     0,
       0,     0,     0,     0,  1125,     0,     0,     0,     0,     0,
       0,     0,   941,     0,     0,     0,     0,   759,   759,  1126,
     993,     0,     0,  1127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1128,     0,     0,
    2521,     0,  1800,     0,  2526,   995,     0,  1800,     0,     0,
       0,     0,     0,     0,  2307,     0,   776,  2310,     0,     0,
       0,     0,  1128,     0,     0,  1129,     0,     0,  1800,  2319,
    1800,  2909,  2540,     0,  1800,  1800,  1800,     0,     0,  1382,
       0,     0,  2611,  1130,     0,     0,     0,  1390,  1391,     0,
    1129,     0,     0,  1800,     0,     0,     0,     0,     0,     0,
       0,  1395,  2562,  2791,     0,   993,     0,     0,  1130,     0,
       0,     0,     0,  1406,     0,  1408,  1409,     0,  1410,  1411,
    1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,
    1422,  1423,  1424,  1425,  1426,     0,     0,  2362,     0,     0,
       0,  2848,  2231,     0,     0,  1427,  1428,     0,     0,     0,
    1430,     0,  1431,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1131,     0,     0,     0,     0,
       0,     0,  1800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2627,  2628,     0,
    1131,  2629,  2630,     0,     0,     0,  2426,  2232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2233,
       0,     0,     0,  1800,  1800,  2647,     0,     0,     0,  2234,
       0,     0,     0,     0,  1800,     0,     0,     0,     0,  1800,
       0,     0,     0,  1132,  2453,     0,     0,     0,  2235,     0,
       0,  2555,     0,     0,     0,     0,     0,  2468,  2236,     0,
       0,  2237,     0,   941,     0,     0,     0,     0,  1132,     0,
       0,     0,     0,     0,  2238,     0,     0,     0,     0,     0,
    1800,     0,     0,     0,     0,     0,     0,     0,     0,  1800,
    2239,  2573,     0,     0,  2384,  2576,  2385,  2386,  2387,  2388,
    2389,  2390,  2066,  2067,  2068,  2069,     0,     0,     0,  2711,
       0,     0,     0,   941,     0,     0,     0,     0,     0,     0,
       0,     0,  2240,     0,     0,     0,     0,     0,   202,     0,
     759,     0,     0,     0,     0,     0,  1800,     0,     0,  1800,
    1800,     0,     0,     0,  2070,  2071,  2072,  2073,  2074,  2075,
    1800,   995,  2241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2242,     0,     0,   202,     0,     0,     0,     0,
       0,  1800,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2243,     0,     0,  2244,     0,  2245,     0,
       0,     0,     0,     0,  -580,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   787,   788,  1800,
       0,     0,   345,     0,  1654,   789,   790,  2246,     0,     0,
       0,   791,     0,     0,     0,     0,  2247,   792,     0,     0,
       0,     0,     0,     0,  1678,  1679,  1680,     0,  1682,   993,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2602,     0,     0,     0,     0,     0,   793,     0,     0,     0,
       0,     0,     0,     0,  1654,     0,     0,     0,  2625,     0,
       0,     0,     0,     0,     0,     0,  2831,     0,     0,     0,
       0,     0,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,     0,  2453,
       0,     0,  2391,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2855,
    2856,     0,  2858,     0,  2860,  2861,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,  1115,  1116,  1117,  1118,
    1119,     0,  1745,     0,     0,     0,     0,   794,     0,  1654,
       0,  1120,  1121,  1122,     0,     0,   941,     0,  1654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   995,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2392,     0,
       0,     0,     0,  2915,     0,  2916,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,  2327,     0,
       0,     0,     0,     0,   795,     0,  2924,  2925,     0,   796,
    2926,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   995,     0,  2929,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,   797,  2395,  2453,     0,     0,
       0,  2755,     0,  2757,     0,     0,     0,     0,     0,     0,
    1123,     0,     0,  1124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,  1971,     0,  1971,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
      47,     0,    48,     0,   941,     0,   941,     0,     0,   798,
       0,     0,    49,     0,   799,     0,    50,     0,   800,    51,
      52,     0,    53,     0,     0,  -580,     0,    54,     0,   801,
       0,     0,     0,     0,     0,   802,     0,     0,   787,   788,
       0,     0,     0,   345,     0,   803,   789,   790,     0,     0,
     804,  2602,   791,   805,     0,     0,   806,     0,   792,     0,
       0,    56,     0,     0,    57,   807,     0,     0,   454,     0,
       0,    59,     0,     0,  2393,     0,     0,     0,     0,  1125,
       0,     0,    60,     0,     0,     0,     0,   793,     0,     0,
       0,     0,     0,     0,  1126,     0,     0,    61,  1127,  1396,
       0,     0,     0,     0,    62,  1217,   808,     0,     0,     0,
     809,    63,     0,     0,    64,    65,    66,     0,   810,    68,
       0,     0,  2396,  1194,  1194,  1194,  1194,  1194,  1194,   811,
       0,     0,     0,     0,     0,   812,     0,  1128,     0,     0,
       0,     0,  2397,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     813,    72,    73,     0,    74,  1129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   794,     0,
       0,    75,    76,  1130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,   814,     0,     0,     0,
       0,     0,     0,   815,     0,   816,    80,    81,    82,     0,
       0,   265,   266,     0,     0,   817,   818,   819,     0,     0,
       0,     0,   267,     0,   820,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   995,     0,     0,  1654,     0,
    2258,     0,     0,     0,     0,  1131,    40,     0,     0,     0,
       0,     0,     0,     0,    83,   795,     0,     0,     0,     0,
     796,     0,     0,     0,     0,     0,     0,   138,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    42,   797,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2304,     0,
       0,  1654,     0,     0,     0,     0,     0,   237,     0,     0,
       0,     0,     0,  1132,     0,     0,    44,     0,     0,     0,
       0,    45,     0,     0,   238,     0,     0,     0,     0,     0,
       0,     0,     0,  -580,     0,     0,    46,     0,     0,     0,
       0,    47,     0,    48,     0,     0,     0,     0,     0,     0,
     798,     0,     0,    49,   135,   799,     0,    50,     0,   800,
      51,    52,   239,    53,     0,     0,     0,     0,    54,     0,
     801,     0,     0,     0,   240,     0,   802,     0,     0,     0,
       0,   268,     0,     0,   241,     0,   803,     0,     0,     0,
       0,   804,     0,     0,   805,     0,     0,   806,     0,     0,
       0,     0,    56,   242,     0,    57,   807,     0,     0,     0,
       0,     0,    59,   243,     0,     0,     0,     0,     2,     3,
     269,     4,     5,    60,     0,     0,     6,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,   270,    61,     0,
       0,     0,     0,     7,     8,    62,     0,   808,     0,     0,
       0,   809,    63,   271,     0,    64,    65,    66,     0,   810,
      68,     9,    10,  -580,     0,     0,     0,     0,     0,   245,
     811,     0,     0,     0,     0,   272,   812,     0,     0,     0,
       0,     0,     0,     0,  2034,     0,     0,   273,     0,     0,
       0,     0,   246,     0,     0,     0,     0,   274,     0,     0,
      70,   813,    72,    73,     0,    74,     0,   247,     0,     0,
       0,     0,     0,     0,   248,     0,   275,   249,     0,     0,
       0,     0,    75,    76,     0,     0,   276,     0,     0,     0,
       0,   136,     0,     0,     0,     0,     0,     0,   250,    77,
       0,   251,   277,   252,  2510,     0,     0,   814,     0,     0,
       0,     0,     0,     0,   815,     0,   816,    80,    81,    82,
       0,     0,   253,     0,     0,     0,   817,   818,   819,     0,
       0,     0,     0,     0,    40,   820,     0,     0,     0,     0,
       0,   254,   278,     0,     0,   348,     0,     0,     0,     0,
       0,     0,  1654,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
       0,     0,    41,    42,    43,    83,     0,     0,     0,     0,
     280,     0,     0,     0,     0,     0,     0,   281,   138,     0,
     282,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,    45,
       0,   283,     0,     0,   284,     0,   285,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,    47,
       0,    48,     0,     0,     0,   286,     0,     0,     0,     0,
       0,    49,     0,     0,     0,    50,     0,  -580,    51,    52,
       0,    53,     0,     0,   287,     0,    54,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     0,   934,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
      56,     0,     0,    57,    58,     0,     0,   288,     0,     0,
      59,     0,    41,    42,    43,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,   897,    62,    44,     0,     0,     0,     0,    45,
      63,   898,     0,    64,    65,    66,     0,    67,    68,     0,
     899,     0,     0,     0,    46,   900,     0,     0,     0,    47,
       0,    48,     0,     0,    69,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,    50,     0,  -580,    51,    52,
       0,    53,     0,     0,     0,     0,    54,     0,    70,    71,
      72,    73,     0,    74,     0,     0,     0,   901,     0,     0,
       0,     0,     0,     0,    55,   902,     0,     0,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,    57,    58,     0,     0,    77,     0,     0,
      59,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,    60,     0,     0,    79,    80,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,     0,
       0,   903,     0,    62,     0,     0,     0,     0,     0,     0,
      63,     0,     0,    64,    65,    66,     0,    67,    68,     0,
       0,     0,     0,     0,     0,     0,   904,     0,    40,     0,
       0,     0,     0,   905,    69,   906,     0,     0,     0,     0,
       0,     0,     0,    83,     0,   907,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,     0,    70,    71,
      72,    73,     0,    74,     0,     0,    41,    42,    43,   908,
       0,     0,  1810,     0,     0,     0,     0,   909,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    44,     0,
       0,     0,     0,    45,     0,    78,     0,     0,     0,     0,
       0,     0,     0,   910,    79,    80,    81,    82,    46,     0,
       0,     0,     0,    47,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,    50,
     911,  -580,    51,    52,     0,    53,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,  2317,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,    83,     0,     0,     0,     0,   912,     0,
       0,     0,     0,     0,    56,     0,   138,    57,    58,   913,
       0,     0,     0,     0,    59,     0,    41,    42,    43,     0,
       0,     0,     0,     0,     0,    60,     0,     0,     0,     0,
    1654,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,    62,    44,     0,
       0,     0,     0,    45,    63,     0,     0,    64,    65,    66,
       0,    67,    68,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,    47,     0,    48,     0,     0,    69,  1909,
       0,     0,     0,     0,     0,    49,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,     0,     0,     0,     0,
      54,     0,    70,    71,    72,    73,     0,    74,   914,   915,
     916,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,   917,     0,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,     0,    57,    58,     0,
       0,    77,     0,     0,    59,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,    60,     0,     0,    79,    80,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,    63,     0,     0,    64,    65,    66,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,   918,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,    70,    71,    72,    73,     0,    74,   787,   788,
      41,    42,    43,   345,     0,     0,   789,   790,     0,     0,
       0,     0,   791,     0,    75,    76,     0,     0,   792,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    44,     0,     0,     0,     0,    45,     0,    78,
       0,     0,     0,     0,     0,     0,     0,   793,    79,    80,
      81,    82,    46,     0,     0,     0,     0,    47,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,    50,     0,     0,    51,    52,     0,    53,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
     138,    57,    58,     0,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   794,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,     0,     0,     0,    63,     0,
       0,    64,    65,    66,     0,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
       0,    74,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,   795,     0,     0,    75,    76,
     796,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    78,    41,    42,   797,     0,     0,     0,
       0,     0,    79,    80,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,  1115,  1116,  1117,  1118,  1119,    44,     0,     0,     0,
       0,    45,     0,     0,     0,     0,  1120,  1121,  1122,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,    47,     0,    48,     0,     0,     0,     0,     0,     0,
     798,    83,     0,    49,     0,   799,     0,    50,     0,   800,
      51,    52,     0,    53,   138,     0,     0,     0,    54,     0,
     801,     0,     0,     0,     0,     0,   802,     0,     0,   787,
     788,     0,     0,     0,   345,     0,   803,   789,   790,     0,
       0,   804,     0,   791,   805,     0,     0,   806,     0,   792,
       0,     0,    56,     0,     0,    57,   807,     0,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,     0,   793,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,     0,     0,    62,  1217,   808,     0,     0,
       0,   809,    63,     0,     0,    64,    65,    66,     0,   810,
      68,     0,     0,     0,     0,  1123,     0,     0,  1124,     0,
     811,     0,     0,     0,     0,     0,   812,     0,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,   813,    72,    73,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   794,
       0,     0,    75,    76,     0,     0,  1114,  1115,  1116,  1117,
    1118,  1119,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,  1120,  1121,  1122,     0,     0,   814,     0,     0,
       0,     0,     0,     0,   815,     0,   816,    80,    81,    82,
       0,     0,     0,     0,     0,     0,   817,   818,   819,     0,
       0,     0,     0,     0,     0,   820,     0,     0,     0,     0,
       0,     0,     0,     0,  1125,   348,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1126,
       0,     0,     0,  1127,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,    83,   795,     0,     0,     0,
       0,   796,     0,     0,     0,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1128,     0,     0,    41,    42,   797,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1129,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,  1123,    45,     0,  1124,     0,     0,     0,  1130,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,    47,     0,    48,     0,     0,     0,     0,     0,
       0,   798,     0,     0,    49,     0,   799,     0,    50,     0,
     800,    51,    52,     0,    53,   787,   788,     0,     0,    54,
     345,   801,     0,   789,   790,     0,     0,   802,     0,   791,
       0,     0,     0,     0,     0,   792,     0,   803,     0,     0,
       0,     0,   804,     0,     0,   805,     0,     0,   806,     0,
       0,     0,     0,    56,     0,     0,    57,   807,     0,     0,
    1131,     0,     0,    59,   793,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
    1125,     0,     0,     0,     0,     0,    62,     0,   808,     0,
       0,     0,   809,    63,     0,  1126,    64,    65,    66,  1127,
     810,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   811,     0,  1985,     0,     0,     0,   812,  1132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1128,     0,
       0,    70,   813,    72,    73,   794,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,     0,  1129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,  1130,     0,     0,     0,   814,     0,
       0,     0,     0,     0,     0,   815,     0,   816,    80,    81,
      82,     0,     0,     0,     0,     0,     0,   817,   818,   819,
       0,     0,     0,     0,     0,     0,   820,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   348,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,   795,     0,     0,     0,     0,   796,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1131,     0,     0,   138,
       0,    41,    42,   797,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,     0,  1132,     0,     0,   798,     0,     0,
      49,     0,   799,     0,    50,     0,   800,    51,    52,     0,
      53,   787,   788,     0,     0,    54,   345,   801,     0,   789,
     790,     0,     0,   802,     0,   791,     0,     0,     0,     0,
       0,   792,     0,   803,     0,     0,     0,     0,   804,     0,
       0,   805,     0,     0,   806,     0,     0,     0,     0,    56,
       0,     0,    57,   807,     0,     0,     0,     0,     0,    59,
     793,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,  2323,   808,     0,     0,     0,   809,    63,
       0,     0,    64,    65,    66,     0,   810,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   811,     0,     0,
       0,     0,     0,   812,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,   813,    72,
      73,   794,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,   814,     0,     0,     0,     0,     0,
       0,   815,     0,   816,    80,    81,    82,     0,     0,     0,
       0,     0,     0,   817,   818,   819,     0,     0,     0,     0,
       0,     0,   820,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,   795,     0,
       0,     0,     0,   796,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,    41,    42,   797,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,    47,     0,    48,     0,     0,     0,
       0,     0,     0,   798,     0,     0,    49,  -807,   799,     0,
      50,     0,   800,    51,    52,     0,    53,   787,   788,     0,
       0,    54,   345,   801,     0,   789,   790,     0,     0,   802,
       0,   791,     0,     0,     0,     0,     0,   792,     0,   803,
       0,     0,     0,     0,   804,     0,     0,   805,     0,     0,
     806,     0,     0,     0,     0,    56,     0,     0,    57,   807,
       0,     0,     0,     0,     0,    59,   793,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,     0,
     808,     0,     0,     0,   809,    63,     0,     0,    64,    65,
      66,     0,   810,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   811,     0,     0,     0,     0,     0,   812,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,   813,    72,    73,   794,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
     814,     0,     0,     0,     0,     0,     0,   815,     0,   816,
      80,    81,    82,     0,     0,     0,     0,     0,     0,   817,
     818,   819,     0,     0,     0,     0,     0,     0,   820,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,   795,     0,     0,     0,     0,   796,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,    41,    42,   797,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
      45,     0,  -580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
      47,     0,    48,     0,     0,     0,     0,     0,     0,   798,
       0,     0,    49,     0,   799,     0,    50,     0,   800,    51,
      52,     0,    53,   787,   788,     0,     0,    54,   345,   801,
       0,   789,   790,     0,     0,   802,     0,   791,     0,     0,
       0,     0,     0,   792,     0,   803,     0,     0,     0,     0,
     804,     0,     0,   805,     0,     0,   806,     0,     0,     0,
       0,    56,     0,     0,    57,   807,     0,     0,     0,     0,
       0,    59,   793,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,     0,   808,     0,     0,     0,
     809,    63,     0,     0,    64,    65,    66,     0,   810,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   811,
       0,     0,     0,     0,     0,   812,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     813,    72,    73,   794,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,   814,     0,     0,     0,
       0,     0,     0,   815,     0,   816,    80,    81,    82,     0,
       0,     0,     0,    40,     0,   817,   818,   819,     0,     0,
       0,     0,     0,     0,   820,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
     795,    41,    42,    43,     0,   796,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,    41,
      42,   797,     0,    44,     0,     0,     0,     0,    45,     0,
       0,  1781,  1782,     0,  1783,     0,   345,     0,     0,  1784,
    1785,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,    44,     0,     0,     0,     0,    45,     0,     0,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,    46,     0,     0,     0,    54,    47,     0,    48,     0,
       0,     0,     0,     0,     0,   798,     0,     0,    49,     0,
     799,     0,    50,    55,   800,    51,    52,     0,    53,     0,
       0,     0,     0,    54,     0,   801,     0,     0,     0,    56,
       0,   802,    57,    58,     0,     0,     0,     0,     0,    59,
       0,   803,     0,     0,     0,     0,   804,     0,     0,  1058,
      60,     0,   806,     0,     0,     0,     0,    56,     0,     0,
      57,   807,     0,     0,     0,    61,     0,    59,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,    60,    63,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      62,     0,   808,    69,     0,     0,   809,    63,     0,     0,
      64,    65,    66,     0,   810,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   811,     0,    70,    71,    72,
      73,   812,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,    70,   813,    72,    73,     0,
      74,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,    75,    76,    40,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,  2119,    77,     0,     0,     0,     0,     0,
       0,     0,   814,     0,     0,     0,     0,     0,     0,   815,
       0,   816,    80,    81,    82,     0,     0,    41,    42,    43,
       0,   817,   818,   819,     0,     0,     0,     0,     0,     0,
     820,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     348,     0,    83,     0,     0,     0,     0,  1781,  1782,    44,
    1783,     0,   345,     0,    45,  1784,  1785,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      83,     0,     0,     0,    47,     0,    48,     0,     0,     0,
       0,     0,     0,   138,     0,     0,    49,     0,     0,     0,
      50,     0,  1786,    51,    52,     0,    53,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,  1787,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,  1788,     0,     0,  2120,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,  2121,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2377,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,     0,
    1791,     0,     0,     0,     0,    63,     0,     0,    64,    65,
      66,     0,  1792,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,  1793,    72,    73,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,  1794,    40,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,  1795,     0,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,  1796,
    1797,  2122,     0,     0,     0,     0,     0,     0,  1798,     0,
       0,     0,     0,    41,    42,    43,     0,     0,   348,     0,
       0,     0,     0,     0,     0,  1781,  1782,     0,  1783,     0,
     345,     0,     0,  1784,  1785,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,     0,    83,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   762,     0,     0,     0,    46,     0,     0,     0,     0,
      47,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    50,     0,  1786,    51,
      52,     0,    53,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,  1787,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
    1788,     0,     0,  2589,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,    57,    58,     0,     0,     0,     0,
       0,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,     0,  1791,     0,     0,     0,
       0,    63,     0,     0,    64,    65,    66,     0,  1792,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
    1793,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2590,     0,     0,  2119,    77,     0,
    1794,     0,     0,     0,     0,     0,    78,     0,     0,     0,
    2591,  2592,     0,  1795,     0,    79,    80,    81,    82,     0,
       0,    41,    42,    43,     0,  1796,  1797,     0,     0,     0,
       0,     0,     0,     0,  1798,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,     0,     0,
       0,  1781,  1782,    44,  1783,     0,   345,     0,    45,  1784,
    1785,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    83,     0,     0,     0,    47,     0,
      48,     0,     0,     0,     0,     0,     0,   762,     0,     0,
      49,     0,     0,     0,    50,     0,  1786,    51,    52,     0,
      53,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,  1787,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,  1788,     0,
       0,  2120,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,  2121,     0,     0,     0,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,     0,  1791,     0,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,  1792,    68,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,  1793,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
    1114,  1115,  1116,  1117,  1118,  1119,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,  1120,  1121,  1122,     0,
       0,     0,     0,     0,     0,     0,    77,     0,  1794,    40,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,  1795,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,  1796,  1797,  2122,     0,     0,     0,     0,
       0,     0,  1798,     0,     0,     0,     0,    41,    42,    43,
       0,     0,   348,     0,     0,     0,     0,     0,     0,  1781,
    1782,     0,  1783,     0,   345,     0,     0,  1784,  1785,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,    83,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   762,     0,     0,     0,    46,
       0,     0,     0,     0,    47,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
      50,     0,  1786,    51,    52,     0,    53,     0,     0,     0,
       0,    54,     0,     0,     0,  1123,     0,  1787,  1124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,  1788,     0,     0,  2589,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,    58,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2377,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,  2607,
    1791,     0,     0,     0,     0,    63,     0,     0,    64,    65,
      66,     0,  1792,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1125,     0,     0,     0,     0,     0,
       0,     0,     0,    70,  1793,    72,    73,     0,    74,  1126,
       0,     0,     0,  1127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,  1794,     0,     0,     0,     0,     0,
      78,     0,  1128,     0,     0,     0,     0,  1795,     0,    79,
      80,    81,    82,     0,     0,    41,    42,    43,     0,  1796,
    1797,     0,     0,     0,     0,     0,     0,     0,  1798,     0,
    1129,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,     0,     0,     0,     0,     0,     0,    44,  1130,     0,
       0,     0,    45,  1781,  1782,     0,  1783,     0,   345,     0,
       0,  1784,  1785,     0,     0,     0,     0,    46,    83,     0,
       0,     0,    47,     0,    48,     0,     0,     0,     0,     0,
       0,   762,     0,     0,    49,     0,     0,     0,    50,     0,
    1786,    51,    52,     0,    53,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,  1787,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,  1788,     0,     0,  1789,     0,     0,     0,     0,
    1131,     0,     0,    56,     0,     0,    57,    58,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,    62,  1790,  1791,     0,
       0,     0,     0,    63,     0,     0,    64,    65,    66,     0,
    1792,    68,     0,     0,     0,     0,     0,     0,  1132,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,  1793,    72,    73,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,  1794,     0,     0,     0,     0,     0,    78,     0,
       0,    40,     0,     0,     0,  1795,     0,    79,    80,    81,
      82,     0,     0,     0,     0,  2119,     0,  1796,  1797,     0,
       0,     0,     0,     0,     0,     0,  1798,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   348,     0,     0,    41,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1781,  1782,     0,  1783,     0,   345,     0,     0,  1784,
    1785,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,    44,     0,     0,     0,     0,    45,     0,     0,   762,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,    47,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,    50,     0,  1786,    51,    52,     0,    53,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,  1787,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,  1788,     0,     0,  2120,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      57,  2121,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      62,     0,  1791,     0,     0,     0,     0,    63,     0,     0,
      64,    65,    66,     0,  1792,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,  1793,    72,    73,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,  1794,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,  1795,
       0,    79,    80,    81,    82,     0,     0,    41,    42,    43,
       0,  1796,  1797,     0,     0,     0,     0,     0,     0,     0,
    1798,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     348,     0,     0,     0,     0,     0,     0,  1781,  1782,    44,
    1783,     0,   345,     0,    45,  1784,  1785,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      83,     0,     0,     0,    47,     0,    48,     0,     0,     0,
       0,     0,     0,   762,     0,     0,    49,     0,     0,     0,
      50,     0,  1786,    51,    52,     0,    53,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,  1787,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,  1788,     0,     0,  2606,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,    58,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,  2607,
    1791,     0,     0,     0,     0,    63,     0,     0,    64,    65,
      66,     0,  1792,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,  1793,    72,    73,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,  1794,    40,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,  1795,     0,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,  1796,
    1797,     0,     0,     0,     0,     0,     0,     0,  1798,     0,
       0,     0,     0,    41,    42,    43,     0,     0,   348,     0,
       0,     0,     0,     0,     0,  1781,  1782,     0,  1783,     0,
     345,     0,     0,  1784,  1785,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,     0,    83,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   762,     0,     0,     0,    46,     0,     0,     0,     0,
      47,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    50,     0,  1786,    51,
      52,     0,    53,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,  1787,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
    1788,     0,     0,  2589,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,    57,    58,     0,     0,     0,     0,
       0,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,  2607,  1791,     0,     0,     0,
       0,    63,     0,     0,    64,    65,    66,     0,  1792,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
    1793,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
    1794,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,  1795,     0,    79,    80,    81,    82,     0,
       0,    41,    42,    43,     0,  1796,  1797,     0,     0,     0,
       0,     0,     0,     0,  1798,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,     0,     0,
       0,  1781,  1782,    44,  1783,     0,   345,     0,    45,  1784,
    1785,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    83,     0,     0,     0,    47,     0,
      48,     0,     0,     0,     0,     0,     0,   762,     0,     0,
      49,     0,     0,     0,    50,     0,  1786,    51,    52,     0,
      53,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,  1787,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,  1788,     0,
       0,  1789,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,     0,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2377,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,     0,  1791,     0,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,  1792,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,  1793,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,  1794,    40,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,  1795,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,  1796,  1797,     0,     0,     0,     0,     0,
       0,     0,  1798,     0,     0,     0,     0,    41,    42,    43,
       0,     0,   348,     0,     0,     0,     0,     0,     0,  1781,
    1782,     0,  1783,     0,   345,     0,     0,  1784,  1785,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,    83,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   762,     0,     0,     0,    46,
       0,     0,     0,     0,    47,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
      50,     0,  1786,    51,    52,     0,    53,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,  1787,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,  1788,     0,     0,  1789,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,    58,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,  2845,
    1791,     0,     0,     0,     0,    63,     0,     0,    64,    65,
      66,     0,  1792,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,  1793,    72,    73,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,  1794,     0,     0,   196,   197,     0,
      78,     0,     0,     0,     0,     0,   198,  1795,     0,    79,
      80,    81,    82,     0,     0,    41,    42,    43,     0,  1796,
    1797,     0,     0,     0,     0,     0,     0,     0,  1798,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    83,     0,
       0,     0,    47,     0,    48,     0,     0,     0,     0,     0,
       0,   762,     0,     0,    49,     0,     0,     0,    50,     0,
    1786,    51,    52,     0,    53,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,  1787,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,  1788,     0,     0,  1789,     0,     0,     0,     0,
    1461,     0,     0,    56,     0,     0,    57,    58,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,    62,     0,  1791,     0,
       0,     0,     0,    63,     0,     0,    64,    65,    66,     0,
    1792,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,    70,  1793,    72,    73,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,    43,     0,     0,     0,     0,
      77,     0,  1794,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,  1795,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    44,     0,  1796,  1797,     0,
      45,     0,     0,     0,     0,     0,  1798,     0,     0,     0,
       0,     0,     0,     0,     0,    46,   348,     0,     0,     0,
      47,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    50,     0,     0,    51,
      52,     0,    53,     0,     0,     0,    83,    54,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,   762,
     345,     0,     0,   989,   990,    55,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,    57,    58,     0,     0,     0,     0,
       0,    59,     0,    41,    42,    43,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,    44,     0,     0,     0,     0,
      45,    63,     0,     0,    64,    65,    66,     0,    67,    68,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
      47,     0,    48,     0,     0,    69,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    50,     0,     0,    51,
      52,     0,    53,     0,     0,     0,     0,    54,     0,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,    57,    58,     0,     0,    77,     0,
       0,    59,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,    60,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    63,     0,     0,    64,    65,    66,     0,    67,    68,
       0,     0,   345,     0,     0,   989,   990,     0,     0,     0,
       0,     0,     0,    40,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,    41,    42,    43,     0,     0,     0,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,    44,     0,     0,    78,     0,    45,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,     0,   991,     0,     0,     0,     0,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1462,     0,     0,    56,
       0,     0,    57,    58,     0,     0,     0,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,   857,     0,     0,     0,   992,     0,    63,
       0,     0,    64,    65,    66,    40,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,    43,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,    44,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    46,     0,     0,     0,     0,
      47,     0,    48,    79,    80,    81,    82,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    50,     0,     0,    51,
      52,     0,    53,   940,     0,     0,     0,    54,     0,     0,
       0,     0,   348,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    83,     0,    57,    58,     0,     0,     0,     0,
       0,    59,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    63,     0,    40,    64,    65,    66,     0,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,    43,     0,     0,     0,     0,     0,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    44,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,    46,     0,     0,    78,     0,    47,     0,
      48,     0,     0,     0,     0,    79,    80,    81,    82,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,   940,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,    40,   348,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,    83,     0,     0,     0,     0,    59,
       0,    41,    42,    43,     0,     0,     0,   138,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,    44,     0,     0,     0,     0,    45,    63,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,   193,     0,     0,     0,    54,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    77,     0,     0,    59,
       0,     0,     0,     0,    78,     0,     0,     0,   858,     0,
      60,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,  1860,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    63,
       0,    40,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,    41,
      42,    43,     0,     0,     0,   138,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,    44,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,    46,     0,     0,    78,     0,    47,     0,    48,     0,
       0,     0,     0,    79,    80,    81,    82,     0,    49,     0,
       0,     0,    50,     0,     0,    51,    52,     0,    53,   761,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      57,    58,    83,     0,     0,     0,     0,    59,     0,    41,
      42,    43,     0,     0,     0,   138,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      62,    44,     0,     0,     0,     0,    45,    63,     0,     0,
      64,    65,    66,     0,    67,    68,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,    47,     0,    48,     0,
       0,    69,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,    50,     0,     0,    51,    52,     0,    53,   940,
       0,     0,     0,    54,     0,    70,    71,    72,    73,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      57,    58,     0,     0,    77,     0,  1979,    59,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,    60,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    63,     0,    40,
      64,    65,    66,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,    41,    42,    43,
       0,     0,     0,   138,     0,    70,    71,    72,    73,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    44,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,    46,
       0,     0,    78,     0,    47,     0,    48,     0,     0,     0,
       0,    79,    80,    81,    82,     0,    49,     0,     0,     0,
      50,     0,     0,    51,    52,     0,    53,   135,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,    58,
      83,     0,     0,     0,     0,    59,     0,    41,    42,    43,
       0,     0,     0,   138,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,    44,
       0,     0,     0,     0,    45,    63,     0,     0,    64,    65,
      66,     0,    67,    68,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,    47,     0,    48,     0,     0,    69,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
      50,     0,     0,    51,    52,     0,    53,  1262,     0,     0,
       0,    54,     0,    70,    71,    72,    73,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,    58,
       0,     0,    77,     0,     0,    59,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,    60,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,    63,     0,    40,    64,    65,
      66,     0,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,    41,    42,    43,     0,     0,
       0,   762,     0,    70,    71,    72,    73,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    44,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,    46,     0,     0,
      78,     0,    47,     0,    48,     0,     0,     0,     0,    79,
      80,    81,    82,     0,    49,     0,     0,     0,    50,     0,
       0,    51,    52,     0,    53,  1300,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,    57,    58,    83,     0,
       0,     0,     0,    59,     0,    41,    42,    43,     0,     0,
       0,   138,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,    62,    44,     0,     0,
       0,     0,    45,    63,     0,     0,    64,    65,    66,     0,
      67,    68,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,    47,     0,    48,     0,     0,    69,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,    50,     0,
       0,    51,    52,     0,    53,  1438,     0,     0,     0,    54,
       0,    70,    71,    72,    73,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,    57,    58,     0,     0,
      77,     0,     0,    59,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,    60,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    63,     0,    40,    64,    65,    66,     0,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,    41,    42,    43,     0,     0,     0,   138,
       0,    70,    71,    72,    73,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,    44,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,    46,     0,     0,    78,     0,
      47,     0,    48,     0,     0,     0,     0,    79,    80,    81,
      82,     0,    49,     0,     0,     0,    50,     0,     0,    51,
      52,     0,    53,   934,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,    57,    58,    83,     0,     0,     0,
       0,    59,     0,    41,    42,    43,     0,     0,     0,   138,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,    44,     0,     0,     0,     0,
      45,    63,     0,     0,    64,    65,    66,     0,    67,    68,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
      47,     0,    48,     0,     0,    69,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    50,     0,     0,    51,
      52,     0,    53,  2467,     0,     0,     0,    54,     0,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,    57,    58,     0,     0,    77,     0,
       0,    59,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,    60,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    63,     0,    40,    64,    65,    66,     0,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,    41,    42,    43,     0,     0,     0,   138,     0,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    44,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,    46,     0,     0,    78,     0,    47,     0,
      48,     0,     0,     0,     0,    79,    80,    81,    82,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,  1190,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,    83,     0,     0,     0,     0,    59,
       0,    41,    42,    43,     0,     0,     0,   138,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,    44,     0,     0,     0,     0,    45,    63,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,  1084,     0,     0,    54,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    77,     0,     0,    59,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
      60,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    63,
       0,    40,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,    41,
      42,    43,     0,     0,     0,   138,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,    44,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,    46,     0,     0,    78,     0,    47,     0,    48,     0,
       0,     0,     0,    79,    80,    81,    82,     0,    49,     0,
       0,     0,    50,     0,     0,    51,    52,     0,    53,     0,
     774,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      57,    58,    83,     0,     0,     0,     0,    59,     0,    41,
      42,    43,     0,     0,     0,   138,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      62,    44,     0,     0,     0,     0,    45,    63,     0,     0,
      64,    65,    66,     0,    67,    68,     0,     0,     0,  1191,
       0,    46,     0,     0,     0,     0,    47,     0,    48,     0,
       0,    69,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,    50,     0,     0,    51,    52,     0,    53,     0,
    1398,     0,     0,    54,     0,    70,    71,    72,    73,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,  1192,     0,     0,     0,    75,    76,  1085,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      57,    58,     0,     0,    77,     0,     0,    59,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,    60,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    63,     0,    40,
      64,    65,    66,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,    41,    42,    43,
       0,     0,     0,   138,     0,    70,    71,    72,    73,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    44,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,    46,
       0,     0,    78,     0,    47,     0,    48,     0,     0,     0,
       0,    79,    80,    81,    82,     0,    49,     0,     0,     0,
      50,     0,     0,    51,    52,     0,    53,     0,  1747,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,    58,
      83,     0,     0,     0,     0,    59,     0,    41,    42,    43,
       0,     0,     0,   138,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,    44,
       0,     0,     0,     0,    45,    63,     0,     0,    64,    65,
      66,     0,    67,    68,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,    47,     0,    48,     0,     0,    69,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
      50,     0,     0,    51,    52,     0,    53,     0,     0,     0,
       0,    54,     0,    70,    71,    72,    73,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,    58,
       0,     0,    77,     0,     0,    59,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,    60,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,    63,     0,    40,    64,    65,
      66,     0,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,    41,    42,    43,     0,     0,
       0,   138,     0,    70,    71,    72,    73,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    44,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,    46,     0,     0,
      78,     0,    47,     0,    48,     0,     0,     0,     0,    79,
      80,    81,    82,     0,    49,     0,     0,     0,    50,     0,
       0,    51,    52,     0,    53,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,    57,    58,    83,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    63,     0,     0,    64,    65,    66,     0,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,     0,    74,     0,     0,     0,
       0,     1,     0,     0,     0,   510,     0,   511,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,     0,     0,
     512,     0,     0,     0,     0,     0,     0,     0,     0,   513,
      77,     0,     0,     0,     0,     0,     0,     0,    78,     0,
     514,   515,   516,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,     0,   517,     0,   518,   519,
     520,     2,     3,   521,     4,     5,   522,     0,   523,     6,
     524,   525,     0,     0,     0,     0,     0,   526,     0,     0,
     527,     0,   528,   529,   530,     0,     7,     8,     0,     0,
       0,     0,   531,     0,   532,   533,     0,   534,     0,   535,
     536,     0,     0,   537,     9,    10,    83,     0,   538,   539,
     540,     0,   541,   542,     0,     0,     0,   543,   544,   138,
     545,     0,     0,     0,   546,     0,   547,   548,     0,     0,
     549,     0,     0,     0,   550,     0,     0,   551,     0,   552,
       0,   553,     0,   554,     0,   555,   556,     0,   557,   558,
     559,     0,     0,     0,   560,     0,   561,   562,     0,   563,
       0,     0,     0,     0,     0,     0,     0,   564,   565,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     566,     0,     0,   567,   568,     0,     0,   569,   570,     0,
       0,   571,   572,     0,     0,     0,     0,     0,     0,     0,
     573,   574,   575,     0,   576,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   577,   578,   579,     0,   580,     0,
       0,     0,   581,   582,     0,     0,     0,   583,     0,     0,
       0,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,     0,     0,   585,     0,     0,     0,     0,     0,   586,
     587,     0,     0,     0,     0,   588,     0,     0,   589,     0,
       0,     0,   590,   591,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,     0,     0,     0,     0,     0,     0,     0,   594,     0,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,   596,     0,   597,   598,     0,
       0,     0,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   601,     0,     0,     0,
     602,     0,     0,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   604,   605,     0,
       0,     0,   606,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
     608,   609,   610,   611,     0,     0,   612,     0,     0,     0,
       0,   613,     0,     0,     0,     0,     0,     0,   614,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     616,     0,   617,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   618,     0,     0,   619,     0,     0,   620,
       0,     0,     0,     0,     0,   621,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   622,     0,     0,   623,     0,     0,     0,     0,
       0,   624,     0,     0,   625,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   626,     0,
       0,     0,     1,     0,     0,   627,   510,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   512,     0,   628,   629,   630,   631,   632,   633,   634,
     513,     0,   635,     0,   636,     0,   637, -1742,     0,     0,
       0,   514,   515,   516,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   517, -1636,   518,
     519,   520,     2,     3,   521,     4,     5,   522,     0,   523,
       6,   524,   525,     0,     0,     0,     0,     0,   526,     0,
       0,   527,     0,   528,   529,   530,     0,     7,     8,     0,
       0,     0,     0,   531,     0,   532,   533,     0,   534,     0,
     535,   536,     0,     0,   537,     9,    10,     0,     0,   538,
     539,   540,     0,   541,   542,     0,     0,     0,   543,   544,
       0,   545,     0,     0,     0,   546,     0,   547,   548,     0,
       0,   549,     0,     0,     0,   550,     0,     0,   551,     0,
     552,     0,   553,     0,   554,     0,   555,   556,     0,   557,
     558,   559,     0,     0,     0,   560,     0,   561,   562, -1636,
     563,     0,     0,     0,     0,     0,     0, -1636,   564,   565,
       0,     0,     0,     0, -1636,     0, -1636,     0,     0,     0,
       0,   566,     0,     0,   567,   568, -1636,     0,   569,   570,
       0,     0,   571,   572,     0,     0,     0,     0,     0,     0,
       0,   573,   574,   575,     0,   576,     0,     0,     0,     0,
       0,     0,     0,     0, -1636,   577,   578,   579,     0,   580,
       0,     0,     0,   581,   582,     0,     0,     0,   583,     0,
   -1636,     0,     0,     0,     0, -1636,   584,     0,     0,     0,
       0,     0,     0,     0,   585, -1636,     0,     0,     0,     0,
     586,   587, -1636,     0,     0,     0,   588,     0,     0,   589,
       0,     0,     0,   590,   591,     0,     0,     0,     0,     0,
       0, -1636,     0,     0,   592,     0,     0,     0,     0,     0,
       0, -1636,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   593,     0,     0,     0,     0,     0,     0,     0,   594,
       0,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
       0,     0,     0,     0, -1636,     0,   596,     0,   597,   598,
       0,     0,     0,     0,     0,     0,     0,   599,     0, -1636,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   600,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   601,     0,     0,
       0,   602,     0,     0,   603,     0, -1636,     0,     0,     0,
       0,     0,     0, -1636,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   604,   605,
       0,     0,     0,   606,     0, -1636,     0,     0, -1636,     0,
   -1636,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,   608,   609,   610,   611,     0,     0,   612,     0,     0,
       0,     0,   613,     0,     0,     0,     0,     0,     0,   614,
     615,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,     0,   617,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   618,     0,     0,   619,     0,     0,
     620,     0,     0,     0,     0,     0,   621,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   622,     0,     0,   623,     0,     0,     0,
       0,     0,   624,     0,     0,   625,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   626,
       0,     0,     0,     1,     0,     0,   627,   510,     0,   511,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   512,     0,   628,   629,   630,   631,   632,   633,
     634,   513,     0,   635,     0,   636,     0,   637,     0,     0,
       0,     0,   514,   515,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,     0,
     518,   519,   520,     2,     3,   521,     4,     5,   522,     0,
     523,     6,   524,   525,     0,     0,     0,     0,     0,   526,
       0,     0,   527,     0,   528,   529,   530,     0,     7,     8,
       0,     0,     0,     0,   531,     0,   532,   533,     0,   534,
       0,   535,   536,     0,     0,   537,     9,    10,     0,     0,
     538,   539,   540,     0,   541,   542,     0,     0,     0,   543,
     544,     0,   545,     0,     0,     0,   546,     0,   547,   548,
       0,     0,   549,     0,     0,     0,   550,     0,     0,   551,
       0,   552,     0,   553,     0,   554,     0,   555,   556,     0,
     557,   558,   559,     0,     0,     0,   560,     0,   561,   562,
       0,   563,     0,     0,     0,     0,     0,     0,     0,   564,
     565,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   566,     0,     0,   567,   568,     0,     0,   569,
     570,     0,     0,   571,   572,     0,     0,     0,     0,     0,
       0,     0,   573,   574,   575,     0,   576,     0,     0, -1742,
       0,     0, -1742,     0, -1742,     0,   577,   578,   579,     0,
     580,     0,     0,     0,   581,   582,     0,     0,     0,   583,
       0,     0,     0,     0, -1742,     0,     0,   584,     0,     0,
       0,     0,     0,     0, -1742,   585,     0,     0,     0,     0,
       0,   586,   587,     0,     0,     0,     0,   588,     0,     0,
     589, -1742,     0,     0,   590,   591,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0, -1742,     0,     0,     0, -1742,     0,     0,
       0,     0,   593,     0,     0,     0,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,     0,     0,   596,     0,   597,
     598,     0,     0,     0,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1742,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   601,     0,
       0,     0,   602,     0,     0,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1742,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   604,
     605,     0,     0,     0,   606,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,   608,   609,   610,   611,     0,     0,   612,     0,
       0,     0,     0,   613,     0,     0,     0,     0,     0,     0,
     614,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   616,     0,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   618,     0,     0,   619,     0,
       0,   620,     0,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   622,     0,     0,   623,     0,     0,
       0,     0,     0,   624,     0,     0,   625,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     626,     0,     0,     0,     1,     0,     0,   627,   510,     0,
     511,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,     0,   628,   629,   630,   631,   632,
     633,   634,   513,     0,   635,     0,   636, -1742,   637,     0,
       0,     0,     0,   514,   515,   516,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   517,
       0,   518,   519,   520,     2,     3,   521,     4,     5,   522,
       0,   523,     6,   524,   525, -1742,     0,     0,     0,     0,
     526,     0,     0,   527,     0,   528,   529,   530,     0,     7,
       8,     0,     0,     0,     0,   531,     0,   532,   533,     0,
     534,     0,   535,   536,     0,     0,   537,     9,    10,     0,
       0,   538,   539,   540,     0,   541,   542,     0,     0,     0,
     543,   544,     0,   545,     0,     0,     0,   546,     0,   547,
     548,     0,     0,   549,     0,     0,     0,   550,     0, -1742,
     551, -1742,   552,     0,   553,     0,   554,     0,   555,   556,
       0,   557,   558,   559,     0,     0, -1742,   560,     0,   561,
     562,     0,   563,     0, -1742,     0,     0,     0, -1742,     0,
     564,   565,     0,     0,     0,     0,     0,     0,     0,     0,
   -1742,     0,     0,   566,     0,     0,   567,   568,     0,     0,
     569,   570,     0, -1742,   571,   572,     0,     0,     0,     0,
       0,     0,     0,   573,   574,   575,     0,   576,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   577,   578,   579,
       0,   580,     0,     0,     0,   581,   582,     0,     0,     0,
     583,     0,     0,     0,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,   585,     0,     0,     0,
       0,     0,   586,   587,     0,     0,     0,     0,   588,     0,
       0,   589,     0,     0,     0,   590,   591,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   593,     0,     0,     0,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,     0,     0,   596,     0,
     597,   598,     0,     0,     0,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   600,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   601,
       0,     0,     0,   602,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     604,   605,     0,     0,     0,   606,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,   608,   609,   610,   611,     0,     0,   612,
       0,     0,     0,     0,   613,     0,     0,     0,     0,     0,
       0,   614,   615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,     0,   617,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   618,     0,     0,   619,
       0,     0,   620,     0,     0,     0,     0,     0,   621,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   622,     0,     0,   623,     0,
       0,     0,     0,     0,   624,     0,     0,   625,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   626,     0,     0,     0,     1,     0,     0,   627,   510,
       0,   511,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   512,     0,   628,   629,   630,   631,
     632,   633,   634,   513,     0,   635,     0,   636,     0,   637,
       0,     0,     0,     0,   514,   515,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     517,     0,   518,   519,   520,     2,     3,   521,     4,     5,
     522,     0,   523,     6,   524,   525,     0,     0,     0,     0,
       0,   526,     0,     0,   527,     0,   528,   529,   530,     0,
       7,     8,     0,     0,     0,     0,   531,     0,   532,   533,
       0,   534,     0,   535,   536,     0, -1742,   537,     9,    10,
   -1742,     0,   538,   539,   540,     0,   541,   542,     0,     0,
       0,   543,   544,     0,   545,     0,     0,     0,   546,     0,
     547,   548, -1742,     0,   549,     0,     0,     0,   550,     0,
       0,   551,     0,   552,     0,   553,     0,   554,     0,   555,
     556,     0,   557,   558,   559,     0,     0,     0,   560,     0,
     561,   562,     0,   563,     0,     0,     0,     0,     0,     0,
       0,   564,   565,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   566,     0,     0,   567,   568,     0,
       0,   569,   570,     0,     0,   571,   572,     0,     0,     0,
       0,     0,     0,     0,   573,   574,   575,     0,   576,     0,
       0, -1742,     0,     0, -1742,     0,     0,     0,   577,   578,
     579,     0,   580,     0,     0,     0,   581,   582,     0,     0,
       0,   583,     0,     0,     0,     0, -1742,     0,     0,   584,
       0,     0,     0,     0,     0,     0,     0,   585,     0,     0,
       0,     0,     0,   586,   587,     0,     0,     0,     0,   588,
       0,     0,   589,     0,     0,     0,   590,   591,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   592,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   593,     0,     0,     0,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,     0,     0,     0,     0,     0,     0,   596,
       0,   597,   598,     0,     0,     0,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   600,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     601,     0,     0,     0,   602,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,   605,     0,     0,     0,   606,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,   608,   609,   610,   611,     0,     0,
     612,     0,     0,     0,     0,   613,     0,     0,     0,     0,
       0,     0,   614,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,     0,   617,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   618,     0,     0,
     619,     0,     0,   620,     0,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   622,     0,     0,   623,
       0,     0,     0,     0,     0,   624,     0,     0,   625,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   626,     0,     0,     0,     1,     0,     0,   627,
     510,     0,   511,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   512,     0,   628,   629,   630,
     631,   632,   633,   634,   513, -1742,   635,     0,   636,     0,
     637,     0,     0,     0,     0,   514,   515,   516,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   517,     0,   518,   519,   520,     2,     3,   521,     4,
       5,   522,     0,   523,     6,   524,   525,     0,     0,     0,
       0,     0,   526,     0,     0,   527,     0,   528,   529,   530,
       0,     7,     8,     0,     0,     0,     0,   531,     0,   532,
     533,     0,   534,     0,   535,   536,     0,     0,   537,     9,
      10,     0,     0,   538,   539,   540,     0,   541,   542,     0,
       0,     0,   543,   544,     0,   545,     0,     0,     0,   546,
       0,   547,   548,     0,     0,   549,     0,     0,     0,   550,
       0,     0,   551,     0,   552,     0,   553,     0,   554,     0,
     555,   556,     0,   557,   558,   559,     0,     0,     0,   560,
       0,   561,   562,     0,   563,     0,     0,     0,     0,     0,
       0,     0,   564,   565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   566,     0,     0,   567,   568,
       0,     0,   569,   570,     0,     0,   571,   572,     0,     0,
       0,     0,     0,     0,     0,   573,   574,   575,     0,   576,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   577,
     578,   579,     0,   580,     0,     0,     0,   581,   582,     0,
       0,     0,   583,     0,     0,     0,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,     0,   585,     0,
       0,     0,     0,     0,   586,   587,     0,     0,     0,     0,
     588,     0,     0,   589,     0,     0,     0,   590,   591,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   593,     0,     0,     0,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,     0,     0,     0,     0,
     596,     0,   597,   598,     0,     0,     0,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     600,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   601,     0,     0,     0,   602,     0,     0,   603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   604,   605,     0,     0,     0,   606,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,   608,   609,   610,   611,     0,
       0,   612,     0,     0,     0,     0,   613,     0,     0,     0,
       0,     0,     0,   614,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,     0,   617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   618,     0,
       0,   619,     0,     0,   620,     0,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   622,     0,     0,
     623,     0,     0,     0,     0,     0,   624,     0,     0,   625,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   626,     0,     0,     0,     1,     0,     0,
     627,   510,     0,   511,     0, -1742, -1742, -1742, -1742, -1742,
       0,     0,     0,     0,     0,     0,   512,     0,   628,   629,
     630,   631,   632,   633,   634,   513,     0,   635,     0,   636,
       0,   637,     0,     0,     0,     0,   514,   515,   516,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   517,     0,   518,   519,   520,     2,     3,   521,
       4,     5,   522,     0,   523,     6,   524,   525,     0,     0,
       0,     0,     0,   526,     0,     0,   527,     0,   528,   529,
     530,     0,     7,     8,     0,     0,     0,     0,   531,     0,
     532,   533,     0,   534,     0,   535,   536,     0,     0,   537,
       9,    10,     0,     0,   538,   539,   540,     0,   541,   542,
       0,     0,     0,   543,   544,     0,   545,     0,     0,     0,
     546,     0,   547,   548,     0,     0,   549,     0,     0,     0,
     550,     0,     0,   551,     0,   552,     0,   553,     0,   554,
       0,   555,   556,     0,   557,   558,   559,     0,     0,     0,
     560,     0,   561,   562,     0,   563,     0,     0,     0,     0,
       0,     0,     0,   564,   565,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   566,     0,     0,   567,
     568,     0,     0,   569,   570,     0,     0,   571,   572,     0,
       0,     0,     0,     0,     0,     0,   573,   574,   575,     0,
     576,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     577,   578,   579,     0,   580,     0,     0,     0,   581,   582,
       0,     0,     0,   583,     0,     0,     0,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,     0,     0,   585,
       0,     0,     0,     0,     0,   586,   587,     0,     0,     0,
       0,   588,     0,     0,   589, -1742,     0,     0,   590,   591,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   593,     0,     0,     0,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
       0,   596,     0,   597,   598,     0,     0,     0,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   600,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   601,     0,     0,     0,   602,     0,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1742,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   604,   605,     0,     0,     0,   606,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,   608,   609,   610,   611,
       0,     0,   612,     0,     0,     0,     0,   613,     0,     0,
       0,     0,     0,     0,   614,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,     0,   617,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   618,
       0,     0,   619,     0,     0,   620,     0,     0,     0,     0,
       0,   621,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   622,     0,
       0,   623,     0,     0,     0,     0,     0,   624,     0,     0,
     625,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   626,     0,     0, -1742,     1,     0,
       0,   627,   510,     0,   511,     0,     0,     0,     0,     0,
       0, -1742, -1742,     0,     0,     0,     0,   512,     0,   628,
     629,   630,   631,   632,   633,   634,   513,     0,   635,     0,
     636, -1742,   637,     0,     0,     0,     0,   514,   515,   516,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   517,     0,   518,   519,   520,     2,     3,
     521,     4,     5,   522,     0,   523,     6,   524,   525,     0,
       0,     0,     0,     0,   526,     0,     0,   527,     0,   528,
     529,   530,     0,     7,     8,     0,     0,     0,     0,   531,
       0,   532,   533,     0,   534,     0,   535,   536,     0,     0,
     537,     9,    10,     0,     0,   538,   539,   540,     0,   541,
     542,     0,     0,     0,   543,   544,     0,   545,     0,     0,
       0,   546,     0,   547,   548,     0,     0,   549,     0,     0,
       0,   550,     0,     0,   551,     0,   552,     0,   553,     0,
     554,     0,   555,   556,     0,   557,   558,   559,     0,     0,
       0,   560,     0,   561,   562,     0,   563,     0,     0,     0,
       0,     0,     0,     0,   564,   565,     0,     0,     0,     0,
       0,     0,     0, -1742,     0,     0,     0,   566,     0,     0,
     567,   568,     0,     0,   569,   570,     0,     0,   571,   572,
       0,     0,     0,     0,     0,     0,     0,   573,   574,   575,
       0,   576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   577,   578,   579,     0,   580,     0,     0,     0,   581,
     582,     0,     0,     0,   583,     0,     0,     0,     0, -1742,
       0,     0,   584,     0,     0,     0,     0,     0,     0,     0,
     585,     0,     0,     0,     0,     0,   586,   587,     0,     0,
       0,     0,   588,     0,     0,   589,     0,     0,     0,   590,
     591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,     0,     0, -1742,     0,
       0,     0, -1742,     0,     0,     0,     0,   593,     0,     0,
       0,     0,     0,     0,     0,   594,     0,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,   596,     0,   597,   598,     0,     0,     0,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1742,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   601,     0,     0,     0,   602,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   604,   605,     0,     0,     0,   606,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,   608,   609,   610,
     611,     0,     0,   612,     0,     0,     0,     0,   613,     0,
       0,     0,     0,     0,     0,   614,   615,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,     0,   617,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     618,     0,     0,   619,     0,     0,   620,     0,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   622,
       0,     0,   623,     0,     0,     0,     0,     0,   624,     0,
       0,   625,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   626,     0,     0,     0,     1,
       0,     0,   627,   510,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   512,     0,
     628,   629,   630,   631,   632,   633,   634,   513,     0,   635,
       0,   636,     0,   637,     0,     0,     0,     0,   514,   515,
     516,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   517,     0,   518,   519,   520,     2,
       3,   521,     4,     5,   522,     0,   523,     6,   524,   525,
       0,     0,     0,     0,     0,   526,     0,     0,   527,     0,
     528,   529,   530,     0,     7,     8,     0,     0,     0,     0,
     531,     0,   532,   533,     0,   534,     0,   535,   536,     0,
       0,   537,     9,    10,     0,     0,   538,   539,   540,     0,
     541,   542,     0,     0,     0,   543,   544,     0,   545,     0,
       0,     0,   546,     0,   547,   548,     0,     0,   549,     0,
       0,     0,   550,     0,     0,   551,     0,   552,     0,   553,
       0,   554,     0,   555,   556,     0,   557,   558,   559,     0,
       0,     0,   560,     0,   561,   562,     0,   563,     0,     0,
       0,     0,     0,     0,     0,   564,   565,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   566,     0,
       0,   567,   568,     0,     0,   569,   570,     0,     0,   571,
     572,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,     0,   576,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   577,   578,   579,     0,   580,     0,     0,     0,
     581,   582,     0,     0,     0,   583,     0,     0,     0,     0,
       0,     0,     0,   584,     0,     0,     0,     0,     0,     0,
       0,   585,     0,     0,     0,     0,     0,   586,   587,     0,
       0,     0,     0,   588,     0,     0,   589,     0,     0,     0,
     590,   591,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   592,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   593,     0,
       0,     0,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,   596,     0,   597,   598,     0,     0,     0,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   600,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   601,     0,     0,     0,   602,     0,
       0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   604,   605,     0,     0,     0,
     606,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,   608,   609,
     610,   611,     0,     0,   612,     0,     0,     0,     0,   613,
       0,     0,     0,     0,     0,     0,   614,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,     0,
     617,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   618,     0,     0,   619,     0,     0,   620,     0,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     622,     0,     0,   623,     0,     0,     0,     0,     0,   624,
       0,     0,   625,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,     0,     0, -1742,
       1,     0,     0,   627,   510,     0,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1742, -1742,     0,   512,
       0,   628,   629,   630,   631,   632,   633,   634,   513,     0,
     635,     0,   636,     0,   637,     0,     0,     0,     0,   514,
     515,   516,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   517,     0,   518,   519,   520,
       2,     3,   521,     4,     5,   522,     0,   523,     6,   524,
     525,     0,     0,     0,     0,     0,   526,     0,     0,   527,
       0,   528,   529,   530,     0,     7,     8,     0,     0,     0,
       0,   531,     0,   532,   533,     0,   534,     0,   535,   536,
       0,     0,   537,     9,    10,     0,     0,   538,   539,   540,
       0,   541,   542,     0,     0,     0,   543,   544,     0,   545,
       0,     0,     0,   546,     0,   547,   548,     0,     0,   549,
       0,     0,     0,   550,     0,     0,   551,     0,   552,     0,
     553,     0,   554,     0,   555,   556,     0,   557,   558,   559,
       0,     0,     0,   560,     0,   561,   562,     0,   563,     0,
       0,     0,     0,     0,     0,     0,   564,   565,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
       0,     0,   567,   568,     0,     0,   569,   570,     0,     0,
     571,   572,     0,     0,     0,     0,     0,     0,     0,   573,
     574,   575,     0,   576,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   577,   578,   579,     0,   580,     0,     0,
       0,   581,   582,     0,     0,     0,   583,     0,     0,     0,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,   585,     0,     0,     0,     0,     0,   586,   587,
       0,     0,     0,     0,   588,     0,     0,   589,     0,     0,
       0,   590,   591,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   592, -1742,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   593,
       0,     0,     0, -1742,     0,     0,     0,   594,     0,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   306,     0,     0,
       0,     0,     0,     0,   596,     0,   597,   598,     0,     0,
       0,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   600,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   601,     0,     0,     0,   602,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   604,   605,     0,     0,
       0,   606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,   608,
     609,   610,   611,     0,     0,   612,     0,     0,     0,     0,
     613,     0,     0,     0,     0,     0,     0,   614,   615,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
       0,   617,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   618,     0,     0,   619,     0,     0,   620,     0,
       0,     0,     0,     0,   621,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -1742,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   622,     0,     0,   623,     0,     0,     0,     0,     0,
     624,     0,     0,   625,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   626,     0,     0,
       0,     1,     0,     0,   627,   510,     0,   511,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     512,     0,   628,   629,   630,   631,   632,   633,   634,   513,
       0,   635,     0,   636,     0,   637,     0,     0,     0,     0,
     514,   515,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   517,     0,   518,   519,
     520,     2,     3,   521,     4,     5,   522,     0,   523,     6,
     524,   525,     0,     0,     0,     0,     0,   526,     0,     0,
     527,     0,   528,   529,   530,     0,     7,     8,     0,     0,
       0,     0,   531,     0,   532,   533,     0,   534,     0,   535,
     536,     0,     0,   537,     9,    10,     0,     0,   538,   539,
     540,     0,   541,   542,     0,     0,     0,   543,   544,     0,
     545,     0,     0,     0,   546,     0,   547,   548,     0,     0,
     549,     0,     0,     0,   550,     0,     0,   551,     0,   552,
       0,   553,     0,   554,     0,   555,   556,     0,   557,   558,
     559,     0,     0,     0,   560,     0,   561,   562,     0,   563,
       0,     0,     0,     0,     0,     0,     0,   564,   565,     0,
       0,     0, -1742,     0,     0,     0,     0,     0,     0,     0,
     566,     0,     0,   567,   568,     0,     0,   569,   570,     0,
       0,   571,   572,     0,     0,     0,     0,     0,     0,     0,
     573,   574,   575,     0,   576,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   577,   578,   579,     0,   580,     0,
       0,     0,   581,   582,     0,     0,     0,   583,     0,     0,
       0,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,     0,     0,   585,     0,     0,     0,     0,     0,   586,
     587,     0,     0,     0,     0,   588,     0,     0,   589,     0,
       0,     0,   590,   591,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,     0,     0,     0,     0,     0, -1742,     0,   594,     0,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1742,   306,     0,
       0,     0,     0,     0,     0,   596,     0,   597,   598,     0,
       0,     0,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   601,     0,     0,     0,
     602,     0,     0,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   604,   605,     0,
       0,     0,   606,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
     608,   609,   610,   611,     0,     0,   612,     0,     0,     0,
       0,   613,     0,     0,     0,     0,     0,     0,   614,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     616,     0,   617,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   618,     0,     0,   619,     0,     0,   620,
       0,     0,     0,     0,     0,   621,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   622,     0,     0,   623,     0,     0,     0,     0,
       0,   624,     0,     0,   625,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   626,     0,
       0,     0,     1,     0,     0,   627,   510,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   512,     0,   628,   629,   630,   631,   632,   633,   634,
     513,     0,   635,     0,   636,     0,   637,     0,     0,     0,
       0,   514,   515,   516,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   517,     0,   518,
     519,   520,     2,     3,   521,     4,     5,   522,     0,   523,
       6,   524,   525,     0,     0,     0,     0,     0,   526,     0,
       0,   527,     0,   528,   529,   530,     0,     7,     8,     0,
       0,     0,     0,   531,     0,   532,   533,     0,   534,     0,
     535,   536,     0,     0,   537,     9,    10,     0,     0,   538,
     539,   540,     0,   541,   542,     0,     0,     0,   543,   544,
       0,   545,     0,     0,     0,   546,     0,   547,   548,     0,
       0,   549,     0,     0,     0,   550,     0,     0,   551,     0,
     552,     0,   553,     0,   554,     0,   555,   556,     0,   557,
     558,   559,     0,     0,     0,   560,     0,   561,   562,     0,
     563,     0,     0,     0,     0,     0,     0,     0,   564,   565,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   566,     0,     0,   567,   568,     0,     0,   569,   570,
       0,     0,   571,   572,     0,     0,     0,     0,     0,     0,
       0,   573,   574,   575,     0,   576,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   577,   578,   579,     0,   580,
       0,     0,     0,   581,   582,     0,     0,     0,   583,     0,
       0,     0,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,     0,   585,     0,     0,     0,     0,     0,
     586,   587,     0,     0,     0,     0,   588,     0,     0,   589,
       0,     0,     0,   590,   591,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   593,     0,     0,     0,     0,     0,     0,     0,   594,
       0,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
       0,     0,     0,     0,     0,     0,   596,     0,   597,   598,
       0,     0,     0,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   600,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   601,     0,     0,
       0,   602,     0,     0,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   604,   605,
       0,     0,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,   608,   609,   610,   611,     0,     0,   612,     0,     0,
       0,     0,   613,     0,     0,     0,     0,     0,     0,   614,
     615,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,     0,   617,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   618,     0,     0,   619,     0,     0,
     620,     0,     0,     0,     0,     0,   621,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   622,     0,     0,   623,     0,     0,     0,
       0,     0,   624,     0,     0,   625,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   626,
       0,     0,     0,     1,     0,     0,   627,   510,     0,   511,
       0, -1742,     0,     0, -1742, -1742,     0,     0,     0,     0,
       0,     0,   512,     0,   628,   629,   630,   631,   632,   633,
     634,   513,     0,   635,     0,   636,     0,   637,     0,     0,
       0,     0,   514,   515,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,     0,
     518,   519,   520,     2,     3,   521,     4,     5,   522,     0,
     523,     6,   524,   525,     0,     0,     0,     0,     0,   526,
       0,     0,   527,     0,   528,   529,   530,     0,     7,     8,
       0,     0,     0,     0,   531,     0,   532,   533,     0,   534,
       0,   535,   536,     0,     0,   537,     9,    10,     0,     0,
     538,   539,   540,     0,   541,   542,     0,     0,     0,   543,
     544,     0,   545,     0,     0,     0,   546,     0,   547,   548,
       0,     0,   549,     0,     0,     0,   550,     0,     0,   551,
       0,   552,     0,   553,     0,   554,     0,   555,   556,     0,
     557,   558,   559,     0,     0,     0,   560,     0,   561,   562,
       0,   563,     0,     0,     0,     0,     0,     0,     0,   564,
     565,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   566,     0,     0,   567,   568,     0,     0,   569,
     570,     0,     0,   571,   572,     0,     0,     0,     0,     0,
       0,     0,   573,   574,   575,     0,   576,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   577,   578,   579,     0,
     580, -1742,     0,     0,   581,   582,     0,     0,     0,   583,
       0,     0,     0,     0, -1742,     0,     0,   584,     0,     0,
       0,     0,     0,     0,     0,   585,     0,     0,     0,     0,
       0,   586,   587,     0,     0,     0,     0,   588,     0,     0,
     589,     0,     0,     0,   590,   591,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   593,     0,     0,     0,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,     0,     0,   596,     0,   597,
     598,     0,     0,     0,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1742,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   601,     0,
       0,     0,   602,     0,     0,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   604,
     605,     0,     0,     0,   606,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,   608,   609,   610,   611,     0,     0,   612,     0,
       0,     0,     0,   613,     0,     0,     0,     0,     0,     0,
     614,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   616,     0,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   618,     0,     0,   619,     0,
       0,   620,     0,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   622,     0,     0,   623,     0,     0,
       0,     0,     0,   624,     0,     0,   625,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     626,     0,     0,     0,     1,     0,     0,   627,   510,     0,
     511,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,     0,   628,   629,   630,   631,   632,
     633,   634,   513,     0,   635,     0,   636,     0,   637,     0,
       0,     0,     0,   514,   515,   516,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   517,
       0,   518,   519,   520,     2,     3,   521,     4,     5,   522,
       0,   523,     6,   524,   525,     0,     0,     0,     0,     0,
     526,     0,     0,   527,     0,   528,   529,   530,     0,     7,
       8,     0,     0,     0,     0,   531,     0,   532,   533,     0,
     534,     0,   535,   536,     0,     0,   537,     9,    10,     0,
       0,   538,   539,   540,     0,   541,   542,     0,     0,     0,
     543,   544,     0,   545,     0,     0,     0,   546,     0,   547,
     548,     0,     0,   549,     0,     0,     0,   550,     0,     0,
     551,     0,   552,     0,   553,     0,   554,     0,   555,   556,
       0,   557,   558,   559,     0,     0,     0,   560,     0,   561,
     562,     0,   563,     0,     0,     0,     0,     0,     0,     0,
     564,   565,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   566,     0,     0,   567,   568,     0,     0,
     569,   570,     0,     0,   571,   572,     0,     0,     0,     0,
       0,     0,     0,   573,   574,   575,     0,   576,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   577,   578,   579,
       0,   580,     0,     0,     0,   581,   582,     0,     0,     0,
     583,     0,     0,     0,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,   585,     0,     0,     0,
       0,     0,   586,   587,     0,     0,     0,     0,   588,     0,
       0,   589,     0,     0,     0,   590,   591,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   593,     0,     0,     0,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,     0,     0,   596,     0,
     597,   598,     0,     0,     0,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   600,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   601,
       0,     0,     0,   602,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     604,   605,     0,     0,     0,   606,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,   608,   609,   610,   611,     0,     0,   612,
       0,     0,     0,     0,   613,     0,     0,     0,     0,     0,
       0,   614,   615,     0,     0,     0,     0,     0,     0,     0,
   -1742,     0,     0,   616,     0,   617,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   618,     0,     0,   619,
       0,     0,   620,     0,     0,     0,     0,     0,   621,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   622,     0,     0,   623,     0,
       0,     0,     0,     0,   624,     0,     0,   625,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   626,     0,     0,     0,     1,     0,     0,   627,   510,
       0,   511,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   512,     0,   628,   629,   630,   631,
     632,   633,   634,   513,     0,   635,     0,   636,     0,   637,
       0,     0,     0,     0,   514,   515,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     517,     0,   518,   519,   520,     2,     3,   521,     4,     5,
     522,     0,   523,     6,   524,   525,     0,     0,     0,     0,
       0,   526,     0,     0,   527,     0,   528,   529,   530,     0,
       7,     8,     0,     0,     0,     0,   531,     0,   532,   533,
       0,   534,     0,   535,   536,     0,     0,   537,     9,    10,
       0,     0,   538,   539,   540,     0,   541,   542,     0,     0,
       0,   543,   544,     0,   545,     0,     0,     0,   546,     0,
     547,   548,     0,     0,   549,     0,     0,     0,   550,     0,
       0,   551,     0,   552,     0,   553,     0,   554,     0,   555,
     556,     0,   557,   558,   559,     0,     0,     0,   560,     0,
     561,   562,     0,   563,     0,     0,     0,     0,     0,     0,
       0,   564,   565,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   566,     0,     0,   567,   568,     0,
       0,   569,   570,     0,     0,   571,   572,     0,     0,     0,
       0,     0,     0,     0,   573,   574,   575,     0,   576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   577,   578,
     579,     0,   580,     0,     0,     0,   581,   582,     0,     0,
       0,   583,     0,     0,     0,     0,     0,     0,     0,   584,
       0,     0,     0,     0,     0,     0,     0,   585,     0,     0,
       0,     0,     0,   586,   587,     0,     0,     0,     0,   588,
       0,     0,   589,     0,     0,     0,   590,   591,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   592,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   593,     0,     0,     0,     0, -1742,
       0,     0,   594,     0,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,     0,     0,     0,     0,     0,     0,   596,
       0,   597,   598,     0,     0,     0,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   600,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     601,     0,     0,     0,   602,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,   605,     0,     0,     0,   606,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,   608,   609,   610,   611,     0,     0,
     612,     0,     0,     0,     0,   613,     0,     0,     0,     0,
       0,     0,   614,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,     0,   617,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   618,     0,     0,
     619,     0,     0,   620,     0,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   622,     0,     0,   623,
       0,     0,     0,     0,     0,   624,     0,     0,   625,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   626,     0,     0,     0,     1,     0,     0,   627,
     510,     0,   511,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   512,     0,   628,   629,   630,
     631,   632,   633,   634,   513,     0,   635,     0,   636,     0,
     637,     0,     0,     0,     0,   514,   515,   516,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   517,     0,   518,   519,   520,     2,     3,   521,     4,
       5,   522,     0,   523,     6,   524,   525,     0,     0,     0,
       0,     0,   526,     0,     0,   527,     0,   528,   529,   530,
       0,     7,     8,     0,     0,     0,     0,   531,     0,   532,
     533,     0,   534,     0,   535,   536,     0,     0,   537,     9,
      10,     0,     0,   538,   539,   540,     0,   541,   542,     0,
       0,     0,   543,   544,     0,   545,     0,     0,     0,   546,
       0,   547,   548,     0,     0,   549,     0,     0,     0,   550,
       0,     0,   551,     0,   552,     0,   553,     0,   554,     0,
     555,   556,     0,   557,   558,   559,     0,     0,     0,   560,
       0,   561,   562,     0,   563,     0,     0,     0,     0,     0,
       0,     0,   564,   565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   566,     0,     0,   567,   568,
       0,     0,   569,   570,     0,     0,   571,   572,     0,     0,
       0,     0,     0,     0,     0,   573,   574,   575,     0,   576,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   577,
     578,   579,     0,   580,     0,     0,     0,   581,   582,     0,
       0,     0,   583,     0,     0,     0,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,     0,   585,     0,
       0,     0,     0,     0,   586,   587,     0,     0,     0,     0,
     588,     0,     0,   589,     0, -1742,     0,   590,   591,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   593,     0,     0,     0,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,     0,     0,     0,     0,
     596,     0,   597,   598,     0,     0,     0,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     600,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   601,     0,     0,     0,   602,     0,     0,   603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   604,   605,     0,     0,     0,   606,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,   608,   609,   610,   611,     0,
       0,   612,     0,     0,     0,     0,   613,     0,     0,     0,
       0,     0,     0,   614,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,     0,   617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   618,     0,
       0,   619,     0,     0,   620,     0,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   622,     0,     0,
     623,     0,     0,     0,     0,     0,   624,     0,     0,   625,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   626,     0,     0,     0,     1,     0,     0,
     627,   510,     0,   511,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,     0,   628,   629,
     630,   631,   632,   633,   634,   513,     0,   635,     0,   636,
       0,   637,     0,     0,     0,     0,   514,   515,   516,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   517,     0,   518,   519,   520,     2,     3,   521,
       4,     5,   522,     0,   523,     6,   524,   525,     0,     0,
       0,     0,     0,   526,     0,     0,   527,     0,   528,   529,
     530,     0,     7,     8,     0,     0,     0,     0,   531,     0,
     532,   533,     0,   534,     0,   535,   536,     0,     0,   537,
       9,    10,     0,     0,   538,   539,   540,     0,   541,   542,
       0,     0,     0,   543,   544,     0,   545,     0,     0,     0,
     546,     0,   547,   548,     0,     0,   549,     0,     0,     0,
     550,     0,     0,   551,     0,   552,     0,   553,     0,   554,
       0,   555,   556,     0,   557,   558,   559,     0,     0,     0,
     560,     0,   561,   562,     0,   563,     0,     0,     0,     0,
       0,     0,     0,   564,   565,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   566,     0,     0,   567,
     568,     0,     0,   569,   570,     0,     0,   571,   572,     0,
       0,     0,     0,     0,     0,     0,   573,   574,   575,     0,
     576,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     577,   578,   579,     0,   580,     0,     0,     0,   581,   582,
       0,     0,     0,   583,     0,     0,     0,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,     0,     0,   585,
       0,     0,     0,     0,     0,   586,   587,     0,     0,     0,
       0,   588,     0,     0,   589,     0,     0,     0,   590,   591,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   593,     0,     0,     0,
   -1742,     0,     0,     0,   594,     0,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
       0,   596,     0,   597,   598,     0,     0,     0,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   600,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   601,     0,     0,     0,   602,     0,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   604,   605,     0,     0,     0,   606,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,   608,   609,   610,   611,
       0,     0,   612,     0,     0,     0,     0,   613,     0,     0,
       0,     0,     0,     0,   614,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,     0,   617,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   618,
       0,     0,   619,     0,     0,   620,     0,     0,     0,     0,
       0,   621,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   622,     0,
       0,   623,     0,     0,     0,     0,     0,   624,     0,     0,
     625,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   626,     0,     0,     0,     1,     0,
       0,   627,   510,     0,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   512,     0,   628,
     629,   630,   631,   632,   633,   634,   513,     0,   635,     0,
     636,     0,   637,     0,     0,     0,     0,   514,   515,   516,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   517,     0,   518,   519,   520,     2,     3,
     521,     4,     5,   522,     0,   523,     6,   524,   525,     0,
       0,     0,     0,     0,   526,     0,     0,   527,     0,   528,
     529,   530,     0,     7,     8,     0,     0,     0,     0,   531,
       0,   532,   533,     0,   534,     0,   535,   536,     0,     0,
     537,     9,    10,     0,     0,   538,   539,   540,     0,   541,
     542,     0,     0,     0,   543,   544,     0,   545,     0,     0,
       0,   546,     0,   547,   548,     0,     0,   549,     0,     0,
       0,   550,     0,     0,   551,     0,   552,     0,   553,     0,
     554,     0,   555,   556,     0,   557,   558,   559,     0,     0,
       0,   560,     0,   561,   562,     0,   563,     0,     0,     0,
       0,     0,     0,     0,   564,   565,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1742,     0,   566,     0,     0,
     567,   568,     0,     0,   569,   570,     0,     0,   571,   572,
       0,     0,     0,     0,     0,     0,     0,   573,   574,   575,
       0,   576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   577,   578,   579,     0,   580,     0,     0,     0,   581,
     582,     0,     0,     0,   583,     0,     0,     0,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,     0,
     585,     0,     0,     0,     0,     0,   586,   587,     0,     0,
       0,     0,   588,     0,     0,   589,     0,     0,     0,   590,
     591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   593,     0,     0,
       0,     0,     0,     0,     0,   594,     0,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,   596,     0,   597,   598,     0,     0,     0,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   601,     0,     0,     0,   602,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   604,   605,     0,     0,     0,   606,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,   608,   609,   610,
     611,     0,     0,   612,     0,     0,     0,     0,   613,     0,
       0,     0,     0,     0,     0,   614,   615,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,     0,   617,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     618,     0,     0,   619,     0,     0,   620,     0,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   622,
       0,     0,   623,     0,     0,     0,     0,     0,   624,     0,
       0,   625,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   626,     0,     0,     0,     1,
       0,     0,   627,   510,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   512,     0,
     628,   629,   630,   631,   632,   633,   634,   513,     0,   635,
       0,   636,     0,   637,     0,     0,     0,     0,   514,   515,
     516,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   517,     0,   518,   519,   520,     2,
       3,   521,     4,     5,   522,     0,   523,     6,   524,   525,
       0,     0,     0,     0,     0,   526,     0,     0,   527,     0,
     528,   529,   530,     0,     7,     8,     0,     0,     0,     0,
     531,     0,   532,   533,     0,   534,     0,   535,   536,     0,
       0,   537,     9,    10,     0,     0,   538,   539,   540,     0,
     541,   542,     0,     0,     0,   543,   544,     0,   545,     0,
       0,     0,   546,     0,   547,   548,     0,     0,   549,     0,
       0,     0,   550,     0,     0,   551,     0,   552,     0,   553,
       0,   554,     0,   555,   556,     0,   557,   558,   559,     0,
       0,     0,   560,     0,   561,   562,     0,   563,     0,     0,
       0,     0,     0,     0,     0,   564,   565,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   566,     0,
       0,   567,   568,     0,     0,   569,   570,     0,     0,   571,
     572,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,     0,   576,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   577,   578,   579,     0,   580,     0,     0,     0,
     581,   582,     0,     0,     0,   583,     0,     0,     0,     0,
       0,     0,     0,   584,     0,     0,     0,     0,     0,     0,
       0,   585,     0,     0,     0,     0,     0,   586,   587,     0,
       0,     0,     0,   588,     0,     0,   589,     0,     0,     0,
     590,   591,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   592,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   593,     0,
       0,     0,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,   596,     0,   597,   598,     0,     0,     0,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1742,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   600,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   601,     0,     0,     0,   602,     0,
       0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   604,   605,     0,     0,     0,
     606,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,   608,   609,
     610,   611,     0,     0,   612,     0,     0,     0,     0,   613,
       0,     0,     0,     0,     0,     0,   614,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,     0,
     617,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   618,     0,     0,   619,     0,     0,   620,     0,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     622,     0,     0,   623,     0,     0,     0,     0,     0,   624,
       0,     0,   625,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,     0,     0,     0,
       1,     0,     0,   627,   510,     0,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
       0,   628,   629,   630,   631,   632,   633,   634,   513,     0,
     635,     0,   636,     0,   637,     0,     0,     0,     0,   514,
     515,   516,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   517,     0,   518,   519,   520,
       2,     3,   521,     4,     5,   522,     0,   523,     6,   524,
     525,     0,     0,     0,     0,     0,   526,     0,     0,   527,
       0,   528,   529,   530,     0,     7,     8,     0,     0,     0,
       0,   531,     0,   532,   533,     0,   534,     0,   535,   536,
       0,     0,   537,     9,    10,     0,     0,   538,   539,   540,
       0,   541,   542,     0,     0,     0,   543,   544,     0,   545,
       0,     0,     0,   546,     0,   547,   548,     0,     0,   549,
       0,     0,     0,   550,     0,     0,   551,     0,   552,     0,
     553,     0,   554,     0,   555,   556, -1742,   557,   558,   559,
       0,     0,     0,   560,     0,   561,   562,     0,   563,     0,
       0,     0,     0,     0,     0,     0,   564,   565,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
       0,     0,   567,   568,     0,     0,   569,   570,     0,     0,
     571,   572,     0,     0,     0,     0,     0,     0,     0,   573,
     574,   575,     0,   576,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   577,   578,   579,     0,   580,     0,     0,
       0,   581,   582,     0,     0,     0,   583,     0,     0,     0,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,   585,     0,     0,     0,     0,     0,   586,   587,
       0,     0,     0,     0,   588,     0,     0,   589,  2142,     0,
       0,   590,   591,  1046,     0,     0,     0,     0,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   593,
       0,     0,     0,     0,     0,     0,     0,   594,     0,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   306,     0,     0,
       0,     0,     0,     0,   596,     0,   597,   598,     0,     0,
       0,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1989,   600,     0,     0,     0,  1046,     0,
       0,     0,     0,     0,     0,   601,     0,     0,     0,   602,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   604,   605,     0,     0,
       0,   606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,   608,
     609,   610,   611,     0,     0,   612,     0,     0,     0,     0,
     613,     0,     0,     0,     0,     0,     0,   614,   615,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
       0,   617,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,   618,     0,     0,   619,     0,     0,   620,     0,
       0,     0,     0,     0,   621,     0,     0,     0,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,    43,     0,     0,     0,     0,     0,     0,
       0,   622,     0,     0,   623,     0,     0,     0,     0,     0,
     624,     0,     0,   625,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   626,    45,     0,
       0,     0,     0,     0,   627,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,   628,   629,   630,   631,   632,   633,   634,     0,
      49,   635,     0,   636,    50,   637,     0,    51,    52,     0,
      53,     0,     0,     0,     0,    54,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,  2143,     0,  1369,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    41,    42,    43,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,    44,     0,
       0,     0,    62,    45,     0,     0,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,    67,    68,    46,     0,
       0,     0,     0,    47,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    49,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,     0,     0,     0,     0,
      54,     0,     0,    40,     0,     0,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2040,    75,
      76,     0,     0,     0,    56,     0,     0,    57,    58,     0,
       0,    41,    42,    43,    59,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    60,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
      61,     0,     0,    44,     0,     0,     0,    62,    45,     0,
       0,     0,     0,     0,    63,     0,     0,    64,    65,    66,
       0,    67,    68,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,    83,     0,     0,    54,     0,     0,    40,     0,
       0,     0,    70,    71,    72,    73,     0,    74,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2277,    75,    76,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    41,    42,    43,    59,
       0,    77,     0,     0,     0,     0,     0,     0,     0,    78,
      60,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,    61,     0,     0,    44,     0,
       0,     0,    62,    45,     0,     0,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,    67,    68,    46,     0,
       0,     0,     0,    47,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    49,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,     0,    83,     0,     0,
      54,     0,     0,    40,     0,     0,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2292,    75,
      76,     0,     0,     0,    56,     0,     0,    57,    58,     0,
       0,    41,    42,    43,    59,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    60,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
      61,     0,     0,    44,     0,     0,     0,    62,    45,     0,
       0,     0,     0,     0,    63,     0,     0,    64,    65,    66,
       0,    67,    68,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,    83,     0,     0,    54,     0,     0,    40,     0,
       0,     0,    70,    71,    72,    73,     0,    74,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2523,    75,    76,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    41,    42,    43,    59,
       0,    77,     0,     0,     0,     0,     0,     0,     0,    78,
      60,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,    61,     0,     0,    44,     0,
       0,     0,    62,    45,     0,     0,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,    67,    68,    46,     0,
       0,     0,     0,    47,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    49,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,     0,    83,     0,     0,
      54,     0,     0,    40,     0,     0,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2657,    75,
      76,     0,     0,     0,    56,     0,     0,    57,    58,     0,
       0,    41,    42,    43,    59,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    60,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
      61,     0,     0,    44,     0,     0,     0,    62,    45,     0,
       0,     0,     0,     0,    63,     0,     0,    64,    65,    66,
       0,    67,    68,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,    83,     0,     0,    54,     0,     0,    40,     0,
       0,     0,    70,    71,    72,    73,     0,    74,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2895,    75,    76,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    41,    42,    43,    59,
       0,    77,     0,     0,     0,     0,     0,     0,     0,    78,
      60,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,    61,     0,     0,    44,     0,
       0,     0,    62,    45,     0,     0,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,    67,    68,    46,     0,
       0,     0,     0,    47,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    49,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,     0,    83,     0,     0,
      54,     0,     0,    40,     0,     0,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,    56,     0,     0,    57,    58,     0,
       0,    41,    42,    43,    59,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    60,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
      61,     0,     0,    44,     0,     0,     0,    62,    45,     0,
       0,     0,     0,     0,    63,     0,     0,    64,    65,    66,
       0,    67,    68,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,    83,     0,     0,    54,     0,     0,    40,     0,
       0,     0,    70,    71,    72,    73,     0,    74,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    41,    42,    43,    59,
       0,    77,     0,   121,   122,     0,     0,     0,     0,    78,
      60,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,    61,     0,     0,    44,     0,
       0,     0,    62,    45,     0,     0,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,    67,    68,    46,     0,
       0,     0,   123,    47,     0,    48,   126,     0,     0,   127,
       0,     0,     0,    69,     0,    49,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,     0,    83,     0,     0,
      54,     0,     0,     0,     0,     0,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,    56,     0,     0,    57,    58,     0,
       0,     0,     0,     0,    59,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    60,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,    63,     0,     0,    64,    65,    66,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,  1046,    70,    71,    72,    73,     0,    74,     0,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,    78,
       0,    41,    42,    43,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,     0,     0,     0,     0,    83,     0,     0,
      49,     0,   128,     0,    50,     0,  1046,    51,    52,     0,
      53,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,     0,     0,     0,    59,
       0,     0,     0,     0,     0,     0,  1941,     0,     0,     0,
      60,     0,   124,     0,     0,     0,     0,     0,     0,  1942,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    63,
       0,    40,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      42,    43,     0,     0,     0,     0,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,    44,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,  1046,
       0,    46,     0,     0,    78,     0,    47,     0,    48,     0,
       0,     0,     0,    79,    80,    81,    82,     0,    49,     0,
       0,     0,    50,     0,     0,    51,    52,     0,    53,     0,
       0,     0,     0,    54,   130,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      57,    58,    83,     0,    41,    42,    43,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,  1943,     0,    44,     0,     0,     0,
      62,    45,     0,     0,     0,     0,     0,    63,     0,     0,
    1944,    65,    66,     0,    67,    68,    46,     0,     0,     0,
       0,    47,     0,    48,     0,     0,     0,     0,     0,     0,
       0,    69,     0,    49,     0,     0,     0,    50,     0,     0,
      51,    52,     0,    53,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,    70,    71,    72,    73,     0,
      74,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,  1046,  2796,     0,     0,     0,    75,    76,     0,
       0,     0,    56,     0,     0,    57,    58,     0,     0,     0,
       0,     0,    59,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,    60,     0,     0,     0,     0,     0,    40,
       0,    79,    80,    81,    82,     0,     0,     0,    61,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,    63,     0,     0,    64,    65,    66,     0,    67,
      68,     0,     0,     0,     0,     0,     0,    41,    42,    43,
       0,     0,     0,     0,     0,     0,    69,     0,  2499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      70,    71,    72,    73,    45,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,    46,
       0,     0,    75,    76,    47,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,    77,
      50,     0,     0,    51,    52,     0,    53,    78,     0,     0,
       0,    54,     0,     0,     0,     0,    79,    80,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,  2680,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    57,    58,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,    40,     0,     0,    83,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,    63,     0,     0,    64,    65,
      66,     0,    67,    68,     0,     0,     0,     0,     0,     0,
      41,    42,    43,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    70,    71,    72,    73,    45,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     761,     0,    46,     0,     0,    75,    76,    47,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,    77,    50,     0,     0,    51,    52,     0,    53,
      78,     0,     0,     0,    54,     0,     0,    40,     0,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,    57,    58,     0,     0,    41,    42,    43,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,    61,     0,     0,    44,     0,     0,
       0,    62,    45,     0,     0,     0,     0,     0,    63,     0,
       0,    64,    65,    66,     0,    67,    68,    46,     0,     0,
       0,     0,    47,     0,    48,     0,     0,     0,     0,     0,
       0,     0,    69,     0,    49,     0,     0,     0,    50,     0,
       0,    51,    52,     0,    53,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
       0,    74,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,  1046,     0,     0,     0,     0,    75,    76,
       0,     0,     0,    56,     0,     0,    57,    58,     0,     0,
       0,     0,     0,    59,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    78,    60,     0,     0,     0,     0,     0,
      40,     0,    79,    80,    81,    82,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    63,     0,     0,    64,    65,    66,     0,
      67,    68,     0,     0,     0,     0,     0,     0,    41,    42,
      43,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    70,    71,    72,    73,    45,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1251,     0,
      46,     0,     0,    75,    76,    47,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
      77,    50,     0,     0,    51,    52,     0,    53,    78,     0,
       0,     0,    54,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,    57,
      58,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,    40,     0,     0,    83,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,    63,     0,     0,    64,
      65,    66,     0,    67,    68,     0,     0,     0,     0,     0,
       0,    41,    42,    43,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    70,    71,    72,    73,    45,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1633,     0,    46,     0,     0,    75,    76,    47,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,    77,    50,     0,     0,    51,    52,     0,
      53,    78,     0,     0,     0,    54,     0,     0,    40,     0,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    41,    42,    43,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,    61,     0,     0,    44,     0,
       0,     0,    62,    45,     0,     0,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,    67,    68,    46,     0,
       0,     0,     0,    47,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    49,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,  1903,     0,     0,     0,     0,    75,
      76,     0,     0,     0,    56,     0,     0,    57,    58,     0,
       0,     0,     0,     0,    59,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    60,     0,     0,     0,     0,
       0,    40,     0,    79,    80,    81,    82,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,    63,     0,     0,    64,    65,    66,
       0,    67,    68,     0,     0,     0,     0,     0,     0,    41,
      42,    43,     0,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    70,    71,    72,    73,    45,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,    75,    76,    47,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,    77,    50,     0,     0,    51,    52,     0,    53,    78,
       0,     0,     0,    54,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      57,    58,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,    40,     0,     0,    83,     0,     0,
       0,     0,     0,    61,   951,     0,     0,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    63,     0,     0,
      64,    65,    66,     0,    67,    68,     0,     0,     0,     0,
       0,     0,    41,    42,    43,     0,     0,     0,     0,     0,
       0,    69,     0,     0,   952,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    70,    71,    72,    73,    45,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,    75,    76,    47,
       0,    48,     0,     0,   953,     0,     0,     0,     0,     0,
       0,    49,     0,     0,    77,    50,     0,     0,    51,    52,
       0,    53,    78,     0,     0,     0,    54,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,     0,
     954,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,    57,    58,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
      63,     0,     0,    64,    65,    66,     0,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,    69,     0,     0,   955,  1098,  1099,
    1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,
    1110,  1111,  1112,  1113,     0,     0,     0,     0,    70,    71,
      72,    73,     0,    74,     0,     0,    41,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1114,  1115,  1116,  1117,  1118,  1119,    77,    44,     0,
       0,     0,     0,    45,     0,    78,     0,  1120,  1121,  1122,
     956,     0,     0,     0,    79,    80,    81,    82,    46,     0,
       0,     0,     0,    47,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,     0,     0,     0,     0,
      54,     0,   957,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,     0,    57,    58,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   958,
      61,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,    63,     0,     0,    64,    65,    66,
       0,    67,    68,     0,     0,     0,  1123,     0,     0,  1124,
       0,     0,     0,     0,     0,     0,     0,     0,   812,     0,
       0,     0,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,     0,     0,
       0,     0,    70,   959,    72,    73,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,  1115,  1116,  1117,  1118,
    1119,    77,     0,     0,     0,     0,     0,     0,     0,   814,
       0,  1120,  1121,  1122,     0,     0,     0,     0,   816,    80,
      81,    82,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,     0,     0,     0,     0,  1125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1126,     0,     0,     0,  1127,  1650,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,  1114,  1115,
    1116,  1117,  1118,  1119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1120,  1121,  1122,     0,     0,     0,
       0,     0,     0,  1128,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1129,     0,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1130,
    1123,     0,     0,  1124,     0,     0,     0,  1114,  1115,  1116,
    1117,  1118,  1119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1120,  1121,  1122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1114,  1115,  1116,  1117,
    1118,  1119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1120,  1121,  1122,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1131,     0,  1123,     0,     0,  1124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1114,  1115,
    1116,  1117,  1118,  1119,     0,     0,     0,     0,     0,  1125,
       0,     0,     0,     0,  1120,  1121,  1122,     0,     0,     0,
       0,     0,     0,     0,  1126,     0,     0,     0,  1127,  1661,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1123,     0,     0,  1124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1123,     0,     0,  1124,     0,     0,     0,     0,     0,
       0,     0,  1125,     0,     0,  1129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1126,     0,     0,
       0,  1127,  1662,  1130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1128,     0,     0,  1123,     0,     0,  1124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1125,     0,     0,     0,     0,     0,     0,  1129,     0,
       0,     0,     0,     0,     0,     0,  1126,     0,     0,     0,
    1127,  1673,     0,     0,     0,  1131,  1130,     0,     0,     0,
    1125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1126,     0,     0,     0,  1127,
    1681,     0,     0,     0,     0,     0,     0,     0,     0,  1128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,     0,  1129,  1128,     0,
       0,     0,     0,  1132,     0,     0,     0,     0,     0,     0,
       0,     0,  1125,     0,     0,  1130,     0,     0,  1131,     0,
       0,     0,     0,     0,     0,     0,  1129,  1126,     0,     0,
       0,  1127,  1683,  1114,  1115,  1116,  1117,  1118,  1119,     0,
       0,     0,     0,     0,  1130,     0,     0,     0,     0,  1120,
    1121,  1122,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,     0,     0,
    1128,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,  1132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1131,  1129,     0,
       0,     0,     0,     0,     0,  1114,  1115,  1116,  1117,  1118,
    1119,     0,     0,     0,     0,     0,  1130,     0,     0,     0,
       0,  1120,  1121,  1122,     0,     0,  1131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,     0,     0,     0,  1132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1123,     0,
       0,  1124,     0,     0,  1132,     0,     0,     0,  1131,  1114,
    1115,  1116,  1117,  1118,  1119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1120,  1121,  1122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1123,     0,     0,  1124,     0,     0,  1132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1125,     0,     0,
       0,    44,     0,     0,    92,     0,    45,     0,     0,     0,
       0,     0,  1126,     0,     0,     0,  1127,  1684,     0,     0,
       0,    46,     0,     0,     0,     0,    47,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,    50,     0,  1123,    51,    52,  1124,    53,     0,
       0,     0,     0,    54,     0,  1128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1125,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1129,  1126,     0,     0,    56,  1127,  1685,
      57,    58,     0,     0,     0,     0,     0,    59,     0,     0,
       0,  1130,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,  1128,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    63,     0,     0,
      64,    65,    66,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1129,     0,     0,     0,     0,
       0,    69,     0,  1125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1130,     0,    40,     0,     0,  1126,     0,
       0,     0,  1127,  1131,     0,    70,    71,    72,    73,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,     0,
       0,     0,     0,    41,    42,    43,     0,     0,     0,     0,
       0,  1128,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,    44,     0,     0,     0,  1129,
      45,  1132,     0,     0,     0,  1131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,  1130,     0,     0,
      47,     0,    48,     0,     0,     0,  1175,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    50,     0,     0,    51,
      52,     0,    53,     0,     0,     0,     0,    54,     0,     0,
      83,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,  1132,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,    57,    58,     0,     0,     0,     0,
       0,    59,     0,    41,    42,    43,     0,     0,     0,  1131,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,    44,     0,     0,     0,     0,
      45,    63,     0,     0,    64,    65,    66,     0,    67,    68,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
      47,     0,    48,     0,     0,    69,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    50,  1132,     0,    51,
      52,     0,    53,     0,     0,     0,     0,    54,     0,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,    57,    58,     0,     0,    77,     0,
       0,    59,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,    60,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    63,     0,    40,    64,    65,    66,     0,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,    41,    42,    43,     0,     0,     0,   138,     0,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    44,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,    46,   881,     0,    78,     0,    47,     0,
      48,     0,     0,     0,     0,    79,    80,    81,    82,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,    83,     0,     0,     0,     0,    59,
       0,    41,    42,    43,     0,     0,     0,   138,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,    44,     0,     0,     0,     0,    45,    63,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,     0,     0,     0,     0,    54,     0,    70,    71,    72,
      73,     0,    74,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,    75,
      76,     0,     0,   882,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    77,     0,     0,    59,
       0,    41,    42,    43,    78,     0,     0,     0,     0,     0,
      60,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,    44,     0,     0,     0,     0,    45,    63,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,  1730,
      48,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      49,     0,    83,     0,    50,     0,     0,    51,    52,     0,
      53,     0,     0,     0,   883,    54,     0,    70,    71,    72,
      73,     0,    74,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    77,     0,     0,    59,
       0,    41,    42,    43,    78,     0,     0,     0,     0,     0,
      60,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,    44,     0,     0,     0,     0,    45,    63,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      49,     0,    83,     0,    50,     0,     0,    51,    52,     0,
      53,     0,     0,     0,   883,    54,     0,    70,    71,    72,
      73,     0,    74,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    77,     0,     0,    59,
       0,    41,    42,    43,    78,     0,     0,     0,     0,     0,
      60,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,    44,     0,     0,    92,     0,    45,    63,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      49,     0,    83,     0,    50,     0,     0,    51,    52,     0,
      53,     0,     0,     0,   883,    54,     0,    70,    71,    72,
      73,     0,    74,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    77,     0,     0,    59,
       0,    41,    42,    43,    78,     0,     0,     0,     0,     0,
      60,     0,    88,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,    44,     0,     0,     0,     0,    45,    63,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,     0,
      48,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      49,  -905,    83,     0,    50,     0,     0,    51,    52,     0,
      53,     0,     0,     0,     0,    54,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,    57,    58,     0,     0,    77,     0,     0,    59,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
      60,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    63,
       0,    40,    64,    65,    66,     0,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,    41,
      42,    43,     0,     0,     0,     0,     0,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,    44,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,    46,     0,     0,    78,     0,    47,     0,    48,     0,
       0,     0,     0,    79,    80,    81,    82,     0,    49,     0,
       0,     0,    50,     0,     0,    51,    52,     0,    53,     0,
       0,     0,     0,    54,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      57,    58,    83,     0,    41,    42,    43,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,  2620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,    44,     0,     0,     0,
      62,    45,     0,     0,     0,     0,     0,    63,     0,     0,
      64,    65,    66,     0,    67,    68,    46,     0,     0,     0,
       0,    47,     0,    48,     0,     0,     0,     0,     0,     0,
       0,    69,     0,    49,     0,     0,     0,    50,     0,     0,
      51,    52,     0,    53,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,    70,    71,    72,    73,     0,
      74,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,     0,
       0,     0,    56,     0,     0,    57,    58,     0,     0,     0,
       0,     0,    59,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,    60,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,    61,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,    63,     0,     0,    64,    65,    66,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83
};

static const short yycheck[] =
{
      22,    23,   100,   406,     0,   199,   781,   300,   301,   513,
     748,     0,    34,   903,   904,   604,   906,   153,   908,   909,
     896,   907,   138,   892,     3,  1388,  1659,   681,   222,   223,
     224,   225,   226,  1433,   586,   987,   759,   253,   167,    35,
    1286,  1287,   631,     4,   777,   634,    35,   999,  1466,  1039,
     570,     4,  2120,   944,     4,   596,  1317,   186,    91,  1712,
    1771,   602,  2119,   932,  2121,   606,    88,   536,     4,    91,
     286,    16,    94,  1576,    96,    19,    21,   175,  2143,    24,
      25,    16,    17,     4,   213,    16,    17,   216,   110,   593,
      40,   593,    16,    17,    21,     4,    46,    33,    25,    35,
    2108,    37,     4,  1053,   100,   101,   128,   129,   130,     4,
       4,   100,   101,   846,   136,  1647,    21,    21,  1518,    24,
      25,    25,  1833,    12,     4,    21,   100,  1527,   117,    25,
    1006,    21,  1008,    53,    54,    25,     4,  1083,   597,     4,
     162,   163,   164,   165,   115,   128,     4,     4,     4,    66,
       4,   140,    18,    19,    20,   177,   178,  2225,   627,   288,
    1692,   457,     4,  2416,   153,     5,   115,   189,     4,  1701,
       4,     4,    16,    17,    24,    25,   238,    21,     5,   175,
      24,    25,   305,   205,  1590,  2539,   175,     5,  2060,  2061,
    2062,  2063,    58,    59,    60,    61,    62,    63,     8,     4,
      10,    11,    12,    13,    14,    15,   762,   200,    74,    75,
      76,     4,     4,   235,   212,   350,   991,  2588,     4,     4,
       4,     4,   420,    73,     4,  1821,   355,     4,   357,  2680,
    2606,  2682,   392,   362,     3,  2739,   537,   171,   234,   375,
     286,   128,    16,    17,     4,   234,   392,    21,   420,   301,
      24,    25,     4,     4,     4,   141,   101,   102,   559,   234,
     199,   420,   237,     4,   239,     4,  2605,     4,   539,     4,
      81,   925,   509,   259,   420,   500,   400,   234,     4,   610,
     246,   303,   304,   199,   259,   414,   392,   411,   310,   311,
       4,     4,    26,   259,   269,    24,  1714,   426,   434,   435,
     601,   508,    29,   295,  2664,  2016,   328,  2667,   432,   580,
     611,   612,   500,   419,   615,   439,     4,   339,   619,     4,
     621,   317,   305,     4,   625,   626,   551,     4,   317,   914,
     915,   310,  2836,   308,     4,     4,   739,   312,  2395,  2494,
    2397,  1873,  2399,   238,   500,  2413,   589,   213,   370,   235,
     216,   373,  2409,  1244,   346,     4,     4,   379,     4,  2416,
     317,     4,  2370,   551,     4,     4,   116,  1899,     4,   616,
     238,     4,   501,   620,   581,   116,   320,   624,    16,    17,
      18,    19,    20,     4,  2723,   583,   375,    16,    17,    18,
      19,    20,   106,     4,   553,   551,   442,     4,     4,     4,
      16,    17,    18,    19,    20,   391,   216,   323,    27,   431,
    2659,   583,  2661,  1188,     3,   354,   391,   352,   305,  1918,
      12,  2872,  1921,   588,   583,   391,  2581,   361,  2583,   589,
     452,   301,   454,  2588,   432,   929,   559,  2033,   354,    24,
     605,   606,   247,    12,   740,   434,   435,   388,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,  1871,   332,   442,  2839,   531,
     247,  1717,  2843,   466,  2828,  1064,  2830,  2853,  1034,   388,
     583,   347,   617,  1429,   506,   351,  1432,   509,   510,  2742,
     542,   513,   514,   437,   516,   352,   733,   519,  2837,  2838,
     206,   475,    58,    59,    60,    61,    62,    63,   530,  1061,
    1062,  1063,   352,   357,   350,   537,   487,   754,    74,    75,
      76,    64,   332,   506,   390,   352,  1078,   549,   372,  1479,
     388,   420,   388,  1037,   352,  1037,  2593,   559,   487,   268,
     562,   310,   588,   272,   273,   274,   388,  2612,  1007,  2606,
     572,   501,   418,   398,   388,   388,   602,   603,   541,   352,
     352,  2569,  2570,   292,   586,   587,   352,   352,   352,   352,
     436,   593,   352,   423,   334,  1229,   622,  1310,  1311,   601,
    1169,   603,   604,   357,   617,   607,  1319,   213,  1540,   611,
     612,   892,   614,   615,   515,   617,  2099,   619,   372,   621,
     352,   352,  2134,   625,   626,   549,   628,  2318,   630,   631,
     238,   633,   634,   352,   636,   352,   518,   352,   512,   543,
    2020,  1512,  1174,  1884,   167,   926,   352,   958,   581,  1214,
    2283,   932,   512,   731,  2287,  2507,   531,  1157,   583,   352,
     590,   620,   559,   508,   945,   581,  1636,   622,  1152,   950,
    1152,   586,   518,   589,   508,   586,   583,   213,   432,   620,
     216,  1250,   586,   531,   352,  2164,   134,   352,  2917,   589,
    1222,   352,   542,   320,   403,   352,  1170,   305,   583,   583,
     223,   588,   352,   352,  2839,  2742,  1869,   583,  2843,   123,
    2222,  2223,  2224,   583,  1283,  1284,  2228,  1249,   427,   606,
     293,     4,  1254,   352,   352,   248,   352,    28,   518,   352,
     109,   733,   352,   352,   257,  2783,   352,   446,   589,   352,
     586,   347,   350,   349,  2792,  1266,   589,   126,   127,   320,
    1606,   352,   754,  2366,    99,   731,   352,   316,   314,   583,
     762,   352,   731,  1036,  2107,   352,   352,   352,   291,  1995,
     388,   294,   481,   259,   432,   777,   299,   583,   392,   388,
     203,    24,   440,   306,   352,   787,   788,    88,    89,   297,
      91,    92,   501,   502,  1243,    96,   332,   799,  1153,   307,
    1155,   180,   578,   805,   806,   419,   420,   546,   517,   585,
     437,   347,   113,   114,     4,   351,  2853,   819,   163,   387,
     165,   560,   308,   400,   586,   564,   312,   129,   130,   583,
     131,   132,    26,    27,   411,   180,   259,   576,   549,   400,
      24,    25,   442,   188,   846,  1156,   260,   192,   371,   558,
     411,   562,   360,   629,   390,   378,   632,  1168,   582,  2371,
     162,   163,   164,   165,   580,   589,   437,   375,   314,   311,
     393,  1737,   217,  2564,     4,   177,   178,  1158,  1159,  1160,
     911,   590,   418,  1596,  1377,   308,  1379,   918,   382,   312,
     892,   893,   387,   335,   417,    12,   338,  1178,   392,    25,
     436,   588,   475,   419,   420,   391,   420,  2419,  1429,  1478,
     420,  1432,   518,   486,  1023,   357,   912,   913,   441,   333,
     916,   917,   549,   531,   926,   419,   420,   392,   451,   452,
     932,  2311,   543,   235,  1215,   546,   495,   234,   598,   599,
     237,   392,   239,   945,   467,   556,  2109,  2110,   950,   560,
     509,   497,   400,   564,   956,  2487,   464,   420,  2490,  2491,
     571,  1242,   259,   411,   392,   576,   489,   578,   391,   492,
     493,   973,   269,   584,   585,   498,   535,  1258,   549,   419,
     420,   592,   518,   327,   432,   987,   597,  1268,   588,   286,
     630,   439,   392,   633,   605,   392,   636,   999,  1172,   607,
     608,   609,   602,   603,   392,   616,  1575,   251,   252,   620,
     618,   308,  1014,   624,   420,   312,   317,   392,   629,  1875,
     462,   632,   622,   392,  1026,   584,  1028,  1559,  1560,   129,
     600,   601,  1034,   133,   557,  1037,   327,  1039,  1040,   453,
    1672,  1043,  1898,   328,   567,  1677,   569,   607,   608,  1681,
     586,  1683,  1684,  1685,   589,  1366,  1058,   607,   608,  1061,
    1062,  1063,  1064,   589,  1066,  1067,   367,   576,   577,   578,
     579,   415,  2232,  2233,   516,    25,  1078,   260,  1080,   262,
      25,    25,   524,    18,    19,    20,  2598,   431,    25,    25,
    1092,   583,  1094,  1095,   391,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1308,  2726,  2727,   460,   129,    25,  1314,    25,
     133,    25,  1124,  1125,   415,    25,    25,  1129,  1649,  1131,
     474,    74,    75,    76,   234,    25,   583,   237,  2650,  2651,
     431,   392,   155,    25,    78,   442,  1859,   583,   388,     4,
    1152,    16,    17,    18,    19,    20,  1158,  1159,  1160,   259,
      16,    17,    18,    19,   392,   392,   352,  1169,  1449,  1171,
     514,  1173,  1174,   583,    25,    28,  1178,  1811,  2690,   222,
     388,   352,   392,   474,  1887,    25,   392,   392,  1901,    19,
      25,    25,  1473,    25,  2043,    19,  1477,    25,    25,   392,
      25,   545,    58,    59,    60,    61,    62,    63,    25,    25,
     554,   352,   392,  1215,  1525,   266,   352,   352,   352,   352,
    1222,   234,   587,   514,   237,  1506,     4,   352,   266,   352,
    2573,   352,   587,  2576,   352,    88,    89,   322,    91,    92,
    1242,  1357,   421,    96,  1360,  1247,   259,  1249,  1250,   482,
     420,  1532,  1254,   420,   545,   583,  1258,  2012,   352,  1780,
     113,   114,     4,   554,   352,  1361,  1268,   583,   420,   580,
     583,  1582,    58,    59,    60,    61,    62,    63,   131,   132,
    1282,  1283,  1284,     7,   388,   896,   440,   392,    74,    75,
      76,   391,   382,   392,  2692,    16,    17,    18,    19,   392,
     392,    16,    17,    18,    19,  1307,  2704,   230,  1310,  1311,
     392,   392,   392,  1315,   512,  1317,   392,  1319,   392,   392,
    2252,   392,   392,   348,   392,   622,   392,   525,  1639,   392,
     392,   392,   327,   392,   392,   392,     4,    58,    59,    60,
      61,    62,    63,    58,    59,    60,    61,    62,    63,   374,
     581,   581,   535,   536,   552,   559,   421,   421,  2870,  1640,
     382,   617,   392,   617,  2876,     7,    16,    17,    18,    19,
     568,   569,   288,   560,  1376,  1377,   574,  1379,   391,   577,
       4,  1383,  1693,     4,  1695,   553,   482,   149,  1357,   327,
     344,  1360,   392,  1704,   392,  1006,  1007,  1008,   392,   392,
     392,  1403,  1404,  1405,   392,  1407,   168,  2805,    58,    59,
      60,    61,    62,    63,   392,  1696,  1697,  1698,  1699,   305,
     415,   392,   542,     7,   327,   327,    12,   213,  2826,   538,
     216,  1433,   457,  1435,     4,  2301,   431,     4,    31,  1720,
     617,   617,    88,    89,   627,    91,    92,  1449,    25,  2829,
      96,   382,   392,   392,   637,    16,    17,    18,    19,   618,
     352,  2179,   392,   352,  2098,  1467,   553,   113,   114,   583,
     559,  1473,   392,  1475,  1476,  1477,  1478,   415,   553,   474,
     117,   392,   589,   432,    19,   131,   132,     3,     4,     5,
       6,     7,     8,   431,    10,  1776,   352,    58,    59,    60,
      61,    62,    63,   589,  1506,    19,   589,   392,   392,  1511,
     620,  1627,   415,   415,   392,  1631,  1518,   392,   311,   514,
      17,  1523,   518,    16,    64,  1527,     4,   552,   431,   431,
    1532,    25,   588,    25,   171,   172,   474,   118,  1540,   564,
     565,   182,  2255,    24,   553,  1547,   332,  1549,   573,   586,
     545,   542,  2084,  2308,  2086,   201,  2412,  1559,  1560,   554,
     443,   347,   199,   443,     4,   351,   508,   116,     4,    25,
      25,   474,   474,  1575,   609,   508,   514,   283,    16,    17,
      18,    19,   508,    57,   388,   222,   223,   224,   225,   226,
      99,   388,   229,  2077,  1596,   508,   583,   352,   781,   352,
     352,   352,  1604,   352,   390,   352,   352,   545,  1889,   352,
    1891,   514,   514,  1615,    38,    39,   554,    41,    42,    43,
      58,    59,    60,    61,    62,    63,  1937,   539,   580,   352,
     352,   352,   418,  2267,  1636,     4,   589,   352,  1640,     4,
     823,     4,   545,   545,     4,  1647,   543,   352,   444,     4,
     436,   554,   554,   392,   163,   583,   165,  1659,  1627,   392,
     589,   588,  1631,   300,   301,   515,    25,    25,  1979,  2303,
      31,   180,    18,    19,   392,   497,   352,     4,   352,   188,
     352,   321,   589,   192,  1686,   583,  1688,   560,    12,   512,
    1692,     4,    25,   508,  1696,  1697,  1698,  1699,   432,  1701,
     212,   392,   352,   547,  1985,  1707,  1708,  1988,   217,  1711,
    1712,   583,    58,    59,    60,    61,    62,    63,  1720,   143,
     589,    66,  2291,   392,   588,     4,   150,   422,  1730,  2298,
     422,     7,   518,  2182,  2183,  2184,   352,  2186,  2187,  2188,
    2189,  2190,  2191,     4,     4,   352,  2195,   487,   327,   511,
     512,   352,   583,   399,   294,     4,     7,   583,   182,   287,
     305,   305,  2043,   525,   583,   420,   306,   191,    58,    59,
      60,    61,    62,    63,  1776,   305,  1778,   392,  2533,   387,
     392,   543,   392,   392,   546,     4,  2499,  1789,   392,   392,
     552,   352,   392,   382,   556,  2178,   220,   221,   560,    25,
     586,   504,   564,     4,     4,     4,   568,   569,   991,   571,
    1812,     4,   574,    25,   576,   577,   578,   305,   361,   580,
     392,   559,   584,   585,   559,     4,   583,   583,     4,   597,
     592,   371,     7,   587,   392,   597,   415,   587,   378,   583,
     392,   265,   392,   605,   392,   352,   352,   352,   352,   352,
     352,    19,   431,     4,   616,   238,   529,  1859,   620,     4,
    1471,   352,   624,  2618,     4,   508,     4,   629,   352,   352,
     632,  1873,   534,   420,  1876,   589,   402,   417,    25,   392,
     304,  1883,  1884,   583,   521,  2519,  1888,  1889,   352,  1891,
     432,   392,   392,     5,    12,   474,     6,  1899,   515,  1901,
     589,   441,     4,    12,   515,   589,     4,     4,    24,  2220,
      24,   451,   452,    24,   352,  1917,  1918,   582,   555,  1921,
      24,   408,    25,    24,   561,    25,   563,   467,   232,    25,
     567,    25,    25,   570,    25,   514,   573,   361,  1940,   583,
    2810,  2811,  2812,  2813,  2814,  2815,   583,   392,   392,   489,
     392,   302,   492,   493,   487,  1957,     4,  1959,   498,  2270,
    2673,   392,   392,   600,   125,   392,   545,  2680,   352,  2682,
     392,   608,   609,   610,  1585,   554,   512,   205,   388,   305,
     352,   142,   143,  1985,   105,   622,  1988,   392,    19,   150,
     392,  1993,   583,    28,     4,  1606,   352,   432,     4,   589,
     637,    25,    25,    25,  2006,  1188,  2008,     4,  2010,   329,
     531,   582,   334,  2294,    25,  2017,   352,   557,  2020,   392,
     352,   182,   392,     4,     4,    12,   508,   204,   174,   569,
     191,   570,     3,   204,    25,   260,    71,    72,   420,  2320,
      25,  2043,     4,   352,    79,    16,    17,    18,    19,  2322,
     352,   392,   352,    88,    89,   409,    91,    92,   353,   220,
    1243,    96,  2064,  2065,  2066,  2067,  2068,  2069,  2702,   392,
      16,    17,    18,    19,   352,  2077,   392,   388,   113,   114,
     352,    25,  2084,   352,  2086,   583,   403,    58,    59,    60,
      61,    62,    63,   352,    25,   352,   131,   132,   392,  2177,
       4,     4,    24,   589,   265,   624,   352,  1290,  1549,     4,
     559,  2285,    58,    59,    60,    61,    62,    63,  2120,   352,
    2122,   352,   352,     0,     0,  2023,  2892,  2205,  1940,  1957,
    1766,  1259,  2134,    17,   896,  1533,    19,  2139,  2006,  1714,
     140,  2143,     6,   304,   781,  1708,   362,   213,   216,   356,
     270,  1022,    16,    17,    18,    19,  2158,  2159,  2160,  2872,
     363,   464,  2164,  1604,  1023,   272,   440,   591,   592,   593,
     594,   595,   809,   426,   273,   452,   394,  2805,   393,   454,
    1506,  1688,   614,  1345,  1922,  1698,  1915,  2942,  1477,  1032,
    2080,  1282,   224,  2348,    58,    59,    60,    61,    62,    63,
    2834,  2177,  2513,  1556,  1809,  1702,   843,  1285,  2177,  1570,
    2093,  1174,  2527,  2647,  2095,   101,  1538,  1016,  1659,  2105,
    2222,  2223,  2224,  2225,   573,   317,  2228,  1544,  1269,  2205,
     229,   263,  2738,  1028,  2515,  1290,  2205,  1547,  2456,  2634,
    1165,  1588,  1212,  2826,  1006,  1007,  1008,   992,   280,  2217,
    2252,   888,  2644,  2255,  2065,   945,  1242,  2215,  1869,  1155,
    2199,  2263,  1934,  2689,  1875,   902,   903,   904,  1088,   906,
    1043,   908,   909,  1692,  2415,  2228,  1869,   914,   915,  2912,
    2876,  2283,  1009,  2746,  2286,  2287,   318,  1898,  2649,  2291,
    1902,  2870,  2294,   328,  2678,  2499,  2298,  2224,   330,  2256,
    2382,  2122,  2383,  2583,  1307,  2132,  2658,  2160,   340,  2311,
    1009,  2691,  2568,  2139,  2874,  2555,  2135,  2721,  2320,  1303,
     355,   958,  1005,    94,  1636,  2405,    -1,   359,   728,    -1,
    2332,   968,  2334,  2335,  2336,  2337,    -1,   369,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1789,    -1,
      -1,    -1,    -1,   385,   991,   992,    -1,    -1,    -1,    -1,
      -1,    -1,  2364,    -1,  2366,    -1,  1549,  1004,  1005,  2371,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2382,  2383,  2693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   426,  2394,   425,    -1,    -1,    -1,  2399,    -1,  1036,
      -1,    -1,    -1,  2405,    -1,    -1,    -1,  2409,    -1,    -1,
      -1,  2413,    -1,  2415,  2416,    -1,   448,  2419,    -1,  2421,
      -1,  1604,    -1,    -1,    -1,    -1,    -1,    -1,  2430,    -1,
      -1,   463,    -1,    -1,  1348,    -1,    -1,   472,   470,    -1,
      -1,   473,    -1,    -1,    -1,    -1,    -1,    -1,  1085,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   494,    -1,    -1,   497,    -1,   499,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1659,    -1,    -1,    -1,
      -1,  2483,    -1,    -1,   519,    -1,   518,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2499,  2109,  2110,
      -1,  2503,    -1,  2505,    -1,   537,    -1,    -1,    -1,  1146,
    1272,    -1,    -1,  2515,    -1,    -1,  1153,    -1,  1155,  1156,
    1157,    -1,    -1,    -1,    -1,    -1,    -1,  1164,  1165,    -1,
      -1,  1168,    -1,    -1,    -1,  1172,    -1,    -1,  1175,     8,
    2821,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,  1188,    -1,  2555,    84,    -1,    -1,    -1,  2560,    -1,
      -1,   596,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2587,    -1,  2589,    -1,    58,
      59,    60,    61,    62,    63,    -1,  2598,    -1,  1781,  1782,
      -1,    -1,    -1,  1517,  2606,    -1,  1789,    -1,    -1,    -1,
    2612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1256,
      -1,    -1,  2624,  2064,  2065,  2066,  2067,  2068,  2069,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1552,    -1,
      -1,  1278,    -1,    -1,    -1,    -1,    -1,  2928,  2650,  2651,
      -1,    -1,  1289,  1290,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,  2673,   202,    -1,    -1,    -1,    -1,    -1,  2680,  2120,
    2682,    -1,   212,  2685,    -1,    -1,    -1,    -1,  2690,    -1,
      -1,    -1,    -1,  1876,    -1,    -1,    -1,    -1,  2139,    -1,
      -1,    -1,    -1,    -1,  1618,  1619,    -1,    -1,    -1,  1471,
     240,  1625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2721,
      -1,    -1,    -1,    -1,  2726,  2727,   256,    -1,    -1,  1366,
      -1,   261,    -1,    -1,    -1,  2737,    -1,    -1,    -1,    -1,
    2742,   271,    -1,    -1,  2746,    -1,    -1,   216,   278,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2783,    -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,
    2792,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2821,
    2822,    -1,    -1,  1585,    -1,    -1,    -1,  2829,    -1,  2012,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2842,    -1,    -1,    -1,  1606,    -1,  1760,  1761,    -1,    -1,
      -1,  2853,    -1,    -1,  1768,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   332,    -1,    -1,    -1,  1504,  2870,    -1,
    2872,    -1,  2874,  1635,  2876,    -1,  1513,    -1,    -1,    -1,
      -1,  2064,  2065,  2066,  2067,  2068,  2069,    -1,  1525,    -1,
      -1,  2332,    -1,  2334,  2335,  2336,  2337,    -1,    -1,    -1,
      -1,    -1,   432,  1817,  1818,  1819,  1820,  1544,    -1,   439,
    2912,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1832,    -1,
      -1,   390,    -1,    -1,    -1,  2366,  2928,    -1,    -1,    -1,
      -1,   461,    -1,    -1,    -1,    -1,   466,  2120,    -1,  2122,
      -1,    -1,    -1,    -1,    -1,  1582,    -1,  1584,    -1,    -1,
      -1,  1588,    -1,  2394,    -1,    -1,  2139,    -1,  2399,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2409,    -1,
      -1,    -1,    -1,    -1,    -1,  2416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1620,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,  2182,
    2183,  2184,  1639,  2186,  2187,  2188,  2189,  2190,  2191,    -1,
      -1,    -1,  2195,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1793,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    -1,  2225,    -1,    -1,    -1,    -1,    -1,    -1,   518,
      -1,    74,    75,    76,    -1,    -1,  1693,    -1,  1695,    -1,
      58,    59,    60,    61,    62,    63,    -1,  1704,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,
      -1,    -1,  1996,  1997,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2005,    -1,    -1,    -1,    -1,    -1,   566,  1860,  2013,
      -1,    -1,    -1,    -1,    -1,  1742,    -1,  1869,    -1,    -1,
      -1,    -1,    -1,  1875,  2555,  2029,  2030,   586,    -1,  2560,
      -1,    -1,    -1,    -1,    -1,  2308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1771,    -1,  1898,    -1,   787,   788,
      -1,    -1,    -1,    -1,    -1,    -1,  2587,    -1,  2589,  2332,
     799,  2334,  2335,  2336,  2337,    -1,   805,   806,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2606,    -1,    -1,    -1,    -1,
     819,  2085,    -1,  2087,    -1,    -1,    -1,    -1,    -1,    -1,
    2094,    -1,  2096,  2366,    -1,    -1,    -1,    -1,    -1,    -1,
     213,  1953,    -1,   216,    -1,    -1,    -1,    -1,    -1,  2382,
    2383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2394,    -1,    -1,    -1,   213,  2399,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2409,    -1,    -1,    -1,
    2413,    -1,    -1,  2416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2685,    -1,    -1,    -1,    -1,    -1,
      -1,  2165,  2166,    -1,    -1,    -1,    -1,    -1,  2172,  2173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1909,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2726,  2727,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2737,    -1,    -1,    -1,
    1937,  2742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,
      -1,  2494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,   351,    -1,
      -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1979,    -1,    -1,    -1,    -1,  2109,  2110,   347,
    2533,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
    2284,    -1,  2555,    -1,  2288,  2012,    -1,  2560,    -1,    -1,
      -1,    -1,    -1,    -1,  2021,    -1,  2023,  2024,    -1,    -1,
      -1,    -1,   390,    -1,    -1,   418,    -1,    -1,  2581,  2036,
    2583,  2842,  2316,    -1,  2587,  2588,  2589,    -1,    -1,  1058,
      -1,    -1,  2853,   436,    -1,    -1,    -1,  1066,  1067,    -1,
     418,    -1,    -1,  2606,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1080,  2346,  2874,    -1,  2618,    -1,    -1,   436,    -1,
      -1,    -1,    -1,  1092,    -1,  1094,  1095,    -1,  1097,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,    -1,    -1,  2104,    -1,    -1,
      -1,  2912,   263,    -1,    -1,  1124,  1125,    -1,    -1,    -1,
    1129,    -1,  1131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,
      -1,    -1,  2685,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2431,  2432,    -1,
     518,  2435,  2436,    -1,    -1,    -1,  2163,   318,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,
      -1,    -1,    -1,  2726,  2727,  2459,    -1,    -1,    -1,   340,
      -1,    -1,    -1,    -1,  2737,    -1,    -1,    -1,    -1,  2742,
      -1,    -1,    -1,   586,  2201,    -1,    -1,    -1,   359,    -1,
      -1,  2333,    -1,    -1,    -1,    -1,    -1,  2214,   369,    -1,
      -1,   372,    -1,  2220,    -1,    -1,    -1,    -1,   586,    -1,
      -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,
    2783,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2792,
     401,  2373,    -1,    -1,     8,  2377,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,  2543,
      -1,    -1,    -1,  2270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   433,    -1,    -1,    -1,    -1,    -1,  2285,    -1,
    2412,    -1,    -1,    -1,    -1,    -1,  2839,    -1,    -1,  2842,
    2843,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
    2853,  2308,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   473,    -1,    -1,  2322,    -1,    -1,    -1,    -1,
      -1,  2874,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   494,    -1,    -1,   497,    -1,   499,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,  2912,
      -1,    -1,    21,    -1,  1383,    24,    25,   528,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,   537,    36,    -1,    -1,
      -1,    -1,    -1,    -1,  1403,  1404,  1405,    -1,  1407,  2942,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2407,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1433,    -1,    -1,    -1,  2425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2710,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,  2456,
      -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2753,
    2754,    -1,  2756,    -1,  2758,  2759,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    -1,  1511,    -1,    -1,    -1,    -1,   156,    -1,  1518,
      -1,    74,    75,    76,    -1,    -1,  2513,    -1,  1527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2533,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,
      -1,    -1,    -1,  2857,    -1,  2859,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,   352,    -1,
      -1,    -1,    -1,    -1,   253,    -1,  2880,  2881,    -1,   258,
    2884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2618,    -1,  2897,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,   390,  2634,    -1,    -1,
      -1,  2638,    -1,  2640,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,
     319,    -1,    -1,    -1,    -1,    -1,    -1,  1686,    -1,  1688,
      -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,
     339,    -1,   341,    -1,  2691,    -1,  2693,    -1,    -1,   348,
      -1,    -1,   351,    -1,   353,    -1,   355,    -1,   357,   358,
     359,    -1,   361,    -1,    -1,     3,    -1,   366,    -1,   368,
      -1,    -1,    -1,    -1,    -1,   374,    -1,    -1,    16,    17,
      -1,    -1,    -1,    21,    -1,   384,    24,    25,    -1,    -1,
     389,  2738,    30,   392,    -1,    -1,   395,    -1,    36,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,     4,    -1,
      -1,   410,    -1,    -1,   518,    -1,    -1,    -1,    -1,   332,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,   347,    -1,    -1,   436,   351,   352,
      -1,    -1,    -1,    -1,   443,   444,   445,    -1,    -1,    -1,
     449,   450,    -1,    -1,   453,   454,   455,    -1,   457,   458,
      -1,    -1,   566,  2810,  2811,  2812,  2813,  2814,  2815,   468,
      -1,    -1,    -1,    -1,    -1,   474,    -1,   390,    -1,    -1,
      -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    -1,   503,   418,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   520,   521,   436,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,
      -1,    -1,    -1,   552,    -1,   554,   555,   556,   557,    -1,
      -1,    44,    45,    -1,    -1,   564,   565,   566,    -1,    -1,
      -1,    -1,    55,    -1,   573,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2942,    -1,    -1,  1957,    -1,
    1959,    -1,    -1,    -1,    -1,   518,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   613,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,   626,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2017,    -1,
      -1,  2020,    -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,   586,    -1,    -1,   314,    -1,    -1,    -1,
      -1,   319,    -1,    -1,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,   334,    -1,    -1,    -1,
      -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,
     348,    -1,    -1,   351,    24,   353,    -1,   355,    -1,   357,
     358,   359,   318,   361,    -1,    -1,    -1,    -1,   366,    -1,
     368,    -1,    -1,    -1,   330,    -1,   374,    -1,    -1,    -1,
      -1,   224,    -1,    -1,   340,    -1,   384,    -1,    -1,    -1,
      -1,   389,    -1,    -1,   392,    -1,    -1,   395,    -1,    -1,
      -1,    -1,   400,   359,    -1,   403,   404,    -1,    -1,    -1,
      -1,    -1,   410,   369,    -1,    -1,    -1,    -1,    88,    89,
     263,    91,    92,   421,    -1,    -1,    96,    -1,    -1,   385,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,   436,    -1,
      -1,    -1,    -1,   113,   114,   443,    -1,   445,    -1,    -1,
      -1,   449,   450,   296,    -1,   453,   454,   455,    -1,   457,
     458,   131,   132,     3,    -1,    -1,    -1,    -1,    -1,   425,
     468,    -1,    -1,    -1,    -1,   318,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,   330,    -1,    -1,
      -1,    -1,   448,    -1,    -1,    -1,    -1,   340,    -1,    -1,
     498,   499,   500,   501,    -1,   503,    -1,   463,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,   359,   473,    -1,    -1,
      -1,    -1,   520,   521,    -1,    -1,   369,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   494,   537,
      -1,   497,   385,   499,  2263,    -1,    -1,   545,    -1,    -1,
      -1,    -1,    -1,    -1,   552,    -1,   554,   555,   556,   557,
      -1,    -1,   518,    -1,    -1,    -1,   564,   565,   566,    -1,
      -1,    -1,    -1,    -1,   244,   573,    -1,    -1,    -1,    -1,
      -1,   537,   425,    -1,    -1,   583,    -1,    -1,    -1,    -1,
      -1,    -1,  2311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,
      -1,    -1,   282,   283,   284,   613,    -1,    -1,    -1,    -1,
     463,    -1,    -1,    -1,    -1,    -1,    -1,   470,   626,    -1,
     473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,   319,
      -1,   494,    -1,    -1,   497,    -1,   499,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,
      -1,   341,    -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,
      -1,   351,    -1,    -1,    -1,   355,    -1,     3,   358,   359,
      -1,   361,    -1,    -1,   537,    -1,   366,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   399,
     400,    -1,    -1,   403,   404,    -1,    -1,   580,    -1,    -1,
     410,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
      -1,    -1,    94,   443,   314,    -1,    -1,    -1,    -1,   319,
     450,   103,    -1,   453,   454,   455,    -1,   457,   458,    -1,
     112,    -1,    -1,    -1,   334,   117,    -1,    -1,    -1,   339,
      -1,   341,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,
      -1,   351,    -1,    -1,    -1,   355,    -1,     3,   358,   359,
      -1,   361,    -1,    -1,    -1,    -1,   366,    -1,   498,   499,
     500,   501,    -1,   503,    -1,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,   384,   167,    -1,    -1,    -1,    -1,
     520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     400,    -1,    -1,   403,   404,    -1,    -1,   537,    -1,    -1,
     410,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,   554,   555,   556,   557,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
      -1,   223,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,   244,    -1,
      -1,    -1,    -1,   255,   474,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   613,    -1,   267,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   626,    -1,   498,   499,
     500,   501,    -1,   503,    -1,    -1,   282,   283,   284,   291,
      -1,    -1,   512,    -1,    -1,    -1,    -1,   299,    -1,    -1,
     520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,   314,    -1,
      -1,    -1,    -1,   319,    -1,   545,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   335,   554,   555,   556,   557,   334,    -1,
      -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,   355,
     362,     3,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,   400,    -1,
      -1,    -1,    -1,    -1,   400,    -1,   626,   403,   404,   411,
      -1,    -1,    -1,    -1,   410,    -1,   282,   283,   284,    -1,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,
    2829,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     436,    -1,    -1,    -1,    -1,    -1,    -1,   443,   314,    -1,
      -1,    -1,    -1,   319,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,    -1,    -1,    -1,    -1,    -1,   334,    -1,
      -1,    -1,    -1,   339,    -1,   341,    -1,    -1,   474,   345,
      -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,   355,
      -1,    -1,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,
     366,    -1,   498,   499,   500,   501,    -1,   503,   510,   511,
     512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,   524,    -1,   520,   521,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,
      -1,   537,    -1,    -1,   410,    -1,    -1,    -1,    -1,   545,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,   554,   555,
     556,   557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,
      -1,   623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     626,    -1,   498,   499,   500,   501,    -1,   503,    16,    17,
     282,   283,   284,    21,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,   520,   521,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   537,   314,    -1,    -1,    -1,    -1,   319,    -1,   545,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,   554,   555,
     556,   557,   334,    -1,    -1,    -1,    -1,   339,    -1,   341,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,
      -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,   361,
      -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   384,    -1,    -1,    -1,    -1,   613,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,
     626,   403,   404,    -1,    -1,    -1,    -1,    -1,   410,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,   421,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,
      -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,
      -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,
      -1,   503,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,   520,   521,
     258,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,   537,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   545,   282,   283,   284,    -1,    -1,    -1,
      -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,   314,    -1,    -1,    -1,
      -1,   319,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,
      -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,
     348,   613,    -1,   351,    -1,   353,    -1,   355,    -1,   357,
     358,   359,    -1,   361,   626,    -1,    -1,    -1,   366,    -1,
     368,    -1,    -1,    -1,    -1,    -1,   374,    -1,    -1,    16,
      17,    -1,    -1,    -1,    21,    -1,   384,    24,    25,    -1,
      -1,   389,    -1,    30,   392,    -1,    -1,   395,    -1,    36,
      -1,    -1,   400,    -1,    -1,   403,   404,    -1,    -1,    -1,
      -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,   443,   444,   445,    -1,    -1,
      -1,   449,   450,    -1,    -1,   453,   454,   455,    -1,   457,
     458,    -1,    -1,    -1,    -1,   213,    -1,    -1,   216,    -1,
     468,    -1,    -1,    -1,    -1,    -1,   474,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     498,   499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   520,   521,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,
      -1,    -1,    74,    75,    76,    -1,    -1,   545,    -1,    -1,
      -1,    -1,    -1,    -1,   552,    -1,   554,   555,   556,   557,
      -1,    -1,    -1,    -1,    -1,    -1,   564,   565,   566,    -1,
      -1,    -1,    -1,    -1,    -1,   573,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   332,   583,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
      -1,    -1,    -1,   351,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   613,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,   626,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,   282,   283,   284,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     418,    -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,
      -1,   213,   319,    -1,   216,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,
      -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,
      -1,   348,    -1,    -1,   351,    -1,   353,    -1,   355,    -1,
     357,   358,   359,    -1,   361,    16,    17,    -1,    -1,   366,
      21,   368,    -1,    24,    25,    -1,    -1,   374,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    -1,   384,    -1,    -1,
      -1,    -1,   389,    -1,    -1,   392,    -1,    -1,   395,    -1,
      -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,    -1,
     518,    -1,    -1,   410,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
     332,    -1,    -1,    -1,    -1,    -1,   443,    -1,   445,    -1,
      -1,    -1,   449,   450,    -1,   347,   453,   454,   455,   351,
     457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   468,    -1,   470,    -1,    -1,    -1,   474,   586,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,   498,   499,   500,   501,   156,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   520,   521,    -1,   418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,   436,    -1,    -1,    -1,   545,    -1,
      -1,    -1,    -1,    -1,    -1,   552,    -1,   554,   555,   556,
     557,    -1,    -1,    -1,    -1,    -1,    -1,   564,   565,   566,
      -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,   626,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,   586,    -1,    -1,   348,    -1,    -1,
     351,    -1,   353,    -1,   355,    -1,   357,   358,   359,    -1,
     361,    16,    17,    -1,    -1,   366,    21,   368,    -1,    24,
      25,    -1,    -1,   374,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,   384,    -1,    -1,    -1,    -1,   389,    -1,
      -1,   392,    -1,    -1,   395,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,    -1,    -1,    -1,   410,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   444,   445,    -1,    -1,    -1,   449,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,
     501,   156,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,
      -1,   552,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,   564,   565,   566,    -1,    -1,    -1,    -1,
      -1,    -1,   573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   626,    -1,   282,   283,   284,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,
      -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,
      -1,    -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,
      -1,    -1,    -1,   348,    -1,    -1,   351,   352,   353,    -1,
     355,    -1,   357,   358,   359,    -1,   361,    16,    17,    -1,
      -1,   366,    21,   368,    -1,    24,    25,    -1,    -1,   374,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,   384,
      -1,    -1,    -1,    -1,   389,    -1,    -1,   392,    -1,    -1,
     395,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
      -1,    -1,    -1,    -1,    -1,   410,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
     445,    -1,    -1,    -1,   449,   450,    -1,    -1,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   498,   499,   500,   501,   156,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,   521,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     545,    -1,    -1,    -1,    -1,    -1,    -1,   552,    -1,   554,
     555,   556,   557,    -1,    -1,    -1,    -1,    -1,    -1,   564,
     565,   566,    -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   626,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,
     319,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,
     339,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,   348,
      -1,    -1,   351,    -1,   353,    -1,   355,    -1,   357,   358,
     359,    -1,   361,    16,    17,    -1,    -1,   366,    21,   368,
      -1,    24,    25,    -1,    -1,   374,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    -1,   384,    -1,    -1,    -1,    -1,
     389,    -1,    -1,   392,    -1,    -1,   395,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,   410,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,   445,    -1,    -1,    -1,
     449,   450,    -1,    -1,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,   156,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,
      -1,    -1,    -1,   552,    -1,   554,   555,   556,   557,    -1,
      -1,    -1,    -1,   244,    -1,   564,   565,   566,    -1,    -1,
      -1,    -1,    -1,    -1,   573,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   282,   283,   284,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,    -1,   282,
     283,   284,    -1,   314,    -1,    -1,    -1,    -1,   319,    -1,
      -1,    16,    17,    -1,    19,    -1,    21,    -1,    -1,    24,
      25,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,   314,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,   334,    -1,    -1,    -1,   366,   339,    -1,   341,    -1,
      -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,   351,    -1,
     353,    -1,   355,   384,   357,   358,   359,    -1,   361,    -1,
      -1,    -1,    -1,   366,    -1,   368,    -1,    -1,    -1,   400,
      -1,   374,   403,   404,    -1,    -1,    -1,    -1,    -1,   410,
      -1,   384,    -1,    -1,    -1,    -1,   389,    -1,    -1,   392,
     421,    -1,   395,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,    -1,    -1,    -1,   436,    -1,   410,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,   421,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
     443,    -1,   445,   474,    -1,    -1,   449,   450,    -1,    -1,
     453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   468,    -1,   498,   499,   500,
     501,   474,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,    -1,    -1,   520,   521,   244,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,    -1,   552,
      -1,   554,   555,   556,   557,    -1,    -1,   282,   283,   284,
      -1,   564,   565,   566,    -1,    -1,    -1,    -1,    -1,    -1,
     573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     583,    -1,   613,    -1,    -1,    -1,    -1,    16,    17,   314,
      19,    -1,    21,    -1,   319,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,
     613,    -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,
      -1,    -1,    -1,   626,    -1,    -1,   351,    -1,    -1,    -1,
     355,    -1,   357,   358,   359,    -1,   361,    -1,    -1,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,   389,    -1,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
      -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
     445,    -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   498,   499,   500,   501,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,   521,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,   539,   244,    -1,    -1,    -1,    -1,
     545,    -1,    -1,    -1,    -1,    -1,    -1,   552,    -1,   554,
     555,   556,   557,    -1,    -1,    -1,    -1,    -1,    -1,   564,
     565,   566,    -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,
      21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,   613,    -1,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   626,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,
     339,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,    -1,   357,   358,
     359,    -1,   361,    -1,    -1,    -1,    -1,   366,    -1,    -1,
      -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
     389,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,   445,    -1,    -1,    -1,
      -1,   450,    -1,    -1,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,   521,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   533,    -1,    -1,   258,   537,    -1,
     539,    -1,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,
     549,   550,    -1,   552,    -1,   554,   555,   556,   557,    -1,
      -1,   282,   283,   284,    -1,   564,   565,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   573,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,   314,    19,    -1,    21,    -1,   319,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   334,   613,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,   626,    -1,    -1,
     351,    -1,    -1,    -1,   355,    -1,   357,   358,   359,    -1,
     361,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,   389,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,    -1,    -1,    -1,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,   445,    -1,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,   539,   244,
      -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,
      -1,   552,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,   564,   565,   566,    -1,    -1,    -1,    -1,
      -1,    -1,   573,    -1,    -1,    -1,    -1,   282,   283,   284,
      -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    19,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,
      -1,    -1,   613,    -1,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   626,    -1,    -1,    -1,   334,
      -1,    -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,
     355,    -1,   357,   358,   359,    -1,   361,    -1,    -1,    -1,
      -1,   366,    -1,    -1,    -1,   213,    -1,   372,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,   389,    -1,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
      -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,
     445,    -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   498,   499,   500,   501,    -1,   503,   347,
      -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,   521,   244,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,   539,    -1,    -1,    -1,    -1,    -1,
     545,    -1,   390,    -1,    -1,    -1,    -1,   552,    -1,   554,
     555,   556,   557,    -1,    -1,   282,   283,   284,    -1,   564,
     565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,
     418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,   436,    -1,
      -1,    -1,   319,    16,    17,    -1,    19,    -1,    21,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,   334,   613,    -1,
      -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,
      -1,   626,    -1,    -1,   351,    -1,    -1,    -1,   355,    -1,
     357,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,   389,    -1,    -1,   392,    -1,    -1,    -1,    -1,
     518,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,    -1,
      -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,    -1,
      -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,    -1,
     457,   458,    -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   520,   521,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     537,    -1,   539,    -1,    -1,    -1,    -1,    -1,   545,    -1,
      -1,   244,    -1,    -1,    -1,   552,    -1,   554,   555,   556,
     557,    -1,    -1,    -1,    -1,   258,    -1,   564,   565,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,   282,
     283,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    19,    -1,    21,    -1,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,
      -1,   314,    -1,    -1,    -1,    -1,   319,    -1,    -1,   626,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   334,    -1,    -1,    -1,    -1,   339,    -1,   341,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,    -1,   355,    -1,   357,   358,   359,    -1,   361,    -1,
      -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,   372,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,   389,    -1,    -1,   392,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
     443,    -1,   445,    -1,    -1,    -1,    -1,   450,    -1,    -1,
     453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,   521,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,    -1,   539,    -1,    -1,    -1,
      -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,    -1,   552,
      -1,   554,   555,   556,   557,    -1,    -1,   282,   283,   284,
      -1,   564,   565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     583,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,   314,
      19,    -1,    21,    -1,   319,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,
     613,    -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,
      -1,    -1,    -1,   626,    -1,    -1,   351,    -1,    -1,    -1,
     355,    -1,   357,   358,   359,    -1,   361,    -1,    -1,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,   389,    -1,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
      -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,
     445,    -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   498,   499,   500,   501,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,   521,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,   539,   244,    -1,    -1,    -1,    -1,
     545,    -1,    -1,    -1,    -1,    -1,    -1,   552,    -1,   554,
     555,   556,   557,    -1,    -1,    -1,    -1,    -1,    -1,   564,
     565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,
      21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,   613,    -1,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   626,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,
     339,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,    -1,   357,   358,
     359,    -1,   361,    -1,    -1,    -1,    -1,   366,    -1,    -1,
      -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
     389,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,   444,   445,    -1,    -1,    -1,
      -1,   450,    -1,    -1,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,   521,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
     539,    -1,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,
      -1,    -1,    -1,   552,    -1,   554,   555,   556,   557,    -1,
      -1,   282,   283,   284,    -1,   564,   565,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   573,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,   314,    19,    -1,    21,    -1,   319,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   334,   613,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,   626,    -1,    -1,
     351,    -1,    -1,    -1,   355,    -1,   357,   358,   359,    -1,
     361,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,   389,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,    -1,    -1,    -1,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   432,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,   445,    -1,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,   539,   244,
      -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,
      -1,   552,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,   564,   565,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   573,    -1,    -1,    -1,    -1,   282,   283,   284,
      -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    19,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,
      -1,    -1,   613,    -1,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   626,    -1,    -1,    -1,   334,
      -1,    -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,
     355,    -1,   357,   358,   359,    -1,   361,    -1,    -1,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,   389,    -1,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
      -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,
     445,    -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   498,   499,   500,   501,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,   521,   244,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,   539,    -1,    -1,    16,    17,    -1,
     545,    -1,    -1,    -1,    -1,    -1,    25,   552,    -1,   554,
     555,   556,   557,    -1,    -1,   282,   283,   284,    -1,   564,
     565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,
      -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,   613,    -1,
      -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,
      -1,   626,    -1,    -1,   351,    -1,    -1,    -1,   355,    -1,
     357,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,   389,    -1,    -1,   392,    -1,    -1,    -1,    -1,
      19,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,    -1,
      -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,   445,    -1,
      -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,    -1,
     457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   520,   521,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,
     537,    -1,   539,    -1,    -1,    -1,    -1,    -1,   545,    -1,
      -1,    -1,    -1,    -1,    -1,   552,    -1,   554,   555,   556,
     557,    -1,    -1,    -1,    -1,   314,    -1,   564,   565,    -1,
     319,    -1,    -1,    -1,    -1,    -1,   573,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   334,   583,    -1,    -1,    -1,
     339,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,   358,
     359,    -1,   361,    -1,    -1,    -1,   613,   366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,   626,
      21,    -1,    -1,    24,    25,   384,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,   410,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,   314,    -1,    -1,    -1,    -1,
     319,   450,    -1,    -1,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,
     339,    -1,   341,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,   358,
     359,    -1,   361,    -1,    -1,    -1,    -1,   366,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
      -1,   520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,   537,    -1,
      -1,   410,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,   554,   555,   556,   557,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,
      -1,   450,    -1,    -1,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,   314,    -1,    -1,   545,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,   554,   555,   556,   557,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,   613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   625,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,    -1,    -1,    -1,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    24,    -1,    -1,    -1,   448,    -1,   450,
      -1,    -1,   453,   454,   455,   244,   457,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,
     319,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   334,    -1,    -1,    -1,    -1,
     339,    -1,   341,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,   358,
     359,    -1,   361,    24,    -1,    -1,    -1,   366,    -1,    -1,
      -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,   613,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,   410,    -1,    -1,    -1,   626,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,
      -1,   450,    -1,   244,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,   521,   314,    -1,    -1,    -1,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,   334,    -1,    -1,   545,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,   554,   555,   556,   557,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    24,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,   583,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,   613,    -1,    -1,    -1,    -1,   410,
      -1,   282,   283,   284,    -1,    -1,    -1,   626,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   314,    -1,    -1,    -1,    -1,   319,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    24,    -1,    -1,    -1,   366,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   537,    -1,    -1,   410,
      -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,   549,    -1,
     421,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,   432,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,   450,
      -1,   244,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,    -1,    -1,    -1,   626,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,   314,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,   334,    -1,    -1,   545,    -1,   339,    -1,   341,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,   351,    -1,
      -1,    -1,   355,    -1,    -1,   358,   359,    -1,   361,    24,
      -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,   613,    -1,    -1,    -1,    -1,   410,    -1,   282,
     283,   284,    -1,    -1,    -1,   626,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
     443,   314,    -1,    -1,    -1,    -1,   319,   450,    -1,    -1,
     453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,    -1,
      -1,   334,    -1,    -1,    -1,    -1,   339,    -1,   341,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,    -1,   355,    -1,    -1,   358,   359,    -1,   361,    24,
      -1,    -1,    -1,   366,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,    -1,   520,   521,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,    -1,    -1,   537,    -1,   539,   410,    -1,    -1,
      -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,   554,   555,   556,   557,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,   244,
     453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,   284,
      -1,    -1,    -1,   626,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,   521,   314,
      -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,   334,
      -1,    -1,   545,    -1,   339,    -1,   341,    -1,    -1,    -1,
      -1,   554,   555,   556,   557,    -1,   351,    -1,    -1,    -1,
     355,    -1,    -1,   358,   359,    -1,   361,    24,    -1,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
     613,    -1,    -1,    -1,    -1,   410,    -1,   282,   283,   284,
      -1,    -1,    -1,   626,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,   314,
      -1,    -1,    -1,    -1,   319,   450,    -1,    -1,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,   334,
      -1,    -1,    -1,    -1,   339,    -1,   341,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,
     355,    -1,    -1,   358,   359,    -1,   361,    24,    -1,    -1,
      -1,   366,    -1,   498,   499,   500,   501,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,    -1,   520,   521,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
      -1,    -1,   537,    -1,    -1,   410,    -1,    -1,    -1,    -1,
     545,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,   554,
     555,   556,   557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,    -1,    -1,    -1,   450,    -1,   244,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,
      -1,   626,    -1,   498,   499,   500,   501,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,   521,   314,    -1,    -1,
      -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,    -1,    -1,    -1,   334,    -1,    -1,
     545,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,   554,
     555,   556,   557,    -1,   351,    -1,    -1,    -1,   355,    -1,
      -1,   358,   359,    -1,   361,    24,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,    -1,    -1,   403,   404,   613,    -1,
      -1,    -1,    -1,   410,    -1,   282,   283,   284,    -1,    -1,
      -1,   626,    -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,   443,   314,    -1,    -1,
      -1,    -1,   319,   450,    -1,    -1,   453,   454,   455,    -1,
     457,   458,    -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,
      -1,    -1,   339,    -1,   341,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,   355,    -1,
      -1,   358,   359,    -1,   361,    24,    -1,    -1,    -1,   366,
      -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,    -1,   520,   521,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,    -1,
     537,    -1,    -1,   410,    -1,    -1,    -1,    -1,   545,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,   554,   555,   556,
     557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,
      -1,    -1,    -1,   450,    -1,   244,   453,   454,   455,    -1,
     457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,    -1,    -1,   626,
      -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   520,   521,   314,    -1,    -1,    -1,    -1,
     319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,    -1,   334,    -1,    -1,   545,    -1,
     339,    -1,   341,    -1,    -1,    -1,    -1,   554,   555,   556,
     557,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,   358,
     359,    -1,   361,    24,    -1,    -1,    -1,   366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,   613,    -1,    -1,    -1,
      -1,   410,    -1,   282,   283,   284,    -1,    -1,    -1,   626,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,   314,    -1,    -1,    -1,    -1,
     319,   450,    -1,    -1,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,
     339,    -1,   341,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,   358,
     359,    -1,   361,    24,    -1,    -1,    -1,   366,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
      -1,   520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,   537,    -1,
      -1,   410,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,   554,   555,   556,   557,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,
      -1,   450,    -1,   244,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,    -1,    -1,   626,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,   521,   314,    -1,    -1,    -1,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,   334,    -1,    -1,   545,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,   554,   555,   556,   557,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    25,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,   613,    -1,    -1,    -1,    -1,   410,
      -1,   282,   283,   284,    -1,    -1,    -1,   626,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   314,    -1,    -1,    -1,    -1,   319,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    25,    -1,    -1,   366,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   537,    -1,    -1,   410,
      -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,   450,
      -1,   244,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,    -1,    -1,    -1,   626,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,   314,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,   334,    -1,    -1,   545,    -1,   339,    -1,   341,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,   351,    -1,
      -1,    -1,   355,    -1,    -1,   358,   359,    -1,   361,    -1,
      25,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,   613,    -1,    -1,    -1,    -1,   410,    -1,   282,
     283,   284,    -1,    -1,    -1,   626,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
     443,   314,    -1,    -1,    -1,    -1,   319,   450,    -1,    -1,
     453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,   462,
      -1,   334,    -1,    -1,    -1,    -1,   339,    -1,   341,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,    -1,   355,    -1,    -1,   358,   359,    -1,   361,    -1,
      25,    -1,    -1,   366,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,    -1,   516,    -1,    -1,    -1,   520,   521,   392,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,    -1,    -1,   537,    -1,    -1,   410,    -1,    -1,
      -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,   554,   555,   556,   557,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,   244,
     453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,   284,
      -1,    -1,    -1,   626,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,   521,   314,
      -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,   334,
      -1,    -1,   545,    -1,   339,    -1,   341,    -1,    -1,    -1,
      -1,   554,   555,   556,   557,    -1,   351,    -1,    -1,    -1,
     355,    -1,    -1,   358,   359,    -1,   361,    -1,    25,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
     613,    -1,    -1,    -1,    -1,   410,    -1,   282,   283,   284,
      -1,    -1,    -1,   626,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,   314,
      -1,    -1,    -1,    -1,   319,   450,    -1,    -1,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,   334,
      -1,    -1,    -1,    -1,   339,    -1,   341,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,
     355,    -1,    -1,   358,   359,    -1,   361,    -1,    -1,    -1,
      -1,   366,    -1,   498,   499,   500,   501,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,    -1,   520,   521,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
      -1,    -1,   537,    -1,    -1,   410,    -1,    -1,    -1,    -1,
     545,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,   554,
     555,   556,   557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,    -1,    -1,    -1,   450,    -1,   244,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,
      -1,   626,    -1,   498,   499,   500,   501,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,   521,   314,    -1,    -1,
      -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,    -1,    -1,    -1,   334,    -1,    -1,
     545,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,   554,
     555,   556,   557,    -1,   351,    -1,    -1,    -1,   355,    -1,
      -1,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,    -1,    -1,   403,   404,   613,    -1,
      -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   626,    -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,
      -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,    -1,
     457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,
      -1,    -1,    -1,   520,   521,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
     537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,
      67,    68,    69,    -1,    -1,    -1,    -1,   554,   555,   556,
     557,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,
      -1,    -1,   119,    -1,   121,   122,    -1,   124,    -1,   126,
     127,    -1,    -1,   130,   131,   132,   613,    -1,   135,   136,
     137,    -1,   139,   140,    -1,    -1,    -1,   144,   145,   626,
     147,    -1,    -1,    -1,   151,    -1,   153,   154,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,   164,    -1,   166,
      -1,   168,    -1,   170,    -1,   172,   173,    -1,   175,   176,
     177,    -1,    -1,    -1,   181,    -1,   183,   184,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,    -1,
      -1,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,   243,    -1,   245,    -1,
      -1,    -1,   249,   250,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,   276,
     277,    -1,    -1,    -1,    -1,   282,    -1,    -1,   285,    -1,
      -1,    -1,   289,   290,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,
      -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,
      -1,    -1,    -1,    -1,    -1,   362,    -1,   364,   365,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,
     427,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,    -1,
      -1,    -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,
     477,   478,   479,   480,    -1,    -1,   483,    -1,    -1,    -1,
      -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,   495,   496,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     507,    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   520,    -1,    -1,   523,    -1,    -1,   526,
      -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,    -1,    -1,   562,    -1,    -1,    -1,    -1,
      -1,   568,    -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   585,    -1,
      -1,    -1,    28,    -1,    -1,   592,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,   610,   611,   612,   613,   614,   615,   616,
      56,    -1,   619,    -1,   621,    -1,   623,   624,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,   110,   111,    -1,   113,   114,    -1,
      -1,    -1,    -1,   119,    -1,   121,   122,    -1,   124,    -1,
     126,   127,    -1,    -1,   130,   131,   132,    -1,    -1,   135,
     136,   137,    -1,   139,   140,    -1,    -1,    -1,   144,   145,
      -1,   147,    -1,    -1,    -1,   151,    -1,   153,   154,    -1,
      -1,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,    -1,
     166,    -1,   168,    -1,   170,    -1,   172,   173,    -1,   175,
     176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
      -1,    -1,    -1,    -1,   200,    -1,   202,    -1,    -1,    -1,
      -1,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
      -1,    -1,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,   241,   242,   243,    -1,   245,
      -1,    -1,    -1,   249,   250,    -1,    -1,    -1,   254,    -1,
     256,    -1,    -1,    -1,    -1,   261,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,   271,    -1,    -1,    -1,    -1,
     276,   277,   278,    -1,    -1,    -1,   282,    -1,    -1,   285,
      -1,    -1,    -1,   289,   290,    -1,    -1,    -1,    -1,    -1,
      -1,   297,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,
      -1,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,
      -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
      -1,    -1,    -1,    -1,   360,    -1,   362,    -1,   364,   365,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,   375,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,
      -1,   427,    -1,    -1,   430,    -1,   432,    -1,    -1,    -1,
      -1,    -1,    -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,
      -1,    -1,    -1,   459,    -1,   461,    -1,    -1,   464,    -1,
     466,    -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,
      -1,   477,   478,   479,   480,    -1,    -1,   483,    -1,    -1,
      -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,   495,
     496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   507,    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,    -1,   523,    -1,    -1,
     526,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   559,    -1,    -1,   562,    -1,    -1,    -1,
      -1,    -1,   568,    -1,    -1,   571,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   585,
      -1,    -1,    -1,    28,    -1,    -1,   592,    32,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,   610,   611,   612,   613,   614,   615,
     616,    56,    -1,   619,    -1,   621,    -1,   623,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,   110,   111,    -1,   113,   114,
      -1,    -1,    -1,    -1,   119,    -1,   121,   122,    -1,   124,
      -1,   126,   127,    -1,    -1,   130,   131,   132,    -1,    -1,
     135,   136,   137,    -1,   139,   140,    -1,    -1,    -1,   144,
     145,    -1,   147,    -1,    -1,    -1,   151,    -1,   153,   154,
      -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,
      -1,   166,    -1,   168,    -1,   170,    -1,   172,   173,    -1,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,    -1,   210,   211,    -1,    -1,   214,
     215,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,   229,    -1,   231,    -1,    -1,   234,
      -1,    -1,   237,    -1,   239,    -1,   241,   242,   243,    -1,
     245,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,
      -1,   276,   277,    -1,    -1,    -1,    -1,   282,    -1,    -1,
     285,   286,    -1,    -1,   289,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   308,    -1,    -1,    -1,   312,    -1,    -1,
      -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     325,    -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     355,    -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,   364,
     365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,
      -1,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,
     455,    -1,    -1,    -1,   459,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,
      -1,    -1,   477,   478,   479,   480,    -1,    -1,   483,    -1,
      -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,
     495,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   507,    -1,   509,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,   523,    -1,
      -1,   526,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,    -1,    -1,   562,    -1,    -1,
      -1,    -1,    -1,   568,    -1,    -1,   571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     585,    -1,    -1,    -1,    28,    -1,    -1,   592,    32,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,   610,   611,   612,   613,   614,
     615,   616,    56,    -1,   619,    -1,   621,   622,   623,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,   110,   111,    -1,   113,
     114,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,    -1,    -1,   130,   131,   132,    -1,
      -1,   135,   136,   137,    -1,   139,   140,    -1,    -1,    -1,
     144,   145,    -1,   147,    -1,    -1,    -1,   151,    -1,   153,
     154,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,   163,
     164,   165,   166,    -1,   168,    -1,   170,    -1,   172,   173,
      -1,   175,   176,   177,    -1,    -1,   180,   181,    -1,   183,
     184,    -1,   186,    -1,   188,    -1,    -1,    -1,   192,    -1,
     194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,   243,
      -1,   245,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,
      -1,    -1,   276,   277,    -1,    -1,    -1,    -1,   282,    -1,
      -1,   285,    -1,    -1,    -1,   289,   290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   325,    -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,
     364,   365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,
      -1,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     454,   455,    -1,    -1,    -1,   459,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,
      -1,    -1,    -1,   477,   478,   479,   480,    -1,    -1,   483,
      -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,
      -1,   495,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   507,    -1,   509,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,   523,
      -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,   532,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,   562,    -1,
      -1,    -1,    -1,    -1,   568,    -1,    -1,   571,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   585,    -1,    -1,    -1,    28,    -1,    -1,   592,    32,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,   610,   611,   612,   613,
     614,   615,   616,    56,    -1,   619,    -1,   621,    -1,   623,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,   110,   111,    -1,
     113,   114,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,    -1,   129,   130,   131,   132,
     133,    -1,   135,   136,   137,    -1,   139,   140,    -1,    -1,
      -1,   144,   145,    -1,   147,    -1,    -1,    -1,   151,    -1,
     153,   154,   155,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,   164,    -1,   166,    -1,   168,    -1,   170,    -1,   172,
     173,    -1,   175,   176,   177,    -1,    -1,    -1,   181,    -1,
     183,   184,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,    -1,    -1,   210,   211,    -1,
      -1,   214,   215,    -1,    -1,   218,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,    -1,
      -1,   234,    -1,    -1,   237,    -1,    -1,    -1,   241,   242,
     243,    -1,   245,    -1,    -1,    -1,   249,   250,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,   276,   277,    -1,    -1,    -1,    -1,   282,
      -1,    -1,   285,    -1,    -1,    -1,   289,   290,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,   331,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,   362,
      -1,   364,   365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     423,    -1,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,    -1,    -1,    -1,   459,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,
      -1,    -1,    -1,    -1,   477,   478,   479,   480,    -1,    -1,
     483,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,
      -1,    -1,   495,   496,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   507,    -1,   509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,
     523,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,   562,
      -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,   571,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,    -1,    28,    -1,    -1,   592,
      32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,   610,   611,   612,
     613,   614,   615,   616,    56,    57,   619,    -1,   621,    -1,
     623,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,   110,   111,
      -1,   113,   114,    -1,    -1,    -1,    -1,   119,    -1,   121,
     122,    -1,   124,    -1,   126,   127,    -1,    -1,   130,   131,
     132,    -1,    -1,   135,   136,   137,    -1,   139,   140,    -1,
      -1,    -1,   144,   145,    -1,   147,    -1,    -1,    -1,   151,
      -1,   153,   154,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,   164,    -1,   166,    -1,   168,    -1,   170,    -1,
     172,   173,    -1,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,   183,   184,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,   210,   211,
      -1,    -1,   214,   215,    -1,    -1,   218,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,   243,    -1,   245,    -1,    -1,    -1,   249,   250,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
      -1,    -1,    -1,    -1,   276,   277,    -1,    -1,    -1,    -1,
     282,    -1,    -1,   285,    -1,    -1,    -1,   289,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,   331,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,
     362,    -1,   364,   365,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   423,    -1,    -1,    -1,   427,    -1,    -1,   430,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   454,   455,    -1,    -1,    -1,   459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,
      -1,    -1,    -1,    -1,    -1,   477,   478,   479,   480,    -1,
      -1,   483,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,
      -1,    -1,    -1,   495,   496,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   507,    -1,   509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,    -1,
      -1,   523,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,
     562,    -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,   571,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   585,    -1,    -1,    -1,    28,    -1,    -1,
     592,    32,    -1,    34,    -1,   597,   598,   599,   600,   601,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,   610,   611,
     612,   613,   614,   615,   616,    56,    -1,   619,    -1,   621,
      -1,   623,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,   110,
     111,    -1,   113,   114,    -1,    -1,    -1,    -1,   119,    -1,
     121,   122,    -1,   124,    -1,   126,   127,    -1,    -1,   130,
     131,   132,    -1,    -1,   135,   136,   137,    -1,   139,   140,
      -1,    -1,    -1,   144,   145,    -1,   147,    -1,    -1,    -1,
     151,    -1,   153,   154,    -1,    -1,   157,    -1,    -1,    -1,
     161,    -1,    -1,   164,    -1,   166,    -1,   168,    -1,   170,
      -1,   172,   173,    -1,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,   183,   184,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,    -1,    -1,   218,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,   243,    -1,   245,    -1,    -1,    -1,   249,   250,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,
      -1,    -1,    -1,    -1,    -1,   276,   277,    -1,    -1,    -1,
      -1,   282,    -1,    -1,   285,   286,    -1,    -1,   289,   290,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,
     331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,
      -1,   362,    -1,   364,   365,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   423,    -1,    -1,    -1,   427,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,    -1,    -1,    -1,   459,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     471,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,   480,
      -1,    -1,   483,    -1,    -1,    -1,    -1,   488,    -1,    -1,
      -1,    -1,    -1,    -1,   495,   496,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,   509,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
      -1,    -1,   523,    -1,    -1,   526,    -1,    -1,    -1,    -1,
      -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,
      -1,   562,    -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,
     571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   585,    -1,    -1,   588,    28,    -1,
      -1,   592,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,   602,   603,    -1,    -1,    -1,    -1,    47,    -1,   610,
     611,   612,   613,   614,   615,   616,    56,    -1,   619,    -1,
     621,   622,   623,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,
     110,   111,    -1,   113,   114,    -1,    -1,    -1,    -1,   119,
      -1,   121,   122,    -1,   124,    -1,   126,   127,    -1,    -1,
     130,   131,   132,    -1,    -1,   135,   136,   137,    -1,   139,
     140,    -1,    -1,    -1,   144,   145,    -1,   147,    -1,    -1,
      -1,   151,    -1,   153,   154,    -1,    -1,   157,    -1,    -1,
      -1,   161,    -1,    -1,   164,    -1,   166,    -1,   168,    -1,
     170,    -1,   172,   173,    -1,   175,   176,   177,    -1,    -1,
      -1,   181,    -1,   183,   184,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,   242,   243,    -1,   245,    -1,    -1,    -1,   249,
     250,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,    -1,    -1,    -1,    -1,   276,   277,    -1,    -1,
      -1,    -1,   282,    -1,    -1,   285,    -1,    -1,    -1,   289,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,
      -1,    -1,   312,    -1,    -1,    -1,    -1,   317,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,
      -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,
      -1,    -1,   362,    -1,   364,   365,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   423,    -1,    -1,    -1,   427,    -1,    -1,
     430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   454,   455,    -1,    -1,    -1,   459,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   471,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,
     480,    -1,    -1,   483,    -1,    -1,    -1,    -1,   488,    -1,
      -1,    -1,    -1,    -1,    -1,   495,   496,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,   509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     520,    -1,    -1,   523,    -1,    -1,   526,    -1,    -1,    -1,
      -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,   568,    -1,
      -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   585,    -1,    -1,    -1,    28,
      -1,    -1,   592,    32,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
     610,   611,   612,   613,   614,   615,   616,    56,    -1,   619,
      -1,   621,    -1,   623,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,   107,    -1,
     109,   110,   111,    -1,   113,   114,    -1,    -1,    -1,    -1,
     119,    -1,   121,   122,    -1,   124,    -1,   126,   127,    -1,
      -1,   130,   131,   132,    -1,    -1,   135,   136,   137,    -1,
     139,   140,    -1,    -1,    -1,   144,   145,    -1,   147,    -1,
      -1,    -1,   151,    -1,   153,   154,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,   168,
      -1,   170,    -1,   172,   173,    -1,   175,   176,   177,    -1,
      -1,    -1,   181,    -1,   183,   184,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,   210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
     229,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,   243,    -1,   245,    -1,    -1,    -1,
     249,   250,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,    -1,    -1,    -1,    -1,   276,   277,    -1,
      -1,    -1,    -1,   282,    -1,    -1,   285,    -1,    -1,    -1,
     289,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,    -1,    -1,
      -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,
      -1,    -1,    -1,   362,    -1,   364,   365,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,   427,    -1,
      -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,    -1,    -1,    -1,
     459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,   480,    -1,    -1,   483,    -1,    -1,    -1,    -1,   488,
      -1,    -1,    -1,    -1,    -1,    -1,   495,   496,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,
     509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,    -1,    -1,   523,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,   568,
      -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   585,    -1,    -1,   588,
      28,    -1,    -1,   592,    32,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   605,   606,    -1,    47,
      -1,   610,   611,   612,   613,   614,   615,   616,    56,    -1,
     619,    -1,   621,    -1,   623,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,    -1,
      -1,   119,    -1,   121,   122,    -1,   124,    -1,   126,   127,
      -1,    -1,   130,   131,   132,    -1,    -1,   135,   136,   137,
      -1,   139,   140,    -1,    -1,    -1,   144,   145,    -1,   147,
      -1,    -1,    -1,   151,    -1,   153,   154,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,
     168,    -1,   170,    -1,   172,   173,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,   183,   184,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,   210,   211,    -1,    -1,   214,   215,    -1,    -1,
     218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,   229,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,   243,    -1,   245,    -1,    -1,
      -1,   249,   250,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,   276,   277,
      -1,    -1,    -1,    -1,   282,    -1,    -1,   285,    -1,    -1,
      -1,   289,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,
      -1,    -1,    -1,   321,    -1,    -1,    -1,   325,    -1,    -1,
      -1,    -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,
      -1,    -1,    -1,    -1,   362,    -1,   364,   365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,   427,
      -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   454,   455,    -1,    -1,
      -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,   477,
     478,   479,   480,    -1,    -1,   483,    -1,    -1,    -1,    -1,
     488,    -1,    -1,    -1,    -1,    -1,    -1,   495,   496,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,
      -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   520,    -1,    -1,   523,    -1,    -1,   526,    -1,
      -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,
     568,    -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   585,    -1,    -1,
      -1,    28,    -1,    -1,   592,    32,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,   610,   611,   612,   613,   614,   615,   616,    56,
      -1,   619,    -1,   621,    -1,   623,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,
      -1,    -1,   119,    -1,   121,   122,    -1,   124,    -1,   126,
     127,    -1,    -1,   130,   131,   132,    -1,    -1,   135,   136,
     137,    -1,   139,   140,    -1,    -1,    -1,   144,   145,    -1,
     147,    -1,    -1,    -1,   151,    -1,   153,   154,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,   164,    -1,   166,
      -1,   168,    -1,   170,    -1,   172,   173,    -1,   175,   176,
     177,    -1,    -1,    -1,   181,    -1,   183,   184,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,    -1,
      -1,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,   243,    -1,   245,    -1,
      -1,    -1,   249,   250,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,   276,
     277,    -1,    -1,    -1,    -1,   282,    -1,    -1,   285,    -1,
      -1,    -1,   289,   290,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,   323,    -1,   325,    -1,
      -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,   355,    -1,
      -1,    -1,    -1,    -1,    -1,   362,    -1,   364,   365,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,
     427,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,    -1,
      -1,    -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,
     477,   478,   479,   480,    -1,    -1,   483,    -1,    -1,    -1,
      -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,   495,   496,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     507,    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   520,    -1,    -1,   523,    -1,    -1,   526,
      -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,    -1,    -1,   562,    -1,    -1,    -1,    -1,
      -1,   568,    -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   585,    -1,
      -1,    -1,    28,    -1,    -1,   592,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,   610,   611,   612,   613,   614,   615,   616,
      56,    -1,   619,    -1,   621,    -1,   623,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,   110,   111,    -1,   113,   114,    -1,
      -1,    -1,    -1,   119,    -1,   121,   122,    -1,   124,    -1,
     126,   127,    -1,    -1,   130,   131,   132,    -1,    -1,   135,
     136,   137,    -1,   139,   140,    -1,    -1,    -1,   144,   145,
      -1,   147,    -1,    -1,    -1,   151,    -1,   153,   154,    -1,
      -1,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,    -1,
     166,    -1,   168,    -1,   170,    -1,   172,   173,    -1,   175,
     176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
      -1,    -1,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,   242,   243,    -1,   245,
      -1,    -1,    -1,   249,   250,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,
     276,   277,    -1,    -1,    -1,    -1,   282,    -1,    -1,   285,
      -1,    -1,    -1,   289,   290,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,
      -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
      -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,   364,   365,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,
      -1,   427,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,
      -1,    -1,    -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,
      -1,   477,   478,   479,   480,    -1,    -1,   483,    -1,    -1,
      -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,   495,
     496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   507,    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,    -1,   523,    -1,    -1,
     526,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   559,    -1,    -1,   562,    -1,    -1,    -1,
      -1,    -1,   568,    -1,    -1,   571,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   585,
      -1,    -1,    -1,    28,    -1,    -1,   592,    32,    -1,    34,
      -1,   597,    -1,    -1,   600,   601,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,   610,   611,   612,   613,   614,   615,
     616,    56,    -1,   619,    -1,   621,    -1,   623,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,   110,   111,    -1,   113,   114,
      -1,    -1,    -1,    -1,   119,    -1,   121,   122,    -1,   124,
      -1,   126,   127,    -1,    -1,   130,   131,   132,    -1,    -1,
     135,   136,   137,    -1,   139,   140,    -1,    -1,    -1,   144,
     145,    -1,   147,    -1,    -1,    -1,   151,    -1,   153,   154,
      -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,
      -1,   166,    -1,   168,    -1,   170,    -1,   172,   173,    -1,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,    -1,   210,   211,    -1,    -1,   214,
     215,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,   229,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,   243,    -1,
     245,   246,    -1,    -1,   249,   250,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,
      -1,   276,   277,    -1,    -1,    -1,    -1,   282,    -1,    -1,
     285,    -1,    -1,    -1,   289,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     325,    -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     355,    -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,   364,
     365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,
      -1,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,
     455,    -1,    -1,    -1,   459,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,
      -1,    -1,   477,   478,   479,   480,    -1,    -1,   483,    -1,
      -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,
     495,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   507,    -1,   509,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,   523,    -1,
      -1,   526,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,    -1,    -1,   562,    -1,    -1,
      -1,    -1,    -1,   568,    -1,    -1,   571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     585,    -1,    -1,    -1,    28,    -1,    -1,   592,    32,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,   610,   611,   612,   613,   614,
     615,   616,    56,    -1,   619,    -1,   621,    -1,   623,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,   110,   111,    -1,   113,
     114,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,    -1,    -1,   130,   131,   132,    -1,
      -1,   135,   136,   137,    -1,   139,   140,    -1,    -1,    -1,
     144,   145,    -1,   147,    -1,    -1,    -1,   151,    -1,   153,
     154,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
     164,    -1,   166,    -1,   168,    -1,   170,    -1,   172,   173,
      -1,   175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,
     184,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,   243,
      -1,   245,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,
      -1,    -1,   276,   277,    -1,    -1,    -1,    -1,   282,    -1,
      -1,   285,    -1,    -1,    -1,   289,   290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   325,    -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,
     364,   365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,
      -1,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     454,   455,    -1,    -1,    -1,   459,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,
      -1,    -1,    -1,   477,   478,   479,   480,    -1,    -1,   483,
      -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,
      -1,   495,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     504,    -1,    -1,   507,    -1,   509,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,   523,
      -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,   532,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,   562,    -1,
      -1,    -1,    -1,    -1,   568,    -1,    -1,   571,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   585,    -1,    -1,    -1,    28,    -1,    -1,   592,    32,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,   610,   611,   612,   613,
     614,   615,   616,    56,    -1,   619,    -1,   621,    -1,   623,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,   110,   111,    -1,
     113,   114,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,    -1,    -1,   130,   131,   132,
      -1,    -1,   135,   136,   137,    -1,   139,   140,    -1,    -1,
      -1,   144,   145,    -1,   147,    -1,    -1,    -1,   151,    -1,
     153,   154,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,   164,    -1,   166,    -1,   168,    -1,   170,    -1,   172,
     173,    -1,   175,   176,   177,    -1,    -1,    -1,   181,    -1,
     183,   184,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,    -1,    -1,   210,   211,    -1,
      -1,   214,   215,    -1,    -1,   218,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
     243,    -1,   245,    -1,    -1,    -1,   249,   250,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,   276,   277,    -1,    -1,    -1,    -1,   282,
      -1,    -1,   285,    -1,    -1,    -1,   289,   290,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,   322,
      -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,   331,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,   362,
      -1,   364,   365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     423,    -1,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,    -1,    -1,    -1,   459,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,
      -1,    -1,    -1,    -1,   477,   478,   479,   480,    -1,    -1,
     483,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,
      -1,    -1,   495,   496,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   507,    -1,   509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,
     523,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,   562,
      -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,   571,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,    -1,    28,    -1,    -1,   592,
      32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,   610,   611,   612,
     613,   614,   615,   616,    56,    -1,   619,    -1,   621,    -1,
     623,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,   110,   111,
      -1,   113,   114,    -1,    -1,    -1,    -1,   119,    -1,   121,
     122,    -1,   124,    -1,   126,   127,    -1,    -1,   130,   131,
     132,    -1,    -1,   135,   136,   137,    -1,   139,   140,    -1,
      -1,    -1,   144,   145,    -1,   147,    -1,    -1,    -1,   151,
      -1,   153,   154,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,   164,    -1,   166,    -1,   168,    -1,   170,    -1,
     172,   173,    -1,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,   183,   184,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,   210,   211,
      -1,    -1,   214,   215,    -1,    -1,   218,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,   243,    -1,   245,    -1,    -1,    -1,   249,   250,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
      -1,    -1,    -1,    -1,   276,   277,    -1,    -1,    -1,    -1,
     282,    -1,    -1,   285,    -1,   287,    -1,   289,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,   331,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,
     362,    -1,   364,   365,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   423,    -1,    -1,    -1,   427,    -1,    -1,   430,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   454,   455,    -1,    -1,    -1,   459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,
      -1,    -1,    -1,    -1,    -1,   477,   478,   479,   480,    -1,
      -1,   483,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,
      -1,    -1,    -1,   495,   496,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   507,    -1,   509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,    -1,
      -1,   523,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,
     562,    -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,   571,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   585,    -1,    -1,    -1,    28,    -1,    -1,
     592,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,   610,   611,
     612,   613,   614,   615,   616,    56,    -1,   619,    -1,   621,
      -1,   623,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,   110,
     111,    -1,   113,   114,    -1,    -1,    -1,    -1,   119,    -1,
     121,   122,    -1,   124,    -1,   126,   127,    -1,    -1,   130,
     131,   132,    -1,    -1,   135,   136,   137,    -1,   139,   140,
      -1,    -1,    -1,   144,   145,    -1,   147,    -1,    -1,    -1,
     151,    -1,   153,   154,    -1,    -1,   157,    -1,    -1,    -1,
     161,    -1,    -1,   164,    -1,   166,    -1,   168,    -1,   170,
      -1,   172,   173,    -1,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,   183,   184,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,    -1,    -1,   218,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,   243,    -1,   245,    -1,    -1,    -1,   249,   250,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,
      -1,    -1,    -1,    -1,    -1,   276,   277,    -1,    -1,    -1,
      -1,   282,    -1,    -1,   285,    -1,    -1,    -1,   289,   290,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,
     321,    -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,
     331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,
      -1,   362,    -1,   364,   365,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   423,    -1,    -1,    -1,   427,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,    -1,    -1,    -1,   459,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     471,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,   480,
      -1,    -1,   483,    -1,    -1,    -1,    -1,   488,    -1,    -1,
      -1,    -1,    -1,    -1,   495,   496,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,   509,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
      -1,    -1,   523,    -1,    -1,   526,    -1,    -1,    -1,    -1,
      -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,
      -1,   562,    -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,
     571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   585,    -1,    -1,    -1,    28,    -1,
      -1,   592,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,   610,
     611,   612,   613,   614,   615,   616,    56,    -1,   619,    -1,
     621,    -1,   623,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,
     110,   111,    -1,   113,   114,    -1,    -1,    -1,    -1,   119,
      -1,   121,   122,    -1,   124,    -1,   126,   127,    -1,    -1,
     130,   131,   132,    -1,    -1,   135,   136,   137,    -1,   139,
     140,    -1,    -1,    -1,   144,   145,    -1,   147,    -1,    -1,
      -1,   151,    -1,   153,   154,    -1,    -1,   157,    -1,    -1,
      -1,   161,    -1,    -1,   164,    -1,   166,    -1,   168,    -1,
     170,    -1,   172,   173,    -1,   175,   176,   177,    -1,    -1,
      -1,   181,    -1,   183,   184,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,    -1,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,   242,   243,    -1,   245,    -1,    -1,    -1,   249,
     250,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,    -1,    -1,    -1,    -1,   276,   277,    -1,    -1,
      -1,    -1,   282,    -1,    -1,   285,    -1,    -1,    -1,   289,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,
      -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,
      -1,    -1,   362,    -1,   364,   365,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   423,    -1,    -1,    -1,   427,    -1,    -1,
     430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   454,   455,    -1,    -1,    -1,   459,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   471,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,
     480,    -1,    -1,   483,    -1,    -1,    -1,    -1,   488,    -1,
      -1,    -1,    -1,    -1,    -1,   495,   496,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,   509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     520,    -1,    -1,   523,    -1,    -1,   526,    -1,    -1,    -1,
      -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,   568,    -1,
      -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   585,    -1,    -1,    -1,    28,
      -1,    -1,   592,    32,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
     610,   611,   612,   613,   614,   615,   616,    56,    -1,   619,
      -1,   621,    -1,   623,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,   107,    -1,
     109,   110,   111,    -1,   113,   114,    -1,    -1,    -1,    -1,
     119,    -1,   121,   122,    -1,   124,    -1,   126,   127,    -1,
      -1,   130,   131,   132,    -1,    -1,   135,   136,   137,    -1,
     139,   140,    -1,    -1,    -1,   144,   145,    -1,   147,    -1,
      -1,    -1,   151,    -1,   153,   154,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,   168,
      -1,   170,    -1,   172,   173,    -1,   175,   176,   177,    -1,
      -1,    -1,   181,    -1,   183,   184,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,   210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
     229,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,   243,    -1,   245,    -1,    -1,    -1,
     249,   250,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,    -1,    -1,    -1,    -1,   276,   277,    -1,
      -1,    -1,    -1,   282,    -1,    -1,   285,    -1,    -1,    -1,
     289,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,    -1,    -1,
      -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,
      -1,    -1,    -1,   362,    -1,   364,   365,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,   427,    -1,
      -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,    -1,    -1,    -1,
     459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,   480,    -1,    -1,   483,    -1,    -1,    -1,    -1,   488,
      -1,    -1,    -1,    -1,    -1,    -1,   495,   496,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,
     509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,    -1,    -1,   523,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,   568,
      -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   585,    -1,    -1,    -1,
      28,    -1,    -1,   592,    32,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,   610,   611,   612,   613,   614,   615,   616,    56,    -1,
     619,    -1,   621,    -1,   623,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,    -1,
      -1,   119,    -1,   121,   122,    -1,   124,    -1,   126,   127,
      -1,    -1,   130,   131,   132,    -1,    -1,   135,   136,   137,
      -1,   139,   140,    -1,    -1,    -1,   144,   145,    -1,   147,
      -1,    -1,    -1,   151,    -1,   153,   154,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,
     168,    -1,   170,    -1,   172,   173,   174,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,   183,   184,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,   210,   211,    -1,    -1,   214,   215,    -1,    -1,
     218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,   229,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,   243,    -1,   245,    -1,    -1,
      -1,   249,   250,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,   276,   277,
      -1,    -1,    -1,    -1,   282,    -1,    -1,   285,    19,    -1,
      -1,   289,   290,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,    -1,
      -1,    -1,    -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,
      -1,    -1,    -1,    -1,   362,    -1,   364,   365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   412,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,   427,
      -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   454,   455,    -1,    -1,
      -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,   477,
     478,   479,   480,    -1,    -1,   483,    -1,    -1,    -1,    -1,
     488,    -1,    -1,    -1,    -1,    -1,    -1,   495,   496,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,
      -1,   509,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   520,    -1,    -1,   523,    -1,    -1,   526,    -1,
      -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,
     568,    -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   314,    -1,    -1,    -1,   585,   319,    -1,
      -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,   610,   611,   612,   613,   614,   615,   616,    -1,
     351,   619,    -1,   621,   355,   623,    -1,   358,   359,    -1,
     361,    -1,    -1,    -1,    -1,   366,    -1,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,    19,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   282,   283,   284,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,   314,    -1,
      -1,    -1,   443,   319,    -1,    -1,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,   334,    -1,
      -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,   351,    -1,    -1,    -1,   355,
      -1,    -1,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,
     366,    -1,    -1,   244,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,   520,
     521,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,
      -1,   282,   283,   284,   410,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
     436,    -1,    -1,   314,    -1,    -1,    -1,   443,   319,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,   613,    -1,    -1,   366,    -1,    -1,   244,    -1,
      -1,    -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   520,   521,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   282,   283,   284,   410,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,   555,
     556,   557,    -1,    -1,    -1,   436,    -1,    -1,   314,    -1,
      -1,    -1,   443,   319,    -1,    -1,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,   334,    -1,
      -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,   351,    -1,    -1,    -1,   355,
      -1,    -1,   358,   359,    -1,   361,    -1,   613,    -1,    -1,
     366,    -1,    -1,   244,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,   520,
     521,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,
      -1,   282,   283,   284,   410,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
     436,    -1,    -1,   314,    -1,    -1,    -1,   443,   319,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,   613,    -1,    -1,   366,    -1,    -1,   244,    -1,
      -1,    -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   520,   521,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   282,   283,   284,   410,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,   555,
     556,   557,    -1,    -1,    -1,   436,    -1,    -1,   314,    -1,
      -1,    -1,   443,   319,    -1,    -1,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,   334,    -1,
      -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,   351,    -1,    -1,    -1,   355,
      -1,    -1,   358,   359,    -1,   361,    -1,   613,    -1,    -1,
     366,    -1,    -1,   244,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,   520,
     521,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,
      -1,   282,   283,   284,   410,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
     436,    -1,    -1,   314,    -1,    -1,    -1,   443,   319,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,   613,    -1,    -1,   366,    -1,    -1,   244,    -1,
      -1,    -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   520,   521,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   282,   283,   284,   410,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,   555,
     556,   557,    -1,    -1,    -1,   436,    -1,    -1,   314,    -1,
      -1,    -1,   443,   319,    -1,    -1,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,   334,    -1,
      -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,   351,    -1,    -1,    -1,   355,
      -1,    -1,   358,   359,    -1,   361,    -1,   613,    -1,    -1,
     366,    -1,    -1,   244,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,
      -1,   282,   283,   284,   410,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
     436,    -1,    -1,   314,    -1,    -1,    -1,   443,   319,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,   613,    -1,    -1,   366,    -1,    -1,   244,    -1,
      -1,    -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,   521,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   282,   283,   284,   410,
      -1,   537,    -1,    24,    25,    -1,    -1,    -1,    -1,   545,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,   555,
     556,   557,    -1,    -1,    -1,   436,    -1,    -1,   314,    -1,
      -1,    -1,   443,   319,    -1,    -1,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,   334,    -1,
      -1,    -1,    73,   339,    -1,   341,    77,    -1,    -1,    80,
      -1,    -1,    -1,   474,    -1,   351,    -1,    -1,    -1,   355,
      -1,    -1,   358,   359,    -1,   361,    -1,   613,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,
      -1,    -1,    -1,    -1,   410,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
     436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,   498,   499,   500,   501,    -1,   503,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,   521,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,   554,   555,
     556,   557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,
     351,    -1,   353,    -1,   355,    -1,    24,   358,   359,    -1,
     361,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,    -1,    -1,    -1,   410,
      -1,    -1,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,
     421,    -1,   423,    -1,    -1,    -1,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,   450,
      -1,   244,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,   314,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    24,
      -1,   334,    -1,    -1,   545,    -1,   339,    -1,   341,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,   351,    -1,
      -1,    -1,   355,    -1,    -1,   358,   359,    -1,   361,    -1,
      -1,    -1,    -1,   366,   575,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,   613,    -1,   282,   283,   284,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,   437,    -1,   314,    -1,    -1,    -1,
     443,   319,    -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,
     453,   454,   455,    -1,   457,   458,   334,    -1,    -1,    -1,
      -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,
     358,   359,    -1,   361,    -1,    -1,    -1,    -1,   366,    -1,
      -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,   520,   521,    -1,
      -1,    -1,   400,    -1,    -1,   403,   404,    -1,    -1,    -1,
      -1,    -1,   410,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   545,   421,    -1,    -1,    -1,    -1,    -1,   244,
      -1,   554,   555,   556,   557,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,
      -1,    -1,   450,    -1,    -1,   453,   454,   455,    -1,   457,
     458,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,   284,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,   476,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,
     498,   499,   500,   501,   319,   503,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,   334,
      -1,    -1,   520,   521,   339,    -1,   341,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,   537,
     355,    -1,    -1,   358,   359,    -1,   361,   545,    -1,    -1,
      -1,   366,    -1,    -1,    -1,    -1,   554,   555,   556,   557,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,
      -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,   613,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
     282,   283,   284,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   314,   498,   499,   500,   501,   319,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,   334,    -1,    -1,   520,   521,   339,    -1,   341,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,
      -1,    -1,   537,   355,    -1,    -1,   358,   359,    -1,   361,
     545,    -1,    -1,    -1,   366,    -1,    -1,   244,    -1,   554,
     555,   556,   557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,
      -1,   403,   404,    -1,    -1,   282,   283,   284,   410,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,
      -1,    -1,    -1,    -1,   436,    -1,    -1,   314,    -1,    -1,
      -1,   443,   319,    -1,    -1,    -1,    -1,    -1,   450,    -1,
      -1,   453,   454,   455,    -1,   457,   458,   334,    -1,    -1,
      -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,    -1,   351,    -1,    -1,    -1,   355,    -1,
      -1,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,
      -1,   503,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,   520,   521,
      -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,    -1,
      -1,    -1,    -1,   410,    -1,   537,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   545,   421,    -1,    -1,    -1,    -1,    -1,
     244,    -1,   554,   555,   556,   557,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,
      -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,    -1,
     457,   458,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,
     284,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     314,   498,   499,   500,   501,   319,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
     334,    -1,    -1,   520,   521,   339,    -1,   341,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,
     537,   355,    -1,    -1,   358,   359,    -1,   361,   545,    -1,
      -1,    -1,   366,    -1,    -1,    -1,    -1,   554,   555,   556,
     557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,   403,
     404,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,   613,    -1,    -1,    -1,
      -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,
      -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,   453,
     454,   455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   314,   498,   499,   500,   501,   319,   503,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,   334,    -1,    -1,   520,   521,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,   537,   355,    -1,    -1,   358,   359,    -1,
     361,   545,    -1,    -1,    -1,   366,    -1,    -1,   244,    -1,
     554,   555,   556,   557,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   282,   283,   284,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,   314,    -1,
      -1,    -1,   443,   319,    -1,    -1,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,   334,    -1,
      -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,   351,    -1,    -1,    -1,   355,
      -1,    -1,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,
      -1,    -1,    -1,    -1,   410,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   421,    -1,    -1,    -1,    -1,
      -1,   244,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
     436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   314,   498,   499,   500,   501,   319,   503,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   334,    -1,    -1,   520,   521,   339,    -1,   341,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,   537,   355,    -1,    -1,   358,   359,    -1,   361,   545,
      -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,   554,   555,
     556,   557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,   613,    -1,    -1,
      -1,    -1,    -1,   436,    30,    -1,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,
     453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,    -1,
      -1,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,   498,   499,   500,   501,   319,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   334,    -1,    -1,   520,   521,   339,
      -1,   341,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,   351,    -1,    -1,   537,   355,    -1,    -1,   358,   359,
      -1,   361,   545,    -1,    -1,    -1,   366,    -1,    -1,    -1,
      -1,   554,   555,   556,   557,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     400,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,    -1,
     410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
      -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,   253,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,   498,   499,
     500,   501,    -1,   503,    -1,    -1,   282,   283,   284,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,   537,   314,    -1,
      -1,    -1,    -1,   319,    -1,   545,    -1,    74,    75,    76,
     326,    -1,    -1,    -1,   554,   555,   556,   557,   334,    -1,
      -1,    -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,   355,
      -1,    -1,   358,   359,    -1,   361,    -1,    -1,    -1,    -1,
     366,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   400,    -1,    -1,   403,   404,    -1,
      -1,    -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,
     436,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,    -1,    -1,    -1,   450,    -1,    -1,   453,   454,   455,
      -1,   457,   458,    -1,    -1,    -1,   213,    -1,    -1,   216,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,   498,   499,   500,   501,    -1,   503,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,   521,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,
      -1,    74,    75,    76,    -1,    -1,    -1,    -1,   554,   555,
     556,   557,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     347,    -1,    -1,    -1,   351,   352,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,   390,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   436,
     213,    -1,    -1,   216,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   518,    -1,   213,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,   332,
      -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,   351,   352,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   586,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   332,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,
      -1,   351,   352,   436,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     390,    -1,    -1,   213,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   332,    -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,
     351,   352,    -1,    -1,    -1,   518,   436,    -1,    -1,    -1,
     332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,   351,
     352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,   418,   390,    -1,
      -1,    -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   332,    -1,    -1,   436,    -1,    -1,   518,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   418,   347,    -1,    -1,
      -1,   351,   352,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    74,
      75,    76,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   518,   418,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
      -1,    74,    75,    76,    -1,    -1,   518,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,   586,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,
      -1,   216,    -1,    -1,   586,    -1,    -1,    -1,   518,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,   216,    -1,    -1,   586,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,
      -1,   314,    -1,    -1,   317,    -1,   319,    -1,    -1,    -1,
      -1,    -1,   347,    -1,    -1,    -1,   351,   352,    -1,    -1,
      -1,   334,    -1,    -1,    -1,    -1,   339,    -1,   341,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,    -1,   355,    -1,   213,   358,   359,   216,   361,    -1,
      -1,    -1,    -1,   366,    -1,   390,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,
      -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   418,   347,    -1,    -1,   400,   351,   352,
     403,   404,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,   390,    -1,    -1,
     443,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,
     453,   454,   455,    -1,   457,   458,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,   474,    -1,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,   244,    -1,    -1,   347,    -1,
      -1,    -1,   351,   518,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,   521,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   554,   555,   556,   557,   314,    -1,    -1,    -1,   418,
     319,   586,    -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   334,    -1,   436,    -1,    -1,
     339,    -1,   341,    -1,    -1,    -1,   345,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,   358,
     359,    -1,   361,    -1,    -1,    -1,    -1,   366,    -1,    -1,
     613,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,   410,    -1,   282,   283,   284,    -1,    -1,    -1,   518,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,   314,    -1,    -1,    -1,    -1,
     319,   450,    -1,    -1,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,
     339,    -1,   341,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   355,   586,    -1,   358,
     359,    -1,   361,    -1,    -1,    -1,    -1,   366,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
      -1,   520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,   403,   404,    -1,    -1,   537,    -1,
      -1,   410,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,   554,   555,   556,   557,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,
      -1,   450,    -1,   244,   453,   454,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,    -1,    -1,   626,    -1,   498,
     499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   520,   521,   314,    -1,    -1,    -1,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,   334,   335,    -1,   545,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,   554,   555,   556,   557,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,   613,    -1,    -1,    -1,    -1,   410,
      -1,   282,   283,   284,    -1,    -1,    -1,   626,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   314,    -1,    -1,    -1,    -1,   319,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    -1,    -1,    -1,   366,    -1,   498,   499,   500,
     501,    -1,   503,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,   524,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   537,    -1,    -1,   410,
      -1,   282,   283,   284,   545,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   314,    -1,    -1,    -1,    -1,   319,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,   470,
     341,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,   613,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    -1,    -1,   625,   366,    -1,   498,   499,   500,
     501,    -1,   503,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   537,    -1,    -1,   410,
      -1,   282,   283,   284,   545,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   314,    -1,    -1,    -1,    -1,   319,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,   613,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    -1,    -1,   625,   366,    -1,   498,   499,   500,
     501,    -1,   503,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   537,    -1,    -1,   410,
      -1,   282,   283,   284,   545,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   314,    -1,    -1,   317,    -1,   319,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,   613,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    -1,    -1,   625,   366,    -1,   498,   499,   500,
     501,    -1,   503,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   537,    -1,    -1,   410,
      -1,   282,   283,   284,   545,    -1,    -1,    -1,    -1,    -1,
     421,    -1,   553,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   314,    -1,    -1,    -1,    -1,   319,   450,
      -1,    -1,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,   339,    -1,
     341,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
     351,   352,   613,    -1,   355,    -1,    -1,   358,   359,    -1,
     361,    -1,    -1,    -1,    -1,   366,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   403,   404,    -1,    -1,   537,    -1,    -1,   410,
      -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,   554,   555,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,   450,
      -1,   244,   453,   454,   455,    -1,   457,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
     521,   314,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,   334,    -1,    -1,   545,    -1,   339,    -1,   341,    -1,
      -1,    -1,    -1,   554,   555,   556,   557,    -1,   351,    -1,
      -1,    -1,   355,    -1,    -1,   358,   359,    -1,   361,    -1,
      -1,    -1,    -1,   366,    -1,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
     403,   404,   613,    -1,   282,   283,   284,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,   314,    -1,    -1,    -1,
     443,   319,    -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,
     453,   454,   455,    -1,   457,   458,   334,    -1,    -1,    -1,
      -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,   351,    -1,    -1,    -1,   355,    -1,    -1,
     358,   359,    -1,   361,    -1,    -1,    -1,    -1,   366,    -1,
      -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,
     503,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,   521,    -1,
      -1,    -1,   400,    -1,    -1,   403,   404,    -1,    -1,    -1,
      -1,    -1,   410,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   545,   421,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   554,   555,   556,   557,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,
      -1,    -1,   450,    -1,    -1,   453,   454,   455,    -1,   457,
     458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     498,   499,   500,   501,    -1,   503,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   520,   521,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   554,   555,   556,   557,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   613
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

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

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#ifdef __cplusplus
# define YYSTD(x) std::x
#else
# define YYSTD(x) x
#endif

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

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
#  ifdef __cplusplus
#   include <cstdlib> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T std::size_t
#  else
#   ifdef __STDC__
#    include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#    define YYSIZE_T size_t
#   endif
#  endif
#  define YYSTACK_ALLOC YYSTD (malloc)
#  define YYSTACK_FREE YYSTD (free)
# endif

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Relocate the TYPE STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Type, Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	yymemcpy ((char *) yyptr, (char *) (Stack),			\
		  yysize * (YYSIZE_T) sizeof (Type));			\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (Type) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# ifdef __cplusplus
#  include <cstddef> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T std::size_t
# else
#  ifdef __STDC__
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  ifdef __cplusplus
#   include <cstdio>  /* INFRINGES ON USER NAME SPACE */
#  else
#   include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYFPRINTF YYSTD (fprintf)
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace. [The following comment makes no
   sense to me.  Could someone clarify it?  --akim] Since this is
   uninitialized, it does not stop multiple parsers from coexisting.
   */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
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

#if ! defined (yyoverflow) && ! defined (yymemcpy)
# if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#  define yymemcpy __builtin_memcpy
# else				/* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
#  if defined (__STDC__) || defined (__cplusplus)
yymemcpy (char *yyto, const char *yyfrom, YYSIZE_T yycount)
#  else
yymemcpy (yyto, yyfrom, yycount)
     char *yyto;
     const char *yyfrom;
     YYSIZE_T yycount;
#  endif
{
  register const char *yyf = yyfrom;
  register char *yyt = yyto;
  register YYSIZE_T yyi = yycount;

  while (yyi-- != 0)
    *yyt++ = *yyf++;
}
# endif
#endif

#ifdef YYERROR_VERBOSE

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
#endif

#line 341 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# ifdef __cplusplus
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else /* !__cplusplus */
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif /* !__cplusplus */
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
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
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
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

  if (yyssp >= yyss + yystacksize - 1)
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
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (short, yyss);
	YYSTACK_RELOCATE (YYSTYPE, yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (YYLTYPE, yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
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
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 1:
#line 754 "fgl.yacc"
{
			print_screen_mode(0);
		}
    break;
case 2:
#line 757 "fgl.yacc"
{
			print_screen_mode(1);
		}
    break;
case 3:
#line 763 "fgl.yacc"
{
		print_start_server(atoi(yyvsp[-3].str),yyvsp[0].str);
	}
    break;
case 4:
#line 769 "fgl.yacc"
{
	print_stop_external();
	}
    break;
case 5:
#line 774 "fgl.yacc"
{
		if (scan_variable(yyvsp[0].str)!=2) {
		char buff[256];
			sprintf(buff,"START EXTERNAL ..ON must be an integer");
			yyerror(buff);
			YYERROR;
		}
	}
    break;
case 8:
#line 786 "fgl.yacc"
{
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;
case 9:
#line 791 "fgl.yacc"
{
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",aclfgl_%s);\n",yyvsp[0].str,yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;
case 10:
#line 802 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;
case 11:
#line 803 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 12:
#line 804 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 13:
#line 805 "fgl.yacc"
{sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 14:
#line 806 "fgl.yacc"
{
  int a;
  a=scan_variable(yyvsp[0].str)&15;
  if (a!=1&&a!=2) {
    
    yyerror("Only INTEGER/SMALLINT variables may be used as subscripts");
    YYERROR;
    /* error processing */;
  }
  sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;
case 15:
#line 821 "fgl.yacc"
{sprintf(yyval.str,"+ %s",yyvsp[0].str);}
    break;
case 16:
#line 822 "fgl.yacc"
{sprintf(yyval.str,"- %s",yyvsp[0].str);}
    break;
case 17:
#line 823 "fgl.yacc"
{sprintf(yyval.str,"* %s",yyvsp[0].str);}
    break;
case 18:
#line 824 "fgl.yacc"
{sprintf(yyval.str,"/ %s",yyvsp[0].str);}
    break;
case 19:
#line 825 "fgl.yacc"
{sprintf(yyval.str,"%% %s",yyvsp[0].str);}
    break;
case 20:
#line 828 "fgl.yacc"
{strcpy(yyval.str,"+");}
    break;
case 21:
#line 829 "fgl.yacc"
{strcpy(yyval.str,"-");}
    break;
case 22:
#line 833 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 23:
#line 834 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 24:
#line 837 "fgl.yacc"
{start_state("attribute",1);}
    break;
case 25:
#line 837 "fgl.yacc"
{strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;
case 27:
#line 844 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 28:
#line 845 "fgl.yacc"
{
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;
case 29:
#line 851 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;
case 30:
#line 852 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;
case 31:
#line 853 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;
case 32:
#line 854 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;
case 33:
#line 855 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;
case 34:
#line 856 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("RED"));}
    break;
case 35:
#line 857 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;
case 36:
#line 858 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;
case 37:
#line 859 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;
case 38:
#line 860 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;
case 39:
#line 861 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;
case 40:
#line 862 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;
case 41:
#line 863 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;
case 42:
#line 864 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;
case 43:
#line 865 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;
case 44:
#line 866 "fgl.yacc"
{inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;
case 47:
#line 873 "fgl.yacc"
{
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;
case 48:
#line 877 "fgl.yacc"
{start_state("attribute",0);strcpy(yyval.str,"");
}
    break;
case 49:
#line 881 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 50:
#line 882 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 51:
#line 886 "fgl.yacc"
{ 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;
case 52:
#line 892 "fgl.yacc"
{ form_attrib.border      =1;}
    break;
case 53:
#line 894 "fgl.yacc"
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
case 54:
#line 905 "fgl.yacc"
{ form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;
case 55:
#line 907 "fgl.yacc"
{ form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;
case 56:
#line 909 "fgl.yacc"
{ form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;
case 57:
#line 911 "fgl.yacc"
{ form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;
case 58:
#line 915 "fgl.yacc"
{ form_attrib.message_line=atoi(yyvsp[0].str); }
    break;
case 59:
#line 917 "fgl.yacc"
{ form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;
case 60:
#line 964 "fgl.yacc"
{strcpy(yyval.str,"CALL");}
    break;
case 61:
#line 968 "fgl.yacc"
{ debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;
case 62:
#line 972 "fgl.yacc"
{
	print_getfldbuf(yyvsp[-2].str);
	}
    break;
case 63:
#line 975 "fgl.yacc"
{
	print_returning();
}
    break;
case 64:
#line 979 "fgl.yacc"
{
	print_form_is_compiled(yyvsp[-1].str);
	}
    break;
case 65:
#line 983 "fgl.yacc"
{ 
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;
case 67:
#line 988 "fgl.yacc"
{ 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
 }
    break;
case 68:
#line 991 "fgl.yacc"
{
	new_counter();
   addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;
case 69:
#line 996 "fgl.yacc"
{
	debug("Got args");
   }
    break;
case 70:
#line 1000 "fgl.yacc"
{
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;
case 71:
#line 1008 "fgl.yacc"
{
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str);
	}
    break;
case 72:
#line 1012 "fgl.yacc"
{
	A4GLSQL_set_status(0);
	new_counter();
	}
    break;
case 73:
#line 1016 "fgl.yacc"
{
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;
case 74:
#line 1019 "fgl.yacc"
{
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;
case 75:
#line 1025 "fgl.yacc"
{
	sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	A4GLSQL_set_status(0);
	new_counter();
	}
    break;
case 76:
#line 1030 "fgl.yacc"
{
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;
case 77:
#line 1033 "fgl.yacc"
{
	char buff[256];
	char *ptr;
	debug("STR3 = %s",yyvsp[-4].str);
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
case 78:
#line 1049 "fgl.yacc"
{
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%d)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;
case 79:
#line 1056 "fgl.yacc"
{
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;
case 80:
#line 1060 "fgl.yacc"
{
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;
case 81:
#line 1064 "fgl.yacc"
{ int cnt;
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
case 82:
#line 1085 "fgl.yacc"
{start_bind('i',0);strcpy(yyval.str,"0");}
    break;
case 83:
#line 1085 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);
}
    break;
case 84:
#line 1089 "fgl.yacc"
{start_bind('i',0);strcpy(yyval.str,"0");}
    break;
case 85:
#line 1090 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 86:
#line 1091 "fgl.yacc"
{strcpy(yyval.str,"WITHOUT WAITING"); }
    break;
case 87:
#line 1096 "fgl.yacc"
{
			yyval.ptr=new_expr("");
		}
    break;
case 88:
#line 1099 "fgl.yacc"
{
			yyval.ptr=yyvsp[0].ptr;
		}
    break;
case 89:
#line 1105 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
}
    break;
case 90:
#line 1108 "fgl.yacc"
{
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;
case 91:
#line 1114 "fgl.yacc"
{
print_pop_variable(yyvsp[0].str);
cnt=1;sprintf(yyval.str,"%d",cnt);
}
    break;
case 92:
#line 1118 "fgl.yacc"
{
print_pop_variable(yyvsp[-2].str);
cnt++;sprintf(yyval.str,"%d",cnt);
}
    break;
case 95:
#line 1128 "fgl.yacc"
{
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;
case 96:
#line 1134 "fgl.yacc"
{
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;
case 97:
#line 1144 "fgl.yacc"
{
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;
case 98:
#line 1154 "fgl.yacc"
{
print_after_when(0);
pop_blockcommand("CASE");
}
    break;
case 99:
#line 1160 "fgl.yacc"
{  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;
case 100:
#line 1169 "fgl.yacc"
{
print_after_when(0);
pop_blockcommand("CASE");
}
    break;
case 105:
#line 1182 "fgl.yacc"
{setinc(-1);incprint();}
    break;
case 107:
#line 1185 "fgl.yacc"
{
incprint();
}
    break;
case 108:
#line 1187 "fgl.yacc"
{incprint();
print_after_when(0);
}
    break;
case 110:
#line 1193 "fgl.yacc"
{incprint();}
    break;
case 111:
#line 1195 "fgl.yacc"
{incprint();
print_after_when(0);
}
    break;
case 112:
#line 1200 "fgl.yacc"
{
print_when(0);

incprint();
}
    break;
case 113:
#line 1205 "fgl.yacc"
{incprint();
print_after_when(1);
setinc(-1);}
    break;
case 114:
#line 1211 "fgl.yacc"
{
incprint();
print_when(1);
}
    break;
case 115:
#line 1215 "fgl.yacc"
{incprint();
print_after_when(1);
setinc(-1);}
    break;
case 116:
#line 1223 "fgl.yacc"
{
  print_close('F',yyvsp[0].str);
 }
    break;
case 117:
#line 1226 "fgl.yacc"
{
  print_close('W',yyvsp[0].str);
}
    break;
case 118:
#line 1229 "fgl.yacc"
{
  print_close('W',yyvsp[0].str);
}
    break;
case 119:
#line 1232 "fgl.yacc"
{
  print_close('D',0);
}
    break;
case 120:
#line 1235 "fgl.yacc"
{
  print_close('S',yyvsp[0].str);
}
    break;
case 121:
#line 1238 "fgl.yacc"
{
  print_close('C',yyvsp[0].str);
}
    break;
case 127:
#line 1254 "fgl.yacc"
{
			printc("%s",yyvsp[0].str);
}
    break;
case 130:
#line 1263 "fgl.yacc"
{
			printc("%s\n",yyvsp[0].str);
}
    break;
case 131:
#line 1267 "fgl.yacc"
{
/* This aint used - its filtered by the lexer first... */
	printc("FIXME : Comment : %s\n");
}
    break;
case 132:
#line 1275 "fgl.yacc"
{
push_blockcommand("CONSTRUCT");
}
    break;
case 133:
#line 1279 "fgl.yacc"
{
	print_construct_1();
}
    break;
case 134:
#line 1282 "fgl.yacc"
{
	print_construct_2(yyvsp[-2].str);
}
    break;
case 135:
#line 1290 "fgl.yacc"
{
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	sprintf(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;
case 136:
#line 1296 "fgl.yacc"
{
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	sprintf(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;
case 141:
#line 1311 "fgl.yacc"
{
                push_construct("",yyval.str);
             }
    break;
case 142:
#line 1315 "fgl.yacc"
{
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;
case 143:
#line 1320 "fgl.yacc"
{
                push_construct(yyvsp[-2].str,"*");
             }
    break;
case 146:
#line 1330 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
	}
    break;
case 147:
#line 1333 "fgl.yacc"
{
		print_befaft_field_2();

	}
    break;
case 148:
#line 1337 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
	}
    break;
case 149:
#line 1339 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 150:
#line 1342 "fgl.yacc"
{
		print_onkey_1(yyvsp[0].str);
	}
    break;
case 151:
#line 1344 "fgl.yacc"
{
		print_onkey_2();
	}
    break;
case 152:
#line 1347 "fgl.yacc"
{
		print_befaft_field_1("AFTER_INP");
	}
    break;
case 153:
#line 1349 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 154:
#line 1352 "fgl.yacc"
{
		print_befaft_field_1("BEFORE_INP");
		}
    break;
case 155:
#line 1355 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 156:
#line 1365 "fgl.yacc"
{sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;
case 157:
#line 1366 "fgl.yacc"
{
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 158:
#line 1374 "fgl.yacc"
{sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;
case 159:
#line 1375 "fgl.yacc"
{
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 160:
#line 1386 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_YEAR);");
	}
    break;
case 161:
#line 1389 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_MONTH);"); 
	}
    break;
case 162:
#line 1392 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_DAY);"); 
	}
    break;
case 163:
#line 1395 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_HOUR);");
	}
    break;
case 164:
#line 1398 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_MINUTE);");
	}
    break;
case 165:
#line 1401 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_SECOND);");
	}
    break;
case 166:
#line 1407 "fgl.yacc"
{
				print_defer(0);
			}
    break;
case 167:
#line 1411 "fgl.yacc"
{
				print_defer(1);
			}
    break;
case 168:
#line 1419 "fgl.yacc"
{strcpy(yyval.str,"");if (modlevel>=0) print_variables();}
    break;
case 169:
#line 1420 "fgl.yacc"
{strcpy(yyval.str,"");if (modlevel>=0) print_variables();lastlineno=yylineno;}
    break;
case 172:
#line 1428 "fgl.yacc"
{dtypelist[0]=0;printcomment("/* define */\n");}
    break;
case 173:
#line 1428 "fgl.yacc"
{printcomment("/*end def */\n");}
    break;
case 178:
#line 1436 "fgl.yacc"
{in_define=1;}
    break;
case 179:
#line 1436 "fgl.yacc"
{in_define=0;strcpy(yyval.str,yyvsp[0].str);}
    break;
case 180:
#line 1440 "fgl.yacc"
{ add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;
case 181:
#line 1441 "fgl.yacc"
{ add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;
case 182:
#line 1444 "fgl.yacc"
{ 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;
case 184:
#line 1449 "fgl.yacc"
{ }
    break;
case 185:
#line 1449 "fgl.yacc"
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
case 189:
#line 1466 "fgl.yacc"
{
		sprintf(yyval.str,"-%d",yyvsp[0].str);}
    break;
case 190:
#line 1470 "fgl.yacc"
{
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 195:
#line 1484 "fgl.yacc"
{
debug("defines array %s",yyvsp[-1].str);
push_type(0,0,yyvsp[-1].str);
}
    break;
case 197:
#line 1493 "fgl.yacc"
{
push_associate(yyvsp[-5].str,yyvsp[-1].str);
push_type(0,0,yyvsp[-1].str);
}
    break;
case 198:
#line 1497 "fgl.yacc"
{
pop_associate();

}
    break;
case 204:
#line 1512 "fgl.yacc"
{sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;
case 205:
#line 1514 "fgl.yacc"
{sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;
case 206:
#line 1515 "fgl.yacc"
{debug("Single");}
    break;
case 208:
#line 1522 "fgl.yacc"
{push_record();in_record++;}
    break;
case 209:
#line 1522 "fgl.yacc"
{pop_record();in_record--;}
    break;
case 210:
#line 1523 "fgl.yacc"
{in_record++;push_record();debug("Like\n");}
    break;
case 211:
#line 1524 "fgl.yacc"
{debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;
case 212:
#line 1527 "fgl.yacc"
{
		push_record();debug("Like\n");}
    break;
case 213:
#line 1529 "fgl.yacc"
{
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;
case 215:
#line 1539 "fgl.yacc"
{
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 218:
#line 1550 "fgl.yacc"
{start_state("dtype",1);}
    break;
case 219:
#line 1550 "fgl.yacc"
{start_state("dtype",0);}
    break;
case 222:
#line 1556 "fgl.yacc"
{push_type("char","1",0);}
    break;
case 223:
#line 1557 "fgl.yacc"
{
char buff[80];
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename); 
}
push_type("char",yyvsp[-1].str,0);
}
    break;
case 224:
#line 1564 "fgl.yacc"
{push_type("char",yyvsp[-1].str,0);}
    break;
case 225:
#line 1565 "fgl.yacc"
{push_type("char",yyvsp[-3].str,0);}
    break;
case 226:
#line 1566 "fgl.yacc"
{push_type("long",0,0);}
    break;
case 227:
#line 1567 "fgl.yacc"
{push_dim(yyvsp[0].str);}
    break;
case 228:
#line 1568 "fgl.yacc"
{push_type("int",0,0);}
    break;
case 229:
#line 1569 "fgl.yacc"
{push_type("form",0,0);}
    break;
case 230:
#line 1570 "fgl.yacc"
{push_type("form",0,0);}
    break;
case 231:
#line 1571 "fgl.yacc"
{ char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;
case 232:
#line 1575 "fgl.yacc"
{
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;
case 233:
#line 1580 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;
case 234:
#line 1585 "fgl.yacc"
{
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;
case 235:
#line 1589 "fgl.yacc"
{
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;
case 236:
#line 1592 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;
case 237:
#line 1596 "fgl.yacc"
{push_type("double",0,0);}
    break;
case 238:
#line 1597 "fgl.yacc"
{push_type("float",0,0);}
    break;
case 239:
#line 1598 "fgl.yacc"
{push_type("fgldate",0,0);}
    break;
case 240:
#line 1599 "fgl.yacc"
{push_type("fglbyte",0,0);}
    break;
case 241:
#line 1600 "fgl.yacc"
{push_type("fglbyte",0,0);}
    break;
case 242:
#line 1601 "fgl.yacc"
{push_type("fgltext",0,0);}
    break;
case 243:
#line 1602 "fgl.yacc"
{push_type("fgltext",0,0);}
    break;
case 244:
#line 1603 "fgl.yacc"
{
push_type("struct_dtime ",yyvsp[0].str,0);
}
    break;
case 245:
#line 1606 "fgl.yacc"
{push_type("struct_ival ",yyvsp[0].str,0);}
    break;
case 246:
#line 1607 "fgl.yacc"
{push_like(yyvsp[0].str);fflush(stdout);printcomment("/*added(XXXXX)\n */");}
    break;
case 247:
#line 1615 "fgl.yacc"
{
printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); printcomment ("/*set col...(ZZZ)\n*/");}
    break;
case 248:
#line 1619 "fgl.yacc"
{debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;
case 249:
#line 1621 "fgl.yacc"
{debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;
case 250:
#line 1623 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 251:
#line 1625 "fgl.yacc"
{
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;
case 252:
#line 1630 "fgl.yacc"
{
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;
case 253:
#line 1634 "fgl.yacc"
{start_state("dtime_val",1);}
    break;
case 254:
#line 1634 "fgl.yacc"
{start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;
case 255:
#line 1637 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 256:
#line 1638 "fgl.yacc"
{strcpy(yyval.str,"2");}
    break;
case 257:
#line 1639 "fgl.yacc"
{strcpy(yyval.str,"3");}
    break;
case 258:
#line 1640 "fgl.yacc"
{strcpy(yyval.str,"4");}
    break;
case 259:
#line 1641 "fgl.yacc"
{strcpy(yyval.str,"5");}
    break;
case 260:
#line 1642 "fgl.yacc"
{strcpy(yyval.str,"6");}
    break;
case 261:
#line 1644 "fgl.yacc"
{
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;
case 262:
#line 1649 "fgl.yacc"
{start_state("dtime_val",1);}
    break;
case 263:
#line 1649 "fgl.yacc"
{ debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;
case 264:
#line 1652 "fgl.yacc"
{
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;
case 265:
#line 1654 "fgl.yacc"
{
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;
case 266:
#line 1660 "fgl.yacc"
{
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;
case 267:
#line 1662 "fgl.yacc"
{
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;
case 268:
#line 1668 "fgl.yacc"
{
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;
case 269:
#line 1676 "fgl.yacc"
{start_state("interval_val",1);}
    break;
case 270:
#line 1676 "fgl.yacc"
{start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;
case 271:
#line 1679 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 272:
#line 1680 "fgl.yacc"
{strcpy(yyval.str,"2");}
    break;
case 273:
#line 1681 "fgl.yacc"
{strcpy(yyval.str,"3");}
    break;
case 274:
#line 1682 "fgl.yacc"
{strcpy(yyval.str,"4");}
    break;
case 275:
#line 1683 "fgl.yacc"
{strcpy(yyval.str,"5");}
    break;
case 276:
#line 1684 "fgl.yacc"
{strcpy(yyval.str,"6");}
    break;
case 277:
#line 1686 "fgl.yacc"
{
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;
case 281:
#line 1698 "fgl.yacc"
{
              	dim_set_name(yyvsp[0].str);
              }
    break;
case 285:
#line 1707 "fgl.yacc"
{dim_push_type("char","1",0);}
    break;
case 286:
#line 1709 "fgl.yacc"
{dim_push_type("char",yyvsp[-1].str,0);}
    break;
case 287:
#line 1711 "fgl.yacc"
{dim_push_type("char",yyvsp[-1].str,0);}
    break;
case 288:
#line 1713 "fgl.yacc"
{dim_push_type("char",yyvsp[-3].str,0);}
    break;
case 289:
#line 1714 "fgl.yacc"
{dim_push_type("long",0,0);}
    break;
case 290:
#line 1715 "fgl.yacc"
{dim_push_type("integer",0,0);}
    break;
case 291:
#line 1716 "fgl.yacc"
{dim_push_type("FORM",0,0);}
    break;
case 292:
#line 1717 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;
case 293:
#line 1722 "fgl.yacc"
{

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;
case 294:
#line 1729 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;
case 295:
#line 1734 "fgl.yacc"
{dim_push_type("fglmoney",0,0);}
    break;
case 296:
#line 1736 "fgl.yacc"
{dim_push_type("fglmoney",0,0);}
    break;
case 297:
#line 1738 "fgl.yacc"
{dim_push_type("fglmoney",0,0);}
    break;
case 298:
#line 1739 "fgl.yacc"
{dim_push_type("double",0,0);}
    break;
case 299:
#line 1740 "fgl.yacc"
{dim_push_type("float",0,0);}
    break;
case 300:
#line 1741 "fgl.yacc"
{dim_push_type("fgldate",0,0);}
    break;
case 301:
#line 1742 "fgl.yacc"
{dim_push_type("fglbyte",0,0);}
    break;
case 302:
#line 1743 "fgl.yacc"
{dim_push_type("fgltext",0,0);}
    break;
case 303:
#line 1744 "fgl.yacc"
{
dim_push_type("struct_dtime ",yyvsp[0].str,0);
}
    break;
case 304:
#line 1747 "fgl.yacc"
{dim_push_type("struct_ival ",0,0);}
    break;
case 305:
#line 1749 "fgl.yacc"
{dim_push_like(yyvsp[0].str);fflush(stdout);printcomment("/*added(XXXXX)\n */");}
    break;
case 306:
#line 1755 "fgl.yacc"
{
printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; printcomment ("/*set col...(ZZZ)\n*/");}
    break;
case 307:
#line 1763 "fgl.yacc"
{
dim_push_type(0,0,yyvsp[-1].str);
}
    break;
case 309:
#line 1771 "fgl.yacc"
{
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;
case 310:
#line 1775 "fgl.yacc"
{
dim_pop_associate();

}
    break;
case 311:
#line 1783 "fgl.yacc"
{dim_push_record();}
    break;
case 312:
#line 1784 "fgl.yacc"
{dim_pop_record();}
    break;
case 313:
#line 1785 "fgl.yacc"
{dim_push_record();debug("Like\n");}
    break;
case 314:
#line 1786 "fgl.yacc"
{debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;
case 320:
#line 1803 "fgl.yacc"
{ dim_push_name(yyval.str); }
    break;
case 321:
#line 1807 "fgl.yacc"
{
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;
case 322:
#line 1811 "fgl.yacc"
{
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;
case 323:
#line 1814 "fgl.yacc"
{ 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;
case 324:
#line 1817 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(4,0,0)); }
    break;
case 325:
#line 1818 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;
case 326:
#line 1819 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;
case 327:
#line 1820 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;
case 328:
#line 1821 "fgl.yacc"
{ 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;
case 329:
#line 1827 "fgl.yacc"
{
		print_display_by_name(yyvsp[0].str);
                }
    break;
case 330:
#line 1832 "fgl.yacc"
{ 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;
case 331:
#line 1835 "fgl.yacc"
{
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;
case 332:
#line 1838 "fgl.yacc"
{
		push_blockcommand("DISPLAY");
		}
    break;
case 333:
#line 1842 "fgl.yacc"
{
		print_display_array_p1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);
		}
    break;
case 334:
#line 1845 "fgl.yacc"
{
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;
case 335:
#line 1853 "fgl.yacc"
{
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;
case 340:
#line 1865 "fgl.yacc"
{
		print_befaft_field_1("AFT_ROW");
		}
    break;
case 341:
#line 1868 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 342:
#line 1871 "fgl.yacc"
{
		print_befaft_field_1("BEF_ROW");
		}
    break;
case 343:
#line 1874 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 344:
#line 1877 "fgl.yacc"
{
		print_onkey_1(yyvsp[0].str);
		}
    break;
case 345:
#line 1880 "fgl.yacc"
{
		print_onkey_2();
	}
    break;
case 346:
#line 1886 "fgl.yacc"
{
			print_error(yyvsp[0].str,0);
		}
    break;
case 347:
#line 1889 "fgl.yacc"
{ 
			print_error(yyvsp[-1].str,1);
	}
    break;
case 348:
#line 1897 "fgl.yacc"
{ if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;
case 349:
#line 1899 "fgl.yacc"
{ if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;
case 350:
#line 1901 "fgl.yacc"
{ if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;
case 351:
#line 1903 "fgl.yacc"
{ if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;
case 352:
#line 1905 "fgl.yacc"
{ if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;
case 353:
#line 1907 "fgl.yacc"
{ if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;
case 354:
#line 1908 "fgl.yacc"
{
	if (in_command("MENU")) {
		exit_loop("MENU");
		//printc("cmd_no=-3;continue;\n");
	} 
              else YYERROR;}
    break;
case 355:
#line 1915 "fgl.yacc"
{ if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;
case 356:
#line 1917 "fgl.yacc"
{ if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;
case 357:
#line 1921 "fgl.yacc"
{ if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;
case 358:
#line 1923 "fgl.yacc"
{ if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;
case 359:
#line 1925 "fgl.yacc"
{ if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;
case 360:
#line 1927 "fgl.yacc"
{ if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;
case 361:
#line 1929 "fgl.yacc"
{ if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;
case 362:
#line 1931 "fgl.yacc"
{ if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;
case 363:
#line 1933 "fgl.yacc"
{ if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;
case 364:
#line 1939 "fgl.yacc"
{ if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;
case 365:
#line 1944 "fgl.yacc"
{
	print_exit_program(0);
}
    break;
case 366:
#line 1947 "fgl.yacc"
{
	print_exit_program(1);
}
    break;
case 371:
#line 1958 "fgl.yacc"
{
	dec_counter(); 
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;
case 374:
#line 1964 "fgl.yacc"
{
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;
case 375:
#line 1967 "fgl.yacc"
{
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;
case 376:
#line 1972 "fgl.yacc"
{
yyval.ptr=yyvsp[0].ptr;
}
    break;
case 380:
#line 1981 "fgl.yacc"
{ yyval.ptr=new_expr("add_spaces();"); }
    break;
case 387:
#line 1992 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 390:
#line 1996 "fgl.yacc"
{yyval.ptr=new_expr("push_null()");}
    break;
case 391:
#line 2000 "fgl.yacc"
{
/*set_counter(0);*/
sprintf(yyval.str,"%d",get_counter_val());
printcomment("/*L1 %s*/\n",yyval.str);
}
    break;
case 392:
#line 2006 "fgl.yacc"
{
sprintf(yyval.str,"%d",get_counter_val());
printcomment("/*L2 %s*/\n",yyval.str);
}
    break;
case 393:
#line 2014 "fgl.yacc"
{
/*set_counter(0);*/
sprintf(yyval.str,"%d",get_counter_val());
printcomment("/*L1 %s*/\n",yyval.str);
}
    break;
case 394:
#line 2020 "fgl.yacc"
{
sprintf(yyval.str,"%d",get_counter_val());
printcomment("/*L2 %s*/\n",yyval.str);
}
    break;
case 395:
#line 2026 "fgl.yacc"
{strcpy(yyval.str,"0");printf("NOthing\n");}
    break;
case 396:
#line 2027 "fgl.yacc"
{debug("Expr list\n");}
    break;
case 397:
#line 2031 "fgl.yacc"
{debug("L1\n");set_counter(1);sprintf(yyval.str,"1");}
    break;
case 398:
#line 2032 "fgl.yacc"
{debug("L2\n");sprintf(yyval.str,"%d",get_counter_val());}
    break;
case 399:
#line 2037 "fgl.yacc"
{sprintf(yyval.str,"%d",get_counter_val());}
    break;
case 400:
#line 2039 "fgl.yacc"
{
print_op("OP_CONCAT");
dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;
case 401:
#line 2046 "fgl.yacc"
{
debug("Print expr (2)");
print_expr(yyvsp[0].ptr);
}
    break;
case 402:
#line 2052 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 404:
#line 2056 "fgl.yacc"
{
strcpy(yyval.str,"+");
}
    break;
case 405:
#line 2060 "fgl.yacc"
{
strcpy(yyval.str,"-");
}
    break;
case 406:
#line 2069 "fgl.yacc"
{
	
        //sprintf($<str>$,"%s pushop(OP_NOT);",$<str>2);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;
case 407:
#line 2075 "fgl.yacc"
{
        //sprintf($<str>$,"push_int(1);");
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;
case 408:
#line 2081 "fgl.yacc"
{
        //sprintf($<str>$,"push_int(0);");
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;
case 409:
#line 2086 "fgl.yacc"
{ yyval.ptr=yyvsp[-1].ptr; }
    break;
case 410:
#line 2087 "fgl.yacc"
{ yyval.ptr=yyvsp[-1].ptr; }
    break;
case 411:
#line 2088 "fgl.yacc"
{
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_EXISTS);");
}
    break;
case 412:
#line 2098 "fgl.yacc"
{
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTEXISTS);");
}
    break;
case 413:
#line 2112 "fgl.yacc"
{
        debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%d",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,get_push_literal('D',yyval.str));
        //sprintf($<str>$,"push_double((double)%s%s)",$<str>1,$<str>2);
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;
case 414:
#line 2121 "fgl.yacc"
{
        debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%d",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 415:
#line 2131 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%d);",atoi(yyvsp[0].str));inc_counter(); 
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 416:
#line 2134 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%s);",yyvsp[0].str); inc_counter();
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 417:
#line 2138 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('S',yyvsp[0].str));
	//sprintf($<str>$,"push_char(%s);",$<str>1);
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 418:
#line 2145 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('D',yyvsp[0].str));
	//sprintf($<str>$,"push_double((double)%s);",$<str>1);
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 419:
#line 2152 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('L',yyvsp[0].str));
	//sprintf($<str>$,"push_long((long)%d);/*2*/",atoi($<str>1));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 420:
#line 2158 "fgl.yacc"
{
char r1[256];
char r2[256];
char buff[256];
char kp[40000];
char *ptr1;
char *ptr2;
void *p1;
int v1;
int v2;
int a;

debug("Got a thru...");
        strcpy(r1,yyvsp[-2].str);
debug("r1=%s",r1);
        ptr1=strrchr(r1,'.');
	if (ptr1==0) {
		yyerror("Must have a . in a thru");YYERROR;
	}
        *ptr1=0;
        ptr1++;
 
        strcpy(r2,yyvsp[0].str);
	debug("r2=%s",r2);

        ptr2=strrchr(r2,'.');
	if (ptr2==0) {
		yyerror("Must have a . in a thru");YYERROR;
	}
        *ptr2=0;
 
	debug("Checking portions %s %s\n",r1,r2);

        if (strcmp(r1,r2)!=0) {
                yyerror("Records for thru look different...");YYERROR;
        }
 
	debug("Checking variables");
        v1=scan_variable(yyvsp[-2].str);
        if (v2==-1) {
		debug("Variable not found..");
                yyerror("Variable not found (first entry in thru)");YYERROR;
        }
        v1=last_var_found;
        debug("v1=%d",v1);
 
        v2=scan_variable(yyvsp[0].str);
        if (v2==-1) {
		debug("Variable not found..");
                yyerror("Variable not found (second entry in thru)");
        }
        v2=last_var_found;
        debug("v2=%d",v2);
 
	p1=new_expr("");
	yyval.ptr=p1;
        for (a=v1;a<=v2;a++) {
	char bbz[256];
                sprintf(buff,"%s.%s",r1,get_var_name(a));
		sprintf(bbz,"push_variable(%s,0x%x);",buff,scan_variable(buff));
		append_expr(p1,bbz);
        }
}
    break;
case 421:
#line 2221 "fgl.yacc"
{
   int a;
   int incvcnt;
   int flg=0;
   a=scan_variable(yyvsp[0].str);
   if (a>=0) {
          if (aubit_strcasecmp(yyvsp[0].str,"today")==0) {
               flg=1;
               sprintf(yyval.str,"push_today();");
          }

          if (aubit_strcasecmp(yyvsp[0].str,"time")==0) {
               flg=1;
               sprintf(yyval.str,"push_time();");
          }

          if (aubit_strcasecmp(yyvsp[0].str,"pageno")==0) {
               flg=1;
               sprintf(yyval.str,"push_variable(&rep.page_no,2);",yyvsp[0].str,scan_variable(yyvsp[0].str));
          }
          if (aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               flg=1;
               sprintf(yyval.str,"push_variable(&rep.line_no,2);",yyvsp[0].str,scan_variable(yyvsp[0].str));
          }
         if (flg==0) {
         sprintf(yyval.str,"push_variable(&%s,0x%x);",yyvsp[0].str,scan_variable(yyvsp[0].str));
         }
   inc_counter();
   }

if (a==-1) { sprintf(yyval.str,"push_char(%s);",yyvsp[0].str);inc_counter();
 }

if (a==-2) {
        char b[40000];
        printcomment("/* print_push_rec... %s */",yyvsp[0].str);
        incvcnt=print_push_rec(yyvsp[0].str,b); 
        inc_counter_by(incvcnt);
	debug("Copy");
        strcpy(yyval.str,b);
        }


yyval.ptr=new_expr(yyval.str);
}
    break;
case 422:
#line 2272 "fgl.yacc"
{
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;
case 423:
#line 2278 "fgl.yacc"
{
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;
case 424:
#line 2282 "fgl.yacc"
{
   if (!in_command("REPORT")) {
   yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
}
    break;
case 425:
#line 2289 "fgl.yacc"
{insql=1;set_ingroup();}
    break;
case 426:
#line 2289 "fgl.yacc"
{
      if (!in_command("REPORT")) {
        yyerror("This can only be done in a report!");YYERROR;
      } 
      insql=0; 
	printcomment("/* rep_Agg = %s\n*/",yyvsp[0].str);
        sprintf(yyval.str,yyvsp[0].str);
	yyval.ptr=new_expr(yyval.str);
      }
    break;
case 427:
#line 2304 "fgl.yacc"
{
	//sprintf($<str>$,"%s pushop(OP_AND);",$<str>2);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
}
    break;
case 428:
#line 2309 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_OR);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
}
    break;
case 429:
#line 2316 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
	}
    break;
case 430:
#line 2319 "fgl.yacc"
{
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;
case 431:
#line 2327 "fgl.yacc"
{
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN_SELECT);");
}
    break;
case 432:
#line 2338 "fgl.yacc"
{
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN_SELECT);");
}
    break;
case 433:
#line 2348 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
}
    break;
case 434:
#line 2354 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
}
    break;
case 435:
#line 2364 "fgl.yacc"
{ 
sprintf(yyval.str,"pushop(OP_ISNULL);"); 
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 436:
#line 2369 "fgl.yacc"
{ 
sprintf(yyval.str,"pushop(OP_ISNOTNULL);"); 
yyval.ptr=new_expr(yyval.str);
}
    break;
case 437:
#line 2377 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_MATCHES);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);");
}
    break;
case 438:
#line 2382 "fgl.yacc"
{ 
//sprintf($<str>$,"%s pushop(OP_MATCHES);pushop(OP_NOT);",$<str>2); 
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);pushop(OP_NOT);");
}
    break;
case 439:
#line 2387 "fgl.yacc"
{
//sprintf($<str>$," %s pushop(OP_LIKE);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);");
}
    break;
case 440:
#line 2392 "fgl.yacc"
{
//sprintf($<str>$,"pushop(OP_LIKE);pushop(OP_NOT);",$<str>2); 
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);pushop(OP_NOT);");
}
    break;
case 441:
#line 2399 "fgl.yacc"
{
sprintf(yyval.str,"pushop(OP_CLIP);");
yyval.ptr=new_expr(yyval.str);
inc_counter();
}
    break;
case 442:
#line 2406 "fgl.yacc"
{
sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
}
    break;
case 443:
#line 2413 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_ADD);",$<str>2);
debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
}
    break;
case 444:
#line 2418 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_SUB);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
}
    break;
case 445:
#line 2422 "fgl.yacc"
{
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
}
    break;
case 446:
#line 2426 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_DIV);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
}
    break;
case 447:
#line 2430 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_MOD);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
}
    break;
case 448:
#line 2434 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_POWER);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
}
    break;
case 449:
#line 2441 "fgl.yacc"
{ 
//sprintf($<str>$,"%s pushop(OP_EQUAL);",$<str>2); 
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;
case 450:
#line 2445 "fgl.yacc"
{ 
sprintf(yyval.str,"%s pushop(OP_EQUAL);",yyvsp[0].str);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;
case 451:
#line 2450 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_LESS_THAN);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
}
    break;
case 452:
#line 2455 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_GREATER_THAN);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
}
    break;
case 453:
#line 2460 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_NOT_EQUAL);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
}
    break;
case 454:
#line 2465 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_LESS_THAN_EQ);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
}
    break;
case 455:
#line 2470 "fgl.yacc"
{
//sprintf($<str>$,"%s pushop(OP_GREATER_THAN_EQ);",$<str>2);
yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
}
    break;
case 456:
#line 2477 "fgl.yacc"
{
reset_counter();
}
    break;
case 457:
#line 2487 "fgl.yacc"
{ 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;
case 458:
#line 2492 "fgl.yacc"
{ 
		sprintf(yyval.str,"%d",get_counter_val()); 
		printcomment("/*function_call_expr2 %s*/\n",yyval.str); 
		drop_counter(); 
		}
    break;
case 459:
#line 2498 "fgl.yacc"
{
		int cnt;
		cnt=1;
		debug("Print expr (1)");
		//print_expr($<ptr>4);
		sprintf(yyval.str,"{int _retvars;\n_retvars=aclfgl_%s(%s); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001);chk_err(%d,\"%s\");}\n}\n}\n", yyvsp[-5].str,yyvsp[-1].str, lastlineno,infilename);
		yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		}
    break;
case 460:
#line 2507 "fgl.yacc"
{
        sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0);
        new_counter();
}
    break;
case 461:
#line 2512 "fgl.yacc"
{
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;
case 462:
#line 2515 "fgl.yacc"
{
	char buff[256];
        char *ptr;
        strcpy(buff,yyvsp[-3].str);
        ptr=strchr(buff,',');
        *ptr=0;
        ptr++;
	sprintf(yyval.str,"{int _retvars;\n_retvars=call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001);chk_err(%d,\"%s\");pop_args(_retvars);push_null();}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
	yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
}
    break;
case 463:
#line 2529 "fgl.yacc"
{inc_counter();chk4var=1;}
    break;
case 464:
#line 2529 "fgl.yacc"
{chk4var=0;}
    break;
case 465:
#line 2529 "fgl.yacc"
{
//sprintf($<str>$,"%s aclfgl_date(1);\n",$<str>4,$<str>1);
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;
case 466:
#line 2533 "fgl.yacc"
{inc_counter();chk4var=1;}
    break;
case 467:
#line 2533 "fgl.yacc"
{chk4var=0;}
    break;
case 468:
#line 2533 "fgl.yacc"
{
//sprintf($<str>$,"%s aclfgl_month(1);\n",$<str>4,$<str>1);
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;
case 469:
#line 2537 "fgl.yacc"
{inc_counter();chk4var=1;}
    break;
case 470:
#line 2537 "fgl.yacc"
{chk4var=0;}
    break;
case 471:
#line 2537 "fgl.yacc"
{
//sprintf($<str>$,"%s aclfgl_day(1);\n",$<str>4,$<str>1);
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;
case 472:
#line 2541 "fgl.yacc"
{inc_counter();chk4var=1;}
    break;
case 473:
#line 2541 "fgl.yacc"
{chk4var=0;}
    break;
case 474:
#line 2541 "fgl.yacc"
{
//sprintf($<str>$,"%s aclfgl_year(1);\n",$<str>4,$<str>1);
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;
case 476:
#line 2550 "fgl.yacc"
{ 
int cnt; 
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001);chk_err(%d,\"%s\");}\n}\n", 
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

}
    break;
case 477:
#line 2557 "fgl.yacc"
{sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;
case 478:
#line 2558 "fgl.yacc"
{
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;
case 479:
#line 2563 "fgl.yacc"
{sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 480:
#line 2567 "fgl.yacc"
{ sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 483:
#line 2574 "fgl.yacc"
{
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	}
    break;
case 484:
#line 2579 "fgl.yacc"
{ inc_counter(); sprintf(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		}
    break;
case 485:
#line 2586 "fgl.yacc"
{ 
//sprintf($<str>$,"%s upshift_stk();",$<str>3);
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
}
    break;
case 486:
#line 2591 "fgl.yacc"
{ 
	//sprintf($<str>$,"%s upshift_stk();",$<str>3);
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
}
    break;
case 487:
#line 2595 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%d);",atoi(yyvsp[-1].str));
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 488:
#line 2598 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%s);",yyvsp[-1].str);
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 489:
#line 2603 "fgl.yacc"
{
//sprintf($<str>$,"%s push_double(-1);pushop(OP_MULT)",$<str>1);
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
}
    break;
case 490:
#line 2607 "fgl.yacc"
{
//sprintf($<str>$,"%s push_double(-28.3465);pushop(OP_MULT);",$<str>1);
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
}
    break;
case 491:
#line 2611 "fgl.yacc"
{
//sprintf($<str>$,"%s push_double(-72.0);pushop(OP_MULT);",$<str>1);
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
}
    break;
case 492:
#line 2618 "fgl.yacc"
{
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;
case 493:
#line 2622 "fgl.yacc"
{debug("For_cmds\n");}
    break;
case 494:
#line 2623 "fgl.yacc"
{

pop_blockcommand("FOR");
print_for_end();
printcomment(" /*END FOR*/\n");}
    break;
case 495:
#line 2630 "fgl.yacc"
{
		print_for_default_step();
	}
    break;
case 497:
#line 2638 "fgl.yacc"
{
push_blockcommand("FOREACH");
}
    break;
case 498:
#line 2642 "fgl.yacc"
{
print_foreach_start();
printcomment(" /* foreach */\n");
}
    break;
case 499:
#line 2647 "fgl.yacc"
{
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 500:
#line 2651 "fgl.yacc"
{
add_continue_blockcommand ("FOREACH");  
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;
case 501:
#line 2661 "fgl.yacc"
{
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;
case 502:
#line 2667 "fgl.yacc"
{
		print_getwin();
	}
    break;
case 503:
#line 2674 "fgl.yacc"
{
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;
case 510:
#line 2691 "fgl.yacc"
{
		print_event('B');
        }
    break;
case 511:
#line 2693 "fgl.yacc"
{
		print_event_2();
        }
    break;
case 512:
#line 2696 "fgl.yacc"
{
		print_event('b');
        }
    break;
case 513:
#line 2698 "fgl.yacc"
{
		print_event_2();
        }
    break;
case 518:
#line 2712 "fgl.yacc"
{
		print_event('A');
        }
    break;
case 519:
#line 2714 "fgl.yacc"
{
		print_event_2();
        }
    break;
case 520:
#line 2717 "fgl.yacc"
{
		print_event('a');
        }
    break;
case 521:
#line 2719 "fgl.yacc"
{
		print_event_2();
        }
    break;
case 534:
#line 2750 "fgl.yacc"
{ 
			print_gtk_field('B',0);
		}
    break;
case 535:
#line 2752 "fgl.yacc"
{
			print_gtk_field_2();
		}
    break;
case 536:
#line 2755 "fgl.yacc"
{ 
			print_gtk_field('A',0);
		}
    break;
case 537:
#line 2757 "fgl.yacc"
{
			print_gtk_field_2();
		}
    break;
case 538:
#line 2760 "fgl.yacc"
{
			print_gtk_field('b',yyvsp[0].str);
		}
    break;
case 539:
#line 2762 "fgl.yacc"
{ 
			print_gtk_field_2();
		}
    break;
case 540:
#line 2765 "fgl.yacc"
{
			print_gtk_field('a',yyvsp[0].str);
		}
    break;
case 541:
#line 2767 "fgl.yacc"
{ 
			print_gtk_field_2();
		}
    break;
case 542:
#line 2770 "fgl.yacc"
{ 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;
case 543:
#line 2772 "fgl.yacc"
{ 
			print_gtk_field_2();
		}
    break;
case 544:
#line 2780 "fgl.yacc"
{
		print_niy("Free Cursor");
		strcpy(yyval.str,"");
		}
    break;
case 545:
#line 2788 "fgl.yacc"
{sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;
case 546:
#line 2789 "fgl.yacc"
{sprintf(yyval.str,"-1");}
    break;
case 547:
#line 2790 "fgl.yacc"
{sprintf(yyval.str,"%d",atoi(yyvsp[0].str))+1;}
    break;
case 548:
#line 2791 "fgl.yacc"
{sprintf(yyval.str,"1");}
    break;
case 549:
#line 2792 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);}
    break;
case 550:
#line 2793 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);}
    break;
case 554:
#line 2801 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;
case 556:
#line 2807 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;
case 557:
#line 2808 "fgl.yacc"
{ sprintf(yyval.str,"int_to_id($<str>3)"); }
    break;
case 558:
#line 2809 "fgl.yacc"
{ sprintf(yyval.str,"int_to_id($<str>3)"); }
    break;
case 559:
#line 2811 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;
case 560:
#line 2813 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;
case 561:
#line 2815 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;
case 562:
#line 2817 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 563:
#line 2819 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;
case 564:
#line 2822 "fgl.yacc"
{
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;
case 565:
#line 2828 "fgl.yacc"
{sprintf(yyval.str,"push_char(%s);\n",yyvsp[0].str);
	addmap("Cursor",last_var,curr_func,yylineno,infilename);
}
    break;
case 566:
#line 2832 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 567:
#line 2834 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;
case 568:
#line 2840 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;
case 569:
#line 2845 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;
case 570:
#line 2850 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;
case 571:
#line 2855 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 572:
#line 2855 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 573:
#line 2858 "fgl.yacc"
{ 
			strcpy(yyval.str,downshift(yyvsp[-1].str)) ;
}
    break;
case 574:
#line 2861 "fgl.yacc"
{ strcpy(yyval.str,downshift(yyvsp[0].str)) ; }
    break;
case 575:
#line 2865 "fgl.yacc"
{
			sprintf(yyval.str,"%s",yyvsp[-1].str) ;
			}
    break;
case 576:
#line 2870 "fgl.yacc"
{
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;
case 577:
#line 2874 "fgl.yacc"
{
//sprintf($<str>$,"clob(\"%s\",%s)",clobber,$<str>3);
strcpy(yyval.str,yyvsp[-1].str);
sprintf(last_var,"->%s",yyvsp[-1].str);
}
    break;
case 580:
#line 2883 "fgl.yacc"
{
		debug("Setident\n");
		//chk4var=1;
	strcpy(yyval.str,"");
	   }
    break;
case 581:
#line 2889 "fgl.yacc"
{
		debug("Unsetident\n");
		chk4var=0;
		}
    break;
case 582:
#line 2893 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;
case 583:
#line 2895 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;
case 584:
#line 2897 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;
case 585:
#line 2899 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;
case 586:
#line 2901 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 587:
#line 2903 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;
case 588:
#line 2906 "fgl.yacc"
{
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;
case 590:
#line 2915 "fgl.yacc"
{
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;
case 635:
#line 2967 "fgl.yacc"
{
	print_goto(yyvsp[0].str);
}
    break;
case 636:
#line 2975 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;
case 638:
#line 2982 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 639:
#line 2985 "fgl.yacc"
{
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;
case 640:
#line 2991 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;
case 641:
#line 2997 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;
case 642:
#line 3001 "fgl.yacc"
{
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;
case 643:
#line 3005 "fgl.yacc"
{
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;
case 644:
#line 3011 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;
case 645:
#line 3015 "fgl.yacc"
{
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;
case 646:
#line 3019 "fgl.yacc"
{
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;
case 647:
#line 3024 "fgl.yacc"
{start_state("messagebox",1);}
    break;
case 648:
#line 3029 "fgl.yacc"
{start_state("messagebox",0);}
    break;
case 662:
#line 3052 "fgl.yacc"
{
		print_if_start();
	}
    break;
case 663:
#line 3057 "fgl.yacc"
{
		print_if_end();
	}
    break;
case 665:
#line 3062 "fgl.yacc"
{
		print_if_else();
	}
    break;
case 667:
#line 3067 "fgl.yacc"
{
	print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;
case 668:
#line 3074 "fgl.yacc"
{debug("init to\n");}
    break;
case 669:
#line 3075 "fgl.yacc"
{
	print_init();
 }
    break;
case 670:
#line 3078 "fgl.yacc"
{
	print_init_table(yyvsp[0].str);
}
    break;
case 672:
#line 3084 "fgl.yacc"
{sprintf(yyval.str,"%s,$s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 673:
#line 3088 "fgl.yacc"
{setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;
case 674:
#line 3089 "fgl.yacc"
{setrecord(yyval.str,yyvsp[-2].str,0);}
    break;
case 677:
#line 3097 "fgl.yacc"
{
sprintf(yyval.str,"0");
}
    break;
case 678:
#line 3099 "fgl.yacc"
{
sprintf(yyval.str,"1");
}
    break;
case 681:
#line 3108 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
}
    break;
case 682:
#line 3110 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 683:
#line 3114 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
}
    break;
case 684:
#line 3116 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 685:
#line 3119 "fgl.yacc"
{
		print_befaft_field_1("AFT_ROW");
}
    break;
case 686:
#line 3121 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 687:
#line 3124 "fgl.yacc"
{
		printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;
case 688:
#line 3127 "fgl.yacc"
{
	print_befaft_field_2();
		}
    break;
case 689:
#line 3130 "fgl.yacc"
{
	print_onkey_1(yyvsp[0].str);
}
    break;
case 690:
#line 3132 "fgl.yacc"
{
	print_onkey_2();
}
    break;
case 691:
#line 3135 "fgl.yacc"
{
		print_befaft_field_1("AFTER_INP");
}
    break;
case 692:
#line 3137 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 693:
#line 3140 "fgl.yacc"
{
		print_befaft_field_1("BEFORE_INP");
}
    break;
case 694:
#line 3142 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 695:
#line 3145 "fgl.yacc"
{printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;
case 696:
#line 3147 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 697:
#line 3150 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
}
    break;
case 698:
#line 3152 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 699:
#line 3158 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;
case 700:
#line 3159 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 701:
#line 3167 "fgl.yacc"
{strcpy(yyval.str,"AFT_INSERT");}
    break;
case 702:
#line 3168 "fgl.yacc"
{strcpy(yyval.str,"AFT_DELETE");}
    break;
case 703:
#line 3173 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;
case 704:
#line 3174 "fgl.yacc"
{
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;
case 705:
#line 3183 "fgl.yacc"
{strcpy(yyval.str,"BEF_INSERT");}
    break;
case 706:
#line 3184 "fgl.yacc"
{strcpy(yyval.str,"BEF_DELETE");}
    break;
case 707:
#line 3191 "fgl.yacc"
{sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;
case 708:
#line 3192 "fgl.yacc"
{
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 709:
#line 3200 "fgl.yacc"
{sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;
case 710:
#line 3201 "fgl.yacc"
{
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 711:
#line 3210 "fgl.yacc"
{
print_next_field(yyvsp[0].str);
}
    break;
case 712:
#line 3215 "fgl.yacc"
{
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 713:
#line 3220 "fgl.yacc"
{sprintf(yyval.str,"\"+\",0");}
    break;
case 714:
#line 3221 "fgl.yacc"
{sprintf(yyval.str,"\"-\",0");}
    break;
case 716:
#line 3226 "fgl.yacc"
{
print_input_1();
}
    break;
case 717:
#line 3229 "fgl.yacc"
{
print_input_2(yyvsp[-2].str);
}
    break;
case 718:
#line 3237 "fgl.yacc"
{
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;
case 719:
#line 3242 "fgl.yacc"
{
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;
case 720:
#line 3246 "fgl.yacc"
{
inp_flags=0;}
    break;
case 721:
#line 3248 "fgl.yacc"
{
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;
case 722:
#line 3257 "fgl.yacc"
{
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;
case 723:
#line 3262 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 724:
#line 3263 "fgl.yacc"
{strcpy(yyval.str,"-1");}
    break;
case 725:
#line 3264 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 726:
#line 3265 "fgl.yacc"
{sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;
case 727:
#line 3268 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 729:
#line 3272 "fgl.yacc"
{iskey=1;}
    break;
case 730:
#line 3272 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;
case 731:
#line 3274 "fgl.yacc"
{strcpy(yyval.str,"->ANY");}
    break;
case 732:
#line 3277 "fgl.yacc"
{iskey=1;}
    break;
case 733:
#line 3277 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;
case 734:
#line 3279 "fgl.yacc"
{sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;
case 735:
#line 3283 "fgl.yacc"
{start_state("keymode",1);iskey=1;}
    break;
case 736:
#line 3283 "fgl.yacc"
{sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;
case 737:
#line 3285 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 738:
#line 3286 "fgl.yacc"
{strcpy(yyval.str,yyvsp[-1].str);}
    break;
case 740:
#line 3289 "fgl.yacc"
{
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 741:
#line 3294 "fgl.yacc"
{start_state("keymode",1);}
    break;
case 742:
#line 3294 "fgl.yacc"
{start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;
case 747:
#line 3300 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 748:
#line 3301 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 749:
#line 3302 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 750:
#line 3303 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 751:
#line 3304 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 752:
#line 3305 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 753:
#line 3306 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 754:
#line 3307 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 755:
#line 3308 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 756:
#line 3309 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 757:
#line 3310 "fgl.yacc"
{ rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;
case 758:
#line 3314 "fgl.yacc"
{
	exitwith ("Expecting a ':'");
}
    break;
case 759:
#line 3318 "fgl.yacc"
{
	print_label(yyvsp[-1].str);
}
    break;
case 760:
#line 3325 "fgl.yacc"
{chk4var=1;}
    break;
case 761:
#line 3325 "fgl.yacc"
{chk4var=0;
printcomment("/*let3*/\n");}
    break;
case 762:
#line 3327 "fgl.yacc"
{
int from_exprs;
int to_vars;
debug("/*processing let*/\n");
expand_obind();
to_vars=how_many_in_bind('o');
debug("/* To vars=%d */\n",to_vars);
if (to_vars>=1) {

	if (!print_let_manyvars(yyvsp[0].str)) {
    		yyerror("Number of variables in let not equal to number of values\n");YYERROR;
	}

} else {
    print_bind_pop1('o');
}

}
    break;
case 763:
#line 3347 "fgl.yacc"
{
	print_push_null();
	strcpy(yyval.str,"1");
}
    break;
case 765:
#line 3356 "fgl.yacc"
{
		if (!print_linked_cmd('S',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;
case 766:
#line 3362 "fgl.yacc"
{
		 if (!print_linked_cmd('D',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;
case 767:
#line 3368 "fgl.yacc"
{
		 if (!print_linked_cmd('U',yyvsp[0].str)) yyerror("Not a linked variable");
}
    break;
case 768:
#line 3374 "fgl.yacc"
{
int vtype;
vtype=scan_variable(yyvsp[-1].str);
if (vtype!=11&&vtype!=12) {
yyerror("Only Byte & Text may be located...");
YYERROR;
}
print_locate('M',yyvsp[-1].str,"0");


}
    break;
case 769:
#line 3385 "fgl.yacc"
{
int vtype;
vtype=scan_variable(yyvsp[-2].str);
if (vtype!=11&&vtype!=12) {
yyerror("Only Byte & Text may be located...");
YYERROR;
}

print_locate('F',yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 770:
#line 3400 "fgl.yacc"
{
int a;
modlevel=-1;
//read_glob_var = 1; 
print_variables(1);
//read_glob_var = 0; 
set_mod_level(varcnt);set_4gl_vars();set_mod_level(0);
strcpy(curr_func,"[Module]");
}
    break;
case 771:
#line 3408 "fgl.yacc"
{inmod();}
    break;
case 773:
#line 3412 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 777:
#line 3420 "fgl.yacc"
{
		print_at_termination(yyvsp[0].str);
	}
    break;
case 792:
#line 3441 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 793:
#line 3442 "fgl.yacc"
{
strcpy(yyval.str,"static ");
}
    break;
case 794:
#line 3447 "fgl.yacc"
{
clr_variable(); lastlineno=yylineno;
clr_function_constants (); 
}
    break;
case 795:
#line 3452 "fgl.yacc"
{ 
sprintf(curr_func,"%s",yyvsp[-1].str);
addmap("Declare Function",curr_func,"MODULE",yylineno,infilename);
print_func_start(yyvsp[-3].str,yyvsp[-1].str,0);
cnt=0;
 }
    break;
case 796:
#line 3459 "fgl.yacc"
{
printcomment("/* new function %s parameters*/\n",yyvsp[-1].str); 
push_blockcommand("FUNC");printcomment("/* define section */\n");}
    break;
case 797:
#line 3463 "fgl.yacc"
{
int c;
printcomment("/*end of define section */\n");
c=print_param('f');
print_func_args(c);

}
    break;
case 799:
#line 3473 "fgl.yacc"
{
		print_func_defret0();
		pop_blockcommand("FUNC");
		print_func_end();
clr_function_constants ();
printcomment("/*end function*/\n");}
    break;
case 800:
#line 3481 "fgl.yacc"
{strcpy(yyval.str,"0");cnt=0;}
    break;
case 801:
#line 3482 "fgl.yacc"
{strcpy(yyval.str,"1");cnt=1;}
    break;
case 802:
#line 3483 "fgl.yacc"
{sprintf(yyval.str,"%d",++cnt);}
    break;
case 803:
#line 3486 "fgl.yacc"
{ 
lastlineno=yylineno;
sprintf(curr_func,"MAIN");
clr_variable(); 
push_blockcommand("MAIN"); 
addmap("MAIN",curr_func,"MODULE",yylineno,infilename);
print_main_1();
}
    break;
case 804:
#line 3495 "fgl.yacc"
{
print_fgllib_start(hdr_dbname);

}
    break;
case 805:
#line 3499 "fgl.yacc"
{
pop_blockcommand("MAIN");
print_main_end();
printcomment("/*end main */\n");}
    break;
case 806:
#line 3504 "fgl.yacc"
{

print_return(atoi(yyvsp[0].str));
}
    break;
case 807:
#line 3509 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 808:
#line 3509 "fgl.yacc"
{
printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 809:
#line 3514 "fgl.yacc"
{open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;
case 810:
#line 3519 "fgl.yacc"
{strcpy(yyval.str,"");lastlineno=yylineno;}
    break;
case 811:
#line 3520 "fgl.yacc"
{
	if (glob_only==1) {
       	debug("Read globals section so Im done\n");
       	YYACCEPT;
	}

  	//read_glob_var = 1;
  	//print_variables (1);
  	//read_glob_var = 0;
	set_mod_level(varcnt);
}
    break;
case 818:
#line 3541 "fgl.yacc"
{
strcpy(curr_func,"[Globals]");
push_blockcommand("GLOBALS");
printcomment("/* start of globals */\n");
}
    break;
case 819:
#line 3547 "fgl.yacc"
{
pop_blockcommand("GLOBALS");
}
    break;
case 820:
#line 3552 "fgl.yacc"
{
printcomment("/* end of globals */");
debug("end of globals\n");
lastlineno=yylineno;
}
    break;
case 821:
#line 3557 "fgl.yacc"
{
int a;
char b[256];
lastlineno=yylineno;

strcpy(b,yyvsp[0].str);

tr_glob_fname(b);

debug("Reading globals file %s\n",b);
rm_quote(b);
read_glob(b);
/*
if (glob_only==0) {
         debug("Opening globals file\n");
         a=read_globals($<str>1);
         debug("Done globals file\n");
         }
*/
}
    break;
case 822:
#line 3580 "fgl.yacc"
{
addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;
case 823:
#line 3584 "fgl.yacc"
{
char buff[80];
sprintf(buff,"%s_%s_%d",yyvsp[-4].str,yyvsp[-6].str,atoi(yyvsp[-1].str));
sprintf(curr_func,"%s",buff);
print_func_start("",buff,1);

cnt=0;
printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
push_blockcommand("FUNC");
printcomment("/* define section */\n");}
    break;
case 824:
#line 3595 "fgl.yacc"
{
printcomment("/*end of define section */\n");
print_param('f');
print_func_args(atoi(yyvsp[-3].str));
}
    break;
case 826:
#line 3606 "fgl.yacc"
{
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;
case 828:
#line 3614 "fgl.yacc"
{
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;
case 829:
#line 3625 "fgl.yacc"
{
	 printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;
case 830:
#line 3629 "fgl.yacc"
{
		print_menu_block_end();
	}
    break;
case 831:
#line 3636 "fgl.yacc"
{
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;
case 832:
#line 3643 "fgl.yacc"
{
		print_menu_block_end();
}
    break;
case 833:
#line 3649 "fgl.yacc"
{
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;
case 834:
#line 3654 "fgl.yacc"
{
		print_menu_block_end();
}
    break;
case 837:
#line 3661 "fgl.yacc"
{strcpy(yyval.str,"\"EMPTY\"");}
    break;
case 838:
#line 3662 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;
case 839:
#line 3664 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str); }
    break;
case 840:
#line 3665 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 841:
#line 3668 "fgl.yacc"
{strcpy(yyval.str,"\"\"");}
    break;
case 842:
#line 3669 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 843:
#line 3670 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 844:
#line 3672 "fgl.yacc"
{
	print_option_op('N',yyvsp[0].str);
}
    break;
case 845:
#line 3677 "fgl.yacc"
{
	print_option_op('S',yyvsp[0].str);
}
    break;
case 846:
#line 3682 "fgl.yacc"
{
	print_option_op('H',yyvsp[0].str);
}
    break;
case 847:
#line 3689 "fgl.yacc"
{sprintf(yyval.str,"MENU_ALL");}
    break;
case 851:
#line 3696 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 852:
#line 3698 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;
case 853:
#line 3700 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;
case 854:
#line 3707 "fgl.yacc"
{
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
}
    break;
case 855:
#line 3712 "fgl.yacc"
{
                push_blockcommand("MENUH");
        }
    break;
case 856:
#line 3716 "fgl.yacc"
{
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;
case 859:
#line 3728 "fgl.yacc"
{

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;
case 860:
#line 3733 "fgl.yacc"
{
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;
case 861:
#line 3738 "fgl.yacc"
{
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;
case 862:
#line 3741 "fgl.yacc"
{
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;
case 863:
#line 3751 "fgl.yacc"
{ 
	print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
	start_state("message",0);
}
    break;
case 866:
#line 3765 "fgl.yacc"
{start_state("message",1);}
    break;
case 868:
#line 3767 "fgl.yacc"
{start_state("message",0);}
    break;
case 869:
#line 3770 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 870:
#line 3770 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 871:
#line 3773 "fgl.yacc"
{
char buff[256];
char buff2[256];
strcpy(buff,yyvsp[0].str);
printcomment("/* .. var %s*/",buff);
if (buff[0]!=' ') addmap("Use Variable",buff,curr_func,yylineno,infilename);
if (strncmp(buff," ASSOCIATE_",11)!=0) {
convlower(buff);
}
strcpy(yyval.str,buff);
debug("Checking variable '%s'",buff);
if (scan_variable (buff) == -1&&buff[0]!=' ') { 
           sprintf(buff2,"'%s' does not represent a defined variable (1)",buff);
           yyerror(buff2); 
           exit (0);
  }
  fflush (stdout);
  mcnt = 0;
}
    break;
case 873:
#line 3796 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 874:
#line 3799 "fgl.yacc"
{ 
         sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); 
         printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;
case 875:
#line 3804 "fgl.yacc"
{

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         printcomment("/* OPEN_SQUARE.. */\n");

         sprintf(buff,"%s.%s",yyvsp[-6].str,yyvsp[-3].str);
         if (scan_variable(buff)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (2)",buff);
           yyerror(buff2); 
           YYERROR;
         }

         printcomment("/*variable with [...]*/");
         get_variable_dets (buff,&type,&arrsize,&size,&level,arrbuff);
         printcomment("/* Arrsize = %d size = %d*/",arrsize,size);
	 
         if (arrsize>0)
         {
             debug("Is array...");
             sprintf (yyval.str, "%s[%s]", buff, change_arr_elem(yyvsp[-1].str));
             printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", yyval.str,num_arr_elem(yyvsp[-1].str),num_arr_elem(arrbuff));
         }
         else
         {
             debug ("Is string...");
             sprintf (yyval.str, " substr(%s,%d,%s,0)", buff, 
                      scan_variable (buff), yyvsp[-1].str);

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;
case 879:
#line 3848 "fgl.yacc"
{
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (3)",yyvsp[-3].str);
           yyerror(buff2); 
           YYERROR;
         }

printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,1)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;
case 880:
#line 3862 "fgl.yacc"
{
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (4)",yyvsp[-3].str);
           yyerror(buff2); 
           YYERROR;
         }
printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,0)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;
case 885:
#line 3886 "fgl.yacc"
{
  int type,arrsize,size,level;
  char buff[256];
  char buff2[256];
  char arrbuff[256];
  printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  printcomment("/*here %s %x */",yyvsp[-1].str,type);
  if (scan_variable(yyvsp[-1].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (7)",yyvsp[-1].str);
           yyerror(buff2); 
           YYERROR;

	}


  debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

  if (strchr(yyvsp[0].str,':'))  {
	char lbuff[256];
	char rbuff[256];
	char tmpbuff[256];
	char *ptr;
	sprintf(lbuff,yyvsp[0].str);
	sprintf(rbuff,strchr(yyvsp[0].str,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str, change_arr_elem(lbuff));
        sprintf (yyval.str, " substr(%s,%d,%s,0)", tmpbuff, scan_variable (tmpbuff), rbuff);
  } else {
 
  if (type & 0xffff != 0 || arrsize>0)
    {
      printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " substr(%s,%d,%s,0)", yyvsp[-1].str, scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      printcomment ("/*character variable %s*/\n", yyval.str);
    }
}

  mcnt++;
}
    break;
case 886:
#line 3938 "fgl.yacc"
{
  debug ("Variable:%s\n", yyval.str);
  cnt = 1;
  sprintf (yyval.str, "1");
}
    break;
case 887:
#line 3944 "fgl.yacc"
{
  cnt++;
  sprintf (yyval.str, "%d", cnt);
  debug ("next variable %s", yyvsp[0].str);
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;
case 888:
#line 3954 "fgl.yacc"
{
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;
case 889:
#line 3959 "fgl.yacc"
{
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;
case 890:
#line 3967 "fgl.yacc"
{
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;
case 891:
#line 3972 "fgl.yacc"
{
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;
case 892:
#line 3980 "fgl.yacc"
{
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;
case 893:
#line 3985 "fgl.yacc"
{
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;
case 894:
#line 3989 "fgl.yacc"
{
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;
case 895:
#line 3996 "fgl.yacc"
{
  sprintf (yyval.str, "(%s-1)", yyvsp[0].str);
}
    break;
case 896:
#line 4001 "fgl.yacc"
{
char buff[256];
strcpy(buff,yyvsp[0].str);
addmap("Let Variable",buff,curr_func,yylineno,infilename);

if (strncmp(buff," ASSOCIATE_",11)!=0) {
convlower(buff);
}
strcpy(yyval.str,buff);
printcomment("/* %s */\n",yyvsp[0].str);
  if (scan_variable (buff) == -1&&buff[0]!=' ')
    {
      printcomment ("/*NOt a variable*/");
      sprintf(buff,"%s is not a variable",yyvsp[0].str);
      yyerror(buff);
    }

  fflush (stdout);
  mcnt = 0;
}
    break;
case 897:
#line 4022 "fgl.yacc"
{
		debug("Array..");
}
    break;
case 898:
#line 4025 "fgl.yacc"
{ sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); }
    break;
case 899:
#line 4027 "fgl.yacc"
{
  int a;
  int b;
  char buff[256];
  char buff2[256];
  printcomment("/*array variable .let. */");

  sprintf(yyval.str,"%s.%s",yyvsp[-6].str,yyvsp[-3].str);

         if (scan_variable(yyval.str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",yyval.str);
           yyerror(buff2); 
           YYERROR;
         }

  debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s.%s[%s-1]", yyvsp[-6].str, yyvsp[-3].str,yyvsp[-1].str);
      printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf(buff,"%s.%s",yyvsp[-6].str,yyvsp[-3].str);
      sprintf (yyval.str, " let_substr(%s,%d,%s,0)", buff, a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;
case 904:
#line 4075 "fgl.yacc"
{
/*OPEN_SQUARE num_list CLOSE_SQUARE*/
  int a;
  int b;
  char buff[256];
  char buff2[256];
  printcomment("/*.let. array variable */");

  debug("?2 arrvar=%s",yyvsp[-1].str);
  if (strchr(yyvsp[0].str,':'))  {
	char lbuff[256];
	char rbuff[256];
	char tmpbuff[256];
	char *ptr;
	sprintf(lbuff,yyvsp[0].str);
	sprintf(rbuff,strchr(yyvsp[0].str,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str, change_arr_elem(lbuff));
        sprintf (yyval.str, " let_substr(%s,%d,%s,0)", tmpbuff, scan_variable (tmpbuff), rbuff);
  } else {
  	b = isarrvariable (yyvsp[-1].str);
  	a = scan_variable (yyvsp[-1].str);

         if (a==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (6)",yyvsp[-1].str);
           yyerror(buff2); 
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
      sprintf (yyval.str, " let_substr(%s,%d,%s,0)", yyvsp[-1].str, scan_variable (yyvsp[-1].str), yyvsp[0].str);
      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;
case 905:
#line 4127 "fgl.yacc"
{
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;
case 907:
#line 4134 "fgl.yacc"
{
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;
case 908:
#line 4140 "fgl.yacc"
{
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;
case 909:
#line 4150 "fgl.yacc"
{
start_bind('f',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;
case 910:
#line 4155 "fgl.yacc"
{
int c;
c=add_bind('f',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;
case 911:
#line 4163 "fgl.yacc"
{
printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
printcomment("/*STarted bind 2*/\n");
sprintf(yyval.str,"");
}
    break;
case 912:
#line 4170 "fgl.yacc"
{
printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
sprintf(yyval.str,""); 
}
    break;
case 914:
#line 4178 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;
case 915:
#line 4181 "fgl.yacc"
{printcomment("/* Variable */\n");}
    break;
case 916:
#line 4182 "fgl.yacc"
{
			debug("Got an ibind thru...");
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;
case 918:
#line 4187 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;
case 919:
#line 4188 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;
case 920:
#line 4191 "fgl.yacc"
{
start_bind('o',yyvsp[0].str);
}
    break;
case 921:
#line 4194 "fgl.yacc"
{
add_bind('o',yyvsp[0].str);
sprintf(yyval.str,""); 
}
    break;
case 922:
#line 4200 "fgl.yacc"
{
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;
case 923:
#line 4206 "fgl.yacc"
{
printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;
case 924:
#line 4210 "fgl.yacc"
{
printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
sprintf(yyval.str,""); 
}
    break;
case 925:
#line 4217 "fgl.yacc"
{
printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;
case 926:
#line 4222 "fgl.yacc"
{
    printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    printcomment("/* use_arr_var complete */\n");
}
    break;
case 927:
#line 4229 "fgl.yacc"
{
start_bind('O',yyvsp[0].str);
}
    break;
case 928:
#line 4232 "fgl.yacc"
{
               add_bind('O',yyvsp[0].str);
               sprintf(yyval.str,""); 
}
    break;
case 933:
#line 4245 "fgl.yacc"
{
  int type,arrsize,size,level;
  char buff[256];
  char buff2[256];
  char arrbuff[256];
  printcomment("/*..array_r_varid..*/");

  get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff);
  sprintf(yyval.str,"%s[%s-1]",yyvsp[-3].str,yyvsp[-1].str);
}
    break;
case 934:
#line 4257 "fgl.yacc"
{
printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
printcomment("/*STarted bind 2*/\n");
sprintf(yyval.str,"");
}
    break;
case 935:
#line 4264 "fgl.yacc"
{
printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
sprintf(yyval.str,""); 
}
    break;
case 936:
#line 4271 "fgl.yacc"
{
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;
case 937:
#line 4274 "fgl.yacc"
{
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;
case 938:
#line 4279 "fgl.yacc"
{
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;
case 943:
#line 4296 "fgl.yacc"
{
	print_niy("OPEN_STATUSBOX");
}
    break;
case 944:
#line 4301 "fgl.yacc"
{
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;
case 945:
#line 4307 "fgl.yacc"
{
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;
case 947:
#line 4314 "fgl.yacc"
{ form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;
case 948:
#line 4319 "fgl.yacc"
{sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;
case 949:
#line 4322 "fgl.yacc"
{strcpy(yyval.str,"0,0");}
    break;
case 950:
#line 4323 "fgl.yacc"
{sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;
case 951:
#line 4326 "fgl.yacc"
{strcpy(yyval.str,"\"\"");}
    break;
case 952:
#line 4327 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 953:
#line 4330 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 954:
#line 4331 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 955:
#line 4336 "fgl.yacc"
{
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;
case 956:
#line 4343 "fgl.yacc"
{
	print_open_cursor(yyvsp[0].str,"0");
}
    break;
case 957:
#line 4346 "fgl.yacc"
{
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;
case 958:
#line 4352 "fgl.yacc"
{sprintf(yyval.str,"0,0");}
    break;
case 959:
#line 4354 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 960:
#line 4356 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;
case 961:
#line 4358 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 962:
#line 4361 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 963:
#line 4361 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 964:
#line 4362 "fgl.yacc"
{strcpy(yyval.str,"2");}
    break;
case 965:
#line 4367 "fgl.yacc"
{
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 966:
#line 4375 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 967:
#line 4376 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 968:
#line 4381 "fgl.yacc"
{sprintf(yyval.str,"0,0");}
    break;
case 969:
#line 4383 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 970:
#line 4385 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 974:
#line 4392 "fgl.yacc"
{
print_options('C',yyvsp[0].str);
}
    break;
case 975:
#line 4395 "fgl.yacc"
{
print_options('E',yyvsp[0].str);
}
    break;
case 976:
#line 4398 "fgl.yacc"
{
print_options('F',yyvsp[0].str);
}
    break;
case 977:
#line 4401 "fgl.yacc"
{
printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;
case 978:
#line 4404 "fgl.yacc"
{
print_options('m',yyvsp[0].str);
}
    break;
case 979:
#line 4407 "fgl.yacc"
{
print_options('P',yyvsp[0].str);
}
    break;
case 980:
#line 4410 "fgl.yacc"
{
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;
case 981:
#line 4414 "fgl.yacc"
{
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;
case 982:
#line 4418 "fgl.yacc"
{
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;
case 983:
#line 4422 "fgl.yacc"
{
print_options('N',yyvsp[0].str);
}
    break;
case 984:
#line 4425 "fgl.yacc"
{
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;
case 985:
#line 4429 "fgl.yacc"
{
print_options('H',yyvsp[0].str);
}
    break;
case 986:
#line 4432 "fgl.yacc"
{ print_set_helpfile(yyvsp[0].str); }
    break;
case 987:
#line 4433 "fgl.yacc"
{ print_set_langfile(yyvsp[0].str); }
    break;
case 988:
#line 4434 "fgl.yacc"
{
print_options('d',yyvsp[0].str);
}
    break;
case 989:
#line 4437 "fgl.yacc"
{
print_options('i',yyvsp[0].str);
}
    break;
case 990:
#line 4440 "fgl.yacc"
{
print_options('W',"1");
}
    break;
case 991:
#line 4443 "fgl.yacc"
{
print_options('W',"0");
}
    break;
case 992:
#line 4446 "fgl.yacc"
{
print_options('f',"1");
}
    break;
case 993:
#line 4449 "fgl.yacc"
{
print_options('f',"0");
}
    break;
case 994:
#line 4452 "fgl.yacc"
{
print_options('S',"1");
}
    break;
case 995:
#line 4455 "fgl.yacc"
{
print_options('S',"0");
}
    break;
case 996:
#line 4464 "fgl.yacc"
{
print_prepare(yyvsp[-2].str,yyvsp[0].str);

addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-4].str);
}
    break;
case 999:
#line 4475 "fgl.yacc"
{ 

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 1000:
#line 4482 "fgl.yacc"
{ 
int ni;
addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
print_execute(yyvsp[-2].str,1);
}
    break;
case 1002:
#line 4498 "fgl.yacc"
{
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;
case 1003:
#line 4503 "fgl.yacc"
{
		if (strcmp(yyvsp[-5].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-4].str);
                pop_blockcommand("PROMPT");
                printcomment("/* END OF PROMPT */");
                }
    break;
case 1004:
#line 4516 "fgl.yacc"
{
		print_niy("GUI PROMPT");
	}
    break;
case 1005:
#line 4521 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1006:
#line 4522 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 1007:
#line 4526 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1011:
#line 4532 "fgl.yacc"
{
	print_onkey_1(yyvsp[0].str);
}
    break;
case 1012:
#line 4534 "fgl.yacc"
{
	print_onkey_2_prompt();
}
    break;
case 1014:
#line 4549 "fgl.yacc"
{
		start_bind('i',0);
		}
    break;
case 1015:
#line 4553 "fgl.yacc"
{
		print_put();
	}
    break;
case 1016:
#line 4559 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1017:
#line 4560 "fgl.yacc"
{ strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1018:
#line 4563 "fgl.yacc"
{push_gen(PUTVAL,yyvsp[0].str);}
    break;
case 1019:
#line 4564 "fgl.yacc"
{push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1022:
#line 4573 "fgl.yacc"
{
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;
case 1023:
#line 4578 "fgl.yacc"
{
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;
case 1024:
#line 4583 "fgl.yacc"
{
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;
case 1025:
#line 4588 "fgl.yacc"
{
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;
case 1032:
#line 4610 "fgl.yacc"
{ 
}
    break;
case 1033:
#line 4613 "fgl.yacc"
{
}
    break;
case 1034:
#line 4616 "fgl.yacc"
{
}
    break;
case 1035:
#line 4619 "fgl.yacc"
{
addmap("Output to report",yyvsp[-8].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-8].str,yyvsp[-2].str); 
}
    break;
case 1036:
#line 4626 "fgl.yacc"
{
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;
case 1037:
#line 4632 "fgl.yacc"
{ sprintf(yyval.str,yyvsp[0].str); }
    break;
case 1038:
#line 4634 "fgl.yacc"
{
	print_format_every_row();
}
    break;
case 1042:
#line 4645 "fgl.yacc"
{ push_report_block("FIRST",'P');}
    break;
case 1043:
#line 4646 "fgl.yacc"
{print_rep_ret();}
    break;
case 1044:
#line 4648 "fgl.yacc"
{ push_report_block("TRAILER",'T');}
    break;
case 1045:
#line 4649 "fgl.yacc"
{print_rep_ret();}
    break;
case 1046:
#line 4651 "fgl.yacc"
{ push_report_block("HEADER",'p');}
    break;
case 1047:
#line 4652 "fgl.yacc"
{print_rep_ret();}
    break;
case 1048:
#line 4654 "fgl.yacc"
{ push_report_block("EVERY",'E');}
    break;
case 1049:
#line 4655 "fgl.yacc"
{print_rep_ret();}
    break;
case 1050:
#line 4657 "fgl.yacc"
{ push_report_block("LAST",'L');}
    break;
case 1051:
#line 4658 "fgl.yacc"
{print_rep_ret();}
    break;
case 1052:
#line 4659 "fgl.yacc"
{
int a;
char buff[80];

a=scan_orderby(yyvsp[0].str,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",yyvsp[0].str);
   yyerror(buff);
	YYERROR;
}
sprintf(buff,"%d",a+1);
push_report_block(buff,'B');
set_curr_block(a+1);
}
    break;
case 1053:
#line 4673 "fgl.yacc"
{print_rep_ret();}
    break;
case 1054:
#line 4675 "fgl.yacc"
{ 
int a;
char buff[80];

a=scan_orderby(yyvsp[0].str,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",yyvsp[0].str);
   yyerror(buff);
	YYERROR;
}

sprintf(buff,"%d",a+1);
push_report_block(buff,'A');
set_curr_block(a+1);

}
    break;
case 1055:
#line 4691 "fgl.yacc"
{print_rep_ret();}
    break;
case 1062:
#line 4701 "fgl.yacc"
{start_state("skip",1);}
    break;
case 1063:
#line 4701 "fgl.yacc"
{
	print_need_lines();
	start_state("skip",0);
}
    break;
case 1064:
#line 4707 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1065:
#line 4707 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 1066:
#line 4710 "fgl.yacc"
{start_state("KWLINE",1);}
    break;
case 1067:
#line 4710 "fgl.yacc"
{
char buff[256];
strcpy(buff,yyvsp[0].str);
if (buff[0]=='1') {
	print_skip_lines();
} else {
	if (rep_type!=REP_TYPE_PDF) { yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(yyvsp[-2].str);
}
start_state("KWLINE",0); 
}
    break;
case 1068:
#line 4720 "fgl.yacc"
{ print_skip_top(); }
    break;
case 1069:
#line 4721 "fgl.yacc"
{ print_niy("FONT SIZE"); }
    break;
case 1070:
#line 4722 "fgl.yacc"
{
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;
case 1071:
#line 4729 "fgl.yacc"
{
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;
case 1072:
#line 4741 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1078:
#line 4752 "fgl.yacc"
{
	print_niy("PRINT AT...");
}
    break;
case 1079:
#line 4757 "fgl.yacc"
{
	print_report_print(0,yyvsp[0].str,0);
}
    break;
case 1080:
#line 4761 "fgl.yacc"
{ 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1081:
#line 4766 "fgl.yacc"
{ 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1082:
#line 4772 "fgl.yacc"
{ strcpy(yyval.str,get_default_scaling());}
    break;
case 1083:
#line 4773 "fgl.yacc"
{ strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;
case 1084:
#line 4774 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1085:
#line 4778 "fgl.yacc"
{strcpy(yyval.str,"tiff");}
    break;
case 1086:
#line 4779 "fgl.yacc"
{strcpy(yyval.str,"gif");}
    break;
case 1087:
#line 4780 "fgl.yacc"
{strcpy(yyval.str,"png");}
    break;
case 1088:
#line 4781 "fgl.yacc"
{strcpy(yyval.str,"jpeg");}
    break;
case 1089:
#line 4785 "fgl.yacc"
{
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;
case 1090:
#line 4795 "fgl.yacc"
{
strcpy(yyval.str,"0");
}
    break;
case 1091:
#line 4797 "fgl.yacc"
{
strcpy(yyval.str,"1");
}
    break;
case 1092:
#line 4802 "fgl.yacc"
{
	print_report_print(1,0,yyvsp[0].str);
	}
    break;
case 1093:
#line 4805 "fgl.yacc"
{
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;
case 1094:
#line 4810 "fgl.yacc"
{
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;
case 1095:
#line 4817 "fgl.yacc"
{
int a;
a=add_report_agg('S',yyvsp[-2].str,yyvsp[0].str,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1096:
#line 4824 "fgl.yacc"
{
int a;
a=add_report_agg('C',yyvsp[-2].str,yyvsp[0].str,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1097:
#line 4831 "fgl.yacc"
{
int a;
a=add_report_agg('P',yyvsp[-2].str,yyvsp[0].str,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;
case 1098:
#line 4838 "fgl.yacc"
{
int a;
a=add_report_agg('A',yyvsp[-2].str,yyvsp[0].str,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;
case 1099:
#line 4845 "fgl.yacc"
{
int a;
a=add_report_agg('A',yyvsp[-2].str,yyvsp[0].str,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;
case 1100:
#line 4852 "fgl.yacc"
{
int a;
a=add_report_agg('N',yyvsp[-2].str,yyvsp[0].str,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1101:
#line 4859 "fgl.yacc"
{
int a;
a=add_report_agg('X',yyvsp[-2].str,yyvsp[0].str,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1106:
#line 4872 "fgl.yacc"
{rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;
case 1107:
#line 4873 "fgl.yacc"
{rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;
case 1108:
#line 4874 "fgl.yacc"
{rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;
case 1109:
#line 4875 "fgl.yacc"
{rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;
case 1110:
#line 4876 "fgl.yacc"
{rep_struct.page_length=atoi(yyvsp[0].str);}
    break;
case 1111:
#line 4877 "fgl.yacc"
{ rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;
case 1112:
#line 4878 "fgl.yacc"
{rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1113:
#line 4879 "fgl.yacc"
{rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1114:
#line 4880 "fgl.yacc"
{rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1115:
#line 4881 "fgl.yacc"
{strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;
case 1118:
#line 4887 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;
case 1119:
#line 4888 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;
case 1120:
#line 4889 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;
case 1121:
#line 4890 "fgl.yacc"
{sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;
case 1126:
#line 4899 "fgl.yacc"
{pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;
case 1127:
#line 4900 "fgl.yacc"
{pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;
case 1128:
#line 4901 "fgl.yacc"
{pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;
case 1129:
#line 4902 "fgl.yacc"
{pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;
case 1130:
#line 4903 "fgl.yacc"
{pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;
case 1131:
#line 4904 "fgl.yacc"
{pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;
case 1132:
#line 4905 "fgl.yacc"
{strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;
case 1133:
#line 4906 "fgl.yacc"
{pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;
case 1134:
#line 4907 "fgl.yacc"
{pdf_rep_struct.paper_size=1;}
    break;
case 1135:
#line 4908 "fgl.yacc"
{pdf_rep_struct.paper_size=2;}
    break;
case 1136:
#line 4909 "fgl.yacc"
{pdf_rep_struct.paper_size=3;}
    break;
case 1140:
#line 4913 "fgl.yacc"
{pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1141:
#line 4914 "fgl.yacc"
{pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1145:
#line 4921 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;
case 1146:
#line 4928 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
}
    break;
case 1147:
#line 4934 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;
case 1148:
#line 4944 "fgl.yacc"
{
rep_type=REP_TYPE_NORMAL;
clr_variable(); lastlineno=yylineno; init_report_structure(&rep_struct);
}
    break;
case 1149:
#line 4949 "fgl.yacc"
{
inc_report_cnt();
sprintf(curr_func,"%s",yyvsp[-1].str);
addmap("Define Report",curr_func,"MODULE",yylineno,infilename);
set_curr_rep_name(yyvsp[-1].str);
print_report_1(yyvsp[-1].str);
push_blockcommand("REPORT");
}
    break;
case 1150:
#line 4958 "fgl.yacc"
{
lastlineno=yylineno;
}
    break;
case 1151:
#line 4963 "fgl.yacc"
{
print_report_2(0,yyvsp[0].str);
rordcnt=atoi(yyvsp[0].str);
}
    break;
case 1152:
#line 4968 "fgl.yacc"
{
print_report_ctrl();
}
    break;
case 1153:
#line 4972 "fgl.yacc"
{
pop_blockcommand("REPORT");
print_report_end() ;
}
    break;
case 1154:
#line 4980 "fgl.yacc"
{ sprintf(yyval.str,"");}
    break;
case 1155:
#line 4981 "fgl.yacc"
{
sprintf(yyval.str,"%s", yyvsp[0].str);
}
    break;
case 1157:
#line 4986 "fgl.yacc"
{
print_if_else();
}
    break;
case 1159:
#line 4992 "fgl.yacc"
{
if (!in_command("REPORT")) {
	yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;
case 1160:
#line 5003 "fgl.yacc"
{sprintf(yyval.str,"\"\"");}
    break;
case 1162:
#line 5010 "fgl.yacc"
{
rep_type=REP_TYPE_PDF;
clr_variable(); lastlineno=yylineno; pdf_init_report_structure(&pdf_rep_struct);
}
    break;
case 1163:
#line 5015 "fgl.yacc"
{
inc_report_cnt();
sprintf(curr_func,"%s",yyvsp[-1].str);
addmap("Define PDF Report",curr_func,"MODULE",yylineno,infilename);
set_curr_rep_name(yyvsp[-1].str);
print_report_1(yyvsp[-1].str);
push_blockcommand("REPORT");
}
    break;
case 1164:
#line 5024 "fgl.yacc"
{
lastlineno=yylineno;
}
    break;
case 1165:
#line 5029 "fgl.yacc"
{
print_report_2(1,yyvsp[0].str);
rordcnt=atoi(yyvsp[0].str);
}
    break;
case 1166:
#line 5034 "fgl.yacc"
{
print_report_ctrl();
}
    break;
case 1167:
#line 5037 "fgl.yacc"
{
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;
case 1168:
#line 5043 "fgl.yacc"
{ sprintf(yyval.str,yyvsp[0].str); }
    break;
case 1169:
#line 5047 "fgl.yacc"
{new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;
case 1170:
#line 5051 "fgl.yacc"
{
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;
case 1171:
#line 5055 "fgl.yacc"
{
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;
case 1172:
#line 5059 "fgl.yacc"
{
	print_returning();
   }
    break;
case 1173:
#line 5065 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1174:
#line 5066 "fgl.yacc"
{ sprintf(yyval.str,"rep.right_margin"); }
    break;
case 1175:
#line 5067 "fgl.yacc"
{ sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;
case 1176:
#line 5068 "fgl.yacc"
{ sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;
case 1177:
#line 5070 "fgl.yacc"
{
print_system_run(0,0);
}
    break;
case 1178:
#line 5072 "fgl.yacc"
{
print_system_run(1,yyvsp[0].str);
}
    break;
case 1179:
#line 5075 "fgl.yacc"
{
print_system_run(2,0);
}
    break;
case 1180:
#line 5079 "fgl.yacc"
{
print_system_run(0,0);
}
    break;
case 1181:
#line 5082 "fgl.yacc"
{
print_system_run(0,0);
/* FIXME */
}
    break;
case 1182:
#line 5089 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);
}
    break;
case 1183:
#line 5094 "fgl.yacc"
{sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;
case 1184:
#line 5095 "fgl.yacc"
{sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;
case 1185:
#line 5096 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 1187:
#line 5101 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);

}
    break;
case 1188:
#line 5109 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1189:
#line 5110 "fgl.yacc"
{insql=1;}
    break;
case 1190:
#line 5110 "fgl.yacc"
{insql=0;}
    break;
case 1191:
#line 5111 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1192:
#line 5112 "fgl.yacc"
{insql=1;}
    break;
case 1193:
#line 5112 "fgl.yacc"
{insql=0;}
    break;
case 1194:
#line 5113 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1195:
#line 5116 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1196:
#line 5118 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1204:
#line 5137 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1207:
#line 5148 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1211:
#line 5158 "fgl.yacc"
{sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1217:
#line 5164 "fgl.yacc"
{ 
	print_set_conn(yyvsp[0].str);
}
    break;
case 1218:
#line 5167 "fgl.yacc"
{
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1219:
#line 5170 "fgl.yacc"
{
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1220:
#line 5176 "fgl.yacc"
{strcpy(yyval.str,"\"default\"");}
    break;
case 1222:
#line 5182 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1224:
#line 5183 "fgl.yacc"
{
		print_sleep();
	}
    break;
case 1225:
#line 5193 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1226:
#line 5196 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1227:
#line 5197 "fgl.yacc"
{ 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); 
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1228:
#line 5203 "fgl.yacc"
{
pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); 
sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1230:
#line 5212 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1232:
#line 5217 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1233:
#line 5218 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1235:
#line 5222 "fgl.yacc"
{
sprintf(yyval.str," %s , %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1237:
#line 5231 "fgl.yacc"
{
sprintf(yyval.str," %s = %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1238:
#line 5236 "fgl.yacc"
{push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1239:
#line 5237 "fgl.yacc"
{push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1240:
#line 5240 "fgl.yacc"
{push_gen(UPDVAL,yyvsp[0].str);}
    break;
case 1241:
#line 5241 "fgl.yacc"
{push_gen(UPDVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1245:
#line 5248 "fgl.yacc"
{
		print_sql_commit(0);
		}
    break;
case 1246:
#line 5257 "fgl.yacc"
{ insql=1;start_bind('i',0);}
    break;
case 1247:
#line 5258 "fgl.yacc"
{
sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1248:
#line 5263 "fgl.yacc"
{insql=1;}
    break;
case 1249:
#line 5263 "fgl.yacc"
{
insql=0;
sprintf(yyval.str," %s %s %s %s" ,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1251:
#line 5269 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1252:
#line 5271 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1254:
#line 5277 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1256:
#line 5283 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1258:
#line 5289 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1261:
#line 5299 "fgl.yacc"
{
      print_fetch_1();
    }
    break;
case 1262:
#line 5303 "fgl.yacc"
{
      print_fetch_2();
    }
    break;
case 1263:
#line 5307 "fgl.yacc"
{
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;
case 1264:
#line 5314 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 1265:
#line 5318 "fgl.yacc"
{sprintf(yyval.str,"%s,%d,1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 1266:
#line 5324 "fgl.yacc"
{
debug("no into\n");
sprintf(yyval.str,"0,0");
}
    break;
case 1267:
#line 5328 "fgl.yacc"
{
debug("FETCH INTO  ...");
start_bind('i',0,-1);
}
    break;
case 1268:
#line 5332 "fgl.yacc"
{
int ni;
ni=print_bind('i');
sprintf(yyval.str,"%d,ibind",ni);
}
    break;
case 1269:
#line 5339 "fgl.yacc"
{
debug("no into\n");
sprintf(yyval.str,"0,0");
}
    break;
case 1270:
#line 5343 "fgl.yacc"
{
debug("FETCH INTO  ...");
start_bind('i',0,-1);
}
    break;
case 1271:
#line 5347 "fgl.yacc"
{
int ni;
//ni=print_bind('i');
//sprintf($<str>$,"%d,ibind",ni);
}
    break;
case 1272:
#line 5355 "fgl.yacc"
{
sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;
case 1273:
#line 5358 "fgl.yacc"
{sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;
case 1274:
#line 5360 "fgl.yacc"
{sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;
case 1275:
#line 5362 "fgl.yacc"
{sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;
case 1276:
#line 5364 "fgl.yacc"
{sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;
case 1277:
#line 5366 "fgl.yacc"
{sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;
case 1278:
#line 5368 "fgl.yacc"
{sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;
case 1281:
#line 5378 "fgl.yacc"
{
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;
case 1282:
#line 5388 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1284:
#line 5393 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1286:
#line 5399 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1287:
#line 5402 "fgl.yacc"
{sprintf(yyval.str,"");}
    break;
case 1289:
#line 5406 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1291:
#line 5412 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1295:
#line 5421 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1298:
#line 5426 "fgl.yacc"
{
print_sql_commit(-1);
}
    break;
case 1299:
#line 5431 "fgl.yacc"
{
		print_sql_commit(1);
	}
    break;
case 1300:
#line 5438 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1301:
#line 5439 "fgl.yacc"
{
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;
case 1302:
#line 5446 "fgl.yacc"
{
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;
case 1303:
#line 5458 "fgl.yacc"
{insql=1;}
    break;
case 1304:
#line 5458 "fgl.yacc"
{
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1305:
#line 5463 "fgl.yacc"
{printcomment("/*  schema */\n");
	print_exec_sql(yyvsp[0].str);

sprintf(yyval.str,"Schema");
}
    break;
case 1306:
#line 5468 "fgl.yacc"
{printcomment("/*  schema  2*/\n");

	print_exec_sql(yyvsp[0].str);

sprintf(yyval.str,"Schema Element");
}
    break;
case 1308:
#line 5475 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);
 }
    break;
case 1310:
#line 5480 "fgl.yacc"
{
sprintf(yyval.str,"Set Database");
}
    break;
case 1311:
#line 5483 "fgl.yacc"
{
int c;
printcomment("/*  delete 1 */\n");

print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"Delete where current...");
}
    break;
case 1312:
#line 5490 "fgl.yacc"
{
int c;
printcomment("/*  delete 2 */\n");

print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"Delete where ...");
}
    break;
case 1313:
#line 5497 "fgl.yacc"
{
sprintf(yyval.str,"Fetch");
printcomment("/*  fetch */\n");
}
    break;
case 1314:
#line 5501 "fgl.yacc"
{
int c;
printcomment("/*  insert */\n");

print_exec_sql_bound(yyvsp[0].str);


sprintf(yyval.str,"insert");

}
    break;
case 1316:
#line 5512 "fgl.yacc"
{
	print_do_select(yyvsp[0].str);
	sprintf(yyval.str,"select");
}
    break;
case 1317:
#line 5516 "fgl.yacc"
{
int c;
print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"update");
}
    break;
case 1318:
#line 5525 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1319:
#line 5528 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1320:
#line 5530 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1321:
#line 5535 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1324:
#line 5542 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1328:
#line 5549 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1329:
#line 5552 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1330:
#line 5554 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1332:
#line 5560 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1334:
#line 5566 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1337:
#line 5577 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1338:
#line 5580 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1339:
#line 5582 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1341:
#line 5588 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1342:
#line 5591 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1344:
#line 5598 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1345:
#line 5604 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1346:
#line 5609 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1349:
#line 5619 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1351:
#line 5625 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1352:
#line 5631 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1353:
#line 5633 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1355:
#line 5639 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1359:
#line 5652 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1360:
#line 5654 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);}
    break;
case 1361:
#line 5660 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1362:
#line 5663 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1364:
#line 5667 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1365:
#line 5669 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1366:
#line 5674 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1367:
#line 5676 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1369:
#line 5679 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1370:
#line 5685 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1371:
#line 5690 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);}
    break;
case 1374:
#line 5700 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1378:
#line 5718 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1379:
#line 5724 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1382:
#line 5734 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1383:
#line 5739 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1385:
#line 5745 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1386:
#line 5749 "fgl.yacc"
{sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;
case 1387:
#line 5750 "fgl.yacc"
{sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1388:
#line 5751 "fgl.yacc"
{sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;
case 1390:
#line 5755 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1392:
#line 5760 "fgl.yacc"
{ sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;
case 1393:
#line 5768 "fgl.yacc"
{
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1394:
#line 5775 "fgl.yacc"
{sprintf(yyval.str,"");}
    break;
case 1396:
#line 5779 "fgl.yacc"
{sprintf(yyval.str,"");}
    break;
case 1398:
#line 5783 "fgl.yacc"
{sprintf(yyval.str,"");}
    break;
case 1401:
#line 5791 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1403:
#line 5797 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1405:
#line 5803 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1407:
#line 5809 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1408:
#line 5814 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1409:
#line 5815 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1410:
#line 5821 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1411:
#line 5823 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1412:
#line 5827 "fgl.yacc"
{strcpy(yyval.str," ALL ");}
    break;
case 1418:
#line 5846 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1421:
#line 5860 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1422:
#line 5862 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1423:
#line 5864 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1424:
#line 5866 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1426:
#line 5873 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1427:
#line 5876 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1429:
#line 5883 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1430:
#line 5885 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1431:
#line 5887 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1432:
#line 5889 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1433:
#line 5891 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1434:
#line 5893 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1443:
#line 5906 "fgl.yacc"
{sprintf(yyval.str,"<=");}
    break;
case 1444:
#line 5907 "fgl.yacc"
{sprintf(yyval.str,">=");}
    break;
case 1449:
#line 5917 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1453:
#line 5926 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);}
    break;
case 1454:
#line 5931 "fgl.yacc"
{sprintf(yyval.str," *?* ");}
    break;
case 1461:
#line 5948 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1462:
#line 5953 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1465:
#line 5957 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1469:
#line 5962 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1471:
#line 5965 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1473:
#line 5968 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1477:
#line 5973 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1478:
#line 5975 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1479:
#line 5978 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1481:
#line 5984 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1485:
#line 5989 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1489:
#line 6005 "fgl.yacc"
{
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;
case 1490:
#line 6009 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);
addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 1491:
#line 6012 "fgl.yacc"
{ sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;
case 1492:
#line 6013 "fgl.yacc"
{ sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;
case 1495:
#line 6024 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);}
    break;
case 1496:
#line 6028 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1497:
#line 6029 "fgl.yacc"
{sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;
case 1498:
#line 6030 "fgl.yacc"
{sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;
case 1499:
#line 6034 "fgl.yacc"
{ 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename); 
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1500:
#line 6039 "fgl.yacc"
{
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;
case 1501:
#line 6044 "fgl.yacc"
{
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;
case 1503:
#line 6057 "fgl.yacc"
{sprintf(yyval.str,convstrsql(yyvsp[0].str));}
    break;
case 1507:
#line 6062 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1508:
#line 6064 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1509:
#line 6066 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1510:
#line 6068 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1512:
#line 6073 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1513:
#line 6076 "fgl.yacc"
{sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1514:
#line 6079 "fgl.yacc"
{strcpy(yyval.str," YEAR TO SECOND ");}
    break;
case 1515:
#line 6081 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1516:
#line 6084 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1517:
#line 6086 "fgl.yacc"
{sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1518:
#line 6089 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1519:
#line 6089 "fgl.yacc"
{strcpy(yyval.str,"5");}
    break;
case 1520:
#line 6089 "fgl.yacc"
{strcpy(yyval.str,"8");}
    break;
case 1521:
#line 6089 "fgl.yacc"
{strcpy(yyval.str,"11");}
    break;
case 1522:
#line 6089 "fgl.yacc"
{strcpy(yyval.str,"14");}
    break;
case 1523:
#line 6089 "fgl.yacc"
{strcpy(yyval.str,"17");}
    break;
case 1524:
#line 6089 "fgl.yacc"
{strcpy(yyval.str,"23");}
    break;
case 1525:
#line 6090 "fgl.yacc"
{strcpy(yyval.str,"4");}
    break;
case 1526:
#line 6090 "fgl.yacc"
{strcpy(yyval.str,"7");}
    break;
case 1527:
#line 6090 "fgl.yacc"
{strcpy(yyval.str,"10");}
    break;
case 1528:
#line 6090 "fgl.yacc"
{strcpy(yyval.str,"13");}
    break;
case 1529:
#line 6090 "fgl.yacc"
{strcpy(yyval.str,"16");}
    break;
case 1530:
#line 6090 "fgl.yacc"
{strcpy(yyval.str,"19");}
    break;
case 1531:
#line 6090 "fgl.yacc"
{strcpy(yyval.str,"25");}
    break;
case 1546:
#line 6096 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1547:
#line 6097 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1548:
#line 6101 "fgl.yacc"
{
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;
case 1549:
#line 6110 "fgl.yacc"
{insql=0;chk4var=0;}
    break;
case 1550:
#line 6110 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-5].str,0,0);
addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-7].str);
}
    break;
case 1551:
#line 6115 "fgl.yacc"
{insql=0;chk4var=0;}
    break;
case 1552:
#line 6115 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,2,0); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;
case 1553:
#line 6121 "fgl.yacc"
{insql=0;chk4var=0;}
    break;
case 1554:
#line 6122 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-4].str,0,1); 
addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-6].str);
}
    break;
case 1555:
#line 6127 "fgl.yacc"
{insql=0;chk4var=0;}
    break;
case 1556:
#line 6128 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,0,1); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;
case 1557:
#line 6137 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1558:
#line 6138 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 1559:
#line 6139 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 1563:
#line 6146 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1564:
#line 6147 "fgl.yacc"
{sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1566:
#line 6153 "fgl.yacc"
{ 
		strcpy(yyval.str,print_curr_spec(1,yyvsp[0].str));
	}
    break;
case 1567:
#line 6159 "fgl.yacc"
{
		strcpy(yyval.str,print_curr_spec(2,yyvsp[0].str));
}
    break;
case 1569:
#line 6168 "fgl.yacc"
{
	sprintf(yyval.str,"%s",yyvsp[-1].str);
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}

	}
    break;
case 1570:
#line 6178 "fgl.yacc"
{debug("Got select list...\n");}
    break;
case 1571:
#line 6180 "fgl.yacc"
{start_bind('i',0,-1);printcomment("/* startbind */");}
    break;
case 1572:
#line 6182 "fgl.yacc"
{
             char buff[1024];
             sprintf(buff,"%s %s %s %s %s %s", yyvsp[-7].str, yyvsp[-6].str, yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str,yyvsp[0].str);
	    strcpy(yyval.str,print_select_all(buff));

}
    break;
case 1573:
#line 6192 "fgl.yacc"
{
             char buff[1024];
             int ni,no;
             sprintf(buff,"%s %s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
             sprintf(yyval.str,"push_char(\"%s\");",buff);
}
    break;
case 1576:
#line 6208 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s %s %s %s %s", yyvsp[-6].str, yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;
case 1577:
#line 6212 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1578:
#line 6213 "fgl.yacc"
{
       printcomment("/* UNION */");
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;
case 1580:
#line 6218 "fgl.yacc"
{
       sprintf(yyval.str,"%s %s %s ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1582:
#line 6226 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1583:
#line 6227 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1584:
#line 6230 "fgl.yacc"
{ start_bind('o',0);sprintf(yyval.str,""); }
    break;
case 1585:
#line 6231 "fgl.yacc"
{ sprintf(yyval.str,""); }
    break;
case 1586:
#line 6235 "fgl.yacc"
{sprintf(yyval.str,"{%s}",yyvsp[0].str);}
    break;
case 1587:
#line 6236 "fgl.yacc"
{sprintf(yyval.str,"[%s,%s]\n",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1588:
#line 6242 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1589:
#line 6247 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str);}
    break;
case 1590:
#line 6250 "fgl.yacc"
{sprintf(yyval.str,"");}
    break;
case 1591:
#line 6251 "fgl.yacc"
{sprintf(yyval.str,"ALL");}
    break;
case 1592:
#line 6252 "fgl.yacc"
{sprintf(yyval.str,"DISTINCT");}
    break;
case 1593:
#line 6253 "fgl.yacc"
{sprintf(yyval.str,"DISTINCT");}
    break;
case 1595:
#line 6258 "fgl.yacc"
{ sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1597:
#line 6262 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1599:
#line 6272 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1600:
#line 6274 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1601:
#line 6276 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1602:
#line 6278 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1603:
#line 6280 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1609:
#line 6286 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1610:
#line 6288 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1611:
#line 6290 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1612:
#line 6292 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1613:
#line 6294 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1614:
#line 6296 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1615:
#line 6298 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1616:
#line 6300 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1617:
#line 6302 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1618:
#line 6303 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1623:
#line 6313 "fgl.yacc"
{

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;
case 1624:
#line 6321 "fgl.yacc"
{
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;
case 1625:
#line 6326 "fgl.yacc"
{strcpy(yyval.str,"\"|\"");}
    break;
case 1626:
#line 6326 "fgl.yacc"
{
strcpy(yyval.str,yyvsp[0].str);
}
    break;
case 1628:
#line 6330 "fgl.yacc"
{
if ((scan_variable(yyvsp[0].str)&15)!=0) {yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;
case 1629:
#line 6335 "fgl.yacc"
{sprintf(yyval.str,"0");}
    break;
case 1630:
#line 6335 "fgl.yacc"
{
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;
case 1632:
#line 6339 "fgl.yacc"
{
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1633:
#line 6343 "fgl.yacc"
{
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;
case 1636:
#line 6352 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1637:
#line 6352 "fgl.yacc"
{
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;
case 1641:
#line 6367 "fgl.yacc"
{ sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1642:
#line 6376 "fgl.yacc"
{
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1643:
#line 6384 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1647:
#line 6394 "fgl.yacc"
{ sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;
case 1648:
#line 6395 "fgl.yacc"
{ sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;
case 1651:
#line 6403 "fgl.yacc"
{
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;
case 1652:
#line 6409 "fgl.yacc"
{
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;
case 1655:
#line 6428 "fgl.yacc"
{sprintf(yyval.str,"UNITS YEAR");}
    break;
case 1656:
#line 6429 "fgl.yacc"
{sprintf(yyval.str,"UNITS MONTH"); }
    break;
case 1657:
#line 6430 "fgl.yacc"
{sprintf(yyval.str,"UNITS DAY);"); }
    break;
case 1658:
#line 6431 "fgl.yacc"
{sprintf(yyval.str,"UNITS HOUR);"); }
    break;
case 1659:
#line 6432 "fgl.yacc"
{sprintf(yyval.str,"UNITS MINUTE);"); }
    break;
case 1660:
#line 6433 "fgl.yacc"
{sprintf(yyval.str,"UNITS SECOND);"); }
    break;
case 1663:
#line 6444 "fgl.yacc"
{list_print_all();}
    break;
case 1666:
#line 6452 "fgl.yacc"
{ 
	printf("Copy %s to %s",yyvsp[0].str,yyvsp[-2].str);
list_copy(yyvsp[0].str,yyvsp[-2].str); 
}
    break;
case 1667:
#line 6456 "fgl.yacc"
{ list_copy(yyvsp[-2].str,yyvsp[-4].str); }
    break;
case 1668:
#line 6457 "fgl.yacc"
{list_copy(yyvsp[0].str,"_database");}
    break;
case 1669:
#line 6461 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_prompt_single(a,yyvsp[0].str);}
    break;
case 1670:
#line 6463 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_prompt_many(a,yyvsp[0].str);}
    break;
case 1671:
#line 6465 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_prompt_many(a,yyvsp[0].str);}
    break;
case 1672:
#line 6467 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_set_single(a,yyvsp[0].str);}
    break;
case 1673:
#line 6469 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_set_single(a,yyvsp[0].str);}
    break;
case 1674:
#line 6474 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_columns(a,yyvsp[0].str);}
    break;
case 1677:
#line 6478 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_set_plus(a,yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1678:
#line 6480 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_set_minus(a,yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1679:
#line 6482 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_in(a,yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1680:
#line 6484 "fgl.yacc"
{
			strcpy(yyval.str,yyvsp[-1].str);
	}
    break;
case 1681:
#line 6487 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_append(a,yyvsp[0].str,yyvsp[-2].str);}
    break;
case 1682:
#line 6490 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_append(a,yyvsp[0].str,yyvsp[-2].str);}
    break;
case 1683:
#line 6492 "fgl.yacc"
{
		char *a; a=(char *)new_id(); strcpy(yyval.str,a); list_append(yyvsp[-4].str,yyvsp[0].str,yyvsp[-2].str,a);}
    break;
case 1684:
#line 6498 "fgl.yacc"
{
if (scan_variable(yyvsp[0].str)!=-1)
{
print_push_variable(yyvsp[0].str);
strcpy(yyval.str,"?");
}
fflush(stdout);
}
    break;
case 1685:
#line 6510 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1689:
#line 6516 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1690:
#line 6517 "fgl.yacc"
{sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1694:
#line 6526 "fgl.yacc"
{
if (scan_variable(yyvsp[0].str)!=-1&&(!system_var(yyvsp[0].str)))
{
int z,a;
a=get_bind_cnt('i');
z=add_bind('i',yyvsp[0].str,scan_variable(yyvsp[0].str));
z-=a;
strcpy(yyval.str,"");
for (a=0;a<z;a++)  {
if (a>0) {strcat(yyval.str,",");}
         strcat(yyval.str,"?");
}

}
fflush(stdout);
}
    break;
case 1695:
#line 6542 "fgl.yacc"
{
char r1[256];
char r2[256];
char buff[256];
char kp[40000];
char *ptr1;
char *ptr2;
int v1;
int v2;
int aa;
int z,a;

 
        strcpy(r1,yyvsp[-2].str);
        ptr1=strrchr(r1,'.');
        if (ptr1==0) {
                yyerror("Must have a . in a thru");YYERROR;
        }
        *ptr1=0;
        ptr1++;
 
        strcpy(r2,yyvsp[0].str);
        debug("r2=%s",r2);
 
        ptr2=strrchr(r2,'.');

        if (ptr2==0) {
                yyerror("Must have a . in a thru");YYERROR;
        }
        *ptr2=0;
 
        debug("Checking portions %s %s\n",r1,r2);
 
        if (strcmp(r1,r2)!=0) {
                yyerror("Records for thru look different...");YYERROR;
        }
 
        debug("Checking variables");
        v1=scan_variable(yyvsp[-2].str);

        if (v2==-1) {
                debug("Variable not found..");
                yyerror("Variable not found (first entry in thru)");YYERROR;
        }
        v1=last_var_found;
        debug("v1=%d",v1);
 
        v2=scan_variable(yyvsp[0].str);
        if (v2==-1) {
                debug("Variable not found..");
                yyerror("Variable not found (second entry in thru)");
        }
        v2=last_var_found;
        debug("v2=%d",v2);
 
        strcpy(yyval.str,"");
        for (aa=v1;aa<=v2;aa++) {
                strcpy(kp,yyval.str);
                sprintf(buff,"%s.%s",r1,get_var_name(aa));

		if (scan_variable(buff)!=-1&&(!system_var(buff))) {
			a=get_bind_cnt('i');
			z=add_bind('i',buff);
			z-=a;
        	}

		for (a=0;a<z;a++)  {
			if (strlen(yyval.str)) {strcat(yyval.str,",");}
         		strcat(yyval.str,"?");
		}

	}
}
    break;
case 1696:
#line 6620 "fgl.yacc"
{set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;
case 1697:
#line 6622 "fgl.yacc"
{set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;
case 1698:
#line 6624 "fgl.yacc"
{set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;
case 1699:
#line 6625 "fgl.yacc"
{
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;
case 1700:
#line 6630 "fgl.yacc"
{
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;
case 1701:
#line 6635 "fgl.yacc"
{set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;
case 1702:
#line 6637 "fgl.yacc"
{set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;
case 1703:
#line 6639 "fgl.yacc"
{set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;
case 1704:
#line 6641 "fgl.yacc"
{set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;
case 1705:
#line 6644 "fgl.yacc"
{
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;
case 1706:
#line 6648 "fgl.yacc"
{
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;
case 1707:
#line 6653 "fgl.yacc"
{
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;
case 1708:
#line 6658 "fgl.yacc"
{ set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;
case 1709:
#line 6662 "fgl.yacc"
{
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;
case 1711:
#line 6672 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 1713:
#line 6680 "fgl.yacc"
{
print_while_1();
push_blockcommand("WHILE");
}
    break;
case 1714:
#line 6683 "fgl.yacc"
{
print_while_2();
}
    break;
case 1715:
#line 6687 "fgl.yacc"
{
print_while_3();
pop_blockcommand("WHILE");
}
    break;
case 1718:
#line 6698 "fgl.yacc"
{
strcpy(yyval.str,"0");
}
    break;
case 1719:
#line 6701 "fgl.yacc"
{
strcpy(yyval.str,"1"); 
}
    break;
case 1720:
#line 6707 "fgl.yacc"
{ 
print_clr_window("\"screen\"");
}
    break;
case 1721:
#line 6710 "fgl.yacc"
{ print_clr_window(yyvsp[0].str); }
    break;
case 1722:
#line 6711 "fgl.yacc"
{ print_clr_window(yyvsp[0].str); }
    break;
case 1723:
#line 6712 "fgl.yacc"
{
	print_clr_form(0,0,yyvsp[0].str);
}
    break;
case 1724:
#line 6715 "fgl.yacc"
{
	print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1725:
#line 6718 "fgl.yacc"
{
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1726:
#line 6723 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 1727:
#line 6724 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1728:
#line 6728 "fgl.yacc"
{
	print_current_window("\"screen\"");
}
    break;
case 1729:
#line 6732 "fgl.yacc"
{
	print_current_window(yyvsp[0].str);
}
    break;
case 1730:
#line 6736 "fgl.yacc"
{
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;
case 1731:
#line 6740 "fgl.yacc"
{
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;
case 1732:
#line 6745 "fgl.yacc"
{
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;
case 1733:
#line 6749 "fgl.yacc"
{
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;
case 1734:
#line 6754 "fgl.yacc"
{

print_def_mn_file();

}
    break;
case 1736:
#line 6762 "fgl.yacc"
{addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;
case 1738:
#line 6768 "fgl.yacc"
{
	print_hide_window(yyvsp[0].str);
}
    break;
case 1739:
#line 6774 "fgl.yacc"
{
print_move_window(yyvsp[-4].str,0);
}
    break;
case 1740:
#line 6778 "fgl.yacc"
{
print_move_window(yyvsp[-4].str,1);
}
    break;
case 1746:
#line 6787 "fgl.yacc"
{
chk4var=0;printcomment("/* [Comm:%s] */\n",yyval.str); 
if (acl_getenv("INCLINES"))
printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;
case 1747:
#line 6794 "fgl.yacc"
{
printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;   
if (acl_getenv("INCLINES"))
printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;
}

#line 727 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
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
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 6884 "fgl.yacc"

/* programmer routines */
//# include "lex.yy.c"
//# include "lexify.c"

set_clobber(char *c) {
strcpy(clobber,c);
}

char *get_hdrdbname() {
	return hdr_dbname;
}

set_hdrdbname(char *s){
	strcpy(hdr_dbname,s);
}
set_str(char *s) {
strcpy(yylval.str,s);
}


