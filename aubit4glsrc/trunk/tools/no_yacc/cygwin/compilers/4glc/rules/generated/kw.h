struct s_kw {
    int id;
	   int mode;
    char *vals[20];
    char *name;
};
#define ON_CLOSE_APPLICATION_STOP 1000
#define DIALOGSETCURRLINE 1001
#define DIALOGKEYSETLABEL 1002
#define UI_INTERFACE_DOT 1003
#define UI_WINDOW_DOT 1004
#define UIWINDOW 1005
#define OMDOMNODE 1006
#define OMNODELIST 1007
#define BASECHANNEL 1008
#define UI_DOT_FORM_DOT 1009
#define DIALOG_DOT 1010
#define STRING 1011
#define KW_COMMENT 1012
#define KW_IMAGE 1013
#define DEBUG_FILE 1014
#define TRACE_PROCEDURE 1015
#define RAISE_EXCEPTION 1016
#define WITH_HOLD_FOR 1017
#define CREATE_PROCEDURE 1018
#define WITH_RESUME 1019
#define TRACE_ON 1020
#define END_PROCEDURE 1021
#define END_EXCEPTION 1022
#define REFERENCES_BYTE 1023
#define REFERENCES_TEXT 1024
#define TRACE_OFF 1025
#define REPLACE_STRING 1026
#define STOP_REPLACE_STRING 1027
#define IGNORE_FUNCTION 1028
#define EMULATE_INSERT_CURSOR_FOR 1029
#define DEFINE_GLOBAL 1030
#define SET_BUFFERED_LOG 1031
#define SET_LOG 1032
#define PRAGMA 1033
#define MDY 1034
#define WEEKDAY 1035
#define SYSTEM_4GL 1036
#define SQL_FEATURE 1037
#define MISC_INFX_SQL 1038
#define CONVERTING_VIA 1039
#define CONVERTING_TO_PIPE 1040
#define CONVERTING_TO_FILE 1041
#define CONVERTING_TO_PRINTER 1042
#define CONVERTING_TO_EMAIL 1043
#define KW_CHANNEL_READ 1044
#define KW_CHANNEL_WRITE 1045
#define AS_CONVERTIBLE 1046
#define FREE_REPORT 1047
#define CONVERTING_TO_MANY 1048
#define CONVERTING_TO 1049
#define CONVERT_REPORT 1050
#define DATETIME_VALUE 1051
#define INTERVAL_VALUE 1052
#define RECOVER_TABLE 1053
#define ROLLFORWARD_DATABASE 1054
#define IN_LINE_MODE 1055
#define IN_FORM_MODE 1056
#define FGL_SIZEOF 1057
#define FGL_ADDRESSOF 1058
#define IMPORT_PACKAGE 1059
#define DYNAMIC_ARRAY 1060
#define RESIZE_ARRAY 1061
#define ALLOCATE_ARRAY 1062
#define DEALLOCATE_ARRAY 1063
#define AFTER_INSERT_DELETE 1064
#define BEFORE_INSERT_DELETE 1065
#define BEFORE_INSERT 1066
#define AS_CONVERTABLE 1067
#define CONCAT_PIPES 1068
#define BEFORE_DELETE 1069
#define DROP_TRIGGER 1070
#define DROP_AUDIT_FOR 1071
#define CREATE_AUDIT_FOR 1072
#define AFTER_INSERT 1073
#define AFTER_DELETE 1074
#define EXECUTE_IMMEDIATE 1075
#define EXECUTE_PROCEDURE 1076
#define DELETE_ROW_EQUAL_TRUE 1077
#define INSERT_ROW_EQUAL_TRUE 1078
#define DELETE_ROW_EQUAL_FALSE 1079
#define INSERT_ROW_EQUAL_FALSE 1080
#define CURRENT_ROW_DISPLAY_EQUAL 1081
#define MAXCOUNT 1082
#define ALTER_TABLE 1083
#define ALTER_INDEX 1084
#define NEXT_SIZE 1085
#define DISPLAY_ATTR_FORM 1086
#define DISPLAY_ATTR_WINDOW 1087
#define INPUT_ATTR_FORM 1088
#define INPUT_ATTR_WINDOW 1089
#define WHENEVER_ERROR_CONTINUE 1090
#define WHENEVER_ANY_ERROR_CONTINUE 1091
#define WHENEVER_WARNING_CONTINUE 1092
#define WHENEVER_SQLSUCCESS_CONTINUE 1093
#define WHENEVER_SQLWARNING_CONTINUE 1094
#define WHENEVER_NOT_FOUND_CONTINUE 1095
#define WHENEVER_SQLERROR_CONTINUE 1096
#define WHENEVER_SUCCESS_CONTINUE 1097
#define WHENEVER_ERROR_GOTO 1098
#define WHENEVER_ANY_ERROR_GOTO 1099
#define WHENEVER_WARNING_GOTO 1100
#define WHENEVER_SQLSUCCESS_GOTO 1101
#define WHENEVER_SQLWARNING_GOTO 1102
#define WHENEVER_NOT_FOUND_GOTO 1103
#define WHENEVER_SQLERROR_GOTO 1104
#define WHENEVER_SUCCESS_GOTO 1105
#define WHENEVER_ERROR_CALL 1106
#define WHENEVER_ANY_ERROR_CALL 1107
#define WHENEVER_WARNING_CALL 1108
#define WHENEVER_SQLSUCCESS_CALL 1109
#define WHENEVER_SQLWARNING_CALL 1110
#define WHENEVER_NOT_FOUND_CALL 1111
#define WHENEVER_SQLERROR_CALL 1112
#define WHENEVER_SUCCESS_CALL 1113
#define WHENEVER_ERROR_STOP 1114
#define WHENEVER_ANY_ERROR_STOP 1115
#define WHENEVER_WARNING_STOP 1116
#define WHENEVER_SQLSUCCESS_STOP 1117
#define WHENEVER_SQLWARNING_STOP 1118
#define WHENEVER_NOT_FOUND_STOP 1119
#define WHENEVER_SQLERROR_STOP 1120
#define WHENEVER_SUCCESS_STOP 1121
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1122
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1123
#define XSET_ident_DOT_MULTIPLY_EQUAL 1124
#define XSET_MULTIPLY_EQUAL 1125
#define XSET_OPEN_BRACKET 1126
#define NEWFORMATSHARED 1127
#define DEFINE_NEW_TYPE 1128
#define CREATE_DATABASE 1129
#define DROP_DATABASE 1130
#define IMPORT_LEGACY_FUNCTION 1131
#define ADD_CONSTRAINT 1132
#define DROP_CONSTRAINT 1133
#define DROP_SYNONYM 1134
#define CONSTRAINT 1135
#define AS_STATIC 1136
#define NOT_FIELD_TOUCHED 1137
#define LOCAL_FUNCTION 1138
#define EVERY_ROW 1139
#define ELIF 1140
#define KW_ARG_VAL 1141
#define DOUBLE_PRECISION 1142
#define COUNT_MULTIPLY 1143
#define WAIT_FOR_KEY 1144
#define AT_TERMINATION_CALL 1145
#define TERMINATE_REPORT 1146
#define TO_MAIN_CAPTION 1147
#define CLEARSTAT 1148
#define TO_MENUITEM 1149
#define ID_TO_INT 1150
#define TO_STATUSBOX 1151
#define ASCII_HEIGHT_ALL 1152
#define ASCII_WIDTH_ALL 1153
#define IMPORT_DATATYPE 1154
#define PAGE_TRAILER_SIZE 1155
#define PAGE_HEADER_SIZE 1156
#define FIRST_PAGE_HEADER_SIZE 1157
#define BYTES_USE_AS_IMAGE 1158
#define BYTES_USE_AS_ASCII 1159
#define KWUP_BY 1160
#define KWDOWN_BY 1161
#define CLOSE_STATUSBOX 1162
#define MODIFY_NEXT_SIZE 1163
#define LOCK_MODE_PAGE 1164
#define LOCK_MODE_ROW 1165
#define TO_PIPE 1166
#define TO_FILE 1167
#define TO_SCREEN 1168
#define TO_PRINTER 1169
#define TO_EMAIL 1170
#define STATUSBOX 1171
#define UNITS_YEAR 1172
#define UNITS_MONTH 1173
#define UNITS_DAY 1174
#define UNITS_HOUR 1175
#define UNITS_MINUTE 1176
#define UNITS_SECOND 1177
#define NO_NEW_LINES 1178
#define FIELDTOWIDGET 1179
#define WITH_HOLD 1180
#define SHOW_MENU 1181
#define TO_CLUSTER 1182
#define TO_NOT_CLUSTER 1183
#define CWIS 1184
#define CREATE_UC_IDX 1185
#define CREATE_U_IDX 1186
#define CREATE_C_IDX 1187
#define CREATE_IDX 1188
#define FORM_IS_COMPILED 1189
#define PDF_REPORT 1190
#define IMPORT_FUNCTION 1191
#define PROMPT_MANY 1192
#define KW_POINTS 1193
#define MM 1194
#define INCHES 1195
#define PREPEND 1196
#define DOUBLE_COLON 1197
#define USE_MEMBER_FUNCTION 1198
#define USE_MEMBER_OF 1199
#define APPEND 1200
#define TEMPLATE 1201
#define END_TEMPLATE 1202
#define SQLSICS 1203
#define CREATE_SCHEMA 1204
#define SQLSIRR 1205
#define UPDATESTATS_T 1206
#define SQLSICR 1207
#define WHENEVER_SQLSUCCESS 1208
#define WHENEVER_SQLWARNING 1209
#define WHENEVER_ANY_ERROR 1210
#define WHENEVER_NOT_FOUND 1211
#define WHENEVER_SQLERROR 1212
#define WHENEVER_SUCCESS 1213
#define WHENEVER_ERROR 1214
#define START_EXTERN 1215
#define CONTINUE_CONSTRUCT 1216
#define FOUNCONSTR 1217
#define SQLSIDR 1218
#define CREATE_TEMP_TABLE 1219
#define CURRENT_WINDOW_IS 1220
#define FIRST_PAGE_HEADER 1221
#define ORDER_EXTERNAL_BY 1222
#define SCROLL_CURSOR_FOR 1223
#define SCROLL_CURSOR 1224
#define SQL_INTERRUPT_OFF 1225
#define STOP_ALL_EXTERNAL 1226
#define WITH_CHECK_OPTION 1227
#define WITH_GRANT_OPTION 1228
#define SQLSLMNW 1229
#define ADDCONSTUNIQ 1230
#define CONTINUE_DISPLAY 1231
#define CONTINUE_FOREACH 1232
#define OUTPUT_TO_REPORT 1233
#define SQL_INTERRUPT_ON 1234
#define WHERE_CURRENT_OF 1235
#define WITHOUT_DEFAULTS 1236
#define FOCONSTR 1237
#define SCALED_BY 1238
#define CONTINUE_PROMPT 1239
#define PDF_FUNCTION 1240
#define DEFER_INTERRUPT 1241
#define DISPLAY_BY_NAME 1242
#define NOT_NULL_UNIQUE 1243
#define SKIP_TO_TOP 1244
#define TOP_OF_PAGE 1245
#define SKIP_TO 1246
#define SKIP_BY 1247
#define WITHOUT_WAITING 1248
#define BEFCONSTRUCT 1249
#define SQLSLMW 1250
#define AFTCONSTRUCT 1251
#define ALL_PRIVILEGES 1252
#define CLOSE_DATABASE 1253
#define CONTINUE_INPUT 1254
#define CONTINUE_WHILE 1255
#define CREATE_SYNONYM 1256
#define DROP_TABLE 1257
#define EXIT_CONSTRUCT 1258
#define INEXCLUSIVE 1259
#define REPORT_TO_PRINTER 1260
#define REPORT_TO_PIPE 1261
#define KW_RETURN 1262
#define SET_SESSION_TO 1263
#define UPDATESTATS 1264
#define WITHOUT_HEAD 1265
#define CLEARSCR 1266
#define WITH_B_LOG 1267
#define AUTHORIZATION 1268
#define BOTTOM_MARGIN 1269
#define CLOSE_SESSION 1270
#define CONTINUE_CASE 1271
#define CONTINUE_MENU 1272
#define DISPLAY_ARRAY 1273
#define END_SQL 1274
#define DOLLAR 1275
#define END_CONSTRUCT 1276
#define FIELD_TOUCHED 1277
#define FINISH_REPORT 1278
#define INFACC 1279
#define INPUT_NO_WRAP 1280
#define SETPMOFF 1281
#define UNCONSTRAINED 1282
#define PAGE_TRAILER 1283
#define SETPMON 1284
#define BEFGROUP 1285
#define CLOSE_WINDOW 1286
#define COMMENT_LINE 1287
#define CONTINUE_FOR 1288
#define CREATE_DB 1289
#define CREATE_TABLE 1290
#define DEFAULT_NULL 1291
#define DEFAULT_TODAY 1292
#define DEFAULT_USER 1293
#define DELETE_USING 1294
#define DISPLAY_FORM 1295
#define END_FUNCTION 1296
#define EXIT_DISPLAY 1297
#define EXIT_FOREACH 1298
#define EXIT_PROGRAM 1299
#define INFCOLS 1300
#define ON_EVERY_ROW 1301
#define OPEN_SESSION 1302
#define RIGHT_MARGIN 1303
#define SELECT_USING 1304
#define START_REPORT 1305
#define UNLOCK_TABLE 1306
#define UPDATE_USING 1307
#define ACL_BUILTIN 1308
#define AFTGROUP 1309
#define INFIDX 1310
#define INFSTAT 1311
#define LEFT_MARGIN 1312
#define PAGE_HEADER 1313
#define ROLLBACK_W 1314
#define SET_SESSION 1315
#define SQLSEON 1316
#define SQLSEOFF 1317
#define WITH_A_LOG 1318
#define BEFDISP 1319
#define BEFORE_MENU 1320
#define CREATE_VIEW 1321
#define DELETE_FROM 1322
#define END_DISPLAY 1323
#define END_REPORT 1324
#define END_FOREACH 1325
#define END_FOR 1326
#define END_GLOBALS 1327
#define EXIT_PROMPT 1328
#define EXTENT_SIZE 1329
#define FOREIGN_KEY 1330
#define HIDE_OPTION 1331
#define KW_HIDE_WINDOW 1332
#define INSERT_INTO 1333
#define IS_SERIAL 1334
#define IS_NOT_NULL 1335
#define MOVE_WINDOW 1336
#define NEXT_OPTION 1337
#define NOT_MATCHES 1338
#define ON_LAST_ROW 1339
#define OPEN_WINDOW 1340
#define OPEN_STATUSBOX 1341
#define PAGE_LENGTH 1342
#define PAGE_WIDTH 1343
#define PRIMARY_KEY 1344
#define PROMPT_LINE 1345
#define RECORD_LIKE 1346
#define ROLLFORWARD 1347
#define SHOW_OPTION 1348
#define SHOW_WINDOW 1349
#define TO_DATABASE 1350
#define USE_SESSION 1351
#define WITH_NO_LOG 1352
#define AFTDISP 1353
#define BEFFIELD 1354
#define INSHARE 1355
#define UNLOCKTAB 1356
#define AFTFIELD 1357
#define ATTRIBUTES 1358
#define BEFINP 1359
#define BEFORE_DISPLAY 1360
#define BEGIN_WORK 1361
#define CLEARWIN 1362
#define CLOSE_FORM 1363
#define DEFER_QUIT 1364
#define DESCENDING 1365
#define DROP_INDEX 1366
#define END_PROMPT 1367
#define END_RECORD 1368
#define ERROR_LINE 1369
#define EXIT_INPUT 1370
#define EXIT_WHILE 1371
#define FOR_UPDATE_OF 1372
#define FOR_UPDATE 1373
#define GET_FLDBUF 1374
#define INITIALIZE 1375
#define INPUT_WRAP 1376
#define LOCK_TABLE 1377
#define MSG_LINE 1378
#define NOT_EXISTS 1379
#define ON_ANY_KEY 1380
#define REFERENCES 1381
#define RENCOL 1382
#define SET_CURSOR 1383
#define SMALLFLOAT 1384
#define SQLSUCCESS 1385
#define TOP_MARGIN 1386
#define WITH_ARRAY 1387
#define ACCEPTKEY 1388
#define KW_ACCEPT 1389
#define AFTINP 1390
#define AFTER_DISPLAY 1391
#define CLEARFORMTODEFAULTS 1392
#define CLEARFORM 1393
#define CLEAR_X_FORM 1394
#define COMMIT_W 1395
#define KW_NEXTPAGE 1396
#define KW_PREVPAGE 1397
#define KW_CTRL_KEY 1398
#define INFTABS 1399
#define NEXTFIELD 1400
#define NEXTFORM 1401
#define RENTAB 1402
#define ASCENDING 1403
#define ASSOCIATE 1404
#define KW_CHAR 1405
#define NCHAR 1406
#define NVARCHAR 1407
#define CONSTRUCT 1408
#define DELIMITER 1409
#define DOWNSHIFT 1410
#define DROP_VIEW 1411
#define END_INPUT 1412
#define END_WHILE 1413
#define EXCLUSIVE 1414
#define EXIT_CASE 1415
#define EXIT_MENU 1416
#define FORM_LINE 1417
#define GREATER_THAN_EQ 1418
#define KW_INTERRUPT 1419
#define INTO_TEMP 1420
#define INVISIBLE 1421
#define IN_MEMORY 1422
#define LINKED_TO 1423
#define LOAD_FROM 1424
#define LOCKTAB 1425
#define MENU_LINE 1426
#define OPEN_FORM 1427
#define OTHERWISE 1428
#define PRECISION 1429
#define KW_PRIOR 1430
#define PROCEDURE 1431
#define REPORT_TO 1432
#define RETURNING 1433
#define UNDERLINE 1434
#define UNLOAD_TO 1435
#define BEFROW 1436
#define UNLOAD_T 1437
#define VARIABLE_ATTRIBUTES 1438
#define VARIABLE 1439
#define KW_ABSOLUTE 1440
#define AFTROW 1441
#define BUFFERED 1442
#define KW_CONSTANT 1443
#define KW_CONST 1444
#define DATABASE 1445
#define DATETIME 1446
#define DEFAULTS 1447
#define DISTINCT 1448
#define END_CASE 1449
#define END_MAIN 1450
#define END_MENU 1451
#define END_TYPE 1452
#define EXIT_FOR 1453
#define EXTERNAL 1454
#define FRACTION 1455
#define FUNCTION 1456
#define GROUP_BY 1457
#define INTERVAL 1458
#define KWMESSAGE 1459
#define NOT_LIKE 1460
#define NOT_ILIKE 1461
#define NOT_NULL 1462
#define PASSWORD 1463
#define KW_PREVIOUS 1464
#define READONLY 1465
#define REGISTER 1466
#define KW_RELATIVE 1467
#define RESOURCE 1468
#define SMALLINT 1469
#define VALIDATE 1470
#define WITH_LOG 1471
#define KW_WORDWRAP 1472
#define BY_NAME 1473
#define IN_FILE 1474
#define IS_NULL 1475
#define LESS_THAN_EQ 1476
#define AVERAGE 1477
#define BETWEEN 1478
#define CAPTION 1479
#define KW_CLIPPED 1480
#define CLOSE_BRACKET 1481
#define COLUMNS 1482
#define COMMAND 1483
#define CONNECT 1484
#define KW_CURRENT 1485
#define DBYNAME 1486
#define KW_DECIMAL 1487
#define DECLARE 1488
#define DEFAULT 1489
#define KW_DISPLAY 1490
#define ENDCODE 1491
#define EXECUTE 1492
#define FOREACH 1493
#define FOREIGN 1494
#define GLOBALS 1495
#define INFIELD 1496
#define INTEGER 1497
#define KWWINDOW 1498
#define MAGENTA 1499
#define MATCHES 1500
#define OPTIONS 1501
#define PERCENT 1502
#define PREPARE 1503
#define PROGRAM 1504
#define RECOVER 1505
#define REVERSE 1506
#define SECTION 1507
#define SESSION 1508
#define SYNONYM 1509
#define THRU 1510
#define TRAILER 1511
#define UPSHIFT 1512
#define VARCHAR 1513
#define WAITING 1514
#define CLOSE_SHEV 1515
#define CLOSE_SQUARE 1516
#define GREATER_THAN 1517
#define KW_FALSE 1518
#define NOT_IN 1519
#define ONKEY 1520
#define OPEN_BRACKET 1521
#define BORDER 1522
#define BOTTOM 1523
#define COLUMN 1524
#define COMMIT 1525
#define CREATE 1526
#define CURSOR 1527
#define DEFINE 1528
#define KW_DELETE 1529
#define KW_DOUBLE 1530
#define END_IF 1531
#define KW_ESCAPE 1532
#define EXISTS 1533
#define EXTEND 1534
#define EXTENT 1535
#define FINISH 1536
#define FORMAT 1537
#define HAVING 1538
#define HEADER 1539
#define KW_INSERT 1540
#define LOCATE 1541
#define MARGIN 1542
#define MEMORY 1543
#define MINUTE 1544
#define MODIFY 1545
#define NORMAL 1546
#define EQUAL 1547
#define NOT_EQUAL 1548
#define OPEN_SHEV 1549
#define OPEN_SQUARE 1550
#define OPTION 1551
#define OUTPUT 1552
#define PROMPT 1553
#define PUBLIC 1554
#define RECORD 1555
#define REPORT 1556
#define REVOKE 1557
#define SCHEMA 1558
#define SCROLL_USING 1559
#define SCROLL 1560
#define SECOND 1561
#define IDLE_SECONDS 1562
#define IDLE_MINUTES 1563
#define IDLE_HOURS 1564
#define KW_SELECT 1565
#define SERIAL 1566
#define SHARED 1567
#define KW_SPACES 1568
#define UNIQUE 1569
#define UNLOCK 1570
#define KW_UPDATE 1571
#define VALUES 1572
#define YELLOW 1573
#define AFTER 1574
#define KWLINE 1575
#define KW_NULL 1576
#define KW_TRUE 1577
#define KW_SINGLE_KEY 1578
#define ALTER 1579
#define ARRAY 1580
#define KW_ASCII 1581
#define AUDIT 1582
#define BLACK 1583
#define BLINK 1584
#define CHECK 1585
#define CLEAR 1586
#define CLOSE 1587
#define CODE_C 1588
#define COUNT 1589
#define DEFER 1590
#define KW_ERROR 1591
#define EVERY 1592
#define FETCH 1593
#define KW_FIRST 1594
#define KW_FLOAT 1595
#define FLUSH 1596
#define FOUND 1597
#define GRANT 1598
#define GREEN 1599
#define KW_GROUP 1600
#define INDEX 1601
#define KWFORM 1602
#define LABEL 1603
#define LESS_THAN 1604
#define LOCAL 1605
#define MONEY 1606
#define MONTH 1607
#define KW_POWER 1608
#define KW_MULTIPLY 1609
#define ORDER 1610
#define OUTER 1611
#define PAUSE 1612
#define PRINT_IMAGE 1613
#define PRINT_FILE 1614
#define PRINT 1615
#define KW_RIGHT 1616
#define SEMICOLON 1617
#define SLEEP 1618
#define TUPLE 1619
#define UNION 1620
#define KW_USING 1621
#define WHERE 1622
#define WHILE 1623
#define WHITE 1624
#define CCODE 1625
#define ANSI 1626
#define BLUE 1627
#define BOLD 1628
#define KW_BYTE 1629
#define FCALL 1630
#define CASE 1631
#define CYAN 1632
#define KW_DATE 1633
#define DESC 1634
#define KW_DIVIDE 1635
#define KWDOWN 1636
#define KW_TAB 1637
#define DROP 1638
#define ELSE 1639
#define EXEC 1640
#define EXIT 1641
#define FREE 1642
#define FROM 1643
#define GOTO 1644
#define HELP_FILE 1645
#define LANG_FILE 1646
#define KW_HELP 1647
#define HIDE 1648
#define HOUR 1649
#define INTO 1650
#define KW_LAST 1651
#define KW_LEFT 1652
#define LIKE 1653
#define MAIN 1654
#define MENU 1655
#define MODE 1656
#define NEED 1657
#define KW_NEXT 1658
#define NOCR 1659
#define OPEN 1660
#define QUIT 1661
#define REAL 1662
#define ROWS 1663
#define SHOW 1664
#define KW_SIZE 1665
#define SKIP 1666
#define SOME 1667
#define STEP 1668
#define STOP 1669
#define TEMP 1670
#define KW_TEXT 1671
#define KW_THEN 1672
#define USER 1673
#define WAIT 1674
#define WHEN 1675
#define WITH 1676
#define WORK 1677
#define YEAR 1678
#define KW_DOW 1679
#define KW_IS 1680
#define XSET 1681
#define ADD 1682
#define ALL 1683
#define KW_AND 1684
#define ANY 1685
#define ASC 1686
#define AVG 1687
#define COLON 1688
#define KW_COMMA 1689
#define DAY 1690
#define DBA 1691
#define DEC 1692
#define DIM 1693
#define KW_FKEY 1694
#define KW_FOR 1695
#define KW_KEY 1696
#define KWNO 1697
#define KW_LET 1698
#define LOG 1699
#define XMAX 1700
#define XMIN 1701
#define KW_MINUS 1702
#define KW_MOD 1703
#define KW_NOT 1704
#define KW_PAD 1705
#define KW_PUT 1706
#define KW_RED 1707
#define KW_ROW 1708
#define KW_RUN 1709
#define KW_SQL 1710
#define KW_SUM 1711
#define KW_TOP 1712
#define KW_USE 1713
#define ATSIGN 1714
#define KW_PLUS 1715
#define AS_TIFF 1716
#define AS_GIF 1717
#define AS_PNG 1718
#define AS_JPEG 1719
#define KW_AS 1720
#define KW_AT 1721
#define KW_BY 1722
#define KW_DOT 1723
#define KW_GO 1724
#define KW_IF 1725
#define KW_IN 1726
#define KW_OF 1727
#define KW_ON 1728
#define KW_OR 1729
#define KW_TO 1730
#define KWUP 1731
#define FONT_NAME 1732
#define FONT_SIZE 1733
#define PAPER_SIZE_IS_LETTER 1734
#define PAPER_SIZE_IS_LEGAL 1735
#define PAPER_SIZE_IS_A5 1736
#define PAPER_SIZE_IS_A4 1737
#define PAPER_SIZE_IS_LETTER_L 1738
#define PAPER_SIZE_IS_LEGAL_L 1739
#define PAPER_SIZE_IS_A5_L 1740
#define PAPER_SIZE_IS_A4_L 1741
#define FORMHANDLER 1742
#define END_FORMHANDLER 1743
#define BEFORE_EVENT 1744
#define BEFORE_OPEN_FORM 1745
#define AFTER_EVENT 1746
#define BEFORE_CLOSE_FORM 1747
#define BEFORE_ANY 1748
#define AFTER_ANY 1749
#define MENUHANDLER 1750
#define END_MENUHANDLER 1751
#define BEFORE_SHOW_MENU 1752
#define DISABLE_PROGRAM 1753
#define DISABLE_ALL 1754
#define BUTTONS 1755
#define CHECK_MENUITEM 1756
#define DISABLE_FORM 1757
#define DISABLE_MENUITEMS 1758
#define DISABLE 1759
#define ENABLE_FORM 1760
#define ENABLE_MENUITEMS 1761
#define ENABLE 1762
#define KWFIELD 1763
#define ICON 1764
#define MESSAGEBOX 1765
#define TO_DEFAULTS 1766
#define UNCHECK_MENUITEM 1767
#define BEFORE 1768
#define KW_INPUT_ARRAY 1769
#define KW_INPUT 1770
#define FINPUT 1771
#define END 1772
#define INT_TO_ID 1773
#define TIMEOUT 1774
#define KW_OFF 1775
#define WITH_1_DIMENSION 1776
#define WITH_2_DIMENSION 1777
#define WITH_3_DIMENSION 1778
#define TILDE 1779
#define ILIKE 1780
#define FGL_ISDYNARR_ALLOCATED 1781
#define FGL_DYNARR_EXTENTSIZE 1782
#define FILLFACTOR 1783
#define END_CLASS 1784
#define KW_CLASS 1785
#define EXTENDS 1786
#define KW_PIPE 1787
#define TIME 1788
#define KWBEGIN 1789
#define TRACE 1790
#define SITENAME 1791
#define DBSERVERNAME 1792
#define SYSTEM 1793
#define EXCEPTION 1794
#define KW_TODAY 1795
#define PGKW_ABORT_P 1796
#define PGKW_ABSOLUTE_P 1797
#define PGKW_ACCESS 1798
#define PGKW_ACTION 1799
#define PGKW_ADD 1800
#define PGKW_AFTER 1801
#define PGKW_AGGREGATE 1802
#define PGKW_ALL 1803
#define PGKW_ALTER 1804
#define PGKW_ANALYSE 1805
#define PGKW_ANALYZE 1806
#define PGKW_AND 1807
#define PGKW_ANY 1808
#define PGKW_ARRAY 1809
#define PGKW_AS 1810
#define PGKW_ASC 1811
#define PGKW_ASSERTION 1812
#define PGKW_ASSIGNMENT 1813
#define PGKW_AT 1814
#define PGKW_AUTHORIZATION 1815
#define PGKW_BACKWARD 1816
#define PGKW_BCONST 1817
#define PGKW_BEFORE 1818
#define PGKW_BEGIN_P 1819
#define PGKW_BETWEEN 1820
#define PGKW_BIGINT 1821
#define PGKW_BINARY 1822
#define PGKW_BIT 1823
#define PGKW_BOOLEAN_P 1824
#define PGKW_BOTH 1825
#define PGKW_BY 1826
#define PGKW_CACHE 1827
#define PGKW_CALLED 1828
#define PGKW_CARAT 1829
#define PGKW_CASCADE 1830
#define PGKW_CASE 1831
#define PGKW_CAST 1832
#define PGKW_CHAIN 1833
#define PGKW_CHARACTER 1834
#define PGKW_CHARACTERISTICS 1835
#define PGKW_CHAR_P 1836
#define PGKW_CHECK 1837
#define PGKW_CHECKPOINT 1838
#define PGKW_CLASS 1839
#define PGKW_CLOSE 1840
#define PGKW_CLOSE_BRACKET 1841
#define PGKW_CLOSE_SQUARE 1842
#define PGKW_CLUSTER 1843
#define PGKW_COALESCE 1844
#define PGKW_COLLATE 1845
#define PGKW_COLON 1846
#define PGKW_COLUMN 1847
#define PGKW_COMMA 1848
#define PGKW_COMMENT 1849
#define PGKW_COMMIT 1850
#define PGKW_COMMITTED 1851
#define PGKW_CONSTRAINT 1852
#define PGKW_CONSTRAINTS 1853
#define PGKW_CONVERSION_P 1854
#define PGKW_CONVERT 1855
#define PGKW_COPY 1856
#define PGKW_CREATE 1857
#define PGKW_CREATEDB 1858
#define PGKW_CREATEUSER 1859
#define PGKW_CROSS 1860
#define PGKW_CURRENT 1861
#define PGKW_CURRENT_DATE 1862
#define PGKW_CURRENT_TIME 1863
#define PGKW_CURRENT_TIMESTAMP 1864
#define PGKW_CURRENT_USER 1865
#define PGKW_CURSOR 1866
#define PGKW_CYCLE 1867
#define PGKW_DATABASE 1868
#define PGKW_DATETIME 1869
#define PGKW_DAY_P 1870
#define PGKW_DBA 1871
#define PGKW_DEALLOCATE 1872
#define PGKW_DEC 1873
#define PGKW_DECIMAL_P 1874
#define PGKW_DECLARE 1875
#define PGKW_DEFAULT 1876
#define PGKW_DEFAULTS 1877
#define PGKW_DEFERRABLE 1878
#define PGKW_DEFERRED 1879
#define PGKW_DEFINER 1880
#define PGKW_DELETE_P 1881
#define PGKW_DELIMITER 1882
#define PGKW_DELIMITERS 1883
#define PGKW_DESC 1884
#define PGKW_DISTINCT 1885
#define PGKW_DIVIDE 1886
#define PGKW_DO 1887
#define PGKW_DOMAIN_P 1888
#define PGKW_DOT 1889
#define PGKW_DOUBLE_P 1890
#define PGKW_DROP 1891
#define PGKW_EACH 1892
#define PGKW_ELSE 1893
#define PGKW_ENCODING 1894
#define PGKW_ENCRYPTED 1895
#define PGKW_END_P 1896
#define PGKW_EQUAL 1897
#define PGKW_ESCAPE 1898
#define PGKW_EXCEPT 1899
#define PGKW_EXCLUDING 1900
#define PGKW_EXCLUSIVE 1901
#define PGKW_EXECUTE 1902
#define PGKW_EXISTS 1903
#define PGKW_EXPLAIN 1904
#define PGKW_EXTEND 1905
#define PGKW_EXTERNAL 1906
#define PGKW_EXTRACT 1907
#define PGKW_FALSE_P 1908
#define PGKW_FETCH 1909
#define PGKW_FIRST_P 1910
#define PGKW_FLOAT_P 1911
#define PGKW_FOR 1912
#define PGKW_FORCE 1913
#define PGKW_FOREIGN 1914
#define PGKW_FORWARD 1915
#define PGKW_FREEZE 1916
#define PGKW_FROM 1917
#define PGKW_FULL 1918
#define PGKW_FUNCTION 1919
#define PGKW_GLOBAL 1920
#define PGKW_GRANT 1921
#define PGKW_GREATER_THAN 1922
#define PGKW_GROUP_P 1923
#define PGKW_HANDLER 1924
#define PGKW_HAVING 1925
#define PGKW_HOLD 1926
#define PGKW_HOUR_P 1927
#define PGKW_ILIKE 1928
#define PGKW_IMMEDIATE 1929
#define PGKW_IMMUTABLE 1930
#define PGKW_IMPLICIT_P 1931
#define PGKW_INCLUDING 1932
#define PGKW_INCREMENT 1933
#define PGKW_INDEX 1934
#define PGKW_INHERITS 1935
#define PGKW_INITIALLY 1936
#define PGKW_INNER_P 1937
#define PGKW_INOUT 1938
#define PGKW_IN_P 1939
#define PGKW_INPUT_P 1940
#define PGKW_INSENSITIVE 1941
#define PGKW_INSERT 1942
#define PGKW_INSTEAD 1943
#define PGKW_INTEGER 1944
#define PGKW_INTERSECT 1945
#define PGKW_INTERVAL 1946
#define PGKW_INTO 1947
#define PGKW_INT_P 1948
#define PGKW_INVOKER 1949
#define PGKW_IS 1950
#define PGKW_ISNULL 1951
#define PGKW_ISOLATION 1952
#define PGKW_JOIN 1953
#define PGKW_KEY 1954
#define PGKW_LANCOMPILER 1955
#define PGKW_LANGUAGE 1956
#define PGKW_LAST_P 1957
#define PGKW_LEADING 1958
#define PGKW_LEFT 1959
#define PGKW_LESS_THAN 1960
#define PGKW_LEVEL 1961
#define PGKW_LIKE 1962
#define PGKW_LIMIT 1963
#define PGKW_LISTEN 1964
#define PGKW_LOAD 1965
#define PGKW_LOCAL 1966
#define PGKW_LOCALTIME 1967
#define PGKW_LOCALTIMESTAMP 1968
#define PGKW_LOCATION 1969
#define PGKW_LOCK_P 1970
#define PGKW_MATCH 1971
#define PGKW_MAXVALUE 1972
#define PGKW_MINUS 1973
#define PGKW_MINUTE_P 1974
#define PGKW_MINVALUE 1975
#define PGKW_MODE 1976
#define PGKW_MODIFY 1977
#define PGKW_MONTH_P 1978
#define PGKW_MOVE 1979
#define PGKW_NAMES 1980
#define PGKW_NATIONAL 1981
#define PGKW_NATURAL 1982
#define PGKW_NCHAR 1983
#define PGKW_NEW 1984
#define PGKW_NEXT 1985
#define PGKW_NO 1986
#define PGKW_NOCREATEDB 1987
#define PGKW_NOCREATEUSER 1988
#define PGKW_NONE 1989
#define PGKW_NOT 1990
#define PGKW_NOTHING 1991
#define PGKW_NOTIFY 1992
#define PGKW_NOTNULL 1993
#define PGKW_NULLIF 1994
#define PGKW_NULL_P 1995
#define PGKW_NUMERIC 1996
#define PGKW_OF 1997
#define PGKW_OFF 1998
#define PGKW_OFFSET 1999
#define PGKW_OIDS 2000
#define PGKW_OLD 2001
#define PGKW_ON 2002
#define PGKW_ONLY 2003
#define PGKW_OPEN_BRACKET 2004
#define PGKW_OPEN_SQUARE 2005
#define PGKW_OPERATOR 2006
#define PGKW_OPTION 2007
#define PGKW_OR 2008
#define PGKW_ORDER 2009
#define PGKW_OUTER_P 2010
#define PGKW_OUT_P 2011
#define PGKW_OVERLAPS 2012
#define PGKW_OVERLAY 2013
#define PGKW_OWNER 2014
#define PGKW_PARAM 2015
#define PGKW_PARTIAL 2016
#define PGKW_PASSWORD 2017
#define PGKW_PATH_P 2018
#define PGKW_PENDANT 2019
#define PGKW_PERCENT 2020
#define PGKW_PLACING 2021
#define PGKW_PLUS 2022
#define PGKW_POSITION 2023
#define PGKW_POSTFIXOP 2024
#define PGKW_PRECISION 2025
#define PGKW_PREPARE 2026
#define PGKW_PRESERVE 2027
#define PGKW_PRIMARY 2028
#define PGKW_PRIOR 2029
#define PGKW_PRIVILEGES 2030
#define PGKW_PROCEDURAL 2031
#define PGKW_PROCEDURE 2032
#define PGKW_READ 2033
#define PGKW_REAL 2034
#define PGKW_RECHECK 2035
#define PGKW_REFERENCES 2036
#define PGKW_REINDEX 2037
#define PGKW_RELATIVE_P 2038
#define PGKW_RENAME 2039
#define PGKW_REPLACE 2040
#define PGKW_RESET 2041
#define PGKW_RESTART 2042
#define PGKW_RESTRICT 2043
#define PGKW_RETURNS 2044
#define PGKW_REVOKE 2045
#define PGKW_RIGHT 2046
#define PGKW_ROLLBACK 2047
#define PGKW_ROW 2048
#define PGKW_ROWS 2049
#define PGKW_RULE 2050
#define PGKW_SCHEMA 2051
#define PGKW_SCROLL 2052
#define PGKW_SECOND_P 2053
#define PGKW_SECURITY 2054
#define PGKW_SELECT 2055
#define PGKW_SEMICOLON 2056
#define PGKW_SEQUENCE 2057
#define PGKW_SERIALIZABLE 2058
#define PGKW_SESSION 2059
#define PGKW_SESSION_USER 2060
#define PGKW_SET 2061
#define PGKW_SETOF 2062
#define PGKW_SHARE 2063
#define PGKW_SHOW 2064
#define PGKW_SIMILAR 2065
#define PGKW_SIMPLE 2066
#define PGKW_SMALLINT 2067
#define PGKW_SOME 2068
#define PGKW_STABLE 2069
#define PGKW_STAR 2070
#define PGKW_START 2071
#define PGKW_STATEMENT 2072
#define PGKW_STATISTICS 2073
#define PGKW_STDIN 2074
#define PGKW_STDOUT 2075
#define PGKW_STORAGE 2076
#define PGKW_STRICT_P 2077
#define PGKW_SUBSTRING 2078
#define PGKW_SYSID 2079
#define PGKW_TABLE 2080
#define PGKW_TEMP 2081
#define PGKW_TEMPLATE 2082
#define PGKW_TEMPORARY 2083
#define PGKW_THEN 2084
#define PGKW_TIME 2085
#define PGKW_TIMESTAMP 2086
#define PGKW_TO 2087
#define PGKW_TOAST 2088
#define PGKW_TODAY_SYN 2089
#define PGKW_TRAILING 2090
#define PGKW_TRANSACTION 2091
#define PGKW_TREAT 2092
#define PGKW_TRIGGER 2093
#define PGKW_TRIM 2094
#define PGKW_TRUE_P 2095
#define PGKW_TRUNCATE 2096
#define PGKW_TRUSTED 2097
#define PGKW_TYPECAST 2098
#define PGKW_TYPE_P 2099
#define PGKW_UMINUS 2100
#define PGKW_UNENCRYPTED 2101
#define PGKW_UNION 2102
#define PGKW_UNIONJOIN 2103
#define PGKW_UNIQUE 2104
#define PGKW_UNKNOWN 2105
#define PGKW_UNLISTEN 2106
#define PGKW_UNLOAD 2107
#define PGKW_UNTIL 2108
#define PGKW_UPDATE 2109
#define PGKW_USAGE 2110
#define PGKW_USER 2111
#define PGKW_USING 2112
#define PGKW_VACUUM 2113
#define PGKW_VALID 2114
#define PGKW_VALIDATOR 2115
#define PGKW_VALUES 2116
#define PGKW_VARCHAR 2117
#define PGKW_VARYING 2118
#define PGKW_VERBOSE 2119
#define PGKW_VERSION 2120
#define PGKW_VIEW 2121
#define PGKW_VOLATILE 2122
#define PGKW_WHEN 2123
#define PGKW_WHERE 2124
#define PGKW_WITH 2125
#define PGKW_WITHOUT 2126
#define PGKW_WORK 2127
#define PGKW_WRITE 2128
#define PGKW_XCONST 2129
#define PGKW_YEAR_P 2130
#define PGKW_ZONE 2131
#define KW_TITLE 2132
#define KW_STYLE 2133
#define KW_ACTION 2134
#define KW_IDLE 2135
#define CANCEL_INSERT 2136
#define CANCEL_DELETE 2137
#define FORCE_UI 2138
#define FGL_MODULE 2139
#define VIA 2140
#define SLICE 2141
