struct s_kw {
    int id;
	   int mode;
    char *vals[20];
    char *name;
};
#define MEMBER_FUNCTION 1000
#define DATETIME_VALUE 1001
#define INTERVAL_VALUE 1002
#define IN_LINE_MODE 1003
#define IN_FORM_MODE 1004
#define FGL_SIZEOF 1005
#define IMPORT_PACKAGE 1006
#define DYNAMIC_ARRAY 1007
#define RESIZE_ARRAY 1008
#define ALLOCATE_ARRAY 1009
#define DEALLOCATE_ARRAY 1010
#define AFTER_INSERT_DELETE 1011
#define BEFORE_INSERT_DELETE 1012
#define BEFORE_INSERT 1013
#define AS_CONVERTABLE 1014
#define CONCAT_PIPES 1015
#define BEFORE_DELETE 1016
#define DROP_TRIGGER 1017
#define AFTER_INSERT 1018
#define AFTER_DELETE 1019
#define EXECUTE_IMMEDIATE 1020
#define DELETE_ROW_EQUAL_TRUE 1021
#define INSERT_ROW_EQUAL_TRUE 1022
#define DELETE_ROW_EQUAL_FALSE 1023
#define INSERT_ROW_EQUAL_FALSE 1024
#define CURRENT_ROW_DISPLAY_EQUAL 1025
#define MAXCOUNT 1026
#define ALTER_TABLE 1027
#define ALTER_INDEX 1028
#define NEXT_SIZE 1029
#define DISPLAY_ATTR_FORM 1030
#define DISPLAY_ATTR_WINDOW 1031
#define INPUT_ATTR_FORM 1032
#define INPUT_ATTR_WINDOW 1033
#define WHENEVER_ERROR_CONTINUE 1034
#define WHENEVER_ANY_ERROR_CONTINUE 1035
#define WHENEVER_WARNING_CONTINUE 1036
#define WHENEVER_SQLSUCCESS_CONTINUE 1037
#define WHENEVER_SQLWARNING_CONTINUE 1038
#define WHENEVER_NOT_FOUND_CONTINUE 1039
#define WHENEVER_SQLERROR_CONTINUE 1040
#define WHENEVER_SUCCESS_CONTINUE 1041
#define WHENEVER_ERROR_GOTO 1042
#define WHENEVER_ANY_ERROR_GOTO 1043
#define WHENEVER_WARNING_GOTO 1044
#define WHENEVER_SQLSUCCESS_GOTO 1045
#define WHENEVER_SQLWARNING_GOTO 1046
#define WHENEVER_NOT_FOUND_GOTO 1047
#define WHENEVER_SQLERROR_GOTO 1048
#define WHENEVER_SUCCESS_GOTO 1049
#define WHENEVER_ERROR_CALL 1050
#define WHENEVER_ANY_ERROR_CALL 1051
#define WHENEVER_WARNING_CALL 1052
#define WHENEVER_SQLSUCCESS_CALL 1053
#define WHENEVER_SQLWARNING_CALL 1054
#define WHENEVER_NOT_FOUND_CALL 1055
#define WHENEVER_SQLERROR_CALL 1056
#define WHENEVER_SUCCESS_CALL 1057
#define WHENEVER_ERROR_STOP 1058
#define WHENEVER_ANY_ERROR_STOP 1059
#define WHENEVER_WARNING_STOP 1060
#define WHENEVER_SQLSUCCESS_STOP 1061
#define WHENEVER_SQLWARNING_STOP 1062
#define WHENEVER_NOT_FOUND_STOP 1063
#define WHENEVER_SQLERROR_STOP 1064
#define WHENEVER_SUCCESS_STOP 1065
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1066
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1067
#define XSET_ident_DOT_MULTIPLY_EQUAL 1068
#define XSET_MULTIPLY_EQUAL 1069
#define XSET_OPEN_BRACKET 1070
#define NEWFORMATSHARED 1071
#define CREATE_DATABASE 1072
#define DROP_DATABASE 1073
#define IMPORT_LEGACY_FUNCTION 1074
#define ADD_CONSTRAINT 1075
#define DROP_CONSTRAINT 1076
#define DROP_SYNONYM 1077
#define CONSTRAINT 1078
#define AS_STATIC 1079
#define NOT_FIELD_TOUCHED 1080
#define LOCAL_FUNCTION 1081
#define EVERY_ROW 1082
#define ELIF 1083
#define DOUBLE_PRECISION 1084
#define COUNT_MULTIPLY 1085
#define WAIT_FOR_KEY 1086
#define AT_TERMINATION_CALL 1087
#define TERMINATE_REPORT 1088
#define TO_MAIN_CAPTION 1089
#define CLEARSTAT 1090
#define TO_MENUITEM 1091
#define ID_TO_INT 1092
#define TO_STATUSBOX 1093
#define ASCII_HEIGHT_ALL 1094
#define ASCII_WIDTH_ALL 1095
#define IMPORT_DATATYPE 1096
#define PAGE_TRAILER_SIZE 1097
#define PAGE_HEADER_SIZE 1098
#define FIRST_PAGE_HEADER_SIZE 1099
#define BYTES_USE_AS_IMAGE 1100
#define BYTES_USE_AS_ASCII 1101
#define KWUP_BY 1102
#define KWDOWN_BY 1103
#define CLOSE_STATUSBOX 1104
#define MODIFY_NEXT_SIZE 1105
#define LOCK_MODE_PAGE 1106
#define LOCK_MODE_ROW 1107
#define TO_PIPE 1108
#define TO_PRINTER 1109
#define STATUSBOX 1110
#define FORMHANDLER_INPUT 1111
#define UNITS_YEAR 1112
#define UNITS_MONTH 1113
#define UNITS_DAY 1114
#define UNITS_HOUR 1115
#define UNITS_MINUTE 1116
#define UNITS_SECOND 1117
#define NO_NEW_LINES 1118
#define FIELDTOWIDGET 1119
#define WITH_HOLD 1120
#define SHOW_MENU 1121
#define TO_CLUSTER 1122
#define TO_NOT_CLUSTER 1123
#define CWIS 1124
#define CREATE_IDX 1125
#define FORM_IS_COMPILED 1126
#define PDF_REPORT 1127
#define IMPORT_FUNCTION 1128
#define PROMPT_MANY 1129
#define POINTS 1130
#define MM 1131
#define INCHES 1132
#define PREPEND 1133
#define MEMBER_OF 1134
#define APPEND 1135
#define TEMPLATE 1136
#define END_TEMPLATE 1137
#define SQLSICS 1138
#define CREATE_SCHEMA 1139
#define SQLSIRR 1140
#define UPDATESTATS_T 1141
#define SQLSICR 1142
#define WHENEVER_SQLSUCCESS 1143
#define WHENEVER_SQLWARNING 1144
#define WHENEVER_ANY_ERROR 1145
#define WHENEVER_NOT_FOUND 1146
#define WHENEVER_SQLERROR 1147
#define WHENEVER_SUCCESS 1148
#define WHENEVER_ERROR 1149
#define START_EXTERN 1150
#define CONTINUE_CONSTRUCT 1151
#define FOUNCONSTR 1152
#define SQLSIDR 1153
#define CREATE_TEMP_TABLE 1154
#define CURRENT_WINDOW_IS 1155
#define FIRST_PAGE_HEADER 1156
#define ORDER_EXTERNAL_BY 1157
#define SCROLL_CURSOR_FOR 1158
#define SCROLL_CURSOR 1159
#define SQL_INTERRUPT_OFF 1160
#define STOP_ALL_EXTERNAL 1161
#define WITH_CHECK_OPTION 1162
#define WITH_GRANT_OPTION 1163
#define SQLSLMNW 1164
#define ADDCONSTUNIQ 1165
#define CONTINUE_DISPLAY 1166
#define CONTINUE_FOREACH 1167
#define OUTPUT_TO_REPORT 1168
#define SQL_INTERRUPT_ON 1169
#define WHERE_CURRENT_OF 1170
#define WITHOUT_DEFAULTS 1171
#define FOCONSTR 1172
#define SCALED_BY 1173
#define CONTINUE_PROMPT 1174
#define PDF_FUNCTION 1175
#define DEFER_INTERRUPT 1176
#define DISPLAY_BY_NAME 1177
#define NOT_NULL_UNIQUE 1178
#define SKIP_TO_TOP 1179
#define TOP_OF_PAGE 1180
#define SKIP_TO 1181
#define SKIP_BY 1182
#define WITHOUT_WAITING 1183
#define BEFCONSTRUCT 1184
#define SQLSLMW 1185
#define AFTCONSTRUCT 1186
#define ALL_PRIVILEGES 1187
#define CLOSE_DATABASE 1188
#define CONTINUE_INPUT 1189
#define CONTINUE_WHILE 1190
#define CREATE_SYNONYM 1191
#define DROP_TABLE 1192
#define EXIT_CONSTRUCT 1193
#define INEXCLUSIVE 1194
#define REPORT_TO_PRINTER 1195
#define REPORT_TO_PIPE 1196
#define RETURN 1197
#define SET_SESSION_TO 1198
#define UPDATESTATS 1199
#define WITHOUT_HEAD 1200
#define CLEARSCR 1201
#define WITH_B_LOG 1202
#define AUTHORIZATION 1203
#define BOTTOM_MARGIN 1204
#define CLOSE_SESSION 1205
#define CONTINUE_CASE 1206
#define CONTINUE_MENU 1207
#define DISPLAY_ARRAY 1208
#define END_SQL 1209
#define DOLLAR 1210
#define END_CONSTRUCT 1211
#define FIELD_TOUCHED 1212
#define FINISH_REPORT 1213
#define INFACC 1214
#define INPUT_NO_WRAP 1215
#define SETPMOFF 1216
#define UNCONSTRAINED 1217
#define PAGE_TRAILER 1218
#define SETPMON 1219
#define BEFGROUP 1220
#define CLOSE_WINDOW 1221
#define COMMENT_LINE 1222
#define CONTINUE_FOR 1223
#define CREATE_DB 1224
#define CREATE_TABLE 1225
#define DEFAULT_NULL 1226
#define DEFAULT_TODAY 1227
#define DEFAULT_USER 1228
#define DELETE_USING 1229
#define DISPLAY_FORM 1230
#define END_FUNCTION 1231
#define EXIT_DISPLAY 1232
#define EXIT_FOREACH 1233
#define EXIT_PROGRAM 1234
#define INFCOLS 1235
#define ON_EVERY_ROW 1236
#define OPEN_SESSION 1237
#define RIGHT_MARGIN 1238
#define SELECT_USING 1239
#define START_REPORT 1240
#define UNLOCK_TABLE 1241
#define UPDATE_USING 1242
#define ACL_BUILTIN 1243
#define AFTGROUP 1244
#define INFIDX 1245
#define INFSTAT 1246
#define LEFT_MARGIN 1247
#define PAGE_HEADER 1248
#define ROLLBACK_W 1249
#define SET_SESSION 1250
#define SQLSEOFF 1251
#define WITH_A_LOG 1252
#define BEFDISP 1253
#define BEFORE_MENU 1254
#define CREATE_VIEW 1255
#define DEFINE_TYPE 1256
#define DELETE_FROM 1257
#define END_DISPLAY 1258
#define END_REPORT 1259
#define END_FOREACH 1260
#define END_FOR 1261
#define END_GLOBALS 1262
#define EXIT_PROMPT 1263
#define EXTENT_SIZE 1264
#define FOREIGN_KEY 1265
#define HIDE_OPTION 1266
#define HIDE_WINDOW 1267
#define INSERT_INTO 1268
#define IS_NOT_NULL 1269
#define MOVE_WINDOW 1270
#define NEXT_OPTION 1271
#define NOT_MATCHES 1272
#define ON_LAST_ROW 1273
#define OPEN_WINDOW 1274
#define OPEN_STATUSBOX 1275
#define PAGE_LENGTH 1276
#define PAGE_WIDTH 1277
#define PRIMARY_KEY 1278
#define PROMPT_LINE 1279
#define RECORD_LIKE 1280
#define ROLLFORWARD 1281
#define SETBL 1282
#define SHOW_OPTION 1283
#define SHOW_WINDOW 1284
#define SQLSEON 1285
#define TO_DATABASE 1286
#define USE_SESSION 1287
#define WITH_NO_LOG 1288
#define AFTDISP 1289
#define BEFFIELD 1290
#define INSHARE 1291
#define UNLOCKTAB 1292
#define AFTFIELD 1293
#define ATTRIBUTES 1294
#define BEFINP 1295
#define BEGIN_WORK 1296
#define CLEARWIN 1297
#define CLOSE_FORM 1298
#define DEFER_QUIT 1299
#define DESCENDING 1300
#define DROP_INDEX 1301
#define END_PROMPT 1302
#define END_RECORD 1303
#define ERROR_LINE 1304
#define EXIT_INPUT 1305
#define EXIT_WHILE 1306
#define FOR_UPDATE_OF 1307
#define FOR_UPDATE 1308
#define GET_FLDBUF 1309
#define INITIALIZE 1310
#define INPUT_WRAP 1311
#define LOCK_TABLE 1312
#define MSG_LINE 1313
#define NOT_EXISTS 1314
#define ON_ANY_KEY 1315
#define REFERENCES 1316
#define RENCOL 1317
#define SET_CURSOR 1318
#define SMALLFLOAT 1319
#define SQLSUCCESS 1320
#define TOP_MARGIN 1321
#define WITH_ARRAY 1322
#define ACCEPTKEY 1323
#define ACCEPT 1324
#define AFTINP 1325
#define CLEARFORMTODEFAULTS 1326
#define CLEARFORM 1327
#define CLEAR_X_FORM 1328
#define COMMIT_W 1329
#define NEXTPAGE 1330
#define PREVPAGE 1331
#define CTRL_KEY 1332
#define INFTABS 1333
#define NEXTFIELD 1334
#define NEXTFORM 1335
#define RENTAB 1336
#define ASCENDING 1337
#define ASSOCIATE 1338
#define CHAR 1339
#define NCHAR 1340
#define NVARCHAR 1341
#define CONSTRUCT 1342
#define DELIMITER 1343
#define DOWNSHIFT 1344
#define DROP_VIEW 1345
#define END_INPUT 1346
#define END_WHILE 1347
#define EXCLUSIVE 1348
#define EXIT_CASE 1349
#define EXIT_MENU 1350
#define FORM_LINE 1351
#define GREATER_THAN_EQ 1352
#define INTERRUPT 1353
#define INTO_TEMP 1354
#define INVISIBLE 1355
#define IN_MEMORY 1356
#define LINKED_TO 1357
#define LOAD_FROM 1358
#define LOCKTAB 1359
#define MENU_LINE 1360
#define OPEN_FORM 1361
#define OTHERWISE 1362
#define PRECISION 1363
#define PRIOR 1364
#define PROCEDURE 1365
#define REPORT_TO 1366
#define RETURNING 1367
#define UNDERLINE 1368
#define UNLOAD_TO 1369
#define BEFROW 1370
#define UNLOAD_T 1371
#define VARIABLE 1372
#define ABSOLUTE 1373
#define AFTROW 1374
#define BUFFERED 1375
#define CONSTANT 1376
#define CONST 1377
#define DATABASE 1378
#define DATETIME 1379
#define DEFAULTS 1380
#define DISTINCT 1381
#define END_CASE 1382
#define END_MAIN 1383
#define END_MENU 1384
#define END_TYPE 1385
#define EXIT_FOR 1386
#define EXTERNAL 1387
#define FRACTION 1388
#define FUNCTION 1389
#define GROUP_BY 1390
#define INTERVAL 1391
#define KWMESSAGE 1392
#define NOT_LIKE 1393
#define NOT_ILIKE 1394
#define NOT_NULL 1395
#define PASSWORD 1396
#define PREVIOUS 1397
#define READONLY 1398
#define REGISTER 1399
#define RELATIVE 1400
#define RESOURCE 1401
#define SMALLINT 1402
#define VALIDATE 1403
#define WITH_LOG 1404
#define WORDWRAP 1405
#define BY_NAME 1406
#define IN_FILE 1407
#define IS_NULL 1408
#define LESS_THAN_EQ 1409
#define AVERAGE 1410
#define BETWEEN 1411
#define CAPTION 1412
#define CLIPPED 1413
#define CLOSE_BRACKET 1414
#define COLUMNS 1415
#define COMMAND 1416
#define CONNECT 1417
#define CURRENT 1418
#define DBYNAME 1419
#define DECIMAL 1420
#define DECLARE 1421
#define DEFAULT 1422
#define DISPLAY 1423
#define ENDCODE 1424
#define EXECUTE 1425
#define FOREACH 1426
#define FOREIGN 1427
#define GLOBALS 1428
#define INFIELD 1429
#define INTEGER 1430
#define KWWINDOW 1431
#define MAGENTA 1432
#define MATCHES 1433
#define OPTIONS 1434
#define PERCENT 1435
#define PREPARE 1436
#define PROGRAM 1437
#define RECOVER 1438
#define REVERSE 1439
#define SECTION 1440
#define SESSION 1441
#define SYNONYM 1442
#define THRU 1443
#define TRAILER 1444
#define UPSHIFT 1445
#define VARCHAR 1446
#define WAITING 1447
#define CLOSE_SHEV 1448
#define CLOSE_SQUARE 1449
#define GREATER_THAN 1450
#define KW_FALSE 1451
#define NOT_IN 1452
#define ONKEY 1453
#define OPEN_BRACKET 1454
#define BORDER 1455
#define BOTTOM 1456
#define COLUMN 1457
#define COMMIT 1458
#define CREATE 1459
#define CURSOR 1460
#define DEFINE 1461
#define DELETE 1462
#define DOUBLE 1463
#define END_IF 1464
#define ESCAPE 1465
#define EXISTS 1466
#define EXTEND 1467
#define EXTENT 1468
#define FINISH 1469
#define FORMAT 1470
#define HAVING 1471
#define HEADER 1472
#define INSERT 1473
#define LOCATE 1474
#define MARGIN 1475
#define MEMORY 1476
#define MINUTE 1477
#define MODIFY 1478
#define NORMAL 1479
#define EQUAL_EQUAL 1480
#define NOT_EQUAL 1481
#define OPEN_SHEV 1482
#define OPEN_SQUARE 1483
#define OPTION 1484
#define OUTPUT 1485
#define PROMPT 1486
#define PUBLIC 1487
#define RECORD 1488
#define REPORT 1489
#define REVOKE 1490
#define SCHEMA 1491
#define SCROLL_USING 1492
#define SCROLL 1493
#define SECOND 1494
#define SELECT 1495
#define SERIAL 1496
#define SETL 1497
#define SHARED 1498
#define SPACES 1499
#define UNIQUE 1500
#define UNLOCK 1501
#define UPDATE 1502
#define VALUES 1503
#define YELLOW 1504
#define AFTER 1505
#define KWLINE 1506
#define KW_NULL 1507
#define KW_TRUE 1508
#define SINGLE_KEY 1509
#define ALTER 1510
#define ARRAY 1511
#define ASCII 1512
#define AUDIT 1513
#define BLACK 1514
#define BLINK 1515
#define CHECK 1516
#define CLEAR 1517
#define CLOSE 1518
#define CODE_C 1519
#define COUNT 1520
#define DEFER 1521
#define ERROR 1522
#define EVERY 1523
#define FETCH 1524
#define FIRST 1525
#define FLOAT 1526
#define FLUSH 1527
#define FOUND 1528
#define GRANT 1529
#define GREEN 1530
#define GROUP 1531
#define INDEX 1532
#define KWFORM 1533
#define LABEL 1534
#define LESS_THAN 1535
#define LOCAL 1536
#define MONEY 1537
#define MONTH 1538
#define POWER 1539
#define MULTIPLY 1540
#define ORDER 1541
#define OUTER 1542
#define PAUSE 1543
#define PRINT_IMAGE 1544
#define PRINT_FILE 1545
#define PRINT 1546
#define RIGHT 1547
#define DOUBLE_COLON 1548
#define SEMICOLON 1549
#define SLEEP 1550
#define TUPLE 1551
#define UNION 1552
#define KW_USING 1553
#define WHERE 1554
#define WHILE 1555
#define WHITE 1556
#define CCODE 1557
#define ANSI 1558
#define BLUE 1559
#define BOLD 1560
#define BYTE 1561
#define FCALL 1562
#define CASE 1563
#define CYAN 1564
#define DATE 1565
#define DESC 1566
#define DIVIDE 1567
#define KWDOWN 1568
#define TAB 1569
#define DROP 1570
#define ELSE 1571
#define EXEC 1572
#define EXIT 1573
#define FREE 1574
#define FROM 1575
#define GOTO 1576
#define HELP_FILE 1577
#define LANG_FILE 1578
#define HELP 1579
#define HIDE 1580
#define HOUR 1581
#define INTO 1582
#define LAST 1583
#define LEFT 1584
#define LIKE 1585
#define MAIN 1586
#define MENU 1587
#define MODE 1588
#define NEED 1589
#define NEXT 1590
#define NOCR 1591
#define OPEN 1592
#define QUIT 1593
#define REAL 1594
#define ROWS 1595
#define SHOW 1596
#define SIZE 1597
#define SKIP 1598
#define SOME 1599
#define STEP 1600
#define STOP 1601
#define TEMP 1602
#define TEXT 1603
#define THEN 1604
#define USER 1605
#define WAIT 1606
#define WHEN 1607
#define WITH 1608
#define WORK 1609
#define YEAR 1610
#define EQUAL 1611
#define KW_IS 1612
#define XSET 1613
#define ADD 1614
#define ALL 1615
#define KW_AND 1616
#define ANY 1617
#define ASC 1618
#define AVG 1619
#define COLON 1620
#define COMMA 1621
#define DAY 1622
#define DBA 1623
#define DEC 1624
#define DIM 1625
#define FKEY 1626
#define FOR 1627
#define KEY 1628
#define KWNO 1629
#define LET 1630
#define LOG 1631
#define XMAX 1632
#define XMIN 1633
#define MINUS 1634
#define MOD 1635
#define NOT 1636
#define PAD 1637
#define PUT 1638
#define RED 1639
#define ROW 1640
#define RUN 1641
#define SQL 1642
#define SUM 1643
#define TOP 1644
#define USE 1645
#define ATSIGN 1646
#define PLUS 1647
#define AS_TIFF 1648
#define AS_GIF 1649
#define AS_PNG 1650
#define AS_JPEG 1651
#define AS 1652
#define AT 1653
#define BY 1654
#define DOT 1655
#define GO 1656
#define IF 1657
#define IN 1658
#define OF 1659
#define ON 1660
#define KW_OR 1661
#define TO 1662
#define KWUP 1663
#define FONT_NAME 1664
#define FONT_SIZE 1665
#define PAPER_SIZE_IS_LETTER 1666
#define PAPER_SIZE_IS_LEGAL 1667
#define PAPER_SIZE_IS_A5 1668
#define PAPER_SIZE_IS_A4 1669
#define PAPER_SIZE_IS_LETTER_L 1670
#define PAPER_SIZE_IS_LEGAL_L 1671
#define PAPER_SIZE_IS_A5_L 1672
#define PAPER_SIZE_IS_A4_L 1673
#define FORMHANDLER 1674
#define END_FORMHANDLER 1675
#define BEFORE_EVENT 1676
#define BEFORE_OPEN_FORM 1677
#define AFTER_EVENT 1678
#define BEFORE_CLOSE_FORM 1679
#define BEFORE_ANY 1680
#define AFTER_ANY 1681
#define MENUHANDLER 1682
#define END_MENUHANDLER 1683
#define BEFORE_SHOW_MENU 1684
#define DISABLE_PROGRAM 1685
#define DISABLE_ALL 1686
#define BUTTONS 1687
#define CHECK_MENUITEM 1688
#define DISABLE_FORM 1689
#define DISABLE_MENUITEMS 1690
#define DISABLE 1691
#define ENABLE_FORM 1692
#define ENABLE_MENUITEMS 1693
#define ENABLE 1694
#define KWFIELD 1695
#define ICON 1696
#define MESSAGEBOX 1697
#define TO_DEFAULTS 1698
#define UNCHECK_MENUITEM 1699
#define BEFORE 1700
#define INPUT 1701
#define END 1702
#define INT_TO_ID 1703
#define TIMEOUT 1704
#define OFF 1705
#define WITH_1_DIMENSION 1706
#define WITH_2_DIMENSION 1707
#define WITH_3_DIMENSION 1708
#define TILDE 1709
#define ILIKE 1710
#define FGL_ISDYNARR_ALLOCATED 1711
#define FGL_DYNARR_EXTENTSIZE 1712
#define FILLFACTOR 1713
#define END_CLASS 1714
#define KW_CLASS 1715
#define EXTENDS 1716
#define PIPE 1717
