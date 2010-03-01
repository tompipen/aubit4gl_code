struct s_kw {
    int id;
	   int mode;
    char *vals[20];
    char *name;
};
#define KW_DOC4GLCOMMENT 1000
#define WITH_LISTING_IN 1001
#define SET_CONSTRAINTS_ALL_DEFERRED 1002
#define KW_LIMIT 1003
#define DOCUMENT 1004
#define DEFINE_GLOBAL 1005
#define ON_EXCEPTION 1006
#define SET_DEBUG_FILE_TO 1007
#define TRACE_ON 1008
#define TRACE_OFF 1009
#define TRACE_PROCEDURE 1010
#define CREATE_PROCEDURE 1011
#define CREATE_DBA_PROCEDURE 1012
#define CREATE_FUNCTION 1013
#define CREATE_DBA_FUNCTION 1014
#define END_PROCEDURE 1015
#define USE_SESSION 1016
#define KW_RUN_CLIENT 1017
#define ON_CLOSE_APPLICATION_STOP 1018
#define LEFT_JOIN 1019
#define LINT_IGNORE 1020
#define LINT_EXPECT 1021
#define IGNORE_ERRORS 1022
#define SQLERRMESSAGE 1023
#define DISPLAY_NULL_TO 1024
#define UNBUFFERED 1025
#define KW_PICTURE 1026
#define ON_CHANGE 1027
#define INNER_JOIN 1028
#define DIALOGSETCURRLINE 1029
#define DIALOGKEYSETLABEL 1030
#define UI_INTERFACE_DOT_FRONTCALL 1031
#define UI_INTERFACE_DOT 1032
#define UI_WINDOW_DOT 1033
#define UIWINDOW 1034
#define UICOMBOBOX 1035
#define OMDOMNODE 1036
#define OMNODELIST 1037
#define UIFORM 1038
#define WITH_CONVERSIONS 1039
#define WITHOUT_CONVERSIONS 1040
#define BARCODE 1041
#define BARCODE_NO_TEXT 1042
#define BARCODETYPE 1043
#define BLUEBAR_COLOR_EQUAL 1044
#define BLUEBAR_STYLE_EQUAL_RECTANGLE_COLOR_EQUAL 1045
#define BLUEBAR_STYLE_EQUAL_RECTANGLE 1046
#define BLUEBAR_STYLE_EQUAL_LINE_COLOR_EQUAL 1047
#define BLUEBAR_STYLE_EQUAL_LINE 1048
#define BLUEBAR 1049
#define NOSQLCLOBBER 1050
#define NOCLOBBER 1051
#define ALWAYSSQLCLOBBER 1052
#define ALWAYSCLOBBER 1053
#define USING_BTREE 1054
#define USING_RTREE 1055
#define BASECHANNEL 1056
#define UI_DOT_FORM_DOT 1057
#define DIALOG_DOT 1058
#define STRING 1059
#define KW_COMMENT 1060
#define KW_IMAGE 1061
#define DEBUG_FILE 1062
#define RAISE_EXCEPTION 1063
#define WITH_HOLD_FOR 1064
#define WITH_RESUME 1065
#define END_EXCEPTION 1066
#define REFERENCES_BYTE 1067
#define ASCOPY 1068
#define REFERENCES_TEXT 1069
#define REPLACE_STRING 1070
#define STOP_REPLACE_STRING 1071
#define IGNORE_FUNCTION 1072
#define EMULATE_INSERT_CURSOR_FOR 1073
#define SET_BUFFERED_LOG 1074
#define SET_FILL_COLOR 1075
#define SET_PARAMETER 1076
#define SET_LOG 1077
#define PRAGMA 1078
#define MDY 1079
#define WEEKDAY 1080
#define SYSTEM_4GL 1081
#define SQL_FEATURE 1082
#define MODE_ANSI 1083
#define START_DATABASE 1084
#define WITH_LOG_IN 1085
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1086
#define CONVERTING_VIA 1087
#define CONVERTING_TO_PIPE 1088
#define CONVERTING_TO_FILE 1089
#define CONVERTING_TO_PRINTER 1090
#define CONVERTING_TO_EMAIL 1091
#define KW_CHANNEL_READ 1092
#define KW_CHANNEL_WRITE 1093
#define AS_CONVERTIBLE 1094
#define FREE_REPORT 1095
#define CONVERTING_TO_MANY 1096
#define CONVERTING_TO 1097
#define CONVERT_REPORT 1098
#define DATETIME_VALUE 1099
#define INTERVAL_VALUE 1100
#define RECOVER_TABLE 1101
#define ROLLFORWARD_DATABASE 1102
#define IN_LINE_MODE 1103
#define IN_FORM_MODE 1104
#define FGL_SIZEOF 1105
#define FGL_ADDRESSOF 1106
#define IMPORT_PACKAGE 1107
#define DYNAMIC_ARRAY 1108
#define RESIZE_ARRAY 1109
#define ALLOCATE_ARRAY 1110
#define DEALLOCATE_ARRAY 1111
#define AFTER_INSERT_DELETE 1112
#define BEFORE_INSERT_DELETE 1113
#define BEFORE_INSERT 1114
#define AS_CONVERTABLE 1115
#define CONCAT_PIPES 1116
#define BEFORE_DELETE 1117
#define DROP_TRIGGER 1118
#define DROP_AUDIT_FOR 1119
#define CREATE_AUDIT_FOR 1120
#define AFTER_INSERT 1121
#define AFTER_DELETE 1122
#define EXECUTE_IMMEDIATE 1123
#define EXECUTE_PROCEDURE 1124
#define DELETE_ROW_EQUAL_TRUE 1125
#define INSERT_ROW_EQUAL_TRUE 1126
#define DELETE_ROW_EQUAL_FALSE 1127
#define INSERT_ROW_EQUAL_FALSE 1128
#define CURRENT_ROW_DISPLAY_EQUAL 1129
#define MAXCOUNT 1130
#define ALTER_TABLE 1131
#define ALTER_INDEX 1132
#define NEXT_SIZE 1133
#define DISPLAY_ATTR_FORM 1134
#define DISPLAY_ATTR_WINDOW 1135
#define INPUT_ATTR_FORM 1136
#define INPUT_ATTR_WINDOW 1137
#define WHENEVER_ERROR_CONTINUE 1138
#define WHENEVER_ANY_ERROR_CONTINUE 1139
#define WHENEVER_WARNING_CONTINUE 1140
#define WHENEVER_SQLSUCCESS_CONTINUE 1141
#define WHENEVER_SQLWARNING_CONTINUE 1142
#define WHENEVER_NOT_FOUND_CONTINUE 1143
#define WHENEVER_SQLERROR_CONTINUE 1144
#define WHENEVER_SUCCESS_CONTINUE 1145
#define WHENEVER_ERROR_GOTO 1146
#define WHENEVER_ANY_ERROR_GOTO 1147
#define WHENEVER_WARNING_GOTO 1148
#define WHENEVER_SQLSUCCESS_GOTO 1149
#define WHENEVER_SQLWARNING_GOTO 1150
#define WHENEVER_NOT_FOUND_GOTO 1151
#define WHENEVER_SQLERROR_GOTO 1152
#define WHENEVER_SUCCESS_GOTO 1153
#define WHENEVER_ERROR_CALL 1154
#define WHENEVER_ANY_ERROR_CALL 1155
#define WHENEVER_WARNING_CALL 1156
#define WHENEVER_SQLSUCCESS_CALL 1157
#define WHENEVER_SQLWARNING_CALL 1158
#define WHENEVER_NOT_FOUND_CALL 1159
#define WHENEVER_SQLERROR_CALL 1160
#define WHENEVER_SUCCESS_CALL 1161
#define WHENEVER_ERROR_STOP 1162
#define WHENEVER_ANY_ERROR_STOP 1163
#define WHENEVER_WARNING_STOP 1164
#define WHENEVER_SQLSUCCESS_STOP 1165
#define WHENEVER_SQLWARNING_STOP 1166
#define WHENEVER_NOT_FOUND_STOP 1167
#define WHENEVER_SQLERROR_STOP 1168
#define WHENEVER_SUCCESS_STOP 1169
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1170
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1171
#define XSET_ident_DOT_MULTIPLY_EQUAL 1172
#define XSET_MULTIPLY_EQUAL 1173
#define XSET_OPEN_BRACKET 1174
#define NEWFORMATSHARED 1175
#define DEFINE_NEW_TYPE 1176
#define CREATE_DATABASE 1177
#define DROP_DATABASE 1178
#define IMPORT_LEGACY_FUNCTION 1179
#define ADD_CONSTRAINT 1180
#define DROP_CONSTRAINT 1181
#define DROP_SYNONYM 1182
#define CONSTRAINT 1183
#define AS_STATIC 1184
#define NOT_FIELD_TOUCHED 1185
#define NOT_FIELD_TOUCHED_CURRENT 1186
#define FIELD_TOUCHED_CURRENT 1187
#define LOCAL_FUNCTION 1188
#define LOCAL_REPORT 1189
#define LOCAL_PDF_REPORT 1190
#define EVERY_ROW 1191
#define ELIF 1192
#define KW_ARG_VAL 1193
#define DOUBLE_PRECISION 1194
#define COUNT_MULTIPLY 1195
#define WAIT_FOR_KEY 1196
#define AT_TERMINATION_CALL 1197
#define TERMINATE_REPORT 1198
#define TO_MAIN_CAPTION 1199
#define CLEARSTAT 1200
#define TO_MENUITEM 1201
#define ID_TO_INT 1202
#define TO_STATUSBOX 1203
#define ASCII_HEIGHT_ALL 1204
#define ASCII_WIDTH_ALL 1205
#define IMPORT_DATATYPE 1206
#define PAGE_TRAILER_SIZE 1207
#define PAGE_HEADER_SIZE 1208
#define FIRST_PAGE_HEADER_SIZE 1209
#define BYTES_USE_AS_IMAGE 1210
#define BYTES_USE_AS_ASCII 1211
#define KWUP_BY 1212
#define KWDOWN_BY 1213
#define CLOSE_STATUSBOX 1214
#define MODIFY_NEXT_SIZE 1215
#define LOCK_MODE_PAGE 1216
#define LOCK_MODE_ROW 1217
#define TO_PIPE 1218
#define TO_FILE 1219
#define TO_SCREEN 1220
#define TO_PRINTER 1221
#define TO_EMAIL 1222
#define STATUSBOX 1223
#define UNITS_YEAR 1224
#define UNITS_MONTH 1225
#define UNITS_DAY 1226
#define UNITS_HOUR 1227
#define UNITS_MINUTE 1228
#define UNITS_SECOND 1229
#define NO_NEW_LINES 1230
#define FIELDTOWIDGET 1231
#define WITH_HOLD 1232
#define SHOW_MENU 1233
#define TO_CLUSTER 1234
#define TO_NOT_CLUSTER 1235
#define CWIS 1236
#define CREATE_UC_IDX 1237
#define CREATE_U_IDX 1238
#define CREATE_C_IDX 1239
#define CREATE_IDX 1240
#define FORM_IS_COMPILED 1241
#define PDF_REPORT 1242
#define IMPORT_FUNCTION 1243
#define PROMPT_MANY 1244
#define KW_POINTS 1245
#define MM 1246
#define CM 1247
#define INCHES 1248
#define PREPEND 1249
#define DOUBLE_COLON 1250
#define USE_MEMBER_FUNCTION 1251
#define USE_MEMBER_OF 1252
#define APPEND 1253
#define TEMPLATE 1254
#define END_TEMPLATE 1255
#define SQLSICS 1256
#define CREATE_SCHEMA 1257
#define SQLSIRR 1258
#define UPDATESTATS_T 1259
#define SQLSICR 1260
#define WHENEVER_SQLSUCCESS 1261
#define WHENEVER_SQLWARNING 1262
#define WHENEVER_ANY_ERROR 1263
#define WHENEVER_NOT_FOUND 1264
#define WHENEVER_SQLERROR 1265
#define WHENEVER_SUCCESS 1266
#define WHENEVER_ERROR 1267
#define START_EXTERN 1268
#define CONTINUE_CONSTRUCT 1269
#define FOUNCONSTR 1270
#define SQLSIDR 1271
#define CREATE_TEMP_TABLE 1272
#define CURRENT_WINDOW_IS 1273
#define FIRST_PAGE_HEADER 1274
#define ORDER_EXTERNAL_BY 1275
#define SCROLL_CURSOR_FOR 1276
#define SCROLL_CURSOR 1277
#define SQL_INTERRUPT_OFF 1278
#define STOP_ALL_EXTERNAL 1279
#define WITH_CHECK_OPTION 1280
#define WITH_GRANT_OPTION 1281
#define SQLSLMNW 1282
#define ADDCONSTUNIQ 1283
#define CONTINUE_DISPLAY 1284
#define CONTINUE_FOREACH 1285
#define OUTPUT_TO_REPORT 1286
#define SQL_INTERRUPT_ON 1287
#define WHERE_CURRENT_OF 1288
#define WITHOUT_DEFAULTS 1289
#define FOCONSTR 1290
#define SCALED_BY 1291
#define CONTINUE_PROMPT 1292
#define PDF_FUNCTION 1293
#define DEFER_INTERRUPT 1294
#define DISPLAY_BY_NAME 1295
#define NOT_NULL_UNIQUE 1296
#define SKIP_TO_TOP 1297
#define TOP_OF_PAGE 1298
#define SKIP_TO 1299
#define SKIP_BY 1300
#define WITHOUT_WAITING 1301
#define BEFCONSTRUCT 1302
#define SQLSLMW 1303
#define AFTCONSTRUCT 1304
#define ALL_PRIVILEGES 1305
#define CLOSE_DATABASE 1306
#define CONTINUE_INPUT 1307
#define CONTINUE_WHILE 1308
#define CREATE_SYNONYM 1309
#define DROP_TABLE 1310
#define EXIT_CONSTRUCT 1311
#define INEXCLUSIVE 1312
#define REPORT_TO_PRINTER 1313
#define REPORT_TO_PIPE 1314
#define KW_RETURN 1315
#define SET_SESSION_TO 1316
#define UPDATESTATS 1317
#define WITHOUT_HEAD 1318
#define CLEARSCR 1319
#define WITH_B_LOG 1320
#define AUTHORIZATION 1321
#define BOTTOM_MARGIN 1322
#define CLOSE_SESSION 1323
#define CONTINUE_CASE 1324
#define CONTINUE_MENU 1325
#define DISPLAY_ARRAY 1326
#define END_SQL 1327
#define DOLLAR 1328
#define END_CONSTRUCT 1329
#define FIELD_TOUCHED 1330
#define FINISH_REPORT 1331
#define INFACC 1332
#define INPUT_NO_WRAP 1333
#define SETPMOFF 1334
#define UNCONSTRAINED 1335
#define PAGE_TRAILER 1336
#define SETPMON 1337
#define BEFGROUP 1338
#define CLOSE_WINDOW 1339
#define COMMENT_LINE 1340
#define CONTINUE_FOR 1341
#define CREATE_DB 1342
#define CREATE_TABLE 1343
#define DEFAULT_NULL 1344
#define DEFAULT_TODAY 1345
#define DEFAULT_USER 1346
#define DELETE_USING 1347
#define DISPLAY_FORM 1348
#define END_FUNCTION 1349
#define EXIT_DISPLAY 1350
#define EXIT_FOREACH 1351
#define EXIT_PROGRAM 1352
#define INFCOLS 1353
#define ON_EVERY_ROW 1354
#define OPEN_SESSION 1355
#define RIGHT_MARGIN 1356
#define SELECT_USING 1357
#define START_REPORT 1358
#define UNLOCK_TABLE 1359
#define UPDATE_USING 1360
#define ACL_BUILTIN 1361
#define AFTGROUP 1362
#define INFIDX 1363
#define INFSTAT 1364
#define LEFT_MARGIN 1365
#define PAGE_HEADER 1366
#define ROLLBACK_W 1367
#define SET_SESSION 1368
#define SQLSEON 1369
#define SQLSEOFF 1370
#define WITH_A_LOG 1371
#define BEFDISP 1372
#define BEFORE_MENU 1373
#define CREATE_VIEW 1374
#define DELETE_FROM 1375
#define END_DISPLAY 1376
#define END_REPORT 1377
#define END_FOREACH 1378
#define END_FOR 1379
#define END_GLOBALS 1380
#define EXIT_PROMPT 1381
#define EXTENT_SIZE 1382
#define FOREIGN_KEY 1383
#define HIDE_OPTION 1384
#define KW_HIDE_WINDOW 1385
#define INSERT_INTO 1386
#define IS_SERIAL 1387
#define IS_NOT_NULL 1388
#define MOVE_WINDOW 1389
#define NEXT_OPTION 1390
#define NOT_MATCHES 1391
#define ON_LAST_ROW 1392
#define OPEN_WINDOW 1393
#define OPEN_STATUSBOX 1394
#define PAGE_LENGTH 1395
#define PAGE_WIDTH 1396
#define PRIMARY_KEY 1397
#define PROMPT_LINE 1398
#define RECORD_LIKE 1399
#define ROLLFORWARD 1400
#define SHOW_OPTION 1401
#define SHOW_WINDOW 1402
#define TO_DATABASE 1403
#define WITH_NO_LOG 1404
#define AFTDISP 1405
#define BEFFIELD 1406
#define INSHARE 1407
#define UNLOCKTAB 1408
#define AFTFIELD 1409
#define ATTRIBUTES 1410
#define BEFINP 1411
#define BEFORE_DISPLAY 1412
#define BEGIN_WORK 1413
#define CLEARWIN 1414
#define CLOSE_FORM 1415
#define DEFER_QUIT 1416
#define DESCENDING 1417
#define DROP_INDEX 1418
#define END_PROMPT 1419
#define END_RECORD 1420
#define ERROR_LINE 1421
#define EXIT_INPUT 1422
#define EXIT_WHILE 1423
#define FOR_UPDATE_OF 1424
#define FOR_UPDATE 1425
#define GET_FLDBUF 1426
#define REFERENCE 1427
#define INITIALIZE 1428
#define INPUT_WRAP 1429
#define LOCK_TABLE 1430
#define MSG_LINE 1431
#define NOT_EXISTS 1432
#define ON_ANY_KEY 1433
#define REFERENCES 1434
#define RENCOL 1435
#define SET_CURSOR 1436
#define SMALLFLOAT 1437
#define SQLSUCCESS 1438
#define TOP_MARGIN 1439
#define WITH_ARRAY 1440
#define ACCEPTKEY 1441
#define KW_ACCEPT 1442
#define AFTINP 1443
#define AFTER_DISPLAY 1444
#define CLEARFORMTODEFAULTS 1445
#define CLEARFORM 1446
#define CLEAR_X_FORM 1447
#define COMMIT_W 1448
#define KW_NEXTPAGE 1449
#define KW_PREVPAGE 1450
#define KW_CTRL_KEY 1451
#define INFTABS 1452
#define NEXTFIELD 1453
#define NEXTFORM 1454
#define RENTAB 1455
#define ASCENDING 1456
#define ASSOCIATE 1457
#define KW_CHAR 1458
#define NCHAR 1459
#define NVARCHAR 1460
#define CONSTRUCT 1461
#define DELIMITER 1462
#define DOWNSHIFT 1463
#define DROP_VIEW 1464
#define END_INPUT 1465
#define END_WHILE 1466
#define EXCLUSIVE 1467
#define EXIT_CASE 1468
#define EXIT_MENU 1469
#define FORM_LINE 1470
#define GREATER_THAN_EQ 1471
#define KW_INTERRUPT 1472
#define INTO_TEMP 1473
#define INVISIBLE 1474
#define IN_MEMORY 1475
#define LINKED_TO 1476
#define LOAD_FROM 1477
#define LOCKTAB 1478
#define MENU_LINE 1479
#define OPEN_FORM 1480
#define OTHERWISE 1481
#define PRECISION 1482
#define KW_PRIOR 1483
#define PROCEDURE 1484
#define REPORT_TO 1485
#define RETURNING 1486
#define UNDERLINE 1487
#define UNLOAD_TO 1488
#define BEFROW 1489
#define UNLOAD_T 1490
#define VARIABLE 1491
#define KW_ABSOLUTE 1492
#define AFTROW 1493
#define BUFFERED 1494
#define KW_CONSTANT 1495
#define KW_CONST 1496
#define DATABASE 1497
#define DATETIME 1498
#define DEFAULTS 1499
#define DISTINCT 1500
#define END_CASE 1501
#define END_MAIN 1502
#define END_MENU 1503
#define END_TYPE 1504
#define EXIT_FOR 1505
#define EXTERNAL 1506
#define FRACTION 1507
#define FUNCTION 1508
#define GROUP_BY 1509
#define INTERVAL 1510
#define KWMESSAGE 1511
#define NOT_LIKE 1512
#define NOT_ILIKE 1513
#define NOT_NULL 1514
#define PASSWORD 1515
#define KW_PREVIOUS 1516
#define READONLY 1517
#define REGISTER 1518
#define KW_RELATIVE 1519
#define RESOURCE 1520
#define SMALLINT 1521
#define VALIDATE 1522
#define WITH_LOG 1523
#define KW_WORDWRAP 1524
#define BY_NAME 1525
#define IN_FILE 1526
#define IS_NULL 1527
#define LESS_THAN_EQ 1528
#define AVERAGE 1529
#define BETWEEN 1530
#define CAPTION 1531
#define KW_CLIPPED 1532
#define CLOSE_BRACKET 1533
#define COLUMNS 1534
#define COMMAND 1535
#define CONNECT 1536
#define KW_CURRENT 1537
#define DBYNAME 1538
#define KW_DECIMAL 1539
#define DECLARE 1540
#define DEFAULT 1541
#define KW_DISPLAY 1542
#define ENDCODE 1543
#define EXECUTE 1544
#define FOREACH 1545
#define FOREIGN 1546
#define GLOBALS 1547
#define INFIELD 1548
#define INTEGER 1549
#define INTEGER8 1550
#define SERIAL8 1551
#define KWWINDOW 1552
#define MAGENTA 1553
#define MATCHES 1554
#define OPTIONS 1555
#define PERCENT 1556
#define PREPARE 1557
#define PROGRAM 1558
#define RECOVER 1559
#define REVERSE 1560
#define SECTION 1561
#define SESSION 1562
#define SYNONYM 1563
#define THRU 1564
#define TRAILER 1565
#define UPSHIFT 1566
#define VARCHAR 1567
#define WAITING 1568
#define CLOSE_SHEV 1569
#define CLOSE_SQUARE 1570
#define GREATER_THAN 1571
#define KW_FALSE 1572
#define NOT_IN 1573
#define ONKEY 1574
#define OPEN_BRACKET 1575
#define BORDER 1576
#define BOTTOM 1577
#define COLUMN 1578
#define COMMIT 1579
#define CREATE 1580
#define CURSOR 1581
#define DEFINE 1582
#define KW_DELETE 1583
#define KW_DOUBLE 1584
#define END_IF 1585
#define KW_ESCAPE 1586
#define EXISTS 1587
#define EXTEND 1588
#define EXTENT 1589
#define FINISH 1590
#define FORMAT 1591
#define HAVING 1592
#define HEADER 1593
#define KW_INSERT 1594
#define LOCATE 1595
#define MARGIN 1596
#define MEMORY 1597
#define MINUTE 1598
#define MODIFY 1599
#define NORMAL 1600
#define EQUAL 1601
#define NOT_EQUAL 1602
#define OPEN_SHEV 1603
#define OPEN_SQUARE 1604
#define OPTION 1605
#define OUTPUT 1606
#define PROMPT 1607
#define PUBLIC 1608
#define RECORD 1609
#define REPORT 1610
#define KW_ENTER 1611
#define REVOKE 1612
#define SCHEMA 1613
#define SCROLL_USING 1614
#define SCROLL 1615
#define SECOND 1616
#define IDLE_SECONDS 1617
#define IDLE_MINUTES 1618
#define IDLE_HOURS 1619
#define KW_SELECT 1620
#define SERIAL 1621
#define SHARED 1622
#define KW_SPACES 1623
#define UNIQUE 1624
#define UNLOCK 1625
#define KW_UPDATE 1626
#define VALUES 1627
#define YELLOW 1628
#define AFTER 1629
#define KW_NULL 1630
#define KW_TRUE 1631
#define KW_SINGLE_KEY 1632
#define ALTER 1633
#define ARRAY 1634
#define KW_ASCII 1635
#define AUDIT 1636
#define BLACK 1637
#define BLINK 1638
#define CHECK 1639
#define CLEAR 1640
#define CLOSE 1641
#define CODE_C 1642
#define COUNT 1643
#define DEFER 1644
#define KW_ERROR 1645
#define EVERY 1646
#define FETCH 1647
#define KW_FIRST 1648
#define KW_FLOAT 1649
#define FLUSH 1650
#define FOUND 1651
#define GRANT 1652
#define GREEN 1653
#define KW_GROUP 1654
#define INDEX 1655
#define KWFORM 1656
#define LABEL 1657
#define LESS_THAN 1658
#define LOCAL 1659
#define MONEY 1660
#define MONTH 1661
#define KW_POWER 1662
#define KW_MULTIPLY 1663
#define ORDER 1664
#define OUTER 1665
#define PAUSE 1666
#define PRINT_IMAGE 1667
#define PRINT_FILE 1668
#define PRINT 1669
#define KW_RIGHT 1670
#define SEMICOLON 1671
#define SLEEP 1672
#define TUPLE 1673
#define UNION 1674
#define KW_USING_FILTER 1675
#define KW_USING 1676
#define WHERE 1677
#define WHILE 1678
#define WHITE 1679
#define CCODE 1680
#define ANSI 1681
#define BLUE 1682
#define BOLD 1683
#define KW_BYTE 1684
#define FCALL 1685
#define CASE 1686
#define CYAN 1687
#define KW_DATE 1688
#define DESC 1689
#define KW_DIVIDE 1690
#define KWDOWN 1691
#define KW_TAB 1692
#define DROP 1693
#define ELSE 1694
#define EXEC 1695
#define EXIT 1696
#define FREE 1697
#define FROM 1698
#define GOTO 1699
#define HELP_FILE 1700
#define LANG_FILE 1701
#define KW_HELP 1702
#define HIDE 1703
#define HOUR 1704
#define INTO 1705
#define KW_LAST 1706
#define KW_LEFT 1707
#define LIKE 1708
#define MAIN 1709
#define MENU 1710
#define MODE 1711
#define NEED 1712
#define KW_NEXT 1713
#define NOCR 1714
#define OPEN 1715
#define QUIT 1716
#define REAL 1717
#define ROWS 1718
#define SHOW 1719
#define KW_SIZE 1720
#define SKIP 1721
#define SOME 1722
#define STEP 1723
#define STOP 1724
#define TEMP 1725
#define KW_TEXT 1726
#define KW_THEN 1727
#define USER 1728
#define WAIT 1729
#define WHEN 1730
#define WITH 1731
#define WORK 1732
#define YEAR 1733
#define KW_DOW 1734
#define KW_IS 1735
#define XSET 1736
#define ADD 1737
#define ALL 1738
#define KW_AND 1739
#define ANY 1740
#define ASC 1741
#define AVG 1742
#define COLON 1743
#define KW_COMMA 1744
#define DAY 1745
#define DBA 1746
#define DEC 1747
#define DIM 1748
#define KW_FKEY 1749
#define KW_FOR 1750
#define KW_KEY 1751
#define KWNO 1752
#define KW_LET 1753
#define LOG 1754
#define XMAX 1755
#define XMIN 1756
#define KW_MINUS 1757
#define KW_MOD 1758
#define KW_NOT 1759
#define KW_PAD 1760
#define KW_PUT 1761
#define KW_RED 1762
#define KW_ROW 1763
#define KW_RUN 1764
#define KW_SQL 1765
#define KW_SUM 1766
#define KW_TOP 1767
#define KW_USE 1768
#define ATSIGN 1769
#define KW_PLUS 1770
#define AS_TIFF 1771
#define AS_GIF 1772
#define AS_PNG 1773
#define AS_JPEG 1774
#define KW_AS_USER 1775
#define KW_AS 1776
#define KW_AT 1777
#define KW_BY 1778
#define KW_DOT 1779
#define KW_GO 1780
#define KW_IF 1781
#define KW_IN 1782
#define KW_OF 1783
#define KW_ON 1784
#define KW_OR 1785
#define KW_TO 1786
#define KWUP 1787
#define FONT_NAME 1788
#define FONT_SIZE 1789
#define PAPER_SIZE_IS_LETTER 1790
#define PAPER_SIZE_IS_LEGAL 1791
#define PAPER_SIZE_IS_A5 1792
#define PAPER_SIZE_IS_A4 1793
#define PAPER_SIZE_IS_LETTER_L 1794
#define PAPER_SIZE_IS_LEGAL_L 1795
#define PAPER_SIZE_IS_A5_L 1796
#define PAPER_SIZE_IS_A4_L 1797
#define FORMHANDLER 1798
#define END_FORMHANDLER 1799
#define BEFORE_EVENT 1800
#define BEFORE_OPEN_FORM 1801
#define AFTER_EVENT 1802
#define BEFORE_CLOSE_FORM 1803
#define BEFORE_ANY 1804
#define AFTER_ANY 1805
#define MENUHANDLER 1806
#define END_MENUHANDLER 1807
#define BEFORE_SHOW_MENU 1808
#define DISABLE_PROGRAM 1809
#define DISABLE_ALL 1810
#define BUTTONS 1811
#define CHECK_MENUITEM 1812
#define DISABLE_FORM 1813
#define DISABLE_MENUITEMS 1814
#define DISABLE 1815
#define ENABLE_FORM 1816
#define ENABLE_MENUITEMS 1817
#define ENABLE 1818
#define KWFIELD 1819
#define ICON 1820
#define MESSAGEBOX 1821
#define TO_DEFAULTS 1822
#define UNCHECK_MENUITEM 1823
#define BEFORE 1824
#define KW_INPUT_ARRAY 1825
#define KW_INPUT 1826
#define FINPUT 1827
#define END 1828
#define INT_TO_ID 1829
#define TIMEOUT 1830
#define KW_OFF 1831
#define WITH_1_DIMENSION 1832
#define WITH_2_DIMENSION 1833
#define WITH_3_DIMENSION 1834
#define TILDE 1835
#define ILIKE 1836
#define FGL_ISDYNARR_ALLOCATED 1837
#define FGL_DYNARR_EXTENTSIZE 1838
#define FILLFACTOR 1839
#define END_CLASS 1840
#define KW_CLASS 1841
#define KW_EXTENDS 1842
#define KW_PIPE 1843
#define TIME 1844
#define KWBEGIN 1845
#define TRACE 1846
#define SITENAME 1847
#define DBSERVERNAME 1848
#define SYSTEM 1849
#define EXCEPTION 1850
#define KW_TODAY 1851
#define KW_ROWID 1852
#define PGKW_ABORT_P 1853
#define PGKW_ABSOLUTE_P 1854
#define PGKW_ACCESS 1855
#define PGKW_ACTION 1856
#define PGKW_ADD 1857
#define PGKW_AFTER 1858
#define PGKW_AGGREGATE 1859
#define PGKW_ALL 1860
#define PGKW_ALTER 1861
#define PGKW_ANALYSE 1862
#define PGKW_ANALYZE 1863
#define PGKW_AND 1864
#define PGKW_ANY 1865
#define PGKW_ARRAY 1866
#define PGKW_AS 1867
#define PGKW_ASC 1868
#define PGKW_ASSERTION 1869
#define PGKW_ASSIGNMENT 1870
#define PGKW_AT 1871
#define PGKW_AUTHORIZATION 1872
#define PGKW_BACKWARD 1873
#define PGKW_BCONST 1874
#define PGKW_BEFORE 1875
#define PGKW_BEGIN_P 1876
#define PGKW_BETWEEN 1877
#define PGKW_BIGINT 1878
#define PGKW_BINARY 1879
#define PGKW_BIT 1880
#define PGKW_BOOLEAN_P 1881
#define PGKW_BOTH 1882
#define PGKW_BY 1883
#define PGKW_CACHE 1884
#define PGKW_CALLED 1885
#define PGKW_CARAT 1886
#define PGKW_CASCADE 1887
#define PGKW_CASE 1888
#define PGKW_CAST 1889
#define PGKW_CHAIN 1890
#define PGKW_CHARACTER 1891
#define PGKW_CHARACTERISTICS 1892
#define PGKW_CHAR_P 1893
#define PGKW_CHECK 1894
#define PGKW_CHECKPOINT 1895
#define PGKW_CLASS 1896
#define PGKW_CLOSE 1897
#define PGKW_CLOSE_BRACKET 1898
#define PGKW_CLOSE_SQUARE 1899
#define PGKW_CLUSTER 1900
#define PGKW_COALESCE 1901
#define PGKW_COLLATE 1902
#define PGKW_COLON 1903
#define PGKW_COLUMN 1904
#define PGKW_COMMA 1905
#define PGKW_COMMENT 1906
#define PGKW_COMMIT 1907
#define PGKW_COMMITTED 1908
#define PGKW_CONSTRAINT 1909
#define PGKW_CONSTRAINTS 1910
#define PGKW_CONVERSION_P 1911
#define PGKW_CONVERT 1912
#define PGKW_COPY 1913
#define PGKW_CREATE 1914
#define PGKW_CREATEDB 1915
#define PGKW_CREATEUSER 1916
#define PGKW_CROSS 1917
#define PGKW_CURRENT 1918
#define PGKW_CURRENT_DATE 1919
#define PGKW_CURRENT_TIME 1920
#define PGKW_CURRENT_TIMESTAMP 1921
#define PGKW_CURRENT_USER 1922
#define PGKW_CURSOR 1923
#define PGKW_CYCLE 1924
#define PGKW_DATABASE 1925
#define PGKW_DATETIME 1926
#define PGKW_DAY_P 1927
#define PGKW_DBA 1928
#define PGKW_DEALLOCATE 1929
#define PGKW_DEC 1930
#define PGKW_DECIMAL_P 1931
#define PGKW_DECLARE 1932
#define PGKW_DEFAULT 1933
#define PGKW_DEFAULTS 1934
#define PGKW_DEFERRABLE 1935
#define PGKW_DEFERRED 1936
#define PGKW_DEFINER 1937
#define PGKW_DELETE_P 1938
#define PGKW_DELIMITER 1939
#define PGKW_DELIMITERS 1940
#define PGKW_DESC 1941
#define PGKW_DISTINCT 1942
#define PGKW_DIVIDE 1943
#define PGKW_DO 1944
#define PGKW_DOMAIN_P 1945
#define PGKW_DOT 1946
#define PGKW_DOUBLE_P 1947
#define PGKW_DROP 1948
#define PGKW_EACH 1949
#define PGKW_ELSE 1950
#define PGKW_ENCODING 1951
#define PGKW_ENCRYPTED 1952
#define PGKW_END_P 1953
#define PGKW_EQUAL 1954
#define PGKW_ESCAPE 1955
#define PGKW_EXCEPT 1956
#define PGKW_EXCLUDING 1957
#define PGKW_EXCLUSIVE 1958
#define PGKW_EXECUTE 1959
#define PGKW_EXISTS 1960
#define PGKW_EXPLAIN 1961
#define PGKW_EXTEND 1962
#define PGKW_EXTERNAL 1963
#define PGKW_EXTRACT 1964
#define PGKW_FALSE_P 1965
#define PGKW_FETCH 1966
#define PGKW_FIRST_P 1967
#define PGKW_FLOAT_P 1968
#define PGKW_FOR 1969
#define PGKW_FORCE 1970
#define PGKW_FOREIGN 1971
#define PGKW_FORWARD 1972
#define PGKW_FREEZE 1973
#define PGKW_FROM 1974
#define PGKW_FULL 1975
#define PGKW_FUNCTION 1976
#define PGKW_GLOBAL 1977
#define PGKW_GRANT 1978
#define PGKW_GREATER_THAN 1979
#define PGKW_GROUP_P 1980
#define PGKW_HANDLER 1981
#define PGKW_HAVING 1982
#define PGKW_HOLD 1983
#define PGKW_HOUR_P 1984
#define PGKW_ILIKE 1985
#define PGKW_IMMEDIATE 1986
#define PGKW_IMMUTABLE 1987
#define PGKW_IMPLICIT_P 1988
#define PGKW_INCLUDING 1989
#define PGKW_INCREMENT 1990
#define PGKW_INDEX 1991
#define PGKW_INHERITS 1992
#define PGKW_INITIALLY 1993
#define PGKW_INNER_P 1994
#define PGKW_INOUT 1995
#define PGKW_IN_P 1996
#define PGKW_INPUT_P 1997
#define PGKW_INSENSITIVE 1998
#define PGKW_INSERT 1999
#define PGKW_INSTEAD 2000
#define PGKW_INTEGER 2001
#define PGKW_INTERSECT 2002
#define PGKW_INTERVAL 2003
#define PGKW_INTO 2004
#define PGKW_INT_P 2005
#define PGKW_INVOKER 2006
#define PGKW_IS 2007
#define PGKW_ISNULL 2008
#define PGKW_ISOLATION 2009
#define PGKW_JOIN 2010
#define PGKW_KEY 2011
#define PGKW_LANCOMPILER 2012
#define PGKW_LANGUAGE 2013
#define PGKW_LAST_P 2014
#define PGKW_LEADING 2015
#define PGKW_LEFT 2016
#define PGKW_LESS_THAN 2017
#define PGKW_LEVEL 2018
#define PGKW_LIKE 2019
#define PGKW_LIMIT 2020
#define PGKW_LISTEN 2021
#define PGKW_LOAD 2022
#define PGKW_LOCAL 2023
#define PGKW_LOCALTIME 2024
#define PGKW_LOCALTIMESTAMP 2025
#define PGKW_LOCATION 2026
#define PGKW_LOCK_P 2027
#define PGKW_MATCH 2028
#define PGKW_MAXVALUE 2029
#define PGKW_MINUS 2030
#define PGKW_MINUTE_P 2031
#define PGKW_MINVALUE 2032
#define PGKW_MODE 2033
#define PGKW_MODIFY 2034
#define PGKW_MONTH_P 2035
#define PGKW_MOVE 2036
#define PGKW_NAMES 2037
#define PGKW_NATIONAL 2038
#define PGKW_NATURAL 2039
#define PGKW_NCHAR 2040
#define PGKW_NEW 2041
#define PGKW_NEXT 2042
#define PGKW_NO 2043
#define PGKW_NOCREATEDB 2044
#define PGKW_NOCREATEUSER 2045
#define PGKW_NONE 2046
#define PGKW_NOT 2047
#define PGKW_NOTHING 2048
#define PGKW_NOTIFY 2049
#define PGKW_NOTNULL 2050
#define PGKW_NULLIF 2051
#define PGKW_NULL_P 2052
#define PGKW_NUMERIC 2053
#define PGKW_OF 2054
#define PGKW_OFF 2055
#define PGKW_OFFSET 2056
#define PGKW_OIDS 2057
#define PGKW_OLD 2058
#define PGKW_ON 2059
#define PGKW_ONLY 2060
#define PGKW_OPEN_BRACKET 2061
#define PGKW_OPEN_SQUARE 2062
#define PGKW_OPERATOR 2063
#define PGKW_OPTION 2064
#define PGKW_OR 2065
#define PGKW_ORDER 2066
#define PGKW_OUTER_P 2067
#define PGKW_OUT_P 2068
#define PGKW_OVERLAPS 2069
#define PGKW_OVERLAY 2070
#define PGKW_OWNER 2071
#define PGKW_PARAM 2072
#define PGKW_PARTIAL 2073
#define PGKW_PASSWORD 2074
#define PGKW_PATH_P 2075
#define PGKW_PENDANT 2076
#define PGKW_PERCENT 2077
#define PGKW_PLACING 2078
#define PGKW_PLUS 2079
#define PGKW_POSITION 2080
#define PGKW_POSTFIXOP 2081
#define PGKW_PRECISION 2082
#define PGKW_PREPARE 2083
#define PGKW_PRESERVE 2084
#define PGKW_PRIMARY 2085
#define PGKW_PRIOR 2086
#define PGKW_PRIVILEGES 2087
#define PGKW_PROCEDURAL 2088
#define PGKW_PROCEDURE 2089
#define PGKW_READ 2090
#define PGKW_REAL 2091
#define PGKW_RECHECK 2092
#define PGKW_REFERENCES 2093
#define PGKW_REINDEX 2094
#define PGKW_RELATIVE_P 2095
#define PGKW_RENAME 2096
#define PGKW_REPLACE 2097
#define PGKW_RESET 2098
#define PGKW_RESTART 2099
#define PGKW_RESTRICT 2100
#define PGKW_RETURNS 2101
#define PGKW_REVOKE 2102
#define PGKW_RIGHT 2103
#define PGKW_ROLLBACK 2104
#define PGKW_ROW 2105
#define PGKW_ROWS 2106
#define PGKW_RULE 2107
#define PGKW_SCHEMA 2108
#define PGKW_SCROLL 2109
#define PGKW_SECOND_P 2110
#define PGKW_SECURITY 2111
#define PGKW_SELECT 2112
#define PGKW_SEMICOLON 2113
#define PGKW_SEQUENCE 2114
#define PGKW_SERIALIZABLE 2115
#define PGKW_SESSION 2116
#define PGKW_SESSION_USER 2117
#define PGKW_SET 2118
#define PGKW_SETOF 2119
#define PGKW_SHARE 2120
#define PGKW_SHOW 2121
#define PGKW_SIMILAR 2122
#define PGKW_SIMPLE 2123
#define PGKW_SMALLINT 2124
#define PGKW_SOME 2125
#define PGKW_STABLE 2126
#define PGKW_STAR 2127
#define PGKW_START 2128
#define PGKW_STATEMENT 2129
#define PGKW_STATISTICS 2130
#define PGKW_STDIN 2131
#define PGKW_STDOUT 2132
#define PGKW_STORAGE 2133
#define PGKW_STRICT_P 2134
#define PGKW_SUBSTRING 2135
#define PGKW_SYSID 2136
#define PGKW_TABLE 2137
#define PGKW_TEMP 2138
#define PGKW_TEMPLATE 2139
#define PGKW_TEMPORARY 2140
#define PGKW_THEN 2141
#define PGKW_TIME 2142
#define PGKW_TIMESTAMP 2143
#define PGKW_TO 2144
#define PGKW_TOAST 2145
#define PGKW_TODAY_SYN 2146
#define PGKW_TRAILING 2147
#define PGKW_TRANSACTION 2148
#define PGKW_TREAT 2149
#define PGKW_TRIGGER 2150
#define PGKW_TRIM 2151
#define PGKW_TRUE_P 2152
#define PGKW_TRUNCATE 2153
#define PGKW_TRUSTED 2154
#define PGKW_TYPECAST 2155
#define PGKW_TYPE_P 2156
#define PGKW_UMINUS 2157
#define PGKW_UNENCRYPTED 2158
#define PGKW_UNION 2159
#define PGKW_UNIONJOIN 2160
#define PGKW_UNIQUE 2161
#define PGKW_UNKNOWN 2162
#define PGKW_UNLISTEN 2163
#define PGKW_UNLOAD 2164
#define PGKW_UNTIL 2165
#define PGKW_UPDATE 2166
#define PGKW_USAGE 2167
#define PGKW_USER 2168
#define PGKW_USING 2169
#define PGKW_VACUUM 2170
#define PGKW_VALID 2171
#define PGKW_VALIDATOR 2172
#define PGKW_VALUES 2173
#define PGKW_VARCHAR 2174
#define PGKW_VARYING 2175
#define PGKW_VERBOSE 2176
#define PGKW_VERSION 2177
#define PGKW_VIEW 2178
#define PGKW_VOLATILE 2179
#define PGKW_WHEN 2180
#define PGKW_WHERE 2181
#define PGKW_WITH 2182
#define PGKW_WITHOUT 2183
#define PGKW_WORK 2184
#define PGKW_WRITE 2185
#define PGKW_XCONST 2186
#define PGKW_YEAR_P 2187
#define PGKW_ZONE 2188
#define KW_TITLE 2189
#define KW_STYLE 2190
#define KW_ACTION 2191
#define KW_IDLE 2192
#define CANCEL_INSERT 2193
#define CANCEL_DELETE 2194
#define FORCE_UI 2195
#define FGL_MODULE 2196
#define VIA 2197
#define SLICE 2198
#define CURSOR_NAME_FUNCTION 2199
#define TIMESTAMP 2200
#define MOVE_TO_TOP 2201
#define LINETO_TOP 2202
#define KW_HEIGHT 2203
#define SET_STROKE_COLOR 2204
#define SET_FONT_SIZE 2205
#define SET_COLOR 2206
#define MOVE_TO 2207
#define FILL_STROKE 2208
#define STROKE 2209
#define LINE_TO 2210
#define SET_FONT_NAME 2211
#define BOOKMARK 2212
#define KW_FILL 2213
#define KW_WIDTH 2214
#define KWLINE 2215
#define ERRORHOOK 2216
#define KW_CAST 2217
#define CURR_FILE_NAME 2218
#define CURR_LINE_NO 2219
#define RIGHT_ALIGNED 2220
#define KW_TAG 2221
#define LINTMODULEISLIBRARY 2222
#define KW_PUBLIC 2223
#define KW_PRIVATE 2224
#define COPYBACK 2225
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2226
#define REFERENCES_BLOBTYPE 2227
#define SORT 2228
