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

/**
 * Embedded C language code.
 * 4gl example code:
 *    START C
 *     ... C Code...
 *    END C
 */
code_cmd 
  : KW_CSTART emb_code KW_CEND
  ;

/**
 * Possible types of embedded code: SQL or C code
 */
emb_code 
  : sql_code 
	| c_code
	;

/**
 * List of embedded SQL code lines
 */
sql_code 
  : sql_code_part 
	| sql_code sql_code_part
  ;

/**
 * SQL Code line
 */
sql_code_part
  : SQLLINE 
  ;

/**
 * List of embedded C code lines
 */
c_code 
  : c_code_part 
	| c_code c_code_part
  ;

/**
 * Embedded C code line
 */
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
 * 4gl example code:
 *   CONSTRUCT BY NAME pr.* ON str
 *    ... construct events ...
 *   END CONSTRUCT
 */
construct_cmd	
  :	CONSTRUCT constr_rest end_constr 
  ;


/**
 * The main part of construct between CONSTRUCT and END CONSTRUCT
 * 4gl example code:
 *    BY NAME pr.* ON str
 *    AFTER FIELD xpto
 *       ... 4gl code ...
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
 * 4gl code example:
 *    xpto.a, xpto.b, x
 */
constr_col_list 
  : constr_col 
	| constr_col_list COMMA constr_col
  ;

/**
 * A construct column
 * 4gl code examples:
 *    xpto.*
 *    xpto.a
 *    y
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
 * 4gl code examples:
 *    BEFORE FIELD xpto
 *      ... 4gl statements ...
 *    AFTER FIELD xpto
 *      ... 4gl statements ...
 *    ON KEY (CONTROL-A)
 *      ... 4gl statements ...
 *    AFTER CONSTRUCT
 *      ... 4gl statements ...
 *    BEFORE CONSTRUCT
 *      ... 4gl statements ...
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
 * 4gl code example:
 *    first_field, second_field
 */
bef_c_field_list 
  : field_name2 
	| bef_c_field_list COMMA field_name2 
  ;

/**
 * The after field construct list 
 * 4gl code example:
 *    first_field, second_field
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

/**
 *
 */
link_to_pk_list 
  : link_to_pk 
	| link_to_pk_list COMMA link_to_pk 
  ;

/**
 *
 */
link_to_pk 
  : define_ident
  ;

/**
 * A datatype identifier
 */
dtype_ident 
  : dtype2 
	;

/**
 * Optional static qualifier.
 */
op_as_static 
  : 
	| AS_STATIC
  ;

/**
 * Possible datatypes with optional static qualifier.
 */
dtype2
  : dtype op_as_static
  ;

/**
 * Possible 4gl data types.
 */
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

/**
 * A variable declared as table.column
 */
like_var 	
  : LIKE tab_name DOT col_name  
  ;

/**
 * A database table name.
 */
tab_name 
  : define_ident 
	;

/**
 * A database column name.
 */
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

/**
 * Interval datatype precision qualifier.
 */
interval_qual 
  : int_start TO int_end  
  ;

/**
 * Datetime start precision.
 */
dtime_start 
  : dtime_val 
  ;

/**
 * Datatime value.
 */
dtime_val 
  : YEAR
  | MONTH
  | DAY
  | HOUR
  | MINUTE
  | SECOND
  | FRACTION opt_frac
  ;

/**
 * Datetime end precision.
 */
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

/**
 * The size of the the interval units ???
 */
opt_unit_size
  : 
  | OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
  ;

/**
 *
 */
dtfrac
  : INT_VALUE 
  ;

/**
 * Interval start precision
 */
int_start 
  : 
	int_start_unit opt_unit_size 
  ;

/**
 * Interval starting unit.
 */
int_start_unit 
  : YEAR 
  | MONTH
  | DAY
  | HOUR
  | MINUTE
  | SECOND
  | FRACTION opt_frac
  ;

/**
 * Interval end unit.
 */
int_end 
  : int_start_unit
	;

/**
 * Optional equal sign
 */
op_equal 
  : 
	| EQUAL 
  ;

/* </DEFINE_STATEMENT> */


/* <DIM_STATEMENT> */

/**
 *
 */
dim_section 
  : DEFINE_TYPE identifier AS dim_dtype
  ;

/**
 *
 */
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

/**
 *
 */
dim_like_var
  : LIKE tab_name  DOT col_name  
  ;

/**
 *
 */
dim_array_variable
  : ARRAY OPEN_SQUARE number_arr_list CLOSE_SQUARE OF dim_dtype
  | ASSOCIATE op_char assoc_open_bracket INT_VALUE assoc_close_bracket
    WITH_ARRAY OPEN_SQUARE number_arr_assoc CLOSE_SQUARE OF dim_dtype  
  ;

/**
 *
 */
dim_record_variable
  : RECORD dim_def_part END_RECORD
  | RECORD_LIKE identifier DOT MULTIPLY
  ;

/**
 *
 */
dim_def_part 
  : dim_def_part2 
	| dim_def_part COMMA dim_def_part2
  ;

/**
 *
 */
dim_def_part2 
  : dim_var_def_list dim_dtype
  ;

/**
 *
 */
dim_var_def_list	
  : dim_var_def_name
	| dim_var_def_list COMMA dim_var_def_name 
	;

/**
 *
 */
dim_var_def_name	
  :	identifier 
	;

/* </DIM_STATEMENT> */


/* <DISPLAY_STATEMENT> */

/**
 * Optional AT used on the DISPLAY statement.
 * 4gl code examples:
 *   AT 3, 5
 * @todo : More examples.
 */
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

/**
 * The display by name statement definition.
 * 4gl code example:
 *   DISPLAY BY NAME a, b ATTRIBUTE(BORDER)
 */
display_b_n_cmd 
  : DISPLAY_BY_NAME ibind_var_list display_attr 
  ;


/**
 * The display statement.
 * 4gl code example:
 *   DISPLAY a, " XPTO ", 4 ATTRIBUTE(REVERSE)
 */
display_cmd 
  : DISPLAY fgl_expr_list opt_at display_attr 
  ;

/**
 * The display form statement.
 * 4gl code example:
 *   DISPLAY FORM "form_name" ATTRIBUTE(REVERSE)
 */
display_form_cmd 
  : DISPLAY_FORM form_name display_attr 
  ;

/**
 * The display array statement.
 * 4gl code example:
 *   DISPLAY ARRAY array_var TO xpto.* ATTRIBUTES(REVERSE)
 *     ... EVENTS ...
 *   END DISPLAY
 */
display_array_cmd 
  : DISPLAY_ARRAY use_arr_var TO identifier DOT MULTIPLY opt_scroll 
	  opt_attributes disp_rest 
  ;

/**
 * Optional scroll to display array statement.
 * 4gl code example:
 *   SCROLL USING a
 * @todo : Understand what is this. I think that is an extension to standard 4gl
 */
opt_scroll
  : 
  | SCROLL_USING field_name 
  ;

/**
 * Attributes used on the DISPLAY statements.
 */
display_attr	
  :	opt_attributes 
	;

/**
 * The optional part (events and end display) of DISPLAY ARRAY statement.
 */
disp_rest 
  : 
	| disp_field_commands END_DISPLAY
	;

/**
 * Event handlers list for DISPLAY ARRAY statement.
 */
disp_field_commands 
  : disp_field_command 
	| disp_field_commands disp_field_command
	;

/**
 * The specific DISPLAY ARRAY events
 * 4gl code examples:
 *    AFTER ROW
 *      ... 4gl code ...
 *    BEFORE ROW
 *      ... 4gl code ...
 *    ON KEY (CONTROL-P)
 *      ... 4gl code ...
 */
disp_field_command 
  : AFTROW commands 
	| BEFROW commands 
	| on_key_command commands 
  ;

/* </DISPLAY_STATEMENT> */

/* <ERROR_STATEMENT> */

/**
 * Error statement
 * 4gl code example:
 *   ERROR "This is an error number : ", status ATTRIBUTE(REVERSE)
 */
error_cmd	
  : ERROR fgl_expr_concat opt_attributes 
	| ERROR fgl_expr_concat opt_attributes  WAIT_FOR_KEY 
  ;

/* </ERROR_STATEMENT> */


/* <EXIT_STATEMENT> */

/**
 * All possible EXIT statements.
 */
exit_cmd 
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

/**
 * All possible continue statements.
 */
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

/**
 * Exit program statement
 */
exit_prog_cmd 
  : EXIT_PROGRAM 
  | EXIT_PROGRAM fgl_expr 
  ;

/* </EXIT_PROGRAM_STATEMENT> */


/* <EXPRESSION_RULE> */

/**
 * The 4gl expression definition.
 * This is diferent of fgl_expr.
 *
 * @todo : Understand the diference
 */
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

/**
 * Some formating of expressions
 */
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

/**
 * Optional 4gl ???ret??? expression.
 */
op_fgl_expr_ret_list
  : 
	| fgl_expr_ret_list
  ;

/**
 * 4gl ???ret??? expression.
 */
fgl_expr_ret 
  : fgl_expr 
	| KW_NULL
  ;

/**
 * Comma separated 4gl ??? ret ??? list
 */
fgl_expr_ret_list 	
  : fgl_expr_ret
	| fgl_expr_ret_list COMMA fgl_expr_ret
  ;

/**
 * Comma separated 4gl expression list.
 */
fgl_expr_list 	
  : fgl_expr
	| fgl_expr_list COMMA fgl_expr
  ;

/**
 * Comma separated 4gl expressions concatenation.
 * @todo : See why this rule is equal to fgl_expr_list
 */
fgl_expr_concat	
  :	fgl_expr
	| fgl_expr_concat COMMA fgl_expr
  ;

/**
 * 4gl expressions 
 */
fgl_expr
  : fgl_expr_c 
  ;

/**
 * Integer signals
 */
int_sign	
  : PLUS
	| MINUS
  ;

/**
 * Boolean expressions
 */
boolean_expr
  : NOT fgl_expr_c 
  | KW_TRUE  
  | KW_FALSE 
  | OPEN_BRACKET fgl_expr_c CLOSE_BRACKET
  | EXISTS OPEN_BRACKET in_select_statement_ss CLOSE_BRACKET
  | NOT_EXISTS OPEN_BRACKET in_select_statement_ss CLOSE_BRACKET 
  ;	

/**
 * Initial expression.
 * @todo : Describe better this expression.
 */
initial_expr
  : int_sign real_number 
  | int_sign INT_VALUE 
  ;

/**
 * Literal (???) expression.
 */
literal_expr
  : CHAR_VALUE  
  | real_number
  | INT_VALUE
  | variable_entry
  ;

/**
 * Variable used in expressions
 */
variable_entry_2 
  : variable
	| variable THRU variable
  ;

/**
 * Variable entry.
 * @todo : Understand why cannot use variable_entry_2 directly
 */
variable_entry 
  : variable_entry_2 
  ;

/**
 * 4gl Expressions that are used only inside reports
 */
report_only_expr
  : COLUMN fgl_expr_c 
  | COLUMNS fgl_expr_c 
  | rep_agg  
  | GROUP rep_agg
  ;

/**
 * AND/OR expressions
 */
and_or_expr
  : KW_AND fgl_expr_c 
  | KW_OR fgl_expr_c 
  ;

/**
 * A comma separated expression list.
 */
inexpr_list 
  : fgl_expr_c  
	| inexpr_list COMMA fgl_expr_c
  ;

/**
 * IN expression to use in intervals.
 * 4gl code example:
 *   IN (SELECT x FROM y)
 *   IN (1,2,3)
 *   NOT IN (1,2,3)
 */
in_expr
  : IN OPEN_BRACKET in_select_statement_ss CLOSE_BRACKET 
  | NOT_IN OPEN_BRACKET in_select_statement_ss CLOSE_BRACKET 
  | IN OPEN_BRACKET reset_cnt inexpr_list CLOSE_BRACKET 
  | NOT_IN OPEN_BRACKET reset_cnt inexpr_list CLOSE_BRACKET 
  ;

/**
 * NULL expressions.
 * 4gl code examples:
 *    IS NULL
 *    IS NOT NULL
 */ 
null_expr
  : IS_NULL  
  | IS_NOT_NULL
  ;

/**
 * Matches expressions to find patterns in strings.
 */
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

/**
 * Clipped expression.
 * @todo : Understand why this rule is needed because just have a TOKEN.
 */
clip_expr
  : CLIPPED 
  ;

/**
 * The using number formating to be used in expressions.
 */ 
using_expr
  : KW_USING fgl_expr_c 
  ;

/**
 * The matematical expressions.
 */
math_expr
  : PLUS fgl_expr_c 
  | MINUS fgl_expr_c
  | MULTIPLY fgl_expr_c 
  | DIVIDE  fgl_expr_c 
  | MOD fgl_expr_c 
  | POWER fgl_expr_c 
  ;

/**
 * Comparison expressions
 */
comparison_expr
  : EQUAL fgl_expr_c 
  | EQUAL_EQUAL fgl_expr_c 
  | LESS_THAN fgl_expr_c
  | GREATER_THAN fgl_expr_c
  | NOT_EQUAL fgl_expr_c
  | LESS_THAN_EQ fgl_expr_c
  | GREATER_THAN_EQ fgl_expr_c
  ;

/**
 * To remove.
 */
reset_cnt : {
	reset_counter();
}
;

/**
 * A call of a function inside an expression.
 */
function_call_expr2
  : identifier OPEN_BRACKET opt_func_call_args CLOSE_BRACKET 
  | identifier DOUBLE_COLON identifier 
	  OPEN_BRACKET opt_func_call_args CLOSE_BRACKET 
  ;

/**
 * @todo : I supose that the parser does not work without some consumed code.
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

/**
 * Optional 
 */
op_extend_d
  : 
	| s_curr_v TO e_curr_v
  ;

/**
 * @todo : This is not optional
 */
op_extend_i
  : interval_qual
  ;

/**
 * A function call inside an expression.
 */
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

/**
 * A builtin expression.
 */
builtin_expr 
  : curr_v_clause 
  | DATE  
  ;

/**
 * Language built in functions.
 */
builtin_funcs 
  : UPSHIFT OPEN_BRACKET fgl_expr_c CLOSE_BRACKET 
  | DOWNSHIFT OPEN_BRACKET fgl_expr_c CLOSE_BRACKET
  | ASCII fgl_expr_c  
  | EXTEND extend_parameters
  ;

/**
 * PDF report generation special expressions.
 * This is an extension to standard Informix 4gl.
 */
pdf_expr 
  : fgl_expr_c POINTS  
  | fgl_expr_c MM 
  | fgl_expr_c INCHES
  ;

/**
 * The parameters of the INTERVAL function.
 * 4gl code example:
 */
interval_func_params 
  : CHAR_VALUE 
  | numeric_time_interval 
  ;

/**
 * Constant / literal interval values.
 */
numeric_time_interval
  : MINUS numeric_time_interval 
	| numeric_time_unit_big	
	| numeric_time_unit_small	
  ;

/**
 * Constant time values.
 */
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

/**
 * Constant time values. 
 */
numeric_time_unit_big
  : INT_VALUE
	| INT_VALUE MINUS INT_VALUE 
  ;

/**
 * A comma separated list of form field names.
 * Used on field_touched function
 */
field_name_list
  : field_name 
	| field_name_list COMMA field_name 

/* </EXPRESSION_RULE> */


/* <FOR_RULE> */

/**
 * The FOR loop statement.
 * 4gl code examples:
 *   FOR i = 1 TO 10 STEP 2
 *      ... 4gl statements ...
 *   END FOR
 */
for_cmd	
  : FOR variable EQUAL fgl_expr TO fgl_expr op_for_step commands END_FOR 
  ;

/**
 * The optional step in the FOR loop.
 * 4gl code example:
 *   STEP -1
 */
op_for_step 
  :	
	|	STEP fgl_expr
  ;

/* </FOR_RULE> */


/* <FOREACH_RULE> */

/**
 * The 4gl FOREACH statement.
 * 4gl code examples:
 *    FOREACH crXppto INTO rec.a, rec.b
 *      ...4gl statements...
 *    END FOREACH
 */
foreach_cmd	
  :	FOREACH fetch_cursor_name opt_foreach_using_part
    opt_foreach_into_fetch_part commands END_FOREACH 
  ;

/**
 * The optional foreach loop USING sub statement.
 * 4gl code example:
 *    USING a,b,2
 */
opt_foreach_using_part
  : 
	| KW_USING reset_cnt fgl_expr_list 
	;

/* </FOREACH_RULE> */


/* <FORM_HANDLER_RULE> */

/**
 * @todo : Understand what is this rule. I think that is an extension to 
 * standard informix 4gl.
 */
formhandler_def 
  : FORMHANDLER identifier define_section  op_code op_bef_ev_list
    op_input_section op_aft_ev_list END_FORMHANDLER 
  ;

/**
 * Optional input section of the FORMHANDLER.
 */
op_input_section 
  : 
	| input_section
	;

/**
 * Optional list of Before events.
 */
op_bef_ev_list 
  :
	| bef_ev_list
  ;

/**
 * List of before events.
 */
bef_ev_list 
  : bef_ev 
	| bef_ev_list bef_ev
  ;

/**
 * A specific before event of FORM HANDLER.
 */
bef_ev 
  : BEFORE_EVENT commands 
  | BEFORE_OPEN_FORM commands 
  ;

/**
 * Optional list of after events
 */
op_aft_ev_list 
  :
  | aft_ev_list
  ;

/**
 * List of after events of FORM HANDLER.
 */
aft_ev_list 
  : aft_ev 
	| aft_ev_list aft_ev
  ;

/**
 * A specific AFTER event to use in FORM HANDLER.
 */
aft_ev 
  : AFTER_EVENT commands 
  | BEFORE_CLOSE_FORM commands 
  ;

/**
 * The input section of FORM HANDLER.
 */
input_section  
  : input_sub_section field_ops END_INPUT
  ;

/**
 * The input sub section of FORM HANDLER.
 */
input_sub_section 
  : FORMHANDLER_INPUT
  | FORMHANDLER_INPUT in_variable_list FROM in_id_list
  | FORMHANDLER_INPUT BY_NAME in_bn_variable_list
  ;

/**
 *
 */
in_variable_list 
  : variable 
	| in_variable_list COMMA variable
  ;

/**
 *
 */
in_id_list 
  : identifier 
	| in_id_list COMMA identifier
  ;

/**
 *
 */
in_bn_variable_list 
  : variable 
	| in_bn_variable_list COMMA variable
  ;

/**
 *
 */
field_ops 
  : field_op 
	| field_ops field_op
  ;

/**
 *
 */
field_op 
  : BEFORE_ANY commands 
  | AFTER_ANY commands 
  | BEFORE in_id_list commands 
  | AFTER in_id_list commands 
  | ON in_id_list commands
  ;

/* </FORM_HANDLER_RULE> */


/* <FREE_STATEMENT> */

/**
 * FREE cursor statement
 * 4gl code example:
 *    FREE crXpto
 */
free_cmd 
  : FREE cursor_name
  ;

/* </FREE_STATEMENT> */


/* <GENERAL_RULE> */

/**
 * A screen line number to be used on statements that need it (ex: PROMPT LINE)
 */
line_no		
  : LAST MINUS INT_VALUE 
	| LAST 
	| FIRST PLUS INT_VALUE 
	| FIRST 
	| INT_VALUE 
	| variable 
	| OFF 
  ;

/**
 * A file name to be used in statements like LOCATE.
 * 4gl code examples:
 *     "/tmp/xpto"
 *     fileName
 */
file_name	
  :	CHAR_VALUE 
	| cvariable 
  ;

/**
 * A number as any expression. Used only to define screen coordinates.
 */
a_number	
  :	fgl_expr
	;

/**
 * Screen coordinates that define a line and a column. Used in statements
 * like DISPLAY AT.
 * 4gl code examples:
 *    1, 2
 *    x, y
 */
coords		
  :	a_number COMMA a_number 
  ;

/**
 * Screen coordinates to ne used only in DISPLAY AT statement.
 * @todo : Undestand if this rule can be removed.
 */
display_coords	
  :	coords
	;

/**
 * A form field name to be used in screen interaction statements.
 * 4gl code examples:
 *    xpto
 *    
 */
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

/**
 * The name of a cursor
 * 4gl code example:
 *   crXpto
 */
cursor_name	
  :	ident_or_var 
  ;

/**
 * The name of a cursor when used to be fecthed.
 * @todo : See if this rule can be merged with cursor_name.
 */
fetch_cursor_name	
  :	ident_or_var 
	;

/**
 * The name of a screen window
 */
win_name	
  :	ident_or_var 
  ;

/**
 * The name of a screen window when they are opened.
 */
open_win_name	
  :	ident_or_var 
  ;

/**
 * The name of a form.
 */
form_name	
  : ident_or_var 
  ;

/**
 * The name of a form when it is to be opened.
 */
open_form_name	
  : ident_or_var 
  ;

/**
 * An optional help number to be used in INPUT(s), menu(s), etc.
 * 4gl code example:
 *    HELP 100
 */
opt_help_no		
  :	
	| HELP INT_VALUE 
  ;

/**
 * An identifier.
 */
identifier	
  : NAMED  
  ;

/**
 * An identifier or variable.
 */
ident_or_var	
  : ident_p2  
  ;

/**
 * An identifier
 * @todo : Understand why this rule is needed.
 */
ident_p2 
  : NAMED 
  | VARIABLE OPEN_BRACKET var_or_string CLOSE_BRACKET
  ;

/**
 * A variable or string
 */
var_or_string 
  : var 
	| CHAR_VALUE
	;

/**
 * Another rule for field name.
 * @todo : Understand if this rule is realy needed.
 */
field_name2	
  :	identifier 
  | identifier OPEN_SQUARE arr_expr CLOSE_SQUARE
	| identifier DOT MULTIPLY
	| identifier OPEN_SQUARE arr_expr CLOSE_SQUARE DOT MULTIPLY
	| identifier DOT identifier 
  | identifier OPEN_SQUARE arr_expr CLOSE_SQUARE DOT identifier
  ;

/**
 * @todo : understand why this rule is needed.
 */
cvariable 
  : variable 
  ;

/**
 * A real literal number 
 */
real_number 
  : NUMBER_VALUE 
	| DOT INT_VALUE 
  ;

/* </GENERAL_RULE> */


/* <GOTO_STATEMENT> */

/**
 * Goto statement
 * 4gl code example:
 *    GOTO xptoLabel
 */
goto_cmd 
  : GOTO label_goto 
  ;

/* </GOTO_STATEMENT> */


/* <UI_RULE> */

/**
 *
 */
check_menu_cmd 
  : CHECK_MENUITEM menu_item_list
  ;

/**
 *
 */
menu_item_list
  : menu_item 
	| menu_item_list COMMA menu_item
  ;

/**
 *
 */
menu_item
  : identifier 
  ;

/**
 *
 */
uncheck_menu_cmd 
  : UNCHECK_MENUITEM menu_item_list
  ;

/**
 *
 */
disable_cmd 
  : DISABLE_MENUITEMS menu_item_list
  | DISABLE fld_list
  | DISABLE_FORM form_name KWFIELD fld_list
  ;

/**
 *
 */
enable_cmd 
  : ENABLE_MENUITEMS menu_item_list
  | ENABLE fld_list
  | ENABLE_FORM form_name KWFIELD fld_list
  ;

/**
 *
 */
msg_box_cmd 
  : MESSAGEBOX fgl_expr_list
    op_caption
    op_icon
    op_buttons
    op_disable_msg
    op_returning_msg 
  ;

/**
 *
 */
op_disable_msg 
  :
  | gm_disable_msg
  ;

/**
 *
 */
gm_disable_msg
  : DISABLE_PROGRAM 
	| DISABLE_ALL
  ;

/**
 *
 */
op_returning_msg 
  : 
  | gm_returning_msg
  ;

/**
 *
 */
gm_returning_msg
  : RETURNING variable
  ;

/**
 *
 */
op_caption 
  : 
	| gm_caption
  ;

/**
 *
 */
gm_caption
  : CAPTION fgl_expr_list 
	;

/**
 *
 */
op_icon 
  : 
	| gm_icon
  ;

/**
 *
 */
gm_icon
  : ICON INT_VALUE  
	;

/**
 *
 */
op_buttons 
  : 
	| gm_buttons
	;

/**
 *
 */
gm_buttons 
  : BUTTONS INT_VALUE op_def_but
	;

/**
 *
 */
op_def_but 
  : 
	| DEFAULT INT_VALUE
	;

/* </UI_RULE> */


/* <IF_STATEMENT> */

/**
 * 4gl IF statement
 * 4gl code example:
 *    IF i = 1 THEN
 *       ... 4gl statements ...
 *    ELSE
 *       ... 4gl statements ...
 *    END IF
 */
if_cmd	
  : IF fgl_expr THEN  commands op_else END_IF 
  ;

/**
 * Optional ELSE subsatement of IF command.
 * 4gl code examples:
 *   ELSE
 *     ... 4gl statements ...
 *
 *   ELSE IF x = 1 THEN
 *     ... 4gl statements ...
 */
op_else 
  : 
	| ELSE 
	| ELIF fgl_expr THEN commands op_else 
	;

/* </IF_STATEMENT> */

/**
 * Import function statement.
 * This statement is an extension to original Informix 4gl.
 */
import_m 
  : IMPORT_FUNCTION identifier OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
	| IMPORT_LEGACY_FUNCTION identifier 
  ;

/**
 * Datatype import.
 */
module_import
  : IMPORT_DATATYPE identifier 
  ;


/* <INITIALIZE_STATEMENT> */

/**
 * The statement INITIALIZE to init values to variables.
 * 4gl code examples:
 *   INITIALIZE x, y, z.* TO NULL
 *   INITIALIZE x LIKE tab.col
 */ 
init_cmd 
  : INITIALIZE init_bind_var_list TO KW_NULL
  | INITIALIZE init_bind_var_list LIKE init_tab_list
  ;

/**
 * A list of tables used on initialize statement.
 */
init_tab_list 
  : init_tab 
	| init_tab_list COMMA init_tab 
  ;

/**
 * An table definitiono to be used on INITIALIZE statement.
 */
init_tab 
  : tab_name DOT column_name 
	| tab_name DOT MULTIPLY 
  ;

/* </INITIALIZE_STATEMENT> */

/* <INPUT_STATEMENT> */

/**
 * Optional end input.
 */
end_input 
  :
  | field_commands END_INPUT 
	;

/**
 * Optional WHITHOUT DEFAULTS property of INPUT statement.
 */
opt_defs 
  : 
  | WITHOUT_DEFAULTS 
  ;

/**
 * The list of field commands to be used inside INPUT statement.
 * The commands are the field and input events.
 */
field_commands 
  : field_command 
	| field_commands field_command
	;

/**
 * The field commands tyo be used inside the INPUT statement.
 */
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

/**
 * The list of fields to be used in before field event of the INPUT
 * statement.
 */
bef_field_list 
  : field_name 
	| bef_field_list COMMA field_name 
  ;

/**
 * The list of fields to be used in after field events of the INPUT 
 * statement.
 */
aft_field_list 
  : field_name 
	| aft_field_list COMMA field_name 
  ;

/**
 * The next field command that is used inside the events of the INPUT
 * statement.
 */
next_field_cmd 
  : NEXTFIELD next_field 
  ;

/**
 *
 */
next_form_cmd 
  : NEXTFORM identifier KWFIELD next_field 
  ;

/**
 * The definition of the field that where to move with
 * NEXT FIELD command.
 */
next_field	
  :	NEXT 
	| PREVIOUS 
	| field_name 
  ;

/**
 * The main rule of the INPUT statement.
 */
input_cmd	
  :	INPUT inp_rest end_input 
  ;

/**
 * The inside of the INPUT statement.
 * 4gl code examples:
 *   BY NAME xpto.* HELP 100
 *   BY NAME xpto.* HELP 100
 *   ARRAY vsArray FROM pa 
 */
inp_rest
  : BY_NAME ibind_var_list opt_defs opt_help_no opt_attributes 
  | ibind_var_list opt_defs FROM fld_list  opt_help_no opt_attributes 
  | ARRAY use_arr_var opt_defs FROM identifier DOT MULTIPLY opt_help_no 
    opt_attributes
  ;

/**
 * Scroll statement that scrolls up or down the values of an array
 * in a screen array.
 */
scroll_cmd 
  : SCROLL fld_list up_or_down 
  ;

/**
 * The up or down definition os the scroll statement and the amount of
 * lines.
 * 4gl code example:
 *    UP 2
 *    DOWN 4
 *    UP
 *    DOWN
 */
up_or_down  
  : KWUP_BY INT_VALUE 
	| KWDOWN_BY INT_VALUE 
	| KWUP 
	| KWDOWN 
  ;

/**
 * Optional help used in the construct statement.
 * 4gl code example:
 *    HELP 20
 */
op_help 
  : 
	| HELP INT_VALUE
  ;

/**
 * Specific INPUT ARRAY attributes.
 * @todo : Understand if this rule could be merged with 
 * input_array_attributes_int rule.
 */
input_array_attributes
  : input_array_attributes_int 
  ;

/**
 * Soecific INPUT ARRAY attributes.
 */
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

/**
 * The on key command used on PROMPT, CONSTRUCT, INPUT statements.
 * 4gl code example:
 *   ON KEY CONTROL-A 
 *   ON ANY KEY
 */
on_key_command 
  : ONKEY key_do 
  | ON_ANY_KEY 
  ;

/**
 * A possible KEY definition.
 * 4gl code example:
 *    KEY CONTROL-X
 */ 
key_val 
  : KEY key_do 
	;

/**
 * The accept key definition.
 * 4gl code example:
 *    ACCEPT KEY ESC
 */
accept_key 
  :  ACCEPTKEY key_value 
  ;


/**
 * A single key definition.
 * 4gl code example:
 *   KEY CONTROL-X
 */
single_key_val 
  : KEY key_do 
  ;

/**
 * A multiple key definition.
 * 4gl code examples:
 *   CONTROL-W
 *   (CONTROL-W,ESC)
 */
key_do	
  : key_value  
	| OPEN_BRACKET key_value_list CLOSE_BRACKET  
  ;

/**
 * A list of comma separated key definition.
 * 4gl code example:
 *    CONTROL-W,ESC
 */
key_value_list 
  : key_value 
	| key_value_list COMMA key_value 
  ;

/**
 * A key value.
 * @todo : Understand if this rule can be merged with key_value_1
 */
key_value 
  : key_value_1 
  ;

/**
 * The definition of all possible specific keys. 
 * 4gl code examples:
 *    CONTROL-W
 *    F1
 *    ESCAPE
 */
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


/**
 * The 4gl LABEL statement to be used with the GOTO statement.
 * The identifier of the label is readed by the lexer.
 * 4gl code example:
 *   LABEL xpto
 */
label_cmd 
  : LABEL  
  ;


/* <LET_STATEMENT> */

/** 
 * The 4gl assignment LET stateement.
 * 4gl code examples:
 *    LET i = 10
 *    LET pRecord.* = NULL
 */
let_cmd 
  : LET obind_var_let_list EQUAL op_expr_null
  ;

/**
 * Optional null expression.
 * @todo : Change the name to this rule because it is not only for NULLS
 * 4gl code example:
 *   NULL
 *   
 */
op_expr_null
  : KW_NULL 
	| fgl_expr_concat 
	;


/* </LET_STATEMENT> */

/** 
 * @todo : Understand what statement is this one.
 */
linked_cmd 
  : SELECT_USING variable 
  ;

/** 
 * @todo : Understand what statement is this one.
 */
linked_del_cmd 
  : DELETE_USING variable 
  ;

/** 
 * @todo : Understand what statement is this one.
 */
linked_upd_cmd 
  : UPDATE_USING variable 
  ;

/**
 * The LOCATE statement to tell where the blob variable is located (in memory
 * or file).
 * 4gl code examples:
 *    LOCATE blobVar IN MEMORY
 *    LOCATE blobVar IN FILE "/tmp/blobFile"
 */
locate_cmd 
  : LOCATE variable IN_MEMORY 
  | LOCATE variable IN_FILE file_name 
  ;


/* <MAIN_RULE> */

/**
 * A 4gl module 
 * 4gl code example:
 *   
 */
module
  : op_module_header func_main_def 
  ;


/**
 * The optional 4gl module header.
 * The module header could be the database, globals and modular
 * variables definition.
 */
op_module_header
  : 
	| module_header 
  ;

/**
 * The list of module header entry(s).
 */
module_header	
  :	module_entry 
	|	module_header module_entry
  ;

/**
 * The possible 4gl header for modules.
 * 4gl code examples:
 *
 */
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
  : 
	| fgl_expr_list 
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


/* <NEWVARIABLE_RULE> */

variable_no_scope
  : variable 
  ;


variable
  : var_int
  ;


var_int 
  : var 
	| DOLLAR var 
  ;

varsetidentdot 
  : var DOT
  ;

var
  : varsetidentdot dot_part_var
  | varsetidentdot identifier OPEN_SQUARE num_list CLOSE_SQUARE 
  | varsetidentdot identifier 
	  OPEN_SQUARE num_list CLOSE_SQUARE OPEN_SQUARE num_list CLOSE_SQUARE 
  | array_r_variable
  | identifier
  | assoc_var_read
  ;

assoc_var_read  
  : identifier OPEN_SHEV assoc_sub CLOSE_SHEV
  ;


assoc_var_write  
  : identifier OPEN_SHEV assoc_sub CLOSE_SHEV
  ;

assoc_sub 
  : variable 
	| CHAR_VALUE
  ;

dot_part_var
  : MULTIPLY 
	| identifier 
  ;

array_r_variable
  : identifier arr_subscripts
  ;

array_r_variable_or_ident
  : identifier arr_subscripts
  ;

arr_subscripts 
  : OPEN_SQUARE num_list CLOSE_SQUARE 
  | OPEN_SQUARE num_list CLOSE_SQUARE OPEN_SQUARE num_list CLOSE_SQUARE 
  ;


num_list
  : num_list_element
  | num_list COMMA num_list_element
  ;

num_list_element
  : arr_expr
  ;

let_variable
  : let_var
  ;

let_var
  : let_array_r_variable 
  | let_var DOT let_var_dot 
  | let_var DOT identifier OPEN_SQUARE num_list CLOSE_SQUARE
  | let_var DOT identifier OPEN_SQUARE num_list CLOSE_SQUARE 
	  OPEN_SQUARE num_list CLOSE_SQUARE
  | identifier
  | assoc_var_write
  ;

let_var_dot 
  : MULTIPLY 
  | identifier 
  ;

let_array_r_variable
  : identifier arr_subscripts
  ;

op_param_var_list
  : 
  | fparam_var_list
	;

fparam_var_list
  :	func_def_var 
	|	fparam_var_list COMMA func_def_var 
  ;

ibind_var_list
  :	ibind_var 
	|	ibind_var_list COMMA ibind_var 
  ;


func_def_var 
  : identifier 
	| identifier DOT identifier 
  ;

ibind_var 
  : variable  
	| variable THRU variable 
	| CHAR_VALUE 
	| real_number 
	| INT_VALUE 
  ;

obind_var_list
  :	obind_var  
	|	obind_var_list COMMA obind_var 
  ;

obind_var 
  : variable
	| variable THRU variable 
  ;

obind_var_let_list
  :	obind_let_var  
	|	obind_var_let_list COMMA obind_let_var 
  ;

obind_let_var 
  : let_variable
  ;

use_arr_var 
  : variable 
  ;

obind_var_list_ord
  :	obind_var_ord
	| obind_var_list_ord COMMA obind_var_ord
  ;

obind_var_ord 
  : variable optional_asc_desc
	;

optional_asc_desc
  : 
	| ASC 
	| DESC
	;

array_r_varid
  : identifier OPEN_SQUARE num_list CLOSE_SQUARE
  ;

init_bind_var_list
  :	init_bind_var 
	|	init_bind_var_list COMMA init_bind_var 
  ;

init_bind_var 
  : variable  
	| variable THRU variable 
  ;

/* </NEWVARIABLE_RULE> */


/* <OPEN_STATEMENTS> */

open_window_cmd 
  : OPEN_WINDOW open_win_name AT coords WITH window_type win_attributes  
  ;

op_at_statusbox 
  : 
	| AT OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET op_size_statusbox
  ;

op_size_statusbox 
  : 
	| SIZE OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET
  ;

open_statusbox_cmd 
  : OPEN_STATUSBOX identifier op_at_statusbox
  ;

formhandler_name
  : identifier 
  ;

open_form_cmd 
  : OPEN_FORM open_form_name  open_form_rest
  ;

open_form_rest
  : open_form_gui
	| FROM fgl_expr 
  ;

open_form_gui
  :  op_at_gui op_like_gui op_disable KW_USING formhandler_name
  ;

op_at_gui
  :
	| AT op_absolute OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET 
  ;

op_like_gui
  : 
	| LIKE ident_or_var
  ;

op_absolute
  : 
	| ABSOLUTE 
  ;

open_session_cmd 
  : OPEN_SESSION conn_id TO_DATABASE var_ident user_details
  ;

open_cursor_cmd 
  : OPEN cursor_name 
	| OPEN cursor_name KW_USING reset_cnt fgl_expr_list 
  ;

user_details 
  :
	| AS USER char_or_var PASSWORD char_or_var
	| AS USER char_or_var COMMA PASSWORD char_or_var
	| AS char_or_var COMMA char_or_var
  ;

op_disable 
  : 
	| DISABLE_PROGRAM 
  | DISABLE_ALL 
  ;

connect_cmd 
  : CONNECT_TO var_ident op_connect_as con_user_details 
  ;

op_connect_as 
  :
  | AS var_ident 
  ;

con_user_details 
  :
  | AS USER char_or_var KW_USING char_or_var
  | USER char_or_var KW_USING char_or_var
  ;

/* </OPEN_STATEMENTS> */


/* <OPTIONS_STATEMENT> */

options_cmd 
  : OPTIONS opt_options
	;

opt_options 
  : opt_allopts
	| opt_options COMMA opt_allopts
	;

opt_allopts 	
  : COMMENT_LINE line_no 
	| ERROR_LINE line_no 
	| FORM_LINE line_no 
	| MENU_LINE line_no 
	| MSG_LINE line_no 
	| PROMPT_LINE line_no 
	| accept_key 
	| DELETE single_key_val 
	| INSERT single_key_val 
	| NEXT single_key_val 
	| PREVIOUS single_key_val 
	| HELP single_key_val 
	| HELP_FILE file_name
	| LANG_FILE file_name
	| DISPLAY attributes_def
	| INPUT attributes_def 
	| INPUT_WRAP 
	| INPUT_NO_WRAP 
	| FOCONSTR 
	| FOUNCONSTR 
	| SQL_INTERRUPT_ON  
	| SQL_INTERRUPT_OFF 
  ;

/* </OPTIONS_STATEMENT> */



/* <PREPARE_STATEMENT> */

prepare_cmd 
  : opt_use PREPARE stmt_id FROM var_or_char 
  ;

var_or_char
  : variable 
	| CHAR_VALUE
	;

execute_cmd 
  : EXECUTE stmt_id
  | EXECUTE stmt_id KW_USING ibind_var_list 
	| EXECUTE_IMMEDIATE var_or_char 
  ;

stmt_id 
  : ident_or_var 
	;

/* </PREPARE_STATEMENT> */


/* <PROMPT_STATEMENT> */

prompt_cmd	
  : PROMPT prompt_title opt_attributes FOR opt_char
    variable opt_timeout opt_help_no opt_attributes 
    prompt_key_sec 
  ;

opt_timeout
  :
  | TIMEOUT INT_VALUE 
  ;

gui_prompt_cmd 
  : PROMPT prompt_title opt_attributes  RETURNING variable 
  ;

opt_char 
  : /* empty */ 
  | CHAR 
  ;

prompt_key_sec 
  :  /* empty */ 
	| prompt_key_clause END_PROMPT
	;

prompt_key_clause 
  : on_key_command_prompt
	| prompt_key_clause on_key_command_prompt 
	;

on_key_command_prompt 
  : on_key_command commands 
  ;

prompt_title 
  : fgl_expr_concat
	;

/* </PROMPT_STATEMENT> */


/* <PUT_STATEMENT> */

put_cmd 
  : PUT cursor_name  put_from
  ;

put_from
  :
  | FROM put_val_list 
  ;

put_val_list  
  : put_val 
	| put_val_list COMMA put_val 
  ;

put_val 
  : value_expression_ss 
  | KW_NULL 
  ;

/* </PUT_STATEMENT> */


/* <REPORT_RULE> */

start_cmd 
  : START_REPORT rep_name TO_PRINTER
	| START_REPORT rep_name TO rout
	| START_REPORT rep_name TO_PIPE rout
	| START_REPORT rep_name
  ;

rout 
  : CHAR_VALUE 
	| cvariable
	;

rep_name 
  : identifier
	;

op_values 
  : 
	| VALUES 
	;

output_cmd 
  : OUTPUT_TO_REPORT rep_name op_values OPEN_BRACKET 
    op_fgl_expr_list CLOSE_BRACKET
  ;

finish_cmd 
  : FINISH_REPORT rep_name
  ;

term_rep_cmd 
  : TERMINATE_REPORT rep_name
  ;

report_section
  : op_output_section op_rep_order_by  
	;

format_section
  : FORMAT EVERY_ROW 
  | FORMAT format_actions
  ;

format_actions 
  : format_action 
	| format_actions format_action
	;

format_action 
  : FIRST_PAGE_HEADER commands 
	| PAGE_TRAILER commands 
	| PAGE_HEADER commands 
	| ON_EVERY_ROW commands 
	| ON_LAST_ROW commands 
	| BEFGROUP variable  commands 
	| AFTGROUP variable commands 
  ;

report_cmd 
  : print_command 
	| print_img_command
	| print_file_command
	| need_command
	| pause_command
	| skip_command
  ;

need_command 
  : NEED fgl_expr KWLINE 
  ;

op_lines 
  : 
	| KWLINE 
  ;

skip_command 
  : SKIP INT_VALUE op_lines 
	| SKIP_TO_TOP 
	| FONT_SIZE nval 
	| SKIP_BY nval 
	| SKIP_TO nval 
  ;

opt_rep_expr_list  
  : 
	| xrep_expr_list
  ;

xrep_expr_list
  : xxrep_expr_list
	| xrep_expr_list xxrep_expr_list
  ;

xxrep_expr_list 
  : rep_expr_list opt_print_at 
  ;

opt_print_at 
  : 
	| AT nval 
  ;

print_command 
  : PRINT opt_rep_expr_list opt_semi 
  ;

print_file_command 
  : PRINT_FILE char_or_var opt_semi 
  ;


print_img_command 
  : PRINT_IMAGE blob_var img_types opt_scaling opt_semi 
  ;

opt_scaling 
  :
	| SCALED_BY fgl_expr_c 
	| SCALED_BY fgl_expr_c COMMA fgl_expr_c 
  ;

img_types 
  :	AS_TIFF 
	| AS_GIF 
	| AS_PNG
	| AS_JPEG
  ;

blob_var 
  :  variable 
  ;

opt_semi 
  : 
  | SEMICOLON 
  ;

rep_expr_list 
  : rep_expr 
  | rep_expr_list COMMA rep_expr 
  ;

rep_expr 
  : fgl_expr op_wordwrap 
  ;

rep_agg 
  : SUM OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
  | COUNT_MULTIPLY rep_where
  | COUNT OPEN_BRACKET MULTIPLY CLOSE_BRACKET rep_where
  | PERCENT   OPEN_BRACKET MULTIPLY CLOSE_BRACKET  rep_where
  | AVERAGE   OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
  | AVG       OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
  | XMIN       OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
  | XMAX       OPEN_BRACKET fgl_expr_c CLOSE_BRACKET  rep_where
  ;

op_output_section 
  : 
	| OUTPUT output_commands 
	;

output_commands 
  : output_command 
	| output_commands output_command
	;

output_command 
  : LEFT_MARGIN INT_VALUE 
  | RIGHT_MARGIN INT_VALUE 
  | TOP_MARGIN INT_VALUE 
  | BOTTOM_MARGIN INT_VALUE 
  | PAGE_LENGTH INT_VALUE 
  | REPORT_TO_PRINTER  
  | REPORT_TO CHAR_VALUE 
  | REPORT_TO variable 
  | REPORT_TO_PIPE CHAR_VALUE 
  | TOP_OF_PAGE CHAR_VALUE 
  ;

pdf_output_commands 
  : pdf_output_command 
	| pdf_output_commands pdf_output_command
	;

nval
  : nval_number POINTS 
	| nval_number INCHES 
	| nval_number MM     
	| nval_number       
  ;

nval_number
  : real_number 
	| INT_VALUE
  ;

pdf_op_output_section 
  : 
	| OUTPUT pdf_output_commands 
	;

pdf_output_command 
  : LEFT_MARGIN nval 
  | RIGHT_MARGIN nval 
  | TOP_MARGIN nval 
  | BOTTOM_MARGIN nval 
  | PAGE_LENGTH nval 
  | PAGE_WIDTH nval 
  | FONT_NAME CHAR_VALUE 
  | FONT_SIZE nval 
  | PAPER_SIZE_IS_A4  
  | PAPER_SIZE_IS_LETTER
  | PAPER_SIZE_IS_LEGAL 
  | PAPER_SIZE_IS_A5 
  | PAPER_SIZE_IS_A4_L 
  | PAPER_SIZE_IS_LETTER_L 
  | PAPER_SIZE_IS_LEGAL_L
  | PAPER_SIZE_IS_A5_L 
  | PAGE_TRAILER_SIZE nval 
  | PAGE_HEADER_SIZE nval 
  | FIRST_PAGE_HEADER_SIZE nval 
  | REPORT_TO CHAR_VALUE 
  | REPORT_TO_PIPE CHAR_VALUE 
  | DEFAULT
  | ASCII_HEIGHT_ALL
  | ASCII_WIDTH_ALL
  ;

op_rep_order_by 
  : 
  | ORDER BY obind_var_list_ord
  | ORDER_EXTERNAL_BY obind_var_list_ord 
  ;

report_def 
  : REPORT identifier OPEN_BRACKET op_param_var_list CLOSE_BRACKET 
	  define_section report_section format_section END_REPORT 
  ;

rep_where 
  :  
  | WHERE fgl_expr_c 
  ;

pause_command
  : PAUSE pause_msg
  ;

pause_msg 
  : 
	| var_or_char 
  ;

pdf_report_def 
  : PDF_REPORT identifier OPEN_BRACKET op_param_var_list CLOSE_BRACKET 
    define_section  pdf_report_section format_section END_REPORT 
  ;

pdf_report_section
  : pdf_op_output_section op_rep_order_by  
	;

pdf_functions 
  : PDF_FUNCTION OPEN_BRACKET CHAR_VALUE COMMA 
   	opt_func_call_args CLOSE_BRACKET opt_return
  ;

op_wordwrap
  :
 	| WORDWRAP 
	| WORDWRAP RIGHT_MARGIN INT_VALUE 
	| WORDWRAP RIGHT_MARGIN variable 
  ;

/* </REPORT_RULE> */


/* <RUN_STATEMENT> */

run_cmd 
  : RUN fgl_expr 
  | RUN fgl_expr RETURNING variable 
  | RUN fgl_expr WITHOUT_WAITING 
  | RUN fgl_expr WAIT 
  | RUN fgl_expr EXIT 
  ;

/* </RUN_STATEMENT> */

drops_cmd 
  : drops_c 
  ;

drops_c 
  : DROP_TABLE  
	| DROP_VIEW  
	| DROP_INDEX  
  ;

create_cmd 
  : create_c_1 
	| create_c_2_ss 
  ;

create_c_2_ss  
  : CREATE_TABLE table_name OPEN_BRACKET table_element_list_ss CLOSE_BRACKET 
	| CREATE_TEMP_TABLE table_name 
	  OPEN_BRACKET table_element_list_ss CLOSE_BRACKET op_no_log 
  ;

create_c_1  
  : CREATE_IDX idx_column_list CLOSE_BRACKET 
	| CREATE_DATABASE ident_or_var 
	;

op_no_log 
  : 
  | WITH_NO_LOG
  ;


idx_column_list 
  : idx_column 
	| idx_column_list COMMA idx_column 
  ;

idx_column 
  : identifier ASC 
  | identifier DESC 
  | identifier
	;

table_element_list_ss
  : table_element_ss 
	| table_element_list_ss COMMA table_element_ss 
  ;
	
table_element_ss
  : ct_column_definiton_ss 
	| table_constraint_definition_ss 
	; 

upd_stats_cmd 
  : UPDATESTATS_T	identifier 
	| UPDATESTATS	
  ;

alter_cmd 
  : ALTER_TABLE identifier alter_clauses_ss 
  ;

alter_clauses_ss
  : alter_clause_ss 
	| alter_clauses_ss COMMA alter_clause_ss 
  ;

alter_clause_ss
  : alter_add_clause_ss 
	| alter_drop_clause 
	| alter_modify_clause 
	| alter_add_constraint_clause 
	| alter_drop_contraint_clause 
	| alter_modify_next 
	| alter_lock_mode 
  ;

alter_add_clause_ss
  : ADD add_column_clause_ss  
	| ADD OPEN_BRACKET add_column_clauses_ss CLOSE_BRACKET 
  ;

add_column_clause_ss
  : table_element_ss 
	| table_element_ss BEFORE identifier 
  ;

add_column_clauses_ss
  : add_column_clause_ss 
	| add_column_clauses_ss COMMA add_column_clause_ss 
  ;

alter_drop_clause
  : DROP drop_column 
	| DROP OPEN_BRACKET drop_column_list CLOSE_BRACKET 
  ;

drop_column_list
  : drop_column 
	| drop_column_list COMMA drop_column 
  ;

drop_column 
  : identifier
  ;

alter_modify_clause 
  : MODIFY modify_column_clause_ss 
	| MODIFY OPEN_BRACKET modify_column_clauses_ss CLOSE_BRACKET 
  ;

modify_column_clauses_ss 
  : modify_column_clause_ss 
	| modify_column_clauses_ss COMMA modify_column_clause_ss 
  ;

modify_column_clause_ss 
  : table_element_ss 
  ;

alter_lock_mode 
  : LOCK_MODE_PAGE 
	| LOCK_MODE_ROW 
  ;

alter_modify_next 
  : MODIFY_NEXT_SIZE INT_VALUE 
  ;

alter_add_constraint_clause
  : ADD_CONSTRAINT column_constraint_ss 
	| ADD_CONSTRAINT OPEN_BRACKET column_constraints_ss CLOSE_BRACKET 
  ;

alter_drop_contraint_clause
  : DROP_CONSTRAINT constraint_name
	| DROP_CONSTRAINT OPEN_BRACKET column_constraints_ss CLOSE_BRACKET 
  ;

column_constraints_ss
  : column_constraint_ss 
	| column_constraints_ss COMMA column_constraint_ss 
  ;

constraint_name
  : identifier
  ;

/* <SET_STATEMENT> */

set_cmd 
  : SQLSEON
  | SQLSEOFF
  | SQLSLMW op_fgl_expr 
  | SQLSLMNW 
  | SQLSIDR
  | SQLSIRR
  | SQLSICS
  | SQLSICR
  | SET_SESSION_TO conn_id 
  | SET_SESSION op_conn_id OPTION char_or_var TO char_or_var 
  | SET_CURSOR cursor_name OPTION char_or_var TO char_or_var 
  ;

op_conn_id 
  : 
	| conn_id;

op_fgl_expr 
  :
  | fgl_expr
	;

/* </SET_STATEMENT> */


/* <SLEEP_STATEMENT> */

sleep_cmd 
  : SLEEP fgl_expr 
  ;

/* </SLEEP_STATEMENT> */


/* <SQL1_RULE> */

rollback_statement
  : ROLLBACK_W 
	;

insert_statement_ss
  : INSERT_INTO table_name op_insert_column_list ins_2_ss 
  ;

ins_2_ss 
  : VALUES OPEN_BRACKET insert_value_list_ss CLOSE_BRACKET 
	| query_specification_ss
	;

op_insert_column_list
  : 
	| OPEN_BRACKET insert_column_list CLOSE_BRACKET
	;

insert_column_list
  : column_name
	| insert_column_list COMMA column_name
  ;

insert_value_list_ss
  : insert_value_ss 
	| insert_value_list_ss COMMA insert_value_ss 
  ;

insert_value_ss
  : value_expression_ss 
	| KW_NULL 
	;

fetch_statement
  : FETCH fetch_part opt_into_fetch_part
  ;

declare_cursor_name  
  : ident_or_var 
  ;

fetch_part
  : fetch_place fetch_cursor_name
  | fetch_cursor_name
  ;

opt_into_fetch_part
  :
  | INTO obind_var_list 
  ;

opt_foreach_into_fetch_part
  :
  | INTO obind_var_list 
  ;

fetch_place 
  : FIRST 
	| LAST
	| NEXT
	| PREVIOUS
	| PRIOR
	| CURRENT
	| RELATIVE fgl_expr
	| ABSOLUTE fgl_expr
  ;

delete_statement_position
  : DELETE_FROM table_name WHERE_CURRENT_OF fetch_cursor_name
	;

delete_statement_search_ss
  : DELETE_FROM table_name op_where_clause_ss
	;

order_by_clause
  : ORDER BY sort_specification_list
	;

sort_specification_list
  : sort_specification
	| sort_specification_list COMMA sort_specification
	;
sort_specification
  : sort_spec op_asc_desc 
  ;

sort_spec
  : INT_VALUE 
	| column_name 
	;

op_asc_desc
  : 
	| ASC 
	| DESC
	;

begin_statement
  : BEGIN_WORK 
  ;

commit_statement
  : COMMIT_W 
	;

op_exclusive 
  :
	|	EXCLUSIVE 
  ;

set_database_cmd 
  : DATABASE var_ident_qchar op_exclusive
  ;


var_ident_qchar
  : var_ident 
	| CHAR_VALUE 
  ;

sql_cmd 
  : opt_use sql_commands 
  ;

sql_commands 
  :  schema_ss 
	| schema_element_ss 
	| commit_statement 
	| misc_sql 
	| begin_statement 
	| delete_statement_position 
	| delete_statement_search_ss 
	| fetch_statement 
	| insert_statement_ss 
	| rollback_statement 
	| select_statement_full_ss 
	| update_statement_ss 
	;

privilege_definition
  : GRANT privileges ON table_name TO grantee_list op_with_grant_option
	;

op_with_grant_option
  : 
	| WITH_GRANT_OPTION
	;

privileges
  : ALL_PRIVILEGES
	| action_list
	;

action_list
  : action
	| action_list COMMA action
	;

action
  : SELECT
	| INSERT
	| DELETE
	| UPDATE op_grant_column_list
	;

op_grant_column_list
  : 
	| OPEN_BRACKET grant_column_list CLOSE_BRACKET
	;

grant_column_list
  : column_name
	| grant_column_list COMMA column_name
	;

grantee_list
  : grantee
	| grantee_list COMMA grantee
	;

grantee
  : PUBLIC
	| authorization_identifier
	;

view_definition_ss
  : CREATE_VIEW table_name op_view_column_list AS query_specification_ss 
	  op_with_check_option 
  ;

op_view_column_list
  : 
	| OPEN_BRACKET view_column_list CLOSE_BRACKET
	;

view_column_list
  : column_name
	| view_column_list COMMA column_name
	;

op_with_check_option
  : 
	| WITH_CHECK_OPTION
	;

check_constraint_definition_ss
  : CHECK OPEN_BRACKET search_condition_ss CLOSE_BRACKET 
	;

referential_constraint_definition
  : FOREIGN_KEY OPEN_BRACKET references_columns CLOSE_BRACKET 
	  references_specification
	;

references_specification
  : REFERENCES referenced_table_and_columns
	;

references_columns
  : references_column_list
	;

referenced_table_and_columns
  : table_name
	| table_name OPEN_BRACKET references_column_list CLOSE_BRACKET
	;

references_column_list
  : column_name
	| references_column_list COMMA column_name
	;

unique_constraint_definition
  : UNIQUE OPEN_BRACKET unique_column_list CLOSE_BRACKET
	| PRIMARY_KEY OPEN_BRACKET unique_column_list CLOSE_BRACKET
	;

unique_column_list
  : column_name
	| unique_column_list COMMA column_name
	;
	
table_constraint_definition_ss
  : unique_constraint_definition 
	| referential_constraint_definition 
	| check_constraint_definition_ss  
	;

default_clause
  : DEFAULT literal
	| DEFAULT_NULL
	;

/*
column_definiton_ss:
	column_name data_type op_default_clause op_column_constraint_list_ss {
		$<sql_string>$=make_sql_string($<str>1," ",$<str>2," ",$<str>3," ",$<sql_string>4,0);
	}
	;
*/

ct_column_definiton_ss
  : identifier data_type op_default_clause op_column_constraint_list_ss 
  ;

op_default_clause
  : 
	| default_clause
  ;

op_column_constraint_list_ss
  : 
  | column_constraint_list_ss 
  ;

column_constraint_list_ss 
  : column_constraint_ss 
	| column_constraint_list_ss column_constraint_ss 
  ;

column_constraint_ss
  : NOT_NULL 
	| NOT_NULL_UNIQUE 
	| UNIQUE 
	| references_specification 
	| CHECK OPEN_BRACKET search_condition_ss CLOSE_BRACKET 
	;

schema_ss
  : CREATE_SCHEMA schema_authorization_clause schema_element_list_ss
	;

schema_authorization_clause
  : schema_authorization_identifier
	;

schema_authorization_identifier
  : authorization_identifier
	;

schema_element_list_ss
  : schema_element_ss
	| schema_element_list_ss schema_element_ss 
	;

schema_element_ss
  : view_definition_ss 
	| privilege_definition 
	;

having_clause_ss
  : HAVING search_condition_ss 
  ;

group_by_clause_ss
  : GROUP_BY column_specification_list_ss 
  ;

column_specification_list_ss
  : column_specification_ss 
	| column_specification_list_ss COMMA column_specification_ss 
  ;

where_clause_ss
  : WHERE search_condition_ss 
  ;

from_clause
  : FROM table_reference_list 
  ;

table_reference_list
  : table_reference
	| table_reference_list COMMA table_reference 
	;

table_reference
  : tname 
	| OUTER tname 
	| OUTER OPEN_BRACKET tname_list  CLOSE_BRACKET 
	;

tname
  : table_name
	| table_name correlation_name 
  ;

/* Was tname instead of table_reference */
tname_list 
  : table_reference 
	| tname_list COMMA table_reference 
  ;

table_expression_ss
  : from_clause  op_where_clause_ss op_group_by_clause_ss op_having_clause_ss 
	;

op_where_clause_ss
  : /* empty */ 
	| where_clause_ss 
	;

op_group_by_clause_ss
  : /*empty */ 
	| group_by_clause_ss 
	;

op_having_clause_ss
  : 
	| having_clause_ss 
	;

search_condition_ss
  : boolean_term_ss 
	| search_condition_ss KW_OR boolean_term_ss 
	;

boolean_term_ss
  : boolean_factor_ss 
	| boolean_term_ss KW_AND boolean_factor_ss 
	;

boolean_factor_ss
  : boolean_primary_ss 
	| NOT boolean_primary_ss 
  ;

boolean_primary_ss
  : predicate_ss 
	| OPEN_BRACKET search_condition_ss CLOSE_BRACKET 
  ;

exists_predicate_ss
  : EXISTS subquery_ss 		
	| NOT_EXISTS subquery_ss 	
	;

op_escape
  :
	| ESCAPE escape_character
	;

pattern_ss
  : value_expression_initial_ss 
/*
	  value_specification {$<sql_string>$=make_sql_string($<str>1);}
	| var_ident_ibind_ss {$<sql_string>$=$<sql_string>1;}
*/
	;

escape_character
  : value_specification
	;

in_predicate_ss
  : value_expression_ss IN OPEN_BRACKET in_value_list CLOSE_BRACKET 
	| value_expression_ss IN subquery_ss 
	| value_expression_ss NOT_IN OPEN_BRACKET in_value_list CLOSE_BRACKET 
	| value_expression_ss NOT_IN subquery_ss 
  ;

in_value_list
  : in_value_specification
	| in_value_list COMMA in_value_specification
	;

in_value_specification 
  : var_ident_ibind_ss 
	| literal
  ;

op_not
  : 
	| NOT
	;

comparison_predicate_ss
  : value_expression_ss op_not IS_NULL 
	| value_expression_ss op_not IS_NOT_NULL 
	| value_expression_ss comp_op value_expression_ss 
	| value_expression_ss op_not BETWEEN value_expression_ss KW_AND 
	  value_expression_ss 
	| value_expression_ss LIKE pattern_ss op_escape 
	| value_expression_ss NOT_LIKE pattern_ss op_escape 
	| value_expression_ss ILIKE pattern_ss op_escape 
	| value_expression_ss NOT_ILIKE pattern_ss op_escape 
	| value_expression_ss op_not MATCHES pattern_ss op_escape 
	;

comp_op
  : EQUAL
	| NOT_EQUAL 
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


predicate_ss
  : comparison_predicate_ss 
	| in_predicate_ss 
	//| quantified_predicate_ss 
	| exists_predicate_ss 
	;


op_all
  : 
	| ALL 
	| DISTINCT 
	| UNIQUE 
	;

data_type
  : char_string_type
	| exact_numeric_type
	| approx_numeric_type
	;

char_string_type
  : CHAR
	| CHAR OPEN_BRACKET length CLOSE_BRACKET
	;

exact_numeric_type
  : NUMERIC OPEN_BRACKET precision op_scale CLOSE_BRACKET
	| SERIAL  
	| DECIMAL OPEN_BRACKET precision op_scale CLOSE_BRACKET
	| MONEY OPEN_BRACKET precision op_scale CLOSE_BRACKET
  | DATE
	| INTEGER
	| SMALLINT
	| DATETIME s_curr TO e_curr
	| DATETIME 
	| INTERVAL s_curr TO e_curr
	| INTERVAL
	| INTERVAL s_curr OPEN_BRACKET INT_VALUE CLOSE_BRACKET TO e_curr
	| TEXT
	| BYTE
	| VARCHAR
	| VARCHAR OPEN_BRACKET INT_VALUE CLOSE_BRACKET
	| VARCHAR OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET
	;

op_scale
  : 
	| COMMA scale 
	;

approx_numeric_type
  : FLOAT OPEN_BRACKET precision CLOSE_BRACKET
	| REAL
	| SMALLFLOAT
	| FLOAT
	| DOUBLE_PRECISION
	;

length
  : INT_VALUE
	;

precision
  : INT_VALUE
	;

scale
  : INT_VALUE
	;

table_name
  : CHAR_VALUE DOT identifier 
	| CHAR_VALUE 
	| identifier 
	| identifier COLON identifier 
	;

authorization_identifier
  : identifier
	;

col_arr 
  : 
	| OPEN_SQUARE INT_VALUE CLOSE_SQUARE 
	| OPEN_SQUARE INT_VALUE COMMA INT_VALUE CLOSE_SQUARE 
  ;

column_name 
  : column_name_specific 
	| ATSIGN column_name_specific 
  ;

column_name_specific
  : identifier col_arr
	| table_name DOT identifier col_arr
	| table_name  DOT MULTIPLY
	;

correlation_name
  : identifier
	;


literal
  : CHAR_VALUE 
	| NUMERIC
	| real_number
	| INT_VALUE
	//| PLUS real_number {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	//| PLUS INT_VALUE {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	//| MINUS real_number {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	//| MINUS INT_VALUE {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
  | curr_clause
	;

curr_v_clause 
  : CURRENT  cur_v_part 
  ;

curr_clause 
  : CURRENT  cur_part 
  ;

cur_part
  : 
  | s_curr TO e_curr
  ;

cur_v_part
  : 
  | s_curr_v TO s_curr_v
  ;

s_curr_v
  : YEAR
	| MONTH
	| DAY
	| HOUR
	| MINUTE
	| SECOND
	| FRACTION
  | FRACTION OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
  ;

e_curr_v
  : YEAR 
	| MONTH
	| DAY
	| HOUR
	| MINUTE 
	| SECOND
  | FRACTION
  | FRACTION OPEN_BRACKET INT_VALUE CLOSE_BRACKET 
  ;


s_curr
  : YEAR 
	| MONTH 
	| DAY 
	| HOUR 
	| MINUTE 
	| SECOND 
	| FRACTION
	;

e_curr
  : YEAR 
	| MONTH 
	| DAY 
	| HOUR 
	| MINUTE 
	| SECOND 
	| FRACTION
	;

dbase_name	
  :	identifier 
  |	CHAR_VALUE 
	;

flush_cmd 
  : opt_use FLUSH fetch_cursor_name  
  ;

declare_cmd 
  : opt_use DECLARE declare_cursor_name CURSOR FOR cursor_specification_all_ss 
	| opt_use DECLARE declare_cursor_name CURSOR WITH_HOLD FOR 
	  cursor_specification_sel_ss 
  | opt_use DECLARE declare_cursor_name SCROLL_CURSOR_FOR 
	  cursor_specification_sel_ss 
  | opt_use DECLARE declare_cursor_name SCROLL_CURSOR WITH_HOLD FOR 
	  cursor_specification_sel_ss 
  ;
 
curs_forupdate 
  : 
	| FOR_UPDATE 
	| FOR_UPDATE_OF cur_update_list 
	;

cur_update_list 
  : colident 
	| cur_update_list COMMA colident 
  ;

colident
  : identifier
	| identifier DOT identifier 
	| CHAR_VALUE DOT identifier DOT identifier 
  ;
	
cursor_specification_all_ss
  : cursor_specification_sel_ss 
	| insert_statement_ss 
  ;

cursor_specification_sel_ss
  : stmt_id 
	| select_statement_ss  
  ;

select_statement_full_ss 
  : select_statement_ss 
  ;

select_statement_ss
  : SELECT op_ad select_list_ss opt_into_sel_ss table_expression_ss
    sel_p2_ss curs_forupdate 
  ;


in_select_statement_ss
  : SELECT op_ad select_list_ss table_expression_ss sel_p2_ss 
  ;

select_statement2_ss
  : select_statement21_ss 
	| char_or_var 
	;

select_statement21_ss
  : SELECT  op_ad select_list_ss opt_into_sel_ss table_expression_ss sel_p2_ss 
  ;

sel_p2_ss 
  : 
  | UNION op_all select_statement2_ss 
  | order_by_clause  
  | INTO_TEMP tmp_tabname op_no_log 
  | order_by_clause INTO_TEMP tmp_tabname op_no_log 
  ;

tmp_tabname
  : identifier
	;

opt_into_sel_ss 
  :  
	| INTO  obind_var_list 
  ;

query_specification_ss
  : SELECT op_ad select_list_ss table_expression_ss 
  ;

subquery_ss
  : OPEN_BRACKET SELECT op_ad select_list_ss table_expression_ss CLOSE_BRACKET 
  ;

op_ad 
  : 
	| ALL 
	| DISTINCT 
	| UNIQUE 
	;

select_list_ss
  : value_expression_pls_ss  
	| select_list_ss COMMA value_expression_pls_ss 
  ;

value_expression_pls_ss 
  : value_expression_ss 
	| value_expression_ss  identifier 
  ;

column_specification_ss 
  : value_expression_ss 
  ;

value_expression_ss
  : value_expression_initial_ss 
	| MINUS value_expression_initial_ss 
	| PLUS value_expression_initial_ss 
  ;

value_expression_initial_ss 
  : value_expression_complex_ss 
	| var_ident_ibind_ss 	
	| subquery_ss 
	| ATSIGN identifier 
	| ATSIGN identifier DOT identifier 
  ;

value_expression_complex_ss 
  : value_expression_initial_ss DIVIDE value_expression_ss
	| value_expression_initial_ss units_qual
	| value_expression_initial_ss MULTIPLY value_expression_ss
	| value_expression_initial_ss PLUS value_expression_ss
	| value_expression_initial_ss MINUS value_expression_ss
	| literal 
	| KW_TRUE 
	| KW_FALSE 
	| USER 
	| MULTIPLY 
	| COUNT_MULTIPLY 
 	| AVG OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
	| XMAX OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
	| XMIN OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
	| SUM OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
	| COUNT OPEN_BRACKET op_all value_expression_ss CLOSE_BRACKET
	| identifier OPEN_BRACKET value_expr_list_ss CLOSE_BRACKET
	| DATE OPEN_BRACKET value_expr_list_ss CLOSE_BRACKET
	| OPEN_BRACKET value_expression_ss CLOSE_BRACKET 
	| EXTEND OPEN_BRACKET extend_qual_ss CLOSE_BRACKET
  ;

value_expr_list_ss 
  : value_expression_ss 
	| value_expr_list_ss COMMA value_expression_ss 
  ;

value_specification
  : literal
	;

unload_cmd 
  : opt_use UNLOAD_TO ufile opt_delim select_statement2_ss 
  ;

load_cmd 
  :  opt_use LOAD_FROM ufile opt_delim INSERT_INTO table_name opt_col_list 
  | opt_use LOAD_FROM ufile opt_delim variable 
  ;

opt_delim 
  : 
	| DELIMITER char_or_var 
  ;

char_or_var 
  : CHAR_VALUE 
	| variable 
  ;

opt_col_list
  : 
	| OPEN_BRACKET col_list CLOSE_BRACKET 

col_list 
  : simple_column_name 
	| col_list COMMA simple_column_name 
  ;

simple_column_name 
  : identifier 
  ;

ufile 
  : CHAR_VALUE 
	| variable
	;

opt_use 
  : 
	| USE_SESSION conn_id FOR 
  ;

conn_id 
  : ident_or_var
	;

misc_sql 
  : lock_stmt
	| unlock_stmt
	| rename_stmt
  ;

rename_stmt 
  : RENTAB rentabname TO rentabname 
	| RENCOL rentabname DOT rencolname TO rencolname 
  ;

rentabname 
  : identifier
	;

rencolname 
  : identifier
	;

unlock_stmt
  : UNLOCK_TABLE tab_name 
  ;

lock_stmt 
  : LOCK_TABLE tab_name share_or_exclusive  
  ;

share_or_exclusive 
  : INSHARE
	| INEXCLUSIVE
  ;

units_qual
  : UNITS_YEAR 
	| UNITS_MONTH
	| UNITS_DAY
	| UNITS_HOUR
	| UNITS_MINUTE
	| UNITS_SECOND
  ;

extend_qual_ss
  : CURRENT COMMA s_curr TO e_curr 
  | var_ident_ibind_ss COMMA s_curr TO e_curr 
  | CURRENT s_curr TO e_curr 
  ;

/* </SQL1_RULE> */

sql_block_cmd 
  : SQL sql_block END_SQL 
  ;


sql_block 
  : sql_block_entry 
	| sql_block sql_block_entry  
  ;

sql_block_entry
  : SQL_TEXT 
	| in_var 
	| sql_block_into 
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

in_var 
  : DOLLAR var_ident_ibind_ss 
  ;

sql_block_into
  : INTO obind_var_list 
  ;




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


/* <UPDATE_RULE> */

update_statement_ss
  : UPDATE table_name set_clause_list_ss  where_upd_ss 
  ;

where_upd_ss 
  : 
	| WHERE_CURRENT_OF fetch_cursor_name 
	| WHERE search_condition_ss 
	;

set_clause_list_ss
  : XSET_OPEN_BRACKET upd_col_list CLOSE_BRACKET EQUAL 
	  OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET 
  | XSET_MULTIPLY_EQUAL_OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET 
  | XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET 
  | XSET upd_columns_ss  
  | XSET_MULTIPLY_EQUAL upd_val_list_ss  
  | XSET_ident_DOT_MULTIPLY_EQUAL upd_val_list_ss  
  ;

upd_columns_ss 
  : col_1_ss  
	| upd_columns_ss COMMA col_1_ss 
  ;


upd_column_name 
  : column_name  
	;

col_1_ss 
  : upd_column_name EQUAL upd_val_ss 
  ;

upd_col_list  
  : upd_column_name	
	| upd_col_list COMMA upd_column_name 
  ;

upd_val_list_ss  
  : upd_val_ss 
	| upd_val_list_ss COMMA upd_val_ss 
  ;

upd_val_ss 
  : KW_NULL 
	| upd_value_expression_ss  
  ;

upd_value_expression_ss
  : upd_value_expression_initial_ss 
  | MINUS upd_value_expression_initial_ss 
  | PLUS upd_value_expression_initial_ss 
  ;

upd_value_expression_initial_ss 
  : upd_var_ident_ibind_ss    
  | subquery_ss 
  | ATSIGN identifier 
  | ATSIGN identifier DOT identifier 
  | upd_value_expression_complex_ss 
  | literal
  | KW_TRUE
  | KW_FALSE
  | USER
  | COUNT_MULTIPLY
  //| MULTIPLY {$<sql_string>$=make_sql_string("*",0);}
  ;

upd_value_expression_complex_ss 
  : upd_value_expression_initial_ss DIVIDE upd_value_expression_ss 
  | upd_value_expression_initial_ss units_qual 
  | upd_value_expression_initial_ss MULTIPLY upd_value_expression_ss 
  | upd_value_expression_initial_ss PLUS upd_value_expression_ss 
  | upd_value_expression_initial_ss MINUS upd_value_expression_ss 
  | AVG OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | XMAX OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | XMIN OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | SUM OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | COUNT OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | identifier OPEN_BRACKET upd_value_expr_list_ss CLOSE_BRACKET 
  | DATE OPEN_BRACKET upd_value_expr_list_ss CLOSE_BRACKET 
  | OPEN_BRACKET upd_value_expression_ss CLOSE_BRACKET 
  | EXTEND OPEN_BRACKET extend_qual_ss CLOSE_BRACKET 
  ;


upd_var_ident_ibind_ss
  : var_ident_ibind_ss 
  ;

upd_value_expr_list_ss 
  : upd_value_expression_ss 
  | upd_value_expr_list_ss COMMA upd_value_expression_ss 
  ;

/* </UPDATE_RULE> */


/* <VAR_RULE> */

var_ident 
  :  var2  
  ;


var2 
  : DOLLAR var3 
	| var3
  ;

var3
  : array_r_variable_or_ident 
	| identifier
	| var3  DOT aft_dot 
	| CHAR_VALUE DOT var3 DOT aft_dot 
  ;

aft_dot 
  : MULTIPLY
	| array_r_varid
	| identifier
  ;

var_ident_ibind_ss 
  : var2  
  | var2 THRU var2 
  ;

/* </VAR_RULE> */


/* <WHENEVER_STATEMENTS> */

whenever_cmd 	
  :  WHENEVER_NOT_FOUND when_do
	|  WHENEVER_SQLERROR when_do
	|  WHENEVER_ANY_ERROR when_do
	|  WHENEVER_ERROR_CONTINUE 
	|  WHENEVER_ERROR when_do
	|  WHENEVER_SQLWARNING when_do
	|  WHENEVER_WARNING_CONTINUE 
	|  WHENEVER_WARNING when_do
	|  WHENEVER_SUCCESS when_do
	|  WHENEVER_SQLSUCCESS when_do
	;

when_do		
  :	CONTINUE 
	|	GO TO label_goto
	|	GOTO label_goto
	|	STOP
	|	FCALL function_name_when
	;

label_goto	
  :	identifier
  |	COLON identifier
	;

function_name_when
  :	identifier
	;

/* </WHENEVER_STATEMENTS> */


/* <WHILE_STATEMENT> */

while_cmd 
  : WHILE fgl_expr commands END_WHILE 
  ;

/* </WHILE_STATEMENT> */


/* <WINDOW_STATEMENTS> */

op_clr_fields 
  : 
	| KWFIELD fld_list
  ;

op_to_defs 
  : 
  | TO_DEFAULTS 
  ;

clear_cmd	
  :	CLEARSCR 
	|	CLEARWIN win_name 
	|	CLEARSTAT win_name 
	|	CLEARFORM 
	|	CLEARFORMTODEFAULTS 
	|	CLEAR_X_FORM form_name op_clr_fields  op_to_defs 
	|	CLEAR fld_list op_to_defs 
  ;

fld_list	
  :	field_name  
	|	fld_list COMMA field_name 
  ;

current_win_cmd	
  :	CWIS 
	|	CURRENT_WINDOW_IS win_name 
  ;

window_type	
  :	fgl_expr ROWS COMMA fgl_expr COLUMNS 
	|	KWFORM fgl_expr 
  ;

show_cmd 
  : SHOW_WINDOW win_name 
  | SHOW_MENU menu_name KW_USING menu_handler op_mnfile 
  ;

op_mnfile 
  : 
  | FROM fgl_expr
  ;

menu_name
  : identifier
  ;

menu_handler
  : identifier
	;

hide_cmd 
  : HIDE_WINDOW win_name 
  ;

move_cmd 
  : MOVE_WINDOW win_name TO fgl_expr COMMA fgl_expr 
  |  MOVE_WINDOW win_name BY fgl_expr COMMA fgl_expr
  ;

/* </WINDOW_STATEMENTS> */


 /* ================ from make_enable ================= */

NAMED : NAMED_GEN
;

 /* ================ end make_enable ================= */

/* ========================== from mkyacc =========================== */

commands 
  : 
  | command1 
	;

all_commands 
  : commands_all opt_semi 
	;

command1	
  : all_commands  
  | command1  all_commands 
  ;

commands_all 
  :  {print_cmd_start();} commands_all1 {print_cmd_end();};

commands_all1 	
  : pause_screen_on_cmd
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
	|	exit_cmd
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

;
%%


/* ===================== EOF (fgl.yacc) =========================== */


