/**
 * @file
 *
 * Informix 4gl grammar in bison format.
 * This grammar is based in the Aubit 4gl grammar that works ok 
 * with a lot of 4gl code.
 *
 * The first goal with this grammar is put it working without C code
 * in order to implement the loading of a 4gl object model.
 *
 */


%{

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

/** Line number in the 4gl source file */
extern int 	lineno; 

/** @todo : check if i can live without this */
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

%}
/** The prefix used when generating the C code. */
%name-prefix="a4gl_yy"
%pure_parser
//glr-parser
%start module
%union	  {



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
	}

/* ============================== 1.reqd ============================ */

%token <str> NAME
%left UMINUS
%left COMMA
%left KW_OR         
%left KW_AND        
%left KW_USING 
%left NOT
%left MATCHES     
%left POWER
%left LESS_THAN 
%left GREATER_THAN 
%left EQUAL 
%left GREATER_THAN_EQ 
%left LESS_THAN_EQ 
%left NOT_EQUAL
%left MINUS PLUS
%left DIVIDE MULTIPLY
%left MOD
%right COMMAND

%token NUMBER_VALUE
%token CHAR_VALUE
%token INT_VALUE
%token NAMED_GEN
/* %token COMMENT */
%token CLINE
%token SQLLINE
%token KW_CSTART
%token KW_CEND
%token USER_DTYPE
%token SQL_TEXT

/** @todo : Why are the tokens numbered ? If not necessary remove it */
%token DYNAMIC_ARRAY 1000
%token RESIZE_ARRAY 1001
%token ALLOCATE_ARRAY 1002
%token DEALLOCATE_ARRAY 1003
%token BEFORE_INSERT 1004
%token CONCAT_PIPES 1005
%token BEFORE_DELETE 1006
%token AFTER_INSERT 1007
%token AFTER_DELETE 1008
%token EXECUTE_IMMEDIATE 1009
%token DELETE_ROW_EQUAL_TRUE 1010
%token INSERT_ROW_EQUAL_TRUE 1011
%token DELETE_ROW_EQUAL_FALSE 1012
%token INSERT_ROW_EQUAL_FALSE 1013
%token CURRENT_ROW_DISPLAY_EQUAL 1014
%token MAXCOUNT 1015
%token ALTER_TABLE 1016
%token WHENEVER_ERROR_CONTINUE 1017
%token WHENEVER_WARNING_CONTINUE 1018
%token XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1019
%token XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1020
%token XSET_ident_DOT_MULTIPLY_EQUAL 1021
%token XSET_MULTIPLY_EQUAL 1022
%token XSET_OPEN_BRACKET 1023
%token NEWFORMATSHARED 1024
%token CREATE_DATABASE 1025
%token IMPORT_LEGACY_FUNCTION 1026
%token ADD_CONSTRAINT 1027
%token DROP_CONSTRAINT 1028
%token AS_STATIC 1029
%token NOT_FIELD_TOUCHED 1030
%token LOCAL_FUNCTION 1031
%token EVERY_ROW 1032
%token ELIF 1033
%token DOUBLE_PRECISION 1034
%token COUNT_MULTIPLY 1035
%token WAIT_FOR_KEY 1036
%token AT_TERMINATION_CALL 1037
%token TERMINATE_REPORT 1038
%token TO_MAIN_CAPTION 1039
%token CLEARSTAT 1040
%token TO_MENUITEM 1041
%token ID_TO_INT 1042
%token TO_STATUSBOX 1043
%token ASCII_HEIGHT_ALL 1044
%token ASCII_WIDTH_ALL 1045
%token IMPORT_DATATYPE 1046
%token PAGE_TRAILER_SIZE 1047
%token PAGE_HEADER_SIZE 1048
%token FIRST_PAGE_HEADER_SIZE 1049
%token BYTES_USE_AS_IMAGE 1050
%token BYTES_USE_AS_ASCII 1051
%token KWUP_BY 1052
%token KWDOWN_BY 1053
%token CLOSE_STATUSBOX 1054
%token MODIFY_NEXT_SIZE 1055
%token LOCK_MODE_PAGE 1056
%token LOCK_MODE_ROW 1057
%token TO_PIPE 1058
%token TO_PRINTER 1059
%token STATUSBOX 1060
%token CONNECT_TO 1061
%token FORMHANDLER_INPUT 1062
%token UNITS_YEAR 1063
%token UNITS_MONTH 1064
%token UNITS_DAY 1065
%token UNITS_HOUR 1066
%token UNITS_MINUTE 1067
%token UNITS_SECOND 1068
%token NO_NEW_LINES 1069
%token FIELDTOWIDGET 1070
%token WITH_HOLD 1071
%token SHOW_MENU 1072
%token CWIS 1073
%token CREATE_IDX 1074
%token FORM_IS_COMPILED 1075
%token PDF_REPORT 1076
%token IMPORT_FUNCTION 1077
%token PROMPT_MANY 1078
%token POINTS 1079
%token MM 1080
%token INCHES 1081
%token PREPEND 1082
%token MEMBER_OF 1083
%token MEMBER_FUNCTION 1084
%token APPEND 1085
%token TEMPLATE 1086
%token END_TEMPLATE 1087
%token SQLSICS 1088
%token CREATE_SCHEMA 1089
%token SQLSIRR 1090
%token UPDATESTATS_T 1091
%token SQLSICR 1092
%token WHENEVER_SQLSUCCESS 1093
%token WHENEVER_SQLWARNING 1094
%token START_EXTERN 1095
%token WHENEVER_ANY_ERROR 1096
%token WHENEVER_NOT_FOUND 1097
%token CONTINUE_CONSTRUCT 1098
%token FOUNCONSTR 1099
%token SQLSIDR 1100
%token WHENEVER_SQLERROR 1101
%token CREATE_TEMP_TABLE 1102
%token CURRENT_WINDOW_IS 1103
%token FIRST_PAGE_HEADER 1104
%token ORDER_EXTERNAL_BY 1105
%token SCROLL_CURSOR_FOR 1106
%token SCROLL_CURSOR 1107
%token SQL_INTERRUPT_OFF 1108
%token STOP_ALL_EXTERNAL 1109
%token WITH_CHECK_OPTION 1110
%token WITH_GRANT_OPTION 1111
%token SQLSLMNW 1112
%token ADDCONSTUNIQ 1113
%token CONTINUE_DISPLAY 1114
%token CONTINUE_FOREACH 1115
%token OUTPUT_TO_REPORT 1116
%token SQL_INTERRUPT_ON 1117
%token WHENEVER_SUCCESS 1118
%token WHENEVER_WARNING 1119
%token WHERE_CURRENT_OF 1120
%token WITHOUT_DEFAULTS 1121
%token FOCONSTR 1122
%token SCALED_BY 1123
%token CONTINUE_PROMPT 1124
%token PDF_FUNCTION 1125
%token DEFER_INTERRUPT 1126
%token DISPLAY_BY_NAME 1127
%token NOT_NULL_UNIQUE 1128
%token SKIP_TO_TOP 1129
%token TOP_OF_PAGE 1130
%token SKIP_TO 1131
%token SKIP_BY 1132
%token WITHOUT_WAITING 1133
%token BEFCONSTRUCT 1134
%token SQLSLMW 1135
%token WHENEVER_ERROR 1136
%token AFTCONSTRUCT 1137
%token ALL_PRIVILEGES 1138
%token CLOSE_DATABASE 1139
%token CONTINUE_INPUT 1140
%token CONTINUE_WHILE 1141
%token CREATE_SYNONYM 1142
%token DROP_TABLE 1143
%token EXIT_CONSTRUCT 1144
%token INEXCLUSIVE 1145
%token REPORT_TO_PRINTER 1146
%token REPORT_TO_PIPE 1147
%token RETURN 1148
%token SET_SESSION_TO 1149
%token UPDATESTATS 1150
%token WITHOUT_HEAD 1151
%token CLEARSCR 1152
%token WITH_B_LOG 1153
%token AUTHORIZATION 1154
%token BOTTOM_MARGIN 1155
%token CLOSE_SESSION 1156
%token CONTINUE_CASE 1157
%token CONTINUE_MENU 1158
%token DISPLAY_ARRAY 1159
%token END_SQL 1160
%token DOLLAR 1161
%token END_CONSTRUCT 1162
%token FIELD_TOUCHED 1163
%token FINISH_REPORT 1164
%token INFACC 1165
%token INPUT_NO_WRAP 1166
%token LOCKMODEPAGE 1167
%token SETPMOFF 1168
%token UNCONSTRAINED 1169
%token PAGE_TRAILER 1170
%token SETPMON 1171
%token BEFGROUP 1172
%token CLOSE_WINDOW 1173
%token COMMENT_LINE 1174
%token CONTINUE_FOR 1175
%token CREATE_DB 1176
%token CREATE_TABLE 1177
%token DEFAULT_NULL 1178
%token DELETE_USING 1179
%token DISPLAY_FORM 1180
%token END_FUNCTION 1181
%token EXIT_DISPLAY 1182
%token EXIT_FOREACH 1183
%token EXIT_PROGRAM 1184
%token INFCOLS 1185
%token LOCKMODEROW 1186
%token ON_EVERY_ROW 1187
%token OPEN_SESSION 1188
%token RIGHT_MARGIN 1189
%token SELECT_USING 1190
%token START_REPORT 1191
%token UNLOCK_TABLE 1192
%token UPDATE_USING 1193
%token ACL_BUILTIN 1194
%token AFTGROUP 1195
%token INFIDX 1196
%token INFSTAT 1197
%token LEFT_MARGIN 1198
%token PAGE_HEADER 1199
%token ROLLBACK_W 1200
%token SET_SESSION 1201
%token SQLSEOFF 1202
%token WITH_A_LOG 1203
%token BEFDISP 1204
%token BEFORE_MENU 1205
%token CREATE_VIEW 1206
%token DEFINE_TYPE 1207
%token DELETE_FROM 1208
%token END_DISPLAY 1209
%token END_REPORT 1210
%token END_FOREACH 1211
%token END_FOR 1212
%token END_GLOBALS 1213
%token EXIT_PROMPT 1214
%token EXTENT_SIZE 1215
%token FOREIGN_KEY 1216
%token HIDE_OPTION 1217
%token HIDE_WINDOW 1218
%token INSERT_INTO 1219
%token IS_NOT_NULL 1220
%token MOVE_WINDOW 1221
%token NEXT_OPTION 1222
%token NOT_MATCHES 1223
%token ON_LAST_ROW 1224
%token OPEN_WINDOW 1225
%token OPEN_STATUSBOX 1226
%token PAGE_LENGTH 1227
%token PAGE_WIDTH 1228
%token PRIMARY_KEY 1229
%token PROMPT_LINE 1230
%token RECORD_LIKE 1231
%token ROLLFORWARD 1232
%token SETBL 1233
%token SHOW_OPTION 1234
%token SHOW_WINDOW 1235
%token SQLSEON 1236
%token TO_DATABASE 1237
%token USE_SESSION 1238
%token WITH_NO_LOG 1239
%token AFTDISP 1240
%token BEFFIELD 1241
%token INSHARE 1242
%token UNLOCKTAB 1243
%token AFTFIELD 1244
%token ATTRIBUTES 1245
%token BEFINP 1246
%token BEGIN_WORK 1247
%token CLEARWIN 1248
%token CLOSE_FORM 1249
%token DEFER_QUIT 1250
%token DESCENDING 1251
%token DROP_INDEX 1252
%token END_PROMPT 1253
%token END_RECORD 1254
%token ERROR_LINE 1255
%token EXIT_INPUT 1256
%token EXIT_WHILE 1257
%token FOR_UPDATE_OF 1258
%token FOR_UPDATE 1259
%token GET_FLDBUF 1260
%token INITIALIZE 1261
%token INPUT_WRAP 1262
%token LOCK_TABLE 1263
%token MSG_LINE 1264
%token NOT_EXISTS 1265
%token ON_ANY_KEY 1266
%token REFERENCES 1267
%token RENCOL 1268
%token SET_CURSOR 1269
%token SMALLFLOAT 1270
%token SQLSUCCESS 1271
%token TOP_MARGIN 1272
%token WITH_ARRAY 1273
%token ACCEPTKEY 1274
%token ACCEPT 1275
%token AFTINP 1276
%token CLEARFORMTODEFAULTS 1277
%token CLEARFORM 1278
%token CLEAR_X_FORM 1279
%token COMMIT_W 1280
%token NEXTPAGE 1281
%token PREVPAGE 1282
%token CTRL_KEY 1283
%token INFTABS 1284
%token NEXTFIELD 1285
%token NEXTFORM 1286
%token RENTAB 1287
%token ASCENDING 1288
%token ASSOCIATE 1289
%token CHARACTER 1290
%token CONSTRUCT 1291
%token DELIMITER 1292
%token DOWNSHIFT 1293
%token DROP_VIEW 1294
%token END_INPUT 1295
%token END_WHILE 1296
%token EXCLUSIVE 1297
%token EXIT_CASE 1298
%token EXIT_MENU 1299
%token FORM_LINE 1300
%token GREATER_THAN_EQ 1301
%token INTERRUPT 1302
%token INTO_TEMP 1303
%token INVISIBLE 1304
%token IN_MEMORY 1305
%token LINKED_TO 1306
%token LOAD_FROM 1307
%token LOCKTAB 1308
%token MENU_LINE 1309
%token OPEN_FORM 1310
%token OTHERWISE 1311
%token PRECISION 1312
%token PRIOR 1313
%token PROCEDURE 1314
%token REPORT_TO 1315
%token RETURNING 1316
%token UNDERLINE 1317
%token UNLOAD_TO 1318
%token BEFROW 1319
%token UNLOAD_T 1320
%token VARIABLE 1321
%token ABSOLUTE 1322
%token AFTROW 1323
%token BUFFERED 1324
%token CONSTANT 1325
%token CONST 1326
%token CONTINUE 1327
%token DATABASE 1328
%token DATETIME 1329
%token DEFAULTS 1330
%token DISTINCT 1331
%token END_CASE 1332
%token END_MAIN 1333
%token END_MENU 1334
%token END_TYPE 1335
%token EXIT_FOR 1336
%token EXTERNAL 1337
%token FRACTION 1338
%token FUNCTION 1339
%token GROUP_BY 1340
%token INTERVAL 1341
%token KWMESSAGE 1342
%token NOT_LIKE 1343
%token NOT_ILIKE 1344
%token NOT_NULL 1345
%token PASSWORD 1346
%token PREVIOUS 1347
%token READONLY 1348
%token REGISTER 1349
%token RELATIVE 1350
%token RESOURCE 1351
%token SMALLINT 1352
%token VALIDATE 1353
%token WHENEVER 1354
%token WITH_LOG 1355
%token WORDWRAP 1356
%token BY_NAME 1357
%token IN_FILE 1358
%token IS_NULL 1359
%token LESS_THAN_EQ 1360
%token AVERAGE 1361
%token BETWEEN 1362
%token CAPTION 1363
%token CLIPPED 1364
%token CLOSE_BRACKET 1365
%token COLUMNS 1366
%token COMMAND 1367
%token COMMENT 1368
%token CONNECT 1369
%token CURRENT 1370
%token DBYNAME 1371
%token DECIMAL 1372
%token DECLARE 1373
%token DEFAULT 1374
%token DISPLAY 1375
%token ENDCODE 1376
%token EXECUTE 1377
%token FOREACH 1378
%token FOREIGN 1379
%token GLOBALS 1380
%token INFIELD 1381
%token INTEGER 1382
%token KWWINDOW 1383
%token MAGENTA 1384
%token MATCHES 1385
%token NUMERIC 1386
%token OPTIONS 1387
%token PERCENT 1388
%token PREPARE 1389
%token PROGRAM 1390
%token RECOVER 1391
%token REVERSE 1392
%token SECTION 1393
%token SESSION 1394
%token SYNONYM 1395
%token THRU 1396
%token TRAILER 1397
%token UPSHIFT 1398
%token VARCHAR 1399
%token WAITING 1400
%token CLOSE_SHEV 1401
%token CLOSE_SQUARE 1402
%token GREATER_THAN 1403
%token KW_FALSE 1404
%token NOT_IN 1405
%token ONKEY 1406
%token OPEN_BRACKET 1407
%token BORDER 1408
%token BOTTOM 1409
%token COLUMN 1410
%token COMMIT 1411
%token CREATE 1412
%token CURSOR 1413
%token DEFINE 1414
%token DELETE 1415
%token DOUBLE 1416
%token END_IF 1417
%token ESCAPE 1418
%token EXISTS 1419
%token EXTEND 1420
%token EXTENT 1421
%token FINISH 1422
%token FORMAT 1423
%token HAVING 1424
%token HEADER 1425
%token INSERT 1426
%token LOCATE 1427
%token MARGIN 1428
%token MEMORY 1429
%token MINUTE 1430
%token MODIFY 1431
%token NORMAL 1432
%token EQUAL_EQUAL 1433
%token NOT_EQUAL 1434
%token OPEN_SHEV 1435
%token OPEN_SQUARE 1436
%token OPTION 1437
%token OUTPUT 1438
%token PROMPT 1439
%token PUBLIC 1440
%token RECORD 1441
%token REPORT 1442
%token REVOKE 1443
%token SCHEMA 1444
%token SCROLL_USING 1445
%token SCROLL 1446
%token SECOND 1447
%token SELECT 1448
%token SERIAL 1449
%token SETL 1450
%token SHARED 1451
%token SPACES 1452
%token UNIQUE 1453
%token UNLOCK 1454
%token UPDATE 1455
%token VALUES 1456
%token YELLOW 1457
%token AFTER 1458
%token KWLINE 1459
%token KW_NULL 1460
%token KW_TRUE 1461
%token SINGLE_KEY 1462
%token ALTER 1463
%token ARRAY 1464
%token ASCII 1465
%token AUDIT 1466
%token BLACK 1467
%token BLINK 1468
%token CHECK 1469
%token CLEAR 1470
%token CLOSE 1471
%token CODE_C 1472
%token COUNT 1473
%token DEFER 1474
%token ERROR 1475
%token EVERY 1476
%token FETCH 1477
%token FIRST 1478
%token FLOAT 1479
%token FLUSH 1480
%token FOUND 1481
%token GRANT 1482
%token GREEN 1483
%token GROUP 1484
%token INDEX 1485
%token KWFORM 1486
%token LABEL 1487
%token LESS_THAN 1488
%token LOCAL 1489
%token MONEY 1490
%token MONTH 1491
%token POWER 1492
%token MULTIPLY 1493
%token ORDER 1494
%token OUTER 1495
%token PAUSE 1496
%token PRINT_IMAGE 1497
%token PRINT_FILE 1498
%token PRINT 1499
%token RIGHT 1500
%token DOUBLE_COLON 1501
%token SEMICOLON 1502
%token SLEEP 1503
%token TUPLE 1504
%token UNION 1505
%token KW_USING 1506
%token WHERE 1507
%token WHILE 1508
%token WHITE 1509
%token CCODE 1510
%token ANSI 1511
%token BLUE 1512
%token BOLD 1513
%token BYTE 1514
%token FCALL 1515
%token CASE 1516
%token CHAR 1517
%token CYAN 1518
%token DATE 1519
%token DESC 1520
%token DIVIDE 1521
%token KWDOWN 1522
%token TAB 1523
%token DROP 1524
%token ELSE 1525
%token EXEC 1526
%token EXIT 1527
%token FREE 1528
%token FROM 1529
%token GOTO 1530
%token HELP_FILE 1531
%token LANG_FILE 1532
%token HELP 1533
%token HIDE 1534
%token HOUR 1535
%token INTO 1536
%token LAST 1537
%token LEFT 1538
%token LIKE 1539
%token MAIN 1540
%token MENU 1541
%token MODE 1542
%token NEED 1543
%token NEXT 1544
%token NOCR 1545
%token OPEN 1546
%token QUIT 1547
%token REAL 1548
%token ROWS 1549
%token SHOW 1550
%token SIZE 1551
%token SKIP 1552
%token SOME 1553
%token STEP 1554
%token STOP 1555
%token TEMP 1556
%token TEXT 1557
%token THEN 1558
%token USER 1559
%token WAIT 1560
%token WHEN 1561
%token WITH 1562
%token WORK 1563
%token YEAR 1564
%token EQUAL 1565
%token KW_IS 1566
%token XSET 1567
%token ADD 1568
%token ALL 1569
%token KW_AND 1570
%token ANY 1571
%token ASC 1572
%token AVG 1573
%token COLON 1574
%token COMMA 1575
%token DAY 1576
%token DBA 1577
%token DEC 1578
%token DIM 1579
%token FKEY 1580
%token FOR 1581
%token KEY 1582
%token KWNO 1583
%token LET 1584
%token LOG 1585
%token XMAX 1586
%token XMIN 1587
%token MINUS 1588
%token MOD 1589
%token NOT 1590
%token PAD 1591
%token PUT 1592
%token RED 1593
%token ROW 1594
%token RUN 1595
%token SQL 1596
%token SUM 1597
%token TOP 1598
%token USE 1599
%token ATSIGN 1600
%token PLUS 1601
%token AS_TIFF 1602
%token AS_GIF 1603
%token AS_PNG 1604
%token AS_JPEG 1605
%token AS 1606
%token AT 1607
%token BY 1608
%token DOT 1609
%token GO 1610
%token IF 1611
%token IN 1612
%token OF 1613
%token ON 1614
%token KW_OR 1615
%token TO 1616
%token KWUP 1617
%token FONT_NAME 1618
%token FONT_SIZE 1619
%token PAPER_SIZE_IS_LETTER 1620
%token PAPER_SIZE_IS_LEGAL 1621
%token PAPER_SIZE_IS_A5 1622
%token PAPER_SIZE_IS_A4 1623
%token PAPER_SIZE_IS_LETTER_L 1624
%token PAPER_SIZE_IS_LEGAL_L 1625
%token PAPER_SIZE_IS_A5_L 1626
%token PAPER_SIZE_IS_A4_L 1627
%token FORMHANDLER 1628
%token END_FORMHANDLER 1629
%token BEFORE_EVENT 1630
%token BEFORE_OPEN_FORM 1631
%token AFTER_EVENT 1632
%token BEFORE_CLOSE_FORM 1633
%token BEFORE_ANY 1634
%token AFTER_ANY 1635
%token MENUHANDLER 1636
%token END_MENUHANDLER 1637
%token BEFORE_SHOW_MENU 1638
%token DISABLE_PROGRAM 1639
%token DISABLE_ALL 1640
%token BUTTONS 1641
%token CHECK_MENUITEM 1642
%token DISABLE_FORM 1643
%token DISABLE_MENUITEMS 1644
%token DISABLE 1645
%token ENABLE_FORM 1646
%token ENABLE_MENUITEMS 1647
%token ENABLE 1648
%token KWFIELD 1649
%token ICON 1650
%token MESSAGEBOX 1651
%token TO_DEFAULTS 1652
%token UNCHECK_MENUITEM 1653
%token BEFORE 1654
%token INPUT 1655
%token END 1656
%token INT_TO_ID 1657
%token TIMEOUT 1658
%token OFF 1659
%token WITH_1_DIMENSION 1660
%token WITH_2_DIMENSION 1661
%token WITH_3_DIMENSION 1662
%token TILDE 1663
%token ILIKE 1664
%token FGL_ISDYNARR_ALLOCATED 1665
%token FGL_DYNARR_EXTENTSIZE 1666
/*
=====================================================================
                        Source: 99.reqd
=====================================================================
*/


%%

pause_screen_on_cmd : SETPMON  
;

pause_screen_off_cmd : SETPMOFF  
;

/**
 * Start serving functions as RPC in a port number.
 * Example of what we are expecting get here something like:
 *    START EXTERN 105 ] FOR function_one, 
 * This is an extension to standard 4gl.
 */
start_rpc_cmd 
  : START_EXTERN valid_port CLOSE_SQUARE FOR  remote_func_list
  ;

/**
 * Stop serving functions using RPC.
 * Example: STOP ALL EXTERNAL
 * This command is generated by the lexer one only token by
 * ignoring spaces and tabs.
 */
stop_rpc_cmd 
  : STOP_ALL_EXTERNAL 
  ;

/**
 * A valid port to serve functions by RPC
 * Examples of ports: 8 ; int_variable
 * @todo : The code of integer variable verification was taken off.
 */
valid_port 
  : variable 
  | INT_VALUE
  ;

/**
 * The list of functions to be served to the RPC clients.
 */
remote_func_list 
  : remote_func 
	| remote_func_list COMMA remote_func
  ;

/**
 * A remote function name.
 * It could be any name valid as function name including KEYWORDS.
 */
remote_func 
  : identifier 
  ;




/*
=====================================================================
                        Source: arr_expr.rule
=====================================================================
*/


/**
 * Array expression.
 * @todo : Explain what is suposed to get here
 * @todo : Try to use '[' and ']' as tokens for clarity
 * @todo : The validation of integer variables was taken of the code
 */
arr_expr 
  : OPEN_BRACKET arr_expr CLOSE_BRACKET  
  | arr_expr arr_next_math arr_expr 
  | INT_VALUE 
  | arr_int_sign INT_VALUE 
  | variable 
  | function_call_expr 
  ;

/**
 *
 */
arr_next_math
  : PLUS 
  | MINUS
  | MULTIPLY 
  | DIVIDE 
  | MOD
  ;


/**
 * Array int sign
 */
arr_int_sign	
  : PLUS 
  | MINUS 
;


/*
=====================================================================
                        Source: attributes.rule
=====================================================================
*/


/**
 * Optional (could be empty) attributes to be used in screens.
 */
opt_attributes
  :	
	| attributes_def 
  ;

/**
 * Possible screen interaction attribute statement.
 * 4gl code examples:
 *     ATTRIBUTES (REVERSE,WHITE)
 *     SIZE (10,20)
 */
attributes_def	
  : ATTRIBUTES OPEN_BRACKET attribs_sec CLOSE_BRACKET 
  | SIZE OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET
  ;

/**
 * Attribute list.
 * 4gl code example:
 *    REVERSE,WHITE
 */
attribs_sec	
  : attribute 
  | attribs_sec COMMA attribute 
  ;

/**
 * Specific possible screen attributes
 */
attribute	
  :BLACK
	|BLUE
	|CYAN
	|GREEN
	|MAGENTA
	|RED
	|WHITE
	|YELLOW
	|REVERSE
	|BLINK
	|UNDERLINE
	|BOLD
	|NORMAL
	|INVISIBLE
	|DIM
  |NO_NEW_LINES {inp_flags=inp_flags | 0x1; strcpy($<str>$,"0");}  
	|input_array_attributes {strcpy($<str>$,"0");}
	;

/**
 *  Optional (could be empty) WINDOW attributes.
 */
win_attributes
  :
	| win_attributes_def
  ;

/**
 * Window attribute sub section
 * 4gl code example:
 *    ATTRIBUTES (MAGENTA,REVERSE)
 */
win_attributes_def	
  :	ATTRIBUTES OPEN_BRACKET wattribs_sec CLOSE_BRACKET 
  ;

/**
 * List of window attributes.
 * 4gl code example:
 *    MAGENTA,REVERSE
 */
wattribs_sec	
  :	wattribute 
	|	wattribs_sec COMMA wattribute 
  ;

/**
 * Concrete window attributes
 */
wattribute	
  : attribute 
  |	BORDER 
	| PAD CHAR_VALUE
	|	COMMENT_LINE line_no
	|	FORM_LINE line_no
	|	ERROR_LINE line_no
	|	MENU_LINE line_no
	|	MSG_LINE line_no
	|	PROMPT_LINE line_no
  ;


/*
=====================================================================
                        Source: call.rule
=====================================================================
*/


/**
 * Explicit function call.
 * 4gl code example:
 *    CALL xpto(a,2,"XX")
 */
call_cmd	
  : FCALL call_ext 
  ;

/**
 * Continuation of the explicit function call.
 * This rule should
 *
 * @todo : I take of the validation of the get_fldbuff inside the input or 
 * construct.
 */
call_ext 
  : function_callb RETURNING variable 
  | GET_FLDBUF OPEN_BRACKET fld_list CLOSE_BRACKET RETURNING  ibind_var_list 
  | FORM_IS_COMPILED OPEN_BRACKET identifier 
	  COMMA CHAR_VALUE COMMA CHAR_VALUE CLOSE_BRACKET 
  | INFIELD OPEN_BRACKET field_name CLOSE_BRACKET RETURNING variable 
  | pdf_functions
  | FIELD_TOUCHED OPEN_BRACKET field_name_list CLOSE_BRACKET RETURNING variable 
  | variable COLON identifier OPEN_BRACKET opt_func_call_args CLOSE_BRACKET 
    opt_return 
  | identifier OPEN_BRACKET opt_func_call_args CLOSE_BRACKET opt_return 
  | SHARED char_or_var IN char_or_var OPEN_BRACKET 
    opt_func_call_args CLOSE_BRACKET opt_return 
  | identifier DOUBLE_COLON identifier  OPEN_BRACKET opt_func_call_args 
    CLOSE_BRACKET opt_return 
  | EXTERNAL remote_host_name COLON remote_func_name 
	  OPEN_SQUARE valid_port CLOSE_SQUARE OPEN_BRACKET
    opt_func_call_args CLOSE_BRACKET opt_return_remote
  ;

/**
 * Optional (could be void) returning of function call statement.
 * 4gl code example: RETURNING a,1,"xx"
 * @todo : Change the name to op_returning
 */
opt_return 	
  : 
	| RETURNING ibind_var_list 
  ;

/**
 * Optional returning subsection of function call as RPC client
 */
opt_return_remote 	
  : 
  | RETURNING ibind_var_list
  | WITHOUT_WAITING
  ;


/**
 * Optional function call arguments.
 */
opt_func_call_args 
  : 
	| func_call_args
  ;

/**
 * Function call argument list.
 * 4gl code example:  a,b,1,"zz"
 */
func_call_args	
  : func_arg
	| func_call_args COMMA func_arg 
  ;


/**
 * A function argument.
 */
func_arg 	
  : fgl_expr_c 
  ;

/**
 * Remote host name to be used in the RPC function calls.
 */
remote_host_name 
  : CHAR_VALUE 
	| identifier
  ;

/**
 * Remote (RPC) function names.
 */
remote_func_name 
  : identifier 
  | identifier DOT identifier 
  ;

/* </CALL_STATEMENT> */


/* <CASE_STATEMENT> */

/**
 * 4gl CASE statement.
 */
case_cmd	
  : CASE fgl_expr when_unit_expr op_otherwise_command_expr end_case_command 
  | CASE when_unit op_otherwise_command end_case_command 
  ;

/**
 * When sub statement of the case instruction with the statements that
 * are executed.
 * @todo : Explain this in a better way
 */
when_unit 
  : when_command 
	| when_unit when_command 
  ;

/**
 * The possible expressions in the when of a case command.
 */
when_unit_expr  
  : when_command_expr 
	| when_unit_expr when_command_expr 
  ;

/**
 * The end of a case statement
 */
end_case_command 
  : END_CASE 
  ;

/**
 * Optional otherwise command of the CASE statement.
 */
op_otherwise_command 
  : 
	| OTHERWISE commands 
  ;

/**
 * Optional otherwise command of the CASE statement.
 * @todo : Understand why i cant use the rule below.
 */
op_otherwise_command_expr 
  : 
	| OTHERWISE commands 
  ;

/**
 * The when definition without the statements to be executed.
 * 4gl code example:
 *    WHEN a = 1
 */
when_command	
  : WHEN  fgl_expr commands 
  ;

/**
 * @todo : understand the diference between this one a the one below.
 */
when_command_expr	
  : WHEN fgl_expr commands 
  ;

/* </CASE_STATEMENT> */



/* <CLOSE_STATEMENTS> */

/**
 * All the close statements:
 *   Form
 *   window
 *   statusbox (???)
 *   database
 *   session - A named connection to a database
 *   cursor
 */
close_cmd	
  :	CLOSE_FORM form_name 
  |	CLOSE_WINDOW win_name 
	|	CLOSE_STATUSBOX win_name 
	|	CLOSE_DATABASE 
	|	CLOSE_SESSION conn_id 
	|	CLOSE fetch_cursor_name 
;

/* </CLOSE_STATEMENTS> */



/* <EMBEDDED_C_CODE> */

code_cmd 
  : KW_CSTART emb_code KW_CEND
  ;

emb_code 
  : sql_code 
	| c_code
	;

sql_code 
  : sql_code_part 
	| sql_code sql_code_part
  ;

sql_code_part
  : SQLLINE 
  ;

c_code 
  : c_code_part 
	| c_code c_code_part
  ;

c_code_part  
  : CLINE 
  ;

/* </EMBEDDED_C_CODE> */


/* <COMMENTS> */

/**
 * This aint used - its filtered by the lexer first...
 */
comment_cmd 
  : COMMENT 
  ;

/* </COMMENTS> */


/* <CONSTRUCT_STATEMENT> */

/**
 * The construct statement.
 */
construct_cmd	
  :	CONSTRUCT constr_rest end_constr 
  ;


/**
 * The main part of construct between CONSTRUCT and END CONSTRUCT
 */
constr_rest
  : BY_NAME variable ON constr_col_list opt_defs op_help opt_attributes
  | variable ON constr_col_list opt_defs FROM fld_list op_help opt_attributes
  ;

/**
 * Optional end construct.
 * @todo : change the name to op_end_construct
 */
end_constr 
  : 
  | constr_extra_commands END_CONSTRUCT 
  ;

/**
 * The construct column list
 */
constr_col_list 
  : constr_col 
	| constr_col_list COMMA constr_col
  ;

/**
 * A construct column
 */
constr_col 
  : identifier 
  | identifier DOT identifier 
  | identifier DOT MULTIPLY 
  ;

/**
 * Extra comand list of the construct statement.
 */ 
constr_extra_commands 
  : constr_extra_command 
	| constr_extra_commands constr_extra_command
  ;

/**
 * Construct possible event statements.
 */
constr_extra_command 
  : BEFFIELD bef_c_field_list commands 
	| AFTFIELD aft_c_field_list commands 
	| on_key_command commands 
	| AFTCONSTRUCT commands 
	| BEFCONSTRUCT commands 
  ;

/**
 * The before field construct list
 */
bef_c_field_list 
  : field_name2 
	| bef_c_field_list COMMA field_name2 
  ;

/**
 * The after field construct list 
 */
aft_c_field_list 
  : field_name2 
	| aft_c_field_list COMMA field_name2 
  ;

/* </CONSTRUCT_STATEMENT> */


/* <DATETIME_EXPRESSION> */

/**
 * A interval expression
 */
interval_expr
  : UNITS_YEAR 
	| UNITS_MONTH 
	| UNITS_DAY 
	| UNITS_HOUR 
	| UNITS_MINUTE 
	| UNITS_SECOND 
  ;


/**
 * Datetime parameters.
 * 4gl code example: 
 *     ( 10:20 + 1 UNITS HOURS )
 * @todo : Confirm if this code is OK
 */
extend_parameters
  : OPEN_BRACKET fgl_expr_c op_datetime_qual CLOSE_BRACKET 
  ;


/**
 * An optional datetime qualifier
 */
op_datetime_qual
  :
  | COMMA dtime_start TO dtime_end 
  ;

/* <DATETIME_EXPRESSION> */


/* <DEFER_STATEMENT> */

/**
 * The signal defer statement
 * 4gl code examples:
 *    DEFER INTERRUPT
 *    DEFER QUIT
 */
defer_cmd	
  : DEFER_INTERRUPT 
	|	DEFER_QUIT 
	;

/* </DEFER_STATEMENT> */


/* <DEFINE_STATEMENT> */

/**
 * Optional define section
 */
define_section
  :
	|	define_multiple 
	;

/**
 *
 */
define_multiple	
  : define_set 
	| define_multiple define_set
  ;

/**
 * A set of define statements.
 * @todo : Understand why whenever is here.
 */
define_set 
  : DEFINE def_part opt_semi
	| dim_section
	| whenever_cmd
  ;

/**
 * The define of variables expected to be after a DEFINE reserved word.
 * 4gl code examples:
 *    x, i smallint, b char(10)
 * @todo : use a better name for the rule
 */
def_part 
  : def_part2 
	| def_part COMMA def_part2
  ;

/**
 * An identifier that could be used in a define section as a variable name.
 */
define_ident 
  : identifier 
  ;

/**
 * The definition of a variable.
 * Here there are extensions to standard 4gl like CONSTANT(s) and
 * initialization on define.
 * 
 * @todo : use a better name for the rule
 */
def_part2
  :	CONSTANT define_ident op_equal CHAR_VALUE
  | CONSTANT define_ident op_equal identifier
  | CONSTANT define_ident op_equal real_number
  | CONSTANT define_ident op_equal INT_VALUE
  | var_def_list dtype_ident 
  | define_ident CONSTANT constant_value
  ;

/**
 * A constant literal value to be used as a constant.
 */
constant_value 
  : INT_VALUE 
	| CHAR_VALUE 
	| real_number 
	| MINUS INT_VALUE 
  ;

/**
 * A possible variable name.
 */
var_def_name	
  :	define_ident 
  ;

/**
 * A List of variables to be defined of the same type.
 * 4gl code example:
 *   x, y
 */
var_def_list	
  : var_def_name
	| var_def_list COMMA var_def_name 
	;

/**
 * Optional CHAR token
 */
op_char 
  : 
	| CHAR;


/**
 * Optional something.
 *
 * @todo : Underestand what this rule makes.
 * @todo : Change the name of this rule to be more explicit
 */
ranking 
  :
	| WITH_1_DIMENSION 
	| WITH_2_DIMENSION
	| WITH_3_DIMENSION
  ;


/**
 * The definition of an array variable  in the define section.
 * The associateive arrays are an aubit extension to standard informix 4gl.
 * 4gl code examples:
 *   x ARRAY[4] OF INTEGER
 */
array_variable	
  : ARRAY OPEN_SQUARE  number_arr_list CLOSE_SQUARE OF dtype_ident
  | DYNAMIC_ARRAY ranking OF dtype_ident
  | ASSOCIATE op_char assoc_open_bracket INT_VALUE assoc_close_bracket
    WITH_ARRAY OPEN_SQUARE number_arr_assoc CLOSE_SQUARE OF dtype_ident  
  ;

/**
 * The specific associative array open bracket.
 */
assoc_open_bracket
  : OPEN_BRACKET 
	| OPEN_SHEV 
	;

/**
 * The specific associative array close bracket.
 */
assoc_close_bracket
  : CLOSE_BRACKET 
	| CLOSE_SHEV 
	;

/**
 * The number of elements definition in an associative array.
 */
number_arr_assoc
  : INT_VALUE
	;

/**
 * The list of the comma separated possible dimensions in an array.
 * 4gl code example:
 *    1,2,4
 */
number_arr_list	
  : number_value_arr COMMA number_value_arr COMMA number_value_arr 
	| number_value_arr COMMA number_value_arr 
	| number_value_arr 
	;

/**
 * The constant array dimension definition.
 */
number_value_arr
  : INT_VALUE 
  ;

/**
 * The definition of a record variable.
 * 4gl code example:
 *    RECORD 
 *      x INTEGER,
 *      y CHAR(10)
 *    END RECORD
 */
record_variable	
  : RECORD def_part END_RECORD 
  |	RECORD_LIKE define_ident DOT MULTIPLY
  |	LINKED_TO define_ident PRIMARY_KEY 
	  OPEN_BRACKET link_to_pk_list CLOSE_BRACKET
  ;

link_to_pk_list 
  : link_to_pk 
	| link_to_pk_list COMMA link_to_pk 
  ;

link_to_pk 
  : define_ident
  ;

dtype_ident 
  : dtype2 
	;

op_as_static
  : 
	| AS_STATIC
  ;

dtype2
  : dtype op_as_static
  ;

dtype	
  : array_variable 
	|	record_variable 
	|	CHAR
	|	CHAR OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
	|	VARCHAR OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
	|	VARCHAR OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET 
	|	INTEGER 
	| AS define_ident 
	|	SMALLINT 
	|	KWFORM 
	|	STATUSBOX
	|	DECIMAL
	|	DECIMAL OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
	|	DECIMAL OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET 
	|	MONEY 
	|	MONEY OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
	|	MONEY OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET 
	|	FLOAT 
	|	SMALLFLOAT
	|	DATE
	|	BYTE
	|	BYTES_USE_AS_IMAGE
	|	BYTES_USE_AS_ASCII
	|	TEXT
	|	DATETIME datetime_qual 
	|	INTERVAL interval_qual 
	| like_var 
	| USER_DTYPE 
	;

like_var 	
  : LIKE tab_name DOT col_name  
  ;

tab_name 
  : define_ident 
	;

col_name 
  : define_ident 
	;

/**
 * Optional datetime qualifier
 */
datetime_qual 
  :  
	| dtime_start TO dtime_end 
  ;

interval_qual 
  : int_start TO int_end  
  ;

dtime_start 
  : dtime_val 
  ;

dtime_val 
  : YEAR
  | MONTH
  | DAY
  | HOUR
  | MINUTE
  | SECOND
  | FRACTION opt_frac
  ;

dtime_end 
  : dtime_val 
  ;

/**
 * Optional fraction of a datetime value
 */
opt_frac
  : 
  | OPEN_BRACKET dtfrac CLOSE_BRACKET 
  ;

opt_unit_size
  : 
  | OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
  ;


dtfrac
  : INT_VALUE 
  ;

int_start 
  : 
	int_start_unit opt_unit_size 
  ;

int_start_unit 
  : YEAR 
  | MONTH
  | DAY
  | HOUR
  | MINUTE
  | SECOND
  | FRACTION opt_frac
  ;

int_end 
  : int_start_unit
	;


op_equal 
  : 
	| EQUAL 
  ;

/* </DEFINE_STATEMENT> */


/* <DIM_STATEMENT> */

dim_section 
  : DEFINE_TYPE identifier AS dim_dtype
  ;

dim_dtype
  : dim_array_variable 
  | dim_record_variable 
  | CHAR 
  | CHAR OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
  | VARCHAR OPEN_BRACKET INT_VALUE CLOSE_BRACKET
  | VARCHAR OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET 
  | INTEGER
  | SMALLINT 
  | KWFORM 
  | DECIMAL 
  | DECIMAL OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
  | DECIMAL OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET 
  | MONEY 
  | MONEY OPEN_BRACKET INT_VALUE CLOSE_BRACKET
  | MONEY OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET 
  | FLOAT 
  | SMALLFLOAT 
  | DATE 
  | BYTE 
  | TEXT 
  | DATETIME datetime_qual 
  | dim_like_var
  ;

dim_like_var
  : LIKE tab_name  DOT col_name  
  ;

dim_array_variable
  : ARRAY OPEN_SQUARE number_arr_list CLOSE_SQUARE OF dim_dtype
  | ASSOCIATE op_char assoc_open_bracket INT_VALUE assoc_close_bracket
    WITH_ARRAY OPEN_SQUARE number_arr_assoc CLOSE_SQUARE OF dim_dtype  
  ;

dim_record_variable
  : RECORD dim_def_part END_RECORD
  | RECORD_LIKE identifier DOT MULTIPLY
  ;

dim_def_part 
  : dim_def_part2 
	| dim_def_part COMMA dim_def_part2
  ;

dim_def_part2 
  : dim_var_def_list dim_dtype
  ;

dim_var_def_list	
  : dim_var_def_name
	| dim_var_def_list COMMA dim_var_def_name 
	;

dim_var_def_name	
  :	identifier 
	;

/* </DIM_STATEMENT> */


/* <DISPLAY_STATEMENT> */

opt_at 
  : 
	| AT display_coords 
	| TO_MENUITEM identifier 
	| TO_MAIN_CAPTION
	| TO fld_list
	| TO KWFORM identifier KWFIELD fld_list 
	| TO KWFORM identifier CAPTION 
	| TO_STATUSBOX identifier 
  ;

display_b_n_cmd 
  : DISPLAY_BY_NAME reset_cnt ibind_var_list display_attr 
  ;


display_cmd : DISPLAY reset_cnt fgl_expr_list opt_at display_attr 
  ;

display_form_cmd 
  : DISPLAY_FORM form_name display_attr 
  ;

display_array_cmd 
  : DISPLAY_ARRAY use_arr_var TO identifier DOT MULTIPLY opt_scroll 
	  opt_attributes disp_rest 
  ;

opt_scroll
  : 
  | SCROLL_USING field_name 
  ;

display_attr	
  :	opt_attributes 
	;

disp_rest 
  : 
	| disp_field_commands END_DISPLAY
	;


disp_field_commands 
  : disp_field_command 
	| disp_field_commands disp_field_command
	;

disp_field_command 
  : AFTROW commands 
	| BEFROW commands 
	| on_key_command commands 
  ;

/* </DISPLAY_STATEMENT> */

/* <ERROR_STATEMENT> */

error_cmd	
  : ERROR reset_cnt fgl_expr_concat opt_attributes 
	| ERROR reset_cnt fgl_expr_concat opt_attributes  WAIT_FOR_KEY 
  ;

/* </ERROR_STATEMENT> */


/* <EXIT_STATEMENT> */

ext_cmd 
  : EXIT_WHILE
	| EXIT_INPUT
	| EXIT_FOREACH
	| EXIT_FOR
	| EXIT_CONSTRUCT
	| EXIT_DISPLAY
	| EXIT_MENU  
	| EXIT_CASE
	| EXIT_PROMPT
  ;

/* </EXIT_STATEMENT> */

/* <CONTINUE_STATEMENT> */

continue_cmd 
  : CONTINUE_WHILE 
	| CONTINUE_INPUT
	| CONTINUE_FOREACH
	| CONTINUE_FOR 
	| CONTINUE_CONSTRUCT
	| CONTINUE_DISPLAY
	| CONTINUE_MENU
	| CONTINUE_PROMPT
  ;

/* </CONTINUE_STATEMENT> */


/* <EXIT_PROGRAM_STATEMENT> */

exit_prog_cmd 
  : EXIT_PROGRAM 
  | EXIT_PROGRAM fgl_expr 
  ;

/* </EXIT_PROGRAM_STATEMENT> */


/* <EXPRESSION_RULE> */

fgl_expr_c 
  : initial_expr
  | boolean_expr
  | report_only_expr
  | function_call_expr
  | fgl_expr_c fgl_next 
  | builtin_expr
  | pdf_expr
  | literal_expr 
  | MINUS fgl_expr_c 
  | PLUS fgl_expr_c 
  ;

fgl_next
  : and_or_expr
  | comparison_expr
  | in_expr
  | SPACES 
  | interval_expr 
  | null_expr
  | string_match_expr
  | clip_expr 
  | using_expr 
  | math_expr
  | CONCAT_PIPES fgl_expr_c 
  ;

op_fgl_expr_ret_list
  : reset_cnt
	| reset_cnt fgl_expr_ret_list
  ;

fgl_expr_ret 
  : fgl_expr 
	| KW_NULL
  ;

fgl_expr_ret_list 	
  : fgl_expr_ret
	| fgl_expr_ret_list COMMA fgl_expr_ret
  ;

fgl_expr_list 	
  : fgl_expr
	| fgl_expr_list COMMA fgl_expr
  ;

fgl_expr_concat	
  :	fgl_expr
	| fgl_expr_concat COMMA fgl_expr
  ;

fgl_expr
  : fgl_expr_c 
  ;

int_sign	
  : PLUS
	| MINUS
  ;

boolean_expr
  : NOT fgl_expr_c 
  | KW_TRUE  
  | KW_FALSE 
  | OPEN_BRACKET fgl_expr_c CLOSE_BRACKET
  | EXISTS OPEN_BRACKET in_select_statement_ss CLOSE_BRACKET
  | NOT_EXISTS OPEN_BRACKET in_select_statement_ss CLOSE_BRACKET 
  ;	

initial_expr
  : int_sign real_number 
  | int_sign INT_VALUE 
  ;

literal_expr
  : CHAR_VALUE  
  | real_number
  | INT_VALUE
  | variable_entry
  ;

variable_entry_2 
  : variable
	| variable THRU variable
  ;

variable_entry 
  : variable_entry_2 
  ;

report_only_expr
  : COLUMN fgl_expr_c 
  | COLUMNS fgl_expr_c 
  | rep_agg  
  | GROUP rep_agg
  ;

and_or_expr
  : KW_AND fgl_expr_c 
  | KW_OR fgl_expr_c 
  ;


inexpr_list 
  : fgl_expr_c  
	| inexpr_list COMMA fgl_expr_c
  ;


in_expr
  : IN OPEN_BRACKET in_select_statement_ss CLOSE_BRACKET 
  | NOT_IN OPEN_BRACKET in_select_statement_ss CLOSE_BRACKET 
  | IN OPEN_BRACKET reset_cnt inexpr_list CLOSE_BRACKET 
  | NOT_IN OPEN_BRACKET reset_cnt inexpr_list CLOSE_BRACKET 
  ;

null_expr
  : IS_NULL  
  | IS_NOT_NULL
  ;

string_match_expr
  : MATCHES fgl_expr_c 
  | NOT_MATCHES fgl_expr_c 
  | MATCHES fgl_expr_c ESCAPE CHAR_VALUE 
  | NOT_MATCHES fgl_expr_c ESCAPE CHAR_VALUE 
  | LIKE fgl_expr_c 
  | NOT_LIKE fgl_expr_c 
  | LIKE fgl_expr_c ESCAPE CHAR_VALUE 
  | NOT_LIKE fgl_expr_c ESCAPE CHAR_VALUE 
  ;

clip_expr
  : CLIPPED 
  ;

using_expr
  : KW_USING fgl_expr_c 
  ;

math_expr
  : PLUS fgl_expr_c 
  | MINUS fgl_expr_c
  | MULTIPLY fgl_expr_c 
  | DIVIDE  fgl_expr_c 
  | MOD fgl_expr_c 
  | POWER fgl_expr_c 
  ;

comparison_expr
  : EQUAL fgl_expr_c 
  | EQUAL_EQUAL fgl_expr_c 
  | LESS_THAN fgl_expr_c
  | GREATER_THAN fgl_expr_c
  | NOT_EQUAL fgl_expr_c
  | LESS_THAN_EQ fgl_expr_c
  | GREATER_THAN_EQ fgl_expr_c
  ;

reset_cnt : {
	reset_counter();
}
;

function_call_expr2
  : identifier OPEN_BRACKET opt_func_call_args CLOSE_BRACKET 
  | identifier DOUBLE_COLON identifier 
	  OPEN_BRACKET opt_func_call_args CLOSE_BRACKET 
  ;

/**
 * @todo : I supose that the parset does not work without some consumed code.
 */
function_callb
  : DATE OPEN_BRACKET fgl_expr_c CLOSE_BRACKET 
  | MONTH OPEN_BRACKET fgl_expr_c CLOSE_BRACKET 
  | DAY OPEN_BRACKET fgl_expr_c CLOSE_BRACKET 
  | YEAR OPEN_BRACKET fgl_expr_c CLOSE_BRACKET 
  | INTERVAL OPEN_BRACKET interval_func_params CLOSE_BRACKET op_extend_i 
  | DATETIME OPEN_BRACKET CHAR_VALUE CLOSE_BRACKET op_extend_d 
  | DATETIME OPEN_BRACKET INT_VALUE CLOSE_BRACKET op_extend_d 
  | DATETIME OPEN_BRACKET INT_VALUE COLON INT_VALUE CLOSE_BRACKET op_extend_d 
  | FGL_ISDYNARR_ALLOCATED OPEN_BRACKET variable CLOSE_BRACKET 
  | FGL_DYNARR_EXTENTSIZE OPEN_BRACKET variable COMMA INT_VALUE CLOSE_BRACKET 
  ;



op_extend_d
  : 
	| s_curr_v TO e_curr_v
  ;

op_extend_i
  : interval_qual
  ;

function_call_expr
  : function_callb
  | GET_FLDBUF OPEN_BRACKET fld_list CLOSE_BRACKET 
  | FIELDTOWIDGET OPEN_BRACKET field_name CLOSE_BRACKET 
  | ID_TO_INT OPEN_BRACKET field_name CLOSE_BRACKET 
  | INFIELD OPEN_BRACKET fld_list CLOSE_BRACKET 
  | FIELD_TOUCHED OPEN_BRACKET fld_list CLOSE_BRACKET 
  | NOT_FIELD_TOUCHED OPEN_BRACKET fld_list CLOSE_BRACKET 
  | builtin_funcs
  | function_call_expr2
  ;

builtin_expr 
  : curr_v_clause 
  | DATE  
  ;

builtin_funcs 
  : UPSHIFT OPEN_BRACKET fgl_expr_c CLOSE_BRACKET 
  | DOWNSHIFT OPEN_BRACKET fgl_expr_c CLOSE_BRACKET
  | ASCII fgl_expr_c  
  | EXTEND extend_parameters
  ;

pdf_expr 
  : fgl_expr_c POINTS  
  | fgl_expr_c MM 
  | fgl_expr_c INCHES
  ;

interval_func_params 
  : CHAR_VALUE 
  | numeric_time_interval 
  ;

numeric_time_interval
  : MINUS numeric_time_interval 
	| numeric_time_unit_big	
	| numeric_time_unit_small	
  ;

numeric_time_unit_small 
  : INT_VALUE 								                   /* DD or HH or MM or SS */
	| INT_VALUE INT_VALUE 			                   /* DD HH */
	| INT_VALUE INT_VALUE COLON INT_VALUE 	       /* DD HH:MM */
	| INT_VALUE INT_VALUE COLON INT_VALUE COLON INT_VALUE 	 /* DD HH:MM:SS*/
	| INT_VALUE INT_VALUE COLON INT_VALUE COLON NUMBER_VALUE /* DD HH MM SS.FFFF*/
	| INT_VALUE COLON INT_VALUE                    /* HH MM */
	| INT_VALUE COLON INT_VALUE COLON INT_VALUE    /* HH MM SS*/
	| INT_VALUE COLON INT_VALUE COLON NUMBER_VALUE /* HH MM SS.FFFF*/

	| INT_VALUE COLON NUMBER_VALUE			           /* MM SS.FFFF*/
	| NUMBER_VALUE					                       /* SS.FFFF*/
  ;

numeric_time_unit_big
  : INT_VALUE
	| INT_VALUE MINUS INT_VALUE 
  ;

field_name_list
  : field_name 
	| field_name_list COMMA field_name 

/* </EXPRESSION_RULE> */


/* <FOR_RULE> */

for_cmd	
  : FOR variable EQUAL fgl_expr TO fgl_expr for_step commands END_FOR 
  ;

for_step 
  :	
	|	STEP fgl_expr
  ;

/* </FOR_RULE> */


/* <FOREACH_RULE> */
foreach_cmd	
  :	FOREACH fetch_cursor_name opt_foreach_using_part
    opt_foreach_into_fetch_part commands END_FOREACH 
  ;

opt_foreach_using_part
  : 
	| KW_USING reset_cnt fgl_expr_list 
	;
/* </FOREACH_RULE> */


/* <FORM_HANDLER_RULE> */

formhandler_def 
  : FORMHANDLER identifier define_section  op_code op_bef_ev_list
    op_input_section op_aft_ev_list END_FORMHANDLER 
  ;

op_input_section 
  : 
	| input_section
	;

op_bef_ev_list 
  :
	| bef_ev_list
  ;

bef_ev_list 
  : bef_ev 
	| bef_ev_list bef_ev
  ;

bef_ev 
  : BEFORE_EVENT commands 
  | BEFORE_OPEN_FORM commands 
  ;

op_aft_ev_list 
  :
  | aft_ev_list
  ;

aft_ev_list 
  : aft_ev 
	| aft_ev_list aft_ev
  ;

aft_ev 
  : AFTER_EVENT commands 
  | BEFORE_CLOSE_FORM commands 
  ;

input_section 
  : input_sub_section field_ops END_INPUT
  ;

input_sub_section 
  : FORMHANDLER_INPUT
  | FORMHANDLER_INPUT in_variable_list FROM in_id_list
  | FORMHANDLER_INPUT BY_NAME in_bn_variable_list
  ;

in_variable_list 
  : variable 
	| in_variable_list COMMA variable
  ;

in_id_list 
  : identifier 
	| in_id_list COMMA identifier
  ;

in_bn_variable_list 
  : variable 
	| in_bn_variable_list COMMA variable
  ;

field_ops 
  : field_op 
	| field_ops field_op
  ;

field_op 
  : BEFORE_ANY commands 
  | AFTER_ANY commands 
  | BEFORE in_id_list commands 
  | AFTER in_id_list commands 
  | ON in_id_list commands
  ;

/* </FORM_HANDLER_RULE> */


/* <FREE_STATEMENT> */

free_cmd 
  : FREE cursor_name
  ;

/* </FREE_STATEMENT> */


/* <GENERAL_RULE> */

line_no		
  : LAST MINUS INT_VALUE 
	| LAST 
	| FIRST PLUS INT_VALUE 
	| FIRST 
	| INT_VALUE 
	| variable 
	| OFF 
  ;

file_name	
  :	CHAR_VALUE 
	| cvariable 
  ;

a_number	
  :	fgl_expr
	;

coords		
  :	a_number COMMA a_number 
  ;

display_coords	
  :	coords
	;

field_name	
  :	identifier 
	| INT_TO_ID OPEN_BRACKET identifier CLOSE_BRACKET 
	| identifier DOT INT_TO_ID OPEN_BRACKET identifier CLOSE_BRACKET 
	| identifier OPEN_SQUARE arr_expr CLOSE_SQUARE
	| identifier DOT MULTIPLY
	| identifier OPEN_SQUARE arr_expr CLOSE_SQUARE DOT MULTIPLY
	| identifier DOT identifier 
	| identifier OPEN_SQUARE arr_expr CLOSE_SQUARE DOT identifier
  ;

cursor_name	
  :	ident_or_var 
  ;

fetch_cursor_name	
  :	ident_or_var 
	;

win_name	
  :	ident_or_var 
  ;

open_win_name	
  :	ident_or_var 
  ;

form_name	
  : ident_or_var 
  ;

open_form_name	
  : ident_or_var 
  ;

opt_help_no		
  :	
	| HELP INT_VALUE 
  ;

identifier	
  : NAMED  
  ;

ident_or_var	
  : ident_p2  
  ;

ident_p2 
  : NAMED 
  | VARIABLE OPEN_BRACKET var_or_string CLOSE_BRACKET
  ;

var_or_string 
  : var 
	| CHAR_VALUE
	;

field_name2	
  :	identifier 
  | identifier OPEN_SQUARE arr_expr CLOSE_SQUARE
	| identifier DOT MULTIPLY
	| identifier OPEN_SQUARE arr_expr CLOSE_SQUARE DOT MULTIPLY
	| identifier DOT identifier 
  | identifier OPEN_SQUARE arr_expr CLOSE_SQUARE DOT identifier
  ;

cvariable 
  : variable 
  ;


real_number 
  : NUMBER_VALUE 
	| DOT INT_VALUE 
  ;


/* @todo : I think that this is no longer needed. Its fixed in another way
reserved_word :
	PASSWORD
	|CHECK
	|CLEAR
	|CLIPPED
	|CLOSE
	|CONSTANT
	|CONSTRUCT
	|COUNT
	|OPTION
	|CYAN
	|HEADER
	|DBA
	|DBYNAME
	|AUDIT
	|KWLINE
	|MODE
	|DEFAULT
	|DEFAULTS
	|DEFER
	|DELIMITER
	|DESC
	|DESCENDING
	|DIM
	|DISABLE
	|KWDOWN
	|DOWNSHIFT
	|DROP
	|FOREIGN
	|EXISTS
	|YEAR
	|MONTH
	|DAY
	|SPACES
	|RESOURCE
	|COMMENT
	|DELETE
	|VALIDATE
	|ESCAPE
	|UPSHIFT
	|AVERAGE
	|UNDERLINE
	|MENU
	|DATE
;
*/

/* </GENERAL_RULE> */


/* <GOTO_STATEMENT> */

goto_cmd 
  : GOTO label_goto 
  ;

/* </GOTO_STATEMENT> */


/* <UI_RULE> */

check_menu_cmd 
  : CHECK_MENUITEM menu_item_list
  ;

menu_item_list
  : menu_item 
	| menu_item_list COMMA menu_item
  ;

menu_item
  : identifier 
  ;

uncheck_menu_cmd 
  : UNCHECK_MENUITEM menu_item_list
  ;

disable_cmd 
  : DISABLE_MENUITEMS menu_item_list
  | DISABLE fld_list
  | DISABLE_FORM form_name KWFIELD fld_list
  ;

enable_cmd 
  : ENABLE_MENUITEMS menu_item_list
  | ENABLE fld_list
  | ENABLE_FORM form_name KWFIELD fld_list
  ;

msg_box_cmd 
  : MESSAGEBOX fgl_expr_list
    op_caption
    op_icon
    op_buttons
    op_disable_msg
    op_returning_msg 
  ;

op_disable_msg 
  :
  | gm_disable_msg
  ;

gm_disable_msg
  : DISABLE_PROGRAM 
	| DISABLE_ALL
  ;


op_returning_msg 
  : 
  | gm_returning_msg
  ;

gm_returning_msg
  : RETURNING variable
  ;

op_caption 
  : 
	| gm_caption
  ;

gm_caption
  : CAPTION fgl_expr_list 
	;

op_icon 
  : 
	| gm_icon
  ;

gm_icon
  : ICON INT_VALUE  
	;

op_buttons 
  : 
	| gm_buttons
	;

gm_buttons 
  : BUTTONS INT_VALUE op_def_but
	;

op_def_but 
  : 
	| DEFAULT INT_VALUE
	;

/* </UI_RULE> */


/* <IF_STATEMENT> */

if_cmd	
  : IF fgl_expr THEN  commands op_else END_IF 
  ;

op_else 
  : 
	| ELSE 
	| ELIF fgl_expr THEN commands op_else 
	;

/* </IF_STATEMENT> */

import_m 
  : IMPORT_FUNCTION identifier OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
	| IMPORT_LEGACY_FUNCTION identifier 
  ;

module_import
  : IMPORT_DATATYPE identifier 
  ;


/* <INITIALIZE_STATEMENT> */

init_cmd : INITIALIZE init_bind_var_list {A4GL_debug("init to\n");} TO KW_NULL
 {
	print_init();
 }
| INITIALIZE init_bind_var_list LIKE init_tab_list  {
	print_init_table($<str>4);
}
;


init_tab_list : init_tab | init_tab_list COMMA init_tab {sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
}
;

init_tab : tab_name DOT column_name {setrecord($<str>$,$<str>1,$<str>3);}
	| tab_name DOT MULTIPLY {setrecord($<str>$,$<str>1,0);}
;

/* </INITIALIZE_STATEMENT> */

/* <INPUT_STATEMENT> */
end_input 
  :
  | field_commands END_INPUT 
	;

opt_defs 
  : 
  | WITHOUT_DEFAULTS 
  ;

field_commands 
  : field_command 
	| field_commands field_command
	;

field_command 
  : BEFFIELD bef_field_list commands 
	| AFTFIELD aft_field_list commands 
	| AFTROW commands 
	| BEFROW commands 
	| on_key_command commands 
	| AFTINP commands 
	| BEFINP commands 
	| BEFORE_DELETE  commands 
	| BEFORE_INSERT  commands 
	| AFTER_DELETE  commands 
	| AFTER_INSERT  commands 
  ;

/*
a_ins_or_delete_row :
	a_ins_or_delete {sprintf($<str>$,"(%s)",$<str>1);} 
	| a_ins_or_delete_row COMMA a_ins_or_delete {
	char buff[256];
	sprintf(buff,"(%s)",$<str>3);
	A4GL_generate_or($<str>$,$<str>1,buff);
	}
;

a_ins_or_delete:
	INSERT {strcpy($<str>$,"AFT_INSERT");}
	| DELETE {strcpy($<str>$,"AFT_DELETE");}
;


b_ins_or_delete_row :
	b_ins_or_delete {sprintf($<str>$,"(%s)",$<str>1);} 
	| b_ins_or_delete_row COMMA b_ins_or_delete {
	char buff[80];
		sprintf(buff,"(%s)",$<str>3);
		A4GL_generate_or($<str>$,$<str>1,$<str>3);
 }

;

b_ins_or_delete:
	INSERT {strcpy($<str>$,"BEF_INSERT");}
	| DELETE {strcpy($<str>$,"BEF_DELETE");}
;
*/

bef_field_list 
  : field_name 
	| bef_field_list COMMA field_name 
  ;

aft_field_list 
  : field_name 
	| aft_field_list COMMA field_name 
  ;

next_field_cmd 
  : NEXTFIELD next_field 
  ;

next_form_cmd 
  : NEXTFORM identifier KWFIELD next_field 
  ;

next_field	
  :	NEXT 
	| PREVIOUS 
	| field_name 
  ;

input_cmd	
  :	INPUT inp_rest end_input 
  ;

inp_rest
  : BY_NAME ibind_var_list opt_defs opt_help_no opt_attributes 
  | ibind_var_list opt_defs FROM fld_list  opt_help_no opt_attributes 
  | ARRAY use_arr_var opt_defs FROM identifier DOT MULTIPLY opt_help_no 
    opt_attributes
  ;

scroll_cmd 
  : SCROLL fld_list up_or_down 
  ;

up_or_down 
  : KWUP_BY INT_VALUE 
	| KWDOWN_BY INT_VALUE 
	| KWUP 
	| KWDOWN 
  ;

op_help 
  : 
	| HELP INT_VALUE
  ;

input_array_attributes: 
  input_array_attributes_int 
  ;

input_array_attributes_int 
  : CURRENT_ROW_DISPLAY_EQUAL CHAR_VALUE 	
	| COUNT EQUAL INT_VALUE
	| COUNT EQUAL variable
	| MAXCOUNT EQUAL INT_VALUE
	| MAXCOUNT EQUAL variable
	| INSERT_ROW_EQUAL_TRUE
	| INSERT_ROW_EQUAL_FALSE
	| DELETE_ROW_EQUAL_TRUE
	| DELETE_ROW_EQUAL_FALSE
  ;

/* </INPUT_STATEMENT> */

on_key_command 
  : ONKEY key_do 
  | ON_ANY_KEY 
  ;

key_val 
  : KEY key_do 
	;

accept_key 
  :  ACCEPTKEY key_value 
  ;


single_key_val 
  : KEY key_do 
  ;

key_do	
  : key_value  
	| OPEN_BRACKET key_value_list CLOSE_BRACKET  
  ;

key_value_list 
  : key_value 
	| key_value_list COMMA key_value 
  ;

key_value 
  : key_value_1 
  ;

key_value_1 
  : FKEY
	| CTRL_KEY 
	|	INTERRUPT 
	| ACCEPT 
	| SINGLE_KEY 
  | ESCAPE 
  | KWUP 
  | HELP 
  | KWDOWN
  | RETURN
  | DELETE
  | INSERT
  | TAB
  | LEFT
  | RIGHT
  | NEXTPAGE
  | PREVPAGE
  | CHAR_VALUE
  ;


label_cmd 
  : LABEL  
  ;


/* <LET_STATEMENT> */

let_cmd 
  : LET obind_var_let_list EQUAL reset_cnt op_expr_null
  ;

op_expr_null
  : KW_NULL 
	| fgl_expr_concat 
	;


/* </LET_STATEMENT> */


linked_cmd 
  : SELECT_USING variable 
  ;

linked_del_cmd 
  : DELETE_USING variable 
  ;

linked_upd_cmd 
  : UPDATE_USING variable 
  ;

locate_cmd 
  : LOCATE variable IN_MEMORY 
  | LOCATE variable IN_FILE file_name 
  ;


/* <MAIN_RULE> */

module
  : op_module_header func_main_def 
  ;


op_module_header
  : 
	| module_header 
  ;

module_header	
  :	module_entry 
	|	module_header module_entry
  ;

module_entry 
  : module_import 
  | module_code 
  | module_globals_section 
  | module_define_section  
	;

func_main_def	
  : /* could be empty file */
  | func_or_main2
  ;

func_or_main2 
  : func_or_main
	| func_or_main2 func_or_main
	;

at_term_cmd 
  : AT_TERMINATION_CALL  identifier 
  ;

func_or_main	
  :	func_def
	|	main_def
	|	mem_func_def
	|	report_def
	|	pdf_report_def
  | menu_def
	| whenever_cmd 
  | formhandler_def
	|	code_cmd
	| import_m
	|	comment_cmd
	;

module_code 
  : code_cmd 
	| whenever_cmd  
	;

op_code 
  : 
	| code_cmd 
	| whenever_cmd  
	;

module_define_section 
  : define_multiple 
  ;


ldeffunction 
  : FUNCTION 
	| LOCAL_FUNCTION
  ;

/*
 * Function definition 
 */
func_def	
  : ldeffunction identifier OPEN_BRACKET  op_param_var_list CLOSE_BRACKET 
      define_section 
      op_code commands 
		end_func_command
	;

/*
 * The end of the function rule 
 */
end_func_command 
  : END_FUNCTION 
  ;


main_def
  :	MAIN define_section commands END_MAIN 
  ;

return_cmd 
  : RETURN op_fgl_expr_ret_list 
  ;

op_fgl_expr_list 
  : reset_cnt 
	| reset_cnt fgl_expr_list 
  ;

db_section	
  : DATABASE dbase_name 
	| SCHEMA dbase_name 
  ;

module_globals_section 
  : actual_globals_section 
  ;

actual_globals_section 
  : xglobals_entry
	| actual_globals_section xglobals_entry
  ;

xglobals_entry 
  : globals_entry 
	| module_code  
	| db_section
  ;

globals_entry
  : GLOBALS glob_section 
  ;

glob_section 
  : define_section END_GLOBALS 
  | file_name 
  ;

mem_func_def 
  : MEMBER_FUNCTION identifier MEMBER_OF identifier OPEN_BRACKET
    op_param_var_list CLOSE_BRACKET
    define_section
    op_code commands end_func_command
	;


/* </MAIN_RULE> */


/* <MENU_STATEMENT> */

menu_cmd	
  :	MENU menu_title menu_commands end_menu_command 
  ;


end_menu_command  
  : END_MENU 
  ;

menu_block_command 
  : BEFORE_MENU commands 
  | COMMAND opt_key menu_opt_name menu_optional_desc opt_help_no commands 
  | COMMAND opt_key opt_help_no commands 
  ;

menu_commands 
  : menu_block_command 
	| menu_commands menu_block_command
	;

opt_key	
  :	
	| key_val 

menu_opt_name	
  :	CHAR_VALUE 
  | variable 
  ;

menu_optional_desc	
  :
  | variable 
  | CHAR_VALUE 
	;

next_option_cmd 
  : NEXT_OPTION opt_name 
  ;

show_option_cmd 
  : SHOW_OPTION opt_name_list 
  ;

hide_option_cmd 
  : HIDE_OPTION opt_name_list 
  ;

opt_name	
  :	ALL 
  | CHAR_VALUE 
  | variable 
  ;

opt_name_list	
  :	opt_name
	|	opt_name_list COMMA opt_name 
	;

menu_title 	
  :	variable 
  | CHAR_VALUE
  ;

/* </MENU_STATEMENT> */



menu_def 
  : MENUHANDLER identifier  define_section menu_handler_elements END_MENUHANDLER
  ;

menu_handler_elements 
  : menu_handler_element 
	| menu_handler_elements menu_handler_element
  ;

menu_handler_element 
  : BEFORE_SHOW_MENU commands 
  | ON identifier commands 
  ;

message_cmd 
  : msg_start msg_next 
  ;

msg_next 
  : 
 	| attributes_def op_msg_wait 
 	| msg_wait 
	| gui_message
  ;

gui_message
  : gm_caption
  | gm_icon
  | gm_buttons
  | gm_disable_msg
  | gm_returning_msg 
  ;


msg_start 
  : KWMESSAGE reset_cnt fgl_expr_list 
	;

op_msg_wait 
  : 
	| WAIT_FOR_KEY 
  ;

msg_wait 
  : WAIT_FOR_KEY 
  ;

/*
=====================================================================
                        Source: newvariable.rule
=====================================================================
*/


variable_no_scope: variable {
char buff[256];
char buff2[256];
strcpy(buff,$<str>1);

if (buff[0]>='A'&&buff[0]<='Z'&&buff[1]=='_') {
	strcpy(buff2,&buff[2]);
} else {
	strcpy(buff2,buff);
}

strcpy($<str>$,buff2);
}

;


variable: var_int
{
char buff[256];
char buff2[256];
char c;
int n;

if (strcmp($<str>1,"status")==0) { strcpy($<str>1,"a4gl_status"); }
if (strncmp($<str>1,"sqlca.",6)==0) { 
	char xbuff[256];
	char xbuff2[256];
	strcpy(xbuff,"a4gl_sqlca.");
	strcpy(xbuff2,$<str>1);
	strcat(xbuff,&xbuff2[6]);
	strcpy($<str>1,xbuff);
}
strcpy(buff,$<str>1);
A4GL_lex_printcomment("/* .. var %s*/",buff);
if (buff[0]!=' ') addmap("Use Variable",buff,curr_func,yylineno,infilename);

if (strncmp(buff," ASSOCIATE_",11)!=0) {
 A4GL_convlower(buff);
}

strcpy($<str>$,buff);
A4GL_debug("Checking variable '%s'",buff);
strcpy(buff2,buff);
n=scan_variable(buff2);

  A4GL_debug("scan variable returns -> %d\n",n);

  if (n == -1&&buff[0]!=' ') {
           sprintf(buff2,"'%s' does not represent a defined variable (1)",buff);
           a4gl_yyerror(buff2);
           exit (0);
  }

  strcpy(buff2,$<str>1);


  if (strstr(buff,".*") && n!=-2) {
		char *ptr;
		strcpy(buff,$<str>1);
		printf("WARNING : Using a .* on a non-record - %s\n",$<str>1);
		ptr=strstr(buff,".*");
		*ptr=0;
                
		sprintf($<str>$,"%s",fgl_add_scope(buff,0));
  } else {
                	sprintf($<str>$,"%s",fgl_add_scope($<str>1,0));
  }

 
  mcnt = 0;
}
;


var_int :
	var | DOLLAR var {strcpy($<str>$,$<str>2);}
;

varsetidentdot : var DOT
;

var: 
 varsetidentdot dot_part_var { 
         sprintf ($<str>$, "%s.%s", $<str>1, $<str>2); 
         A4GL_lex_printcomment("/* record building -> %s */\n",$<str>$);
         }
| varsetidentdot identifier OPEN_SQUARE num_list CLOSE_SQUARE {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         A4GL_lex_printcomment("/* OPEN_SQUARE.. */\n");

	if (strcmp($<str>1,"sqlca")==0) {
		strcpy($<str>1,"a4gl_sqlca");
	}
         sprintf(buff,"%s.%s",$<str>1,$<str>2);
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
             sprintf ($<str>$, "%s[%s]", buff, change_arr_elem($<str>4));
             A4GL_lex_printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", $<str>$,num_arr_elem($<str>4),num_arr_elem(arrbuff));
         }
         else
         {
             A4GL_debug ("Is string...");
             sprintf ($<str>$, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", fgl_add_scope(buff,0), (int)scan_variable (buff), $<str>4);
      		dec_counter();

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             A4GL_lex_printcomment ("/*character variable %s*/\n", $<str>$);
         }

         mcnt++;
}

| varsetidentdot identifier OPEN_SQUARE num_list CLOSE_SQUARE OPEN_SQUARE num_list CLOSE_SQUARE {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         A4GL_lex_printcomment("/* OPEN_SQUARE.. */\n");

	if (strcmp($<str>1,"sqlca")==0) {
		strcpy($<str>1,"a4gl_sqlca");
	}
         sprintf(buff,"%s.%s",$<str>1,$<str>2);
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
             sprintf (buff2, "%s[%s]", buff, change_arr_elem($<str>4));
             sprintf ($<str>$, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", fgl_add_scope(buff2,0), (int)scan_variable (buff2), $<str>4);
             A4GL_lex_printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", $<str>$,num_arr_elem($<str>4),num_arr_elem(arrbuff));
      	dec_counter();
         }
         else
         {
		a4gl_yyerror("Expecting an array of chars...");
		YYERROR;

         }

         mcnt++;
}

| array_r_variable
| identifier
| assoc_var_read
;

assoc_var_read  : identifier OPEN_SHEV assoc_sub CLOSE_SHEV
{
char buff2[256];
         if (scan_variable($<str>1)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (3)",$<str>1);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

A4GL_lex_printcomment("/*Associative Variable : %s*/\n",$<str>3);
sprintf($<str>$," ASSOCIATE_%s(%s,1)",upshift($<str>1),$<str>3);
};


assoc_var_write  : identifier OPEN_SHEV assoc_sub CLOSE_SHEV
{
char buff2[256];
         if (scan_variable($<str>1)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (4)",$<str>1);
           a4gl_yyerror(buff2); 
           YYERROR;
         }
A4GL_lex_printcomment("/*Associative Variable : %s*/\n",$<str>3);
sprintf($<str>$," ASSOCIATE_%s(%s,0)",upshift($<str>1),$<str>3);
};

assoc_sub : variable | CHAR_VALUE
;


dot_part_var:
 MULTIPLY | 
 identifier 
;



array_r_variable:
identifier arr_subscripts
{
int type,arrsize,size,level;
char buff2[256];
char arrbuff[256];

  A4GL_debug("ARRAY (array_r_variable) : %s %s",$<str>1,$<str>2);
  //printf("ARRAY (array_r_variable) : %s %s",$<str>1,$<str>2);
  A4GL_lex_printcomment("/*array variable nnn */");
  get_variable_dets ($<str>1,&type,&arrsize,&size,&level,arrbuff);
  A4GL_lex_printcomment("/*here %s %x */",$<str>1,type);
  if (scan_variable($<str>1)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (7)",$<str>1);
           a4gl_yyerror(buff2); 
           YYERROR;

	}


  A4GL_debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

  if (strchr($<str>2,':'))  {
	char lbuff[256];
	char rbuff[256];
	char tmpbuff[256];
	char *ptr;
	strcpy(lbuff,$<str>2);
	strcpy(rbuff,strchr($<str>2,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", $<str>1, change_arr_elem(lbuff));
        sprintf ($<str>$, " a4gl_substr(%s , 0x%x , %s , 0 ) /*1.1*/", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
      	dec_counter();
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
		A4GL_debug("MJA Path 1");
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",$<str>2);
      sprintf ($<str>$, "%s[%s]", $<str>1, change_arr_elem($<str>2));
      A4GL_lex_printcomment ("/* array variable %s*/\n", $<str>$);
    }
  else
    {
             sprintf ($<str>$, " a4gl_substr(%s , %d , %s , 0 ) /*1.2*/", fgl_add_scope($<str>1,0), (int)scan_variable ($<str>1), $<str>2);
             addmap("Use Variable",$<str>1,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", $<str>$);
      	dec_counter();
      	mcnt--;
    }
}

  mcnt++;
}
;




array_r_variable_or_ident:
identifier arr_subscripts
{
  int type,arrsize,size,level;
  //char buff2[256];
  char arrbuff[256];
//printf("ARRAY (array_r_variable) : %s %s",$<str>1,$<str>2);
  A4GL_lex_printcomment("/*array variable nnn */");
  get_variable_dets ($<str>1,&type,&arrsize,&size,&level,arrbuff);
  A4GL_lex_printcomment("/*here %s %x */",$<str>1,type);
  if (scan_variable($<str>1)==-1) {
	sprintf($<str>$,"%s[%s]",$<str>1,$<str>2);
  } else {


  A4GL_debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

  if (strchr($<str>2,':'))  {
	char lbuff[256];
	char rbuff[256];
	char tmpbuff[256];
	char *ptr;
	strcpy(lbuff,$<str>2);
	strcpy(rbuff,strchr($<str>2,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", $<str>1, change_arr_elem(lbuff));
             sprintf ($<str>$, " a4gl_substr(%s , %d , %s , 0 ) /*1.3*/", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
      	dec_counter();
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",$<str>2);
      sprintf ($<str>$, "%s[%s]", $<str>1, change_arr_elem($<str>2));
      A4GL_lex_printcomment ("/* array variable %s*/\n", $<str>$);
    }
  else
    {
             sprintf ($<str>$, " a4gl_substr(%s , %d , %s , 0 ) /*1.4*/", fgl_add_scope($<str>1,0), (int)scan_variable ($<str>1), $<str>2);
             addmap("Use Variable",$<str>1,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", $<str>$);
      	dec_counter();
      	mcnt--;
    }
  }
}

  mcnt++;
}
;






arr_subscripts : 
	OPEN_SQUARE num_list CLOSE_SQUARE {
	 A4GL_debug("---> Subscript or substring");
		strcpy($<str>$,$<str>2);
	}
|
	OPEN_SQUARE num_list CLOSE_SQUARE OPEN_SQUARE num_list CLOSE_SQUARE {
	 A4GL_debug("---> Subscript & substring");
		sprintf($<str>$,"%s:%s",$<str>2,$<str>5);
	}
;


num_list: num_list_element
{
A4GL_debug("List element");
  sprintf ($<str>$, "%s", $<str>1);
}
|num_list COMMA num_list_element
{
A4GL_debug("List element continues");
  sprintf ($<str>$, "%s,%s", $<str>1, $<str>3); 
}

;

num_list_element: arr_expr
{
  sprintf ($<str>$, "%s", $<str>1);
};


let_variable: let_var
{
char buff[256];
char c;
if (strcmp($<str>1,"status")==0) { strcpy($<str>1,"a4gl_status"); }
if (strncmp($<str>1,"sqlca.",6)==0) {
        char xbuff[256];
        char xbuff2[256];
        strcpy(xbuff,"a4gl_sqlca.");
        strcpy(xbuff2,$<str>1);
        strcat(xbuff,&xbuff2[6]);
        strcpy($<str>1,xbuff);
}
strcpy(buff,$<str>1);
addmap("Let Variable",buff,curr_func,yylineno,infilename);
if (strncmp(buff," ASSOCIATE_",11)!=0) {
A4GL_convlower(buff);
}
strcpy($<str>$,buff);
A4GL_lex_printcomment("/* %s */\n",$<str>1);


  if (scan_variable (buff) == -1&&buff[0]!=' ')
    {
      A4GL_lex_printcomment ("/*NOt a variable*/");
      sprintf(buff,"%s is not a variable",$<str>1);
      a4gl_yyerror(buff);
    }


  sprintf($<str>$,"%s",fgl_add_scope($<str>1,0));
  mcnt = 0;
};

let_var: let_array_r_variable {
	 A4GL_debug("Array..");
}
| let_var DOT let_var_dot { sprintf ($<str>$, "%s.%s", $<str>1, $<str>3); }
| let_var DOT identifier OPEN_SQUARE num_list CLOSE_SQUARE
{
  int a;
  int b;
  char buff[256];
  char buff2[256];
  A4GL_lex_printcomment("/*array variable .let. */");
  if (strcmp($<str>1,"status")==0) { strcpy($<str>1,"a4gl_status"); }
  if (strcmp($<str>1,"sqlca")==0) {
        strcpy($<str>1,"a4gl_sqlca");
  }
  sprintf($<str>$,"%s.%s",$<str>1,$<str>3);

         if (scan_variable($<str>$)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",$<str>$);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

  A4GL_debug("?1arrvar=%s",$<str>$);
  b = isarrvariable ($<str>$);
  a = scan_variable ($<str>$);

  A4GL_lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf ($<str>$, "%s.%s[%s-1] ", $<str>1, $<str>3,$<str>5);
      A4GL_lex_printcomment ("/* array variable %s*/\n", $<str>$);
    }
  else
    {
      sprintf(buff,"%s.%s",$<str>1,$<str>3);
      sprintf ($<str>$, " a4gl_let_substr(%s,%d,%s,0) /* M4 */", fgl_add_scope(buff,0), a, $<str>5);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", $<str>$);
    }

  mcnt++;

}
| let_var DOT identifier OPEN_SQUARE num_list CLOSE_SQUARE OPEN_SQUARE num_list CLOSE_SQUARE
{
  int a;
  int b;
  char buff[256];
  char buff2[256];
  A4GL_lex_printcomment("/*array variable .let. */");
  if (strcmp($<str>1,"status")==0) { strcpy($<str>1,"a4gl_status"); }
  if (strcmp($<str>1,"sqlca")==0) {
        strcpy($<str>1,"a4gl_sqlca");
  }
  sprintf($<str>$,"%s.%s",$<str>1,$<str>3);

         if (scan_variable($<str>$)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",$<str>$);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

  A4GL_debug("?1arrvar=%s",$<str>$);
  b = isarrvariable ($<str>$);
  a = scan_variable ($<str>$);

  A4GL_lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (buff, "%s.%s[%s-1] ", $<str>1, $<str>3,$<str>5);
      sprintf ($<str>$, " a4gl_let_substr(%s,%x,%s,0) /* M1 */", fgl_add_scope(buff,0), a, $<str>8);
      A4GL_lex_printcomment ("/* subscript on array variable %s*/\n", $<str>$);
    }
  else
    {
		a4gl_yyerror("I was really hoping for an array");
		YYERROR;

    }

  mcnt++;

}


| identifier
| assoc_var_write
;

let_var_dot :
MULTIPLY 
| identifier 
;

let_array_r_variable:
identifier arr_subscripts
{
/*OPEN_SQUARE num_list CLOSE_SQUARE*/
  int a;
  int b;
  char buff2[256];
  A4GL_lex_printcomment("/*.let. array variable */");

  A4GL_debug("?2 arrvar=%s",$<str>1);
  if (strchr($<str>2,':'))  {
	char lbuff[256];
	char rbuff[256];
	char tmpbuff[256];
	char *ptr;
	strcpy(lbuff,$<str>2);
	strcpy(rbuff,strchr($<str>2,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", $<str>1, change_arr_elem(lbuff));
        sprintf ($<str>$, " a4gl_let_substr(%s,%d,%s,0) /* M2 */", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
  } else {
  	b = isarrvariable ($<str>1);
  	a = scan_variable ($<str>1);

         if (a==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (6)",$<str>1);
           a4gl_yyerror(buff2); 
           YYERROR;
         }


  A4GL_debug("/*a=%d b=%d*/\n",a,b);

  if (b != 0)
    {
      sprintf ($<str>$, "%s[%s]", $<str>1, A4GL_decode_array_string($<str>2));
      A4GL_debug ("/* array variable %s*/\n", $<str>$);
    }
  else
    {
      sprintf ($<str>$, " a4gl_let_substr(%s,%d,%s,0) /* M3 */", fgl_add_scope($<str>1,0), (int)scan_variable ($<str>1), $<str>2);

      addmap("Let Variable",$<str>1,curr_func,yylineno,infilename);
      A4GL_debug ("/*character variable %s*/\n", $<str>$);
    }
 }
  mcnt++;

}
;



op_param_var_list: {
start_bind('f',0);
start_bind('O',0);
strcpy($<str>$,"0");}
| fparam_var_list;


fparam_var_list:	func_def_var {
start_bind('f',$<str>1);
start_bind('O',$<str>1);
sprintf($<str>$,"1");
}
	|	
fparam_var_list COMMA func_def_var {
int c;
c=add_bind('f',$<str>3);
c=add_bind('O',$<str>3);
sprintf($<str>$,"%d",c); 
}
;




ibind_var_list:	ibind_var {
A4GL_lex_printcomment("/*STarted bind %s*/\n",$<str>1);
start_bind('i',$<str>1);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy($<str>$,"");
}
	|	
ibind_var_list COMMA ibind_var {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',$<str>3);
strcpy($<str>$,"");
}
;


func_def_var : identifier | identifier DOT identifier {sprintf($<str>$,"%s.%s",$<str>1,$<str>2);}
;

ibind_var : variable  {A4GL_lex_printcomment("/* Variable */\n");}
	| variable THRU variable { A4GL_debug("Got an ibind thru..."); sprintf($<str>$,"%s\n%s",$<str>1,$<str>3); }
	| CHAR_VALUE 
	| real_number {sprintf($<str>$,"\"%s\"",$<str>1);}
	| INT_VALUE {sprintf($<str>$,"\"%s\"",$<str>1);}
;

obind_var_list:	obind_var  {
start_bind('o',$<str>1);
} 
	|	obind_var_list COMMA obind_var {
add_bind('o',$<str>3);
strcpy($<str>$,"");
}
;

obind_var : variable   {
	addmap("OBIND",$<str>1,curr_func,yylineno,infilename);
	}
	| variable THRU variable { A4GL_debug("Got an obind thru..."); sprintf($<str>$,"%s\n%s",$<str>1,$<str>3); }
;


obind_var_let_list:	obind_let_var  {
A4GL_lex_printcomment("/* start obind with  %s*/\n",$<str>1);
start_bind('o',$<str>1);
} 
	|	obind_var_let_list COMMA obind_let_var {
A4GL_lex_printcomment("/* add to obind %s */\n",$<str>3);
add_bind('o',$<str>3);
strcpy($<str>$,"");
}
;

obind_let_var : let_variable   {
A4GL_lex_printcomment("/* Read variable %s*/\n",$<str>1);
}
;

use_arr_var : variable {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',$<str>1);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
;

obind_var_list_ord:	obind_var_ord  {
start_bind('O',$<str>1);
} 
	| obind_var_list_ord COMMA obind_var_ord {
               add_bind('O',$<str>3);
               strcpy($<str>$,"");
}
;

obind_var_ord : variable optional_asc_desc;

optional_asc_desc: | ASC | DESC;


array_r_varid:
identifier OPEN_SQUARE num_list CLOSE_SQUARE
{
  int type,arrsize,size,level;
  char arrbuff[256];
  A4GL_lex_printcomment("/*..array_r_varid..*/");

//printf("Got array %s %s\n",$<str>1,$<str>3);
if (get_variable_dets ($<str>1,&type,&arrsize,&size,&level,arrbuff)>=0) {
	// Its a variable
	//printf("gvd = true\n");
  sprintf($<str>$,"%s[%s]",$<str>1,subtract_one($<str>3));
} else {
	// Its an sql identifier or similar
	//printf("gvd = false\n");
  sprintf($<str>$,"%s[%s]",$<str>1,$<str>3);
}
//printf("All done - ARRAY (array_r_varid) : %s\n",$<str>$);
}
;

init_bind_var_list:	init_bind_var {
A4GL_lex_printcomment("/*STarted bind %s*/\n",$<str>1);
start_bind('N',$<str>1);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy($<str>$,"");
}
	|	
init_bind_var_list COMMA init_bind_var {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',$<str>3);
strcpy($<str>$,"");
}
;

init_bind_var : variable  {
		strcpy($<str>$,$<str>1);
	}
	| variable THRU variable {
			sprintf($<str>$,"%s\n%s",$<str>1,$<str>3);
		}
;

/* ========================= newvariable.rule ======================= */

/*
=====================================================================
                        Source: open.rule
=====================================================================
*/

open_window_cmd :
	OPEN_WINDOW open_win_name AT coords WITH window_type win_attributes  {
form_attrib.iswindow=1;
print_open_window($<str>2,$<str>6);
sprintf($<str>$,"open window");
}
;

op_at_statusbox : 
	| AT OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET op_size_statusbox
;

op_size_statusbox : 
	| SIZE OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET
;

open_statusbox_cmd :
	OPEN_STATUSBOX identifier op_at_statusbox
{
	print_niy("OPEN_STATUSBOX");
}
;

formhandler_name:identifier {
addmap("Call Formhandler",$<str>1,curr_func,yylineno,infilename); 
}
;
open_form_cmd :
	OPEN_FORM open_form_name  open_form_rest
		{
		print_open_form($<str>3,$<str>2,$<str>2);
		}
;

open_form_rest: open_form_gui
	| FROM fgl_expr 
	{ form_attrib.iswindow=0;strcpy($<str>$,"A4GL_open_form(%s);"); }

;

open_form_gui:  op_at_gui op_like_gui op_disable KW_USING formhandler_name
	{sprintf($<str>$,"A4GL_open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",$<str>1,$<str>2,$<str>3,$<str>5,$<str>5);}
;

op_at_gui:{strcpy($<str>$,"0,0");} | AT op_absolute OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET 
	{sprintf($<str>$,"%s,2",$<str>2);}
;

op_like_gui: {strcpy($<str>$,"\"\"");} |
	LIKE ident_or_var {strcpy($<str>$,$<str>2);}
;

op_absolute: {strcpy($<str>$,"0");}
	| ABSOLUTE {strcpy($<str>$,"1");}
;

open_session_cmd : 
 OPEN_SESSION conn_id TO_DATABASE var_ident user_details
 {
print_open_session($<str>2,$<str>4,$<str>5);

}

;
open_cursor_cmd :
	OPEN cursor_name {
	print_open_cursor($<str>2,"0");
}
	| OPEN cursor_name KW_USING reset_cnt fgl_expr_list {
	print_open_cursor($<str>2,$<str>5); /* CHANGED from $<str>4 */
}
;


user_details :  {sprintf($<str>$,"0,0");}
	| AS USER char_or_var PASSWORD char_or_var
              {sprintf($<str>$,"%s, %s",$<str>3,$<str>5);}
	| AS USER char_or_var COMMA PASSWORD char_or_var
              {sprintf($<str>$,"%s, %s",$<str>3,$<str>6);}
	| AS char_or_var COMMA char_or_var
              {sprintf($<str>$,"%s, %s",$<str>2,$<str>4);}
;

op_disable : {strcpy($<str>$,"0");} | DISABLE_PROGRAM {strcpy($<str>$,"1");}
| DISABLE_ALL {strcpy($<str>$,"2");}
;


connect_cmd :
CONNECT_TO var_ident op_connect_as con_user_details {
	print_open_session($<str>3,$<str>2,$<str>4);
}
;



op_connect_as :
        {strcpy($<str>$,"\"default_conn\"");}
        | AS var_ident {strcpy($<str>$,$<str>2);}

;

con_user_details :
        {sprintf($<str>$,"0,0");}
        | AS USER char_or_var KW_USING char_or_var
              {sprintf($<str>$,"%s, %s",$<str>3,$<str>5);}
        | USER char_or_var KW_USING char_or_var
              {sprintf($<str>$,"%s, %s",$<str>2,$<str>4);}
;

/* ======================= open.rule =========================== */

/*
=====================================================================
                        Source: options.rule
=====================================================================
*/


options_cmd : OPTIONS opt_options;

opt_options : opt_allopts
	| opt_options COMMA opt_allopts;

opt_allopts 	: COMMENT_LINE line_no {
print_options('C',$<str>2);
}
		| ERROR_LINE line_no {
print_options('E',$<str>2);
}
		| FORM_LINE line_no {
print_options('F',$<str>2);
}
		| MENU_LINE line_no {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',$<str>2);
}
		| MSG_LINE line_no {
print_options('m',$<str>2);
}
		| PROMPT_LINE line_no {
print_options('P',$<str>2);
}
		| accept_key {
print_options('A',$<str>1);
iskey=0;
}
		| DELETE single_key_val {
print_options('D',$<str>2);
iskey=0;
}
		| INSERT single_key_val {
print_options('I',$<str>2);
iskey=0;
}
		| NEXT single_key_val {
print_options('N',$<str>2);
}
		| PREVIOUS single_key_val {
print_options('p',$<str>2);
iskey=0;
}
		| HELP single_key_val {
print_options('H',$<str>2);
}
		| HELP_FILE file_name { print_set_helpfile($<str>2); }
		| LANG_FILE file_name { print_set_langfile($<str>2); }
		| DISPLAY attributes_def {
print_options('d',$<str>2);
}
		| INPUT attributes_def {
print_options('i',$<str>2);
}
		| INPUT_WRAP {
print_options('W',"1");
}
		| INPUT_NO_WRAP {
print_options('W',"0");
}
		| FOCONSTR {
print_options('f',"1");
}
		| FOUNCONSTR {
print_options('f',"0");
}
		| SQL_INTERRUPT_ON  {
print_options('S',"1");
}
		| SQL_INTERRUPT_OFF {
print_options('S',"0");
}
;


/* =========================== options.rule =========================== */


/*
=====================================================================
                        Source: prepare.rule
=====================================================================
*/


prepare_cmd : opt_use PREPARE stmt_id FROM var_or_char 
{
	print_prepare($<str>3,$<str>5);
	addmap("Prepare",$<str>3,curr_func,yylineno,infilename);
	print_undo_use($<str>1);
}
;

var_or_char: variable | CHAR_VALUE;

execute_cmd : EXECUTE stmt_id
{

print_execute($<str>2,0);

addmap("Execute",$<str>2,curr_func,yylineno,infilename);
}
            | EXECUTE stmt_id KW_USING ibind_var_list {
	addmap("Execute",$<str>2,curr_func,yylineno,infilename);
	print_execute($<str>2,1);
	}
	| EXECUTE_IMMEDIATE var_or_char {
		print_execute_immediate($<str>2);
	}
;

stmt_id : ident_or_var ;


/* ========================== prepare.rule ========================= */


/*
=====================================================================
                        Source: prompt.rule
=====================================================================
*/

prompt_cmd	:
	PROMPT prompt_title opt_attributes FOR opt_char
        variable opt_timeout opt_help_no
        opt_attributes {
                push_blockcommand("PROMPT");

	print_prompt_1($<str>3,$<str>5,$<str>8,$<str>9,atoi($<str>7)) ;
}
        prompt_key_sec {
		if (strcmp($<str>5,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end($<str>6);
                pop_blockcommand("PROMPT");
                A4GL_lex_printcomment("/* END OF PROMPT */");
                }

;

opt_timeout:  {sprintf($<str>$,"0");}
| TIMEOUT INT_VALUE {sprintf($<str>$,$<str>2);}
;

gui_prompt_cmd :
	PROMPT prompt_title opt_attributes  RETURNING variable {
		print_niy("GUI PROMPT");
	}
;

opt_char : /* empty */ {strcpy($<str>$,"0");}
| CHAR {strcpy($<str>$,"1");}
;


prompt_key_sec :  /* empty */ {strcpy($<str>$,"");}
	| prompt_key_clause END_PROMPT;

prompt_key_clause : on_key_command_prompt
	| prompt_key_clause on_key_command_prompt ;

on_key_command_prompt : on_key_command {
	print_onkey_1($<str>1);
} commands {
	print_onkey_2_prompt();
}
;


prompt_title : fgl_expr_concat;



/* ========================= prompt.rule ============================ */



put_cmd :
        PUT cursor_name  {
		start_bind('i',0);
		}
		put_from
		{
		print_put($<str>2,$<str>4);
	}
;

put_from:
	{strcpy($<str>$,"");} 
| FROM put_val_list { strcpy($<str>$,$<str>2);
A4GL_debug("putlist = %s\n",$<str>$);
}
;

put_val_list  : put_val {push_gen(PUTVAL,$<str>1);} | 
                put_val_list COMMA put_val {push_gen(PUTVAL,$<str>3); sprintf($<str>$,"%s,%s",$<str>1,$<str>3);} 
;

put_val : value_expression_ss {
	char buff[256];	
	strcpy(buff,$<sql_string>1);
	A4GL_debug("put buff=%s\n",buff);
	if (buff[0]!='\''&&strncmp(buff,"?",1)!=0&&strncmp(buff," :",2)!=0) {
		A4GL_debug("Got : %s - expecting '..', : or ?",buff);
 		a4gl_yyerror("Put values must be variables, strings or 'NULL'");
		YYERROR;
	}

	A4GL_add_put_string(buff);
	strcpy($<str>$,buff);

} | KW_NULL 


;



/*
=====================================================================
                        Source: report.rule
=====================================================================
*/


start_cmd : START_REPORT rep_name TO_PRINTER
{
addmap("Start Report",$<str>2,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",$<str>2);
}
	    | START_REPORT rep_name TO rout
{
addmap("Start Report",$<str>2,curr_func,yylineno,infilename);
print_start_report("F",$<str>4,$<str>2);
}
	    | START_REPORT rep_name TO_PIPE rout
{
addmap("Start Report",$<str>2,curr_func,yylineno,infilename);
print_start_report("P",$<str>4,$<str>2);
}
	    | START_REPORT rep_name
{
addmap("Start Report",$<str>2,curr_func,yylineno,infilename);
print_start_report("","\"\"",$<str>2);
}
;




rout : CHAR_VALUE | cvariable;



rep_name : identifier;


op_values : | VALUES ;

output_cmd : OUTPUT_TO_REPORT rep_name op_values  OPEN_BRACKET 
reset_cnt 
op_fgl_expr_list 
CLOSE_BRACKET
{
addmap("Output to report",$<str>2,curr_func,yylineno,infilename);
print_output_to_report($<str>2,$<str>6); 
}
;

finish_cmd : FINISH_REPORT rep_name
{
addmap("Finish Report",$<str>2,curr_func,yylineno,infilename);
print_finish_report($<str>2);
}
;



term_rep_cmd : TERMINATE_REPORT rep_name
{
addmap("Finish Report",$<str>2,curr_func,yylineno,infilename);
print_terminate_report($<str>2);
}
;

report_section: op_output_section op_rep_order_by  { strcpy($<str>$,$<str>2); } ;

format_section: FORMAT EVERY_ROW {
	print_format_every_row();
}
| 
FORMAT format_actions
;

format_actions : format_action | format_actions format_action;

format_action :
	 FIRST_PAGE_HEADER 
{ push_report_block("FIRST",'P');}
commands {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
	| PAGE_TRAILER
{ push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
commands {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
	| PAGE_HEADER 
{ push_report_block("HEADER",'p');}
commands {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
	| ON_EVERY_ROW 
{ push_report_block("EVERY",'E');}
commands {print_rep_ret(0);}
	| ON_LAST_ROW 
{ push_report_block("LAST",'L');}
commands {print_rep_ret(0);}
	| BEFGROUP variable  {
int a;
char buff[80];
A4GL_debug("rordcnt=%d",rordcnt);
a=scan_orderby($<str>2,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",$<str>2);
   a4gl_yyerror(buff);
	YYERROR;
}
sprintf(buff,"%d",a+1);
push_report_block(buff,'B');
set_curr_block(a+1);
}
commands {print_rep_ret(0);}
	| AFTGROUP variable
{ 
int a;
char buff[80];

A4GL_debug("rordcnt=%d",rordcnt);
a=scan_orderby($<str>2,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",$<str>2);
   a4gl_yyerror(buff);
	YYERROR;
}

sprintf(buff,"%d",a+1);
push_report_block(buff,'A');
set_curr_block(a+1);

}
commands {print_rep_ret(0);}
;

report_cmd : 
	print_command 
	| print_img_command
	| print_file_command
	| need_command
	| pause_command
	| skip_command
;

need_command : NEED fgl_expr {start_state("skip",1);} KWLINE {
	print_need_lines();
	start_state("skip",0);
}
;

op_lines : {strcpy($<str>$,"0");} | KWLINE {strcpy($<str>$,"1");}
;

skip_command : SKIP INT_VALUE {start_state("KWLINE",1);} op_lines {
double n;
char buff[256];
strcpy(buff,$<str>4);
n=atof($<str>2);
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
	| SKIP_TO_TOP { print_skip_top(); }
	| FONT_SIZE nval { print_niy("FONT SIZE"); }
	| SKIP_BY nval {
		double n;
			n=atof($<str>2);
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(n);
		}
	| SKIP_TO nval {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to($<str>2);
		}


;


opt_rep_expr_list : {strcpy($<str>$,"");}
	| xrep_expr_list
;

xrep_expr_list: xxrep_expr_list
	| xrep_expr_list xxrep_expr_list
;

xxrep_expr_list : rep_expr_list opt_print_at 
;

opt_print_at : | AT nval {
	print_niy("PRINT AT...");
}
;

print_command : PRINT opt_rep_expr_list opt_semi {
	char wt;
	print_report_print(0,$<str>3,0);
	wt=get_curr_report_stack_whytype();
	if (strcmp($<str>3,"0")==0) {
		if (wt=='P'||wt=='p'||wt=='T') { /* Page header or trailer */
			if (isin_command("WHILE")||isin_command("FOR")) {
				a4gl_yyerror("You can't print within a loop in a PAGE HEADER or PAGE TRAILER");
				YYERROR;
			}
		}
	}
	if (strcmp($<str>3,"0")==0) {
			if (if_print_stack_cnt==0) if_print_section[0]=0;
		if (get_curr_report_stack_whytype()=='T') {
			if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=1;
		}
	}
} ;

print_file_command : PRINT_FILE char_or_var opt_semi { 
	print_report_print_file($<str>2,$<str>3);
} ;


print_img_command : PRINT_IMAGE blob_var img_types opt_scaling opt_semi { 
	print_report_print_img($<str>4,$<str>2,$<str>3,$<str>5);
} 
;

opt_scaling :
	{ strcpy($<str>$,A4GL_get_default_scaling());}
	| SCALED_BY fgl_expr_c { strcpy($<str>$,$<str>2); strcat($<str>$,$<str>2); }
	| SCALED_BY fgl_expr_c COMMA fgl_expr_c {sprintf($<str>$,"%s %s",$<str>2,$<str>4);}
;

img_types : 	
	AS_TIFF {strcpy($<str>$,"tiff");}
	| AS_GIF {strcpy($<str>$,"gif");}
	| AS_PNG {strcpy($<str>$,"png");}
	| AS_JPEG {strcpy($<str>$,"jpeg");}
;


blob_var :  variable {
	int vtype;
	vtype=scan_variable($<str>1);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
;

opt_semi : {
strcpy($<str>$,"0");
} | SEMICOLON {
strcpy($<str>$,"1");
};

rep_expr_list : 
	rep_expr {
	print_report_print(1,0,$<str>1);
	} 
| rep_expr_list COMMA rep_expr {
	print_report_print(1,0,$<str>3); /* changed from $<str>1 */
}
;

rep_expr : fgl_expr op_wordwrap {
	strcpy($<str>$,$<str>2); 
	}
;

rep_agg : 
SUM OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
{
int a;
a=add_report_agg('S',$<ptr>3,$<ptr>5,racnt);
sprintf($<str>$,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
| COUNT_MULTIPLY rep_where
{
int a;
a=add_report_agg('C',0,$<ptr>2,racnt);
sprintf($<str>$,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
| COUNT OPEN_BRACKET MULTIPLY CLOSE_BRACKET rep_where
{
int a;
a=add_report_agg('C',0,$<ptr>5,racnt);
sprintf($<str>$,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}


| PERCENT   OPEN_BRACKET MULTIPLY CLOSE_BRACKET  rep_where
{
int a;
a=add_report_agg('P',$<ptr>3,$<ptr>5,racnt);
sprintf($<str>$,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
| AVERAGE   OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
{
int a;
a=add_report_agg('A',$<ptr>3,$<ptr>5,racnt);
sprintf($<str>$,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
| AVG       OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
{
int a;
a=add_report_agg('A',$<ptr>3,$<ptr>5,racnt);
sprintf($<str>$,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
| XMIN       OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
{
int a;
a=add_report_agg('N',$<ptr>3,$<ptr>5,racnt);
sprintf($<str>$,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
| XMAX       OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
{
int a;
a=add_report_agg('X',$<ptr>3,$<ptr>5,racnt);
sprintf($<str>$,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
;

op_output_section : | OUTPUT output_commands ;

output_commands : output_command | output_commands output_command;

output_command : 
  LEFT_MARGIN INT_VALUE {rep_struct.left_margin=atoi($<str>2);}
| RIGHT_MARGIN INT_VALUE {rep_struct.right_margin=atoi($<str>2);}
| TOP_MARGIN INT_VALUE {rep_struct.top_margin=atoi($<str>2);}
| BOTTOM_MARGIN INT_VALUE {rep_struct.bottom_margin=atoi($<str>2);}
| PAGE_LENGTH INT_VALUE {rep_struct.page_length=atoi($<str>2);}
| REPORT_TO_PRINTER  { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
| REPORT_TO CHAR_VALUE {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,$<str>2);}
| REPORT_TO variable {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,$<str>2);}
| REPORT_TO_PIPE CHAR_VALUE {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,$<str>2);}
| TOP_OF_PAGE CHAR_VALUE {strcpy(rep_struct.top_of_page,$<str>2);}
;

pdf_output_commands : pdf_output_command | pdf_output_commands pdf_output_command;


nval: nval_number POINTS {sprintf($<str>$,"-%f",atof($<str>1));}
	| nval_number INCHES {sprintf($<str>$,"-%f",atof($<str>1)*72.0); }
	| nval_number MM     {sprintf($<str>$,"-%f",atof($<str>1)*2.83465);}
	| nval_number        {sprintf($<str>$,"%f",atof($<str>1));} 
;

nval_number: real_number | INT_VALUE
;

pdf_op_output_section : | OUTPUT pdf_output_commands ;

pdf_output_command : 
  LEFT_MARGIN nval {pdf_rep_struct.left_margin=atof($<str>2);A4GL_debug("Left margin=%s\n",$<str>2);}
| RIGHT_MARGIN nval {pdf_rep_struct.right_margin=atof($<str>2);}
| TOP_MARGIN nval {pdf_rep_struct.top_margin=atof($<str>2);}
| BOTTOM_MARGIN nval {pdf_rep_struct.bottom_margin=atof($<str>2);}
| PAGE_LENGTH nval {pdf_rep_struct.page_length=atof($<str>2);}
| PAGE_WIDTH nval {pdf_rep_struct.page_width=atof($<str>2);}
| FONT_NAME CHAR_VALUE {strcpy(pdf_rep_struct.font_name,$<str>2);}
| FONT_SIZE nval {pdf_rep_struct.font_size=atof($<str>2);}

| PAPER_SIZE_IS_A4  {pdf_rep_struct.paper_size=1;}
| PAPER_SIZE_IS_LETTER  {pdf_rep_struct.paper_size=2;}
| PAPER_SIZE_IS_LEGAL  {pdf_rep_struct.paper_size=3;}
| PAPER_SIZE_IS_A5  {pdf_rep_struct.paper_size=5;}

| PAPER_SIZE_IS_A4_L  {pdf_rep_struct.paper_size=-1;}
| PAPER_SIZE_IS_LETTER_L  {pdf_rep_struct.paper_size=-2;}
| PAPER_SIZE_IS_LEGAL_L  {pdf_rep_struct.paper_size=-3;}
| PAPER_SIZE_IS_A5_L  {pdf_rep_struct.paper_size=-5;}

| PAGE_TRAILER_SIZE nval 
| PAGE_HEADER_SIZE nval 
| FIRST_PAGE_HEADER_SIZE nval 
| REPORT_TO CHAR_VALUE {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,$<str>2);}
| REPORT_TO_PIPE CHAR_VALUE {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,$<str>2);}
| DEFAULT
| ASCII_HEIGHT_ALL
| ASCII_WIDTH_ALL
;


op_rep_order_by : {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf($<str>$,"%d",a);
}
| ORDER BY obind_var_list_ord
{
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf($<str>$,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
| ORDER_EXTERNAL_BY obind_var_list_ord {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf($<str>$,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
;


report_def : REPORT 
	{ 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
	identifier 
	OPEN_BRACKET
	{
		inc_report_cnt();
		sprintf(curr_func,"%s",$<str>3);
		addmap("Define Report",curr_func,"MODULE",yylineno,infilename);
		variable_action(-1,$<str>3,"","","add_function");
		set_curr_rep_name($<str>3);
		print_report_1($<str>3);
		push_blockcommand("REPORT");
		}
	op_param_var_list 
	CLOSE_BRACKET 
	{
		lastlineno=yylineno;
		}
	define_section 
	{
		print_variables();
		}
	report_section 
	{
		print_report_2(0,$<str>11);
		rordcnt=atoi($<str>11);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,$<str>11);
		}
	format_section 
	{
		print_report_ctrl();
		}

	END_REPORT 
	{
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
;



rep_where :  { strcpy($<str>$,"");
	$<ptr>$=0;
}
| WHERE fgl_expr_c {
	$<ptr>$=$<ptr>2;
//sprintf($<str>$,"%s", $<str>2);
}
;



pause_command: PAUSE pause_msg
{
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause($<str>2) ;
}

;

pause_msg : {strcpy($<str>$,"\"\"");}
	|
	var_or_char 
;

pdf_report_def : 
PDF_REPORT 
{
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
identifier OPEN_BRACKET
{
inc_report_cnt();
variable_action(-1,$<str>3,"","","add_function");
sprintf(curr_func,"%s",$<str>3);
addmap("Define PDF Report",curr_func,"MODULE",yylineno,infilename);
set_curr_rep_name($<str>3);
print_report_1($<str>3);
push_blockcommand("REPORT");
}
op_param_var_list CLOSE_BRACKET 
{
lastlineno=yylineno;
}
define_section  {
	print_variables();
}
pdf_report_section 
{
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,$<str>11);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,$<str>11);
	rordcnt=atoi($<str>11);
}
format_section 
{
print_report_ctrl();
}
END_REPORT {
	pop_blockcommand("REPORT");
	print_report_end();
}
;

pdf_report_section: pdf_op_output_section op_rep_order_by  { strcpy($<str>$,$<str>2); } ;


pdf_functions :
	PDF_FUNCTION OPEN_BRACKET CHAR_VALUE COMMA {new_counter();
   		addmap("CALL",$<str>3,curr_func,yylineno,infilename);
   		}
   		opt_func_call_args
   		{
		sprintf($<str>$,"%d",get_counter_val());drop_counter();
		}
   		CLOSE_BRACKET
   		{
		print_pdf_call($<str>3,$<ptr>6,$<str>7);
   		}
   		opt_return
   		{
	print_returning();
   }
;

op_wordwrap:
	{strcpy($<str>$,"0");}
 	| WORDWRAP { strcpy($<str>$,"rep.right_margin"); }
	| WORDWRAP RIGHT_MARGIN INT_VALUE { sprintf($<str>$,"%s",$<str>3); }
	| WORDWRAP RIGHT_MARGIN variable { sprintf($<str>$,"%s",$<str>3); }
;

/* ============================ report.rule ========================== */

run_cmd : RUN fgl_expr {
print_system_run(0,0);
} | RUN fgl_expr RETURNING variable {
print_system_run(1,$<str>4);
} | 
RUN fgl_expr WITHOUT_WAITING {
print_system_run(2,0);
}
|
RUN fgl_expr WAIT {
print_system_run(0,0);
}
| RUN fgl_expr EXIT {
print_system_run(0,0);
/* FIXME */
}
;


drops_cmd : drops_c {
	print_exec_sql($<str>1);
}
;

drops_c : DROP_TABLE  {sprintf($<str>$, "%s",$<str>1);}
	| DROP_VIEW  {sprintf($<str>$,  "%s",$<str>1);}
	| DROP_INDEX  {sprintf($<str>$,"%s",$<str>1);}
;


create_cmd : 
	create_c_1 { print_exec_sql($<str>1); }
	| create_c_2_ss { print_exec_sql($<sql_string>1); 
	free($<sql_string>1);
}
;

create_c_2_ss  : 
	CREATE_TABLE {insql=1;} table_name OPEN_BRACKET {insql=0;} table_element_list_ss CLOSE_BRACKET {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>3," ",$<str>4,$<sql_string>6,$<str>7,0);
		free($<sql_string>6);
	} 

	| CREATE_TEMP_TABLE {insql=1;} table_name OPEN_BRACKET {insql=0;} table_element_list_ss CLOSE_BRACKET op_no_log {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>3," ",$<str>4,$<sql_string>6,$<str>7, " ",$<str>8,0);
		free($<sql_string>6);

}

;



create_c_1  : 
	CREATE_IDX idx_column_list CLOSE_BRACKET {sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);} 
	| CREATE_DATABASE ident_or_var {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
	;

op_no_log : 
{strcpy($<str>$,"");} 
| WITH_NO_LOG
{
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy($<str>$,"");
} else {
	sprintf($<str>$," %s ",$<str>1);
}
}
;


idx_column_list : 
idx_column | 
idx_column_list COMMA idx_column 
{sprintf($<str>$,"%s,%s",$<str>1,$<str>3);}
;

idx_column : 
 identifier ASC {sprintf($<str>$,"%s ASC",$<str>1);}
| identifier DESC {sprintf($<str>$,"%s DESC",$<str>1);}
| identifier;


table_element_list_ss:
  	table_element_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| table_element_list_ss COMMA table_element_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
	}
;
	
table_element_ss:
	  ct_column_definiton_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| table_constraint_definition_ss {
		$<sql_string>$=$<sql_string>1;
	}
	;
	


upd_stats_cmd : 
	UPDATESTATS_T	identifier {sprintf($<str>$,"%s %s",$<str>1,$<str>2);}
	| UPDATESTATS	
;




alter_cmd : ALTER_TABLE identifier alter_clauses_ss {
	$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<sql_string>3,0);
	print_exec_sql($<sql_string>$); 
}
;

alter_clauses_ss:
	alter_clause_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| alter_clauses_ss COMMA alter_clause_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
	}


;


alter_clause_ss:
	alter_add_clause_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| alter_drop_clause {
		$<sql_string>$=strdup($<str>1);
	}
	| alter_modify_clause {
		$<sql_string>$=strdup($<str>1);
	}
	| alter_add_constraint_clause {
		$<sql_string>$=strdup($<str>1);
	}
	| alter_drop_contraint_clause {
		$<sql_string>$=strdup($<str>1);
	}
	| alter_modify_next {
		$<sql_string>$=strdup($<str>1);
	}
	| alter_lock_mode {
		$<sql_string>$=strdup($<str>1);
	}
;


alter_add_clause_ss:
	ADD add_column_clause_ss  {
		$<sql_string>$=make_sql_string("ADD ",$<sql_string>2,0);
	}
	| ADD OPEN_BRACKET add_column_clauses_ss CLOSE_BRACKET {
		$<sql_string>$=make_sql_string("ADD (",$<sql_string>3,")",0);
	}
;


add_column_clause_ss:
	table_element_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| table_element_ss BEFORE identifier {
		$<sql_string>$=make_sql_string($<sql_string>1," BEFORE ",$<str>3,0);
	}
;

add_column_clauses_ss:
	add_column_clause_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| add_column_clauses_ss COMMA add_column_clause_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
	}
;


alter_drop_clause:
	DROP drop_column {
		sprintf($<str>$,"DROP %s",$<str>2);
	}
	| DROP OPEN_BRACKET drop_column_list CLOSE_BRACKET {
		sprintf($<str>$,"DROP (%s)",$<str>3);
	}
;


drop_column_list:
	drop_column 
	| drop_column_list COMMA drop_column {
		sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
	}
;

drop_column : identifier
;

alter_modify_clause :
	MODIFY modify_column_clause_ss {
		sprintf($<str>$,"MODIFY %s",$<sql_string>2);
	}
	| MODIFY OPEN_BRACKET modify_column_clauses_ss CLOSE_BRACKET {
		sprintf($<str>$,"MODIFY (%s)",$<sql_string>3);
	}
;

modify_column_clauses_ss :
	modify_column_clause_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| modify_column_clauses_ss COMMA modify_column_clause_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
	}
;

modify_column_clause_ss :
	table_element_ss {
		$<sql_string>$=$<sql_string>1;
	}
;


alter_lock_mode :
	LOCK_MODE_PAGE {strcpy($<str>$,"LOCK MODE PAGE");}
	| LOCK_MODE_ROW {strcpy($<str>$,"LOCK MODE ROW");}
;

alter_modify_next :
	MODIFY_NEXT_SIZE INT_VALUE {
		sprintf($<str>$,"MODIFT NEXT SIZE %d",atoi($<str>2));
	}
;

alter_add_constraint_clause:
	ADD_CONSTRAINT column_constraint_ss {
		sprintf($<str>$,"ADD CONSTRAINT %s",$<sql_string>2);
	}
	| ADD_CONSTRAINT OPEN_BRACKET column_constraints_ss CLOSE_BRACKET {
		sprintf($<str>$,"ADD CONSTRAINT (%s)",$<sql_string>3);
	}
;


alter_drop_contraint_clause:
	DROP_CONSTRAINT constraint_name
	| DROP_CONSTRAINT OPEN_BRACKET column_constraints_ss CLOSE_BRACKET {
		sprintf($<str>$,"ADD CONSTRAINT (%s)",$<sql_string>3);
	}
;


column_constraints_ss:
	column_constraint_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| column_constraints_ss COMMA column_constraint_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
	}
;

constraint_name: identifier
;

/*
=====================================================================
                        Source: set.rule
=====================================================================
*/


set_cmd :
SQLSEON
| SQLSEOFF
| SQLSLMW op_fgl_expr {sprintf($<str>$,"%s %s /*FIXME */",$<str>1,$<str>2);}
| SQLSLMNW 
| SQLSIDR
| SQLSIRR
| SQLSICS
| SQLSICR
| SET_SESSION_TO conn_id { 
	print_set_conn($<str>2);
}
| SET_SESSION op_conn_id OPTION char_or_var TO char_or_var {
	print_set_options("conn",$<str>2,$<str>4,$<str>6);
}
| SET_CURSOR cursor_name OPTION char_or_var TO char_or_var {
	print_set_options("stmt",$<str>2,$<str>4,$<str>6);
}
;

op_conn_id : 
{strcpy($<str>$,"\"default\"");} | conn_id;




op_fgl_expr :
{strcpy($<str>$,"");} | fgl_expr;


/* ================================================================ */

/*
=====================================================================
                        Source: sleep.rule
=====================================================================
*/

sleep_cmd : SLEEP fgl_expr {
		print_sleep();
	}
;


/*
=====================================================================
                        Source: sql1.rule
=====================================================================
*/

rollback_statement:
	ROLLBACK_W 
		{
		print_sql_commit(0);
		}
	;




insert_statement_ss:
INSERT_INTO { insql=1;start_bind('i',0);} table_name op_insert_column_list ins_2_ss {
	$<sql_string>$=make_sql_string($<str>1," ",$<str>3," ",$<str>4," ",$<sql_string>5,0);
}
;

ins_2_ss : VALUES {insql=1;} OPEN_BRACKET insert_value_list_ss CLOSE_BRACKET {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
$<sql_string>$=make_sql_string($<str>1," (",$<sql_string>4,")",0);}
	| query_specification_ss
		{$<sql_string>$=$<sql_string>1;}
	;

op_insert_column_list: {strcpy($<str>$,"");}
	| OPEN_BRACKET insert_column_list CLOSE_BRACKET
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;


insert_column_list:
	column_name
	| insert_column_list COMMA column_name
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
;

insert_value_list_ss:
	insert_value_ss {
		$<sql_string>$=$<sql_string>1;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
	| insert_value_list_ss COMMA insert_value_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,",", $<sql_string>3,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
;

insert_value_ss:
	value_expression_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| KW_NULL {
		$<sql_string>$=strdup("NULL");
	}
	;

fetch_statement:
	FETCH 
    {
      print_fetch_1();
    } 
  fetch_part 
    {
      print_fetch_2();
    } 
	opt_into_fetch_part
    {
      print_fetch_3($<str>3,$<str>5);
    }
;

declare_cursor_name  :       ident_or_var {sprintf($<str>$,"%s",$<str>1);doing_declare=1;}
;

fetch_part: 
	fetch_place  fetch_cursor_name
{sprintf($<str>$,"%s, %s",$<str>2,$<str>1);
addmap("Fetch Cursor",$<str>2,curr_func,yylineno,infilename);
}
        | fetch_cursor_name
{sprintf($<str>$,"%s, %d, 1",$<str>1,FETCH_RELATIVE);

addmap("Fetch Cursor",$<str>1,curr_func,yylineno,infilename);
}
;

opt_into_fetch_part: {
A4GL_debug("no into\n");
strcpy($<str>$,"0,0");
} | 
	INTO {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    obind_var_list 
{
	int no;
	no=print_bind('o');
	sprintf($<str>$,"%d,obind",no);
}
;

opt_foreach_into_fetch_part: {
A4GL_debug("no into\n");
strcpy($<str>$,"0,0");
} | 
	INTO {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
        obind_var_list {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
;

fetch_place : 
	FIRST {
		sprintf($<str>$,"%d,1",FETCH_ABSOLUTE);}
	| LAST
		{sprintf($<str>$,"%d,-1",FETCH_ABSOLUTE);}
	| NEXT
		{sprintf($<str>$,"%d,1",FETCH_RELATIVE);}
	| PREVIOUS
		{sprintf($<str>$,"%d,-1",FETCH_RELATIVE);}
	| PRIOR
		{sprintf($<str>$,"%d,-1",FETCH_RELATIVE);}
	| CURRENT
		{sprintf($<str>$,"%d,0",FETCH_RELATIVE);}
	| RELATIVE fgl_expr
		{sprintf($<str>$,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
	| ABSOLUTE fgl_expr
		{sprintf($<str>$,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
;


delete_statement_position:
	DELETE_FROM table_name WHERE_CURRENT_OF fetch_cursor_name
{
 
rm_quotes($<str>4);
sprintf($<str>$," %s %s %s %s ",$<str>1,$<str>2,$<str>3,$<str>4
);}
	;


delete_statement_search_ss:
	DELETE_FROM table_name op_where_clause_ss
              {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<sql_string>3,0);
		}
	;

order_by_clause:
	ORDER BY sort_specification_list
	{sprintf($<str>$,"%s %s %s",$<str>1,$<str>2,$<str>3);}
	;

sort_specification_list:
	sort_specification
	| sort_specification_list COMMA sort_specification
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

sort_specification: sort_spec op_asc_desc {sprintf($<str>$,"%s %s",$<str>1,$<str>2);}
;

sort_spec: INT_VALUE 
	| column_name 
	;

op_asc_desc: {strcpy($<str>$,"");}
	| ASC 
	| DESC
	;

begin_statement: BEGIN_WORK {
print_sql_commit(-1);
};

commit_statement:
	COMMIT_W {
		print_sql_commit(1);
	}
	;


op_exclusive :
		{strcpy($<str>$,"");}
	|	EXCLUSIVE {
		strcpy($<str>$,"EXCLUSIVE");
	}
;

set_database_cmd : 
       DATABASE var_ident_qchar op_exclusive
{
if (strcmp($<str>2,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn($<str>2);
}
}

;


var_ident_qchar: var_ident {strcpy($<str>$,$<str>1);}
	| CHAR_VALUE {strcpy($<str>$, A4GL_strip_quotes ($<str>1));}
;

sql_cmd : opt_use {insql=1;} sql_commands {
print_undo_use($<str>1);
insql=0;strcpy($<str>$,$<str>3);}
;

sql_commands :  schema_ss {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql($<sql_string>1);
			strcpy($<str>$,"Schema");
	} 
	| schema_element_ss {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql($<sql_string>1);
		strcpy($<str>$,"Schema Element");
	} 
	| commit_statement 
	| misc_sql {
		print_exec_sql($<str>1);
 	}
	| begin_statement 
	| delete_statement_position {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound($<str>1);
		strcpy($<str>$,"Delete where current...");
	} 
	| delete_statement_search_ss {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound($<sql_string>1);
		strcpy($<str>$,"Delete where ...");
	} 
	| fetch_statement {
		strcpy($<str>$,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	} 
	| insert_statement_ss {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound($<sql_string>1);
		strcpy($<str>$,"insert");
	} 
	| rollback_statement 
	| select_statement_full_ss {
		print_do_select($<sql_string>1);
		strcpy($<str>$,"select");
	} 
	| update_statement_ss {
		print_exec_sql_bound($<sql_string>1);
		strcpy($<str>$,"update");
	} 
	;

privilege_definition:
	GRANT privileges ON table_name TO grantee_list op_with_grant_option
{sprintf($<str>$," %s %s %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5,$<str>6,$<str>7);}
	;

op_with_grant_option: {strcpy($<str>$,"");}
	| WITH_GRANT_OPTION
{sprintf($<str>$," %s ",$<str>1);}
	;

privileges:
	ALL_PRIVILEGES
{sprintf($<str>$," %s ",$<str>1);}
	| action_list
	;

action_list:
	action
	| action_list COMMA action
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

action: SELECT
	| INSERT
	| DELETE
	| UPDATE op_grant_column_list
{sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	;

op_grant_column_list: {strcpy($<str>$,"");}
	| OPEN_BRACKET grant_column_list CLOSE_BRACKET
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

grant_column_list:
	  column_name
	| grant_column_list COMMA column_name
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

grantee_list:
	  grantee
	| grantee_list COMMA grantee
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

grantee:
	PUBLIC
	| authorization_identifier
	;


view_definition_ss:
	CREATE_VIEW table_name op_view_column_list AS query_specification_ss op_with_check_option {
$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<str>3," ",$<str>4," ",$<sql_string>5," ",$<str>6,0);
}
;

op_view_column_list: {strcpy($<str>$,"");}
	| OPEN_BRACKET view_column_list CLOSE_BRACKET
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

view_column_list:
	column_name
	| view_column_list COMMA column_name
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

op_with_check_option: {strcpy($<str>$,"");}
	| WITH_CHECK_OPTION
	;


check_constraint_definition_ss:
	CHECK OPEN_BRACKET search_condition_ss CLOSE_BRACKET {
		$<sql_string>$=make_sql_string("CHECK(",$<sql_string>3,")",0);
	}
	;


referential_constraint_definition:
	FOREIGN_KEY OPEN_BRACKET references_columns CLOSE_BRACKET references_specification
{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
	;

references_specification:
	REFERENCES referenced_table_and_columns
{sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	;

references_columns:
	references_column_list
	;

referenced_table_and_columns:
	  table_name
	| table_name OPEN_BRACKET references_column_list CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	;

references_column_list:
	  column_name
	| references_column_list COMMA column_name
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;


unique_constraint_definition:
	  UNIQUE OPEN_BRACKET unique_column_list CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	| PRIMARY_KEY OPEN_BRACKET unique_column_list CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	;

unique_column_list:
	  column_name
	| unique_column_list COMMA column_name
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;
	

table_constraint_definition_ss:
	unique_constraint_definition {
		$<sql_string>$=strdup($<str>1);
	}
	| referential_constraint_definition {
		$<sql_string>$=strdup($<str>1);
	}
	| check_constraint_definition_ss  {
		$<sql_string>$=$<sql_string>1;
	}
	;


default_clause:
	  DEFAULT literal
{sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	| DEFAULT_NULL
{sprintf($<str>$," %s",$<str>1);}
	;


/*
column_definiton_ss:
	column_name data_type op_default_clause op_column_constraint_list_ss {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<str>3," ",$<sql_string>4,0);
	}
	;
*/

ct_column_definiton_ss:
	identifier data_type op_default_clause op_column_constraint_list_ss {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<str>3," ",$<sql_string>4,0);
	}
;

op_default_clause: {strcpy($<str>$,"");}
	|default_clause
;

op_column_constraint_list_ss: {
		$<sql_string>$=strdup("");
	} | column_constraint_list_ss {
		$<sql_string>$=$<sql_string>1;
	}
;


column_constraint_list_ss :
	column_constraint_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| column_constraint_list_ss column_constraint_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,$<sql_string>2,0);
	}
;

column_constraint_ss:
	  NOT_NULL {
		sprintf($<str>$," %s ",$<str>1);
		$<sql_string>$=strdup($<str>$);
	}
	| NOT_NULL_UNIQUE {
		sprintf($<str>$," %s ",$<str>1);
		$<sql_string>$=strdup($<str>$);
	}
	| UNIQUE {
		sprintf($<str>$," %s ",$<str>1);
		$<sql_string>$=strdup($<str>$);
	}
	| references_specification {
		$<sql_string>$=strdup($<str>1);
	}
	| CHECK OPEN_BRACKET search_condition_ss CLOSE_BRACKET {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<sql_string>3," ",$<str>4,0);
	}
	;


schema_ss:
	CREATE_SCHEMA schema_authorization_clause schema_element_list_ss
{
$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<str>3,0);
}
	;

schema_authorization_clause:
	schema_authorization_identifier
{sprintf($<str>$," %s",$<str>1);}
	;

schema_authorization_identifier:
	authorization_identifier
	;

schema_element_list_ss:
	  schema_element_ss
	| schema_element_list_ss schema_element_ss {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<sql_string>2,0);
	}
	;

schema_element_ss:
	view_definition_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| privilege_definition {
		$<sql_string>$=strdup($<str>1);
	}
	;






having_clause_ss:
	HAVING search_condition_ss {
		$<sql_string>$=make_sql_string($<str>1," ",$<sql_string>2,0);
	}
;


group_by_clause_ss:
	GROUP_BY column_specification_list_ss {
		$<sql_string>$=make_sql_string("GROUP BY ",$<sql_string>2,0);
	}
;

column_specification_list_ss:
	  column_specification_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| column_specification_list_ss COMMA column_specification_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
	}
;


where_clause_ss:
	WHERE search_condition_ss {
		$<sql_string>$=make_sql_string("WHERE ",$<sql_string>2,0);
	}
;


from_clause:
	FROM table_reference_list {
		sprintf($<str>$,"%s %s",$<str>1,$<str>2);
	}
;

table_reference_list:
	  table_reference
	| table_reference_list COMMA table_reference {
		sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);
	}
	;

table_reference:
	  tname {sprintf($<str>$," %s ", $<str>1);}
	| OUTER tname {sprintf($<str>$," %s %s ",$<str>1,$<str>2);}
	| OUTER OPEN_BRACKET tname_list  CLOSE_BRACKET {sprintf($<str>$," %s (%s) ",$<str>1,$<str>3);}
	;

tname: table_name
	| table_name correlation_name {sprintf($<str>$,"%s %s",$<str>1,$<str>2);}
;


/* Was tname instead of table_reference */
tname_list : table_reference | tname_list COMMA table_reference { sprintf($<str>$," %s,%s ",$<str>1,$<str>3);  }
;

table_expression_ss:
	from_clause  
	op_where_clause_ss
	op_group_by_clause_ss
	op_having_clause_ss {
		$<sql_string>$=make_sql_string($<str>1," ",$<sql_string>2," ",$<sql_string>3," ",$<sql_string>4,0);
	}
	;

op_where_clause_ss: /* empty */ { $<sql_string>$=strdup("");}
	| where_clause_ss {$<sql_string>$=$<sql_string>1;}
	;

op_group_by_clause_ss: /*empty */ {
	$<sql_string>$=strdup("");
}
	| group_by_clause_ss {
		$<sql_string>$=$<sql_string>1;
}
	;

op_having_clause_ss: {$<sql_string>$=strdup("");}
	| having_clause_ss {$<sql_string>$=$<sql_string>1;}
	;


search_condition_ss:
	boolean_term_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| search_condition_ss KW_OR boolean_term_ss {
		$<sql_string>$=make_sql_string($<sql_string>1," OR ",$<sql_string>3,0);
	}
	;

boolean_term_ss:
	boolean_factor_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| boolean_term_ss KW_AND boolean_factor_ss {
		$<sql_string>$=make_sql_string($<sql_string>1," AND ",$<sql_string>3,0);
	}
	;

boolean_factor_ss:
	boolean_primary_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| NOT boolean_primary_ss {
		$<sql_string>$=make_sql_string($<str>1," ",$<sql_string>2,0);
	}
;

boolean_primary_ss:
	  predicate_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| OPEN_BRACKET search_condition_ss CLOSE_BRACKET {
		$<sql_string>$=make_sql_string($<str>1,$<sql_string>2,$<str>3,0);
	}
;


exists_predicate_ss:
	EXISTS subquery_ss 		{$<sql_string>$=make_sql_string($<str>1," ",$<sql_string>2,0);}
	| NOT_EXISTS subquery_ss 	{$<sql_string>$=make_sql_string($<str>1," ",$<sql_string>2,0);}
	;


//quantified_predicate_ss:
	//value_expression comp_op quantifier subquery_ss
//{$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<str>3," ",$<sql_string>4,0);}
	//| subquery_ss comp_op value_expression {$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," ",$<str>3,0);}
	//;
/*
quantifier:
	{strcpy($<str>$," ALL ");}
	| all
	| some
	;
all:
	ALL
	;

some:
	  SOME
	| ANY
	;
*/




op_escape:
		{strcpy($<str>$,"");}
	| ESCAPE escape_character
	{sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	;

pattern_ss:
	value_expression_initial_ss {$<sql_string>$=$<sql_string>1;}
/*
	  value_specification {$<sql_string>$=make_sql_string($<str>1);}
	| var_ident_ibind_ss {$<sql_string>$=$<sql_string>1;}
*/
	;

escape_character:
	  value_specification
	;


in_predicate_ss:
	value_expression_ss IN OPEN_BRACKET in_value_list CLOSE_BRACKET {
		$<sql_string>$=make_sql_string($<sql_string>1," IN (",$<str>4,")",0);
	}
	| value_expression_ss IN subquery_ss {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," ",$<sql_string>3,0);
	}
	| value_expression_ss NOT_IN OPEN_BRACKET in_value_list CLOSE_BRACKET {
		$<sql_string>$=make_sql_string($<sql_string>1," NOT IN (",$<str>4,")",0);
	}
	| value_expression_ss NOT_IN subquery_ss {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," ",$<sql_string>3,0);
	}
;

in_value_list:
	  in_value_specification
	| in_value_list COMMA in_value_specification
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

in_value_specification : var_ident_ibind_ss {
		strcpy($<str>$,$<sql_string>1);
	}
	 | literal
;

op_not: {strcpy($<str>$,"");}
	| NOT
	;


comparison_predicate_ss:
	value_expression_ss op_not IS_NULL {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," IS NULL",0);
	}
	| value_expression_ss op_not IS_NOT_NULL {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," IS NOT NULL",0);
	}
	| value_expression_ss comp_op value_expression_ss {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," ",$<sql_string>3,0);
	}
	| value_expression_ss op_not BETWEEN value_expression_ss KW_AND value_expression_ss {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," BETWEEN ",$<sql_string>4," AND ",$<sql_string>6,0);
	}
	| value_expression_ss LIKE pattern_ss op_escape {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," ",$<sql_string>3,$<str>4,0);
	}
	| value_expression_ss NOT_LIKE pattern_ss op_escape {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," ",$<sql_string>3,$<str>4,0);
	}
	| value_expression_ss ILIKE pattern_ss op_escape {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," ",$<sql_string>3,$<str>4,0);
	}
	| value_expression_ss NOT_ILIKE pattern_ss op_escape {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," ",$<sql_string>3,$<str>4,0);
	}


	| value_expression_ss op_not MATCHES pattern_ss op_escape {
		$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2," MATCHES ",$<sql_string>4,$<str>5,0);
	}
	;

comp_op:
	  EQUAL
	| NOT_EQUAL {strcpy($<str>$,"!=");}
	| LESS_THAN
	| GREATER_THAN 
        | NOT_MATCHES
        //| NOT_LIKE
	| MATCHES
	| TILDE
	//| LIKE {strcpy($<str>$,"likE");}
	| LESS_THAN_EQ {strcpy($<str>$,"<=");}
	| GREATER_THAN_EQ {strcpy($<str>$,">=");}
	;


predicate_ss:
	  comparison_predicate_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| in_predicate_ss {
		$<sql_string>$=$<sql_string>1;
	}
	//| quantified_predicate_ss { $<sql_string>$=$<sql_string>1; }
	| exists_predicate_ss {
		$<sql_string>$=$<sql_string>1;
	}
	;


op_all: {strcpy($<str>$,"");}
	| ALL {strcpy($<str>$," ALL ");}
	| DISTINCT {strcpy($<str>$," DISTINCT ");}
	| UNIQUE {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy($<str>$," DISTINCT ");
	}
	;






data_type:
	  char_string_type
	| exact_numeric_type
	| approx_numeric_type
	;

char_string_type:
	  CHAR
	| CHAR OPEN_BRACKET length CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	;

exact_numeric_type:
	NUMERIC OPEN_BRACKET precision op_scale CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
	| SERIAL  {strcpy($<str>$,"SERIAL");}
	| DECIMAL OPEN_BRACKET precision op_scale CLOSE_BRACKET
	| MONEY OPEN_BRACKET precision op_scale CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
        | DATE
	| INTEGER
	| SMALLINT
	| DATETIME s_curr TO e_curr
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	| DATETIME 
	| INTERVAL s_curr TO e_curr
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	| INTERVAL
	| INTERVAL s_curr OPEN_BRACKET INT_VALUE CLOSE_BRACKET TO e_curr
{sprintf($<str>$," %s %s %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5,$<str>6,$<str>7);}
	| TEXT
	| BYTE
	| VARCHAR
	| VARCHAR OPEN_BRACKET INT_VALUE CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	| VARCHAR OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5,$<str>6);}
	;

op_scale: {strcpy($<str>$,"");}
	| COMMA scale {
		sprintf($<str>$,",%s",$<str>2);
}
	;

approx_numeric_type:
	FLOAT OPEN_BRACKET precision CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	| REAL
	| SMALLFLOAT
	| FLOAT
	| DOUBLE_PRECISION
{sprintf($<str>$," %s",$<str>1);}
	;

length:
	INT_VALUE
	;

precision:
	INT_VALUE
	;

scale:
	INT_VALUE
	;

table_name:
	 CHAR_VALUE DOT identifier { sprintf($<str>$,"\\\"%s\\\"%s%s", A4GL_strip_quotes ($<str>1),$<str>2,$<str>3); addmap("Use Table",$<str>$,curr_func,yylineno,infilename); }
	| CHAR_VALUE {
		sprintf($<str>$," %s", A4GL_strip_quotes ($<str>1));
		addmap("Use Table",$<str>$,curr_func,yylineno,infilename);
	}
	| identifier {strcpy($<str>$,$<str>1); addmap("Use Table",$<str>1,curr_func,yylineno,infilename); }
	| identifier COLON identifier { sprintf($<str>$," %s%s%s",$<str>1,$<str>2,$<str>3); addmap("Use Table",$<str>$,curr_func,yylineno,infilename); }
/*
	| identifier DOT identifier { sprintf($<str>$," %s%s%s",$<str>1,$<str>2,$<str>3); addmap("Use Table",$<str>$,curr_func,yylineno,infilename); }
*/

	;

//db_name : identifier;

authorization_identifier:
	identifier
	;

/*table_identifier:
	identifier {strcpy($<str>$,$<str>1);}
	;
*/


col_arr : {strcpy($<str>$,"");} 
	| OPEN_SQUARE INT_VALUE CLOSE_SQUARE {sprintf($<str>$,"[%s]",$<str>2);}
	| OPEN_SQUARE INT_VALUE COMMA INT_VALUE CLOSE_SQUARE {sprintf($<str>$,"[%s,%s]",$<str>2,$<str>4);}
;

column_name : 
	column_name_specific {
		strcpy($<str>$,$<str>1);
	}
	| ATSIGN column_name_specific {
		strcpy($<str>$,$<str>2);
	}
;

column_name_specific: identifier col_arr
{ 
addmap("Use Column",$<str>1,curr_func,yylineno,infilename);
sprintf($<str>$,"%s%s",$<str>1,$<str>2);
}
	| table_name DOT identifier col_arr
{
sprintf($<str>$,"%s.%s%s",$<str>1,$<str>3,$<str>4);
addmap("Use Column",$<str>$,curr_func,yylineno,infilename);
}
	| table_name  DOT MULTIPLY
 {
sprintf($<str>$,"%s.%s",$<str>1,$<str>3);
addmap("Use Column",$<str>$,curr_func,yylineno,infilename);
}
	;

correlation_name:
	identifier
	;


literal: CHAR_VALUE {
	strcpy($<str>$,convstrsql($<str>1));
 A4GL_debug("Set $<str>$ to %s\n",$<str>$);
}
	| NUMERIC
	| real_number
	| INT_VALUE
	//| PLUS real_number {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	//| PLUS INT_VALUE {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	//| MINUS real_number {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	//| MINUS INT_VALUE {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
        | curr_clause
	;

curr_v_clause : CURRENT  cur_v_part 
{strcpy($<str>$,$<str>2);}
;
curr_clause : CURRENT  cur_part 
{
char *ptr;
ptr=acl_getenv("SQL_CURRENT_FUNCTION");
if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }

if (ptr) {
	sprintf($<str>$," %s(%s) ",ptr,$<str>2);
} else {
	sprintf($<str>$," %s %s ",$<str>1,$<str>2);
}
}
;

cur_part: {
//char *ptr;

//ptr=acl_getenv("SQL_CURRENT_FUNCTION");

//if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }

//if (ptr) {
	sprintf($<str>$,"'%s','%s'","YEAR","SECOND");
//} else {
	strcpy($<str>$," YEAR TO SECOND ");
//}
	strcpy($<str>$,"");
}
| s_curr TO e_curr
{
char *ptr;
ptr=acl_getenv("SQL_CURRENT_FUNCTION");
if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }
if (ptr) {
	sprintf($<str>$,"'%s','%s'",$<str>1,$<str>3);
} else {
	sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);
}
}
;

cur_v_part: {strcpy($<str>$,"1,10");}
| s_curr_v TO s_curr_v
{sprintf($<str>$," %s ,%s",$<str>1,$<str>3);}
;

s_curr_v: YEAR {strcpy($<str>$,"1");} | MONTH  {strcpy($<str>$,"2");}| DAY  {strcpy($<str>$,"3");}| HOUR  {strcpy($<str>$,"4");}| MINUTE  {strcpy($<str>$,"5");}| SECOND  {strcpy($<str>$,"6");}| 
FRACTION {
sprintf($<str>$,"%d",6+2);
}
| FRACTION OPEN_BRACKET INT_VALUE CLOSE_BRACKET {
sprintf($<str>$,"%d",atoi($<str>3)+6);
}
;

e_curr_v: YEAR {strcpy($<str>$,"4");} | MONTH  {strcpy($<str>$,"7");}| DAY  {strcpy($<str>$,"10");}| HOUR  {strcpy($<str>$,"13");}| MINUTE  {strcpy($<str>$,"16");}| SECOND  {strcpy($<str>$,"19");} 
| 
FRACTION {
strcpy($<str>$,"25");
} 
| FRACTION OPEN_BRACKET INT_VALUE CLOSE_BRACKET {
strcpy($<str>$,"25");
}
;


s_curr: YEAR | MONTH | DAY | HOUR | MINUTE | SECOND | FRACTION;
e_curr: YEAR | MONTH | DAY | HOUR | MINUTE | SECOND | FRACTION;

dbase_name	:	identifier {strcpy($<str>$,$<str>1);}
		|	CHAR_VALUE {strcpy($<str>$, A4GL_strip_quotes ($<str>1));}
		;

flush_cmd : opt_use
	FLUSH fetch_cursor_name  {
	print_flush_cursor($<str>3);
		addmap("Flush Cursor",$<str>3,curr_func,yylineno,infilename);
print_undo_use($<str>1);
		}

;

declare_cmd : opt_use DECLARE declare_cursor_name CURSOR FOR cursor_specification_all_ss {insql=0;chk4var=0;}  {
		print_declare("",$<sql_string>6,$<str>3,0,0);
		addmap("Declare Cursor",$<str>3,curr_func,yylineno,infilename);
		print_undo_use($<str>1);
		doing_declare=0;
	}
	| opt_use DECLARE declare_cursor_name CURSOR WITH_HOLD FOR cursor_specification_sel_ss {insql=0;chk4var=0;}  {
		print_declare("",$<sql_string>7,$<str>3,2,0); 
		addmap("Declare Cursor",$<str>3,curr_func,yylineno,infilename);
		print_undo_use($<str>1);
		doing_declare=0;
	}

        | opt_use DECLARE declare_cursor_name SCROLL_CURSOR_FOR cursor_specification_sel_ss {insql=0;chk4var=0;}  {
		print_declare("",$<sql_string>5,$<str>3,0,1); 
		addmap("Declare Cursor",$<str>3,curr_func,yylineno,infilename);
		print_undo_use($<str>1);
		doing_declare=0;
	}
       	| opt_use DECLARE declare_cursor_name SCROLL_CURSOR WITH_HOLD FOR cursor_specification_sel_ss {insql=0;chk4var=0;}  {
		print_declare("",$<sql_string>7,$<str>3,2,1); 
		addmap("Declare Cursor",$<str>3,curr_func,yylineno,infilename);
		print_undo_use($<str>1);
		doing_declare=0;
	}
;
 
curs_forupdate : {strcpy($<str>$,"");} 
		| FOR_UPDATE {strcpy($<str>$," FOR UPDATE");} 
		| FOR_UPDATE_OF cur_update_list {sprintf($<str>$," FOR UPDATE OF %s",$<str>2);} 
		;

cur_update_list : colident {strcpy($<str>$,$<str>1);} | cur_update_list COMMA colident {sprintf($<str>$,"%s,%s",$<str>1,$<str>3);}
;

colident: identifier
	| identifier DOT identifier {sprintf($<str>$,"%s.%s",$<str>1,$<str>3);}
	| CHAR_VALUE DOT identifier DOT identifier {sprintf($<str>$,"\\\"%s\\\".%s.%s", A4GL_strip_quotes ($<str>1),$<str>3,$<str>5);}
;
	

cursor_specification_all_ss:
	cursor_specification_sel_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| insert_statement_ss { 
		$<sql_string>$=make_sql_string(print_curr_spec(1,$<sql_string>1),0);
	}
;

cursor_specification_sel_ss:
	 stmt_id {
		start_bind('i',0);
		start_bind('o',0);
		$<sql_string>$=make_sql_string(print_curr_spec(2,$<str>1) ,0);
	}
	| select_statement_ss  {
		$<sql_string>$=$<sql_string>1;
	}
;



select_statement_full_ss : select_statement_ss 
	{
	$<sql_string>$=$<sql_string>1;
	if (strstr($<str>1,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
// FIX USAGE
;

select_statement_ss:
	SELECT 
	op_ad 
	{ start_bind('i',0); }
	select_list_ss {A4GL_debug("Got select list...\n");}
        opt_into_sel_ss 
	table_expression_ss
        sel_p2_ss curs_forupdate {
		char *ptr;
                ptr=make_sql_string("SELECT ",$<str>2, $<sql_string>4," ", $<sql_string>6, " ",$<sql_string>7," ",$<sql_string>8,$<str>9,0);

		$<sql_string>$=strdup(print_select_all(ptr));
		free(ptr);
		free($<sql_string>4);
		free($<sql_string>6);
		free($<sql_string>7);
		free($<sql_string>8);
}
;


in_select_statement_ss:
	SELECT op_ad select_list_ss table_expression_ss sel_p2_ss {
		$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0);
	free($<sql_string>3);
	free($<sql_string>4);
	free($<sql_string>5);
}

;

select_statement2_ss:
	select_statement21_ss {
		$<sql_string>$=$<sql_string>1;
	 }
	| char_or_var {
		$<sql_string>$=strdup($<str>1);
	};

select_statement21_ss:
	SELECT  op_ad select_list_ss
        opt_into_sel_ss
	table_expression_ss
        sel_p2_ss {
	$<sql_string>$=make_sql_string($<str>1, " ",$<str>2," ",$<sql_string>3," ", $<sql_string>4," ", $<sql_string>5, " ",$<sql_string>6,0);
	free($<sql_string>3);
	free($<sql_string>5);
	free($<sql_string>6);
}
;


sel_p2_ss : {
		$<sql_string>$=strdup("");
		}
| UNION op_all select_statement2_ss {
       A4GL_lex_printcomment("/* UNION */");
	$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<sql_string>3,0);
       }
| order_by_clause  {
	$<sql_string>$=strdup($<str>1);
}
| INTO_TEMP tmp_tabname op_no_log { $<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<str>3,0); } 
| order_by_clause INTO_TEMP tmp_tabname op_no_log { 
	$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<str>3," ",$<str>4,0);
}
;


tmp_tabname: identifier;


opt_into_sel_ss :  { start_bind('o',0);$<sql_string>$=make_sql_string("",0); }
	| INTO  obind_var_list { 
		$<sql_string>$=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
;



query_specification_ss:
	SELECT op_ad select_list_ss table_expression_ss {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ", $<sql_string>3," ",$<sql_string>4,0);
		free($<sql_string>3);
		//free($<sql_string>4);

	}
;

subquery_ss:
	OPEN_BRACKET SELECT op_ad select_list_ss table_expression_ss CLOSE_BRACKET {
		$<sql_string>$=make_sql_string("(",$<str>2," ",$<str>3," ",$<sql_string>4," ",$<sql_string>5,")",0);
	}
;

op_ad: {strcpy($<str>$,"");}
	| ALL {strcpy($<str>$,"ALL ");}
	| DISTINCT {strcpy($<str>$," DISTINCT ");}
	| UNIQUE {strcpy($<str>$," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy($<str>$," DISTINCT ");
}
	;

select_list_ss: 
	value_expression_pls_ss  {
		$<sql_string>$=$<sql_string>1;
	}
	| select_list_ss COMMA value_expression_pls_ss { 
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
	}
;

value_expression_pls_ss : 
	value_expression_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| value_expression_ss  identifier {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			$<sql_string>$=make_sql_string($<sql_string>1," AS ",$<str>2,0);
		} else {
			$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2,0);
		}
	}
;


column_specification_ss : value_expression_ss {
	$<sql_string>$=$<sql_string>1;
}

;



value_expression_ss:
	value_expression_initial_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| MINUS value_expression_initial_ss {
		$<sql_string>$=make_sql_string("-",$<sql_string>2,0);
	}
	| PLUS value_expression_initial_ss {
		$<sql_string>$=make_sql_string("+",$<sql_string>2,0);
	}
;

value_expression_initial_ss :
	value_expression_complex_ss {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
		$<sql_string>$=$<sql_string>1;
	}
	| var_ident_ibind_ss 	{
		$<sql_string>$=$<sql_string>1;
	}
	| subquery_ss {
		$<sql_string>$=$<sql_string>1;
	}
	| ATSIGN identifier {
		$<sql_string>$=strdup($<str>2);
	}
	| ATSIGN identifier DOT identifier {
		$<sql_string>$=make_sql_string($<str>2,".",$<str>4);
	}
;

value_expression_complex_ss :
	value_expression_initial_ss DIVIDE value_expression_ss
		{$<sql_string>$=make_sql_string($<sql_string>1,"/",$<sql_string>3,0);}
	| value_expression_initial_ss units_qual
		{$<sql_string>$=make_sql_string($<sql_string>1," ",$<str>2,0);}
	| value_expression_initial_ss MULTIPLY value_expression_ss
		{$<sql_string>$=make_sql_string($<sql_string>1,"*",$<sql_string>3,0);}
	| value_expression_initial_ss PLUS value_expression_ss
		{$<sql_string>$=make_sql_string($<sql_string>1,"+",$<sql_string>3,0);}
	| value_expression_initial_ss MINUS value_expression_ss
		{$<sql_string>$=make_sql_string($<sql_string>1,"-",$<sql_string>3,0);}
	| literal {$<sql_string>$=make_sql_string($<str>1,0);}
	| KW_TRUE {$<sql_string>$=make_sql_string("1",0);}
	| KW_FALSE {$<sql_string>$=make_sql_string("0",0);}
	| USER {$<sql_string>$=make_sql_string("USER",0);}
	| MULTIPLY {$<sql_string>$=make_sql_string("*",0);}
	| COUNT_MULTIPLY {$<sql_string>$=make_sql_string("COUNT(*)",0);}
 	| AVG OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
{$<sql_string>$=make_sql_string("AVG(",$<str>3,$<sql_string>4,")",0);}
	| XMAX OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
{$<sql_string>$=make_sql_string("MAX(",$<str>3,$<sql_string>4,")",0);}
	| XMIN OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
{$<sql_string>$=make_sql_string("MIN(",$<str>3,$<sql_string>4,")",0);}
	| SUM OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
{$<sql_string>$=make_sql_string("SUM(",$<str>3,$<sql_string>4,")",0);}
	| COUNT OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
{$<sql_string>$=make_sql_string("COUNT(",$<str>3,$<sql_string>4,")",0);}
	| identifier OPEN_BRACKET value_expr_list_ss CLOSE_BRACKET
{$<sql_string>$=make_sql_string($<str>1,"(",$<sql_string>3,")",0);}
	| DATE OPEN_BRACKET value_expr_list_ss CLOSE_BRACKET
{$<sql_string>$=make_sql_string("DATE(",$<sql_string>3,")",0);}
	| OPEN_BRACKET value_expression_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("(",$<sql_string>2,")",0);}
	| EXTEND OPEN_BRACKET extend_qual_ss CLOSE_BRACKET
{$<sql_string>$=make_sql_string("EXTEND(",$<sql_string>3,")",0);}
;

value_expr_list_ss : 
	value_expression_ss {$<sql_string>$=$<sql_string>1;}
	| value_expr_list_ss COMMA value_expression_ss {
	$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
}
	
;

value_specification:
	 literal
	;

unload_cmd :  opt_use UNLOAD_TO ufile opt_delim select_statement2_ss {

print_unload($<str>3,$<str>4,$<sql_string>5);
print_undo_use($<str>1);
}
;


load_cmd :  
opt_use LOAD_FROM ufile opt_delim INSERT_INTO table_name opt_col_list {
print_load($<str>3,$<str>4,$<str>6,$<str>7);
print_undo_use($<str>1);
}
| opt_use LOAD_FROM ufile opt_delim variable {
print_load_str($<str>3,$<str>4,$<str>5);
print_undo_use($<str>1);
}

;

opt_delim : {strcpy($<str>$,"\"|\"");} | DELIMITER char_or_var {
strcpy($<str>$,$<str>2);
};

char_or_var : CHAR_VALUE | variable {
if ((scan_variable($<str>1)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
;

opt_col_list: {strcpy($<str>$,"0");} | OPEN_BRACKET col_list CLOSE_BRACKET {
sprintf($<str>$,"%s,0",$<str>2);
};

col_list : simple_column_name | col_list COMMA simple_column_name {
    sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
};

simple_column_name : identifier {
     sprintf($<str>$,"\"%s\"",$<str>1);
}
;


ufile : CHAR_VALUE | variable;


opt_use : {strcpy($<str>$,"");} | USE_SESSION conn_id FOR {
print_use_session($<str>3);
strcpy($<str>$,A4GL_get_undo_use());
}
;

conn_id : ident_or_var;





misc_sql :
	lock_stmt
	| unlock_stmt
	| rename_stmt
;

rename_stmt :
	RENTAB rentabname TO rentabname { sprintf($<str>$,"%s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4); }
	| RENCOL rentabname DOT rencolname TO rencolname { sprintf($<str>$,"%s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4); }
;

rentabname : identifier;
rencolname : identifier;

unlock_stmt:

	UNLOCK_TABLE tab_name {
		sprintf($<str>$,"%s %s",$<str>1,$<str>2);
	}
;

lock_stmt :
	LOCK_TABLE tab_name share_or_exclusive  {
		sprintf($<str>$,"%s %s %s",
					$<str>1,
					$<str>2,
					$<str>3
					);
		}
;

share_or_exclusive :
	INSHARE
	| INEXCLUSIVE
;





units_qual:
	UNITS_YEAR {strcpy($<str>$,"UNITS YEAR");}
	| UNITS_MONTH {strcpy($<str>$,"UNITS MONTH"); }
	| UNITS_DAY {strcpy($<str>$,"UNITS DAY"); }
	| UNITS_HOUR {strcpy($<str>$,"UNITS HOUR"); }
	| UNITS_MINUTE {strcpy($<str>$,"UNITS MINUTE"); }
	| UNITS_SECOND {strcpy($<str>$,"UNITS SECOND"); }
;

extend_qual_ss:
        CURRENT COMMA s_curr TO e_curr {$<sql_string>$=make_sql_string($<str>1,$<str>2,$<str>3," ",$<str>4," ",$<str>5,0);}
        | var_ident_ibind_ss COMMA s_curr TO e_curr {$<sql_string>$=make_sql_string($<sql_string>1,$<str>2,$<str>3," ",$<str>4," ",$<str>5,0);}
        | CURRENT s_curr TO e_curr {$<sql_string>$=make_sql_string($<str>1,$<str>2," ",$<str>3," ",$<str>4,0);}
;

/* ========================= sql1.rule ================================ */
sql_block_cmd : SQL {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	} sql_block END_SQL {
			sql_mode=0;
			print_sql_block_cmd($<str>3);
	}
;


sql_block :
	sql_block_entry 
	| sql_block sql_block_entry  {sprintf($<str>$,"%s %s",$<str>1,$<str>2);}
;

sql_block_entry:
	SQL_TEXT 
	| in_var {strcpy($<str>$,$<str>1);}
	| sql_block_into {strcpy($<str>$,$<str>1);}
| ABSOLUTE
| ACCEPT
| ACL_BUILTIN
| ADD
| AFTER
| ALL
| ALTER
| ANSI
| ANY
| APPEND
| ARRAY
| AS
| ASC
| ASCENDING
| ASCII
| ASSOCIATE
| AT
| ATSIGN
| ATTRIBUTES
| AUDIT
| AUTHORIZATION
| AVERAGE
| AVG
| BEFORE
| BETWEEN
| BLACK
| BLINK
| BLUE
| BOLD
| BORDER
| BOTTOM
| BUFFERED
| BUTTONS
| BY
| BYTE
| CAPTION
| CASE
| CCODE
| CHAR
| CHARACTER
| CHECK
| CLEAR
| CLIPPED
| CLOSE
| CLOSE_BRACKET
| CLOSE_SQUARE
| CODE_C
| COLON
| COLUMN
| COLUMNS
| COMMA
| COMMAND
| COMMENT
| COMMIT
| CONNECT
| CONST
| CONSTANT
| CONSTRUCT
| CONTINUE
| COUNT
| CREATE
| CURRENT
| CURSOR
| CYAN
| DATABASE
| DATE
| DATETIME
| DAY
| DBA
| DBYNAME
| DEC
| DECIMAL
| DECLARE
| DEFAULT
| DEFAULTS
| DEFER
| DEFINE
| DELETE
| DELIMITER
| DESC
| DESCENDING
| DIM
| DISABLE
| DISPLAY
| DISTINCT
| DIVIDE
| DOT
| DOUBLE
| DOWNSHIFT
| DROP
| ELIF
| ELSE
| ENABLE
| ENDCODE
| EQUAL
| ERROR
| ESCAPE
| EVERY
| EXCLUSIVE
| EXEC
| EXECUTE
| EXISTS
| EXIT
| EXTEND
| EXTENT
| EXTERNAL
| FCALL
| FETCH
| FIELDTOWIDGET
| FIELD_TOUCHED
| FINISH
| FIRST
| FKEY
| FLOAT
| FLUSH
| FOR
| FOREACH
| FOREIGN
| FORMAT
| FORMHANDLER
| FORMHANDLER_INPUT
| FORM_IS_COMPILED
| FOUND
| FRACTION
| FREE
| FROM
| FUNCTION
| GET_FLDBUF
| GLOBALS
| GO
| GOTO
| GRANT
| GREATER_THAN
| GREEN
| GROUP
| HAVING
| HEADER
| HELP
| HIDE
| HOUR
| ICON
| ID_TO_INT
| IF
| IN
| INCHES
| INDEX
| INFIELD
| INITIALIZE
| INPUT
| INSERT
| INTEGER
| INTERRUPT
| INTERVAL
| INT_TO_ID
| INVISIBLE
| KEY
| KWDOWN
| KWFIELD
| KWFORM
| KWLINE
| KWMESSAGE
| KWNO
| KWUP
| KWWINDOW
| KW_AND
| KW_FALSE
| KW_IS
| KW_NULL
| KW_OR
| KW_TRUE
| KW_USING
| LAST
| LEFT
| LESS_THAN
| LET
| LIKE
| LOCAL
| LOCATE
| LOG
| MAGENTA
| MAIN
| MARGIN
| MATCHES
| MAXCOUNT
| MEMORY
| MENU
| MENUHANDLER
| MESSAGEBOX
| MINUS
| MINUTE
| MM
| MOD
| MODE
| MODIFY
| MONEY
| MONTH
| MULTIPLY
| NEED
| NEXT
| NEXTPAGE
| NOCR
| NORMAL
| NOT
| NUMERIC
| OF
| OFF
| ON
| OPEN
| OPEN_BRACKET
| OPEN_SQUARE
| OPTION
| OPTIONS
| ORDER
| OTHERWISE
| OUTER
| OUTPUT
| PAD
| PASSWORD
| PAUSE
| PDF_FUNCTION
| PDF_REPORT
| PERCENT
| PLUS
| POINTS
| PRECISION
| PREPARE
| PREPEND
| PREVIOUS
| PREVPAGE
| PRINT
| PRIOR
| PROCEDURE
| PROGRAM
| PROMPT
| PUBLIC
| PUT
| QUIT
| READONLY
| REAL
| RECORD
| RECOVER
| RED
| REFERENCES
| REGISTER
| RELATIVE
| REPORT
| RESOURCE
| RETURN
| RETURNING
| REVERSE
| REVOKE
| RIGHT
| ROLLFORWARD
| ROW
| ROWS
| RUN
| SCHEMA
| SCROLL
| SECOND
| SECTION
| SELECT
| SEMICOLON
| SERIAL
| SESSION
| SHARED
| SHOW
| SINGLE_KEY
| SIZE
| SKIP
| SLEEP
| SMALLFLOAT
| SMALLINT
| SOME
| SPACES
| SQL
| SQLSUCCESS
| STATUSBOX
| STEP
| STOP
| SUM
| SYNONYM
| TAB
| TEMP
| TEMPLATE
| TEXT
| THEN
| THRU
| TIMEOUT
| TO
| TOP
| TRAILER
| TUPLE
| UNCONSTRAINED
| UNDERLINE
| UNION
| UNIQUE
| UNLOCK
| UPDATE
| UPSHIFT
| USE
| USER
| VALIDATE
| VALUES
| VARCHAR
| VARIABLE
| WAIT
| WAITING
| WHEN
| WHENEVER
| WHERE
| WHILE
| WHITE
| WITH
| WORDWRAP
| WORK
| XMAX
| XMIN
| XSET
| YEAR
| YELLOW




	;

in_var :
	DOLLAR {sql_mode=0;} var_ident_ibind_ss {
		strcpy($<str>$,$<sql_string>3);
		sql_mode=1;
	}
;

sql_block_into: 
	INTO {sql_mode=0;} obind_var_list {
 		strcpy($<str>$,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
;


/*
=====================================================================
                        Source: template.rule
=====================================================================
*/


/*
op_template :
	| template_m
;

template_m :
	TEMPLATE 
		template_list
	END_TEMPLATE {list_print_all();}
;

template_list : template_item
	| template_list template_item
;

template_item : 
		identifier EQUAL template_value { 
	printf("Copy %s to %s",$<str>3,$<str>1);
list_copy($<str>3,$<str>1); 
}
	| 	identifier OPEN_SQUARE CLOSE_SQUARE EQUAL template_value { list_copy($<str>3,$<str>1); }
	|	DATABASE EQUAL template_single_value {list_copy($<str>3,"_database");}
;

template_single_value :
		PROMPT CHAR_VALUE  {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_prompt_single(a,$<str>2);}
	| 	PROMPT_MANY CHAR_VALUE  {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_prompt_many(a,$<str>2);}
	| 	PROMPT INT_VALUE COMMA CHAR_VALUE  {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_prompt_many(a,$<str>4);}
	|	CHAR_VALUE {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_set_single(a,$<str>1);}
	| 	INT_VALUE {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_set_single(a,$<str>1);}
;

template_value : 
		COLUMNS identifier  {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_columns(a,$<str>2);}
	| identifier
	| 	template_single_value
	|       template_value PLUS template_value {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_set_plus(a,$<str>1,$<str>3);}
	|	template_value MINUS template_value {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_set_minus(a,$<str>1,$<str>3);}
	|	template_value IN template_value {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); 
		list_in();
	}
	| 	OPEN_BRACKET template_value CLOSE_BRACKET {
			strcpy($<str>$,$<str>2);
	}
	|	APPEND template_single_value TO template_value  {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_append(a,$<str>4,$<str>2);}

	|	PREPEND template_single_value TO template_value  {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); list_append(a,$<str>4,$<str>2);}
	| 	USE template_value WITH template_single_value ON template_value  {
		char *a; a=(char *)new_id(); strcpy($<str>$,a); 
        list_append($<str>2,$<str>6,$<str>4);
	}
;

*/

/*
=====================================================================
                        Source: update.rule
=====================================================================
*/


update_statement_ss:
	UPDATE table_name {
		strcpy(current_upd_table,$<str>2);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		$<sql_string>$=strdup("");
	} set_clause_list_ss  {
		strcpy(current_upd_table,"");
	} where_upd_ss {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<sql_string>4," ",$<sql_string>6,0);
	}
;



where_upd_ss : {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		$<sql_string>$=strdup("");
	}
	| WHERE_CURRENT_OF fetch_cursor_name { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes($<str>2);
		sprintf($<str>$,"%s %s",$<str>1,$<str>2);
		$<sql_string>$=make_sql_string($<str>$,0);
	}
	| WHERE search_condition_ss {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		$<sql_string>$=make_sql_string("WHERE ",$<sql_string>2,0);
	}
	;


set_clause_list_ss: 
    XSET_OPEN_BRACKET upd_col_list CLOSE_BRACKET EQUAL OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET {
		$<sql_string>$=make_sql_string("SET (",$<str>2,")=(",$<sql_string>6,")",0);

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			$<sql_string>$=strdup(fix_update_expr(0)); 
			ansi_violation("Update (..)=(..)",0);
		}  else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    | XSET_MULTIPLY_EQUAL_OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET {	
		$<sql_string>$=make_sql_string("SET *=(",$<sql_string>2,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			$<sql_string>$=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    | XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET {	
		$<sql_string>$=make_sql_string("SET *=(",$<sql_string>2,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			$<sql_string>$=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }


    | XSET upd_columns_ss  {
		$<sql_string>$=make_sql_string("SET ",$<sql_string>2,0);
    }
    | XSET_MULTIPLY_EQUAL upd_val_list_ss  {
		char *ptr;

		ptr=$<sql_string>2;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			$<sql_string>$=make_sql_string("SET *= ",$<sql_string>2,0);
		} else {
			$<sql_string>$=make_sql_string("SET *=(",$<sql_string>2,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			$<sql_string>$=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    | XSET_ident_DOT_MULTIPLY_EQUAL upd_val_list_ss  {
		char *ptr;

		ptr=$<sql_string>2;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			$<sql_string>$=make_sql_string("SET *= ",$<sql_string>2,0);
		} else {
			$<sql_string>$=make_sql_string("SET *=(",$<sql_string>2,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			$<sql_string>$=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}




;

upd_columns_ss : 
	col_1_ss  {
		$<sql_string>$=$<sql_string>1;
	}
	| upd_columns_ss COMMA col_1_ss {
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
	}
;


upd_column_name : column_name  ;

col_1_ss : 
	upd_column_name EQUAL upd_val_ss {
		$<sql_string>$=make_sql_string($<str>1,"=",$<sql_string>3,0);
	}
;

upd_col_list  : upd_column_name	{
			push_gen(UPDCOL,$<str>1); strcpy($<str>$,$<str>1);
		} 
		| upd_col_list COMMA upd_column_name {
			push_gen(UPDCOL,$<str>3); sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
		}

;


upd_val_list_ss  : 
	upd_val_ss { 
		$<sql_string>$=$<sql_string>1; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,$<sql_string>1);
		}
	}
	| upd_val_list_ss COMMA upd_val_ss { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,$<sql_string>3);
		}
		$<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0); 
	} 
;



upd_val_ss : 
	KW_NULL {
		$<sql_string>$=strdup($<str>1);
	}
	| upd_value_expression_ss  {
		$<sql_string>$=$<sql_string>1;
	}
;



upd_value_expression_ss:
        upd_value_expression_initial_ss {
                $<sql_string>$=$<sql_string>1;
        }
        | MINUS upd_value_expression_initial_ss {
                $<sql_string>$=make_sql_string("-",$<sql_string>2,0);
        }
        | PLUS upd_value_expression_initial_ss {
                $<sql_string>$=make_sql_string("+",$<sql_string>2,0);
        }
;



upd_value_expression_initial_ss :
        upd_var_ident_ibind_ss    {
                $<sql_string>$=$<sql_string>1;

        }
        | subquery_ss {
                $<sql_string>$=$<sql_string>1;
        }
        | ATSIGN identifier {
                $<sql_string>$=strdup($<str>2);
        }
        | ATSIGN identifier DOT identifier {
                $<sql_string>$=make_sql_string($<str>2,".",$<str>4);
        }
        | upd_value_expression_complex_ss { 
		$<sql_string>$=$<sql_string>1; 
		pop_all_gen(UPDVAL2,"!");
	}
        | literal {$<sql_string>$=make_sql_string($<str>1,0);}
        | KW_TRUE {$<sql_string>$=make_sql_string("TRUE",0);}
        | KW_FALSE {$<sql_string>$=make_sql_string("FALSE",0);}
        | USER {$<sql_string>$=make_sql_string("USER",0);}
        | COUNT_MULTIPLY {$<sql_string>$=make_sql_string("COUNT(*)",0);}
        //| MULTIPLY {$<sql_string>$=make_sql_string("*",0);}
;


upd_value_expression_complex_ss :
        upd_value_expression_initial_ss DIVIDE upd_value_expression_ss {$<sql_string>$=make_sql_string($<sql_string>1,"/",$<sql_string>3,0);}
        | upd_value_expression_initial_ss units_qual {$<sql_string>$=make_sql_string($<sql_string>1,$<str>2,0);}
        | upd_value_expression_initial_ss MULTIPLY upd_value_expression_ss {$<sql_string>$=make_sql_string($<sql_string>1,"*",$<sql_string>3,0);}
        | upd_value_expression_initial_ss PLUS upd_value_expression_ss {$<sql_string>$=make_sql_string($<sql_string>1,"+",$<sql_string>3,0);}
        | upd_value_expression_initial_ss MINUS upd_value_expression_ss {$<sql_string>$=make_sql_string($<sql_string>1,"-",$<sql_string>3,0);}
        | AVG OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("AVERAGE(",$<str>3,$<sql_string>4,")",0);}
        | XMAX OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("MAX(",$<str>3,$<sql_string>4,")",0);}
        | XMIN OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("MIN(",$<str>3,$<sql_string>4,")",0);}
        | SUM OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("SUM(",$<str>3,$<sql_string>4,")",0);}
        | COUNT OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("COUNT(",$<str>3,$<sql_string>4,")",0);}
        | identifier OPEN_BRACKET upd_value_expr_list_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string($<str>1,"(",$<sql_string>3,")",0);}
        | DATE OPEN_BRACKET upd_value_expr_list_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("DATE(",$<sql_string>3,")",0);}
        | OPEN_BRACKET upd_value_expression_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("(",$<sql_string>2,")",0);}
        | EXTEND OPEN_BRACKET extend_qual_ss CLOSE_BRACKET {$<sql_string>$=make_sql_string("EXTEND(",$<sql_string>3,")",0);}
;


upd_var_ident_ibind_ss:  var_ident_ibind_ss {
		$<sql_string>$=$<sql_string>1;
}
;

upd_value_expr_list_ss :
        upd_value_expression_ss {$<sql_string>$=$<sql_string>1;}
        | upd_value_expr_list_ss COMMA upd_value_expression_ss {
        $<sql_string>$=make_sql_string($<sql_string>1,",",$<sql_string>3,0);
}

;
/*
=====================================================================
                        Source: var2.rule
=====================================================================
*/


var_ident :  var2  
{
	if (scan_variable($<str>1)!=-1)
	{
		char c;
		char buff[1024];
			sprintf(buff,"%s",fgl_add_scope($<str>1,0));

		print_push_variable(buff);

		strcpy($<str>$,"?");

	} else {
		strcpy($<str>$,$<str>1);
	}

}
;


var2 :
	DOLLAR  var3 {strcpy($<str>$,$<str>2);} | var3
;

var3:
        array_r_variable_or_ident // MJA 010503
	| identifier
	| var3  DOT aft_dot {sprintf($<str>$,"%s.%s",$<str>1,$<str>3);}
	| CHAR_VALUE DOT var3 DOT aft_dot {sprintf($<str>$,"\\\"%s\\\".%s.%s", A4GL_strip_quotes ($<str>1),$<str>3,$<str>5);}
;

aft_dot :
	MULTIPLY
	| array_r_varid
	| identifier
;



var_ident_ibind_ss :  var2  
{
	int sv_val;
	//printf("var_ident_ibind_ss : %s\n",$<str>1);
	sv_val=scan_variable($<str>1);

	if (strncmp($<str>1," a4gl_sub",9)==0) {
		// Its a substring of a variable
		sv_val=1;
	}

	if (sv_val!=-1&&(!system_var($<str>1)))
	{
		// Its a variable
		int z = 0,a = 0;
		//printf("add as bind\n");
		a=get_bind_cnt('i');
		z=add_bind('i',$<str>1);
		z-=a;
		$<sql_string>$=strdup(A4GL_set_var_sql(doing_declare,z));

	} else { 
		// Its a column
		$<sql_string>$=strdup(get_column_transform($<str>1));
	}
}
| var2 THRU var2 
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
printf("THRU : %s %s\n",$<str>1,$<str>3);

A4GL_debug("Starting THRU");

sprintf(buff,"%s\n%s",$<str>1,$<str>3);
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
	$<sql_string>$=strdup(was_str);
}
;



/* ================================ var2.rule ===================== */
/*
=====================================================================
                        Source: whenever.rule
=====================================================================
*/


whenever_cmd 	:  WHENEVER_NOT_FOUND when_do
{set_whenever(WHEN_NOTFOUND|atoi($<str>2),0);}
		|  WHENEVER_SQLERROR when_do
{set_whenever(WHEN_SQLERROR|atoi($<str>2),0);}
		|  WHENEVER_ANY_ERROR when_do
{set_whenever(WHEN_ANYERROR|atoi($<str>2),0);}
		|  WHENEVER_ERROR_CONTINUE {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
		|  WHENEVER_ERROR when_do
{
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi($<str>2));
set_whenever(WHEN_ERROR+atoi($<str>2),0);
}
		|  WHENEVER_SQLWARNING when_do
{set_whenever(WHEN_SQLWARNING|atoi($<str>2),0);}
		|  WHENEVER_WARNING_CONTINUE {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
		|  WHENEVER_WARNING when_do
{set_whenever(WHEN_WARNING|atoi($<str>2),0);}
		|  WHENEVER_SUCCESS when_do
{set_whenever(WHEN_SUCCESS|atoi($<str>2),0);}
		|  WHENEVER_SQLSUCCESS when_do
{set_whenever(WHEN_SQLSUCCESS|atoi($<str>2),0);}
		;

when_do		:	CONTINUE {
 set_whento("");
			sprintf($<str>$,"%d",WHEN_CONTINUE); }
		|	GO TO label_goto
{
set_whento($<str>3);
sprintf($<str>$,"%d",WHEN_GOTO);
 }
		|	GOTO label_goto
{
set_whento($<str>2); 
sprintf($<str>$,"%d",WHEN_GOTO);
}
		|	STOP
{ set_whento(""); 
sprintf($<str>$,"%d",WHEN_STOP);
}
		|	FCALL function_name_when
{
set_whento($<str>2);
sprintf($<str>$,"%d",WHEN_CALL);
}
		;



label_goto	:	identifier
		|	COLON identifier
{sprintf($<str>$,"%s",$<str>2);}
		;

function_name_when:	identifier
		;

/* =============================== whenever.rule ==================== */
/*
=====================================================================
                        Source: while.rule
=====================================================================
*/


while_cmd : WHILE
{
print_while_1();
push_blockcommand("WHILE");
} fgl_expr {
print_while_2();
}
            commands
END_WHILE {
print_while_3();
pop_blockcommand("WHILE");
}
;

/* ========================= while.rule ========================= */

/*
=====================================================================
                        Source: window.rule
=====================================================================
*/


op_clr_fields : | KWFIELD fld_list
;

op_to_defs : 
{ strcpy($<str>$,"0"); }
| TO_DEFAULTS { strcpy($<str>$,"1"); }
;

clear_cmd	:	CLEARSCR { print_clr_window("\"screen\""); }
		|	CLEARWIN win_name { print_clr_window($<str>2); }
		|	CLEARSTAT win_name { print_clr_window($<str>2); }
		|	CLEARFORM { print_clr_form(0,0,"0"); }
		|	CLEARFORMTODEFAULTS { print_clr_form(0,0,"1"); }
		|	CLEAR_X_FORM form_name op_clr_fields  op_to_defs { print_clr_form($<str>2,$<str>3,$<str>4); }
		|	CLEAR fld_list op_to_defs {
	print_clr_fields($<str>2,$<str>3);
}
;

fld_list	:	field_name  {sprintf($<str>$,"%s",$<str>1);}
		|	fld_list COMMA field_name {sprintf($<str>$,"%s,%s",$<str>1,$<str>3);}
;


current_win_cmd	:	CWIS {
	print_current_window("\"screen\"");
}
		|	CURRENT_WINDOW_IS win_name 
{
	print_current_window($<str>2);
};

window_type	:	fgl_expr ROWS COMMA fgl_expr COLUMNS {
sprintf($<str>$,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
		|	KWFORM fgl_expr {
sprintf($<str>$,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
};

show_cmd : SHOW_WINDOW win_name {
	print_show_window($<str>2);
	addmap("Show Window",$<str>2,curr_func,yylineno,infilename); 
}
| SHOW_MENU menu_name KW_USING menu_handler op_mnfile {
	print_show_menu($<str>2,$<str>4);
	addmap("Call Menuhandler",$<str>4,curr_func,yylineno,infilename); 
}
;
op_mnfile : {

print_def_mn_file();

} | FROM fgl_expr
;

menu_name: identifier
{addmap("Use Menu",$<str>1,curr_func,yylineno,infilename); }
;

menu_handler: identifier;


hide_cmd : HIDE_WINDOW win_name {
	print_hide_window($<str>2);
}
;

move_cmd : MOVE_WINDOW win_name TO fgl_expr COMMA fgl_expr 
{
print_move_window($<str>2,0);
}
          |  MOVE_WINDOW win_name BY fgl_expr COMMA fgl_expr
{
print_move_window($<str>2,1);
}
;

/* ========================== window.rule ========================= */


 /* ================ from make_enable ================= */

NAMED : NAMED_GEN
;

 /* ================ end make_enable ================= */

/* ========================== from mkyacc =========================== */
commands : | command1 ;
all_commands : commands_all opt_semi ;
command1	: all_commands  {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",$<str>$);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
| command1  all_commands {
A4GL_lex_printcomment("/* [COMM:%s] */\n",$<str>2);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
;

commands_all :  {print_cmd_start();} commands_all1 {print_cmd_end();};
commands_all1 	:
 		pause_screen_on_cmd
	|	pause_screen_off_cmd
	|	start_rpc_cmd
	|	stop_rpc_cmd
	|	call_cmd
	|	case_cmd
	|	close_cmd
	|	code_cmd
	|	comment_cmd
	|	construct_cmd
	|	defer_cmd
	|	display_b_n_cmd
	|	display_cmd
	|	display_form_cmd
	|	display_array_cmd
	|	error_cmd
	|	ext_cmd
	|	continue_cmd
	|	exit_prog_cmd
	|	for_cmd
	|	foreach_cmd
	|	free_cmd
	|	goto_cmd
	|	check_menu_cmd
	|	uncheck_menu_cmd
	|	disable_cmd
	|	enable_cmd
	|	msg_box_cmd
	|	if_cmd
	|	init_cmd
	|	next_field_cmd
	|	next_form_cmd
	|	input_cmd
	|	scroll_cmd
	|	label_cmd
	|	let_cmd
	|	linked_cmd
	|	linked_del_cmd
	|	linked_upd_cmd
	|	locate_cmd
	|	at_term_cmd
	|	return_cmd
	|	menu_cmd
	|	next_option_cmd
	|	show_option_cmd
	|	hide_option_cmd
	|	message_cmd
	|	open_window_cmd
	|	open_statusbox_cmd
	|	open_form_cmd
	|	open_session_cmd
	|	open_cursor_cmd
	|	connect_cmd
	|	options_cmd
	|	prepare_cmd
	|	execute_cmd
	|	prompt_cmd
	|	gui_prompt_cmd
	|	put_cmd
	|	start_cmd
	|	output_cmd
	|	finish_cmd
	|	term_rep_cmd
	|	report_cmd
	|	run_cmd
	|	drops_cmd
	|	create_cmd
	|	upd_stats_cmd
	|	alter_cmd
	|	set_cmd
	|	sleep_cmd
	|	set_database_cmd
	|	sql_cmd
	|	flush_cmd
	|	declare_cmd
	|	unload_cmd
	|	load_cmd
	|	sql_block_cmd
	|	whenever_cmd
	|	while_cmd
	|	clear_cmd
	|	current_win_cmd
	|	show_cmd
	|	hide_cmd
	|	move_cmd
/* ========================== end from mkyacc =========================== */
/*
=====================================================================
                        Source: last.reqd
=====================================================================
*/

;
%%
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


