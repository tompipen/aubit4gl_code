/* A Bison parser, made from fgl.yacc
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	NAME	257
# define	UMINUS	258
# define	COMMA	1541
# define	OR	1581
# define	AND	1536
# define	USING	1470
# define	MATCHES	1350
# define	POWER	1457
# define	LESS_THAN	1453
# define	GREATER_THAN	1368
# define	EQUAL	1531
# define	GREATER_THAN_EQ	1268
# define	LESS_THAN_EQ	1325
# define	NOT_EQUAL	1399
# define	MINUS	1554
# define	PLUS	1567
# define	DIVIDE	1485
# define	MULTIPLY	1458
# define	MOD	1555
# define	COMMAND	1332
# define	NUMBER_VALUE	259
# define	CHAR_VALUE	260
# define	INT_VALUE	261
# define	NAMED_GEN	262
# define	CLINE	263
# define	SQLLINE	264
# define	KW_CSTART	265
# define	KW_CEND	266
# define	LOCAL_FUNCTION	1000
# define	EVERY_ROW	1001
# define	DOUBLE_PRECISION	1002
# define	COUNT_MULTIPLY	1003
# define	NEWFORMATSHARED	1004
# define	WAIT_FOR_KEY	1005
# define	AT_TERMINATION_CALL	1006
# define	TO_MAIN_CAPTION	1007
# define	CLEARSTAT	1008
# define	TO_MENUITEM	1009
# define	ID_TO_INT	1010
# define	TO_STATUSBOX	1011
# define	ASCII_HEIGHT_ALL	1012
# define	ASCII_WIDTH_ALL	1013
# define	IMPORT_DATATYPE	1014
# define	UP_BY	1015
# define	PAGE_TRAILER_SIZE	1016
# define	PAGE_HEADER_SIZE	1017
# define	FIRST_PAGE_HEADER_SIZE	1018
# define	BYTES_USE_AS_IMAGE	1019
# define	BYTES_USE_AS_ASCII	1020
# define	DOWN_BY	1021
# define	CLOSE_STATUSBOX	1022
# define	ADD_CONSTRAINT	1023
# define	DROP_CONSTRAINT	1024
# define	MODIFY_NEXT_SIZE	1025
# define	LOCK_MODE_PAGE	1026
# define	LOCK_MODE_ROW	1027
# define	TO_PIPE	1028
# define	TO_PRINTER	1029
# define	STATUSBOX	1030
# define	CONNECT_TO	1031
# define	FORMHANDLER_INPUT	1032
# define	UNITS_YEAR	1033
# define	UNITS_MONTH	1034
# define	UNITS_DAY	1035
# define	UNITS_HOUR	1036
# define	UNITS_MINUTE	1037
# define	UNITS_SECOND	1038
# define	NO_NEW_LINES	1039
# define	FIELDTOWIDGET	1040
# define	WITH_HOLD	1041
# define	SHOW_MENU	1042
# define	CWIS	1043
# define	CREATE_IDX	1044
# define	FORM_IS_COMPILED	1045
# define	PDF_REPORT	1046
# define	IMPORT_FUNCTION	1047
# define	PROMPT_MANY	1048
# define	POINTS	1049
# define	MM	1050
# define	INCHES	1051
# define	PREPEND	1052
# define	MEMBER_OF	1053
# define	MEMBER_FUNCTION	1054
# define	APPEND	1055
# define	TEMPLATE	1056
# define	END_TEMPLATE	1057
# define	SQLSICS	1058
# define	CREATE_SCHEMA	1059
# define	SQLSIRR	1060
# define	UPDATESTATS_T	1061
# define	SQLSICR	1062
# define	WHENEVER_SQLSUCCESS	1063
# define	WHENEVER_SQLWARNING	1064
# define	START_EXTERN	1065
# define	WHENEVER_ANY_ERROR	1066
# define	WHENEVER_NOT_FOUND	1067
# define	CONTINUE_CONSTRUCT	1068
# define	FOUNCONSTR	1069
# define	SQLSIDR	1070
# define	WHENEVER_SQLERROR	1071
# define	CREATE_TEMP_TABLE	1072
# define	CURRENT_WINDOW_IS	1073
# define	FIRST_PAGE_HEADER	1074
# define	ORDER_EXTERNAL_BY	1075
# define	SCROLL_CURSOR_FOR	1076
# define	SCROLL_CURSOR	1077
# define	SQL_INTERRUPT_OFF	1078
# define	STOP_ALL_EXTERNAL	1079
# define	WITH_CHECK_OPTION	1080
# define	WITH_GRANT_OPTION	1081
# define	SQLSLMNW	1082
# define	ADDCONSTUNIQ	1083
# define	CONTINUE_DISPLAY	1084
# define	CONTINUE_FOREACH	1085
# define	OUTPUT_TO_REPORT	1086
# define	SQL_INTERRUPT_ON	1087
# define	WHENEVER_SUCCESS	1088
# define	WHENEVER_WARNING	1089
# define	WHERE_CURRENT_OF	1090
# define	WITHOUT_DEFAULTS	1091
# define	FOCONSTR	1092
# define	SCALED_BY	1093
# define	CONTINUE_PROMPT	1094
# define	PDF_FUNCTION	1095
# define	DEFER_INTERRUPT	1096
# define	DISPLAY_BY_NAME	1097
# define	NOT_NULL_UNIQUE	1098
# define	SKIP_TO_TOP	1099
# define	TOP_OF_PAGE	1100
# define	SKIP_TO	1101
# define	SKIP_BY	1102
# define	WITHOUT_WAITING	1103
# define	BEFCONSTRUCT	1104
# define	SQLSLMW	1105
# define	WHENEVER_ERROR_CONTINUE	1106
# define	WHENEVER_ERROR	1107
# define	AFTCONSTRUCT	1108
# define	ALL_PRIVILEGES	1109
# define	CLOSE_DATABASE	1110
# define	CONTINUE_INPUT	1111
# define	CONTINUE_WHILE	1112
# define	CREATE_SYNONYM	1113
# define	DROP_TABLE	1114
# define	EXIT_CONSTRUCT	1115
# define	INEXCLUSIVE	1116
# define	REPORT_TO_PRINTER	1117
# define	REPORT_TO_PIPE	1118
# define	SET_SESSION_TO	1119
# define	UPDATESTATS	1120
# define	WITHOUT_HEAD	1121
# define	CLEARSCR	1122
# define	WITH_B_LOG	1123
# define	AUTHORIZATION	1124
# define	BOTTOM_MARGIN	1125
# define	CLOSE_SESSION	1126
# define	CONTINUE_CASE	1127
# define	CONTINUE_MENU	1128
# define	DISPLAY_ARRAY	1129
# define	END_CONSTRUCT	1130
# define	FIELD_TOUCHED	1131
# define	FINISH_REPORT	1132
# define	INFACC	1133
# define	INPUT_NO_WRAP	1134
# define	LOCKMODEPAGE	1135
# define	SETPMOFF	1136
# define	UNCONSTRAINED	1137
# define	PAGE_TRAILER	1138
# define	SETPMON	1139
# define	BEFGROUP	1140
# define	CLOSE_WINDOW	1141
# define	COMMENT_LINE	1142
# define	CONTINUE_FOR	1143
# define	CREATE_DB	1144
# define	CREATE_TABLE	1145
# define	DEFAULT_NULL	1146
# define	DELETE_USING	1147
# define	DISPLAY_FORM	1148
# define	END_FUNCTION	1149
# define	EXIT_DISPLAY	1150
# define	EXIT_FOREACH	1151
# define	EXIT_PROGRAM	1152
# define	INFCOLS	1153
# define	LOCKMODEROW	1154
# define	ON_EVERY_ROW	1155
# define	OPEN_SESSION	1156
# define	RIGHT_MARGIN	1157
# define	SELECT_USING	1158
# define	START_REPORT	1159
# define	UNLOCK_TABLE	1160
# define	UPDATE_USING	1161
# define	ACL_BUILTIN	1162
# define	AFTGROUP	1163
# define	INFIDX	1164
# define	INFSTAT	1165
# define	LEFT_MARGIN	1166
# define	PAGE_HEADER	1167
# define	ROLLBACK_W	1168
# define	SET_SESSION	1169
# define	SQLSEOFF	1170
# define	WITH_A_LOG	1171
# define	ALTER_TABLE	1172
# define	BEFDISP	1173
# define	BEFORE_MENU	1174
# define	CREATE_VIEW	1175
# define	DEFINE_TYPE	1176
# define	DELETE_FROM	1177
# define	END_DISPLAY	1178
# define	END_REPORT	1179
# define	END_FOREACH	1180
# define	END_FOR	1181
# define	END_GLOBALS	1182
# define	EXIT_PROMPT	1183
# define	EXTENT_SIZE	1184
# define	FOREIGN_KEY	1185
# define	HIDE_OPTION	1186
# define	HIDE_WINDOW	1187
# define	INSERT_INTO	1188
# define	IS_NOT_NULL	1189
# define	MOVE_WINDOW	1190
# define	NEXT_OPTION	1191
# define	NOT_MATCHES	1192
# define	ON_LAST_ROW	1193
# define	OPEN_WINDOW	1194
# define	OPEN_STATUSBOX	1195
# define	PAGE_LENGTH	1196
# define	PAGE_WIDTH	1197
# define	PRIMARY_KEY	1198
# define	PROMPT_LINE	1199
# define	RECORD_LIKE	1200
# define	ROLLFORWARD	1201
# define	SETBL	1202
# define	SHOW_OPTION	1203
# define	SHOW_WINDOW	1204
# define	SQLSEON	1205
# define	TO_DATABASE	1206
# define	USE_SESSION	1207
# define	WITH_NO_LOG	1208
# define	AFTDISP	1209
# define	BEFFIELD	1210
# define	INSHARE	1211
# define	UNLOCKTAB	1212
# define	AFTFIELD	1213
# define	ATTRIBUTES	1214
# define	BEFINP	1215
# define	BEGIN_WORK	1216
# define	CLEARWIN	1217
# define	CLOSE_FORM	1218
# define	DEFER_QUIT	1219
# define	DESCENDING	1220
# define	DROP_INDEX	1221
# define	END_PROMPT	1222
# define	END_RECORD	1223
# define	ERROR_LINE	1224
# define	EXIT_INPUT	1225
# define	EXIT_WHILE	1226
# define	FOR_UPDATE_OF	1227
# define	FOR_UPDATE	1228
# define	GET_FLDBUF	1229
# define	INITIALIZE	1230
# define	INPUT_WRAP	1231
# define	LOCK_TABLE	1232
# define	MSG_LINE	1233
# define	NOT_EXISTS	1234
# define	ON_ANY_KEY	1235
# define	REFERENCES	1236
# define	RENCOL	1237
# define	SET_CURSOR	1238
# define	SMALLFLOAT	1239
# define	SQLSUCCESS	1240
# define	TOP_MARGIN	1241
# define	WITH_ARRAY	1242
# define	ACCEPTKEY	1243
# define	ACCEPT	1244
# define	AFTINP	1245
# define	CLEARFORM	1246
# define	COMMIT_W	1247
# define	NEXTPAGE	1248
# define	PREVPAGE	1249
# define	CTRL_KEY	1250
# define	INFTABS	1251
# define	NEXTFIELD	1252
# define	NEXTFORM	1253
# define	RENTAB	1254
# define	ASCENDING	1255
# define	ASSOCIATE	1256
# define	CHARACTER	1257
# define	CONSTRUCT	1258
# define	DELIMITER	1259
# define	DOWNSHIFT	1260
# define	DROP_VIEW	1261
# define	END_INPUT	1262
# define	END_WHILE	1263
# define	EXCLUSIVE	1264
# define	EXIT_CASE	1265
# define	EXIT_MENU	1266
# define	FORM_LINE	1267
# define	INTERRUPT	1269
# define	INTO_TEMP	1270
# define	INVISIBLE	1271
# define	IN_MEMORY	1272
# define	LINKED_TO	1273
# define	LOAD_FROM	1274
# define	LOCKTAB	1275
# define	MENU_LINE	1276
# define	OPEN_FORM	1277
# define	OTHERWISE	1278
# define	PRECISION	1279
# define	PROCEDURE	1280
# define	REPORT_TO	1281
# define	RETURNING	1282
# define	UNDERLINE	1283
# define	UNLOAD_TO	1284
# define	BEFROW	1285
# define	UNLOAD_T	1286
# define	VARIABLE	1287
# define	ABSOLUTE	1288
# define	AFTROW	1289
# define	BUFFERED	1290
# define	CONSTANT	1291
# define	CONST	1292
# define	CONTINUE	1293
# define	DATABASE	1294
# define	DATETIME	1295
# define	DEFAULTS	1296
# define	DISTINCT	1297
# define	END_CASE	1298
# define	END_MAIN	1299
# define	END_MENU	1300
# define	END_TYPE	1301
# define	EXIT_FOR	1302
# define	EXTERNAL	1303
# define	FRACTION	1304
# define	FUNCTION	1305
# define	GROUP_BY	1306
# define	INTERVAL	1307
# define	KWMESSAGE	1308
# define	NOT_LIKE	1309
# define	NOT_NULL	1310
# define	PASSWORD	1311
# define	PREVIOUS	1312
# define	READONLY	1313
# define	REGISTER	1314
# define	RELATIVE	1315
# define	RESOURCE	1316
# define	SMALLINT	1317
# define	VALIDATE	1318
# define	WHENEVER	1319
# define	WITH_LOG	1320
# define	WORDWRAP	1321
# define	BY_NAME	1322
# define	IN_FILE	1323
# define	IS_NULL	1324
# define	AVERAGE	1326
# define	BETWEEN	1327
# define	CAPTION	1328
# define	CLIPPED	1329
# define	CLOSE_BRACKET	1330
# define	COLUMNS	1331
# define	COMMENT	1333
# define	CONNECT	1334
# define	CURRENT	1335
# define	DBYNAME	1336
# define	DECIMAL	1337
# define	DECLARE	1338
# define	DEFAULT	1339
# define	DISPLAY	1340
# define	ENDCODE	1341
# define	EXECUTE	1342
# define	FOREACH	1343
# define	FOREIGN	1344
# define	GLOBALS	1345
# define	INFIELD	1346
# define	INTEGER	1347
# define	KWWINDOW	1348
# define	MAGENTA	1349
# define	NUMERIC	1351
# define	OPTIONS	1352
# define	PERCENT	1353
# define	PREPARE	1354
# define	PROGRAM	1355
# define	RECOVER	1356
# define	REVERSE	1357
# define	SECTION	1358
# define	SESSION	1359
# define	SYNONYM	1360
# define	THRU	1361
# define	TRAILER	1362
# define	UPSHIFT	1363
# define	VARCHAR	1364
# define	WAITING	1365
# define	CLOSE_SHEV	1366
# define	CLOSE_SQUARE	1367
# define	KW_FALSE	1369
# define	NOT_IN	1370
# define	ONKEY	1371
# define	OPEN_BRACKET	1372
# define	BORDER	1373
# define	BOTTOM	1374
# define	COLUMN	1375
# define	COMMIT	1376
# define	CREATE	1377
# define	CURSOR	1378
# define	DEFINE	1379
# define	DELETE	1380
# define	DOUBLE	1381
# define	END_IF	1382
# define	ESCAPE	1383
# define	EXISTS	1384
# define	EXTEND	1385
# define	EXTENT	1386
# define	FINISH	1387
# define	FORMAT	1388
# define	HAVING	1389
# define	HEADER	1390
# define	INSERT	1391
# define	LOCATE	1392
# define	MARGIN	1393
# define	MEMORY	1394
# define	MINUTE	1395
# define	MODIFY	1396
# define	NORMAL	1397
# define	EQUAL_EQUAL	1398
# define	OPEN_SHEV	1400
# define	OPEN_SQUARE	1401
# define	OPTION	1402
# define	OUTPUT	1403
# define	PROMPT	1404
# define	PUBLIC	1405
# define	RECORD	1406
# define	REPORT	1407
# define	RETURN	1408
# define	REVOKE	1409
# define	SCHEMA	1410
# define	SCROLL	1411
# define	SECOND	1412
# define	SELECT	1413
# define	SERIAL	1414
# define	SETL	1415
# define	SHARED	1416
# define	SPACES	1417
# define	UNIQUE	1418
# define	UNLOCK	1419
# define	UPDATE	1420
# define	VALUES	1421
# define	YELLOW	1422
# define	AFTER	1423
# define	KWLINE	1424
# define	KW_NULL	1425
# define	KW_TRUE	1426
# define	SINGLE_KEY	1427
# define	ALTER	1428
# define	ARRAY	1429
# define	ASCII	1430
# define	AUDIT	1431
# define	BLACK	1432
# define	BLINK	1433
# define	CHECK	1434
# define	CLEAR	1435
# define	CLOSE	1436
# define	CODE_C	1437
# define	COUNT	1438
# define	DEFER	1439
# define	ERROR	1440
# define	EVERY	1441
# define	FETCH	1442
# define	FIRST	1443
# define	FLOAT	1444
# define	FLUSH	1445
# define	FOUND	1446
# define	GRANT	1447
# define	GREEN	1448
# define	GROUP	1449
# define	INDEX	1450
# define	KWFORM	1451
# define	LABEL	1452
# define	LOCAL	1454
# define	MONEY	1455
# define	MONTH	1456
# define	ORDER	1459
# define	OUTER	1460
# define	PAUSE	1461
# define	PRINT_IMAGE	1462
# define	PRINT_FILE	1463
# define	PRINT	1464
# define	RIGHT	1465
# define	SEMICOLON	1466
# define	SLEEP	1467
# define	TUPLE	1468
# define	UNION	1469
# define	WHERE	1471
# define	WHILE	1472
# define	WHITE	1473
# define	CCODE	1474
# define	ANSI	1475
# define	BLUE	1476
# define	BOLD	1477
# define	BYTE	1478
# define	FCALL	1479
# define	CASE	1480
# define	CHAR	1481
# define	CYAN	1482
# define	DATE	1483
# define	DESC	1484
# define	DOWN	1486
# define	TAB	1487
# define	DROP	1488
# define	ELSE	1489
# define	EXEC	1490
# define	EXIT	1491
# define	FREE	1492
# define	FROM	1493
# define	GOTO	1494
# define	HELP_FILE	1495
# define	LANG_FILE	1496
# define	HELP	1497
# define	HIDE	1498
# define	HOUR	1499
# define	INTO	1500
# define	LAST	1501
# define	LEFT	1502
# define	LIKE	1503
# define	MAIN	1504
# define	MENU	1505
# define	MODE	1506
# define	MOVE	1507
# define	NEED	1508
# define	NEXT	1509
# define	NOCR	1510
# define	OPEN	1511
# define	QUIT	1512
# define	REAL	1513
# define	ROWS	1514
# define	SHOW	1515
# define	SIZE	1516
# define	SKIP	1517
# define	SOME	1518
# define	STEP	1519
# define	STOP	1520
# define	TEMP	1521
# define	TEXT	1522
# define	THEN	1523
# define	USER	1524
# define	VIEW	1525
# define	WAIT	1526
# define	WHEN	1527
# define	WITH	1528
# define	WORK	1529
# define	YEAR	1530
# define	KW_IS	1532
# define	XSET	1533
# define	ADD	1534
# define	ALL	1535
# define	ANY	1537
# define	ASC	1538
# define	AVG	1539
# define	COLON	1540
# define	DAY	1542
# define	DBA	1543
# define	DEC	1544
# define	DIM	1545
# define	FKEY	1546
# define	FOR	1547
# define	KEY	1548
# define	KWNO	1549
# define	LET	1550
# define	LOG	1551
# define	XMAX	1552
# define	XMIN	1553
# define	NOT	1556
# define	PAD	1557
# define	PUT	1558
# define	RED	1559
# define	ROW	1560
# define	RUN	1561
# define	SQL	1562
# define	SUM	1563
# define	TOP	1564
# define	USE	1565
# define	ATSIGN	1566
# define	AS_TIFF	1568
# define	AS_GIF	1569
# define	AS_PNG	1570
# define	AS_JPEG	1571
# define	AS	1572
# define	AT	1573
# define	BY	1574
# define	DOT	1575
# define	GO	1576
# define	IF	1577
# define	IN	1578
# define	OF	1579
# define	ON	1580
# define	TO	1582
# define	UP	1583
# define	FONT_NAME	1584
# define	FONT_SIZE	1585
# define	PAPER_SIZE_IS_LETTER	1586
# define	PAPER_SIZE_IS_LEGAL	1587
# define	PAPER_SIZE_IS_A5	1588
# define	PAPER_SIZE_IS_A4	1589
# define	PAPER_SIZE_IS_LETTER_L	1590
# define	PAPER_SIZE_IS_LEGAL_L	1591
# define	PAPER_SIZE_IS_A5_L	1592
# define	PAPER_SIZE_IS_A4_L	1593
# define	FORMHANDLER	1594
# define	END_FORMHANDLER	1595
# define	BEFORE_EVENT	1596
# define	BEFORE_OPEN_FORM	1597
# define	AFTER_EVENT	1598
# define	BEFORE_CLOSE_FORM	1599
# define	BEFORE_ANY	1600
# define	AFTER_ANY	1601
# define	MENUHANDLER	1602
# define	END_MENUHANDLER	1603
# define	BEFORE_SHOW_MENU	1604
# define	DISABLE_PROGRAM	1605
# define	DISABLE_ALL	1606
# define	BUTTONS	1607
# define	CHECK_MENUITEM	1608
# define	DISABLE_FORM	1609
# define	DISABLE_MENUITEMS	1610
# define	DISABLE	1611
# define	ENABLE_FORM	1612
# define	ENABLE_MENUITEMS	1613
# define	ENABLE	1614
# define	KWFIELD	1615
# define	ICON	1616
# define	MESSAGEBOX	1617
# define	TO_DEFAULTS	1618
# define	UNCHECK_MENUITEM	1619
# define	BEFORE	1620
# define	INPUT	1621
# define	END	1622
# define	INT_TO_ID	1623

#line 66 "fgl.yacc"


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

//#define YYPURE 1
//#define YYLEX_PARAM yystate

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

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/



#line 174 "fgl.yacc"
#ifndef YYSTYPE
typedef union	  {



	char	str[3100];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;

	} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		2916
#define	YYFLAG		-32768
#define	YYNTBASE	637

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 1623 ? yytranslate[x] : 1413)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const short yytranslate[] =
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,    23,
      24,    25,    26,    27,    28,    29,    30,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    14,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,    15,   355,   356,   357,   358,
     359,   360,    22,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
       9,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,    12,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,    16,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,    11,   478,   479,   480,    10,    20,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       8,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,    19,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,    13,   551,   552,   553,   554,     7,   555,   556,   557,
     558,     5,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,    17,    21,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,    18,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,     6,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     4,    10,    12,    14,    16,    18,    22,
      24,    28,    32,    34,    37,    39,    41,    43,    45,    47,
      49,    51,    53,    54,    56,    57,    63,    70,    72,    76,
      78,    80,    82,    84,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   104,   106,   108,   109,   111,   112,   118,
     120,   124,   126,   128,   131,   134,   137,   140,   143,   146,
     149,   152,   156,   157,   165,   170,   177,   179,   186,   187,
     188,   198,   199,   200,   201,   210,   211,   212,   223,   224,
     225,   233,   234,   235,   236,   251,   252,   255,   256,   259,
     261,   262,   264,   266,   270,   272,   274,   276,   278,   282,
     283,   290,   291,   297,   299,   302,   304,   307,   309,   310,
     311,   315,   316,   317,   321,   322,   327,   328,   333,   336,
     339,   342,   344,   347,   350,   354,   356,   358,   360,   363,
     365,   367,   370,   372,   374,   375,   376,   382,   390,   399,
     400,   403,   405,   409,   411,   415,   419,   421,   424,   425,
     430,   431,   436,   437,   441,   442,   446,   447,   451,   453,
     457,   459,   463,   465,   467,   469,   471,   473,   475,   477,
     479,   480,   482,   484,   487,   488,   492,   494,   496,   498,
     502,   503,   506,   511,   516,   521,   524,   525,   530,   532,
     534,   536,   539,   541,   543,   547,   548,   550,   551,   559,
     560,   573,   575,   577,   579,   581,   583,   589,   593,   595,
     597,   598,   603,   604,   610,   611,   619,   621,   625,   627,
     629,   630,   633,   635,   637,   639,   644,   649,   656,   658,
     661,   663,   665,   667,   669,   674,   681,   683,   688,   695,
     697,   699,   701,   703,   705,   707,   709,   712,   715,   717,
     719,   724,   726,   728,   729,   733,   737,   738,   741,   743,
     745,   747,   749,   751,   753,   756,   757,   760,   761,   765,
     766,   770,   772,   773,   777,   779,   781,   783,   785,   787,
     789,   792,   794,   795,   797,   798,   804,   806,   808,   810,
     815,   820,   827,   829,   831,   833,   835,   840,   847,   849,
     854,   861,   863,   865,   867,   869,   871,   874,   877,   879,
     884,   885,   893,   894,   907,   908,   913,   914,   920,   922,
     926,   929,   931,   935,   937,   938,   941,   944,   946,   949,
     955,   960,   963,   968,   974,   978,   979,   980,   992,   993,
     997,   999,  1000,  1003,  1005,  1008,  1009,  1013,  1014,  1018,
    1019,  1023,  1028,  1034,  1036,  1038,  1040,  1042,  1044,  1046,
    1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,  1066,
    1068,  1070,  1073,  1075,  1077,  1079,  1081,  1084,  1086,  1088,
    1090,  1093,  1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,
    1112,  1114,  1116,  1117,  1119,  1121,  1123,  1125,  1129,  1131,
    1135,  1137,  1141,  1143,  1145,  1147,  1150,  1152,  1154,  1158,
    1163,  1168,  1171,  1174,  1177,  1180,  1182,  1184,  1186,  1190,
    1192,  1195,  1198,  1200,  1201,  1205,  1208,  1211,  1213,  1217,
    1222,  1227,  1233,  1239,  1241,  1243,  1246,  1249,  1252,  1255,
    1257,  1260,  1263,  1266,  1269,  1272,  1275,  1278,  1281,  1284,
    1287,  1290,  1293,  1296,  1299,  1300,  1301,  1302,  1309,  1310,
    1311,  1318,  1319,  1320,  1327,  1328,  1329,  1336,  1337,  1338,
    1345,  1346,  1347,  1354,  1356,  1361,  1366,  1371,  1376,  1381,
    1383,  1385,  1387,  1389,  1394,  1399,  1404,  1409,  1412,  1415,
    1418,  1419,  1420,  1432,  1433,  1436,  1437,  1438,  1439,  1448,
    1449,  1450,  1461,  1462,  1464,  1465,  1467,  1469,  1472,  1473,
    1477,  1478,  1482,  1483,  1485,  1487,  1490,  1491,  1495,  1496,
    1500,  1504,  1506,  1511,  1515,  1517,  1521,  1523,  1527,  1529,
    1533,  1535,  1538,  1539,  1543,  1544,  1548,  1549,  1554,  1555,
    1560,  1561,  1566,  1569,  1573,  1575,  1579,  1581,  1583,  1585,
    1587,  1589,  1591,  1595,  1597,  1599,  1604,  1611,  1616,  1620,
    1627,  1631,  1638,  1640,  1642,  1644,  1646,  1648,  1650,  1651,
    1654,  1658,  1660,  1664,  1666,  1671,  1673,  1675,  1676,  1677,
    1679,  1684,  1688,  1695,  1699,  1706,  1708,  1710,  1713,  1715,
    1717,  1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,
    1737,  1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,
    1757,  1759,  1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,
    1777,  1779,  1781,  1783,  1785,  1787,  1789,  1791,  1793,  1796,
    1799,  1801,  1805,  1807,  1810,  1813,  1816,  1821,  1824,  1827,
    1832,  1833,  1842,  1843,  1845,  1847,  1849,  1850,  1852,  1855,
    1856,  1858,  1861,  1862,  1864,  1867,  1868,  1870,  1874,  1875,
    1878,  1879,  1887,  1888,  1889,  1893,  1899,  1900,  1903,  1904,
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
    2190,  2191,  2192,  2203,  2204,  2206,  2208,  2211,  2214,  2216,
    2218,  2220,  2222,  2224,  2226,  2228,  2230,  2232,  2234,  2236,
    2237,  2239,  2241,  2243,  2245,  2246,  2247,  2248,  2249,  2263,
    2265,  2266,  2267,  2274,  2278,  2279,  2281,  2284,  2285,  2287,
    2289,  2292,  2294,  2296,  2298,  2300,  2301,  2305,  2308,  2310,
    2311,  2312,  2313,  2328,  2329,  2335,  2337,  2338,  2342,  2343,
    2351,  2352,  2358,  2360,  2363,  2364,  2366,  2368,  2370,  2371,
    2373,  2375,  2378,  2381,  2384,  2386,  2388,  2390,  2392,  2396,
    2398,  2400,  2401,  2402,  2410,  2412,  2415,  2416,  2420,  2421,
    2426,  2429,  2430,  2433,  2435,  2437,  2439,  2441,  2443,  2445,
    2447,  2448,  2452,  2453,  2455,  2457,  2459,  2461,  2464,  2468,
    2471,  2477,  2479,  2481,  2483,  2488,  2493,  2495,  2497,  2499,
    2501,  2504,  2508,  2515,  2517,  2521,  2523,  2525,  2527,  2532,
    2540,  2542,  2544,  2546,  2548,  2551,  2552,  2554,  2556,  2560,
    2562,  2566,  2568,  2572,  2574,  2578,  2580,  2582,  2584,  2586,
    2590,  2592,  2594,  2598,  2600,  2602,  2604,  2608,  2611,  2612,
    2614,  2616,  2621,  2623,  2627,  2629,  2633,  2641,  2642,  2650,
    2651,  2658,  2662,  2664,  2668,  2670,  2673,  2679,  2680,  2688,
    2689,  2692,  2693,  2695,  2701,  2704,  2710,  2711,  2717,  2724,
    2729,  2730,  2732,  2734,  2739,  2740,  2743,  2744,  2750,  2755,
    2758,  2760,  2764,  2767,  2770,  2773,  2776,  2779,  2782,  2784,
    2787,  2790,  2793,  2796,  2799,  2802,  2805,  2808,  2811,  2813,
    2815,  2817,  2819,  2821,  2823,  2829,  2831,  2833,  2836,  2841,
    2843,  2844,  2855,  2861,  2862,  2864,  2865,  2868,  2870,  2873,
    2874,  2878,  2880,  2881,  2886,  2887,  2890,  2892,  2896,  2898,
    2900,  2904,  2909,  2914,  2917,  2919,  2921,  2923,  2924,  2926,
    2927,  2928,  2929,  2940,  2943,  2946,  2949,  2952,  2954,  2957,
    2958,  2962,  2963,  2967,  2968,  2972,  2973,  2977,  2978,  2982,
    2983,  2988,  2989,  2994,  2996,  2998,  3000,  3002,  3004,  3006,
    3007,  3012,  3013,  3015,  3016,  3021,  3023,  3026,  3029,  3032,
    3033,  3035,  3037,  3040,  3043,  3044,  3047,  3051,  3055,  3061,
    3062,  3065,  3070,  3072,  3074,  3076,  3078,  3080,  3081,  3083,
    3085,  3089,  3092,  3098,  3101,  3107,  3113,  3119,  3125,  3131,
    3137,  3138,  3141,  3143,  3146,  3149,  3152,  3155,  3158,  3161,
    3163,  3166,  3169,  3172,  3175,  3177,  3180,  3183,  3186,  3189,
    3191,  3193,  3195,  3196,  3199,  3202,  3205,  3208,  3211,  3214,
    3217,  3220,  3223,  3225,  3227,  3229,  3231,  3233,  3235,  3237,
    3239,  3242,  3245,  3248,  3251,  3254,  3256,  3258,  3260,  3261,
    3265,  3268,  3269,  3270,  3271,  3272,  3273,  3288,  3289,  3292,
    3295,  3296,  3298,  3299,  3300,  3301,  3302,  3303,  3318,  3321,
    3322,  3323,  3324,  3335,  3336,  3338,  3342,  3346,  3349,  3354,
    3358,  3362,  3366,  3368,  3370,  3372,  3374,  3376,  3380,  3381,
    3382,  3390,  3391,  3392,  3401,  3402,  3404,  3406,  3410,  3413,
    3416,  3418,  3420,  3424,  3426,  3428,  3431,  3433,  3435,  3437,
    3440,  3442,  3444,  3446,  3448,  3450,  3453,  3460,  3467,  3468,
    3470,  3471,  3473,  3476,  3482,  3483,  3486,  3489,  3491,  3499,
    3501,  3507,  3511,  3513,  3517,  3519,  3523,  3525,  3529,  3531,
    3535,  3537,  3539,  3541,  3543,  3544,  3550,  3551,  3557,  3559,
    3560,  3564,  3566,  3570,  3572,  3576,  3578,  3580,  3581,  3582,
    3588,  3591,  3593,  3594,  3595,  3599,  3600,  3601,  3605,  3607,
    3609,  3611,  3613,  3615,  3618,  3621,  3626,  3630,  3634,  3636,
    3640,  3643,  3645,  3647,  3648,  3650,  3652,  3654,  3656,  3657,
    3659,  3663,  3664,  3668,  3670,  3672,  3674,  3676,  3678,  3680,
    3682,  3684,  3686,  3688,  3690,  3692,  3694,  3702,  3703,  3705,
    3707,  3709,  3711,  3715,  3717,  3719,  3721,  3724,  3725,  3729,
    3731,  3735,  3737,  3741,  3743,  3745,  3752,  3753,  3757,  3759,
    3763,  3764,  3766,  3771,  3777,  3780,  3782,  3784,  3789,  3791,
    3795,  3800,  3805,  3807,  3811,  3813,  3815,  3817,  3820,  3822,
    3827,  3828,  3830,  3831,  3834,  3836,  3838,  3840,  3845,  3849,
    3851,  3853,  3855,  3858,  3860,  3862,  3865,  3868,  3870,  3874,
    3877,  3880,  3882,  3886,  3888,  3891,  3896,  3898,  3901,  3903,
    3907,  3912,  3913,  3915,  3916,  3918,  3919,  3921,  3923,  3927,
    3929,  3933,  3935,  3938,  3940,  3944,  3947,  3950,  3955,  3959,
    3960,  3962,  3964,  3966,  3968,  3970,  3973,  3975,  3977,  3983,
    3987,  3993,  3997,  3999,  4003,  4004,  4006,  4010,  4014,  4018,
    4022,  4029,  4035,  4037,  4039,  4041,  4043,  4045,  4047,  4049,
    4051,  4053,  4055,  4057,  4059,  4061,  4063,  4064,  4066,  4068,
    4070,  4072,  4074,  4076,  4078,  4083,  4089,  4091,  4097,  4103,
    4105,  4107,  4109,  4114,  4116,  4121,  4123,  4131,  4133,  4135,
    4137,  4142,  4149,  4150,  4153,  4158,  4160,  4162,  4164,  4166,
    4168,  4170,  4172,  4174,  4176,  4180,  4184,  4186,  4188,  4190,
    4191,  4195,  4201,  4204,  4210,  4215,  4217,  4219,  4221,  4223,
    4225,  4228,  4231,  4234,  4237,  4239,  4242,  4245,  4246,  4250,
    4251,  4255,  4257,  4259,  4261,  4263,  4265,  4267,  4269,  4271,
    4273,  4275,  4277,  4279,  4281,  4283,  4285,  4287,  4289,  4291,
    4293,  4295,  4297,  4299,  4301,  4303,  4305,  4307,  4309,  4311,
    4313,  4315,  4319,  4320,  4329,  4330,  4340,  4341,  4349,  4350,
    4360,  4361,  4363,  4366,  4368,  4372,  4374,  4378,  4384,  4386,
    4388,  4390,  4392,  4395,  4396,  4397,  4406,  4412,  4414,  4416,
    4424,  4425,  4429,  4431,  4435,  4437,  4438,  4441,  4447,  4455,
    4456,  4458,  4460,  4462,  4464,  4468,  4470,  4473,  4475,  4479,
    4482,  4486,  4490,  4494,  4496,  4498,  4500,  4502,  4504,  4506,
    4508,  4514,  4520,  4526,  4532,  4538,  4543,  4550,  4554,  4556,
    4560,  4561,  4563,  4569,  4577,  4578,  4581,  4583,  4585,  4586,
    4590,  4592,  4596,  4598,  4600,  4602,  4603,  4607,  4609,  4611,
    4613,  4615,  4620,  4627,  4629,  4631,  4634,  4638,  4640,  4642,
    4644,  4646,  4648,  4650,  4652,  4654,  4656,  4659,  4661,  4663,
    4665,  4669,  4675,  4677,  4679,  4681,  4683,  4687,  4690,  4693,
    4696,  4698,  4701,  4704,  4707,  4710,  4713,  4715,  4719,  4722,
    4724,  4727,  4729,  4732,  4734,  4735,  4736,  4743,  4744,  4747,
    4748,  4750,  4752,  4755,  4758,  4761,  4766,  4770,  4772,  4776,
    4778,  4781,  4787,  4790,  4793,  4799,  4800,  4803,  4805,  4807,
    4810,  4817,  4824,  4826,  4827,  4829,  4832,  4834,  4837,  4838,
    4841,  4843,  4845,  4847,  4849,  4851,  4853,  4855,  4857,  4859,
    4861,  4863,  4865,  4867,  4869,  4871,  4873,  4875,  4877,  4879,
    4881,  4883,  4885,  4887,  4889,  4891,  4893,  4895,  4897,  4899,
    4901,  4903,  4905,  4907,  4909,  4911,  4913,  4915,  4917,  4919,
    4921,  4923,  4925,  4927,  4929,  4931,  4933,  4935,  4937,  4939,
    4941,  4943,  4945,  4947,  4949,  4951,  4953,  4955,  4957,  4959,
    4961,  4963,  4965,  4967,  4969,  4971,  4973,  4975,  4977,  4979,
    4981,  4983,  4985,  4987,  4989,  4991,  4993,  4995,  4997,  4999,
    5001,  5003
};
static const short yyrhs[] =
{
     170,     0,   167,     0,    96,   641,   394,   564,   642,     0,
     110,     0,  1043,     0,    25,     0,   643,     0,   642,     5,
     643,     0,   891,     0,   398,   644,   359,     0,   644,   645,
     644,     0,    25,     0,   646,    25,     0,  1043,     0,    18,
       0,    17,     0,    20,     0,    19,     0,    21,     0,    18,
       0,    17,     0,     0,   648,     0,     0,   245,   398,   649,
     650,   359,     0,   536,   398,    25,     5,    25,   359,     0,
     651,     0,   650,     5,   651,     0,   457,     0,   497,     0,
     503,     0,   473,     0,   377,     0,   574,     0,   494,     0,
     447,     0,   384,     0,   458,     0,   313,     0,   498,     0,
     423,     0,   301,     0,   562,     0,    70,     0,     0,   653,
       0,     0,   245,   398,   654,   655,   359,     0,   656,     0,
     655,     5,   656,     0,   651,     0,   399,     0,   572,    24,
       0,   173,   878,     0,   298,   878,     0,   255,   878,     0,
     306,   878,     0,   264,   878,     0,   230,   878,     0,   500,
     658,     0,   830,   312,  1043,     0,     0,   260,   398,  1397,
     359,   312,   659,  1061,     0,    76,   398,   891,   359,     0,
     374,   398,   883,   359,   312,  1043,     0,  1179,     0,   162,
     398,   883,   359,   312,  1043,     0,     0,     0,  1043,   558,
     891,   398,   660,   674,   359,   661,   672,     0,     0,     0,
       0,   891,   398,   662,   674,   663,   359,   664,   672,     0,
       0,     0,   441,  1367,   592,  1367,   398,   665,   674,   666,
     359,   672,     0,     0,     0,    35,   398,   667,   674,   668,
     359,   672,     0,     0,     0,     0,   333,   677,   558,   678,
     426,   641,   394,   398,   669,   674,   670,   359,   671,   673,
       0,     0,   312,  1061,     0,     0,   312,  1061,     0,   134,
       0,     0,   675,     0,   676,     0,   675,     5,   676,     0,
     801,     0,    24,     0,   891,     0,   891,     0,   891,   589,
     891,     0,     0,   501,   808,   680,   683,   687,   684,     0,
       0,   501,   681,   682,   685,   684,     0,   689,     0,   682,
     689,     0,   691,     0,   683,   691,     0,   328,     0,     0,
       0,   308,   686,  1407,     0,     0,     0,   308,   688,  1407,
       0,     0,   547,   808,   690,  1407,     0,     0,   547,   808,
     692,  1407,     0,   249,   888,     0,   172,   886,     0,    53,
     886,     0,   141,     0,   157,  1373,     0,   461,   885,     0,
      29,   695,    30,     0,   696,     0,   698,     0,   697,     0,
     696,   697,     0,    28,     0,   699,     0,   698,   699,     0,
      27,     0,   361,     0,     0,     0,   289,   702,   704,   703,
     705,     0,   352,  1043,   594,   706,   932,   959,   647,     0,
    1043,   594,   706,   932,   513,  1397,   959,   647,     0,     0,
     708,   161,     0,   707,     0,   706,     5,   707,     0,   891,
       0,   891,   589,   891,     0,   891,   589,    20,     0,   709,
       0,   708,   709,     0,     0,   241,   715,   710,  1407,     0,
       0,   244,   716,   711,  1407,     0,     0,   960,   712,  1407,
       0,     0,   139,   713,  1407,     0,     0,   135,   714,  1407,
       0,   897,     0,   715,     5,   897,     0,   897,     0,   716,
       5,   897,     0,    64,     0,    65,     0,    66,     0,    67,
       0,    68,     0,    69,     0,   127,     0,   250,     0,     0,
     720,     0,   721,     0,   720,   721,     0,     0,   405,   722,
     723,     0,   768,     0,  1387,     0,   726,     0,   723,     5,
     726,     0,     0,   725,   891,     0,   321,   724,   767,    24,
       0,   321,   724,   767,   899,     0,   321,   724,   767,    25,
       0,   730,   746,     0,     0,   724,   321,   727,   728,     0,
      25,     0,    24,     0,   899,     0,    17,    25,     0,   724,
       0,   729,     0,   730,     5,   729,     0,     0,   502,     0,
       0,   454,   426,   738,   394,   733,   593,   746,     0,     0,
     287,   731,   735,    25,   736,   273,   426,   737,   394,   734,
     593,   746,     0,   398,     0,   425,     0,   359,     0,   393,
       0,    25,     0,   739,     5,   739,     5,   739,     0,   739,
       5,   739,     0,   739,     0,    25,     0,     0,   431,   741,
     723,   254,     0,     0,   231,   742,   724,   589,    20,     0,
       0,   303,   743,   724,   229,   398,   744,   359,     0,   745,
       0,   744,     5,   745,     0,   724,     0,   747,     0,     0,
     748,   749,     0,   732,     0,   740,     0,   502,     0,   502,
     398,    25,   359,     0,   391,   398,    25,   359,     0,   391,
     398,    25,     5,    25,   359,     0,   375,     0,   586,   724,
       0,   347,     0,   476,     0,    61,     0,   365,     0,   365,
     398,    25,   359,     0,   365,   398,    25,     5,    25,   359,
       0,   479,     0,   479,   398,    25,   359,     0,   479,   398,
      25,     5,    25,   359,     0,   469,     0,   270,     0,   504,
       0,   499,     0,    50,     0,    51,     0,   542,     0,   325,
     753,     0,   337,   754,     0,   750,     0,   891,     0,   523,
     751,   589,   752,     0,   724,     0,   724,     0,     0,   755,
     595,   758,     0,   763,   595,   766,     0,     0,   756,   757,
       0,   550,     0,   480,     0,   559,     0,   519,     0,   421,
       0,   437,     0,   334,   760,     0,     0,   759,   757,     0,
       0,   398,   762,   359,     0,     0,   398,    25,   359,     0,
      25,     0,     0,   764,   765,   761,     0,   550,     0,   480,
       0,   559,     0,   519,     0,   421,     0,   437,     0,   334,
     760,     0,   765,     0,     0,    13,     0,     0,   207,   891,
     769,   586,   770,     0,   772,     0,   775,     0,   502,     0,
     502,   398,    25,   359,     0,   391,   398,    25,   359,     0,
     391,   398,    25,     5,    25,   359,     0,   375,     0,   347,
       0,   476,     0,   365,     0,   365,   398,    25,   359,     0,
     365,   398,    25,     5,    25,   359,     0,   479,     0,   479,
     398,    25,   359,     0,   479,   398,    25,     5,    25,   359,
       0,   469,     0,   270,     0,   504,     0,   499,     0,   542,
       0,   325,   753,     0,   337,   754,     0,   771,     0,   523,
     751,   589,   752,     0,     0,   454,   426,   738,   394,   773,
     593,   770,     0,     0,   287,   731,   735,    25,   736,   273,
     426,   737,   394,   774,   593,   770,     0,     0,   431,   776,
     778,   254,     0,     0,   231,   777,   891,   589,    20,     0,
     779,     0,   778,     5,   779,     0,   780,   770,     0,   781,
       0,   780,     5,   781,     0,   891,     0,     0,   587,   882,
       0,    40,   891,     0,    38,     0,   595,  1397,     0,   595,
     476,   891,   628,  1397,     0,   595,   476,   891,   357,     0,
      42,   891,     0,   128,   824,  1061,   790,     0,   368,   824,
     806,   782,   790,     0,   179,   888,   790,     0,     0,     0,
     160,   787,  1068,   595,   891,   589,    20,   789,   647,   788,
     791,     0,     0,   436,     8,   883,     0,   647,     0,     0,
     792,   209,     0,   793,     0,   792,   793,     0,     0,   319,
     794,  1407,     0,     0,   315,   795,  1407,     0,     0,   960,
     796,  1407,     0,   465,   824,   807,   647,     0,   465,   824,
     807,   647,    36,     0,   257,     0,   256,     0,   182,     0,
     332,     0,   146,     0,   181,     0,   297,     0,   296,     0,
     214,     0,   143,     0,   142,     0,   116,     0,   174,     0,
      99,     0,   115,     0,   159,     0,   125,     0,   183,     0,
     183,   808,     0,   811,     0,   810,     0,   813,     0,   839,
       0,   801,   802,     0,   840,     0,   842,     0,   812,     0,
      17,   801,     0,    18,   801,     0,   815,     0,   823,     0,
     817,     0,   442,     0,   717,     0,   818,     0,   819,     0,
     820,     0,   821,     0,   822,     0,     0,   805,     0,   808,
       0,   450,     0,   804,     0,   805,     5,   804,     0,   808,
       0,   806,     5,   808,     0,   808,     0,   807,     5,   808,
       0,   801,     0,    18,     0,    17,     0,   571,   801,     0,
     451,     0,   395,     0,   398,   801,   359,     0,   410,   398,
    1349,   359,     0,   265,   398,  1349,   359,     0,   809,   899,
       0,   809,    25,     0,   455,    25,     0,   455,  1043,     0,
      24,     0,   899,     0,    25,     0,  1043,   388,  1043,     0,
    1043,     0,   401,   801,     0,   360,   801,     0,  1153,     0,
       0,   474,   814,  1153,     0,     7,   801,     0,     6,   801,
       0,   801,     0,   816,     5,   801,     0,   592,   398,  1349,
     359,     0,   396,   398,  1349,   359,     0,   592,   398,   824,
     816,   359,     0,   396,   398,   824,   816,   359,     0,   354,
       0,   220,     0,     9,   801,     0,   223,   801,     0,   523,
     801,     0,   339,   801,     0,   358,     0,     8,   801,     0,
      18,   801,     0,    17,   801,     0,    20,   801,     0,    19,
     801,     0,    21,   801,     0,    10,   801,     0,    13,   801,
       0,   424,   801,     0,    11,   801,     0,    12,   801,     0,
      16,   801,     0,    15,   801,     0,    14,   801,     0,     0,
       0,     0,   891,   398,   826,   674,   827,   359,     0,     0,
       0,    35,   398,   828,   674,   829,   359,     0,     0,     0,
     504,   398,   831,   801,   832,   359,     0,     0,     0,   480,
     398,   833,   801,   834,   359,     0,     0,     0,   559,   398,
     835,   801,   836,   359,     0,     0,     0,   550,   398,   837,
     801,   838,   359,     0,   830,     0,   260,   398,  1397,   359,
       0,    71,   398,   883,   359,     0,    41,   398,   883,   359,
       0,   374,   398,   883,   359,     0,   162,   398,   883,   359,
       0,   841,     0,   825,     0,  1325,     0,   504,     0,   390,
     398,   801,   359,     0,   291,   398,   801,   359,     0,   455,
     398,    25,   359,     0,   455,   398,  1043,   359,     0,   801,
      80,     0,   801,    81,     0,   801,    82,     0,     0,     0,
     564,  1043,    13,   808,   595,   808,   846,   844,  1407,   845,
     212,     0,     0,   539,   808,     0,     0,     0,     0,   371,
     848,   885,   849,  1228,   850,  1407,   211,     0,     0,     0,
     607,   891,   852,   719,   853,   988,   855,   854,   860,   608,
       0,     0,   865,     0,     0,   856,     0,   857,     0,   856,
     857,     0,     0,   609,   858,  1407,     0,     0,   610,   859,
    1407,     0,     0,   861,     0,   862,     0,   861,   862,     0,
       0,   611,   863,  1407,     0,     0,   612,   864,  1407,     0,
     866,   870,   293,     0,    63,     0,    63,   867,   513,   868,
       0,    63,   352,   869,     0,  1043,     0,   867,     5,  1043,
       0,   891,     0,   868,     5,   891,     0,  1043,     0,   869,
       5,  1043,     0,   871,     0,   870,   871,     0,     0,   613,
     872,  1407,     0,     0,   614,   873,  1407,     0,     0,   633,
     868,   874,  1407,     0,     0,   448,   868,   875,  1407,     0,
       0,   594,   868,   876,  1407,     0,   512,   884,     0,   521,
      17,    25,     0,   521,     0,   468,    18,    25,     0,   468,
       0,    25,     0,  1043,     0,    24,     0,   898,     0,   808,
       0,   880,     5,   880,     0,   881,     0,   891,     0,   636,
     398,   891,   359,     0,   891,   589,   636,   398,   891,   359,
       0,   891,   426,   644,   394,     0,   891,   589,    20,     0,
     891,   426,   644,   394,   589,    20,     0,   891,   589,   891,
       0,   891,   426,   644,   394,   589,   891,     0,   892,     0,
     892,     0,   892,     0,   892,     0,   892,     0,   892,     0,
       0,   517,    25,     0,   895,  1406,   896,     0,   900,     0,
     895,   893,   896,     0,  1406,     0,   317,   398,   894,   359,
       0,  1046,     0,    24,     0,     0,     0,   891,     0,   891,
     426,   644,   394,     0,   891,   589,    20,     0,   891,   426,
     644,   394,   589,    20,     0,   891,   589,   891,     0,   891,
     426,   644,   394,   589,   891,     0,  1043,     0,    23,     0,
     589,    25,     0,   341,     0,   459,     0,   460,     0,   358,
       0,   461,     0,   321,     0,   289,     0,   463,     0,   427,
       0,   503,     0,   416,     0,   560,     0,   364,     0,   456,
       0,   449,     0,   526,     0,   367,     0,   326,     0,   464,
       0,   290,     0,   505,     0,   251,     0,   562,     0,   624,
       0,   506,     0,   291,     0,   508,     0,   372,     0,   410,
       0,   550,     0,   480,     0,   559,     0,   525,     0,   442,
       0,   346,     0,   361,     0,   406,     0,   348,     0,   409,
       0,   390,     0,   514,  1389,     0,   621,   903,     0,   904,
       0,   903,     5,   904,     0,   891,     0,   632,   903,     0,
     623,   903,     0,   624,  1397,     0,   622,   888,   628,  1397,
       0,   626,   903,     0,   627,  1397,     0,   625,   888,   628,
    1397,     0,     0,   630,   909,   806,   914,   916,   918,   910,
     912,     0,     0,   911,     0,   618,     0,   619,     0,     0,
     913,     0,   312,  1043,     0,     0,   915,     0,   357,   806,
       0,     0,   917,     0,   629,    25,     0,     0,   919,     0,
     620,    25,   920,     0,     0,   367,    25,     0,     0,   591,
     808,   543,   922,  1407,   923,   408,     0,     0,     0,   509,
     924,  1407,     0,    78,   891,   398,    25,   359,     0,     0,
      45,   891,     0,     0,   261,  1073,   928,   595,   450,     0,
     261,  1073,   523,   929,     0,   930,     0,   929,     5,   930,
       0,   751,   589,  1322,     0,   751,   589,    20,     0,     0,
     933,   293,     0,     0,   122,     0,   934,     0,   933,   934,
       0,     0,   241,   948,   935,  1407,     0,     0,   244,   949,
     936,  1407,     0,     0,   319,   937,  1407,     0,     0,   315,
     938,  1407,     0,     0,   960,   939,  1407,     0,     0,   276,
     940,  1407,     0,     0,   246,   941,  1407,     0,     0,   633,
     946,   942,  1407,     0,     0,   448,   944,   943,  1407,     0,
     945,     0,   944,     5,   945,     0,   417,     0,   406,     0,
     947,     0,   946,     5,   947,     0,   417,     0,   406,     0,
     883,     0,   948,     5,   883,     0,   883,     0,   949,     5,
     883,     0,   283,   952,     0,   284,   891,   628,   952,     0,
     529,     0,   342,     0,   883,     0,     0,   634,   955,   954,
     931,     0,   352,  1061,   932,   890,   647,     0,  1061,   932,
     513,  1397,   890,   647,     0,     0,   454,  1068,   932,   513,
     891,   589,    20,   890,   956,   647,     0,   436,  1397,   958,
       0,   596,     0,   506,     0,    46,    25,     0,    52,    25,
       0,     0,   517,    25,     0,     0,   397,   961,   967,     0,
     266,     0,     0,   565,   963,   967,     0,   274,   969,     0,
       0,   565,   966,   967,     0,   969,     0,   398,   968,   359,
       0,   969,     0,   968,     5,   969,     0,     0,   970,   971,
       0,   563,     0,   281,     0,   299,     0,   275,     0,   452,
       0,   409,     0,   596,     0,   506,     0,   433,     0,   507,
       0,   522,     0,   487,     0,   279,     0,   280,     0,    24,
       0,   477,   891,     0,   477,   891,   558,     0,     0,     0,
     567,   974,  1066,   975,    13,   824,   976,     0,   450,     0,
     807,     0,   189,  1043,     0,   178,  1043,     0,   192,  1043,
       0,   418,  1043,   302,     0,   418,  1043,   353,   879,     0,
       0,     0,   988,   926,   988,  1002,   988,   982,   719,   988,
     983,   984,     0,     0,   985,     0,   987,     0,   985,   987,
       0,    37,   891,     0,   990,     0,   996,     0,  1008,     0,
    1163,     0,  1172,     0,  1029,     0,  1387,     0,   851,     0,
     694,     0,   925,     0,   700,     0,     0,   694,     0,  1387,
       0,   335,     0,    31,     0,     0,     0,     0,     0,   989,
     991,   891,   398,   992,  1059,   359,   993,   719,   994,   988,
    1407,   995,     0,   180,     0,     0,     0,   524,   997,   719,
     998,  1407,   329,     0,   433,   824,   803,     0,     0,   806,
       0,   324,  1333,     0,     0,  1003,     0,  1004,     0,  1003,
    1004,     0,  1005,     0,   694,     0,  1387,     0,  1001,     0,
       0,   373,  1006,  1007,     0,   719,   213,     0,   879,     0,
       0,     0,     0,    85,   891,    84,   891,   398,  1009,  1059,
     359,  1010,   719,  1011,   988,  1407,   995,     0,     0,   525,
    1013,  1028,  1019,  1014,     0,   330,     0,     0,   205,  1016,
    1407,     0,     0,    22,  1020,  1021,  1022,   890,  1017,  1407,
       0,     0,    22,  1020,   890,  1018,  1407,     0,  1015,     0,
    1019,  1015,     0,     0,   962,     0,    24,     0,  1043,     0,
       0,  1043,     0,    24,     0,   222,  1026,     0,   234,  1027,
       0,   217,  1027,     0,   554,     0,    24,     0,  1043,     0,
    1026,     0,  1027,     5,  1026,     0,  1043,     0,    24,     0,
       0,     0,   615,   891,  1030,   719,  1031,  1032,   616,     0,
    1033,     0,  1032,  1033,     0,     0,   617,  1034,  1407,     0,
       0,   594,   891,  1035,  1407,     0,  1039,  1037,     0,     0,
     648,  1041,     0,  1042,     0,  1038,     0,   915,     0,   917,
       0,   919,     0,   911,     0,   913,     0,     0,   338,  1040,
     807,     0,     0,    36,     0,    36,     0,  1044,     0,  1046,
       0,   581,  1046,     0,  1046,   895,   589,     0,  1045,  1050,
       0,  1045,   891,   426,  1053,   394,     0,  1051,     0,   891,
       0,  1047,     0,   891,   425,  1049,   393,     0,   891,   425,
    1049,   393,     0,  1043,     0,    24,     0,    20,     0,   891,
       0,   891,  1052,     0,   426,  1053,   394,     0,   426,  1053,
     394,   426,  1053,   394,     0,  1054,     0,  1053,     5,  1054,
       0,   644,     0,  1056,     0,  1058,     0,  1056,   895,   589,
    1057,     0,  1056,   895,   589,   891,   426,  1053,   394,     0,
     891,     0,  1048,     0,    20,     0,   891,     0,   891,  1052,
       0,     0,  1060,     0,  1062,     0,  1060,     5,  1062,     0,
    1063,     0,  1061,     5,  1063,     0,   891,     0,   891,   589,
     891,     0,  1043,     0,  1043,   388,  1043,     0,    24,     0,
     899,     0,    25,     0,  1065,     0,  1064,     5,  1065,     0,
    1043,     0,  1067,     0,  1066,     5,  1067,     0,  1055,     0,
    1043,     0,  1070,     0,  1069,     5,  1070,     0,  1043,  1071,
       0,     0,   556,     0,   505,     0,   891,   426,  1053,   394,
       0,  1074,     0,  1073,     5,  1074,     0,  1043,     0,  1043,
     388,  1043,     0,   225,   887,   587,   881,   548,  1399,   652,
       0,     0,   587,   398,   808,     5,   808,   359,  1077,     0,
       0,   536,   398,   808,     5,   808,   359,     0,   226,   891,
    1076,     0,   891,     0,   307,   889,  1081,     0,  1082,     0,
     513,   808,     0,  1083,  1084,  1089,     8,  1079,     0,     0,
     587,  1085,   398,   808,     5,   808,   359,     0,     0,   523,
     892,     0,     0,   318,     0,   187,  1373,   237,  1382,  1088,
       0,   531,   884,     0,   531,   884,     8,   824,   806,     0,
       0,   586,   544,  1367,   341,  1367,     0,   586,   544,  1367,
       5,   341,  1367,     0,   586,  1367,     5,  1367,     0,     0,
     618,     0,   619,     0,    62,  1382,  1091,  1092,     0,     0,
     586,  1382,     0,     0,   586,   544,  1367,     8,  1367,     0,
     544,  1367,     8,  1367,     0,   379,  1094,     0,  1095,     0,
    1094,     5,  1095,     0,   173,   878,     0,   255,   878,     0,
     298,   878,     0,   306,   878,     0,   264,   878,     0,   230,
     878,     0,   964,     0,   406,   965,     0,   417,   965,     0,
     529,   965,     0,   342,   965,     0,   517,   965,     0,   515,
     879,     0,   516,   879,     0,   368,   648,     0,   634,   648,
       0,   262,     0,   165,     0,   123,     0,   100,     0,   118,
       0,   109,     0,  1372,   381,  1099,   513,  1097,     0,  1043,
       0,    24,     0,   370,  1099,     0,   370,  1099,     8,  1061,
       0,   892,     0,     0,   429,  1108,   647,   564,  1103,  1043,
     890,   647,  1101,  1104,     0,   429,  1108,   647,   312,  1043,
       0,     0,   502,     0,     0,  1105,   253,     0,  1106,     0,
    1105,  1106,     0,     0,   960,  1107,  1407,     0,   807,     0,
       0,   573,   884,  1110,  1111,     0,     0,   513,  1112,     0,
    1113,     0,  1112,     5,  1113,     0,  1361,     0,   450,     0,
     190,  1116,    60,     0,   190,  1116,   595,  1115,     0,   190,
    1116,    59,  1115,     0,   190,  1116,     0,    24,     0,   898,
       0,   891,     0,     0,   446,     0,     0,     0,     0,   117,
    1116,  1117,   398,  1119,   824,  1120,  1000,  1121,   359,     0,
     163,  1116,     0,  1154,  1162,     0,   414,    32,     0,   414,
    1125,     0,  1126,     0,  1125,  1126,     0,     0,   105,  1127,
    1407,     0,     0,   169,  1128,  1407,     0,     0,   198,  1129,
    1407,     0,     0,   186,  1130,  1407,     0,     0,   224,  1131,
    1407,     0,     0,   171,  1043,  1132,  1407,     0,     0,   194,
    1043,  1133,  1407,     0,  1144,     0,  1146,     0,  1145,     0,
    1135,     0,  1170,     0,  1138,     0,     0,   528,   808,  1136,
     449,     0,     0,   449,     0,     0,   537,   808,  1139,  1137,
       0,   130,     0,   598,  1158,     0,   133,  1158,     0,   132,
    1158,     0,     0,  1141,     0,  1142,     0,  1141,  1142,     0,
    1151,  1143,     0,     0,   587,  1158,     0,   486,  1140,  1150,
       0,   485,  1367,  1150,     0,   484,  1149,  1148,  1147,  1150,
       0,     0,   124,   801,     0,   124,   801,     5,   801,     0,
     582,     0,   583,     0,   584,     0,   585,     0,  1043,     0,
       0,   488,     0,  1152,     0,  1151,     5,  1152,     0,   808,
    1183,     0,   578,   398,   801,   359,  1169,     0,    34,  1169,
       0,   463,   398,    20,   359,  1169,     0,   380,   398,    20,
     359,  1169,     0,   355,   398,   801,   359,  1169,     0,   557,
     398,   801,   359,  1169,     0,   570,   398,   801,   359,  1169,
       0,   569,   398,   801,   359,  1169,     0,     0,   428,  1155,
       0,  1156,     0,  1155,  1156,     0,   197,    25,     0,   188,
      25,     0,   272,    25,     0,   156,    25,     0,   227,    25,
       0,   148,     0,   311,    24,     0,   311,  1043,     0,   149,
      24,     0,   131,    24,     0,  1161,     0,  1157,  1161,     0,
    1159,    80,     0,  1159,    82,     0,  1159,    81,     0,  1159,
       0,   899,     0,    25,     0,     0,   428,  1157,     0,   197,
    1158,     0,   188,  1158,     0,   272,  1158,     0,   156,  1158,
       0,   227,  1158,     0,   228,  1158,     0,   597,    24,     0,
     598,  1158,     0,   602,     0,   599,     0,   600,     0,   601,
       0,   606,     0,   603,     0,   604,     0,   605,     0,    47,
    1158,     0,    48,  1158,     0,    49,  1158,     0,   311,    24,
       0,   149,    24,     0,   367,     0,    43,     0,    44,     0,
       0,   481,   588,  1069,     0,   106,  1069,     0,     0,     0,
       0,     0,     0,   432,  1164,   891,   398,  1165,  1059,   359,
    1166,   719,  1123,  1167,  1124,  1168,   210,     0,     0,   492,
     801,     0,   483,  1171,     0,     0,  1097,     0,     0,     0,
       0,     0,     0,    77,  1173,   891,   398,  1174,  1059,   359,
    1175,   719,  1178,  1176,  1124,  1177,   210,     0,  1160,  1162,
       0,     0,     0,     0,   126,   398,    24,     5,  1180,   674,
    1181,   359,  1182,   672,     0,     0,   351,     0,   351,   188,
      25,     0,   351,   188,  1043,     0,   576,   808,     0,   576,
     808,   312,  1043,     0,   576,   808,   134,     0,   576,   808,
     546,     0,   576,   808,   511,     0,  1186,     0,   145,     0,
     292,     0,   252,     0,  1188,     0,    75,  1194,   359,     0,
       0,     0,   176,  1189,  1317,   398,  1190,  1196,   359,     0,
       0,     0,   103,  1191,  1317,   398,  1192,  1196,   359,  1193,
       0,     0,   239,     0,  1195,     0,  1194,     5,  1195,     0,
     891,   556,     0,   891,   505,     0,   891,     0,  1197,     0,
    1196,     5,  1197,     0,  1268,     0,  1266,     0,    92,   891,
       0,   151,     0,   236,     0,   201,     0,   136,  1201,     0,
     113,     0,   101,     0,    91,     0,    89,     0,    93,     0,
     150,  1373,     0,   200,  1200,   427,  1367,   595,  1367,     0,
     269,   884,   427,  1367,   595,  1367,     0,     0,  1373,     0,
       0,   808,     0,   489,   808,     0,   445,  1317,   552,  1205,
    1204,     0,     0,   121,   885,     0,   492,  1290,     0,  1206,
       0,   398,  1210,   359,    13,   398,  1211,   359,     0,  1207,
       0,    20,    13,   398,  1211,   359,     0,    20,    13,  1211,
       0,  1209,     0,  1207,     5,  1209,     0,  1322,     0,  1208,
      13,  1212,     0,  1208,     0,  1210,     5,  1208,     0,  1212,
       0,  1211,     5,  1212,     0,  1361,     0,   450,     0,  1356,
       0,   199,     0,     0,   219,  1215,  1317,  1218,  1216,     0,
       0,   446,  1217,   398,  1220,   359,     0,  1355,     0,     0,
     398,  1219,   359,     0,  1322,     0,  1219,     5,  1322,     0,
    1221,     0,  1220,     5,  1221,     0,  1361,     0,   450,     0,
       0,     0,   467,  1223,  1225,  1224,  1226,     0,  1230,   885,
       0,   885,     0,     0,     0,   520,  1227,  1061,     0,     0,
       0,   520,  1229,  1061,     0,   468,     0,   521,     0,   529,
       0,   342,     0,   363,     0,   345,   808,     0,   318,   808,
       0,   208,  1317,   121,   885,     0,   208,  1317,  1287,     0,
     481,   588,  1234,     0,  1235,     0,  1234,     5,  1235,     0,
    1236,  1237,     0,    25,     0,  1322,     0,     0,   556,     0,
     505,     0,   247,     0,   278,     0,     0,   295,     0,   324,
    1382,  1240,     0,     0,  1372,  1243,  1244,     0,  1272,     0,
    1276,     0,  1239,     0,  1374,     0,  1238,     0,  1241,     0,
    1231,     0,  1232,     0,  1222,     0,  1214,     0,  1213,     0,
    1345,     0,  1203,     0,   472,  1247,   594,  1317,   595,  1252,
    1246,     0,     0,   112,     0,   140,     0,  1248,     0,  1249,
       0,  1248,     5,  1249,     0,   438,     0,   417,     0,   406,
       0,   445,  1250,     0,     0,   398,  1251,   359,     0,  1322,
       0,  1251,     5,  1322,     0,  1253,     0,  1252,     5,  1253,
       0,   430,     0,  1319,     0,   206,  1317,  1255,   586,  1355,
    1257,     0,     0,   398,  1256,   359,     0,  1322,     0,  1256,
       5,  1322,     0,     0,   111,     0,   459,   398,  1290,   359,
       0,   216,   398,  1261,   359,  1260,     0,   267,  1262,     0,
    1263,     0,  1317,     0,  1317,   398,  1263,   359,     0,  1322,
       0,  1263,     5,  1322,     0,   443,   398,  1265,   359,     0,
     229,   398,  1265,   359,     0,  1322,     0,  1265,     5,  1322,
       0,  1264,     0,  1259,     0,  1258,     0,   367,  1324,     0,
     177,     0,  1322,  1309,  1269,  1270,     0,     0,  1267,     0,
       0,  1271,  1270,     0,   340,     0,   129,     0,  1260,     0,
     459,   398,  1290,   359,     0,    90,  1273,  1275,     0,  1274,
       0,  1319,     0,  1276,     0,  1275,  1276,     0,  1254,     0,
    1245,     0,   415,  1290,     0,   336,  1279,     0,  1360,     0,
    1279,     5,  1360,     0,   492,  1290,     0,   513,  1282,     0,
    1283,     0,  1282,     5,  1283,     0,  1284,     0,   482,  1284,
       0,   482,   398,  1285,   359,     0,  1317,     0,  1317,  1323,
       0,  1283,     0,  1285,     5,  1283,     0,  1281,  1287,  1288,
    1289,     0,     0,  1280,     0,     0,  1278,     0,     0,  1277,
       0,  1291,     0,  1290,     6,  1291,     0,  1292,     0,  1291,
       7,  1292,     0,  1293,     0,   571,  1293,     0,  1307,     0,
     398,  1290,   359,     0,   410,  1356,     0,   265,  1356,     0,
    1361,  1306,  1296,  1356,     0,  1356,  1306,  1361,     0,     0,
    1297,     0,  1298,     0,   554,     0,   538,     0,   555,     0,
     409,  1301,     0,  1363,     0,  1363,     0,  1361,   592,   398,
    1303,   359,     0,  1361,   592,  1356,     0,  1361,   396,   398,
    1303,   359,     0,  1361,   396,  1356,     0,  1363,     0,  1303,
       5,  1363,     0,     0,   571,     0,  1361,  1304,   354,     0,
    1361,  1304,   220,     0,  1361,  1306,  1361,     0,  1361,  1306,
    1356,     0,  1361,  1304,   356,  1361,     7,  1361,     0,  1361,
    1304,   523,  1300,  1299,     0,    13,     0,    16,     0,    11,
       0,    12,     0,   223,     0,   339,     0,     9,     0,   523,
       0,    15,     0,    14,     0,  1305,     0,  1302,     0,  1295,
       0,  1294,     0,     0,   554,     0,   327,     0,   443,     0,
    1310,     0,  1311,     0,  1313,     0,   502,     0,   502,   398,
    1314,   359,     0,   378,   398,  1315,  1312,   359,     0,   439,
       0,   365,   398,  1315,  1312,   359,     0,   479,   398,  1315,
    1312,   359,     0,   504,     0,   375,     0,   347,     0,   325,
    1331,   595,  1332,     0,   325,     0,   337,  1331,   595,  1332,
       0,   337,     0,   337,  1331,   398,    25,   359,   595,  1332,
       0,   542,     0,   499,     0,   391,     0,   391,   398,    25,
     359,     0,   391,   398,    25,     5,    25,   359,     0,     0,
       5,  1316,     0,   469,   398,  1315,   359,     0,   533,     0,
     270,     0,   469,     0,    33,     0,    25,     0,    25,     0,
      25,     0,    24,     0,  1320,     0,  1318,   558,  1320,     0,
      24,   589,  1320,     0,   891,     0,   891,     0,   891,     0,
       0,   426,    25,   394,     0,   426,    25,     5,    25,   394,
       0,   891,  1321,     0,  1317,   895,   589,   891,  1321,     0,
    1317,   895,   589,    20,     0,   891,     0,    24,     0,   378,
       0,   899,     0,    25,     0,    18,   899,     0,    18,    25,
       0,    17,   899,     0,    17,    25,     0,  1326,     0,   363,
    1328,     0,   363,  1327,     0,     0,  1331,   595,  1332,     0,
       0,  1329,   595,  1330,     0,   550,     0,   480,     0,   559,
       0,   519,     0,   421,     0,   437,     0,   334,     0,   550,
       0,   480,     0,   559,     0,   519,     0,   421,     0,   437,
       0,   334,     0,   550,     0,   480,     0,   559,     0,   519,
       0,   421,     0,   437,     0,   334,     0,   550,     0,   480,
       0,   559,     0,   519,     0,   421,     0,   437,     0,   334,
       0,   891,     0,    24,     0,  1372,   470,   885,     0,     0,
    1372,   366,   885,   404,   564,  1343,  1336,  1340,     0,     0,
    1372,   366,   885,   404,    72,   564,  1344,  1337,  1340,     0,
       0,  1372,   366,   885,   107,  1344,  1338,  1340,     0,     0,
    1372,   366,   885,   108,    72,   564,  1344,  1339,  1340,     0,
       0,   259,     0,   258,  1341,     0,  1342,     0,  1341,     5,
    1342,     0,   891,     0,   891,   589,   891,     0,    24,   589,
     891,   589,   891,     0,  1344,     0,  1214,     0,  1099,     0,
    1346,     0,  1346,  1340,     0,     0,     0,   438,  1357,  1358,
    1347,  1354,  1348,  1286,  1352,     0,   438,  1357,  1358,  1286,
    1352,     0,  1351,     0,  1367,     0,   438,   895,  1357,  1358,
    1354,  1286,  1352,     0,     0,   491,  1308,  1350,     0,  1233,
       0,   300,  1353,  1193,     0,   891,     0,     0,   520,  1064,
       0,   438,   895,  1357,  1358,  1286,     0,   398,   438,   895,
    1357,  1358,  1286,   359,     0,     0,   554,     0,   327,     0,
     443,     0,  1359,     0,  1358,     5,  1359,     0,  1361,     0,
    1361,  1406,     0,  1361,     0,  1361,    19,  1361,     0,  1361,
    1381,     0,  1361,    20,  1361,     0,  1361,    18,  1361,     0,
    1361,    17,  1361,     0,  1386,     0,  1324,     0,   451,     0,
     395,     0,   544,     0,    20,     0,    34,     0,   557,   398,
    1308,  1361,   359,     0,   569,   398,  1308,  1361,   359,     0,
     570,   398,  1308,  1361,   359,     0,   578,   398,  1308,  1361,
     359,     0,   463,   398,  1308,  1361,   359,     0,   891,   398,
    1362,   359,     0,   504,   895,   398,   895,  1362,   359,     0,
     398,  1361,   359,     0,  1361,     0,  1362,     5,  1361,     0,
       0,  1324,     0,  1372,   314,  1371,  1366,  1350,     0,  1372,
     304,  1371,  1366,   219,  1317,  1368,     0,     0,   290,  1367,
       0,    24,     0,  1043,     0,     0,   398,  1369,   359,     0,
    1370,     0,  1369,     5,  1370,     0,   891,     0,    24,     0,
    1043,     0,     0,   238,  1373,   564,     0,   892,     0,  1379,
       0,  1378,     0,  1375,     0,   285,  1376,   595,  1376,     0,
     268,  1376,   589,  1377,   595,  1377,     0,   891,     0,   891,
       0,   191,   751,     0,   263,   751,  1380,     0,   242,     0,
     147,     0,    64,     0,    65,     0,    66,     0,    67,     0,
      68,     0,    69,     0,  1383,     0,   581,  1384,     0,  1384,
       0,  1072,     0,   891,     0,  1384,   589,  1385,     0,    24,
     589,  1384,   589,  1385,     0,    20,     0,  1072,     0,   891,
       0,  1383,     0,  1383,   388,  1383,     0,    98,  1388,     0,
     102,  1388,     0,    97,  1388,     0,   137,     0,   138,  1388,
       0,    95,  1388,     0,   120,  1388,     0,   119,  1388,     0,
      94,  1388,     0,   323,     0,   590,   595,  1389,     0,   514,
    1389,     0,   540,     0,   500,  1390,     0,   891,     0,   558,
     891,     0,   891,     0,     0,     0,   493,  1392,   808,  1393,
    1407,   294,     0,     0,   628,  1397,     0,     0,   631,     0,
     153,     0,   248,   886,     0,    39,   886,     0,   277,  1395,
       0,   277,   888,  1394,  1395,     0,   460,  1397,  1395,     0,
     883,     0,  1397,     5,   883,     0,    74,     0,   104,   886,
       0,   808,   534,     5,   808,   360,     0,   476,   808,     0,
     235,   886,     0,    73,  1402,     8,  1403,  1401,     0,     0,
     513,   808,     0,   891,     0,   891,     0,   218,   886,     0,
     221,   886,   595,   808,     5,   808,     0,   221,   886,   588,
     808,     5,   808,     0,    26,     0,     0,  1409,     0,  1410,
    1150,     0,  1408,     0,  1409,  1408,     0,     0,  1411,  1412,
       0,   637,     0,   638,     0,   639,     0,   640,     0,   657,
       0,   679,     0,   693,     0,   694,     0,   700,     0,   701,
       0,   718,     0,   783,     0,   784,     0,   785,     0,   786,
       0,   797,     0,   798,     0,   799,     0,   800,     0,   843,
       0,   847,     0,   877,     0,   901,     0,   902,     0,   905,
       0,   906,     0,   907,     0,   908,     0,   921,     0,   927,
       0,   950,     0,   951,     0,   953,     0,   957,     0,   972,
       0,   973,     0,   977,     0,   978,     0,   979,     0,   980,
       0,   986,     0,   999,     0,  1012,     0,  1023,     0,  1024,
       0,  1025,     0,  1036,     0,  1075,     0,  1078,     0,  1080,
       0,  1086,     0,  1087,     0,  1090,     0,  1093,     0,  1096,
       0,  1098,     0,  1100,     0,  1102,     0,  1109,     0,  1114,
       0,  1118,     0,  1122,     0,  1134,     0,  1184,     0,  1185,
       0,  1187,     0,  1198,     0,  1199,     0,  1202,     0,  1241,
       0,  1242,     0,  1334,     0,  1335,     0,  1364,     0,  1365,
       0,  1387,     0,  1391,     0,  1396,     0,  1398,     0,  1400,
       0,  1404,     0,  1405,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   857,   860,   863,   869,   875,   882,   886,   886,   892,
     909,   911,   912,   913,   914,   927,   929,   930,   931,   932,
     937,   938,   949,   952,   955,   955,   959,   962,   963,   969,
     970,   971,   972,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   987,   988,   991,   991,   999,
    1000,  1003,  1009,  1011,  1022,  1024,  1026,  1028,  1032,  1034,
    1096,  1099,  1104,  1104,  1111,  1114,  1118,  1119,  1122,  1122,
    1122,  1141,  1141,  1141,  1141,  1162,  1162,  1162,  1175,  1175,
    1175,  1198,  1198,  1198,  1198,  1236,  1236,  1240,  1241,  1242,
    1246,  1250,  1255,  1259,  1267,  1270,  1270,  1276,  1280,  1292,
    1292,  1310,  1310,  1326,  1326,  1329,  1329,  1332,  1336,  1336,
    1336,  1343,  1343,  1343,  1351,  1351,  1362,  1362,  1381,  1384,
    1387,  1390,  1393,  1396,  1409,  1414,  1414,  1415,  1415,  1418,
    1423,  1423,  1427,  1437,  1450,  1450,  1450,  1464,  1471,  1479,
    1480,  1483,  1483,  1486,  1490,  1495,  1502,  1502,  1505,  1505,
    1513,  1513,  1518,  1518,  1523,  1523,  1528,  1528,  1540,  1542,
    1549,  1551,  1567,  1571,  1574,  1577,  1580,  1583,  1596,  1600,
    1615,  1616,  1619,  1620,  1623,  1623,  1625,  1626,  1629,  1629,
    1632,  1632,  1635,  1637,  1640,  1644,  1645,  1645,  1661,  1662,
    1662,  1662,  1666,  1673,  1674,  1677,  1677,  1679,  1679,  1685,
    1685,  1702,  1702,  1704,  1704,  1706,  1708,  1710,  1712,  1715,
    1719,  1719,  1720,  1720,  1724,  1724,  1736,  1736,  1741,  1745,
    1747,  1747,  1750,  1752,  1753,  1754,  1761,  1762,  1763,  1764,
    1767,  1768,  1769,  1770,  1774,  1779,  1784,  1788,  1791,  1795,
    1796,  1797,  1798,  1799,  1800,  1801,  1802,  1805,  1806,  1807,
    1838,  1843,  1845,  1847,  1847,  1854,  1858,  1858,  1861,  1862,
    1863,  1864,  1865,  1866,  1867,  1873,  1873,  1876,  1878,  1884,
    1886,  1892,  1900,  1900,  1903,  1904,  1905,  1906,  1907,  1908,
    1909,  1915,  1918,  1918,  1930,  1930,  1937,  1939,  1940,  1942,
    1943,  1945,  1947,  1948,  1949,  1950,  1955,  1961,  1967,  1968,
    1970,  1972,  1973,  1974,  1975,  1976,  1977,  1980,  1981,  1987,
    1995,  1995,  2000,  2000,  2016,  2016,  2018,  2018,  2026,  2026,
    2029,  2032,  2033,  2038,  2050,  2054,  2057,  2060,  2061,  2062,
    2063,  2064,  2069,  2074,  2080,  2085,  2085,  2085,  2099,  2102,
    2107,  2112,  2112,  2116,  2116,  2118,  2118,  2125,  2125,  2131,
    2131,  2147,  2150,  2164,  2166,  2168,  2170,  2172,  2174,  2176,
    2182,  2184,  2188,  2190,  2192,  2194,  2196,  2198,  2200,  2206,
    2220,  2224,  2236,  2238,  2239,  2240,  2241,  2245,  2246,  2247,
    2251,  2256,  2262,  2264,  2265,  2266,  2267,  2268,  2269,  2270,
    2271,  2272,  2277,  2277,  2281,  2281,  2284,  2290,  2298,  2304,
    2314,  2315,  2323,  2330,  2334,  2343,  2349,  2355,  2361,  2363,
    2373,  2385,  2395,  2405,  2409,  2412,  2419,  2426,  2432,  2496,
    2549,  2556,  2561,  2569,  2569,  2584,  2590,  2598,  2601,  2608,
    2620,  2630,  2636,  2644,  2650,  2657,  2663,  2668,  2673,  2680,
    2688,  2696,  2702,  2706,  2711,  2715,  2719,  2725,  2729,  2733,
    2737,  2741,  2745,  2749,  2756,  2763,  2763,  2763,  2786,  2786,
    2786,  2807,  2807,  2807,  2811,  2811,  2811,  2814,  2814,  2814,
    2817,  2817,  2817,  2823,  2825,  2831,  2832,  2837,  2840,  2844,
    2845,  2848,  2853,  2859,  2863,  2867,  2870,  2875,  2878,  2881,
    2895,  2895,  2895,  2908,  2911,  2924,  2924,  2924,  2924,  2953,
    2953,  2953,  2973,  2973,  2975,  2976,  2979,  2980,  2983,  2983,
    2989,  2989,  2996,  2997,  3000,  3001,  3004,  3004,  3010,  3010,
    3017,  3020,  3022,  3023,  3027,  3028,  3031,  3031,  3034,  3035,
    3038,  3039,  3042,  3042,  3048,  3048,  3053,  3053,  3058,  3058,
    3063,  3063,  3078,  3093,  3095,  3096,  3097,  3098,  3099,  3102,
    3102,  3105,  3107,  3110,  3112,  3114,  3115,  3116,  3118,  3120,
    3122,  3124,  3128,  3135,  3137,  3143,  3148,  3153,  3158,  3158,
    3161,  3164,  3168,  3173,  3176,  3183,  3183,  3185,  3191,  3195,
    3196,  3198,  3200,  3202,  3204,  3208,  3217,  3217,  3223,  3225,
    3226,  3227,  3228,  3229,  3230,  3231,  3232,  3233,  3234,  3235,
    3236,  3237,  3238,  3239,  3240,  3241,  3242,  3243,  3244,  3245,
    3246,  3247,  3248,  3249,  3250,  3251,  3252,  3253,  3254,  3255,
    3256,  3257,  3258,  3259,  3260,  3261,  3262,  3263,  3275,  3287,
    3293,  3294,  3298,  3303,  3309,  3313,  3317,  3323,  3327,  3331,
    3337,  3337,  3345,  3346,  3350,  3350,  3354,  3355,  3358,  3361,
    3361,  3364,  3366,  3366,  3369,  3371,  3371,  3372,  3374,  3374,
    3380,  3380,  3393,  3393,  3393,  3397,  3403,  3403,  3416,  3416,
    3420,  3426,  3426,  3430,  3431,  3442,  3443,  3445,  3447,  3452,
    3452,  3454,  3454,  3461,  3461,  3467,  3467,  3472,  3472,  3478,
    3478,  3483,  3483,  3488,  3488,  3493,  3493,  3498,  3498,  3505,
    3507,  3514,  3516,  3520,  3522,  3530,  3532,  3538,  3540,  3547,
    3549,  3558,  3563,  3568,  3569,  3570,  3573,  3573,  3583,  3589,
    3594,  3594,  3604,  3610,  3611,  3612,  3613,  3616,  3616,  3621,
    3621,  3623,  3627,  3627,  3629,  3633,  3633,  3636,  3637,  3640,
    3640,  3645,  3645,  3648,  3649,  3650,  3651,  3652,  3653,  3654,
    3655,  3656,  3657,  3658,  3659,  3660,  3661,  3662,  3666,  3669,
    3683,  3683,  3683,  3710,  3714,  3720,  3726,  3732,  3739,  3750,
    3769,  3769,  3769,  3780,  3782,  3784,  3785,  3788,  3794,  3795,
    3796,  3797,  3798,  3799,  3800,  3801,  3802,  3803,  3804,  3807,
    3807,  3807,  3810,  3810,  3818,  3818,  3818,  3818,  3818,  3850,
    3863,  3863,  3863,  3885,  3892,  3892,  3897,  3902,  3903,  3917,
    3919,  3922,  3922,  3922,  3922,  3925,  3925,  3936,  3941,  3963,
    3963,  3963,  3963,  3998,  3998,  4006,  4015,  4015,  4024,  4024,
    4038,  4038,  4051,  4051,  4053,  4054,  4056,  4057,  4060,  4061,
    4062,  4064,  4069,  4074,  4079,  4082,  4083,  4086,  4087,  4090,
    4091,  4100,  4100,  4100,  4116,  4117,  4121,  4121,  4132,  4132,
    4144,  4147,  4151,  4155,  4160,  4163,  4165,  4166,  4167,  4168,
    4172,  4172,  4174,  4174,  4177,  4186,  4209,  4210,  4213,  4216,
    4221,  4260,  4261,  4262,  4265,  4279,  4291,  4291,  4295,  4296,
    4302,  4355,  4360,  4368,  4373,  4381,  4387,  4409,  4412,  4413,
    4451,  4452,  4455,  4457,  4460,  4514,  4518,  4521,  4526,  4538,
    4544,  4553,  4553,  4556,  4557,  4561,  4562,  4563,  4566,  4569,
    4575,  4581,  4585,  4592,  4597,  4604,  4607,  4613,  4615,  4615,
    4615,  4618,  4630,  4636,  4644,  4647,  4660,  4668,  4669,  4672,
    4673,  4676,  4683,  4687,  4694,  4695,  4700,  4704,  4704,  4708,
    4708,  4712,  4713,  4716,  4724,  4728,  4734,  4735,  4737,  4739,
    4743,  4743,  4744,  4748,  4756,  4758,  4762,  4764,  4766,  4779,
    4781,  4782,  4784,  4787,  4790,  4793,  4796,  4799,  4802,  4806,
    4810,  4814,  4817,  4821,  4824,  4825,  4826,  4829,  4832,  4835,
    4838,  4841,  4844,  4847,  4863,  4871,  4871,  4873,  4880,  4887,
    4899,  4899,  4919,  4925,  4926,  4930,  4931,  4933,  4934,  4936,
    4936,  4944,  4952,  4952,  4962,  4964,  4967,  4967,  4971,  4971,
    4983,  4988,  4993,  4998,  5008,  5008,  5012,  5015,  5015,  5017,
    5017,  5017,  5017,  5033,  5040,  5042,  5045,  5049,  5049,  5051,
    5051,  5055,  5055,  5058,  5058,  5061,  5061,  5064,  5064,  5067,
    5067,  5082,  5082,  5102,  5103,  5104,  5105,  5106,  5107,  5109,
    5109,  5115,  5115,  5118,  5118,  5128,  5129,  5130,  5137,  5149,
    5150,  5153,  5154,  5157,  5160,  5160,  5165,  5169,  5174,  5179,
    5181,  5182,  5185,  5187,  5188,  5189,  5193,  5203,  5205,  5209,
    5213,  5218,  5223,  5231,  5238,  5247,  5254,  5261,  5268,  5275,
    5284,  5284,  5286,  5286,  5288,  5290,  5291,  5292,  5293,  5294,
    5295,  5296,  5297,  5298,  5301,  5301,  5304,  5305,  5306,  5307,
    5310,  5310,  5313,  5313,  5315,  5317,  5318,  5319,  5320,  5321,
    5322,  5323,  5325,  5326,  5327,  5328,  5330,  5331,  5332,  5333,
    5335,  5336,  5337,  5338,  5339,  5340,  5341,  5342,  5346,  5352,
    5359,  5368,  5368,  5368,  5368,  5368,  5368,  5406,  5409,  5417,
    5429,  5430,  5434,  5434,  5434,  5434,  5434,  5434,  5470,  5473,
    5473,  5473,  5473,  5491,  5493,  5494,  5495,  5500,  5502,  5504,
    5508,  5512,  5519,  5524,  5525,  5526,  5530,  5536,  5539,  5539,
    5539,  5540,  5540,  5540,  5544,  5546,  5551,  5552,  5556,  5558,
    5559,  5562,  5564,  5568,  5570,  5575,  5577,  5590,  5592,  5593,
    5594,  5595,  5596,  5597,  5598,  5599,  5602,  5605,  5610,  5611,
    5616,  5617,  5628,  5641,  5646,  5647,  5652,  5660,  5662,  5663,
    5666,  5668,  5671,  5671,  5678,  5680,  5686,  5686,  5690,  5690,
    5694,  5694,  5694,  5696,  5706,  5706,  5713,  5713,  5716,  5719,
    5720,  5725,  5727,  5731,  5733,  5737,  5739,  5742,  5742,  5742,
    5757,  5762,  5769,  5772,  5772,  5786,  5789,  5789,  5804,  5807,
    5809,  5811,  5813,  5815,  5817,  5822,  5832,  5837,  5842,  5844,
    5848,  5850,  5851,  5854,  5855,  5856,  5859,  5863,  5870,  5872,
    5877,  5891,  5891,  5896,  5901,  5907,  5908,  5911,  5912,  5916,
    5923,  5930,  5934,  5944,  5945,  5949,  5956,  5961,  5962,  5966,
    5969,  5972,  5974,  5978,  5979,  5980,  5981,  5985,  5986,  5990,
    5992,  5996,  5998,  6002,  6004,  6008,  6013,  6014,  6018,  6020,
    6024,  6025,  6029,  6035,  6040,  6045,  6049,  6051,  6055,  6057,
    6062,  6065,  6069,  6071,  6076,  6078,  6079,  6083,  6086,  6091,
    6096,  6097,  6100,  6101,  6105,  6108,  6110,  6111,  6116,  6121,
    6126,  6130,  6132,  6136,  6138,  6146,  6152,  6157,  6159,  6163,
    6168,  6172,  6174,  6178,  6180,  6181,  6184,  6185,  6190,  6190,
    6193,  6205,  6206,  6209,  6210,  6213,  6214,  6218,  6220,  6224,
    6226,  6230,  6232,  6236,  6238,  6243,  6245,  6249,  6252,  6256,
    6258,  6259,  6261,  6265,  6267,  6274,  6279,  6283,  6288,  6291,
    6293,  6295,  6300,  6302,  6306,  6307,  6311,  6314,  6316,  6318,
    6320,  6322,  6327,  6329,  6330,  6331,  6332,  6333,  6334,  6335,
    6336,  6337,  6341,  6343,  6344,  6345,  6347,  6348,  6349,  6350,
    6358,  6360,  6361,  6364,  6366,  6370,  6373,  6374,  6375,  6377,
    6378,  6379,  6380,  6382,  6383,  6385,  6386,  6388,  6389,  6390,
    6391,  6393,  6397,  6398,  6401,  6404,  6405,  6406,  6407,  6411,
    6415,  6419,  6423,  6428,  6431,  6432,  6436,  6438,  6442,  6447,
    6448,  6449,  6452,  6457,  6462,  6471,  6476,  6477,  6478,  6479,
    6480,  6482,  6484,  6486,  6488,  6491,  6494,  6498,  6499,  6503,
    6504,  6508,  6508,  6508,  6508,  6508,  6508,  6508,  6509,  6509,
    6509,  6509,  6509,  6509,  6509,  6512,  6512,  6512,  6512,  6512,
    6512,  6512,  6513,  6513,  6513,  6513,  6513,  6513,  6513,  6515,
    6516,  6519,  6528,  6528,  6534,  6534,  6540,  6540,  6546,  6546,
    6556,  6557,  6558,  6561,  6561,  6564,  6565,  6566,  6570,  6572,
    6577,  6581,  6585,  6596,  6596,  6596,  6614,  6623,  6624,  6626,
    6635,  6636,  6640,  6641,  6646,  6649,  6650,  6655,  6660,  6665,
    6666,  6667,  6668,  6671,  6673,  6676,  6677,  6681,  6685,  6688,
    6690,  6692,  6694,  6696,  6697,  6698,  6699,  6700,  6701,  6702,
    6704,  6706,  6708,  6710,  6712,  6714,  6716,  6718,  6721,  6722,
    6724,  6725,  6728,  6736,  6741,  6741,  6745,  6745,  6750,  6750,
    6754,  6754,  6758,  6764,  6764,  6767,  6767,  6773,  6779,  6781,
    6782,  6785,  6787,  6790,  6791,  6793,  6800,  6810,  6812,  6819,
    6821,  6822,  6823,  6824,  6825,  6910,  6922,  6923,  6926,  6928,
    6929,  6930,  6933,  6935,  6936,  6939,  6960,  7045,  7047,  7049,
    7051,  7055,  7060,  7062,  7064,  7066,  7070,  7073,  7078,  7083,
    7087,  7096,  7097,  7101,  7112,  7112,  7112,  7135,  7135,  7138,
    7142,  7147,  7151,  7152,  7153,  7156,  7159,  7164,  7165,  7169,
    7172,  7177,  7181,  7186,  7190,  7195,  7199,  7202,  7206,  7209,
    7214,  7218,  7229,  7235,  7235,  7236,  7237,  7244,  7253,  7253,
    7254,  7256,  7257,  7258,  7259,  7260,  7261,  7262,  7263,  7264,
    7265,  7266,  7267,  7268,  7269,  7270,  7271,  7272,  7273,  7274,
    7275,  7276,  7277,  7278,  7279,  7280,  7281,  7282,  7283,  7284,
    7285,  7286,  7287,  7288,  7289,  7290,  7291,  7292,  7293,  7294,
    7295,  7296,  7297,  7298,  7299,  7300,  7301,  7302,  7303,  7304,
    7305,  7306,  7307,  7308,  7309,  7310,  7311,  7312,  7313,  7314,
    7315,  7316,  7317,  7318,  7319,  7320,  7321,  7322,  7323,  7324,
    7325,  7326,  7327,  7328,  7329,  7330,  7331,  7332,  7333,  7334,
    7335,  7336
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "NAME", "UMINUS", "COMMA", "OR", "AND", 
  "USING", "MATCHES", "POWER", "LESS_THAN", "GREATER_THAN", "EQUAL", 
  "GREATER_THAN_EQ", "LESS_THAN_EQ", "NOT_EQUAL", "MINUS", "PLUS", 
  "DIVIDE", "MULTIPLY", "MOD", "COMMAND", "NUMBER_VALUE", "CHAR_VALUE", 
  "INT_VALUE", "NAMED_GEN", "CLINE", "SQLLINE", "KW_CSTART", "KW_CEND", 
  "LOCAL_FUNCTION", "EVERY_ROW", "DOUBLE_PRECISION", "COUNT_MULTIPLY", 
  "NEWFORMATSHARED", "WAIT_FOR_KEY", "AT_TERMINATION_CALL", 
  "TO_MAIN_CAPTION", "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", 
  "TO_STATUSBOX", "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", 
  "IMPORT_DATATYPE", "UP_BY", "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", 
  "FIRST_PAGE_HEADER_SIZE", "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", 
  "DOWN_BY", "CLOSE_STATUSBOX", "ADD_CONSTRAINT", "DROP_CONSTRAINT", 
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
  "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", "SHARED", "SPACES", 
  "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", "AFTER", "KWLINE", 
  "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", "ASCII", "AUDIT", 
  "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", "COUNT", "DEFER", 
  "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", "FOUND", "GRANT", 
  "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", "MONEY", "MONTH", 
  "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", "PRINT_FILE", "PRINT", 
  "RIGHT", "SEMICOLON", "SLEEP", "TUPLE", "UNION", "WHERE", "WHILE", 
  "WHITE", "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", "FCALL", "CASE", 
  "CHAR", "CYAN", "DATE", "DESC", "DOWN", "TAB", "DROP", "ELSE", "EXEC", 
  "EXIT", "FREE", "FROM", "GOTO", "HELP_FILE", "LANG_FILE", "HELP", 
  "HIDE", "HOUR", "INTO", "LAST", "LEFT", "LIKE", "MAIN", "MENU", "MODE", 
  "MOVE", "NEED", "NEXT", "NOCR", "OPEN", "QUIT", "REAL", "ROWS", "SHOW", 
  "SIZE", "SKIP", "SOME", "STEP", "STOP", "TEMP", "TEXT", "THEN", "USER", 
  "VIEW", "WAIT", "WHEN", "WITH", "WORK", "YEAR", "KW_IS", "XSET", "ADD", 
  "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", "DBA", "DEC", "DIM", "FKEY", 
  "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", "XMIN", "NOT", "PAD", "PUT", 
  "RED", "ROW", "RUN", "SQL", "SUM", "TOP", "USE", "ATSIGN", "AS_TIFF", 
  "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", "BY", "DOT", "GO", "IF", 
  "IN", "OF", "ON", "TO", "UP", "FONT_NAME", "FONT_SIZE", 
  "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", "PAPER_SIZE_IS_A5", 
  "PAPER_SIZE_IS_A4", "PAPER_SIZE_IS_LETTER_L", "PAPER_SIZE_IS_LEGAL_L", 
  "PAPER_SIZE_IS_A5_L", "PAPER_SIZE_IS_A4_L", "FORMHANDLER", 
  "END_FORMHANDLER", "BEFORE_EVENT", "BEFORE_OPEN_FORM", "AFTER_EVENT", 
  "BEFORE_CLOSE_FORM", "BEFORE_ANY", "AFTER_ANY", "MENUHANDLER", 
  "END_MENUHANDLER", "BEFORE_SHOW_MENU", "DISABLE_PROGRAM", "DISABLE_ALL", 
  "BUTTONS", "CHECK_MENUITEM", "DISABLE_FORM", "DISABLE_MENUITEMS", 
  "DISABLE", "ENABLE_FORM", "ENABLE_MENUITEMS", "ENABLE", "KWFIELD", 
  "ICON", "MESSAGEBOX", "TO_DEFAULTS", "UNCHECK_MENUITEM", "BEFORE", 
  "INPUT", "END", "INT_TO_ID", "pause_screen_on_cmd", 
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
  "bef_c_field_list", "aft_c_field_list", "interval_expr", "defer_cmd", 
  "define_section", "define_multiple", "define_set", "@29", "def_part", 
  "define_ident", "@30", "def_part2", "@31", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "array_variable", "@32", 
  "@33", "assoc_open_bracket", "assoc_close_bracket", "number_arr_assoc", 
  "number_arr_list", "number_value_arr", "record_variable", "@34", "@35", 
  "@36", "link_to_pk_list", "link_to_pk", "dtype_ident", "dtype2", "@37", 
  "dtype", "like_var", "tab_name", "col_name", "datetime_qual", 
  "interval_qual", "dtime_start", "@38", "dtime_val", "dtime_end", "@39", 
  "opt_frac", "opt_unit_size", "dtfrac", "int_start", "@40", 
  "int_start_unit", "int_end", "op_equal", "dim_section", "@41", 
  "dim_dtype", "dim_like_var", "dim_array_variable", "@42", "@43", 
  "dim_record_variable", "@44", "@45", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@46", "@47", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@48", "@49", "@50", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "report_only_expr", 
  "@51", "and_or_expr", "inexpr_list", "in_expr", "null_expr", 
  "string_match_expr", "clip_expr", "using_expr", "math_expr", 
  "comparison_expr", "reset_cnt", "function_call_expr2", "@52", "@53", 
  "@54", "@55", "function_callb", "@56", "@57", "@58", "@59", "@60", 
  "@61", "@62", "@63", "function_call_expr", "builtin_expr", 
  "builtin_funcs", "pdf_expr", "for_cmd", "@64", "@65", "for_step", 
  "foreach_cmd", "@66", "@67", "@68", "formhandler_def", "@69", "@70", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@71", 
  "@72", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@73", "@74", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@75", "@76", "@77", 
  "@78", "@79", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "setident", "unsetident", "field_name2", "cvariable", 
  "real_number", "reserved_word", "goto_cmd", "check_menu_cmd", 
  "menu_item_list", "menu_item", "uncheck_menu_cmd", "disable_cmd", 
  "enable_cmd", "msg_box_cmd", "@80", "op_disable_msg", "gm_disable_msg", 
  "op_returning_msg", "gm_returning_msg", "op_caption", "gm_caption", 
  "op_icon", "gm_icon", "op_buttons", "gm_buttons", "op_def_but", 
  "if_cmd", "@81", "op_else", "@82", "import_m", "op_import", "init_cmd", 
  "@83", "init_tab_list", "init_tab", "end_input", "opt_defs", 
  "field_commands", "field_command", "@84", "@85", "@86", "@87", "@88", 
  "@89", "@90", "@91", "@92", "a_ins_or_delete_row", "a_ins_or_delete", 
  "b_ins_or_delete_row", "b_ins_or_delete", "bef_field_list", 
  "aft_field_list", "next_field_cmd", "next_form_cmd", "next_field", 
  "input_cmd", "@93", "inp_rest", "@94", "scroll_cmd", "up_or_down", 
  "op_help", "on_key_command", "@95", "key_val", "@96", "accept_key", 
  "single_key_val", "@97", "key_do", "key_value_list", "key_value", "@98", 
  "key_value_1", "label_cmd", "let_cmd", "@99", "@100", "op_expr_null", 
  "linked_cmd", "linked_del_cmd", "linked_upd_cmd", "locate_cmd", 
  "module", "@101", "@102", "func_main_def", "func_or_main2", 
  "at_term_cmd", "func_or_main", "op_code", "ldeffunction", "func_def", 
  "@103", "@104", "@105", "@106", "end_func_command", "main_def", "@107", 
  "@108", "return_cmd", "op_fgl_expr_list", "db_section", 
  "globals_section", "actual_globals_section", "xglobals_entry", 
  "globals_entry", "@109", "glob_section", "mem_func_def", "@110", "@111", 
  "@112", "menu_cmd", "@113", "end_menu_command", "menu_block_command", 
  "@114", "@115", "@116", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@117", "@118", "menu_handler_elements", 
  "menu_handler_element", "@119", "@120", "message_cmd", "msg_next", 
  "gui_message", "msg_start", "@121", "op_msg_wait", "msg_wait", 
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
  "@122", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@123", "prompt_title", 
  "put_cmd", "@124", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "@125", "@126", "@127", 
  "finish_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@128", "@129", "@130", "@131", "@132", "@133", "@134", 
  "report_cmd", "need_command", "@135", "op_lines", "skip_command", 
  "@136", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@137", "@138", "@139", "@140", "@141", 
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
  "in_select_statement", "select_statement2", "select_statement21", 
  "sel_p2", "tmp_tabname", "opt_into_sel", "query_specification", 
  "subquery", "op_ad", "select_list", "value_expression_pls", 
  "column_specification", "value_expression", "value_expr_list", 
  "value_specification", "unload_cmd", "load_cmd", "opt_delim", 
  "char_or_var", "opt_col_list", "col_list", "simple_column_name", 
  "ufile", "opt_use", "conn_id", "misc_sql", "rename_stmt", "rentabname", 
  "rencolname", "unlock_stmt", "lock_stmt", "share_or_exclusive", 
  "units_qual", "var_ident", "var2", "var3", "aft_dot", "var_ident_ibind", 
  "whenever_cmd", "when_do", "label_goto", "function_name_when", 
  "while_cmd", "@167", "@168", "op_clr_fields", "op_to_defs", "clear_cmd", 
  "fld_list", "current_win_cmd", "window_type", "show_cmd", "op_mnfile", 
  "menu_name", "menu_handler", "hide_cmd", "move_cmd", "NAMED", 
  "commands", "all_commands", "command1", "commands_all", "@169", 
  "commands_all1", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,   637,   638,   639,   640,   641,   641,   642,   642,   643,
     644,   644,   644,   644,   644,   645,   645,   645,   645,   645,
     646,   646,   647,   647,   649,   648,   648,   650,   650,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   652,   652,   654,   653,   655,
     655,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     657,   658,   659,   658,   658,   658,   658,   658,   660,   661,
     658,   662,   663,   664,   658,   665,   666,   658,   667,   668,
     658,   669,   670,   671,   658,   672,   672,   673,   673,   673,
     674,   674,   675,   675,   676,   677,   677,   678,   678,   680,
     679,   681,   679,   682,   682,   683,   683,   684,   685,   686,
     685,   687,   688,   687,   690,   689,   692,   691,   693,   693,
     693,   693,   693,   693,   694,   695,   695,   696,   696,   697,
     698,   698,   699,   700,   702,   703,   701,   704,   704,   705,
     705,   706,   706,   707,   707,   707,   708,   708,   710,   709,
     711,   709,   712,   709,   713,   709,   714,   709,   715,   715,
     716,   716,   717,   717,   717,   717,   717,   717,   718,   718,
     719,   719,   720,   720,   722,   721,   721,   721,   723,   723,
     725,   724,   726,   726,   726,   726,   727,   726,   728,   728,
     728,   728,   729,   730,   730,   731,   731,   733,   732,   734,
     732,   735,   735,   736,   736,   737,   738,   738,   738,   739,
     741,   740,   742,   740,   743,   740,   744,   744,   745,   746,
     748,   747,   749,   749,   749,   749,   749,   749,   749,   749,
     749,   749,   749,   749,   749,   749,   749,   749,   749,   749,
     749,   749,   749,   749,   749,   749,   749,   749,   749,   749,
     750,   751,   752,   753,   753,   754,   756,   755,   757,   757,
     757,   757,   757,   757,   757,   759,   758,   760,   760,   761,
     761,   762,   764,   763,   765,   765,   765,   765,   765,   765,
     765,   766,   767,   767,   769,   768,   770,   770,   770,   770,
     770,   770,   770,   770,   770,   770,   770,   770,   770,   770,
     770,   770,   770,   770,   770,   770,   770,   770,   770,   771,
     773,   772,   774,   772,   776,   775,   777,   775,   778,   778,
     779,   780,   780,   781,   782,   782,   782,   782,   782,   782,
     782,   782,   783,   784,   785,   787,   788,   786,   789,   789,
     790,   791,   791,   792,   792,   794,   793,   795,   793,   796,
     793,   797,   797,   798,   798,   798,   798,   798,   798,   798,
     798,   798,   799,   799,   799,   799,   799,   799,   799,   799,
     800,   800,   801,   801,   801,   801,   801,   801,   801,   801,
     801,   801,   802,   802,   802,   802,   802,   802,   802,   802,
     802,   802,   803,   803,   804,   804,   805,   805,   806,   806,
     807,   807,   808,   809,   809,   810,   810,   810,   810,   810,
     810,   811,   811,   812,   812,   812,   812,   812,   812,   812,
     813,   813,   813,   814,   813,   815,   815,   816,   816,   817,
     817,   817,   817,   818,   818,   819,   819,   819,   819,   820,
     821,   822,   822,   822,   822,   822,   822,   823,   823,   823,
     823,   823,   823,   823,   824,   826,   827,   825,   828,   829,
     825,   831,   832,   830,   833,   834,   830,   835,   836,   830,
     837,   838,   830,   839,   839,   839,   839,   839,   839,   839,
     839,   840,   840,   841,   841,   841,   841,   842,   842,   842,
     844,   845,   843,   846,   846,   848,   849,   850,   847,   852,
     853,   851,   854,   854,   855,   855,   856,   856,   858,   857,
     859,   857,   860,   860,   861,   861,   863,   862,   864,   862,
     865,   866,   866,   866,   867,   867,   868,   868,   869,   869,
     870,   870,   872,   871,   873,   871,   874,   871,   875,   871,
     876,   871,   877,   878,   878,   878,   878,   878,   878,   879,
     879,   880,   881,   882,   883,   883,   883,   883,   883,   883,
     883,   883,   884,   885,   886,   887,   888,   889,   890,   890,
     891,   891,   892,   893,   893,   894,   894,   895,   896,   897,
     897,   897,   897,   897,   897,   898,   899,   899,   900,   900,
     900,   900,   900,   900,   900,   900,   900,   900,   900,   900,
     900,   900,   900,   900,   900,   900,   900,   900,   900,   900,
     900,   900,   900,   900,   900,   900,   900,   900,   900,   900,
     900,   900,   900,   900,   900,   900,   900,   900,   901,   902,
     903,   903,   904,   905,   906,   906,   906,   907,   907,   907,
     909,   908,   910,   910,   911,   911,   912,   912,   913,   914,
     914,   915,   916,   916,   917,   918,   918,   919,   920,   920,
     922,   921,   923,   924,   923,   925,   926,   926,   928,   927,
     927,   929,   929,   930,   930,   931,   931,   932,   932,   933,
     933,   935,   934,   936,   934,   937,   934,   938,   934,   939,
     934,   940,   934,   941,   934,   942,   934,   943,   934,   944,
     944,   945,   945,   946,   946,   947,   947,   948,   948,   949,
     949,   950,   951,   952,   952,   952,   954,   953,   955,   955,
     956,   955,   957,   958,   958,   958,   958,   959,   959,   961,
     960,   960,   963,   962,   964,   966,   965,   967,   967,   968,
     968,   970,   969,   971,   971,   971,   971,   971,   971,   971,
     971,   971,   971,   971,   971,   971,   971,   971,   972,   972,
     974,   975,   973,   976,   976,   977,   978,   979,   980,   980,
     982,   983,   981,   984,   984,   985,   985,   986,   987,   987,
     987,   987,   987,   987,   987,   987,   987,   987,   987,   988,
     988,   988,   989,   989,   991,   992,   993,   994,   990,   995,
     997,   998,   996,   999,  1000,  1000,  1001,  1002,  1002,  1003,
    1003,  1004,  1004,  1004,  1004,  1006,  1005,  1007,  1007,  1009,
    1010,  1011,  1008,  1013,  1012,  1014,  1016,  1015,  1017,  1015,
    1018,  1015,  1019,  1019,  1020,  1020,  1021,  1021,  1022,  1022,
    1022,  1023,  1024,  1025,  1026,  1026,  1026,  1027,  1027,  1028,
    1028,  1030,  1031,  1029,  1032,  1032,  1034,  1033,  1035,  1033,
    1036,  1037,  1037,  1037,  1037,  1038,  1038,  1038,  1038,  1038,
    1040,  1039,  1041,  1041,  1042,  1043,  1044,  1044,  1045,  1046,
    1046,  1046,  1046,  1046,  1047,  1048,  1049,  1049,  1050,  1050,
    1051,  1052,  1052,  1053,  1053,  1054,  1055,  1056,  1056,  1056,
    1056,  1056,  1057,  1057,  1058,  1059,  1059,  1060,  1060,  1061,
    1061,  1062,  1062,  1063,  1063,  1063,  1063,  1063,  1064,  1064,
    1065,  1066,  1066,  1067,  1068,  1069,  1069,  1070,  1071,  1071,
    1071,  1072,  1073,  1073,  1074,  1074,  1075,  1076,  1076,  1077,
    1077,  1078,  1079,  1080,  1081,  1081,  1082,  1083,  1083,  1084,
    1084,  1085,  1085,  1086,  1087,  1087,  1088,  1088,  1088,  1088,
    1089,  1089,  1089,  1090,  1091,  1091,  1092,  1092,  1092,  1093,
    1094,  1094,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
    1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
    1095,  1095,  1095,  1095,  1096,  1097,  1097,  1098,  1098,  1099,
    1101,  1100,  1102,  1103,  1103,  1104,  1104,  1105,  1105,  1107,
    1106,  1108,  1110,  1109,  1111,  1111,  1112,  1112,  1113,  1113,
    1114,  1114,  1114,  1114,  1115,  1115,  1116,  1117,  1117,  1119,
    1120,  1121,  1118,  1122,  1123,  1124,  1124,  1125,  1125,  1127,
    1126,  1128,  1126,  1129,  1126,  1130,  1126,  1131,  1126,  1132,
    1126,  1133,  1126,  1134,  1134,  1134,  1134,  1134,  1134,  1136,
    1135,  1137,  1137,  1139,  1138,  1138,  1138,  1138,  1138,  1140,
    1140,  1141,  1141,  1142,  1143,  1143,  1144,  1145,  1146,  1147,
    1147,  1147,  1148,  1148,  1148,  1148,  1149,  1150,  1150,  1151,
    1151,  1152,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
    1154,  1154,  1155,  1155,  1156,  1156,  1156,  1156,  1156,  1156,
    1156,  1156,  1156,  1156,  1157,  1157,  1158,  1158,  1158,  1158,
    1159,  1159,  1160,  1160,  1161,  1161,  1161,  1161,  1161,  1161,
    1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,
    1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1162,  1162,
    1162,  1164,  1165,  1166,  1167,  1168,  1163,  1169,  1169,  1170,
    1171,  1171,  1173,  1174,  1175,  1176,  1177,  1172,  1178,  1180,
    1181,  1182,  1179,  1183,  1183,  1183,  1183,  1184,  1184,  1184,
    1184,  1184,  1185,  1186,  1186,  1186,  1187,  1188,  1189,  1190,
    1188,  1191,  1192,  1188,  1193,  1193,  1194,  1194,  1195,  1195,
    1195,  1196,  1196,  1197,  1197,  1198,  1198,  1199,  1199,  1199,
    1199,  1199,  1199,  1199,  1199,  1199,  1199,  1199,  1200,  1200,
    1201,  1201,  1202,  1203,  1204,  1204,  1204,  1205,  1205,  1205,
    1206,  1206,  1207,  1207,  1208,  1209,  1210,  1210,  1211,  1211,
    1212,  1212,  1212,  1213,  1215,  1214,  1217,  1216,  1216,  1218,
    1218,  1219,  1219,  1220,  1220,  1221,  1221,  1223,  1224,  1222,
    1225,  1225,  1226,  1227,  1226,  1228,  1229,  1228,  1230,  1230,
    1230,  1230,  1230,  1230,  1230,  1231,  1232,  1233,  1234,  1234,
    1235,  1236,  1236,  1237,  1237,  1237,  1238,  1239,  1240,  1240,
    1241,  1243,  1242,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1245,  1246,  1246,  1247,
    1247,  1248,  1248,  1249,  1249,  1249,  1249,  1250,  1250,  1251,
    1251,  1252,  1252,  1253,  1253,  1254,  1255,  1255,  1256,  1256,
    1257,  1257,  1258,  1259,  1260,  1261,  1262,  1262,  1263,  1263,
    1264,  1264,  1265,  1265,  1266,  1266,  1266,  1267,  1267,  1268,
    1269,  1269,  1270,  1270,  1271,  1271,  1271,  1271,  1272,  1273,
    1274,  1275,  1275,  1276,  1276,  1277,  1278,  1279,  1279,  1280,
    1281,  1282,  1282,  1283,  1283,  1283,  1284,  1284,  1285,  1285,
    1286,  1287,  1287,  1288,  1288,  1289,  1289,  1290,  1290,  1291,
    1291,  1292,  1292,  1293,  1293,  1294,  1294,  1295,  1295,  1296,
    1296,  1296,  1297,  1298,  1298,  1299,  1300,  1301,  1302,  1302,
    1302,  1302,  1303,  1303,  1304,  1304,  1305,  1305,  1305,  1305,
    1305,  1305,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,
    1306,  1306,  1307,  1307,  1307,  1307,  1308,  1308,  1308,  1308,
    1309,  1309,  1309,  1310,  1310,  1311,  1311,  1311,  1311,  1311,
    1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,
    1311,  1311,  1312,  1312,  1313,  1313,  1313,  1313,  1313,  1314,
    1315,  1316,  1317,  1317,  1317,  1317,  1318,  1319,  1320,  1321,
    1321,  1321,  1322,  1322,  1322,  1323,  1324,  1324,  1324,  1324,
    1324,  1324,  1324,  1324,  1324,  1325,  1326,  1327,  1327,  1328,
    1328,  1329,  1329,  1329,  1329,  1329,  1329,  1329,  1330,  1330,
    1330,  1330,  1330,  1330,  1330,  1331,  1331,  1331,  1331,  1331,
    1331,  1331,  1332,  1332,  1332,  1332,  1332,  1332,  1332,  1333,
    1333,  1334,  1336,  1335,  1337,  1335,  1338,  1335,  1339,  1335,
    1340,  1340,  1340,  1341,  1341,  1342,  1342,  1342,  1343,  1343,
    1344,  1344,  1345,  1347,  1348,  1346,  1349,  1350,  1350,  1351,
    1352,  1352,  1352,  1352,  1353,  1354,  1354,  1355,  1356,  1357,
    1357,  1357,  1357,  1358,  1358,  1359,  1359,  1360,  1361,  1361,
    1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,
    1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1362,  1362,
    1363,  1363,  1364,  1365,  1366,  1366,  1367,  1367,  1368,  1368,
    1369,  1369,  1370,  1371,  1371,  1372,  1372,  1373,  1374,  1374,
    1374,  1375,  1375,  1376,  1377,  1378,  1379,  1380,  1380,  1381,
    1381,  1381,  1381,  1381,  1381,  1382,  1383,  1383,  1384,  1384,
    1384,  1384,  1385,  1385,  1385,  1386,  1386,  1387,  1387,  1387,
    1387,  1387,  1387,  1387,  1387,  1387,  1388,  1388,  1388,  1388,
    1388,  1389,  1389,  1390,  1392,  1393,  1391,  1394,  1394,  1395,
    1395,  1396,  1396,  1396,  1396,  1396,  1396,  1397,  1397,  1398,
    1398,  1399,  1399,  1400,  1400,  1401,  1401,  1402,  1403,  1404,
    1405,  1405,  1406,  1407,  1407,  1408,  1409,  1409,  1411,  1410,
    1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1412
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     1,     5,     1,     1,     1,     1,     3,     1,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     0,     5,     6,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     5,     1,
       3,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     0,     7,     4,     6,     1,     6,     0,     0,
       9,     0,     0,     0,     8,     0,     0,    10,     0,     0,
       7,     0,     0,     0,    14,     0,     2,     0,     2,     1,
       0,     1,     1,     3,     1,     1,     1,     1,     3,     0,
       6,     0,     5,     1,     2,     1,     2,     1,     0,     0,
       3,     0,     0,     3,     0,     4,     0,     4,     2,     2,
       2,     1,     2,     2,     3,     1,     1,     1,     2,     1,
       1,     2,     1,     1,     0,     0,     5,     7,     8,     0,
       2,     1,     3,     1,     3,     3,     1,     2,     0,     4,
       0,     4,     0,     3,     0,     3,     0,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     0,     3,     1,     1,     1,     3,
       0,     2,     4,     4,     4,     2,     0,     4,     1,     1,
       1,     2,     1,     1,     3,     0,     1,     0,     7,     0,
      12,     1,     1,     1,     1,     1,     5,     3,     1,     1,
       0,     4,     0,     5,     0,     7,     1,     3,     1,     1,
       0,     2,     1,     1,     1,     4,     4,     6,     1,     2,
       1,     1,     1,     1,     4,     6,     1,     4,     6,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       4,     1,     1,     0,     3,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     0,     2,     0,     3,     0,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     1,     0,     5,     1,     1,     1,     4,
       4,     6,     1,     1,     1,     1,     4,     6,     1,     4,
       6,     1,     1,     1,     1,     1,     2,     2,     1,     4,
       0,     7,     0,    12,     0,     4,     0,     5,     1,     3,
       2,     1,     3,     1,     0,     2,     2,     1,     2,     5,
       4,     2,     4,     5,     3,     0,     0,    11,     0,     3,
       1,     0,     2,     1,     2,     0,     3,     0,     3,     0,
       3,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     2,     1,     1,     3,     4,
       4,     2,     2,     2,     2,     1,     1,     1,     3,     1,
       2,     2,     1,     0,     3,     2,     2,     1,     3,     4,
       4,     5,     5,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     0,     0,     6,     0,     0,
       6,     0,     0,     6,     0,     0,     6,     0,     0,     6,
       0,     0,     6,     1,     4,     4,     4,     4,     4,     1,
       1,     1,     1,     4,     4,     4,     4,     2,     2,     2,
       0,     0,    11,     0,     2,     0,     0,     0,     8,     0,
       0,    10,     0,     1,     0,     1,     1,     2,     0,     3,
       0,     3,     0,     1,     1,     2,     0,     3,     0,     3,
       3,     1,     4,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     0,     3,     0,     3,     0,     4,     0,     4,
       0,     4,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     4,     6,     4,     3,     6,
       3,     6,     1,     1,     1,     1,     1,     1,     0,     2,
       3,     1,     3,     1,     4,     1,     1,     0,     0,     1,
       4,     3,     6,     3,     6,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     3,     1,     2,     2,     2,     4,     2,     2,     4,
       0,     8,     0,     1,     1,     1,     0,     1,     2,     0,
       1,     2,     0,     1,     2,     0,     1,     3,     0,     2,
       0,     7,     0,     0,     3,     5,     0,     2,     0,     5,
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
       0,     0,    10,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     0,     0,     0,     0,    13,     1,
       0,     0,     6,     3,     0,     1,     2,     0,     1,     1,
       2,     1,     1,     1,     1,     0,     3,     2,     1,     0,
       0,     0,    14,     0,     5,     1,     0,     3,     0,     7,
       0,     5,     1,     2,     0,     1,     1,     1,     0,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     0,     0,     7,     1,     2,     0,     3,     0,     4,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     0,     1,     1,     1,     1,     2,     3,     2,
       5,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       2,     3,     6,     1,     3,     1,     1,     1,     4,     7,
       1,     1,     1,     1,     2,     0,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     3,     1,     1,     1,     3,     2,     0,     1,
       1,     4,     1,     3,     1,     3,     7,     0,     7,     0,
       6,     3,     1,     3,     1,     2,     5,     0,     7,     0,
       2,     0,     1,     5,     2,     5,     0,     5,     6,     4,
       0,     1,     1,     4,     0,     2,     0,     5,     4,     2,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     2,     4,     1,
       0,    10,     5,     0,     1,     0,     2,     1,     2,     0,
       3,     1,     0,     4,     0,     2,     1,     3,     1,     1,
       3,     4,     4,     2,     1,     1,     1,     0,     1,     0,
       0,     0,    10,     2,     2,     2,     2,     1,     2,     0,
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
       2,     0,     0,     0,     0,     0,    14,     0,     2,     2,
       0,     1,     0,     0,     0,     0,     0,    14,     2,     0,
       0,     0,    10,     0,     1,     3,     3,     2,     4,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     0,     0,
       7,     0,     0,     8,     0,     1,     1,     3,     2,     2,
       1,     1,     3,     1,     1,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     6,     6,     0,     1,
       0,     1,     2,     5,     0,     2,     2,     1,     7,     1,
       5,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     0,     5,     0,     5,     1,     0,
       3,     1,     3,     1,     3,     1,     1,     0,     0,     5,
       2,     1,     0,     0,     3,     0,     0,     3,     1,     1,
       1,     1,     1,     2,     2,     4,     3,     3,     1,     3,
       2,     1,     1,     0,     1,     1,     1,     1,     0,     1,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     0,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     0,     3,     1,
       3,     1,     3,     1,     1,     6,     0,     3,     1,     3,
       0,     1,     4,     5,     2,     1,     1,     4,     1,     3,
       4,     4,     1,     3,     1,     1,     1,     2,     1,     4,
       0,     1,     0,     2,     1,     1,     1,     4,     3,     1,
       1,     1,     2,     1,     1,     2,     2,     1,     3,     2,
       2,     1,     3,     1,     2,     4,     1,     2,     1,     3,
       4,     0,     1,     0,     1,     0,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     2,     2,     4,     3,     0,
       1,     1,     1,     1,     1,     2,     1,     1,     5,     3,
       5,     3,     1,     3,     0,     1,     3,     3,     3,     3,
       6,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     1,     5,     5,     1,
       1,     1,     4,     1,     4,     1,     7,     1,     1,     1,
       4,     6,     0,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     0,
       3,     5,     2,     5,     4,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     8,     0,     9,     0,     7,     0,     9,
       0,     1,     2,     1,     3,     1,     3,     5,     1,     1,
       1,     1,     2,     0,     0,     8,     5,     1,     1,     7,
       0,     3,     1,     3,     1,     0,     2,     5,     7,     0,
       1,     1,     1,     1,     3,     1,     2,     1,     3,     2,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     4,     6,     3,     1,     3,
       0,     1,     5,     7,     0,     2,     1,     1,     0,     3,
       1,     3,     1,     1,     1,     0,     3,     1,     1,     1,
       1,     4,     6,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       3,     5,     1,     1,     1,     1,     3,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     1,     3,     2,     1,
       2,     1,     2,     1,     0,     0,     6,     0,     2,     0,
       1,     1,     2,     2,     2,     4,     3,     1,     3,     1,
       2,     5,     2,     2,     5,     0,     2,     1,     1,     2,
       6,     6,     1,     0,     1,     2,     1,     2,     0,     2,
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

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
     789,     0,     0,     0,     0,     0,     0,     0,     0,  1650,
       0,   790,   666,   791,   132,   129,     0,   125,   127,   126,
     130,  1656,   577,   577,  1659,     0,  1655,  1652,  1649,  1647,
    1648,  1654,  1653,  1651,   577,   789,   124,   128,   131,   609,
     594,   607,   613,   593,   605,   588,   622,   625,   591,   623,
     600,   604,   615,   627,   624,   626,   616,   598,   596,   621,
     602,   601,   589,   590,   592,   595,   606,   618,   597,   608,
     612,   614,   620,   603,   617,   619,   599,   610,   611,  1663,
       0,   571,  1660,   577,  1661,  1658,   577,   667,   807,  1692,
     578,  1662,  1657,   577,   815,   812,   814,   789,   808,   809,
     811,   813,   570,  1530,  1529,   806,   170,   770,   810,   549,
     577,   174,   577,     0,   171,   172,   176,   818,   882,   550,
     816,   585,   875,   577,   876,   883,   881,   177,   170,   284,
     180,   877,   817,   173,   577,   577,   890,   888,   889,   879,
       0,   789,     0,   180,   175,   192,   577,   178,   193,   220,
     887,   886,     0,    21,    20,    12,   577,   895,     0,    14,
       0,   893,   577,   878,   771,     0,   282,   180,   186,   181,
     180,   185,   219,   577,   884,     0,    16,    15,    18,    17,
      19,   577,    13,   577,   891,     0,   773,   316,   302,   195,
     253,   272,   293,   295,   292,     0,   314,     0,   301,   294,
     298,   304,   288,   303,   180,   305,   285,   308,   286,   287,
     283,     0,   179,     0,   192,   194,   243,   244,   232,   212,
     240,   195,   214,   253,   272,   230,   233,   228,     0,   210,
       0,   239,   231,   236,   242,   224,   241,   180,   245,   180,
     222,   223,   221,   248,   249,    10,    11,   894,   577,   880,
     793,  1162,   577,   577,   792,   133,  1151,   800,   577,   577,
     786,   788,   785,   787,   772,   774,   775,   794,   778,   779,
     780,   783,   781,   782,   784,   577,   196,     0,   306,     0,
       0,   307,     0,     0,     0,     0,   577,     0,     0,     0,
     251,     0,   586,   182,   184,     0,   183,     0,   189,   188,
     187,   190,   180,     0,   180,   246,   247,     0,     0,   180,
       0,     0,     0,     0,   229,     0,   577,     0,     0,   577,
     170,   499,   851,   776,   577,     0,   201,   202,     0,   265,
     267,   262,   263,   259,   261,   258,   260,   257,     0,   267,
     278,   279,   275,   277,   274,   276,   269,     0,     0,     0,
     318,     0,   321,   323,   209,     0,   208,     0,     0,   180,
     587,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   892,     0,     0,   577,     0,   801,   170,   170,
       0,     0,     0,   254,     0,     0,   264,   281,   255,   280,
       0,   273,     0,   296,     0,   290,   577,   315,   577,   320,
     310,     0,     0,   299,   289,   252,   309,     0,     0,     0,
       0,   234,     0,   226,   211,   197,     0,   237,   225,   250,
    1163,     0,     0,  1152,  1698,   500,   852,   795,   317,   203,
     204,     0,   266,   271,     0,     0,     0,     0,   319,   322,
       0,   207,     0,   213,     0,   180,     0,     0,     0,     0,
     577,   665,   819,   577,     0,  1696,  1698,  1087,  1615,   789,
       0,   577,     0,   268,   270,   297,   291,     0,     0,   300,
       0,   218,     0,   216,   235,   227,   220,   238,   911,     0,
     906,   907,   577,     0,   802,  1697,  1088,  1695,   577,   577,
     577,   577,   577,  1679,   577,  1213,  1212,   577,  1214,   577,
     366,  1211,  1191,   577,     4,  1210,   367,   364,   577,   369,
     168,   454,  1065,     0,     0,  1220,   121,   363,   362,  1183,
     357,   577,  1206,  1671,   577,   368,   335,   577,     2,     1,
     577,   365,  1188,   577,   577,   358,   355,   370,   577,   577,
     577,   577,   577,  1208,   361,   577,   577,   577,   577,   577,
     577,   577,   577,  1207,   577,   577,   577,   169,  1185,   354,
     353,   577,   577,  1669,   577,   577,   134,  1184,   360,   359,
     577,   577,   356,   870,   454,   577,   495,     0,   577,   577,
     454,   577,   577,   577,   454,   577,  1160,   577,   577,  1069,
     577,  1664,   577,   101,   577,   577,   823,   577,   577,   577,
     577,   760,   577,   577,   577,     0,   577,   577,   577,   577,
     577,   577,   577,   640,   577,   577,  1700,  1701,  1702,  1703,
    1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,
    1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,
    1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,
    1744,  1745,  1746,   861,  1747,  1748,  1749,  1750,  1751,  1752,
    1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,
    1056,  1058,  1053,  1055,  1054,  1057,  1763,  1764,  1182,  1765,
    1186,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,
    1291,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1699,   504,
     577,   856,     0,   854,     0,     0,   311,   206,     0,   180,
     215,   198,   577,  1164,   577,     0,  1153,   777,  1673,   564,
       0,   120,     0,   577,  1639,  1638,   964,  1635,  1637,  1687,
       0,  1200,     0,  1196,  1205,     6,     0,     5,   577,  1680,
    1026,  1027,   577,  1121,  1120,  1068,  1119,  1067,   577,   577,
     415,   417,  1157,     0,     0,     0,     0,     0,     0,   613,
       0,   577,  1499,     0,     0,   627,   407,   577,   577,   616,
     406,   577,   595,   423,   618,   482,   617,     0,   619,     0,
       0,   577,     0,   402,  1221,     0,   373,   372,   379,   374,
     480,   473,   375,   377,   479,   378,   882,   416,   419,   422,
    1209,   481,  1617,  1215,   122,   577,  1033,   119,   577,   766,
      22,   566,   371,     0,   765,  1023,   767,     0,  1219,   845,
     844,   847,   843,   846,  1689,     0,   841,     0,   565,   937,
     842,  1683,     0,  1672,   118,   934,   668,   932,     0,   562,
    1670,  1667,  1674,   714,   713,     0,   715,   554,   711,     0,
     577,   947,   567,  1288,   577,   577,   999,   997,   577,   991,
     993,   992,   990,   989,   577,   577,   577,   988,   577,   741,
     577,   577,     0,     0,     0,     0,   577,   577,     0,     0,
       0,   978,   969,   970,     0,  1011,   400,    22,   392,  1677,
       0,  1669,   123,   563,   577,   758,   996,   995,  1161,  1159,
    1086,     0,  1606,  1607,  1087,  1173,  1087,  1070,  1071,  1074,
    1089,  1222,   577,     0,     0,     0,     0,     0,   577,     0,
     577,     0,    60,     0,   882,     0,    66,     0,    99,   542,
     628,   577,  1059,   954,  1063,     0,   577,  1012,  1177,     0,
    1066,   632,   629,   630,     0,   634,   635,     0,   637,   638,
     577,   633,   915,   917,   577,   577,   916,   716,   913,   677,
     909,   874,     0,   577,   577,     0,   644,   645,     0,     0,
     872,   868,   869,   865,   866,   867,   860,   864,   863,   577,
     577,   577,   577,   577,     0,   508,   510,   502,   505,   506,
     858,  1698,   853,   855,   796,   205,     0,     0,   217,   912,
     170,   908,   820,   170,     0,   578,   573,   577,  1636,   577,
     577,   966,   577,   577,  1199,  1198,   577,  1187,     0,  1472,
    1478,     0,     0,  1473,  1028,     0,    22,  1116,  1118,  1117,
     380,   381,   577,  1093,   458,   577,   577,   577,   577,     0,
     577,   577,   421,  1507,  1505,  1506,  1502,  1504,  1501,  1503,
    1495,     0,   577,     0,   577,     0,   420,     0,   413,   577,
     414,     0,     0,   464,   461,   470,   577,   467,   577,   577,
     405,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   162,   163,
     164,   165,   166,   167,   487,   488,   489,   434,   577,   577,
     433,   439,     0,   577,   385,   577,     0,   386,   376,   382,
     384,   387,   388,   389,   390,   391,   383,   412,   411,   455,
     577,   924,     0,     0,   340,    23,   334,   577,   577,  1020,
     577,   577,   577,   577,   577,   577,     0,   941,  1616,   577,
     577,   180,     0,   577,   577,  1669,   577,   577,   577,   577,
     577,   135,     0,   577,   951,   943,   944,   949,  1289,  1290,
     871,   324,   398,   577,   496,   547,   546,   544,   972,   548,
     977,   973,   976,   734,     0,   974,   975,   735,   982,   986,
     979,   980,   984,   985,   983,   981,   987,     0,   768,   577,
     577,     0,   395,   803,   396,   393,   394,   577,     0,     0,
     724,   723,   722,  1676,    22,   759,  1082,  1083,  1084,  1085,
    1079,  1077,  1174,  1091,  1076,  1072,   577,     0,  1073,  1665,
      78,   577,     0,   577,   577,    95,     0,    96,   577,     0,
     577,    71,   577,   577,   108,   103,     0,   850,     0,   849,
       0,   454,  1061,   577,   900,   901,   923,   896,   897,   761,
     921,  1014,  1179,   577,  1181,  1180,   660,   577,   577,   577,
     649,   677,   677,   675,   577,   577,   678,     0,    24,   648,
     651,     0,   658,   654,   873,   862,  1613,  1614,  1604,  1604,
       0,     0,  1531,   577,   180,  1243,   577,   577,  1244,  1286,
     180,   577,  1287,   577,  1569,   577,  1257,     0,  1305,  1303,
    1302,  1301,  1299,  1300,  1297,  1295,  1298,  1292,  1364,  1363,
    1293,  1294,  1304,  1540,  1296,  1620,  1619,  1618,  1698,  1698,
     521,   512,   503,     0,   507,  1698,   857,   170,   312,   199,
    1122,   170,  1100,   577,   572,     0,     0,   965,   577,     0,
     963,  1642,  1644,  1643,  1640,  1688,  1685,  1197,   577,   577,
    1192,   577,  1029,   332,  1158,    90,     0,     0,     0,     0,
    1569,     0,     0,     0,     0,     0,     0,     0,   408,     0,
       0,     0,     0,     0,   424,   577,   577,   577,     0,   577,
       0,     0,     0,   426,   425,   440,   435,   446,   449,   450,
     447,   453,   452,   451,   442,   441,   444,   443,   445,   436,
     438,   454,   448,   437,   454,    90,   418,   577,  1189,   956,
    1024,  1025,  1022,  1021,     0,   848,     0,     0,   551,     0,
       0,   577,   935,   933,     0,   670,   671,     0,     0,  1668,
    1675,     0,     0,   558,     0,   560,   712,     0,   139,   577,
     945,   952,     0,   577,   960,   577,   327,   577,   577,   577,
     577,    22,   998,  1265,     0,     0,   757,   746,   755,   756,
     744,   745,   748,   751,   747,   754,   750,   752,   753,   743,
     749,   742,   741,   971,   769,   401,   577,  1003,   577,  1678,
     725,   726,   351,   577,  1087,   577,  1090,  1075,  1698,    90,
       0,     0,     0,     0,   577,     0,   577,    61,    90,     0,
     114,   109,     0,   104,   577,   111,   105,   834,   826,   832,
       0,  1060,   577,  1062,  1064,     0,   577,   904,     0,   577,
       0,   577,  1013,  1178,  1698,   631,   636,   639,   652,   650,
     568,     0,   577,   577,   693,   731,   691,   687,   685,   729,
       0,     0,   717,     0,   679,   689,   914,   910,   577,     0,
       0,     0,   657,   577,     0,   577,   577,     0,     0,   577,
    1477,     0,  1359,  1360,  1625,  1326,  1381,   577,     0,  1623,
       0,     0,  1571,  1572,  1570,   577,     0,   577,  1309,  1315,
    1314,  1313,  1317,     0,  1310,  1311,   577,  1541,  1552,   509,
     511,   577,     0,   524,   516,   518,     0,   513,   514,   577,
     577,   532,   534,   577,     0,   530,   859,   797,     0,     0,
       0,  1148,  1165,   821,     0,  1154,  1148,   576,     0,   575,
     577,   931,     0,   577,   577,  1684,     3,     7,     9,  1478,
    1475,   577,  1474,   454,   459,    91,    92,    94,   476,   475,
     478,   474,   577,   410,   484,  1157,  1514,  1512,  1513,  1509,
    1511,  1508,  1510,  1500,   477,  1157,   483,   409,   485,   486,
    1157,   465,   462,   471,  1157,   468,  1157,  1157,  1157,   577,
       0,   577,     0,   456,     0,   577,   577,   953,   577,   577,
     577,   577,   577,     0,   577,   180,   669,   577,   555,   557,
     577,   577,   156,   154,   577,   577,   136,     0,   146,   152,
     677,   141,   143,   577,   950,   961,   962,     0,   399,   326,
     331,   553,   325,   577,   328,   333,  1266,   497,   545,   543,
     741,   736,   737,  1002,  1004,   577,   397,   352,  1080,  1078,
    1175,  1176,     0,    79,    64,  1169,     0,     0,     0,    97,
       0,     0,    72,    68,  1698,  1698,   107,   102,   116,   112,
       0,   106,   732,   835,   568,  1698,   825,   824,   833,   955,
     577,     0,   577,   922,   454,     0,     0,  1588,  1486,  1489,
    1589,  1497,  1487,  1586,   577,  1019,  1585,   595,   577,  1587,
       0,     0,     0,     0,  1639,  1488,  1015,  1016,  1584,  1494,
    1018,  1645,  1583,   662,   655,   653,     0,    22,   577,   707,
     681,   709,   683,  1698,  1698,  1698,  1698,   741,   702,   701,
     697,   699,   706,   705,   695,   703,   676,   680,  1698,   568,
      44,    42,    39,    33,    37,    41,    36,    29,    38,    32,
      35,    30,    40,    31,    43,    34,     0,    27,     0,   659,
    1605,   577,   577,  1602,  1557,  1558,  1550,  1536,  1551,     0,
       0,   577,   994,  1358,  1361,   577,     0,   577,   577,  1382,
    1276,  1249,  1628,  1627,  1626,   577,   577,  1553,  1573,  1575,
     577,   577,  1271,   577,  1272,  1268,  1269,  1270,  1261,  1258,
     577,   577,  1316,   577,     0,     0,  1545,  1542,  1543,   523,
     528,   577,   577,  1698,  1698,   501,   515,   538,   526,   540,
    1698,  1698,   536,   520,   531,   789,     0,   220,  1146,  1147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1145,     0,     0,  1133,  1134,  1135,  1132,  1137,  1138,
    1139,  1136,  1123,  1114,   577,     0,  1168,     0,   789,     0,
    1109,     0,     0,     0,     0,     0,     0,   577,  1101,  1102,
       0,  1034,   574,  1641,   577,     0,  1686,   577,     0,     0,
       0,   589,  1479,     0,  1201,  1346,  1345,  1344,  1204,  1203,
     577,     0,  1030,     0,   577,     0,  1096,  1095,  1094,     0,
       0,     0,  1097,     0,  1099,  1098,  1092,   427,     0,   430,
       0,   429,     0,     0,     0,   577,     0,  1216,  1691,  1690,
     552,   577,     0,    45,   577,   674,   673,   672,  1217,   577,
       0,   677,  1698,  1698,   148,   579,   158,   150,   160,   140,
     147,  1698,   577,     0,   577,     0,   577,     0,   577,  1698,
       0,   739,   568,   577,  1666,     0,    90,   577,    62,   577,
     577,   577,    75,     0,    90,   115,   110,  1698,  1698,   100,
     741,   836,   830,   838,   837,   827,   493,   885,   902,   903,
     898,   577,  1493,  1492,  1491,  1490,  1521,  1519,  1520,  1516,
    1518,  1515,  1517,  1496,     0,     0,  1436,     0,  1436,  1436,
    1436,  1436,   577,   577,   577,   577,   577,   577,  1629,  1630,
    1631,  1632,  1633,  1634,  1579,   577,   663,     0,   642,   656,
     569,   718,     0,   577,  1698,   577,  1698,   694,   692,   688,
     686,   730,     0,  1698,     0,  1698,   690,    22,     0,    25,
       0,  1608,  1569,  1540,   577,   577,  1549,  1532,  1548,  1362,
       0,  1328,     0,  1275,     0,   577,   616,   577,  1369,  1387,
    1389,  1391,  1435,  1434,  1433,  1432,  1393,     0,  1414,   577,
       0,  1624,     0,  1621,   577,  1565,  1576,     0,   577,  1224,
    1227,  1229,     0,  1232,  1234,  1274,  1273,  1262,  1260,     0,
    1319,     0,  1312,   577,   577,   577,   577,   525,   522,   517,
     519,   577,  1698,  1698,   533,   535,  1698,  1698,   313,   200,
    1140,  1141,  1142,  1144,  1127,  1125,  1124,  1128,  1129,  1126,
    1143,  1130,  1131,  1115,   928,  1150,   925,   577,     0,  1166,
    1698,  1113,  1112,  1107,  1105,  1104,  1108,  1106,  1110,  1111,
    1103,  1155,   968,   577,     8,   577,   577,   577,   577,     0,
    1482,   577,  1194,     0,  1468,  1466,  1453,  1455,  1451,     0,
    1450,     0,  1459,  1446,  1467,     0,  1458,  1443,  1449,  1465,
    1457,  1350,  1440,  1441,  1442,   577,   460,    93,   577,  1381,
    1560,   466,   463,   472,   469,   577,   432,   431,   457,   338,
    1190,     0,   577,  1682,     0,     0,   936,    46,     0,   559,
     561,   556,   727,   157,   155,   577,  1698,   577,   577,   577,
    1698,   153,   142,   577,   145,   144,   577,   942,   946,   330,
     577,  1267,     0,   741,   738,    22,  1081,    85,  1170,    67,
     577,     0,    98,    65,    90,    73,     0,   117,   113,   733,
    1698,   840,   568,   839,   577,   490,   577,   763,   764,   762,
       0,  1597,  1438,  1439,  1437,   577,   577,   577,   577,   577,
     577,  1598,     0,  1017,  1582,  1581,  1578,  1580,  1646,  1698,
     661,   646,   643,     0,   708,   682,   710,   684,   700,   698,
     704,   696,   719,    28,    26,   577,  1603,   577,  1537,  1538,
    1534,  1540,   577,  1327,   577,  1330,     0,  1396,   577,     0,
    1414,  1395,  1392,   577,   577,  1428,  1424,  1425,  1422,  1431,
    1430,  1423,  1426,  1427,  1429,   577,     0,  1415,     0,     0,
     577,     0,  1251,  1246,  1245,  1248,   577,  1574,   577,  1554,
     577,  1236,     0,   577,   577,  1223,   577,   577,  1263,  1259,
     577,  1318,   577,     0,  1546,  1544,   529,   527,   539,   541,
     537,     0,   930,   929,   927,   577,  1149,  1035,  1039,  1041,
     577,  1045,   577,  1043,  1047,  1036,  1037,     0,     0,     0,
     967,     0,  1335,  1338,     0,  1342,     0,     0,     0,  1202,
    1195,  1193,   577,     0,     0,     0,     0,     0,     0,     0,
       0,  1348,     0,  1351,  1352,   805,  1031,   577,  1370,  1371,
    1373,  1376,  1383,   577,     0,  1436,  1562,  1556,   428,     0,
      22,     0,   577,   959,   577,    47,   939,     0,    22,   159,
     149,     0,   581,   583,   161,   151,   727,     0,   329,   498,
     740,  1000,   577,    80,     0,    63,     0,    76,    85,    69,
     831,   828,   494,  1698,     0,  1528,  1526,  1527,  1523,  1525,
    1522,  1524,  1498,     0,   577,     0,     0,     0,     0,   577,
    1595,   664,   641,   647,   568,  1612,     0,  1610,  1565,  1540,
    1540,  1533,  1329,  1569,  1331,  1325,  1569,  1394,  1388,  1390,
    1398,  1600,  1411,  1600,  1409,  1417,  1416,   577,  1600,   577,
    1403,  1402,  1404,     0,  1400,  1401,  1419,  1418,   577,  1250,
       0,  1622,   920,  1566,   918,     0,   577,  1241,  1231,  1238,
    1242,  1240,   577,     0,  1225,  1226,  1233,  1235,   577,  1320,
    1323,  1307,  1321,  1324,   577,   799,   798,   926,  1698,  1698,
    1049,  1698,  1051,  1698,  1698,  1038,  1167,   822,  1156,     0,
     577,   577,  1341,  1340,  1332,     0,  1480,  1484,  1479,     0,
       0,     0,  1470,  1462,  1462,     0,     0,  1462,  1469,     0,
    1486,  1347,  1355,   577,  1354,     0,  1356,  1349,  1352,     0,
     577,  1374,   577,  1485,  1377,   577,  1384,  1385,  1564,  1194,
     577,   577,   577,   336,   577,   957,     0,     0,     0,   938,
     728,   137,   580,    22,   948,  1005,    86,  1171,    81,     0,
      74,    85,  1698,   491,   899,  1594,     0,  1590,  1591,  1592,
    1593,  1599,   720,   577,  1609,     0,  1539,  1535,   577,   577,
       0,  1601,  1412,     0,     0,     0,  1406,  1397,  1252,   577,
     577,  1560,     0,  1240,   577,  1237,     0,  1264,   577,  1308,
    1306,  1547,  1040,  1042,  1698,  1046,  1698,  1044,  1048,  1333,
    1339,  1343,     0,  1483,  1452,     0,  1454,     0,     0,     0,
       0,  1460,  1464,     0,  1444,  1334,  1336,   577,  1353,  1032,
    1378,     0,  1372,  1366,  1367,  1577,   577,  1386,  1380,  1563,
    1281,  1277,  1278,  1283,  1282,  1561,   339,   341,   958,  1681,
     577,   577,   577,   577,   577,   577,    52,     0,    51,     0,
      49,   577,   577,   138,  1009,  1001,     0,  1007,    85,    90,
      85,    70,   829,     0,  1596,    22,  1611,  1560,     0,     0,
    1600,  1410,  1408,   577,  1600,  1421,  1256,     0,  1253,  1255,
     919,  1555,  1230,  1239,   577,  1322,  1050,  1052,  1481,     0,
    1471,  1463,  1447,  1445,     0,  1448,   577,     0,   577,  1375,
     577,  1365,   577,  1285,  1284,  1280,   347,   345,   337,     0,
     343,   349,    54,    59,    56,    58,    55,    57,    53,     0,
      48,     0,   582,   584,  1698,  1006,  1008,  1172,    82,    77,
     492,   721,  1559,  1567,     0,  1413,  1420,  1405,  1407,   577,
    1247,     0,     0,  1461,     0,  1357,  1379,  1368,  1279,  1698,
    1698,   342,   344,  1698,    50,   577,  1010,     0,  1568,  1254,
    1228,  1456,  1337,   348,   346,   350,     0,    83,   940,    87,
      89,   577,    84,    88,     0,     0,     0
};

static const short yydefgoto[] =
{
     616,   617,   618,   619,   746,  1636,  1637,   157,   181,   158,
    1134,  1135,  1559,  1846,  2788,  2286,  2287,  2677,  2789,  2790,
     620,   932,  2320,  2054,  2691,  1508,  2053,  2528,  2324,  2689,
    1499,  2045,  2799,  2897,  2909,  2523,  2912,  1644,  1645,  1646,
    1236,  1748,   621,  1246,   937,  1244,  1515,  1757,  1512,  1755,
    1760,  2058,  1245,  1754,  1516,  2057,   622,    11,    16,    17,
      18,    19,    20,   261,   625,   860,  1448,  1161,  1706,  1710,
    1711,  1707,  1708,  2296,  2300,  2031,  2023,  2022,  2024,  2027,
    1117,   626,   113,   114,   115,   130,   144,   290,   146,   147,
     213,   300,   148,   149,   277,   240,   448,  1619,   328,   431,
    1006,   355,   356,   241,   309,   302,   304,   472,   473,   171,
     172,   173,   242,   243,  1434,   406,   278,   281,   279,   280,
     337,   383,   384,   386,   391,   434,   282,   283,   346,   388,
     211,   116,   142,   206,   207,   208,   440,  1618,   209,   286,
     275,   349,   350,   351,   352,  1461,   627,   628,   629,   630,
     815,  2777,  2500,  1136,  2848,  2849,  2850,  2890,  2889,  2893,
     631,   632,   633,   634,   793,  1118,  1203,  1204,  1205,  1171,
     895,  1172,   795,   796,   797,   798,   799,  1072,  1119,  1998,
    1120,  1121,  1122,  1123,  1124,  1125,  1126,   752,   800,  1415,
    2002,  1365,  1983,   801,  1386,  1990,  1385,  1989,  1389,  1993,
    1387,  1991,   802,   803,   804,   805,   635,  2533,  2803,  2335,
     636,   868,  1463,  2039,   262,   378,   459,  1331,   997,   998,
     999,  1328,  1329,  1606,  1607,  1608,  1903,  1904,  1332,  1333,
    1602,  1907,  1899,  1614,  1615,  1910,  1911,  2196,  2192,  2193,
     637,  1178,   117,  1429,  1430,  1722,   899,   848,   902,   728,
     837,   820,   861,  1807,   118,   729,  1015,  1628,    80,   102,
    2026,   119,   807,    81,   638,   639,   952,   953,   640,   641,
     642,   643,   960,  2361,   981,  2552,   982,  1538,   983,  1804,
     984,  2108,   985,  1562,   644,  1534,  2107,  2359,   263,    35,
     645,  1152,  1435,  1436,  1552,  1277,  1553,  1554,  2114,  2116,
    1816,  1815,  1828,  1814,  1813,  2125,  2123,  1820,  1821,  1824,
    1825,  1810,  1812,   646,   647,   858,   648,  1273,   967,  2805,
     649,  1212,  2508,  1555,  1817,  1763,  2060,   891,  1188,  1482,
    1731,  2040,  1732,  1184,  1481,   650,   651,   946,  1530,  2339,
     652,   653,   654,   655,  2914,   128,   186,   264,   265,   656,
     266,    12,   267,   268,   324,   461,  1337,  1915,  2616,   269,
     320,   424,   657,  2486,    96,    97,    98,    99,   100,   106,
     120,   270,   482,  1341,  1948,   658,   941,  1767,  1519,  1765,
    2692,  2330,  1520,  1764,  2063,  2332,   659,   660,   661,   831,
     832,  1248,   271,   379,   460,   712,   713,  1001,  1335,   662,
     986,   987,   663,   864,  1285,   988,   808,   122,   123,   124,
     125,  1255,   152,   139,   126,   136,   160,   161,  1256,  1257,
    2070,  1258,   479,   480,   969,   481,   970,  2593,  2594,  1259,
    1260,  1132,  2215,  2216,  2444,   735,   846,   847,   664,  1147,
    2679,   665,  2308,   666,  1165,  1166,  1167,  1454,  1452,   667,
     668,  1687,  1717,   669,  1021,  1350,   670,   892,   893,   671,
     908,   672,  1856,   673,  2685,   674,  1735,  2795,  2796,  2797,
    2864,   897,   675,  1261,  1532,  1796,  1797,   676,  1422,   751,
    1035,   677,  1643,  2265,  2659,   678,  1625,  2219,  2455,  2456,
    2618,  2619,  2623,  2621,  2624,  2734,  2736,   679,   680,  1250,
    1524,   681,  1252,   916,   917,   918,  1228,   682,   683,   684,
    1494,  1220,   911,   487,   919,   920,   809,  1626,  1958,  1959,
    1942,   755,   756,  1621,  1943,  1946,   272,   319,   453,  1013,
    1960,  2459,  1043,   685,   909,   273,   316,   450,  1010,  1947,
    2457,  1622,   936,  2046,  2524,  2798,  1223,   686,   687,   688,
     689,   690,   818,  1685,   748,  1641,  2471,   742,   743,  1973,
    1974,   691,   692,   827,   810,   693,  1308,  2425,  2169,  2170,
    2171,  2172,  2173,  2422,  2598,  2599,  1309,  1310,  1577,  2414,
    2590,  2160,  2411,  2817,  2818,  1311,  1587,  2177,  1889,  2429,
    2608,  1727,  2038,  1890,  1312,  1313,  2496,  2771,  2772,  2773,
    2845,  1314,  1315,  1169,   694,   695,   994,  1317,  1318,  2730,
    1593,  1594,  1595,  1892,  2179,  2611,  2612,  1319,  1866,  2140,
    2565,  1975,  1976,  2656,  2461,  2755,  2462,  1977,  2464,  1978,
    2483,  1979,  2484,  2657,  2658,  1320,  1571,  1572,  1863,  1321,
    2767,  2666,  2763,  1869,  2269,  2488,  2489,  2490,  2761,  2270,
    1870,  2667,  2768,  2148,  2149,  2150,  2151,  2152,  2153,  2583,
    2584,  2585,  2815,  2715,  2877,  2154,  2710,  2409,  2155,  2410,
    2156,  2345,  2261,  2262,  2263,  2748,  2264,  2649,  2643,  2831,
    1980,  1032,  2613,  1033,  2240,  2174,  2664,  1798,   811,  1799,
    2083,  1060,  1061,  1663,  2084,  2542,   105,   696,   697,  2381,
    2560,  2133,  2559,  1598,  1897,  1898,  2137,  1857,  1322,  1858,
    2165,  2595,  1371,  1853,  1854,  2497,  2669,  2419,  2385,  2157,
    1585,  1877,  1878,  2764,  2158,  2352,  2712,   698,   699,  1564,
    1855,  2376,  2556,  2557,  1288,   700,   813,  1324,  1325,  1580,
    2162,  1326,  1327,  1874,  2104,   736,  1801,   738,  1354,  1802,
     127,    26,    85,    82,   702,   922,  1498,  1155,   852,   703,
     900,   704,  2013,   705,  1635,   740,  1356,   706,   707,    90,
     454,   455,   456,   457,   458,   708
};

static const short yypact[] =
{
    1862,   321,   437,   437,   437,   437,   437,   437,   437,-32768,
     437,-32768,   268,-32768,-32768,-32768,   377,   260,-32768,   365,
  -32768,-32768, 18059, 17563,-32768,  -214,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768, 18059,  1862,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
     395,-32768,-32768, 18059,-32768,-32768, 17563,-32768,   792,-32768,
  -32768,-32768,-32768, 13940,-32768,-32768,-32768,  1862,   792,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768, 11346,-32768,-32768,-32768,
   18059,-32768, 18059,   217,  1685,-32768,-32768,-32768,   471,-32768,
  -32768,-32768,-32768,  9881,  -133,-32768,-32768,-32768,  1685,-32768,
     150,  -133,-32768,-32768, 12395,  8850,-32768,-32768,   275,-32768,
     -28,  1862,    21,-32768,   703,   391, 18059,-32768,-32768,   720,
  -32768,-32768,   349,-32768,-32768,-32768,  8850,   952,   723,-32768,
     109,-32768,  8850,-32768,-32768,  2823,   754,   150,-32768,-32768,
  -32768,-32768,-32768, 16812,-32768,   309,-32768,-32768,-32768,-32768,
  -32768,  8850,-32768,  8850,   369,   110,   360,-32768,-32768,   284,
     655,-32768,-32768,   400,-32768,   404,-32768,   390,-32768,-32768,
     422,-32768,   431,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,    54,-32768,   108,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,   284,-32768,   655,-32768,-32768,   440,-32768,   449,-32768,
     405,-32768,-32768,   451,-32768,   453,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,   952,-32768,  8850,-32768,
  -32768,-32768, 18059, 18059,-32768,-32768,-32768,-32768, 18059, 18059,
  -32768,-32768,-32768,-32768,-32768,   360,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768, 18059,-32768,   -47,-32768,   267,
     954,-32768,   280,   969,   829,   831, 18059,   854,   856,   860,
  -32768,   303,-32768,-32768,-32768,   863,-32768,   880,-32768,-32768,
  -32768,-32768,-32768,   -47,-32768,-32768,-32768,   885,   888,   150,
     854,   896,   902,   344,-32768,   114, 18059,   543,   872, 18059,
    1685,-32768,-32768,-32768, 18059,   358,-32768,-32768,   938,-32768,
     567,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   969,   567,
  -32768,-32768,-32768,-32768,-32768,-32768,   578,   135,   153,   197,
  -32768,  2286,-32768,-32768,-32768,   584,   978,   155,   633,-32768,
  -32768,-32768,   410,   982,   780,   158,   161,   214,   620,   163,
     657,-32768,-32768,   623,  1005, 18059,   634,-32768,  1685,  1685,
     641,  1029,   -76,-32768,   954,  1028,-32768,-32768,-32768,-32768,
    1030,-32768,  1052,-32768,  1065,-32768, 18059,-32768, 18059,-32768,
  -32768,   854,  1074,-32768,-32768,-32768,-32768,  1080,   -76,   706,
    1076,-32768,  1081,-32768,-32768,-32768,  1082,-32768,-32768,-32768,
  -32768,   746,   715,-32768,   795,-32768,-32768,-32768,-32768,-32768,
  -32768,   853,-32768,-32768,   768,   769,   770,   772,-32768,-32768,
     540,  1139,   783,-32768,   874,-32768,   786,   789,   569,   804,
   17687,-32768,-32768, 17687,   835,-32768,  3975,   678,  9343,  1862,
    -295, 17687,   741,-32768,-32768,-32768,-32768,  2823,   854,-32768,
     742,-32768,   179,-32768,-32768,-32768,-32768,-32768,   580,   812,
    1167,-32768, 17687,   814,-32768,-32768,-32768,-32768, 18059,-32768,
  -32768, 12519, 18059,-32768, 18059,-32768,-32768, 18059,-32768, 14932,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768, 18059,-32768,
  -32768,-32768,-32768,    67,    67,  4702,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768, 18059,-32768,-32768,
  -32768,-32768,-32768, 17811,-32768,-32768,-32768,  4702,-32768, 17811,
   18059, 17811,   748,-32768,-32768, 11718,-32768,-32768, 11718,-32768,
   18059, 11718,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768, 17811,-32768,    18, 17062, 18059,-32768,-32768,-32768,-32768,
  -32768, 12519,-32768,-32768,-32768,-32768,-32768,  1779, 17811,  5979,
  -32768, 17315, 17315,-32768,-32768, 18059, 11842, 17811, 12643,  4702,
    5979,-32768, 15747,  4702,-32768, 17563,-32768,  5979,-32768,  5979,
   17811,-32768,-32768,  5979,  5979,    67, 18059,-32768, 18059, 17315,
  -32768, 18059, 17315,-32768, 18059, 10873,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,    22,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
     487,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   326,
   18059,-32768,   299,-32768,   820,  1155,-32768,-32768,  1155,-32768,
  -32768,-32768, 18059,-32768, 18059,   822,-32768,-32768,-32768,-32768,
     129,-32768,   593, 14064,   757,-32768,   602,-32768,   600,-32768,
    1185,  -264,   187,-32768,-32768,-32768,   802,-32768, 14188,-32768,
  -32768,   751, 10997,-32768,-32768,-32768,   701,-32768,  5979,  5979,
  -32768,-32768,   714,   810,   815,   817,   819,   827,   828,   837,
     839,  5979,  1043,   840,   841,   843,-32768,  5979,  5979,   845,
  -32768, 14808,   852,-32768,   855,   858,   868,   879,   882,   886,
     887,  5979,   889, 16884,-32768,    70,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,   392,-32768,   830,-32768,
  -32768,-32768,-32768,-32768,-32768, 17811,-32768,-32768, 14188,-32768,
     -71,-32768,-32768,   973,-32768,    26,-32768,   824,-32768,-32768,
  -32768,-32768,  1249,-32768,-32768,  -241,-32768,   671,-32768,   674,
    1249,-32768,   708,-32768,-32768,   890,    49,-32768,   862,-32768,
  -32768,   662,-32768,-32768,-32768,   893,-32768,  -193,-32768,   673,
   17439,  -226,-32768,  1009,  5979,  5979,-32768,  1297,-32768,-32768,
  -32768,-32768,-32768,-32768, 14684, 14684, 14684,-32768, 14684,-32768,
   14684, 14684,   755,   -71,   755,   755, 12767, 12767,   755,   755,
     -71,-32768,  1301,-32768,   -20,  1318,-32768,   -71,  4308,-32768,
      50,    29,-32768,-32768,  5979,   766,-32768,-32768,-32768,-32768,
  -32768,   462,-32768,-32768,   678,   975,   678,  4702,-32768,    43,
  -32768,-32768,  5979,   930,   931,   934,   935,   936, 14312,   937,
   12643,   858,-32768,  1026,   473,   782,-32768,   794,-32768,-32768,
  -32768, 12891,-32768,  1334,-32768,  1331, 18059,-32768,   -11,   805,
  -32768,-32768,  1340,-32768,   721,  1340,  1345,   724,  1340,  1345,
    5979,  1340,-32768,-32768, 10997, 17811,-32768,-32768,   965,   233,
  -32768,-32768,   956, 17811,  5979,   963,-32768,-32768,  1337,  1349,
    1342,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768, 13015,
   13015,-32768,-32768,-32768,  1609,-32768,-32768,  1313,   326,-32768,
  -32768,   315,-32768,-32768,-32768,-32768,   985,   987,-32768,-32768,
    1685,-32768,-32768,  1685,   984,-32768,-32768, 14064,   600,  8850,
   12519,  -254, 10005, 18059,-32768,-32768, 18059,-32768,   823,   799,
     825,   998,   846,-32768,-32768,  1003,    61,-32768,-32768,-32768,
    1378,  1378,  5979,-32768,-32768, 17315, 17315, 17315, 17315,   967,
    5979,  5979, 16884,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,   808, 17315,  1387,  5979,  9732, 16884,   967,-32768, 15056,
  -32768,  1390,   236,-32768,-32768,-32768,  5979,-32768,  5979,  5979,
   16884,  5979,  5979,  5979,  5979,  5979,  5979,  5979,  5979,  5979,
    5979,  5979,  5979,  5979,  5979,  5979,  5979,  5979,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  5979,  5979,
  -32768,-32768,  1010,  5979,-32768,  5979,  1014,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   17811,-32768,   818,  1017,-32768,-32768,-32768, 12519, 13139,-32768,
   13139, 12643, 11718,  5979,  5979,  5979,  1019,-32768,-32768, 17811,
   17811,-32768,   826, 12643, 17315,   787, 18059,  8850,  3506, 17062,
   17811,-32768,   832,  5979,  1102,-32768,-32768,   906,-32768,-32768,
    1318,    42,-32768, 10997,-32768,-32768,  1407,  1413,-32768,-32768,
  -32768,-32768,-32768,-32768,   439,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,  1779,-32768, 12767,
    5979,  -124,-32768,-32768,-32768,  1427,-32768, 17315,  1416,  1425,
  -32768,-32768,-32768,-32768,    63,-32768,-32768,-32768,-32768,-32768,
    1316,-32768,  1265,-32768,-32768,-32768,  5979,    67,-32768,-32768,
  -32768, 18059,  1431, 17315, 17315,-32768,   898,-32768, 17315,   869,
   17811,-32768, 18059,  5979,   -94,-32768,   915,-32768,   167,-32768,
    1016,-32768,  1020,  5979,   493,-32768,-32768,  -133,-32768,  1465,
  -32768,   959,-32768, 17811,-32768,-32768,-32768, 18059, 17315, 17315,
     132,   233,  1352,  1148, 17811, 10997,-32768,   962,-32768,-32768,
    1474,  1456,  1118,-32768,-32768,-32768,-32768,-32768,  1208,  1208,
      73,   986,-32768, 18059,-32768,-32768, 14188, 14188,-32768,-32768,
  -32768, 18059,-32768, 18059,   -66, 14188,-32768,   605,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,   695,-32768,-32768,-32768,-32768,   123,   123,
   15361,   407,-32768,   245,-32768,   315,-32768,  1685,-32768,-32768,
    1077,  1685,  1078, 14436,-32768,   921,   116,-32768, 12643,   968,
  -32768,-32768,   757,-32768,-32768,-32768,  1001,-32768, 18059, 18059,
  -32768, 18059,-32768,-32768, 16884,  4702,  1152,  1156,  1157,   188,
     -66,  1158, 15960, 16222,  1244,  1163,  1170, 16323,-32768,  1171,
    1173,  1184,  1194,   852,-32768,  5979,  5979,  5979, 16400,  5979,
   16440, 16518, 16620, 11499, 16916, 16990,  5371,  5884,  2084,  2995,
    1688,  7387,  4053,  4320,  1378,  1378,  3540,  3511,  1304, 16884,
   16884,   967, 16884, 16884,   967,  4702,-32768, 18059,-32768,   940,
  -32768,-32768,-32768,-32768,   949,-32768,  1549,  1551,-32768,  1552,
    1011,  5979,-32768,-32768,   972,  1559,-32768,  1119,   977,  1345,
  -32768,  1209,   189,-32768,  1172,-32768,-32768,   979,  1055, 18059,
  -32768,-32768,  1179,-32768,   418,  5979,-32768, 18059, 18059,  5979,
   17191,   -71,  1574,  1060,  1556,  1558,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,  1186,-32768,-32768,-32768, 17811,  1083,  4953,-32768,
  -32768,-32768,  1550,  5979,   678, 15237,-32768,-32768,  1295,  4702,
    1233,  1590,  1238,   191, 18059,  1240, 12643,-32768,  4702,  1202,
  -32768,-32768,  1275,-32768,  5979,   -86,-32768,  1039,-32768,-32768,
     151,-32768,  5979,-32768,-32768,  1015, 12395,-32768,  1022, 18059,
    1592,  7227,-32768,-32768,  -129,-32768,  1345,  1345,   980,-32768,
    1089,  1100, 17315, 17315,-32768,-32768,-32768,-32768,-32768,-32768,
    -113,    16,-32768,   698,-32768,-32768,-32768,-32768, 17315,  1341,
    1612,  1589,-32768, 12643,  1399, 12023,  1187,  1554,    36, 13263,
  -32768,   -45,-32768,-32768,-32768,  1224,   -40, 14188,   131,-32768,
    1034,  1036,-32768,-32768,-32768,  8726,  1072,   955,-32768,-32768,
  -32768,-32768,  1231,  1050,  1644,-32768, 14560,-32768,-32768,-32768,
  -32768, 17811,    51,-32768,-32768,-32768,  1044,   407,-32768, 18059,
   18059,-32768,-32768, 18059,   171,-32768,-32768,-32768,  1058,  1062,
    1035,   -33,-32768,-32768,  1931,-32768,   -33,-32768,  1294,  -133,
   10005,-32768,  1648, 12643,  5979,-32768,  1655,-32768,-32768,-32768,
  -32768, 11470,-32768,-32768,-32768,  1656,-32768, 16884,-32768,-32768,
  -32768,-32768,  8726,-32768,-32768,   714,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   714,-32768,-32768,-32768,-32768,
     714, 16884, 16884, 16884,   714, 16884,   714,   714,   714,  5979,
    1305,  5979,  1307,-32768,  1084, 11470, 12147,-32768, 12643,  5979,
    5979,  5979,  5215,  1666,  9757,-32768,-32768, 12643,-32768,  1085,
   18059, 18059,-32768,-32768, 18059, 18059,-32768,   589,-32768,-32768,
     261,-32768,  1086,  5979,-32768,-32768,-32768,  1668,-32768,-32768,
  -32768,-32768,-32768, 18059,  1345,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768, 17811,-32768,-32768,  2478,-32768,
  -32768,-32768,  1383,-32768,-32768,-32768,  1368,  1372,  1261,  1101,
    1377,  1300,-32768,-32768,  -123,  1392,-32768,-32768,-32768,-32768,
    1275,-32768,-32768,-32768, 11594,   195,-32768,-32768,-32768,  1474,
    5979,  1323, 10129,-32768,-32768,    95,   103,-32768,   593,-32768,
  -32768,  1388,-32768,-32768,  8726,-32768,-32768,  1325,-32768,-32768,
    1328,  1329,  1332,  1333,   354,-32768,  1716,-32768,-32768,-32768,
    2156,  1347,-32768,  1228,  1113,-32768,  1722,   -71, 18059,-32768,
    1754,-32768,  1755,   983,   983,   983,   983,  1186,-32768,-32768,
    1756,-32768,-32768,-32768,  1760,-32768,-32768,-32768,   983,    48,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,   193,-32768,  1741,-32768,
  -32768, 14188,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1203,
    1207,     9,-32768,   -45,-32768, 14188,  1191,-32768,  6734,-32768,
  -32768,  1374,-32768,-32768,-32768, 18059, 18059,  1768,-32768,  2169,
    9633,  5979,-32768,  5979,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768, 14188,-32768, 14188,   517,  1195,  1196,  1784,-32768,  1786,
  -32768, 17811, 18059,   385,   385,-32768,-32768,  1787,-32768,  1787,
     346,   346,  1787,-32768,-32768,  1862,  2823,-32768,-32768,-32768,
      67,    67,    67,  1769,    67,    67,    67,    67,    67,    67,
    1771,-32768,  1772,    67,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,  1035,-32768, 17811,  1213,-32768,  1393,  1862,  1773,
  -32768,  1782,  1785,  1788,  1793,  1796,  1799, 13387,  1931,-32768,
    1393,-32768,-32768,  1222, 12643,  1804,-32768, 18059,  1428,  1432,
    1433,  1434,   278,   207,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,  2720,-32768,  1475,  5979,   102,-32768,-32768,-32768,  1478,
    1481,  1482,-32768,  1486,-32768,-32768,-32768, 16884,   210,-32768,
     229,-32768,  1488,  1813,   235, 12643,  1837,-32768,-32768,-32768,
  -32768,  5979,  1314,  1604,  5979,-32768,-32768,-32768,-32768, 10253,
    1491,   261,   873,   873,  1846,  -176,-32768,  1850,-32768,-32768,
  -32768,   873, 18059,  1344, 10377,  1855, 18059,  -179, 10997,  1651,
     237,-32768,  1089,  5979,-32768,  1504,  4702, 17811,-32768, 14932,
   18059, 17811,-32768,  1506,  4702,-32768,-32768,  -123,  1392,-32768,
    1186,-32768,-32768, 12271,-32768,-32768,  1335,-32768,-32768,  1441,
  -32768,  5466,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  1278,   607,   323,  1472,   323,   323,
     323,   323,  8726,  7227,  8726,  8726,  8726,  8726,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768, 12519,-32768,  1467,   433,-32768,
  -32768,-32768,  1289, 17315,   983, 17315,   983,-32768,-32768,-32768,
  -32768,-32768,  -113,   983,    16,   983,-32768,   -71,  1341,-32768,
    1522,  1484,   -66,   695,  1187,  1187,-32768,-32768,-32768,-32768,
     239,-32768,  1445,-32768,  1487,  6241,  1487,  7478,  1878,  1879,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,   518,   351, 14188,
     406,-32768,  1298,-32768,  8726,  1369,-32768,  1885, 14188,    24,
  -32768,  1894,  1887,-32768,-32768,-32768,-32768,  1384,-32768,   242,
  -32768,  1310,-32768, 18059, 18059, 14560, 17811,-32768,  1787,-32768,
  -32768, 18059,   346,   346,-32768,-32768,   346,  1726,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  -181,  1908,-32768, 17811,  1396,-32768,
    1726,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768, 12643,-32768, 14188, 14188, 14188,  6734,  1891,
  -32768, 11470,  1679,  1343,-32768,-32768,  1388,  1388,-32768,  1523,
  -32768,  1524,  1533,-32768,  1537,  1538,-32768,  1539,-32768,-32768,
  -32768,    44,-32768,-32768,-32768,  5728,-32768,-32768, 13511,  1447,
     248,-32768,-32768,-32768,-32768,  5979,-32768,-32768,-32768,  1505,
  -32768,   154, 12643,-32768,  1915,  1544,-32768,-32768,  1584,-32768,
  -32768,-32768,  1429,-32768,-32768, 18059,   873,  8850, 10501, 18059,
     873,-32768,-32768, 17315,-32768,-32768,  5979,-32768,-32768,-32768,
   17315,  1574,  1737,-32768,-32768,   -71, 16884,  1637,-32768,-32768,
   10997,  1557,-32768,-32768,  4702,-32768,  1591,-32768,-32768,-32768,
     195,-32768,  1089,-32768,  5979,-32768,  8850,-32768,  1318,-32768,
    1415,-32768,-32768,-32768,-32768,  8726,-32768,  8726,  8726,  8726,
    8726,  2156,   244,-32768,  1248,  1248,  1483,  1646,-32768,  1545,
  -32768,  1643,-32768,  1938,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768, 18059,-32768,  8726,-32768,-32768,
  -32768,   695, 14188,-32768,-32768,  1856,  1528,-32768,-32768,   140,
     759,-32768,-32768,  6734,  6734,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,  8726,  1563,-32768,  1573,   -56,
    6492,   247,-32768,-32768,-32768,-32768, 18059,-32768, 17811,-32768,
    7740,-32768,   249,-32768,  6734,-32768, 14188,  7982,-32768,-32768,
   14188,-32768, 17935,  1386,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,  1792,-32768,-32768,-32768, 17811,  1908,-32768,-32768,-32768,
   17811,-32768, 17811,-32768,-32768,  1071,-32768,  1763,  1792,  1766,
  -32768,  1618,  1974,-32768,   251,-32768,   252,   181,   145,-32768,
  -32768,-32768, 10625,  1389,  -198,  1958,  1958,  1960,  1958,  1958,
    1961,-32768,   124,-32768,    47,  1474,-32768, 13692,  1983,-32768,
  -32768, 15485,  1657, 18059,  1403,   323,-32768,-32768, 16884,  1986,
     -71,  1660, 12643,-32768,  5979,-32768,  1462,  1977,   -71,-32768,
  -32768,   254,-32768,-32768,-32768,-32768,    78,  1645,  1345,-32768,
  -32768,-32768, 10997,-32768,  1647,  1574,  1607,-32768,  1637,-32768,
  -32768,-32768,-32768,  1801,   147,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,   744,  8726,  1092,  1134,  1291,  1628,  8726,
  -32768,-32768,-32768,-32768,  1089,-32768,   253,-32768,    65,   695,
     695,-32768,-32768,   -66,-32768,-32768,   -66,-32768,  1879,-32768,
    2156,    81,-32768,    81,-32768,-32768,-32768,  8726,   124,  8233,
  -32768,-32768,-32768,  1487,-32768,-32768,-32768,  2156, 14188,-32768,
    1610,-32768,-32768,  2006,-32768,  1503,  6985,-32768,  2013,-32768,
  -32768,  2156, 14188,  2007,-32768,  1878,-32768,-32768, 10997,-32768,
  -32768,   276,-32768,-32768, 18059,-32768,-32768,-32768,  1809,  1809,
  -32768,  1809,-32768,  1809,  1809,-32768,-32768,-32768,-32768,  1758,
   14188, 14188,-32768,-32768,-32768,  1997,-32768,-32768,  1597,  1415,
    2001,  1415,-32768,  2024,  2024,   255,  1671,  2024,-32768,  1672,
  -32768,-32768,-32768, 14188,-32768,  1638,-32768,-32768,    47,  1676,
   13511,-32768, 13511,-32768,-32768,  8726,-32768,  1622,-32768,  1679,
   13816, 12023, 17315,-32768, 12643,-32768,  1678,  4574,  1641,-32768,
  -32768,-32768,  1451,   -71,-32768,    -4,  1574,-32768,-32768,  1686,
  -32768,  1637,   195,-32768,-32768,-32768,   258,-32768,-32768,-32768,
  -32768,  2156,-32768, 18059,-32768,  1503,-32768,-32768,  8726,  8726,
     264,-32768,-32768,   279,  2115,  1635,-32768,-32768,-32768,  8475,
   17811,   248,   298,   607,  7982,-32768,  1650,  1574, 17935,-32768,
  -32768,-32768,-32768,-32768,  1809,-32768,  1809,-32768,-32768,-32768,
  -32768,-32768,  1658,-32768,-32768,  1691,-32768,  2026,  1696,  1697,
    2032,-32768,-32768,  1699,-32768,-32768,  1661,  6734,-32768,-32768,
  -32768,   302,-32768,  2055,-32768,  2156,  6734,-32768,-32768,-32768,
  -32768,  2056,-32768,  -146,-32768,-32768,-32768,   362,-32768,-32768,
   14684, 14684, 14684, 14684, 14684, 14684,-32768,  2039,-32768,   304,
  -32768,  5979, 10749,-32768,-32768,-32768,    -7,-32768,  1637,  4702,
    1637,-32768,-32768,  1853,-32768,   -71,-32768,   248,   102,   102,
     124,-32768,-32768,  8726,   124,-32768,-32768,   305,-32768,  2156,
  -32768,-32768,-32768,-32768,  7982,-32768,-32768,-32768,-32768,  1471,
  -32768,-32768,-32768,-32768,  1708,-32768, 14188,   185, 13511,-32768,
    8726,  1878, 13816,-32768,-32768,-32768,-32768,-32768,-32768,    86,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  4574,
  -32768,  2063,-32768,-32768,     2,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  1710,-32768,  2156,-32768,-32768,  8475,
  -32768,   306,  1415,-32768,   307,-32768,-32768,-32768,-32768,   531,
     531,-32768,-32768,   531,-32768,  5979,-32768,  1727,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,  1729,-32768,-32768,    91,
  -32768, 10997,-32768,  1574,  2089,  2092,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,-32768,    45,-32768,   139,  -154,-32768,-32768,
    -893,  -440,-32768,-32768, -1508,-32768,-32768,-32768,-32768,  -752,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768, -2375,-32768, -1399,-32768,   125,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,   348,-32768,-32768,
  -32768,-32768,   866,-32768,   598,-32768,-32768,    79,-32768,-32768,
    2097,-32768,  2096,  1662,-32768,-32768,-32768,-32768,-32768,   415,
      92,-32768,   411,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,   -93,-32768,  2015,-32768,  1818,   -13,-32768,  1964,
  -32768,-32768,  1966,-32768,  1917,-32768,-32768,-32768,  1838,  1732,
    1426,  1835,  -125,-32768,-32768,-32768,-32768,-32768,  1435,  -463,
  -32768,-32768,-32768,-32768,  -175,  1789,  1932,  1933,-32768,-32768,
    1775,-32768,-32768,  1817,-32768,-32768,-32768,-32768,  1830,-32768,
  -32768,-32768,-32768,  -345,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,  1774,-32768,  1780,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,  -977,-32768,-32768,  -678,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,  2360,-32768,-32768,   684,-32768,  -943,
    -841,  -195,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   509,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,  -541,-32768,-32768,
  -32768,-32768,-32768,  1599,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    1199,-32768,-32768,-32768,-32768,   585,-32768,-32768,-32768,-32768,
  -32768, -1381,-32768,-32768,   579,-32768,-32768,-32768,-32768,-32768,
  -32768,  -856,  -501,   503,   739,-32768,  -555,   243,  -857,   640,
  -32768,   259,-32768, -1719,   -22,  -359,-32768,-32768,  2316,  1189,
   -1664,  -726,  1114,-32768,-32768,-32768,   293,   932,-32768,-32768,
  -32768,-32768,-32768,-32768,    93,-32768,  -161,-32768,   939,-32768,
     664,-32768,   401,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,   511,-32768, -1234,-32768,   654,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    88,-32768,
      84,-32768,-32768,-32768,-32768,  1053,-32768,-32768,-32768,-32768,
  -32768,-32768,  -299, -1430,-32768,-32768,-32768,-32768,    96,-32768,
   -1618,-32768,  -865,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    1953,   -25,-32768,-32768,-32768,-32768,-32768,-32768,  -232,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,  2129,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   709,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -506,
    1677,-32768,-32768,-32768,-32768,-32768,  1518,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,  1834,-32768,-32768,   -91,
  -32768,-32768,   705,-32768,-32768,   990,  -159,  2049,-32768,-32768,
  -32768,-32768,   262,-32768,  -744,  1515,   966,-32768,  -480,-32768,
     716,  1282,    31,  -196,-32768,  -986,-32768,  1104,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1054,-32768,
     681,-32768,  -481,-32768,-32768,-32768,-32768,-32768,-32768,  -544,
  -32768,-32768,-32768,-32768,-32768,-32768,   162,-32768,  1116,  -222,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,   297,-32768,  -197,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,  1346,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,  -849,-32768,  1033,  1188,-32768,-32768,   308,
  -32768,  -387,-32768,-32768,   319,   636,-32768,-32768,-32768,-32768,
  -32768,-32768,  -187,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,  -405,-32768,  1239,   582,
      27,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768, -2057,  -157,-32768, -2383, -2298,-32768,   409,-32768,-32768,
  -32768,-32768,-32768,-32768,  -608,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -570,-32768,
  -32768,-32768,-32768,-32768,  1280,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,   381,-32768,-32768,-32768,  -450,-32768,-32768,-32768,
  -32768,-32768,-32768,  -350,-32768,-32768,  -554,-32768,    46,-32768,
  -32768,-32768,-32768,  -373,-32768,-32768,-32768,-32768,-32768, -1428,
  -32768,-32768,-32768,-32768,-32768,-32768, -1955,  -201,-32768, -1906,
      20,-32768,-32768, -2099,  -103,  -102,   146,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,  -276,-32768,-32768,   141,
  -32768, -1919,-32768,-32768,-32768, -1901,-32768,-32768, -1615,-32768,
    -743,-32768,  1006,  -665,  -338, -1550,-32768, -1820,-32768,-32768,
  -32768,-32768,-32768,-32768, -1150, -2302,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768, -2036,-32768,   118,-32768, -1455,-32768,  1311,
  -32768,-32768,  -929,  -370,-32768, -2476,-32768,  -252,   156, -2070,
   -1344, -1620,   149,  -530,  1137,  -233, -2259,-32768,-32768,  1025,
    -548,-32768,-32768,  -388,  1327,-32768,   265,-32768,-32768, -1254,
     -98,-32768,-32768,-32768,-32768,  -519,  -484,  -539,   689,-32768,
      15,  1735,   -17,-32768,-32768,-32768,-32768,-32768,  -719,-32768,
    -552,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -702,
    1458,  1864,-32768,-32768,-32768,-32768
};


#define	YYLAST		18683


static const short yytable[] =
{
      79,    84,   175,   185,  1201,  1031,   399,   737,  1036,   856,
      88,  1174,    87,   721,  1183,    13,  1683,  1270,  1709,  1180,
    1181,   131,  1182,  1170,  1185,  1186,  1652,   246,  1016,   291,
     901,  1280,  1985,   865,  1207,   141,  1353,  1540,  1541,   898,
     914,  2028,   836,   904,  -577,  2062,  2389,  1455,  1226,  1581,
      13,  1847,   863,  1207,  1150,  1207,  1901,   956,   971,  1363,
     959,    91,   313,  1214,    84,  1221,  1275,  1224,  1200,    92,
    2164,   104,   107,  1944,  2387,  1133,  2391,   292,   293,   294,
    1456,  1867,  1457,  1207,  1458,  1138,  1139,   737,   129,   315,
     292,  1981,   753,   292,   867,  1127,  1208,  2378,  1775,  1776,
    1743,   138,  1209,   101,   292,  2650,  1779,  2164,  1860,  1752,
    2127,  2421,    13,   101,   183,   183,   164,   145,   292,   183,
    2072,   183,   716,  1262,   169,   297,   292,   757,  2074,  2607,
     166,   292,   298,   299,  1290,  1981,  1292,  1455,  1379,  2467,
     392,  1775,  1776,  1864,  2016,  2423,  2393,   292,  2650,  1779,
    2635,   244,   183,  2690,   145,    89,    13,   214,   394,  2501,
     402,  1296,   812,   410,  2575,   812,   412,    95,   416,  2347,
    2348,  2349,  2350,  1517,   972,   821,  2652,    95,  2309,   812,
    1566,  1567,  1213,   812,   719, -1693, -1693,  2393,  1486,  1517,
     838,  2393,  1026,  1207,  1018,   812,  1207,   821,  2128,  2121,
    2640,   274,   396,   849,   821, -1693,   176,   177,   178,   179,
     180,   862,  2241,  2722,  1511,  2275,   866, -1693,   950,   167,
    1271,  2481,  1759,   980,   903,  2910,   314,   377,  1298,  1909,
     317,   318,  1912,  1157,  2275,   849,   321,   322,  1275,   849,
    2241,  1024,  2313,   849,  2382,  2821,  2865,  2430,   821,  2549,
    2297,   821,  2588,   325,  2602, -1693,  2631,  2631,  2703,  1545,
    2750,  1582,  1545,  2549,   353,   260,  2032,   972, -1693,  2810,
     762,   176,   177,   178,   179,   180,   441,  1709,  1872, -1693,
     274,  2728,  1198,   429,  2810,   425,   426,  1163,    15,   362,
    1348,   364,  1025,  1818,   373,  2891,   145,   376,  2576,   710,
    2577,  1263,   380,  2724,  1819,   816,   972,  2838,   972,  2859,
    2879,  2724,  2630,    34,  2653,  2141,  2801,   430,   825,  2716,
     794,  1492,   711,  2315,  2442,  2605,   176,   177,   178,   179,
     180,  2872,  1349,  1199,   973,  -577,  2572,  2744,  2574,  2746,
    2586,  2180,   822,   717,   260,  2561,   405,  1143,    14,    15,
    2600,   326,  1545,   422,  1144,  1276,  1518,  2600,   405,  2843,
    2395,  1164,  2396,  2397,  2398,  2399,  2400,  2401,  2094,  2095,
    2096,  2097,  1518,  1873,   353,  2443,   353,  1583,   327,   974,
   -1693,    86,  1239,  1276,   896,  1192,  1193,  2654,  2729,     1,
    1549,   250,    14,  1549,   915,   921,  1158,  2641,   938, -1693,
   -1693,  2846,   942,  2911,   944,  2847,  2138,    36,   948,   949,
    2844,  2482,  1421,  2298,  1421,  2098,  2099,  2100,  2101,  2102,
    2103,    89,  1822,  2867, -1693,  2869,  2823,  1307,   478,  1462,
     132,   478,   471,  1823,   709,  2139,  1440,   251,   252,   478,
    1487,  2881,  2329,  1189,  1781,   253,  1014,  1304,  1945,  2310,
    1196,   397,  1868,  1243,     2,     3,  -577,     4,     5,  1782,
     478,  1514,     6,  1466,  1913,   975,   727,  2578,   414,   734,
     739,   143,   741,   701,    13,   744,  2033,  1568,  1345,     7,
       8,  1766,  1680,  1549,  1725,  1682,   750,  1781,  1584,   974,
    1366,  1367,  1368,   806,   393,  2502,  1369,     9,    10,  2567,
    1264,  1347,  1782,   184,   249,   750,  2655,  1375,   372,   903,
    1631,  1291,   395,  2717,   403,   806,  2424,   411,   750,  2388,
     413,  2188,   417,  2706,  2707, -1693,  2600,  2395,   839,  2396,
    2397,  2398,  2399,  2400,  2401,  1265,   737,   623,   720,  2636,
    2634,  2694,   857,   859,  2885,  2725,  1027,  1651,  2493,   734,
    1747,  2875,  2129,  1575,  1576,  2878,  1210,   806,   975,   857,
     857,   163,  1586,   905,  1902,  1806,  2242,   806,   806,  2276,
     934,   806,  1151,    84,  2402,   806,  2671,   806,   940,  1769,
    2901,   806,   806,  1699,   951,  2418,   951,   857,  2277,   951,
     857,   770,   951,  1424,  2280,  2507,  2314,   975,  2383,   975,
    1861,  2431,  1439,  2550,   856,  1438,  2589,   165,  2603,  2412,
    2632,  2633,  2704,  2531,  2751,  2268,   774,  2804,  1419,  1609,
    2373,  1140,  2163,  2811,  2094,  2095,  2096,  2097,  1545,  1459,
    1227,  2509,   903,   866,   903,  2514,  1425,  1460,  2812, -1693,
     976,   977,   978,   295,  1353,  1739,  1211,  2318,  2682,   850,
    2342,   979,  1489,   737,  2600,  2326,   295,  2822,  2837,   295,
     850,  2839,  2651,  2860,  2880,  2900,  2902,  2841,   245,   896,
     295,  2098,  2099,  2100,  2101,  2102,  2103,  2846,  1502,  2379,
    2380,  2847,  1503,  1505,   295,  2463,  2465,  2465,  1000,  2721,
    2403,  1981,   295,  1609,  1640,   254,  1642,   295,  1484,  1383,
    1009,   162,   478,  1206,  2239,  2760,   471,  2762,   167,   896,
    1522,   734,   168,   295,  1467,   483,  1536,  1537,  1468,  1469,
    1470,   255,   915,   714,  1702,   170,  1030,  1229,  1703,  2494,
    1888, -1693, -1693, -1693, -1693, -1693,   806,   806,  1471,  2495,
   -1693,  2402,   174,  2749,   725,  1588,  2753,  2406,   182,   806,
    2029,  2711,  2092,  2711,  2600,   806,   806,  2558,  2711,  1549,
      21,  2094,  2095,  2096,  2097,  1610,  2343,   210,  2395,   806,
    2396,  2397,  2398,  2399,  2400,  2401,  2094,  2095,  2096,  2097,
    1019,  1037,  1038,  1039,  1611,  1612,   276,  2292,  2377,   814,
    1129,   989,   256,   787, -1693,   248,  1030, -1693,   284,  2807,
    1632,   990,   285,   823,  1613,   789,   790,   828,  2098,  2099,
    2100,  2101,  2102,  2103,   792,   844,   287,   134,   135,   842,
     288,     1,   851,  2098,  2099,  2100,  2101,  2102,  2103,   289,
    1704,   310,  2562,  1705,  1871,  2702, -1476,   939,   307,  1610,
    1497,   943,   806,   806,  2384,   947, -1693,   308,  1472,   311,
   -1693,   312,  2413,   991,   347,  1545,   348,  2403,  1611,  1612,
    1346,  2644,   329,  2646,  2647,  2041,   954, -1478,   992,   957,
    1679,  1241,  1473,  1681,  2404,   338,   806,  2344,  1613,   354,
    2609,   357,   806,  2886,   257,   358,     2,     3,   360,     4,
       5,  1474,   359,   710,     6,   806,   134,   135,   134,   135,
     806,   955,  2873,  2874,   958,   361,  1237,   961,  1724, -1693,
     365,     7,     8,   366,  2111,  1002,   711,  1340,  1526,   135,
    1342,   369,  2407,  1589,  1254,  2527,  1475,   370, -1693,     9,
      10, -1693, -1693,   371,  1590,   995,   996,    22,   806,  1542,
   -1693,   374,  1543,  2408,  1544,  1476,  1477,   381,  1426,  1427,
    1428,    23,   806,  1596,  1597,  1591,   375,   993,  1751, -1693,
   -1693,  1478,  1592,   382,  1545,   385,  2341,   258,  1450,   176,
     177,   178,   179,   180,  1546,   259,   390,    24,   400, -1693,
    1190,  1191,  2402,   401,  1194,  1195,  1549,  1809,  1811,  -256,
    2711,  1826,   404, -1693,  2711,   734, -1693, -1693,   734,   407,
    1352,  1355,  1479,  1442,   741,  1485,  1829,   408, -1693,   409,
    2143,  1589, -1693,  1547,   415,  1850,   418,  1548,  1604,  1605,
     806,   420,  1590,   857,   857,   857,   857,    25,   806,   806,
     421,   915,   423,  2178, -1693,  1480,  1715,  1716,  2718,   427,
     857,  2404,   806,  1591,  1216,  1217,  1218,  1219,  1510,   428,
    1592,   976,   977,   433,   806,   435,   806,   806,  1525,   806,
     806,   806,   806,   806,   806,   806,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,  -256,   436,  1918,  1919,
    2740,  2741,  1920,  1921,  1922,  1965,   806,   806,  2808,  2809,
     437,   806,  -256,   806,  1714,  1549,  2473,  2474,  2403,   442,
     443,   446,  1982,  2695,   445,   451,   447,   449,  2131,  2094,
    2095,  2096,  2097,   452, -1693,   734,    93, -1693,  2341,  1574,
    2774,   806,   806,   806, -1693,  1578,   462,   463,   464,   465,
     731,   466,   857,   467,  1441,  -256,  1445,   857,  2006, -1693,
    2007,   806,   469,   749,   468,   474,  1550,   470,   475,  2018,
    2181,  2094,  2095,  2096,  2097,  2406,  2098,  2099,  2100,  2101,
    2102,  2103,   476,   477,   484,    94,   486,   715,   718,   722,
     817,   723,   724,   726,  -256, -1218,  2448,  2166,   806,  1004,
    1005,  1012,  1017,  1019,  1923,   857,   834,   835,  1020,  1022,
    1702,  1924,   841,  1023,  1703,   843,  1028,  1034,  2098,  2099,
    2100,  2101,  2102,  2103,   806,  -256,  1042,   866,  1044,  1500,
    1137,   857,   857,  1045,  -256,  1046,   857,  1047,  1130,  2708,
    1509,   806,  2709,  1925, -1693,  1048,  1049, -1693,   903, -1693,
    2338,   806,  1926,  2071,  2372,  1050,  1693,  1051,  1062,  1063,
    2449,  1064,  2450,  1067,  1617,   951,   857,   857,  1623, -1693,
    1071,  1141,  1629,  1073,  1142,  2794,  1074,  2451,  1145, -1693,
    1718,  1146,  1927,  1928,  1428,  2452,  1075,  2096,  2097,  2453,
   -1693,  1570,  1148,  1881,  1030,  1030, -1693,  1076,  1149,  1579,
    1077,  1579,  2404,  1030,  1078,  1079,  2463,  1081,   330,  1153,
    1154,  1156,  2774,  1206,  2311,  2454,  1704,  1882, -1693,  1705,
    1883,  1159, -1693,   339,  1168,  1173,  1197,  1929,  2094,  2095,
    2096,  2097,  2098,  2099,  2100,  2101,  2102,  2103,  1884,  1758,
    1187,  1545,  2485,  1200,  1215,   296,  1222,   301,  1230,  1231,
    2407,  1551,  1232,  1233,  1234,  1238,  1638,  1639,  1240,  1639,
    1242,  1243,  1251,   806,  1253,  1267,  1930,  2851,  1266,  1268,
    1207,  2408,  1269,  1274,  1278,  2098,  2099,  2100,  2101,  2102,
    2103,  1281,  1282,   806,   806,   806,  2794,   806,  1098,  1099,
    1100,  1101,  1102,  1103,  1283,   331,  1330,  1053,  1284,  1338,
   -1693,  1339,  1343, -1476,  1104,  1105,  1106,  1358,  1359,  1542,
     340,   332,  1543,   806,  1544,  1684,  1360,  1095,  1096,  1097,
    2868,  1362,  1931,  1374,  1361,  1370,   341,  1376,  1411,   806,
    1382,  1830,  1414,  1417,  1545,  1418,  2232,  1431,   850,  2851,
    1451,  1437,  2521,  1885,  1546,  1464,  1449,  1712,  2447,  1453,
    1465, -1693,  1488,   806,   333,  1719,  1720,   806,   857,  1966,
    1493,  1490,  1098,  1099,  1100,  1101,  1102,  1103,  2520,   342,
    1491,  2697,  1549,  1495,  2199,  1501,  1504,  2281,  1104,  1105,
    1106,  1506,  1514,  1547,  1054,  1521,   806,  1548,  1986,  1523,
    1529,   806,  1531,   334,  1276,  1558,  1886,   806,  1987,  1455,
    1055,  1560,  1749,  1988,  1887,  1561,   806,  1992,   343,  1994,
    1995,  1996,   806,  2698,  2008,  2009,  1428,  2012,  1563,  1569,
     806,  2448,   866,  2097,   335,  1620,  1624,  1254,   903,  1794,
    1630,  1648,  1633,   336,  1634,  1649,  1650,  1653,  2035,   344,
     857,   857,  1664,  1056,  1107,  2491,  1686,  1108,   345,  1665,
    1667,   903,  1668,  2200,  2201,  2202,   857,  2204,  2205,  2206,
    2207,  2208,  2209,  1669,  1688,  1549,  2212,  2098,  2099,  2100,
    2101,  2102,  2103,  1670,  1689,  1030,  1690,  1691,  2364,  1692,
    2366,  1694,  1057,  1794,  1695,  2449,  2604,  2450,  1698,  1696,
    1700,  2198,  1697,  1701,  1896,  2066,  2525,  1713,  1656,  1275,
    1726,  1728,  2451,  1729,  1730,  1734,  1737,  1908,  1908, -1693,
    2452,  1908,  1744,  1058,  2453,  1745,  1550,  1746,  1107,  1750,
    1753,  1108,  1059,  1756,  1762,  1774,  1806,  2673,  1352,   979,
    1770,  1772,   806,  1808,  1849,  2681, -1693,  1848,  1851,  1972,
    2454,  2358,  1865,  1875,  1880,  1304,  1859,   754,   754,  1891,
    1794,  1876,  1932,  1933,  1934,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1831,  1109,  1893,  2094,  2095,  2096,  2097,  1894,
    2699,  1916,  1905,  1962,  1832,  1917,  1964,   806,  1110,   806,
    1967,  1984,  1111,  1972,  1999,  1657,  2001,   806,   806,   806,
     806,  2014,  1972,  2003,  2019,  2034,  2036,  2044,  2020,  1712,
    2047,  1658,  2025,  2025,  2048,  2460,  2175,  2049,  2176,  2051,
    2050,   806,  2098,  2099,  2100,  2101,  2102,  2103,  2052,  1293,
    1112,  2037,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
    2098,  2099,  2100,  2101,  2102,  2103,  2067,  1109,  1833,   754,
   -1693,  2093,  2076,  2086,  1659,  1834,  2088,  2089,  1113,   966,
    2090,  2091,  1110,   978,  2503,  2105,  1111,  2106,    27,    28,
      29,    30,    31,    32,  2491,    33,  1114,  2110,   806,  2535,
    2069,  2516,  1098,  1099,  1100,  1101,  1102,  1103,  2518,  2113,
    2115,  2122,  1794,  1660,  1835,  2124,  2130,  2134,  1104,  1105,
    1106,  2135,  2159,  2164,  1112,   866,   866,  2142,  2686,     2,
       3,  1551,     4,     5,  2183,  2184,  2112,     6,  1836,  2185,
    2793,  2186,  2191,  2203,  1661,  2210,  2211,  2221,  1837,  1838,
    1294,  2217,  1113,  1662,     7,     8,  2222,  2218,  1295,  2077,
    2223, -1640,  2233,  2224,  1839,  1296,  2283,  1297,  2225,  2288,
    1114,  2226,     9,    10,  2227,  2078,  2235,  1115,  1298,  1030,
    2236,  2237,  2238,  2279,  2266,  1840,  2536,  2271,  1841,  1842,
    2272,  2273,  2282,  1972,  1843,  2274,  1794,  2278,  2284,  2285,
    2291,  2295,  2537,  2161,  1579,  2299,  1299,  2303,  1972,   806,
    2306,   806, -1693,  2317,  2727,  2325,   966,  2336,  2079,  1972,
    2346,  1030,  1300,  2340,  2334,  2360,   896,  1301,  2363,   869,
    1908,  2374,  2375,  2384,  2393,  2386,  2394,  1302,   870,  2418,
    2197,     1,   110,  2416,  1303,  2538,  1116,   871,  2420,  2426,
    2427,  1115,   872,  1844,  2428,  2432, -1693,  2080,  1107,  1128,
    2756,  1108,  2871,  2445, -1693,  1845,  2468,  2491,  2470,  2491,
    2504,  2475,  2476,  2220,  2852,  2853,  2854,  2855,  2856,  2857,
      13,  2477,  2472,   571,  2539,  2478,  2479,  2480,  2081,  1868,
     121,  2499,  2505,  2506,   873,  1638,  2507,  2082,  2519,  2522,
    2529,  2526,   874, -1693,  2675,   973,     2,     3,  2554,     4,
       5,  2571,   806,    13,     6,  2540,  2388,  2564,   151,   159,
    1116,  2573,  2615,  2626,  2541,  2614,  2628,  2629, -1693,  2630,
   -1693,     7,     8,  2642,  2639,  2645,  2648,  2700,  2662,   806,
     159,  2670,   806,  2665,  2672, -1693,   159,  2290,  2678,     9,
      10,  2674,  2680, -1693,  2684,  2688,  2687, -1693,  2719,   875,
    1712,  2720,  2305, -1693,  2307,   159,  2268,   159,  2724, -1693,
    2726,   806,  2742,  2239,   806,  2653,  2745,  1109,  2322,  2747,
    2752,  2754,   806, -1693,   876,  2759,  2757,  2766,  2779,  2791,
    2792,   877,  1110,   878,  2814,  2800,  1111,  1304,  2824,   806,
    2829,  2830,  2828,   879,  1305,  2832,  2833,  2834,  2835,  2836,
    2840,  2842,  1949,  2858,   903,  2870,  2882,  2883,  2895,  2898,
    1794,  1794,  1794,  1794,  1794,  1794,  1306,   880,   966,  1950,
    1951,  1307,   159,   734,  1112,   881,  2907,  1952,  2908,  2915,
     111,   857,  2916,   857,  2321,  2491,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,  2234,  2894,  2059,  2267,
    1513,  2517,  1113,  1761,    37,    38,  2021,  2776,  2030,  1953,
     624,   882,  2813,  1794,  2302,  1794,  2778,   367,  1954,   133,
    1114,   212,  2094,  2095,  2096,  2097,   215,  1972,   303,  2532,
     444,   363,  1794,  2511,  1007,   368,  1972,   883,  1098,  1099,
    1100,  1101,  1102,  1103,  1008,   305,   389,   306,  1955,   432,
     419,  2433,  2434,  1896,  1104,  1105,  1106,  2913,   387,  2437,
     438,  2892,  1736,  2094,  2095,  2096,  2097,  2534,   439,  2098,
    2099,  2100,  2101,  2102,  2103,   884,  2094,  2095,  2096,  2097,
    2000,   933,  1906,  1914,  2010,    89,   885,  1334,  1721,  1535,
    2553,  2362,  1805,  1956,  1344,  2109,  2017,  1827,  2370,  1539,
    2368,  1115,  1446,  1972,  1972,  1972,  1794,  2683,   323,  1972,
    2098,  2099,  2100,  2101,  2102,  2103,  2627,   108,   840,  1768,
    1003,  1771,   247,  2098,  2099,  2100,  2101,  2102,  2103,  1011,
    2820,  1557,  1957,   806,  1527,  1773,  1030,  1272,  2446,  2617,
    1862,  1483,  2866,   806,  1433,  2353,  1423,  2231,  2625,  1496,
    1384,  2213,  1961,  1225,  2769,  1357,  2230,  2004,  2469,  2606,
    2136,  2899,  2888,  2025,  1316,  2182,  2513,  2025,  2825,  2739,
    1116,   857,  2884,  2466,   806,  2758,  2661,   966,   857,  2492,
    2568,   398,  2569,  2392,   886,   887,   888,  2713,  2405,  1573,
    2743,  2775,   806,  2435,  1107,  1323,  2705,  1108,   889,  2676,
    2887,  2696,   806,  2417,  1565,  2806,  2415,  1289,  2591,  1963,
     485,     0,     0,  1794,     0,  1794,  1794,  1794,  1794,     0,
       0,     0,     0,   747,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2555,     0,  1794,     0,     0,     0,     0,
    1972,     0,     0,     0,     0,     0,     0,   819,     0,     0,
       0,  1794,  1794,   824,     0,   826,     0,     0,     0,   833,
       0,     0,   833,  1794,     0,   833,     0,     0,  1794,   966,
       0,     0,     0,     0,  2161,   845,     0,     0,  1794,     0,
       0,     0,  1794,     0,  1972,  1794,     0,     0,  1972,     0,
    1570,     0,   894,   890,     0,     0,     0,     0,     0,     0,
     907,   910,   913,  1109,     0,     0,   935,     0,     0,     0,
       0,     0,     0,     0,   945,     0,     0,     0,  1110,     0,
     140,     0,  1111,     0,     0,     0,     0,   140,     0,   968,
    2638,     0,     0,     0,     0,     0,     0,     0,     0,  1336,
       0,     0,     0,     0,     0,  1030,     0,     0,     0,  2663,
       0,  2668,     0,     0,     0,     0,     0,     0,     0,     0,
    1112,     0,   806,  2043,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
       0,     0,     0,     0,     0,     0,     0,     0,  1113,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,     0,
       0,     0,  1794,     0,     0,     0,  1114,  1794,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,     0,     0,     0,     0,  1794,   188,  1794,  1104,  1105,
    1106,     0,     0,     0,     0,     0,  1972,     0,     0,     0,
       0,     0,     0,   189,  1794,     0,     0,     0,     0,     0,
    1972,     0,     0,     0,     0,     0,   968,     0,     0,     0,
       0,     0,  2731,     0,     0,     0,  2861,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1115,  1972,  1972,
       0,   190,     0,     0,     0,  1070,     0,     0,     0,     0,
       0,     0,     0,   191,     0,     0,     0,     0,     0,     0,
       0,  1030,     0,   192,     0,     0,     0,     0,  1030,     0,
    1030,     0,     0,  1794,     0,  1795,     0,     0,  1972,  1131,
     857,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,     0,     0,     0,     0,     0,     0,  1800,     0,
       0,     0,     0,     0,     0,     0,  1116,   195,     0,     0,
       0,  2555,     0,     0,     0,     0,  1794,  1794,     0,     0,
       0,     0,     0,     0,  1162,     0,     0,  1794,  1107,  1795,
    2906,  1108,  1794,     0,     0,     0,  1570,     0,  1179,  1179,
    1179,     0,  1179,     0,  1179,  1179,     0,   196,     0,     0,
     121,   121,  1879,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1794,     0,     0,     0,     0,
     197,     0,     0,     0,  1794,     0,     0,     0,     0,     0,
       0,     0,     0,  2244,     0,   198,     0,     0,     0,     0,
       0,     0,   199,     0,   913,   200,  1795,     0,     0,   806,
    2863,     0,     0,     0,     0,  1249,     0,   806,     0,     0,
       0,     0,     0,     0,     0,   201,  1599,  1600,   202,  1879,
     203,  1794,     0,  1616,     0,     0,     0,     0,   968,  1131,
       0,     0,  1794,     0,     0,   730,   730,  1279,     0,   204,
       0,     0,     0,     0,  1972,     0,  1030,  1109,  1794,   730,
    1972,     0,     0,  1287,  1287,     0,     0,     0,   205,     0,
       0,     0,  1110,     0,     0,     0,  1111,   730,     0,     0,
     730,     0,     0,     0,     0,     0,   730,     0,     0,     0,
     730,     0,     0,   159,   730,     0,     0,  1794,   730,     0,
       0,     0,   730,   730,     0,   730,     0,     0,   730,     0,
     730,   730,   730,   806,  1112,     0,     0,     0,   730,   730,
       0,     0,     0,     0,     0,     0,   730,     0,     0,  2073,
    2075,   730,     0,     0,     0,     0,     0,     0,  1795,   730,
       0,     0,  1113,  1381,     0,     0,     0,     0,     0,     0,
     730,     0,     0,     0,   730,     0,     0,     0,   730,     0,
    1114,  2085,     0,   730,     0,     0,   730,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1742,     0,     0,     0,
       0,     0,     0,     0,  1416,     0,     0,     0,     0,     0,
       0,     0,   121,     0,   121,   913,   833,     0,     0,     0,
       0,     0,  1795,  1432,   845,     0,     0,   913,     0,     0,
    2245,   159,  1803,     0,  1447,     0,     0,     0,     0,     0,
       0,  1115,     0,     0,     0,     0,     0,   968,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1097,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   754,   754,   754,     0,   754,   754,
     754,   754,   754,   754,     0,  2246,     0,   754,     0,     0,
       0,     0,     0,     0,   187,     0,     0,  2247,     0,  1098,
    1099,  1100,  1101,  1102,  1103,     0,     0,  2248,     0,     0,
    1116,     0,     0,     0,  1507,  1104,  1105,  1106,     0,     0,
       0,     0,     0,     0,     0,  2249,     0,     0,     0,     0,
       0,     0,     0,   188,     0,  2250,     0,  1533,  2251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1556,   968,
     189,  2252,     0,     0,     0,     0,     0,     0,  1040,  1041,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1052,     0,     0,     0,     0,     0,  1065,  1066,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,  1080,   966,     0,     0,     0,     0,     0,     0,  2253,
     191,     0,     0,     0,  1603,     0,     0,     0,     0,     0,
     192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   913,     0,   730,     0,     0,     0,   193,  2254,
       0,     0,     0,     0,     0,     0,     0,     0,   194,  2255,
       0,     0,     0,     0,     0,     0,  1795,  1795,  1795,  1795,
    1795,  1795,  2055,  2056,   195,  1107,     0,     0,  1108,  2256,
       0,     0,  2257,  2065,  2258,     0,     0,     0,     0,  2351,
    1800,  2354,  2355,  2356,  2357,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2259,   196,     0,     0,     0,     0,  1795,
       0,  1795,  2260,     0,     0,     0,     0,     0,     0,     0,
       0,  2117,  2118,  2119,  2120,     0,     0,   197,  1795,     0,
       0,     0,  2390,     0,     0,     0,  2126,     0,     0,     0,
       0,     0,   198,     0,     0,     0,     0,     0,     0,   199,
       0,  1879,   200,     0,     0,     0,     0,   730,   730,   730,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1733,     0,   201,     0,     0,   202,     0,   203,     0,  1741,
       0,     0,     0,     0,  1109,     0,     0,     0,     0,     0,
     913,     0,     0,     0,     0,     0,   204,     0,     0,  1110,
       0,     0,  1795,  1111,     0,     0,     0,     0,     0,     0,
     151,  2189,  2190,     0,     0,   205,     0,     0,  2194,  2195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,     0,     0,   913,     0,   913,
       0,     0,  1364,   907,     0,     0,     0,     0,     0,     0,
    1372,  1373,     0,     0,     0,     0,     0,     0,     0,  1113,
       0,     0,     0,     0,  1377,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   966,  1900,  1388,  1114,  1390,  1391,
       0,  1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,
    1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,     0,  1795,
       0,  1795,  1795,  1795,  1795,     0,     0,   913,  1409,  1410,
       0,     0,     0,  1412,     0,  1413,     0,     0,     0,     0,
    2293,  2294,  2543,     0,  2545,  2546,  2547,  2548,     0,  2301,
       0,  1795,     0,     0,     0,     0,     0,  2312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1795,  1795,     0,
       0,     0,     0,     0,  1879,  2327,  2328,     0,  1115,  1795,
     913,     0,   913,     0,  1795,     0,  1443,     0,     0,     0,
       0,   913,  1097,     0,  1795,     0,     0,     0,  1795,     0,
       0,  1795,  2570,     0,     0,     0,     0,  2587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2601,     0,     0,
    1096,  1097,     0,     0,  2601,     0,     0,     0,     0,  2042,
       0,     0,  2365,  1528,  2367,  1098,  1099,  1100,  1101,  1102,
    1103,  2369,     0,  2371,     0,     0,     0,  1116,     0,     0,
       0,  1104,  1105,  1106,     0,     0,  1795,     0,  2064,     0,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,  1105,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2438,  2439,     0,     0,  2440,  2441,     0,     0,  1795,     0,
       0,     0,     0,  1795,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2458,     0,
       0,  2351,     0,     0,     0,  1795,  2701,  1795,     0,     0,
       0,  1795,  1795,  1795,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1795,     0,     0,     0,  2714,     0,  2085,     0,     0,     0,
       0,     0,   966,     0,     0,  1647,     0,     0,     0,     0,
       0,  1107,     0,  2723,  1108,  2187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1671,  1672,  1673,     0,  1675,
       0,     0,     0,     0,  2510,     0,     0,    39,  2515,     0,
    1107,     0,     0,  1108,     0,     0,     0,     0,     0,   730,
       0,     0,     0,     0,     0,  1647,     0,     0,  2214,  1795,
       0,     0,     0,     0,     0,     0,     0,     0,  2530,     0,
       0,  2229,     0,     0,     0,    40,    41,    42,   913,     0,
       0,     0,  2765,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2551,     0,     0,
       0,     0,  1795,  1795,     0,     0,     0,    43,     0,     0,
       0,     0,    44,  1795,     0,     0,     0,     0,  1795,   913,
       0,     0,     0,     0,     0,  1879,  1879,    45,     0,     0,
    1109,     0,    46,  1738,    47,     0,  2819,     0,     0,  1647,
       0,  2601,     0,     0,    48,  1110,     0,    49,  1647,  1111,
      50,  1795,   968,    51,     0,     0,     0,     0,    52,  1109,
    1795,  2319,   730,   747,     0,  2323,     0,     0,     0,     0,
       0,     0,     0,     0,  1110,     0,    53,  2333,  1111,     0,
       0,     0,     0,   730,     0,     0,     0,  1112,     0,     0,
       0,     0,    54,     0,     0,    55,    56,     0,     0,     0,
       0,     0,    57,     0,  1795,     0,     0,  1795,  1795,     0,
       0,     0,     0,    58,     0,  1113,  1112,     0,  1795,     0,
       0,     0,     0,     0,     0,   140,     0,     0,    59,     0,
    2876,     0,     0,  1114,  1795,    60,     0,     0,     0,     0,
       0,  2601,    61,     0,  1113,    62,    63,    64,     0,    65,
      66,     0,     0,     0,     0,     0,     0,  2765,     0,     0,
       0,     0,  1114,     0,     0,     0,    67,     0,     0,     0,
       0,  2693,     0,  1795,     0,     0,     0, -1694,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,    69,    70,     0,    71,     0,  2819,     0,     0,     0,
    2436,     0,     0,     0,     0,   966,     0,     0,     0,     0,
       0,    72,    73,     0,  1115,     0,     0,     0, -1694,  1997,
       0,  1997,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2214,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,  1115,     0,    75,    76,   913,    77,  1092,
    1093,  1094,  1095,  1096,  1097,     0,  2732,  2733,     0,  2735,
   -1694,  2737,  2738,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1116,  2087,     0,     0,     0,     0,     0,
   -1694,     0,     0,     0, -1694,     0,   913,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
      78,   159,  1116,  1104,  1105,  1106, -1694,     0,     0,     0,
       0,     0,  1444,     0, -1694,     0, -1694,     0,     0,     0,
    2802,     0,     0,     0,   968, -1694,     0,     0,     0,     0,
       0, -1694,     0,     0,     0,     0,     0,     0,  2132, -1694,
     159,     0,     0, -1694,     0,     0,     0,   730,     0,     0,
   -1694,     0,     0,   730, -1694, -1694, -1694, -1694,     0,     0,
       0,     0,  2826,     0,  2827,     0,     0,     0,     0, -1694,
       0,     0,     0,     0,     0,     0,   730,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1694,     0,     0, -1694,
       0, -1694,     0,     0,     0,     0,     0,     0, -1694,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1694,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1694,  2592,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1694, -1694,
       0,     0,     0,  1107,     0,     0,  1108,     0,     0,  2214,
       0,     0,     0, -1694,  2620,     0,  2622,     0,     0,     0,
   -1694,     0,     0,     0, -1694,     0,  2243,     0,     0,     0,
       0,     0,     0, -1694, -1694, -1694,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2896,     0,     0,   758,   759,     0,     0,     0,
       0,   292,   760,   761,  -577,     0,   913,  1093,  1094,  1095,
    1096,  1097,   762,   763,  1647,     0,     0,  2903,  2904,   764,
       0,  2905,     0,     0,     0,     0,   968,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1694,     0,     0,     0,     0,     0,     0,   765,
       0,     0,     0, -1694,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
    1104,  1105,  1106,  2316,     0,     0,  1647,  1110,     0,     0,
       0,  1111,     0,     0,  1647,     0,     0,     0,     0,     0,
       0,     0,     0, -1694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   968,     0,     0,     0,     0,     0,     0,  1112,
     730,   730,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     766,     0,     0,     0,     0,     0,     0,  1113,     0,     0,
       0,     0,     0,     0, -1694,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   913,     0,     0,   913,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1694,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,     0,  1108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2592,     0,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,   767, -1694,
       0,     0,     0,   768,     0,     0,  1115,     0,     0,     0,
       0,     0,     0, -1694, -1694, -1694, -1694, -1694, -1694, -1694,
       0, -1694, -1694,     0,     0,     0,     0,    40,    41,   769,
       0,     0,     0,     0,     0,     0,     0,     0, -1694,     0,
       0,     0,     0,     0,  1179,  1179,  1179,  1179,  1179,  1179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,    44,  2498,     0,     0,     0,     0,
       0,     0,     0,     0,  1830,  1116,     0,     0,     0,    45,
       0,     0,     0,     0,    46,     0,    47,     0,     0,  1109,
       0,     0,  2544,   770,     0,     0,    48,     0,   771,    49,
       0,   772,    50,     0,  1110,    51,     0,     0,  1111,     0,
      52,     0,   773,     0,  1647,     0,     0,     0,   774,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   775,     0,
    2563,     0,     0,   776,  2566,     0,   777,     0,     0,   778,
       0,     0,     0,     0,    54,     0,  1112,    55,   779,   758,
     759,     0,     0,     0,    57,   292,   760,   761,  -577,     0,
       0,     0,     0,     0,     0,    58,   762,   763,     0,   730,
       0,     0,     0,   764,  1113,   968,     0,  2780,     0,     0,
      59,     0,     0,     0,     0,     0,     0,    60,  1202,   780,
       0,     0,  1114,   781,    61,     0,     0,    62,    63,    64,
       0,   782,    66,   765,     0,     0,     0,     0,     0,     0,
       0,     0,   783,     0,     0,     0,     0,     0,   784,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2781,     0,     0,     0,     0,     0,
       0,    68,   785,    69,    70,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2782,
       0,     0,     0,    72,    73,     0,     0,     0,  2783,     0,
       0,     0,     0,  1115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   786,     0,
       0,     0,     0,     0,   766,   787,     0,   788,    76,     0,
      77,     0,  2784,     0,     0,  1831,     0,   789,   790,   791,
    2785,     0,     0,     0,     0,     0,   792,  1832,     0,   112,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1833,     0,    39,     0,     0,     0,     0,  1834,     0,
       0,     0,   767,     0,     0,     0,     0,   768,     0,     0,
     758,   759,     0,  2786,     0,     0,   292,   760,   761,     0,
       0,     0,     0,     0,     0,     0,     0,   762,   763,     0,
       0,    40,    41,   769,   764,     0,     0,  1835,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1836,     0,    43,   765,     0,     0,     0,    44,     0,
       0,  1837,  1838,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,  1839,    46,     0,
      47,     0,     0,     0,     0,     0,     0,   770,     0,     0,
      48,     0,   771,    49,     0,   772,    50,     0,  1840,    51,
       0,  1841,  1842,     0,    52,     0,   773,  1843,     0,     0,
       0,     0,   774,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   775,     0,     0,     0,     0,   776,     0,     0,
     777,     0,     0,   778,     0,     0,     0,     0,    54,     0,
       0,    55,   779,     0,     0,   766,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,  1844,     0,     0,     0,
       0,     0,     0,     0,    59,     0,  2787,     0,  1845,     0,
       0,    60,     0,   780,     0,     0,     0,   781,    61,  1647,
       0,    62,    63,    64,     0,   782,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   783,     0,     0,     0,
       0,     0,   784,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    68,   785,    69,    70,     0,
      71,     0,     0,   767,     0,     0,     0,     0,   768,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,     0,   758,   759,     0,     0,     0,     0,   292,   760,
     761,     0,    40,    41,   769,     0,     0,     0,     0,   762,
     763,     0,   786,     0,     0,     0,   764,     0,     0,   787,
       0,   788,    76,     0,    77,     0,     0,     0,     0,     0,
       0,   789,   790,   791,    43,     0,     0,     0,     0,    44,
     792,     0,     0,   112,     0,     0,   765,     0,     0,     0,
       0,   295,     0,     0,    45,     0,     0,     0,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,   770,     0,
       0,    48,     0,   771,    49,     0,   772,    50,     0,     0,
      51,     0,     0,     0,     0,    52,    78,   773,     0,     0,
       0,     0,     0,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   775,     0,     0,     0,     0,   776,     0,
       0,   777,     0,     0,   778,     0,     0,     0,     0,    54,
       0,     0,    55,   779,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,   766,     0,     0,
      58,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,     0,     0,    59,     0,     0,     0,     0,
       0,     0,    60,  1202,   780,     0,     0,     0,   781,    61,
       0,     0,    62,    63,    64,     0,   782,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   783,     0,     0,
       0,     0,     0,   784,     0,  1098,  1099,  1100,  1101,  1102,
    1103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,  1105,  1106,     0,     0,    68,   785,    69,    70,
       0,    71,     0,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,   767,     0,     0,    72,    73,
     768,     0,     0,   758,   759,     0,     0,     0,     0,   292,
     760,   761,     0,     0,     0,     0,     0,     0,     0,     0,
     762,   763,     0,   786,    40,    41,   769,   764,     0,     0,
     787,     0,   788,    76,     0,    77,     0,     0,     0,     0,
       0,     0,   789,   790,   791,     0,     0,     0,     0,     0,
       0,   792,     0,     0,   112,     0,    43,   765,     0,     0,
       0,    44,   295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
     770,     0,     0,    48,     0,   771,    49,    78,   772,    50,
       0,     0,    51,     0,     0,     0,     0,    52,     0,   773,
       0,  1107,     0,     0,  1108,   774,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   775,     0,     0,     0,     0,
     776,     0,     0,   777,     0,     0,   778,     0,     0,     0,
       0,    54,     0,     0,    55,   779,     0,     0,   766,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,    60,     0,   780,     0,     0,     0,
     781,    61,     0,     0,    62,    63,    64,     0,   782,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   783,
       0,  2011,     0,     0,     0,   784,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1109,     0,     0,     0,     0,     0,     0,    39,    68,   785,
      69,    70,     0,    71,     0,  1110,   767,     0,     0,  1111,
       0,   768,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,   758,   759,     0,     0,     0,
       0,   292,   760,   761,     0,    40,    41,   769,     0,     0,
       0,     0,   762,   763,     0,   786,     0,  1112,     0,   764,
       0,     0,   787,     0,   788,    76,     0,    77,     0,     0,
       0,     0,     0,     0,   789,   790,   791,    43,     0,     0,
       0,     0,    44,   792,     0,  1113,   112,     0,     0,   765,
       0,     0,     0,     0,   295,     0,     0,    45,     0,     0,
       0,     0,    46,  1114,    47,     0,     0,     0,     0,     0,
       0,   770,     0,     0,    48,     0,   771,    49,     0,   772,
      50,     0,     0,    51,     0,     0,     0,     0,    52,    78,
     773,     0,     0,     0,     0,     0,   774,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   775,     0,     0,     0,
       0,   776,     0,     0,   777,     0,     0,   778,     0,     0,
       0,     0,    54,     0,     0,    55,   779,     0,     0,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
     766,     0,     0,    58,  1115,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,     0,     0,    59,     0,
       0,     0,     0,     0,     0,    60,  2337,   780,     0,     0,
       0,   781,    61,     0,     0,    62,    63,    64,     0,   782,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     783,     0,     0,     0,     0,     0,   784,     0,  1098,  1099,
    1100,  1101,  1102,  1103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1116,  1104,  1105,  1106,     0,     0,    68,
     785,    69,    70,     0,    71,     0,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,   767,     0,
       0,    72,    73,   768,     0,     0,   758,   759,     0,     0,
       0,     0,   292,   760,   761,     0,     0,     0,     0,     0,
       0,     0,     0,   762,   763,     0,   786,    40,    41,   769,
     764,     0,     0,   787,     0,   788,    76,     0,    77,     0,
       0,     0,     0,     0,     0,   789,   790,   791,     0,     0,
       0,     0,     0,     0,   792,     0,     0,   112,     0,    43,
     765,     0,     0,     0,    44,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,    46,     0,    47,     0,     0,     0,
       0,     0,     0,   770,     0,     0,    48,  -804,   771,    49,
      78,   772,    50,     0,     0,    51,     0,     0,     0,     0,
      52,     0,   773,     0,  1107,     0,     0,  1108,   774,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   775,     0,
       0,     0,     0,   776,     0,     0,   777,     0,     0,   778,
       0,     0,     0,     0,    54,     0,     0,    55,   779,     0,
       0,   766,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,    60,     0,   780,
       0,     0,     0,   781,    61,     0,     0,    62,    63,    64,
       0,   782,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   783,     0,     0,     0,     0,     0,   784,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1109,     0,     0,     0,     0,     0,     0,
      39,    68,   785,    69,    70,     0,    71,     0,  1110,   767,
       0,     0,  1111,     0,   768,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,     0,     0,     0,  1775,  1776,
       0,  1777,     0,     0,   292,  1778,  1779,     0,    40,    41,
     769,     0,     0,     0,     0,  1780,     0,     0,   786,     0,
    1112,     0,     0,     0,     0,   787,     0,   788,    76,     0,
      77,     0,     0,     0,     0,     0,     0,   789,   790,   791,
      43,     0,     0,     0,     0,    44,   792,     0,  1113,   112,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
      45,     0,     0,     0,     0,    46,  1114,    47,     0,     0,
       0,     0,     0,     0,   770,     0,     0,    48,     0,   771,
      49,     0,   772,    50,     0,     0,    51,     0,     0,     0,
       0,    52,    78,   773,     0,     0,     0,     0,     0,   774,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   775,
       0,     0,     0,     0,   776,     0,     0,   777,     0,     0,
     778,     0,     0,     0,     0,    54,     0,     0,    55,   779,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,  1115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,     0,     0,     0,     0,     0,     0,    60,     0,
     780,     0,     0,     0,   781,    61,     0,     0,    62,    63,
      64,     0,   782,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   783,     0,     0,     0,     0,     0,   784,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1116,     0,     0,     0,
       0,     0,    68,   785,    69,    70,     0,    71,     0,     0,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,  2144,     0,     0,  1775,
    1776,     0,  1777,     0,     0,   292,  1778,  1779,     0,     0,
       0,     0,     0,     0,     0,     0,  1780,     0,     0,   786,
      40,    41,    42,     0,     0,     0,   787,     0,   788,    76,
       0,    77,     0,     0,     0,     0,     0,     0,   789,   790,
     791,     0,     0,     0,     0,     0,     0,   792,     0,     0,
     112,     0,    43,     0,     0,     0,     0,    44,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    78,  1781,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,  1782,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,  1783,     0,     0,  2145,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
      55,  2146,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2388,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
      60,     0,  1786,     0,     0,     0,     0,    61,     0,     0,
      62,    63,    64,     0,  1787,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    68,  1788,    69,    70,     0,    71,
       0,  1775,  1776,     0,  1777,     0,     0,   292,  1778,  1779,
       0,     0,     0,     0,     0,     0,    72,    73,  1780,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,    41,    42,     0,  1789,     0,     0,     0,     0,
       0,    74,     0,     0,     0,     0,     0,     0,  1790,     0,
      75,    76,     0,    77,     0,     0,     0,     0,     0,     0,
    1791,  1792,  2147,    43,     0,     0,     0,     0,    44,  1793,
       0,     0,   733,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,    45,     0,     0,     0,     0,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    49,     0,  1781,    50,     0,     0,    51,
       0,     0,     0,     0,    52,    78,     0,     0,     0,     0,
    1782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,  1783,     0,     0,
    2579,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,    55,    56,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,    60,     0,  1786,     0,     0,     0,     0,    61,     0,
       0,    62,    63,    64,     0,  1787,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,  1788,    69,    70,  2144,
      71,     0,  1775,  1776,     0,  1777,     0,     0,   292,  1778,
    1779,     0,     0,     0,     0,     0,     0,    72,    73,  1780,
       0,     0,     0,    40,    41,    42,     0,     0,     0,     0,
    2580,     0,     0,     0,     0,     0,  1789,     0,     0,     0,
       0,     0,    74,     0,     0,     0,  2581,  2582,     0,  1790,
       0,    75,    76,     0,    77,    43,     0,     0,     0,     0,
      44,  1791,  1792,     0,     0,     0,     0,     0,     0,     0,
    1793,     0,     0,   733,     0,    45,     0,     0,     0,     0,
      46,   295,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,    49,     0,  1781,    50,     0,
       0,    51,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,  1782,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,  1783,
       0,     0,  2145,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,    55,  2146,     0,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,    60,     0,  1786,     0,     0,     0,     0,
      61,     0,     0,    62,    63,    64,     0,  1787,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    68,  1788,    69,
      70,     0,    71,     0,  1775,  1776,     0,  1777,     0,     0,
     292,  1778,  1779,     0,     0,     0,     0,     0,     0,    72,
      73,  1780,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,    42,     0,  1789,     0,
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,  1790,     0,    75,    76,     0,    77,     0,     0,     0,
       0,     0,     0,  1791,  1792,  2147,    43,     0,     0,     0,
       0,    44,  1793,     0,     0,   733,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,     0,  1781,    50,
       0,     0,    51,     0,     0,     0,     0,    52,    78,     0,
       0,     0,     0,  1782,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
    1783,     0,     0,  2579,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,     0,     0,
       0,    57,  1091,  1092,  1093,  1094,  1095,  1096,  1097,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2388,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,    60,  2597,  1786,     0,     0,     0,
       0,    61,     0,     0,    62,    63,    64,     0,  1787,    66,
       0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,  1104,  1105,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,  1788,
      69,    70,     0,    71,     0,  1775,  1776,     0,  1777,     0,
       0,   292,  1778,  1779,     0,     0,     0,     0,     0,     0,
      72,    73,  1780,     0,     0,     0,    40,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1789,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,  1790,     0,    75,    76,     0,    77,    43,     0,
       0,     0,     0,    44,  1791,  1792,     0,     0,     0,     0,
       0,     0,     0,  1793,     0,     0,   733,     0,    45,     0,
       0,     0,     0,    46,   295,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    49,     0,
    1781,    50,     0,     0,    51,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,  1782,     0,  1107,     0,    78,
    1108,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,  1783,     0,     0,  1784,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
       0,     0,     0,     0,     0,     0,    60,  1785,  1786,     0,
       0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
    1787,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1109,     0,     0,    39,
      68,  1788,    69,    70,     0,    71,     0,     0,     0,     0,
       0,  1110,     0,  2144,     0,  1111,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,  1775,  1776,     0,
    1777,     0,     0,   292,  1778,  1779,     0,    40,    41,    42,
       0,  1789,     0,     0,  1780,     0,     0,    74,     0,     0,
       0,     0,     0,  1112,  1790,     0,    75,    76,     0,    77,
       0,     0,     0,     0,     0,     0,  1791,  1792,     0,    43,
       0,     0,     0,     0,    44,  1793,     0,     0,   733,     0,
       0,  1113,     0,     0,     0,     0,   295,     0,     0,    45,
       0,     0,     0,     0,    46,     0,    47,     0,     0,  1114,
       0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
       0,  1781,    50,     0,     0,    51,     0,     0,     0,     0,
      52,    78,     0,     0,     0,     0,  1782,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,     0,     0,  1783,     0,     0,  2145,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,    55,  2146,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
    1115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,    60,     0,  1786,
       0,     0,     0,     0,    61,     0,     0,    62,    63,    64,
       0,  1787,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1116,
       0,    68,  1788,    69,    70,     0,    71,     0,     0,     0,
       0,    39,     0,     0,     0,     0,     0,     0,     0,  1775,
    1776,     0,  1777,    72,    73,   292,  1778,  1779,     0,     0,
       0,     0,     0,     0,     0,     0,  1780,     0,     0,     0,
       0,     0,  1789,     0,     0,     0,     0,     0,    74,    40,
      41,    42,     0,     0,     0,  1790,     0,    75,    76,     0,
      77,     0,     0,     0,     0,     0,     0,  1791,  1792,     0,
       0,     0,     0,     0,     0,     0,  1793,     0,     0,   733,
       0,    43,     0,     0,     0,     0,    44,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,    46,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,    49,    78,  1781,    50,     0,     0,    51,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,  1782,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,  1783,     0,     0,  2596,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,    55,
      56,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,    60,
    2597,  1786,     0,     0,     0,     0,    61,     0,     0,    62,
      63,    64,     0,  1787,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,  1788,    69,    70,     0,    71,     0,
    1775,  1776,     0,  1777,     0,     0,   292,  1778,  1779,     0,
       0,     0,     0,     0,     0,    72,    73,  1780,     0,     0,
       0,    40,    41,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1789,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,  1790,     0,    75,
      76,     0,    77,    43,     0,     0,     0,     0,    44,  1791,
    1792,     0,     0,     0,     0,     0,     0,     0,  1793,     0,
       0,   733,     0,    45,     0,     0,     0,     0,    46,   295,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    49,     0,  1781,    50,     0,     0,    51,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
    1782,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,  1783,     0,     0,
    2579,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,    55,    56,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,    60,  2597,  1786,     0,     0,     0,     0,    61,     0,
       0,    62,    63,    64,     0,  1787,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    68,  1788,    69,    70,     0,
      71,     0,  1775,  1776,     0,  1777,     0,     0,   292,  1778,
    1779,     0,     0,     0,     0,     0,     0,    72,    73,  1780,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    41,    42,     0,  1789,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,  1790,
       0,    75,    76,     0,    77,     0,     0,     0,     0,     0,
       0,  1791,  1792,     0,    43,     0,     0,     0,     0,    44,
    1793,     0,     0,   733,     0,     0,     0,     0,     0,     0,
       0,   295,     0,     0,    45,     0,     0,     0,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,    49,     0,  1781,    50,     0,     0,
      51,     0,     0,     0,     0,    52,    78,     0,     0,     0,
       0,  1782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,  1783,     0,
       0,  1784,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,    55,    56,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2388,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,    60,     0,  1786,     0,     0,     0,     0,    61,
       0,     0,    62,    63,    64,     0,  1787,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,  1788,    69,    70,
       0,    71,     0,  1775,  1776,     0,  1777,     0,     0,   292,
    1778,  1779,     0,     0,     0,     0,     0,     0,    72,    73,
    1780,     0,     0,     0,    40,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1789,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
    1790,     0,    75,    76,     0,    77,    43,     0,     0,     0,
       0,    44,  1791,  1792,     0,     0,     0,     0,     0,     0,
       0,  1793,     0,     0,   733,     0,    45,     0,     0,     0,
       0,    46,   295,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,     0,  1781,    50,
       0,     0,    51,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,  1782,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,    53,     0,   153,   154,     0,
    1783,     0,     0,  1784,     0,   155,     0,     0,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,    60,  2816,  1786,     0,     0,     0,
       0,    61,     0,     0,    62,    63,    64,     0,  1787,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    68,  1788,
      69,    70,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    41,    42,     0,  1789,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,  1790,     0,    75,    76,     0,    77,     0,     0,
       0,     0,     0,     0,  1791,  1792,     0,    43,     0,     0,
       0,     0,    44,  1793,     0,     0,   733,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,    45,     0,     0,
       0,     0,    46,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    49,     0,  1781,
      50,     0,     0,    51,     0,     0,     0,     0,    52,    78,
       0,    39,     0,     0,  1782,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,  1783,     0,     0,  1784,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,    55,    56,     0,     0,    40,
      41,    42,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
       0,    43,     0,     0,     0,    60,    44,  1786,     0,     0,
       0,     0,    61,     0,     0,    62,    63,    64,     0,  1787,
      66,    45,     0,     0,     0,     0,    46,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    67,     0,    48,     0,
       0,    49,     0,     0,    50,     0,     0,    51,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,    68,
    1788,    69,    70,     0,    71,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,    72,    73,     0,     0,     0,    54,     0,     0,    55,
      56,     0,     0,     0,     0,     0,    57,     0,     0,     0,
    1789,     0,     0,     0,     0,     0,    74,    58,     0,     0,
       0,     0,     0,  1790,     0,    75,    76,     0,    77,     0,
       0,     0,    59,     0,     0,  1791,  1792,     0,     0,    60,
       0,     0,     0,     0,  1793,     0,    61,   733,     0,    62,
      63,    64,     0,    65,    66,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,    68,     0,    69,    70,     0,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,    72,    73,     0,     0,     0,
     488,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   490,     0,     0,     0,
      74,     0,     0,     0,     0,   491,     0,     0,     0,    75,
      76,     0,    77,     0,     0,     0,   492,   493,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   495,     0,   496,   497,   498,     2,     3,   499,
       4,     5,   500,     0,   501,     6,   502,   503,     0,     0,
       0,     0,     0,   504,     0,     0,   505,     0,   506,   507,
     508,     0,     7,     8,     0,     0,     0,     0,   509,     0,
     510,   511,     0,   512,    78,   513,   514,     0,     0,   515,
       9,    10,     0,     0,   516,   517,   518,     0,   519,   520,
       0,     0,     0,   521,   522,     0,   523,     0,     0,     0,
     524,     0,   525,   526,     0,     0,   527,     0,     0,     0,
     528,     0,     0,   529,     0,   530,     0,   531,     0,   532,
       0,   533,   534,     0,   535,   536,   537,     0,     0,     0,
     538,     0,   539,   540,     0,   541,     0,     0,     0,     0,
       0,     0,     0,   542,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   544,     0,     0,
     545,   546,     0,     0,   547,   548,     0,     0,   549,   550,
       0,     0,     0,     0,     0,     0,     0,   551,   552,   553,
       0,   554,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,   556,   557,     0,   558,     0,     0,     0,   559,
     560,     0,     0,     0,   561,     0,     0,     0,     0,     0,
       0,     0,   562,     0,     0,     0,     0,     0,     0,     0,
     563,     0,     0,     0,     0,     0,   564,   565,     0,     0,
       0,     0,   566,     0,     0,   567,     0,     0,     0,   568,
     569,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     570,     0,     0,  2167,     0,     0,     0,  1029,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,     0,     0,   572,     0,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,     0,     0,     0,
       0,   574,     0,   575,   576,     0,     0,     0,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,     0,     0,     0,     0,     0,     0,
       0,   578,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,     0,     0,     0,   580,  2015,     0,   581,
       0,  1029,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,     0,   582,   583,     0,     0,     0,   584,     0,
       0,     0,  1104,  1105,  1106,     0,     0,     0,     0,     0,
     585,     0,     0,     0,     0,     0,   586,   587,   588,   589,
       0,     0,   590,     0,     0,     0,   591,     0,     0,     0,
       0,     0,     0,   592,   593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   596,     0,
       0,   597,     0,     0,   598,     0,     0,     0,     0,     0,
     599,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,     0,     0,   600,     0,     0,
     601,     0,     0,     0,     0,     0,   602,     0,     0,   603,
       0,     0,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   604,     0,     0,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,     0,    43,  1108,     0,     0,     0,    44,
       0,     0,     0,     0,   606,   607,   608,   609,   610,   611,
     612,     0,     0,   613,    45,   614,     0,   615,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
      51,     0,     0,     0,     0,    52,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,  1351,     0,     0,     0,     0,
       0,  2168,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1109,     0,     0,     0,    59,     0,     0,    43,     0,
       0,     0,    60,    44,     0,     0,  1110,     0,     0,    61,
    1111,  1378,    62,    63,    64,     0,    65,    66,    45,     0,
       0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
       0,    50,     0,     0,    51,     0,     0,     0,  1112,    52,
       0,     0,    39,     0,     0,     0,    68,     0,    69,    70,
       0,    71,     0,     0,     0,     0,     0,    53,     0,  2068,
       0,     0,     0,     0,     0,     0,  1113,     0,    72,    73,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
      40,    41,    42,    57,  1114,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
       0,     0,    43,     0,     0,     0,    60,    44,     0,     0,
       0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
      65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
       0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,  1115,    39,    78,     0,     0,
      68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
       0,    53,     0,  2289,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
      55,    56,     0,     0,    40,    41,    42,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    58,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
       0,     0,     0,    59,  1116,     0,    43,     0,     0,     0,
      60,    44,     0,     0,     0,     0,     0,    61,     0,     0,
      62,    63,    64,     0,    65,    66,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    48,     0,     0,    49,     0,     0,    50,
       0,     0,    51,     0,     0,     0,     0,    52,     0,     0,
      39,    78,     0,     0,    68,     0,    69,    70,     0,    71,
       0,     0,     0,     0,     0,    53,     0,  2304,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,    40,    41,
      42,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    58,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,    77,     0,     0,     0,    59,     0,     0,
      43,     0,     0,     0,    60,    44,     0,     0,     0,     0,
       0,    61,     0,     0,    62,    63,    64,     0,    65,    66,
      45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    67,     0,    48,     0,     0,
      49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
       0,    52,     0,     0,    39,    78,     0,     0,    68,     0,
      69,    70,     0,    71,     0,     0,     0,     0,     0,    53,
       0,  2512,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
       0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
       0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
       0,     0,     0,     0,     0,    61,     0,     0,    62,    63,
      64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
      51,     0,     0,     0,     0,    52,     0,     0,    39,    78,
       0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
       0,     0,     0,    53,     0,  2637,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
       0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
       0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
       0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
       0,     0,    62,    63,    64,     0,    65,    66,    45,     0,
       0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
       0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
       0,     0,    39,    78,     0,     0,    68,     0,    69,    70,
       0,    71,     0,     0,     0,     0,     0,    53,     0,  2862,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
      40,    41,    42,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
       0,     0,    43,     0,     0,     0,    60,    44,     0,     0,
       0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
      65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
       0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,     0,    39,    78,     0,     0,
      68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,   292,   962,   963,     0,
       0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
      55,    56,     0,     0,    40,    41,    42,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    58,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
       0,     0,     0,    59,     0,     0,    43,     0,     0,     0,
      60,    44,     0,     0,     0,     0,     0,    61,     0,     0,
      62,    63,    64,     0,    65,    66,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    48,     0,     0,    49,     0,     0,    50,
       0,     0,    51,     0,     0,     0,     0,    52,     0,     0,
      39,    78,     0,     0,    68,     0,    69,    70,     0,    71,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
     292,   962,   963,     0,     0,     0,    72,    73,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,    40,    41,
      42,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    58,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,    77,     0,     0,     0,    59,     0,     0,
      43,     0,     0,     0,    60,    44,     0,     0,     0,     0,
       0,    61,     0,     0,    62,    63,    64,     0,    65,    66,
      45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    67,     0,    48,     0,     0,
      49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
       0,    52,     0,     0,    39,    78,     0,     0,    68,     0,
      69,    70,     0,    71,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
       0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
       0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
       0,     0,     0,     0,     0,    61,     0,     0,    62,    63,
      64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
       0,    47,     0,     0,     0,   964,     0,     0,     0,    67,
       0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
      51,     0,     0,     0,     0,    52,     0,     0,    39,    78,
       0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
       0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
       0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
       0,     0,    60,    44,     0,     0,     0,   965,     0,    61,
       0,     0,    62,    63,    64,     0,    65,    66,    45,     0,
       0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
       0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     109,     0,  -577,    78,     0,     0,    68,     0,    69,    70,
       0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
       2,     3,     0,     4,     5,     0,    60,     0,     6,     0,
       0,     0,     0,    61,   112,     0,    62,    63,    64,     0,
      65,    66,   295,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1029,     0,     0,    78,     0,     0,
      68,     0,    69,    70,     0,    71,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,     0,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,   110,     0,     0,    75,    76,     0,    77,
       0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,  1104,
    1105,  1106,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2061,     0,
    -577,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1968,    45,     0,     0,
       0,     0,    46,     0,    47,     0,     0,     0,     0,  1969,
       0,     0,     0,     0,    48,     0,     0,    49,     0,     0,
      50,     0,     0,    51,     0,     0,     0,     0,    52,  1107,
       0,    39,  1108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,   829,     0,     0,     0,     0,     0,     0,     0,
       0,   111,    54,     0,     0,    55,    56,     0,     0,    40,
      41,    42,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
       0,    43,     0,     0,     0,    60,    44,     0,     0,     0,
       0,     0,    61,     0,     0,    62,    63,    64,     0,    65,
      66,    45,     0,     0,     0,     0,    46,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    67,     0,    48,     0,
       0,    49,     0,     0,    50,     0,     0,    51,  1109,     0,
       0,     0,    52,     0,     0,    39,     0,     0,     0,    68,
       0,    69,    70,  1110,    71,     0,     0,  1111,     0,     0,
      53,     0,     0,     0,     0,     0,   906,     0,  -577,     0,
       0,    72,    73,     0,     0,     0,    54,     0,     0,    55,
      56,     0,     0,    40,    41,    42,    57,     0,     0,     0,
       0,     0,     0,     0,     0,  1112,    74,    58,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,    77,     0,
       0,     0,    59,  1970,     0,    43,     0,     0,     0,    60,
      44,     0,     0,  1113,     0,     0,    61,   112,     0,  1971,
      63,    64,     0,    65,    66,    45,     0,     0,     0,     0,
      46,  1114,    47,     0,     0,     0,     0,     0,     0,     0,
      67,     0,    48,     0,     0,    49,     0,     0,    50,     0,
       0,    51,     0,     0,     0,     0,    52,     0,     0,    39,
      78,     0,     0,    68,     0,    69,    70,     0,    71,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
      54,     0,     0,    55,    56,     0,     0,    40,    41,    42,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    58,  1115,     0,     0,     0,     0,     0,     0,    75,
      76,     0,    77,     0,     0,     0,    59,     0,     0,    43,
       0,     0,     0,    60,    44,     0,     0,   912,     0,     0,
      61,     0,     0,    62,    63,    64,     0,    65,    66,    45,
       0,     0,     0,     0,    46,     0,    47,     0,     0,     0,
       0,     0,     0,     0,    67,     0,    48,     0,     0,    49,
       0,     0,    50,     0,     0,    51,     0,     0,     0,     0,
      52,  1116,     0,    39,    78,     0,     0,    68,     0,    69,
      70,     0,    71,     0,     0,     0,     0,     0,    53,     0,
       0,  1806,     0,     0,     0,     0,     0,     0,     0,    72,
      73,     0,     0,     0,    54,     0,     0,    55,    56,     0,
       0,    40,    41,    42,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    58,     0,     0,     0,     0,
       0,     0,     0,    75,    76,     0,    77,     0,     0,     0,
      59,     0,     0,    43,     0,     0,     0,    60,    44,     0,
       0,   912,     0,     0,    61,   112,     0,    62,    63,    64,
       0,    65,    66,    45,     0,     0,     0,     0,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    67,     0,
      48,     0,     0,    49,     0,     0,    50,     0,     0,    51,
       0,     0,     0,     0,    52,     0,     0,     0,    78,     0,
       0,    68,     0,    69,    70,     0,    71,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,     0,     0,     0,    54,     0,
       0,    55,    56,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    58,
       0,     0,   830,     0,    39,     0,     0,    75,    76,     0,
      77,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,  2331,     0,  -577,    61,   112,
       0,    62,    63,    64,     0,    65,    66,     0,     0,     0,
       0,     0,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,    43,    68,     0,    69,    70,    44,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,    72,    73,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
      51,     0,    74,     0,     0,    52,     0,     0,    39,     0,
       0,    75,    76,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,   150,
       0,     0,     0,   112,     0,     0,     0,     0,     0,    54,
       0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1852,     0,     0,     0,    59,    78,     0,    43,     0,
       0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
       0,     0,    62,    63,    64,     0,    65,    66,    45,     0,
       0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
       0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
       0,     0,    39,     0,     0,     0,    68,     0,    69,    70,
       0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,   732,     0,     0,     0,     0,    72,    73,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
      40,    41,    42,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
       0,     0,    43,     0,     0,     0,    60,    44,     0,     0,
       0,     0,     0,    61,   112,     0,    62,    63,    64,     0,
      65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
       0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,     0,    39,    78,     0,     0,
      68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,   912,     0,     0,
       0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
      55,    56,     0,     0,    40,    41,    42,    57,     0,     0,
       0,  2005,     0,     0,     0,     0,     0,    74,    58,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
       0,     0,     0,    59,     0,     0,    43,     0,     0,     0,
      60,    44,     0,     0,     0,     0,     0,    61,   112,     0,
      62,    63,    64,     0,    65,    66,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    48,     0,     0,    49,     0,     0,    50,
       0,     0,    51,     0,     0,     0,     0,    52,     0,     0,
      39,    78,     0,     0,    68,     0,    69,    70,     0,    71,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,   109,     0,     0,     0,     0,    72,    73,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,    40,    41,
      42,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    58,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,    77,     0,     0,     0,    59,     0,     0,
      43,     0,     0,     0,    60,    44,     0,     0,     0,     0,
       0,    61,   112,     0,    62,    63,    64,     0,    65,    66,
      45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    67,     0,    48,     0,     0,
      49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
       0,    52,     0,     0,    39,    78,     0,     0,    68,     0,
      69,    70,     0,    71,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,  1247,     0,     0,     0,     0,
      72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
       0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
       0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
       0,     0,     0,     0,     0,    61,   112,     0,    62,    63,
      64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
      51,     0,     0,     0,     0,    52,     0,     0,    39,    78,
       0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,  1286,
       0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
       0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
       0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
       0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
     733,     0,    62,    63,    64,     0,    65,    66,    45,     0,
       0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
       0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
       0,     0,    39,    78,     0,     0,    68,     0,    69,    70,
       0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,  1420,     0,     0,     0,     0,    72,    73,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
      40,    41,    42,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
       0,     0,    43,     0,     0,     0,    60,    44,     0,     0,
       0,     0,     0,    61,   112,     0,    62,    63,    64,     0,
      65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
       0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,     0,    39,    78,     0,     0,
      68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,   906,     0,     0,
       0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
      55,    56,     0,     0,    40,    41,    42,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    58,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
       0,     0,     0,    59,     0,     0,    43,     0,     0,     0,
      60,    44,     0,     0,     0,     0,     0,    61,   112,     0,
      62,    63,    64,     0,    65,    66,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    48,     0,     0,    49,     0,     0,    50,
       0,     0,    51,     0,     0,     0,     0,    52,     0,     0,
      39,    78,     0,     0,    68,     0,    69,    70,     0,    71,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,  2228,     0,     0,     0,     0,    72,    73,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,    40,    41,
      42,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    58,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,    77,     0,     0,     0,    59,     0,     0,
      43,     0,     0,     0,    60,    44,     0,     0,     0,     0,
       0,    61,   112,     0,    62,    63,    64,     0,    65,    66,
      45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    67,     0,    48,     0,     0,
      49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
       0,    52,     0,     0,    39,    78,     0,     0,    68,     0,
      69,    70,     0,    71,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,  1029,     0,     0,     0,     0,
      72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
       0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
       0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
       0,     0,     0,     0,     0,    61,   112,     0,    62,    63,
      64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
      51,     0,     0,     0,     0,    52,     0,     0,    39,    78,
       0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
       0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
       0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
       0,     0,    60,    44,     0,     0,  1029,     0,     0,    61,
     112,     0,    62,    63,    64,     0,    65,    66,    45,     0,
       0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
       0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
       0,     0,    39,    78,     0,     0,    68,     0,    69,    70,
       0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
      40,    41,    42,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
       0,     0,    43,     0,     0,     0,    60,    44,     0,     0,
    1029,  2770,     0,    61,   112,     0,    62,    63,    64,     0,
      65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
       0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,     0,     0,    78,     0,     0,
      68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
      55,    56,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    58,     0,
       0,     0,     0,    39,     0,     0,    75,    76,     0,    77,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,   103,     0,     0,    61,   112,     0,
      62,    63,    64,     0,    65,    66,     0,     0,     0,     0,
       0,    40,    41,    42,     0,     0,     0,     0,     0,     0,
       0,    67,     0,  2487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    43,    68,     0,    69,    70,    44,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,    72,    73,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    49,     0,     0,    50,     0,     0,    51,
       0,    74,     0,     0,    52,     0,     0,    39,     0,     0,
      75,    76,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,   732,     0,
    2660,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,    55,    56,     0,     0,    40,    41,    42,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    78,     0,    43,     0,     0,
       0,    60,    44,     0,     0,     0,     0,     0,    61,     0,
       0,    62,    63,    64,     0,    65,    66,    45,     0,     0,
       0,     0,    46,     0,    47,     0,     0,     0,     0,     0,
       0,     0,    67,     0,    48,     0,     0,    49,     0,     0,
      50,     0,     0,    51,     0,     0,     0,     0,    52,     0,
       0,    39,     0,     0,     0,    68,     0,    69,    70,     0,
      71,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,  1029,     0,     0,     0,     0,    72,    73,     0,
       0,     0,    54,     0,     0,    55,    56,     0,     0,    40,
      41,    42,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    58,     0,     0,     0,     0,     0,     0,
       0,    75,    76,     0,    77,     0,     0,     0,    59,     0,
       0,    43,     0,     0,     0,    60,    44,     0,     0,     0,
       0,     0,    61,     0,     0,    62,    63,    64,     0,    65,
      66,    45,     0,     0,     0,     0,    46,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    67,     0,    48,     0,
       0,    49,     0,     0,    50,     0,     0,    51,     0,     0,
       0,     0,    52,     0,     0,    39,    78,     0,     0,    68,
       0,    69,    70,     0,    71,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,  1235,     0,     0,     0,
       0,    72,    73,     0,     0,     0,    54,     0,     0,    55,
      56,     0,     0,    40,    41,    42,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    58,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,    77,     0,
       0,     0,    59,     0,     0,    43,     0,     0,     0,    60,
      44,     0,     0,     0,     0,     0,    61,     0,     0,    62,
      63,    64,     0,    65,    66,    45,     0,     0,     0,     0,
      46,     0,    47,     0,     0,     0,     0,     0,     0,     0,
      67,     0,    48,     0,     0,    49,     0,     0,    50,     0,
       0,    51,     0,     0,     0,     0,    52,     0,     0,    39,
      78,     0,     0,    68,     0,    69,    70,     0,    71,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
    1627,     0,     0,     0,     0,    72,    73,     0,     0,     0,
      54,     0,     0,    55,    56,     0,     0,    40,    41,    42,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    58,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,    77,     0,     0,     0,    59,     0,     0,    43,
       0,     0,     0,    60,    44,     0,     0,     0,     0,     0,
      61,     0,     0,    62,    63,    64,     0,    65,    66,    45,
       0,     0,     0,     0,    46,     0,    47,     0,     0,     0,
       0,     0,     0,     0,    67,     0,    48,     0,     0,    49,
       0,     0,    50,     0,     0,    51,     0,     0,     0,     0,
      52,     0,     0,    39,    78,     0,     0,    68,     0,    69,
      70,     0,    71,     0,     0,     0,     0,     0,    53,     0,
       0,     0,     0,     0,  1895,     0,     0,     0,     0,    72,
      73,     0,     0,     0,    54,     0,     0,    55,    56,     0,
       0,    40,    41,    42,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    58,     0,     0,     0,     0,
       0,     0,     0,    75,    76,     0,    77,     0,     0,     0,
      59,     0,     0,    43,     0,     0,     0,    60,    44,     0,
       0,     0,     0,     0,    61,     0,     0,    62,    63,    64,
       0,    65,    66,    45,     0,     0,     0,     0,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    67,     0,
      48,     0,     0,    49,     0,     0,    50,     0,     0,    51,
       0,     0,     0,     0,    52,     0,     0,    39,    78,     0,
       0,    68,     0,    69,    70,     0,    71,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,  1175,
       0,     0,     0,    72,    73,     0,     0,     0,    54,     0,
       0,    55,    56,     0,     0,    40,    41,    42,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    58,
       0,     0,     0,     0,     0,     0,     0,    75,    76,     0,
      77,     0,     0,     0,    59,     0,     0,    43,     0,     0,
       0,    60,    44,     0,     0,     0,     0,     0,    61,     0,
       0,    62,    63,    64,     0,    65,    66,    45,     0,     0,
       0,     0,    46,     0,    47,     0,     0,     0,     0,     0,
       0,     0,    67,     0,    48,     0,     0,    49,     0,     0,
      50,     0,     0,    51,     0,     0,     0,     0,    52,     0,
       0,    39,    78,     0,     0,    68,     0,    69,    70,     0,
      71,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,  1068,     0,     0,     0,    72,    73,     0,
       0,     0,    54,     0,     0,    55,    56,     0,     0,    40,
      41,    42,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    58,     0,     0,     0,     0,     0,     0,
       0,    75,    76,     0,    77,     0,     0,     0,    59,     0,
       0,    43,     0,     0,     0,    60,    44,     0,     0,     0,
       0,     0,    61,     0,     0,    62,    63,    64,     0,    65,
      66,    45,     0,     0,     0,     0,    46,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    67,     0,    48,     0,
       0,    49,     0,     0,    50,     0,     0,    51,     0,     0,
       0,     0,    52,     0,     0,    39,    78,     0,     0,    68,
       0,    69,    70,     0,    71,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,   745,     0,     0,
       0,    72,    73,     0,     0,     0,    54,     0,     0,    55,
      56,     0,     0,    40,    41,    42,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    58,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,    77,     0,
       0,     0,    59,     0,     0,    43,     0,     0,     0,    60,
      44,     0,     0,     0,     0,     0,    61,     0,     0,    62,
      63,    64,     0,    65,    66,    45,     0,     0,     0,     0,
      46,     0,    47,     0,     0,     0,     0,     0,     0,     0,
      67,     0,    48,     0,     0,    49,     0,     0,    50,     0,
       0,    51,     0,     0,     0,     0,    52,     0,     0,    39,
      78,     0,     0,    68,     0,    69,    70,     0,    71,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,  1380,     0,     0,     0,    72,    73,     0,     0,     0,
      54,     0,     0,    55,    56,     0,     0,    40,    41,    42,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    58,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,    77,     0,     0,     0,    59,     0,     0,    43,
       0,     0,     0,    60,    44,     0,     0,     0,     0,     0,
      61,     0,     0,    62,    63,    64,     0,    65,    66,    45,
       0,     0,  1176,     0,    46,     0,    47,     0,     0,     0,
       0,     0,     0,     0,    67,     0,    48,     0,     0,    49,
       0,     0,    50,     0,     0,    51,     0,     0,     0,     0,
      52,     0,     0,    39,    78,     0,     0,    68,     0,    69,
      70,     0,    71,     0,     0,     0,     0,     0,    53,     0,
       0,     0,     0,     0,     0,  1177,  1069,     0,     0,    72,
      73,     0,     0,     0,    54,     0,     0,    55,    56,     0,
       0,    40,    41,    42,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    58,     0,     0,     0,     0,
       0,     0,     0,    75,    76,     0,    77,     0,     0,     0,
      59,     0,     0,    43,     0,     0,     0,    60,    44,     0,
       0,     0,  1740,     0,    61,   112,     0,    62,    63,    64,
       0,    65,    66,    45,     0,     0,     0,     0,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    67,     0,
      48,     0,     0,    49,     0,     0,    50,     0,     0,    51,
       0,     0,     0,     0,    52,     0,     0,    39,    78,     0,
       0,    68,     0,    69,    70,     0,    71,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,     0,     0,     0,    54,     0,
       0,    55,    56,     0,     0,    40,    41,    42,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    58,
       0,     0,     0,     0,     0,     0,     0,    75,    76,     0,
      77,     0,     0,     0,    59,     0,     0,    43,     0,     0,
       0,    60,    44,     0,     0,     0,     0,  -577,    61,   112,
       0,    62,    63,    64,     0,    65,    66,    45,     0,     0,
       0,     0,    46,     0,    47,     0,     0,     0,     0,     0,
       0,     0,    67,     0,    48,     0,     0,    49,     0,     0,
      50,     0,     0,    51,     0,     0,     0,     0,    52,     0,
       0,     0,    78,     0,     0,    68,     0,    69,    70,     0,
      71,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,     0,    54,     0,     0,    55,    56,     0,     0,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    58,     0,     0,     0,     0,    39,     0,
       0,    75,    76,     0,    77,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,    60,     0,     0,     0,     0,
       0,  -577,    61,   112,     0,    62,    63,    64,     0,    65,
      66,     0,     0,     0,     0,     0,    40,    41,    42,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    43,    68,
       0,    69,    70,    44,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,    72,    73,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    49,     0,
       0,    50,     0,     0,    51,     0,    74,     0,     0,    52,
       0,     0,    39,     0,     0,    75,    76,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,     0,     0,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
      40,    41,    42,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      78,     0,    43,     0,     0,     0,    60,    44,     0,     0,
       0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
      65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,     0,  1601,     0,     0,     0,    67,     0,    48,
       0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,     0,    39,     0,     0,     0,
      68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
      55,    56,     0,     0,    40,    41,    42,    57,     0,     0,
       0,     0,   923,     0,     0,     0,     0,    74,    58,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
       0,     0,     0,    59,     0,     0,    43,     0,     0,     0,
      60,    44,     0,     0,     0,     0,     0,    61,   112,     0,
      62,    63,    64,   924,    65,    66,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    48,     0,     0,    49,     0,     0,    50,
       0,     0,    51,     0,     0,     0,     0,    52,     0,     0,
       0,    78,     0,     0,    68,     0,    69,    70,     0,    71,
       0,     0,     0,   925,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,   926,
       0,    74,    58,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,    77,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,    60,     0,     0,     0,     0,     0,
       0,    61,   112,     0,    62,    63,    64,     0,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,     0,     0,     0,    78,     0,     0,    68,     0,
      69,    70,     0,    71,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,   927,     0,     0,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,     0,     0,     0,    74,    40,    41,    42,     0,
    1104,  1105,  1106,     0,    75,    76,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
     928,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    49,    78,
       0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
       0,   929,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
    1107,     0,     0,  1108,     0,     0,     0,     0,   930,    59,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   784,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,     0,     0,     0,     0,     0,     0,
      68,   931,    69,    70,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,     0,     0,     0,     0,     0,   786,     0,  1109,
       0,     0,  1104,  1105,  1106,     0,   788,    76,     0,    77,
       0,     0,     0,     0,  1110,     0,     0,     0,  1111,  1654,
       0,     0,     0,     0,     0,     0,     0,     0,   112,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1113,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1114,  1104,  1105,  1106,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,     0,     0,  1108,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,  1105,  1106,  1115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,  1105,  1106,     0,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
       0,     0,     0,  1107,     0,     0,  1108,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,     0,
       0,  1109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
    1111,  1655,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1104,  1105,
    1106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
    1107,     0,     0,  1108,     0,     0,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,     0,     0,     0,     0,  1113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,  1109,  1108,  1114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,  1666,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,  1105,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,  1109,
       0,  1108,     0,     0,     0,  1115,     0,  1113,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,  1111,  1674,
       0,     0,     0,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1110,     0,  1112,     0,  1111,  1676,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1112,     0,     0,     0,
    1107,     0,  1114,  1108,     0,     0,  1115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1109,     0,     0,
       0,     0,   216,   217,  1113,     0,     0,     0,     0,     0,
       0,     0,  1110,   218,     0,     0,  1111,  1677,     0,     0,
       0,     0,  1114,     0,     0,     0,     0,     0,     0,     0,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,     0,     0,     0,     0,
       0,     0,     0,     0,  1112,  1116,     0,     0,     0,     0,
       0,     0,     0,  1115,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,     0,     0,
       0,     0,  1113,     0,     0,     0,     0,     0,  1098,  1099,
    1100,  1101,  1102,  1103,     0,     0,     0,     0,     0,  1109,
    1114,     0,     0,  1115,  1104,  1105,  1106,     0,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,  1111,  1678,
    1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,  1104,  1105,  1106,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,     0,
       0,  1115,     0,   219,  1113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,  1114,    39,     0,     0,     0,     0,     0,     0,
    1104,  1105,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
       0,    40,    41,    42,  1107,     0,     0,  1108,     0,     0,
    1116,     0,     0,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,  1107,   223,    44,  1108,
       0,     0,     0,  1115,     0,     0,     0,     0,     0,   224,
       0,     0,     0,    45,     0,     0,     0,     0,    46,   225,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    49,     0,     0,    50,   226,     0,    51,
       0,     0,     0,     0,    52,     0,     0,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,   228,     0,     0,     0,     0,     0,     0,
    1107,     0,  1116,  1108,     0,     0,     0,     0,    54,     0,
       0,    55,    56,  1109,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,    58,
       0,     0,  1111,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,  1109,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,   230,     0,    61,     0,
    1110,    62,    63,    64,  1111,    65,    66,     0,     0,     0,
    1112,   231,     0,     0,     0,     0,     0,     0,   232,     0,
       0,   233,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1113,     0,
       0,   234,  1112,    39,   235,    68,   236,    69,    70,     0,
      71,     0,     0,     0,     0,     0,  1114,     0,     0,  1109,
       0,     0,     0,     0,     0,   237,     0,    72,    73,     0,
    1113,     0,     0,     0,  1110,     0,     0,     0,  1111,     0,
       0,    40,    41,    42,   238,     0,     0,     0,  1114,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,  1112,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,     0,     0,    45,   853,     0,     0,  1115,    46,     0,
      47,     0,     0,     0,  1113,     0,     0,     0,     0,     0,
      48,     0,     0,    49,     0,     0,    50,     0,     0,    51,
       0,     0,  1114,     0,    52,     0,    78,     0,     0,  1115,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,    55,    56,     0,     0,     0,  1116,     0,    57,     0,
      40,    41,    42,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,  1116,     0,
       0,    60,    43,  1115,     0,     0,     0,    44,    61,     0,
       0,    62,    63,    64,     0,    65,    66,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,    67,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,    68,    39,    69,    70,     0,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,  1116,     0,     0,     0,     0,    72,    73,     0,
       0,   854,     0,     0,     0,     0,     0,    54,     0,     0,
      55,    56,     0,     0,    40,    41,    42,    57,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    58,     0,
       0,    75,    76,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,    59,     0,     0,    43,     0,     0,     0,
      60,    44,     0,     0,     0,     0,     0,    61,     0,     0,
      62,    63,    64,     0,    65,    66,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,  1723,     0,     0,
       0,    67,     0,    48,     0,     0,    49,     0,     0,    50,
       0,     0,    51,     0,     0,     0,    78,    52,     0,     0,
      39,     0,     0,     0,    68,     0,    69,    70,   855,    71,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,    40,    41,
      42,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    58,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,    77,     0,     0,     0,    59,     0,     0,
      43,     0,     0,     0,    60,    44,     0,     0,     0,     0,
       0,    61,     0,     0,    62,    63,    64,     0,    65,    66,
      45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
       0,  1160,     0,     0,     0,    67,     0,    48,     0,     0,
      49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
       0,    52,     0,     0,    39,    78,     0,     0,    68,     0,
      69,    70,     0,    71,     0,     0,     0,   855,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
       0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
       0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
       0,     0,     0,     0,     0,    61,     0,     0,    62,    63,
      64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
      51,     0,     0,     0,     0,    52,     0,     0,    39,    78,
       0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
       0,   855,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
       0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
       0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
       0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
     112,     0,    62,    63,    64,     0,    65,    66,    45,     0,
       0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    48,  -905,     0,    49,     0,
       0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
       0,     0,    39,    78,     0,     0,    68,     0,    69,    70,
       0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
      40,    41,    42,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
       0,    83,    75,    76,     0,    77,     0,     0,     0,    59,
       0,     0,    43,     0,     0,     0,    60,    44,     0,     0,
       0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
      65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
       0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,     0,    39,    78,     0,     0,
      68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
      55,    56,     0,     0,    40,    41,    42,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    58,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
       0,     0,     0,    59,     0,     0,    43,     0,     0,     0,
      60,    44,     0,     0,     0,     0,     0,    61,     0,     0,
      62,    63,    64,     0,    65,    66,    45,     0,     0,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    48,     0,     0,    49,     0,     0,    50,
       0,     0,    51,     0,     0,     0,     0,    52,     0,     0,
      39,    78,     0,     0,    68,     0,    69,    70,     0,    71,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,     0,     0,
       0,    54,     0,     0,    55,    56,     0,     0,    40,    41,
      42,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    58,     0,     0,  2610,     0,     0,     0,     0,
      75,    76,     0,    77,     0,     0,     0,    59,     0,     0,
      43,     0,     0,     0,    60,    44,     0,     0,     0,     0,
       0,    61,   112,     0,    62,    63,    64,     0,    65,    66,
      45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    67,     0,    48,     0,     0,
      49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
       0,    52,     0,     0,     0,    78,     0,     0,    68,     0,
      69,    70,     0,    71,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
       0,    59,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,     0,    61,     0,     0,    62,    63,
      64,     0,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    76,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78
};

static const short yycheck[] =
{
      22,    23,   156,   162,   897,   748,   351,   491,   752,   564,
      35,   868,    34,   476,   879,     0,  1415,   960,  1448,   875,
     876,   112,   878,   864,   880,   881,  1370,   181,   730,   204,
     582,   974,  1652,   574,     5,   128,  1022,  1271,  1272,   580,
     588,  1705,   548,   584,    26,  1764,  2145,     5,     5,  1303,
      35,  1559,   571,     5,     5,     5,     5,   609,    36,  1036,
     612,    83,   237,   904,    86,   914,     5,   916,     5,    86,
       5,    93,    97,   106,  2144,   818,  2146,    23,    24,    25,
      38,   121,    40,     5,    42,    59,    60,   571,   110,   248,
      23,  1641,    25,    23,   575,    25,    46,  2133,    17,    18,
    1499,   123,    52,    88,    23,    24,    25,     5,    72,  1508,
    1829,  2168,    97,    98,     5,     5,   141,   130,    23,     5,
      25,     5,   467,   134,   146,    17,    23,   514,    25,  2427,
     143,    23,    24,    25,   991,  1685,   993,     5,  1067,  2238,
       5,    17,    18,  1571,  1694,   121,     6,    23,    24,    25,
       5,   173,     5,  2528,   167,    26,   141,   170,     5,     5,
       5,   206,   521,     5,   220,   524,     5,    88,     5,  2088,
    2089,  2090,  2091,    22,   245,   534,   129,    98,   357,   538,
     107,   108,   901,   542,     5,   308,    63,     6,   312,    22,
     549,     6,     5,     5,   733,   554,     5,   556,     5,  1817,
     398,   186,     5,   562,   563,   328,    17,    18,    19,    20,
      21,   570,     5,  2596,   308,     5,   575,    22,   605,     5,
     964,   177,   308,   663,   583,   134,   239,   320,   219,  1610,
     252,   253,  1613,   426,     5,   594,   258,   259,     5,   598,
       5,   505,     5,   602,     5,  2721,   253,     5,   607,     5,
     426,   610,     5,   275,     5,   253,     5,     5,     5,   266,
       5,   327,   266,     5,   286,   186,     5,   245,   266,     5,
      34,    17,    18,    19,    20,    21,   401,  1707,   147,   408,
     265,     5,   302,   359,     5,   378,   379,   513,    28,   302,
     544,   304,   556,   406,   316,   209,   309,   319,   354,   594,
     356,   312,   324,     5,   417,   527,   245,     5,   245,     5,
       5,     5,     5,    45,   267,  1865,  2691,   393,   540,  2578,
     515,  1214,   617,  2042,   505,  2424,    17,    18,    19,    20,
      21,  2807,   586,   353,   312,   317,  2406,  2639,  2408,  2641,
    2410,  1891,   537,   468,   265,  2381,   359,   588,    27,    28,
    2420,   398,   266,   375,   595,   122,   205,  2427,   371,   505,
       9,   587,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   205,   242,   396,   556,   398,   443,   425,   357,
     509,   595,   930,   122,   579,   886,   887,   340,   112,    29,
     397,    31,    27,   397,   589,   590,   589,   595,   593,   397,
     205,   315,   597,   312,   599,   319,  1861,    30,   603,   604,
     556,   367,  1138,   589,  1140,    64,    65,    66,    67,    68,
      69,    26,   406,  2798,   547,  2800,  2724,   472,   450,  1173,
     213,   453,   445,   417,   459,  1863,  1155,    77,    78,   461,
     564,  2824,  2060,   883,   363,    85,   317,   438,   481,   628,
     890,   254,   492,   547,    94,    95,   589,    97,    98,   378,
     482,   547,   102,    24,   293,   536,   488,   523,   254,   491,
     492,   321,   494,   458,   459,   497,  1710,   404,  1017,   119,
     120,   330,  1411,   397,  1461,  1414,   508,   363,   554,   357,
    1045,  1046,  1047,   515,   359,   341,  1048,   137,   138,   359,
     511,  1020,   378,   394,   394,   527,   459,  1062,   394,   868,
     394,   992,   359,  2583,   359,   537,   492,   359,   540,   438,
     359,  1902,   359,  2559,  2560,   330,  2596,     9,   550,    11,
      12,    13,    14,    15,    16,   546,  1020,   458,   359,   394,
     359,   394,   564,   565,   359,  2602,   359,   359,   300,   571,
     359,  2810,   359,  1296,  1297,  2814,   506,   579,   536,   581,
     582,   589,  1305,   585,   513,   517,   359,   589,   590,   359,
     592,   593,   523,   595,   223,   597,  2495,   599,   595,  1522,
    2882,   603,   604,   394,   606,   520,   608,   609,   359,   611,
     612,   355,   614,  1141,   359,   517,   359,   536,   359,   536,
     564,   359,  1154,   359,  1159,  1153,   359,   586,   359,  2159,
     359,   359,   359,  2332,   359,   513,   380,   359,  1137,   448,
    2128,   595,  1876,   359,    17,    18,    19,    20,   266,   587,
     587,  2295,   991,   992,   993,  2299,  1142,   595,   359,   293,
     618,   619,   620,   589,  1630,  1494,   596,  2046,   394,   631,
     327,   629,  1207,  1137,  2724,  2054,   589,   359,  2757,   589,
     631,   359,  2482,   359,   359,   359,   359,  2766,   359,   864,
     589,    64,    65,    66,    67,    68,    69,   315,  1233,  2134,
    2135,   319,  1234,  1238,   589,  2235,  2236,  2237,   710,  2595,
     339,  2241,   589,   448,  1359,   335,  1361,   589,  1199,   463,
     722,   426,   724,   898,   426,  2660,   719,  2662,     5,   904,
    1251,   733,   321,   589,   275,   453,  1268,  1269,   279,   280,
     281,   361,   917,   461,   135,     5,   748,   922,   139,   481,
    1587,   608,   609,   610,   611,   612,   758,   759,   299,   491,
     209,   223,   393,  2644,   482,   140,  2647,   396,    25,   771,
     161,  2571,   398,  2573,  2824,   777,   778,  2377,  2578,   397,
     323,    17,    18,    19,    20,   594,   443,    13,     9,   791,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     426,    80,    81,    82,   613,   614,   502,  2021,  2132,   524,
     398,   304,   432,   557,   448,   426,   818,   266,   398,  2705,
    1348,   314,   398,   538,   633,   569,   570,   542,    64,    65,
      66,    67,    68,    69,   578,   556,   426,   425,   426,   554,
     398,    29,   563,    64,    65,    66,    67,    68,    69,   398,
     241,   426,  2382,   244,  1577,  2554,   558,   594,   398,   594,
    1227,   598,   864,   865,   438,   602,   315,   398,   409,   398,
     319,   398,   446,   366,    25,   266,    25,   339,   613,   614,
    1019,  2476,   595,  2478,  2479,  1730,   607,   589,   381,   610,
    1411,   398,   433,  1414,   523,   595,   898,   554,   633,    25,
    2430,    25,   904,  2838,   524,    25,    94,    95,    25,    97,
      98,   452,   589,   594,   102,   917,   425,   426,   425,   426,
     922,   608,  2808,  2809,   611,    25,   928,   614,  1460,   594,
      25,   119,   120,    25,  1807,   616,   617,  1010,   425,   426,
    1013,    25,   571,   406,   946,  2324,   487,    25,   397,   137,
     138,   616,   617,   589,   417,   609,   610,   500,   960,   241,
     594,   398,   244,   592,   246,   506,   507,   589,  1143,  1144,
    1145,   514,   974,   258,   259,   438,    84,   470,  1506,   613,
     614,   522,   445,    25,   266,   398,   359,   607,  1163,    17,
      18,    19,    20,    21,   276,   615,   398,   540,   394,   633,
     884,   885,   223,     5,   888,   889,   397,  1542,  1543,   334,
    2810,   293,   359,   608,  2814,  1017,   611,   612,  1020,   589,
    1022,  1023,   563,  1157,  1026,  1200,  1558,    25,   135,   229,
    1867,   406,   139,   315,   394,  1563,   359,   319,   611,   612,
    1042,   398,   417,  1045,  1046,  1047,  1048,   590,  1050,  1051,
      25,  1226,   398,  1890,   161,   596,   618,   619,  2588,   398,
    1062,   523,  1064,   438,   582,   583,   584,   585,  1243,    20,
     445,   618,   619,    25,  1076,    25,  1078,  1079,  1253,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,   421,    25,    43,    44,
    2630,  2631,    47,    48,    49,  1633,  1108,  1109,  2708,  2709,
      25,  1113,   437,  1115,  1453,   397,  2246,  2247,   339,    25,
      20,    25,  1643,   359,   398,   359,    25,    25,  1851,    17,
      18,    19,    20,   398,   241,  1137,   324,   244,   359,  1294,
    2670,  1143,  1144,  1145,   329,  1300,   273,   359,   359,   359,
     490,   359,  1154,   593,  1156,   480,  1158,  1159,  1686,   266,
    1688,  1163,   359,   503,     5,   359,   448,   273,   359,  1697,
    1893,    17,    18,    19,    20,   396,    64,    65,    66,    67,
      68,    69,   593,   359,   329,   373,   488,   426,   426,   589,
     530,   359,     5,   359,   519,   427,   105,  1879,  1200,   359,
      25,   359,   589,   426,   149,  1207,   546,   547,   586,   589,
     135,   156,   552,     8,   139,   555,   394,   446,    64,    65,
      66,    67,    68,    69,  1226,   550,   492,  1566,   398,  1231,
     237,  1233,  1234,   398,   559,   398,  1238,   398,   388,  2563,
    1242,  1243,  2566,   188,   241,   398,   398,   244,  1587,   246,
    2071,  1253,   197,  1774,  2127,   398,  1431,   398,   398,   398,
     169,   398,   171,   398,  1337,  1267,  1268,  1269,  1341,   266,
     398,   427,  1343,   398,     5,  2685,   398,   186,   587,   276,
    1455,   587,   227,   228,  1459,   194,   398,    19,    20,   198,
     397,  1293,   564,   318,  1296,  1297,   293,   398,   388,  1301,
     398,  1303,   523,  1305,   398,   398,  2836,   398,   334,   427,
     628,   398,  2842,  1488,  2038,   224,   241,   342,   315,   244,
     345,   628,   319,   334,   295,     8,     5,   272,    17,    18,
      19,    20,    64,    65,    66,    67,    68,    69,   363,  1514,
     565,   266,  2265,     5,   558,   211,   351,   213,   398,   398,
     571,   633,   398,   398,   398,   398,  1358,  1359,   312,  1361,
     558,   547,     8,  1365,    13,     5,   311,  2777,   543,   628,
       5,   592,   628,   388,   398,    64,    65,    66,    67,    68,
      69,   398,    25,  1385,  1386,  1387,  2796,  1389,    64,    65,
      66,    67,    68,    69,    25,   421,    63,   334,    36,   394,
     397,   394,   398,   558,    80,    81,    82,   564,   589,   241,
     421,   437,   244,  1415,   246,  1417,   398,    19,    20,    21,
    2799,   398,   367,   595,   558,   438,   437,    20,   398,  1431,
      20,    70,   398,   595,   266,   398,  1964,   398,   631,  2849,
     318,   595,  2315,   468,   276,    18,   594,  1449,    32,   523,
      17,   448,     5,  1455,   480,  1457,  1458,  1459,  1460,  1634,
     124,    25,    64,    65,    66,    67,    68,    69,  2313,   480,
      25,   359,   397,   188,  1917,    24,   558,  2005,    80,    81,
      82,   592,   547,   315,   421,   449,  1488,   319,  1655,   449,
       5,  1493,   513,   519,   122,   513,   521,  1499,  1665,     5,
     437,    25,  1504,  1670,   529,   367,  1508,  1674,   519,  1676,
    1677,  1678,  1514,   359,  1689,  1690,  1691,  1692,   290,   513,
    1522,   105,  1861,    20,   550,   428,   428,  1529,  1867,  1531,
     589,   359,   544,   559,   513,   359,   359,   359,  1713,   550,
    1542,  1543,   359,   480,   220,  2268,   586,   223,   559,   359,
     359,  1890,   359,  1920,  1921,  1922,  1558,  1924,  1925,  1926,
    1927,  1928,  1929,   359,   595,   397,  1933,    64,    65,    66,
      67,    68,    69,   359,     5,  1577,     5,     5,  2113,   548,
    2115,   589,   519,  1585,     5,   169,  2423,   171,   359,   450,
     398,  1916,   595,   594,  1596,  1770,  2320,   398,   334,     5,
     520,    25,   186,    25,   398,   502,    36,  1609,  1610,   294,
     194,  1613,   359,   550,   198,     5,   448,   359,   220,   359,
     398,   223,   559,   328,   565,    13,   517,  2500,  1630,   629,
     595,   589,  1634,   513,    25,  2508,   633,     5,   219,  1641,
     224,  2105,   398,   589,   552,   438,    72,   513,   514,   398,
    1652,   595,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   301,   339,   594,    17,    18,    19,    20,     5,
     359,   593,   608,   359,   313,   593,     8,  1679,   354,  1681,
       5,     5,   358,  1685,   359,   421,   359,  1689,  1690,  1691,
    1692,     5,  1694,   589,   589,   589,     8,   294,  1700,  1701,
     312,   437,  1704,  1705,   312,  2233,  1881,   426,  1883,   312,
     589,  1713,    64,    65,    66,    67,    68,    69,   398,    90,
     396,  1723,    14,    15,    16,    17,    18,    19,    20,    21,
      64,    65,    66,    67,    68,    69,   393,   339,   377,   605,
     328,     5,   334,   398,   480,   384,   398,   398,   424,   615,
     398,   398,   354,   620,  2282,   388,   358,   509,     3,     4,
       5,     6,     7,     8,  2487,    10,   442,    25,  1770,   334,
    1772,  2303,    64,    65,    66,    67,    68,    69,  2310,     5,
       5,     5,  1784,   519,   423,     5,    25,   564,    80,    81,
      82,   564,   398,     5,   396,  2134,  2135,   586,  2522,    94,
      95,   633,    97,    98,   589,   589,  1808,   102,   447,     5,
    2683,     5,     5,    24,   550,    24,    24,    24,   457,   458,
     191,   588,   424,   559,   119,   120,    24,   414,   199,   421,
      25,   589,     8,    25,   473,   206,  2011,   208,    25,  2014,
     442,    25,   137,   138,    25,   437,   398,   523,   219,  1851,
     398,   398,   398,    20,   359,   494,   421,   359,   497,   498,
     359,   359,     5,  1865,   503,   359,  1868,   359,   534,   245,
     359,     5,   437,  1875,  1876,     5,   247,   513,  1880,  1881,
       5,  1883,   211,   359,  2608,   359,   752,   426,   480,  1891,
     398,  1893,   263,   595,   539,   408,  2071,   268,   589,   100,
    1902,   359,   398,   438,     6,   398,     7,   278,   109,   520,
    1915,    29,   207,   595,   285,   480,   592,   118,    13,     5,
      13,   523,   123,   562,   520,   595,   180,   519,   220,   795,
    2653,   223,  2805,     5,   105,   574,    25,  2660,   239,  2662,
       5,   398,   398,  1948,  2780,  2781,  2782,  2783,  2784,  2785,
    1915,   398,   589,   324,   519,   398,   398,   398,   550,   492,
     106,   436,   398,   359,   165,  1967,   517,   559,   211,   312,
     359,   394,   173,   408,  2502,   312,    94,    95,    20,    97,
      98,   398,  1984,  1948,   102,   550,   438,   111,   134,   135,
     592,   398,   180,   210,   559,   589,   210,   359,   169,     5,
     171,   119,   120,    25,   595,    25,    25,   359,     5,  2011,
     156,   588,  2014,   336,     8,   186,   162,  2019,   536,   137,
     138,   341,    25,   194,   359,   398,   359,   198,   398,   230,
    2032,     5,  2034,   212,  2036,   181,   513,   183,     5,   210,
      13,  2043,    25,   426,  2046,   267,    25,   339,  2050,     5,
     359,   359,  2054,   224,   255,   359,   398,   415,   360,   398,
     589,   262,   354,   264,   409,   359,   358,   438,   398,  2071,
     359,    25,   394,   274,   445,   359,   359,    25,   359,   398,
       5,     5,   131,    24,  2423,   212,   595,   359,     5,   359,
    2092,  2093,  2094,  2095,  2096,  2097,   467,   298,   964,   148,
     149,   472,   248,  2105,   396,   306,   359,   156,   359,     0,
     405,  2113,     0,  2115,  2049,  2838,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,  1967,  2859,  1760,  1984,
    1244,  2306,   424,  1515,    17,    19,  1701,  2672,  1707,   188,
     458,   342,     7,  2145,  2032,  2147,  2674,   309,   197,   114,
     442,   167,    17,    18,    19,    20,   170,  2159,   221,  2334,
     408,   303,  2164,  2297,   718,   310,  2168,   368,    64,    65,
      66,    67,    68,    69,   719,   223,   339,   224,   227,   384,
     371,  2183,  2184,  2185,    80,    81,    82,  2911,   338,  2191,
     396,  2849,  1488,    17,    18,    19,    20,  2336,   398,    64,
      65,    66,    67,    68,    69,   406,    17,    18,    19,    20,
    1681,   592,  1607,  1614,  1691,    26,   417,   998,  1459,  1267,
    2361,  2108,  1538,   272,  1015,  1804,  1695,  1553,  2124,  1270,
    2122,   523,  1159,  2235,  2236,  2237,  2238,  2516,   265,  2241,
      64,    65,    66,    67,    68,    69,  2458,    98,   551,  1520,
     712,  1526,   183,    64,    65,    66,    67,    68,    69,   724,
    2720,  1275,   311,  2265,  1254,  1529,  2268,   965,  2217,  2445,
    1569,  1197,  2796,  2275,  1150,  2093,  1140,  1960,  2455,  1226,
    1072,  1942,  1626,   917,  2669,  1026,  1958,  1685,  2241,  2426,
    1861,  2879,  2842,  2295,   994,  1894,  2298,  2299,  2728,  2629,
     592,  2303,  2836,  2237,  2306,  2658,  2487,  1173,  2310,  2269,
    2393,     5,  2394,  2147,   515,   516,   517,  2573,  2157,  1293,
    2638,  2671,  2324,  2185,   220,   994,  2558,   223,   529,  2504,
    2840,  2544,  2334,  2164,  1289,  2703,  2160,   990,  2416,  1630,
     456,    -1,    -1,  2345,    -1,  2347,  2348,  2349,  2350,    -1,
      -1,    -1,    -1,   499,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2375,    -1,  2377,    -1,    -1,    -1,    -1,
    2382,    -1,    -1,    -1,    -1,    -1,    -1,   533,    -1,    -1,
      -1,  2393,  2394,   539,    -1,   541,    -1,    -1,    -1,   545,
      -1,    -1,   548,  2405,    -1,   551,    -1,    -1,  2410,  1275,
      -1,    -1,    -1,    -1,  2416,   561,    -1,    -1,  2420,    -1,
      -1,    -1,  2424,    -1,  2426,  2427,    -1,    -1,  2430,    -1,
    2432,    -1,   578,   634,    -1,    -1,    -1,    -1,    -1,    -1,
     586,   587,   588,   339,    -1,    -1,   592,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   600,    -1,    -1,    -1,   354,    -1,
     124,    -1,   358,    -1,    -1,    -1,    -1,   131,    -1,   615,
    2472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1001,
      -1,    -1,    -1,    -1,    -1,  2487,    -1,    -1,    -1,  2491,
      -1,  2493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     396,    -1,  2504,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,  2544,    -1,    -1,    -1,   442,  2549,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2577,   270,  2579,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,  2588,    -1,    -1,    -1,
      -1,    -1,    -1,   287,  2596,    -1,    -1,    -1,    -1,    -1,
    2602,    -1,    -1,    -1,    -1,    -1,   752,    -1,    -1,    -1,
      -1,    -1,  2614,    -1,    -1,    -1,  2791,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   523,  2630,  2631,
      -1,   325,    -1,    -1,    -1,   781,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2653,    -1,   347,    -1,    -1,    -1,    -1,  2660,    -1,
    2662,    -1,    -1,  2665,    -1,  1531,    -1,    -1,  2670,   815,
    2672,   365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   375,    -1,    -1,    -1,    -1,    -1,    -1,  1531,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   592,   391,    -1,    -1,
      -1,  2703,    -1,    -1,    -1,    -1,  2708,  2709,    -1,    -1,
      -1,    -1,    -1,    -1,   860,    -1,    -1,  2719,   220,  1585,
    2895,   223,  2724,    -1,    -1,    -1,  2728,    -1,   874,   875,
     876,    -1,   878,    -1,   880,   881,    -1,   431,    -1,    -1,
     886,   887,  1585,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2757,    -1,    -1,    -1,    -1,
     454,    -1,    -1,    -1,  2766,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,   469,    -1,    -1,    -1,    -1,
      -1,    -1,   476,    -1,   930,   479,  1652,    -1,    -1,  2791,
    2792,    -1,    -1,    -1,    -1,   941,    -1,  2799,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   499,  1328,  1329,   502,  1652,
     504,  2813,    -1,  1335,    -1,    -1,    -1,    -1,   964,   965,
      -1,    -1,  2824,    -1,    -1,   489,   490,   973,    -1,   523,
      -1,    -1,    -1,    -1,  2836,    -1,  2838,   339,  2840,   503,
    2842,    -1,    -1,   989,   990,    -1,    -1,    -1,   542,    -1,
      -1,    -1,   354,    -1,    -1,    -1,   358,   521,    -1,    -1,
     524,    -1,    -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,
     534,    -1,    -1,  1019,   538,    -1,    -1,  2879,   542,    -1,
      -1,    -1,   546,   547,    -1,   549,    -1,    -1,   552,    -1,
     554,   555,   556,  2895,   396,    -1,    -1,    -1,   562,   563,
      -1,    -1,    -1,    -1,    -1,    -1,   570,    -1,    -1,  1775,
    1776,   575,    -1,    -1,    -1,    -1,    -1,    -1,  1784,   583,
      -1,    -1,   424,  1069,    -1,    -1,    -1,    -1,    -1,    -1,
     594,    -1,    -1,    -1,   598,    -1,    -1,    -1,   602,    -1,
     442,  1784,    -1,   607,    -1,    -1,   610,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1498,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1138,    -1,  1140,  1141,  1142,    -1,    -1,    -1,
      -1,    -1,  1868,  1149,  1150,    -1,    -1,  1153,    -1,    -1,
     270,  1157,  1534,    -1,  1160,    -1,    -1,    -1,    -1,    -1,
      -1,   523,    -1,    -1,    -1,    -1,    -1,  1173,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1199,  1920,  1921,  1922,    -1,  1924,  1925,
    1926,  1927,  1928,  1929,    -1,   325,    -1,  1933,    -1,    -1,
      -1,    -1,    -1,    -1,   231,    -1,    -1,   337,    -1,    64,
      65,    66,    67,    68,    69,    -1,    -1,   347,    -1,    -1,
     592,    -1,    -1,    -1,  1240,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,   375,    -1,  1263,   378,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1274,  1275,
     287,   391,    -1,    -1,    -1,    -1,    -1,    -1,   758,   759,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   771,    -1,    -1,    -1,    -1,    -1,   777,   778,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,
      -1,   791,  2038,    -1,    -1,    -1,    -1,    -1,    -1,   439,
     337,    -1,    -1,    -1,  1330,    -1,    -1,    -1,    -1,    -1,
     347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1348,    -1,   868,    -1,    -1,    -1,   365,   469,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,   479,
      -1,    -1,    -1,    -1,    -1,    -1,  2092,  2093,  2094,  2095,
    2096,  2097,  1754,  1755,   391,   220,    -1,    -1,   223,   499,
      -1,    -1,   502,  1765,   504,    -1,    -1,    -1,    -1,  2092,
    2093,  2094,  2095,  2096,  2097,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   533,   431,    -1,    -1,    -1,    -1,  2145,
      -1,  2147,   542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1813,  1814,  1815,  1816,    -1,    -1,   454,  2164,    -1,
      -1,    -1,  2145,    -1,    -1,    -1,  1828,    -1,    -1,    -1,
      -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,  2164,   479,    -1,    -1,    -1,    -1,   991,   992,   993,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1486,    -1,   499,    -1,    -1,   502,    -1,   504,    -1,  1495,
      -1,    -1,    -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,
    1506,    -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,   354,
      -1,    -1,  2238,   358,    -1,    -1,    -1,    -1,    -1,    -1,
    1526,  1903,  1904,    -1,    -1,   542,    -1,    -1,  1910,  1911,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   396,    -1,    -1,    -1,    -1,    -1,  1563,    -1,  1565,
      -1,    -1,  1042,  1569,    -1,    -1,    -1,    -1,    -1,    -1,
    1050,  1051,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,
      -1,    -1,    -1,    -1,  1064,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2320,  1601,  1076,   442,  1078,  1079,
      -1,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,    -1,  2345,
      -1,  2347,  2348,  2349,  2350,    -1,    -1,  1633,  1108,  1109,
      -1,    -1,    -1,  1113,    -1,  1115,    -1,    -1,    -1,    -1,
    2022,  2023,  2345,    -1,  2347,  2348,  2349,  2350,    -1,  2031,
      -1,  2377,    -1,    -1,    -1,    -1,    -1,  2039,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2393,  2394,    -1,
      -1,    -1,    -1,    -1,  2377,  2057,  2058,    -1,   523,  2405,
    1686,    -1,  1688,    -1,  2410,    -1,    20,    -1,    -1,    -1,
      -1,  1697,    21,    -1,  2420,    -1,    -1,    -1,  2424,    -1,
      -1,  2427,  2405,    -1,    -1,    -1,    -1,  2410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2420,    -1,    -1,
      20,    21,    -1,    -1,  2427,    -1,    -1,    -1,    -1,  1735,
      -1,    -1,  2114,  1257,  2116,    64,    65,    66,    67,    68,
      69,  2123,    -1,  2125,    -1,    -1,    -1,   592,    -1,    -1,
      -1,    80,    81,    82,    -1,    -1,  2482,    -1,  1764,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2522,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2192,  2193,    -1,    -1,  2196,  2197,    -1,    -1,  2544,    -1,
      -1,    -1,    -1,  2549,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2220,    -1,
      -1,  2544,    -1,    -1,    -1,  2571,  2549,  2573,    -1,    -1,
      -1,  2577,  2578,  2579,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2596,    -1,    -1,    -1,  2577,    -1,  2579,    -1,    -1,    -1,
      -1,    -1,  2608,    -1,    -1,  1365,    -1,    -1,    -1,    -1,
      -1,   220,    -1,  2596,   223,  1901,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1385,  1386,  1387,    -1,  1389,
      -1,    -1,    -1,    -1,  2296,    -1,    -1,   251,  2300,    -1,
     220,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,  1453,
      -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,  1944,  2665,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2330,    -1,
      -1,  1957,    -1,    -1,    -1,   289,   290,   291,  1964,    -1,
      -1,    -1,  2665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2359,    -1,    -1,
      -1,    -1,  2708,  2709,    -1,    -1,    -1,   321,    -1,    -1,
      -1,    -1,   326,  2719,    -1,    -1,    -1,    -1,  2724,  2005,
      -1,    -1,    -1,    -1,    -1,  2708,  2709,   341,    -1,    -1,
     339,    -1,   346,  1493,   348,    -1,  2719,    -1,    -1,  1499,
      -1,  2724,    -1,    -1,   358,   354,    -1,   361,  1508,   358,
     364,  2757,  2038,   367,    -1,    -1,    -1,    -1,   372,   339,
    2766,  2047,  1566,  2049,    -1,  2051,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   354,    -1,   390,  2063,   358,    -1,
      -1,    -1,    -1,  1587,    -1,    -1,    -1,   396,    -1,    -1,
      -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,    -1,
      -1,    -1,   416,    -1,  2810,    -1,    -1,  2813,  2814,    -1,
      -1,    -1,    -1,   427,    -1,   424,   396,    -1,  2824,    -1,
      -1,    -1,    -1,    -1,    -1,  1629,    -1,    -1,   442,    -1,
    2813,    -1,    -1,   442,  2840,   449,    -1,    -1,    -1,    -1,
      -1,  2824,   456,    -1,   424,   459,   460,   461,    -1,   463,
     464,    -1,    -1,    -1,    -1,    -1,    -1,  2840,    -1,    -1,
      -1,    -1,   442,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,  2533,    -1,  2879,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   503,
      -1,   505,   506,    -1,   508,    -1,  2879,    -1,    -1,    -1,
    2186,    -1,    -1,    -1,    -1,  2911,    -1,    -1,    -1,    -1,
      -1,   525,   526,    -1,   523,    -1,    -1,    -1,    63,  1679,
      -1,  1681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2217,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,
      -1,    -1,    -1,   523,    -1,   559,   560,  2233,   562,    16,
      17,    18,    19,    20,    21,    -1,  2618,  2619,    -1,  2621,
     105,  2623,  2624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   592,  1788,    -1,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,    -1,  2282,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     624,  2297,   592,    80,    81,    82,   161,    -1,    -1,    -1,
      -1,    -1,   636,    -1,   169,    -1,   171,    -1,    -1,    -1,
    2692,    -1,    -1,    -1,  2320,   180,    -1,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,  1852,   194,
    2336,    -1,    -1,   198,    -1,    -1,    -1,  1861,    -1,    -1,
     205,    -1,    -1,  1867,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,  2734,    -1,  2736,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,  1890,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,   244,
      -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   276,  2418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,   294,
      -1,    -1,    -1,   220,    -1,    -1,   223,    -1,    -1,  2445,
      -1,    -1,    -1,   308,  2450,    -1,  2452,    -1,    -1,    -1,
     315,    -1,    -1,    -1,   319,    -1,  1980,    -1,    -1,    -1,
      -1,    -1,    -1,   328,   329,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2864,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,  2502,    17,    18,    19,
      20,    21,    34,    35,  1984,    -1,    -1,  2889,  2890,    41,
      -1,  2893,    -1,    -1,    -1,    -1,  2522,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   397,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,   408,    64,    65,    66,    67,    68,    69,
      -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,  2043,    -1,    -1,  2046,   354,    -1,    -1,
      -1,   358,    -1,    -1,  2054,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2608,    -1,    -1,    -1,    -1,    -1,    -1,   396,
    2134,  2135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,
      -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2671,    -1,    -1,  2674,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2720,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   594,
      -1,    -1,    -1,   265,    -1,    -1,   523,    -1,    -1,    -1,
      -1,    -1,    -1,   608,   609,   610,   611,   612,   613,   614,
      -1,   616,   617,    -1,    -1,    -1,    -1,   289,   290,   291,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   633,    -1,
      -1,    -1,    -1,    -1,  2780,  2781,  2782,  2783,  2784,  2785,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,
      -1,    -1,    -1,    -1,   326,  2275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,   592,    -1,    -1,    -1,   341,
      -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,   339,
      -1,    -1,  2346,   355,    -1,    -1,   358,    -1,   360,   361,
      -1,   363,   364,    -1,   354,   367,    -1,    -1,   358,    -1,
     372,    -1,   374,    -1,  2324,    -1,    -1,    -1,   380,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
    2384,    -1,    -1,   395,  2388,    -1,   398,    -1,    -1,   401,
      -1,    -1,    -1,    -1,   406,    -1,   396,   409,   410,    17,
      18,    -1,    -1,    -1,   416,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,   427,    34,    35,    -1,  2423,
      -1,    -1,    -1,    41,   424,  2911,    -1,   173,    -1,    -1,
     442,    -1,    -1,    -1,    -1,    -1,    -1,   449,   450,   451,
      -1,    -1,   442,   455,   456,    -1,    -1,   459,   460,   461,
      -1,   463,   464,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,   503,   504,   505,   506,    -1,   508,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,
      -1,    -1,    -1,    -1,   162,   557,    -1,   559,   560,    -1,
     562,    -1,   298,    -1,    -1,   301,    -1,   569,   570,   571,
     306,    -1,    -1,    -1,    -1,    -1,   578,   313,    -1,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,    -1,   251,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      17,    18,    -1,   399,    -1,    -1,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,   289,   290,   291,    41,    -1,    -1,   423,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   447,    -1,   321,    71,    -1,    -1,    -1,   326,    -1,
      -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   341,    -1,    -1,    -1,   473,   346,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,
     358,    -1,   360,   361,    -1,   363,   364,    -1,   494,   367,
      -1,   497,   498,    -1,   372,    -1,   374,   503,    -1,    -1,
      -1,    -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,
     398,    -1,    -1,   401,    -1,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,    -1,    -1,   162,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,    -1,   572,    -1,   574,    -1,
      -1,   449,    -1,   451,    -1,    -1,    -1,   455,   456,  2799,
      -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   503,   504,   505,   506,    -1,
     508,    -1,    -1,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,   289,   290,   291,    -1,    -1,    -1,    -1,    34,
      35,    -1,   550,    -1,    -1,    -1,    41,    -1,    -1,   557,
      -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,
      -1,   569,   570,   571,   321,    -1,    -1,    -1,    -1,   326,
     578,    -1,    -1,   581,    -1,    -1,    71,    -1,    -1,    -1,
      -1,   589,    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,
      -1,   358,    -1,   360,   361,    -1,   363,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   372,   624,   374,    -1,    -1,
      -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,
      -1,   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,
     427,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,    -1,   449,   450,   451,    -1,    -1,    -1,   455,   456,
      -1,    -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,   480,    -1,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    -1,    -1,   503,   504,   505,   506,
      -1,   508,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,   525,   526,
     265,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,   550,   289,   290,   291,    41,    -1,    -1,
     557,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,
      -1,    -1,   569,   570,   571,    -1,    -1,    -1,    -1,    -1,
      -1,   578,    -1,    -1,   581,    -1,   321,    71,    -1,    -1,
      -1,   326,   589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
     355,    -1,    -1,   358,    -1,   360,   361,   624,   363,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,   374,
      -1,   220,    -1,    -1,   223,   380,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
     395,    -1,    -1,   398,    -1,    -1,   401,    -1,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,   162,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    -1,   451,    -1,    -1,    -1,
     455,   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,   476,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,    -1,    -1,    -1,    -1,    -1,   251,   503,   504,
     505,   506,    -1,   508,    -1,   354,   260,    -1,    -1,   358,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     525,   526,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,   289,   290,   291,    -1,    -1,
      -1,    -1,    34,    35,    -1,   550,    -1,   396,    -1,    41,
      -1,    -1,   557,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,    -1,    -1,    -1,   569,   570,   571,   321,    -1,    -1,
      -1,    -1,   326,   578,    -1,   424,   581,    -1,    -1,    71,
      -1,    -1,    -1,    -1,   589,    -1,    -1,   341,    -1,    -1,
      -1,    -1,   346,   442,   348,    -1,    -1,    -1,    -1,    -1,
      -1,   355,    -1,    -1,   358,    -1,   360,   361,    -1,   363,
     364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,   624,
     374,    -1,    -1,    -1,    -1,    -1,   380,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
      -1,   395,    -1,    -1,   398,    -1,    -1,   401,    -1,    -1,
      -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,    -1,
      -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,   427,   523,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,   442,    -1,
      -1,    -1,    -1,    -1,    -1,   449,   450,   451,    -1,    -1,
      -1,   455,   456,    -1,    -1,   459,   460,   461,    -1,   463,
     464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,   480,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   592,    80,    81,    82,    -1,    -1,   503,
     504,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,   525,   526,   265,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,   550,   289,   290,   291,
      41,    -1,    -1,   557,    -1,   559,   560,    -1,   562,    -1,
      -1,    -1,    -1,    -1,    -1,   569,   570,   571,    -1,    -1,
      -1,    -1,    -1,    -1,   578,    -1,    -1,   581,    -1,   321,
      71,    -1,    -1,    -1,   326,   589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
      -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,
      -1,    -1,    -1,   355,    -1,    -1,   358,   359,   360,   361,
     624,   363,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
     372,    -1,   374,    -1,   220,    -1,    -1,   223,   380,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,   395,    -1,    -1,   398,    -1,    -1,   401,
      -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
      -1,   162,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     442,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,   451,
      -1,    -1,    -1,   455,   456,    -1,    -1,   459,   460,   461,
      -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   503,   504,   505,   506,    -1,   508,    -1,   354,   260,
      -1,    -1,   358,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   525,   526,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    23,    24,    25,    -1,   289,   290,
     291,    -1,    -1,    -1,    -1,    34,    -1,    -1,   550,    -1,
     396,    -1,    -1,    -1,    -1,   557,    -1,   559,   560,    -1,
     562,    -1,    -1,    -1,    -1,    -1,    -1,   569,   570,   571,
     321,    -1,    -1,    -1,    -1,   326,   578,    -1,   424,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,
     341,    -1,    -1,    -1,    -1,   346,   442,   348,    -1,    -1,
      -1,    -1,    -1,    -1,   355,    -1,    -1,   358,    -1,   360,
     361,    -1,   363,   364,    -1,    -1,   367,    -1,    -1,    -1,
      -1,   372,   624,   374,    -1,    -1,    -1,    -1,    -1,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,   395,    -1,    -1,   398,    -1,    -1,
     401,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   427,   523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,
     451,    -1,    -1,    -1,   455,   456,    -1,    -1,   459,   460,
     461,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,
      -1,    -1,   503,   504,   505,   506,    -1,   508,    -1,    -1,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   525,   526,   265,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,   550,
     289,   290,   291,    -1,    -1,    -1,   557,    -1,   559,   560,
      -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,   569,   570,
     571,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,
     581,    -1,   321,    -1,    -1,    -1,    -1,   326,   589,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,
      -1,    -1,   361,   624,   363,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,   378,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,   398,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,
      -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,
     449,    -1,   451,    -1,    -1,    -1,    -1,   456,    -1,    -1,
     459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   503,   504,   505,   506,    -1,   508,
      -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   289,   290,   291,    -1,   544,    -1,    -1,    -1,    -1,
      -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,
     569,   570,   571,   321,    -1,    -1,    -1,    -1,   326,   578,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     589,    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,    -1,    -1,   361,    -1,   363,   364,    -1,    -1,   367,
      -1,    -1,    -1,    -1,   372,   624,    -1,    -1,    -1,    -1,
     378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,
     398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,
      -1,   449,    -1,   451,    -1,    -1,    -1,    -1,   456,    -1,
      -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   503,   504,   505,   506,   265,
     508,    -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    34,
      -1,    -1,    -1,   289,   290,   291,    -1,    -1,    -1,    -1,
     538,    -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,
      -1,    -1,   550,    -1,    -1,    -1,   554,   555,    -1,   557,
      -1,   559,   560,    -1,   562,   321,    -1,    -1,    -1,    -1,
     326,   569,   570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     578,    -1,    -1,   581,    -1,   341,    -1,    -1,    -1,    -1,
     346,   589,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   358,    -1,    -1,   361,    -1,   363,   364,    -1,
      -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,
      -1,    -1,   378,    -1,    -1,    -1,   624,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,   395,
      -1,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     406,    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,
      -1,    -1,    -1,   449,    -1,   451,    -1,    -1,    -1,    -1,
     456,    -1,    -1,   459,   460,   461,    -1,   463,   464,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   503,   504,   505,
     506,    -1,   508,    -1,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,   525,
     526,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   289,   290,   291,    -1,   544,    -1,
      -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,
      -1,   557,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,
      -1,    -1,    -1,   569,   570,   571,   321,    -1,    -1,    -1,
      -1,   326,   578,    -1,    -1,   581,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   589,    -1,    -1,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   358,    -1,    -1,   361,    -1,   363,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,   624,    -1,
      -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
     395,    -1,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,
      -1,   416,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   438,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,    -1,    -1,   449,   450,   451,    -1,    -1,    -1,
      -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,
      -1,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   503,   504,
     505,   506,    -1,   508,    -1,    17,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
     525,   526,    34,    -1,    -1,    -1,   289,   290,   291,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   544,
      -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,
      -1,    -1,   557,    -1,   559,   560,    -1,   562,   321,    -1,
      -1,    -1,    -1,   326,   569,   570,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   578,    -1,    -1,   581,    -1,   341,    -1,
      -1,    -1,    -1,   346,   589,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,    -1,
     363,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
      -1,    -1,    -1,    -1,    -1,   378,    -1,   220,    -1,   624,
     223,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,   395,    -1,    -1,   398,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
      -1,    -1,    -1,    -1,    -1,    -1,   449,   450,   451,    -1,
      -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
     463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,   251,
     503,   504,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,   354,    -1,   265,    -1,   358,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    23,    24,    25,    -1,   289,   290,   291,
      -1,   544,    -1,    -1,    34,    -1,    -1,   550,    -1,    -1,
      -1,    -1,    -1,   396,   557,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,    -1,    -1,    -1,   569,   570,    -1,   321,
      -1,    -1,    -1,    -1,   326,   578,    -1,    -1,   581,    -1,
      -1,   424,    -1,    -1,    -1,    -1,   589,    -1,    -1,   341,
      -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,   442,
      -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,
      -1,   363,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
     372,   624,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,   395,    -1,    -1,   398,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
     523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     442,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,   451,
      -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,
      -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,
      -1,   503,   504,   505,   506,    -1,   508,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,   525,   526,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,   550,   289,
     290,   291,    -1,    -1,    -1,   557,    -1,   559,   560,    -1,
     562,    -1,    -1,    -1,    -1,    -1,    -1,   569,   570,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,   581,
      -1,   321,    -1,    -1,    -1,    -1,   326,   589,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,
      -1,   361,   624,   363,   364,    -1,    -1,   367,    -1,    -1,
      -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,   378,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     390,    -1,    -1,    -1,    -1,   395,    -1,    -1,   398,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,
     410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,
     450,   451,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,
     460,   461,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   503,   504,   505,   506,    -1,   508,    -1,
      17,    18,    -1,    20,    -1,    -1,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,   525,   526,    34,    -1,    -1,
      -1,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,
     550,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,   559,
     560,    -1,   562,   321,    -1,    -1,    -1,    -1,   326,   569,
     570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,
      -1,   581,    -1,   341,    -1,    -1,    -1,    -1,   346,   589,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,    -1,    -1,   361,    -1,   363,   364,    -1,    -1,   367,
      -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,
     378,    -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,
     398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,
      -1,   449,   450,   451,    -1,    -1,    -1,    -1,   456,    -1,
      -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   503,   504,   505,   506,    -1,
     508,    -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   289,   290,   291,    -1,   544,    -1,    -1,    -1,
      -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,   557,
      -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,
      -1,   569,   570,    -1,   321,    -1,    -1,    -1,    -1,   326,
     578,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   589,    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   358,    -1,    -1,   361,    -1,   363,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   372,   624,    -1,    -1,    -1,
      -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,
      -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   438,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,    -1,   449,    -1,   451,    -1,    -1,    -1,    -1,   456,
      -1,    -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   503,   504,   505,   506,
      -1,   508,    -1,    17,    18,    -1,    20,    -1,    -1,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
      34,    -1,    -1,    -1,   289,   290,   291,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,
      -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,
     557,    -1,   559,   560,    -1,   562,   321,    -1,    -1,    -1,
      -1,   326,   569,   570,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   578,    -1,    -1,   581,    -1,   341,    -1,    -1,    -1,
      -1,   346,   589,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   358,    -1,    -1,   361,    -1,   363,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,    -1,   378,    -1,    -1,    -1,   624,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    17,    18,    -1,
     395,    -1,    -1,   398,    -1,    25,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,    -1,    -1,   449,   450,   451,    -1,    -1,    -1,
      -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   503,   504,
     505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     525,   526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   289,   290,   291,    -1,   544,
      -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,
      -1,    -1,   557,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,    -1,    -1,    -1,   569,   570,    -1,   321,    -1,    -1,
      -1,    -1,   326,   578,    -1,    -1,   581,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   589,    -1,    -1,   341,    -1,    -1,
      -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   358,    -1,    -1,   361,    -1,   363,
     364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,   624,
      -1,   251,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
      -1,   395,    -1,    -1,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,
     290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,
      -1,   321,    -1,    -1,    -1,   449,   326,   451,    -1,    -1,
      -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,
     464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,
      -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,
      -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,   503,
     504,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,    -1,
      -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,
     410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
     544,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,
      -1,    -1,    -1,   557,    -1,   559,   560,    -1,   562,    -1,
      -1,    -1,   442,    -1,    -1,   569,   570,    -1,    -1,   449,
      -1,    -1,    -1,    -1,   578,    -1,   456,   581,    -1,   459,
     460,   461,    -1,   463,   464,   589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,   525,   526,    -1,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
     550,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,   559,
     560,    -1,   562,    -1,    -1,    -1,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   581,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,   110,    -1,    -1,   113,    -1,   115,   116,
     117,    -1,   119,   120,    -1,    -1,    -1,    -1,   125,    -1,
     127,   128,    -1,   130,   624,   132,   133,    -1,    -1,   136,
     137,   138,    -1,    -1,   141,   142,   143,    -1,   145,   146,
      -1,    -1,    -1,   150,   151,    -1,   153,    -1,    -1,    -1,
     157,    -1,   159,   160,    -1,    -1,   163,    -1,    -1,    -1,
     167,    -1,    -1,   170,    -1,   172,    -1,   174,    -1,   176,
      -1,   178,   179,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
     217,   218,    -1,    -1,   221,   222,    -1,    -1,   225,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,   236,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   249,   250,    -1,   252,    -1,    -1,    -1,   256,
     257,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     277,    -1,    -1,    -1,    -1,    -1,   283,   284,    -1,    -1,
      -1,    -1,   289,    -1,    -1,   292,    -1,    -1,    -1,   296,
     297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     307,    -1,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,
      -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   361,    -1,    -1,    -1,    -1,    -1,
      -1,   368,    -1,   370,   371,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,    -1,    -1,   433,    20,    -1,   436,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    -1,   460,   461,    -1,    -1,    -1,   465,    -1,
      -1,    -1,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,
     477,    -1,    -1,    -1,    -1,    -1,   483,   484,   485,   486,
      -1,    -1,   489,    -1,    -1,    -1,   493,    -1,    -1,    -1,
      -1,    -1,    -1,   500,   501,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   512,    -1,   514,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,    -1,
      -1,   528,    -1,    -1,   531,    -1,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,   564,    -1,    -1,
     567,    -1,    -1,    -1,    -1,    -1,   573,    -1,    -1,   576,
      -1,    -1,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,
      -1,   598,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,    -1,   321,   223,    -1,    -1,    -1,   326,
      -1,    -1,    -1,    -1,   621,   622,   623,   624,   625,   626,
     627,    -1,    -1,   630,   341,   632,    -1,   634,    -1,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    20,    -1,    -1,    -1,    -1,
      -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   339,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
      -1,    -1,   449,   326,    -1,    -1,   354,    -1,    -1,   456,
     358,   359,   459,   460,   461,    -1,   463,   464,   341,    -1,
      -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
      -1,   364,    -1,    -1,   367,    -1,    -1,    -1,   396,   372,
      -1,    -1,   251,    -1,    -1,    -1,   503,    -1,   505,   506,
      -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,   525,   526,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
     289,   290,   291,   416,   442,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
      -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
      -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
     463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,
      -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,   523,   251,   624,    -1,    -1,
     503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,   442,   592,    -1,   321,    -1,    -1,    -1,
     449,   326,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,
     459,   460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,
     251,   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,
     291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,
     321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,
      -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,
     341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,
     361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,
      -1,   372,    -1,    -1,   251,   624,    -1,    -1,   503,    -1,
     505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
      -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,
     461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,   624,
      -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
      -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
      -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,
      -1,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
      -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
      -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
      -1,    -1,   251,   624,    -1,    -1,   503,    -1,   505,   506,
      -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
     289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
      -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
      -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
     463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,
      -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,    -1,   251,   624,    -1,    -1,
     503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,
     449,   326,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,
     459,   460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,
     251,   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
      23,    24,    25,    -1,    -1,    -1,   525,   526,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,
     291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,
     321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,
      -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,
     341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,
     361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,
      -1,   372,    -1,    -1,   251,   624,    -1,    -1,   503,    -1,
     505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
      -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,
     461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
      -1,   348,    -1,    -1,    -1,   352,    -1,    -1,    -1,   480,
      -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,   624,
      -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
      -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
      -1,    -1,   449,   326,    -1,    -1,    -1,   454,    -1,   456,
      -1,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
      -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
      -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
      24,    -1,    26,   624,    -1,    -1,   503,    -1,   505,   506,
      -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
      94,    95,    -1,    97,    98,    -1,   449,    -1,   102,    -1,
      -1,    -1,    -1,   456,   581,    -1,   459,   460,   461,    -1,
     463,   464,   589,    -1,    -1,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,   624,    -1,    -1,
     503,    -1,   505,   506,    -1,   508,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,   525,   526,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    80,
      81,    82,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      26,   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   289,   290,   291,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,
      -1,    -1,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,   341,    -1,    -1,
      -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,   358,    -1,    -1,   361,    -1,    -1,
     364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,   220,
      -1,   251,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,   406,    -1,    -1,   409,   410,    -1,    -1,   289,
     290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,
      -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,
      -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,
     464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,
      -1,   361,    -1,    -1,   364,    -1,    -1,   367,   339,    -1,
      -1,    -1,   372,    -1,    -1,   251,    -1,    -1,    -1,   503,
      -1,   505,   506,   354,   508,    -1,    -1,   358,    -1,    -1,
     390,    -1,    -1,    -1,    -1,    -1,    24,    -1,    26,    -1,
      -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,
     410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   396,   550,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,
      -1,    -1,   442,   443,    -1,   321,    -1,    -1,    -1,   449,
     326,    -1,    -1,   424,    -1,    -1,   456,   581,    -1,   459,
     460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,
     346,   442,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,
      -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,
     624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,
      -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,
     406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     550,   427,   523,    -1,    -1,    -1,    -1,    -1,    -1,   559,
     560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,
      -1,    -1,    -1,   449,   326,    -1,    -1,    24,    -1,    -1,
     456,    -1,    -1,   459,   460,   461,    -1,   463,   464,   341,
      -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,
      -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
     372,   592,    -1,   251,   624,    -1,    -1,   503,    -1,   505,
     506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,   517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,
     526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
      -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,
     442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,
      -1,    24,    -1,    -1,   456,   581,    -1,   459,   460,   461,
      -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
     358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,
      -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,   624,    -1,
      -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,
      -1,    -1,   554,    -1,   251,    -1,    -1,   559,   560,    -1,
     562,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,
      -1,   449,    -1,    -1,    -1,    24,    -1,    26,   456,   581,
      -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,
      -1,    -1,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   624,    -1,   321,   503,    -1,   505,   506,   326,
     508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   341,    -1,    -1,   525,   526,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
     367,    -1,   550,    -1,    -1,   372,    -1,    -1,   251,    -1,
      -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   438,    -1,    -1,    -1,   442,   624,    -1,   321,    -1,
      -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,
      -1,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
      -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
      -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
      -1,    -1,   251,    -1,    -1,    -1,   503,    -1,   505,   506,
      -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,   525,   526,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
     289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
      -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
      -1,    -1,    -1,   456,   581,    -1,   459,   460,   461,    -1,
     463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,
      -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,    -1,   251,   624,    -1,    -1,
     503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,
      -1,   544,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,
     449,   326,    -1,    -1,    -1,    -1,    -1,   456,   581,    -1,
     459,   460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,
     251,   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,
     291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,
     321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,
      -1,   456,   581,    -1,   459,   460,   461,    -1,   463,   464,
     341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,
     361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,
      -1,   372,    -1,    -1,   251,   624,    -1,    -1,   503,    -1,
     505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
     525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
      -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
      -1,    -1,    -1,    -1,    -1,   456,   581,    -1,   459,   460,
     461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,   624,
      -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
      -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
      -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,
     581,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
      -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
      -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
      -1,    -1,   251,   624,    -1,    -1,   503,    -1,   505,   506,
      -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,   525,   526,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
     289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
      -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
      -1,    -1,    -1,   456,   581,    -1,   459,   460,   461,    -1,
     463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,
      -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,    -1,   251,   624,    -1,    -1,
     503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,
     449,   326,    -1,    -1,    -1,    -1,    -1,   456,   581,    -1,
     459,   460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,
     251,   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,
     291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,
     321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,
      -1,   456,   581,    -1,   459,   460,   461,    -1,   463,   464,
     341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,
     361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,
      -1,   372,    -1,    -1,   251,   624,    -1,    -1,   503,    -1,
     505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
     525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
      -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
      -1,    -1,    -1,    -1,    -1,   456,   581,    -1,   459,   460,
     461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,   624,
      -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
      -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
      -1,    -1,   449,   326,    -1,    -1,    24,    -1,    -1,   456,
     581,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
      -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
      -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
      -1,    -1,   251,   624,    -1,    -1,   503,    -1,   505,   506,
      -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
     289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
      -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
      24,    25,    -1,   456,   581,    -1,   459,   460,   461,    -1,
     463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,
      -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,    -1,    -1,   624,    -1,    -1,
     503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,
      -1,    -1,    -1,   251,    -1,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,
     449,    -1,    -1,    -1,    24,    -1,    -1,   456,   581,    -1,
     459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,    -1,
      -1,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,   482,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   624,    -1,   321,   503,    -1,   505,   506,   326,   508,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   341,    -1,    -1,   525,   526,   346,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,
      -1,   550,    -1,    -1,   372,    -1,    -1,   251,    -1,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    24,    -1,
     398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,    -1,    -1,   289,   290,   291,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,   624,    -1,   321,    -1,    -1,
      -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,    -1,
      -1,   459,   460,   461,    -1,   463,   464,   341,    -1,    -1,
      -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,
     364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,
      -1,   251,    -1,    -1,    -1,   503,    -1,   505,   506,    -1,
     508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,   525,   526,    -1,
      -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,
     290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,
      -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,
      -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,
     464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,
      -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,
      -1,    -1,   372,    -1,    -1,   251,   624,    -1,    -1,   503,
      -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,
     390,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,
     410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,
      -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,
     326,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,
     460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,
     346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,
      -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,
     624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,
      -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,
     406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
     560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,
      -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,
     456,    -1,    -1,   459,   460,   461,    -1,   463,   464,   341,
      -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,
      -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
     372,    -1,    -1,   251,   624,    -1,    -1,   503,    -1,   505,
     506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,   525,
     526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
      -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,
     442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,
      -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,
      -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
     358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,
      -1,    -1,    -1,    -1,   372,    -1,    -1,   251,   624,    -1,
      -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,    -1,    -1,   289,   290,   291,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,
     562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,
      -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,    -1,
      -1,   459,   460,   461,    -1,   463,   464,   341,    -1,    -1,
      -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,
     364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,
      -1,   251,   624,    -1,    -1,   503,    -1,   505,   506,    -1,
     508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,   525,   526,    -1,
      -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,
     290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,
      -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,
      -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,
     464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,
      -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,
      -1,    -1,   372,    -1,    -1,   251,   624,    -1,    -1,   503,
      -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,
     410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,
      -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,
     326,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,
     460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,
     346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,
      -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,
     624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,
      -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,
     406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
     560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,
      -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,
     456,    -1,    -1,   459,   460,   461,    -1,   463,   464,   341,
      -1,    -1,   468,    -1,   346,    -1,   348,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,
      -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
     372,    -1,    -1,   251,   624,    -1,    -1,   503,    -1,   505,
     506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    -1,   521,   398,    -1,    -1,   525,
     526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
      -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,
     442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,
      -1,    -1,    25,    -1,   456,   581,    -1,   459,   460,   461,
      -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
     358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,
      -1,    -1,    -1,    -1,   372,    -1,    -1,   251,   624,    -1,
      -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,    -1,    -1,   289,   290,   291,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,
     562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,
      -1,   449,   326,    -1,    -1,    -1,    -1,    26,   456,   581,
      -1,   459,   460,   461,    -1,   463,   464,   341,    -1,    -1,
      -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,
     364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,
      -1,    -1,   624,    -1,    -1,   503,    -1,   505,   506,    -1,
     508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,
      -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,    -1,
      -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   550,   427,    -1,    -1,    -1,    -1,   251,    -1,
      -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,
      -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,
      -1,    26,   456,   581,    -1,   459,   460,   461,    -1,   463,
     464,    -1,    -1,    -1,    -1,    -1,   289,   290,   291,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,   321,   503,
      -1,   505,   506,   326,   508,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,
      -1,   525,   526,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,    -1,
      -1,   364,    -1,    -1,   367,    -1,   550,    -1,    -1,   372,
      -1,    -1,   251,    -1,    -1,   559,   560,    -1,   562,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
     289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
     624,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
      -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
     463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,    -1,   352,    -1,    -1,    -1,   480,    -1,   358,
      -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,    -1,   251,    -1,    -1,    -1,
     503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,   550,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,
     449,   326,    -1,    -1,    -1,    -1,    -1,   456,   581,    -1,
     459,   460,   461,    76,   463,   464,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,
      -1,    -1,    -1,   126,    -1,   390,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,
      -1,   456,   581,    -1,   459,   460,   461,    -1,   463,   464,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,   624,    -1,    -1,   503,    -1,
     505,   506,    -1,   508,    -1,    -1,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
     525,   526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,   550,   289,   290,   291,    -1,
      80,    81,    82,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,    -1,   326,    -1,    -1,    -1,    -1,    -1,    -1,
     333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,
      -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,   624,
      -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
      -1,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
     220,    -1,    -1,   223,    -1,    -1,    -1,    -1,   441,   442,
      -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,
      -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
     463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
     503,   504,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,   550,    -1,   339,
      -1,    -1,    80,    81,    82,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,   358,   359,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   424,    -1,    -1,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   442,    80,    81,    82,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,    -1,    -1,   223,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,   220,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,
     358,   359,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,
     220,    -1,    -1,   223,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,    -1,   339,   223,   442,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,
      -1,   358,   359,    -1,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   339,
      -1,   223,    -1,    -1,    -1,   523,    -1,   424,    -1,    -1,
      -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,   358,   359,
      -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   354,    -1,   396,    -1,   358,   359,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
     220,    -1,   442,   223,    -1,    -1,   523,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,
      -1,    -1,    50,    51,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   354,    61,    -1,    -1,   358,   359,    -1,    -1,
      -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   396,   592,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   523,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,   339,
     442,    -1,    -1,   523,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,   358,   359,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    80,    81,    82,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   523,    -1,   231,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      -1,    -1,   442,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,
      -1,   289,   290,   291,   220,    -1,    -1,   223,    -1,    -1,
     592,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   321,    -1,    -1,   220,   325,   326,   223,
      -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,   337,
      -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,   347,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,    -1,    -1,   361,    -1,    -1,   364,   365,    -1,   367,
      -1,    -1,    -1,    -1,   372,    -1,    -1,   375,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,   391,    -1,    -1,    -1,    -1,    -1,    -1,
     220,    -1,   592,   223,    -1,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,   339,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,   427,
      -1,    -1,   358,   431,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,   339,    -1,    -1,    -1,    -1,
      -1,   449,    -1,    -1,    -1,    -1,   454,    -1,   456,    -1,
     354,   459,   460,   461,   358,   463,   464,    -1,    -1,    -1,
     396,   469,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,   479,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,   499,   396,   251,   502,   503,   504,   505,   506,    -1,
     508,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,   339,
      -1,    -1,    -1,    -1,    -1,   523,    -1,   525,   526,    -1,
     424,    -1,    -1,    -1,   354,    -1,    -1,    -1,   358,    -1,
      -1,   289,   290,   291,   542,    -1,    -1,    -1,   442,    -1,
      -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   321,    -1,    -1,   396,    -1,   326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,
      -1,    -1,    -1,   341,   342,    -1,    -1,   523,   346,    -1,
     348,    -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,
     358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,
      -1,    -1,   442,    -1,   372,    -1,   624,    -1,    -1,   523,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,
      -1,   409,   410,    -1,    -1,    -1,   592,    -1,   416,    -1,
     289,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,   592,    -1,
      -1,   449,   321,   523,    -1,    -1,    -1,   326,   456,    -1,
      -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,
      -1,    -1,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,   358,
      -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,   503,   251,   505,   506,    -1,
     508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   390,   592,    -1,    -1,    -1,    -1,   525,   526,    -1,
      -1,   529,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,
      -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,
     449,   326,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,
     459,   460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,   476,    -1,    -1,
      -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,
      -1,    -1,   367,    -1,    -1,    -1,   624,   372,    -1,    -1,
     251,    -1,    -1,    -1,   503,    -1,   505,   506,   636,   508,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,
     291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,
     321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,
      -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,
     341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,
      -1,   352,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,
     361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,
      -1,   372,    -1,    -1,   251,   624,    -1,    -1,   503,    -1,
     505,   506,    -1,   508,    -1,    -1,    -1,   636,    -1,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
      -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,
     461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,   624,
      -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
      -1,   636,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,
      -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
      -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
      -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,
     581,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
      -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,   358,   359,    -1,   361,    -1,
      -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
      -1,    -1,   251,   624,    -1,    -1,   503,    -1,   505,   506,
      -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
      -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
     289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
      -1,   558,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
      -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
      -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
     463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,
      -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,    -1,   251,   624,    -1,    -1,
     503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
     409,   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,
     449,   326,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,
     459,   460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,
      -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,
     251,   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,
      -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
      -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,
     291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,   427,    -1,    -1,   430,    -1,    -1,    -1,    -1,
     559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,
     321,    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,
      -1,   456,   581,    -1,   459,   460,   461,    -1,   463,   464,
     341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,
     361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,
      -1,   372,    -1,    -1,    -1,   624,    -1,    -1,   503,    -1,
     505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,
      -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,
     461,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,
      -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
      -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   624
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
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


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
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
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

#line 315 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
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
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
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
#line 857 "fgl.yacc"
{ print_screen_mode(0);}
    break;
case 2:
#line 860 "fgl.yacc"
{ print_screen_mode(1);}
    break;
case 3:
#line 864 "fgl.yacc"
{
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;
case 4:
#line 870 "fgl.yacc"
{
	print_stop_external();
	}
    break;
case 5:
#line 875 "fgl.yacc"
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
#line 887 "fgl.yacc"
{
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;
case 9:
#line 892 "fgl.yacc"
{
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",aclfgl_%s);\n",yyvsp[0].str,yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;
case 10:
#line 910 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;
case 11:
#line 911 "fgl.yacc"
{ sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 12:
#line 912 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 13:
#line 913 "fgl.yacc"
{sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 14:
#line 914 "fgl.yacc"
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
#line 928 "fgl.yacc"
{strcpy(yyval.str,"+");}
    break;
case 16:
#line 929 "fgl.yacc"
{strcpy(yyval.str,"-");}
    break;
case 17:
#line 930 "fgl.yacc"
{strcpy(yyval.str,"*");}
    break;
case 18:
#line 931 "fgl.yacc"
{strcpy(yyval.str,"/");}
    break;
case 19:
#line 932 "fgl.yacc"
{strcpy(yyval.str,"%");}
    break;
case 20:
#line 937 "fgl.yacc"
{strcpy(yyval.str,"+");}
    break;
case 21:
#line 938 "fgl.yacc"
{strcpy(yyval.str,"-");}
    break;
case 22:
#line 949 "fgl.yacc"
{
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;
case 23:
#line 952 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 24:
#line 955 "fgl.yacc"
{start_state("attribute",1);}
    break;
case 25:
#line 955 "fgl.yacc"
{strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;
case 27:
#line 962 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 28:
#line 963 "fgl.yacc"
{
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;
case 29:
#line 969 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;
case 30:
#line 970 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;
case 31:
#line 971 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;
case 32:
#line 972 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;
case 33:
#line 973 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;
case 34:
#line 974 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("RED"));}
    break;
case 35:
#line 975 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;
case 36:
#line 976 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;
case 37:
#line 977 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;
case 38:
#line 978 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;
case 39:
#line 979 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;
case 40:
#line 980 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;
case 41:
#line 981 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;
case 42:
#line 982 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;
case 43:
#line 983 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;
case 44:
#line 984 "fgl.yacc"
{inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;
case 47:
#line 991 "fgl.yacc"
{
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;
case 48:
#line 995 "fgl.yacc"
{start_state("attribute",0);strcpy(yyval.str,"");
}
    break;
case 49:
#line 999 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 50:
#line 1000 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 51:
#line 1004 "fgl.yacc"
{ 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;
case 52:
#line 1010 "fgl.yacc"
{ form_attrib.border      =1;}
    break;
case 53:
#line 1012 "fgl.yacc"
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
#line 1023 "fgl.yacc"
{ form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;
case 55:
#line 1025 "fgl.yacc"
{ form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;
case 56:
#line 1027 "fgl.yacc"
{ form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;
case 57:
#line 1029 "fgl.yacc"
{ form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;
case 58:
#line 1033 "fgl.yacc"
{ form_attrib.message_line=atoi(yyvsp[0].str); }
    break;
case 59:
#line 1035 "fgl.yacc"
{ form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;
case 60:
#line 1096 "fgl.yacc"
{strcpy(yyval.str,"CALL");}
    break;
case 61:
#line 1100 "fgl.yacc"
{ debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;
case 62:
#line 1104 "fgl.yacc"
{
	print_getfldbuf(yyvsp[-2].str);
	}
    break;
case 63:
#line 1107 "fgl.yacc"
{
	print_returning();
}
    break;
case 64:
#line 1111 "fgl.yacc"
{
	print_form_is_compiled(yyvsp[-1].str);
	}
    break;
case 65:
#line 1115 "fgl.yacc"
{
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;
case 67:
#line 1119 "fgl.yacc"
{ 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;
case 68:
#line 1122 "fgl.yacc"
{
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;
case 69:
#line 1128 "fgl.yacc"
{
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
	debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;
case 70:
#line 1137 "fgl.yacc"
{
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;
case 71:
#line 1141 "fgl.yacc"
{
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;
case 72:
#line 1146 "fgl.yacc"
{
	debug("Got args");
   }
    break;
case 73:
#line 1150 "fgl.yacc"
{
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;
case 74:
#line 1158 "fgl.yacc"
{
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;
case 75:
#line 1162 "fgl.yacc"
{
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;
case 76:
#line 1166 "fgl.yacc"
{
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;
case 77:
#line 1169 "fgl.yacc"
{
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;
case 78:
#line 1175 "fgl.yacc"
{
	sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;
case 79:
#line 1180 "fgl.yacc"
{
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;
case 80:
#line 1183 "fgl.yacc"
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
case 81:
#line 1199 "fgl.yacc"
{
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;
case 82:
#line 1206 "fgl.yacc"
{
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;
case 83:
#line 1210 "fgl.yacc"
{
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;
case 84:
#line 1214 "fgl.yacc"
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
case 85:
#line 1236 "fgl.yacc"
{start_bind('i',0);strcpy(yyval.str,"0");}
    break;
case 86:
#line 1236 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);
}
    break;
case 87:
#line 1240 "fgl.yacc"
{start_bind('i',0);strcpy(yyval.str,"0");}
    break;
case 88:
#line 1241 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 89:
#line 1242 "fgl.yacc"
{strcpy(yyval.str,"WITHOUT WAITING"); }
    break;
case 90:
#line 1247 "fgl.yacc"
{
			yyval.ptr=new_expr("");
		}
    break;
case 91:
#line 1250 "fgl.yacc"
{
			yyval.ptr=yyvsp[0].ptr;
		}
    break;
case 92:
#line 1256 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
}
    break;
case 93:
#line 1259 "fgl.yacc"
{
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;
case 96:
#line 1271 "fgl.yacc"
{
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;
case 97:
#line 1277 "fgl.yacc"
{
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;
case 98:
#line 1280 "fgl.yacc"
{ sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;
case 99:
#line 1295 "fgl.yacc"
{
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;
case 100:
#line 1305 "fgl.yacc"
{
print_after_when(0);
pop_blockcommand("CASE");
}
    break;
case 101:
#line 1311 "fgl.yacc"
{  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;
case 102:
#line 1320 "fgl.yacc"
{
print_after_when(0);
pop_blockcommand("CASE");
}
    break;
case 107:
#line 1333 "fgl.yacc"
{setinc(-1);incprint();}
    break;
case 109:
#line 1336 "fgl.yacc"
{
incprint();
}
    break;
case 110:
#line 1338 "fgl.yacc"
{incprint();
print_after_when(0);
}
    break;
case 112:
#line 1344 "fgl.yacc"
{incprint();}
    break;
case 113:
#line 1346 "fgl.yacc"
{incprint();
print_after_when(0);
}
    break;
case 114:
#line 1351 "fgl.yacc"
{
print_when(0);

incprint();
}
    break;
case 115:
#line 1356 "fgl.yacc"
{incprint();
print_after_when(1);
setinc(-1);}
    break;
case 116:
#line 1362 "fgl.yacc"
{
incprint();
print_when(1);
}
    break;
case 117:
#line 1366 "fgl.yacc"
{incprint();
print_after_when(1);
setinc(-1);}
    break;
case 118:
#line 1381 "fgl.yacc"
{
  print_close('F',yyvsp[0].str);
 }
    break;
case 119:
#line 1384 "fgl.yacc"
{
  print_close('W',yyvsp[0].str);
}
    break;
case 120:
#line 1387 "fgl.yacc"
{
  print_close('W',yyvsp[0].str);
}
    break;
case 121:
#line 1390 "fgl.yacc"
{
  print_close('D',0);
}
    break;
case 122:
#line 1393 "fgl.yacc"
{
  print_close('S',yyvsp[0].str);
}
    break;
case 123:
#line 1396 "fgl.yacc"
{
  print_close('C',yyvsp[0].str);
}
    break;
case 129:
#line 1418 "fgl.yacc"
{
			lex_printc("%s",yyvsp[0].str);
}
    break;
case 132:
#line 1427 "fgl.yacc"
{
			lex_printc("%s\n",yyvsp[0].str);
}
    break;
case 133:
#line 1437 "fgl.yacc"
{
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
}
    break;
case 134:
#line 1451 "fgl.yacc"
{
push_blockcommand("CONSTRUCT");
}
    break;
case 135:
#line 1455 "fgl.yacc"
{
	print_construct_1();
}
    break;
case 136:
#line 1458 "fgl.yacc"
{
	print_construct_2(yyvsp[-2].str);
}
    break;
case 137:
#line 1466 "fgl.yacc"
{
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	sprintf(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;
case 138:
#line 1472 "fgl.yacc"
{
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	sprintf(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;
case 143:
#line 1487 "fgl.yacc"
{
                push_construct("",yyval.str);
             }
    break;
case 144:
#line 1491 "fgl.yacc"
{
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;
case 145:
#line 1496 "fgl.yacc"
{
                push_construct(yyvsp[-2].str,"*");
             }
    break;
case 148:
#line 1506 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
	}
    break;
case 149:
#line 1509 "fgl.yacc"
{
		print_befaft_field_2();

	}
    break;
case 150:
#line 1513 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
	}
    break;
case 151:
#line 1515 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 152:
#line 1518 "fgl.yacc"
{
		print_onkey_1(yyvsp[0].str);
	}
    break;
case 153:
#line 1520 "fgl.yacc"
{
		print_onkey_2();
	}
    break;
case 154:
#line 1523 "fgl.yacc"
{
		print_befaft_field_1("AFTER_INP");
	}
    break;
case 155:
#line 1525 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 156:
#line 1528 "fgl.yacc"
{
		print_befaft_field_1("BEFORE_INP");
		}
    break;
case 157:
#line 1531 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 158:
#line 1541 "fgl.yacc"
{sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;
case 159:
#line 1542 "fgl.yacc"
{
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 160:
#line 1550 "fgl.yacc"
{sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;
case 161:
#line 1551 "fgl.yacc"
{
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 162:
#line 1568 "fgl.yacc"
{
        	yyval.ptr=new_expr("pushop(OP_YEAR);");
	}
    break;
case 163:
#line 1571 "fgl.yacc"
{
        	yyval.ptr=new_expr("pushop(OP_MONTH);");
	}
    break;
case 164:
#line 1574 "fgl.yacc"
{
        	yyval.ptr=new_expr("pushop(OP_DAY);");
	}
    break;
case 165:
#line 1577 "fgl.yacc"
{
        	yyval.ptr=new_expr("pushop(OP_HOUR);");
	}
    break;
case 166:
#line 1580 "fgl.yacc"
{
        	yyval.ptr=new_expr("pushop(OP_MINUTE);");
	}
    break;
case 167:
#line 1583 "fgl.yacc"
{
        	yyval.ptr=new_expr("pushop(OP_SECOND);");
	}
    break;
case 168:
#line 1596 "fgl.yacc"
{
				print_defer(0);
			}
    break;
case 169:
#line 1600 "fgl.yacc"
{
				print_defer(1);
			}
    break;
case 170:
#line 1615 "fgl.yacc"
{strcpy(yyval.str,"");if (modlevel>=0) print_variables();}
    break;
case 171:
#line 1616 "fgl.yacc"
{strcpy(yyval.str,"");if (modlevel>=0) print_variables();lastlineno=yylineno;}
    break;
case 174:
#line 1624 "fgl.yacc"
{dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;
case 175:
#line 1624 "fgl.yacc"
{lex_printcomment("/*end def */\n");}
    break;
case 180:
#line 1632 "fgl.yacc"
{in_define=1;}
    break;
case 181:
#line 1632 "fgl.yacc"
{in_define=0;strcpy(yyval.str,yyvsp[0].str);}
    break;
case 182:
#line 1636 "fgl.yacc"
{ add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;
case 183:
#line 1637 "fgl.yacc"
{ add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;
case 184:
#line 1640 "fgl.yacc"
{ 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;
case 186:
#line 1645 "fgl.yacc"
{ }
    break;
case 187:
#line 1645 "fgl.yacc"
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
case 191:
#line 1662 "fgl.yacc"
{
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;
case 192:
#line 1666 "fgl.yacc"
{
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 197:
#line 1680 "fgl.yacc"
{
debug("defines array %s",yyvsp[-1].str);
push_type(0,0,yyvsp[-1].str);
}
    break;
case 199:
#line 1689 "fgl.yacc"
{
push_associate(yyvsp[-5].str,yyvsp[-1].str);
push_type(0,0,yyvsp[-1].str);
}
    break;
case 200:
#line 1693 "fgl.yacc"
{
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;
case 206:
#line 1709 "fgl.yacc"
{sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;
case 207:
#line 1711 "fgl.yacc"
{sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;
case 208:
#line 1712 "fgl.yacc"
{debug("Single");}
    break;
case 210:
#line 1719 "fgl.yacc"
{push_record();in_record++;}
    break;
case 211:
#line 1719 "fgl.yacc"
{pop_record();in_record--;}
    break;
case 212:
#line 1720 "fgl.yacc"
{in_record++;push_record();debug("Like\n");}
    break;
case 213:
#line 1721 "fgl.yacc"
{debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;
case 214:
#line 1724 "fgl.yacc"
{
		push_record();debug("Like\n");}
    break;
case 215:
#line 1726 "fgl.yacc"
{
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;
case 217:
#line 1736 "fgl.yacc"
{
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 220:
#line 1747 "fgl.yacc"
{start_state("dtype",1);}
    break;
case 221:
#line 1747 "fgl.yacc"
{start_state("dtype",0);}
    break;
case 224:
#line 1753 "fgl.yacc"
{push_type("char","1",0);}
    break;
case 225:
#line 1754 "fgl.yacc"
{
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;
case 226:
#line 1761 "fgl.yacc"
{push_type("char",yyvsp[-1].str,0);}
    break;
case 227:
#line 1762 "fgl.yacc"
{push_type("char",yyvsp[-3].str,0);}
    break;
case 228:
#line 1763 "fgl.yacc"
{push_type("long",0,0);}
    break;
case 229:
#line 1764 "fgl.yacc"
{
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;
case 230:
#line 1767 "fgl.yacc"
{push_type("int",0,0);}
    break;
case 231:
#line 1768 "fgl.yacc"
{push_type("form",0,0);}
    break;
case 232:
#line 1769 "fgl.yacc"
{push_type("form",0,0);}
    break;
case 233:
#line 1770 "fgl.yacc"
{ char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;
case 234:
#line 1774 "fgl.yacc"
{
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;
case 235:
#line 1779 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;
case 236:
#line 1784 "fgl.yacc"
{
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;
case 237:
#line 1788 "fgl.yacc"
{
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;
case 238:
#line 1791 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;
case 239:
#line 1795 "fgl.yacc"
{push_type("double",0,0);}
    break;
case 240:
#line 1796 "fgl.yacc"
{push_type("float",0,0);}
    break;
case 241:
#line 1797 "fgl.yacc"
{push_type("fgldate",0,0);}
    break;
case 242:
#line 1798 "fgl.yacc"
{push_type("fglbyte",0,0);}
    break;
case 243:
#line 1799 "fgl.yacc"
{push_type("fglbyte",0,0);}
    break;
case 244:
#line 1800 "fgl.yacc"
{push_type("fgltext",0,0);}
    break;
case 245:
#line 1801 "fgl.yacc"
{push_type("fgltext",0,0);}
    break;
case 246:
#line 1802 "fgl.yacc"
{
push_type("struct_dtime ",yyvsp[0].str,0);
}
    break;
case 247:
#line 1805 "fgl.yacc"
{push_type("struct_ival ",yyvsp[0].str,0);}
    break;
case 248:
#line 1806 "fgl.yacc"
{push_like(yyvsp[0].str);fflush(stdout);lex_printcomment("/*added(XXXXX)\n */");}
    break;
case 249:
#line 1807 "fgl.yacc"
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
				if ((int)function != -1) 
				{
					debug("call returns %s\n",function());
					strcpy(buff,function());
					debug("Set up buff as %s");
					push_type(function(),0,0);
					debug("Pushed type : %s\n",function());
				}
			} else {
				/* yyerror("Unknown datatype : %s",$<str>1); */
                yyerror("Unknown datatype.");
			}
		}
    break;
case 250:
#line 1839 "fgl.yacc"
{
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;
case 251:
#line 1843 "fgl.yacc"
{debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;
case 252:
#line 1845 "fgl.yacc"
{debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;
case 253:
#line 1847 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 254:
#line 1849 "fgl.yacc"
{
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;
case 255:
#line 1854 "fgl.yacc"
{
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;
case 256:
#line 1858 "fgl.yacc"
{start_state("dtime_val",1);}
    break;
case 257:
#line 1858 "fgl.yacc"
{start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;
case 258:
#line 1861 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 259:
#line 1862 "fgl.yacc"
{strcpy(yyval.str,"2");}
    break;
case 260:
#line 1863 "fgl.yacc"
{strcpy(yyval.str,"3");}
    break;
case 261:
#line 1864 "fgl.yacc"
{strcpy(yyval.str,"4");}
    break;
case 262:
#line 1865 "fgl.yacc"
{strcpy(yyval.str,"5");}
    break;
case 263:
#line 1866 "fgl.yacc"
{strcpy(yyval.str,"6");}
    break;
case 264:
#line 1868 "fgl.yacc"
{
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;
case 265:
#line 1873 "fgl.yacc"
{start_state("dtime_val",1);}
    break;
case 266:
#line 1873 "fgl.yacc"
{ debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;
case 267:
#line 1876 "fgl.yacc"
{
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;
case 268:
#line 1878 "fgl.yacc"
{
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;
case 269:
#line 1884 "fgl.yacc"
{
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;
case 270:
#line 1886 "fgl.yacc"
{
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;
case 271:
#line 1892 "fgl.yacc"
{
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;
case 272:
#line 1900 "fgl.yacc"
{start_state("interval_val",1);}
    break;
case 273:
#line 1900 "fgl.yacc"
{start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;
case 274:
#line 1903 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 275:
#line 1904 "fgl.yacc"
{strcpy(yyval.str,"2");}
    break;
case 276:
#line 1905 "fgl.yacc"
{strcpy(yyval.str,"3");}
    break;
case 277:
#line 1906 "fgl.yacc"
{strcpy(yyval.str,"4");}
    break;
case 278:
#line 1907 "fgl.yacc"
{strcpy(yyval.str,"5");}
    break;
case 279:
#line 1908 "fgl.yacc"
{strcpy(yyval.str,"6");}
    break;
case 280:
#line 1910 "fgl.yacc"
{
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;
case 284:
#line 1931 "fgl.yacc"
{
              	dim_set_name(yyvsp[0].str);
              }
    break;
case 288:
#line 1940 "fgl.yacc"
{dim_push_type("char","1",0);}
    break;
case 289:
#line 1942 "fgl.yacc"
{dim_push_type("char",yyvsp[-1].str,0);}
    break;
case 290:
#line 1944 "fgl.yacc"
{dim_push_type("char",yyvsp[-1].str,0);}
    break;
case 291:
#line 1946 "fgl.yacc"
{dim_push_type("char",yyvsp[-3].str,0);}
    break;
case 292:
#line 1947 "fgl.yacc"
{dim_push_type("long",0,0);}
    break;
case 293:
#line 1948 "fgl.yacc"
{dim_push_type("integer",0,0);}
    break;
case 294:
#line 1949 "fgl.yacc"
{dim_push_type("FORM",0,0);}
    break;
case 295:
#line 1950 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;
case 296:
#line 1955 "fgl.yacc"
{

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;
case 297:
#line 1962 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;
case 298:
#line 1967 "fgl.yacc"
{dim_push_type("fglmoney",0,0);}
    break;
case 299:
#line 1969 "fgl.yacc"
{dim_push_type("fglmoney",0,0);}
    break;
case 300:
#line 1971 "fgl.yacc"
{dim_push_type("fglmoney",0,0);}
    break;
case 301:
#line 1972 "fgl.yacc"
{dim_push_type("double",0,0);}
    break;
case 302:
#line 1973 "fgl.yacc"
{dim_push_type("float",0,0);}
    break;
case 303:
#line 1974 "fgl.yacc"
{dim_push_type("fgldate",0,0);}
    break;
case 304:
#line 1975 "fgl.yacc"
{dim_push_type("fglbyte",0,0);}
    break;
case 305:
#line 1976 "fgl.yacc"
{dim_push_type("fgltext",0,0);}
    break;
case 306:
#line 1977 "fgl.yacc"
{
dim_push_type("struct_dtime ",yyvsp[0].str,0);
}
    break;
case 307:
#line 1980 "fgl.yacc"
{dim_push_type("struct_ival ",0,0);}
    break;
case 308:
#line 1982 "fgl.yacc"
{dim_push_like(yyvsp[0].str);fflush(stdout);lex_printcomment("/*added(XXXXX)\n */");}
    break;
case 309:
#line 1988 "fgl.yacc"
{
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;
case 310:
#line 1996 "fgl.yacc"
{
dim_push_type(0,0,yyvsp[-1].str);
}
    break;
case 312:
#line 2004 "fgl.yacc"
{
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;
case 313:
#line 2008 "fgl.yacc"
{
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;
case 314:
#line 2016 "fgl.yacc"
{dim_push_record();}
    break;
case 315:
#line 2017 "fgl.yacc"
{dim_pop_record();}
    break;
case 316:
#line 2018 "fgl.yacc"
{dim_push_record();debug("Like\n");}
    break;
case 317:
#line 2019 "fgl.yacc"
{debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;
case 323:
#line 2038 "fgl.yacc"
{ dim_push_name(yyval.str,0); }
    break;
case 324:
#line 2050 "fgl.yacc"
{
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;
case 325:
#line 2054 "fgl.yacc"
{
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;
case 326:
#line 2057 "fgl.yacc"
{ 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;
case 327:
#line 2060 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(4,0,0)); }
    break;
case 328:
#line 2061 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;
case 329:
#line 2062 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;
case 330:
#line 2063 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;
case 331:
#line 2064 "fgl.yacc"
{ 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;
case 332:
#line 2070 "fgl.yacc"
{
		print_display_by_name(yyvsp[0].str);
                }
    break;
case 333:
#line 2075 "fgl.yacc"
{ 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;
case 334:
#line 2080 "fgl.yacc"
{
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;
case 335:
#line 2085 "fgl.yacc"
{
		push_blockcommand("DISPLAY");
		}
    break;
case 336:
#line 2089 "fgl.yacc"
{
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;
case 337:
#line 2092 "fgl.yacc"
{
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;
case 338:
#line 2100 "fgl.yacc"
{
sprintf(yyval.str,"0,0");
}
    break;
case 339:
#line 2102 "fgl.yacc"
{
	sprintf(yyval.str,yyvsp[0].str);
}
    break;
case 340:
#line 2107 "fgl.yacc"
{
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;
case 345:
#line 2119 "fgl.yacc"
{
		print_befaft_field_1("AFT_ROW");
		}
    break;
case 346:
#line 2122 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 347:
#line 2125 "fgl.yacc"
{
		print_befaft_field_1("BEF_ROW");
		}
    break;
case 348:
#line 2128 "fgl.yacc"
{
		print_befaft_field_2();
	}
    break;
case 349:
#line 2131 "fgl.yacc"
{
		print_onkey_1(yyvsp[0].str);
		}
    break;
case 350:
#line 2134 "fgl.yacc"
{
		print_onkey_2();
	}
    break;
case 351:
#line 2147 "fgl.yacc"
{
			print_error(yyvsp[0].str,0);
		}
    break;
case 352:
#line 2150 "fgl.yacc"
{ 
			print_error(yyvsp[-1].str,1);
	}
    break;
case 353:
#line 2165 "fgl.yacc"
{ if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;
case 354:
#line 2167 "fgl.yacc"
{ if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;
case 355:
#line 2169 "fgl.yacc"
{ if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;
case 356:
#line 2171 "fgl.yacc"
{ if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;
case 357:
#line 2173 "fgl.yacc"
{ if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;
case 358:
#line 2175 "fgl.yacc"
{ if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;
case 359:
#line 2176 "fgl.yacc"
{
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;
case 360:
#line 2183 "fgl.yacc"
{ if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;
case 361:
#line 2185 "fgl.yacc"
{ if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;
case 362:
#line 2189 "fgl.yacc"
{ if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;
case 363:
#line 2191 "fgl.yacc"
{ if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;
case 364:
#line 2193 "fgl.yacc"
{ if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;
case 365:
#line 2195 "fgl.yacc"
{ if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;
case 366:
#line 2197 "fgl.yacc"
{ if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;
case 367:
#line 2199 "fgl.yacc"
{ if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;
case 368:
#line 2201 "fgl.yacc"
{ if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;
case 369:
#line 2207 "fgl.yacc"
{ if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;
case 370:
#line 2221 "fgl.yacc"
{
	print_exit_program(0);
}
    break;
case 371:
#line 2224 "fgl.yacc"
{
	print_exit_program(1);
}
    break;
case 376:
#line 2241 "fgl.yacc"
{
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;
case 379:
#line 2247 "fgl.yacc"
{
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;
case 380:
#line 2251 "fgl.yacc"
{
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;
case 381:
#line 2256 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
}
    break;
case 385:
#line 2266 "fgl.yacc"
{ yyval.ptr=new_expr("add_spaces();"); }
    break;
case 392:
#line 2277 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 395:
#line 2281 "fgl.yacc"
{yyval.ptr=new_expr("push_null()");}
    break;
case 396:
#line 2285 "fgl.yacc"
{
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;
case 397:
#line 2291 "fgl.yacc"
{
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;
case 398:
#line 2299 "fgl.yacc"
{
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;
case 399:
#line 2305 "fgl.yacc"
{
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;
case 400:
#line 2314 "fgl.yacc"
{sprintf(yyval.str,"%d",get_counter_val());}
    break;
case 401:
#line 2316 "fgl.yacc"
{
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;
case 402:
#line 2323 "fgl.yacc"
{
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;
case 403:
#line 2331 "fgl.yacc"
{
	strcpy(yyval.str,"+");
}
    break;
case 404:
#line 2335 "fgl.yacc"
{
	strcpy(yyval.str,"-");
}
    break;
case 405:
#line 2344 "fgl.yacc"
{
	
        /* sprintf($<str>$,"%s pushop(OP_NOT);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;
case 406:
#line 2350 "fgl.yacc"
{
        /* sprintf($<str>$,"push_int(1);"); */
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;
case 407:
#line 2356 "fgl.yacc"
{
        /* sprintf($<str>$,"push_int(0);"); */
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;
case 408:
#line 2361 "fgl.yacc"
{ yyval.ptr=yyvsp[-1].ptr; }
    break;
case 409:
#line 2363 "fgl.yacc"
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
case 410:
#line 2373 "fgl.yacc"
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
case 411:
#line 2387 "fgl.yacc"
{
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,get_push_literal('D',yyval.str));
        /* sprintf($<str>$,"push_double((double)%s%s)",$<str>1,$<str>2); */
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;
case 412:
#line 2396 "fgl.yacc"
{
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 413:
#line 2406 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%d);",atoi(yyvsp[0].str));inc_counter(); 
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 414:
#line 2409 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%s);",yyvsp[0].str); inc_counter();
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 415:
#line 2413 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('S',yyvsp[0].str));
	/* sprintf($<str>$,"push_char(%s);",$<str>1); */
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 416:
#line 2420 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('D',yyvsp[0].str));
	/* sprintf($<str>$,"push_double((double)%s);",$<str>1); */
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 417:
#line 2427 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 418:
#line 2433 "fgl.yacc"
{
char r1[256];
char r2[256];
char buff[256];
/* char kp[40000]; */
char *ptr1;
char *ptr2;
void *p1;
int v1;
int v2 = 0;
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
		sprintf(bbz,"push_variable(%s,0x%x);",buff,(int)scan_variable(buff));
		append_expr(p1,bbz);
        }
}
    break;
case 419:
#line 2497 "fgl.yacc"
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
               sprintf(yyval.str,"push_variable(&rep.page_no,2);");
		  }
          if (aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               flg=1;
               sprintf(yyval.str,"push_variable(&rep.line_no,2);");
          }
         if (flg==0) {
         sprintf(yyval.str,"push_variable(&%s,0x%x);",yyvsp[0].str,(int)scan_variable(yyvsp[0].str));
         }
   inc_counter();
   }

	if (a==-1) 
	{ 
		sprintf(yyval.str,"push_char(%s);",yyvsp[0].str);inc_counter();
	}

	if (a==-2) 
	{
	        char b[40000];
	        lex_printcomment("/* print_push_rec... %s */",yyvsp[0].str);
	        incvcnt=print_push_rec(yyvsp[0].str,b);
	        inc_counter_by(incvcnt);
			debug("Copy");
	        strcpy(yyval.str,b);
	}


	yyval.ptr=new_expr(yyval.str);
}
    break;
case 420:
#line 2551 "fgl.yacc"
{
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;
case 421:
#line 2557 "fgl.yacc"
{
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;
case 422:
#line 2561 "fgl.yacc"
{
   if (!in_command("REPORT")) {
   yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=new_expr(yyvsp[0].str);
}
    break;
case 423:
#line 2569 "fgl.yacc"
{insql=1;set_ingroup();}
    break;
case 424:
#line 2569 "fgl.yacc"
{
	char buff[256];
      if (!in_command("REPORT")) {
        yyerror("This can only be done in a report!");YYERROR;
      } 
      insql=0; 
	lex_printcomment("/* rep_Agg = %s\n*/",yyvsp[0].str);
        sprintf(buff,yyvsp[0].str);
	debug("report aggregate :  %s",buff);
	yyval.ptr=new_expr(buff);
      }
    break;
case 425:
#line 2586 "fgl.yacc"
{
	/* sprintf($<str>$,"%s pushop(OP_AND);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
}
    break;
case 426:
#line 2591 "fgl.yacc"
{
	/* sprintf($<str>$,"%s pushop(OP_OR);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
}
    break;
case 427:
#line 2598 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
	}
    break;
case 428:
#line 2601 "fgl.yacc"
{
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;
case 429:
#line 2609 "fgl.yacc"
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
case 430:
#line 2620 "fgl.yacc"
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
case 431:
#line 2630 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
}
    break;
case 432:
#line 2636 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
}
    break;
case 433:
#line 2646 "fgl.yacc"
{ 
	sprintf(yyval.str,"pushop(OP_ISNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 434:
#line 2651 "fgl.yacc"
{
	sprintf(yyval.str,"pushop(OP_ISNOTNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 435:
#line 2659 "fgl.yacc"
{
	/* sprintf($<str>$,"%s pushop(OP_MATCHES);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);");
}
    break;
case 436:
#line 2664 "fgl.yacc"
{
	/* sprintf($<str>$,"%s pushop(OP_MATCHES);pushop(OP_NOT);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);pushop(OP_NOT);");
}
    break;
case 437:
#line 2669 "fgl.yacc"
{
	/* sprintf($<str>$," %s pushop(OP_LIKE);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);");
}
    break;
case 438:
#line 2674 "fgl.yacc"
{
	/* sprintf($<str>$,"pushop(OP_LIKE);pushop(OP_NOT);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);pushop(OP_NOT);");
}
    break;
case 439:
#line 2682 "fgl.yacc"
{
	sprintf(yyval.str,"pushop(OP_CLIP);");
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;
case 440:
#line 2690 "fgl.yacc"
{
	sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
}
    break;
case 441:
#line 2698 "fgl.yacc"
{
	debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
}
    break;
case 442:
#line 2703 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
}
    break;
case 443:
#line 2707 "fgl.yacc"
{
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
}
    break;
case 444:
#line 2712 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
}
    break;
case 445:
#line 2716 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
}
    break;
case 446:
#line 2720 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
}
    break;
case 447:
#line 2726 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;
case 448:
#line 2729 "fgl.yacc"
{
	sprintf(yyval.str,"%s pushop(OP_EQUAL);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;
case 449:
#line 2734 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
}
    break;
case 450:
#line 2738 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
}
    break;
case 451:
#line 2742 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
}
    break;
case 452:
#line 2746 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
}
    break;
case 453:
#line 2750 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
}
    break;
case 454:
#line 2756 "fgl.yacc"
{
	reset_counter();
}
    break;
case 455:
#line 2766 "fgl.yacc"
{ 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;
case 456:
#line 2771 "fgl.yacc"
{ 
		sprintf(yyval.str,"%d",get_counter_val()); 
		lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;
case 457:
#line 2777 "fgl.yacc"
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
case 458:
#line 2786 "fgl.yacc"
{
        sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;
case 459:
#line 2791 "fgl.yacc"
{
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;
case 460:
#line 2794 "fgl.yacc"
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
case 461:
#line 2808 "fgl.yacc"
{inc_counter();chk4var=1;}
    break;
case 462:
#line 2808 "fgl.yacc"
{chk4var=0;}
    break;
case 463:
#line 2808 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;
case 464:
#line 2811 "fgl.yacc"
{inc_counter();chk4var=1;}
    break;
case 465:
#line 2811 "fgl.yacc"
{chk4var=0;}
    break;
case 466:
#line 2811 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;
case 467:
#line 2814 "fgl.yacc"
{inc_counter();chk4var=1;}
    break;
case 468:
#line 2814 "fgl.yacc"
{chk4var=0;}
    break;
case 469:
#line 2814 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;
case 470:
#line 2817 "fgl.yacc"
{inc_counter();chk4var=1;}
    break;
case 471:
#line 2817 "fgl.yacc"
{chk4var=0;}
    break;
case 472:
#line 2817 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;
case 474:
#line 2825 "fgl.yacc"
{
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

}
    break;
case 475:
#line 2831 "fgl.yacc"
{sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;
case 476:
#line 2832 "fgl.yacc"
{
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;
case 477:
#line 2837 "fgl.yacc"
{sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 478:
#line 2841 "fgl.yacc"
{ sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 481:
#line 2848 "fgl.yacc"
{
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	}
    break;
case 482:
#line 2853 "fgl.yacc"
{ inc_counter(); sprintf(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		}
    break;
case 483:
#line 2860 "fgl.yacc"
{ 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
}
    break;
case 484:
#line 2864 "fgl.yacc"
{ 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
}
    break;
case 485:
#line 2867 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%d);",atoi(yyvsp[-1].str));
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 486:
#line 2870 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%s);",yyvsp[-1].str);
	yyval.ptr=new_expr(yyval.str);
}
    break;
case 487:
#line 2875 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
}
    break;
case 488:
#line 2878 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
}
    break;
case 489:
#line 2881 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
}
    break;
case 490:
#line 2896 "fgl.yacc"
{
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;
case 491:
#line 2900 "fgl.yacc"
{debug("For_cmds\n");}
    break;
case 492:
#line 2901 "fgl.yacc"
{

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");}
    break;
case 493:
#line 2908 "fgl.yacc"
{
		print_for_default_step();
	}
    break;
case 495:
#line 2925 "fgl.yacc"
{
push_blockcommand("FOREACH");
}
    break;
case 496:
#line 2929 "fgl.yacc"
{
print_foreach_start();
lex_printcomment(" /* foreach */\n");
}
    break;
case 497:
#line 2934 "fgl.yacc"
{
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 498:
#line 2938 "fgl.yacc"
{
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;
case 499:
#line 2954 "fgl.yacc"
{
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;
case 500:
#line 2960 "fgl.yacc"
{
		print_getwin();
	}
    break;
case 501:
#line 2967 "fgl.yacc"
{
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;
case 508:
#line 2984 "fgl.yacc"
{
		print_event('B');
        }
    break;
case 509:
#line 2986 "fgl.yacc"
{
		print_event_2();
        }
    break;
case 510:
#line 2989 "fgl.yacc"
{
		print_event('b');
        }
    break;
case 511:
#line 2991 "fgl.yacc"
{
		print_event_2();
        }
    break;
case 516:
#line 3005 "fgl.yacc"
{
		print_event('A');
        }
    break;
case 517:
#line 3007 "fgl.yacc"
{
		print_event_2();
        }
    break;
case 518:
#line 3010 "fgl.yacc"
{
		print_event('a');
        }
    break;
case 519:
#line 3012 "fgl.yacc"
{
		print_event_2();
        }
    break;
case 532:
#line 3043 "fgl.yacc"
{ 
			print_gtk_field('B',0);
		}
    break;
case 533:
#line 3045 "fgl.yacc"
{
			print_gtk_field_2();
		}
    break;
case 534:
#line 3048 "fgl.yacc"
{ 
			print_gtk_field('A',0);
		}
    break;
case 535:
#line 3050 "fgl.yacc"
{
			print_gtk_field_2();
		}
    break;
case 536:
#line 3053 "fgl.yacc"
{
			print_gtk_field('b',yyvsp[0].str);
		}
    break;
case 537:
#line 3055 "fgl.yacc"
{ 
			print_gtk_field_2();
		}
    break;
case 538:
#line 3058 "fgl.yacc"
{
			print_gtk_field('a',yyvsp[0].str);
		}
    break;
case 539:
#line 3060 "fgl.yacc"
{ 
			print_gtk_field_2();
		}
    break;
case 540:
#line 3063 "fgl.yacc"
{ 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;
case 541:
#line 3065 "fgl.yacc"
{ 
			print_gtk_field_2();
		}
    break;
case 542:
#line 3080 "fgl.yacc"
{
		print_niy("Free Cursor");
		strcpy(yyval.str,"");
		}
    break;
case 543:
#line 3094 "fgl.yacc"
{sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;
case 544:
#line 3095 "fgl.yacc"
{sprintf(yyval.str,"-1");}
    break;
case 545:
#line 3096 "fgl.yacc"
{sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;
case 546:
#line 3097 "fgl.yacc"
{sprintf(yyval.str,"1");}
    break;
case 547:
#line 3098 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);}
    break;
case 548:
#line 3099 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);}
    break;
case 552:
#line 3107 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;
case 554:
#line 3113 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;
case 555:
#line 3114 "fgl.yacc"
{ sprintf(yyval.str,"int_to_id($<str>3)"); }
    break;
case 556:
#line 3115 "fgl.yacc"
{ sprintf(yyval.str,"int_to_id($<str>3)"); }
    break;
case 557:
#line 3117 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;
case 558:
#line 3119 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;
case 559:
#line 3121 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;
case 560:
#line 3123 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 561:
#line 3125 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;
case 562:
#line 3128 "fgl.yacc"
{
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;
case 563:
#line 3135 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 564:
#line 3137 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;
case 565:
#line 3143 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;
case 566:
#line 3148 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;
case 567:
#line 3153 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;
case 568:
#line 3158 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 569:
#line 3158 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 570:
#line 3161 "fgl.yacc"
{ 
			strcpy(yyval.str,downshift(yyvsp[-1].str)) ;
}
    break;
case 571:
#line 3164 "fgl.yacc"
{ strcpy(yyval.str,downshift(yyvsp[0].str)) ; }
    break;
case 572:
#line 3168 "fgl.yacc"
{
			sprintf(yyval.str,"%s",yyvsp[-1].str) ;
			}
    break;
case 573:
#line 3173 "fgl.yacc"
{
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;
case 574:
#line 3177 "fgl.yacc"
{
strcpy(yyval.str,yyvsp[-1].str);
sprintf(last_var,"->%s",yyvsp[-1].str);
}
    break;
case 577:
#line 3185 "fgl.yacc"
{
		debug("Setident\n");
		/* chk4var=1; */
	strcpy(yyval.str,"");
	   }
    break;
case 578:
#line 3191 "fgl.yacc"
{
		debug("Unsetident\n");
		chk4var=0;
		}
    break;
case 579:
#line 3195 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;
case 580:
#line 3197 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;
case 581:
#line 3199 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;
case 582:
#line 3201 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;
case 583:
#line 3203 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 584:
#line 3205 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;
case 585:
#line 3208 "fgl.yacc"
{
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;
case 587:
#line 3217 "fgl.yacc"
{
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;
case 628:
#line 3275 "fgl.yacc"
{
	print_goto(yyvsp[0].str);
}
    break;
case 629:
#line 3288 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;
case 631:
#line 3295 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 632:
#line 3298 "fgl.yacc"
{
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;
case 633:
#line 3304 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;
case 634:
#line 3310 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;
case 635:
#line 3314 "fgl.yacc"
{
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;
case 636:
#line 3318 "fgl.yacc"
{
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;
case 637:
#line 3324 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;
case 638:
#line 3328 "fgl.yacc"
{
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;
case 639:
#line 3332 "fgl.yacc"
{
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;
case 640:
#line 3337 "fgl.yacc"
{start_state("messagebox",1);}
    break;
case 641:
#line 3342 "fgl.yacc"
{start_state("messagebox",0);}
    break;
case 660:
#line 3383 "fgl.yacc"
{
		print_if_start();
	}
    break;
case 661:
#line 3388 "fgl.yacc"
{
		print_if_end();
	}
    break;
case 663:
#line 3393 "fgl.yacc"
{
		print_if_else();
	}
    break;
case 665:
#line 3398 "fgl.yacc"
{
	print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;
case 667:
#line 3404 "fgl.yacc"
{
		add_ex_dtype(yyvsp[0].str);
	}
    break;
case 668:
#line 3416 "fgl.yacc"
{debug("init to\n");}
    break;
case 669:
#line 3417 "fgl.yacc"
{
	print_init();
 }
    break;
case 670:
#line 3420 "fgl.yacc"
{
	print_init_table(yyvsp[0].str);
}
    break;
case 672:
#line 3426 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 673:
#line 3430 "fgl.yacc"
{setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;
case 674:
#line 3431 "fgl.yacc"
{setrecord(yyval.str,yyvsp[-2].str,0);}
    break;
case 677:
#line 3445 "fgl.yacc"
{
sprintf(yyval.str,"0");
}
    break;
case 678:
#line 3447 "fgl.yacc"
{
sprintf(yyval.str,"1");
}
    break;
case 681:
#line 3456 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
}
    break;
case 682:
#line 3458 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 683:
#line 3462 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
}
    break;
case 684:
#line 3464 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 685:
#line 3467 "fgl.yacc"
{
		print_befaft_field_1("AFT_ROW");
}
    break;
case 686:
#line 3469 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 687:
#line 3472 "fgl.yacc"
{
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;
case 688:
#line 3475 "fgl.yacc"
{
	print_befaft_field_2();
		}
    break;
case 689:
#line 3478 "fgl.yacc"
{
	print_onkey_1(yyvsp[0].str);
}
    break;
case 690:
#line 3480 "fgl.yacc"
{
	print_onkey_2();
}
    break;
case 691:
#line 3483 "fgl.yacc"
{
		print_befaft_field_1("AFTER_INP");
}
    break;
case 692:
#line 3485 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 693:
#line 3488 "fgl.yacc"
{
		print_befaft_field_1("BEFORE_INP");
}
    break;
case 694:
#line 3490 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 695:
#line 3493 "fgl.yacc"
{lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;
case 696:
#line 3495 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 697:
#line 3498 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
}
    break;
case 698:
#line 3500 "fgl.yacc"
{
	print_befaft_field_2();
}
    break;
case 699:
#line 3506 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;
case 700:
#line 3507 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 701:
#line 3515 "fgl.yacc"
{strcpy(yyval.str,"AFT_INSERT");}
    break;
case 702:
#line 3516 "fgl.yacc"
{strcpy(yyval.str,"AFT_DELETE");}
    break;
case 703:
#line 3521 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;
case 704:
#line 3522 "fgl.yacc"
{
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;
case 705:
#line 3531 "fgl.yacc"
{strcpy(yyval.str,"BEF_INSERT");}
    break;
case 706:
#line 3532 "fgl.yacc"
{strcpy(yyval.str,"BEF_DELETE");}
    break;
case 707:
#line 3539 "fgl.yacc"
{sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;
case 708:
#line 3540 "fgl.yacc"
{
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 709:
#line 3548 "fgl.yacc"
{sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;
case 710:
#line 3549 "fgl.yacc"
{
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;
case 711:
#line 3558 "fgl.yacc"
{
print_next_field(yyvsp[0].str);
}
    break;
case 712:
#line 3563 "fgl.yacc"
{
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 713:
#line 3568 "fgl.yacc"
{sprintf(yyval.str,"\"+\",0");}
    break;
case 714:
#line 3569 "fgl.yacc"
{sprintf(yyval.str,"\"-\",0");}
    break;
case 716:
#line 3574 "fgl.yacc"
{
print_input_1();
}
    break;
case 717:
#line 3577 "fgl.yacc"
{
print_input_2(yyvsp[-2].str);
}
    break;
case 718:
#line 3585 "fgl.yacc"
{
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;
case 719:
#line 3590 "fgl.yacc"
{
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;
case 720:
#line 3594 "fgl.yacc"
{
inp_flags=0;}
    break;
case 721:
#line 3596 "fgl.yacc"
{
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;
case 722:
#line 3605 "fgl.yacc"
{
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;
case 723:
#line 3610 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 724:
#line 3611 "fgl.yacc"
{strcpy(yyval.str,"-1");}
    break;
case 725:
#line 3612 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 726:
#line 3613 "fgl.yacc"
{sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;
case 727:
#line 3616 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 729:
#line 3622 "fgl.yacc"
{iskey=1;}
    break;
case 730:
#line 3622 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;
case 731:
#line 3624 "fgl.yacc"
{strcpy(yyval.str,"->ANY");}
    break;
case 732:
#line 3627 "fgl.yacc"
{iskey=1;}
    break;
case 733:
#line 3627 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;
case 734:
#line 3629 "fgl.yacc"
{sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;
case 735:
#line 3633 "fgl.yacc"
{start_state("keymode",1);iskey=1;}
    break;
case 736:
#line 3633 "fgl.yacc"
{sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;
case 737:
#line 3636 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 738:
#line 3637 "fgl.yacc"
{strcpy(yyval.str,yyvsp[-1].str);}
    break;
case 740:
#line 3640 "fgl.yacc"
{
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 741:
#line 3645 "fgl.yacc"
{start_state("keymode",1);}
    break;
case 742:
#line 3645 "fgl.yacc"
{start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;
case 747:
#line 3652 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 748:
#line 3653 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 749:
#line 3654 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 750:
#line 3655 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 751:
#line 3656 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 752:
#line 3657 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 753:
#line 3658 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 754:
#line 3659 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 755:
#line 3660 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 756:
#line 3661 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 757:
#line 3662 "fgl.yacc"
{ rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;
case 758:
#line 3666 "fgl.yacc"
{
	exitwith ("Expecting a ':'");
}
    break;
case 759:
#line 3670 "fgl.yacc"
{
	print_label(yyvsp[-1].str);
}
    break;
case 760:
#line 3684 "fgl.yacc"
{chk4var=1;}
    break;
case 761:
#line 3684 "fgl.yacc"
{chk4var=0;
lex_printcomment("/*let3*/\n");}
    break;
case 762:
#line 3686 "fgl.yacc"
{
int to_vars;
	
	debug("/*processing let*/\n");
	expand_obind();
	to_vars=how_many_in_bind('o');
	debug("/* To vars=%d */\n",to_vars);
	if (to_vars>=1)
	{

		if (!print_let_manyvars(yyvsp[0].str))
		{
	    		yyerror("Number of variables in let not equal to number of values\n");YYERROR;
		}

	}
	else
	{
	    print_bind_pop1('o');
	}

}
    break;
case 763:
#line 3710 "fgl.yacc"
{
	print_push_null();
	strcpy(yyval.str,"1");
}
    break;
case 765:
#line 3721 "fgl.yacc"
{
		if (!print_linked_cmd('S',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;
case 766:
#line 3727 "fgl.yacc"
{
		 if (!print_linked_cmd('D',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;
case 767:
#line 3733 "fgl.yacc"
{
		 if (!print_linked_cmd('U',yyvsp[0].str)) yyerror("Not a linked variable");
}
    break;
case 768:
#line 3739 "fgl.yacc"
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
#line 3750 "fgl.yacc"
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
#line 3770 "fgl.yacc"
{
	modlevel=-1;
	/* read_glob_var = 1; */
	print_variables();
	/* read_glob_var = 0; */
	set_mod_level(varcnt);set_4gl_vars();set_mod_level(0);
	strcpy(curr_func,"[Module]");
}
    break;
case 771:
#line 3777 "fgl.yacc"
{inmod();}
    break;
case 773:
#line 3781 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 777:
#line 3789 "fgl.yacc"
{
		print_at_termination(yyvsp[0].str);
	}
    break;
case 792:
#line 3810 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 793:
#line 3811 "fgl.yacc"
{
strcpy(yyval.str,"static ");
}
    break;
case 794:
#line 3819 "fgl.yacc"
{
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;
case 795:
#line 3824 "fgl.yacc"
{ 
  sprintf(curr_func,"%s",yyvsp[-1].str);
  addmap("Declare Function",curr_func,"MODULE",yylineno,infilename);
  print_func_start(yyvsp[-3].str,yyvsp[-1].str,0);
  printDeclareFunctionStack(yyvsp[-1].str);
  cnt=0;
}
    break;
case 796:
#line 3832 "fgl.yacc"
{
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;
case 797:
#line 3838 "fgl.yacc"
{
  int c;
  lex_printcomment("/*end of define section */\n");
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;
case 799:
#line 3852 "fgl.yacc"
{
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    lex_printcomment("/*end function*/\n");
  }
    break;
case 800:
#line 3865 "fgl.yacc"
{ 
    lastlineno=yylineno;
    sprintf(curr_func,"MAIN");
    clr_variable(); 
    push_blockcommand("MAIN"); 
    addmap("MAIN",curr_func,"MODULE",yylineno,infilename);
    print_main_1();
  }
    break;
case 801:
#line 3874 "fgl.yacc"
{
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;
case 802:
#line 3880 "fgl.yacc"
{
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");}
    break;
case 803:
#line 3887 "fgl.yacc"
{
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;
case 804:
#line 3892 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 805:
#line 3892 "fgl.yacc"
{
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 806:
#line 3897 "fgl.yacc"
{open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;
case 807:
#line 3902 "fgl.yacc"
{strcpy(yyval.str,"");lastlineno=yylineno;}
    break;
case 808:
#line 3903 "fgl.yacc"
{
	if (glob_only==1) {
       	debug("Read globals section so Im done\n");
       	YYACCEPT;
	}

  	/* read_glob_var = 1;
  	 print_variables ();
  	read_glob_var = 0;
    */
	set_mod_level(varcnt);
}
    break;
case 815:
#line 3925 "fgl.yacc"
{
strcpy(curr_func,"[Globals]");
push_blockcommand("GLOBALS");
lex_printcomment("/* start of globals */\n");
}
    break;
case 816:
#line 3931 "fgl.yacc"
{
pop_blockcommand("GLOBALS");
}
    break;
case 817:
#line 3936 "fgl.yacc"
{
lex_printcomment("/* end of globals */");
debug("end of globals\n");
lastlineno=yylineno;
}
    break;
case 818:
#line 3941 "fgl.yacc"
{
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
case 819:
#line 3964 "fgl.yacc"
{
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;
case 820:
#line 3968 "fgl.yacc"
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
case 821:
#line 3981 "fgl.yacc"
{
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;
case 823:
#line 3998 "fgl.yacc"
{
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;
case 825:
#line 4006 "fgl.yacc"
{
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;
case 826:
#line 4017 "fgl.yacc"
{
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;
case 827:
#line 4021 "fgl.yacc"
{
		print_menu_block_end();
	}
    break;
case 828:
#line 4028 "fgl.yacc"
{
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;
case 829:
#line 4035 "fgl.yacc"
{
		print_menu_block_end();
}
    break;
case 830:
#line 4041 "fgl.yacc"
{
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;
case 831:
#line 4046 "fgl.yacc"
{
		print_menu_block_end();
}
    break;
case 834:
#line 4053 "fgl.yacc"
{strcpy(yyval.str,"\"EMPTY\"");}
    break;
case 835:
#line 4054 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;
case 836:
#line 4056 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str); }
    break;
case 837:
#line 4057 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 838:
#line 4060 "fgl.yacc"
{strcpy(yyval.str,"\"\"");}
    break;
case 839:
#line 4061 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 840:
#line 4062 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 841:
#line 4064 "fgl.yacc"
{
	print_option_op('N',yyvsp[0].str);
}
    break;
case 842:
#line 4069 "fgl.yacc"
{
	print_option_op('S',yyvsp[0].str);
}
    break;
case 843:
#line 4074 "fgl.yacc"
{
	print_option_op('H',yyvsp[0].str);
}
    break;
case 844:
#line 4081 "fgl.yacc"
{sprintf(yyval.str,"MENU_ALL");}
    break;
case 848:
#line 4088 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 849:
#line 4090 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;
case 850:
#line 4092 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;
case 851:
#line 4101 "fgl.yacc"
{
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
}
    break;
case 852:
#line 4106 "fgl.yacc"
{
                push_blockcommand("MENUH");
        }
    break;
case 853:
#line 4110 "fgl.yacc"
{
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;
case 856:
#line 4122 "fgl.yacc"
{

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;
case 857:
#line 4127 "fgl.yacc"
{
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;
case 858:
#line 4132 "fgl.yacc"
{
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;
case 859:
#line 4135 "fgl.yacc"
{
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;
case 860:
#line 4144 "fgl.yacc"
{start_state("message",0);}
    break;
case 861:
#line 4147 "fgl.yacc"
{
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;
case 862:
#line 4151 "fgl.yacc"
{ 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;
case 863:
#line 4155 "fgl.yacc"
{ 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;
case 870:
#line 4172 "fgl.yacc"
{start_state("message",1);}
    break;
case 872:
#line 4174 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 873:
#line 4174 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 874:
#line 4177 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 875:
#line 4187 "fgl.yacc"
{
char buff[256];
char buff2[256];
strcpy(buff,yyvsp[0].str);
lex_printcomment("/* .. var %s*/",buff);
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
case 877:
#line 4210 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 879:
#line 4217 "fgl.yacc"
{ 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;
case 880:
#line 4222 "fgl.yacc"
{

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         lex_printcomment("/* OPEN_SQUARE.. */\n");

         sprintf(buff,"%s.%s",yyvsp[-4].str,yyvsp[-3].str);
         if (scan_variable(buff)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (2)",buff);
           yyerror(buff2);
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
             sprintf (yyval.str, " substr(%s,%d,%s,0)", buff,
                      (int)scan_variable (buff), yyvsp[-1].str);

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;
case 884:
#line 4266 "fgl.yacc"
{
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (3)",yyvsp[-3].str);
           yyerror(buff2); 
           YYERROR;
         }

lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,1)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;
case 885:
#line 4280 "fgl.yacc"
{
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (4)",yyvsp[-3].str);
           yyerror(buff2); 
           YYERROR;
         }
lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,0)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;
case 890:
#line 4304 "fgl.yacc"
{
  int type,arrsize,size,level;
  char buff2[256];
  char arrbuff[256];
  lex_printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  lex_printcomment("/*here %s %x */",yyvsp[-1].str,type);
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
        sprintf (yyval.str, " substr(%s,%d,%s,0)", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
  } else {
 
  if ((type & (0xffff != 0)) || (arrsize>0))
    {
      lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " substr(%s,%d,%s,0)", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }
}

  mcnt++;
}
    break;
case 891:
#line 4356 "fgl.yacc"
{
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;
case 892:
#line 4361 "fgl.yacc"
{
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;
case 893:
#line 4369 "fgl.yacc"
{
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;
case 894:
#line 4374 "fgl.yacc"
{
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;
case 895:
#line 4382 "fgl.yacc"
{
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;
case 896:
#line 4388 "fgl.yacc"
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
      yyerror(buff);
    }

  fflush (stdout);
  mcnt = 0;
}
    break;
case 897:
#line 4409 "fgl.yacc"
{
		debug("Array..");
}
    break;
case 898:
#line 4412 "fgl.yacc"
{ sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); }
    break;
case 899:
#line 4414 "fgl.yacc"
{
  int a;
  int b;
  char buff[256];
  char buff2[256];
  lex_printcomment("/*array variable .let. */");

  sprintf(yyval.str,"%s.%s",yyvsp[-6].str,yyvsp[-3].str);

         if (scan_variable(yyval.str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",yyval.str);
           yyerror(buff2); 
           YYERROR;
         }

  debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s.%s[%s-1]", yyvsp[-6].str, yyvsp[-3].str,yyvsp[-1].str);
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
case 904:
#line 4462 "fgl.yacc"
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
	sprintf(lbuff,yyvsp[0].str);
	sprintf(rbuff,strchr(yyvsp[0].str,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str, change_arr_elem(lbuff));
        sprintf (yyval.str, " let_substr(%s,%d,%s,0)", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
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
      sprintf (yyval.str, " let_substr(%s,%d,%s,0)", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);

      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;
case 905:
#line 4514 "fgl.yacc"
{
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;
case 907:
#line 4521 "fgl.yacc"
{
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;
case 908:
#line 4527 "fgl.yacc"
{
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;
case 909:
#line 4538 "fgl.yacc"
{
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;
case 910:
#line 4545 "fgl.yacc"
{
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;
case 912:
#line 4553 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;
case 913:
#line 4556 "fgl.yacc"
{lex_printcomment("/* Variable */\n");}
    break;
case 914:
#line 4557 "fgl.yacc"
{
			debug("Got an ibind thru...");
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;
case 916:
#line 4562 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;
case 917:
#line 4563 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;
case 918:
#line 4566 "fgl.yacc"
{
start_bind('o',yyvsp[0].str);
}
    break;
case 919:
#line 4569 "fgl.yacc"
{
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;
case 920:
#line 4575 "fgl.yacc"
{
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;
case 921:
#line 4581 "fgl.yacc"
{
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;
case 922:
#line 4585 "fgl.yacc"
{
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;
case 923:
#line 4592 "fgl.yacc"
{
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;
case 924:
#line 4597 "fgl.yacc"
{
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
}
    break;
case 925:
#line 4604 "fgl.yacc"
{
start_bind('O',yyvsp[0].str);
}
    break;
case 926:
#line 4607 "fgl.yacc"
{
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;
case 931:
#line 4620 "fgl.yacc"
{
  int type,arrsize,size,level;
  char arrbuff[256];
  lex_printcomment("/*..array_r_varid..*/");

  get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff);
  sprintf(yyval.str,"%s[%s-1]",yyvsp[-3].str,yyvsp[-1].str);
}
    break;
case 932:
#line 4630 "fgl.yacc"
{
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;
case 933:
#line 4637 "fgl.yacc"
{
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;
case 934:
#line 4644 "fgl.yacc"
{
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;
case 935:
#line 4647 "fgl.yacc"
{
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;
case 936:
#line 4661 "fgl.yacc"
{
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;
case 941:
#line 4678 "fgl.yacc"
{
	print_niy("OPEN_STATUSBOX");
}
    break;
case 942:
#line 4683 "fgl.yacc"
{
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;
case 943:
#line 4689 "fgl.yacc"
{
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;
case 945:
#line 4696 "fgl.yacc"
{ form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;
case 946:
#line 4701 "fgl.yacc"
{sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;
case 947:
#line 4704 "fgl.yacc"
{strcpy(yyval.str,"0,0");}
    break;
case 948:
#line 4705 "fgl.yacc"
{sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;
case 949:
#line 4708 "fgl.yacc"
{strcpy(yyval.str,"\"\"");}
    break;
case 950:
#line 4709 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 951:
#line 4712 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 952:
#line 4713 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 953:
#line 4718 "fgl.yacc"
{
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;
case 954:
#line 4725 "fgl.yacc"
{
	print_open_cursor(yyvsp[0].str,"0");
}
    break;
case 955:
#line 4728 "fgl.yacc"
{
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;
case 956:
#line 4734 "fgl.yacc"
{sprintf(yyval.str,"0,0");}
    break;
case 957:
#line 4736 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 958:
#line 4738 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;
case 959:
#line 4740 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 960:
#line 4743 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 961:
#line 4743 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 962:
#line 4744 "fgl.yacc"
{strcpy(yyval.str,"2");}
    break;
case 963:
#line 4749 "fgl.yacc"
{
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 964:
#line 4757 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 965:
#line 4758 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 966:
#line 4763 "fgl.yacc"
{sprintf(yyval.str,"0,0");}
    break;
case 967:
#line 4765 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 968:
#line 4767 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 972:
#line 4784 "fgl.yacc"
{
print_options('C',yyvsp[0].str);
}
    break;
case 973:
#line 4787 "fgl.yacc"
{
print_options('E',yyvsp[0].str);
}
    break;
case 974:
#line 4790 "fgl.yacc"
{
print_options('F',yyvsp[0].str);
}
    break;
case 975:
#line 4793 "fgl.yacc"
{
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;
case 976:
#line 4796 "fgl.yacc"
{
print_options('m',yyvsp[0].str);
}
    break;
case 977:
#line 4799 "fgl.yacc"
{
print_options('P',yyvsp[0].str);
}
    break;
case 978:
#line 4802 "fgl.yacc"
{
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;
case 979:
#line 4806 "fgl.yacc"
{
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;
case 980:
#line 4810 "fgl.yacc"
{
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;
case 981:
#line 4814 "fgl.yacc"
{
print_options('N',yyvsp[0].str);
}
    break;
case 982:
#line 4817 "fgl.yacc"
{
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;
case 983:
#line 4821 "fgl.yacc"
{
print_options('H',yyvsp[0].str);
}
    break;
case 984:
#line 4824 "fgl.yacc"
{ print_set_helpfile(yyvsp[0].str); }
    break;
case 985:
#line 4825 "fgl.yacc"
{ print_set_langfile(yyvsp[0].str); }
    break;
case 986:
#line 4826 "fgl.yacc"
{
print_options('d',yyvsp[0].str);
}
    break;
case 987:
#line 4829 "fgl.yacc"
{
print_options('i',yyvsp[0].str);
}
    break;
case 988:
#line 4832 "fgl.yacc"
{
print_options('W',"1");
}
    break;
case 989:
#line 4835 "fgl.yacc"
{
print_options('W',"0");
}
    break;
case 990:
#line 4838 "fgl.yacc"
{
print_options('f',"1");
}
    break;
case 991:
#line 4841 "fgl.yacc"
{
print_options('f',"0");
}
    break;
case 992:
#line 4844 "fgl.yacc"
{
print_options('S',"1");
}
    break;
case 993:
#line 4847 "fgl.yacc"
{
print_options('S',"0");
}
    break;
case 994:
#line 4864 "fgl.yacc"
{
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;
case 997:
#line 4874 "fgl.yacc"
{

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 998:
#line 4881 "fgl.yacc"
{
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;
case 1000:
#line 4902 "fgl.yacc"
{
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;
case 1001:
#line 4907 "fgl.yacc"
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
case 1002:
#line 4920 "fgl.yacc"
{
		print_niy("GUI PROMPT");
	}
    break;
case 1003:
#line 4925 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1004:
#line 4926 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 1005:
#line 4930 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1009:
#line 4936 "fgl.yacc"
{
	print_onkey_1(yyvsp[0].str);
}
    break;
case 1010:
#line 4938 "fgl.yacc"
{
	print_onkey_2_prompt();
}
    break;
case 1012:
#line 4953 "fgl.yacc"
{
		start_bind('i',0);
		}
    break;
case 1013:
#line 4957 "fgl.yacc"
{
		print_put();
	}
    break;
case 1014:
#line 4963 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1015:
#line 4964 "fgl.yacc"
{ strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1016:
#line 4967 "fgl.yacc"
{push_gen(PUTVAL,yyvsp[0].str);}
    break;
case 1017:
#line 4968 "fgl.yacc"
{push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1020:
#line 4984 "fgl.yacc"
{
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;
case 1021:
#line 4989 "fgl.yacc"
{
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;
case 1022:
#line 4994 "fgl.yacc"
{
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;
case 1023:
#line 4999 "fgl.yacc"
{
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;
case 1029:
#line 5018 "fgl.yacc"
{ 
}
    break;
case 1030:
#line 5021 "fgl.yacc"
{
}
    break;
case 1031:
#line 5024 "fgl.yacc"
{
}
    break;
case 1032:
#line 5027 "fgl.yacc"
{
addmap("Output to report",yyvsp[-8].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-8].str,yyvsp[-2].str); 
}
    break;
case 1033:
#line 5034 "fgl.yacc"
{
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;
case 1034:
#line 5040 "fgl.yacc"
{ sprintf(yyval.str,yyvsp[0].str); }
    break;
case 1035:
#line 5042 "fgl.yacc"
{
	print_format_every_row();
}
    break;
case 1039:
#line 5053 "fgl.yacc"
{ push_report_block("FIRST",'P');}
    break;
case 1040:
#line 5054 "fgl.yacc"
{print_rep_ret(0);}
    break;
case 1041:
#line 5056 "fgl.yacc"
{ push_report_block("TRAILER",'T');}
    break;
case 1042:
#line 5057 "fgl.yacc"
{print_rep_ret(0);}
    break;
case 1043:
#line 5059 "fgl.yacc"
{ push_report_block("HEADER",'p');}
    break;
case 1044:
#line 5060 "fgl.yacc"
{print_rep_ret(0);}
    break;
case 1045:
#line 5062 "fgl.yacc"
{ push_report_block("EVERY",'E');}
    break;
case 1046:
#line 5063 "fgl.yacc"
{print_rep_ret(0);}
    break;
case 1047:
#line 5065 "fgl.yacc"
{ push_report_block("LAST",'L');}
    break;
case 1048:
#line 5066 "fgl.yacc"
{print_rep_ret(0);}
    break;
case 1049:
#line 5067 "fgl.yacc"
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
case 1050:
#line 5081 "fgl.yacc"
{print_rep_ret(0);}
    break;
case 1051:
#line 5083 "fgl.yacc"
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
case 1052:
#line 5099 "fgl.yacc"
{print_rep_ret(0);}
    break;
case 1059:
#line 5109 "fgl.yacc"
{start_state("skip",1);}
    break;
case 1060:
#line 5109 "fgl.yacc"
{
	print_need_lines();
	start_state("skip",0);
}
    break;
case 1061:
#line 5115 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1062:
#line 5115 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 1063:
#line 5118 "fgl.yacc"
{start_state("KWLINE",1);}
    break;
case 1064:
#line 5118 "fgl.yacc"
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
case 1065:
#line 5128 "fgl.yacc"
{ print_skip_top(); }
    break;
case 1066:
#line 5129 "fgl.yacc"
{ print_niy("FONT SIZE"); }
    break;
case 1067:
#line 5130 "fgl.yacc"
{
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;
case 1068:
#line 5137 "fgl.yacc"
{
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;
case 1069:
#line 5149 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1075:
#line 5160 "fgl.yacc"
{
	print_niy("PRINT AT...");
}
    break;
case 1076:
#line 5165 "fgl.yacc"
{
	print_report_print(0,yyvsp[0].str,0);
}
    break;
case 1077:
#line 5169 "fgl.yacc"
{ 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1078:
#line 5174 "fgl.yacc"
{ 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1079:
#line 5180 "fgl.yacc"
{ strcpy(yyval.str,get_default_scaling());}
    break;
case 1080:
#line 5181 "fgl.yacc"
{ strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;
case 1081:
#line 5182 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1082:
#line 5186 "fgl.yacc"
{strcpy(yyval.str,"tiff");}
    break;
case 1083:
#line 5187 "fgl.yacc"
{strcpy(yyval.str,"gif");}
    break;
case 1084:
#line 5188 "fgl.yacc"
{strcpy(yyval.str,"png");}
    break;
case 1085:
#line 5189 "fgl.yacc"
{strcpy(yyval.str,"jpeg");}
    break;
case 1086:
#line 5193 "fgl.yacc"
{
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;
case 1087:
#line 5203 "fgl.yacc"
{
strcpy(yyval.str,"0");
}
    break;
case 1088:
#line 5205 "fgl.yacc"
{
strcpy(yyval.str,"1");
}
    break;
case 1089:
#line 5210 "fgl.yacc"
{
	print_report_print(1,0,yyvsp[0].str);
	}
    break;
case 1090:
#line 5213 "fgl.yacc"
{
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;
case 1091:
#line 5218 "fgl.yacc"
{
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;
case 1092:
#line 5225 "fgl.yacc"
{
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1093:
#line 5232 "fgl.yacc"
{
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1094:
#line 5239 "fgl.yacc"
{
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1095:
#line 5248 "fgl.yacc"
{
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;
case 1096:
#line 5255 "fgl.yacc"
{
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;
case 1097:
#line 5262 "fgl.yacc"
{
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;
case 1098:
#line 5269 "fgl.yacc"
{
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1099:
#line 5276 "fgl.yacc"
{
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;
case 1104:
#line 5289 "fgl.yacc"
{rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;
case 1105:
#line 5290 "fgl.yacc"
{rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;
case 1106:
#line 5291 "fgl.yacc"
{rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;
case 1107:
#line 5292 "fgl.yacc"
{rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;
case 1108:
#line 5293 "fgl.yacc"
{rep_struct.page_length=atoi(yyvsp[0].str);}
    break;
case 1109:
#line 5294 "fgl.yacc"
{ rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;
case 1110:
#line 5295 "fgl.yacc"
{rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1111:
#line 5296 "fgl.yacc"
{rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1112:
#line 5297 "fgl.yacc"
{rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1113:
#line 5298 "fgl.yacc"
{strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;
case 1116:
#line 5304 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;
case 1117:
#line 5305 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;
case 1118:
#line 5306 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;
case 1119:
#line 5307 "fgl.yacc"
{sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;
case 1124:
#line 5316 "fgl.yacc"
{pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;
case 1125:
#line 5317 "fgl.yacc"
{pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;
case 1126:
#line 5318 "fgl.yacc"
{pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;
case 1127:
#line 5319 "fgl.yacc"
{pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;
case 1128:
#line 5320 "fgl.yacc"
{pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;
case 1129:
#line 5321 "fgl.yacc"
{pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;
case 1130:
#line 5322 "fgl.yacc"
{strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;
case 1131:
#line 5323 "fgl.yacc"
{pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;
case 1132:
#line 5325 "fgl.yacc"
{pdf_rep_struct.paper_size=1;}
    break;
case 1133:
#line 5326 "fgl.yacc"
{pdf_rep_struct.paper_size=2;}
    break;
case 1134:
#line 5327 "fgl.yacc"
{pdf_rep_struct.paper_size=3;}
    break;
case 1135:
#line 5328 "fgl.yacc"
{pdf_rep_struct.paper_size=5;}
    break;
case 1136:
#line 5330 "fgl.yacc"
{pdf_rep_struct.paper_size=-1;}
    break;
case 1137:
#line 5331 "fgl.yacc"
{pdf_rep_struct.paper_size=-2;}
    break;
case 1138:
#line 5332 "fgl.yacc"
{pdf_rep_struct.paper_size=-3;}
    break;
case 1139:
#line 5333 "fgl.yacc"
{pdf_rep_struct.paper_size=-5;}
    break;
case 1143:
#line 5338 "fgl.yacc"
{pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1144:
#line 5339 "fgl.yacc"
{pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;
case 1148:
#line 5346 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;
case 1149:
#line 5353 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
}
    break;
case 1150:
#line 5359 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;
case 1151:
#line 5369 "fgl.yacc"
{
rep_type=REP_TYPE_NORMAL;
clr_variable(); lastlineno=yylineno; init_report_structure(&rep_struct);
}
    break;
case 1152:
#line 5374 "fgl.yacc"
{
inc_report_cnt();
sprintf(curr_func,"%s",yyvsp[-1].str);
addmap("Define Report",curr_func,"MODULE",yylineno,infilename);
set_curr_rep_name(yyvsp[-1].str);
print_report_1(yyvsp[-1].str);
push_blockcommand("REPORT");
}
    break;
case 1153:
#line 5383 "fgl.yacc"
{
lastlineno=yylineno;
}
    break;
case 1154:
#line 5388 "fgl.yacc"
{

print_report_2(0,yyvsp[0].str);
rordcnt=atoi(yyvsp[0].str);
}
    break;
case 1155:
#line 5394 "fgl.yacc"
{
print_report_ctrl();
}
    break;
case 1156:
#line 5398 "fgl.yacc"
{
pop_blockcommand("REPORT");
print_report_end() ;
}
    break;
case 1157:
#line 5406 "fgl.yacc"
{ strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;
case 1158:
#line 5409 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;
case 1159:
#line 5418 "fgl.yacc"
{
if (!in_command("REPORT")) {
	yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;
case 1160:
#line 5429 "fgl.yacc"
{sprintf(yyval.str,"\"\"");}
    break;
case 1162:
#line 5436 "fgl.yacc"
{
rep_type=REP_TYPE_PDF;
clr_variable(); lastlineno=yylineno; pdf_init_report_structure(&pdf_rep_struct);
}
    break;
case 1163:
#line 5441 "fgl.yacc"
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
#line 5450 "fgl.yacc"
{
lastlineno=yylineno;
}
    break;
case 1165:
#line 5455 "fgl.yacc"
{
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;
case 1166:
#line 5461 "fgl.yacc"
{
print_report_ctrl();
}
    break;
case 1167:
#line 5464 "fgl.yacc"
{
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;
case 1168:
#line 5470 "fgl.yacc"
{ sprintf(yyval.str,yyvsp[0].str); }
    break;
case 1169:
#line 5474 "fgl.yacc"
{new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;
case 1170:
#line 5478 "fgl.yacc"
{
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;
case 1171:
#line 5482 "fgl.yacc"
{
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;
case 1172:
#line 5486 "fgl.yacc"
{
	print_returning();
   }
    break;
case 1173:
#line 5492 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1174:
#line 5493 "fgl.yacc"
{ sprintf(yyval.str,"rep.right_margin"); }
    break;
case 1175:
#line 5494 "fgl.yacc"
{ sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;
case 1176:
#line 5495 "fgl.yacc"
{ sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;
case 1177:
#line 5500 "fgl.yacc"
{
print_system_run(0,0);
}
    break;
case 1178:
#line 5502 "fgl.yacc"
{
print_system_run(1,yyvsp[0].str);
}
    break;
case 1179:
#line 5505 "fgl.yacc"
{
print_system_run(2,0);
}
    break;
case 1180:
#line 5509 "fgl.yacc"
{
print_system_run(0,0);
}
    break;
case 1181:
#line 5512 "fgl.yacc"
{
print_system_run(0,0);
/* FIXME */
}
    break;
case 1182:
#line 5519 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);
}
    break;
case 1183:
#line 5524 "fgl.yacc"
{sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;
case 1184:
#line 5525 "fgl.yacc"
{sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;
case 1185:
#line 5526 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 1186:
#line 5530 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);

}
    break;
case 1187:
#line 5538 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1188:
#line 5539 "fgl.yacc"
{insql=1;}
    break;
case 1189:
#line 5539 "fgl.yacc"
{insql=0;}
    break;
case 1190:
#line 5540 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1191:
#line 5541 "fgl.yacc"
{insql=1;}
    break;
case 1192:
#line 5541 "fgl.yacc"
{insql=0;}
    break;
case 1193:
#line 5542 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1194:
#line 5545 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1195:
#line 5547 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1202:
#line 5565 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1205:
#line 5576 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1209:
#line 5593 "fgl.yacc"
{sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1215:
#line 5599 "fgl.yacc"
{ 
	print_set_conn(yyvsp[0].str);
}
    break;
case 1216:
#line 5602 "fgl.yacc"
{
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1217:
#line 5605 "fgl.yacc"
{
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1218:
#line 5611 "fgl.yacc"
{strcpy(yyval.str,"\"default\"");}
    break;
case 1220:
#line 5617 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1222:
#line 5628 "fgl.yacc"
{
		print_sleep();
	}
    break;
case 1223:
#line 5643 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1224:
#line 5646 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1225:
#line 5647 "fgl.yacc"
{ 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1226:
#line 5653 "fgl.yacc"
{
pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1228:
#line 5662 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1230:
#line 5667 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1231:
#line 5668 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1233:
#line 5672 "fgl.yacc"
{
sprintf(yyval.str," %s , %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1235:
#line 5681 "fgl.yacc"
{
sprintf(yyval.str," %s = %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1236:
#line 5686 "fgl.yacc"
{push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1237:
#line 5687 "fgl.yacc"
{push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1238:
#line 5690 "fgl.yacc"
{push_gen(UPDVAL,yyvsp[0].str);}
    break;
case 1239:
#line 5691 "fgl.yacc"
{push_gen(UPDVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1243:
#line 5698 "fgl.yacc"
{
		print_sql_commit(0);
		}
    break;
case 1244:
#line 5707 "fgl.yacc"
{ insql=1;start_bind('i',0);}
    break;
case 1245:
#line 5708 "fgl.yacc"
{
sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1246:
#line 5713 "fgl.yacc"
{insql=1;}
    break;
case 1247:
#line 5713 "fgl.yacc"
{
insql=0;
sprintf(yyval.str," %s %s %s %s" ,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1249:
#line 5719 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1250:
#line 5721 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1252:
#line 5728 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1254:
#line 5734 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1257:
#line 5744 "fgl.yacc"
{
      print_fetch_1();
    }
    break;
case 1258:
#line 5748 "fgl.yacc"
{
      print_fetch_2();
    }
    break;
case 1259:
#line 5752 "fgl.yacc"
{
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;
case 1260:
#line 5759 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 1261:
#line 5763 "fgl.yacc"
{sprintf(yyval.str,"%s,%d,1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 1262:
#line 5769 "fgl.yacc"
{
debug("no into\n");
sprintf(yyval.str,"0,0");
}
    break;
case 1263:
#line 5773 "fgl.yacc"
{
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('i',0);
}
    break;
case 1264:
#line 5779 "fgl.yacc"
{
	int ni;
	ni=print_bind('i');
	sprintf(yyval.str,"%d,ibind",ni);
}
    break;
case 1265:
#line 5786 "fgl.yacc"
{
debug("no into\n");
sprintf(yyval.str,"0,0");
}
    break;
case 1266:
#line 5790 "fgl.yacc"
{
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('i',0);
}
    break;
case 1267:
#line 5795 "fgl.yacc"
{
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;
case 1268:
#line 5805 "fgl.yacc"
{
sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;
case 1269:
#line 5808 "fgl.yacc"
{sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;
case 1270:
#line 5810 "fgl.yacc"
{sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;
case 1271:
#line 5812 "fgl.yacc"
{sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;
case 1272:
#line 5814 "fgl.yacc"
{sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;
case 1273:
#line 5816 "fgl.yacc"
{sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;
case 1274:
#line 5818 "fgl.yacc"
{sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;
case 1275:
#line 5824 "fgl.yacc"
{
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;
case 1276:
#line 5834 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1277:
#line 5839 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1279:
#line 5845 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1283:
#line 5854 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1286:
#line 5859 "fgl.yacc"
{
print_sql_commit(-1);
}
    break;
case 1287:
#line 5864 "fgl.yacc"
{
		print_sql_commit(1);
	}
    break;
case 1288:
#line 5871 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1289:
#line 5872 "fgl.yacc"
{
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;
case 1290:
#line 5879 "fgl.yacc"
{
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;
case 1291:
#line 5891 "fgl.yacc"
{insql=1;}
    break;
case 1292:
#line 5891 "fgl.yacc"
{
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1293:
#line 5896 "fgl.yacc"
{lex_printcomment("/*  schema */\n");
	print_exec_sql(yyvsp[0].str);

sprintf(yyval.str,"Schema");
}
    break;
case 1294:
#line 5901 "fgl.yacc"
{lex_printcomment("/*  schema  2*/\n");

	print_exec_sql(yyvsp[0].str);

sprintf(yyval.str,"Schema Element");
}
    break;
case 1296:
#line 5908 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);
 }
    break;
case 1298:
#line 5913 "fgl.yacc"
{
sprintf(yyval.str,"Set Database");
}
    break;
case 1299:
#line 5916 "fgl.yacc"
{

lex_printcomment("/*  delete 1 */\n");

print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"Delete where current...");
}
    break;
case 1300:
#line 5923 "fgl.yacc"
{

lex_printcomment("/*  delete 2 */\n");

print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"Delete where ...");
}
    break;
case 1301:
#line 5930 "fgl.yacc"
{
sprintf(yyval.str,"Fetch");
lex_printcomment("/*  fetch */\n");
}
    break;
case 1302:
#line 5934 "fgl.yacc"
{

lex_printcomment("/*  insert */\n");

print_exec_sql_bound(yyvsp[0].str);


sprintf(yyval.str,"insert");

}
    break;
case 1304:
#line 5945 "fgl.yacc"
{
	print_do_select(yyvsp[0].str);
	sprintf(yyval.str,"select");
}
    break;
case 1305:
#line 5949 "fgl.yacc"
{

print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"update");
}
    break;
case 1306:
#line 5958 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1307:
#line 5961 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1308:
#line 5963 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1309:
#line 5968 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1312:
#line 5975 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1316:
#line 5982 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1317:
#line 5985 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1318:
#line 5987 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1320:
#line 5993 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1322:
#line 5999 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1325:
#line 6010 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1326:
#line 6013 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1327:
#line 6015 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1329:
#line 6021 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1330:
#line 6024 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1332:
#line 6031 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1333:
#line 6037 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1334:
#line 6042 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1337:
#line 6052 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1339:
#line 6058 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1340:
#line 6064 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1341:
#line 6066 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1343:
#line 6072 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1347:
#line 6085 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1348:
#line 6087 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);}
    break;
case 1349:
#line 6093 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1350:
#line 6096 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1352:
#line 6100 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1353:
#line 6102 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1354:
#line 6107 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1355:
#line 6109 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1357:
#line 6112 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1358:
#line 6118 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1359:
#line 6123 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);}
    break;
case 1362:
#line 6133 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1365:
#line 6148 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1366:
#line 6154 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1369:
#line 6164 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1370:
#line 6169 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1372:
#line 6175 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1373:
#line 6179 "fgl.yacc"
{sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;
case 1374:
#line 6180 "fgl.yacc"
{sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1375:
#line 6181 "fgl.yacc"
{sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;
case 1377:
#line 6185 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1379:
#line 6190 "fgl.yacc"
{ sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;
case 1380:
#line 6198 "fgl.yacc"
{
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1381:
#line 6205 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1383:
#line 6209 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1385:
#line 6213 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1388:
#line 6221 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1390:
#line 6227 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1392:
#line 6233 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1394:
#line 6239 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1395:
#line 6244 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1396:
#line 6245 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1397:
#line 6251 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1398:
#line 6253 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1399:
#line 6257 "fgl.yacc"
{strcpy(yyval.str," ALL ");}
    break;
case 1405:
#line 6276 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1408:
#line 6290 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1409:
#line 6292 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1410:
#line 6294 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1411:
#line 6296 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1413:
#line 6303 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1414:
#line 6306 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1416:
#line 6313 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1417:
#line 6315 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1418:
#line 6317 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1419:
#line 6319 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1420:
#line 6321 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1421:
#line 6323 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1430:
#line 6336 "fgl.yacc"
{sprintf(yyval.str,"<=");}
    break;
case 1431:
#line 6337 "fgl.yacc"
{sprintf(yyval.str,">=");}
    break;
case 1436:
#line 6347 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1444:
#line 6367 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1445:
#line 6372 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1448:
#line 6376 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1452:
#line 6381 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1454:
#line 6384 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1456:
#line 6387 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1460:
#line 6392 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1461:
#line 6394 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1462:
#line 6397 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1464:
#line 6403 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1468:
#line 6408 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);}
    break;
case 1472:
#line 6424 "fgl.yacc"
{
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;
case 1473:
#line 6428 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);
addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;
case 1474:
#line 6431 "fgl.yacc"
{ sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;
case 1475:
#line 6432 "fgl.yacc"
{ sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;
case 1478:
#line 6443 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);}
    break;
case 1479:
#line 6447 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1480:
#line 6448 "fgl.yacc"
{sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;
case 1481:
#line 6449 "fgl.yacc"
{sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;
case 1482:
#line 6453 "fgl.yacc"
{ 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1483:
#line 6458 "fgl.yacc"
{
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;
case 1484:
#line 6463 "fgl.yacc"
{
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;
case 1486:
#line 6476 "fgl.yacc"
{sprintf(yyval.str,convstrsql(yyvsp[0].str));}
    break;
case 1490:
#line 6481 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1491:
#line 6483 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1492:
#line 6485 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1493:
#line 6487 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1495:
#line 6492 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1496:
#line 6495 "fgl.yacc"
{sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1497:
#line 6498 "fgl.yacc"
{strcpy(yyval.str," YEAR TO SECOND ");}
    break;
case 1498:
#line 6500 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1499:
#line 6503 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1500:
#line 6505 "fgl.yacc"
{sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1501:
#line 6508 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1502:
#line 6508 "fgl.yacc"
{strcpy(yyval.str,"5");}
    break;
case 1503:
#line 6508 "fgl.yacc"
{strcpy(yyval.str,"8");}
    break;
case 1504:
#line 6508 "fgl.yacc"
{strcpy(yyval.str,"11");}
    break;
case 1505:
#line 6508 "fgl.yacc"
{strcpy(yyval.str,"14");}
    break;
case 1506:
#line 6508 "fgl.yacc"
{strcpy(yyval.str,"17");}
    break;
case 1507:
#line 6508 "fgl.yacc"
{strcpy(yyval.str,"23");}
    break;
case 1508:
#line 6509 "fgl.yacc"
{strcpy(yyval.str,"4");}
    break;
case 1509:
#line 6509 "fgl.yacc"
{strcpy(yyval.str,"7");}
    break;
case 1510:
#line 6509 "fgl.yacc"
{strcpy(yyval.str,"10");}
    break;
case 1511:
#line 6509 "fgl.yacc"
{strcpy(yyval.str,"13");}
    break;
case 1512:
#line 6509 "fgl.yacc"
{strcpy(yyval.str,"16");}
    break;
case 1513:
#line 6509 "fgl.yacc"
{strcpy(yyval.str,"19");}
    break;
case 1514:
#line 6509 "fgl.yacc"
{strcpy(yyval.str,"25");}
    break;
case 1529:
#line 6515 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1530:
#line 6516 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1531:
#line 6520 "fgl.yacc"
{
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;
case 1532:
#line 6529 "fgl.yacc"
{insql=0;chk4var=0;}
    break;
case 1533:
#line 6529 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-5].str,0,0);
addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-7].str);
}
    break;
case 1534:
#line 6534 "fgl.yacc"
{insql=0;chk4var=0;}
    break;
case 1535:
#line 6534 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,2,0); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;
case 1536:
#line 6540 "fgl.yacc"
{insql=0;chk4var=0;}
    break;
case 1537:
#line 6541 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-4].str,0,1); 
addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-6].str);
}
    break;
case 1538:
#line 6546 "fgl.yacc"
{insql=0;chk4var=0;}
    break;
case 1539:
#line 6547 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,0,1); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;
case 1540:
#line 6556 "fgl.yacc"
{strcpy(yyval.str,"0");}
    break;
case 1541:
#line 6557 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 1542:
#line 6558 "fgl.yacc"
{strcpy(yyval.str,"1");}
    break;
case 1546:
#line 6565 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1547:
#line 6566 "fgl.yacc"
{sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1549:
#line 6572 "fgl.yacc"
{ 
		strcpy(yyval.str,print_curr_spec(1,yyvsp[0].str));
	}
    break;
case 1550:
#line 6578 "fgl.yacc"
{
		strcpy(yyval.str,print_curr_spec(2,yyvsp[0].str));
}
    break;
case 1552:
#line 6587 "fgl.yacc"
{
	sprintf(yyval.str,"%s",yyvsp[-1].str);
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}

	}
    break;
case 1553:
#line 6597 "fgl.yacc"
{debug("Got select list...\n");}
    break;
case 1554:
#line 6599 "fgl.yacc"
{
			/* start_bind('i',0,-1); */
            start_bind('i',0);
			lex_printcomment("/* startbind */");
		}
    break;
case 1555:
#line 6605 "fgl.yacc"
{
             char buff[1024];
             sprintf(buff,"%s %s %s %s %s %s", yyvsp[-7].str, yyvsp[-6].str, yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str,yyvsp[0].str);
	    strcpy(yyval.str,print_select_all(buff));

}
    break;
case 1556:
#line 6615 "fgl.yacc"
{
             char buff[1024];

             sprintf(buff,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
             sprintf(yyval.str,"push_char(\"%s\");",buff);
}
    break;
case 1559:
#line 6631 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s %s %s %s %s", yyvsp[-6].str, yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;
case 1560:
#line 6635 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1561:
#line 6636 "fgl.yacc"
{
       lex_printcomment("/* UNION */");
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;
case 1563:
#line 6641 "fgl.yacc"
{
       sprintf(yyval.str,"%s %s %s ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1565:
#line 6649 "fgl.yacc"
{ start_bind('o',0);strcpy(yyval.str,""); }
    break;
case 1566:
#line 6650 "fgl.yacc"
{ strcpy(yyval.str,""); }
    break;
case 1567:
#line 6657 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1568:
#line 6662 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str);}
    break;
case 1569:
#line 6665 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1570:
#line 6666 "fgl.yacc"
{sprintf(yyval.str,"ALL");}
    break;
case 1571:
#line 6667 "fgl.yacc"
{sprintf(yyval.str,"DISTINCT");}
    break;
case 1572:
#line 6668 "fgl.yacc"
{sprintf(yyval.str,"DISTINCT");}
    break;
case 1574:
#line 6673 "fgl.yacc"
{ sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1576:
#line 6677 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1578:
#line 6687 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1579:
#line 6689 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1580:
#line 6691 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1581:
#line 6693 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1582:
#line 6695 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1588:
#line 6701 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;
case 1589:
#line 6703 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);}
    break;
case 1590:
#line 6705 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1591:
#line 6707 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1592:
#line 6709 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1593:
#line 6711 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1594:
#line 6713 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1595:
#line 6715 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1596:
#line 6717 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1597:
#line 6718 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;
case 1602:
#line 6728 "fgl.yacc"
{

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;
case 1603:
#line 6736 "fgl.yacc"
{
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;
case 1604:
#line 6741 "fgl.yacc"
{strcpy(yyval.str,"\"|\"");}
    break;
case 1605:
#line 6741 "fgl.yacc"
{
strcpy(yyval.str,yyvsp[0].str);
}
    break;
case 1607:
#line 6745 "fgl.yacc"
{
if ((scan_variable(yyvsp[0].str)&15)!=0) {yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;
case 1608:
#line 6750 "fgl.yacc"
{sprintf(yyval.str,"0");}
    break;
case 1609:
#line 6750 "fgl.yacc"
{
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;
case 1611:
#line 6754 "fgl.yacc"
{
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;
case 1612:
#line 6758 "fgl.yacc"
{
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;
case 1615:
#line 6767 "fgl.yacc"
{strcpy(yyval.str,"");}
    break;
case 1616:
#line 6767 "fgl.yacc"
{
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;
case 1621:
#line 6786 "fgl.yacc"
{ sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;
case 1622:
#line 6787 "fgl.yacc"
{ sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;
case 1625:
#line 6795 "fgl.yacc"
{
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;
case 1626:
#line 6801 "fgl.yacc"
{
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;
case 1629:
#line 6820 "fgl.yacc"
{sprintf(yyval.str,"UNITS YEAR");}
    break;
case 1630:
#line 6821 "fgl.yacc"
{sprintf(yyval.str,"UNITS MONTH"); }
    break;
case 1631:
#line 6822 "fgl.yacc"
{sprintf(yyval.str,"UNITS DAY);"); }
    break;
case 1632:
#line 6823 "fgl.yacc"
{sprintf(yyval.str,"UNITS HOUR);"); }
    break;
case 1633:
#line 6824 "fgl.yacc"
{sprintf(yyval.str,"UNITS MINUTE);"); }
    break;
case 1634:
#line 6825 "fgl.yacc"
{sprintf(yyval.str,"UNITS SECOND);"); }
    break;
case 1635:
#line 6911 "fgl.yacc"
{
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
	fflush(stdout);
}
    break;
case 1636:
#line 6923 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);}
    break;
case 1640:
#line 6929 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1641:
#line 6930 "fgl.yacc"
{sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1645:
#line 6940 "fgl.yacc"
{
	if (scan_variable(yyvsp[0].str)!=-1&&(!system_var(yyvsp[0].str)))
	{
		int z = 0,a = 0;
		a=get_bind_cnt('i');
		/* z=add_bind('i',$<str>1,scan_variable($<str>1)); //int add_bind (char i, char *var); */
		z=add_bind('i',yyvsp[0].str);

		z-=a;
		strcpy(yyval.str,"");

		for (a=0;a<z;a++)
		{
			if (a>0) {strcat(yyval.str,",");}
			strcat(yyval.str,"?");
		}

	}
	fflush(stdout);
}
    break;
case 1646:
#line 6961 "fgl.yacc"
{
char r1[256];
char r2[256];
char buff[256];
char kp[40000];
char *ptr1;
char *ptr2;
int v1;
int v2 = 0;
int aa;
int z = 0,a = 0;

 
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
case 1647:
#line 7046 "fgl.yacc"
{set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;
case 1648:
#line 7048 "fgl.yacc"
{set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;
case 1649:
#line 7050 "fgl.yacc"
{set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;
case 1650:
#line 7051 "fgl.yacc"
{
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;
case 1651:
#line 7056 "fgl.yacc"
{
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;
case 1652:
#line 7061 "fgl.yacc"
{set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;
case 1653:
#line 7063 "fgl.yacc"
{set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;
case 1654:
#line 7065 "fgl.yacc"
{set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;
case 1655:
#line 7067 "fgl.yacc"
{set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;
case 1656:
#line 7070 "fgl.yacc"
{
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;
case 1657:
#line 7074 "fgl.yacc"
{
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;
case 1658:
#line 7079 "fgl.yacc"
{
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;
case 1659:
#line 7084 "fgl.yacc"
{ set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;
case 1660:
#line 7088 "fgl.yacc"
{
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;
case 1662:
#line 7098 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 1664:
#line 7113 "fgl.yacc"
{
print_while_1();
push_blockcommand("WHILE");
}
    break;
case 1665:
#line 7116 "fgl.yacc"
{
print_while_2();
}
    break;
case 1666:
#line 7120 "fgl.yacc"
{
print_while_3();
pop_blockcommand("WHILE");
}
    break;
case 1669:
#line 7139 "fgl.yacc"
{
strcpy(yyval.str,"0");
}
    break;
case 1670:
#line 7142 "fgl.yacc"
{
strcpy(yyval.str,"1"); 
}
    break;
case 1671:
#line 7148 "fgl.yacc"
{ 
print_clr_window("\"screen\"");
}
    break;
case 1672:
#line 7151 "fgl.yacc"
{ print_clr_window(yyvsp[0].str); }
    break;
case 1673:
#line 7152 "fgl.yacc"
{ print_clr_window(yyvsp[0].str); }
    break;
case 1674:
#line 7153 "fgl.yacc"
{
	print_clr_form(0,0,yyvsp[0].str);
}
    break;
case 1675:
#line 7156 "fgl.yacc"
{
	print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1676:
#line 7159 "fgl.yacc"
{
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;
case 1677:
#line 7164 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;
case 1678:
#line 7165 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;
case 1679:
#line 7169 "fgl.yacc"
{
	print_current_window("\"screen\"");
}
    break;
case 1680:
#line 7173 "fgl.yacc"
{
	print_current_window(yyvsp[0].str);
}
    break;
case 1681:
#line 7177 "fgl.yacc"
{
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;
case 1682:
#line 7181 "fgl.yacc"
{
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;
case 1683:
#line 7186 "fgl.yacc"
{
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;
case 1684:
#line 7190 "fgl.yacc"
{
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;
case 1685:
#line 7195 "fgl.yacc"
{

print_def_mn_file();

}
    break;
case 1687:
#line 7203 "fgl.yacc"
{addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;
case 1689:
#line 7209 "fgl.yacc"
{
	print_hide_window(yyvsp[0].str);
}
    break;
case 1690:
#line 7215 "fgl.yacc"
{
print_move_window(yyvsp[-4].str,0);
}
    break;
case 1691:
#line 7219 "fgl.yacc"
{
print_move_window(yyvsp[-4].str,1);
}
    break;
case 1696:
#line 7237 "fgl.yacc"
{
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;
case 1697:
#line 7244 "fgl.yacc"
{
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;
case 1698:
#line 7253 "fgl.yacc"
{print_cmd_start();}
    break;
case 1699:
#line 7253 "fgl.yacc"
{print_cmd_end();}
    break;
}

#line 705 "/usr/share/bison/bison.simple"


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
#line 7345 "fgl.yacc"

/* programmer routines */
/*
# include "lex.yy.c"
# include "lexify.c"
*/

void
set_clobber(char *c)
{
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

void
set_str(char *s)
{
	strcpy(yylval.str,s);
}

/* ====================== last.reqd =============================== */


/* ===================== EOF (fgl.yacc) =========================== */


