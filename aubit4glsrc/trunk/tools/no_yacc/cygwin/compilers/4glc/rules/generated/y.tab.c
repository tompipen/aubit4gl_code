
/*  A Bison parser, made from fgl.yacc
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	NAME	257
#define	UMINUS	258
#define	COMMA	1541
#define	OR	1581
#define	AND	1536
#define	USING	1470
#define	MATCHES	1350
#define	POWER	1457
#define	LESS_THAN	1453
#define	GREATER_THAN	1368
#define	EQUAL	1531
#define	GREATER_THAN_EQ	1268
#define	LESS_THAN_EQ	1325
#define	NOT_EQUAL	1399
#define	MINUS	1554
#define	PLUS	1567
#define	DIVIDE	1485
#define	MULTIPLY	1458
#define	MOD	1555
#define	COMMAND	1332
#define	NUMBER_VALUE	259
#define	CHAR_VALUE	260
#define	INT_VALUE	261
#define	NAMED_GEN	262
#define	CLINE	263
#define	SQLLINE	264
#define	KW_CSTART	265
#define	KW_CEND	266
#define	LOCAL_FUNCTION	1000
#define	EVERY_ROW	1001
#define	DOUBLE_PRECISION	1002
#define	COUNT_MULTIPLY	1003
#define	NEWFORMATSHARED	1004
#define	WAIT_FOR_KEY	1005
#define	AT_TERMINATION_CALL	1006
#define	TO_MAIN_CAPTION	1007
#define	CLEARSTAT	1008
#define	TO_MENUITEM	1009
#define	ID_TO_INT	1010
#define	TO_STATUSBOX	1011
#define	ASCII_HEIGHT_ALL	1012
#define	ASCII_WIDTH_ALL	1013
#define	IMPORT_DATATYPE	1014
#define	UP_BY	1015
#define	PAGE_TRAILER_SIZE	1016
#define	PAGE_HEADER_SIZE	1017
#define	FIRST_PAGE_HEADER_SIZE	1018
#define	BYTES_USE_AS_IMAGE	1019
#define	BYTES_USE_AS_ASCII	1020
#define	DOWN_BY	1021
#define	CLOSE_STATUSBOX	1022
#define	ADD_CONSTRAINT	1023
#define	DROP_CONSTRAINT	1024
#define	MODIFY_NEXT_SIZE	1025
#define	LOCK_MODE_PAGE	1026
#define	LOCK_MODE_ROW	1027
#define	TO_PIPE	1028
#define	TO_PRINTER	1029
#define	STATUSBOX	1030
#define	CONNECT_TO	1031
#define	FORMHANDLER_INPUT	1032
#define	UNITS_YEAR	1033
#define	UNITS_MONTH	1034
#define	UNITS_DAY	1035
#define	UNITS_HOUR	1036
#define	UNITS_MINUTE	1037
#define	UNITS_SECOND	1038
#define	NO_NEW_LINES	1039
#define	FIELDTOWIDGET	1040
#define	WITH_HOLD	1041
#define	SHOW_MENU	1042
#define	CWIS	1043
#define	CREATE_IDX	1044
#define	FORM_IS_COMPILED	1045
#define	PDF_REPORT	1046
#define	IMPORT_FUNCTION	1047
#define	PROMPT_MANY	1048
#define	POINTS	1049
#define	MM	1050
#define	INCHES	1051
#define	PREPEND	1052
#define	MEMBER_OF	1053
#define	MEMBER_FUNCTION	1054
#define	APPEND	1055
#define	TEMPLATE	1056
#define	END_TEMPLATE	1057
#define	SQLSICS	1058
#define	CREATE_SCHEMA	1059
#define	SQLSIRR	1060
#define	UPDATESTATS_T	1061
#define	SQLSICR	1062
#define	WHENEVER_SQLSUCCESS	1063
#define	WHENEVER_SQLWARNING	1064
#define	START_EXTERN	1065
#define	WHENEVER_ANY_ERROR	1066
#define	WHENEVER_NOT_FOUND	1067
#define	CONTINUE_CONSTRUCT	1068
#define	FOUNCONSTR	1069
#define	SQLSIDR	1070
#define	WHENEVER_SQLERROR	1071
#define	CREATE_TEMP_TABLE	1072
#define	CURRENT_WINDOW_IS	1073
#define	FIRST_PAGE_HEADER	1074
#define	ORDER_EXTERNAL_BY	1075
#define	SCROLL_CURSOR_FOR	1076
#define	SCROLL_CURSOR	1077
#define	SQL_INTERRUPT_OFF	1078
#define	STOP_ALL_EXTERNAL	1079
#define	WITH_CHECK_OPTION	1080
#define	WITH_GRANT_OPTION	1081
#define	SQLSLMNW	1082
#define	ADDCONSTUNIQ	1083
#define	CONTINUE_DISPLAY	1084
#define	CONTINUE_FOREACH	1085
#define	OUTPUT_TO_REPORT	1086
#define	SQL_INTERRUPT_ON	1087
#define	WHENEVER_SUCCESS	1088
#define	WHENEVER_WARNING	1089
#define	WHERE_CURRENT_OF	1090
#define	WITHOUT_DEFAULTS	1091
#define	FOCONSTR	1092
#define	SCALED_BY	1093
#define	CONTINUE_PROMPT	1094
#define	PDF_FUNCTION	1095
#define	DEFER_INTERRUPT	1096
#define	DISPLAY_BY_NAME	1097
#define	NOT_NULL_UNIQUE	1098
#define	SKIP_TO_TOP	1099
#define	TOP_OF_PAGE	1100
#define	SKIP_TO	1101
#define	SKIP_BY	1102
#define	WITHOUT_WAITING	1103
#define	BEFCONSTRUCT	1104
#define	SQLSLMW	1105
#define	WHENEVER_ERROR_CONTINUE	1106
#define	WHENEVER_ERROR	1107
#define	AFTCONSTRUCT	1108
#define	ALL_PRIVILEGES	1109
#define	CLOSE_DATABASE	1110
#define	CONTINUE_INPUT	1111
#define	CONTINUE_WHILE	1112
#define	CREATE_SYNONYM	1113
#define	DROP_TABLE	1114
#define	EXIT_CONSTRUCT	1115
#define	INEXCLUSIVE	1116
#define	REPORT_TO_PRINTER	1117
#define	REPORT_TO_PIPE	1118
#define	SET_SESSION_TO	1119
#define	UPDATESTATS	1120
#define	WITHOUT_HEAD	1121
#define	CLEARSCR	1122
#define	WITH_B_LOG	1123
#define	AUTHORIZATION	1124
#define	BOTTOM_MARGIN	1125
#define	CLOSE_SESSION	1126
#define	CONTINUE_CASE	1127
#define	CONTINUE_MENU	1128
#define	DISPLAY_ARRAY	1129
#define	END_CONSTRUCT	1130
#define	FIELD_TOUCHED	1131
#define	FINISH_REPORT	1132
#define	INFACC	1133
#define	INPUT_NO_WRAP	1134
#define	LOCKMODEPAGE	1135
#define	SETPMOFF	1136
#define	UNCONSTRAINED	1137
#define	PAGE_TRAILER	1138
#define	SETPMON	1139
#define	BEFGROUP	1140
#define	CLOSE_WINDOW	1141
#define	COMMENT_LINE	1142
#define	CONTINUE_FOR	1143
#define	CREATE_DB	1144
#define	CREATE_TABLE	1145
#define	DEFAULT_NULL	1146
#define	DELETE_USING	1147
#define	DISPLAY_FORM	1148
#define	END_FUNCTION	1149
#define	EXIT_DISPLAY	1150
#define	EXIT_FOREACH	1151
#define	EXIT_PROGRAM	1152
#define	INFCOLS	1153
#define	LOCKMODEROW	1154
#define	ON_EVERY_ROW	1155
#define	OPEN_SESSION	1156
#define	RIGHT_MARGIN	1157
#define	SELECT_USING	1158
#define	START_REPORT	1159
#define	UNLOCK_TABLE	1160
#define	UPDATE_USING	1161
#define	ACL_BUILTIN	1162
#define	AFTGROUP	1163
#define	INFIDX	1164
#define	INFSTAT	1165
#define	LEFT_MARGIN	1166
#define	PAGE_HEADER	1167
#define	ROLLBACK_W	1168
#define	SET_SESSION	1169
#define	SQLSEOFF	1170
#define	WITH_A_LOG	1171
#define	ALTER_TABLE	1172
#define	BEFDISP	1173
#define	BEFORE_MENU	1174
#define	CREATE_VIEW	1175
#define	DEFINE_TYPE	1176
#define	DELETE_FROM	1177
#define	END_DISPLAY	1178
#define	END_REPORT	1179
#define	END_FOREACH	1180
#define	END_FOR	1181
#define	END_GLOBALS	1182
#define	EXIT_PROMPT	1183
#define	EXTENT_SIZE	1184
#define	FOREIGN_KEY	1185
#define	HIDE_OPTION	1186
#define	HIDE_WINDOW	1187
#define	INSERT_INTO	1188
#define	IS_NOT_NULL	1189
#define	MOVE_WINDOW	1190
#define	NEXT_OPTION	1191
#define	NOT_MATCHES	1192
#define	ON_LAST_ROW	1193
#define	OPEN_WINDOW	1194
#define	OPEN_STATUSBOX	1195
#define	PAGE_LENGTH	1196
#define	PAGE_WIDTH	1197
#define	PRIMARY_KEY	1198
#define	PROMPT_LINE	1199
#define	RECORD_LIKE	1200
#define	ROLLFORWARD	1201
#define	SETBL	1202
#define	SHOW_OPTION	1203
#define	SHOW_WINDOW	1204
#define	SQLSEON	1205
#define	TO_DATABASE	1206
#define	USE_SESSION	1207
#define	WITH_NO_LOG	1208
#define	AFTDISP	1209
#define	BEFFIELD	1210
#define	INSHARE	1211
#define	UNLOCKTAB	1212
#define	AFTFIELD	1213
#define	ATTRIBUTES	1214
#define	BEFINP	1215
#define	BEGIN_WORK	1216
#define	CLEARWIN	1217
#define	CLOSE_FORM	1218
#define	DEFER_QUIT	1219
#define	DESCENDING	1220
#define	DROP_INDEX	1221
#define	END_PROMPT	1222
#define	END_RECORD	1223
#define	ERROR_LINE	1224
#define	EXIT_INPUT	1225
#define	EXIT_WHILE	1226
#define	FOR_UPDATE_OF	1227
#define	FOR_UPDATE	1228
#define	GET_FLDBUF	1229
#define	INITIALIZE	1230
#define	INPUT_WRAP	1231
#define	LOCK_TABLE	1232
#define	MSG_LINE	1233
#define	NOT_EXISTS	1234
#define	ON_ANY_KEY	1235
#define	REFERENCES	1236
#define	RENCOL	1237
#define	SET_CURSOR	1238
#define	SMALLFLOAT	1239
#define	SQLSUCCESS	1240
#define	TOP_MARGIN	1241
#define	WITH_ARRAY	1242
#define	ACCEPTKEY	1243
#define	ACCEPT	1244
#define	AFTINP	1245
#define	CLEARFORM	1246
#define	COMMIT_W	1247
#define	NEXTPAGE	1248
#define	PREVPAGE	1249
#define	CTRL_KEY	1250
#define	INFTABS	1251
#define	NEXTFIELD	1252
#define	NEXTFORM	1253
#define	RENTAB	1254
#define	ASCENDING	1255
#define	ASSOCIATE	1256
#define	CHARACTER	1257
#define	CONSTRUCT	1258
#define	DELIMITER	1259
#define	DOWNSHIFT	1260
#define	DROP_VIEW	1261
#define	END_INPUT	1262
#define	END_WHILE	1263
#define	EXCLUSIVE	1264
#define	EXIT_CASE	1265
#define	EXIT_MENU	1266
#define	FORM_LINE	1267
#define	INTERRUPT	1269
#define	INTO_TEMP	1270
#define	INVISIBLE	1271
#define	IN_MEMORY	1272
#define	LINKED_TO	1273
#define	LOAD_FROM	1274
#define	LOCKTAB	1275
#define	MENU_LINE	1276
#define	OPEN_FORM	1277
#define	OTHERWISE	1278
#define	PRECISION	1279
#define	PROCEDURE	1280
#define	REPORT_TO	1281
#define	RETURNING	1282
#define	UNDERLINE	1283
#define	UNLOAD_TO	1284
#define	BEFROW	1285
#define	UNLOAD_T	1286
#define	VARIABLE	1287
#define	ABSOLUTE	1288
#define	AFTROW	1289
#define	BUFFERED	1290
#define	CONSTANT	1291
#define	CONST	1292
#define	CONTINUE	1293
#define	DATABASE	1294
#define	DATETIME	1295
#define	DEFAULTS	1296
#define	DISTINCT	1297
#define	END_CASE	1298
#define	END_MAIN	1299
#define	END_MENU	1300
#define	END_TYPE	1301
#define	EXIT_FOR	1302
#define	EXTERNAL	1303
#define	FRACTION	1304
#define	FUNCTION	1305
#define	GROUP_BY	1306
#define	INTERVAL	1307
#define	KWMESSAGE	1308
#define	NOT_LIKE	1309
#define	NOT_NULL	1310
#define	PASSWORD	1311
#define	PREVIOUS	1312
#define	READONLY	1313
#define	REGISTER	1314
#define	RELATIVE	1315
#define	RESOURCE	1316
#define	SMALLINT	1317
#define	VALIDATE	1318
#define	WHENEVER	1319
#define	WITH_LOG	1320
#define	WORDWRAP	1321
#define	BY_NAME	1322
#define	IN_FILE	1323
#define	IS_NULL	1324
#define	AVERAGE	1326
#define	BETWEEN	1327
#define	CAPTION	1328
#define	CLIPPED	1329
#define	CLOSE_BRACKET	1330
#define	COLUMNS	1331
#define	COMMENT	1333
#define	CONNECT	1334
#define	CURRENT	1335
#define	DBYNAME	1336
#define	DECIMAL	1337
#define	DECLARE	1338
#define	DEFAULT	1339
#define	DISPLAY	1340
#define	ENDCODE	1341
#define	EXECUTE	1342
#define	FOREACH	1343
#define	FOREIGN	1344
#define	GLOBALS	1345
#define	INFIELD	1346
#define	INTEGER	1347
#define	KWWINDOW	1348
#define	MAGENTA	1349
#define	NUMERIC	1351
#define	OPTIONS	1352
#define	PERCENT	1353
#define	PREPARE	1354
#define	PROGRAM	1355
#define	RECOVER	1356
#define	REVERSE	1357
#define	SECTION	1358
#define	SESSION	1359
#define	SYNONYM	1360
#define	THRU	1361
#define	TRAILER	1362
#define	UPSHIFT	1363
#define	VARCHAR	1364
#define	WAITING	1365
#define	CLOSE_SHEV	1366
#define	CLOSE_SQUARE	1367
#define	KW_FALSE	1369
#define	NOT_IN	1370
#define	ONKEY	1371
#define	OPEN_BRACKET	1372
#define	BORDER	1373
#define	BOTTOM	1374
#define	COLUMN	1375
#define	COMMIT	1376
#define	CREATE	1377
#define	CURSOR	1378
#define	DEFINE	1379
#define	DELETE	1380
#define	DOUBLE	1381
#define	END_IF	1382
#define	ESCAPE	1383
#define	EXISTS	1384
#define	EXTEND	1385
#define	EXTENT	1386
#define	FINISH	1387
#define	FORMAT	1388
#define	HAVING	1389
#define	HEADER	1390
#define	INSERT	1391
#define	LOCATE	1392
#define	MARGIN	1393
#define	MEMORY	1394
#define	MINUTE	1395
#define	MODIFY	1396
#define	NORMAL	1397
#define	EQUAL_EQUAL	1398
#define	OPEN_SHEV	1400
#define	OPEN_SQUARE	1401
#define	OPTION	1402
#define	OUTPUT	1403
#define	PROMPT	1404
#define	PUBLIC	1405
#define	RECORD	1406
#define	REPORT	1407
#define	RETURN	1408
#define	REVOKE	1409
#define	SCHEMA	1410
#define	SCROLL	1411
#define	SECOND	1412
#define	SELECT	1413
#define	SERIAL	1414
#define	SETL	1415
#define	SHARED	1416
#define	SPACES	1417
#define	UNIQUE	1418
#define	UNLOCK	1419
#define	UPDATE	1420
#define	VALUES	1421
#define	YELLOW	1422
#define	AFTER	1423
#define	KWLINE	1424
#define	KW_NULL	1425
#define	KW_TRUE	1426
#define	SINGLE_KEY	1427
#define	ALTER	1428
#define	ARRAY	1429
#define	ASCII	1430
#define	AUDIT	1431
#define	BLACK	1432
#define	BLINK	1433
#define	CHECK	1434
#define	CLEAR	1435
#define	CLOSE	1436
#define	CODE_C	1437
#define	COUNT	1438
#define	DEFER	1439
#define	ERROR	1440
#define	EVERY	1441
#define	FETCH	1442
#define	FIRST	1443
#define	FLOAT	1444
#define	FLUSH	1445
#define	FOUND	1446
#define	GRANT	1447
#define	GREEN	1448
#define	GROUP	1449
#define	INDEX	1450
#define	KWFORM	1451
#define	LABEL	1452
#define	LOCAL	1454
#define	MONEY	1455
#define	MONTH	1456
#define	ORDER	1459
#define	OUTER	1460
#define	PAUSE	1461
#define	PRINT_IMAGE	1462
#define	PRINT_FILE	1463
#define	PRINT	1464
#define	RIGHT	1465
#define	SEMICOLON	1466
#define	SLEEP	1467
#define	TUPLE	1468
#define	UNION	1469
#define	WHERE	1471
#define	WHILE	1472
#define	WHITE	1473
#define	CCODE	1474
#define	ANSI	1475
#define	BLUE	1476
#define	BOLD	1477
#define	BYTE	1478
#define	FCALL	1479
#define	CASE	1480
#define	CHAR	1481
#define	CYAN	1482
#define	DATE	1483
#define	DESC	1484
#define	DOWN	1486
#define	TAB	1487
#define	DROP	1488
#define	ELSE	1489
#define	EXEC	1490
#define	EXIT	1491
#define	FREE	1492
#define	FROM	1493
#define	GOTO	1494
#define	HELP_FILE	1495
#define	LANG_FILE	1496
#define	HELP	1497
#define	HIDE	1498
#define	HOUR	1499
#define	INTO	1500
#define	LAST	1501
#define	LEFT	1502
#define	LIKE	1503
#define	MAIN	1504
#define	MENU	1505
#define	MODE	1506
#define	MOVE	1507
#define	NEED	1508
#define	NEXT	1509
#define	NOCR	1510
#define	OPEN	1511
#define	QUIT	1512
#define	REAL	1513
#define	ROWS	1514
#define	SHOW	1515
#define	SIZE	1516
#define	SKIP	1517
#define	SOME	1518
#define	STEP	1519
#define	STOP	1520
#define	TEMP	1521
#define	TEXT	1522
#define	THEN	1523
#define	USER	1524
#define	VIEW	1525
#define	WAIT	1526
#define	WHEN	1527
#define	WITH	1528
#define	WORK	1529
#define	YEAR	1530
#define	KW_IS	1532
#define	XSET	1533
#define	ADD	1534
#define	ALL	1535
#define	ANY	1537
#define	ASC	1538
#define	AVG	1539
#define	COLON	1540
#define	DAY	1542
#define	DBA	1543
#define	DEC	1544
#define	DIM	1545
#define	FKEY	1546
#define	FOR	1547
#define	KEY	1548
#define	KWNO	1549
#define	LET	1550
#define	LOG	1551
#define	XMAX	1552
#define	XMIN	1553
#define	NOT	1556
#define	PAD	1557
#define	PUT	1558
#define	RED	1559
#define	ROW	1560
#define	RUN	1561
#define	SQL	1562
#define	SUM	1563
#define	TOP	1564
#define	USE	1565
#define	ATSIGN	1566
#define	AS_TIFF	1568
#define	AS_GIF	1569
#define	AS_PNG	1570
#define	AS_JPEG	1571
#define	AS	1572
#define	AT	1573
#define	BY	1574
#define	DOT	1575
#define	GO	1576
#define	IF	1577
#define	IN	1578
#define	OF	1579
#define	ON	1580
#define	TO	1582
#define	UP	1583
#define	FONT_NAME	1584
#define	FONT_SIZE	1585
#define	PAPER_SIZE_IS_LETTER	1586
#define	PAPER_SIZE_IS_LEGAL	1587
#define	PAPER_SIZE_IS_A5	1588
#define	PAPER_SIZE_IS_A4	1589
#define	PAPER_SIZE_IS_LETTER_L	1590
#define	PAPER_SIZE_IS_LEGAL_L	1591
#define	PAPER_SIZE_IS_A5_L	1592
#define	PAPER_SIZE_IS_A4_L	1593
#define	FORMHANDLER	1594
#define	END_FORMHANDLER	1595
#define	BEFORE_EVENT	1596
#define	BEFORE_OPEN_FORM	1597
#define	AFTER_EVENT	1598
#define	BEFORE_CLOSE_FORM	1599
#define	BEFORE_ANY	1600
#define	AFTER_ANY	1601
#define	MENUHANDLER	1602
#define	END_MENUHANDLER	1603
#define	BEFORE_SHOW_MENU	1604
#define	DISABLE_PROGRAM	1605
#define	DISABLE_ALL	1606
#define	BUTTONS	1607
#define	CHECK_MENUITEM	1608
#define	DISABLE_FORM	1609
#define	DISABLE_MENUITEMS	1610
#define	DISABLE	1611
#define	ENABLE_FORM	1612
#define	ENABLE_MENUITEMS	1613
#define	ENABLE	1614
#define	KWFIELD	1615
#define	ICON	1616
#define	MESSAGEBOX	1617
#define	TO_DEFAULTS	1618
#define	UNCHECK_MENUITEM	1619
#define	BEFORE	1620
#define	INPUT	1621
#define	END	1622
#define	INT_TO_ID	1623

#line 66 "fgl.yacc"


/*
=====================================================================
                    Constants definitions
=====================================================================
*/


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



#line 171 "fgl.yacc"
typedef union	  {



	char	str[3100];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;

	} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		2910
#define	YYFLAG		-32768
#define	YYNTBASE	637

#define YYTRANSLATE(x) ((unsigned)(x) <= 1623 ? yytranslate[x] : 1413)

static const short yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,    23,    24,
    25,    26,    27,    28,    29,    30,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
   192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
   212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
   222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
   232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
   242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
   252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
   262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
   272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
   282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
   292,   293,   294,   295,   296,   297,   298,    14,   299,   300,
   301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
   311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
   321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
   331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
   341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
   351,   352,   353,   354,    15,   355,   356,   357,   358,   359,
   360,    22,   361,   362,   363,   364,   365,   366,   367,   368,
   369,   370,   371,   372,   373,   374,   375,   376,   377,     9,
   378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
   388,   389,   390,   391,   392,   393,   394,    12,   395,   396,
   397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
   407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
   417,   418,   419,   420,   421,   422,   423,   424,    16,   425,
   426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
   436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
   446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
   456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
   466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
   476,   477,    11,   478,   479,   480,    10,    20,   481,   482,
   483,   484,   485,   486,   487,   488,   489,   490,   491,     8,
   492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
   502,   503,   504,   505,    19,   506,   507,   508,   509,   510,
   511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
   521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
   531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
   541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
    13,   551,   552,   553,   554,     7,   555,   556,   557,   558,
     5,   559,   560,   561,   562,   563,   564,   565,   566,   567,
   568,   569,   570,    17,    21,   571,   572,   573,   574,   575,
   576,   577,   578,   579,   580,   581,    18,   582,   583,   584,
   585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     6,   595,   596,   597,   598,   599,   600,   601,   602,   603,
   604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
   614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
   624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
   634,   635,   636
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,    10,    12,    14,    16,    18,    22,    24,
    28,    32,    34,    37,    39,    41,    43,    45,    47,    49,
    51,    53,    54,    56,    57,    63,    70,    72,    76,    78,
    80,    82,    84,    86,    88,    90,    92,    94,    96,    98,
   100,   102,   104,   106,   108,   109,   111,   112,   118,   120,
   124,   126,   128,   131,   134,   137,   140,   143,   146,   149,
   152,   156,   157,   165,   170,   177,   179,   186,   187,   188,
   198,   199,   200,   201,   210,   211,   212,   223,   224,   225,
   233,   234,   235,   236,   251,   252,   255,   256,   259,   261,
   262,   264,   266,   270,   272,   274,   276,   278,   282,   283,
   290,   291,   297,   299,   302,   304,   307,   309,   310,   311,
   315,   316,   317,   321,   322,   327,   328,   333,   336,   339,
   342,   344,   347,   350,   354,   356,   358,   360,   363,   365,
   367,   370,   372,   374,   375,   376,   382,   390,   399,   400,
   403,   405,   409,   411,   415,   419,   421,   424,   425,   430,
   431,   436,   437,   441,   442,   446,   447,   451,   453,   457,
   459,   463,   465,   467,   469,   471,   473,   475,   477,   479,
   480,   482,   484,   487,   488,   492,   494,   496,   498,   502,
   503,   506,   511,   516,   521,   524,   525,   530,   532,   534,
   536,   539,   541,   543,   547,   548,   550,   551,   559,   560,
   573,   575,   577,   579,   581,   583,   589,   593,   595,   597,
   598,   603,   604,   610,   611,   619,   621,   625,   627,   629,
   630,   633,   635,   637,   639,   644,   649,   656,   658,   661,
   663,   665,   667,   669,   674,   681,   683,   688,   695,   697,
   699,   701,   703,   705,   707,   709,   712,   715,   717,   719,
   724,   726,   728,   729,   733,   737,   738,   741,   743,   745,
   747,   749,   751,   753,   756,   757,   760,   761,   765,   766,
   770,   772,   773,   777,   779,   781,   783,   785,   787,   789,
   792,   794,   795,   797,   798,   804,   806,   808,   810,   815,
   820,   827,   829,   831,   833,   835,   840,   847,   849,   854,
   861,   863,   865,   867,   869,   871,   874,   877,   879,   884,
   885,   893,   894,   907,   908,   913,   914,   920,   922,   926,
   929,   931,   935,   937,   938,   941,   944,   946,   949,   955,
   960,   963,   968,   974,   978,   979,   980,   992,   993,   997,
   999,  1000,  1003,  1005,  1008,  1009,  1013,  1014,  1018,  1019,
  1023,  1028,  1034,  1036,  1039,  1041,  1043,  1045,  1047,  1049,
  1051,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,  1069,
  1071,  1073,  1075,  1077,  1079,  1081,  1084,  1086,  1088,  1090,
  1093,  1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,
  1114,  1116,  1117,  1119,  1121,  1123,  1125,  1129,  1131,  1135,
  1137,  1141,  1143,  1145,  1147,  1150,  1152,  1154,  1158,  1163,
  1168,  1171,  1174,  1177,  1180,  1182,  1184,  1186,  1190,  1192,
  1195,  1198,  1200,  1201,  1205,  1208,  1211,  1213,  1217,  1222,
  1227,  1233,  1239,  1241,  1243,  1246,  1249,  1252,  1255,  1257,
  1260,  1263,  1266,  1269,  1272,  1275,  1278,  1281,  1284,  1287,
  1290,  1293,  1296,  1299,  1300,  1301,  1302,  1309,  1310,  1311,
  1318,  1319,  1320,  1327,  1328,  1329,  1336,  1337,  1338,  1345,
  1346,  1347,  1354,  1356,  1361,  1366,  1371,  1376,  1381,  1383,
  1385,  1387,  1389,  1394,  1399,  1404,  1409,  1412,  1415,  1418,
  1419,  1420,  1421,  1430,  1431,  1432,  1443,  1444,  1446,  1447,
  1449,  1451,  1454,  1455,  1459,  1460,  1464,  1465,  1467,  1469,
  1472,  1473,  1477,  1478,  1482,  1486,  1488,  1493,  1497,  1499,
  1503,  1505,  1509,  1511,  1515,  1517,  1520,  1521,  1525,  1526,
  1530,  1531,  1536,  1537,  1542,  1543,  1548,  1549,  1550,  1562,
  1563,  1566,  1569,  1573,  1575,  1579,  1581,  1583,  1585,  1587,
  1589,  1591,  1595,  1597,  1599,  1604,  1611,  1616,  1620,  1627,
  1631,  1638,  1640,  1642,  1644,  1646,  1648,  1650,  1651,  1654,
  1658,  1660,  1664,  1666,  1671,  1673,  1675,  1676,  1677,  1679,
  1684,  1688,  1695,  1699,  1706,  1708,  1710,  1713,  1715,  1717,
  1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,
  1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,  1757,
  1759,  1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,  1777,
  1779,  1781,  1783,  1785,  1787,  1789,  1791,  1793,  1796,  1799,
  1801,  1805,  1807,  1810,  1813,  1816,  1821,  1824,  1827,  1832,
  1833,  1842,  1843,  1845,  1847,  1849,  1850,  1852,  1855,  1856,
  1858,  1861,  1862,  1864,  1867,  1868,  1870,  1874,  1875,  1878,
  1879,  1887,  1888,  1889,  1893,  1899,  1900,  1903,  1904,  1910,
  1915,  1917,  1921,  1925,  1929,  1930,  1933,  1934,  1936,  1938,
  1941,  1942,  1947,  1948,  1953,  1954,  1958,  1959,  1963,  1964,
  1968,  1969,  1973,  1974,  1978,  1979,  1984,  1985,  1990,  1992,
  1996,  1998,  2000,  2002,  2006,  2008,  2010,  2012,  2016,  2018,
  2022,  2025,  2030,  2032,  2034,  2036,  2037,  2042,  2048,  2055,
  2056,  2067,  2071,  2073,  2075,  2078,  2081,  2082,  2085,  2086,
  2090,  2092,  2093,  2097,  2100,  2101,  2105,  2107,  2111,  2113,
  2117,  2118,  2121,  2123,  2125,  2127,  2129,  2131,  2133,  2135,
  2137,  2139,  2141,  2143,  2145,  2147,  2149,  2151,  2154,  2158,
  2159,  2160,  2168,  2170,  2172,  2175,  2178,  2181,  2185,  2190,
  2191,  2192,  2203,  2204,  2206,  2208,  2211,  2214,  2216,  2218,
  2220,  2222,  2224,  2226,  2228,  2230,  2232,  2234,  2236,  2237,
  2239,  2241,  2243,  2245,  2246,  2247,  2248,  2249,  2263,  2265,
  2266,  2267,  2274,  2278,  2279,  2281,  2284,  2285,  2287,  2289,
  2292,  2294,  2296,  2298,  2300,  2301,  2305,  2308,  2310,  2311,
  2312,  2313,  2328,  2329,  2330,  2338,  2340,  2343,  2344,  2348,
  2349,  2354,  2355,  2361,  2363,  2364,  2368,  2369,  2377,  2378,
  2384,  2386,  2389,  2390,  2392,  2394,  2396,  2397,  2399,  2401,
  2404,  2407,  2410,  2412,  2414,  2416,  2418,  2422,  2424,  2426,
  2429,  2430,  2433,  2435,  2437,  2439,  2441,  2443,  2445,  2447,
  2448,  2452,  2453,  2455,  2457,  2459,  2461,  2464,  2468,  2471,
  2477,  2479,  2481,  2483,  2488,  2493,  2495,  2497,  2499,  2501,
  2504,  2508,  2515,  2517,  2521,  2523,  2525,  2527,  2532,  2540,
  2542,  2544,  2546,  2548,  2551,  2552,  2554,  2556,  2560,  2562,
  2566,  2568,  2572,  2574,  2578,  2580,  2582,  2584,  2586,  2590,
  2592,  2594,  2598,  2600,  2602,  2604,  2608,  2611,  2612,  2614,
  2616,  2621,  2623,  2627,  2629,  2633,  2641,  2642,  2650,  2651,
  2658,  2662,  2664,  2668,  2670,  2673,  2679,  2680,  2688,  2689,
  2692,  2693,  2695,  2701,  2704,  2710,  2711,  2717,  2724,  2729,
  2730,  2732,  2734,  2739,  2740,  2743,  2744,  2750,  2755,  2758,
  2760,  2764,  2767,  2770,  2773,  2776,  2779,  2782,  2784,  2787,
  2790,  2793,  2796,  2799,  2802,  2805,  2808,  2811,  2813,  2815,
  2817,  2819,  2821,  2823,  2829,  2831,  2833,  2836,  2841,  2843,
  2844,  2855,  2861,  2862,  2864,  2865,  2868,  2870,  2873,  2874,
  2878,  2880,  2881,  2886,  2887,  2890,  2892,  2896,  2898,  2900,
  2904,  2909,  2914,  2917,  2919,  2921,  2923,  2924,  2926,  2927,
  2928,  2929,  2940,  2943,  2946,  2949,  2952,  2954,  2957,  2958,
  2962,  2963,  2967,  2968,  2972,  2973,  2977,  2978,  2982,  2983,
  2988,  2989,  2994,  2996,  2998,  3000,  3002,  3004,  3006,  3007,
  3012,  3013,  3015,  3016,  3021,  3023,  3026,  3029,  3032,  3033,
  3035,  3037,  3040,  3043,  3044,  3047,  3051,  3055,  3061,  3062,
  3065,  3070,  3072,  3074,  3076,  3078,  3080,  3081,  3083,  3085,
  3089,  3092,  3098,  3101,  3107,  3113,  3119,  3125,  3131,  3132,
  3135,  3137,  3140,  3143,  3146,  3149,  3152,  3155,  3157,  3160,
  3163,  3166,  3169,  3171,  3174,  3177,  3180,  3183,  3185,  3187,
  3189,  3190,  3193,  3196,  3199,  3202,  3205,  3208,  3211,  3214,
  3217,  3219,  3221,  3223,  3225,  3227,  3229,  3231,  3233,  3236,
  3239,  3242,  3245,  3248,  3250,  3252,  3254,  3255,  3259,  3262,
  3263,  3264,  3265,  3266,  3267,  3282,  3283,  3286,  3289,  3290,
  3292,  3293,  3294,  3295,  3296,  3297,  3312,  3315,  3316,  3317,
  3318,  3329,  3330,  3332,  3336,  3340,  3343,  3348,  3352,  3356,
  3360,  3362,  3364,  3366,  3368,  3370,  3374,  3375,  3376,  3384,
  3385,  3386,  3395,  3396,  3398,  3400,  3404,  3407,  3410,  3412,
  3414,  3418,  3420,  3422,  3425,  3427,  3429,  3431,  3434,  3436,
  3438,  3440,  3442,  3444,  3447,  3454,  3461,  3462,  3464,  3465,
  3467,  3470,  3476,  3477,  3480,  3483,  3485,  3493,  3495,  3501,
  3505,  3507,  3511,  3513,  3517,  3519,  3523,  3525,  3529,  3531,
  3533,  3535,  3537,  3538,  3544,  3545,  3551,  3553,  3554,  3558,
  3560,  3564,  3566,  3570,  3572,  3574,  3575,  3576,  3582,  3585,
  3587,  3588,  3589,  3593,  3594,  3595,  3599,  3601,  3603,  3605,
  3607,  3609,  3612,  3615,  3620,  3624,  3628,  3630,  3634,  3637,
  3639,  3641,  3642,  3644,  3646,  3648,  3650,  3651,  3653,  3657,
  3658,  3662,  3664,  3666,  3668,  3670,  3672,  3674,  3676,  3678,
  3680,  3682,  3684,  3686,  3688,  3696,  3697,  3699,  3701,  3703,
  3705,  3709,  3711,  3713,  3715,  3718,  3719,  3723,  3725,  3729,
  3731,  3735,  3737,  3739,  3746,  3747,  3751,  3753,  3757,  3758,
  3760,  3765,  3771,  3774,  3776,  3778,  3783,  3785,  3789,  3794,
  3799,  3801,  3805,  3807,  3809,  3811,  3814,  3816,  3821,  3822,
  3824,  3825,  3828,  3830,  3832,  3834,  3839,  3843,  3845,  3847,
  3849,  3852,  3854,  3856,  3859,  3862,  3864,  3868,  3871,  3874,
  3876,  3880,  3882,  3885,  3890,  3892,  3895,  3897,  3901,  3906,
  3907,  3909,  3910,  3912,  3913,  3915,  3917,  3921,  3923,  3927,
  3929,  3932,  3934,  3938,  3941,  3944,  3949,  3953,  3954,  3956,
  3958,  3960,  3962,  3964,  3967,  3969,  3971,  3977,  3981,  3987,
  3991,  3993,  3997,  3998,  4000,  4004,  4008,  4012,  4016,  4023,
  4029,  4031,  4033,  4035,  4037,  4039,  4041,  4043,  4045,  4047,
  4049,  4051,  4053,  4055,  4057,  4058,  4060,  4062,  4064,  4066,
  4068,  4070,  4072,  4077,  4083,  4085,  4091,  4097,  4099,  4101,
  4103,  4108,  4110,  4115,  4117,  4125,  4127,  4129,  4131,  4136,
  4143,  4144,  4147,  4152,  4154,  4156,  4158,  4160,  4162,  4164,
  4166,  4168,  4170,  4174,  4178,  4180,  4182,  4184,  4185,  4189,
  4195,  4198,  4204,  4209,  4211,  4213,  4215,  4217,  4219,  4222,
  4225,  4228,  4231,  4233,  4236,  4239,  4240,  4244,  4245,  4249,
  4251,  4253,  4255,  4257,  4259,  4261,  4263,  4265,  4267,  4269,
  4271,  4273,  4275,  4277,  4279,  4281,  4283,  4285,  4287,  4289,
  4291,  4293,  4295,  4297,  4299,  4301,  4303,  4305,  4307,  4309,
  4313,  4314,  4323,  4324,  4334,  4335,  4343,  4344,  4354,  4355,
  4357,  4360,  4362,  4366,  4368,  4372,  4378,  4380,  4382,  4384,
  4386,  4389,  4390,  4391,  4400,  4406,  4408,  4410,  4418,  4419,
  4423,  4425,  4429,  4431,  4432,  4435,  4441,  4449,  4450,  4452,
  4454,  4456,  4458,  4462,  4464,  4467,  4469,  4473,  4476,  4480,
  4484,  4488,  4490,  4492,  4494,  4496,  4498,  4500,  4502,  4508,
  4514,  4520,  4526,  4532,  4537,  4544,  4548,  4550,  4554,  4555,
  4557,  4563,  4571,  4572,  4575,  4577,  4579,  4580,  4584,  4586,
  4590,  4592,  4594,  4596,  4597,  4601,  4603,  4605,  4607,  4609,
  4614,  4621,  4623,  4625,  4628,  4632,  4634,  4636,  4638,  4640,
  4642,  4644,  4646,  4648,  4650,  4653,  4655,  4657,  4659,  4663,
  4669,  4671,  4673,  4675,  4677,  4681,  4684,  4687,  4690,  4692,
  4695,  4698,  4701,  4704,  4707,  4709,  4713,  4716,  4718,  4721,
  4723,  4726,  4728,  4729,  4730,  4737,  4738,  4741,  4742,  4744,
  4746,  4749,  4752,  4755,  4760,  4764,  4766,  4770,  4772,  4775,
  4781,  4784,  4787,  4793,  4794,  4797,  4799,  4801,  4804,  4811,
  4818,  4820,  4821,  4823,  4826,  4828,  4831,  4832,  4835,  4837,
  4839,  4841,  4843,  4845,  4847,  4849,  4851,  4853,  4855,  4857,
  4859,  4861,  4863,  4865,  4867,  4869,  4871,  4873,  4875,  4877,
  4879,  4881,  4883,  4885,  4887,  4889,  4891,  4893,  4895,  4897,
  4899,  4901,  4903,  4905,  4907,  4909,  4911,  4913,  4915,  4917,
  4919,  4921,  4923,  4925,  4927,  4929,  4931,  4933,  4935,  4937,
  4939,  4941,  4943,  4945,  4947,  4949,  4951,  4953,  4955,  4957,
  4959,  4961,  4963,  4965,  4967,  4969,  4971,  4973,  4975,  4977,
  4979,  4981,  4983,  4985,  4987,  4989,  4991,  4993,  4995,  4997
};

static const short yyrhs[] = {   170,
     0,   167,     0,    96,   641,   394,   564,   642,     0,   110,
     0,  1043,     0,    25,     0,   643,     0,   642,     5,   643,
     0,   891,     0,   398,   644,   359,     0,   644,   645,   644,
     0,    25,     0,   646,    25,     0,  1043,     0,    18,     0,
    17,     0,    20,     0,    19,     0,    21,     0,    18,     0,
    17,     0,     0,   648,     0,     0,   245,   398,   649,   650,
   359,     0,   536,   398,    25,     5,    25,   359,     0,   651,
     0,   650,     5,   651,     0,   457,     0,   497,     0,   503,
     0,   473,     0,   377,     0,   574,     0,   494,     0,   447,
     0,   384,     0,   458,     0,   313,     0,   498,     0,   423,
     0,   301,     0,   562,     0,    70,     0,     0,   653,     0,
     0,   245,   398,   654,   655,   359,     0,   656,     0,   655,
     5,   656,     0,   651,     0,   399,     0,   572,    24,     0,
   173,   878,     0,   298,   878,     0,   255,   878,     0,   306,
   878,     0,   264,   878,     0,   230,   878,     0,   500,   658,
     0,   830,   312,  1043,     0,     0,   260,   398,  1397,   359,
   312,   659,  1061,     0,    76,   398,   891,   359,     0,   374,
   398,   883,   359,   312,  1043,     0,  1179,     0,   162,   398,
   883,   359,   312,  1043,     0,     0,     0,  1043,   558,   891,
   398,   660,   674,   359,   661,   672,     0,     0,     0,     0,
   891,   398,   662,   674,   663,   359,   664,   672,     0,     0,
     0,   441,  1367,   592,  1367,   398,   665,   674,   666,   359,
   672,     0,     0,     0,    35,   398,   667,   674,   668,   359,
   672,     0,     0,     0,     0,   333,   677,   558,   678,   426,
   641,   394,   398,   669,   674,   670,   359,   671,   673,     0,
     0,   312,  1061,     0,     0,   312,  1061,     0,   134,     0,
     0,   675,     0,   676,     0,   675,     5,   676,     0,   801,
     0,    24,     0,   891,     0,   891,     0,   891,   589,   891,
     0,     0,   501,   808,   680,   683,   687,   684,     0,     0,
   501,   681,   682,   685,   684,     0,   689,     0,   682,   689,
     0,   691,     0,   683,   691,     0,   328,     0,     0,     0,
   308,   686,  1407,     0,     0,     0,   308,   688,  1407,     0,
     0,   547,   808,   690,  1407,     0,     0,   547,   808,   692,
  1407,     0,   249,   888,     0,   172,   886,     0,    53,   886,
     0,   141,     0,   157,  1373,     0,   461,   885,     0,    29,
   695,    30,     0,   696,     0,   698,     0,   697,     0,   696,
   697,     0,    28,     0,   699,     0,   698,   699,     0,    27,
     0,   361,     0,     0,     0,   289,   702,   704,   703,   705,
     0,   352,  1043,   594,   706,   932,   959,   647,     0,  1043,
   594,   706,   932,   513,  1397,   959,   647,     0,     0,   708,
   161,     0,   707,     0,   706,     5,   707,     0,   891,     0,
   891,   589,   891,     0,   891,   589,    20,     0,   709,     0,
   708,   709,     0,     0,   241,   715,   710,  1407,     0,     0,
   244,   716,   711,  1407,     0,     0,   960,   712,  1407,     0,
     0,   139,   713,  1407,     0,     0,   135,   714,  1407,     0,
   897,     0,   715,     5,   897,     0,   897,     0,   716,     5,
   897,     0,    64,     0,    65,     0,    66,     0,    67,     0,
    68,     0,    69,     0,   127,     0,   250,     0,     0,   720,
     0,   721,     0,   720,   721,     0,     0,   405,   722,   723,
     0,   768,     0,  1387,     0,   726,     0,   723,     5,   726,
     0,     0,   725,   891,     0,   321,   724,   767,    24,     0,
   321,   724,   767,   899,     0,   321,   724,   767,    25,     0,
   730,   746,     0,     0,   724,   321,   727,   728,     0,    25,
     0,    24,     0,   899,     0,    17,    25,     0,   724,     0,
   729,     0,   730,     5,   729,     0,     0,   502,     0,     0,
   454,   426,   738,   394,   733,   593,   746,     0,     0,   287,
   731,   735,    25,   736,   273,   426,   737,   394,   734,   593,
   746,     0,   398,     0,   425,     0,   359,     0,   393,     0,
    25,     0,   739,     5,   739,     5,   739,     0,   739,     5,
   739,     0,   739,     0,    25,     0,     0,   431,   741,   723,
   254,     0,     0,   231,   742,   724,   589,    20,     0,     0,
   303,   743,   724,   229,   398,   744,   359,     0,   745,     0,
   744,     5,   745,     0,   724,     0,   747,     0,     0,   748,
   749,     0,   732,     0,   740,     0,   502,     0,   502,   398,
    25,   359,     0,   391,   398,    25,   359,     0,   391,   398,
    25,     5,    25,   359,     0,   375,     0,   586,   724,     0,
   347,     0,   476,     0,    61,     0,   365,     0,   365,   398,
    25,   359,     0,   365,   398,    25,     5,    25,   359,     0,
   479,     0,   479,   398,    25,   359,     0,   479,   398,    25,
     5,    25,   359,     0,   469,     0,   270,     0,   504,     0,
   499,     0,    50,     0,    51,     0,   542,     0,   325,   753,
     0,   337,   754,     0,   750,     0,   891,     0,   523,   751,
   589,   752,     0,   724,     0,   724,     0,     0,   755,   595,
   758,     0,   763,   595,   766,     0,     0,   756,   757,     0,
   550,     0,   480,     0,   559,     0,   519,     0,   421,     0,
   437,     0,   334,   760,     0,     0,   759,   757,     0,     0,
   398,   762,   359,     0,     0,   398,    25,   359,     0,    25,
     0,     0,   764,   765,   761,     0,   550,     0,   480,     0,
   559,     0,   519,     0,   421,     0,   437,     0,   334,   760,
     0,   765,     0,     0,    13,     0,     0,   207,   891,   769,
   586,   770,     0,   772,     0,   775,     0,   502,     0,   502,
   398,    25,   359,     0,   391,   398,    25,   359,     0,   391,
   398,    25,     5,    25,   359,     0,   375,     0,   347,     0,
   476,     0,   365,     0,   365,   398,    25,   359,     0,   365,
   398,    25,     5,    25,   359,     0,   479,     0,   479,   398,
    25,   359,     0,   479,   398,    25,     5,    25,   359,     0,
   469,     0,   270,     0,   504,     0,   499,     0,   542,     0,
   325,   753,     0,   337,   754,     0,   771,     0,   523,   751,
   589,   752,     0,     0,   454,   426,   738,   394,   773,   593,
   770,     0,     0,   287,   731,   735,    25,   736,   273,   426,
   737,   394,   774,   593,   770,     0,     0,   431,   776,   778,
   254,     0,     0,   231,   777,   891,   589,    20,     0,   779,
     0,   778,     5,   779,     0,   780,   770,     0,   781,     0,
   780,     5,   781,     0,   891,     0,     0,   587,   882,     0,
    40,   891,     0,    38,     0,   595,  1397,     0,   595,   476,
   891,   628,  1397,     0,   595,   476,   891,   357,     0,    42,
   891,     0,   128,   824,  1061,   790,     0,   368,   824,   806,
   782,   790,     0,   179,   888,   790,     0,     0,     0,   160,
   787,  1068,   595,   891,   589,    20,   789,   647,   788,   791,
     0,     0,   436,     8,   883,     0,   647,     0,     0,   792,
   209,     0,   793,     0,   792,   793,     0,     0,   319,   794,
  1407,     0,     0,   315,   795,  1407,     0,     0,   960,   796,
  1407,     0,   465,   824,   807,   647,     0,   465,   824,   807,
   647,    36,     0,   183,     0,   183,   808,     0,   257,     0,
   256,     0,   182,     0,   332,     0,   146,     0,   181,     0,
   297,     0,   296,     0,   214,     0,   143,     0,   142,     0,
   116,     0,   174,     0,    99,     0,   115,     0,   159,     0,
   125,     0,   811,     0,   810,     0,   813,     0,   839,     0,
   801,   802,     0,   840,     0,   842,     0,   812,     0,    17,
   801,     0,    18,   801,     0,   815,     0,   823,     0,   817,
     0,   442,     0,   717,     0,   818,     0,   819,     0,   820,
     0,   821,     0,   822,     0,     0,   805,     0,   808,     0,
   450,     0,   804,     0,   805,     5,   804,     0,   808,     0,
   806,     5,   808,     0,   808,     0,   807,     5,   808,     0,
   801,     0,    18,     0,    17,     0,   571,   801,     0,   451,
     0,   395,     0,   398,   801,   359,     0,   410,   398,  1349,
   359,     0,   265,   398,  1349,   359,     0,   809,   899,     0,
   809,    25,     0,   455,    25,     0,   455,  1043,     0,    24,
     0,   899,     0,    25,     0,  1043,   388,  1043,     0,  1043,
     0,   401,   801,     0,   360,   801,     0,  1153,     0,     0,
   474,   814,  1153,     0,     7,   801,     0,     6,   801,     0,
   801,     0,   816,     5,   801,     0,   592,   398,  1349,   359,
     0,   396,   398,  1349,   359,     0,   592,   398,   824,   816,
   359,     0,   396,   398,   824,   816,   359,     0,   354,     0,
   220,     0,     9,   801,     0,   223,   801,     0,   523,   801,
     0,   339,   801,     0,   358,     0,     8,   801,     0,    18,
   801,     0,    17,   801,     0,    20,   801,     0,    19,   801,
     0,    21,   801,     0,    10,   801,     0,    13,   801,     0,
   424,   801,     0,    11,   801,     0,    12,   801,     0,    16,
   801,     0,    15,   801,     0,    14,   801,     0,     0,     0,
     0,   891,   398,   826,   674,   827,   359,     0,     0,     0,
    35,   398,   828,   674,   829,   359,     0,     0,     0,   504,
   398,   831,   801,   832,   359,     0,     0,     0,   480,   398,
   833,   801,   834,   359,     0,     0,     0,   559,   398,   835,
   801,   836,   359,     0,     0,     0,   550,   398,   837,   801,
   838,   359,     0,   830,     0,   260,   398,  1397,   359,     0,
    71,   398,   883,   359,     0,    41,   398,   883,   359,     0,
   374,   398,   883,   359,     0,   162,   398,   883,   359,     0,
   841,     0,   825,     0,  1325,     0,   504,     0,   390,   398,
   801,   359,     0,   291,   398,   801,   359,     0,   455,   398,
    25,   359,     0,   455,   398,  1043,   359,     0,   801,    80,
     0,   801,    81,     0,   801,    82,     0,     0,     0,     0,
   371,   844,   885,   845,  1228,   846,  1407,   211,     0,     0,
     0,   607,   891,   848,   719,   849,   988,   851,   850,   856,
   608,     0,     0,   861,     0,     0,   852,     0,   853,     0,
   852,   853,     0,     0,   609,   854,  1407,     0,     0,   610,
   855,  1407,     0,     0,   857,     0,   858,     0,   857,   858,
     0,     0,   611,   859,  1407,     0,     0,   612,   860,  1407,
     0,   862,   866,   293,     0,    63,     0,    63,   863,   513,
   864,     0,    63,   352,   865,     0,  1043,     0,   863,     5,
  1043,     0,   891,     0,   864,     5,   891,     0,  1043,     0,
   865,     5,  1043,     0,   867,     0,   866,   867,     0,     0,
   613,   868,  1407,     0,     0,   614,   869,  1407,     0,     0,
   633,   864,   870,  1407,     0,     0,   448,   864,   871,  1407,
     0,     0,   594,   864,   872,  1407,     0,     0,     0,   564,
  1043,    13,   808,   595,   808,   876,   874,  1407,   875,   212,
     0,     0,   539,   808,     0,   512,   884,     0,   521,    17,
    25,     0,   521,     0,   468,    18,    25,     0,   468,     0,
    25,     0,  1043,     0,    24,     0,   898,     0,   808,     0,
   880,     5,   880,     0,   881,     0,   891,     0,   636,   398,
   891,   359,     0,   891,   589,   636,   398,   891,   359,     0,
   891,   426,   644,   394,     0,   891,   589,    20,     0,   891,
   426,   644,   394,   589,    20,     0,   891,   589,   891,     0,
   891,   426,   644,   394,   589,   891,     0,   892,     0,   892,
     0,   892,     0,   892,     0,   892,     0,   892,     0,     0,
   517,    25,     0,   895,  1406,   896,     0,   900,     0,   895,
   893,   896,     0,  1406,     0,   317,   398,   894,   359,     0,
  1046,     0,    24,     0,     0,     0,   891,     0,   891,   426,
   644,   394,     0,   891,   589,    20,     0,   891,   426,   644,
   394,   589,    20,     0,   891,   589,   891,     0,   891,   426,
   644,   394,   589,   891,     0,  1043,     0,    23,     0,   589,
    25,     0,   341,     0,   459,     0,   460,     0,   358,     0,
   461,     0,   321,     0,   289,     0,   463,     0,   427,     0,
   503,     0,   416,     0,   560,     0,   364,     0,   456,     0,
   449,     0,   526,     0,   367,     0,   326,     0,   464,     0,
   290,     0,   505,     0,   251,     0,   562,     0,   624,     0,
   506,     0,   291,     0,   508,     0,   372,     0,   410,     0,
   550,     0,   480,     0,   559,     0,   525,     0,   442,     0,
   346,     0,   361,     0,   406,     0,   348,     0,   409,     0,
   390,     0,   514,  1389,     0,   621,   903,     0,   904,     0,
   903,     5,   904,     0,   891,     0,   632,   903,     0,   623,
   903,     0,   624,  1397,     0,   622,   888,   628,  1397,     0,
   626,   903,     0,   627,  1397,     0,   625,   888,   628,  1397,
     0,     0,   630,   909,   806,   914,   916,   918,   910,   912,
     0,     0,   911,     0,   618,     0,   619,     0,     0,   913,
     0,   312,  1043,     0,     0,   915,     0,   357,   806,     0,
     0,   917,     0,   629,    25,     0,     0,   919,     0,   620,
    25,   920,     0,     0,   367,    25,     0,     0,   591,   808,
   543,   922,  1407,   923,   408,     0,     0,     0,   509,   924,
  1407,     0,    78,   891,   398,    25,   359,     0,     0,    45,
   891,     0,     0,   261,  1073,   928,   595,   450,     0,   261,
  1073,   523,   929,     0,   930,     0,   929,     5,   930,     0,
   751,   589,  1322,     0,   751,   589,    20,     0,     0,   933,
   293,     0,     0,   122,     0,   934,     0,   933,   934,     0,
     0,   241,   948,   935,  1407,     0,     0,   244,   949,   936,
  1407,     0,     0,   319,   937,  1407,     0,     0,   315,   938,
  1407,     0,     0,   960,   939,  1407,     0,     0,   276,   940,
  1407,     0,     0,   246,   941,  1407,     0,     0,   633,   946,
   942,  1407,     0,     0,   448,   944,   943,  1407,     0,   945,
     0,   944,     5,   945,     0,   417,     0,   406,     0,   947,
     0,   946,     5,   947,     0,   417,     0,   406,     0,   883,
     0,   948,     5,   883,     0,   883,     0,   949,     5,   883,
     0,   283,   952,     0,   284,   891,   628,   952,     0,   529,
     0,   342,     0,   883,     0,     0,   634,   955,   954,   931,
     0,   352,  1061,   932,   890,   647,     0,  1061,   932,   513,
  1397,   890,   647,     0,     0,   454,  1068,   932,   513,   891,
   589,    20,   890,   956,   647,     0,   436,  1397,   958,     0,
   596,     0,   506,     0,    46,    25,     0,    52,    25,     0,
     0,   517,    25,     0,     0,   397,   961,   967,     0,   266,
     0,     0,   565,   963,   967,     0,   274,   969,     0,     0,
   565,   966,   967,     0,   969,     0,   398,   968,   359,     0,
   969,     0,   968,     5,   969,     0,     0,   970,   971,     0,
   563,     0,   281,     0,   299,     0,   275,     0,   452,     0,
   409,     0,   596,     0,   506,     0,   433,     0,   507,     0,
   522,     0,   487,     0,   279,     0,   280,     0,    24,     0,
   477,   891,     0,   477,   891,   558,     0,     0,     0,   567,
   974,  1066,   975,    13,   824,   976,     0,   450,     0,   807,
     0,   189,  1043,     0,   178,  1043,     0,   192,  1043,     0,
   418,  1043,   302,     0,   418,  1043,   353,   879,     0,     0,
     0,   988,   926,   988,  1002,   988,   982,   719,   988,   983,
   984,     0,     0,   985,     0,   987,     0,   985,   987,     0,
    37,   891,     0,   990,     0,   996,     0,  1008,     0,  1163,
     0,  1172,     0,  1012,     0,  1387,     0,   847,     0,   694,
     0,   925,     0,   700,     0,     0,   694,     0,  1387,     0,
   335,     0,    31,     0,     0,     0,     0,     0,   989,   991,
   891,   398,   992,  1059,   359,   993,   719,   994,   988,  1407,
   995,     0,   180,     0,     0,     0,   524,   997,   719,   998,
  1407,   329,     0,   433,   824,   803,     0,     0,   806,     0,
   324,  1333,     0,     0,  1003,     0,  1004,     0,  1003,  1004,
     0,  1005,     0,   694,     0,  1387,     0,  1001,     0,     0,
   373,  1006,  1007,     0,   719,   213,     0,   879,     0,     0,
     0,     0,    85,   891,    84,   891,   398,  1009,  1059,   359,
  1010,   719,  1011,   988,  1407,   995,     0,     0,     0,   615,
   891,  1013,   719,  1014,  1015,   616,     0,  1016,     0,  1015,
  1016,     0,     0,   617,  1017,  1407,     0,     0,   594,   891,
  1018,  1407,     0,     0,   525,  1020,  1035,  1026,  1021,     0,
   330,     0,     0,   205,  1023,  1407,     0,     0,    22,  1027,
  1028,  1029,   890,  1024,  1407,     0,     0,    22,  1027,   890,
  1025,  1407,     0,  1022,     0,  1026,  1022,     0,     0,   962,
     0,    24,     0,  1043,     0,     0,  1043,     0,    24,     0,
   222,  1033,     0,   234,  1034,     0,   217,  1034,     0,   554,
     0,    24,     0,  1043,     0,  1033,     0,  1034,     5,  1033,
     0,  1043,     0,    24,     0,  1039,  1037,     0,     0,   648,
  1041,     0,  1042,     0,  1038,     0,   915,     0,   917,     0,
   919,     0,   911,     0,   913,     0,     0,   338,  1040,   807,
     0,     0,    36,     0,    36,     0,  1044,     0,  1046,     0,
   581,  1046,     0,  1046,   895,   589,     0,  1045,  1050,     0,
  1045,   891,   426,  1053,   394,     0,  1051,     0,   891,     0,
  1047,     0,   891,   425,  1049,   393,     0,   891,   425,  1049,
   393,     0,  1043,     0,    24,     0,    20,     0,   891,     0,
   891,  1052,     0,   426,  1053,   394,     0,   426,  1053,   394,
   426,  1053,   394,     0,  1054,     0,  1053,     5,  1054,     0,
   644,     0,  1056,     0,  1058,     0,  1056,   895,   589,  1057,
     0,  1056,   895,   589,   891,   426,  1053,   394,     0,   891,
     0,  1048,     0,    20,     0,   891,     0,   891,  1052,     0,
     0,  1060,     0,  1062,     0,  1060,     5,  1062,     0,  1063,
     0,  1061,     5,  1063,     0,   891,     0,   891,   589,   891,
     0,  1043,     0,  1043,   388,  1043,     0,    24,     0,   899,
     0,    25,     0,  1065,     0,  1064,     5,  1065,     0,  1043,
     0,  1067,     0,  1066,     5,  1067,     0,  1055,     0,  1043,
     0,  1070,     0,  1069,     5,  1070,     0,  1043,  1071,     0,
     0,   556,     0,   505,     0,   891,   426,  1053,   394,     0,
  1074,     0,  1073,     5,  1074,     0,  1043,     0,  1043,   388,
  1043,     0,   225,   887,   587,   881,   548,  1399,   652,     0,
     0,   587,   398,   808,     5,   808,   359,  1077,     0,     0,
   536,   398,   808,     5,   808,   359,     0,   226,   891,  1076,
     0,   891,     0,   307,   889,  1081,     0,  1082,     0,   513,
   808,     0,  1083,  1084,  1089,     8,  1079,     0,     0,   587,
  1085,   398,   808,     5,   808,   359,     0,     0,   523,   892,
     0,     0,   318,     0,   187,  1373,   237,  1382,  1088,     0,
   531,   884,     0,   531,   884,     8,   824,   806,     0,     0,
   586,   544,  1367,   341,  1367,     0,   586,   544,  1367,     5,
   341,  1367,     0,   586,  1367,     5,  1367,     0,     0,   618,
     0,   619,     0,    62,  1382,  1091,  1092,     0,     0,   586,
  1382,     0,     0,   586,   544,  1367,     8,  1367,     0,   544,
  1367,     8,  1367,     0,   379,  1094,     0,  1095,     0,  1094,
     5,  1095,     0,   173,   878,     0,   255,   878,     0,   298,
   878,     0,   306,   878,     0,   264,   878,     0,   230,   878,
     0,   964,     0,   406,   965,     0,   417,   965,     0,   529,
   965,     0,   342,   965,     0,   517,   965,     0,   515,   879,
     0,   516,   879,     0,   368,   648,     0,   634,   648,     0,
   262,     0,   165,     0,   123,     0,   100,     0,   118,     0,
   109,     0,  1372,   381,  1099,   513,  1097,     0,  1043,     0,
    24,     0,   370,  1099,     0,   370,  1099,     8,  1061,     0,
   892,     0,     0,   429,  1108,   647,   564,  1103,  1043,   890,
   647,  1101,  1104,     0,   429,  1108,   647,   312,  1043,     0,
     0,   502,     0,     0,  1105,   253,     0,  1106,     0,  1105,
  1106,     0,     0,   960,  1107,  1407,     0,   807,     0,     0,
   573,   884,  1110,  1111,     0,     0,   513,  1112,     0,  1113,
     0,  1112,     5,  1113,     0,  1361,     0,   450,     0,   190,
  1116,    60,     0,   190,  1116,   595,  1115,     0,   190,  1116,
    59,  1115,     0,   190,  1116,     0,    24,     0,   898,     0,
   891,     0,     0,   446,     0,     0,     0,     0,   117,  1116,
  1117,   398,  1119,   824,  1120,  1000,  1121,   359,     0,   163,
  1116,     0,  1154,  1162,     0,   414,    32,     0,   414,  1125,
     0,  1126,     0,  1125,  1126,     0,     0,   105,  1127,  1407,
     0,     0,   169,  1128,  1407,     0,     0,   198,  1129,  1407,
     0,     0,   186,  1130,  1407,     0,     0,   224,  1131,  1407,
     0,     0,   171,  1043,  1132,  1407,     0,     0,   194,  1043,
  1133,  1407,     0,  1144,     0,  1146,     0,  1145,     0,  1135,
     0,  1170,     0,  1138,     0,     0,   528,   808,  1136,   449,
     0,     0,   449,     0,     0,   537,   808,  1139,  1137,     0,
   130,     0,   598,  1158,     0,   133,  1158,     0,   132,  1158,
     0,     0,  1141,     0,  1142,     0,  1141,  1142,     0,  1151,
  1143,     0,     0,   587,  1158,     0,   486,  1140,  1150,     0,
   485,  1367,  1150,     0,   484,  1149,  1148,  1147,  1150,     0,
     0,   124,   801,     0,   124,   801,     5,   801,     0,   582,
     0,   583,     0,   584,     0,   585,     0,  1043,     0,     0,
   488,     0,  1152,     0,  1151,     5,  1152,     0,   808,  1183,
     0,   578,   398,   801,   359,  1169,     0,    34,  1169,     0,
   380,   398,    20,   359,  1169,     0,   355,   398,   801,   359,
  1169,     0,   557,   398,   801,   359,  1169,     0,   570,   398,
   801,   359,  1169,     0,   569,   398,   801,   359,  1169,     0,
     0,   428,  1155,     0,  1156,     0,  1155,  1156,     0,   197,
    25,     0,   188,    25,     0,   272,    25,     0,   156,    25,
     0,   227,    25,     0,   148,     0,   311,    24,     0,   311,
  1043,     0,   149,    24,     0,   131,    24,     0,  1161,     0,
  1157,  1161,     0,  1159,    80,     0,  1159,    82,     0,  1159,
    81,     0,  1159,     0,   899,     0,    25,     0,     0,   428,
  1157,     0,   197,  1158,     0,   188,  1158,     0,   272,  1158,
     0,   156,  1158,     0,   227,  1158,     0,   228,  1158,     0,
   597,    24,     0,   598,  1158,     0,   602,     0,   599,     0,
   600,     0,   601,     0,   606,     0,   603,     0,   604,     0,
   605,     0,    47,  1158,     0,    48,  1158,     0,    49,  1158,
     0,   311,    24,     0,   149,    24,     0,   367,     0,    43,
     0,    44,     0,     0,   481,   588,  1069,     0,   106,  1069,
     0,     0,     0,     0,     0,     0,   432,  1164,   891,   398,
  1165,  1059,   359,  1166,   719,  1123,  1167,  1124,  1168,   210,
     0,     0,   492,   801,     0,   483,  1171,     0,     0,  1097,
     0,     0,     0,     0,     0,     0,    77,  1173,   891,   398,
  1174,  1059,   359,  1175,   719,  1178,  1176,  1124,  1177,   210,
     0,  1160,  1162,     0,     0,     0,     0,   126,   398,    24,
     5,  1180,   674,  1181,   359,  1182,   672,     0,     0,   351,
     0,   351,   188,    25,     0,   351,   188,  1043,     0,   576,
   808,     0,   576,   808,   312,  1043,     0,   576,   808,   134,
     0,   576,   808,   546,     0,   576,   808,   511,     0,  1186,
     0,   145,     0,   292,     0,   252,     0,  1188,     0,    75,
  1194,   359,     0,     0,     0,   176,  1189,  1317,   398,  1190,
  1196,   359,     0,     0,     0,   103,  1191,  1317,   398,  1192,
  1196,   359,  1193,     0,     0,   239,     0,  1195,     0,  1194,
     5,  1195,     0,   891,   556,     0,   891,   505,     0,   891,
     0,  1197,     0,  1196,     5,  1197,     0,  1268,     0,  1266,
     0,    92,   891,     0,   151,     0,   236,     0,   201,     0,
   136,  1201,     0,   113,     0,   101,     0,    91,     0,    89,
     0,    93,     0,   150,  1373,     0,   200,  1200,   427,  1367,
   595,  1367,     0,   269,   884,   427,  1367,   595,  1367,     0,
     0,  1373,     0,     0,   808,     0,   489,   808,     0,   445,
  1317,   552,  1205,  1204,     0,     0,   121,   885,     0,   492,
  1290,     0,  1206,     0,   398,  1210,   359,    13,   398,  1211,
   359,     0,  1207,     0,    20,    13,   398,  1211,   359,     0,
    20,    13,  1211,     0,  1209,     0,  1207,     5,  1209,     0,
  1322,     0,  1208,    13,  1212,     0,  1208,     0,  1210,     5,
  1208,     0,  1212,     0,  1211,     5,  1212,     0,  1361,     0,
   450,     0,  1356,     0,   199,     0,     0,   219,  1215,  1317,
  1218,  1216,     0,     0,   446,  1217,   398,  1220,   359,     0,
  1355,     0,     0,   398,  1219,   359,     0,  1322,     0,  1219,
     5,  1322,     0,  1221,     0,  1220,     5,  1221,     0,  1361,
     0,   450,     0,     0,     0,   467,  1223,  1225,  1224,  1226,
     0,  1230,   885,     0,   885,     0,     0,     0,   520,  1227,
  1061,     0,     0,     0,   520,  1229,  1061,     0,   468,     0,
   521,     0,   529,     0,   342,     0,   363,     0,   345,   808,
     0,   318,   808,     0,   208,  1317,   121,   885,     0,   208,
  1317,  1287,     0,   481,   588,  1234,     0,  1235,     0,  1234,
     5,  1235,     0,  1236,  1237,     0,    25,     0,  1322,     0,
     0,   556,     0,   505,     0,   247,     0,   278,     0,     0,
   295,     0,   324,  1382,  1240,     0,     0,  1372,  1243,  1244,
     0,  1272,     0,  1276,     0,  1239,     0,  1374,     0,  1238,
     0,  1241,     0,  1231,     0,  1232,     0,  1222,     0,  1214,
     0,  1213,     0,  1345,     0,  1203,     0,   472,  1247,   594,
  1317,   595,  1252,  1246,     0,     0,   112,     0,   140,     0,
  1248,     0,  1249,     0,  1248,     5,  1249,     0,   438,     0,
   417,     0,   406,     0,   445,  1250,     0,     0,   398,  1251,
   359,     0,  1322,     0,  1251,     5,  1322,     0,  1253,     0,
  1252,     5,  1253,     0,   430,     0,  1319,     0,   206,  1317,
  1255,   586,  1355,  1257,     0,     0,   398,  1256,   359,     0,
  1322,     0,  1256,     5,  1322,     0,     0,   111,     0,   459,
   398,  1290,   359,     0,   216,   398,  1261,   359,  1260,     0,
   267,  1262,     0,  1263,     0,  1317,     0,  1317,   398,  1263,
   359,     0,  1322,     0,  1263,     5,  1322,     0,   443,   398,
  1265,   359,     0,   229,   398,  1265,   359,     0,  1322,     0,
  1265,     5,  1322,     0,  1264,     0,  1259,     0,  1258,     0,
   367,  1324,     0,   177,     0,  1322,  1309,  1269,  1270,     0,
     0,  1267,     0,     0,  1271,  1270,     0,   340,     0,   129,
     0,  1260,     0,   459,   398,  1290,   359,     0,    90,  1273,
  1275,     0,  1274,     0,  1319,     0,  1276,     0,  1275,  1276,
     0,  1254,     0,  1245,     0,   415,  1290,     0,   336,  1279,
     0,  1360,     0,  1279,     5,  1360,     0,   492,  1290,     0,
   513,  1282,     0,  1283,     0,  1282,     5,  1283,     0,  1284,
     0,   482,  1284,     0,   482,   398,  1285,   359,     0,  1317,
     0,  1317,  1323,     0,  1283,     0,  1285,     5,  1283,     0,
  1281,  1287,  1288,  1289,     0,     0,  1280,     0,     0,  1278,
     0,     0,  1277,     0,  1291,     0,  1290,     6,  1291,     0,
  1292,     0,  1291,     7,  1292,     0,  1293,     0,   571,  1293,
     0,  1307,     0,   398,  1290,   359,     0,   410,  1356,     0,
   265,  1356,     0,  1361,  1306,  1296,  1356,     0,  1356,  1306,
  1361,     0,     0,  1297,     0,  1298,     0,   554,     0,   538,
     0,   555,     0,   409,  1301,     0,  1363,     0,  1363,     0,
  1361,   592,   398,  1303,   359,     0,  1361,   592,  1356,     0,
  1361,   396,   398,  1303,   359,     0,  1361,   396,  1356,     0,
  1363,     0,  1303,     5,  1363,     0,     0,   571,     0,  1361,
  1304,   354,     0,  1361,  1304,   220,     0,  1361,  1306,  1361,
     0,  1361,  1306,  1356,     0,  1361,  1304,   356,  1361,     7,
  1361,     0,  1361,  1304,   523,  1300,  1299,     0,    13,     0,
    16,     0,    11,     0,    12,     0,   223,     0,   339,     0,
     9,     0,   523,     0,    15,     0,    14,     0,  1305,     0,
  1302,     0,  1295,     0,  1294,     0,     0,   554,     0,   327,
     0,   443,     0,  1310,     0,  1311,     0,  1313,     0,   502,
     0,   502,   398,  1314,   359,     0,   378,   398,  1315,  1312,
   359,     0,   439,     0,   365,   398,  1315,  1312,   359,     0,
   479,   398,  1315,  1312,   359,     0,   504,     0,   375,     0,
   347,     0,   325,  1331,   595,  1332,     0,   325,     0,   337,
  1331,   595,  1332,     0,   337,     0,   337,  1331,   398,    25,
   359,   595,  1332,     0,   542,     0,   499,     0,   391,     0,
   391,   398,    25,   359,     0,   391,   398,    25,     5,    25,
   359,     0,     0,     5,  1316,     0,   469,   398,  1315,   359,
     0,   533,     0,   270,     0,   469,     0,    33,     0,    25,
     0,    25,     0,    25,     0,    24,     0,  1320,     0,  1318,
   558,  1320,     0,    24,   589,  1320,     0,   891,     0,   891,
     0,   891,     0,     0,   426,    25,   394,     0,   426,    25,
     5,    25,   394,     0,   891,  1321,     0,  1317,   895,   589,
   891,  1321,     0,  1317,   895,   589,    20,     0,   891,     0,
    24,     0,   378,     0,   899,     0,    25,     0,    18,   899,
     0,    18,    25,     0,    17,   899,     0,    17,    25,     0,
  1326,     0,   363,  1328,     0,   363,  1327,     0,     0,  1331,
   595,  1332,     0,     0,  1329,   595,  1330,     0,   550,     0,
   480,     0,   559,     0,   519,     0,   421,     0,   437,     0,
   334,     0,   550,     0,   480,     0,   559,     0,   519,     0,
   421,     0,   437,     0,   334,     0,   550,     0,   480,     0,
   559,     0,   519,     0,   421,     0,   437,     0,   334,     0,
   550,     0,   480,     0,   559,     0,   519,     0,   421,     0,
   437,     0,   334,     0,   891,     0,    24,     0,  1372,   470,
   885,     0,     0,  1372,   366,   885,   404,   564,  1343,  1336,
  1340,     0,     0,  1372,   366,   885,   404,    72,   564,  1344,
  1337,  1340,     0,     0,  1372,   366,   885,   107,  1344,  1338,
  1340,     0,     0,  1372,   366,   885,   108,    72,   564,  1344,
  1339,  1340,     0,     0,   259,     0,   258,  1341,     0,  1342,
     0,  1341,     5,  1342,     0,   891,     0,   891,   589,   891,
     0,    24,   589,   891,   589,   891,     0,  1344,     0,  1214,
     0,  1099,     0,  1346,     0,  1346,  1340,     0,     0,     0,
   438,  1357,  1358,  1347,  1354,  1348,  1286,  1352,     0,   438,
  1357,  1358,  1286,  1352,     0,  1351,     0,  1367,     0,   438,
   895,  1357,  1358,  1354,  1286,  1352,     0,     0,   491,  1308,
  1350,     0,  1233,     0,   300,  1353,  1193,     0,   891,     0,
     0,   520,  1064,     0,   438,   895,  1357,  1358,  1286,     0,
   398,   438,   895,  1357,  1358,  1286,   359,     0,     0,   554,
     0,   327,     0,   443,     0,  1359,     0,  1358,     5,  1359,
     0,  1361,     0,  1361,  1406,     0,  1361,     0,  1361,    19,
  1361,     0,  1361,  1381,     0,  1361,    20,  1361,     0,  1361,
    18,  1361,     0,  1361,    17,  1361,     0,  1386,     0,  1324,
     0,   451,     0,   395,     0,   544,     0,    20,     0,    34,
     0,   557,   398,  1308,  1361,   359,     0,   569,   398,  1308,
  1361,   359,     0,   570,   398,  1308,  1361,   359,     0,   578,
   398,  1308,  1361,   359,     0,   463,   398,  1308,  1361,   359,
     0,   891,   398,  1362,   359,     0,   504,   895,   398,   895,
  1362,   359,     0,   398,  1361,   359,     0,  1361,     0,  1362,
     5,  1361,     0,     0,  1324,     0,  1372,   314,  1371,  1366,
  1350,     0,  1372,   304,  1371,  1366,   219,  1317,  1368,     0,
     0,   290,  1367,     0,    24,     0,  1043,     0,     0,   398,
  1369,   359,     0,  1370,     0,  1369,     5,  1370,     0,   891,
     0,    24,     0,  1043,     0,     0,   238,  1373,   564,     0,
   892,     0,  1379,     0,  1378,     0,  1375,     0,   285,  1376,
   595,  1376,     0,   268,  1376,   589,  1377,   595,  1377,     0,
   891,     0,   891,     0,   191,   751,     0,   263,   751,  1380,
     0,   242,     0,   147,     0,    64,     0,    65,     0,    66,
     0,    67,     0,    68,     0,    69,     0,  1383,     0,   581,
  1384,     0,  1384,     0,  1072,     0,   891,     0,  1384,   589,
  1385,     0,    24,   589,  1384,   589,  1385,     0,    20,     0,
  1072,     0,   891,     0,  1383,     0,  1383,   388,  1383,     0,
    98,  1388,     0,   102,  1388,     0,    97,  1388,     0,   137,
     0,   138,  1388,     0,    95,  1388,     0,   120,  1388,     0,
   119,  1388,     0,    94,  1388,     0,   323,     0,   590,   595,
  1389,     0,   514,  1389,     0,   540,     0,   500,  1390,     0,
   891,     0,   558,   891,     0,   891,     0,     0,     0,   493,
  1392,   808,  1393,  1407,   294,     0,     0,   628,  1397,     0,
     0,   631,     0,   153,     0,   248,   886,     0,    39,   886,
     0,   277,  1395,     0,   277,   888,  1394,  1395,     0,   460,
  1397,  1395,     0,   883,     0,  1397,     5,   883,     0,    74,
     0,   104,   886,     0,   808,   534,     5,   808,   360,     0,
   476,   808,     0,   235,   886,     0,    73,  1402,     8,  1403,
  1401,     0,     0,   513,   808,     0,   891,     0,   891,     0,
   218,   886,     0,   221,   886,   595,   808,     5,   808,     0,
   221,   886,   588,   808,     5,   808,     0,    26,     0,     0,
  1409,     0,  1410,  1150,     0,  1408,     0,  1409,  1408,     0,
     0,  1411,  1412,     0,   637,     0,   638,     0,   639,     0,
   640,     0,   657,     0,   679,     0,   693,     0,   694,     0,
   700,     0,   701,     0,   718,     0,   783,     0,   784,     0,
   785,     0,   786,     0,   797,     0,   798,     0,   799,     0,
   800,     0,   843,     0,   873,     0,   877,     0,   901,     0,
   902,     0,   905,     0,   906,     0,   907,     0,   908,     0,
   921,     0,   927,     0,   950,     0,   951,     0,   953,     0,
   957,     0,   972,     0,   973,     0,   977,     0,   978,     0,
   979,     0,   980,     0,   986,     0,   999,     0,  1019,     0,
  1030,     0,  1031,     0,  1032,     0,  1036,     0,  1075,     0,
  1078,     0,  1080,     0,  1086,     0,  1087,     0,  1090,     0,
  1093,     0,  1096,     0,  1098,     0,  1100,     0,  1102,     0,
  1109,     0,  1114,     0,  1118,     0,  1122,     0,  1134,     0,
  1184,     0,  1185,     0,  1187,     0,  1198,     0,  1199,     0,
  1202,     0,  1241,     0,  1242,     0,  1334,     0,  1335,     0,
  1364,     0,  1365,     0,  1387,     0,  1391,     0,  1396,     0,
  1398,     0,  1400,     0,  1404,     0,  1405,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   854,   857,   860,   866,   872,   879,   883,   883,   889,   906,
   908,   909,   910,   911,   924,   926,   927,   928,   929,   934,
   935,   946,   949,   952,   952,   956,   959,   960,   966,   967,
   968,   969,   970,   971,   972,   973,   974,   975,   976,   977,
   978,   979,   980,   981,   984,   985,   988,   992,   996,   997,
  1000,  1006,  1008,  1019,  1021,  1023,  1025,  1029,  1031,  1093,
  1096,  1101,  1104,  1108,  1111,  1115,  1116,  1119,  1124,  1134,
  1138,  1143,  1147,  1155,  1159,  1163,  1166,  1172,  1177,  1180,
  1195,  1203,  1207,  1211,  1233,  1233,  1237,  1238,  1239,  1243,
  1247,  1252,  1256,  1264,  1267,  1267,  1273,  1277,  1289,  1300,
  1307,  1315,  1323,  1323,  1326,  1326,  1329,  1333,  1333,  1335,
  1340,  1340,  1343,  1348,  1353,  1359,  1363,  1378,  1381,  1384,
  1387,  1390,  1393,  1406,  1411,  1411,  1412,  1412,  1415,  1420,
  1420,  1424,  1434,  1447,  1452,  1455,  1461,  1468,  1476,  1477,
  1480,  1480,  1483,  1487,  1492,  1499,  1499,  1502,  1506,  1510,
  1512,  1515,  1517,  1520,  1522,  1525,  1528,  1537,  1539,  1546,
  1548,  1564,  1568,  1571,  1574,  1577,  1580,  1593,  1597,  1612,
  1613,  1616,  1617,  1620,  1621,  1622,  1623,  1626,  1626,  1629,
  1629,  1632,  1634,  1637,  1641,  1642,  1642,  1658,  1659,  1659,
  1659,  1663,  1670,  1671,  1674,  1674,  1676,  1681,  1682,  1690,
  1699,  1699,  1701,  1701,  1703,  1705,  1707,  1709,  1712,  1716,
  1716,  1717,  1717,  1721,  1722,  1733,  1733,  1738,  1742,  1744,
  1744,  1747,  1749,  1750,  1751,  1758,  1759,  1760,  1761,  1764,
  1765,  1766,  1767,  1771,  1776,  1781,  1785,  1788,  1792,  1793,
  1794,  1795,  1796,  1797,  1798,  1799,  1802,  1803,  1804,  1835,
  1840,  1842,  1844,  1844,  1851,  1855,  1855,  1858,  1859,  1860,
  1861,  1862,  1863,  1864,  1870,  1870,  1873,  1875,  1881,  1883,
  1889,  1897,  1897,  1900,  1901,  1902,  1903,  1904,  1905,  1906,
  1912,  1915,  1915,  1927,  1931,  1934,  1936,  1937,  1939,  1940,
  1942,  1944,  1945,  1946,  1947,  1952,  1958,  1964,  1965,  1967,
  1969,  1970,  1971,  1972,  1973,  1974,  1977,  1978,  1984,  1992,
  1996,  1997,  2005,  2013,  2013,  2015,  2015,  2023,  2023,  2026,
  2029,  2030,  2035,  2047,  2051,  2054,  2057,  2058,  2059,  2060,
  2061,  2066,  2071,  2077,  2082,  2085,  2089,  2096,  2099,  2104,
  2109,  2109,  2113,  2113,  2115,  2119,  2122,  2125,  2128,  2131,
  2144,  2147,  2161,  2165,  2178,  2180,  2182,  2184,  2186,  2188,
  2190,  2196,  2198,  2202,  2204,  2206,  2208,  2210,  2212,  2214,
  2220,  2233,  2235,  2236,  2237,  2238,  2242,  2243,  2244,  2248,
  2253,  2259,  2261,  2262,  2263,  2264,  2265,  2266,  2267,  2268,
  2269,  2274,  2274,  2278,  2278,  2281,  2287,  2295,  2301,  2311,
  2312,  2320,  2327,  2331,  2340,  2346,  2352,  2358,  2360,  2370,
  2382,  2392,  2402,  2406,  2409,  2416,  2423,  2429,  2493,  2546,
  2553,  2558,  2566,  2566,  2581,  2587,  2595,  2598,  2605,  2617,
  2627,  2633,  2641,  2647,  2654,  2660,  2665,  2670,  2677,  2685,
  2693,  2699,  2703,  2708,  2712,  2716,  2722,  2726,  2730,  2734,
  2738,  2742,  2746,  2753,  2760,  2768,  2774,  2783,  2788,  2791,
  2804,  2805,  2805,  2808,  2808,  2808,  2811,  2811,  2811,  2814,
  2814,  2814,  2820,  2822,  2828,  2829,  2834,  2837,  2841,  2842,
  2845,  2850,  2856,  2860,  2864,  2867,  2872,  2875,  2878,  2892,
  2897,  2902,  2906,  2921,  2928,  2932,  2941,  2941,  2943,  2944,
  2947,  2948,  2951,  2954,  2957,  2959,  2964,  2965,  2968,  2969,
  2972,  2975,  2978,  2980,  2985,  2988,  2990,  2991,  2995,  2996,
  2999,  2999,  3002,  3003,  3006,  3007,  3010,  3013,  3016,  3018,
  3021,  3023,  3026,  3028,  3031,  3033,  3046,  3051,  3052,  3059,
  3062,  3075,  3090,  3092,  3093,  3094,  3095,  3096,  3099,  3099,
  3102,  3104,  3107,  3109,  3111,  3112,  3113,  3115,  3117,  3119,
  3121,  3125,  3132,  3134,  3140,  3145,  3150,  3155,  3155,  3158,
  3161,  3165,  3170,  3173,  3180,  3180,  3182,  3188,  3192,  3193,
  3195,  3197,  3199,  3201,  3205,  3214,  3214,  3220,  3222,  3223,
  3224,  3225,  3226,  3227,  3228,  3229,  3230,  3231,  3232,  3233,
  3234,  3235,  3236,  3237,  3238,  3239,  3240,  3241,  3242,  3243,
  3244,  3245,  3246,  3247,  3248,  3249,  3250,  3251,  3252,  3253,
  3254,  3255,  3256,  3257,  3258,  3259,  3260,  3272,  3284,  3290,
  3291,  3295,  3300,  3306,  3310,  3314,  3320,  3324,  3328,  3334,
  3335,  3342,  3343,  3347,  3347,  3351,  3352,  3355,  3358,  3358,
  3361,  3363,  3363,  3366,  3368,  3368,  3369,  3371,  3371,  3377,
  3384,  3390,  3390,  3392,  3394,  3400,  3400,  3413,  3413,  3417,
  3423,  3423,  3427,  3428,  3439,  3440,  3442,  3444,  3449,  3449,
  3451,  3455,  3458,  3461,  3464,  3466,  3469,  3472,  3475,  3477,
  3480,  3482,  3485,  3487,  3490,  3492,  3495,  3497,  3502,  3504,
  3511,  3513,  3517,  3519,  3527,  3529,  3535,  3537,  3544,  3546,
  3555,  3560,  3565,  3566,  3567,  3570,  3574,  3580,  3586,  3591,
  3593,  3601,  3607,  3608,  3609,  3610,  3613,  3613,  3618,  3619,
  3620,  3624,  3624,  3626,  3630,  3630,  3633,  3634,  3637,  3637,
  3642,  3642,  3645,  3646,  3647,  3648,  3649,  3650,  3651,  3652,
  3653,  3654,  3655,  3656,  3657,  3658,  3659,  3663,  3666,  3680,
  3681,  3682,  3707,  3711,  3717,  3723,  3729,  3736,  3747,  3766,
  3774,  3775,  3777,  3779,  3781,  3782,  3785,  3791,  3792,  3793,
  3794,  3795,  3796,  3797,  3798,  3799,  3800,  3801,  3804,  3804,
  3804,  3807,  3807,  3815,  3820,  3828,  3835,  3842,  3847,  3860,
  3871,  3877,  3882,  3889,  3889,  3894,  3899,  3900,  3914,  3916,
  3919,  3919,  3919,  3919,  3922,  3928,  3933,  3938,  3960,  3964,
  3978,  3984,  3990,  3996,  3999,  4006,  4007,  4011,  4017,  4022,
  4025,  4040,  4046,  4048,  4057,  4063,  4066,  4077,  4080,  4088,
  4093,  4093,  4095,  4096,  4098,  4099,  4102,  4103,  4104,  4106,
  4111,  4116,  4121,  4124,  4125,  4128,  4129,  4132,  4133,  4141,
  4144,  4148,  4152,  4157,  4160,  4162,  4163,  4164,  4165,  4169,
  4169,  4171,  4171,  4174,  4183,  4206,  4207,  4210,  4213,  4218,
  4257,  4258,  4259,  4262,  4276,  4288,  4288,  4292,  4293,  4299,
  4352,  4357,  4365,  4370,  4378,  4384,  4406,  4409,  4410,  4448,
  4449,  4452,  4454,  4457,  4511,  4515,  4518,  4523,  4535,  4541,
  4550,  4550,  4553,  4554,  4558,  4559,  4560,  4563,  4566,  4572,
  4578,  4582,  4589,  4594,  4601,  4604,  4610,  4612,  4612,  4612,
  4615,  4627,  4633,  4641,  4644,  4657,  4665,  4666,  4669,  4670,
  4673,  4680,  4684,  4691,  4692,  4697,  4701,  4701,  4705,  4705,
  4709,  4710,  4713,  4721,  4725,  4731,  4732,  4734,  4736,  4740,
  4740,  4741,  4745,  4753,  4755,  4759,  4761,  4763,  4776,  4778,
  4779,  4781,  4784,  4787,  4790,  4793,  4796,  4799,  4803,  4807,
  4811,  4814,  4818,  4821,  4822,  4823,  4826,  4829,  4832,  4835,
  4838,  4841,  4844,  4860,  4868,  4868,  4870,  4877,  4884,  4896,
  4904,  4916,  4922,  4923,  4927,  4928,  4930,  4931,  4933,  4935,
  4941,  4949,  4954,  4959,  4961,  4964,  4964,  4968,  4968,  4980,
  4985,  4990,  4995,  5005,  5005,  5009,  5012,  5012,  5014,  5018,
  5021,  5024,  5030,  5037,  5039,  5042,  5046,  5046,  5048,  5051,
  5052,  5054,  5055,  5057,  5058,  5060,  5061,  5063,  5064,  5078,
  5079,  5096,  5099,  5100,  5101,  5102,  5103,  5104,  5106,  5106,
  5112,  5112,  5115,  5115,  5125,  5126,  5127,  5134,  5146,  5147,
  5150,  5151,  5154,  5157,  5157,  5162,  5166,  5171,  5176,  5178,
  5179,  5182,  5184,  5185,  5186,  5190,  5200,  5202,  5206,  5210,
  5215,  5220,  5228,  5235,  5242,  5249,  5256,  5263,  5272,  5272,
  5274,  5274,  5276,  5278,  5279,  5280,  5281,  5282,  5283,  5284,
  5285,  5286,  5289,  5289,  5292,  5293,  5294,  5295,  5298,  5298,
  5301,  5301,  5303,  5305,  5306,  5307,  5308,  5309,  5310,  5311,
  5313,  5314,  5315,  5316,  5318,  5319,  5320,  5321,  5323,  5324,
  5325,  5326,  5327,  5328,  5329,  5330,  5334,  5340,  5347,  5356,
  5361,  5370,  5375,  5382,  5386,  5394,  5397,  5405,  5417,  5418,
  5422,  5428,  5437,  5442,  5449,  5452,  5458,  5461,  5466,  5470,
  5474,  5479,  5481,  5482,  5483,  5488,  5490,  5492,  5496,  5500,
  5507,  5512,  5513,  5514,  5518,  5524,  5527,  5527,  5527,  5528,
  5529,  5529,  5532,  5534,  5539,  5540,  5544,  5546,  5547,  5550,
  5552,  5556,  5558,  5563,  5565,  5578,  5580,  5581,  5582,  5583,
  5584,  5585,  5586,  5587,  5590,  5593,  5598,  5599,  5604,  5605,
  5616,  5629,  5634,  5635,  5640,  5648,  5650,  5651,  5654,  5656,
  5659,  5659,  5666,  5668,  5674,  5674,  5678,  5678,  5682,  5682,
  5682,  5684,  5694,  5695,  5701,  5701,  5704,  5707,  5708,  5713,
  5715,  5719,  5721,  5725,  5727,  5730,  5736,  5740,  5745,  5750,
  5757,  5760,  5767,  5774,  5777,  5783,  5792,  5795,  5797,  5799,
  5801,  5803,  5805,  5810,  5820,  5825,  5830,  5832,  5836,  5838,
  5839,  5842,  5843,  5844,  5847,  5851,  5858,  5860,  5865,  5879,
  5879,  5884,  5889,  5895,  5896,  5899,  5900,  5904,  5911,  5918,
  5922,  5932,  5933,  5937,  5944,  5949,  5950,  5954,  5957,  5960,
  5962,  5966,  5967,  5968,  5969,  5973,  5974,  5978,  5980,  5984,
  5986,  5990,  5992,  5996,  6001,  6002,  6006,  6008,  6012,  6013,
  6017,  6023,  6028,  6033,  6037,  6039,  6043,  6045,  6050,  6053,
  6057,  6059,  6064,  6066,  6067,  6071,  6074,  6079,  6084,  6085,
  6088,  6089,  6093,  6096,  6098,  6099,  6104,  6109,  6114,  6118,
  6120,  6124,  6126,  6134,  6140,  6145,  6147,  6151,  6156,  6160,
  6162,  6166,  6168,  6169,  6172,  6173,  6178,  6178,  6181,  6193,
  6194,  6197,  6198,  6201,  6202,  6206,  6208,  6212,  6214,  6218,
  6220,  6224,  6226,  6231,  6233,  6237,  6240,  6244,  6246,  6247,
  6249,  6253,  6255,  6262,  6267,  6271,  6276,  6279,  6281,  6283,
  6288,  6290,  6294,  6295,  6299,  6302,  6304,  6306,  6308,  6310,
  6315,  6317,  6318,  6319,  6320,  6321,  6322,  6323,  6324,  6325,
  6329,  6331,  6332,  6333,  6335,  6336,  6337,  6338,  6346,  6348,
  6349,  6352,  6354,  6358,  6361,  6362,  6363,  6365,  6366,  6367,
  6368,  6370,  6371,  6373,  6374,  6376,  6377,  6378,  6379,  6381,
  6385,  6386,  6389,  6392,  6393,  6394,  6395,  6399,  6403,  6407,
  6411,  6416,  6419,  6420,  6424,  6426,  6430,  6435,  6436,  6437,
  6440,  6445,  6450,  6459,  6464,  6465,  6466,  6467,  6468,  6470,
  6472,  6474,  6476,  6479,  6482,  6486,  6487,  6491,  6492,  6496,
  6496,  6496,  6496,  6496,  6496,  6496,  6497,  6497,  6497,  6497,
  6497,  6497,  6497,  6500,  6500,  6500,  6500,  6500,  6500,  6500,
  6501,  6501,  6501,  6501,  6501,  6501,  6501,  6503,  6504,  6507,
  6516,  6517,  6522,  6522,  6528,  6529,  6534,  6535,  6544,  6545,
  6546,  6549,  6549,  6552,  6553,  6554,  6558,  6560,  6565,  6569,
  6573,  6584,  6587,  6593,  6602,  6611,  6612,  6614,  6623,  6624,
  6628,  6629,  6634,  6637,  6638,  6643,  6648,  6653,  6654,  6655,
  6656,  6659,  6661,  6664,  6665,  6669,  6673,  6676,  6678,  6680,
  6682,  6684,  6685,  6686,  6687,  6688,  6689,  6690,  6692,  6694,
  6696,  6698,  6700,  6702,  6704,  6706,  6709,  6710,  6712,  6713,
  6716,  6724,  6729,  6729,  6733,  6733,  6738,  6738,  6742,  6742,
  6746,  6752,  6752,  6755,  6755,  6761,  6767,  6769,  6770,  6773,
  6775,  6778,  6779,  6781,  6788,  6798,  6800,  6807,  6809,  6810,
  6811,  6812,  6813,  6898,  6910,  6911,  6914,  6916,  6917,  6918,
  6921,  6923,  6924,  6927,  6948,  7033,  7035,  7037,  7039,  7043,
  7048,  7050,  7052,  7054,  7058,  7061,  7066,  7071,  7075,  7084,
  7085,  7089,  7100,  7104,  7108,  7123,  7123,  7126,  7130,  7135,
  7139,  7140,  7141,  7144,  7147,  7152,  7153,  7157,  7160,  7165,
  7169,  7174,  7178,  7183,  7187,  7190,  7194,  7197,  7202,  7206,
  7217,  7223,  7223,  7224,  7225,  7232,  7241,  7241,  7242,  7244,
  7245,  7246,  7247,  7248,  7249,  7250,  7251,  7252,  7253,  7254,
  7255,  7256,  7257,  7258,  7259,  7260,  7261,  7262,  7263,  7264,
  7265,  7266,  7267,  7268,  7269,  7270,  7271,  7272,  7273,  7274,
  7275,  7276,  7277,  7278,  7279,  7280,  7281,  7282,  7283,  7284,
  7285,  7286,  7287,  7288,  7289,  7290,  7291,  7292,  7293,  7294,
  7295,  7296,  7297,  7298,  7299,  7300,  7301,  7302,  7303,  7304,
  7305,  7306,  7307,  7308,  7309,  7310,  7311,  7312,  7313,  7314,
  7315,  7316,  7317,  7318,  7319,  7320,  7321,  7322,  7323,  7324
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","NAME","UMINUS",
"COMMA","OR","AND","USING","MATCHES","POWER","LESS_THAN","GREATER_THAN","EQUAL",
"GREATER_THAN_EQ","LESS_THAN_EQ","NOT_EQUAL","MINUS","PLUS","DIVIDE","MULTIPLY",
"MOD","COMMAND","NUMBER_VALUE","CHAR_VALUE","INT_VALUE","NAMED_GEN","CLINE",
"SQLLINE","KW_CSTART","KW_CEND","LOCAL_FUNCTION","EVERY_ROW","DOUBLE_PRECISION",
"COUNT_MULTIPLY","NEWFORMATSHARED","WAIT_FOR_KEY","AT_TERMINATION_CALL","TO_MAIN_CAPTION",
"CLEARSTAT","TO_MENUITEM","ID_TO_INT","TO_STATUSBOX","ASCII_HEIGHT_ALL","ASCII_WIDTH_ALL",
"IMPORT_DATATYPE","UP_BY","PAGE_TRAILER_SIZE","PAGE_HEADER_SIZE","FIRST_PAGE_HEADER_SIZE",
"BYTES_USE_AS_IMAGE","BYTES_USE_AS_ASCII","DOWN_BY","CLOSE_STATUSBOX","ADD_CONSTRAINT",
"DROP_CONSTRAINT","MODIFY_NEXT_SIZE","LOCK_MODE_PAGE","LOCK_MODE_ROW","TO_PIPE",
"TO_PRINTER","STATUSBOX","CONNECT_TO","FORMHANDLER_INPUT","UNITS_YEAR","UNITS_MONTH",
"UNITS_DAY","UNITS_HOUR","UNITS_MINUTE","UNITS_SECOND","NO_NEW_LINES","FIELDTOWIDGET",
"WITH_HOLD","SHOW_MENU","CWIS","CREATE_IDX","FORM_IS_COMPILED","PDF_REPORT",
"IMPORT_FUNCTION","PROMPT_MANY","POINTS","MM","INCHES","PREPEND","MEMBER_OF",
"MEMBER_FUNCTION","APPEND","TEMPLATE","END_TEMPLATE","SQLSICS","CREATE_SCHEMA",
"SQLSIRR","UPDATESTATS_T","SQLSICR","WHENEVER_SQLSUCCESS","WHENEVER_SQLWARNING",
"START_EXTERN","WHENEVER_ANY_ERROR","WHENEVER_NOT_FOUND","CONTINUE_CONSTRUCT",
"FOUNCONSTR","SQLSIDR","WHENEVER_SQLERROR","CREATE_TEMP_TABLE","CURRENT_WINDOW_IS",
"FIRST_PAGE_HEADER","ORDER_EXTERNAL_BY","SCROLL_CURSOR_FOR","SCROLL_CURSOR",
"SQL_INTERRUPT_OFF","STOP_ALL_EXTERNAL","WITH_CHECK_OPTION","WITH_GRANT_OPTION",
"SQLSLMNW","ADDCONSTUNIQ","CONTINUE_DISPLAY","CONTINUE_FOREACH","OUTPUT_TO_REPORT",
"SQL_INTERRUPT_ON","WHENEVER_SUCCESS","WHENEVER_WARNING","WHERE_CURRENT_OF",
"WITHOUT_DEFAULTS","FOCONSTR","SCALED_BY","CONTINUE_PROMPT","PDF_FUNCTION","DEFER_INTERRUPT",
"DISPLAY_BY_NAME","NOT_NULL_UNIQUE","SKIP_TO_TOP","TOP_OF_PAGE","SKIP_TO","SKIP_BY",
"WITHOUT_WAITING","BEFCONSTRUCT","SQLSLMW","WHENEVER_ERROR_CONTINUE","WHENEVER_ERROR",
"AFTCONSTRUCT","ALL_PRIVILEGES","CLOSE_DATABASE","CONTINUE_INPUT","CONTINUE_WHILE",
"CREATE_SYNONYM","DROP_TABLE","EXIT_CONSTRUCT","INEXCLUSIVE","REPORT_TO_PRINTER",
"REPORT_TO_PIPE","SET_SESSION_TO","UPDATESTATS","WITHOUT_HEAD","CLEARSCR","WITH_B_LOG",
"AUTHORIZATION","BOTTOM_MARGIN","CLOSE_SESSION","CONTINUE_CASE","CONTINUE_MENU",
"DISPLAY_ARRAY","END_CONSTRUCT","FIELD_TOUCHED","FINISH_REPORT","INFACC","INPUT_NO_WRAP",
"LOCKMODEPAGE","SETPMOFF","UNCONSTRAINED","PAGE_TRAILER","SETPMON","BEFGROUP",
"CLOSE_WINDOW","COMMENT_LINE","CONTINUE_FOR","CREATE_DB","CREATE_TABLE","DEFAULT_NULL",
"DELETE_USING","DISPLAY_FORM","END_FUNCTION","EXIT_DISPLAY","EXIT_FOREACH","EXIT_PROGRAM",
"INFCOLS","LOCKMODEROW","ON_EVERY_ROW","OPEN_SESSION","RIGHT_MARGIN","SELECT_USING",
"START_REPORT","UNLOCK_TABLE","UPDATE_USING","ACL_BUILTIN","AFTGROUP","INFIDX",
"INFSTAT","LEFT_MARGIN","PAGE_HEADER","ROLLBACK_W","SET_SESSION","SQLSEOFF",
"WITH_A_LOG","ALTER_TABLE","BEFDISP","BEFORE_MENU","CREATE_VIEW","DEFINE_TYPE",
"DELETE_FROM","END_DISPLAY","END_REPORT","END_FOREACH","END_FOR","END_GLOBALS",
"EXIT_PROMPT","EXTENT_SIZE","FOREIGN_KEY","HIDE_OPTION","HIDE_WINDOW","INSERT_INTO",
"IS_NOT_NULL","MOVE_WINDOW","NEXT_OPTION","NOT_MATCHES","ON_LAST_ROW","OPEN_WINDOW",
"OPEN_STATUSBOX","PAGE_LENGTH","PAGE_WIDTH","PRIMARY_KEY","PROMPT_LINE","RECORD_LIKE",
"ROLLFORWARD","SETBL","SHOW_OPTION","SHOW_WINDOW","SQLSEON","TO_DATABASE","USE_SESSION",
"WITH_NO_LOG","AFTDISP","BEFFIELD","INSHARE","UNLOCKTAB","AFTFIELD","ATTRIBUTES",
"BEFINP","BEGIN_WORK","CLEARWIN","CLOSE_FORM","DEFER_QUIT","DESCENDING","DROP_INDEX",
"END_PROMPT","END_RECORD","ERROR_LINE","EXIT_INPUT","EXIT_WHILE","FOR_UPDATE_OF",
"FOR_UPDATE","GET_FLDBUF","INITIALIZE","INPUT_WRAP","LOCK_TABLE","MSG_LINE",
"NOT_EXISTS","ON_ANY_KEY","REFERENCES","RENCOL","SET_CURSOR","SMALLFLOAT","SQLSUCCESS",
"TOP_MARGIN","WITH_ARRAY","ACCEPTKEY","ACCEPT","AFTINP","CLEARFORM","COMMIT_W",
"NEXTPAGE","PREVPAGE","CTRL_KEY","INFTABS","NEXTFIELD","NEXTFORM","RENTAB","ASCENDING",
"ASSOCIATE","CHARACTER","CONSTRUCT","DELIMITER","DOWNSHIFT","DROP_VIEW","END_INPUT",
"END_WHILE","EXCLUSIVE","EXIT_CASE","EXIT_MENU","FORM_LINE","INTERRUPT","INTO_TEMP",
"INVISIBLE","IN_MEMORY","LINKED_TO","LOAD_FROM","LOCKTAB","MENU_LINE","OPEN_FORM",
"OTHERWISE","PRECISION","PROCEDURE","REPORT_TO","RETURNING","UNDERLINE","UNLOAD_TO",
"BEFROW","UNLOAD_T","VARIABLE","ABSOLUTE","AFTROW","BUFFERED","CONSTANT","CONST",
"CONTINUE","DATABASE","DATETIME","DEFAULTS","DISTINCT","END_CASE","END_MAIN",
"END_MENU","END_TYPE","EXIT_FOR","EXTERNAL","FRACTION","FUNCTION","GROUP_BY",
"INTERVAL","KWMESSAGE","NOT_LIKE","NOT_NULL","PASSWORD","PREVIOUS","READONLY",
"REGISTER","RELATIVE","RESOURCE","SMALLINT","VALIDATE","WHENEVER","WITH_LOG",
"WORDWRAP","BY_NAME","IN_FILE","IS_NULL","AVERAGE","BETWEEN","CAPTION","CLIPPED",
"CLOSE_BRACKET","COLUMNS","COMMENT","CONNECT","CURRENT","DBYNAME","DECIMAL",
"DECLARE","DEFAULT","DISPLAY","ENDCODE","EXECUTE","FOREACH","FOREIGN","GLOBALS",
"INFIELD","INTEGER","KWWINDOW","MAGENTA","NUMERIC","OPTIONS","PERCENT","PREPARE",
"PROGRAM","RECOVER","REVERSE","SECTION","SESSION","SYNONYM","THRU","TRAILER",
"UPSHIFT","VARCHAR","WAITING","CLOSE_SHEV","CLOSE_SQUARE","KW_FALSE","NOT_IN",
"ONKEY","OPEN_BRACKET","BORDER","BOTTOM","COLUMN","COMMIT","CREATE","CURSOR",
"DEFINE","DELETE","DOUBLE","END_IF","ESCAPE","EXISTS","EXTEND","EXTENT","FINISH",
"FORMAT","HAVING","HEADER","INSERT","LOCATE","MARGIN","MEMORY","MINUTE","MODIFY",
"NORMAL","EQUAL_EQUAL","OPEN_SHEV","OPEN_SQUARE","OPTION","OUTPUT","PROMPT",
"PUBLIC","RECORD","REPORT","RETURN","REVOKE","SCHEMA","SCROLL","SECOND","SELECT",
"SERIAL","SETL","SHARED","SPACES","UNIQUE","UNLOCK","UPDATE","VALUES","YELLOW",
"AFTER","KWLINE","KW_NULL","KW_TRUE","SINGLE_KEY","ALTER","ARRAY","ASCII","AUDIT",
"BLACK","BLINK","CHECK","CLEAR","CLOSE","CODE_C","COUNT","DEFER","ERROR","EVERY",
"FETCH","FIRST","FLOAT","FLUSH","FOUND","GRANT","GREEN","GROUP","INDEX","KWFORM",
"LABEL","LOCAL","MONEY","MONTH","ORDER","OUTER","PAUSE","PRINT_IMAGE","PRINT_FILE",
"PRINT","RIGHT","SEMICOLON","SLEEP","TUPLE","UNION","WHERE","WHILE","WHITE",
"CCODE","ANSI","BLUE","BOLD","BYTE","FCALL","CASE","CHAR","CYAN","DATE","DESC",
"DOWN","TAB","DROP","ELSE","EXEC","EXIT","FREE","FROM","GOTO","HELP_FILE","LANG_FILE",
"HELP","HIDE","HOUR","INTO","LAST","LEFT","LIKE","MAIN","MENU","MODE","MOVE",
"NEED","NEXT","NOCR","OPEN","QUIT","REAL","ROWS","SHOW","SIZE","SKIP","SOME",
"STEP","STOP","TEMP","TEXT","THEN","USER","VIEW","WAIT","WHEN","WITH","WORK",
"YEAR","KW_IS","XSET","ADD","ALL","ANY","ASC","AVG","COLON","DAY","DBA","DEC",
"DIM","FKEY","FOR","KEY","KWNO","LET","LOG","XMAX","XMIN","NOT","PAD","PUT",
"RED","ROW","RUN","SQL","SUM","TOP","USE","ATSIGN","AS_TIFF","AS_GIF","AS_PNG",
"AS_JPEG","AS","AT","BY","DOT","GO","IF","IN","OF","ON","TO","UP","FONT_NAME",
"FONT_SIZE","PAPER_SIZE_IS_LETTER","PAPER_SIZE_IS_LEGAL","PAPER_SIZE_IS_A5",
"PAPER_SIZE_IS_A4","PAPER_SIZE_IS_LETTER_L","PAPER_SIZE_IS_LEGAL_L","PAPER_SIZE_IS_A5_L",
"PAPER_SIZE_IS_A4_L","FORMHANDLER","END_FORMHANDLER","BEFORE_EVENT","BEFORE_OPEN_FORM",
"AFTER_EVENT","BEFORE_CLOSE_FORM","BEFORE_ANY","AFTER_ANY","MENUHANDLER","END_MENUHANDLER",
"BEFORE_SHOW_MENU","DISABLE_PROGRAM","DISABLE_ALL","BUTTONS","CHECK_MENUITEM",
"DISABLE_FORM","DISABLE_MENUITEMS","DISABLE","ENABLE_FORM","ENABLE_MENUITEMS",
"ENABLE","KWFIELD","ICON","MESSAGEBOX","TO_DEFAULTS","UNCHECK_MENUITEM","BEFORE",
"INPUT","END","INT_TO_ID","pause_screen_on_cmd","pause_screen_off_cmd","start_rpc_cmd",
"stop_rpc_cmd","valid_port","remote_func_list","remote_func","arr_expr","arr_next_math",
"arr_int_sign","opt_attributes","attributes_def","@1","attribs_sec","attribute",
"win_attributes","win_attributes_def","@2","wattribs_sec","wattribute","call_cmd",
"call_ext","@3","@4","@5","@6","@7","@8","@9","@10","@11","@12","@13","@14",
"@15","opt_return","opt_return_remote","opt_func_call_args","func_call_args",
"func_arg","remote_host_name","remote_func_name","case_cmd","@16","@17","when_unit",
"when_unit_expr","end_case_command","op_otherwise_command","@18","op_otherwise_command_expr",
"@19","when_command","@20","when_command_expr","@21","close_cmd","code_cmd",
"emb_code","sql_code","sql_code_part","c_code","c_code_part","comment_cmd","construct_cmd",
"@22","@23","constr_rest","end_constr","constr_col_list","constr_col","constr_extra_commands",
"constr_extra_command","@24","@25","@26","@27","@28","bef_c_field_list","aft_c_field_list",
"interval_expr","defer_cmd","define_section","define_multiple","define_set",
"@29","def_part","define_ident","@30","def_part2","@31","constant_value","var_def_name",
"var_def_list","op_char","array_variable","@32","@33","assoc_open_bracket","assoc_close_bracket",
"number_arr_assoc","number_arr_list","number_value_arr","record_variable","@34",
"@35","@36","link_to_pk_list","link_to_pk","dtype_ident","dtype2","@37","dtype",
"like_var","tab_name","col_name","datetime_qual","interval_qual","dtime_start",
"@38","dtime_val","dtime_end","@39","opt_frac","opt_unit_size","dtfrac","int_start",
"@40","int_start_unit","int_end","op_equal","dim_section","@41","dim_dtype",
"dim_like_var","dim_array_variable","@42","@43","dim_record_variable","@44",
"@45","dim_def_part","dim_def_part2","dim_var_def_list","dim_var_def_name","opt_at",
"display_b_n_cmd","display_cmd","display_form_cmd","display_array_cmd","@46",
"@47","opt_scroll","display_attr","disp_rest","disp_field_commands","disp_field_command",
"@48","@49","@50","error_cmd","exit_prog_cmd","ext_cmd","continue_cmd","fgl_expr_c",
"fgl_next","op_fgl_expr_ret_list","fgl_expr_ret","fgl_expr_ret_list","fgl_expr_list",
"fgl_expr_concat","fgl_expr","int_sign","boolean_expr","initial_expr","literal_expr",
"report_only_expr","@51","and_or_expr","inexpr_list","in_expr","null_expr","string_match_expr",
"clip_expr","using_expr","math_expr","comparison_expr","reset_cnt","function_call_expr2",
"@52","@53","@54","@55","function_callb","@56","@57","@58","@59","@60","@61",
"@62","@63","function_call_expr","builtin_expr","builtin_funcs","pdf_expr","foreach_cmd",
"@64","@65","@66","formhandler_def","@67","@68","op_input_section","op_bef_ev_list",
"bef_ev_list","bef_ev","@69","@70","op_aft_ev_list","aft_ev_list","aft_ev","@71",
"@72","input_section","input_sub_section","in_variable_list","in_id_list","in_bn_variable_list",
"field_ops","field_op","@73","@74","@75","@76","@77","for_cmd","@78","@79","for_step",
"free_cmd","line_no","file_name","a_number","coords","display_coords","field_name",
"cursor_name","fetch_cursor_name","win_name","open_win_name","form_name","open_form_name",
"opt_help_no","identifier","ident_or_var","ident_p2","var_or_string","setident",
"unsetident","field_name2","cvariable","real_number","reserved_word","goto_cmd",
"check_menu_cmd","menu_item_list","menu_item","uncheck_menu_cmd","disable_cmd",
"enable_cmd","msg_box_cmd","@80","op_disable_msg","gm_disable_msg","op_returning_msg",
"gm_returning_msg","op_caption","gm_caption","op_icon","gm_icon","op_buttons",
"gm_buttons","op_def_but","if_cmd","@81","op_else","@82","import_m","op_import",
"init_cmd","@83","init_tab_list","init_tab","end_input","opt_defs","field_commands",
"field_command","@84","@85","@86","@87","@88","@89","@90","@91","@92","a_ins_or_delete_row",
"a_ins_or_delete","b_ins_or_delete_row","b_ins_or_delete","bef_field_list","aft_field_list",
"next_field_cmd","next_form_cmd","next_field","input_cmd","@93","inp_rest","@94",
"scroll_cmd","up_or_down","op_help","on_key_command","@95","key_val","@96","accept_key",
"single_key_val","@97","key_do","key_value_list","key_value","@98","key_value_1",
"label_cmd","let_cmd","@99","@100","op_expr_null","linked_cmd","linked_del_cmd",
"linked_upd_cmd","locate_cmd","module","@101","@102","func_main_def","func_or_main2",
"at_term_cmd","func_or_main","op_code","ldeffunction","func_def","@103","@104",
"@105","@106","end_func_command","main_def","@107","@108","return_cmd","op_fgl_expr_list",
"db_section","globals_section","actual_globals_section","xglobals_entry","globals_entry",
"@109","glob_section","mem_func_def","@110","@111","@112","menu_def","@113",
"@114","menu_handler_elements","menu_handler_element","@115","@116","menu_cmd",
"@117","end_menu_command","menu_block_command","@118","@119","@120","menu_commands",
"opt_key","menu_opt_name","menu_optional_desc","next_option_cmd","show_option_cmd",
"hide_option_cmd","opt_name","opt_name_list","menu_title","message_cmd","msg_next",
"gui_message","msg_start","@121","op_msg_wait","msg_wait","variable","var_int",
"varsetidentdot","var","assoc_var_read","assoc_var_write","assoc_sub","dot_part_var",
"array_r_variable","arr_subscripts","num_list","num_list_element","let_variable",
"let_var","let_var_dot","let_array_r_variable","op_param_var_list","fparam_var_list",
"ibind_var_list","func_def_var","ibind_var","obind_var_list","obind_var","obind_var_let_list",
"obind_let_var","use_arr_var","obind_var_list_ord","obind_var_ord","optional_asc_desc",
"array_r_varid","init_bind_var_list","init_bind_var","open_window_cmd","op_at_statusbox",
"op_size_statusbox","open_statusbox_cmd","formhandler_name","open_form_cmd",
"open_form_rest","open_form_gui","op_at_gui","op_like_gui","op_absolute","open_session_cmd",
"open_cursor_cmd","user_details","op_disable","connect_cmd","op_connect_as",
"con_user_details","options_cmd","opt_options","opt_allopts","prepare_cmd","var_or_char",
"execute_cmd","stmt_id","prompt_cmd","@122","gui_prompt_cmd","opt_char","prompt_key_sec",
"prompt_key_clause","on_key_command_prompt","@123","prompt_title","put_cmd",
"@124","put_from","put_val_list","put_val","start_cmd","rout","rep_name","op_values",
"output_cmd","@125","@126","@127","finish_cmd","report_section","format_section",
"format_actions","format_action","@128","@129","@130","@131","@132","@133","@134",
"report_cmd","need_command","@135","op_lines","skip_command","@136","opt_rep_expr_list",
"xrep_expr_list","xxrep_expr_list","opt_print_at","print_command","print_file_command",
"print_img_command","opt_scaling","img_types","blob_var","opt_semi","rep_expr_list",
"rep_expr","rep_agg","op_output_section","output_commands","output_command",
"pdf_output_commands","nval","nval_number","pdf_op_output_section","pdf_output_command",
"op_rep_order_by","report_def","@137","@138","@139","@140","@141","rep_where",
"pause_command","pause_msg","pdf_report_def","@142","@143","@144","@145","@146",
"pdf_report_section","pdf_functions","@147","@148","@149","op_wordwrap","run_cmd",
"drops_cmd","drops_c","create_cmd","create_c_1","@150","@151","@152","@153",
"op_no_log","idx_column_list","idx_column","table_element_list","table_element",
"upd_stats_cmd","set_cmd","op_conn_id","op_fgl_expr","sleep_cmd","update_statement",
"where_upd","set_clause_list","special_upd_clause","upd_columns","upd_column_name",
"col_1","upd_col_list","upd_val_list","upd_val","rollback_statement","insert_statement",
"@154","ins_2","@155","op_insert_column_list","insert_column_list","insert_value_list",
"insert_value","fetch_statement","@156","@157","fetch_part","opt_into_fetch_part",
"@158","opt_foreach_into_fetch_part","@159","fetch_place","delete_statement_position",
"delete_statement_search","order_by_clause","sort_specification_list","sort_specification",
"sort_spec","op_asc_desc","begin_statement","commit_statement","op_exclusive",
"set_database_cmd","sql_cmd","@160","sql_commands","privilege_definition","op_with_grant_option",
"privileges","action_list","action","op_grant_column_list","grant_column_list",
"grantee_list","grantee","view_definition","op_view_column_list","view_column_list",
"op_with_check_option","check_constraint_definition","referential_constraint_definition",
"references_specification","references_columns","referenced_table_and_columns",
"references_column_list","unique_constraint_definition","unique_column_list",
"table_constraint_definition","default_clause","column_definiton","op_default_clause",
"op_column_constraint_list","column_constraint","schema","schema_authorization_clause",
"schema_authorization_identifier","schema_element_list","schema_element","having_clause",
"group_by_clause","column_specification_list","where_clause","from_clause","table_reference_list",
"table_reference","tname","tname_list","table_expression","op_where_clause",
"op_group_by_clause","op_having_clause","search_condition","boolean_term","boolean_factor",
"boolean_primary","exists_predicate","quantified_predicate","quantifier","all",
"some","op_escape","pattern","escape_character","in_predicate","in_value_list",
"op_not","comparison_predicate","comp_op","predicate","op_all","data_type","char_string_type",
"exact_numeric_type","op_scale","approx_numeric_type","length","precision","scale",
"table_name","db_name","authorization_identifier","table_identifier","col_arr",
"column_name","correlation_name","literal","curr_v_clause","curr_clause","cur_part",
"cur_v_part","s_curr_v","e_curr_v","s_curr","e_curr","dbase_name","flush_cmd",
"declare_cmd","@161","@162","@163","@164","curs_forupdate","cur_update_list",
"colident","cursor_specification_all","cursor_specification_sel","select_statement_full",
"select_statement","@165","@166","in_select_statement","select_statement2","select_statement21",
"sel_p2","tmp_tabname","opt_into_sel","query_specification","subquery","op_ad",
"select_list","value_expression_pls","column_specification","value_expression",
"value_expr_list","value_specification","unload_cmd","load_cmd","opt_delim",
"char_or_var","opt_col_list","col_list","simple_column_name","ufile","opt_use",
"conn_id","misc_sql","rename_stmt","rentabname","rencolname","unlock_stmt","lock_stmt",
"share_or_exclusive","units_qual","var_ident","var2","var3","aft_dot","var_ident_ibind",
"whenever_cmd","when_do","label_goto","function_name_when","while_cmd","@167",
"@168","op_clr_fields","op_to_defs","clear_cmd","fld_list","current_win_cmd",
"window_type","show_cmd","op_mnfile","menu_name","menu_handler","hide_cmd","move_cmd",
"NAMED","commands","all_commands","command1","commands_all","@169","commands_all1", NULL
};
#endif

static const short yyr1[] = {     0,
   637,   638,   639,   640,   641,   641,   642,   642,   643,   644,
   644,   644,   644,   644,   645,   645,   645,   645,   645,   646,
   646,   647,   647,   649,   648,   648,   650,   650,   651,   651,
   651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
   651,   651,   651,   651,   652,   652,   654,   653,   655,   655,
   656,   656,   656,   656,   656,   656,   656,   656,   656,   657,
   658,   659,   658,   658,   658,   658,   658,   660,   661,   658,
   662,   663,   664,   658,   665,   666,   658,   667,   668,   658,
   669,   670,   671,   658,   672,   672,   673,   673,   673,   674,
   674,   675,   675,   676,   677,   677,   678,   678,   680,   679,
   681,   679,   682,   682,   683,   683,   684,   685,   686,   685,
   687,   688,   687,   690,   689,   692,   691,   693,   693,   693,
   693,   693,   693,   694,   695,   695,   696,   696,   697,   698,
   698,   699,   700,   702,   703,   701,   704,   704,   705,   705,
   706,   706,   707,   707,   707,   708,   708,   710,   709,   711,
   709,   712,   709,   713,   709,   714,   709,   715,   715,   716,
   716,   717,   717,   717,   717,   717,   717,   718,   718,   719,
   719,   720,   720,   722,   721,   721,   721,   723,   723,   725,
   724,   726,   726,   726,   726,   727,   726,   728,   728,   728,
   728,   729,   730,   730,   731,   731,   733,   732,   734,   732,
   735,   735,   736,   736,   737,   738,   738,   738,   739,   741,
   740,   742,   740,   743,   740,   744,   744,   745,   746,   748,
   747,   749,   749,   749,   749,   749,   749,   749,   749,   749,
   749,   749,   749,   749,   749,   749,   749,   749,   749,   749,
   749,   749,   749,   749,   749,   749,   749,   749,   749,   750,
   751,   752,   753,   753,   754,   756,   755,   757,   757,   757,
   757,   757,   757,   757,   759,   758,   760,   760,   761,   761,
   762,   764,   763,   765,   765,   765,   765,   765,   765,   765,
   766,   767,   767,   769,   768,   770,   770,   770,   770,   770,
   770,   770,   770,   770,   770,   770,   770,   770,   770,   770,
   770,   770,   770,   770,   770,   770,   770,   770,   771,   773,
   772,   774,   772,   776,   775,   777,   775,   778,   778,   779,
   780,   780,   781,   782,   782,   782,   782,   782,   782,   782,
   782,   783,   784,   785,   787,   788,   786,   789,   789,   790,
   791,   791,   792,   792,   794,   793,   795,   793,   796,   793,
   797,   797,   798,   798,   799,   799,   799,   799,   799,   799,
   799,   799,   799,   800,   800,   800,   800,   800,   800,   800,
   800,   801,   801,   801,   801,   801,   801,   801,   801,   801,
   801,   802,   802,   802,   802,   802,   802,   802,   802,   802,
   802,   803,   803,   804,   804,   805,   805,   806,   806,   807,
   807,   808,   809,   809,   810,   810,   810,   810,   810,   810,
   811,   811,   812,   812,   812,   812,   812,   812,   812,   813,
   813,   813,   814,   813,   815,   815,   816,   816,   817,   817,
   817,   817,   818,   818,   819,   819,   819,   819,   820,   821,
   822,   822,   822,   822,   822,   822,   823,   823,   823,   823,
   823,   823,   823,   824,   826,   827,   825,   828,   829,   825,
   831,   832,   830,   833,   834,   830,   835,   836,   830,   837,
   838,   830,   839,   839,   839,   839,   839,   839,   839,   839,
   840,   840,   841,   841,   841,   841,   842,   842,   842,   844,
   845,   846,   843,   848,   849,   847,   850,   850,   851,   851,
   852,   852,   854,   853,   855,   853,   856,   856,   857,   857,
   859,   858,   860,   858,   861,   862,   862,   862,   863,   863,
   864,   864,   865,   865,   866,   866,   868,   867,   869,   867,
   870,   867,   871,   867,   872,   867,   874,   875,   873,   876,
   876,   877,   878,   878,   878,   878,   878,   878,   879,   879,
   880,   881,   882,   883,   883,   883,   883,   883,   883,   883,
   883,   884,   885,   886,   887,   888,   889,   890,   890,   891,
   891,   892,   893,   893,   894,   894,   895,   896,   897,   897,
   897,   897,   897,   897,   898,   899,   899,   900,   900,   900,
   900,   900,   900,   900,   900,   900,   900,   900,   900,   900,
   900,   900,   900,   900,   900,   900,   900,   900,   900,   900,
   900,   900,   900,   900,   900,   900,   900,   900,   900,   900,
   900,   900,   900,   900,   900,   900,   900,   901,   902,   903,
   903,   904,   905,   906,   906,   906,   907,   907,   907,   909,
   908,   910,   910,   911,   911,   912,   912,   913,   914,   914,
   915,   916,   916,   917,   918,   918,   919,   920,   920,   922,
   921,   923,   924,   923,   925,   926,   926,   928,   927,   927,
   929,   929,   930,   930,   931,   931,   932,   932,   933,   933,
   935,   934,   936,   934,   937,   934,   938,   934,   939,   934,
   940,   934,   941,   934,   942,   934,   943,   934,   944,   944,
   945,   945,   946,   946,   947,   947,   948,   948,   949,   949,
   950,   951,   952,   952,   952,   954,   953,   955,   955,   956,
   955,   957,   958,   958,   958,   958,   959,   959,   961,   960,
   960,   963,   962,   964,   966,   965,   967,   967,   968,   968,
   970,   969,   971,   971,   971,   971,   971,   971,   971,   971,
   971,   971,   971,   971,   971,   971,   971,   972,   972,   974,
   975,   973,   976,   976,   977,   978,   979,   980,   980,   982,
   983,   981,   984,   984,   985,   985,   986,   987,   987,   987,
   987,   987,   987,   987,   987,   987,   987,   987,   988,   988,
   988,   989,   989,   991,   992,   993,   994,   990,   995,   997,
   998,   996,   999,  1000,  1000,  1001,  1002,  1002,  1003,  1003,
  1004,  1004,  1004,  1004,  1006,  1005,  1007,  1007,  1009,  1010,
  1011,  1008,  1013,  1014,  1012,  1015,  1015,  1017,  1016,  1018,
  1016,  1020,  1019,  1021,  1023,  1022,  1024,  1022,  1025,  1022,
  1026,  1026,  1027,  1027,  1028,  1028,  1029,  1029,  1029,  1030,
  1031,  1032,  1033,  1033,  1033,  1034,  1034,  1035,  1035,  1036,
  1037,  1037,  1037,  1037,  1038,  1038,  1038,  1038,  1038,  1040,
  1039,  1041,  1041,  1042,  1043,  1044,  1044,  1045,  1046,  1046,
  1046,  1046,  1046,  1047,  1048,  1049,  1049,  1050,  1050,  1051,
  1052,  1052,  1053,  1053,  1054,  1055,  1056,  1056,  1056,  1056,
  1056,  1057,  1057,  1058,  1059,  1059,  1060,  1060,  1061,  1061,
  1062,  1062,  1063,  1063,  1063,  1063,  1063,  1064,  1064,  1065,
  1066,  1066,  1067,  1068,  1069,  1069,  1070,  1071,  1071,  1071,
  1072,  1073,  1073,  1074,  1074,  1075,  1076,  1076,  1077,  1077,
  1078,  1079,  1080,  1081,  1081,  1082,  1083,  1083,  1084,  1084,
  1085,  1085,  1086,  1087,  1087,  1088,  1088,  1088,  1088,  1089,
  1089,  1089,  1090,  1091,  1091,  1092,  1092,  1092,  1093,  1094,
  1094,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
  1095,  1095,  1095,  1096,  1097,  1097,  1098,  1098,  1099,  1101,
  1100,  1102,  1103,  1103,  1104,  1104,  1105,  1105,  1107,  1106,
  1108,  1110,  1109,  1111,  1111,  1112,  1112,  1113,  1113,  1114,
  1114,  1114,  1114,  1115,  1115,  1116,  1117,  1117,  1119,  1120,
  1121,  1118,  1122,  1123,  1124,  1124,  1125,  1125,  1127,  1126,
  1128,  1126,  1129,  1126,  1130,  1126,  1131,  1126,  1132,  1126,
  1133,  1126,  1134,  1134,  1134,  1134,  1134,  1134,  1136,  1135,
  1137,  1137,  1139,  1138,  1138,  1138,  1138,  1138,  1140,  1140,
  1141,  1141,  1142,  1143,  1143,  1144,  1145,  1146,  1147,  1147,
  1147,  1148,  1148,  1148,  1148,  1149,  1150,  1150,  1151,  1151,
  1152,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1154,  1154,
  1155,  1155,  1156,  1156,  1156,  1156,  1156,  1156,  1156,  1156,
  1156,  1156,  1157,  1157,  1158,  1158,  1158,  1158,  1159,  1159,
  1160,  1160,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,
  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,
  1161,  1161,  1161,  1161,  1161,  1161,  1162,  1162,  1162,  1164,
  1165,  1166,  1167,  1168,  1163,  1169,  1169,  1170,  1171,  1171,
  1173,  1174,  1175,  1176,  1177,  1172,  1178,  1180,  1181,  1182,
  1179,  1183,  1183,  1183,  1183,  1184,  1184,  1184,  1184,  1184,
  1185,  1186,  1186,  1186,  1187,  1188,  1189,  1190,  1188,  1191,
  1192,  1188,  1193,  1193,  1194,  1194,  1195,  1195,  1195,  1196,
  1196,  1197,  1197,  1198,  1198,  1199,  1199,  1199,  1199,  1199,
  1199,  1199,  1199,  1199,  1199,  1199,  1200,  1200,  1201,  1201,
  1202,  1203,  1204,  1204,  1204,  1205,  1205,  1205,  1206,  1206,
  1207,  1207,  1208,  1209,  1210,  1210,  1211,  1211,  1212,  1212,
  1212,  1213,  1215,  1214,  1217,  1216,  1216,  1218,  1218,  1219,
  1219,  1220,  1220,  1221,  1221,  1223,  1224,  1222,  1225,  1225,
  1226,  1227,  1226,  1228,  1229,  1228,  1230,  1230,  1230,  1230,
  1230,  1230,  1230,  1231,  1232,  1233,  1234,  1234,  1235,  1236,
  1236,  1237,  1237,  1237,  1238,  1239,  1240,  1240,  1241,  1243,
  1242,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
  1244,  1244,  1244,  1244,  1245,  1246,  1246,  1247,  1247,  1248,
  1248,  1249,  1249,  1249,  1249,  1250,  1250,  1251,  1251,  1252,
  1252,  1253,  1253,  1254,  1255,  1255,  1256,  1256,  1257,  1257,
  1258,  1259,  1260,  1261,  1262,  1262,  1263,  1263,  1264,  1264,
  1265,  1265,  1266,  1266,  1266,  1267,  1267,  1268,  1269,  1269,
  1270,  1270,  1271,  1271,  1271,  1271,  1272,  1273,  1274,  1275,
  1275,  1276,  1276,  1277,  1278,  1279,  1279,  1280,  1281,  1282,
  1282,  1283,  1283,  1283,  1284,  1284,  1285,  1285,  1286,  1287,
  1287,  1288,  1288,  1289,  1289,  1290,  1290,  1291,  1291,  1292,
  1292,  1293,  1293,  1294,  1294,  1295,  1295,  1296,  1296,  1296,
  1297,  1298,  1298,  1299,  1300,  1301,  1302,  1302,  1302,  1302,
  1303,  1303,  1304,  1304,  1305,  1305,  1305,  1305,  1305,  1305,
  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,
  1307,  1307,  1307,  1307,  1308,  1308,  1308,  1308,  1309,  1309,
  1309,  1310,  1310,  1311,  1311,  1311,  1311,  1311,  1311,  1311,
  1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,  1311,
  1312,  1312,  1313,  1313,  1313,  1313,  1313,  1314,  1315,  1316,
  1317,  1317,  1317,  1317,  1318,  1319,  1320,  1321,  1321,  1321,
  1322,  1322,  1322,  1323,  1324,  1324,  1324,  1324,  1324,  1324,
  1324,  1324,  1324,  1325,  1326,  1327,  1327,  1328,  1328,  1329,
  1329,  1329,  1329,  1329,  1329,  1329,  1330,  1330,  1330,  1330,
  1330,  1330,  1330,  1331,  1331,  1331,  1331,  1331,  1331,  1331,
  1332,  1332,  1332,  1332,  1332,  1332,  1332,  1333,  1333,  1334,
  1336,  1335,  1337,  1335,  1338,  1335,  1339,  1335,  1340,  1340,
  1340,  1341,  1341,  1342,  1342,  1342,  1343,  1343,  1344,  1344,
  1345,  1347,  1348,  1346,  1349,  1350,  1350,  1351,  1352,  1352,
  1352,  1352,  1353,  1354,  1354,  1355,  1356,  1357,  1357,  1357,
  1357,  1358,  1358,  1359,  1359,  1360,  1361,  1361,  1361,  1361,
  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,
  1361,  1361,  1361,  1361,  1361,  1361,  1362,  1362,  1363,  1363,
  1364,  1365,  1366,  1366,  1367,  1367,  1368,  1368,  1369,  1369,
  1370,  1371,  1371,  1372,  1372,  1373,  1374,  1374,  1374,  1375,
  1375,  1376,  1377,  1378,  1379,  1380,  1380,  1381,  1381,  1381,
  1381,  1381,  1381,  1382,  1383,  1383,  1384,  1384,  1384,  1384,
  1385,  1385,  1385,  1386,  1386,  1387,  1387,  1387,  1387,  1387,
  1387,  1387,  1387,  1387,  1388,  1388,  1388,  1388,  1388,  1389,
  1389,  1390,  1392,  1393,  1391,  1394,  1394,  1395,  1395,  1396,
  1396,  1396,  1396,  1396,  1396,  1397,  1397,  1398,  1398,  1399,
  1399,  1400,  1400,  1401,  1401,  1402,  1403,  1404,  1405,  1405,
  1406,  1407,  1407,  1408,  1409,  1409,  1411,  1410,  1412,  1412,
  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,
  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412,  1412
};

static const short yyr2[] = {     0,
     1,     1,     5,     1,     1,     1,     1,     3,     1,     3,
     3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
     1,     0,     1,     0,     5,     6,     1,     3,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     0,     1,     0,     5,     1,     3,
     1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
     3,     0,     7,     4,     6,     1,     6,     0,     0,     9,
     0,     0,     0,     8,     0,     0,    10,     0,     0,     7,
     0,     0,     0,    14,     0,     2,     0,     2,     1,     0,
     1,     1,     3,     1,     1,     1,     1,     3,     0,     6,
     0,     5,     1,     2,     1,     2,     1,     0,     0,     3,
     0,     0,     3,     0,     4,     0,     4,     2,     2,     2,
     1,     2,     2,     3,     1,     1,     1,     2,     1,     1,
     2,     1,     1,     0,     0,     5,     7,     8,     0,     2,
     1,     3,     1,     3,     3,     1,     2,     0,     4,     0,
     4,     0,     3,     0,     3,     0,     3,     1,     3,     1,
     3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
     1,     1,     2,     0,     3,     1,     1,     1,     3,     0,
     2,     4,     4,     4,     2,     0,     4,     1,     1,     1,
     2,     1,     1,     3,     0,     1,     0,     7,     0,    12,
     1,     1,     1,     1,     1,     5,     3,     1,     1,     0,
     4,     0,     5,     0,     7,     1,     3,     1,     1,     0,
     2,     1,     1,     1,     4,     4,     6,     1,     2,     1,
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
     2,     4,     5,     3,     0,     0,    11,     0,     3,     1,
     0,     2,     1,     2,     0,     3,     0,     3,     0,     3,
     4,     5,     1,     2,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
     2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     0,     1,     1,     1,     1,     3,     1,     3,     1,
     3,     1,     1,     1,     2,     1,     1,     3,     4,     4,
     2,     2,     2,     2,     1,     1,     1,     3,     1,     2,
     2,     1,     0,     3,     2,     2,     1,     3,     4,     4,
     5,     5,     1,     1,     2,     2,     2,     2,     1,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     0,     0,     0,     6,     0,     0,     6,
     0,     0,     6,     0,     0,     6,     0,     0,     6,     0,
     0,     6,     1,     4,     4,     4,     4,     4,     1,     1,
     1,     1,     4,     4,     4,     4,     2,     2,     2,     0,
     0,     0,     8,     0,     0,    10,     0,     1,     0,     1,
     1,     2,     0,     3,     0,     3,     0,     1,     1,     2,
     0,     3,     0,     3,     3,     1,     4,     3,     1,     3,
     1,     3,     1,     3,     1,     2,     0,     3,     0,     3,
     0,     4,     0,     4,     0,     4,     0,     0,    11,     0,
     2,     2,     3,     1,     3,     1,     1,     1,     1,     1,
     1,     3,     1,     1,     4,     6,     4,     3,     6,     3,
     6,     1,     1,     1,     1,     1,     1,     0,     2,     3,
     1,     3,     1,     4,     1,     1,     0,     0,     1,     4,
     3,     6,     3,     6,     1,     1,     2,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
     3,     1,     2,     2,     2,     4,     2,     2,     4,     0,
     8,     0,     1,     1,     1,     0,     1,     2,     0,     1,
     2,     0,     1,     2,     0,     1,     3,     0,     2,     0,
     7,     0,     0,     3,     5,     0,     2,     0,     5,     4,
     1,     3,     3,     3,     0,     2,     0,     1,     1,     2,
     0,     4,     0,     4,     0,     3,     0,     3,     0,     3,
     0,     3,     0,     3,     0,     4,     0,     4,     1,     3,
     1,     1,     1,     3,     1,     1,     1,     3,     1,     3,
     2,     4,     1,     1,     1,     0,     4,     5,     6,     0,
    10,     3,     1,     1,     2,     2,     0,     2,     0,     3,
     1,     0,     3,     2,     0,     3,     1,     3,     1,     3,
     0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     2,     3,     0,
     0,     7,     1,     1,     2,     2,     2,     3,     4,     0,
     0,    10,     0,     1,     1,     2,     2,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
     1,     1,     1,     0,     0,     0,     0,    13,     1,     0,
     0,     6,     3,     0,     1,     2,     0,     1,     1,     2,
     1,     1,     1,     1,     0,     3,     2,     1,     0,     0,
     0,    14,     0,     0,     7,     1,     2,     0,     3,     0,
     4,     0,     5,     1,     0,     3,     0,     7,     0,     5,
     1,     2,     0,     1,     1,     1,     0,     1,     1,     2,
     2,     2,     1,     1,     1,     1,     3,     1,     1,     2,
     0,     2,     1,     1,     1,     1,     1,     1,     1,     0,
     3,     0,     1,     1,     1,     1,     2,     3,     2,     5,
     1,     1,     1,     4,     4,     1,     1,     1,     1,     2,
     3,     6,     1,     3,     1,     1,     1,     4,     7,     1,
     1,     1,     1,     2,     0,     1,     1,     3,     1,     3,
     1,     3,     1,     3,     1,     1,     1,     1,     3,     1,
     1,     3,     1,     1,     1,     3,     2,     0,     1,     1,
     4,     1,     3,     1,     3,     7,     0,     7,     0,     6,
     3,     1,     3,     1,     2,     5,     0,     7,     0,     2,
     0,     1,     5,     2,     5,     0,     5,     6,     4,     0,
     1,     1,     4,     0,     2,     0,     5,     4,     2,     1,
     3,     2,     2,     2,     2,     2,     2,     1,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
     1,     1,     1,     5,     1,     1,     2,     4,     1,     0,
    10,     5,     0,     1,     0,     2,     1,     2,     0,     3,
     1,     0,     4,     0,     2,     1,     3,     1,     1,     3,
     4,     4,     2,     1,     1,     1,     0,     1,     0,     0,
     0,    10,     2,     2,     2,     2,     1,     2,     0,     3,
     0,     3,     0,     3,     0,     3,     0,     3,     0,     4,
     0,     4,     1,     1,     1,     1,     1,     1,     0,     4,
     0,     1,     0,     4,     1,     2,     2,     2,     0,     1,
     1,     2,     2,     0,     2,     3,     3,     5,     0,     2,
     4,     1,     1,     1,     1,     1,     0,     1,     1,     3,
     2,     5,     2,     5,     5,     5,     5,     5,     0,     2,
     1,     2,     2,     2,     2,     2,     2,     1,     2,     2,
     2,     2,     1,     2,     2,     2,     2,     1,     1,     1,
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
     2,     2,     2,     1,     1,     1,     0,     3,     2,     0,
     0,     0,     0,     0,    14,     0,     2,     2,     0,     1,
     0,     0,     0,     0,     0,    14,     2,     0,     0,     0,
    10,     0,     1,     3,     3,     2,     4,     3,     3,     3,
     1,     1,     1,     1,     1,     3,     0,     0,     7,     0,
     0,     8,     0,     1,     1,     3,     2,     2,     1,     1,
     3,     1,     1,     2,     1,     1,     1,     2,     1,     1,
     1,     1,     1,     2,     6,     6,     0,     1,     0,     1,
     2,     5,     0,     2,     2,     1,     7,     1,     5,     3,
     1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
     1,     1,     0,     5,     0,     5,     1,     0,     3,     1,
     3,     1,     3,     1,     1,     0,     0,     5,     2,     1,
     0,     0,     3,     0,     0,     3,     1,     1,     1,     1,
     1,     2,     2,     4,     3,     3,     1,     3,     2,     1,
     1,     0,     1,     1,     1,     1,     0,     1,     3,     0,
     3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     7,     0,     1,     1,     1,     1,
     3,     1,     1,     1,     2,     0,     3,     1,     3,     1,
     3,     1,     1,     6,     0,     3,     1,     3,     0,     1,
     4,     5,     2,     1,     1,     4,     1,     3,     4,     4,
     1,     3,     1,     1,     1,     2,     1,     4,     0,     1,
     0,     2,     1,     1,     1,     4,     3,     1,     1,     1,
     2,     1,     1,     2,     2,     1,     3,     2,     2,     1,
     3,     1,     2,     4,     1,     2,     1,     3,     4,     0,
     1,     0,     1,     0,     1,     1,     3,     1,     3,     1,
     2,     1,     3,     2,     2,     4,     3,     0,     1,     1,
     1,     1,     1,     2,     1,     1,     5,     3,     5,     3,
     1,     3,     0,     1,     3,     3,     3,     3,     6,     5,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
     1,     1,     4,     5,     1,     5,     5,     1,     1,     1,
     4,     1,     4,     1,     7,     1,     1,     1,     4,     6,
     0,     2,     4,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     3,     3,     1,     1,     1,     0,     3,     5,
     2,     5,     4,     1,     1,     1,     1,     1,     2,     2,
     2,     2,     1,     2,     2,     0,     3,     0,     3,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
     0,     8,     0,     9,     0,     7,     0,     9,     0,     1,
     2,     1,     3,     1,     3,     5,     1,     1,     1,     1,
     2,     0,     0,     8,     5,     1,     1,     7,     0,     3,
     1,     3,     1,     0,     2,     5,     7,     0,     1,     1,
     1,     1,     3,     1,     2,     1,     3,     2,     3,     3,
     3,     1,     1,     1,     1,     1,     1,     1,     5,     5,
     5,     5,     5,     4,     6,     3,     1,     3,     0,     1,
     5,     7,     0,     2,     1,     1,     0,     3,     1,     3,
     1,     1,     1,     0,     3,     1,     1,     1,     1,     4,
     6,     1,     1,     2,     3,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     2,     1,     1,     1,     3,     5,
     1,     1,     1,     1,     3,     2,     2,     2,     1,     2,
     2,     2,     2,     2,     1,     3,     2,     1,     2,     1,
     2,     1,     0,     0,     6,     0,     2,     0,     1,     1,
     2,     2,     2,     4,     3,     1,     3,     1,     2,     5,
     2,     2,     5,     0,     2,     1,     1,     2,     6,     6,
     1,     0,     1,     2,     1,     2,     0,     2,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

static const short yydefact[] = {   789,
     0,     0,     0,     0,     0,     0,     0,     0,  1649,     0,
   790,   666,   791,   132,   129,     0,   125,   127,   126,   130,
  1655,   577,   577,  1658,     0,  1654,  1651,  1648,  1646,  1647,
  1653,  1652,  1650,   577,   789,   124,   128,   131,   609,   594,
   607,   613,   593,   605,   588,   622,   625,   591,   623,   600,
   604,   615,   627,   624,   626,   616,   598,   596,   621,   602,
   601,   589,   590,   592,   595,   606,   618,   597,   608,   612,
   614,   620,   603,   617,   619,   599,   610,   611,  1662,     0,
   571,  1659,   577,  1660,  1657,   577,   667,   807,  1691,   578,
  1661,  1656,   577,   815,   812,   814,   789,   808,   809,   811,
   813,   570,  1529,  1528,   806,   170,   770,   810,   549,   577,
   174,   577,     0,   171,   172,   176,   818,   882,   550,   816,
   585,   875,   577,   876,   883,   881,   177,   170,   284,   180,
   877,   817,   173,   577,   577,   890,   888,   889,   879,     0,
   789,     0,   180,   175,   192,   577,   178,   193,   220,   887,
   886,     0,    21,    20,    12,   577,   895,     0,    14,     0,
   893,   577,   878,   771,     0,   282,   180,   186,   181,   180,
   185,   219,   577,   884,     0,    16,    15,    18,    17,    19,
   577,    13,   577,   891,     0,   773,   316,   302,   195,   253,
   272,   293,   295,   292,     0,   314,     0,   301,   294,   298,
   304,   288,   303,   180,   305,   285,   308,   286,   287,   283,
     0,   179,     0,   192,   194,   243,   244,   232,   212,   240,
   195,   214,   253,   272,   230,   233,   228,     0,   210,     0,
   239,   231,   236,   242,   224,   241,   180,   245,   180,   222,
   223,   221,   248,   249,    10,    11,   894,   577,   880,   793,
  1161,   577,   577,   792,   133,  1150,   800,   577,   577,   786,
   788,   785,   787,   772,   774,   775,   794,   778,   779,   780,
   783,   781,   782,   784,   577,   196,     0,   306,     0,     0,
   307,     0,     0,     0,     0,   577,     0,     0,     0,   251,
     0,   586,   182,   184,     0,   183,     0,   189,   188,   187,
   190,   180,     0,   180,   246,   247,     0,     0,   180,     0,
     0,     0,     0,   229,     0,   577,     0,     0,   577,   170,
   494,   823,   776,   577,     0,   201,   202,     0,   265,   267,
   262,   263,   259,   261,   258,   260,   257,     0,   267,   278,
   279,   275,   277,   274,   276,   269,     0,     0,     0,   318,
     0,   321,   323,   209,     0,   208,     0,     0,   180,   587,
   191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   180,   892,     0,     0,   577,     0,   801,   170,   170,     0,
     0,     0,   254,     0,     0,   264,   281,   255,   280,     0,
   273,     0,   296,     0,   290,   577,   315,   577,   320,   310,
     0,     0,   299,   289,   252,   309,     0,     0,     0,     0,
   234,     0,   226,   211,   197,     0,   237,   225,   250,  1162,
     0,     0,  1151,  1697,   495,   824,   795,   317,   203,   204,
     0,   266,   271,     0,     0,     0,     0,   319,   322,     0,
   207,     0,   213,     0,   180,     0,     0,     0,     0,   577,
   665,   819,   577,     0,  1695,  1697,  1087,  1614,   789,     0,
   577,     0,   268,   270,   297,   291,     0,     0,   300,     0,
   218,     0,   216,   235,   227,   220,   238,   911,     0,   906,
   907,   577,     0,   802,  1696,  1088,  1694,   577,   577,   577,
   577,   577,  1678,   577,  1212,  1211,   577,  1213,   577,   368,
  1210,  1190,   577,     4,  1209,   369,   366,   577,   371,   168,
   454,  1065,     0,     0,  1219,   121,   365,   364,  1182,   359,
   577,  1205,  1670,   577,   370,   335,   577,     2,     1,   577,
   367,  1187,   577,   577,   360,   357,   353,   577,   577,   577,
   577,   577,  1207,   363,   577,   577,   577,   577,   577,   577,
   577,   577,  1206,   577,   577,   577,   169,  1184,   356,   355,
   577,   577,  1668,   577,   577,   134,  1183,   362,   361,   577,
   577,   358,   870,   454,   577,   490,     0,   577,   577,   454,
   577,   577,   577,   454,   577,  1159,   577,   577,  1069,   577,
  1663,   577,   101,   577,   577,   832,   577,   577,   577,   577,
   760,   577,   577,   577,     0,   577,   577,   577,   577,   577,
   577,   577,   640,   577,   577,  1699,  1700,  1701,  1702,  1703,
  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,
  1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,
  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,
  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,
  1744,  1745,   861,  1746,  1747,  1748,  1749,  1750,  1751,  1752,
  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,  1056,
  1058,  1053,  1055,  1054,  1057,  1762,  1763,  1181,  1764,  1185,
  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1290,
  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1698,   499,   577,
   828,     0,   826,     0,     0,   311,   206,     0,   180,   215,
   198,   577,  1163,   577,     0,  1152,   777,  1672,   564,     0,
   120,     0,   577,  1638,  1637,   964,  1634,  1636,  1686,     0,
  1199,     0,  1195,  1204,     6,     0,     5,   577,  1679,  1026,
  1027,   577,  1120,  1119,  1068,  1118,  1067,   577,   577,   415,
   417,  1156,     0,     0,     0,     0,     0,     0,   613,     0,
   577,  1498,     0,     0,   627,   407,   577,   577,   616,   406,
   577,   423,   618,   482,   617,     0,   619,     0,     0,   577,
     0,   402,  1220,     0,   373,   372,   379,   374,   480,   473,
   375,   377,   479,   378,   882,   416,   419,   422,  1208,   481,
  1616,  1214,   122,   577,  1033,   119,   577,   766,    22,   566,
   354,     0,   765,  1023,   767,     0,  1218,   854,   853,   856,
   852,   855,  1688,     0,   850,     0,   565,   937,   851,  1682,
     0,  1671,   118,   934,   668,   932,     0,   562,  1669,  1666,
  1673,   714,   713,     0,   715,   554,   711,     0,   577,   947,
   567,  1287,   577,   577,   999,   997,   577,   991,   993,   992,
   990,   989,   577,   577,   577,   988,   577,   741,   577,   577,
     0,     0,     0,     0,   577,   577,     0,     0,     0,   978,
   969,   970,     0,  1011,   400,    22,   392,  1676,     0,  1668,
   123,   563,   577,   758,   996,   995,  1160,  1158,  1086,     0,
  1605,  1606,  1087,  1172,  1087,  1070,  1071,  1074,  1089,  1221,
   577,     0,     0,     0,     0,     0,   577,     0,   577,     0,
    60,     0,   882,     0,    66,     0,    99,   542,   628,   577,
  1059,   954,  1063,     0,   577,  1012,  1176,     0,  1066,   632,
   629,   630,     0,   634,   635,     0,   637,   638,   577,   633,
   915,   917,   577,   577,   916,   716,   913,   677,   909,   874,
     0,   577,   577,     0,   644,   645,     0,     0,   872,   868,
   869,   865,   866,   867,   860,   864,   863,   577,   577,   577,
   577,   577,     0,   503,   505,   497,   500,   501,   830,  1697,
   825,   827,   796,   205,     0,     0,   217,   912,   170,   908,
   820,   170,     0,   578,   573,   577,  1635,   577,   577,   966,
   577,   577,  1198,  1197,   577,  1186,     0,  1471,  1477,     0,
     0,  1472,  1028,     0,    22,  1115,  1117,  1116,   380,   381,
   577,  1093,   458,   577,   577,   577,   577,     0,   577,   577,
   421,  1506,  1504,  1505,  1501,  1503,  1500,  1502,  1494,     0,
   577,     0,   577,     0,   420,     0,   413,   577,   414,     0,
   464,   461,   470,   577,   467,   577,   577,   405,   577,   577,
   577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
   577,   577,   577,   577,   577,   162,   163,   164,   165,   166,
   167,   487,   488,   489,   434,   577,   577,   433,   439,     0,
   577,   385,   577,     0,   386,   376,   382,   384,   387,   388,
   389,   390,   391,   383,   412,   411,   455,   577,   924,     0,
     0,   340,    23,   334,   577,   577,  1020,   577,   577,   577,
   577,   577,   577,     0,   941,  1615,   577,   577,   180,     0,
   577,   577,  1668,   577,   577,   577,   577,   577,   135,     0,
   577,   951,   943,   944,   949,  1288,  1289,   871,   324,   398,
   577,   491,   547,   546,   544,   972,   548,   977,   973,   976,
   734,     0,   974,   975,   735,   982,   986,   979,   980,   984,
   985,   983,   981,   987,     0,   768,   577,   577,     0,   395,
   803,   396,   393,   394,   577,     0,     0,   724,   723,   722,
  1675,    22,   759,  1082,  1083,  1084,  1085,  1079,  1077,  1173,
  1091,  1076,  1072,   577,     0,  1073,  1664,    78,   577,     0,
   577,   577,    95,     0,    96,   577,     0,   577,    71,   577,
   577,   108,   103,     0,   859,     0,   858,     0,   454,  1061,
   577,   900,   901,   923,   896,   897,   761,   921,  1014,  1178,
   577,  1180,  1179,   660,   577,   577,   577,   649,   677,   677,
   675,   577,   577,   678,     0,    24,   648,   651,     0,   658,
   654,   873,   862,  1612,  1613,  1603,  1603,     0,     0,  1530,
   577,   180,  1242,   577,   577,  1243,  1285,   180,   577,  1286,
   577,  1568,   577,  1256,     0,  1304,  1302,  1301,  1300,  1298,
  1299,  1296,  1294,  1297,  1291,  1363,  1362,  1292,  1293,  1303,
  1539,  1295,  1619,  1618,  1617,  1697,  1697,   516,   507,   498,
     0,   502,  1697,   829,   170,   312,   199,  1121,   170,  1099,
   577,   572,     0,     0,   965,   577,     0,   963,  1641,  1643,
  1642,  1639,  1687,  1684,  1196,   577,   577,  1191,   577,  1029,
   332,  1157,    90,     0,     0,     0,     0,  1568,     0,     0,
     0,     0,     0,     0,     0,   408,     0,     0,     0,   424,
   577,   577,   577,     0,   577,     0,     0,     0,   426,   425,
   440,   435,   446,   449,   450,   447,   453,   452,   451,   442,
   441,   444,   443,   445,   436,   438,   454,   448,   437,   454,
    90,   418,   577,  1188,   956,  1024,  1025,  1022,  1021,     0,
   857,     0,     0,   551,     0,     0,   577,   935,   933,     0,
   670,   671,     0,     0,  1667,  1674,     0,     0,   558,     0,
   560,   712,     0,   139,   577,   945,   952,     0,   577,   960,
   577,   327,   577,   577,   577,   577,    22,   998,  1264,     0,
     0,   757,   746,   755,   756,   744,   745,   748,   751,   747,
   754,   750,   752,   753,   743,   749,   742,   741,   971,   769,
   401,   577,  1003,   577,  1677,   725,   726,   351,   577,  1087,
   577,  1090,  1075,  1697,    90,     0,     0,     0,     0,   577,
     0,   577,    61,    90,     0,   114,   109,     0,   104,   577,
   111,   105,   843,   835,   841,     0,  1060,   577,  1062,  1064,
     0,   577,   904,     0,   577,     0,   577,  1013,  1177,  1697,
   631,   636,   639,   652,   650,   568,     0,   577,   577,   693,
   731,   691,   687,   685,   729,     0,     0,   717,     0,   679,
   689,   914,   910,   577,     0,     0,     0,   657,   577,     0,
   577,   577,     0,     0,   577,  1476,     0,  1358,  1359,  1624,
  1325,  1380,   577,     0,  1622,     0,     0,  1570,  1571,  1569,
   577,     0,   577,  1308,  1314,  1313,  1312,  1316,     0,  1309,
  1310,   577,  1540,  1551,   504,   506,   577,     0,   519,   511,
   513,     0,   508,   509,   577,   577,   527,   529,   577,     0,
   525,   831,   797,     0,     0,     0,  1147,  1164,   821,     0,
  1153,  1147,   576,     0,   575,   577,   931,     0,   577,   577,
  1683,     3,     7,     9,  1477,  1474,   577,  1473,   454,   459,
    91,    92,    94,   476,   475,   478,   474,   577,   410,   484,
  1156,  1513,  1511,  1512,  1508,  1510,  1507,  1509,  1499,   477,
  1156,   483,   409,   485,   486,   465,   462,   471,  1156,   468,
  1156,  1156,  1156,   577,     0,   577,     0,   456,     0,   577,
   577,   953,   577,   577,   577,   577,   577,     0,   577,   180,
   669,   577,   555,   557,   577,   577,   156,   154,   577,   577,
   136,     0,   146,   152,   677,   141,   143,   577,   950,   961,
   962,     0,   399,   326,   331,   553,   325,   577,   328,   333,
  1265,   492,   545,   543,   741,   736,   737,  1002,  1004,   577,
   397,   352,  1080,  1078,  1174,  1175,     0,    79,    64,  1168,
     0,     0,     0,    97,     0,     0,    72,    68,  1697,  1697,
   107,   102,   116,   112,     0,   106,   732,   844,   568,  1697,
   834,   833,   842,   955,   577,     0,   577,   922,   454,     0,
     0,  1587,  1485,  1488,  1588,  1496,  1486,  1585,   577,  1019,
  1584,   595,   577,  1586,     0,     0,     0,     0,  1638,  1487,
  1015,  1016,  1583,  1493,  1018,  1644,  1582,   662,   655,   653,
     0,    22,   577,   707,   681,   709,   683,  1697,  1697,  1697,
  1697,   741,   702,   701,   697,   699,   706,   705,   695,   703,
   676,   680,  1697,   568,    44,    42,    39,    33,    37,    41,
    36,    29,    38,    32,    35,    30,    40,    31,    43,    34,
     0,    27,     0,   659,  1604,   577,   577,  1601,  1556,  1557,
  1549,  1535,  1550,     0,     0,   577,   994,  1357,  1360,   577,
     0,   577,   577,  1381,  1275,  1248,  1627,  1626,  1625,   577,
   577,  1552,  1572,  1574,   577,   577,  1270,   577,  1271,  1267,
  1268,  1269,  1260,  1257,   577,   577,  1315,   577,     0,     0,
  1544,  1541,  1542,   518,   523,   577,   577,  1697,  1697,   496,
   510,   533,   521,   535,  1697,  1697,   531,   515,   526,   789,
     0,   220,  1145,  1146,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,  1144,     0,     0,  1132,  1133,
  1134,  1131,  1136,  1137,  1138,  1135,  1122,  1113,   577,     0,
  1167,     0,   789,     0,  1108,     0,     0,     0,     0,     0,
     0,   577,  1100,  1101,     0,  1034,   574,  1640,   577,     0,
  1685,   577,     0,     0,     0,   589,  1478,     0,  1200,  1345,
  1344,  1343,  1203,  1202,   577,     0,  1030,     0,   577,     0,
  1095,  1094,     0,     0,     0,  1096,     0,  1098,  1097,  1092,
   427,     0,   430,     0,   429,     0,     0,     0,   577,     0,
  1215,  1690,  1689,   552,   577,     0,    45,   577,   674,   673,
   672,  1216,   577,     0,   677,  1697,  1697,   148,   579,   158,
   150,   160,   140,   147,  1697,   577,     0,   577,     0,   577,
     0,   577,  1697,     0,   739,   568,   577,  1665,     0,    90,
   577,    62,   577,   577,   577,    75,     0,    90,   115,   110,
  1697,  1697,   100,   741,   845,   839,   847,   846,   836,   540,
   885,   902,   903,   898,   577,  1492,  1491,  1490,  1489,  1520,
  1518,  1519,  1515,  1517,  1514,  1516,  1495,     0,     0,  1435,
     0,  1435,  1435,  1435,  1435,   577,   577,   577,   577,   577,
   577,  1628,  1629,  1630,  1631,  1632,  1633,  1578,   577,   663,
     0,   642,   656,   569,   718,     0,   577,  1697,   577,  1697,
   694,   692,   688,   686,   730,     0,  1697,     0,  1697,   690,
    22,     0,    25,     0,  1607,  1568,  1539,   577,   577,  1548,
  1531,  1547,  1361,     0,  1327,     0,  1274,     0,   577,   616,
   577,  1368,  1386,  1388,  1390,  1434,  1433,  1432,  1431,  1392,
     0,  1413,   577,     0,  1623,     0,  1620,   577,  1564,  1575,
     0,   577,  1223,  1226,  1228,     0,  1231,  1233,  1273,  1272,
  1261,  1259,     0,  1318,     0,  1311,   577,   577,   577,   577,
   520,   517,   512,   514,   577,  1697,  1697,   528,   530,  1697,
  1697,   313,   200,  1139,  1140,  1141,  1143,  1126,  1124,  1123,
  1127,  1128,  1125,  1142,  1129,  1130,  1114,   928,  1149,   925,
   577,     0,  1165,  1697,  1112,  1111,  1106,  1104,  1103,  1107,
  1105,  1109,  1110,  1102,  1154,   968,   577,     8,   577,   577,
   577,   577,     0,  1481,   577,  1193,     0,  1467,  1465,  1452,
  1454,  1450,     0,  1449,     0,  1458,  1445,  1466,     0,  1457,
  1442,  1448,  1464,  1456,  1349,  1439,  1440,  1441,   577,   460,
    93,   577,  1380,  1559,   466,   463,   472,   469,   577,   432,
   431,   457,   338,  1189,     0,   577,  1681,     0,     0,   936,
    46,     0,   559,   561,   556,   727,   157,   155,   577,  1697,
   577,   577,   577,  1697,   153,   142,   577,   145,   144,   577,
   942,   946,   330,   577,  1266,     0,   741,   738,    22,  1081,
    85,  1169,    67,   577,     0,    98,    65,    90,    73,     0,
   117,   113,   733,  1697,   849,   568,   848,   577,   537,   577,
   763,   764,   762,     0,  1596,  1437,  1438,  1436,   577,   577,
   577,   577,   577,   577,  1597,     0,  1017,  1581,  1580,  1577,
  1579,  1645,  1697,   661,   646,   643,     0,   708,   682,   710,
   684,   700,   698,   704,   696,   719,    28,    26,   577,  1602,
   577,  1536,  1537,  1533,  1539,   577,  1326,   577,  1329,     0,
  1395,   577,     0,  1413,  1394,  1391,   577,   577,  1427,  1423,
  1424,  1421,  1430,  1429,  1422,  1425,  1426,  1428,   577,     0,
  1414,     0,     0,   577,     0,  1250,  1245,  1244,  1247,   577,
  1573,   577,  1553,   577,  1235,     0,   577,   577,  1222,   577,
   577,  1262,  1258,   577,  1317,   577,     0,  1545,  1543,   524,
   522,   534,   536,   532,     0,   930,   929,   927,   577,  1148,
  1035,  1039,  1041,   577,  1045,   577,  1043,  1047,  1036,  1037,
     0,     0,     0,   967,     0,  1334,  1337,     0,  1341,     0,
     0,     0,  1201,  1194,  1192,   577,     0,     0,     0,     0,
     0,     0,     0,     0,  1347,     0,  1350,  1351,   805,  1031,
   577,  1369,  1370,  1372,  1375,  1382,   577,     0,  1435,  1561,
  1555,   428,     0,    22,     0,   577,   959,   577,    47,   939,
     0,    22,   159,   149,     0,   581,   583,   161,   151,   727,
     0,   329,   493,   740,  1000,   577,    80,     0,    63,     0,
    76,    85,    69,   840,   837,   541,  1697,     0,  1527,  1525,
  1526,  1522,  1524,  1521,  1523,  1497,     0,   577,     0,     0,
     0,     0,   577,  1594,   664,   641,   647,   568,  1611,     0,
  1609,  1564,  1539,  1539,  1532,  1328,  1568,  1330,  1324,  1568,
  1393,  1387,  1389,  1397,  1599,  1410,  1599,  1408,  1416,  1415,
   577,  1599,   577,  1402,  1401,  1403,     0,  1399,  1400,  1418,
  1417,   577,  1249,     0,  1621,   920,  1565,   918,     0,   577,
  1240,  1230,  1237,  1241,  1239,   577,     0,  1224,  1225,  1232,
  1234,   577,  1319,  1322,  1306,  1320,  1323,   577,   799,   798,
   926,  1697,  1697,  1049,  1697,  1051,  1697,  1697,  1038,  1166,
   822,  1155,     0,   577,   577,  1340,  1339,  1331,     0,  1479,
  1483,  1478,     0,     0,     0,  1469,  1461,  1461,     0,     0,
  1461,  1468,     0,  1485,  1346,  1354,   577,  1353,     0,  1355,
  1348,  1351,     0,   577,  1373,   577,  1484,  1376,   577,  1383,
  1384,  1563,  1193,   577,   577,   577,   336,   577,   957,     0,
     0,     0,   938,   728,   137,   580,    22,   948,  1005,    86,
  1170,    81,     0,    74,    85,  1697,   538,   899,  1593,     0,
  1589,  1590,  1591,  1592,  1598,   720,   577,  1608,     0,  1538,
  1534,   577,   577,     0,  1600,  1411,     0,     0,     0,  1405,
  1396,  1251,   577,   577,  1559,     0,  1239,   577,  1236,     0,
  1263,   577,  1307,  1305,  1546,  1040,  1042,  1697,  1046,  1697,
  1044,  1048,  1332,  1338,  1342,     0,  1482,  1451,     0,  1453,
     0,     0,     0,     0,  1459,  1463,     0,  1443,  1333,  1335,
   577,  1352,  1032,  1377,     0,  1371,  1365,  1366,  1576,   577,
  1385,  1379,  1562,  1280,  1276,  1277,  1282,  1281,  1560,   339,
   341,   958,  1680,   577,   577,   577,   577,   577,   577,    52,
     0,    51,     0,    49,   577,   577,   138,  1009,  1001,     0,
  1007,    85,    90,    85,    70,   838,     0,  1595,    22,  1610,
  1559,     0,     0,  1599,  1409,  1407,   577,  1599,  1420,  1255,
     0,  1252,  1254,   919,  1554,  1229,  1238,   577,  1321,  1050,
  1052,  1480,     0,  1470,  1462,  1446,  1444,     0,  1447,   577,
     0,   577,  1374,   577,  1364,   577,  1284,  1283,  1279,   347,
   345,   337,     0,   343,   349,    54,    59,    56,    58,    55,
    57,    53,     0,    48,     0,   582,   584,  1697,  1006,  1008,
  1171,    82,    77,   539,   721,  1558,  1566,     0,  1412,  1419,
  1404,  1406,   577,  1246,     0,     0,  1460,     0,  1356,  1378,
  1367,  1278,  1697,  1697,   342,   344,  1697,    50,   577,  1010,
     0,  1567,  1253,  1227,  1455,  1336,   348,   346,   350,     0,
    83,   940,    87,    89,   577,    84,    88,     0,     0,     0
};

static const short yydefgoto[] = {   616,
   617,   618,   619,   746,  1632,  1633,   157,   181,   158,  1132,
  1133,  1555,  1841,  2782,  2280,  2281,  2671,  2783,  2784,   620,
   931,  2314,  2048,  2685,  1504,  2047,  2522,  2318,  2683,  1495,
  2039,  2793,  2891,  2903,  2517,  2906,  1640,  1641,  1642,  1234,
  1743,   621,  1244,   936,  1242,  1511,  1752,  1508,  1750,  1755,
  2052,  1243,  1749,  1512,  2051,   622,    11,    16,    17,    18,
    19,    20,   261,   625,   859,  1444,  1159,  1701,  1705,  1706,
  1702,  1703,  2290,  2294,  2025,  2017,  2016,  2018,  2021,  1115,
   626,   113,   114,   115,   130,   144,   290,   146,   147,   213,
   300,   148,   149,   277,   240,   448,  1615,   328,   431,  1005,
   355,   356,   241,   309,   302,   304,   472,   473,   171,   172,
   173,   242,   243,  1430,   406,   278,   281,   279,   280,   337,
   383,   384,   386,   391,   434,   282,   283,   346,   388,   211,
   116,   142,   206,   207,   208,   440,  1614,   209,   286,   275,
   349,   350,   351,   352,  1457,   627,   628,   629,   630,   814,
  2771,  2494,  1134,  2842,  2843,  2844,  2884,  2883,  2887,   631,
   632,   633,   634,   792,  1116,  1201,  1202,  1203,  1169,   894,
  1170,   794,   795,   796,   797,   798,  1070,  1117,  1992,  1118,
  1119,  1120,  1121,  1122,  1123,  1124,   752,   799,  1411,  1996,
  1363,  1978,   800,  1382,  1984,  1381,  1983,  1385,  1987,  1383,
  1985,   801,   802,   803,   804,   635,   867,  1459,  2033,   262,
   378,   459,  1329,   996,   997,   998,  1326,  1327,  1602,  1603,
  1604,  1898,  1899,  1330,  1331,  1598,  1902,  1894,  1610,  1611,
  1905,  1906,  2190,  2186,  2187,   636,  2527,  2797,  2329,   637,
  1176,   117,  1425,  1426,  1717,   898,   847,   901,   728,   836,
   819,   860,  1802,   118,   729,  1014,  1624,    80,   102,  2020,
   119,   806,    81,   638,   639,   951,   952,   640,   641,   642,
   643,   959,  2355,   980,  2546,   981,  1534,   982,  1799,   983,
  2102,   984,  1558,   644,  1530,  2101,  2353,   263,    35,   645,
  1150,  1431,  1432,  1548,  1275,  1549,  1550,  2108,  2110,  1811,
  1810,  1823,  1809,  1808,  2119,  2117,  1815,  1816,  1819,  1820,
  1805,  1807,   646,   647,   857,   648,  1271,   966,  2799,   649,
  1210,  2502,  1551,  1812,  1758,  2054,   890,  1186,  1478,  1726,
  2034,  1727,  1182,  1477,   650,   651,   945,  1526,  2333,   652,
   653,   654,   655,  2908,   128,   186,   264,   265,   656,   266,
    12,   267,   268,   324,   461,  1335,  1910,  2610,   269,   320,
   424,   657,  2480,    96,    97,    98,    99,   100,   106,   120,
   270,   482,  1339,  1943,   271,   379,   460,   712,   713,  1000,
  1333,   658,   940,  1762,  1515,  1760,  2686,  2324,  1516,  1759,
  2057,  2326,   659,   660,   661,   830,   831,  1246,   662,   985,
   986,   663,   863,  1283,   987,   807,   122,   123,   124,   125,
  1253,   152,   139,   126,   136,   160,   161,  1254,  1255,  2064,
  1256,   479,   480,   968,   481,   969,  2587,  2588,  1257,  1258,
  1130,  2209,  2210,  2438,   735,   845,   846,   664,  1145,  2673,
   665,  2302,   666,  1163,  1164,  1165,  1450,  1448,   667,   668,
  1682,  1712,   669,  1020,  1348,   670,   891,   892,   671,   907,
   672,  1851,   673,  2679,   674,  1730,  2789,  2790,  2791,  2858,
   896,   675,  1259,  1528,  1791,  1792,   676,  1418,   751,  1034,
   677,  1639,  2259,  2653,   678,  1621,  2213,  2449,  2450,  2612,
  2613,  2617,  2615,  2618,  2728,  2730,   679,   680,  1248,  1520,
   681,  1250,   915,   916,   917,  1226,   682,   683,   684,  1490,
  1218,   910,   487,   918,   919,   808,  1622,  1953,  1954,  1937,
   755,   756,  1617,  1938,  1941,   272,   319,   453,  1012,  1955,
  2453,  1042,   685,   908,   273,   316,   450,  1009,  1942,  2451,
  1618,   935,  2040,  2518,  2792,  1221,   686,   687,   688,   689,
   690,   817,  1680,   748,  1637,  2465,   742,   743,  1968,  1969,
   691,   692,   826,   809,   693,  1306,  2419,  2163,  2164,  2165,
  2166,  2167,  2416,  2592,  2593,  1307,  1308,  1573,  2408,  2584,
  2154,  2405,  2811,  2812,  1309,  1583,  2171,  1884,  2423,  2602,
  1722,  2032,  1885,  1310,  1311,  2490,  2765,  2766,  2767,  2839,
  1312,  1313,  1167,   694,   695,   993,  1315,  1316,  2724,  1589,
  1590,  1591,  1887,  2173,  2605,  2606,  1317,  1861,  2134,  2559,
  1970,  1971,  2650,  2455,  2749,  2456,  1972,  2458,  1973,  2477,
  1974,  2478,  2651,  2652,  1318,  1567,  1568,  1858,  1319,  2761,
  2660,  2757,  1864,  2263,  2482,  2483,  2484,  2755,  2264,  1865,
  2661,  2762,  2142,  2143,  2144,  2145,  2146,  2147,  2577,  2578,
  2579,  2809,  2709,  2871,  2148,  2704,  2403,  2149,  2404,  2150,
  2339,  2255,  2256,  2257,  2742,  2258,  2643,  2637,  2825,  1975,
  1031,  2607,  1032,  2234,  2168,  2658,  1793,   810,  1794,  2077,
  1059,  1060,  1659,  2078,  2536,   105,   696,   697,  2375,  2554,
  2127,  2553,  1594,  1892,  1893,  2131,  1852,  1320,  1853,  2159,
  2589,  1369,  1848,  1849,  2491,  2663,  2413,  2379,  2151,  1581,
  1872,  1873,  2758,  2152,  2346,  2706,   698,   699,  1560,  1850,
  2370,  2550,  2551,  1286,   700,   812,  1322,  1323,  1576,  2156,
  1324,  1325,  1869,  2098,   736,  1796,   738,  1352,  1797,   127,
    26,    85,    82,   702,   921,  1494,  1153,   851,   703,   899,
   704,  2007,   705,  1631,   740,  1354,   706,   707,    90,   454,
   455,   456,   457,   458,   708
};

static const short yypact[] = {  2049,
   736,   389,   389,   389,   389,   389,   389,   389,-32768,   389,
-32768,   246,-32768,-32768,-32768,   280,   302,-32768,   332,-32768,
-32768, 17798, 17302,-32768,  -204,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768, 17798,  2049,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   377,
-32768,-32768, 17798,-32768,-32768, 17302,-32768,   850,-32768,-32768,
-32768,-32768, 13727,-32768,-32768,-32768,  2049,   850,-32768,-32768,
-32768,-32768,-32768,-32768,-32768, 11133,-32768,-32768,-32768, 17798,
-32768, 17798,   162,  1382,-32768,-32768,-32768,   363,-32768,-32768,
-32768,-32768,  9668,  -180,-32768,-32768,-32768,  1382,-32768,   117,
  -180,-32768,-32768, 12182,  8637,-32768,-32768,    17,-32768,  -142,
  2049,  -124,-32768,   560,   272, 17798,-32768,-32768,   606,-32768,
-32768,   274,-32768,-32768,-32768,  8637,   893,   653,-32768,   112,
-32768,  8637,-32768,-32768,  1751,   678,   117,-32768,-32768,-32768,
-32768,-32768, 16518,-32768,   360,-32768,-32768,-32768,-32768,-32768,
  8637,-32768,  8637,   298,   128,  1163,-32768,-32768,   228,  1050,
-32768,-32768,   335,-32768,   341,-32768,   320,-32768,-32768,   352,
-32768,   361,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    55,-32768,    68,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   228,-32768,  1050,-32768,-32768,   382,-32768,   385,-32768,   370,
-32768,-32768,   404,-32768,   409,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   893,-32768,  8637,-32768,-32768,
-32768, 17798, 17798,-32768,-32768,-32768,-32768, 17798, 17798,-32768,
-32768,-32768,-32768,-32768,  1163,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768, 17798,-32768,  -122,-32768,   248,  1121,
-32768,   258,  1273,   718,   789, 17798,   821,   843,   851,-32768,
   301,-32768,-32768,-32768,   891,-32768,   896,-32768,-32768,-32768,
-32768,-32768,  -122,-32768,-32768,-32768,   899,   902,   117,   821,
   905,   909,   329,-32768,   129, 17798,   555,   874, 17798,  1382,
-32768,-32768,-32768, 17798,   372,-32768,-32768,   938,-32768,   574,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1273,   574,-32768,
-32768,-32768,-32768,-32768,-32768,   582,   139,   141,   178,-32768,
  1039,-32768,-32768,-32768,   591,   991,   150,   639,-32768,-32768,
-32768,   415,   980,   778,   157,   168,   190,   615,   186,   654,
-32768,-32768,   614,   989, 17798,   620,-32768,  1382,  1382,   622,
  1001,   -97,-32768,  1121,  1004,-32768,-32768,-32768,-32768,  1009,
-32768,  1010,-32768,  1012,-32768, 17798,-32768, 17798,-32768,-32768,
   821,  1013,-32768,-32768,-32768,-32768,  1006,   -97,   647,  1021,
-32768,  1022,-32768,-32768,-32768,  1023,-32768,-32768,-32768,-32768,
   715,   683,-32768,   754,-32768,-32768,-32768,-32768,-32768,-32768,
   814,-32768,-32768,   729,   733,   737,   739,-32768,-32768,   506,
  1096,   743,-32768,   830,-32768,   748,   749,   521,   768, 17426,
-32768,-32768, 17426,   802,-32768,  3753,   645,  9130,  2049,  -324,
 17426,   710,-32768,-32768,-32768,-32768,  1751,   821,-32768,   711,
-32768,   188,-32768,-32768,-32768,-32768,-32768,   552,   785,  1138,
-32768, 17426,   786,-32768,-32768,-32768,-32768, 17798,-32768,-32768,
 12306, 17798,-32768, 17798,-32768,-32768, 17798,-32768, 14719,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768, 17798,-32768,-32768,
-32768,-32768,    74,    74,  4489,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768, 17798,-32768,-32768,-32768,
-32768,-32768, 17550,-32768,-32768,-32768,  4489,-32768, 17550, 17798,
 17550,   721,-32768,-32768, 11505,-32768,-32768, 11505,-32768, 17798,
 11505,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
 17550,-32768,    20, 16724, 17798,-32768,-32768,-32768,-32768,-32768,
 12306,-32768,-32768,-32768,-32768,-32768,  1520, 17550,  5766,-32768,
 17054, 17054,-32768,-32768, 17798, 11629, 17550, 12430,  4489,  5766,
-32768, 15534,  4489,-32768, 17302,-32768,  5766,-32768,  5766, 17550,
-32768,-32768,  5766,  5766,    74, 17798,-32768, 17798, 17054,-32768,
 17798, 17054,-32768, 17798, 10660,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,     1,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   583,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   283, 17798,
-32768,   254,-32768,   791,  1126,-32768,-32768,  1126,-32768,-32768,
-32768, 17798,-32768, 17798,   794,-32768,-32768,-32768,-32768,   219,
-32768,   579, 13851,   747,-32768,   589,-32768,   588,-32768,  1170,
  -216,   189,-32768,-32768,-32768,   790,-32768, 13975,-32768,-32768,
   741, 10784,-32768,-32768,-32768,   693,-32768,  5766,  5766,-32768,
-32768,   687,   787,   795,   797,   800,   801,   803,   805,   806,
  5766,  1342,   807,   808,   810,-32768,  5766,  5766,   813,-32768,
 14595,-32768,   815,   823,   824,   828,   829,   833,   835,  5766,
   841, 16305,-32768,    75,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   316,-32768,   840,-32768,-32768,-32768,
-32768,-32768,-32768, 17550,-32768,-32768, 13975,-32768,     4,-32768,
-32768,   951,-32768,    70,-32768,   762,-32768,-32768,-32768,-32768,
  1207,-32768,-32768,  -200,-32768,   655,-32768,   659,  1207,-32768,
   688,-32768,-32768,   871,   103,-32768,   837,-32768,-32768,   623,
-32768,-32768,-32768,   864,-32768,  -192,-32768,   638, 17178,  -241,
-32768,   972,  5766,  5766,-32768,  1260,-32768,-32768,-32768,-32768,
-32768,-32768, 14471, 14471, 14471,-32768, 14471,-32768, 14471, 14471,
   706,     4,   706,   706, 12554, 12554,   706,   706,     4,-32768,
  1271,-32768,    53,  1281,-32768,     4,  4083,-32768,    60,    24,
-32768,-32768,  5766,   720,-32768,-32768,-32768,-32768,-32768,   392,
-32768,-32768,   645,   940,   645,  4489,-32768,    46,-32768,-32768,
  5766,   894,   895,   900,   901,   906, 14099,   912, 12430,   823,
-32768,   977,   346,   753,-32768,   750,-32768,-32768,-32768, 12678,
-32768,  1299,-32768,  1305, 17798,-32768,    42,   769,-32768,-32768,
  1318,-32768,   697,  1318,  1322,   701,  1318,  1322,  5766,  1318,
-32768,-32768, 10784, 17550,-32768,-32768,   944,   239,-32768,-32768,
   935, 17550,  5766,   942,-32768,-32768,  1317,  1319,  1307,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768, 12802, 12802,-32768,
-32768,-32768,  1794,-32768,-32768,  1282,   283,-32768,-32768,   261,
-32768,-32768,-32768,-32768,   957,   959,-32768,-32768,  1382,-32768,
-32768,  1382,   956,-32768,-32768, 13851,   588,  8637, 12306,  -263,
  9792, 17798,-32768,-32768, 17798,-32768,   792,   773,   799,   974,
   816,-32768,-32768,   975,    69,-32768,-32768,-32768,  7174,  7174,
  5766,-32768,-32768, 17054, 17054, 17054, 17054,   937,  5766,  5766,
 16305,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   783,
 17054,  1359,  5766,  3349, 16305,   937,-32768, 14843,-32768,   137,
-32768,-32768,-32768,  5766,-32768,  5766,  5766, 16305,  5766,  5766,
  5766,  5766,  5766,  5766,  5766,  5766,  5766,  5766,  5766,  5766,
  5766,  5766,  5766,  5766,  5766,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  5766,  5766,-32768,-32768,   982,
  5766,-32768,  5766,   984,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768, 17550,-32768,   788,
   987,-32768,-32768,-32768, 12306, 12926,-32768, 12926, 12430, 11505,
  5766,  5766,  5766,   990,-32768,-32768, 17550, 17550,-32768,   817,
 12430, 17054,   756, 17798,  8637,  1997, 16724, 17550,-32768,   798,
  5766,  1082,-32768,-32768,   878,-32768,-32768,  1281,    81,-32768,
 10784,-32768,-32768,  1384,  1404,-32768,-32768,-32768,-32768,-32768,
-32768,   486,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,  1520,-32768, 12554,  5766,  -131,-32768,
-32768,-32768,  1415,-32768, 17054,  1397,  1399,-32768,-32768,-32768,
-32768,    79,-32768,-32768,-32768,-32768,-32768,  1301,-32768,  1238,
-32768,-32768,-32768,  5766,    74,-32768,-32768,-32768, 17798,  1421,
 17054, 17054,-32768,   869,-32768, 17054,   836, 17550,-32768, 17798,
  5766,   -89,-32768,   903,-32768,   245,-32768,   997,-32768,  1000,
  5766,   447,-32768,-32768,  -180,-32768,  1447,-32768,   941,-32768,
 17550,-32768,-32768,-32768, 17798, 17054, 17054,   134,   239,  1336,
   472, 17550, 10784,-32768,   947,-32768,-32768,  1456,  1439,  1105,
-32768,-32768,-32768,-32768,-32768,  1175,  1175,    92,   961,-32768,
 17798,-32768,-32768, 13975, 13975,-32768,-32768,-32768, 17798,-32768,
 17798,  -109, 13975,-32768,    40,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   674,-32768,-32768,-32768,-32768,    72,    72, 15148,   345,-32768,
   602,-32768,   261,-32768,  1382,-32768,-32768,  1053,  1382,  1055,
 14223,-32768,   897,   131,-32768, 12430,   945,-32768,-32768,   747,
-32768,-32768,-32768,   978,-32768, 17798, 17798,-32768, 17798,-32768,
-32768, 16305,  4489,  1136,  1140,  1141,   191,  -109,  1145,  4078,
  9519,  1602,  1147,  1148, 15747,-32768,  1150,  1152,  1153,-32768,
  5766,  5766,  5766, 16009,  5766, 16110, 16187, 16227, 11286, 16407,
 16671,  5158,  5671, 16376,  3042,  3270,  2524,  4112,  2872,  7174,
  7174,  7584,  1649,  3460, 16305, 16305,   937, 16305, 16305,   937,
  4489,-32768, 17798,-32768,   911,-32768,-32768,-32768,-32768,   890,
-32768,  1509,  1516,-32768,  1517,   965,  5766,-32768,-32768,   946,
  1524,-32768,  1081,   939,  1322,-32768,  1174,   167,-32768,  1139,
-32768,-32768,   950,  1149, 17798,-32768,-32768,  1142,-32768,   321,
  5766,-32768, 17798, 17798,  5766, 16930,     4,  1531,  1025,  1522,
  1523,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1155,-32768,-32768,
-32768, 17550,  1052,  4740,-32768,-32768,-32768,  1519,  5766,   645,
 15024,-32768,-32768,  1262,  4489,  1198,  1555,  1204,   193, 17798,
  1209, 12430,-32768,  4489,  1168,-32768,-32768,  1252,-32768,  5766,
   -70,-32768,  1017,-32768,-32768,   152,-32768,  5766,-32768,-32768,
   993, 12182,-32768,   996, 17798,  1577,  7014,-32768,-32768,  -125,
-32768,  1322,  1322,   962,-32768,  1075,  1080, 17054, 17054,-32768,
-32768,-32768,-32768,-32768,-32768,   -17,   317,-32768,   161,-32768,
-32768,-32768,-32768, 17054,   468,  1593,  1574,-32768, 12430,  1383,
 11810,  1165,  1533,     5, 13050,-32768,   -42,-32768,-32768,-32768,
  1212,    27, 13975,   114,-32768,  1024,  1016,-32768,-32768,-32768,
  8513,  1060,   522,-32768,-32768,-32768,-32768,  1216,  1027,  1612,
-32768, 14347,-32768,-32768,-32768,-32768, 17550,   122,-32768,-32768,
-32768,  1014,   345,-32768, 17798, 17798,-32768,-32768, 17798,   558,
-32768,-32768,-32768,  1026,  1032,  3649,    16,-32768,-32768,  1430,
-32768,    16,-32768,  1274,  -180,  9792,-32768,  1620, 12430,  5766,
-32768,  1625,-32768,-32768,-32768,-32768, 11257,-32768,-32768,-32768,
  1630,-32768, 16305,-32768,-32768,-32768,-32768,  8513,-32768,-32768,
   687,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   687,-32768,-32768,-32768,-32768, 16305, 16305, 16305,   687, 16305,
   687,   687,   687,  5766,  1277,  5766,  1278,-32768,  1043, 11257,
 11934,-32768, 12430,  5766,  5766,  5766,  5002,  1634,  9544,-32768,
-32768, 12430,-32768,  1056, 17798, 17798,-32768,-32768, 17798, 17798,
-32768,   745,-32768,-32768,   263,-32768,  1057,  5766,-32768,-32768,
-32768,  1633,-32768,-32768,-32768,-32768,-32768, 17798,  1322,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768, 17550,
-32768,-32768,  3240,-32768,-32768,-32768,  1348,-32768,-32768,-32768,
  1337,  1338,  1222,  1064,  1339,  1257,-32768,-32768,     8,  1328,
-32768,-32768,-32768,-32768,  1252,-32768,-32768,-32768, 11381,   182,
-32768,-32768,-32768,  1456,  5766,  1275,  9916,-32768,-32768,    84,
    88,-32768,   579,-32768,-32768,  1685,-32768,-32768,  8513,-32768,
-32768,  1268,-32768,-32768,  1283,  1284,  1285,  1292,   -76,-32768,
  1667,-32768,-32768,-32768,  1912,  1287,-32768,  1182,  1059,-32768,
  1672,     4, 17798,-32768,  1687,-32768,  1694,  1062,  1062,  1062,
  1062,  1155,-32768,-32768,  1695,-32768,-32768,-32768,  1696,-32768,
-32768,-32768,  1062,    61,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   203,-32768,  1678,-32768,-32768, 13975,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,  1143,  1156,   -12,-32768,   -42,-32768, 13975,
  1118,-32768,  6521,-32768,-32768,  1308,-32768,-32768,-32768, 17798,
 17798,  1700,-32768,  2637,  9420,  5766,-32768,  5766,-32768,-32768,
-32768,-32768,-32768,-32768,-32768, 13975,-32768, 13975,  -119,  1120,
  1122,  1707,-32768,  1714,-32768, 17550, 17798,   109,   109,-32768,
-32768,  1716,-32768,  1716,   642,   642,  1716,-32768,-32768,  2049,
  1751,-32768,-32768,-32768,    74,    74,    74,  1703,    74,    74,
    74,    74,    74,    74,  1704,-32768,  1710,    74,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,  3649,-32768, 17550,  1151,
-32768,  1323,  2049,  1718,-32768,  1720,  1715,  1721,  1724,  1726,
  1727, 13174,  1430,-32768,  1323,-32768,-32768,  1166, 12430,  1746,
-32768, 17798,  1358,  1361,  1362,  1363,  -175,   242,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  1269,-32768,  1405,  5766,   127,
-32768,-32768,  1407,  1408,  1413,-32768,  1417,-32768,-32768,-32768,
 16305,   247,-32768,   251,-32768,  1418,  1742,   264, 12430,  1769,
-32768,-32768,-32768,-32768,  5766,  1251,  1541,  5766,-32768,-32768,
-32768,-32768, 10040,  1429,   263,   856,   856,  1784,  -178,-32768,
  1788,-32768,-32768,-32768,   856, 17798,  1286, 10164,  1790, 17798,
  -160, 10784,  1586,   287,-32768,  1075,  5766,-32768,  1441,  4489,
 17550,-32768, 14719, 17798, 17550,-32768,  1442,  4489,-32768,-32768,
     8,  1328,-32768,  1155,-32768,-32768, 12058,-32768,-32768,  1264,
-32768,-32768,  1379,-32768,  5253,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1213,  1092,   -95,
  1409,   -95,   -95,   -95,   -95,  8513,  7014,  8513,  8513,  8513,
  8513,-32768,-32768,-32768,-32768,-32768,-32768,-32768, 12306,-32768,
  1401,   349,-32768,-32768,-32768,  1221, 17054,  1062, 17054,  1062,
-32768,-32768,-32768,-32768,-32768,   -17,  1062,   317,  1062,-32768,
     4,   468,-32768,  1453,  1416,  -109,   674,  1165,  1165,-32768,
-32768,-32768,-32768,   290,-32768,  1377,-32768,  1419,  6028,  1419,
  7265,  1810,  1812,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   212,  2403, 13975,  -137,-32768,  1225,-32768,  8513,  1309,-32768,
  1814, 13975,    37,-32768,  1823,  1817,-32768,-32768,-32768,-32768,
  1311,-32768,   294,-32768,  1241,-32768, 17798, 17798, 14347, 17550,
-32768,  1716,-32768,-32768, 17798,   642,   642,-32768,-32768,   642,
  1657,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    51,  1834,-32768,
 17550,  1627,-32768,  1657,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768, 12430,-32768, 13975, 13975,
 13975,  6521,  1815,-32768, 11257,  1603,  1254,-32768,-32768,  1685,
  1685,-32768,  1446,-32768,  1448,  1452,-32768,  1454,  1459,-32768,
  1460,-32768,-32768,-32768,    45,-32768,-32768,-32768,  5515,-32768,
-32768, 13298,  1353,   104,-32768,-32768,-32768,-32768,  5766,-32768,
-32768,-32768,  1423,-32768,   138, 12430,-32768,  1855,  1472,-32768,
-32768,  1512,-32768,-32768,-32768,  1356,-32768,-32768, 17798,   856,
  8637, 10288, 17798,   856,-32768,-32768, 17054,-32768,-32768,  5766,
-32768,-32768,-32768, 17054,  1531,  1665,-32768,-32768,     4, 16305,
  1567,-32768,-32768, 10784,  1486,-32768,-32768,  4489,-32768,  1528,
-32768,-32768,-32768,   182,-32768,  1075,-32768,  5766,-32768,  8637,
-32768,  1281,-32768,  1693,-32768,-32768,-32768,-32768,  8513,-32768,
  8513,  8513,  8513,  8513,  1912,   295,-32768,  2264,  2264,  1011,
  1930,-32768,  1473,-32768,  1571,-32768,  1869,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768, 17798,-32768,
  8513,-32768,-32768,-32768,   674, 13975,-32768,-32768,  1783,  1457,
-32768,-32768,    89,   351,-32768,-32768,  6521,  6521,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  8513,  1499,
-32768,  1504,   -68,  6279,   300,-32768,-32768,-32768,-32768, 17798,
-32768, 17550,-32768,  7527,-32768,   307,-32768,  6521,-32768, 13975,
  7769,-32768,-32768, 13975,-32768, 17674,  1314,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,  1725,-32768,-32768,-32768, 17550,  1834,
-32768,-32768,-32768, 17550,-32768, 17550,-32768,-32768,  1926,-32768,
  1723,  1725,  1729,-32768,  1545,  1919,-32768,   310,-32768,   312,
   148,   132,-32768,-32768,-32768, 10412,  1340,  -144,  1900,  1900,
  1909,  1900,  1900,  1916,-32768,    58,-32768,   543,  1456,-32768,
 13479,  1938,-32768,-32768, 15272,  1608, 17798,  1357,   -95,-32768,
-32768, 16305,  1939,     4,  1607, 12430,-32768,  5766,-32768,  1414,
  1927,     4,-32768,-32768,   222,-32768,-32768,-32768,-32768,    97,
  1596,  1322,-32768,-32768,-32768, 10784,-32768,  1599,  1531,  1561,
-32768,  1567,-32768,-32768,-32768,-32768,  1748,   145,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,  1098,  8513,  1302,  1330,
  1508,  1903,  8513,-32768,-32768,-32768,-32768,  1075,-32768,   326,
-32768,    82,   674,   674,-32768,-32768,  -109,-32768,-32768,  -109,
-32768,  1812,-32768,  1912,    35,-32768,    35,-32768,-32768,-32768,
  8513,    58,  8020,-32768,-32768,-32768,  1419,-32768,-32768,-32768,
  1912, 13975,-32768,  1563,-32768,-32768,  1957,-32768,  1451,  6772,
-32768,  1961,-32768,-32768,  1912, 13975,  1960,-32768,  1810,-32768,
-32768, 10784,-32768,-32768,   260,-32768,-32768, 17798,-32768,-32768,
-32768,  2005,  2005,-32768,  2005,-32768,  2005,  2005,-32768,-32768,
-32768,-32768,  1708, 13975, 13975,-32768,-32768,-32768,  1949,-32768,
-32768,  1558,  1693,  1962,  1693,-32768,  1984,  1984,   327,  1631,
  1984,-32768,  1642,-32768,-32768,-32768, 13975,-32768,  1594,-32768,
-32768,   543,  1646, 13298,-32768, 13298,-32768,-32768,  8513,-32768,
  1595,-32768,  1603, 13603, 11810, 17054,-32768, 12430,-32768,  1651,
  4559,  1611,-32768,-32768,-32768,  1425,     4,-32768,    -7,  1531,
-32768,-32768,  1661,-32768,  1567,   182,-32768,-32768,-32768,   328,
-32768,-32768,-32768,-32768,  1912,-32768, 17798,-32768,  1451,-32768,
-32768,  8513,  8513,   330,-32768,-32768,   333,  2307,  1616,-32768,
-32768,-32768,  8262, 17550,   104,   337,  1092,  7769,-32768,  1618,
  1531, 17674,-32768,-32768,-32768,-32768,-32768,  2005,-32768,  2005,
-32768,-32768,-32768,-32768,-32768,  1635,-32768,-32768,  1669,-32768,
  2007,  1671,  1674,  2009,-32768,-32768,  1681,-32768,-32768,  1644,
  6521,-32768,-32768,-32768,   338,-32768,  2043,-32768,  1912,  6521,
-32768,-32768,-32768,-32768,  2045,-32768,   204,-32768,-32768,-32768,
   463,-32768,-32768, 14471, 14471, 14471, 14471, 14471, 14471,-32768,
  2027,-32768,   339,-32768,  5766, 10536,-32768,-32768,-32768,    13,
-32768,  1567,  4489,  1567,-32768,-32768,  1841,-32768,     4,-32768,
   104,   127,   127,    58,-32768,-32768,  8513,    58,-32768,-32768,
   340,-32768,  1912,-32768,-32768,-32768,-32768,  7769,-32768,-32768,
-32768,-32768,  1461,-32768,-32768,-32768,-32768,  1699,-32768, 13975,
   154, 13298,-32768,  8513,  1810, 13603,-32768,-32768,-32768,-32768,
-32768,-32768,   581,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,  4559,-32768,  2050,-32768,-32768,    86,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1701,-32768,  1912,
-32768,-32768,  8262,-32768,   342,  1693,-32768,   344,-32768,-32768,
-32768,-32768,   635,   635,-32768,-32768,   635,-32768,  5766,-32768,
  1711,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1712,
-32768,-32768,   350,-32768, 10784,-32768,  1531,  2054,  2059,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,    31,-32768,   101,  -154,-32768,-32768,  -871,
  -460,-32768,-32768, -1488,-32768,-32768,-32768,-32768,  -778,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768, -1981,-32768, -1390,-32768,   105,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   331,-32768,-32768,-32768,
-32768,   847,-32768,   572,-32768,-32768,   187,-32768,-32768,  2073,
-32768,  2074,  1636,-32768,-32768,-32768,-32768,-32768,   396,    73,
-32768,   394,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,  -105,-32768,  1986,-32768,  1792,    90,-32768,  1936,-32768,
-32768,  1935,-32768,  1886,-32768,-32768,-32768,  1808,  1705,  1410,
  1805,  -117,-32768,-32768,-32768,-32768,-32768,  1420,  -459,-32768,
-32768,-32768,-32768,  -169,  1752,  1910,  1908,-32768,-32768,  1750,
-32768,-32768,  1796,-32768,-32768,-32768,-32768,  1800,-32768,-32768,
-32768,-32768,  -347,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,  1749,-32768,  1755,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,  -925,-32768,-32768,  -695,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,  -257,-32768,-32768,   665,-32768,  -935,  -841,
    39,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   483,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,  -544,-32768,-32768,-32768,
-32768,-32768,  1568,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  1167,-32768,-32768,-32768,-32768,
   559,-32768,-32768,-32768,-32768,-32768, -1434,-32768,-32768,   556,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -866,  -707,   481,   722,-32768,  -557,   214,  -852,   784,-32768,
   169,-32768, -1709,   -22,  -393,-32768,-32768,  1344,  1161, -1652,
  -713,  1083,-32768,-32768,-32768,   207,   913,-32768,-32768,-32768,
-32768,-32768,-32768,    77,-32768,  -185,-32768,   915,-32768,   646,
-32768,   386,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   491,-32768, -1238,-32768,   643,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    85,-32768,    66,
-32768,-32768,-32768,-32768,  1031,-32768,-32768,-32768,-32768,-32768,
-32768,  -317, -1425,-32768,-32768,-32768,-32768,   -26,-32768, -1583,
-32768,  -860,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1932,
   -25,-32768,-32768,-32768,-32768,-32768,-32768,  -254,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,  2097,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1488,-32768,
-32768,-32768,-32768,-32768,   686,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  -515,  1655,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  1946,-32768,-32768,   -92,-32768,
-32768,   692,-32768,-32768,   964,  -159,  2034,-32768,-32768,-32768,
-32768,  -171,-32768,  -747,  1494,   948,-32768,  -495,-32768,   698,
  1258,    14,  -215,-32768,  -974,-32768,  1078,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1033,-32768,   666,
-32768,  -457,-32768,-32768,-32768,-32768,-32768,-32768,  -556,-32768,
-32768,-32768,-32768,-32768,-32768,   146,-32768,  1100,  -220,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   281,-32768,  -207,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,  1329,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,  -859,-32768,  1034,  1176,-32768,-32768,   296,-32768,
  -480,-32768,-32768,   314,   634,-32768,-32768,-32768,-32768,-32768,
-32768,  -356,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  -406,-32768,  1234,   580,    28,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
 -2072,  -156,-32768, -2377, -2215,-32768,   412,-32768,-32768,-32768,
-32768,-32768,-32768,  -608,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -567,-32768,-32768,
-32768,-32768,-32768,  1279,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   384,-32768,-32768,-32768,  -446,-32768,-32768,-32768,-32768,
-32768,-32768,  -346,-32768,-32768,  -551,-32768,    49,-32768,-32768,
-32768,-32768,  -371,-32768,-32768,-32768,-32768,-32768, -1312,-32768,
-32768,-32768,-32768,-32768,-32768, -2376,  -196,-32768, -1894,    26,
-32768,-32768, -2090,   -96,   -98,   151,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  -273,-32768,-32768,   144,-32768,
 -1917,-32768,-32768,-32768, -2245,-32768,-32768, -1672,-32768,  -691,
-32768,  1007,  -471,  -335, -1478,-32768, -1768,-32768,-32768,-32768,
-32768,-32768,-32768, -1257, -2423,-32768,-32768,-32768,-32768,-32768,
-32768,-32768, -1974,-32768,   120,-32768, -1598,-32768,  1310,-32768,
-32768,  -816,  -365,-32768, -2480,-32768,  -251,   153, -2096, -1340,
 -1609,   147,  -532,  1191,  -234, -2309,-32768,-32768,  1028,  -543,
-32768,-32768,  -388,  1321,-32768,   216,-32768,-32768, -1232,   -99,
-32768,-32768,-32768,-32768,  -508,  -475,  -576,   690,-32768,     6,
  1403,   -31,-32768,-32768,-32768,-32768,-32768,  -711,-32768,  -539,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -704,   863,
  1856,-32768,-32768,-32768,-32768
};


#define	YYLAST		18422


static const short yytable[] = {    79,
    84,   175,   185,   399,  1035,    13,   855,  1178,  1179,    88,
  1180,    87,  1183,  1184,  1172,   737,   721,  1181,  1704,   131,
  1678,  1168,   141,  1268,  1199,  1015,   246,  1648,  1205,   864,
  1536,  1537,   835,   757,   291,   897,   970,  1278,  1980,   903,
    13,  2381,   900,  2385,   913,  -577,  1351,  2022,  2383,  2056,
  1224,  1770,  1771,  1219,    92,  1222,  1030,   292,  2644,  1774,
    91,  1212,   862,    84,  1205,  1205,  1842,   313,  1577,   955,
   104,   107,   958,  1273,  1770,  1771,  1855,   292,   293,   294,
   292,  2644,  1774,  1198,   297,  1451,  2158,   129,   315,  2415,
   292,   298,   299,   101,  2387,   737,   292,   292,   753,  1125,
   138,  1205,    13,   101,  1738,  1206,   292,  1148,  2066,  1361,
   292,  1207,  2068,  1747,  2121,   164,   183,   866,  1452,   716,
  1453,  1939,  1454,   169,   949,  1131,  1896,   811,  1136,  1137,
   811,  2158,   183,   183, -1692,   183,  2629,  1288,  1451,  1290,
   820,  2461,  2495,   392,   811,   394,    13,  1862,   811,   183,
   244,  2569,  2372,  2387,   402,   837,  1017,  2417,  1976,  2387,
   811,   410,   820,  1294,  2341,  2342,  2343,  2344,   848,   820,
   762,  1904,   412,  1513,  1907,  1260,   861,  1190,  1191,  1584,
  1482,   865,   396,   176,   177,   178,   179,   180,  1211,   902,
   416,   274,   719,  1025,   167,  1205,  2303,  1205,  1562,  1563,
   848,  1976,   979, -1692,   848,  2601,  1296,  2122,   848,  2738,
  2010,  2740,  2716,   820,   377,  1269,   820,  1578,  1507,   145,
  2389,  2475,  2390,  2391,  2392,  2393,  2394,  2395,  2115,   317,
   318,  2336,   166,  1155,  2815,   321,   322,  1754,   176,   177,
   178,   179,   180,  1273,    89,   971,  2235,  2291,   971,  1377,
  2233,  2269,   325,  2634,  1859,  2269,   145,  2132,  1541,   214,
  1867,   429,  2710,   353,  2722,  2859,  1513,  2026,  2235,   710,
   274,  1161,   425,   426,    95,   326,  1704,  2754,  1541,  2756,
  1346,   483, -1692,   441,    95,  2570,  1585,  2571,  1023,   714,
    34,  2307,   711,   373,  2376,   430,   376,  1586,  2424,  2543,
  2378,   380,   327,  2566,  2582,  2568,   815,  2580,  2407,    36,
   725,  2596,   972,   971,  2625, -1692,  2625,  2594,  1587,   824,
  2866,  2086,  1347,   971,  2594,  1588,  2309,  2599,   314,    15,
  2697,  2744,  2543,  1579,  2804, -1692,  -577,  2804, -1692,  1024,
  1488,  2718,  2832,  2853,  2873,  1162,  2718,  2337,  2624,  1018,
   717, -1692,   422,  1261,  1196,  1868,  1514,   973,    14,  2389,
  1274,  2390,  2391,  2392,  2393,  2394,  2395,  2088,  2089,  2090,
  2091,  2723,   260,   353,   132,   353,   176,   177,   178,   179,
   180,  2135, -1475, -1692,  1274,  1237, -1692,  1141,  1813,  1545,
    86,   362,  2743,   364,  1142,  2747,  1156,  1776,   145,  1814,
  2555,  1538,    89,  2487,  1539,  1197,  1540,  2174,  -577,  1545,
  2292,  2476,  1777, -1477,  2092,  2093,  2094,  2095,  2096,  2097,
  1776,  1187,  1417,  1458,  1417,  1302,  1541,   478,  1194,  1305,
   478,   397,  1483,   709,  2396,  1777,  1542,   143,   478,  1343,
  2875,  1436,   162,   414,  1580,  1585,   163,  2561,   405,  1514,
  2635,   260,  2895,  1821,  2572,  2880,  1586,  1241,  2338,   478,
   405,   165,  2182,   701,    13,   727,  2027,  2304,   734,   739,
  2323,   741,  2382,   902,   744,  1543,  1510,  1587,  2496,  1544,
  2711,  1761, -1692,  2904,  1588,   750,  1364,  1365,  1366,  1480,
   973,   770,   805,  2594,  2869,  1564,  1940,   393,  2872,   395,
  1039,  1040,  2817,  1373,   750,   184,  2628,  1367,   403,  1462,
  1345, -1692,  2879,  1051,   805,   411,   774,   750,  1863,  1064,
  1065,   249,   372,  2719,  1627,  2630,   413,   838,  2418,  2373,
  2374,  1720,  1078,  1289,   471,  1013,   974,  1825,  2688,   974,
  2684,   856,   858,   737,   417,  2133,   720,  1026,   734,  1647,
  2397,  1742,  1262,   793, -1692,  2436,   805,  1545,   856,   856,
  1694,  2123,   904,   939,   167,  1208,   805,   805,  1856,   933,
   805,  2665,    84,  2396,   805,   821,   805,  1801,  2700,  2701,
   805,   805,  1764,   950,  2488,   950,   856,  1263,   950,   856,
  1675,   950,   168,  1677,  2489,  1420,   902,   865,   902,   855,
  2236,  2412,  1571,  1572,   974,  2270,  2437,  1434,  1546,  2271,
   170,  1582,  1435,  2501,   974,  2676,  2525,   895,   975,   976,
   977,  2594,  2274,   295,  1421,  1149,  1415,   914,   920,   978,
  1734,   937,  1225,  2367,  1897,   941,  2503,   943,  2157,  2262,
  2508,   947,   948,   295,   623,  2308,   295,  1485,  2377,  2312,
   849,  1351,  2425,  2544,   849,  1209,   295,  2320,  2583,   737,
  2831,  2905,   295,   295,  1138,  2597,   174,  1455,  2626,  2835,
  2627,  2646,   295,  1498,  2406,  1456,   295,   182,  1501, -1692,
 -1692, -1692, -1692, -1692,  2698,  2745,  2798,   999,  2805,  2397,
   210,  2806,  1499,   786,  2715,  2816,  2833,  2854,  2874,  1008,
  2894,   478,  2896,  2795,  1518,   788,   789,  2645,  2837,  2335,
   734,    21,  1538,  1127,   791,  1539, -1692,  1540,   245, -1692,
 -1692,  2594,  1817,   248,   843,  1029,  1532,  1533,  1541,   276,
  1883,   850,   284,  1818,  2398,   805,   805,  1541,   285,   813,
   134,   135,   347,  1239,  1493,   287,  2400,  1542,   805,   288,
  2457,  2459,  2459,   822,   805,   805,  1976,   827,   289,  2838,
  1463,  2552,    14,    15,  1464,  1465,  1466,   805,  1826,   841,
   134,   135,  1036,  1037,  1038,   953,  2286,  2840,   956,   307,
  1827,  2841,   308,  1362,  1467,  2371,  1543,   134,   135,  2885,
  1544,  1370,  1371,  1547,  1029,   310,  2705,  2638,  2705,  2640,
  2641,   311,  1628,  2705,  2801,  1375,   312,   938,   471,  2647,
  2861,   942,  2863,   348,   954,   946,  1384,   957,  1386,  1387,
   960,  1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,  1396,
  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,  2696,  1876,
   805,   805,   329, -1692,  1828,   354,  1541,   710,  1405,  1406,
  1908,  1829,   338,  1408, -1692,  1409,  1188,  1189,  1344,  1545,
  1192,  1193,  1674,  1877,  2035,  1676,  1878,   357,  1545,  1001,
   711,  1522,   135,  2398,   805,   358, -1692, -1692,     1,  1697,
   805,  1866,  2648,  1698,  1879,  1636,   988,  1638,    22,   359,
  1830,   994,   995,   805,  1468,  2840,   989,  2556,   805,  2841,
 -1692,   895,    23,  1338,  1235,  2023,  1340,  2867,  2868,   176,
   177,   178,   179,   180,  1831,   360,  1719,   371,  1469,  1546,
   361,  2401,  1252,   365,  1832,  1833,   366,  2521,    24,   369,
  2105,  1592,  1593,   370, -1692,  1204,   805,  1470,  1710,  1711,
  1834,   895,  2402,     2,     3,  2603,     4,     5,   990, -1692,
   805,     6,   374, -1692,   914,  1600,  1601,   375,  1746,  1227,
   381,  1835,   382,   991,  1836,  1837,   975,   976,     7,     8,
  1838,   385,  1471,  1214,  1215,  1216,  1217,  1545,    25,   390,
  1804,  1806,  2467,  2468,   400,  1699,     9,    10,  1700,  1880,
 -1692,  1472,  1473,   734, -1692,   401,   734,   404,  1350,  1353,
  1438,  2649,   741,   407,   408,  1605,   409,  1474,   415,  2137,
  1541,   420,   418,   421,  1824,  1845, -1692,   423,   805,   427,
   428,   856,   856,   856,   856,   443,   805,   805,   433,  1839,
  2091, -1692,  2172,   435,   436,  2705,   437,   442,   856,  2705,
   805,  1840,  1881,   398,   445,   446,   447,   449,  1475,  1605,
  1882,   805,   992,   805,   805,  1709,   805,   805,   805,   805,
   805,   805,   805,   805,   805,   805,   805,   805,   805,   805,
   805,   805,   805,   451,  2092,  2093,  2094,  2095,  2096,  2097,
   452,  1476, -1692,   805,   805,  1960,   462,   463,   805, -1692,
   805,   464,  2802,  2803,  1977,   465, -1692,   466,   467, -1692,
   468,   469,   470,  2712,  1547,  1643,   474,   475,  2088,  2089,
  2090,  2091,   734,   476,  2088,  2089,  2090,  2091,   805,   805,
   805, -1692,  1570,  1666,  1667,  1668,   477,  1670,  1574,   856,
   484,  1437,   486,  1441,   856,   715,   718,  2000,   805,  2001,
   722,  1545,   724,   723,   726,  2734,  2735, -1217,  2012,  1003,
  1004,  1606,  1011,  1643,  2125,  2092,  2093,  2094,  2095,  2096,
  2097,  2092,  2093,  2094,  2095,  2096,  2097,  1016,   865,  2160,
  1607,  1608,  1018,    93,  1019,   805,  1021,  1022,  1041,  1422,
  1423,  1424,   856,  1027,  1043,  2768,  1033,  1135,  1139,   902,
  1609,     1,  1044,   250,  1045,  1606,  2175,  1046,  1047,  1446,
  1048,   805,  1049,  1050,  1061,  1062,  1496,  1063,   856,   856,
  1066,  1140,  1071,   856,  1607,  1608,  2702,  1505,   805,  2703,
  1072,  1073,    94,  2332,  2065,  1074,  1075,  1128,   805,  1613,
  1076,  1733,  1077,  1619,  1609, -1692,  1481,  1643,  1079,   251,
   252,  1143,   950,   856,   856,  1144,  1643,   253,  1625,  2366,
  1152,  1146, -1692,  2788, -1692, -1692,     2,     3,  1147,     4,
     5,  1154,   914,  1151,     6,  1157,  1166,  1171,  1566,   187,
  1185,  1029,  1029,   731, -1692,  1195,  1575,  1213,  1575,  1506,
  1029,     7,     8,  1697,  2305,  1198,   749,  1698,  1238,  1521,
  1220,  1228,  1229,   296,  1981,   301,  1241,  1230,  1231,     9,
    10,  2238, -1692,  1232,  1982, -1692,  1249, -1692,   188,  1236,
  1240,  1264,  1986,   816,  1988,  1989,  1990,  1251,  2088,  2089,
  2090,  2091,  1265,  2479,  1266,   189,  1205, -1692,  1267,   833,
   834,  1272,  1276,  1634,  1635,   840,  1635, -1692,   842,  1279,
   805,  1280,  1282,  1281,  1328,  2845,  2088,  2089,  2090,  2091,
  1336,  2457,  1337,  1341, -1692,  1356, -1475,  2768,   805,   805,
   805,  1357,   805,   190,  2788,  2092,  2093,  2094,  2095,  2096,
  2097,  1358,  1360,  1359,  1368,   191, -1692,  1372,  1374,  1407,
 -1692,  1410,  1413,  -256,  1414,   192,   849,  1427,   805,  1699,
  1679,  1445,  1700,  2092,  2093,  2094,  2095,  2096,  2097,  1447,
  1449,  1460,  2862,   193,   805,    27,    28,    29,    30,    31,
    32,  1433,    33,   194,  1541,  2226,  1991,  2845,  1991,  1484,
  1461,  1486,  1707,  1487,  1489,  1491,  1500,  1502,   805,   195,
  1714,  1715,   805,   856,  2194,  2195,  2196,  2515,  2198,  2199,
  2200,  2201,  2202,  2203,  1497,  1517,  2514,  2206,  1519,  1510,
  2335,  1525,  2193,  1527,   330,  2275,  2689,  1274, -1692,  1554,
  1451,   805,   865,  1556,  1559,  1688,   805,   140,   902,   196,
  -256,  1557,   805,  1565,   140,     2,     3,  1744,     4,     5,
  1616,   805,  1620,     6,  1683,  1626,  -256,   805,  1629,  1713,
  1630,   902,   197,  1424,  1644,   805,  1681,   254,  1645,  1646,
     7,     8,  1252,  1649,  1789,  1660,  1661,   198,  1663, -1692,
  1664,  1665,  1687,  1684,   199,   856,   856,   200,     9,    10,
  1685,  1686,  1204,   255,  2088,  2089,  2090,  2091,  1690,  -256,
  1691,   856,  1693,  1692,  1689,  1273,  1695,   201,  2239,  1708,
   202,   331,   203,  1696,  1721,  1545,  1723,  1724,  1753,  2358,
  1029,  2360,  1725,  1729,  1732, -1692,  1739,   332,  1789,  1740,
  1944,   204,  1741,  2192,  2598,  1748,  2519,  1745,  -256,  1891,
  2485,  2092,  2093,  2094,  2095,  2096,  2097,  1945,  1946,  1751,
   205,  1757,  1903,  1903,  1767,  1947,  1903,  1765,   110,  1769,
   978,  1801,  1803,  2240,   256,   754,   754,  1843,  1844,  -256,
   333,  1846,  1302,  1350,  1854,  2241,   339,   805,  -256,  1860,
  1871,  1875,  1870,  1886,  1967,  2242,  1889,  1948,  1911,   868,
  1888,  1900,  2667,  2352,  1912,  1789,  1949,  1959,   869,  1962,
  2675,  1997,  1957,  2243,  1979,  1993,  1995,   870,  2008,   334,
  2030,  2038,   871,  2244,  2013,  2028,  2245,  2043,  2041,  2042,
  2045,   805,  2044,   805,  2046, -1692,  1950,  1967,  2441,  2246,
  2691,   805,   805,   805,   805,  2080,  1967,  2061,  1961,  1095,
   335,  2087,  2014,  1707,  2099,  1052,  2019,  2019,   977,   336,
  2082,  2083,  2084,  2454,   872,   805,   257,   754,  2692,  2085,
  2100,  2107,   873,   340, -1692,  2031,  2104,   965,  2109,  2116,
  2118,  1951,  2124,  2136,  2158,  2153,  2128,  2247,  2177,   341,
  2178,  2179,  1096,  1097,  1098,  1099,  1100,  1101,  2180,  2129,
  2185,  1643,  2002,  2003,  1424,  2006,  2197,  2204,  1102,  1103,
  1104,  2442,  2497,  2205,   865,   865,  2212,  2248,  2211,  2217,
  1952,  2215,   805,  2216,  2063,  2218,  2029,  2249,  2219,   874,
  2220,  2221,   342,  2227, -1639,  2229,  1789,  2510,  2230,  2231,
  2232,  2273,  1053,  2260,  2512,  2265,  2266,  2250,  2680,   258,
  2251,  2267,  2252,  2276,   875,  2268,  2272,   259,  1054,  2310,
  2106,   876,  1643,   877,  2278,  2279,   111,  2285,  2289,  2485,
  1643,   343,  2293,   878,  2300,  2443, -1692,  2444,  2297,  2311,
  2319,  2253,  2328,  2060,  2330,  2787,  2340,  2334,  2354,  2357,
  2254,  2368,  2445,  2369,  2378,  2387,  2380,   879,  2388,  2410,
  2446,  1055,   344,  1029,  2447,   880,  2414,  2420,  2412,  2421,
  2422,   345,   730,   730,   965,  2426, -1692,  1967,  2439,  2462,
  1789,  2464,  2466,  2469,  1863,  2470,   730,  2155,  1575,  2471,
  2448,  2472,  1967,   805,  2721,   805,  2473,  2474,  2493,  2498,
  1056,   881,  1334,  1967,   730,  1029,  2693,   730,  1105,  2499,
  2500,  1106,  2501,   730,  1903,  2513,  1126,   730,  2516,  2520,
 -1692,   730,   972,  1291,  2191,   730,  2523,   882,  2548,   730,
   730,  1057,   730,  2558,  2382,   730,  2565,   730,   730,   730,
  1058,  2567,  2608,  2623,  2609,   730,   730,  2846,  2847,  2848,
  2849,  2850,  2851,   730,  2169,    13,  2170,  2214,   730,  2088,
  2089,  2090,  2091,  2624,  2636,   883,   730,  2865,  2088,  2089,
  2090,  2091,  2620,  2639,  2633,  1652,   884,   730,  2622,  1634,
  2642,   730,  2656,  2659,  2664,   730,  2666,  2668,    13,  2672,
   730,  2674,  2669,   730,  2678,  2750,   805,  2681,  2682, -1692,
  2713,  2714,  2485,  2262,  2485,  2718,  2092,  2093,  2094,  2095,
  2096,  2097,  2720,  2736,  2647,  2092,  2093,  2094,  2095,  2096,
  2097,   187,   805,  2233,  1292,   805,  2739,  1107,  2741,  2746,
  2284,  2751,  1293,  2092,  2093,  2094,  2095,  2096,  2097,  1294,
  2748,  1295,  1108,  1707,  2753,  2299,  1109,  2301,  2785,  2760,
  2773,  2492,  1296,  2786,   805,  2818,  1439,   805,  2070,  2794,
   188,  2316,  1653,   902,  2808,   805,  2529,  2823,  2822,  2826,
  2442,  2824,  2827,  2828,   885,   886,   887,   189,  1654,  2829,
  1297,  2830,   805,  2277,  1110,   965,  2282,  2834,   888,  2836,
  2852,   121,  2864,  2909,  2889,  2876,  1298,  2877,  2910,  2892,
  1643,  1299,  2228,  1789,  1789,  1789,  1789,  1789,  1789,  2901,
  2902,  1300,  1111,  2315,  2888,   190,   734,     1,  1301,   151,
   159,  1655,  1756,  2261,   856,  2053,   856,   191,  1509,    37,
  1112,  2015,    38,   624,  2443,  2024,  2444,   192,  2296,   133,
   367,   159,   212,   895,   215,  2071,   303,   159,  2770, -1692,
   363,  2445,   444,  2530,   368,   193,  1789,   571,  1789,  2446,
  1656,  2072,   419,  2447,  2772,   194,   159,  1006,   159,  2531,
  1967,   306,   305,   432,   389,  1789,  2505,   387,  1007,  1967,
  2485,   195,     2,     3,   438,     4,     5,  2886,  1731,  2448,
     6,  1657,   439,   889,  2427,  2428,  1891,  2907,  1994,   932,
  1658,  1901,  2431,  1332,  2073,  1909,  2004,     7,     8,  2547,
  2528,  1113,  2532, -1692,  1342, -1692,  1716,  1531,  2356,  1800,
  2011,   196,  1535,  2364,  2103,     9,    10,  1442,  1595,  1596,
 -1692,  1822,  2677,   159,   108,  1612,   323,  2621, -1692,  1002,
  2362,  1763, -1692,  2074,   197,   839,  1967,  1967,  1967,  1789,
   730,  2533,  1967,  1766, -1692,  1523,   247,  1010,  2814,   198,
  1553,  1270,  1768,  2611,  2440,  1429,   199,  1479, -1692,   200,
  1857,  1302,  2347,  2860,  2075,  2225,   805,  1419,  1303,  1029,
  1114,  2619,  2534,  2076,  1223,  1380,   805,    39,  2224,   201,
  2207,  2535,   202,   965,   203,  1956,  2763,  1492,  1355,  1998,
  1304,  2694,  2463,  2600,  2893,  1305,  2019,  2130,  2882,  2507,
  2019,  1314,  2176,   204,   856,  2819,  2733,   805,  2878,  2460,
  2752,   856,  2090,  2091,  2655,    40,    41,    42,  2486,  2563,
  2562,  2386,   205,  2707,  2399,   805,  2737,  1569,  2429,  2769,
  2699,  2881,  1321,  2690,  2411,   805,  2409,   754,  2800,  1287,
  2585,   485,     0,  2807,  1561,  1958,  1789,    43,  1789,  1789,
  1789,  1789,    44,  2088,  2089,  2090,  2091,  2092,  2093,  2094,
  2095,  2096,  2097,   730,   730,   730,     0,    45,  2511,     0,
     0,     0,    46,     0,    47,     0,  2549,     0,  1789,     0,
     0,     0,     0,  1967,    48,   965,  1737,    49,     0,     0,
    50,     0,     0,    51,  1789,  1789,  2526,     0,    52,     0,
  2092,  2093,  2094,  2095,  2096,  2097,  1789,     0,     0,     0,
     0,  1789,     0,     0,     0,     0,    53,  2155,     0,     0,
     0,  1789,  1798,     0,     0,  1789,     0,  1967,  1789,     0,
     0,  1967,    54,  1566,     0,    55,    56,     0,     0,     0,
     0,  2389,    57,  2390,  2391,  2392,  2393,  2394,  2395,  2088,
  2089,  2090,  2091,    58,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
     0,     0,     0,  2632,   747,    60,     0,     0,     0,     0,
     0,     0,    61,     0,     0,    62,    63,    64,  1029,    65,
    66,     0,  2657,     0,  2662,     0,  2092,  2093,  2094,  2095,
  2096,  2097,     0,     0,     0,   805,    67,     0,   818,     0,
     0,     0,     0,     0,   823,     0,   825,     0,     0,     0,
   832,     0,     0,   832,     0,     0,   832,     0,     0,    68,
     0,    69,    70,     0,    71,     0,   844,     0,     0,     0,
     0,     0,     0,     0,     0,  1789,     0,     0,     0,     0,
  1789,    72,    73,   893,     0,     0,     0,     0,     0,     0,
     0,   906,   909,   912,     0,  1643,  2670,   934,  1089,  1090,
  1091,  1092,  1093,  1094,  1095,   944,    74,     0,  1789,     0,
  1789,     0,     0,     0,     0,    75,    76,     0,    77,  1967,
   967,     0,     0,     0,     0,     0,     0,  1789,     0,     0,
     0,     0,     0,  1967,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,  2725,     0,  1096,  1097,  1098,
  1099,  1100,  1101,     0,     0,     0,     0,     0,  1524,     0,
     0,  1967,  1967,  1102,  1103,  1104,     0,     0,     0,  1790,
     0,  2049,  2050,     0,     0,     0,     0,     0,     0,     0,
    78,     0,  2059,     0,  1029,  2396,     0,     0,     0,     0,
     0,  1029,  1440,  1029,     0,     0,  1789,     0,     0,     0,
     0,  1967,     0,   856,     0,     0,     0,     0,     0,     0,
     0,     0,     0,  2088,  2089,  2090,  2091,     0,     0,     0,
     0,     0,    89,  1790,     0,     0,     0,     0,     0,     0,
  2111,  2112,  2113,  2114,  2549,     0,     0,     0,     0,  1789,
  1789,     0,     0,     0,     0,  2120,     0,     0,     0,     0,
  1789,     0,     0,     0,     0,  1789,     0,   967,     0,  1566,
  2092,  2093,  2094,  2095,  2096,  2097,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,  1795,     0,     0,
     0,     0,     0,     0,     0,     0,  1069,     0,  1789,     0,
  1790,     0,     0,     0,     0,     0,     0,  1789,     0,     0,
     0,  2397,     0,  1105,     0,     0,  1106,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  1129,
  2183,  2184,   805,  2857,     0,     0,     0,  2188,  2189,     0,
   805,  1874,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,  1789,     0,     0,     0,     0,     0,
     0,     0,   730,     0,     0,  1789,     0,     0,  2400,     0,
     0,     0,     0,     0,  1160,     0,     0,  1967,     0,  1029,
     0,  1789,     0,  1967,     0,     0,     0,     0,  1177,  1177,
  1177,     0,  1177,  2855,  1177,  1177,     0,     0,     0,     0,
   121,   121,     0,     0,     0,     0,     0,     0,  1874,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1789,     0,  2067,  2069,     0,     0,     0,     0,     0,     0,
     0,  1790,  1107,     0,     0,     0,   805,     0,     0,     0,
     0,     0,     0,     0,   912,     0,     0,  1108,  2287,  2288,
     0,  1109,     0,     0,     0,  1247,     0,  2295,  1091,  1092,
  1093,  1094,  1095,     0,     0,  2306,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   730,     0,     0,   967,  1129,
     0,     0,     0,  2321,  2322,     0,     0,  1277,     0,  1110,
     0,     0,     0,     0,     0,  2398,   730,  2900,     0,     0,
     0,     0,     0,  1285,  1285,  1096,  1097,  1098,  1099,  1100,
  1101,     0,     0,     0,     0,  1790,     0,  1111,     0,     0,
     0,  1102,  1103,  1104,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   159,     0,  1112,     0,     0,   140,  2079,
  2359,     0,  2361,  2401,     0,     0,     0,     0,     0,  2363,
     0,  2365,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,  2402,     0,     0,   754,   754,   754,
     0,   754,   754,   754,   754,   754,   754,     0,     0,     0,
   754,     0,     0,  1379,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,  1113,     0,  2432,  2433,
     0,     0,  2434,  2435,  1087,  1088,  1089,  1090,  1091,  1092,
  1093,  1094,  1095,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,  1412,     0,     0,  2452,     0,     0,     0,
     0,   121,     0,   121,   912,   832,     0,     0,     0,     0,
     0,  1105,  1428,   844,  1106,     0,   912,     0,     0,     0,
   159,     0,     0,  1443,     0,  1096,  1097,  1098,  1099,  1100,
  1101,     0,     0,     0,   965,  1114,   967,     0,     0,     0,
     0,  1102,  1103,  1104,     0,     0,  2081,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  2504,     0,     0,     0,  2509,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,  1790,  1790,
  1790,  1790,  1790,  1790,     0,     0,     0,     0,     0,     0,
     0,     0,     0,  1503,     0,     0,  2524,     0,     0,     0,
  2126,     0,     0,     0,     0,     0,     0,     0,     0,   730,
     0,     0,     0,     0,     0,   730,  1529,     0,     0,     0,
  1107,     0,     0,     0,     0,  2545,     0,  1552,   967,     0,
     0,  1790,     0,  1790,     0,  1108,     0,     0,   730,  1109,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1790,     0,     0,     0,  2037,  1080,  1081,  1082,  1083,  1084,
  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
  1095,  1105,     0,     0,  1106,     0,     0,  1110,     0,     0,
     0,     0,     0,  1599,     0,     0,  2345,  1795,  2348,  2349,
  2350,  2351,     0,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
  1095,   912,     0,     0,     0,  1111,     0,     0,     0,     0,
     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
     0,     0,     0,  1112,  1790,     0,     0,     0,  2237,  1102,
  1103,  1104,     0,     0,     0,     0,     0,     0,     0,  2384,
     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
     0,     0,     0,     0,     0,     0,     0,     0,  1874,  1102,
  1103,  1104,     0,     0,  1080,  1081,  1082,  1083,  1084,  1085,
  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1107,     0,     0,     0,     0,     0,     0,     0,     0,  2687,
     0,     0,     0,     0,  1113,  1108,   965,     0,     0,  1109,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,
     0,  1790,     0,  1790,  1790,  1790,  1790,  1728,  1102,  1103,
  1104,     0,     0,     0,     0,     0,  1736,  1110,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   912,     0,     0,
     0,     0,     0,  1790,     0,     0,     0,     0,     0,  1105,
     0,     0,  1106,  1114,     0,  1111,     0,   151,     0,  1790,
  1790,   730,   730,     0,  2726,  2727,     0,  2729,     0,  2731,
  2732,  1790,     0,  1112,     0,     0,  1790,     0,     0,  1105,
     0,     0,  1106,     0,     0,     0,  1790,     0,     0,     0,
  1790,     0,     0,  1790,   912,     0,   912,     0,     0,     0,
   906,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,  2537,
     0,  2539,  2540,  2541,  2542,     0,     0,     0,     0,  1102,
  1103,  1104,  1895,     0,     0,     0,     0,     0,  2796,     0,
     0,     0,     0,     0,     0,     0,     0,     0,  1790,     0,
     0,  1874,     0,     0,  1113,     0,     0,     0,  1105,     0,
     0,  1106,     0,     0,   912,     0,     0,     0,  1107,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  2564,
  2820,     0,  2821,  1108,  2581,     0,     0,  1109,   965,     0,
     0,     0,     0,     0,  2595,     0,     0,     0,  1107,     0,
     0,  2595,     0,     0,     0,     0,     0,     0,     0,     0,
  1790,     0,     0,  1108,     0,  1790,   912,  1109,   912,     0,
     0,     0,     0,  1114,     0,  1110,     0,   912,     0,     0,
     0,     0,     0,     0,     0,     0,     0,  1790,     0,  1790,
     0,     0,     0,  1790,  1790,  1790,     0,     0,     0,     0,
     0,     0,     0,  1111,     0,  1110,     0,     0,     0,     0,
     0,     0,  1790,     0,     0,  2036,     0,     0,     0,  1105,
     0,  1112,  1106,  2538,   965,     0,     0,  1107,     0,     0,
     0,  1913,  1914,  1111,     0,  1915,  1916,  1917,     0,     0,
     0,     0,  1108,     0,  2058,     0,  1109,  1376,     0,     0,
     0,  1112,     0,     0,     0,     0,     0,     0,     0,     0,
  2890,  2557,     0,     0,     0,  2560,     0,     0,  2345,     0,
     0,     0,     0,  2695,     0,     0,     0,     0,     0,     0,
     0,  1790,     0,     0,  1110,  2897,  2898,     0,     0,  2899,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   730,  2708,  1113,  2079,     0,     0,     0,     0,     0,     0,
     0,     0,  1111,     0, -1693,     0,     0,     0,     0,     0,
  2717,     0,     0,     0,  1790,  1790,     0,     0,     0,     0,
  1112,     0,  1113,     0,     0,  1790,     0,  1918,  1107,     0,
  1790,     0,     0,     0,  1919,     0,     0,     0,     0,     0,
     0,     0,     0,  1108,     0, -1693,     0,  1109,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,  1114,     0,  1790,     0,     0,  1920,     0,     0,     0,
     0,  2181,  1790,     0,     0,  1921,     0,     0,     0,  2759,
     0,     0,     0,     0,     0,  1110,     0, -1693,     0,     0,
     0,  1114,     0,     0,     0,     0,     0,     0,     0,     0,
     0,  1113,     0,     0,     0,  1922,  1923,     0,     0,     0,
     0,     0,     0,  1111,  2208,     0,  1790, -1693,     0,  1790,
  1790, -1693,  1874,  1874,     0,     0,     0,  2223,     0,     0,
  1790,  1112,     0,  2813,   912,     0,     0,     0,  2595,     0,
     0,     0,     0, -1693,     0,     0,  1790,     0,     0,     0,
  1924, -1693,     0, -1693,     0,     0,     0,     0,     0,     0,
     0,     0, -1693,     0,     0,     0,     0,     0, -1693,     0,
  1114,     0,     0,     0,   912,     0, -1693,     0,     0,     0,
 -1693,     0,     0,     0,     0,  1790,     0, -1693,     0,  1925,
     0, -1693, -1693, -1693, -1693,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0, -1693,   967,     0,     0,
     0,     0,  1113,     0,     0,     0,  2313,   965,   747,     0,
  2317,     0,     0, -1693,     0,     0, -1693,  2870, -1693,     0,
     0,     0,  2327,     0,     0, -1693,     0,     0,  2595,     0,
     0,     0,     0,     0,     0,  1926,     0,     0, -1693,     0,
     0,     0,     0,     0,  2759,     0,     0,     0, -1693,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0, -1693, -1693,     0,     0,     0,
     0,  1114,     0,     0,     0,     0,     0,     0,     0,     0,
 -1693,     0,     0,  2813,     0,     0,     0, -1693,     0,     0,
     0, -1693,     0,     0,     0,     0,     0,     0,     0,     0,
 -1693, -1693, -1693,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,   758,
   759,     0,     0,     0,     0,   292,   760,   761,  -577,     0,
     0,     0,     0,     0,     0,     0,   762,   763,     0,     0,
     0,     0,     0,   764,     0,  2430,     0,  1090,  1091,  1092,
  1093,  1094,  1095,     0,     0,     0,     0,     0,     0,     0,
     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0, -1693,
     0,     0,     0,   765,     0,     0,  2208,  1102,  1103,  1104,
 -1693,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   912,     0,     0,  1096,  1097,  1098,  1099,  1100,
  1101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,  1102,  1103,  1104,     0,     0,     0,     0,     0,     0,
 -1693,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   912,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   159,     0,     0,     0,
     0,     0,     0,     0,   766,  1927,  1928,  1929,  1930,  1931,
  1932,  1933,  1934,  1935,  1936,     0,     0,     0,     0,   967,
     0, -1693,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,  1105,     0, -1693,
  1106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,  1105,     0,    39,  1106,     0,     0,     0,     0,     0,
     0,     0,   767,     0,     0,     0, -1693,   768,     0,     0,
     0,     0,     0,     0,     0,     0,     0,  2586,     0,     0,
 -1693, -1693, -1693, -1693, -1693, -1693, -1693,     0, -1693, -1693,
     0,    40,    41,   769,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,  2208, -1693,     0,     0,     0,  2614,
     0,  2616,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    43,     0,     0,     0,     0,    44,     0,
     0,     0,     0,     0,     0,     0,  1107,     0,     0,     0,
     0,     0,     0,    45,     0,     0,     0,     0,    46,     0,
    47,  1108,     0,     0,     0,  1109,  1650,   770,     0,     0,
    48,   912,   771,    49,     0,   772,    50,     0,     0,    51,
  1107,     0,     0,     0,    52,     0,   773,     0,     0,     0,
     0,   967,   774,     0,     0,  1108,     0,     0,     0,  1109,
     0,     0,   775,  1110,     0,     0,     0,   776,     0,     0,
   777,     0,     0,   778,     0,     0,     0,     0,    54,     0,
     0,    55,   779,     0,     0,     0,     0,     0,    57,     0,
     0,  1111,     0,     0,     0,   758,   759,  1110,     0,    58,
     0,   292,   760,   761,  -577,     0,     0,     0,     0,  1112,
     0,     0,   762,   763,    59,     0,     0,     0,     0,   764,
     0,    60,  1200,   780,     0,  1111,     0,   781,    61,     0,
     0,    62,    63,    64,     0,    65,    66,   967,     0,     0,
     0,     0,     0,  1112,     0,     0,   782,     0,     0,   765,
     0,     0,   783,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    68,   784,    69,    70,     0,
    71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1113,     0,     0,     0,     0,     0,     0,    72,    73,     0,
   912,     0,     0,   912,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,  1825,     0,
     0,     0,   785,     0,  1113,     0,     0,     0,     0,   786,
     0,   787,    76,     0,    77,     0,     0,     0,     0,     0,
   766,   788,   789,   790,     0,     0,     0,     0,     0,  2586,
   791,     0,     0,   112,     0,     0,     0,     0,     0,  1114,
     0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,  1114,     0,     0,    78,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  1177,
  1177,  1177,  1177,  1177,  1177,     0,     0,     0,     0,     0,
     0,  2774,     0,     0,     0,     0,     0,     0,     0,    39,
     0,     0,     0,     0,     0,     0,     0,     0,   767,     0,
     0,     0,     0,   768,     0,     0,   758,   759,     0,     0,
     0,     0,   292,   760,   761,     0,     0,     0,     0,     0,
     0,     0,     0,   762,   763,     0,     0,    40,    41,   769,
   764,     0,     0,     0,     0,     0,     0,     0,  2775,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
   765,     0,     0,  2776,    44,     0,     0,     0,     0,     0,
     0,     0,  2777,     0,     0,     0,     0,     0,     0,    45,
     0,     0,     0,     0,    46,     0,    47,     0,     0,     0,
     0,     0,     0,   770,     0,     0,    48,     0,   771,    49,
   967,   772,    50,     0,     0,    51,  2778,     0,     0,  1826,
    52,     0,   773,     0,  2779,     0,     0,     0,   774,     0,
     0,  1827,     0,     0,     0,     0,     0,     0,   775,     0,
     0,     0,     0,   776,     0,     0,   777,     0,     0,   778,
     0,     0,     0,     0,    54,     0,     0,    55,   779,     0,
     0,   766,     0,     0,    57,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    59,     0,     0,     0,     0,  1828,     0,    60,     0,   780,
     0,     0,  1829,   781,    61,     0,     0,    62,    63,    64,
     0,    65,    66,     0,     0,     0,     0,  2780,     0,     0,
     0,     0,   782,     0,     0,     0,     0,     0,   783,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,  1830,     0,     0,     0,     0,     0,     0,     0,     0,
    39,    68,   784,    69,    70,     0,    71,     0,     0,   767,
     0,     0,     0,     0,   768,  1831,     0,     0,     0,     0,
     0,     0,     0,    72,    73,  1832,  1833,     0,   758,   759,
     0,     0,     0,     0,   292,   760,   761,     0,    40,    41,
   769,  1834,     0,     0,     0,   762,   763,     0,   785,     0,
     0,     0,   764,     0,     0,   786,     0,   787,    76,     0,
    77,     0,  1835,     0,     0,  1836,  1837,   788,   789,   790,
    43,  1838,     0,     0,     0,    44,   791,     0,     0,   112,
     0,     0,   765,     0,     0,     0,     0,   295,     0,     0,
    45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
     0,     0,     0,     0,   770,     0,     0,    48,     0,   771,
    49,     0,   772,    50,     0,     0,    51,     0,     0,     0,
     0,    52,    78,   773,     0,     0,     0,     0,     0,   774,
  1839,     0,     0,     0,     0,     0,     0,     0,     0,   775,
  2781,     0,  1840,     0,   776,     0,     0,   777,     0,     0,
   778,     0,     0,     0,     0,    54,     0,     0,    55,   779,
     0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
     0,     0,     0,   766,     0,     0,    58,  1084,  1085,  1086,
  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,     0,
     0,    59,     0,     0,     0,     0,     0,     0,    60,  1200,
   780,     0,     0,     0,   781,    61,     0,     0,    62,    63,
    64,     0,    65,    66,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   782,     0,     0,     0,     0,     0,   783,
     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,  1102,  1103,  1104,
     0,     0,    68,   784,    69,    70,     0,    71,     0,     0,
     0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
     0,   767,     0,     0,    72,    73,   768,     0,     0,   758,
   759,     0,     0,     0,     0,   292,   760,   761,     0,     0,
     0,     0,     0,     0,     0,     0,   762,   763,     0,   785,
    40,    41,   769,   764,     0,     0,   786,     0,   787,    76,
     0,    77,     0,     0,     0,     0,     0,     0,   788,   789,
   790,     0,     0,     0,     0,     0,     0,   791,     0,     0,
   112,     0,    43,   765,     0,     0,     0,    44,   295,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    45,     0,     0,     0,     0,    46,     0,    47,
     0,     0,     0,     0,     0,     0,   770,     0,     0,    48,
     0,   771,    49,    78,   772,    50,     0,     0,    51,     0,
     0,     0,     0,    52,     0,   773,     0,  1105,     0,     0,
  1106,   774,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   775,     0,     0,     0,     0,   776,     0,     0,   777,
     0,     0,   778,     0,     0,     0,     0,    54,     0,     0,
    55,   779,     0,     0,   766,     0,     0,    57,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
    60,     0,   780,     0,     0,     0,   781,    61,     0,     0,
    62,    63,    64,     0,    65,    66,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   782,     0,  2005,     0,     0,
     0,   783,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,  1107,     0,     0,     0,
     0,     0,     0,    39,    68,   784,    69,    70,     0,    71,
     0,  1108,   767,     0,     0,  1109,     0,   768,     0,     0,
     0,     0,     0,     0,     0,     0,    72,    73,     0,     0,
     0,   758,   759,     0,     0,     0,     0,   292,   760,   761,
     0,    40,    41,   769,     0,     0,     0,     0,   762,   763,
     0,   785,     0,  1110,     0,   764,     0,     0,   786,     0,
   787,    76,     0,    77,     0,     0,     0,     0,     0,     0,
   788,   789,   790,    43,     0,     0,     0,     0,    44,   791,
     0,  1111,   112,     0,     0,   765,     0,     0,     0,     0,
   295,     0,     0,    45,     0,     0,     0,     0,    46,  1112,
    47,     0,     0,     0,     0,     0,     0,   770,     0,     0,
    48,     0,   771,    49,     0,   772,    50,     0,     0,    51,
     0,     0,     0,     0,    52,    78,   773,     0,     0,     0,
     0,     0,   774,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   775,     0,     0,     0,     0,   776,     0,     0,
   777,     0,     0,   778,     0,     0,     0,     0,    54,     0,
     0,    55,   779,     0,     0,     0,     0,     0,    57,     0,
     0,     0,     0,     0,     0,     0,   766,     0,     0,    58,
  1113,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
  1094,  1095,     0,     0,    59,     0,     0,     0,     0,     0,
     0,    60,  2331,   780,     0,     0,     0,   781,    61,     0,
     0,    62,    63,    64,     0,    65,    66,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   782,     0,     0,     0,
     0,     0,   783,     0,  1096,  1097,  1098,  1099,  1100,  1101,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  1114,
  1102,  1103,  1104,     0,     0,    68,   784,    69,    70,     0,
    71,     0,     0,     0,     0,    39,     0,     0,     0,     0,
     0,     0,     0,     0,   767,     0,     0,    72,    73,   768,
     0,     0,   758,   759,     0,     0,     0,     0,   292,   760,
   761,     0,     0,     0,     0,     0,     0,     0,     0,   762,
   763,     0,   785,    40,    41,   769,   764,     0,     0,   786,
     0,   787,    76,     0,    77,     0,     0,     0,     0,     0,
     0,   788,   789,   790,     0,     0,     0,     0,     0,     0,
   791,     0,     0,   112,     0,    43,   765,     0,     0,     0,
    44,   295,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
    46,     0,    47,     0,     0,     0,     0,     0,     0,   770,
     0,     0,    48,  -804,   771,    49,    78,   772,    50,     0,
     0,    51,     0,     0,     0,     0,    52,     0,   773,     0,
  1105,     0,     0,  1106,   774,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   775,     0,     0,     0,     0,   776,
     0,     0,   777,     0,     0,   778,     0,     0,     0,     0,
    54,     0,     0,    55,   779,     0,     0,   766,     0,     0,
    57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
     0,     0,     0,    60,     0,   780,     0,     0,     0,   781,
    61,     0,     0,    62,    63,    64,     0,    65,    66,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   782,     0,
     0,     0,     0,     0,   783,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
     0,     0,     0,     0,     0,     0,    39,    68,   784,    69,
    70,     0,    71,     0,  1108,   767,     0,     0,  1109,     0,
   768,     0,     0,     0,     0,     0,     0,     0,     0,    72,
    73,     0,     0,     0,  1770,  1771,     0,  1772,     0,     0,
   292,  1773,  1774,     0,    40,    41,   769,     0,     0,     0,
     0,  1775,     0,     0,   785,     0,  1110,     0,     0,     0,
     0,   786,     0,   787,    76,     0,    77,     0,     0,     0,
     0,     0,     0,   788,   789,   790,    43,     0,     0,     0,
     0,    44,   791,     0,  1111,   112,     0,     0,     0,     0,
     0,     0,     0,   295,     0,     0,    45,     0,     0,     0,
     0,    46,  1112,    47,     0,     0,     0,     0,     0,     0,
   770,     0,     0,    48,     0,   771,    49,     0,   772,    50,
     0,     0,    51,     0,     0,     0,     0,    52,    78,   773,
     0,     0,     0,     0,     0,   774,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   775,     0,     0,     0,     0,
   776,     0,     0,   777,     0,     0,   778,     0,     0,     0,
     0,    54,     0,     0,    55,   779,     0,     0,     0,     0,
     0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    58,  1113,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    59,     0,     0,
     0,     0,     0,     0,    60,     0,   780,     0,     0,     0,
   781,    61,     0,     0,    62,    63,    64,     0,    65,    66,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   782,
     0,     0,     0,     0,     0,   783,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1114,     0,     0,     0,     0,     0,    68,   784,
    69,    70,     0,    71,     0,     0,     0,     0,    39,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    72,    73,  2138,     0,     0,  1770,  1771,     0,  1772,     0,
     0,   292,  1773,  1774,     0,     0,     0,     0,     0,     0,
     0,     0,  1775,     0,     0,   785,    40,    41,    42,     0,
     0,     0,   786,     0,   787,    76,     0,    77,     0,     0,
     0,     0,     0,     0,   788,   789,   790,     0,     0,     0,
     0,     0,     0,   791,     0,     0,   112,     0,    43,     0,
     0,     0,     0,    44,   295,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
     0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    48,     0,     0,    49,    78,
  1776,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     0,     0,     0,     0,     0,  1777,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
     0,     0,  1778,     0,     0,  2139,     0,     0,     0,     0,
     0,     0,     0,    54,     0,     0,    55,  2140,     0,     0,
     0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,  2382,     0,     0,     0,    59,
     0,     0,     0,     0,     0,     0,    60,     0,  1781,     0,
     0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
  1782,    66,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
    68,  1783,    69,    70,     0,    71,     0,  1770,  1771,     0,
  1772,     0,     0,   292,  1773,  1774,     0,     0,     0,     0,
     0,     0,    72,    73,  1775,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    40,    41,    42,
     0,  1784,     0,     0,     0,     0,     0,    74,     0,     0,
     0,     0,     0,     0,  1785,     0,    75,    76,     0,    77,
     0,     0,     0,     0,     0,     0,  1786,  1787,  2141,    43,
     0,     0,     0,     0,    44,  1788,     0,     0,   733,     0,
     0,     0,     0,     0,     0,     0,   295,     0,     0,    45,
     0,     0,     0,     0,    46,     0,    47,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
     0,  1776,    50,     0,     0,    51,     0,     0,     0,     0,
    52,    78,     0,     0,     0,     0,  1777,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
     0,     0,     0,  1778,     0,     0,  2573,     0,     0,     0,
     0,     0,     0,     0,    54,     0,     0,    55,    56,     0,
     0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    59,     0,     0,     0,     0,     0,     0,    60,     0,  1781,
     0,     0,     0,     0,    61,     0,     0,    62,    63,    64,
     0,  1782,    66,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    68,  1783,    69,    70,  2138,    71,     0,  1770,  1771,
     0,  1772,     0,     0,   292,  1773,  1774,     0,     0,     0,
     0,     0,     0,    72,    73,  1775,     0,     0,     0,    40,
    41,    42,     0,     0,     0,     0,  2574,     0,     0,     0,
     0,     0,  1784,     0,     0,     0,     0,     0,    74,     0,
     0,     0,  2575,  2576,     0,  1785,     0,    75,    76,     0,
    77,    43,     0,     0,     0,     0,    44,  1786,  1787,     0,
     0,     0,     0,     0,     0,     0,  1788,     0,     0,   733,
     0,    45,     0,     0,     0,     0,    46,   295,    47,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
     0,    49,     0,  1776,    50,     0,     0,    51,     0,     0,
     0,     0,    52,     0,     0,     0,     0,     0,  1777,     0,
     0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
    53,     0,     0,     0,     0,  1778,     0,     0,  2139,     0,
     0,     0,     0,     0,     0,     0,    54,     0,     0,    55,
  2140,     0,     0,     0,     0,     0,    57,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    59,     0,     0,     0,     0,     0,     0,    60,
     0,  1781,     0,     0,     0,     0,    61,     0,     0,    62,
    63,    64,     0,  1782,    66,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    39,    68,  1783,    69,    70,     0,    71,     0,
  1770,  1771,     0,  1772,     0,     0,   292,  1773,  1774,     0,
     0,     0,     0,     0,     0,    72,    73,  1775,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    40,    41,    42,     0,  1784,     0,     0,     0,     0,     0,
    74,     0,     0,     0,     0,     0,     0,  1785,     0,    75,
    76,     0,    77,     0,     0,     0,     0,     0,     0,  1786,
  1787,  2141,    43,     0,     0,     0,     0,    44,  1788,     0,
     0,   733,     0,     0,     0,     0,     0,     0,     0,   295,
     0,     0,    45,     0,     0,     0,     0,    46,     0,    47,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
     0,     0,    49,     0,  1776,    50,     0,     0,    51,     0,
     0,     0,     0,    52,    78,     0,     0,     0,     0,  1777,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    53,     0,     0,     0,     0,  1778,     0,     0,  2573,
     0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
    55,    56,     0,     0,     0,     0,     0,    57,     0,     0,
     0,     0,  1093,  1094,  1095,     0,     0,     0,    58,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  2382,
     0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
    60,  2591,  1781,     0,     0,     0,     0,    61,     0,     0,
    62,    63,    64,     0,  1782,    66,     0,  1096,  1097,  1098,
  1099,  1100,  1101,     0,     0,     0,     0,     0,     0,     0,
     0,    67,     0,  1102,  1103,  1104,     0,     0,     0,     0,
     0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    68,  1783,    69,    70,     0,    71,
     0,  1770,  1771,     0,  1772,     0,     0,   292,  1773,  1774,
     0,     0,     0,     0,     0,     0,    72,    73,  1775,     0,
     0,     0,    40,    41,    42,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,  1784,     0,     0,     0,     0,
     0,    74,     0,     0,     0,     0,     0,     0,  1785,     0,
    75,    76,     0,    77,    43,     0,     0,     0,     0,    44,
  1786,  1787,     0,     0,     0,     0,     0,     0,     0,  1788,
     0,     0,   733,     0,    45,     0,     0,     0,     0,    46,
   295,    47,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    48,     0,     0,    49,     0,  1776,    50,     0,     0,
    51,     0,     0,     0,     0,    52,     0,     0,     0,     0,
     0,  1777,     0,  1105,     0,    78,  1106,     0,     0,     0,
     0,     0,     0,    53,     0,     0,     0,     0,  1778,     0,
     0,  1779,     0,     0,     0,     0,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,     0,     0,     0,    57,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
     0,     0,    60,  1780,  1781,     0,     0,     0,     0,    61,
     0,     0,    62,    63,    64,     0,  1782,    66,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    67,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1107,     0,     0,    39,    68,  1783,    69,    70,
     0,    71,     0,     0,     0,     0,     0,  1108,     0,  2138,
     0,  1109,     0,     0,     0,     0,     0,     0,    72,    73,
     0,     0,     0,  1770,  1771,     0,  1772,     0,     0,   292,
  1773,  1774,     0,    40,    41,    42,     0,  1784,     0,     0,
  1775,     0,     0,    74,     0,     0,     0,     0,     0,  1110,
  1785,     0,    75,    76,     0,    77,     0,     0,     0,     0,
     0,     0,  1786,  1787,     0,    43,     0,     0,     0,     0,
    44,  1788,     0,     0,   733,     0,     0,  1111,     0,     0,
     0,     0,   295,  1094,  1095,    45,     0,     0,     0,     0,
    46,     0,    47,     0,     0,  1112,     0,     0,     0,     0,
     0,     0,    48,     0,     0,    49,     0,  1776,    50,     0,
     0,    51,     0,     0,     0,     0,    52,    78,     0,     0,
     0,     0,  1777,     0,     0,     0,     0,  1096,  1097,  1098,
  1099,  1100,  1101,     0,    53,     0,     0,     0,     0,  1778,
     0,     0,  2139,  1102,  1103,  1104,     0,     0,     0,     0,
    54,     0,     0,    55,  2140,     0,     0,     0,     0,     0,
    57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    58,     0,     0,     0,     0,  1113,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
     0,     0,     0,    60,     0,  1781,     0,     0,     0,     0,
    61,     0,     0,    62,    63,    64,     0,  1782,    66,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,  1114,     0,    68,  1783,    69,
    70,     0,    71,     0,     0,     0,     0,    39,     0,     0,
     0,     0,     0,     0,     0,  1770,  1771,     0,  1772,    72,
    73,   292,  1773,  1774,     0,     0,     0,     0,     0,     0,
     0,     0,  1775,  1105,     0,     0,  1106,     0,  1784,     0,
     0,     0,     0,     0,    74,    40,    41,    42,     0,     0,
     0,  1785,     0,    75,    76,     0,    77,     0,     0,     0,
     0,     0,     0,  1786,  1787,     0,     0,     0,     0,     0,
     0,     0,  1788,     0,     0,   733,     0,    43,     0,     0,
     0,     0,    44,   295,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
     0,     0,    46,     0,    47,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    48,     0,     0,    49,    78,  1776,
    50,     0,     0,    51,     0,     0,     0,     0,    52,     0,
     0,     0,     0,     0,  1777,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    53,     0,     0,     0,
     0,  1778,  1107,     0,  2590,     0,     0,     0,     0,     0,
     0,     0,    54,     0,     0,    55,    56,  1108,     0,     0,
     0,  1109,    57,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
     0,     0,     0,     0,     0,    60,  2591,  1781,     0,  1110,
     0,     0,    61,     0,     0,    62,    63,    64,     0,  1782,
    66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    67,  1111,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
     0,     0,     0,     0,     0,  1112,     0,     0,     0,    68,
  1783,    69,    70,     0,    71,     0,  1770,  1771,     0,  1772,
     0,     0,   292,  1773,  1774,     0,     0,     0,     0,     0,
     0,    72,    73,  1775,     0,     0,     0,    40,    41,    42,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1784,     0,     0,     0,     0,     0,    74,     0,     0,     0,
     0,     0,     0,  1785,     0,    75,    76,     0,    77,    43,
     0,     0,     0,     0,    44,  1786,  1787,     0,     0,     0,
     0,     0,     0,     0,  1788,     0,  1113,   733,     0,    45,
     0,     0,     0,     0,    46,   295,    47,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
     0,  1776,    50,     0,     0,    51,     0,     0,     0,     0,
    52,     0,     0,     0,     0,     0,  1777,     0,     0,     0,
    78,     0,     0,     0,     0,     0,     0,     0,    53,     0,
     0,     0,     0,  1778,     0,     0,  2573,     0,     0,     0,
     0,     0,     0,     0,    54,  1114,     0,    55,    56,     0,
     0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    59,     0,     0,     0,     0,     0,     0,    60,  2591,  1781,
     0,     0,     0,     0,    61,     0,     0,    62,    63,    64,
     0,  1782,    66,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    39,    68,  1783,    69,    70,     0,    71,     0,  1770,  1771,
     0,  1772,     0,     0,   292,  1773,  1774,     0,     0,     0,
     0,     0,     0,    72,    73,  1775,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    40,    41,
    42,     0,  1784,     0,     0,     0,     0,     0,    74,     0,
     0,     0,     0,     0,     0,  1785,     0,    75,    76,     0,
    77,     0,     0,     0,     0,     0,     0,  1786,  1787,     0,
    43,     0,     0,     0,     0,    44,  1788,     0,     0,   733,
     0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
    45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
    49,     0,  1776,    50,     0,     0,    51,     0,     0,     0,
     0,    52,    78,     0,     0,     0,     0,  1777,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
     0,     0,     0,     0,  1778,     0,     0,  1779,     0,     0,
     0,     0,     0,     0,     0,    54,     0,     0,    55,    56,
     0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,  2382,     0,     0,
     0,    59,     0,     0,     0,     0,     0,     0,    60,     0,
  1781,     0,     0,     0,     0,    61,     0,     0,    62,    63,
    64,     0,  1782,    66,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    68,  1783,    69,    70,     0,    71,     0,  1770,
  1771,     0,  1772,     0,     0,   292,  1773,  1774,     0,     0,
     0,     0,     0,     0,    72,    73,  1775,     0,     0,     0,
    40,    41,    42,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,  1784,     0,     0,     0,     0,     0,    74,
     0,     0,     0,     0,     0,     0,  1785,     0,    75,    76,
     0,    77,    43,     0,     0,     0,     0,    44,  1786,  1787,
     0,     0,     0,     0,     0,     0,     0,  1788,     0,     0,
   733,     0,    45,     0,     0,     0,     0,    46,   295,    47,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
     0,     0,    49,     0,  1776,    50,     0,     0,    51,     0,
     0,     0,     0,    52,     0,     0,     0,     0,     0,  1777,
     0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
     0,    53,     0,   153,   154,     0,  1778,     0,     0,  1779,
     0,   155,     0,     0,     0,     0,     0,    54,     0,     0,
    55,    56,     0,     0,     0,     0,     0,    57,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
    60,  2810,  1781,     0,     0,     0,     0,    61,     0,     0,
    62,    63,    64,     0,  1782,    66,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    39,    68,  1783,    69,    70,     0,    71,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    72,    73,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    40,    41,    42,     0,  1784,     0,     0,     0,     0,
     0,    74,     0,     0,     0,     0,     0,     0,  1785,     0,
    75,    76,     0,    77,     0,     0,     0,     0,     0,     0,
  1786,  1787,     0,    43,     0,     0,     0,     0,    44,  1788,
     0,     0,   733,     0,     0,     0,     0,     0,     0,     0,
   295,     0,     0,    45,     0,     0,     0,     0,    46,     0,
    47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    48,     0,     0,    49,     0,  1776,    50,     0,     0,    51,
     0,     0,     0,     0,    52,    78,     0,    39,     0,     0,
  1777,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    53,     0,     0,     0,     0,  1778,     0,     0,
  1779,     0,     0,     0,     0,     0,     0,     0,    54,     0,
     0,    55,    56,     0,     0,    40,    41,    42,    57,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    59,     0,     0,    43,     0,     0,
     0,    60,    44,  1781,     0,     0,     0,     0,    61,     0,
     0,    62,    63,    64,     0,  1782,    66,    45,     0,     0,
     0,     0,    46,     0,    47,     0,     0,     0,     0,     0,
     0,     0,    67,     0,    48,     0,     0,    49,     0,     0,
    50,     0,     0,    51,     0,     0,     0,     0,    52,     0,
     0,     0,     0,     0,     0,    68,  1783,    69,    70,     0,
    71,     0,     0,     0,     0,     0,    53,     0,     0,     0,
     0,     0,     0,     0,   156,     0,     0,    72,    73,     0,
     0,     0,    54,     0,     0,    55,    56,     0,     0,     0,
     0,     0,    57,     0,     0,     0,  1784,     0,     0,     0,
     0,     0,    74,    58,     0,     0,     0,     0,     0,  1785,
     0,    75,    76,     0,    77,     0,     0,     0,    59,     0,
     0,  1786,  1787,     0,     0,    60,     0,     0,     0,     0,
  1788,     0,    61,   733,     0,    62,    63,    64,     0,    65,
    66,   295,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    78,     0,     0,    68,
     0,    69,    70,     0,    71,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
     0,    72,    73,     0,     0,     0,   488,     0,   489,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   490,     0,     0,     0,    74,     0,     0,     0,
     0,   491,     0,     0,     0,    75,    76,     0,    77,     0,
     0,     0,   492,   493,   494,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   112,   495,     0,
   496,   497,   498,     2,     3,   499,     4,     5,   500,     0,
   501,     6,   502,   503,     0,     0,     0,     0,     0,   504,
     0,     0,   505,     0,   506,   507,   508,     0,     7,     8,
     0,     0,     0,     0,   509,     0,   510,   511,     0,   512,
    78,   513,   514,     0,     0,   515,     9,    10,     0,     0,
   516,   517,   518,     0,   519,   520,     0,     0,     0,   521,
   522,     0,   523,     0,     0,     0,   524,     0,   525,   526,
     0,     0,   527,     0,     0,     0,   528,     0,     0,   529,
     0,   530,     0,   531,     0,   532,     0,   533,   534,     0,
   535,   536,   537,     0,     0,     0,   538,     0,   539,   540,
     0,   541,     0,     0,     0,     0,     0,     0,     0,   542,
   543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   544,     0,     0,   545,   546,     0,     0,
   547,   548,     0,     0,   549,   550,     0,     0,     0,     0,
     0,     0,     0,   551,   552,   553,     0,   554,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   555,   556,   557,
     0,   558,     0,     0,     0,   559,   560,     0,     0,     0,
   561,     0,     0,     0,     0,     0,     0,     0,   562,     0,
     0,     0,     0,     0,     0,     0,   563,     0,     0,     0,
     0,     0,   564,   565,     0,     0,     0,     0,   566,     0,
     0,   567,     0,     0,     0,   568,   569,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   570,     0,     0,  2161,
     0,     0,     0,  1028,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
     0,   572,     0,     0,     0,     0,     0,   573,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   255,     0,     0,     0,     0,     0,     0,   574,     0,   575,
   576,     0,     0,     0,     0,     0,     0,     0,   577,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,  1080,  1081,  1082,  1083,  1084,  1085,
  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
     0,     0,     0,     0,     0,     0,     0,   578,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   579,     0,
     0,     0,   580,  2009,     0,   581,     0,  1028,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,   582,
   583,     0,     0,     0,   584,     0,     0,     0,  1102,  1103,
  1104,     0,     0,     0,     0,     0,   585,     0,     0,     0,
     0,     0,   586,   587,   588,   589,     0,     0,   590,     0,
     0,     0,   591,     0,     0,     0,     0,     0,     0,   592,
   593,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   594,     0,   595,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   596,     0,     0,   597,     0,     0,
   598,     0,     0,     0,     0,     0,   599,     0,     0,     0,
    39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     0,     0,     0,   600,     0,     0,   601,     0,     0,     0,
     0,     0,   602,     0,     0,   603,     0,     0,    40,    41,
    42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   604,     0,     0,     0,     0,     0,     0,   605,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,  1105,     0,
    43,  1106,     0,     0,     0,    44,     0,     0,     0,     0,
   606,   607,   608,   609,   610,   611,   612,     0,     0,   613,
    45,   614,     0,   615,     0,    46,     0,    47,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
    49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
     0,    52,     0,     0,    39,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
     0,  1349,     0,     0,     0,     0,     0,  2162,     0,     0,
     0,     0,     0,     0,     0,    54,     0,     0,    55,    56,
     0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
     0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
     0,     0,  1108,     0,     0,    61,  1109,  1651,    62,    63,
    64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
     0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
     0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
    51,     0,     0,     0,  1110,    52,     0,     0,    39,     0,
     0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
     0,     0,     0,    53,     0,  2062,     0,     0,     0,     0,
     0,     0,  1111,     0,    72,    73,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
  1112,     0,     0,     0,     0,     0,     0,     0,     0,    74,
    58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
     0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
     0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
     0,     0,    62,    63,    64,     0,    65,    66,    45,     0,
     0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
     0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
     0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     0,  1113,    39,    78,     0,     0,    68,     0,    69,    70,
     0,    71,     0,     0,     0,     0,     0,    53,     0,  2283,
     0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
     0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
    40,    41,    42,    57,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
     0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
  1114,     0,    43,     0,     0,     0,    60,    44,     0,     0,
     0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
    65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
     0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
     0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
     0,     0,     0,    52,     0,     0,    39,    78,     0,     0,
    68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
     0,    53,     0,  2298,     0,     0,     0,     0,     0,     0,
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
     0,     0,     0,     0,     0,    53,     0,  2506,     0,     0,
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
     0,  2631,     0,     0,     0,     0,     0,     0,     0,     0,
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
     0,     0,     0,    53,     0,  2856,     0,     0,     0,     0,
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
     0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
     0,     0,   292,   961,   962,     0,     0,     0,    72,    73,
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
     0,    53,     0,     0,     0,     0,   292,   961,   962,     0,
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
     0,    74,    58,     0,     0,     0,     0,     0,     0,     0,
    75,    76,     0,    77,     0,     0,     0,    59,     0,     0,
    43,     0,     0,     0,    60,    44,     0,     0,     0,     0,
     0,    61,     0,     0,    62,    63,    64,     0,    65,    66,
    45,     0,     0,     0,     0,    46,     0,    47,     0,     0,
     0,   963,     0,     0,     0,    67,     0,    48,     0,     0,
    49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
     0,    52,     0,     0,    39,    78,     0,     0,    68,     0,
    69,    70,     0,    71,     0,     0,     0,     0,     0,    53,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
     0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
     0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
     0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
     0,     0,     0,   964,     0,    61,     0,     0,    62,    63,
    64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
     0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
     0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
    51,     0,     0,     0,     0,    52,   109,     0,  -577,    78,
     0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
     0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,     0,     0,     0,    57,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
    58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
     0,    77,     0,     0,     0,    59,     2,     3,     0,     4,
     5,     0,    60,     0,     6,     0,     0,     0,     0,    61,
   112,     0,    62,    63,    64,     0,    65,    66,   295,     0,
     0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    67,     0,     0,     0,     0,     0,     9,
    10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1028,     0,     0,    78,     0,     0,    68,     0,    69,    70,
     0,    71,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
  1089,  1090,  1091,  1092,  1093,  1094,  1095,     0,    72,    73,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    74,     0,     0,     0,     0,     0,   110,
     0,     0,    75,    76,     0,    77,     0,     0,     0,  1096,
  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   112,  1102,  1103,  1104,     0,     0,
     0,     0,   295,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,  2055,     0,  -577,    78,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    40,    41,    42,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    43,     0,     0,     0,     0,    44,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1963,    45,     0,     0,     0,     0,    46,     0,
    47,     0,     0,     0,     0,  1964,     0,     0,     0,     0,
    48,     0,     0,    49,     0,     0,    50,     0,     0,    51,
     0,     0,     0,     0,    52,  1105,     0,    39,  1106,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    53,     0,     0,     0,     0,     0,   828,     0,
     0,     0,     0,     0,     0,     0,     0,   111,    54,     0,
     0,    55,    56,     0,     0,    40,    41,    42,    57,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    59,     0,     0,    43,     0,     0,
     0,    60,    44,     0,     0,     0,     0,     0,    61,     0,
     0,    62,    63,    64,     0,    65,    66,    45,     0,     0,
     0,     0,    46,     0,    47,     0,     0,     0,     0,     0,
     0,     0,    67,     0,    48,     0,     0,    49,     0,     0,
    50,     0,     0,    51,  1107,     0,     0,     0,    52,     0,
     0,    39,     0,     0,     0,    68,     0,    69,    70,  1108,
    71,     0,     0,  1109,     0,     0,    53,     0,     0,     0,
     0,     0,   905,     0,  -577,     0,     0,    72,    73,     0,
     0,     0,    54,     0,     0,    55,    56,     0,     0,    40,
    41,    42,    57,     0,     0,     0,     0,     0,     0,     0,
     0,  1110,    74,    58,     0,     0,     0,     0,     0,     0,
     0,    75,    76,     0,    77,     0,     0,     0,    59,  1965,
     0,    43,     0,     0,     0,    60,    44,     0,     0,  1111,
     0,     0,    61,   112,     0,  1966,    63,    64,     0,    65,
    66,    45,     0,     0,     0,     0,    46,  1112,    47,     0,
     0,     0,     0,     0,     0,     0,    67,     0,    48,     0,
     0,    49,     0,     0,    50,     0,     0,    51,     0,     0,
     0,     0,    52,     0,     0,    39,    78,     0,     0,    68,
     0,    69,    70,     0,    71,     0,     0,     0,     0,     0,
    53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    72,    73,     0,     0,     0,    54,     0,     0,    55,
    56,     0,     0,    40,    41,    42,    57,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    74,    58,  1113,     0,
     0,     0,     0,     0,     0,    75,    76,     0,    77,     0,
     0,     0,    59,     0,     0,    43,     0,     0,     0,    60,
    44,     0,     0,   911,     0,     0,    61,     0,     0,    62,
    63,    64,     0,    65,    66,    45,     0,     0,     0,     0,
    46,     0,    47,     0,     0,     0,     0,     0,     0,     0,
    67,     0,    48,     0,     0,    49,     0,     0,    50,     0,
     0,    51,     0,     0,     0,     0,    52,  1114,     0,    39,
    78,     0,     0,    68,     0,    69,    70,     0,    71,     0,
     0,     0,     0,     0,    53,     0,     0,  1801,     0,     0,
     0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
    54,     0,     0,    55,    56,     0,     0,    40,    41,    42,
    57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    74,    58,     0,     0,     0,     0,     0,     0,     0,    75,
    76,     0,    77,     0,     0,     0,    59,     0,     0,    43,
     0,     0,     0,    60,    44,     0,     0,   911,     0,     0,
    61,   112,     0,    62,    63,    64,     0,    65,    66,    45,
     0,     0,     0,     0,    46,     0,    47,     0,     0,     0,
     0,     0,     0,     0,    67,     0,    48,     0,     0,    49,
     0,     0,    50,     0,     0,    51,     0,     0,     0,     0,
    52,     0,     0,     0,    78,     0,     0,    68,     0,    69,
    70,     0,    71,     0,     0,     0,     0,     0,    53,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
    73,     0,     0,     0,    54,     0,     0,    55,    56,     0,
     0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    74,    58,     0,     0,   829,     0,
    39,     0,     0,    75,    76,     0,    77,     0,     0,     0,
    59,     0,     0,     0,     0,     0,     0,    60,     0,     0,
     0,  2325,     0,  -577,    61,   112,     0,    62,    63,    64,
     0,    65,    66,     0,     0,     0,     0,     0,    40,    41,
    42,     0,     0,     0,     0,     0,     0,     0,    67,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
    43,    68,     0,    69,    70,    44,    71,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    45,     0,     0,    72,    73,    46,     0,    47,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
    49,     0,     0,    50,     0,     0,    51,     0,    74,     0,
     0,    52,     0,     0,    39,     0,     0,    75,    76,     0,
    77,     0,     0,     0,     0,     0,     0,     0,     0,    53,
     0,     0,     0,     0,     0,   150,     0,     0,     0,   112,
     0,     0,     0,     0,     0,    54,     0,     0,    55,    56,
     0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,  1847,     0,     0,
     0,    59,    78,     0,    43,     0,     0,     0,    60,    44,
     0,     0,     0,     0,     0,    61,     0,     0,    62,    63,
    64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
     0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
     0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
    51,     0,     0,     0,     0,    52,     0,     0,    39,     0,
     0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
     0,     0,     0,    53,     0,     0,     0,     0,     0,   732,
     0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
    58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
     0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
     0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
   112,     0,    62,    63,    64,     0,    65,    66,    45,     0,
     0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
     0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
     0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     0,     0,    39,    78,     0,     0,    68,     0,    69,    70,
     0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
     0,     0,     0,   911,     0,     0,     0,     0,    72,    73,
     0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
    40,    41,    42,    57,     0,     0,     0,  1999,     0,     0,
     0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
     0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
     0,     0,    43,     0,     0,     0,    60,    44,     0,     0,
     0,     0,     0,    61,   112,     0,    62,    63,    64,     0,
    65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
     0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
     0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
     0,     0,     0,    52,     0,     0,    39,    78,     0,     0,
    68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
     0,    53,     0,     0,     0,     0,     0,   109,     0,     0,
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
     0,  1245,     0,     0,     0,     0,    72,    73,     0,     0,
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
     0,     0,     0,     0,     0,  1284,     0,     0,     0,     0,
    72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
     0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
     0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
     0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
     0,     0,     0,     0,     0,    61,   733,     0,    62,    63,
    64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
     0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
     0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
    51,     0,     0,     0,     0,    52,     0,     0,    39,    78,
     0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
     0,     0,     0,    53,     0,     0,     0,     0,     0,  1416,
     0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
    58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
     0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
     0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
   112,     0,    62,    63,    64,     0,    65,    66,    45,     0,
     0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
     0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
     0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     0,     0,    39,    78,     0,     0,    68,     0,    69,    70,
     0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
     0,     0,     0,   905,     0,     0,     0,     0,    72,    73,
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
     0,    53,     0,     0,     0,     0,     0,  2222,     0,     0,
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
     0,  1028,     0,     0,     0,     0,    72,    73,     0,     0,
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
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    72,    73,     0,     0,     0,    54,     0,     0,    55,    56,
     0,     0,    40,    41,    42,    57,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    74,    58,     0,     0,     0,
     0,     0,     0,     0,    75,    76,     0,    77,     0,     0,
     0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
     0,     0,  1028,     0,     0,    61,   112,     0,    62,    63,
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
     0,     0,    60,    44,     0,     0,  1028,  2764,     0,    61,
   112,     0,    62,    63,    64,     0,    65,    66,    45,     0,
     0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
     0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
     0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     0,     0,     0,    78,     0,     0,    68,     0,    69,    70,
     0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
     0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
     0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    74,    58,     0,     0,     0,     0,    39,
     0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
     0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
   103,     0,     0,    61,   112,     0,    62,    63,    64,     0,
    65,    66,     0,     0,     0,     0,     0,    40,    41,    42,
     0,     0,     0,     0,     0,     0,     0,    67,     0,  2481,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    78,     0,    43,
    68,     0,    69,    70,    44,    71,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
     0,     0,    72,    73,    46,     0,    47,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
     0,     0,    50,     0,     0,    51,     0,    74,     0,     0,
    52,     0,     0,    39,     0,     0,    75,    76,     0,    77,
     0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
     0,     0,     0,     0,   732,     0,  2654,     0,     0,     0,
     0,     0,     0,     0,    54,     0,     0,    55,    56,     0,
     0,    40,    41,    42,    57,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    59,    78,     0,    43,     0,     0,     0,    60,    44,     0,
     0,     0,     0,     0,    61,     0,     0,    62,    63,    64,
     0,    65,    66,    45,     0,     0,     0,     0,    46,     0,
    47,     0,     0,     0,     0,     0,     0,     0,    67,     0,
    48,     0,     0,    49,     0,     0,    50,     0,     0,    51,
     0,     0,     0,     0,    52,     0,     0,    39,     0,     0,
     0,    68,     0,    69,    70,     0,    71,     0,     0,     0,
     0,     0,    53,     0,     0,     0,     0,     0,  1028,     0,
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
     0,     0,  1233,     0,     0,     0,     0,    72,    73,     0,
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
    53,     0,     0,     0,     0,     0,  1623,     0,     0,     0,
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
  1890,     0,     0,     0,     0,    72,    73,     0,     0,     0,
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
     0,     0,     0,     0,     0,  1173,     0,     0,     0,    72,
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
     0,     0,    53,     0,     0,     0,     0,     0,     0,  1067,
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
     0,     0,     0,   745,     0,     0,     0,    72,    73,     0,
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
    53,     0,     0,     0,     0,     0,     0,  1378,     0,     0,
     0,    72,    73,     0,     0,     0,    54,     0,     0,    55,
    56,     0,     0,    40,    41,    42,    57,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    74,    58,     0,     0,
     0,     0,     0,     0,     0,    75,    76,     0,    77,     0,
     0,     0,    59,     0,     0,    43,     0,     0,     0,    60,
    44,     0,     0,     0,     0,     0,    61,     0,     0,    62,
    63,    64,     0,    65,    66,    45,     0,     0,  1174,     0,
    46,     0,    47,     0,     0,     0,     0,     0,     0,     0,
    67,     0,    48,     0,     0,    49,     0,     0,    50,     0,
     0,    51,     0,     0,     0,     0,    52,     0,     0,    39,
    78,     0,     0,    68,     0,    69,    70,     0,    71,     0,
     0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
     0,  1175,  1068,     0,     0,    72,    73,     0,     0,     0,
    54,     0,     0,    55,    56,     0,     0,    40,    41,    42,
    57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    74,    58,     0,     0,     0,     0,     0,     0,     0,    75,
    76,     0,    77,     0,     0,     0,    59,     0,     0,    43,
     0,     0,     0,    60,    44,     0,     0,     0,  1735,     0,
    61,   112,     0,    62,    63,    64,     0,    65,    66,    45,
     0,     0,     0,     0,    46,     0,    47,     0,     0,     0,
     0,     0,     0,     0,    67,     0,    48,     0,     0,    49,
     0,     0,    50,     0,     0,    51,     0,     0,     0,     0,
    52,     0,     0,    39,    78,     0,     0,    68,     0,    69,
    70,     0,    71,     0,     0,     0,     0,     0,    53,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
    73,     0,     0,     0,    54,     0,     0,    55,    56,     0,
     0,    40,    41,    42,    57,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    74,    58,     0,     0,     0,     0,
     0,     0,     0,    75,    76,     0,    77,     0,     0,     0,
    59,     0,     0,    43,     0,     0,     0,    60,    44,     0,
     0,     0,     0,  -577,    61,   112,     0,    62,    63,    64,
     0,    65,    66,    45,     0,     0,     0,     0,    46,     0,
    47,     0,     0,     0,     0,     0,     0,     0,    67,     0,
    48,     0,     0,    49,     0,     0,    50,     0,     0,    51,
     0,     0,     0,     0,    52,     0,     0,     0,    78,     0,
     0,    68,     0,    69,    70,     0,    71,     0,     0,     0,
     0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    72,    73,     0,     0,     0,    54,     0,
     0,    55,    56,     0,     0,     0,     0,     0,    57,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    74,    58,
     0,     0,     0,     0,    39,     0,     0,    75,    76,     0,
    77,     0,     0,     0,    59,     0,     0,     0,     0,     0,
     0,    60,     0,     0,     0,     0,     0,  -577,    61,   112,
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
     0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   112,     0,     0,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    59,    78,     0,    43,     0,
     0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
     0,     0,    62,    63,    64,     0,    65,    66,    45,     0,
     0,     0,     0,    46,     0,    47,     0,     0,     0,  1597,
     0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
     0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     0,     0,    39,     0,     0,     0,    68,     0,    69,    70,
     0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
     0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
    40,    41,    42,    57,     0,     0,     0,     0,   922,     0,
     0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
     0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
     0,     0,    43,     0,     0,     0,    60,    44,     0,     0,
     0,     0,     0,    61,   112,     0,    62,    63,    64,   923,
    65,    66,    45,     0,     0,     0,     0,    46,     0,    47,
     0,     0,     0,     0,     0,     0,     0,    67,     0,    48,
     0,     0,    49,     0,     0,    50,     0,     0,    51,     0,
     0,     0,     0,    52,     0,     0,     0,    78,     0,     0,
    68,     0,    69,    70,     0,    71,     0,     0,     0,   924,
     0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
    55,    56,     0,     0,     0,     0,     0,    57,     0,     0,
     0,     0,     0,     0,     0,   925,     0,    74,    58,     0,
     0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
     0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
    60,     0,     0,     0,     0,     0,     0,    61,   112,     0,
    62,    63,    64,     0,    65,    66,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    67,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,     0,     0,
     0,    78,     0,     0,    68,     0,    69,    70,     0,    71,
     0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
     0,     0,     0,   926,     0,     0,    72,    73,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
     0,    74,    40,    41,    42,     0,  1102,  1103,  1104,     0,
    75,    76,     0,    77,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    43,     0,     0,     0,     0,    44,
     0,     0,     0,     0,     0,     0,   927,     0,     0,     0,
     0,     0,     0,     0,    45,     0,     0,     0,     0,    46,
     0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    48,     0,     0,    49,    78,     0,    50,     0,     0,
    51,     0,     0,     0,     0,    52,     0,   928,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,     0,     0,     0,    57,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    58,     0,     0,     0,     0,     0,  1105,     0,     0,  1106,
     0,     0,     0,     0,   929,    59,     0,     0,     0,     0,
     0,     0,    60,     0,     0,     0,     0,     0,     0,    61,
     0,     0,    62,    63,    64,     0,    65,    66,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   783,  1080,  1081,  1082,  1083,  1084,  1085,
  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
     0,     0,     0,     0,     0,     0,    68,   930,    69,    70,
     0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,
     0,     0,     0,   785,     0,  1107,     0,     0,  1102,  1103,
  1104,     0,   787,    76,     0,    77,     0,     0,     0,     0,
  1108,     0,     0,     0,  1109,  1662,     0,     0,     0,     0,
     0,     0,     0,     0,   112,  1080,  1081,  1082,  1083,  1084,
  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
  1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1110,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1111,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
     0,     0,     0,     0,     0,     0,     0,     0,  1112,  1102,
  1103,  1104,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,  1105,     0,
     0,  1106,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,     0,     0,
  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,  1102,  1103,  1104,  1113,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,  1102,  1103,  1104,     0,
  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
  1090,  1091,  1092,  1093,  1094,  1095,     0,     0,     0,  1105,
     0,     0,  1106,     0,     0,     0,     0,     0,  1114,     0,
     0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1108,     0,     0,     0,  1109,  1669,  1096,  1097,
  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,  1102,  1103,  1104,  1086,  1087,  1088,
  1089,  1090,  1091,  1092,  1093,  1094,  1095,     0,     0,     0,
     0,     0,     0,     0,  1110,     0,  1105,     0,     0,  1106,
     0,     0,     0,     0,  1082,  1083,  1084,  1085,  1086,  1087,
  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,     0,     0,
     0,     0,  1111,     0,     0,     0,     0,     0,     0,  1096,
  1097,  1098,  1099,  1100,  1101,     0,  1105,     0,  1107,  1106,
  1112,     0,     0,     0,     0,  1102,  1103,  1104,     0,     0,
     0,     0,     0,  1108,     0,     0,     0,  1109,  1671,     0,
  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,  1102,  1103,  1104,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,  1110,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,  1105,  1107,     0,  1106,     0,     0,
     0,  1113,     0,  1111,     0,     0,     0,     0,     0,     0,
  1108,     0,     0,     0,  1109,  1672,     0,     0,     0,     0,
     0,  1112,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,  1107,     0,   216,   217,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   218,     0,
  1108,     0,  1110,     0,  1109,  1673,     0,     0,     0,     0,
     0,     0,     0,     0,     0,  1105,     0,     0,  1106,     0,
  1114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,  1110,     0,     0,     0,  1105,     0,  1112,  1106,
     0,     0,  1113,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,  1107,     0,     0,     0,     0,     0,     0,
  1111,     0,     0,     0,     0,     0,     0,     0,  1108,     0,
     0,     0,  1109,     0,     0,     0,     0,     0,  1112,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  1083,
  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
  1094,  1095,     0,     0,     0,     0,     0,     0,     0,     0,
  1110,  1114,     0,     0,     0,     0,     0,     0,     0,  1113,
     0,     0,     0,     0,  1107,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,  1111,  1108,
     0,     0,     0,  1109,  1096,  1097,  1098,  1099,  1100,  1101,
     0,     0,     0,     0,     0,  1107,  1112,     0,   219,  1113,
  1102,  1103,  1104,     0,     0,     0,     0,     0,     0,     0,
  1108,     0,     0,     0,  1109,     0,     0,     0,    39,     0,
     0,  1110,     0,     0,     0,     0,     0,     0,  1114,     0,
     0,     0,     0,     0,     0,     0,     0,   220,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  1111,
     0,     0,  1110,     0,   221,     0,    40,    41,    42,     0,
     0,     0,     0,     0,     0,     0,     0,  1112,  1114,     0,
   222,     0,     0,     0,     0,     0,     0,  1113,     0,     0,
  1111,     0,     0,     0,     0,     0,     0,     0,    43,     0,
     0,     0,   223,    44,     0,     0,     0,     0,  1112,     0,
     0,     0,     0,     0,   224,     0,     0,     0,    45,     0,
     0,     0,     0,    46,   225,    47,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    48,     0,     0,    49,     0,
     0,    50,   226,     0,    51,     0,     0,     0,     0,    52,
  1105,     0,   227,  1106,     0,     0,  1114,     0,  1113,     0,
     0,     0,     0,     0,     0,     0,     0,    53,   228,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    54,     0,     0,    55,    56,     0,  1113,
     0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    58,     0,     0,     0,   229,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
     0,     0,     0,     0,     0,     0,    60,  1114,     0,     0,
     0,   230,     0,    61,    39,     0,    62,    63,    64,     0,
    65,    66,     0,     0,     0,     0,   231,     0,     0,     0,
     0,     0,     0,   232,     0,     0,   233,    67,  1114,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
     0,     0,    40,    41,    42,     0,   234,     0,     0,   235,
    68,   236,    69,    70,  1108,    71,     0,     0,  1109,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   237,     0,    72,    73,    43,     0,     0,     0,     0,    44,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
     0,     0,     0,     0,    45,   852,  1110,    74,     0,    46,
     0,    47,     0,     0,     0,     0,    75,    76,     0,    77,
     0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
    51,     0,     0,     0,  1111,    52,     0,     0,     0,     0,
     0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
     0,     0,  1112,    53,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,     0,     0,     0,    57,
     0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
    58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
     0,     0,    60,     0,     0,     0,     0,     0,     0,    61,
    39,     0,    62,    63,    64,     0,    65,    66,     0,     0,
     0,     0,     0,  1113,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    67,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    40,    41,
    42,     0,     0,     0,     0,     0,    68,     0,    69,    70,
     0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
    43,     0,   853,     0,     0,    44,     0,     0,     0,     0,
     0,     0,  1114,     0,     0,     0,     0,     0,     0,     0,
    45,     0,     0,    74,     0,    46,     0,    47,     0,     0,
     0,     0,    75,    76,     0,    77,     0,    48,     0,     0,
    49,     0,     0,    50,     0,     0,    51,     0,     0,     0,
     0,    52,     0,     0,    39,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    54,     0,     0,    55,    56,
     0,     0,    40,    41,    42,    57,     0,    78,     0,     0,
     0,     0,     0,     0,     0,     0,    58,     0,     0,   854,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    59,     0,     0,    43,     0,     0,     0,    60,    44,
     0,     0,     0,     0,     0,    61,     0,     0,    62,    63,
    64,     0,    65,    66,    45,     0,     0,     0,     0,    46,
     0,    47,     0,     0,     0,  1718,     0,     0,     0,    67,
     0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
    51,     0,     0,     0,     0,    52,     0,     0,    39,     0,
     0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
     0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
    58,     0,     0,     0,     0,     0,     0,     0,    75,    76,
     0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
     0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
     0,     0,    62,    63,    64,     0,    65,    66,    45,     0,
     0,     0,     0,    46,     0,    47,     0,     0,     0,  1158,
     0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
     0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     0,     0,    39,    78,     0,     0,    68,     0,    69,    70,
     0,    71,     0,     0,     0,   854,     0,    53,     0,     0,
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
    68,     0,    69,    70,     0,    71,     0,     0,     0,   854,
     0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    72,    73,     0,     0,     0,    54,     0,     0,
    55,    56,     0,     0,    40,    41,    42,    57,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    74,    58,     0,
     0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
     0,     0,     0,    59,     0,     0,    43,     0,     0,     0,
    60,    44,     0,     0,     0,     0,     0,    61,   112,     0,
    62,    63,    64,     0,    65,    66,    45,     0,     0,     0,
     0,    46,     0,    47,     0,     0,     0,     0,     0,     0,
     0,    67,     0,    48,  -905,     0,    49,     0,     0,    50,
     0,     0,    51,     0,     0,     0,     0,    52,     0,     0,
    39,    78,     0,     0,    68,     0,    69,    70,     0,    71,
     0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    72,    73,     0,     0,
     0,    54,     0,     0,    55,    56,     0,     0,    40,    41,
    42,    57,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    74,    58,     0,     0,     0,     0,     0,     0,    83,
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
     0,    47,     0,     0,     0,     0,     0,     0,     0,    67,
     0,    48,     0,     0,    49,     0,     0,    50,     0,     0,
    51,     0,     0,     0,     0,    52,     0,     0,    39,    78,
     0,     0,    68,     0,    69,    70,     0,    71,     0,     0,
     0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    72,    73,     0,     0,     0,    54,
     0,     0,    55,    56,     0,     0,    40,    41,    42,    57,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
    58,     0,     0,  2604,     0,     0,     0,     0,    75,    76,
     0,    77,     0,     0,     0,    59,     0,     0,    43,     0,
     0,     0,    60,    44,     0,     0,     0,     0,     0,    61,
   112,     0,    62,    63,    64,     0,    65,    66,    45,     0,
     0,     0,     0,    46,     0,    47,     0,     0,     0,     0,
     0,     0,     0,    67,     0,    48,     0,     0,    49,     0,
     0,    50,     0,     0,    51,     0,     0,     0,     0,    52,
     0,     0,     0,    78,     0,     0,    68,     0,    69,    70,
     0,    71,     0,     0,     0,     0,     0,    53,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
     0,     0,     0,    54,     0,     0,    55,    56,     0,     0,
     0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    74,    58,     0,     0,     0,     0,     0,
     0,     0,    75,    76,     0,    77,     0,     0,     0,    59,
     0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
     0,     0,     0,    61,     0,     0,    62,    63,    64,     0,
    65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
    68,     0,    69,    70,     0,    71,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    72,    73,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
     0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    78
};

static const short yycheck[] = {    22,
    23,   156,   162,   351,   752,     0,   564,   874,   875,    35,
   877,    34,   879,   880,   867,   491,   476,   878,  1444,   112,
  1411,   863,   128,   959,   896,   730,   181,  1368,     5,   574,
  1269,  1270,   548,   514,   204,   580,    36,   973,  1648,   584,
    35,  2138,   582,  2140,   588,    26,  1021,  1700,  2139,  1759,
     5,    17,    18,   913,    86,   915,   748,    23,    24,    25,
    83,   903,   571,    86,     5,     5,  1555,   237,  1301,   609,
    93,    97,   612,     5,    17,    18,    72,    23,    24,    25,
    23,    24,    25,     5,    17,     5,     5,   110,   248,  2162,
    23,    24,    25,    88,     6,   571,    23,    23,    25,    25,
   123,     5,    97,    98,  1495,    46,    23,     5,    25,  1035,
    23,    52,    25,  1504,  1824,   141,     5,   575,    38,   467,
    40,   106,    42,   146,   605,   817,     5,   521,    59,    60,
   524,     5,     5,     5,    63,     5,     5,   990,     5,   992,
   534,  2232,     5,     5,   538,     5,   141,   121,   542,     5,
   173,   220,  2127,     6,     5,   549,   733,   121,  1637,     6,
   554,     5,   556,   206,  2082,  2083,  2084,  2085,   562,   563,
    34,  1606,     5,    22,  1609,   134,   570,   885,   886,   140,
   312,   575,     5,    17,    18,    19,    20,    21,   900,   583,
     5,   186,     5,     5,     5,     5,   357,     5,   107,   108,
   594,  1680,   663,    22,   598,  2421,   219,     5,   602,  2633,
  1689,  2635,  2590,   607,   320,   963,   610,   327,   308,   130,
     9,   177,    11,    12,    13,    14,    15,    16,  1812,   252,
   253,   327,   143,   426,  2715,   258,   259,   308,    17,    18,
    19,    20,    21,     5,    26,   245,     5,   426,   245,  1066,
   426,     5,   275,   398,  1567,     5,   167,  1856,   266,   170,
   147,   359,  2572,   286,     5,   253,    22,     5,     5,   594,
   265,   513,   378,   379,    88,   398,  1702,  2654,   266,  2656,
   544,   453,   408,   401,    98,   354,   406,   356,   505,   461,
    45,     5,   617,   316,     5,   393,   319,   417,     5,     5,
   438,   324,   425,  2400,     5,  2402,   527,  2404,   446,    30,
   482,     5,   312,   245,     5,   308,     5,  2414,   438,   540,
  2801,   398,   586,   245,  2421,   445,  2036,  2418,   239,    28,
     5,     5,     5,   443,     5,   328,   317,     5,   253,   556,
  1212,     5,     5,     5,     5,   587,     5,   443,     5,   426,
   468,   266,   375,   312,   302,   242,   205,   357,    27,     9,
   122,    11,    12,    13,    14,    15,    16,    17,    18,    19,
    20,   112,   186,   396,   213,   398,    17,    18,    19,    20,
    21,  1860,   558,   509,   122,   929,   205,   588,   406,   397,
   595,   302,  2638,   304,   595,  2641,   589,   363,   309,   417,
  2375,   241,    26,   300,   244,   353,   246,  1886,   589,   397,
   589,   367,   378,   589,    64,    65,    66,    67,    68,    69,
   363,   882,  1136,  1171,  1138,   438,   266,   450,   889,   472,
   453,   254,   564,   459,   223,   378,   276,   321,   461,  1016,
  2818,  1153,   426,   254,   554,   406,   589,   359,   359,   205,
   595,   265,  2876,   293,   523,  2832,   417,   547,   554,   482,
   371,   586,  1897,   458,   459,   488,  1705,   628,   491,   492,
  2054,   494,   438,   867,   497,   315,   547,   438,   341,   319,
  2577,   330,   397,   134,   445,   508,  1044,  1045,  1046,  1197,
   357,   355,   515,  2590,  2804,   404,   481,   359,  2808,   359,
   758,   759,  2718,  1061,   527,   394,   359,  1047,   359,    24,
  1019,   330,   359,   771,   537,   359,   380,   540,   492,   777,
   778,   394,   394,  2596,   394,   394,   359,   550,   492,  2128,
  2129,  1457,   790,   991,   445,   317,   536,    70,   394,   536,
  2522,   564,   565,  1019,   359,  1858,   359,   359,   571,   359,
   339,   359,   511,   515,   547,   505,   579,   397,   581,   582,
   394,   359,   585,   595,     5,   506,   589,   590,   564,   592,
   593,  2489,   595,   223,   597,   537,   599,   517,  2553,  2554,
   603,   604,  1518,   606,   481,   608,   609,   546,   611,   612,
  1407,   614,   321,  1410,   491,  1139,   990,   991,   992,  1157,
   359,   520,  1294,  1295,   536,   359,   556,  1151,   448,   359,
     5,  1303,  1152,   517,   536,   394,  2326,   579,   618,   619,
   620,  2718,   359,   589,  1140,   523,  1135,   589,   590,   629,
  1490,   593,   587,  2122,   513,   597,  2289,   599,  1871,   513,
  2293,   603,   604,   589,   458,   359,   589,  1205,   359,  2040,
   631,  1626,   359,   359,   631,   596,   589,  2048,   359,  1135,
  2751,   312,   589,   589,   595,   359,   393,   587,   359,  2760,
   359,   129,   589,  1231,  2153,   595,   589,    25,  1236,   608,
   609,   610,   611,   612,   359,   359,   359,   710,   359,   339,
    13,   359,  1232,   557,  2589,   359,   359,   359,   359,   722,
   359,   724,   359,  2685,  1249,   569,   570,  2476,   505,   359,
   733,   323,   241,   398,   578,   244,   608,   246,   359,   611,
   612,  2818,   406,   426,   556,   748,  1266,  1267,   266,   502,
  1583,   563,   398,   417,   523,   758,   759,   266,   398,   524,
   425,   426,    25,   398,  1225,   426,   396,   276,   771,   398,
  2229,  2230,  2231,   538,   777,   778,  2235,   542,   398,   556,
   275,  2371,    27,    28,   279,   280,   281,   790,   301,   554,
   425,   426,    80,    81,    82,   607,  2015,   315,   610,   398,
   313,   319,   398,  1041,   299,  2126,   315,   425,   426,   209,
   319,  1049,  1050,   633,   817,   426,  2565,  2470,  2567,  2472,
  2473,   398,  1346,  2572,  2699,  1063,   398,   594,   719,   267,
  2792,   598,  2794,    25,   608,   602,  1074,   611,  1076,  1077,
   614,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  2548,   318,
   863,   864,   595,   209,   377,    25,   266,   594,  1106,  1107,
   293,   384,   595,  1111,   594,  1113,   883,   884,  1018,   397,
   887,   888,  1407,   342,  1725,  1410,   345,    25,   397,   616,
   617,   425,   426,   523,   897,    25,   616,   617,    29,   135,
   903,  1573,   340,   139,   363,  1357,   304,  1359,   500,   589,
   423,   609,   610,   916,   409,   315,   314,  2376,   921,   319,
   266,   863,   514,  1009,   927,   161,  1012,  2802,  2803,    17,
    18,    19,    20,    21,   447,    25,  1456,   589,   433,   448,
    25,   571,   945,    25,   457,   458,    25,  2318,   540,    25,
  1802,   258,   259,    25,   293,   897,   959,   452,   618,   619,
   473,   903,   592,    94,    95,  2424,    97,    98,   366,   315,
   973,   102,   398,   319,   916,   611,   612,    84,  1502,   921,
   589,   494,    25,   381,   497,   498,   618,   619,   119,   120,
   503,   398,   487,   582,   583,   584,   585,   397,   590,   398,
  1538,  1539,  2240,  2241,   394,   241,   137,   138,   244,   468,
   135,   506,   507,  1016,   139,     5,  1019,   359,  1021,  1022,
  1155,   459,  1025,   589,    25,   448,   229,   522,   394,  1862,
   266,   398,   359,    25,  1554,  1559,   161,   398,  1041,   398,
    20,  1044,  1045,  1046,  1047,    20,  1049,  1050,    25,   562,
    20,   397,  1885,    25,    25,  2804,    25,    25,  1061,  2808,
  1063,   574,   521,     5,   398,    25,    25,    25,   563,   448,
   529,  1074,   470,  1076,  1077,  1449,  1079,  1080,  1081,  1082,
  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
  1093,  1094,  1095,   359,    64,    65,    66,    67,    68,    69,
   398,   596,   329,  1106,  1107,  1629,   273,   359,  1111,   448,
  1113,   359,  2702,  2703,  1639,   359,   241,   359,   593,   244,
     5,   359,   273,  2582,   633,  1363,   359,   359,    17,    18,
    19,    20,  1135,   593,    17,    18,    19,    20,  1141,  1142,
  1143,   266,  1292,  1381,  1382,  1383,   359,  1385,  1298,  1152,
   329,  1154,   488,  1156,  1157,   426,   426,  1681,  1161,  1683,
   589,   397,     5,   359,   359,  2624,  2625,   427,  1692,   359,
    25,   594,   359,  1411,  1846,    64,    65,    66,    67,    68,
    69,    64,    65,    66,    67,    68,    69,   589,  1562,  1874,
   613,   614,   426,   324,   586,  1198,   589,     8,   492,  1141,
  1142,  1143,  1205,   394,   398,  2664,   446,   237,   427,  1583,
   633,    29,   398,    31,   398,   594,  1888,   398,   398,  1161,
   398,  1224,   398,   398,   398,   398,  1229,   398,  1231,  1232,
   398,     5,   398,  1236,   613,   614,  2557,  1240,  1241,  2560,
   398,   398,   373,  2065,  1769,   398,   398,   388,  1251,  1335,
   398,  1489,   398,  1339,   633,   594,  1198,  1495,   398,    77,
    78,   587,  1265,  1266,  1267,   587,  1504,    85,  1341,  2121,
   628,   564,   397,  2679,   613,   614,    94,    95,   388,    97,
    98,   398,  1224,   427,   102,   628,   295,     8,  1291,   231,
   565,  1294,  1295,   490,   633,     5,  1299,   558,  1301,  1241,
  1303,   119,   120,   135,  2032,     5,   503,   139,   312,  1251,
   351,   398,   398,   211,  1651,   213,   547,   398,   398,   137,
   138,    33,   241,   398,  1661,   244,     8,   246,   270,   398,
   558,   543,  1669,   530,  1671,  1672,  1673,    13,    17,    18,
    19,    20,     5,  2259,   628,   287,     5,   266,   628,   546,
   547,   388,   398,  1356,  1357,   552,  1359,   276,   555,   398,
  1363,    25,    36,    25,    63,  2771,    17,    18,    19,    20,
   394,  2830,   394,   398,   293,   564,   558,  2836,  1381,  1382,
  1383,   589,  1385,   325,  2790,    64,    65,    66,    67,    68,
    69,   398,   398,   558,   438,   337,   315,   595,    20,   398,
   319,   398,   595,   334,   398,   347,   631,   398,  1411,   241,
  1413,   594,   244,    64,    65,    66,    67,    68,    69,   318,
   523,    18,  2793,   365,  1427,     3,     4,     5,     6,     7,
     8,   595,    10,   375,   266,  1959,  1674,  2843,  1676,     5,
    17,    25,  1445,    25,   124,   188,   558,   592,  1451,   391,
  1453,  1454,  1455,  1456,  1915,  1916,  1917,  2309,  1919,  1920,
  1921,  1922,  1923,  1924,    24,   449,  2307,  1928,   449,   547,
   359,     5,  1912,   513,   334,  1999,   359,   122,   397,   513,
     5,  1484,  1856,    25,   290,  1427,  1489,   124,  1862,   431,
   421,   367,  1495,   513,   131,    94,    95,  1500,    97,    98,
   428,  1504,   428,   102,   595,   589,   437,  1510,   544,  1451,
   513,  1885,   454,  1455,   359,  1518,   586,   335,   359,   359,
   119,   120,  1525,   359,  1527,   359,   359,   469,   359,   448,
   359,   359,   548,     5,   476,  1538,  1539,   479,   137,   138,
     5,     5,  1484,   361,    17,    18,    19,    20,     5,   480,
   450,  1554,   359,   595,   589,     5,   398,   499,   270,   398,
   502,   421,   504,   594,   520,   397,    25,    25,  1510,  2107,
  1573,  2109,   398,   502,    36,   294,   359,   437,  1581,     5,
   131,   523,   359,  1911,  2417,   398,  2314,   359,   519,  1592,
  2262,    64,    65,    66,    67,    68,    69,   148,   149,   328,
   542,   565,  1605,  1606,   589,   156,  1609,   595,   207,    13,
   629,   517,   513,   325,   432,   513,   514,     5,    25,   550,
   480,   219,   438,  1626,    72,   337,   334,  1630,   559,   398,
   595,   552,   589,   398,  1637,   347,     5,   188,   593,   100,
   594,   608,  2494,  2099,   593,  1648,   197,     8,   109,     5,
  2502,   589,   359,   365,     5,   359,   359,   118,     5,   519,
     8,   294,   123,   375,   589,   589,   378,   426,   312,   312,
   312,  1674,   589,  1676,   398,   328,   227,  1680,    32,   391,
   359,  1684,  1685,  1686,  1687,   398,  1689,   393,  1630,    21,
   550,     5,  1695,  1696,   388,   334,  1699,  1700,   620,   559,
   398,   398,   398,  2227,   165,  1708,   524,   605,   359,   398,
   509,     5,   173,   421,   633,  1718,    25,   615,     5,     5,
     5,   272,    25,   586,     5,   398,   564,   439,   589,   437,
   589,     5,    64,    65,    66,    67,    68,    69,     5,   564,
     5,  1979,  1684,  1685,  1686,  1687,    24,    24,    80,    81,
    82,   105,  2276,    24,  2128,  2129,   414,   469,   588,    25,
   311,    24,  1765,    24,  1767,    25,  1708,   479,    25,   230,
    25,    25,   480,     8,   589,   398,  1779,  2297,   398,   398,
   398,    20,   421,   359,  2304,   359,   359,   499,  2516,   607,
   502,   359,   504,     5,   255,   359,   359,   615,   437,  2037,
  1803,   262,  2040,   264,   534,   245,   405,   359,     5,  2481,
  2048,   519,     5,   274,     5,   169,   211,   171,   513,   359,
   359,   533,   539,  1765,   426,  2677,   398,   595,   408,   589,
   542,   359,   186,   398,   438,     6,   398,   298,     7,   595,
   194,   480,   550,  1846,   198,   306,    13,     5,   520,    13,
   520,   559,   489,   490,   752,   595,   180,  1860,     5,    25,
  1863,   239,   589,   398,   492,   398,   503,  1870,  1871,   398,
   224,   398,  1875,  1876,  2602,  1878,   398,   398,   436,     5,
   519,   342,  1000,  1886,   521,  1888,   359,   524,   220,   398,
   359,   223,   517,   530,  1897,   211,   794,   534,   312,   394,
   408,   538,   312,    90,  1910,   542,   359,   368,    20,   546,
   547,   550,   549,   111,   438,   552,   398,   554,   555,   556,
   559,   398,   589,   359,   180,   562,   563,  2774,  2775,  2776,
  2777,  2778,  2779,   570,  1876,  1910,  1878,  1943,   575,    17,
    18,    19,    20,     5,    25,   406,   583,  2799,    17,    18,
    19,    20,   210,    25,   595,   334,   417,   594,   210,  1962,
    25,   598,     5,   336,   588,   602,     8,   341,  1943,   536,
   607,    25,  2496,   610,   359,  2647,  1979,   359,   398,   212,
   398,     5,  2654,   513,  2656,     5,    64,    65,    66,    67,
    68,    69,    13,    25,   267,    64,    65,    66,    67,    68,
    69,   231,  2005,   426,   191,  2008,    25,   339,     5,   359,
  2013,   398,   199,    64,    65,    66,    67,    68,    69,   206,
   359,   208,   354,  2026,   359,  2028,   358,  2030,   398,   415,
   360,  2269,   219,   589,  2037,   398,    20,  2040,   334,   359,
   270,  2044,   421,  2417,   409,  2048,   334,   359,   394,   359,
   105,    25,   359,    25,   515,   516,   517,   287,   437,   359,
   247,   398,  2065,  2005,   396,   963,  2008,     5,   529,     5,
    24,   106,   212,     0,     5,   595,   263,   359,     0,   359,
  2318,   268,  1962,  2086,  2087,  2088,  2089,  2090,  2091,   359,
   359,   278,   424,  2043,  2853,   325,  2099,    29,   285,   134,
   135,   480,  1511,  1979,  2107,  1755,  2109,   337,  1242,    17,
   442,  1696,    19,   458,   169,  1702,   171,   347,  2026,   114,
   309,   156,   167,  2065,   170,   421,   221,   162,  2666,   105,
   303,   186,   408,   421,   310,   365,  2139,   324,  2141,   194,
   519,   437,   371,   198,  2668,   375,   181,   718,   183,   437,
  2153,   224,   223,   384,   339,  2158,  2291,   338,   719,  2162,
  2832,   391,    94,    95,   396,    97,    98,  2843,  1484,   224,
   102,   550,   398,   634,  2177,  2178,  2179,  2905,  1676,   592,
   559,  1603,  2185,   997,   480,  1610,  1686,   119,   120,  2355,
  2330,   523,   480,   169,  1014,   171,  1455,  1265,  2102,  1534,
  1690,   431,  1268,  2118,  1799,   137,   138,  1157,  1326,  1327,
   186,  1549,  2510,   248,    98,  1333,   265,  2452,   194,   712,
  2116,  1516,   198,   519,   454,   551,  2229,  2230,  2231,  2232,
   867,   519,  2235,  1522,   210,  1252,   183,   724,  2714,   469,
  1273,   964,  1525,  2439,  2211,  1148,   476,  1195,   224,   479,
  1565,   438,  2087,  2790,   550,  1955,  2259,  1138,   445,  2262,
   592,  2449,   550,   559,   916,  1070,  2269,   251,  1953,   499,
  1937,   559,   502,  1171,   504,  1622,  2663,  1224,  1025,  1680,
   467,   359,  2235,  2420,  2873,   472,  2289,  1856,  2836,  2292,
  2293,   993,  1889,   523,  2297,  2722,  2623,  2300,  2830,  2231,
  2652,  2304,    19,    20,  2481,   289,   290,   291,  2263,  2388,
  2387,  2141,   542,  2567,  2151,  2318,  2632,  1291,  2179,  2665,
  2552,  2834,   993,  2538,  2158,  2328,  2154,  1225,  2697,   989,
  2410,   456,    -1,     7,  1287,  1626,  2339,   321,  2341,  2342,
  2343,  2344,   326,    17,    18,    19,    20,    64,    65,    66,
    67,    68,    69,   990,   991,   992,    -1,   341,  2300,    -1,
    -1,    -1,   346,    -1,   348,    -1,  2369,    -1,  2371,    -1,
    -1,    -1,    -1,  2376,   358,  1273,  1494,   361,    -1,    -1,
   364,    -1,    -1,   367,  2387,  2388,  2328,    -1,   372,    -1,
    64,    65,    66,    67,    68,    69,  2399,    -1,    -1,    -1,
    -1,  2404,    -1,    -1,    -1,    -1,   390,  2410,    -1,    -1,
    -1,  2414,  1530,    -1,    -1,  2418,    -1,  2420,  2421,    -1,
    -1,  2424,   406,  2426,    -1,   409,   410,    -1,    -1,    -1,
    -1,     9,   416,    11,    12,    13,    14,    15,    16,    17,
    18,    19,    20,   427,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,
    -1,    -1,    -1,  2466,   499,   449,    -1,    -1,    -1,    -1,
    -1,    -1,   456,    -1,    -1,   459,   460,   461,  2481,   463,
   464,    -1,  2485,    -1,  2487,    -1,    64,    65,    66,    67,
    68,    69,    -1,    -1,    -1,  2498,   480,    -1,   533,    -1,
    -1,    -1,    -1,    -1,   539,    -1,   541,    -1,    -1,    -1,
   545,    -1,    -1,   548,    -1,    -1,   551,    -1,    -1,   503,
    -1,   505,   506,    -1,   508,    -1,   561,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,  2538,    -1,    -1,    -1,    -1,
  2543,   525,   526,   578,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   586,   587,   588,    -1,  2793,  2498,   592,    15,    16,
    17,    18,    19,    20,    21,   600,   550,    -1,  2571,    -1,
  2573,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,  2582,
   615,    -1,    -1,    -1,    -1,    -1,    -1,  2590,    -1,    -1,
    -1,    -1,    -1,  2596,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,  2608,    -1,    64,    65,    66,
    67,    68,    69,    -1,    -1,    -1,    -1,    -1,  1255,    -1,
    -1,  2624,  2625,    80,    81,    82,    -1,    -1,    -1,  1527,
    -1,  1749,  1750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   624,    -1,  1760,    -1,  2647,   223,    -1,    -1,    -1,    -1,
    -1,  2654,   636,  2656,    -1,    -1,  2659,    -1,    -1,    -1,
    -1,  2664,    -1,  2666,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
    -1,    -1,    26,  1581,    -1,    -1,    -1,    -1,    -1,    -1,
  1808,  1809,  1810,  1811,  2697,    -1,    -1,    -1,    -1,  2702,
  2703,    -1,    -1,    -1,    -1,  1823,    -1,    -1,    -1,    -1,
  2713,    -1,    -1,    -1,    -1,  2718,    -1,   752,    -1,  2722,
    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1527,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   781,    -1,  2751,    -1,
  1648,    -1,    -1,    -1,    -1,    -1,    -1,  2760,    -1,    -1,
    -1,   339,    -1,   220,    -1,    -1,   223,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   814,
  1898,  1899,  2785,  2786,    -1,    -1,    -1,  1905,  1906,    -1,
  2793,  1581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,  2807,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,  1449,    -1,    -1,  2818,    -1,    -1,   396,    -1,
    -1,    -1,    -1,    -1,   859,    -1,    -1,  2830,    -1,  2832,
    -1,  2834,    -1,  2836,    -1,    -1,    -1,    -1,   873,   874,
   875,    -1,   877,  2785,   879,   880,    -1,    -1,    -1,    -1,
   885,   886,    -1,    -1,    -1,    -1,    -1,    -1,  1648,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
  2873,    -1,  1770,  1771,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,  1779,   339,    -1,    -1,    -1,  2889,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   929,    -1,    -1,   354,  2016,  2017,
    -1,   358,    -1,    -1,    -1,   940,    -1,  2025,    17,    18,
    19,    20,    21,    -1,    -1,  2033,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,  1562,    -1,    -1,   963,   964,
    -1,    -1,    -1,  2051,  2052,    -1,    -1,   972,    -1,   396,
    -1,    -1,    -1,    -1,    -1,   523,  1583,  2889,    -1,    -1,
    -1,    -1,    -1,   988,   989,    64,    65,    66,    67,    68,
    69,    -1,    -1,    -1,    -1,  1863,    -1,   424,    -1,    -1,
    -1,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,  1018,    -1,   442,    -1,    -1,  1625,  1779,
  2108,    -1,  2110,   571,    -1,    -1,    -1,    -1,    -1,  2117,
    -1,  2119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   592,    -1,    -1,  1915,  1916,  1917,
    -1,  1919,  1920,  1921,  1922,  1923,  1924,    -1,    -1,    -1,
  1928,    -1,    -1,  1068,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   523,    -1,  2186,  2187,
    -1,    -1,  2190,  2191,    13,    14,    15,    16,    17,    18,
    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,  1128,    -1,    -1,  2214,    -1,    -1,    -1,
    -1,  1136,    -1,  1138,  1139,  1140,    -1,    -1,    -1,    -1,
    -1,   220,  1147,  1148,   223,    -1,  1151,    -1,    -1,    -1,
  1155,    -1,    -1,  1158,    -1,    64,    65,    66,    67,    68,
    69,    -1,    -1,    -1,  2032,   592,  1171,    -1,    -1,    -1,
    -1,    80,    81,    82,    -1,    -1,  1783,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,  1197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,  2290,    -1,    -1,    -1,  2294,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2086,  2087,
  2088,  2089,  2090,  2091,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,  1238,    -1,    -1,  2324,    -1,    -1,    -1,
  1847,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1856,
    -1,    -1,    -1,    -1,    -1,  1862,  1261,    -1,    -1,    -1,
   339,    -1,    -1,    -1,    -1,  2353,    -1,  1272,  1273,    -1,
    -1,  2139,    -1,  2141,    -1,   354,    -1,    -1,  1885,   358,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
  2158,    -1,    -1,    -1,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,   220,    -1,    -1,   223,    -1,    -1,   396,    -1,    -1,
    -1,    -1,    -1,  1328,    -1,    -1,  2086,  2087,  2088,  2089,
  2090,  2091,    -1,    14,    15,    16,    17,    18,    19,    20,
    21,  1346,    -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
    -1,    -1,    -1,   442,  2232,    -1,    -1,    -1,  1975,    80,
    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2139,
    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2158,    80,
    81,    82,    -1,    -1,     6,     7,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2527,
    -1,    -1,    -1,    -1,   523,   354,  2314,    -1,    -1,   358,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,    -1,
    -1,  2339,    -1,  2341,  2342,  2343,  2344,  1482,    80,    81,
    82,    -1,    -1,    -1,    -1,    -1,  1491,   396,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1502,    -1,    -1,
    -1,    -1,    -1,  2371,    -1,    -1,    -1,    -1,    -1,   220,
    -1,    -1,   223,   592,    -1,   424,    -1,  1522,    -1,  2387,
  2388,  2128,  2129,    -1,  2612,  2613,    -1,  2615,    -1,  2617,
  2618,  2399,    -1,   442,    -1,    -1,  2404,    -1,    -1,   220,
    -1,    -1,   223,    -1,    -1,    -1,  2414,    -1,    -1,    -1,
  2418,    -1,    -1,  2421,  1559,    -1,  1561,    -1,    -1,    -1,
  1565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,  2339,
    -1,  2341,  2342,  2343,  2344,    -1,    -1,    -1,    -1,    80,
    81,    82,  1597,    -1,    -1,    -1,    -1,    -1,  2686,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2476,    -1,
    -1,  2371,    -1,    -1,   523,    -1,    -1,    -1,   220,    -1,
    -1,   223,    -1,    -1,  1629,    -1,    -1,    -1,   339,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2399,
  2728,    -1,  2730,   354,  2404,    -1,    -1,   358,  2516,    -1,
    -1,    -1,    -1,    -1,  2414,    -1,    -1,    -1,   339,    -1,
    -1,  2421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
  2538,    -1,    -1,   354,    -1,  2543,  1681,   358,  1683,    -1,
    -1,    -1,    -1,   592,    -1,   396,    -1,  1692,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2565,    -1,  2567,
    -1,    -1,    -1,  2571,  2572,  2573,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   424,    -1,   396,    -1,    -1,    -1,    -1,
    -1,    -1,  2590,    -1,    -1,  1730,    -1,    -1,    -1,   220,
    -1,   442,   223,  2340,  2602,    -1,    -1,   339,    -1,    -1,
    -1,    43,    44,   424,    -1,    47,    48,    49,    -1,    -1,
    -1,    -1,   354,    -1,  1759,    -1,   358,   359,    -1,    -1,
    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
  2858,  2378,    -1,    -1,    -1,  2382,    -1,    -1,  2538,    -1,
    -1,    -1,    -1,  2543,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,  2659,    -1,    -1,   396,  2883,  2884,    -1,    -1,  2887,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
  2417,  2571,   523,  2573,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   424,    -1,    22,    -1,    -1,    -1,    -1,    -1,
  2590,    -1,    -1,    -1,  2702,  2703,    -1,    -1,    -1,    -1,
   442,    -1,   523,    -1,    -1,  2713,    -1,   149,   339,    -1,
  2718,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   354,    -1,    63,    -1,   358,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   592,    -1,  2751,    -1,    -1,   188,    -1,    -1,    -1,
    -1,  1896,  2760,    -1,    -1,   197,    -1,    -1,    -1,  2659,
    -1,    -1,    -1,    -1,    -1,   396,    -1,   105,    -1,    -1,
    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   523,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
    -1,    -1,    -1,   424,  1939,    -1,  2804,   135,    -1,  2807,
  2808,   139,  2702,  2703,    -1,    -1,    -1,  1952,    -1,    -1,
  2818,   442,    -1,  2713,  1959,    -1,    -1,    -1,  2718,    -1,
    -1,    -1,    -1,   161,    -1,    -1,  2834,    -1,    -1,    -1,
   272,   169,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,   186,    -1,
   592,    -1,    -1,    -1,  1999,    -1,   194,    -1,    -1,    -1,
   198,    -1,    -1,    -1,    -1,  2873,    -1,   205,    -1,   311,
    -1,   209,   210,   211,   212,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   224,  2032,    -1,    -1,
    -1,    -1,   523,    -1,    -1,    -1,  2041,  2905,  2043,    -1,
  2045,    -1,    -1,   241,    -1,    -1,   244,  2807,   246,    -1,
    -1,    -1,  2057,    -1,    -1,   253,    -1,    -1,  2818,    -1,
    -1,    -1,    -1,    -1,    -1,   367,    -1,    -1,   266,    -1,
    -1,    -1,    -1,    -1,  2834,    -1,    -1,    -1,   276,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   293,   294,    -1,    -1,    -1,
    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   308,    -1,    -1,  2873,    -1,    -1,    -1,   315,    -1,    -1,
    -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   328,   329,   330,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    17,
    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
    -1,    -1,    -1,    41,    -1,  2180,    -1,    16,    17,    18,
    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    64,    65,    66,    67,    68,    69,    -1,    -1,   397,
    -1,    -1,    -1,    71,    -1,    -1,  2211,    80,    81,    82,
   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,  2227,    -1,    -1,    64,    65,    66,    67,    68,
    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,  2276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,  2291,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   162,   597,   598,   599,   600,   601,
   602,   603,   604,   605,   606,    -1,    -1,    -1,    -1,  2314,
    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,  2330,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   547,
   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   220,    -1,   251,   223,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   260,    -1,    -1,    -1,   594,   265,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2412,    -1,    -1,
   608,   609,   610,   611,   612,   613,   614,    -1,   616,   617,
    -1,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,  2439,   633,    -1,    -1,    -1,  2444,
    -1,  2446,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   321,    -1,    -1,    -1,    -1,   326,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,    -1,
    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,    -1,
   348,   354,    -1,    -1,    -1,   358,   359,   355,    -1,    -1,
   358,  2496,   360,   361,    -1,   363,   364,    -1,    -1,   367,
   339,    -1,    -1,    -1,   372,    -1,   374,    -1,    -1,    -1,
    -1,  2516,   380,    -1,    -1,   354,    -1,    -1,    -1,   358,
    -1,    -1,   390,   396,    -1,    -1,    -1,   395,    -1,    -1,
   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,   406,    -1,
    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,
    -1,   424,    -1,    -1,    -1,    17,    18,   396,    -1,   427,
    -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,   442,
    -1,    -1,    34,    35,   442,    -1,    -1,    -1,    -1,    41,
    -1,   449,   450,   451,    -1,   424,    -1,   455,   456,    -1,
    -1,   459,   460,   461,    -1,   463,   464,  2602,    -1,    -1,
    -1,    -1,    -1,   442,    -1,    -1,   474,    -1,    -1,    71,
    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   503,   504,   505,   506,    -1,
   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   523,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,
  2665,    -1,    -1,  2668,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
    -1,    -1,   550,    -1,   523,    -1,    -1,    -1,    -1,   557,
    -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,
   162,   569,   570,   571,    -1,    -1,    -1,    -1,    -1,  2714,
   578,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,   592,
    -1,   589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   592,    -1,    -1,   624,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2774,
  2775,  2776,  2777,  2778,  2779,    -1,    -1,    -1,    -1,    -1,
    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,
    -1,    -1,    -1,   265,    -1,    -1,    17,    18,    -1,    -1,
    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    34,    35,    -1,    -1,   289,   290,   291,
    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,
    71,    -1,    -1,   255,   326,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,   341,
    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,
    -1,    -1,    -1,   355,    -1,    -1,   358,    -1,   360,   361,
  2905,   363,   364,    -1,    -1,   367,   298,    -1,    -1,   301,
   372,    -1,   374,    -1,   306,    -1,    -1,    -1,   380,    -1,
    -1,   313,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
    -1,    -1,    -1,   395,    -1,    -1,   398,    -1,    -1,   401,
    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
    -1,   162,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   442,    -1,    -1,    -1,    -1,   377,    -1,   449,    -1,   451,
    -1,    -1,   384,   455,   456,    -1,    -1,   459,   460,   461,
    -1,   463,   464,    -1,    -1,    -1,    -1,   399,    -1,    -1,
    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   480,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   251,   503,   504,   505,   506,    -1,   508,    -1,    -1,   260,
    -1,    -1,    -1,    -1,   265,   447,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   525,   526,   457,   458,    -1,    17,    18,
    -1,    -1,    -1,    -1,    23,    24,    25,    -1,   289,   290,
   291,   473,    -1,    -1,    -1,    34,    35,    -1,   550,    -1,
    -1,    -1,    41,    -1,    -1,   557,    -1,   559,   560,    -1,
   562,    -1,   494,    -1,    -1,   497,   498,   569,   570,   571,
   321,   503,    -1,    -1,    -1,   326,   578,    -1,    -1,   581,
    -1,    -1,    71,    -1,    -1,    -1,    -1,   589,    -1,    -1,
   341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,
    -1,    -1,    -1,    -1,   355,    -1,    -1,   358,    -1,   360,
   361,    -1,   363,   364,    -1,    -1,   367,    -1,    -1,    -1,
    -1,   372,   624,   374,    -1,    -1,    -1,    -1,    -1,   380,
   562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
   572,    -1,   574,    -1,   395,    -1,    -1,   398,    -1,    -1,
   401,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   162,    -1,    -1,   427,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,   450,
   451,    -1,    -1,    -1,   455,   456,    -1,    -1,   459,   460,
   461,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   480,
    -1,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
    -1,    -1,   503,   504,   505,   506,    -1,   508,    -1,    -1,
    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   260,    -1,    -1,   525,   526,   265,    -1,    -1,    17,
    18,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,   550,
   289,   290,   291,    41,    -1,    -1,   557,    -1,   559,   560,
    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,   569,   570,
   571,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,
   581,    -1,   321,    71,    -1,    -1,    -1,   326,   589,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
    -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,   358,
    -1,   360,   361,   624,   363,   364,    -1,    -1,   367,    -1,
    -1,    -1,    -1,   372,    -1,   374,    -1,   220,    -1,    -1,
   223,   380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,   398,
    -1,    -1,   401,    -1,    -1,    -1,    -1,   406,    -1,    -1,
   409,   410,    -1,    -1,   162,    -1,    -1,   416,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,
   449,    -1,   451,    -1,    -1,    -1,   455,   456,    -1,    -1,
   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   474,    -1,   476,    -1,    -1,
    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,    -1,
    -1,    -1,    -1,   251,   503,   504,   505,   506,    -1,   508,
    -1,   354,   260,    -1,    -1,   358,    -1,   265,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
    -1,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
    -1,   289,   290,   291,    -1,    -1,    -1,    -1,    34,    35,
    -1,   550,    -1,   396,    -1,    41,    -1,    -1,   557,    -1,
   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,
   569,   570,   571,   321,    -1,    -1,    -1,    -1,   326,   578,
    -1,   424,   581,    -1,    -1,    71,    -1,    -1,    -1,    -1,
   589,    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,   442,
   348,    -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,
   358,    -1,   360,   361,    -1,   363,   364,    -1,    -1,   367,
    -1,    -1,    -1,    -1,   372,   624,   374,    -1,    -1,    -1,
    -1,    -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,
   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,   406,    -1,
    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,   427,
   523,    11,    12,    13,    14,    15,    16,    17,    18,    19,
    20,    21,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,
    -1,   449,   450,   451,    -1,    -1,    -1,   455,   456,    -1,
    -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
    -1,    -1,   480,    -1,    64,    65,    66,    67,    68,    69,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,
    80,    81,    82,    -1,    -1,   503,   504,   505,   506,    -1,
   508,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   260,    -1,    -1,   525,   526,   265,
    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
    35,    -1,   550,   289,   290,   291,    41,    -1,    -1,   557,
    -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,
    -1,   569,   570,   571,    -1,    -1,    -1,    -1,    -1,    -1,
   578,    -1,    -1,   581,    -1,   321,    71,    -1,    -1,    -1,
   326,   589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,
   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,   355,
    -1,    -1,   358,   359,   360,   361,   624,   363,   364,    -1,
    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,   374,    -1,
   220,    -1,    -1,   223,   380,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,   395,
    -1,    -1,   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,
   406,    -1,    -1,   409,   410,    -1,    -1,   162,    -1,    -1,
   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,
    -1,    -1,    -1,   449,    -1,   451,    -1,    -1,    -1,   455,
   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,
    -1,    -1,    -1,    -1,    -1,    -1,   251,   503,   504,   505,
   506,    -1,   508,    -1,   354,   260,    -1,    -1,   358,    -1,
   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,
   526,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
    23,    24,    25,    -1,   289,   290,   291,    -1,    -1,    -1,
    -1,    34,    -1,    -1,   550,    -1,   396,    -1,    -1,    -1,
    -1,   557,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,
    -1,    -1,    -1,   569,   570,   571,   321,    -1,    -1,    -1,
    -1,   326,   578,    -1,   424,   581,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   589,    -1,    -1,   341,    -1,    -1,    -1,
    -1,   346,   442,   348,    -1,    -1,    -1,    -1,    -1,    -1,
   355,    -1,    -1,   358,    -1,   360,   361,    -1,   363,   364,
    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,   624,   374,
    -1,    -1,    -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
   395,    -1,    -1,   398,    -1,    -1,   401,    -1,    -1,    -1,
    -1,   406,    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,
    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   427,   523,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,
    -1,    -1,    -1,    -1,   449,    -1,   451,    -1,    -1,    -1,
   455,   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,   503,   504,
   505,   506,    -1,   508,    -1,    -1,    -1,    -1,   251,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   525,   526,   265,    -1,    -1,    17,    18,    -1,    20,    -1,
    -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    34,    -1,    -1,   550,   289,   290,   291,    -1,
    -1,    -1,   557,    -1,   559,   560,    -1,   562,    -1,    -1,
    -1,    -1,    -1,    -1,   569,   570,   571,    -1,    -1,    -1,
    -1,    -1,    -1,   578,    -1,    -1,   581,    -1,   321,    -1,
    -1,    -1,    -1,   326,   589,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,
    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,   624,
   363,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
    -1,    -1,   395,    -1,    -1,   398,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,   442,
    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,   451,    -1,
    -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
   503,   504,   505,   506,    -1,   508,    -1,    17,    18,    -1,
    20,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,
    -1,    -1,   525,   526,    34,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,   290,   291,
    -1,   544,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,
    -1,    -1,    -1,    -1,   557,    -1,   559,   560,    -1,   562,
    -1,    -1,    -1,    -1,    -1,    -1,   569,   570,   571,   321,
    -1,    -1,    -1,    -1,   326,   578,    -1,    -1,   581,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,   341,
    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,
    -1,   363,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
   372,   624,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
    -1,    -1,    -1,   395,    -1,    -1,   398,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,   451,
    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,
    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   503,   504,   505,   506,   265,   508,    -1,    17,    18,
    -1,    20,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
    -1,    -1,    -1,   525,   526,    34,    -1,    -1,    -1,   289,
   290,   291,    -1,    -1,    -1,    -1,   538,    -1,    -1,    -1,
    -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,   550,    -1,
    -1,    -1,   554,   555,    -1,   557,    -1,   559,   560,    -1,
   562,   321,    -1,    -1,    -1,    -1,   326,   569,   570,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,   581,
    -1,   341,    -1,    -1,    -1,    -1,   346,   589,   348,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,
    -1,   361,    -1,   363,   364,    -1,    -1,   367,    -1,    -1,
    -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,   378,    -1,
    -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,   398,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,
   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,
    -1,   451,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,
   460,   461,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   251,   503,   504,   505,   506,    -1,   508,    -1,
    17,    18,    -1,    20,    -1,    -1,    23,    24,    25,    -1,
    -1,    -1,    -1,    -1,    -1,   525,   526,    34,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   289,   290,   291,    -1,   544,    -1,    -1,    -1,    -1,    -1,
   550,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,   559,
   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,   569,
   570,   571,   321,    -1,    -1,    -1,    -1,   326,   578,    -1,
    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   589,
    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,
    -1,    -1,   361,    -1,   363,   364,    -1,    -1,   367,    -1,
    -1,    -1,    -1,   372,   624,    -1,    -1,    -1,    -1,   378,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,   398,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,
   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
    -1,    -1,    19,    20,    21,    -1,    -1,    -1,   427,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,
    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,
   449,   450,   451,    -1,    -1,    -1,    -1,   456,    -1,    -1,
   459,   460,   461,    -1,   463,   464,    -1,    64,    65,    66,
    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   480,    -1,    80,    81,    82,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   503,   504,   505,   506,    -1,   508,
    -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,    25,
    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    34,    -1,
    -1,    -1,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,
    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,
   559,   560,    -1,   562,   321,    -1,    -1,    -1,    -1,   326,
   569,   570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,
    -1,    -1,   581,    -1,   341,    -1,    -1,    -1,    -1,   346,
   589,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   358,    -1,    -1,   361,    -1,   363,   364,    -1,    -1,
   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,
    -1,   378,    -1,   220,    -1,   624,   223,    -1,    -1,    -1,
    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,
    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
    -1,    -1,   449,   450,   451,    -1,    -1,    -1,    -1,   456,
    -1,    -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   339,    -1,    -1,   251,   503,   504,   505,   506,
    -1,   508,    -1,    -1,    -1,    -1,    -1,   354,    -1,   265,
    -1,   358,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    23,
    24,    25,    -1,   289,   290,   291,    -1,   544,    -1,    -1,
    34,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,   396,
   557,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,
    -1,    -1,   569,   570,    -1,   321,    -1,    -1,    -1,    -1,
   326,   578,    -1,    -1,   581,    -1,    -1,   424,    -1,    -1,
    -1,    -1,   589,    20,    21,   341,    -1,    -1,    -1,    -1,
   346,    -1,   348,    -1,    -1,   442,    -1,    -1,    -1,    -1,
    -1,    -1,   358,    -1,    -1,   361,    -1,   363,   364,    -1,
    -1,   367,    -1,    -1,    -1,    -1,   372,   624,    -1,    -1,
    -1,    -1,   378,    -1,    -1,    -1,    -1,    64,    65,    66,
    67,    68,    69,    -1,   390,    -1,    -1,    -1,    -1,   395,
    -1,    -1,   398,    80,    81,    82,    -1,    -1,    -1,    -1,
   406,    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,
   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   427,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,
    -1,    -1,    -1,   449,    -1,   451,    -1,    -1,    -1,    -1,
   456,    -1,    -1,   459,   460,   461,    -1,   463,   464,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   592,    -1,   503,   504,   505,
   506,    -1,   508,    -1,    -1,    -1,    -1,   251,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,   525,
   526,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    34,   220,    -1,    -1,   223,    -1,   544,    -1,
    -1,    -1,    -1,    -1,   550,   289,   290,   291,    -1,    -1,
    -1,   557,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,
    -1,    -1,    -1,   569,   570,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   578,    -1,    -1,   581,    -1,   321,    -1,    -1,
    -1,    -1,   326,   589,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,    -1,
    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,   624,   363,
   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,
    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
    -1,   395,   339,    -1,   398,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   406,    -1,    -1,   409,   410,   354,    -1,    -1,
    -1,   358,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,
    -1,    -1,    -1,    -1,    -1,   449,   450,   451,    -1,   396,
    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,   463,
   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   480,   424,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,   503,
   504,   505,   506,    -1,   508,    -1,    17,    18,    -1,    20,
    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
    -1,   525,   526,    34,    -1,    -1,    -1,   289,   290,   291,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   544,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,
    -1,    -1,    -1,   557,    -1,   559,   560,    -1,   562,   321,
    -1,    -1,    -1,    -1,   326,   569,   570,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   578,    -1,   523,   581,    -1,   341,
    -1,    -1,    -1,    -1,   346,   589,   348,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,
    -1,   363,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
   372,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,
   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
    -1,    -1,    -1,   395,    -1,    -1,   398,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   406,   592,    -1,   409,   410,    -1,
    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,   450,   451,
    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,
    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   251,   503,   504,   505,   506,    -1,   508,    -1,    17,    18,
    -1,    20,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
    -1,    -1,    -1,   525,   526,    34,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,   290,
   291,    -1,   544,    -1,    -1,    -1,    -1,    -1,   550,    -1,
    -1,    -1,    -1,    -1,    -1,   557,    -1,   559,   560,    -1,
   562,    -1,    -1,    -1,    -1,    -1,    -1,   569,   570,    -1,
   321,    -1,    -1,    -1,    -1,   326,   578,    -1,    -1,   581,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,
   341,    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,
   361,    -1,   363,   364,    -1,    -1,   367,    -1,    -1,    -1,
    -1,   372,   624,    -1,    -1,    -1,    -1,   378,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
    -1,    -1,    -1,    -1,   395,    -1,    -1,   398,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,
    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,
   451,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,
   461,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   503,   504,   505,   506,    -1,   508,    -1,    17,
    18,    -1,    20,    -1,    -1,    23,    24,    25,    -1,    -1,
    -1,    -1,    -1,    -1,   525,   526,    34,    -1,    -1,    -1,
   289,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,   550,
    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,   559,   560,
    -1,   562,   321,    -1,    -1,    -1,    -1,   326,   569,   570,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,
   581,    -1,   341,    -1,    -1,    -1,    -1,   346,   589,   348,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,
    -1,    -1,   361,    -1,   363,   364,    -1,    -1,   367,    -1,
    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,   378,
    -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   390,    -1,    17,    18,    -1,   395,    -1,    -1,   398,
    -1,    25,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,
   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,
   449,   450,   451,    -1,    -1,    -1,    -1,   456,    -1,    -1,
   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   251,   503,   504,   505,   506,    -1,   508,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   289,   290,   291,    -1,   544,    -1,    -1,    -1,    -1,
    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,
   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,
   569,   570,    -1,   321,    -1,    -1,    -1,    -1,   326,   578,
    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   589,    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,    -1,
   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   358,    -1,    -1,   361,    -1,   363,   364,    -1,    -1,   367,
    -1,    -1,    -1,    -1,   372,   624,    -1,   251,    -1,    -1,
   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,
   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,
    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,
    -1,   449,   326,   451,    -1,    -1,    -1,    -1,   456,    -1,
    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,    -1,
    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,
   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,
    -1,    -1,    -1,    -1,    -1,   503,   504,   505,   506,    -1,
   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   398,    -1,    -1,   525,   526,    -1,
    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,    -1,
    -1,    -1,   416,    -1,    -1,    -1,   544,    -1,    -1,    -1,
    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,   557,
    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,    -1,
    -1,   569,   570,    -1,    -1,   449,    -1,    -1,    -1,    -1,
   578,    -1,   456,   581,    -1,   459,   460,   461,    -1,   463,
   464,   589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,   503,
    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
    -1,   525,   526,    -1,    -1,    -1,    37,    -1,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    53,    -1,    -1,    -1,   550,    -1,    -1,    -1,
    -1,    62,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,
    -1,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    89,    -1,
    91,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,   110,
    -1,    -1,   113,    -1,   115,   116,   117,    -1,   119,   120,
    -1,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,   130,
   624,   132,   133,    -1,    -1,   136,   137,   138,    -1,    -1,
   141,   142,   143,    -1,   145,   146,    -1,    -1,    -1,   150,
   151,    -1,   153,    -1,    -1,    -1,   157,    -1,   159,   160,
    -1,    -1,   163,    -1,    -1,    -1,   167,    -1,    -1,   170,
    -1,   172,    -1,   174,    -1,   176,    -1,   178,   179,    -1,
   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   214,    -1,    -1,   217,   218,    -1,    -1,
   221,   222,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   234,   235,   236,    -1,   238,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,
    -1,   252,    -1,    -1,    -1,   256,   257,    -1,    -1,    -1,
   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,
    -1,    -1,   283,   284,    -1,    -1,    -1,    -1,   289,    -1,
    -1,   292,    -1,    -1,    -1,   296,   297,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   307,    -1,    -1,    20,
    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   332,    -1,    -1,    -1,    -1,    -1,   338,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   361,    -1,    -1,    -1,    -1,    -1,    -1,   368,    -1,   370,
   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   379,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,
    -1,    -1,   433,    20,    -1,   436,    -1,    24,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,   460,
   461,    -1,    -1,    -1,   465,    -1,    -1,    -1,    80,    81,
    82,    -1,    -1,    -1,    -1,    -1,   477,    -1,    -1,    -1,
    -1,    -1,   483,   484,   485,   486,    -1,    -1,   489,    -1,
    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,   500,
   501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   512,    -1,   514,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   525,    -1,    -1,   528,    -1,    -1,
   531,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
    -1,    -1,    -1,   564,    -1,    -1,   567,    -1,    -1,    -1,
    -1,    -1,   573,    -1,    -1,   576,    -1,    -1,   289,   290,
   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   591,    -1,    -1,    -1,    -1,    -1,    -1,   598,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,
   321,   223,    -1,    -1,    -1,   326,    -1,    -1,    -1,    -1,
   621,   622,   623,   624,   625,   626,   627,    -1,    -1,   630,
   341,   632,    -1,   634,    -1,   346,    -1,   348,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,
   361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,
    -1,   372,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
    -1,    20,    -1,    -1,    -1,    -1,    -1,   398,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
    -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,
    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
    -1,    -1,   354,    -1,    -1,   456,   358,   359,   459,   460,
   461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
   367,    -1,    -1,    -1,   396,   372,    -1,    -1,   251,    -1,
    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
    -1,    -1,    -1,   390,    -1,    20,    -1,    -1,    -1,    -1,
    -1,    -1,   424,    -1,   525,   526,    -1,    -1,    -1,   406,
    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,
    -1,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
    -1,   523,   251,   624,    -1,    -1,   503,    -1,   505,   506,
    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    20,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
   289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
   592,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
    -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
   463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,
    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
    -1,    -1,    -1,   372,    -1,    -1,   251,   624,    -1,    -1,
   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
    -1,   390,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
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
    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
    -1,    -1,    23,    24,    25,    -1,    -1,    -1,   525,   526,
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
   505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
    -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,
    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
    -1,    -1,    -1,   454,    -1,   456,    -1,    -1,   459,   460,
   461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
   367,    -1,    -1,    -1,    -1,   372,    24,    -1,    26,   624,
    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,
    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
    -1,   562,    -1,    -1,    -1,   442,    94,    95,    -1,    97,
    98,    -1,   449,    -1,   102,    -1,    -1,    -1,    -1,   456,
   581,    -1,   459,   460,   461,    -1,   463,   464,   589,    -1,
    -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,   137,
   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    24,    -1,    -1,   624,    -1,    -1,   503,    -1,   505,   506,
    -1,   508,     7,     8,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    -1,   525,   526,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,   207,
    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,    64,
    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   581,    80,    81,    82,    -1,    -1,
    -1,    -1,   589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    24,    -1,    26,   624,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   321,    -1,    -1,    -1,    -1,   326,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   216,   341,    -1,    -1,    -1,    -1,   346,    -1,
   348,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,
    -1,    -1,    -1,    -1,   372,   220,    -1,   251,   223,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    24,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,   406,    -1,
    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,
    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,    -1,
    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,    -1,
    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,    -1,
   364,    -1,    -1,   367,   339,    -1,    -1,    -1,   372,    -1,
    -1,   251,    -1,    -1,    -1,   503,    -1,   505,   506,   354,
   508,    -1,    -1,   358,    -1,    -1,   390,    -1,    -1,    -1,
    -1,    -1,    24,    -1,    26,    -1,    -1,   525,   526,    -1,
    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,
   290,   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   396,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,   443,
    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,   424,
    -1,    -1,   456,   581,    -1,   459,   460,   461,    -1,   463,
   464,   341,    -1,    -1,    -1,    -1,   346,   442,   348,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,
    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,
    -1,    -1,   372,    -1,    -1,   251,   624,    -1,    -1,   503,
    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,
   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,
   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,   523,    -1,
    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,
    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,
   326,    -1,    -1,    24,    -1,    -1,   456,    -1,    -1,   459,
   460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,
   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,
    -1,   367,    -1,    -1,    -1,    -1,   372,   592,    -1,   251,
   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,
    -1,    -1,    -1,    -1,   390,    -1,    -1,   517,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,
   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,
   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,
    -1,    -1,    -1,   449,   326,    -1,    -1,    24,    -1,    -1,
   456,   581,    -1,   459,   460,   461,    -1,   463,   464,   341,
    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,
    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
   372,    -1,    -1,    -1,   624,    -1,    -1,   503,    -1,   505,
   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,
   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,   554,    -1,
   251,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,
   442,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,
    -1,    24,    -1,    26,   456,   581,    -1,   459,   460,   461,
    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,   289,   290,
   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,
   321,   503,    -1,   505,   506,   326,   508,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   341,    -1,    -1,   525,   526,   346,    -1,   348,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,
   361,    -1,    -1,   364,    -1,    -1,   367,    -1,   550,    -1,
    -1,   372,    -1,    -1,   251,    -1,    -1,   559,   560,    -1,
   562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,   581,
    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
    -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,
    -1,   442,   624,    -1,   321,    -1,    -1,    -1,   449,   326,
    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,
   461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,    -1,
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
   289,   290,   291,   416,    -1,    -1,    -1,   544,    -1,    -1,
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
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   525,   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
    -1,    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,
    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
    -1,    -1,    24,    -1,    -1,   456,   581,    -1,   459,   460,
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
    -1,    -1,   449,   326,    -1,    -1,    24,    25,    -1,   456,
   581,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
    -1,    -1,    -1,   624,    -1,    -1,   503,    -1,   505,   506,
    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,   251,
    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,
    24,    -1,    -1,   456,   581,    -1,   459,   460,   461,    -1,
   463,   464,    -1,    -1,    -1,    -1,    -1,   289,   290,   291,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   482,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,   321,
   503,    -1,   505,   506,   326,   508,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
    -1,    -1,   525,   526,   346,    -1,   348,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,
    -1,    -1,   364,    -1,    -1,   367,    -1,   550,    -1,    -1,
   372,    -1,    -1,   251,    -1,    -1,   559,   560,    -1,   562,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
    -1,    -1,    -1,    -1,    24,    -1,   398,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   442,   624,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,
    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,
    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,
   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,
    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,    -1,    -1,
    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,
    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    24,    -1,
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
    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,   525,
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
   460,   461,    -1,   463,   464,   341,    -1,    -1,   468,    -1,
   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   480,    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,
    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,
   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,
    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,
    -1,   521,   398,    -1,    -1,   525,   526,    -1,    -1,    -1,
   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,
   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
   560,    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,
    -1,    -1,    -1,   449,   326,    -1,    -1,    -1,    25,    -1,
   456,   581,    -1,   459,   460,   461,    -1,   463,   464,   341,
    -1,    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,
    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,
   372,    -1,    -1,   251,   624,    -1,    -1,   503,    -1,   505,
   506,    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,
   526,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,
    -1,   289,   290,   291,   416,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,
   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,
    -1,    -1,    -1,    26,   456,   581,    -1,   459,   460,   461,
    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,
   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,
    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,   624,    -1,
    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,
    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,
    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,
    -1,    -1,    -1,    -1,   251,    -1,    -1,   559,   560,    -1,
   562,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,
    -1,   449,    -1,    -1,    -1,    -1,    -1,    26,   456,   581,
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
    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,   406,
    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   442,   624,    -1,   321,    -1,
    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,
    -1,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,   352,
    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
    -1,    -1,   251,    -1,    -1,    -1,   503,    -1,   505,   506,
    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
   289,   290,   291,   416,    -1,    -1,    -1,    -1,    35,    -1,
    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
    -1,    -1,   321,    -1,    -1,    -1,   449,   326,    -1,    -1,
    -1,    -1,    -1,   456,   581,    -1,   459,   460,   461,    76,
   463,   464,   341,    -1,    -1,    -1,    -1,   346,    -1,   348,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   358,
    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,   367,    -1,
    -1,    -1,    -1,   372,    -1,    -1,    -1,   624,    -1,    -1,
   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,   126,
    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
   409,   410,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   162,    -1,   550,   427,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,
   449,    -1,    -1,    -1,    -1,    -1,    -1,   456,   581,    -1,
   459,   460,   461,    -1,   463,   464,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   480,     6,     7,     8,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
    -1,   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,
    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   260,    -1,    -1,   525,   526,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
    -1,   550,   289,   290,   291,    -1,    80,    81,    82,    -1,
   559,   560,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,    -1,   326,
    -1,    -1,    -1,    -1,    -1,    -1,   333,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,   346,
    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   358,    -1,    -1,   361,   624,    -1,   364,    -1,    -1,
   367,    -1,    -1,    -1,    -1,   372,    -1,   374,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   427,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,   223,
    -1,    -1,    -1,    -1,   441,   442,    -1,    -1,    -1,    -1,
    -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,   456,
    -1,    -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   480,     6,     7,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    -1,    -1,    -1,    -1,    -1,    -1,   503,   504,   505,   506,
    -1,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,    -1,
    -1,    -1,    -1,   550,    -1,   339,    -1,    -1,    80,    81,
    82,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,
   354,    -1,    -1,    -1,   358,   359,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   581,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   424,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    80,
    81,    82,     6,     7,     8,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,
    -1,   223,     6,     7,     8,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,   523,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,   220,
    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,   592,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   354,    -1,    -1,    -1,   358,   359,    64,    65,
    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    80,    81,    82,    12,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   396,    -1,   220,    -1,    -1,   223,
    -1,    -1,    -1,    -1,     8,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,    64,
    65,    66,    67,    68,    69,    -1,   220,    -1,   339,   223,
   442,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,    -1,
    -1,    -1,    -1,   354,    -1,    -1,    -1,   358,   359,    -1,
    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   220,   339,    -1,   223,    -1,    -1,
    -1,   523,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,
   354,    -1,    -1,    -1,   358,   359,    -1,    -1,    -1,    -1,
    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   339,    -1,    50,    51,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
   354,    -1,   396,    -1,   358,   359,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,   223,    -1,
   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   396,    -1,    -1,    -1,   220,    -1,   442,   223,
    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,
   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,
    -1,    -1,   358,    -1,    -1,    -1,    -1,    -1,   442,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
    10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   396,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   523,
    -1,    -1,    -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,   354,
    -1,    -1,    -1,   358,    64,    65,    66,    67,    68,    69,
    -1,    -1,    -1,    -1,    -1,   339,   442,    -1,   231,   523,
    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   354,    -1,    -1,    -1,   358,    -1,    -1,    -1,   251,    -1,
    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,   592,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,
    -1,    -1,   396,    -1,   287,    -1,   289,   290,   291,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,   592,    -1,
   303,    -1,    -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,
   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,   442,    -1,
    -1,    -1,    -1,    -1,   337,    -1,    -1,    -1,   341,    -1,
    -1,    -1,    -1,   346,   347,   348,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,   361,    -1,
    -1,   364,   365,    -1,   367,    -1,    -1,    -1,    -1,   372,
   220,    -1,   375,   223,    -1,    -1,   592,    -1,   523,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,   391,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,   523,
    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,   431,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
    -1,    -1,    -1,    -1,    -1,    -1,   449,   592,    -1,    -1,
    -1,   454,    -1,   456,   251,    -1,   459,   460,   461,    -1,
   463,   464,    -1,    -1,    -1,    -1,   469,    -1,    -1,    -1,
    -1,    -1,    -1,   476,    -1,    -1,   479,   480,   592,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,
    -1,    -1,   289,   290,   291,    -1,   499,    -1,    -1,   502,
   503,   504,   505,   506,   354,   508,    -1,    -1,   358,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   523,    -1,   525,   526,   321,    -1,    -1,    -1,    -1,   326,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,
    -1,    -1,    -1,    -1,   341,   342,   396,   550,    -1,   346,
    -1,   348,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
   367,    -1,    -1,    -1,   424,   372,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   442,   390,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
    -1,    -1,   409,   410,    -1,    -1,    -1,    -1,    -1,   416,
    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
    -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,   456,
   251,    -1,   459,   460,   461,    -1,   463,   464,    -1,    -1,
    -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,   290,
   291,    -1,    -1,    -1,    -1,    -1,   503,    -1,   505,   506,
    -1,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
   321,    -1,   529,    -1,    -1,   326,    -1,    -1,    -1,    -1,
    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   341,    -1,    -1,   550,    -1,   346,    -1,   348,    -1,    -1,
    -1,    -1,   559,   560,    -1,   562,    -1,   358,    -1,    -1,
   361,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,
    -1,   372,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,   410,
    -1,    -1,   289,   290,   291,   416,    -1,   624,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,   636,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,   449,   326,
    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   460,
   461,    -1,   463,   464,   341,    -1,    -1,    -1,    -1,   346,
    -1,   348,    -1,    -1,    -1,   476,    -1,    -1,    -1,   480,
    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,    -1,
    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,
    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,
    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,
    -1,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,   352,
    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
    -1,    -1,   251,   624,    -1,    -1,   503,    -1,   505,   506,
    -1,   508,    -1,    -1,    -1,   636,    -1,   390,    -1,    -1,
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
   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,   636,
    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   525,   526,    -1,    -1,    -1,   406,    -1,    -1,
   409,   410,    -1,    -1,   289,   290,   291,   416,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   427,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,    -1,    -1,
   449,   326,    -1,    -1,    -1,    -1,    -1,   456,   581,    -1,
   459,   460,   461,    -1,   463,   464,   341,    -1,    -1,    -1,
    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   480,    -1,   358,   359,    -1,   361,    -1,    -1,   364,
    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,
   251,   624,    -1,    -1,   503,    -1,   505,   506,    -1,   508,
    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,
    -1,   406,    -1,    -1,   409,   410,    -1,    -1,   289,   290,
   291,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,    -1,   558,
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
    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
    -1,   358,    -1,    -1,   361,    -1,    -1,   364,    -1,    -1,
   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   251,   624,
    -1,    -1,   503,    -1,   505,   506,    -1,   508,    -1,    -1,
    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,   406,
    -1,    -1,   409,   410,    -1,    -1,   289,   290,   291,   416,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
   427,    -1,    -1,   430,    -1,    -1,    -1,    -1,   559,   560,
    -1,   562,    -1,    -1,    -1,   442,    -1,    -1,   321,    -1,
    -1,    -1,   449,   326,    -1,    -1,    -1,    -1,    -1,   456,
   581,    -1,   459,   460,   461,    -1,   463,   464,   341,    -1,
    -1,    -1,    -1,   346,    -1,   348,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   480,    -1,   358,    -1,    -1,   361,    -1,
    -1,   364,    -1,    -1,   367,    -1,    -1,    -1,    -1,   372,
    -1,    -1,    -1,   624,    -1,    -1,   503,    -1,   505,   506,
    -1,   508,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
    -1,    -1,    -1,   406,    -1,    -1,   409,   410,    -1,    -1,
    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   550,   427,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,   442,
    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,
    -1,    -1,    -1,   456,    -1,    -1,   459,   460,   461,    -1,
   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,
   503,    -1,   505,   506,    -1,   508,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   525,   526,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   624
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/lib/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/lib/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
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
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
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

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 854 "fgl.yacc"
{ print_screen_mode(0);;
    break;}
case 2:
#line 857 "fgl.yacc"
{ print_screen_mode(1);;
    break;}
case 3:
#line 861 "fgl.yacc"
{
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	;
    break;}
case 4:
#line 867 "fgl.yacc"
{
	print_stop_external();
	;
    break;}
case 5:
#line 872 "fgl.yacc"
{
		if (scan_variable(yyvsp[0].str)!=2) {
		char buff[256];
			sprintf(buff,"START EXTERNAL ..ON must be an integer");
			yyerror(buff);
			YYERROR;
		}
	;
    break;}
case 8:
#line 884 "fgl.yacc"
{
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	;
    break;}
case 9:
#line 889 "fgl.yacc"
{
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",aclfgl_%s);\n",yyvsp[0].str,yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	;
    break;}
case 10:
#line 907 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[-1].str);;
    break;}
case 11:
#line 908 "fgl.yacc"
{ sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 12:
#line 909 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);;
    break;}
case 13:
#line 910 "fgl.yacc"
{sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 14:
#line 911 "fgl.yacc"
{
  int a;
  a=scan_variable(yyvsp[0].str)&15;
  if (a!=1&&a!=2) {
    
    yyerror("Only INTEGER/SMALLINT variables may be used as subscripts");
    YYERROR;
    /* error processing */;
  }
  sprintf(yyval.str,"%s",yyvsp[0].str);
;
    break;}
case 15:
#line 925 "fgl.yacc"
{strcpy(yyval.str,"+");;
    break;}
case 16:
#line 926 "fgl.yacc"
{strcpy(yyval.str,"-");;
    break;}
case 17:
#line 927 "fgl.yacc"
{strcpy(yyval.str,"*");;
    break;}
case 18:
#line 928 "fgl.yacc"
{strcpy(yyval.str,"/");;
    break;}
case 19:
#line 929 "fgl.yacc"
{strcpy(yyval.str,"%");;
    break;}
case 20:
#line 934 "fgl.yacc"
{strcpy(yyval.str,"+");;
    break;}
case 21:
#line 935 "fgl.yacc"
{strcpy(yyval.str,"-");;
    break;}
case 22:
#line 946 "fgl.yacc"
{
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);;
    break;}
case 23:
#line 949 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 24:
#line 952 "fgl.yacc"
{start_state("attribute",1);;
    break;}
case 25:
#line 952 "fgl.yacc"
{strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
;
    break;}
case 27:
#line 959 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 28:
#line 960 "fgl.yacc"
{
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
;
    break;}
case 29:
#line 966 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLACK"));;
    break;}
case 30:
#line 967 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLUE"));;
    break;}
case 31:
#line 968 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("CYAN"));;
    break;}
case 32:
#line 969 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("GREEN"));;
    break;}
case 33:
#line 970 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("MAGENTA"));;
    break;}
case 34:
#line 971 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("RED"));;
    break;}
case 35:
#line 972 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("WHITE"));;
    break;}
case 36:
#line 973 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("YELLOW"));;
    break;}
case 37:
#line 974 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("REVERSE"));;
    break;}
case 38:
#line 975 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BLINK"));;
    break;}
case 39:
#line 976 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("UNDERLINE"));;
    break;}
case 40:
#line 977 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("BOLD"));;
    break;}
case 41:
#line 978 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("NORMAL"));;
    break;}
case 42:
#line 979 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("INVISIBLE"));;
    break;}
case 43:
#line 980 "fgl.yacc"
{sprintf(yyval.str,"%d",attr_code("DIM"));;
    break;}
case 44:
#line 981 "fgl.yacc"
{inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");;
    break;}
case 47:
#line 988 "fgl.yacc"
{
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;;
    break;}
case 48:
#line 992 "fgl.yacc"
{start_state("attribute",0);strcpy(yyval.str,"");
;
    break;}
case 49:
#line 996 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 50:
#line 997 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 51:
#line 1001 "fgl.yacc"
{ 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
;
    break;}
case 52:
#line 1007 "fgl.yacc"
{ form_attrib.border      =1;;
    break;}
case 53:
#line 1009 "fgl.yacc"
{int a;
char *buff;
a=form_attrib.attrib&255;
if (strlen(yyvsp[0].str) > 2) {
buff=yyvsp[0].str;
form_attrib.attrib=form_attrib.attrib+buff[1];
} else  {
form_attrib.attrib=form_attrib.attrib+' ';
      }
;
    break;}
case 54:
#line 1020 "fgl.yacc"
{ form_attrib.comment_line=atoi(yyvsp[0].str); ;
    break;}
case 55:
#line 1022 "fgl.yacc"
{ form_attrib.form_line   =atoi(yyvsp[0].str); ;
    break;}
case 56:
#line 1024 "fgl.yacc"
{ form_attrib.error_line  =atoi(yyvsp[0].str); ;
    break;}
case 57:
#line 1026 "fgl.yacc"
{ form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
;
    break;}
case 58:
#line 1030 "fgl.yacc"
{ form_attrib.message_line=atoi(yyvsp[0].str); ;
    break;}
case 59:
#line 1032 "fgl.yacc"
{ form_attrib.prompt_line =atoi(yyvsp[0].str); ;
    break;}
case 60:
#line 1093 "fgl.yacc"
{strcpy(yyval.str,"CALL");;
    break;}
case 61:
#line 1097 "fgl.yacc"
{ debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	;
    break;}
case 62:
#line 1101 "fgl.yacc"
{
	print_getfldbuf(yyvsp[-2].str);
	;
    break;}
case 63:
#line 1104 "fgl.yacc"
{
	print_returning();
;
    break;}
case 64:
#line 1108 "fgl.yacc"
{
	print_form_is_compiled(yyvsp[-1].str);
	;
    break;}
case 65:
#line 1112 "fgl.yacc"
{
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   ;
    break;}
case 67:
#line 1116 "fgl.yacc"
{ 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     ;
    break;}
case 68:
#line 1119 "fgl.yacc"
{
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   ;
    break;}
case 69:
#line 1125 "fgl.yacc"
{
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
	debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   ;
    break;}
case 70:
#line 1134 "fgl.yacc"
{
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   ;
    break;}
case 71:
#line 1138 "fgl.yacc"
{
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   ;
    break;}
case 72:
#line 1143 "fgl.yacc"
{
	debug("Got args");
   ;
    break;}
case 73:
#line 1147 "fgl.yacc"
{
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   ;
    break;}
case 74:
#line 1155 "fgl.yacc"
{
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   ;
    break;}
case 75:
#line 1159 "fgl.yacc"
{
	A4GLSQL_set_status(0,0);
	new_counter();
	;
    break;}
case 76:
#line 1163 "fgl.yacc"
{
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
;
    break;}
case 77:
#line 1166 "fgl.yacc"
{
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
;
    break;}
case 78:
#line 1172 "fgl.yacc"
{
	sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	A4GLSQL_set_status(0,0);
	new_counter();
	;
    break;}
case 79:
#line 1177 "fgl.yacc"
{
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
;
    break;}
case 80:
#line 1180 "fgl.yacc"
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
;
    break;}
case 81:
#line 1196 "fgl.yacc"
{
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   ;
    break;}
case 82:
#line 1203 "fgl.yacc"
{
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   ;
    break;}
case 83:
#line 1207 "fgl.yacc"
{
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   ;
    break;}
case 84:
#line 1211 "fgl.yacc"
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
  ;
    break;}
case 85:
#line 1233 "fgl.yacc"
{start_bind('i',0);strcpy(yyval.str,"0");;
    break;}
case 86:
#line 1233 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);
;
    break;}
case 87:
#line 1237 "fgl.yacc"
{start_bind('i',0);strcpy(yyval.str,"0");;
    break;}
case 88:
#line 1238 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 89:
#line 1239 "fgl.yacc"
{strcpy(yyval.str,"WITHOUT WAITING"); ;
    break;}
case 90:
#line 1244 "fgl.yacc"
{
			yyval.ptr=new_expr("");
		;
    break;}
case 91:
#line 1247 "fgl.yacc"
{
			yyval.ptr=yyvsp[0].ptr;
		;
    break;}
case 92:
#line 1253 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
;
    break;}
case 93:
#line 1256 "fgl.yacc"
{
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
;
    break;}
case 96:
#line 1268 "fgl.yacc"
{
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
;
    break;}
case 97:
#line 1274 "fgl.yacc"
{
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
;
    break;}
case 98:
#line 1277 "fgl.yacc"
{ sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); ;
    break;}
case 99:
#line 1292 "fgl.yacc"
{
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
;
    break;}
case 100:
#line 1302 "fgl.yacc"
{
print_after_when(0);
pop_blockcommand("CASE");
;
    break;}
case 101:
#line 1308 "fgl.yacc"
{  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
;
    break;}
case 102:
#line 1317 "fgl.yacc"
{
print_after_when(0);
pop_blockcommand("CASE");
;
    break;}
case 107:
#line 1330 "fgl.yacc"
{setinc(-1);incprint();;
    break;}
case 109:
#line 1333 "fgl.yacc"
{
incprint();
;
    break;}
case 110:
#line 1335 "fgl.yacc"
{incprint();
print_after_when(0);
;
    break;}
case 112:
#line 1341 "fgl.yacc"
{incprint();;
    break;}
case 113:
#line 1343 "fgl.yacc"
{incprint();
print_after_when(0);
;
    break;}
case 114:
#line 1348 "fgl.yacc"
{
print_when(0);

incprint();
;
    break;}
case 115:
#line 1353 "fgl.yacc"
{incprint();
print_after_when(1);
setinc(-1);;
    break;}
case 116:
#line 1359 "fgl.yacc"
{
incprint();
print_when(1);
;
    break;}
case 117:
#line 1363 "fgl.yacc"
{incprint();
print_after_when(1);
setinc(-1);;
    break;}
case 118:
#line 1378 "fgl.yacc"
{
  print_close('F',yyvsp[0].str);
 ;
    break;}
case 119:
#line 1381 "fgl.yacc"
{
  print_close('W',yyvsp[0].str);
;
    break;}
case 120:
#line 1384 "fgl.yacc"
{
  print_close('W',yyvsp[0].str);
;
    break;}
case 121:
#line 1387 "fgl.yacc"
{
  print_close('D',0);
;
    break;}
case 122:
#line 1390 "fgl.yacc"
{
  print_close('S',yyvsp[0].str);
;
    break;}
case 123:
#line 1393 "fgl.yacc"
{
  print_close('C',yyvsp[0].str);
;
    break;}
case 129:
#line 1415 "fgl.yacc"
{
			lex_printc("%s",yyvsp[0].str);
;
    break;}
case 132:
#line 1424 "fgl.yacc"
{
			lex_printc("%s\n",yyvsp[0].str);
;
    break;}
case 133:
#line 1434 "fgl.yacc"
{
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
;
    break;}
case 134:
#line 1448 "fgl.yacc"
{
push_blockcommand("CONSTRUCT");
;
    break;}
case 135:
#line 1452 "fgl.yacc"
{
	print_construct_1();
;
    break;}
case 136:
#line 1455 "fgl.yacc"
{
	print_construct_2(yyvsp[-2].str);
;
    break;}
case 137:
#line 1463 "fgl.yacc"
{
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	sprintf(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
;
    break;}
case 138:
#line 1469 "fgl.yacc"
{
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	sprintf(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
;
    break;}
case 143:
#line 1484 "fgl.yacc"
{
                push_construct("",yyval.str);
             ;
    break;}
case 144:
#line 1488 "fgl.yacc"
{
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             ;
    break;}
case 145:
#line 1493 "fgl.yacc"
{
                push_construct(yyvsp[-2].str,"*");
             ;
    break;}
case 148:
#line 1503 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
	;
    break;}
case 149:
#line 1506 "fgl.yacc"
{
		print_befaft_field_2();

	;
    break;}
case 150:
#line 1510 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
	;
    break;}
case 151:
#line 1512 "fgl.yacc"
{
		print_befaft_field_2();
	;
    break;}
case 152:
#line 1515 "fgl.yacc"
{
		print_onkey_1(yyvsp[0].str);
	;
    break;}
case 153:
#line 1517 "fgl.yacc"
{
		print_onkey_2();
	;
    break;}
case 154:
#line 1520 "fgl.yacc"
{
		print_befaft_field_1("AFTER_INP");
	;
    break;}
case 155:
#line 1522 "fgl.yacc"
{
		print_befaft_field_2();
	;
    break;}
case 156:
#line 1525 "fgl.yacc"
{
		print_befaft_field_1("BEFORE_INP");
		;
    break;}
case 157:
#line 1528 "fgl.yacc"
{
		print_befaft_field_2();
	;
    break;}
case 158:
#line 1538 "fgl.yacc"
{sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);;
    break;}
case 159:
#line 1539 "fgl.yacc"
{
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	;
    break;}
case 160:
#line 1547 "fgl.yacc"
{sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);;
    break;}
case 161:
#line 1548 "fgl.yacc"
{
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	;
    break;}
case 162:
#line 1565 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_YEAR);");
	;
    break;}
case 163:
#line 1568 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_MONTH);"); 
	;
    break;}
case 164:
#line 1571 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_DAY);"); 
	;
    break;}
case 165:
#line 1574 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_HOUR);");
	;
    break;}
case 166:
#line 1577 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_MINUTE);");
	;
    break;}
case 167:
#line 1580 "fgl.yacc"
{
		sprintf(yyval.str,"pushop(OP_SECOND);");
	;
    break;}
case 168:
#line 1593 "fgl.yacc"
{
				print_defer(0);
			;
    break;}
case 169:
#line 1597 "fgl.yacc"
{
				print_defer(1);
			;
    break;}
case 170:
#line 1612 "fgl.yacc"
{strcpy(yyval.str,"");if (modlevel>=0) print_variables();;
    break;}
case 171:
#line 1613 "fgl.yacc"
{strcpy(yyval.str,"");if (modlevel>=0) print_variables();lastlineno=yylineno;;
    break;}
case 174:
#line 1621 "fgl.yacc"
{dtypelist[0]=0;lex_printcomment("/* define */\n");;
    break;}
case 175:
#line 1621 "fgl.yacc"
{lex_printcomment("/*end def */\n");;
    break;}
case 180:
#line 1629 "fgl.yacc"
{in_define=1;;
    break;}
case 181:
#line 1629 "fgl.yacc"
{in_define=0;strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 182:
#line 1633 "fgl.yacc"
{ add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); ;
    break;}
case 183:
#line 1634 "fgl.yacc"
{ add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 ;
    break;}
case 184:
#line 1637 "fgl.yacc"
{ 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 ;
    break;}
case 186:
#line 1642 "fgl.yacc"
{ ;
    break;}
case 187:
#line 1642 "fgl.yacc"
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
;
    break;}
case 191:
#line 1659 "fgl.yacc"
{
		sprintf(yyval.str,"-%p",yyvsp[0].str);;
    break;}
case 192:
#line 1663 "fgl.yacc"
{
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
;
    break;}
case 197:
#line 1677 "fgl.yacc"
{
debug("defines array %s",yyvsp[-1].str);
push_type(0,0,yyvsp[-1].str);
;
    break;}
case 199:
#line 1686 "fgl.yacc"
{
push_associate(yyvsp[-5].str,yyvsp[-1].str);
push_type(0,0,yyvsp[-1].str);
;
    break;}
case 200:
#line 1690 "fgl.yacc"
{
    /* void pop_associate (char *a); */
	pop_associate(0);

;
    break;}
case 206:
#line 1706 "fgl.yacc"
{sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");;
    break;}
case 207:
#line 1708 "fgl.yacc"
{sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");;
    break;}
case 208:
#line 1709 "fgl.yacc"
{debug("Single");;
    break;}
case 210:
#line 1716 "fgl.yacc"
{push_record();in_record++;;
    break;}
case 211:
#line 1716 "fgl.yacc"
{pop_record();in_record--;;
    break;}
case 212:
#line 1717 "fgl.yacc"
{in_record++;push_record();debug("Like\n");;
    break;}
case 213:
#line 1718 "fgl.yacc"
{debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;;
    break;}
case 214:
#line 1721 "fgl.yacc"
{
		push_record();debug("Like\n");;
    break;}
case 215:
#line 1723 "fgl.yacc"
{
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
;
    break;}
case 217:
#line 1733 "fgl.yacc"
{
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 220:
#line 1744 "fgl.yacc"
{start_state("dtype",1);;
    break;}
case 221:
#line 1744 "fgl.yacc"
{start_state("dtype",0);;
    break;}
case 224:
#line 1750 "fgl.yacc"
{push_type("char","1",0);;
    break;}
case 225:
#line 1751 "fgl.yacc"
{
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
;
    break;}
case 226:
#line 1758 "fgl.yacc"
{push_type("char",yyvsp[-1].str,0);;
    break;}
case 227:
#line 1759 "fgl.yacc"
{push_type("char",yyvsp[-3].str,0);;
    break;}
case 228:
#line 1760 "fgl.yacc"
{push_type("long",0,0);;
    break;}
case 229:
#line 1761 "fgl.yacc"
{
debug("Using specified type...");
push_dim(yyvsp[0].str);;
    break;}
case 230:
#line 1764 "fgl.yacc"
{push_type("int",0,0);;
    break;}
case 231:
#line 1765 "fgl.yacc"
{push_type("form",0,0);;
    break;}
case 232:
#line 1766 "fgl.yacc"
{push_type("form",0,0);;
    break;}
case 233:
#line 1767 "fgl.yacc"
{ char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				;
    break;}
case 234:
#line 1771 "fgl.yacc"
{
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
;
    break;}
case 235:
#line 1776 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
;
    break;}
case 236:
#line 1781 "fgl.yacc"
{
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);;
    break;}
case 237:
#line 1785 "fgl.yacc"
{
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);;
    break;}
case 238:
#line 1788 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);;
    break;}
case 239:
#line 1792 "fgl.yacc"
{push_type("double",0,0);;
    break;}
case 240:
#line 1793 "fgl.yacc"
{push_type("float",0,0);;
    break;}
case 241:
#line 1794 "fgl.yacc"
{push_type("fgldate",0,0);;
    break;}
case 242:
#line 1795 "fgl.yacc"
{push_type("fglbyte",0,0);;
    break;}
case 243:
#line 1796 "fgl.yacc"
{push_type("fglbyte",0,0);;
    break;}
case 244:
#line 1797 "fgl.yacc"
{push_type("fgltext",0,0);;
    break;}
case 245:
#line 1798 "fgl.yacc"
{push_type("fgltext",0,0);;
    break;}
case 246:
#line 1799 "fgl.yacc"
{
push_type("struct_dtime ",yyvsp[0].str,0);
;
    break;}
case 247:
#line 1802 "fgl.yacc"
{push_type("struct_ival ",yyvsp[0].str,0);;
    break;}
case 248:
#line 1803 "fgl.yacc"
{push_like(yyvsp[0].str);fflush(stdout);lex_printcomment("/*added(XXXXX)\n */");;
    break;}
case 249:
#line 1804 "fgl.yacc"
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
		;
    break;}
case 250:
#line 1836 "fgl.yacc"
{
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");;
    break;}
case 251:
#line 1840 "fgl.yacc"
{debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 252:
#line 1842 "fgl.yacc"
{debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 253:
#line 1844 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 254:
#line 1846 "fgl.yacc"
{
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); ;
    break;}
case 255:
#line 1851 "fgl.yacc"
{
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
;
    break;}
case 256:
#line 1855 "fgl.yacc"
{start_state("dtime_val",1);;
    break;}
case 257:
#line 1855 "fgl.yacc"
{start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 258:
#line 1858 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 259:
#line 1859 "fgl.yacc"
{strcpy(yyval.str,"2");;
    break;}
case 260:
#line 1860 "fgl.yacc"
{strcpy(yyval.str,"3");;
    break;}
case 261:
#line 1861 "fgl.yacc"
{strcpy(yyval.str,"4");;
    break;}
case 262:
#line 1862 "fgl.yacc"
{strcpy(yyval.str,"5");;
    break;}
case 263:
#line 1863 "fgl.yacc"
{strcpy(yyval.str,"6");;
    break;}
case 264:
#line 1865 "fgl.yacc"
{
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); ;
    break;}
case 265:
#line 1870 "fgl.yacc"
{start_state("dtime_val",1);;
    break;}
case 266:
#line 1870 "fgl.yacc"
{ debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 267:
#line 1873 "fgl.yacc"
{
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");;
    break;}
case 268:
#line 1875 "fgl.yacc"
{
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
;
    break;}
case 269:
#line 1881 "fgl.yacc"
{
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");;
    break;}
case 270:
#line 1883 "fgl.yacc"
{
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
;
    break;}
case 271:
#line 1889 "fgl.yacc"
{
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
;
    break;}
case 272:
#line 1897 "fgl.yacc"
{start_state("interval_val",1);;
    break;}
case 273:
#line 1897 "fgl.yacc"
{start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));;
    break;}
case 274:
#line 1900 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 275:
#line 1901 "fgl.yacc"
{strcpy(yyval.str,"2");;
    break;}
case 276:
#line 1902 "fgl.yacc"
{strcpy(yyval.str,"3");;
    break;}
case 277:
#line 1903 "fgl.yacc"
{strcpy(yyval.str,"4");;
    break;}
case 278:
#line 1904 "fgl.yacc"
{strcpy(yyval.str,"5");;
    break;}
case 279:
#line 1905 "fgl.yacc"
{strcpy(yyval.str,"6");;
    break;}
case 280:
#line 1907 "fgl.yacc"
{
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); ;
    break;}
case 284:
#line 1928 "fgl.yacc"
{
              	dim_set_name(yyvsp[0].str);
              ;
    break;}
case 288:
#line 1937 "fgl.yacc"
{dim_push_type("char","1",0);;
    break;}
case 289:
#line 1939 "fgl.yacc"
{dim_push_type("char",yyvsp[-1].str,0);;
    break;}
case 290:
#line 1941 "fgl.yacc"
{dim_push_type("char",yyvsp[-1].str,0);;
    break;}
case 291:
#line 1943 "fgl.yacc"
{dim_push_type("char",yyvsp[-3].str,0);;
    break;}
case 292:
#line 1944 "fgl.yacc"
{dim_push_type("long",0,0);;
    break;}
case 293:
#line 1945 "fgl.yacc"
{dim_push_type("integer",0,0);;
    break;}
case 294:
#line 1946 "fgl.yacc"
{dim_push_type("FORM",0,0);;
    break;}
case 295:
#line 1947 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
;
    break;}
case 296:
#line 1952 "fgl.yacc"
{

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
;
    break;}
case 297:
#line 1959 "fgl.yacc"
{
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
;
    break;}
case 298:
#line 1964 "fgl.yacc"
{dim_push_type("fglmoney",0,0);;
    break;}
case 299:
#line 1966 "fgl.yacc"
{dim_push_type("fglmoney",0,0);;
    break;}
case 300:
#line 1968 "fgl.yacc"
{dim_push_type("fglmoney",0,0);;
    break;}
case 301:
#line 1969 "fgl.yacc"
{dim_push_type("double",0,0);;
    break;}
case 302:
#line 1970 "fgl.yacc"
{dim_push_type("float",0,0);;
    break;}
case 303:
#line 1971 "fgl.yacc"
{dim_push_type("fgldate",0,0);;
    break;}
case 304:
#line 1972 "fgl.yacc"
{dim_push_type("fglbyte",0,0);;
    break;}
case 305:
#line 1973 "fgl.yacc"
{dim_push_type("fgltext",0,0);;
    break;}
case 306:
#line 1974 "fgl.yacc"
{
dim_push_type("struct_dtime ",yyvsp[0].str,0);
;
    break;}
case 307:
#line 1977 "fgl.yacc"
{dim_push_type("struct_ival ",0,0);;
    break;}
case 308:
#line 1979 "fgl.yacc"
{dim_push_like(yyvsp[0].str);fflush(stdout);lex_printcomment("/*added(XXXXX)\n */");;
    break;}
case 309:
#line 1985 "fgl.yacc"
{
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");;
    break;}
case 310:
#line 1993 "fgl.yacc"
{
dim_push_type(0,0,yyvsp[-1].str);
;
    break;}
case 312:
#line 2001 "fgl.yacc"
{
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
;
    break;}
case 313:
#line 2005 "fgl.yacc"
{
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
;
    break;}
case 314:
#line 2013 "fgl.yacc"
{dim_push_record();;
    break;}
case 315:
#line 2014 "fgl.yacc"
{dim_pop_record();;
    break;}
case 316:
#line 2015 "fgl.yacc"
{dim_push_record();debug("Like\n");;
    break;}
case 317:
#line 2016 "fgl.yacc"
{debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();;
    break;}
case 323:
#line 2035 "fgl.yacc"
{ dim_push_name(yyval.str,0); ;
    break;}
case 324:
#line 2047 "fgl.yacc"
{
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	;
    break;}
case 325:
#line 2051 "fgl.yacc"
{
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	;
    break;}
case 326:
#line 2054 "fgl.yacc"
{ 
	strcpy(yyval.str,"#error not implemented yet");
	;
    break;}
case 327:
#line 2057 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(4,0,0)); ;
    break;}
case 328:
#line 2058 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); ;
    break;}
case 329:
#line 2059 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); ;
    break;}
case 330:
#line 2060 "fgl.yacc"
{ strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); ;
    break;}
case 331:
#line 2061 "fgl.yacc"
{ 
	strcpy(yyval.str,"#error not implemented yet");
 ;
    break;}
case 332:
#line 2067 "fgl.yacc"
{
		print_display_by_name(yyvsp[0].str);
                ;
    break;}
case 333:
#line 2072 "fgl.yacc"
{ 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		;
    break;}
case 334:
#line 2077 "fgl.yacc"
{
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	;
    break;}
case 335:
#line 2082 "fgl.yacc"
{
		push_blockcommand("DISPLAY");
		;
    break;}
case 336:
#line 2086 "fgl.yacc"
{
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		;
    break;}
case 337:
#line 2089 "fgl.yacc"
{
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
;
    break;}
case 338:
#line 2097 "fgl.yacc"
{
sprintf(yyval.str,"0,0");
;
    break;}
case 339:
#line 2099 "fgl.yacc"
{
	sprintf(yyval.str,yyvsp[0].str);
;
    break;}
case 340:
#line 2104 "fgl.yacc"
{
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			;
    break;}
case 345:
#line 2116 "fgl.yacc"
{
		print_befaft_field_1("AFT_ROW");
		;
    break;}
case 346:
#line 2119 "fgl.yacc"
{
		print_befaft_field_2();
	;
    break;}
case 347:
#line 2122 "fgl.yacc"
{
		print_befaft_field_1("BEF_ROW");
		;
    break;}
case 348:
#line 2125 "fgl.yacc"
{
		print_befaft_field_2();
	;
    break;}
case 349:
#line 2128 "fgl.yacc"
{
		print_onkey_1(yyvsp[0].str);
		;
    break;}
case 350:
#line 2131 "fgl.yacc"
{
		print_onkey_2();
	;
    break;}
case 351:
#line 2144 "fgl.yacc"
{
			print_error(yyvsp[0].str,0);
		;
    break;}
case 352:
#line 2147 "fgl.yacc"
{ 
			print_error(yyvsp[-1].str,1);
	;
    break;}
case 353:
#line 2162 "fgl.yacc"
{
	print_exit_program(0);
;
    break;}
case 354:
#line 2165 "fgl.yacc"
{
	print_exit_program(1);
;
    break;}
case 355:
#line 2179 "fgl.yacc"
{ if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} ;
    break;}
case 356:
#line 2181 "fgl.yacc"
{ if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} ;
    break;}
case 357:
#line 2183 "fgl.yacc"
{ if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} ;
    break;}
case 358:
#line 2185 "fgl.yacc"
{ if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} ;
    break;}
case 359:
#line 2187 "fgl.yacc"
{ if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} ;
    break;}
case 360:
#line 2189 "fgl.yacc"
{ if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} ;
    break;}
case 361:
#line 2190 "fgl.yacc"
{
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;;
    break;}
case 362:
#line 2197 "fgl.yacc"
{ if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} ;
    break;}
case 363:
#line 2199 "fgl.yacc"
{ if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} ;
    break;}
case 364:
#line 2203 "fgl.yacc"
{ if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} ;
    break;}
case 365:
#line 2205 "fgl.yacc"
{ if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} ;
    break;}
case 366:
#line 2207 "fgl.yacc"
{ if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} ;
    break;}
case 367:
#line 2209 "fgl.yacc"
{ if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} ;
    break;}
case 368:
#line 2211 "fgl.yacc"
{ if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} ;
    break;}
case 369:
#line 2213 "fgl.yacc"
{ if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} ;
    break;}
case 370:
#line 2215 "fgl.yacc"
{ if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} ;
    break;}
case 371:
#line 2221 "fgl.yacc"
{ if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} ;
    break;}
case 376:
#line 2238 "fgl.yacc"
{
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
;
    break;}
case 379:
#line 2244 "fgl.yacc"
{
	debug("Got literal ptr=%p",yyvsp[0].ptr);
;
    break;}
case 380:
#line 2248 "fgl.yacc"
{
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
;
    break;}
case 381:
#line 2253 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
;
    break;}
case 385:
#line 2263 "fgl.yacc"
{ yyval.ptr=new_expr("add_spaces();"); ;
    break;}
case 392:
#line 2274 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 395:
#line 2278 "fgl.yacc"
{yyval.ptr=new_expr("push_null()");;
    break;}
case 396:
#line 2282 "fgl.yacc"
{
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
;
    break;}
case 397:
#line 2288 "fgl.yacc"
{
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
;
    break;}
case 398:
#line 2296 "fgl.yacc"
{
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
;
    break;}
case 399:
#line 2302 "fgl.yacc"
{
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
;
    break;}
case 400:
#line 2311 "fgl.yacc"
{sprintf(yyval.str,"%d",get_counter_val());;
    break;}
case 401:
#line 2313 "fgl.yacc"
{
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
;
    break;}
case 402:
#line 2320 "fgl.yacc"
{
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
;
    break;}
case 403:
#line 2328 "fgl.yacc"
{
	strcpy(yyval.str,"+");
;
    break;}
case 404:
#line 2332 "fgl.yacc"
{
	strcpy(yyval.str,"-");
;
    break;}
case 405:
#line 2341 "fgl.yacc"
{
	
        /* sprintf($<str>$,"%s pushop(OP_NOT);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
;
    break;}
case 406:
#line 2347 "fgl.yacc"
{
        /* sprintf($<str>$,"push_int(1);"); */
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
;
    break;}
case 407:
#line 2353 "fgl.yacc"
{
        /* sprintf($<str>$,"push_int(0);"); */
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
;
    break;}
case 408:
#line 2358 "fgl.yacc"
{ yyval.ptr=yyvsp[-1].ptr; ;
    break;}
case 409:
#line 2360 "fgl.yacc"
{
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_EXISTS);");
;
    break;}
case 410:
#line 2370 "fgl.yacc"
{
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTEXISTS);");
;
    break;}
case 411:
#line 2384 "fgl.yacc"
{
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,get_push_literal('D',yyval.str));
        /* sprintf($<str>$,"push_double((double)%s%s)",$<str>1,$<str>2); */
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
;
    break;}
case 412:
#line 2393 "fgl.yacc"
{
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
;
    break;}
case 413:
#line 2403 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%d);",atoi(yyvsp[0].str));inc_counter(); 
	yyval.ptr=new_expr(yyval.str);
;
    break;}
case 414:
#line 2406 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%s);",yyvsp[0].str); inc_counter();
	yyval.ptr=new_expr(yyval.str);
;
    break;}
case 415:
#line 2410 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('S',yyvsp[0].str));
	/* sprintf($<str>$,"push_char(%s);",$<str>1); */
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
;
    break;}
case 416:
#line 2417 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('D',yyvsp[0].str));
	/* sprintf($<str>$,"push_double((double)%s);",$<str>1); */
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
;
    break;}
case 417:
#line 2424 "fgl.yacc"
{
	sprintf(yyval.str,get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
;
    break;}
case 418:
#line 2430 "fgl.yacc"
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
;
    break;}
case 419:
#line 2494 "fgl.yacc"
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
;
    break;}
case 420:
#line 2548 "fgl.yacc"
{
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
;
    break;}
case 421:
#line 2554 "fgl.yacc"
{
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
;
    break;}
case 422:
#line 2558 "fgl.yacc"
{
   if (!in_command("REPORT")) {
   yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=new_expr(yyvsp[0].str);
;
    break;}
case 423:
#line 2566 "fgl.yacc"
{insql=1;set_ingroup();;
    break;}
case 424:
#line 2566 "fgl.yacc"
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
      ;
    break;}
case 425:
#line 2583 "fgl.yacc"
{
	/* sprintf($<str>$,"%s pushop(OP_AND);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
;
    break;}
case 426:
#line 2588 "fgl.yacc"
{
	/* sprintf($<str>$,"%s pushop(OP_OR);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
;
    break;}
case 427:
#line 2595 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
	;
    break;}
case 428:
#line 2598 "fgl.yacc"
{
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	;
    break;}
case 429:
#line 2606 "fgl.yacc"
{
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN_SELECT);");
;
    break;}
case 430:
#line 2617 "fgl.yacc"
{
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN_SELECT);");
;
    break;}
case 431:
#line 2627 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
;
    break;}
case 432:
#line 2633 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
;
    break;}
case 433:
#line 2643 "fgl.yacc"
{ 
	sprintf(yyval.str,"pushop(OP_ISNULL);");
	yyval.ptr=new_expr(yyval.str);
;
    break;}
case 434:
#line 2648 "fgl.yacc"
{
	sprintf(yyval.str,"pushop(OP_ISNOTNULL);");
	yyval.ptr=new_expr(yyval.str);
;
    break;}
case 435:
#line 2656 "fgl.yacc"
{
	/* sprintf($<str>$,"%s pushop(OP_MATCHES);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);");
;
    break;}
case 436:
#line 2661 "fgl.yacc"
{
	/* sprintf($<str>$,"%s pushop(OP_MATCHES);pushop(OP_NOT);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);pushop(OP_NOT);");
;
    break;}
case 437:
#line 2666 "fgl.yacc"
{
	/* sprintf($<str>$," %s pushop(OP_LIKE);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);");
;
    break;}
case 438:
#line 2671 "fgl.yacc"
{
	/* sprintf($<str>$,"pushop(OP_LIKE);pushop(OP_NOT);",$<str>2); */
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);pushop(OP_NOT);");
;
    break;}
case 439:
#line 2679 "fgl.yacc"
{
	sprintf(yyval.str,"pushop(OP_CLIP);");
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
;
    break;}
case 440:
#line 2687 "fgl.yacc"
{
	sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
;
    break;}
case 441:
#line 2695 "fgl.yacc"
{
	debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
;
    break;}
case 442:
#line 2700 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
;
    break;}
case 443:
#line 2704 "fgl.yacc"
{
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
;
    break;}
case 444:
#line 2709 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
;
    break;}
case 445:
#line 2713 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
;
    break;}
case 446:
#line 2717 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
;
    break;}
case 447:
#line 2723 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
;
    break;}
case 448:
#line 2726 "fgl.yacc"
{
	sprintf(yyval.str,"%s pushop(OP_EQUAL);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
;
    break;}
case 449:
#line 2731 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
;
    break;}
case 450:
#line 2735 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
;
    break;}
case 451:
#line 2739 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
;
    break;}
case 452:
#line 2743 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
;
    break;}
case 453:
#line 2747 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
;
    break;}
case 454:
#line 2753 "fgl.yacc"
{
	reset_counter();
;
    break;}
case 455:
#line 2763 "fgl.yacc"
{ 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		;
    break;}
case 456:
#line 2768 "fgl.yacc"
{ 
		sprintf(yyval.str,"%d",get_counter_val()); 
		lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		;
    break;}
case 457:
#line 2774 "fgl.yacc"
{
		int cnt;
		cnt=1;
		debug("Print expr (1)");
		/* print_expr($<ptr>4); */
		sprintf(yyval.str,"{int _retvars;\n_retvars=aclfgl_%s(%s); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n}\n", yyvsp[-5].str,yyvsp[-1].str, lastlineno,infilename);
		yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		;
    break;}
case 458:
#line 2783 "fgl.yacc"
{
        sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
;
    break;}
case 459:
#line 2788 "fgl.yacc"
{
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
;
    break;}
case 460:
#line 2791 "fgl.yacc"
{
	char buff[256];
        char *ptr;
        strcpy(buff,yyvsp[-3].str);
        ptr=strchr(buff,',');
        *ptr=0;
        ptr++;
	sprintf(yyval.str,"{int _retvars;\n_retvars=call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");pop_args(_retvars);push_null();}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
	yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
;
    break;}
case 461:
#line 2805 "fgl.yacc"
{inc_counter();chk4var=1;;
    break;}
case 462:
#line 2805 "fgl.yacc"
{chk4var=0;;
    break;}
case 463:
#line 2805 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();;
    break;}
case 464:
#line 2808 "fgl.yacc"
{inc_counter();chk4var=1;;
    break;}
case 465:
#line 2808 "fgl.yacc"
{chk4var=0;;
    break;}
case 466:
#line 2808 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();;
    break;}
case 467:
#line 2811 "fgl.yacc"
{inc_counter();chk4var=1;;
    break;}
case 468:
#line 2811 "fgl.yacc"
{chk4var=0;;
    break;}
case 469:
#line 2811 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();;
    break;}
case 470:
#line 2814 "fgl.yacc"
{inc_counter();chk4var=1;;
    break;}
case 471:
#line 2814 "fgl.yacc"
{chk4var=0;;
    break;}
case 472:
#line 2814 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();;
    break;}
case 474:
#line 2822 "fgl.yacc"
{
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

;
    break;}
case 475:
#line 2828 "fgl.yacc"
{sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); ;
    break;}
case 476:
#line 2829 "fgl.yacc"
{
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
;
    break;}
case 477:
#line 2834 "fgl.yacc"
{sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
;
    break;}
case 478:
#line 2838 "fgl.yacc"
{ sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
;
    break;}
case 481:
#line 2845 "fgl.yacc"
{
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	;
    break;}
case 482:
#line 2850 "fgl.yacc"
{ inc_counter(); sprintf(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		;
    break;}
case 483:
#line 2857 "fgl.yacc"
{ 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
;
    break;}
case 484:
#line 2861 "fgl.yacc"
{ 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
;
    break;}
case 485:
#line 2864 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%d);",atoi(yyvsp[-1].str));
	yyval.ptr=new_expr(yyval.str);
;
    break;}
case 486:
#line 2867 "fgl.yacc"
{ sprintf(yyval.str,"push_ascii(%s);",yyvsp[-1].str);
	yyval.ptr=new_expr(yyval.str);
;
    break;}
case 487:
#line 2872 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
;
    break;}
case 488:
#line 2875 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
;
    break;}
case 489:
#line 2878 "fgl.yacc"
{
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
;
    break;}
case 490:
#line 2893 "fgl.yacc"
{
push_blockcommand("FOREACH");
;
    break;}
case 491:
#line 2897 "fgl.yacc"
{
print_foreach_start();
lex_printcomment(" /* foreach */\n");
;
    break;}
case 492:
#line 2902 "fgl.yacc"
{
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 493:
#line 2906 "fgl.yacc"
{
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
;
    break;}
case 494:
#line 2922 "fgl.yacc"
{
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        ;
    break;}
case 495:
#line 2928 "fgl.yacc"
{
		print_getwin();
	;
    break;}
case 496:
#line 2935 "fgl.yacc"
{
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);;
    break;}
case 503:
#line 2952 "fgl.yacc"
{
		print_event('B');
        ;
    break;}
case 504:
#line 2954 "fgl.yacc"
{
		print_event_2();
        ;
    break;}
case 505:
#line 2957 "fgl.yacc"
{
		print_event('b');
        ;
    break;}
case 506:
#line 2959 "fgl.yacc"
{
		print_event_2();
        ;
    break;}
case 511:
#line 2973 "fgl.yacc"
{
		print_event('A');
        ;
    break;}
case 512:
#line 2975 "fgl.yacc"
{
		print_event_2();
        ;
    break;}
case 513:
#line 2978 "fgl.yacc"
{
		print_event('a');
        ;
    break;}
case 514:
#line 2980 "fgl.yacc"
{
		print_event_2();
        ;
    break;}
case 527:
#line 3011 "fgl.yacc"
{ 
			print_gtk_field('B',0);
		;
    break;}
case 528:
#line 3013 "fgl.yacc"
{
			print_gtk_field_2();
		;
    break;}
case 529:
#line 3016 "fgl.yacc"
{ 
			print_gtk_field('A',0);
		;
    break;}
case 530:
#line 3018 "fgl.yacc"
{
			print_gtk_field_2();
		;
    break;}
case 531:
#line 3021 "fgl.yacc"
{
			print_gtk_field('b',yyvsp[0].str);
		;
    break;}
case 532:
#line 3023 "fgl.yacc"
{ 
			print_gtk_field_2();
		;
    break;}
case 533:
#line 3026 "fgl.yacc"
{
			print_gtk_field('a',yyvsp[0].str);
		;
    break;}
case 534:
#line 3028 "fgl.yacc"
{ 
			print_gtk_field_2();
		;
    break;}
case 535:
#line 3031 "fgl.yacc"
{ 
			print_gtk_field('o',yyvsp[0].str);
		;
    break;}
case 536:
#line 3033 "fgl.yacc"
{ 
			print_gtk_field_2();
		;
    break;}
case 537:
#line 3047 "fgl.yacc"
{
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
;
    break;}
case 538:
#line 3051 "fgl.yacc"
{debug("For_cmds\n");;
    break;}
case 539:
#line 3052 "fgl.yacc"
{

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");;
    break;}
case 540:
#line 3059 "fgl.yacc"
{
		print_for_default_step();
	;
    break;}
case 542:
#line 3077 "fgl.yacc"
{
		print_niy("Free Cursor");
		strcpy(yyval.str,"");
		;
    break;}
case 543:
#line 3091 "fgl.yacc"
{sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));;
    break;}
case 544:
#line 3092 "fgl.yacc"
{sprintf(yyval.str,"-1");;
    break;}
case 545:
#line 3093 "fgl.yacc"
{sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);;
    break;}
case 546:
#line 3094 "fgl.yacc"
{sprintf(yyval.str,"1");;
    break;}
case 547:
#line 3095 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);;
    break;}
case 548:
#line 3096 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);;
    break;}
case 552:
#line 3104 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); ;
    break;}
case 554:
#line 3110 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);;
    break;}
case 555:
#line 3111 "fgl.yacc"
{ sprintf(yyval.str,"int_to_id($<str>3)"); ;
    break;}
case 556:
#line 3112 "fgl.yacc"
{ sprintf(yyval.str,"int_to_id($<str>3)"); ;
    break;}
case 557:
#line 3114 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);;
    break;}
case 558:
#line 3116 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);;
    break;}
case 559:
#line 3118 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);;
    break;}
case 560:
#line 3120 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 561:
#line 3122 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);;
    break;}
case 562:
#line 3125 "fgl.yacc"
{
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			;
    break;}
case 563:
#line 3132 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);;
    break;}
case 564:
#line 3134 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
;
    break;}
case 565:
#line 3140 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
;
    break;}
case 566:
#line 3145 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
;
    break;}
case 567:
#line 3150 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
;
    break;}
case 568:
#line 3155 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 569:
#line 3155 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 570:
#line 3158 "fgl.yacc"
{ 
			strcpy(yyval.str,downshift(yyvsp[-1].str)) ;
;
    break;}
case 571:
#line 3161 "fgl.yacc"
{ strcpy(yyval.str,downshift(yyvsp[0].str)) ; ;
    break;}
case 572:
#line 3165 "fgl.yacc"
{
			sprintf(yyval.str,"%s",yyvsp[-1].str) ;
			;
    break;}
case 573:
#line 3170 "fgl.yacc"
{
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
;
    break;}
case 574:
#line 3174 "fgl.yacc"
{
strcpy(yyval.str,yyvsp[-1].str);
sprintf(last_var,"->%s",yyvsp[-1].str);
;
    break;}
case 577:
#line 3182 "fgl.yacc"
{
		debug("Setident\n");
		/* chk4var=1; */
	strcpy(yyval.str,"");
	   ;
    break;}
case 578:
#line 3188 "fgl.yacc"
{
		debug("Unsetident\n");
		chk4var=0;
		;
    break;}
case 579:
#line 3192 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);;
    break;}
case 580:
#line 3194 "fgl.yacc"
{sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);;
    break;}
case 581:
#line 3196 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);;
    break;}
case 582:
#line 3198 "fgl.yacc"
{sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);;
    break;}
case 583:
#line 3200 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 584:
#line 3202 "fgl.yacc"
{sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);;
    break;}
case 585:
#line 3205 "fgl.yacc"
{
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
yyerror("Only a character variable can be used for this");
YYERROR;
}
;
    break;}
case 587:
#line 3214 "fgl.yacc"
{
		sprintf(yyval.str,".%s",yyvsp[0].str);
;
    break;}
case 628:
#line 3272 "fgl.yacc"
{
	print_goto(yyvsp[0].str);
;
    break;}
case 629:
#line 3285 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'C');
;
    break;}
case 631:
#line 3292 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 632:
#line 3295 "fgl.yacc"
{
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
;
    break;}
case 633:
#line 3301 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'U');
;
    break;}
case 634:
#line 3307 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'D');
;
    break;}
case 635:
#line 3311 "fgl.yacc"
{
print_gui_do_fields(yyvsp[0].str,'D');
;
    break;}
case 636:
#line 3315 "fgl.yacc"
{
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
;
    break;}
case 637:
#line 3321 "fgl.yacc"
{
print_gui_do_menuitems(yyvsp[0].str,'E');
;
    break;}
case 638:
#line 3325 "fgl.yacc"
{
print_gui_do_fields(yyvsp[0].str,'E');
;
    break;}
case 639:
#line 3329 "fgl.yacc"
{
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
;
    break;}
case 640:
#line 3334 "fgl.yacc"
{start_state("messagebox",1);;
    break;}
case 641:
#line 3339 "fgl.yacc"
{start_state("messagebox",0);;
    break;}
case 660:
#line 3380 "fgl.yacc"
{
		print_if_start();
	;
    break;}
case 661:
#line 3385 "fgl.yacc"
{
		print_if_end();
	;
    break;}
case 663:
#line 3390 "fgl.yacc"
{
		print_if_else();
	;
    break;}
case 665:
#line 3395 "fgl.yacc"
{
	print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
;
    break;}
case 667:
#line 3401 "fgl.yacc"
{
		add_ex_dtype(yyvsp[0].str);
	;
    break;}
case 668:
#line 3413 "fgl.yacc"
{debug("init to\n");;
    break;}
case 669:
#line 3414 "fgl.yacc"
{
	print_init();
 ;
    break;}
case 670:
#line 3417 "fgl.yacc"
{
	print_init_table(yyvsp[0].str);
;
    break;}
case 672:
#line 3423 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 673:
#line 3427 "fgl.yacc"
{setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 674:
#line 3428 "fgl.yacc"
{setrecord(yyval.str,yyvsp[-2].str,0);;
    break;}
case 677:
#line 3442 "fgl.yacc"
{
sprintf(yyval.str,"0");
;
    break;}
case 678:
#line 3444 "fgl.yacc"
{
sprintf(yyval.str,"1");
;
    break;}
case 681:
#line 3453 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
;
    break;}
case 682:
#line 3455 "fgl.yacc"
{
	print_befaft_field_2();
;
    break;}
case 683:
#line 3459 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
;
    break;}
case 684:
#line 3461 "fgl.yacc"
{
	print_befaft_field_2();
;
    break;}
case 685:
#line 3464 "fgl.yacc"
{
		print_befaft_field_1("AFT_ROW");
;
    break;}
case 686:
#line 3466 "fgl.yacc"
{
	print_befaft_field_2();
;
    break;}
case 687:
#line 3469 "fgl.yacc"
{
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
;
    break;}
case 688:
#line 3472 "fgl.yacc"
{
	print_befaft_field_2();
		;
    break;}
case 689:
#line 3475 "fgl.yacc"
{
	print_onkey_1(yyvsp[0].str);
;
    break;}
case 690:
#line 3477 "fgl.yacc"
{
	print_onkey_2();
;
    break;}
case 691:
#line 3480 "fgl.yacc"
{
		print_befaft_field_1("AFTER_INP");
;
    break;}
case 692:
#line 3482 "fgl.yacc"
{
	print_befaft_field_2();
;
    break;}
case 693:
#line 3485 "fgl.yacc"
{
		print_befaft_field_1("BEFORE_INP");
;
    break;}
case 694:
#line 3487 "fgl.yacc"
{
	print_befaft_field_2();
;
    break;}
case 695:
#line 3490 "fgl.yacc"
{lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
;
    break;}
case 696:
#line 3492 "fgl.yacc"
{
	print_befaft_field_2();
;
    break;}
case 697:
#line 3495 "fgl.yacc"
{
		print_befaft_field_1(yyvsp[0].str);
;
    break;}
case 698:
#line 3497 "fgl.yacc"
{
	print_befaft_field_2();
;
    break;}
case 699:
#line 3503 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[0].str);;
    break;}
case 700:
#line 3504 "fgl.yacc"
{
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	;
    break;}
case 701:
#line 3512 "fgl.yacc"
{strcpy(yyval.str,"AFT_INSERT");;
    break;}
case 702:
#line 3513 "fgl.yacc"
{strcpy(yyval.str,"AFT_DELETE");;
    break;}
case 703:
#line 3518 "fgl.yacc"
{sprintf(yyval.str,"(%s)",yyvsp[0].str);;
    break;}
case 704:
#line 3519 "fgl.yacc"
{
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 ;
    break;}
case 705:
#line 3528 "fgl.yacc"
{strcpy(yyval.str,"BEF_INSERT");;
    break;}
case 706:
#line 3529 "fgl.yacc"
{strcpy(yyval.str,"BEF_DELETE");;
    break;}
case 707:
#line 3536 "fgl.yacc"
{sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);;
    break;}
case 708:
#line 3537 "fgl.yacc"
{
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	;
    break;}
case 709:
#line 3545 "fgl.yacc"
{sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);;
    break;}
case 710:
#line 3546 "fgl.yacc"
{
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	;
    break;}
case 711:
#line 3555 "fgl.yacc"
{
print_next_field(yyvsp[0].str);
;
    break;}
case 712:
#line 3560 "fgl.yacc"
{
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 713:
#line 3565 "fgl.yacc"
{sprintf(yyval.str,"\"+\",0");;
    break;}
case 714:
#line 3566 "fgl.yacc"
{sprintf(yyval.str,"\"-\",0");;
    break;}
case 716:
#line 3571 "fgl.yacc"
{
print_input_1();
;
    break;}
case 717:
#line 3574 "fgl.yacc"
{
print_input_2(yyvsp[-2].str);
;
    break;}
case 718:
#line 3582 "fgl.yacc"
{
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
;
    break;}
case 719:
#line 3587 "fgl.yacc"
{
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
;
    break;}
case 720:
#line 3591 "fgl.yacc"
{
inp_flags=0;;
    break;}
case 721:
#line 3593 "fgl.yacc"
{
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
;
    break;}
case 722:
#line 3602 "fgl.yacc"
{
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	;
    break;}
case 723:
#line 3607 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 724:
#line 3608 "fgl.yacc"
{strcpy(yyval.str,"-1");;
    break;}
case 725:
#line 3609 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);;
    break;}
case 726:
#line 3610 "fgl.yacc"
{sprintf(yyval.str,"-%s",yyvsp[0].str);;
    break;}
case 727:
#line 3613 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 729:
#line 3619 "fgl.yacc"
{iskey=1;;
    break;}
case 730:
#line 3619 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);iskey=0;;
    break;}
case 731:
#line 3621 "fgl.yacc"
{strcpy(yyval.str,"->ANY");;
    break;}
case 732:
#line 3624 "fgl.yacc"
{iskey=1;;
    break;}
case 733:
#line 3624 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);iskey=0;;
    break;}
case 734:
#line 3626 "fgl.yacc"
{sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;;
    break;}
case 735:
#line 3630 "fgl.yacc"
{start_state("keymode",1);iskey=1;;
    break;}
case 736:
#line 3630 "fgl.yacc"
{sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);;
    break;}
case 737:
#line 3633 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 738:
#line 3634 "fgl.yacc"
{strcpy(yyval.str,yyvsp[-1].str);;
    break;}
case 740:
#line 3637 "fgl.yacc"
{
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 741:
#line 3642 "fgl.yacc"
{start_state("keymode",1);;
    break;}
case 742:
#line 3642 "fgl.yacc"
{start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 747:
#line 3649 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 748:
#line 3650 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 749:
#line 3651 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 750:
#line 3652 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 751:
#line 3653 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 752:
#line 3654 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 753:
#line 3655 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 754:
#line 3656 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 755:
#line 3657 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 756:
#line 3658 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 757:
#line 3659 "fgl.yacc"
{ rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); ;
    break;}
case 758:
#line 3663 "fgl.yacc"
{
	exitwith ("Expecting a ':'");
;
    break;}
case 759:
#line 3667 "fgl.yacc"
{
	print_label(yyvsp[-1].str);
;
    break;}
case 760:
#line 3681 "fgl.yacc"
{chk4var=1;;
    break;}
case 761:
#line 3681 "fgl.yacc"
{chk4var=0;
lex_printcomment("/*let3*/\n");;
    break;}
case 762:
#line 3683 "fgl.yacc"
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

;
    break;}
case 763:
#line 3707 "fgl.yacc"
{
	print_push_null();
	strcpy(yyval.str,"1");
;
    break;}
case 765:
#line 3718 "fgl.yacc"
{
		if (!print_linked_cmd('S',yyvsp[0].str)) yyerror("Not a linked variable");
	;
    break;}
case 766:
#line 3724 "fgl.yacc"
{
		 if (!print_linked_cmd('D',yyvsp[0].str)) yyerror("Not a linked variable");
	;
    break;}
case 767:
#line 3730 "fgl.yacc"
{
		 if (!print_linked_cmd('U',yyvsp[0].str)) yyerror("Not a linked variable");
;
    break;}
case 768:
#line 3736 "fgl.yacc"
{
int vtype;
vtype=scan_variable(yyvsp[-1].str);
if (vtype!=11&&vtype!=12) {
yyerror("Only Byte & Text may be located...");
YYERROR;
}
print_locate('M',yyvsp[-1].str,"0");


;
    break;}
case 769:
#line 3747 "fgl.yacc"
{
int vtype;
vtype=scan_variable(yyvsp[-2].str);
if (vtype!=11&&vtype!=12) {
yyerror("Only Byte & Text may be located...");
YYERROR;
}

print_locate('F',yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 770:
#line 3767 "fgl.yacc"
{
	modlevel=-1;
	/* read_glob_var = 1; */
	print_variables();
	/* read_glob_var = 0; */
	set_mod_level(varcnt);set_4gl_vars();set_mod_level(0);
	strcpy(curr_func,"[Module]");
;
    break;}
case 771:
#line 3774 "fgl.yacc"
{inmod();;
    break;}
case 773:
#line 3778 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 777:
#line 3786 "fgl.yacc"
{
		print_at_termination(yyvsp[0].str);
	;
    break;}
case 792:
#line 3807 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 793:
#line 3808 "fgl.yacc"
{
strcpy(yyval.str,"static ");
;
    break;}
case 794:
#line 3816 "fgl.yacc"
{
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
;
    break;}
case 795:
#line 3821 "fgl.yacc"
{ 
  sprintf(curr_func,"%s",yyvsp[-1].str);
  addmap("Declare Function",curr_func,"MODULE",yylineno,infilename);
  print_func_start(yyvsp[-3].str,yyvsp[-1].str,0);
  printDeclareFunctionStack(yyvsp[-1].str);
  cnt=0;
;
    break;}
case 796:
#line 3829 "fgl.yacc"
{
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
;
    break;}
case 797:
#line 3835 "fgl.yacc"
{
  int c;
  lex_printcomment("/*end of define section */\n");
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
;
    break;}
case 799:
#line 3849 "fgl.yacc"
{
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    lex_printcomment("/*end function*/\n");
  ;
    break;}
case 800:
#line 3862 "fgl.yacc"
{ 
    lastlineno=yylineno;
    sprintf(curr_func,"MAIN");
    clr_variable(); 
    push_blockcommand("MAIN"); 
    addmap("MAIN",curr_func,"MODULE",yylineno,infilename);
    print_main_1();
  ;
    break;}
case 801:
#line 3871 "fgl.yacc"
{
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  ;
    break;}
case 802:
#line 3877 "fgl.yacc"
{
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");;
    break;}
case 803:
#line 3884 "fgl.yacc"
{
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  ;
    break;}
case 804:
#line 3889 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 805:
#line 3889 "fgl.yacc"
{
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);;
    break;}
case 806:
#line 3894 "fgl.yacc"
{open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;;
    break;}
case 807:
#line 3899 "fgl.yacc"
{strcpy(yyval.str,"");lastlineno=yylineno;;
    break;}
case 808:
#line 3900 "fgl.yacc"
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
;
    break;}
case 815:
#line 3922 "fgl.yacc"
{
strcpy(curr_func,"[Globals]");
push_blockcommand("GLOBALS");
lex_printcomment("/* start of globals */\n");
;
    break;}
case 816:
#line 3928 "fgl.yacc"
{
pop_blockcommand("GLOBALS");
;
    break;}
case 817:
#line 3933 "fgl.yacc"
{
lex_printcomment("/* end of globals */");
debug("end of globals\n");
lastlineno=yylineno;
;
    break;}
case 818:
#line 3938 "fgl.yacc"
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
;
    break;}
case 819:
#line 3961 "fgl.yacc"
{
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
;
    break;}
case 820:
#line 3965 "fgl.yacc"
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
;
    break;}
case 821:
#line 3978 "fgl.yacc"
{
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
;
    break;}
case 823:
#line 3991 "fgl.yacc"
{
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
;
    break;}
case 824:
#line 3996 "fgl.yacc"
{
                push_blockcommand("MENUH");
        ;
    break;}
case 825:
#line 4000 "fgl.yacc"
{
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                ;
    break;}
case 828:
#line 4012 "fgl.yacc"
{

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        ;
    break;}
case 829:
#line 4017 "fgl.yacc"
{
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        ;
    break;}
case 830:
#line 4022 "fgl.yacc"
{
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        ;
    break;}
case 831:
#line 4025 "fgl.yacc"
{
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
;
    break;}
case 832:
#line 4040 "fgl.yacc"
{
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	;
    break;}
case 834:
#line 4048 "fgl.yacc"
{
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
;
    break;}
case 835:
#line 4059 "fgl.yacc"
{
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  ;
    break;}
case 836:
#line 4063 "fgl.yacc"
{
		print_menu_block_end();
	;
    break;}
case 837:
#line 4070 "fgl.yacc"
{
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		;
    break;}
case 838:
#line 4077 "fgl.yacc"
{
		print_menu_block_end();
;
    break;}
case 839:
#line 4083 "fgl.yacc"
{
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		;
    break;}
case 840:
#line 4088 "fgl.yacc"
{
		print_menu_block_end();
;
    break;}
case 843:
#line 4095 "fgl.yacc"
{strcpy(yyval.str,"\"EMPTY\"");;
    break;}
case 844:
#line 4096 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);;
    break;}
case 845:
#line 4098 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str); ;
    break;}
case 846:
#line 4099 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 847:
#line 4102 "fgl.yacc"
{strcpy(yyval.str,"\"\"");;
    break;}
case 848:
#line 4103 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 849:
#line 4104 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 850:
#line 4106 "fgl.yacc"
{
	print_option_op('N',yyvsp[0].str);
;
    break;}
case 851:
#line 4111 "fgl.yacc"
{
	print_option_op('S',yyvsp[0].str);
;
    break;}
case 852:
#line 4116 "fgl.yacc"
{
	print_option_op('H',yyvsp[0].str);
;
    break;}
case 853:
#line 4123 "fgl.yacc"
{sprintf(yyval.str,"MENU_ALL");;
    break;}
case 857:
#line 4130 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 858:
#line 4132 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);;
    break;}
case 859:
#line 4134 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);;
    break;}
case 860:
#line 4141 "fgl.yacc"
{start_state("message",0);;
    break;}
case 861:
#line 4144 "fgl.yacc"
{
		print_message(0,"0",0);
		start_state("message",0);
	   ;
    break;}
case 862:
#line 4148 "fgl.yacc"
{ 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  ;
    break;}
case 863:
#line 4152 "fgl.yacc"
{ 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  ;
    break;}
case 870:
#line 4169 "fgl.yacc"
{start_state("message",1);;
    break;}
case 872:
#line 4171 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 873:
#line 4171 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 874:
#line 4174 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 875:
#line 4184 "fgl.yacc"
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
;
    break;}
case 877:
#line 4207 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 879:
#line 4214 "fgl.yacc"
{ 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         ;
    break;}
case 880:
#line 4219 "fgl.yacc"
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
;
    break;}
case 884:
#line 4263 "fgl.yacc"
{
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (3)",yyvsp[-3].str);
           yyerror(buff2); 
           YYERROR;
         }

lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,1)",upshift(yyvsp[-3].str),yyvsp[-1].str);
;
    break;}
case 885:
#line 4277 "fgl.yacc"
{
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (4)",yyvsp[-3].str);
           yyerror(buff2); 
           YYERROR;
         }
lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,0)",upshift(yyvsp[-3].str),yyvsp[-1].str);
;
    break;}
case 890:
#line 4301 "fgl.yacc"
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
;
    break;}
case 891:
#line 4353 "fgl.yacc"
{
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	;
    break;}
case 892:
#line 4358 "fgl.yacc"
{
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	;
    break;}
case 893:
#line 4366 "fgl.yacc"
{
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
;
    break;}
case 894:
#line 4371 "fgl.yacc"
{
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
;
    break;}
case 895:
#line 4379 "fgl.yacc"
{
  sprintf (yyval.str, "%s", yyvsp[0].str);
;
    break;}
case 896:
#line 4385 "fgl.yacc"
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
;
    break;}
case 897:
#line 4406 "fgl.yacc"
{
		debug("Array..");
;
    break;}
case 898:
#line 4409 "fgl.yacc"
{ sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); ;
    break;}
case 899:
#line 4411 "fgl.yacc"
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

;
    break;}
case 904:
#line 4459 "fgl.yacc"
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

;
    break;}
case 905:
#line 4511 "fgl.yacc"
{
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");;
    break;}
case 907:
#line 4518 "fgl.yacc"
{
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
;
    break;}
case 908:
#line 4524 "fgl.yacc"
{
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
;
    break;}
case 909:
#line 4535 "fgl.yacc"
{
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
;
    break;}
case 910:
#line 4542 "fgl.yacc"
{
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
;
    break;}
case 912:
#line 4550 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);;
    break;}
case 913:
#line 4553 "fgl.yacc"
{lex_printcomment("/* Variable */\n");;
    break;}
case 914:
#line 4554 "fgl.yacc"
{
			debug("Got an ibind thru...");
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		;
    break;}
case 916:
#line 4559 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);;
    break;}
case 917:
#line 4560 "fgl.yacc"
{sprintf(yyval.str,"\"%s\"",yyvsp[0].str);;
    break;}
case 918:
#line 4563 "fgl.yacc"
{
start_bind('o',yyvsp[0].str);
;
    break;}
case 919:
#line 4566 "fgl.yacc"
{
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
;
    break;}
case 920:
#line 4572 "fgl.yacc"
{
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	;
    break;}
case 921:
#line 4578 "fgl.yacc"
{
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
;
    break;}
case 922:
#line 4582 "fgl.yacc"
{
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
;
    break;}
case 923:
#line 4589 "fgl.yacc"
{
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
;
    break;}
case 924:
#line 4594 "fgl.yacc"
{
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
;
    break;}
case 925:
#line 4601 "fgl.yacc"
{
start_bind('O',yyvsp[0].str);
;
    break;}
case 926:
#line 4604 "fgl.yacc"
{
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
;
    break;}
case 931:
#line 4617 "fgl.yacc"
{
  int type,arrsize,size,level;
  char arrbuff[256];
  lex_printcomment("/*..array_r_varid..*/");

  get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff);
  sprintf(yyval.str,"%s[%s-1]",yyvsp[-3].str,yyvsp[-1].str);
;
    break;}
case 932:
#line 4627 "fgl.yacc"
{
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
;
    break;}
case 933:
#line 4634 "fgl.yacc"
{
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
;
    break;}
case 934:
#line 4641 "fgl.yacc"
{
		strcpy(yyval.str,yyvsp[0].str);
	;
    break;}
case 935:
#line 4644 "fgl.yacc"
{
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		;
    break;}
case 936:
#line 4658 "fgl.yacc"
{
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
;
    break;}
case 941:
#line 4675 "fgl.yacc"
{
	print_niy("OPEN_STATUSBOX");
;
    break;}
case 942:
#line 4680 "fgl.yacc"
{
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
;
    break;}
case 943:
#line 4686 "fgl.yacc"
{
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		;
    break;}
case 945:
#line 4693 "fgl.yacc"
{ form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); ;
    break;}
case 946:
#line 4698 "fgl.yacc"
{sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);;
    break;}
case 947:
#line 4701 "fgl.yacc"
{strcpy(yyval.str,"0,0");;
    break;}
case 948:
#line 4702 "fgl.yacc"
{sprintf(yyval.str,"%s,2",yyvsp[-5].str);;
    break;}
case 949:
#line 4705 "fgl.yacc"
{strcpy(yyval.str,"\"\"");;
    break;}
case 950:
#line 4706 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 951:
#line 4709 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 952:
#line 4710 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 953:
#line 4715 "fgl.yacc"
{
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

;
    break;}
case 954:
#line 4722 "fgl.yacc"
{
	print_open_cursor(yyvsp[0].str,"0");
;
    break;}
case 955:
#line 4725 "fgl.yacc"
{
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
;
    break;}
case 956:
#line 4731 "fgl.yacc"
{sprintf(yyval.str,"0,0");;
    break;}
case 957:
#line 4733 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 958:
#line 4735 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);;
    break;}
case 959:
#line 4737 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 960:
#line 4740 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 961:
#line 4740 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 962:
#line 4741 "fgl.yacc"
{strcpy(yyval.str,"2");;
    break;}
case 963:
#line 4746 "fgl.yacc"
{
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 964:
#line 4754 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 965:
#line 4755 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 966:
#line 4760 "fgl.yacc"
{sprintf(yyval.str,"0,0");;
    break;}
case 967:
#line 4762 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 968:
#line 4764 "fgl.yacc"
{sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 972:
#line 4781 "fgl.yacc"
{
print_options('C',yyvsp[0].str);
;
    break;}
case 973:
#line 4784 "fgl.yacc"
{
print_options('E',yyvsp[0].str);
;
    break;}
case 974:
#line 4787 "fgl.yacc"
{
print_options('F',yyvsp[0].str);
;
    break;}
case 975:
#line 4790 "fgl.yacc"
{
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
;
    break;}
case 976:
#line 4793 "fgl.yacc"
{
print_options('m',yyvsp[0].str);
;
    break;}
case 977:
#line 4796 "fgl.yacc"
{
print_options('P',yyvsp[0].str);
;
    break;}
case 978:
#line 4799 "fgl.yacc"
{
print_options('A',yyvsp[0].str);
iskey=0;
;
    break;}
case 979:
#line 4803 "fgl.yacc"
{
print_options('D',yyvsp[0].str);
iskey=0;
;
    break;}
case 980:
#line 4807 "fgl.yacc"
{
print_options('I',yyvsp[0].str);
iskey=0;
;
    break;}
case 981:
#line 4811 "fgl.yacc"
{
print_options('N',yyvsp[0].str);
;
    break;}
case 982:
#line 4814 "fgl.yacc"
{
print_options('p',yyvsp[0].str);
iskey=0;
;
    break;}
case 983:
#line 4818 "fgl.yacc"
{
print_options('H',yyvsp[0].str);
;
    break;}
case 984:
#line 4821 "fgl.yacc"
{ print_set_helpfile(yyvsp[0].str); ;
    break;}
case 985:
#line 4822 "fgl.yacc"
{ print_set_langfile(yyvsp[0].str); ;
    break;}
case 986:
#line 4823 "fgl.yacc"
{
print_options('d',yyvsp[0].str);
;
    break;}
case 987:
#line 4826 "fgl.yacc"
{
print_options('i',yyvsp[0].str);
;
    break;}
case 988:
#line 4829 "fgl.yacc"
{
print_options('W',"1");
;
    break;}
case 989:
#line 4832 "fgl.yacc"
{
print_options('W',"0");
;
    break;}
case 990:
#line 4835 "fgl.yacc"
{
print_options('f',"1");
;
    break;}
case 991:
#line 4838 "fgl.yacc"
{
print_options('f',"0");
;
    break;}
case 992:
#line 4841 "fgl.yacc"
{
print_options('S',"1");
;
    break;}
case 993:
#line 4844 "fgl.yacc"
{
print_options('S',"0");
;
    break;}
case 994:
#line 4861 "fgl.yacc"
{
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
;
    break;}
case 997:
#line 4871 "fgl.yacc"
{

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
;
    break;}
case 998:
#line 4878 "fgl.yacc"
{
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
;
    break;}
case 1000:
#line 4899 "fgl.yacc"
{
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
;
    break;}
case 1001:
#line 4904 "fgl.yacc"
{
		if (strcmp(yyvsp[-5].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-4].str);
                pop_blockcommand("PROMPT");
                lex_printcomment("/* END OF PROMPT */");
                ;
    break;}
case 1002:
#line 4917 "fgl.yacc"
{
		print_niy("GUI PROMPT");
	;
    break;}
case 1003:
#line 4922 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 1004:
#line 4923 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 1005:
#line 4927 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1009:
#line 4933 "fgl.yacc"
{
	print_onkey_1(yyvsp[0].str);
;
    break;}
case 1010:
#line 4935 "fgl.yacc"
{
	print_onkey_2_prompt();
;
    break;}
case 1012:
#line 4950 "fgl.yacc"
{
		start_bind('i',0);
		;
    break;}
case 1013:
#line 4954 "fgl.yacc"
{
		print_put();
	;
    break;}
case 1014:
#line 4960 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1015:
#line 4961 "fgl.yacc"
{ strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 1016:
#line 4964 "fgl.yacc"
{push_gen(PUTVAL,yyvsp[0].str);;
    break;}
case 1017:
#line 4965 "fgl.yacc"
{push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1020:
#line 4981 "fgl.yacc"
{
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
;
    break;}
case 1021:
#line 4986 "fgl.yacc"
{
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
;
    break;}
case 1022:
#line 4991 "fgl.yacc"
{
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
;
    break;}
case 1023:
#line 4996 "fgl.yacc"
{
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
;
    break;}
case 1029:
#line 5015 "fgl.yacc"
{ 
;
    break;}
case 1030:
#line 5018 "fgl.yacc"
{
;
    break;}
case 1031:
#line 5021 "fgl.yacc"
{
;
    break;}
case 1032:
#line 5024 "fgl.yacc"
{
addmap("Output to report",yyvsp[-8].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-8].str,yyvsp[-2].str); 
;
    break;}
case 1033:
#line 5031 "fgl.yacc"
{
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
;
    break;}
case 1034:
#line 5037 "fgl.yacc"
{ sprintf(yyval.str,yyvsp[0].str); ;
    break;}
case 1035:
#line 5039 "fgl.yacc"
{
	print_format_every_row();
;
    break;}
case 1039:
#line 5050 "fgl.yacc"
{ push_report_block("FIRST",'P');;
    break;}
case 1040:
#line 5051 "fgl.yacc"
{print_rep_ret(0);;
    break;}
case 1041:
#line 5053 "fgl.yacc"
{ push_report_block("TRAILER",'T');;
    break;}
case 1042:
#line 5054 "fgl.yacc"
{print_rep_ret(0);;
    break;}
case 1043:
#line 5056 "fgl.yacc"
{ push_report_block("HEADER",'p');;
    break;}
case 1044:
#line 5057 "fgl.yacc"
{print_rep_ret(0);;
    break;}
case 1045:
#line 5059 "fgl.yacc"
{ push_report_block("EVERY",'E');;
    break;}
case 1046:
#line 5060 "fgl.yacc"
{print_rep_ret(0);;
    break;}
case 1047:
#line 5062 "fgl.yacc"
{ push_report_block("LAST",'L');;
    break;}
case 1048:
#line 5063 "fgl.yacc"
{print_rep_ret(0);;
    break;}
case 1049:
#line 5064 "fgl.yacc"
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
;
    break;}
case 1050:
#line 5078 "fgl.yacc"
{print_rep_ret(0);;
    break;}
case 1051:
#line 5080 "fgl.yacc"
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

;
    break;}
case 1052:
#line 5096 "fgl.yacc"
{print_rep_ret(0);;
    break;}
case 1059:
#line 5106 "fgl.yacc"
{start_state("skip",1);;
    break;}
case 1060:
#line 5106 "fgl.yacc"
{
	print_need_lines();
	start_state("skip",0);
;
    break;}
case 1061:
#line 5112 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 1062:
#line 5112 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 1063:
#line 5115 "fgl.yacc"
{start_state("KWLINE",1);;
    break;}
case 1064:
#line 5115 "fgl.yacc"
{
char buff[256];
strcpy(buff,yyvsp[0].str);
if (buff[0]=='1') {
	print_skip_lines();
} else {
	if (rep_type!=REP_TYPE_PDF) { yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(yyvsp[-2].str);
}
start_state("KWLINE",0); 
;
    break;}
case 1065:
#line 5125 "fgl.yacc"
{ print_skip_top(); ;
    break;}
case 1066:
#line 5126 "fgl.yacc"
{ print_niy("FONT SIZE"); ;
    break;}
case 1067:
#line 5127 "fgl.yacc"
{
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		;
    break;}
case 1068:
#line 5134 "fgl.yacc"
{
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		;
    break;}
case 1069:
#line 5146 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1075:
#line 5157 "fgl.yacc"
{
	print_niy("PRINT AT...");
;
    break;}
case 1076:
#line 5162 "fgl.yacc"
{
	print_report_print(0,yyvsp[0].str,0);
;
    break;}
case 1077:
#line 5166 "fgl.yacc"
{ 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1078:
#line 5171 "fgl.yacc"
{ 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 1079:
#line 5177 "fgl.yacc"
{ strcpy(yyval.str,get_default_scaling());;
    break;}
case 1080:
#line 5178 "fgl.yacc"
{ strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); ;
    break;}
case 1081:
#line 5179 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1082:
#line 5183 "fgl.yacc"
{strcpy(yyval.str,"tiff");;
    break;}
case 1083:
#line 5184 "fgl.yacc"
{strcpy(yyval.str,"gif");;
    break;}
case 1084:
#line 5185 "fgl.yacc"
{strcpy(yyval.str,"png");;
    break;}
case 1085:
#line 5186 "fgl.yacc"
{strcpy(yyval.str,"jpeg");;
    break;}
case 1086:
#line 5190 "fgl.yacc"
{
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	yyerror("Only Blobs may be printed...");
	YYERROR;
	}
;
    break;}
case 1087:
#line 5200 "fgl.yacc"
{
strcpy(yyval.str,"0");
;
    break;}
case 1088:
#line 5202 "fgl.yacc"
{
strcpy(yyval.str,"1");
;
    break;}
case 1089:
#line 5207 "fgl.yacc"
{
	print_report_print(1,0,yyvsp[0].str);
	;
    break;}
case 1090:
#line 5210 "fgl.yacc"
{
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
;
    break;}
case 1091:
#line 5215 "fgl.yacc"
{
	strcpy(yyval.str,yyvsp[0].str); 
	;
    break;}
case 1092:
#line 5222 "fgl.yacc"
{
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
;
    break;}
case 1093:
#line 5229 "fgl.yacc"
{
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
;
    break;}
case 1094:
#line 5236 "fgl.yacc"
{
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
;
    break;}
case 1095:
#line 5243 "fgl.yacc"
{
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
;
    break;}
case 1096:
#line 5250 "fgl.yacc"
{
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
;
    break;}
case 1097:
#line 5257 "fgl.yacc"
{
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
;
    break;}
case 1098:
#line 5264 "fgl.yacc"
{
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
;
    break;}
case 1103:
#line 5277 "fgl.yacc"
{rep_struct.left_margin=atoi(yyvsp[0].str);;
    break;}
case 1104:
#line 5278 "fgl.yacc"
{rep_struct.right_margin=atoi(yyvsp[0].str);;
    break;}
case 1105:
#line 5279 "fgl.yacc"
{rep_struct.top_margin=atoi(yyvsp[0].str);;
    break;}
case 1106:
#line 5280 "fgl.yacc"
{rep_struct.bottom_margin=atoi(yyvsp[0].str);;
    break;}
case 1107:
#line 5281 "fgl.yacc"
{rep_struct.page_length=atoi(yyvsp[0].str);;
    break;}
case 1108:
#line 5282 "fgl.yacc"
{ rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");;
    break;}
case 1109:
#line 5283 "fgl.yacc"
{rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);;
    break;}
case 1110:
#line 5284 "fgl.yacc"
{rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);;
    break;}
case 1111:
#line 5285 "fgl.yacc"
{rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);;
    break;}
case 1112:
#line 5286 "fgl.yacc"
{strcpy(rep_struct.top_of_page,yyvsp[0].str);;
    break;}
case 1115:
#line 5292 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));;
    break;}
case 1116:
#line 5293 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); ;
    break;}
case 1117:
#line 5294 "fgl.yacc"
{sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);;
    break;}
case 1118:
#line 5295 "fgl.yacc"
{sprintf(yyval.str,"%f",atof(yyvsp[0].str));;
    break;}
case 1123:
#line 5304 "fgl.yacc"
{pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);;
    break;}
case 1124:
#line 5305 "fgl.yacc"
{pdf_rep_struct.right_margin=atof(yyvsp[0].str);;
    break;}
case 1125:
#line 5306 "fgl.yacc"
{pdf_rep_struct.top_margin=atof(yyvsp[0].str);;
    break;}
case 1126:
#line 5307 "fgl.yacc"
{pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);;
    break;}
case 1127:
#line 5308 "fgl.yacc"
{pdf_rep_struct.page_length=atof(yyvsp[0].str);;
    break;}
case 1128:
#line 5309 "fgl.yacc"
{pdf_rep_struct.page_width=atof(yyvsp[0].str);;
    break;}
case 1129:
#line 5310 "fgl.yacc"
{strcpy(pdf_rep_struct.font_name,yyvsp[0].str);;
    break;}
case 1130:
#line 5311 "fgl.yacc"
{pdf_rep_struct.font_size=atof(yyvsp[0].str);;
    break;}
case 1131:
#line 5313 "fgl.yacc"
{pdf_rep_struct.paper_size=1;;
    break;}
case 1132:
#line 5314 "fgl.yacc"
{pdf_rep_struct.paper_size=2;;
    break;}
case 1133:
#line 5315 "fgl.yacc"
{pdf_rep_struct.paper_size=3;;
    break;}
case 1134:
#line 5316 "fgl.yacc"
{pdf_rep_struct.paper_size=5;;
    break;}
case 1135:
#line 5318 "fgl.yacc"
{pdf_rep_struct.paper_size=-1;;
    break;}
case 1136:
#line 5319 "fgl.yacc"
{pdf_rep_struct.paper_size=-2;;
    break;}
case 1137:
#line 5320 "fgl.yacc"
{pdf_rep_struct.paper_size=-3;;
    break;}
case 1138:
#line 5321 "fgl.yacc"
{pdf_rep_struct.paper_size=-5;;
    break;}
case 1142:
#line 5326 "fgl.yacc"
{pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);;
    break;}
case 1143:
#line 5327 "fgl.yacc"
{pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);;
    break;}
case 1147:
#line 5334 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
;
    break;}
case 1148:
#line 5341 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
;
    break;}
case 1149:
#line 5347 "fgl.yacc"
{
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
;
    break;}
case 1150:
#line 5357 "fgl.yacc"
{
rep_type=REP_TYPE_NORMAL;
clr_variable(); lastlineno=yylineno; init_report_structure(&rep_struct);
;
    break;}
case 1151:
#line 5362 "fgl.yacc"
{
inc_report_cnt();
sprintf(curr_func,"%s",yyvsp[-1].str);
addmap("Define Report",curr_func,"MODULE",yylineno,infilename);
set_curr_rep_name(yyvsp[-1].str);
print_report_1(yyvsp[-1].str);
push_blockcommand("REPORT");
;
    break;}
case 1152:
#line 5371 "fgl.yacc"
{
lastlineno=yylineno;
;
    break;}
case 1153:
#line 5376 "fgl.yacc"
{

print_report_2(0,yyvsp[0].str);
rordcnt=atoi(yyvsp[0].str);
;
    break;}
case 1154:
#line 5382 "fgl.yacc"
{
print_report_ctrl();
;
    break;}
case 1155:
#line 5386 "fgl.yacc"
{
pop_blockcommand("REPORT");
print_report_end() ;
;
    break;}
case 1156:
#line 5394 "fgl.yacc"
{ strcpy(yyval.str,"");
	yyval.ptr=0;
;
    break;}
case 1157:
#line 5397 "fgl.yacc"
{
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
;
    break;}
case 1158:
#line 5406 "fgl.yacc"
{
if (!in_command("REPORT")) {
	yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
;
    break;}
case 1159:
#line 5417 "fgl.yacc"
{sprintf(yyval.str,"\"\"");;
    break;}
case 1161:
#line 5424 "fgl.yacc"
{
rep_type=REP_TYPE_PDF;
clr_variable(); lastlineno=yylineno; pdf_init_report_structure(&pdf_rep_struct);
;
    break;}
case 1162:
#line 5429 "fgl.yacc"
{
inc_report_cnt();
sprintf(curr_func,"%s",yyvsp[-1].str);
addmap("Define PDF Report",curr_func,"MODULE",yylineno,infilename);
set_curr_rep_name(yyvsp[-1].str);
print_report_1(yyvsp[-1].str);
push_blockcommand("REPORT");
;
    break;}
case 1163:
#line 5438 "fgl.yacc"
{
lastlineno=yylineno;
;
    break;}
case 1164:
#line 5443 "fgl.yacc"
{
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
;
    break;}
case 1165:
#line 5449 "fgl.yacc"
{
print_report_ctrl();
;
    break;}
case 1166:
#line 5452 "fgl.yacc"
{
	pop_blockcommand("REPORT");
	print_report_end();
;
    break;}
case 1167:
#line 5458 "fgl.yacc"
{ sprintf(yyval.str,yyvsp[0].str); ;
    break;}
case 1168:
#line 5462 "fgl.yacc"
{new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		;
    break;}
case 1169:
#line 5466 "fgl.yacc"
{
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		;
    break;}
case 1170:
#line 5470 "fgl.yacc"
{
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		;
    break;}
case 1171:
#line 5474 "fgl.yacc"
{
	print_returning();
   ;
    break;}
case 1172:
#line 5480 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 1173:
#line 5481 "fgl.yacc"
{ sprintf(yyval.str,"rep.right_margin"); ;
    break;}
case 1174:
#line 5482 "fgl.yacc"
{ sprintf(yyval.str,"%s",yyvsp[0].str); ;
    break;}
case 1175:
#line 5483 "fgl.yacc"
{ sprintf(yyval.str,"%s",yyvsp[0].str); ;
    break;}
case 1176:
#line 5488 "fgl.yacc"
{
print_system_run(0,0);
;
    break;}
case 1177:
#line 5490 "fgl.yacc"
{
print_system_run(1,yyvsp[0].str);
;
    break;}
case 1178:
#line 5493 "fgl.yacc"
{
print_system_run(2,0);
;
    break;}
case 1179:
#line 5497 "fgl.yacc"
{
print_system_run(0,0);
;
    break;}
case 1180:
#line 5500 "fgl.yacc"
{
print_system_run(0,0);
/* FIXME */
;
    break;}
case 1181:
#line 5507 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);
;
    break;}
case 1182:
#line 5512 "fgl.yacc"
{sprintf(yyval.str, "%s",yyvsp[0].str);;
    break;}
case 1183:
#line 5513 "fgl.yacc"
{sprintf(yyval.str,  "%s",yyvsp[0].str);;
    break;}
case 1184:
#line 5514 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);;
    break;}
case 1185:
#line 5518 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);

;
    break;}
case 1186:
#line 5526 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1187:
#line 5527 "fgl.yacc"
{insql=1;;
    break;}
case 1188:
#line 5527 "fgl.yacc"
{insql=0;;
    break;}
case 1189:
#line 5528 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1190:
#line 5529 "fgl.yacc"
{insql=1;;
    break;}
case 1191:
#line 5529 "fgl.yacc"
{insql=0;;
    break;}
case 1192:
#line 5530 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1193:
#line 5533 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1194:
#line 5535 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);;
    break;}
case 1201:
#line 5553 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1204:
#line 5564 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1208:
#line 5581 "fgl.yacc"
{sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1214:
#line 5587 "fgl.yacc"
{ 
	print_set_conn(yyvsp[0].str);
;
    break;}
case 1215:
#line 5590 "fgl.yacc"
{
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 1216:
#line 5593 "fgl.yacc"
{
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 1217:
#line 5599 "fgl.yacc"
{strcpy(yyval.str,"\"default\"");;
    break;}
case 1219:
#line 5605 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1221:
#line 5616 "fgl.yacc"
{
		print_sleep();
	;
    break;}
case 1222:
#line 5631 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1223:
#line 5634 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1224:
#line 5635 "fgl.yacc"
{ 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1225:
#line 5641 "fgl.yacc"
{
pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1227:
#line 5650 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1229:
#line 5655 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1230:
#line 5656 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1232:
#line 5660 "fgl.yacc"
{
sprintf(yyval.str," %s , %s",yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 1234:
#line 5669 "fgl.yacc"
{
sprintf(yyval.str," %s = %s",yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 1235:
#line 5674 "fgl.yacc"
{push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 1236:
#line 5675 "fgl.yacc"
{push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1237:
#line 5678 "fgl.yacc"
{push_gen(UPDVAL,yyvsp[0].str);;
    break;}
case 1238:
#line 5679 "fgl.yacc"
{push_gen(UPDVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1242:
#line 5686 "fgl.yacc"
{
		print_sql_commit(0);
		;
    break;}
case 1243:
#line 5695 "fgl.yacc"
{ insql=1;start_bind('i',0);;
    break;}
case 1244:
#line 5696 "fgl.yacc"
{
sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1245:
#line 5701 "fgl.yacc"
{insql=1;;
    break;}
case 1246:
#line 5701 "fgl.yacc"
{
insql=0;
sprintf(yyval.str," %s %s %s %s" ,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1248:
#line 5707 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1249:
#line 5709 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1251:
#line 5716 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1253:
#line 5722 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1256:
#line 5732 "fgl.yacc"
{
      print_fetch_1();
    ;
    break;}
case 1257:
#line 5736 "fgl.yacc"
{
      print_fetch_2();
    ;
    break;}
case 1258:
#line 5740 "fgl.yacc"
{
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    ;
    break;}
case 1259:
#line 5747 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
;
    break;}
case 1260:
#line 5751 "fgl.yacc"
{sprintf(yyval.str,"%s,%d,1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
;
    break;}
case 1261:
#line 5757 "fgl.yacc"
{
debug("no into\n");
sprintf(yyval.str,"0,0");
;
    break;}
case 1262:
#line 5761 "fgl.yacc"
{
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('i',0);
;
    break;}
case 1263:
#line 5767 "fgl.yacc"
{
	int ni;
	ni=print_bind('i');
	sprintf(yyval.str,"%d,ibind",ni);
;
    break;}
case 1264:
#line 5774 "fgl.yacc"
{
debug("no into\n");
sprintf(yyval.str,"0,0");
;
    break;}
case 1265:
#line 5778 "fgl.yacc"
{
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('i',0);
;
    break;}
case 1266:
#line 5783 "fgl.yacc"
{
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
;
    break;}
case 1267:
#line 5793 "fgl.yacc"
{
sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);;
    break;}
case 1268:
#line 5796 "fgl.yacc"
{sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);;
    break;}
case 1269:
#line 5798 "fgl.yacc"
{sprintf(yyval.str,"%d,1",FETCH_RELATIVE);;
    break;}
case 1270:
#line 5800 "fgl.yacc"
{sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);;
    break;}
case 1271:
#line 5802 "fgl.yacc"
{sprintf(yyval.str,"%d,0",FETCH_RELATIVE);;
    break;}
case 1272:
#line 5804 "fgl.yacc"
{sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);;
    break;}
case 1273:
#line 5806 "fgl.yacc"
{sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);;
    break;}
case 1274:
#line 5812 "fgl.yacc"
{
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);;
    break;}
case 1275:
#line 5822 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1276:
#line 5827 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1278:
#line 5833 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1282:
#line 5842 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1285:
#line 5847 "fgl.yacc"
{
print_sql_commit(-1);
;
    break;}
case 1286:
#line 5852 "fgl.yacc"
{
		print_sql_commit(1);
	;
    break;}
case 1287:
#line 5859 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1288:
#line 5860 "fgl.yacc"
{
		strcpy(yyval.str,"EXCLUSIVE");
	;
    break;}
case 1289:
#line 5867 "fgl.yacc"
{
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
;
    break;}
case 1290:
#line 5879 "fgl.yacc"
{insql=1;;
    break;}
case 1291:
#line 5879 "fgl.yacc"
{
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 1292:
#line 5884 "fgl.yacc"
{lex_printcomment("/*  schema */\n");
	print_exec_sql(yyvsp[0].str);

sprintf(yyval.str,"Schema");
;
    break;}
case 1293:
#line 5889 "fgl.yacc"
{lex_printcomment("/*  schema  2*/\n");

	print_exec_sql(yyvsp[0].str);

sprintf(yyval.str,"Schema Element");
;
    break;}
case 1295:
#line 5896 "fgl.yacc"
{
	print_exec_sql(yyvsp[0].str);
 ;
    break;}
case 1297:
#line 5901 "fgl.yacc"
{
sprintf(yyval.str,"Set Database");
;
    break;}
case 1298:
#line 5904 "fgl.yacc"
{

lex_printcomment("/*  delete 1 */\n");

print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"Delete where current...");
;
    break;}
case 1299:
#line 5911 "fgl.yacc"
{

lex_printcomment("/*  delete 2 */\n");

print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"Delete where ...");
;
    break;}
case 1300:
#line 5918 "fgl.yacc"
{
sprintf(yyval.str,"Fetch");
lex_printcomment("/*  fetch */\n");
;
    break;}
case 1301:
#line 5922 "fgl.yacc"
{

lex_printcomment("/*  insert */\n");

print_exec_sql_bound(yyvsp[0].str);


sprintf(yyval.str,"insert");

;
    break;}
case 1303:
#line 5933 "fgl.yacc"
{
	print_do_select(yyvsp[0].str);
	sprintf(yyval.str,"select");
;
    break;}
case 1304:
#line 5937 "fgl.yacc"
{

print_exec_sql_bound(yyvsp[0].str);
sprintf(yyval.str,"update");
;
    break;}
case 1305:
#line 5946 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1306:
#line 5949 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1307:
#line 5951 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);;
    break;}
case 1308:
#line 5956 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);;
    break;}
case 1311:
#line 5963 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1315:
#line 5970 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1316:
#line 5973 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1317:
#line 5975 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1319:
#line 5981 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1321:
#line 5987 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1324:
#line 5998 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1325:
#line 6001 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1326:
#line 6003 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1328:
#line 6009 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1329:
#line 6012 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1331:
#line 6019 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1332:
#line 6025 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1333:
#line 6030 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1336:
#line 6040 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1338:
#line 6046 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1339:
#line 6052 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1340:
#line 6054 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1342:
#line 6060 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1346:
#line 6073 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1347:
#line 6075 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);;
    break;}
case 1348:
#line 6081 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1349:
#line 6084 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1351:
#line 6088 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1352:
#line 6090 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1353:
#line 6095 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);;
    break;}
case 1354:
#line 6097 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);;
    break;}
case 1356:
#line 6100 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1357:
#line 6106 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1358:
#line 6111 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);;
    break;}
case 1361:
#line 6121 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1364:
#line 6136 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1365:
#line 6142 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1368:
#line 6152 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1369:
#line 6157 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1371:
#line 6163 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1372:
#line 6167 "fgl.yacc"
{sprintf(yyval.str," %s ", yyvsp[0].str);;
    break;}
case 1373:
#line 6168 "fgl.yacc"
{sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1374:
#line 6169 "fgl.yacc"
{sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);;
    break;}
case 1376:
#line 6173 "fgl.yacc"
{sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1378:
#line 6178 "fgl.yacc"
{ sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  ;
    break;}
case 1379:
#line 6186 "fgl.yacc"
{
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1380:
#line 6193 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1382:
#line 6197 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1384:
#line 6201 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1387:
#line 6209 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1389:
#line 6215 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1391:
#line 6221 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1393:
#line 6227 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1394:
#line 6232 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1395:
#line 6233 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1396:
#line 6239 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1397:
#line 6241 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1398:
#line 6245 "fgl.yacc"
{strcpy(yyval.str," ALL ");;
    break;}
case 1404:
#line 6264 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1407:
#line 6278 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1408:
#line 6280 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1409:
#line 6282 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1410:
#line 6284 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1412:
#line 6291 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1413:
#line 6294 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1415:
#line 6301 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1416:
#line 6303 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1417:
#line 6305 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1418:
#line 6307 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1419:
#line 6309 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1420:
#line 6311 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1429:
#line 6324 "fgl.yacc"
{sprintf(yyval.str,"<=");;
    break;}
case 1430:
#line 6325 "fgl.yacc"
{sprintf(yyval.str,">=");;
    break;}
case 1435:
#line 6335 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1443:
#line 6355 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1444:
#line 6360 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1447:
#line 6364 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1451:
#line 6369 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1453:
#line 6372 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1455:
#line 6375 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1459:
#line 6380 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1460:
#line 6382 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1461:
#line 6385 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1463:
#line 6391 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1467:
#line 6396 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);;
    break;}
case 1471:
#line 6412 "fgl.yacc"
{
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	;
    break;}
case 1472:
#line 6416 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);
addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename);
;
    break;}
case 1473:
#line 6419 "fgl.yacc"
{ sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); ;
    break;}
case 1474:
#line 6420 "fgl.yacc"
{ sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); ;
    break;}
case 1477:
#line 6431 "fgl.yacc"
{sprintf(yyval.str,yyvsp[0].str);;
    break;}
case 1478:
#line 6435 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1479:
#line 6436 "fgl.yacc"
{sprintf(yyval.str,"[%s]",yyvsp[-1].str);;
    break;}
case 1480:
#line 6437 "fgl.yacc"
{sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);;
    break;}
case 1481:
#line 6441 "fgl.yacc"
{ 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1482:
#line 6446 "fgl.yacc"
{
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
;
    break;}
case 1483:
#line 6451 "fgl.yacc"
{
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
;
    break;}
case 1485:
#line 6464 "fgl.yacc"
{sprintf(yyval.str,convstrsql(yyvsp[0].str));;
    break;}
case 1489:
#line 6469 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1490:
#line 6471 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1491:
#line 6473 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1492:
#line 6475 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1494:
#line 6480 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 1495:
#line 6483 "fgl.yacc"
{sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1496:
#line 6486 "fgl.yacc"
{strcpy(yyval.str," YEAR TO SECOND ");;
    break;}
case 1497:
#line 6488 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1498:
#line 6491 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1499:
#line 6493 "fgl.yacc"
{sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1500:
#line 6496 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 1501:
#line 6496 "fgl.yacc"
{strcpy(yyval.str,"5");;
    break;}
case 1502:
#line 6496 "fgl.yacc"
{strcpy(yyval.str,"8");;
    break;}
case 1503:
#line 6496 "fgl.yacc"
{strcpy(yyval.str,"11");;
    break;}
case 1504:
#line 6496 "fgl.yacc"
{strcpy(yyval.str,"14");;
    break;}
case 1505:
#line 6496 "fgl.yacc"
{strcpy(yyval.str,"17");;
    break;}
case 1506:
#line 6496 "fgl.yacc"
{strcpy(yyval.str,"23");;
    break;}
case 1507:
#line 6497 "fgl.yacc"
{strcpy(yyval.str,"4");;
    break;}
case 1508:
#line 6497 "fgl.yacc"
{strcpy(yyval.str,"7");;
    break;}
case 1509:
#line 6497 "fgl.yacc"
{strcpy(yyval.str,"10");;
    break;}
case 1510:
#line 6497 "fgl.yacc"
{strcpy(yyval.str,"13");;
    break;}
case 1511:
#line 6497 "fgl.yacc"
{strcpy(yyval.str,"16");;
    break;}
case 1512:
#line 6497 "fgl.yacc"
{strcpy(yyval.str,"19");;
    break;}
case 1513:
#line 6497 "fgl.yacc"
{strcpy(yyval.str,"25");;
    break;}
case 1528:
#line 6503 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 1529:
#line 6504 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 1530:
#line 6508 "fgl.yacc"
{
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		;
    break;}
case 1531:
#line 6517 "fgl.yacc"
{insql=0;chk4var=0;;
    break;}
case 1532:
#line 6517 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-5].str,0,0);
addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-7].str);
;
    break;}
case 1533:
#line 6522 "fgl.yacc"
{insql=0;chk4var=0;;
    break;}
case 1534:
#line 6522 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,2,0); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
;
    break;}
case 1535:
#line 6528 "fgl.yacc"
{insql=0;chk4var=0;;
    break;}
case 1536:
#line 6529 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-4].str,0,1); 
addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-6].str);
;
    break;}
case 1537:
#line 6534 "fgl.yacc"
{insql=0;chk4var=0;;
    break;}
case 1538:
#line 6535 "fgl.yacc"
{
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,0,1); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
;
    break;}
case 1539:
#line 6544 "fgl.yacc"
{strcpy(yyval.str,"0");;
    break;}
case 1540:
#line 6545 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 1541:
#line 6546 "fgl.yacc"
{strcpy(yyval.str,"1");;
    break;}
case 1545:
#line 6553 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1546:
#line 6554 "fgl.yacc"
{sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1548:
#line 6560 "fgl.yacc"
{ 
		strcpy(yyval.str,print_curr_spec(1,yyvsp[0].str));
	;
    break;}
case 1549:
#line 6566 "fgl.yacc"
{
		strcpy(yyval.str,print_curr_spec(2,yyvsp[0].str));
;
    break;}
case 1551:
#line 6575 "fgl.yacc"
{
	sprintf(yyval.str,"%s",yyvsp[-1].str);
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}

	;
    break;}
case 1552:
#line 6585 "fgl.yacc"
{debug("Got select list...\n");;
    break;}
case 1553:
#line 6587 "fgl.yacc"
{
			/* start_bind('i',0,-1); */
            start_bind('i',0);
			lex_printcomment("/* startbind */");
		;
    break;}
case 1554:
#line 6593 "fgl.yacc"
{
             char buff[1024];
             sprintf(buff,"%s %s %s %s %s %s", yyvsp[-7].str, yyvsp[-6].str, yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str,yyvsp[0].str);
	    strcpy(yyval.str,print_select_all(buff));

;
    break;}
case 1555:
#line 6603 "fgl.yacc"
{
             char buff[1024];

             sprintf(buff,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
             sprintf(yyval.str,"push_char(\"%s\");",buff);
;
    break;}
case 1558:
#line 6619 "fgl.yacc"
{sprintf(yyval.str,"%s %s %s %s %s %s %s", yyvsp[-6].str, yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);;
    break;}
case 1559:
#line 6623 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1560:
#line 6624 "fgl.yacc"
{
       lex_printcomment("/* UNION */");
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       ;
    break;}
case 1562:
#line 6629 "fgl.yacc"
{
       sprintf(yyval.str,"%s %s %s ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1564:
#line 6637 "fgl.yacc"
{ start_bind('o',0);strcpy(yyval.str,""); ;
    break;}
case 1565:
#line 6638 "fgl.yacc"
{ strcpy(yyval.str,""); ;
    break;}
case 1566:
#line 6645 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1567:
#line 6650 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str);;
    break;}
case 1568:
#line 6653 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1569:
#line 6654 "fgl.yacc"
{sprintf(yyval.str,"ALL");;
    break;}
case 1570:
#line 6655 "fgl.yacc"
{sprintf(yyval.str,"DISTINCT");;
    break;}
case 1571:
#line 6656 "fgl.yacc"
{sprintf(yyval.str,"DISTINCT");;
    break;}
case 1573:
#line 6661 "fgl.yacc"
{ sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1575:
#line 6665 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1577:
#line 6675 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1578:
#line 6677 "fgl.yacc"
{sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1579:
#line 6679 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1580:
#line 6681 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1581:
#line 6683 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1587:
#line 6689 "fgl.yacc"
{sprintf(yyval.str," %s ",yyvsp[0].str);;
    break;}
case 1588:
#line 6691 "fgl.yacc"
{sprintf(yyval.str," %s",yyvsp[0].str);;
    break;}
case 1589:
#line 6693 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1590:
#line 6695 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1591:
#line 6697 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1592:
#line 6699 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1593:
#line 6701 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1594:
#line 6703 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1595:
#line 6705 "fgl.yacc"
{sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1596:
#line 6706 "fgl.yacc"
{sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);;
    break;}
case 1601:
#line 6716 "fgl.yacc"
{

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
;
    break;}
case 1602:
#line 6724 "fgl.yacc"
{
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
;
    break;}
case 1603:
#line 6729 "fgl.yacc"
{strcpy(yyval.str,"\"|\"");;
    break;}
case 1604:
#line 6729 "fgl.yacc"
{
strcpy(yyval.str,yyvsp[0].str);
;
    break;}
case 1606:
#line 6733 "fgl.yacc"
{
if ((scan_variable(yyvsp[0].str)&15)!=0) {yyerror("Variable must be of type char for a delimiter..");YYERROR;}
;
    break;}
case 1607:
#line 6738 "fgl.yacc"
{sprintf(yyval.str,"0");;
    break;}
case 1608:
#line 6738 "fgl.yacc"
{
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
;
    break;}
case 1610:
#line 6742 "fgl.yacc"
{
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
;
    break;}
case 1611:
#line 6746 "fgl.yacc"
{
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
;
    break;}
case 1614:
#line 6755 "fgl.yacc"
{strcpy(yyval.str,"");;
    break;}
case 1615:
#line 6755 "fgl.yacc"
{
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
;
    break;}
case 1620:
#line 6774 "fgl.yacc"
{ sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); ;
    break;}
case 1621:
#line 6775 "fgl.yacc"
{ sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); ;
    break;}
case 1624:
#line 6783 "fgl.yacc"
{
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	;
    break;}
case 1625:
#line 6789 "fgl.yacc"
{
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		;
    break;}
case 1628:
#line 6808 "fgl.yacc"
{sprintf(yyval.str,"UNITS YEAR");;
    break;}
case 1629:
#line 6809 "fgl.yacc"
{sprintf(yyval.str,"UNITS MONTH"); ;
    break;}
case 1630:
#line 6810 "fgl.yacc"
{sprintf(yyval.str,"UNITS DAY);"); ;
    break;}
case 1631:
#line 6811 "fgl.yacc"
{sprintf(yyval.str,"UNITS HOUR);"); ;
    break;}
case 1632:
#line 6812 "fgl.yacc"
{sprintf(yyval.str,"UNITS MINUTE);"); ;
    break;}
case 1633:
#line 6813 "fgl.yacc"
{sprintf(yyval.str,"UNITS SECOND);"); ;
    break;}
case 1634:
#line 6899 "fgl.yacc"
{
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
	fflush(stdout);
;
    break;}
case 1635:
#line 6911 "fgl.yacc"
{strcpy(yyval.str,yyvsp[0].str);;
    break;}
case 1639:
#line 6917 "fgl.yacc"
{sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1640:
#line 6918 "fgl.yacc"
{sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1644:
#line 6928 "fgl.yacc"
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
;
    break;}
case 1645:
#line 6949 "fgl.yacc"
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
;
    break;}
case 1646:
#line 7034 "fgl.yacc"
{set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);;
    break;}
case 1647:
#line 7036 "fgl.yacc"
{set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);;
    break;}
case 1648:
#line 7038 "fgl.yacc"
{set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);;
    break;}
case 1649:
#line 7039 "fgl.yacc"
{
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
;
    break;}
case 1650:
#line 7044 "fgl.yacc"
{
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
;
    break;}
case 1651:
#line 7049 "fgl.yacc"
{set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);;
    break;}
case 1652:
#line 7051 "fgl.yacc"
{set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);;
    break;}
case 1653:
#line 7053 "fgl.yacc"
{set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);;
    break;}
case 1654:
#line 7055 "fgl.yacc"
{set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);;
    break;}
case 1655:
#line 7058 "fgl.yacc"
{
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); ;
    break;}
case 1656:
#line 7062 "fgl.yacc"
{
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 ;
    break;}
case 1657:
#line 7067 "fgl.yacc"
{
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
;
    break;}
case 1658:
#line 7072 "fgl.yacc"
{ set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
;
    break;}
case 1659:
#line 7076 "fgl.yacc"
{
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
;
    break;}
case 1661:
#line 7086 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);;
    break;}
case 1663:
#line 7101 "fgl.yacc"
{
print_while_1();
push_blockcommand("WHILE");
;
    break;}
case 1664:
#line 7104 "fgl.yacc"
{
print_while_2();
;
    break;}
case 1665:
#line 7108 "fgl.yacc"
{
print_while_3();
pop_blockcommand("WHILE");
;
    break;}
case 1668:
#line 7127 "fgl.yacc"
{
strcpy(yyval.str,"0");
;
    break;}
case 1669:
#line 7130 "fgl.yacc"
{
strcpy(yyval.str,"1"); 
;
    break;}
case 1670:
#line 7136 "fgl.yacc"
{ 
print_clr_window("\"screen\"");
;
    break;}
case 1671:
#line 7139 "fgl.yacc"
{ print_clr_window(yyvsp[0].str); ;
    break;}
case 1672:
#line 7140 "fgl.yacc"
{ print_clr_window(yyvsp[0].str); ;
    break;}
case 1673:
#line 7141 "fgl.yacc"
{
	print_clr_form(0,0,yyvsp[0].str);
;
    break;}
case 1674:
#line 7144 "fgl.yacc"
{
	print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1675:
#line 7147 "fgl.yacc"
{
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
;
    break;}
case 1676:
#line 7152 "fgl.yacc"
{sprintf(yyval.str,"%s",yyvsp[0].str);;
    break;}
case 1677:
#line 7153 "fgl.yacc"
{sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);;
    break;}
case 1678:
#line 7157 "fgl.yacc"
{
	print_current_window("\"screen\"");
;
    break;}
case 1679:
#line 7161 "fgl.yacc"
{
	print_current_window(yyvsp[0].str);
;
    break;}
case 1680:
#line 7165 "fgl.yacc"
{
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
;
    break;}
case 1681:
#line 7169 "fgl.yacc"
{
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
;
    break;}
case 1682:
#line 7174 "fgl.yacc"
{
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
;
    break;}
case 1683:
#line 7178 "fgl.yacc"
{
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
;
    break;}
case 1684:
#line 7183 "fgl.yacc"
{

print_def_mn_file();

;
    break;}
case 1686:
#line 7191 "fgl.yacc"
{addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); ;
    break;}
case 1688:
#line 7197 "fgl.yacc"
{
	print_hide_window(yyvsp[0].str);
;
    break;}
case 1689:
#line 7203 "fgl.yacc"
{
print_move_window(yyvsp[-4].str,0);
;
    break;}
case 1690:
#line 7207 "fgl.yacc"
{
print_move_window(yyvsp[-4].str,1);
;
    break;}
case 1695:
#line 7225 "fgl.yacc"
{
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
;
    break;}
case 1696:
#line 7232 "fgl.yacc"
{
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
;
    break;}
case 1697:
#line 7241 "fgl.yacc"
{print_cmd_start();;
    break;}
case 1698:
#line 7241 "fgl.yacc"
{print_cmd_end();;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/lib/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

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

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 7333 "fgl.yacc"

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


