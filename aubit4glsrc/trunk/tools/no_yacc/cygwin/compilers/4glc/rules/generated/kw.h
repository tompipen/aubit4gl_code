struct s_kw {
    int id;
	   int mode;
    char *vals[20];
    char *name;
};
#define KW_DOC4GLCOMMENT 1000
#define KW_RUN_CLIENT 1001
#define ON_CLOSE_APPLICATION_STOP 1002
#define LEFT_JOIN 1003
#define LINT_IGNORE 1004
#define LINT_EXPECT 1005
#define SQLERRMESSAGE 1006
#define DISPLAY_NULL_TO 1007
#define UNBUFFERED 1008
#define KW_PICTURE 1009
#define ON_CHANGE 1010
#define INNER_JOIN 1011
#define DIALOGSETCURRLINE 1012
#define DIALOGKEYSETLABEL 1013
#define UI_INTERFACE_DOT_FRONTCALL 1014
#define UI_INTERFACE_DOT 1015
#define UI_WINDOW_DOT 1016
#define UIWINDOW 1017
#define UICOMBOBOX 1018
#define OMDOMNODE 1019
#define OMNODELIST 1020
#define UIFORM 1021
#define WITH_CONVERSIONS 1022
#define WITHOUT_CONVERSIONS 1023
#define BARCODE 1024
#define BARCODE_NO_TEXT 1025
#define BARCODETYPE 1026
#define BLUEBAR_COLOR_EQUAL 1027
#define BLUEBAR_STYLE_EQUAL_RECTANGLE_COLOR_EQUAL 1028
#define BLUEBAR_STYLE_EQUAL_RECTANGLE 1029
#define BLUEBAR_STYLE_EQUAL_LINE_COLOR_EQUAL 1030
#define BLUEBAR_STYLE_EQUAL_LINE 1031
#define BLUEBAR 1032
#define NOSQLCLOBBER 1033
#define NOCLOBBER 1034
#define ALWAYSSQLCLOBBER 1035
#define ALWAYSCLOBBER 1036
#define USING_BTREE 1037
#define USING_RTREE 1038
#define BASECHANNEL 1039
#define UI_DOT_FORM_DOT 1040
#define DIALOG_DOT 1041
#define STRING 1042
#define KW_COMMENT 1043
#define KW_IMAGE 1044
#define DEBUG_FILE 1045
#define TRACE_PROCEDURE 1046
#define RAISE_EXCEPTION 1047
#define WITH_HOLD_FOR 1048
#define CREATE_PROCEDURE 1049
#define WITH_RESUME 1050
#define TRACE_ON 1051
#define END_PROCEDURE 1052
#define END_EXCEPTION 1053
#define REFERENCES_BYTE 1054
#define ASCOPY 1055
#define REFERENCES_TEXT 1056
#define TRACE_OFF 1057
#define REPLACE_STRING 1058
#define STOP_REPLACE_STRING 1059
#define IGNORE_FUNCTION 1060
#define EMULATE_INSERT_CURSOR_FOR 1061
#define DEFINE_GLOBAL 1062
#define SET_BUFFERED_LOG 1063
#define SET_FILL_COLOR 1064
#define SET_PARAMETER 1065
#define SET_LOG 1066
#define PRAGMA 1067
#define MDY 1068
#define WEEKDAY 1069
#define SYSTEM_4GL 1070
#define SQL_FEATURE 1071
#define MODE_ANSI 1072
#define START_DATABASE 1073
#define WITH_LOG_IN 1074
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1075
#define CONVERTING_VIA 1076
#define CONVERTING_TO_PIPE 1077
#define CONVERTING_TO_FILE 1078
#define CONVERTING_TO_PRINTER 1079
#define CONVERTING_TO_EMAIL 1080
#define KW_CHANNEL_READ 1081
#define KW_CHANNEL_WRITE 1082
#define AS_CONVERTIBLE 1083
#define FREE_REPORT 1084
#define CONVERTING_TO_MANY 1085
#define CONVERTING_TO 1086
#define CONVERT_REPORT 1087
#define DATETIME_VALUE 1088
#define INTERVAL_VALUE 1089
#define RECOVER_TABLE 1090
#define ROLLFORWARD_DATABASE 1091
#define IN_LINE_MODE 1092
#define IN_FORM_MODE 1093
#define FGL_SIZEOF 1094
#define FGL_ADDRESSOF 1095
#define IMPORT_PACKAGE 1096
#define DYNAMIC_ARRAY 1097
#define RESIZE_ARRAY 1098
#define ALLOCATE_ARRAY 1099
#define DEALLOCATE_ARRAY 1100
#define AFTER_INSERT_DELETE 1101
#define BEFORE_INSERT_DELETE 1102
#define BEFORE_INSERT 1103
#define AS_CONVERTABLE 1104
#define CONCAT_PIPES 1105
#define BEFORE_DELETE 1106
#define DROP_TRIGGER 1107
#define DROP_AUDIT_FOR 1108
#define CREATE_AUDIT_FOR 1109
#define AFTER_INSERT 1110
#define AFTER_DELETE 1111
#define EXECUTE_IMMEDIATE 1112
#define EXECUTE_PROCEDURE 1113
#define DELETE_ROW_EQUAL_TRUE 1114
#define INSERT_ROW_EQUAL_TRUE 1115
#define DELETE_ROW_EQUAL_FALSE 1116
#define INSERT_ROW_EQUAL_FALSE 1117
#define CURRENT_ROW_DISPLAY_EQUAL 1118
#define MAXCOUNT 1119
#define ALTER_TABLE 1120
#define ALTER_INDEX 1121
#define NEXT_SIZE 1122
#define DISPLAY_ATTR_FORM 1123
#define DISPLAY_ATTR_WINDOW 1124
#define INPUT_ATTR_FORM 1125
#define INPUT_ATTR_WINDOW 1126
#define WHENEVER_ERROR_CONTINUE 1127
#define WHENEVER_ANY_ERROR_CONTINUE 1128
#define WHENEVER_WARNING_CONTINUE 1129
#define WHENEVER_SQLSUCCESS_CONTINUE 1130
#define WHENEVER_SQLWARNING_CONTINUE 1131
#define WHENEVER_NOT_FOUND_CONTINUE 1132
#define WHENEVER_SQLERROR_CONTINUE 1133
#define WHENEVER_SUCCESS_CONTINUE 1134
#define WHENEVER_ERROR_GOTO 1135
#define WHENEVER_ANY_ERROR_GOTO 1136
#define WHENEVER_WARNING_GOTO 1137
#define WHENEVER_SQLSUCCESS_GOTO 1138
#define WHENEVER_SQLWARNING_GOTO 1139
#define WHENEVER_NOT_FOUND_GOTO 1140
#define WHENEVER_SQLERROR_GOTO 1141
#define WHENEVER_SUCCESS_GOTO 1142
#define WHENEVER_ERROR_CALL 1143
#define WHENEVER_ANY_ERROR_CALL 1144
#define WHENEVER_WARNING_CALL 1145
#define WHENEVER_SQLSUCCESS_CALL 1146
#define WHENEVER_SQLWARNING_CALL 1147
#define WHENEVER_NOT_FOUND_CALL 1148
#define WHENEVER_SQLERROR_CALL 1149
#define WHENEVER_SUCCESS_CALL 1150
#define WHENEVER_ERROR_STOP 1151
#define WHENEVER_ANY_ERROR_STOP 1152
#define WHENEVER_WARNING_STOP 1153
#define WHENEVER_SQLSUCCESS_STOP 1154
#define WHENEVER_SQLWARNING_STOP 1155
#define WHENEVER_NOT_FOUND_STOP 1156
#define WHENEVER_SQLERROR_STOP 1157
#define WHENEVER_SUCCESS_STOP 1158
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1159
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1160
#define XSET_ident_DOT_MULTIPLY_EQUAL 1161
#define XSET_MULTIPLY_EQUAL 1162
#define XSET_OPEN_BRACKET 1163
#define NEWFORMATSHARED 1164
#define DEFINE_NEW_TYPE 1165
#define CREATE_DATABASE 1166
#define DROP_DATABASE 1167
#define IMPORT_LEGACY_FUNCTION 1168
#define ADD_CONSTRAINT 1169
#define DROP_CONSTRAINT 1170
#define DROP_SYNONYM 1171
#define CONSTRAINT 1172
#define AS_STATIC 1173
#define NOT_FIELD_TOUCHED 1174
#define NOT_FIELD_TOUCHED_CURRENT 1175
#define FIELD_TOUCHED_CURRENT 1176
#define LOCAL_FUNCTION 1177
#define LOCAL_REPORT 1178
#define LOCAL_PDF_REPORT 1179
#define EVERY_ROW 1180
#define ELIF 1181
#define KW_ARG_VAL 1182
#define DOUBLE_PRECISION 1183
#define COUNT_MULTIPLY 1184
#define WAIT_FOR_KEY 1185
#define AT_TERMINATION_CALL 1186
#define TERMINATE_REPORT 1187
#define TO_MAIN_CAPTION 1188
#define CLEARSTAT 1189
#define TO_MENUITEM 1190
#define ID_TO_INT 1191
#define TO_STATUSBOX 1192
#define ASCII_HEIGHT_ALL 1193
#define ASCII_WIDTH_ALL 1194
#define IMPORT_DATATYPE 1195
#define PAGE_TRAILER_SIZE 1196
#define PAGE_HEADER_SIZE 1197
#define FIRST_PAGE_HEADER_SIZE 1198
#define BYTES_USE_AS_IMAGE 1199
#define BYTES_USE_AS_ASCII 1200
#define KWUP_BY 1201
#define KWDOWN_BY 1202
#define CLOSE_STATUSBOX 1203
#define MODIFY_NEXT_SIZE 1204
#define LOCK_MODE_PAGE 1205
#define LOCK_MODE_ROW 1206
#define TO_PIPE 1207
#define TO_FILE 1208
#define TO_SCREEN 1209
#define TO_PRINTER 1210
#define TO_EMAIL 1211
#define STATUSBOX 1212
#define UNITS_YEAR 1213
#define UNITS_MONTH 1214
#define UNITS_DAY 1215
#define UNITS_HOUR 1216
#define UNITS_MINUTE 1217
#define UNITS_SECOND 1218
#define NO_NEW_LINES 1219
#define FIELDTOWIDGET 1220
#define WITH_HOLD 1221
#define SHOW_MENU 1222
#define TO_CLUSTER 1223
#define TO_NOT_CLUSTER 1224
#define CWIS 1225
#define CREATE_UC_IDX 1226
#define CREATE_U_IDX 1227
#define CREATE_C_IDX 1228
#define CREATE_IDX 1229
#define FORM_IS_COMPILED 1230
#define PDF_REPORT 1231
#define IMPORT_FUNCTION 1232
#define PROMPT_MANY 1233
#define KW_POINTS 1234
#define MM 1235
#define CM 1236
#define INCHES 1237
#define PREPEND 1238
#define DOUBLE_COLON 1239
#define USE_MEMBER_FUNCTION 1240
#define USE_MEMBER_OF 1241
#define APPEND 1242
#define TEMPLATE 1243
#define END_TEMPLATE 1244
#define SQLSICS 1245
#define CREATE_SCHEMA 1246
#define SQLSIRR 1247
#define UPDATESTATS_T 1248
#define SQLSICR 1249
#define WHENEVER_SQLSUCCESS 1250
#define WHENEVER_SQLWARNING 1251
#define WHENEVER_ANY_ERROR 1252
#define WHENEVER_NOT_FOUND 1253
#define WHENEVER_SQLERROR 1254
#define WHENEVER_SUCCESS 1255
#define WHENEVER_ERROR 1256
#define START_EXTERN 1257
#define CONTINUE_CONSTRUCT 1258
#define FOUNCONSTR 1259
#define SQLSIDR 1260
#define CREATE_TEMP_TABLE 1261
#define CURRENT_WINDOW_IS 1262
#define FIRST_PAGE_HEADER 1263
#define ORDER_EXTERNAL_BY 1264
#define SCROLL_CURSOR_FOR 1265
#define SCROLL_CURSOR 1266
#define SQL_INTERRUPT_OFF 1267
#define STOP_ALL_EXTERNAL 1268
#define WITH_CHECK_OPTION 1269
#define WITH_GRANT_OPTION 1270
#define SQLSLMNW 1271
#define ADDCONSTUNIQ 1272
#define CONTINUE_DISPLAY 1273
#define CONTINUE_FOREACH 1274
#define OUTPUT_TO_REPORT 1275
#define SQL_INTERRUPT_ON 1276
#define WHERE_CURRENT_OF 1277
#define WITHOUT_DEFAULTS 1278
#define FOCONSTR 1279
#define SCALED_BY 1280
#define CONTINUE_PROMPT 1281
#define PDF_FUNCTION 1282
#define DEFER_INTERRUPT 1283
#define DISPLAY_BY_NAME 1284
#define NOT_NULL_UNIQUE 1285
#define SKIP_TO_TOP 1286
#define TOP_OF_PAGE 1287
#define SKIP_TO 1288
#define SKIP_BY 1289
#define WITHOUT_WAITING 1290
#define BEFCONSTRUCT 1291
#define SQLSLMW 1292
#define AFTCONSTRUCT 1293
#define ALL_PRIVILEGES 1294
#define CLOSE_DATABASE 1295
#define CONTINUE_INPUT 1296
#define CONTINUE_WHILE 1297
#define CREATE_SYNONYM 1298
#define DROP_TABLE 1299
#define EXIT_CONSTRUCT 1300
#define INEXCLUSIVE 1301
#define REPORT_TO_PRINTER 1302
#define REPORT_TO_PIPE 1303
#define KW_RETURN 1304
#define SET_SESSION_TO 1305
#define UPDATESTATS 1306
#define WITHOUT_HEAD 1307
#define CLEARSCR 1308
#define WITH_B_LOG 1309
#define AUTHORIZATION 1310
#define BOTTOM_MARGIN 1311
#define CLOSE_SESSION 1312
#define CONTINUE_CASE 1313
#define CONTINUE_MENU 1314
#define DISPLAY_ARRAY 1315
#define END_SQL 1316
#define DOLLAR 1317
#define END_CONSTRUCT 1318
#define FIELD_TOUCHED 1319
#define FINISH_REPORT 1320
#define INFACC 1321
#define INPUT_NO_WRAP 1322
#define SETPMOFF 1323
#define UNCONSTRAINED 1324
#define PAGE_TRAILER 1325
#define SETPMON 1326
#define BEFGROUP 1327
#define CLOSE_WINDOW 1328
#define COMMENT_LINE 1329
#define CONTINUE_FOR 1330
#define CREATE_DB 1331
#define CREATE_TABLE 1332
#define DEFAULT_NULL 1333
#define DEFAULT_TODAY 1334
#define DEFAULT_USER 1335
#define DELETE_USING 1336
#define DISPLAY_FORM 1337
#define END_FUNCTION 1338
#define EXIT_DISPLAY 1339
#define EXIT_FOREACH 1340
#define EXIT_PROGRAM 1341
#define INFCOLS 1342
#define ON_EVERY_ROW 1343
#define OPEN_SESSION 1344
#define RIGHT_MARGIN 1345
#define SELECT_USING 1346
#define START_REPORT 1347
#define UNLOCK_TABLE 1348
#define UPDATE_USING 1349
#define ACL_BUILTIN 1350
#define AFTGROUP 1351
#define INFIDX 1352
#define INFSTAT 1353
#define LEFT_MARGIN 1354
#define PAGE_HEADER 1355
#define ROLLBACK_W 1356
#define SET_SESSION 1357
#define SQLSEON 1358
#define SQLSEOFF 1359
#define WITH_A_LOG 1360
#define BEFDISP 1361
#define BEFORE_MENU 1362
#define CREATE_VIEW 1363
#define DELETE_FROM 1364
#define END_DISPLAY 1365
#define END_REPORT 1366
#define END_FOREACH 1367
#define END_FOR 1368
#define END_GLOBALS 1369
#define EXIT_PROMPT 1370
#define EXTENT_SIZE 1371
#define FOREIGN_KEY 1372
#define HIDE_OPTION 1373
#define KW_HIDE_WINDOW 1374
#define INSERT_INTO 1375
#define IS_SERIAL 1376
#define IS_NOT_NULL 1377
#define MOVE_WINDOW 1378
#define NEXT_OPTION 1379
#define NOT_MATCHES 1380
#define ON_LAST_ROW 1381
#define OPEN_WINDOW 1382
#define OPEN_STATUSBOX 1383
#define PAGE_LENGTH 1384
#define PAGE_WIDTH 1385
#define PRIMARY_KEY 1386
#define PROMPT_LINE 1387
#define RECORD_LIKE 1388
#define ROLLFORWARD 1389
#define SHOW_OPTION 1390
#define SHOW_WINDOW 1391
#define TO_DATABASE 1392
#define USE_SESSION 1393
#define WITH_NO_LOG 1394
#define AFTDISP 1395
#define BEFFIELD 1396
#define INSHARE 1397
#define UNLOCKTAB 1398
#define AFTFIELD 1399
#define ATTRIBUTES 1400
#define BEFINP 1401
#define BEFORE_DISPLAY 1402
#define BEGIN_WORK 1403
#define CLEARWIN 1404
#define CLOSE_FORM 1405
#define DEFER_QUIT 1406
#define DESCENDING 1407
#define DROP_INDEX 1408
#define END_PROMPT 1409
#define END_RECORD 1410
#define ERROR_LINE 1411
#define EXIT_INPUT 1412
#define EXIT_WHILE 1413
#define FOR_UPDATE_OF 1414
#define FOR_UPDATE 1415
#define GET_FLDBUF 1416
#define REFERENCE 1417
#define INITIALIZE 1418
#define INPUT_WRAP 1419
#define LOCK_TABLE 1420
#define MSG_LINE 1421
#define NOT_EXISTS 1422
#define ON_ANY_KEY 1423
#define REFERENCES 1424
#define RENCOL 1425
#define SET_CURSOR 1426
#define SMALLFLOAT 1427
#define SQLSUCCESS 1428
#define TOP_MARGIN 1429
#define WITH_ARRAY 1430
#define ACCEPTKEY 1431
#define KW_ACCEPT 1432
#define AFTINP 1433
#define AFTER_DISPLAY 1434
#define CLEARFORMTODEFAULTS 1435
#define CLEARFORM 1436
#define CLEAR_X_FORM 1437
#define COMMIT_W 1438
#define KW_NEXTPAGE 1439
#define KW_PREVPAGE 1440
#define KW_CTRL_KEY 1441
#define INFTABS 1442
#define NEXTFIELD 1443
#define NEXTFORM 1444
#define RENTAB 1445
#define ASCENDING 1446
#define ASSOCIATE 1447
#define KW_CHAR 1448
#define NCHAR 1449
#define NVARCHAR 1450
#define CONSTRUCT 1451
#define DELIMITER 1452
#define DOWNSHIFT 1453
#define DROP_VIEW 1454
#define END_INPUT 1455
#define END_WHILE 1456
#define EXCLUSIVE 1457
#define EXIT_CASE 1458
#define EXIT_MENU 1459
#define FORM_LINE 1460
#define GREATER_THAN_EQ 1461
#define KW_INTERRUPT 1462
#define INTO_TEMP 1463
#define INVISIBLE 1464
#define IN_MEMORY 1465
#define LINKED_TO 1466
#define LOAD_FROM 1467
#define LOCKTAB 1468
#define MENU_LINE 1469
#define OPEN_FORM 1470
#define OTHERWISE 1471
#define PRECISION 1472
#define KW_PRIOR 1473
#define PROCEDURE 1474
#define REPORT_TO 1475
#define RETURNING 1476
#define UNDERLINE 1477
#define UNLOAD_TO 1478
#define BEFROW 1479
#define UNLOAD_T 1480
#define VARIABLE 1481
#define KW_ABSOLUTE 1482
#define AFTROW 1483
#define BUFFERED 1484
#define KW_CONSTANT 1485
#define KW_CONST 1486
#define DATABASE 1487
#define DATETIME 1488
#define DEFAULTS 1489
#define DISTINCT 1490
#define END_CASE 1491
#define END_MAIN 1492
#define END_MENU 1493
#define END_TYPE 1494
#define EXIT_FOR 1495
#define EXTERNAL 1496
#define FRACTION 1497
#define FUNCTION 1498
#define GROUP_BY 1499
#define INTERVAL 1500
#define KWMESSAGE 1501
#define NOT_LIKE 1502
#define NOT_ILIKE 1503
#define NOT_NULL 1504
#define PASSWORD 1505
#define KW_PREVIOUS 1506
#define READONLY 1507
#define REGISTER 1508
#define KW_RELATIVE 1509
#define RESOURCE 1510
#define SMALLINT 1511
#define VALIDATE 1512
#define WITH_LOG 1513
#define KW_WORDWRAP 1514
#define BY_NAME 1515
#define IN_FILE 1516
#define IS_NULL 1517
#define LESS_THAN_EQ 1518
#define AVERAGE 1519
#define BETWEEN 1520
#define CAPTION 1521
#define KW_CLIPPED 1522
#define CLOSE_BRACKET 1523
#define COLUMNS 1524
#define COMMAND 1525
#define CONNECT 1526
#define KW_CURRENT 1527
#define DBYNAME 1528
#define KW_DECIMAL 1529
#define DECLARE 1530
#define DEFAULT 1531
#define KW_DISPLAY 1532
#define ENDCODE 1533
#define EXECUTE 1534
#define FOREACH 1535
#define FOREIGN 1536
#define GLOBALS 1537
#define INFIELD 1538
#define INTEGER 1539
#define INTEGER8 1540
#define SERIAL8 1541
#define KWWINDOW 1542
#define MAGENTA 1543
#define MATCHES 1544
#define OPTIONS 1545
#define PERCENT 1546
#define PREPARE 1547
#define PROGRAM 1548
#define RECOVER 1549
#define REVERSE 1550
#define SECTION 1551
#define SESSION 1552
#define SYNONYM 1553
#define THRU 1554
#define TRAILER 1555
#define UPSHIFT 1556
#define VARCHAR 1557
#define WAITING 1558
#define CLOSE_SHEV 1559
#define CLOSE_SQUARE 1560
#define GREATER_THAN 1561
#define KW_FALSE 1562
#define NOT_IN 1563
#define ONKEY 1564
#define OPEN_BRACKET 1565
#define BORDER 1566
#define BOTTOM 1567
#define COLUMN 1568
#define COMMIT 1569
#define CREATE 1570
#define CURSOR 1571
#define DEFINE 1572
#define KW_DELETE 1573
#define KW_DOUBLE 1574
#define END_IF 1575
#define KW_ESCAPE 1576
#define EXISTS 1577
#define EXTEND 1578
#define EXTENT 1579
#define FINISH 1580
#define FORMAT 1581
#define HAVING 1582
#define HEADER 1583
#define KW_INSERT 1584
#define LOCATE 1585
#define MARGIN 1586
#define MEMORY 1587
#define MINUTE 1588
#define MODIFY 1589
#define NORMAL 1590
#define EQUAL 1591
#define NOT_EQUAL 1592
#define OPEN_SHEV 1593
#define OPEN_SQUARE 1594
#define OPTION 1595
#define OUTPUT 1596
#define PROMPT 1597
#define PUBLIC 1598
#define RECORD 1599
#define REPORT 1600
#define KW_ENTER 1601
#define REVOKE 1602
#define SCHEMA 1603
#define SCROLL_USING 1604
#define SCROLL 1605
#define SECOND 1606
#define IDLE_SECONDS 1607
#define IDLE_MINUTES 1608
#define IDLE_HOURS 1609
#define KW_SELECT 1610
#define SERIAL 1611
#define SHARED 1612
#define KW_SPACES 1613
#define UNIQUE 1614
#define UNLOCK 1615
#define KW_UPDATE 1616
#define VALUES 1617
#define YELLOW 1618
#define AFTER 1619
#define KW_NULL 1620
#define KW_TRUE 1621
#define KW_SINGLE_KEY 1622
#define ALTER 1623
#define ARRAY 1624
#define KW_ASCII 1625
#define AUDIT 1626
#define BLACK 1627
#define BLINK 1628
#define CHECK 1629
#define CLEAR 1630
#define CLOSE 1631
#define CODE_C 1632
#define COUNT 1633
#define DEFER 1634
#define KW_ERROR 1635
#define EVERY 1636
#define FETCH 1637
#define KW_FIRST 1638
#define KW_FLOAT 1639
#define FLUSH 1640
#define FOUND 1641
#define GRANT 1642
#define GREEN 1643
#define KW_GROUP 1644
#define INDEX 1645
#define KWFORM 1646
#define LABEL 1647
#define LESS_THAN 1648
#define LOCAL 1649
#define MONEY 1650
#define MONTH 1651
#define KW_POWER 1652
#define KW_MULTIPLY 1653
#define ORDER 1654
#define OUTER 1655
#define PAUSE 1656
#define PRINT_IMAGE 1657
#define PRINT_FILE 1658
#define PRINT 1659
#define KW_RIGHT 1660
#define SEMICOLON 1661
#define SLEEP 1662
#define TUPLE 1663
#define UNION 1664
#define KW_USING_FILTER 1665
#define KW_USING 1666
#define WHERE 1667
#define WHILE 1668
#define WHITE 1669
#define CCODE 1670
#define ANSI 1671
#define BLUE 1672
#define BOLD 1673
#define KW_BYTE 1674
#define FCALL 1675
#define CASE 1676
#define CYAN 1677
#define KW_DATE 1678
#define DESC 1679
#define KW_DIVIDE 1680
#define KWDOWN 1681
#define KW_TAB 1682
#define DROP 1683
#define ELSE 1684
#define EXEC 1685
#define EXIT 1686
#define FREE 1687
#define FROM 1688
#define GOTO 1689
#define HELP_FILE 1690
#define LANG_FILE 1691
#define KW_HELP 1692
#define HIDE 1693
#define HOUR 1694
#define INTO 1695
#define KW_LAST 1696
#define KW_LEFT 1697
#define LIKE 1698
#define MAIN 1699
#define MENU 1700
#define MODE 1701
#define NEED 1702
#define KW_NEXT 1703
#define NOCR 1704
#define OPEN 1705
#define QUIT 1706
#define REAL 1707
#define ROWS 1708
#define SHOW 1709
#define KW_SIZE 1710
#define SKIP 1711
#define SOME 1712
#define STEP 1713
#define STOP 1714
#define TEMP 1715
#define KW_TEXT 1716
#define KW_THEN 1717
#define USER 1718
#define WAIT 1719
#define WHEN 1720
#define WITH 1721
#define WORK 1722
#define YEAR 1723
#define KW_DOW 1724
#define KW_IS 1725
#define XSET 1726
#define ADD 1727
#define ALL 1728
#define KW_AND 1729
#define ANY 1730
#define ASC 1731
#define AVG 1732
#define COLON 1733
#define KW_COMMA 1734
#define DAY 1735
#define DBA 1736
#define DEC 1737
#define DIM 1738
#define KW_FKEY 1739
#define KW_FOR 1740
#define KW_KEY 1741
#define KWNO 1742
#define KW_LET 1743
#define LOG 1744
#define XMAX 1745
#define XMIN 1746
#define KW_MINUS 1747
#define KW_MOD 1748
#define KW_NOT 1749
#define KW_PAD 1750
#define KW_PUT 1751
#define KW_RED 1752
#define KW_ROW 1753
#define KW_RUN 1754
#define KW_SQL 1755
#define KW_SUM 1756
#define KW_TOP 1757
#define KW_USE 1758
#define ATSIGN 1759
#define KW_PLUS 1760
#define AS_TIFF 1761
#define AS_GIF 1762
#define AS_PNG 1763
#define AS_JPEG 1764
#define KW_AS_USER 1765
#define KW_AS 1766
#define KW_AT 1767
#define KW_BY 1768
#define KW_DOT 1769
#define KW_GO 1770
#define KW_IF 1771
#define KW_IN 1772
#define KW_OF 1773
#define KW_ON 1774
#define KW_OR 1775
#define KW_TO 1776
#define KWUP 1777
#define FONT_NAME 1778
#define FONT_SIZE 1779
#define PAPER_SIZE_IS_LETTER 1780
#define PAPER_SIZE_IS_LEGAL 1781
#define PAPER_SIZE_IS_A5 1782
#define PAPER_SIZE_IS_A4 1783
#define PAPER_SIZE_IS_LETTER_L 1784
#define PAPER_SIZE_IS_LEGAL_L 1785
#define PAPER_SIZE_IS_A5_L 1786
#define PAPER_SIZE_IS_A4_L 1787
#define FORMHANDLER 1788
#define END_FORMHANDLER 1789
#define BEFORE_EVENT 1790
#define BEFORE_OPEN_FORM 1791
#define AFTER_EVENT 1792
#define BEFORE_CLOSE_FORM 1793
#define BEFORE_ANY 1794
#define AFTER_ANY 1795
#define MENUHANDLER 1796
#define END_MENUHANDLER 1797
#define BEFORE_SHOW_MENU 1798
#define DISABLE_PROGRAM 1799
#define DISABLE_ALL 1800
#define BUTTONS 1801
#define CHECK_MENUITEM 1802
#define DISABLE_FORM 1803
#define DISABLE_MENUITEMS 1804
#define DISABLE 1805
#define ENABLE_FORM 1806
#define ENABLE_MENUITEMS 1807
#define ENABLE 1808
#define KWFIELD 1809
#define ICON 1810
#define MESSAGEBOX 1811
#define TO_DEFAULTS 1812
#define UNCHECK_MENUITEM 1813
#define BEFORE 1814
#define KW_INPUT_ARRAY 1815
#define KW_INPUT 1816
#define FINPUT 1817
#define END 1818
#define INT_TO_ID 1819
#define TIMEOUT 1820
#define KW_OFF 1821
#define WITH_1_DIMENSION 1822
#define WITH_2_DIMENSION 1823
#define WITH_3_DIMENSION 1824
#define TILDE 1825
#define ILIKE 1826
#define FGL_ISDYNARR_ALLOCATED 1827
#define FGL_DYNARR_EXTENTSIZE 1828
#define FILLFACTOR 1829
#define END_CLASS 1830
#define KW_CLASS 1831
#define KW_EXTENDS 1832
#define KW_PIPE 1833
#define TIME 1834
#define KWBEGIN 1835
#define TRACE 1836
#define SITENAME 1837
#define DBSERVERNAME 1838
#define SYSTEM 1839
#define EXCEPTION 1840
#define KW_TODAY 1841
#define KW_ROWID 1842
#define PGKW_ABORT_P 1843
#define PGKW_ABSOLUTE_P 1844
#define PGKW_ACCESS 1845
#define PGKW_ACTION 1846
#define PGKW_ADD 1847
#define PGKW_AFTER 1848
#define PGKW_AGGREGATE 1849
#define PGKW_ALL 1850
#define PGKW_ALTER 1851
#define PGKW_ANALYSE 1852
#define PGKW_ANALYZE 1853
#define PGKW_AND 1854
#define PGKW_ANY 1855
#define PGKW_ARRAY 1856
#define PGKW_AS 1857
#define PGKW_ASC 1858
#define PGKW_ASSERTION 1859
#define PGKW_ASSIGNMENT 1860
#define PGKW_AT 1861
#define PGKW_AUTHORIZATION 1862
#define PGKW_BACKWARD 1863
#define PGKW_BCONST 1864
#define PGKW_BEFORE 1865
#define PGKW_BEGIN_P 1866
#define PGKW_BETWEEN 1867
#define PGKW_BIGINT 1868
#define PGKW_BINARY 1869
#define PGKW_BIT 1870
#define PGKW_BOOLEAN_P 1871
#define PGKW_BOTH 1872
#define PGKW_BY 1873
#define PGKW_CACHE 1874
#define PGKW_CALLED 1875
#define PGKW_CARAT 1876
#define PGKW_CASCADE 1877
#define PGKW_CASE 1878
#define PGKW_CAST 1879
#define PGKW_CHAIN 1880
#define PGKW_CHARACTER 1881
#define PGKW_CHARACTERISTICS 1882
#define PGKW_CHAR_P 1883
#define PGKW_CHECK 1884
#define PGKW_CHECKPOINT 1885
#define PGKW_CLASS 1886
#define PGKW_CLOSE 1887
#define PGKW_CLOSE_BRACKET 1888
#define PGKW_CLOSE_SQUARE 1889
#define PGKW_CLUSTER 1890
#define PGKW_COALESCE 1891
#define PGKW_COLLATE 1892
#define PGKW_COLON 1893
#define PGKW_COLUMN 1894
#define PGKW_COMMA 1895
#define PGKW_COMMENT 1896
#define PGKW_COMMIT 1897
#define PGKW_COMMITTED 1898
#define PGKW_CONSTRAINT 1899
#define PGKW_CONSTRAINTS 1900
#define PGKW_CONVERSION_P 1901
#define PGKW_CONVERT 1902
#define PGKW_COPY 1903
#define PGKW_CREATE 1904
#define PGKW_CREATEDB 1905
#define PGKW_CREATEUSER 1906
#define PGKW_CROSS 1907
#define PGKW_CURRENT 1908
#define PGKW_CURRENT_DATE 1909
#define PGKW_CURRENT_TIME 1910
#define PGKW_CURRENT_TIMESTAMP 1911
#define PGKW_CURRENT_USER 1912
#define PGKW_CURSOR 1913
#define PGKW_CYCLE 1914
#define PGKW_DATABASE 1915
#define PGKW_DATETIME 1916
#define PGKW_DAY_P 1917
#define PGKW_DBA 1918
#define PGKW_DEALLOCATE 1919
#define PGKW_DEC 1920
#define PGKW_DECIMAL_P 1921
#define PGKW_DECLARE 1922
#define PGKW_DEFAULT 1923
#define PGKW_DEFAULTS 1924
#define PGKW_DEFERRABLE 1925
#define PGKW_DEFERRED 1926
#define PGKW_DEFINER 1927
#define PGKW_DELETE_P 1928
#define PGKW_DELIMITER 1929
#define PGKW_DELIMITERS 1930
#define PGKW_DESC 1931
#define PGKW_DISTINCT 1932
#define PGKW_DIVIDE 1933
#define PGKW_DO 1934
#define PGKW_DOMAIN_P 1935
#define PGKW_DOT 1936
#define PGKW_DOUBLE_P 1937
#define PGKW_DROP 1938
#define PGKW_EACH 1939
#define PGKW_ELSE 1940
#define PGKW_ENCODING 1941
#define PGKW_ENCRYPTED 1942
#define PGKW_END_P 1943
#define PGKW_EQUAL 1944
#define PGKW_ESCAPE 1945
#define PGKW_EXCEPT 1946
#define PGKW_EXCLUDING 1947
#define PGKW_EXCLUSIVE 1948
#define PGKW_EXECUTE 1949
#define PGKW_EXISTS 1950
#define PGKW_EXPLAIN 1951
#define PGKW_EXTEND 1952
#define PGKW_EXTERNAL 1953
#define PGKW_EXTRACT 1954
#define PGKW_FALSE_P 1955
#define PGKW_FETCH 1956
#define PGKW_FIRST_P 1957
#define PGKW_FLOAT_P 1958
#define PGKW_FOR 1959
#define PGKW_FORCE 1960
#define PGKW_FOREIGN 1961
#define PGKW_FORWARD 1962
#define PGKW_FREEZE 1963
#define PGKW_FROM 1964
#define PGKW_FULL 1965
#define PGKW_FUNCTION 1966
#define PGKW_GLOBAL 1967
#define PGKW_GRANT 1968
#define PGKW_GREATER_THAN 1969
#define PGKW_GROUP_P 1970
#define PGKW_HANDLER 1971
#define PGKW_HAVING 1972
#define PGKW_HOLD 1973
#define PGKW_HOUR_P 1974
#define PGKW_ILIKE 1975
#define PGKW_IMMEDIATE 1976
#define PGKW_IMMUTABLE 1977
#define PGKW_IMPLICIT_P 1978
#define PGKW_INCLUDING 1979
#define PGKW_INCREMENT 1980
#define PGKW_INDEX 1981
#define PGKW_INHERITS 1982
#define PGKW_INITIALLY 1983
#define PGKW_INNER_P 1984
#define PGKW_INOUT 1985
#define PGKW_IN_P 1986
#define PGKW_INPUT_P 1987
#define PGKW_INSENSITIVE 1988
#define PGKW_INSERT 1989
#define PGKW_INSTEAD 1990
#define PGKW_INTEGER 1991
#define PGKW_INTERSECT 1992
#define PGKW_INTERVAL 1993
#define PGKW_INTO 1994
#define PGKW_INT_P 1995
#define PGKW_INVOKER 1996
#define PGKW_IS 1997
#define PGKW_ISNULL 1998
#define PGKW_ISOLATION 1999
#define PGKW_JOIN 2000
#define PGKW_KEY 2001
#define PGKW_LANCOMPILER 2002
#define PGKW_LANGUAGE 2003
#define PGKW_LAST_P 2004
#define PGKW_LEADING 2005
#define PGKW_LEFT 2006
#define PGKW_LESS_THAN 2007
#define PGKW_LEVEL 2008
#define PGKW_LIKE 2009
#define PGKW_LIMIT 2010
#define PGKW_LISTEN 2011
#define PGKW_LOAD 2012
#define PGKW_LOCAL 2013
#define PGKW_LOCALTIME 2014
#define PGKW_LOCALTIMESTAMP 2015
#define PGKW_LOCATION 2016
#define PGKW_LOCK_P 2017
#define PGKW_MATCH 2018
#define PGKW_MAXVALUE 2019
#define PGKW_MINUS 2020
#define PGKW_MINUTE_P 2021
#define PGKW_MINVALUE 2022
#define PGKW_MODE 2023
#define PGKW_MODIFY 2024
#define PGKW_MONTH_P 2025
#define PGKW_MOVE 2026
#define PGKW_NAMES 2027
#define PGKW_NATIONAL 2028
#define PGKW_NATURAL 2029
#define PGKW_NCHAR 2030
#define PGKW_NEW 2031
#define PGKW_NEXT 2032
#define PGKW_NO 2033
#define PGKW_NOCREATEDB 2034
#define PGKW_NOCREATEUSER 2035
#define PGKW_NONE 2036
#define PGKW_NOT 2037
#define PGKW_NOTHING 2038
#define PGKW_NOTIFY 2039
#define PGKW_NOTNULL 2040
#define PGKW_NULLIF 2041
#define PGKW_NULL_P 2042
#define PGKW_NUMERIC 2043
#define PGKW_OF 2044
#define PGKW_OFF 2045
#define PGKW_OFFSET 2046
#define PGKW_OIDS 2047
#define PGKW_OLD 2048
#define PGKW_ON 2049
#define PGKW_ONLY 2050
#define PGKW_OPEN_BRACKET 2051
#define PGKW_OPEN_SQUARE 2052
#define PGKW_OPERATOR 2053
#define PGKW_OPTION 2054
#define PGKW_OR 2055
#define PGKW_ORDER 2056
#define PGKW_OUTER_P 2057
#define PGKW_OUT_P 2058
#define PGKW_OVERLAPS 2059
#define PGKW_OVERLAY 2060
#define PGKW_OWNER 2061
#define PGKW_PARAM 2062
#define PGKW_PARTIAL 2063
#define PGKW_PASSWORD 2064
#define PGKW_PATH_P 2065
#define PGKW_PENDANT 2066
#define PGKW_PERCENT 2067
#define PGKW_PLACING 2068
#define PGKW_PLUS 2069
#define PGKW_POSITION 2070
#define PGKW_POSTFIXOP 2071
#define PGKW_PRECISION 2072
#define PGKW_PREPARE 2073
#define PGKW_PRESERVE 2074
#define PGKW_PRIMARY 2075
#define PGKW_PRIOR 2076
#define PGKW_PRIVILEGES 2077
#define PGKW_PROCEDURAL 2078
#define PGKW_PROCEDURE 2079
#define PGKW_READ 2080
#define PGKW_REAL 2081
#define PGKW_RECHECK 2082
#define PGKW_REFERENCES 2083
#define PGKW_REINDEX 2084
#define PGKW_RELATIVE_P 2085
#define PGKW_RENAME 2086
#define PGKW_REPLACE 2087
#define PGKW_RESET 2088
#define PGKW_RESTART 2089
#define PGKW_RESTRICT 2090
#define PGKW_RETURNS 2091
#define PGKW_REVOKE 2092
#define PGKW_RIGHT 2093
#define PGKW_ROLLBACK 2094
#define PGKW_ROW 2095
#define PGKW_ROWS 2096
#define PGKW_RULE 2097
#define PGKW_SCHEMA 2098
#define PGKW_SCROLL 2099
#define PGKW_SECOND_P 2100
#define PGKW_SECURITY 2101
#define PGKW_SELECT 2102
#define PGKW_SEMICOLON 2103
#define PGKW_SEQUENCE 2104
#define PGKW_SERIALIZABLE 2105
#define PGKW_SESSION 2106
#define PGKW_SESSION_USER 2107
#define PGKW_SET 2108
#define PGKW_SETOF 2109
#define PGKW_SHARE 2110
#define PGKW_SHOW 2111
#define PGKW_SIMILAR 2112
#define PGKW_SIMPLE 2113
#define PGKW_SMALLINT 2114
#define PGKW_SOME 2115
#define PGKW_STABLE 2116
#define PGKW_STAR 2117
#define PGKW_START 2118
#define PGKW_STATEMENT 2119
#define PGKW_STATISTICS 2120
#define PGKW_STDIN 2121
#define PGKW_STDOUT 2122
#define PGKW_STORAGE 2123
#define PGKW_STRICT_P 2124
#define PGKW_SUBSTRING 2125
#define PGKW_SYSID 2126
#define PGKW_TABLE 2127
#define PGKW_TEMP 2128
#define PGKW_TEMPLATE 2129
#define PGKW_TEMPORARY 2130
#define PGKW_THEN 2131
#define PGKW_TIME 2132
#define PGKW_TIMESTAMP 2133
#define PGKW_TO 2134
#define PGKW_TOAST 2135
#define PGKW_TODAY_SYN 2136
#define PGKW_TRAILING 2137
#define PGKW_TRANSACTION 2138
#define PGKW_TREAT 2139
#define PGKW_TRIGGER 2140
#define PGKW_TRIM 2141
#define PGKW_TRUE_P 2142
#define PGKW_TRUNCATE 2143
#define PGKW_TRUSTED 2144
#define PGKW_TYPECAST 2145
#define PGKW_TYPE_P 2146
#define PGKW_UMINUS 2147
#define PGKW_UNENCRYPTED 2148
#define PGKW_UNION 2149
#define PGKW_UNIONJOIN 2150
#define PGKW_UNIQUE 2151
#define PGKW_UNKNOWN 2152
#define PGKW_UNLISTEN 2153
#define PGKW_UNLOAD 2154
#define PGKW_UNTIL 2155
#define PGKW_UPDATE 2156
#define PGKW_USAGE 2157
#define PGKW_USER 2158
#define PGKW_USING 2159
#define PGKW_VACUUM 2160
#define PGKW_VALID 2161
#define PGKW_VALIDATOR 2162
#define PGKW_VALUES 2163
#define PGKW_VARCHAR 2164
#define PGKW_VARYING 2165
#define PGKW_VERBOSE 2166
#define PGKW_VERSION 2167
#define PGKW_VIEW 2168
#define PGKW_VOLATILE 2169
#define PGKW_WHEN 2170
#define PGKW_WHERE 2171
#define PGKW_WITH 2172
#define PGKW_WITHOUT 2173
#define PGKW_WORK 2174
#define PGKW_WRITE 2175
#define PGKW_XCONST 2176
#define PGKW_YEAR_P 2177
#define PGKW_ZONE 2178
#define KW_TITLE 2179
#define KW_STYLE 2180
#define KW_ACTION 2181
#define KW_IDLE 2182
#define CANCEL_INSERT 2183
#define CANCEL_DELETE 2184
#define FORCE_UI 2185
#define FGL_MODULE 2186
#define VIA 2187
#define SLICE 2188
#define CURSOR_NAME_FUNCTION 2189
#define TIMESTAMP 2190
#define MOVE_TO_TOP 2191
#define LINETO_TOP 2192
#define KW_HEIGHT 2193
#define SET_STROKE_COLOR 2194
#define SET_FONT_SIZE 2195
#define SET_COLOR 2196
#define MOVE_TO 2197
#define FILL_STROKE 2198
#define STROKE 2199
#define LINE_TO 2200
#define SET_FONT_NAME 2201
#define BOOKMARK 2202
#define KW_FILL 2203
#define KW_WIDTH 2204
#define KWLINE 2205
#define ERRORHOOK 2206
#define KW_CAST 2207
#define CURR_FILE_NAME 2208
#define CURR_LINE_NO 2209
#define RIGHT_ALIGNED 2210
#define KW_TAG 2211
#define LINTMODULEISLIBRARY 2212
#define KW_PUBLIC 2213
#define KW_PRIVATE 2214
