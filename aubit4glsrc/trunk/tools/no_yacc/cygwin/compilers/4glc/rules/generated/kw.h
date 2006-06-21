struct s_kw {
    int id;
	   int mode;
    char *vals[20];
    char *name;
};
#define MEMBER_FUNCTION 1000
#define DIALOGSETCURRLINE 1001
#define DIALOGKEYSETLABEL 1002
#define DIALOGX 1003
#define TRACE_PROCEDURE 1004
#define RAISE_EXCEPTION 1005
#define WITH_HOLD_FOR 1006
#define CREATE_PROCEDURE 1007
#define WITH_RESUME 1008
#define TRACE_ON 1009
#define END_PROCEDURE 1010
#define END_EXCEPTION 1011
#define REFERENCES_BYTE 1012
#define REFERENCES_TEXT 1013
#define TRACE_OFF 1014
#define REPLACE_STRING 1015
#define STOP_REPLACE_STRING 1016
#define IGNORE_FUNCTION 1017
#define EMULATE_INSERT_CURSOR_FOR 1018
#define DEFINE_GLOBAL 1019
#define SET_BUFFERED_LOG 1020
#define SET_LOG 1021
#define PRAGMA 1022
#define MDY 1023
#define WEEKDAY 1024
#define SYSTEM_4GL 1025
#define SQL_FEATURE 1026
#define MISC_INFX_SQL 1027
#define CONVERTING_TO_PIPE 1028
#define CONVERTING_TO_FILE 1029
#define CONVERTING_TO_PRINTER 1030
#define CONVERTING_TO_EMAIL 1031
#define KW_CHANNEL_READ 1032
#define KW_CHANNEL_WRITE 1033
#define AS_CONVERTABLE 1034
#define FREE_REPORT 1035
#define CONVERTING_TO_MANY 1036
#define CONVERTING_TO 1037
#define CONVERT_REPORT 1038
#define DATETIME_VALUE 1039
#define INTERVAL_VALUE 1040
#define RECOVER_TABLE 1041
#define ROLLFORWARD_DATABASE 1042
#define IN_LINE_MODE 1043
#define IN_FORM_MODE 1044
#define FGL_SIZEOF 1045
#define FGL_ADDRESSOF 1046
#define IMPORT_PACKAGE 1047
#define DYNAMIC_ARRAY 1048
#define RESIZE_ARRAY 1049
#define ALLOCATE_ARRAY 1050
#define DEALLOCATE_ARRAY 1051
#define AFTER_INSERT_DELETE 1052
#define BEFORE_INSERT_DELETE 1053
#define BEFORE_INSERT 1054
#define CONCAT_PIPES 1055
#define BEFORE_DELETE 1056
#define DROP_TRIGGER 1057
#define DROP_AUDIT_FOR 1058
#define CREATE_AUDIT_FOR 1059
#define AFTER_INSERT 1060
#define AFTER_DELETE 1061
#define EXECUTE_IMMEDIATE 1062
#define EXECUTE_PROCEDURE 1063
#define DELETE_ROW_EQUAL_TRUE 1064
#define INSERT_ROW_EQUAL_TRUE 1065
#define DELETE_ROW_EQUAL_FALSE 1066
#define INSERT_ROW_EQUAL_FALSE 1067
#define CURRENT_ROW_DISPLAY_EQUAL 1068
#define MAXCOUNT 1069
#define ALTER_TABLE 1070
#define ALTER_INDEX 1071
#define NEXT_SIZE 1072
#define DISPLAY_ATTR_FORM 1073
#define DISPLAY_ATTR_WINDOW 1074
#define INPUT_ATTR_FORM 1075
#define INPUT_ATTR_WINDOW 1076
#define WHENEVER_ERROR_CONTINUE 1077
#define WHENEVER_ANY_ERROR_CONTINUE 1078
#define WHENEVER_WARNING_CONTINUE 1079
#define WHENEVER_SQLSUCCESS_CONTINUE 1080
#define WHENEVER_SQLWARNING_CONTINUE 1081
#define WHENEVER_NOT_FOUND_CONTINUE 1082
#define WHENEVER_SQLERROR_CONTINUE 1083
#define WHENEVER_SUCCESS_CONTINUE 1084
#define WHENEVER_ERROR_GOTO 1085
#define WHENEVER_ANY_ERROR_GOTO 1086
#define WHENEVER_WARNING_GOTO 1087
#define WHENEVER_SQLSUCCESS_GOTO 1088
#define WHENEVER_SQLWARNING_GOTO 1089
#define WHENEVER_NOT_FOUND_GOTO 1090
#define WHENEVER_SQLERROR_GOTO 1091
#define WHENEVER_SUCCESS_GOTO 1092
#define WHENEVER_ERROR_CALL 1093
#define WHENEVER_ANY_ERROR_CALL 1094
#define WHENEVER_WARNING_CALL 1095
#define WHENEVER_SQLSUCCESS_CALL 1096
#define WHENEVER_SQLWARNING_CALL 1097
#define WHENEVER_NOT_FOUND_CALL 1098
#define WHENEVER_SQLERROR_CALL 1099
#define WHENEVER_SUCCESS_CALL 1100
#define WHENEVER_ERROR_STOP 1101
#define WHENEVER_ANY_ERROR_STOP 1102
#define WHENEVER_WARNING_STOP 1103
#define WHENEVER_SQLSUCCESS_STOP 1104
#define WHENEVER_SQLWARNING_STOP 1105
#define WHENEVER_NOT_FOUND_STOP 1106
#define WHENEVER_SQLERROR_STOP 1107
#define WHENEVER_SUCCESS_STOP 1108
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1109
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1110
#define XSET_ident_DOT_MULTIPLY_EQUAL 1111
#define XSET_MULTIPLY_EQUAL 1112
#define XSET_OPEN_BRACKET 1113
#define NEWFORMATSHARED 1114
#define DEFINE_NEW_TYPE 1115
#define CREATE_DATABASE 1116
#define DROP_DATABASE 1117
#define IMPORT_LEGACY_FUNCTION 1118
#define ADD_CONSTRAINT 1119
#define DROP_CONSTRAINT 1120
#define DROP_SYNONYM 1121
#define CONSTRAINT 1122
#define AS_STATIC 1123
#define NOT_FIELD_TOUCHED 1124
#define LOCAL_FUNCTION 1125
#define EVERY_ROW 1126
#define ELIF 1127
#define KW_ARG_VAL 1128
#define DOUBLE_PRECISION 1129
#define COUNT_MULTIPLY 1130
#define WAIT_FOR_KEY 1131
#define AT_TERMINATION_CALL 1132
#define TERMINATE_REPORT 1133
#define TO_MAIN_CAPTION 1134
#define CLEARSTAT 1135
#define TO_MENUITEM 1136
#define ID_TO_INT 1137
#define TO_STATUSBOX 1138
#define ASCII_HEIGHT_ALL 1139
#define ASCII_WIDTH_ALL 1140
#define IMPORT_DATATYPE 1141
#define PAGE_TRAILER_SIZE 1142
#define PAGE_HEADER_SIZE 1143
#define FIRST_PAGE_HEADER_SIZE 1144
#define BYTES_USE_AS_IMAGE 1145
#define BYTES_USE_AS_ASCII 1146
#define KWUP_BY 1147
#define KWDOWN_BY 1148
#define CLOSE_STATUSBOX 1149
#define MODIFY_NEXT_SIZE 1150
#define LOCK_MODE_PAGE 1151
#define LOCK_MODE_ROW 1152
#define TO_PIPE 1153
#define TO_FILE 1154
#define TO_SCREEN 1155
#define TO_PRINTER 1156
#define TO_EMAIL 1157
#define STATUSBOX 1158
#define UNITS_YEAR 1159
#define UNITS_MONTH 1160
#define UNITS_DAY 1161
#define UNITS_HOUR 1162
#define UNITS_MINUTE 1163
#define UNITS_SECOND 1164
#define NO_NEW_LINES 1165
#define FIELDTOWIDGET 1166
#define WITH_HOLD 1167
#define SHOW_MENU 1168
#define TO_CLUSTER 1169
#define TO_NOT_CLUSTER 1170
#define CWIS 1171
#define CREATE_UC_IDX 1172
#define CREATE_U_IDX 1173
#define CREATE_C_IDX 1174
#define CREATE_IDX 1175
#define FORM_IS_COMPILED 1176
#define PDF_REPORT 1177
#define IMPORT_FUNCTION 1178
#define PROMPT_MANY 1179
#define KW_POINTS 1180
#define MM 1181
#define INCHES 1182
#define PREPEND 1183
#define MEMBER_OF 1184
#define APPEND 1185
#define TEMPLATE 1186
#define END_TEMPLATE 1187
#define SQLSICS 1188
#define CREATE_SCHEMA 1189
#define SQLSIRR 1190
#define UPDATESTATS_T 1191
#define SQLSICR 1192
#define WHENEVER_SQLSUCCESS 1193
#define WHENEVER_SQLWARNING 1194
#define WHENEVER_ANY_ERROR 1195
#define WHENEVER_NOT_FOUND 1196
#define WHENEVER_SQLERROR 1197
#define WHENEVER_SUCCESS 1198
#define WHENEVER_ERROR 1199
#define START_EXTERN 1200
#define CONTINUE_CONSTRUCT 1201
#define FOUNCONSTR 1202
#define SQLSIDR 1203
#define CREATE_TEMP_TABLE 1204
#define CURRENT_WINDOW_IS 1205
#define FIRST_PAGE_HEADER 1206
#define ORDER_EXTERNAL_BY 1207
#define SCROLL_CURSOR_FOR 1208
#define SCROLL_CURSOR 1209
#define SQL_INTERRUPT_OFF 1210
#define STOP_ALL_EXTERNAL 1211
#define WITH_CHECK_OPTION 1212
#define WITH_GRANT_OPTION 1213
#define SQLSLMNW 1214
#define ADDCONSTUNIQ 1215
#define CONTINUE_DISPLAY 1216
#define CONTINUE_FOREACH 1217
#define OUTPUT_TO_REPORT 1218
#define SQL_INTERRUPT_ON 1219
#define WHERE_CURRENT_OF 1220
#define WITHOUT_DEFAULTS 1221
#define FOCONSTR 1222
#define SCALED_BY 1223
#define CONTINUE_PROMPT 1224
#define PDF_FUNCTION 1225
#define DEFER_INTERRUPT 1226
#define DISPLAY_BY_NAME 1227
#define NOT_NULL_UNIQUE 1228
#define SKIP_TO_TOP 1229
#define TOP_OF_PAGE 1230
#define SKIP_TO 1231
#define SKIP_BY 1232
#define WITHOUT_WAITING 1233
#define BEFCONSTRUCT 1234
#define SQLSLMW 1235
#define AFTCONSTRUCT 1236
#define ALL_PRIVILEGES 1237
#define CLOSE_DATABASE 1238
#define CONTINUE_INPUT 1239
#define CONTINUE_WHILE 1240
#define CREATE_SYNONYM 1241
#define DROP_TABLE 1242
#define EXIT_CONSTRUCT 1243
#define INEXCLUSIVE 1244
#define REPORT_TO_PRINTER 1245
#define REPORT_TO_PIPE 1246
#define KW_RETURN 1247
#define SET_SESSION_TO 1248
#define UPDATESTATS 1249
#define WITHOUT_HEAD 1250
#define CLEARSCR 1251
#define WITH_B_LOG 1252
#define AUTHORIZATION 1253
#define BOTTOM_MARGIN 1254
#define CLOSE_SESSION 1255
#define CONTINUE_CASE 1256
#define CONTINUE_MENU 1257
#define DISPLAY_ARRAY 1258
#define END_SQL 1259
#define DOLLAR 1260
#define END_CONSTRUCT 1261
#define FIELD_TOUCHED 1262
#define FINISH_REPORT 1263
#define INFACC 1264
#define INPUT_NO_WRAP 1265
#define SETPMOFF 1266
#define UNCONSTRAINED 1267
#define PAGE_TRAILER 1268
#define SETPMON 1269
#define BEFGROUP 1270
#define CLOSE_WINDOW 1271
#define COMMENT_LINE 1272
#define CONTINUE_FOR 1273
#define CREATE_DB 1274
#define CREATE_TABLE 1275
#define DEFAULT_NULL 1276
#define DEFAULT_TODAY 1277
#define DEFAULT_USER 1278
#define DELETE_USING 1279
#define DISPLAY_FORM 1280
#define END_FUNCTION 1281
#define EXIT_DISPLAY 1282
#define EXIT_FOREACH 1283
#define EXIT_PROGRAM 1284
#define INFCOLS 1285
#define ON_EVERY_ROW 1286
#define OPEN_SESSION 1287
#define RIGHT_MARGIN 1288
#define SELECT_USING 1289
#define START_REPORT 1290
#define UNLOCK_TABLE 1291
#define UPDATE_USING 1292
#define ACL_BUILTIN 1293
#define AFTGROUP 1294
#define INFIDX 1295
#define INFSTAT 1296
#define LEFT_MARGIN 1297
#define PAGE_HEADER 1298
#define ROLLBACK_W 1299
#define SET_SESSION 1300
#define SQLSEON 1301
#define SQLSEOFF 1302
#define WITH_A_LOG 1303
#define BEFDISP 1304
#define BEFORE_MENU 1305
#define CREATE_VIEW 1306
#define DELETE_FROM 1307
#define END_DISPLAY 1308
#define END_REPORT 1309
#define END_FOREACH 1310
#define END_FOR 1311
#define END_GLOBALS 1312
#define EXIT_PROMPT 1313
#define EXTENT_SIZE 1314
#define FOREIGN_KEY 1315
#define HIDE_OPTION 1316
#define KW_HIDE_WINDOW 1317
#define INSERT_INTO 1318
#define IS_SERIAL 1319
#define IS_NOT_NULL 1320
#define MOVE_WINDOW 1321
#define NEXT_OPTION 1322
#define NOT_MATCHES 1323
#define ON_LAST_ROW 1324
#define OPEN_WINDOW 1325
#define OPEN_STATUSBOX 1326
#define PAGE_LENGTH 1327
#define PAGE_WIDTH 1328
#define PRIMARY_KEY 1329
#define PROMPT_LINE 1330
#define RECORD_LIKE 1331
#define ROLLFORWARD 1332
#define SHOW_OPTION 1333
#define SHOW_WINDOW 1334
#define TO_DATABASE 1335
#define USE_SESSION 1336
#define WITH_NO_LOG 1337
#define AFTDISP 1338
#define BEFFIELD 1339
#define INSHARE 1340
#define UNLOCKTAB 1341
#define AFTFIELD 1342
#define ATTRIBUTES 1343
#define BEFINP 1344
#define BEFORE_DISPLAY 1345
#define BEGIN_WORK 1346
#define CLEARWIN 1347
#define CLOSE_FORM 1348
#define DEFER_QUIT 1349
#define DESCENDING 1350
#define DROP_INDEX 1351
#define END_PROMPT 1352
#define END_RECORD 1353
#define ERROR_LINE 1354
#define EXIT_INPUT 1355
#define EXIT_WHILE 1356
#define FOR_UPDATE_OF 1357
#define FOR_UPDATE 1358
#define GET_FLDBUF 1359
#define INITIALIZE 1360
#define INPUT_WRAP 1361
#define LOCK_TABLE 1362
#define MSG_LINE 1363
#define NOT_EXISTS 1364
#define ON_ANY_KEY 1365
#define REFERENCES 1366
#define RENCOL 1367
#define SET_CURSOR 1368
#define SMALLFLOAT 1369
#define SQLSUCCESS 1370
#define TOP_MARGIN 1371
#define WITH_ARRAY 1372
#define ACCEPTKEY 1373
#define KW_ACCEPT 1374
#define AFTINP 1375
#define AFTER_DISPLAY 1376
#define CLEARFORMTODEFAULTS 1377
#define CLEARFORM 1378
#define CLEAR_X_FORM 1379
#define COMMIT_W 1380
#define KW_NEXTPAGE 1381
#define KW_PREVPAGE 1382
#define KW_CTRL_KEY 1383
#define INFTABS 1384
#define NEXTFIELD 1385
#define NEXTFORM 1386
#define RENTAB 1387
#define ASCENDING 1388
#define ASSOCIATE 1389
#define KW_CHAR 1390
#define NCHAR 1391
#define NVARCHAR 1392
#define CONSTRUCT 1393
#define DELIMITER 1394
#define DOWNSHIFT 1395
#define DROP_VIEW 1396
#define END_INPUT 1397
#define END_WHILE 1398
#define EXCLUSIVE 1399
#define EXIT_CASE 1400
#define EXIT_MENU 1401
#define FORM_LINE 1402
#define GREATER_THAN_EQ 1403
#define KW_INTERRUPT 1404
#define INTO_TEMP 1405
#define INVISIBLE 1406
#define IN_MEMORY 1407
#define LINKED_TO 1408
#define LOAD_FROM 1409
#define LOCKTAB 1410
#define MENU_LINE 1411
#define OPEN_FORM 1412
#define OTHERWISE 1413
#define PRECISION 1414
#define KW_PRIOR 1415
#define PROCEDURE 1416
#define REPORT_TO 1417
#define RETURNING 1418
#define UNDERLINE 1419
#define UNLOAD_TO 1420
#define BEFROW 1421
#define UNLOAD_T 1422
#define VARIABLE_ATTRIBUTES 1423
#define VARIABLE 1424
#define KW_ABSOLUTE 1425
#define AFTROW 1426
#define BUFFERED 1427
#define KW_CONSTANT 1428
#define KW_CONST 1429
#define DATABASE 1430
#define DATETIME 1431
#define DEFAULTS 1432
#define DISTINCT 1433
#define END_CASE 1434
#define END_MAIN 1435
#define END_MENU 1436
#define END_TYPE 1437
#define EXIT_FOR 1438
#define EXTERNAL 1439
#define FRACTION 1440
#define FUNCTION 1441
#define GROUP_BY 1442
#define INTERVAL 1443
#define KWMESSAGE 1444
#define NOT_LIKE 1445
#define NOT_ILIKE 1446
#define NOT_NULL 1447
#define PASSWORD 1448
#define KW_PREVIOUS 1449
#define READONLY 1450
#define REGISTER 1451
#define KW_RELATIVE 1452
#define RESOURCE 1453
#define SMALLINT 1454
#define VALIDATE 1455
#define WITH_LOG 1456
#define WORDWRAP 1457
#define BY_NAME 1458
#define IN_FILE 1459
#define IS_NULL 1460
#define LESS_THAN_EQ 1461
#define AVERAGE 1462
#define BETWEEN 1463
#define CAPTION 1464
#define CLIPPED 1465
#define CLOSE_BRACKET 1466
#define COLUMNS 1467
#define COMMAND 1468
#define CONNECT 1469
#define KW_CURRENT 1470
#define DBYNAME 1471
#define KW_DECIMAL 1472
#define DECLARE 1473
#define DEFAULT 1474
#define KW_DISPLAY 1475
#define ENDCODE 1476
#define EXECUTE 1477
#define FOREACH 1478
#define FOREIGN 1479
#define GLOBALS 1480
#define INFIELD 1481
#define INTEGER 1482
#define KWWINDOW 1483
#define MAGENTA 1484
#define MATCHES 1485
#define OPTIONS 1486
#define PERCENT 1487
#define PREPARE 1488
#define PROGRAM 1489
#define RECOVER 1490
#define REVERSE 1491
#define SECTION 1492
#define SESSION 1493
#define SYNONYM 1494
#define THRU 1495
#define TRAILER 1496
#define UPSHIFT 1497
#define VARCHAR 1498
#define WAITING 1499
#define CLOSE_SHEV 1500
#define CLOSE_SQUARE 1501
#define GREATER_THAN 1502
#define KW_FALSE 1503
#define NOT_IN 1504
#define ONKEY 1505
#define OPEN_BRACKET 1506
#define BORDER 1507
#define BOTTOM 1508
#define COLUMN 1509
#define COMMIT 1510
#define CREATE 1511
#define CURSOR 1512
#define DEFINE 1513
#define KW_DELETE 1514
#define KW_DOUBLE 1515
#define END_IF 1516
#define KW_ESCAPE 1517
#define EXISTS 1518
#define EXTEND 1519
#define EXTENT 1520
#define FINISH 1521
#define FORMAT 1522
#define HAVING 1523
#define HEADER 1524
#define KW_INSERT 1525
#define LOCATE 1526
#define MARGIN 1527
#define MEMORY 1528
#define MINUTE 1529
#define MODIFY 1530
#define NORMAL 1531
#define EQUAL 1532
#define NOT_EQUAL 1533
#define OPEN_SHEV 1534
#define OPEN_SQUARE 1535
#define OPTION 1536
#define OUTPUT 1537
#define PROMPT 1538
#define PUBLIC 1539
#define RECORD 1540
#define REPORT 1541
#define REVOKE 1542
#define SCHEMA 1543
#define SCROLL_USING 1544
#define SCROLL 1545
#define SECOND 1546
#define IDLE_SECONDS 1547
#define IDLE_MINUTES 1548
#define IDLE_HOURS 1549
#define KW_SELECT 1550
#define SERIAL 1551
#define SHARED 1552
#define SPACES 1553
#define UNIQUE 1554
#define UNLOCK 1555
#define KW_UPDATE 1556
#define VALUES 1557
#define YELLOW 1558
#define AFTER 1559
#define KWLINE 1560
#define KW_NULL 1561
#define KW_TRUE 1562
#define KW_SINGLE_KEY 1563
#define ALTER 1564
#define ARRAY 1565
#define ASCII 1566
#define AUDIT 1567
#define BLACK 1568
#define BLINK 1569
#define CHECK 1570
#define CLEAR 1571
#define CLOSE 1572
#define CODE_C 1573
#define COUNT 1574
#define DEFER 1575
#define KW_ERROR 1576
#define EVERY 1577
#define FETCH 1578
#define KW_FIRST 1579
#define KW_FLOAT 1580
#define FLUSH 1581
#define FOUND 1582
#define GRANT 1583
#define GREEN 1584
#define KW_GROUP 1585
#define INDEX 1586
#define KWFORM 1587
#define LABEL 1588
#define LESS_THAN 1589
#define LOCAL 1590
#define MONEY 1591
#define MONTH 1592
#define POWER 1593
#define MULTIPLY 1594
#define ORDER 1595
#define OUTER 1596
#define PAUSE 1597
#define PRINT_IMAGE 1598
#define PRINT_FILE 1599
#define PRINT 1600
#define KW_RIGHT 1601
#define DOUBLE_COLON 1602
#define SEMICOLON 1603
#define SLEEP 1604
#define TUPLE 1605
#define UNION 1606
#define KW_USING 1607
#define WHERE 1608
#define WHILE 1609
#define WHITE 1610
#define CCODE 1611
#define ANSI 1612
#define BLUE 1613
#define BOLD 1614
#define KW_BYTE 1615
#define FCALL 1616
#define CASE 1617
#define CYAN 1618
#define KW_DATE 1619
#define DESC 1620
#define DIVIDE 1621
#define KWDOWN 1622
#define KW_TAB 1623
#define DROP 1624
#define ELSE 1625
#define EXEC 1626
#define EXIT 1627
#define FREE 1628
#define FROM 1629
#define GOTO 1630
#define HELP_FILE 1631
#define LANG_FILE 1632
#define KW_HELP 1633
#define HIDE 1634
#define HOUR 1635
#define INTO 1636
#define KW_LAST 1637
#define KW_LEFT 1638
#define LIKE 1639
#define MAIN 1640
#define MENU 1641
#define MODE 1642
#define NEED 1643
#define KW_NEXT 1644
#define NOCR 1645
#define OPEN 1646
#define QUIT 1647
#define REAL 1648
#define ROWS 1649
#define SHOW 1650
#define KW_SIZE 1651
#define SKIP 1652
#define SOME 1653
#define STEP 1654
#define STOP 1655
#define TEMP 1656
#define KW_TEXT 1657
#define THEN 1658
#define USER 1659
#define WAIT 1660
#define WHEN 1661
#define WITH 1662
#define WORK 1663
#define YEAR 1664
#define KW_DOW 1665
#define KW_IS 1666
#define XSET 1667
#define ADD 1668
#define ALL 1669
#define KW_AND 1670
#define ANY 1671
#define ASC 1672
#define AVG 1673
#define COLON 1674
#define KW_COMMA 1675
#define DAY 1676
#define DBA 1677
#define DEC 1678
#define DIM 1679
#define KW_FKEY 1680
#define FOR 1681
#define KEY 1682
#define KWNO 1683
#define LET 1684
#define LOG 1685
#define XMAX 1686
#define XMIN 1687
#define MINUS 1688
#define MOD 1689
#define NOT 1690
#define PAD 1691
#define PUT 1692
#define RED 1693
#define ROW 1694
#define KW_RUN 1695
#define SQL 1696
#define SUM 1697
#define TOP 1698
#define USE 1699
#define ATSIGN 1700
#define PLUS 1701
#define AS_TIFF 1702
#define AS_GIF 1703
#define AS_PNG 1704
#define AS_JPEG 1705
#define AS 1706
#define AT 1707
#define BY 1708
#define DOT 1709
#define GO 1710
#define IF 1711
#define KW_IN 1712
#define OF 1713
#define KW_ON 1714
#define KW_OR 1715
#define TO 1716
#define KWUP 1717
#define FONT_NAME 1718
#define FONT_SIZE 1719
#define PAPER_SIZE_IS_LETTER 1720
#define PAPER_SIZE_IS_LEGAL 1721
#define PAPER_SIZE_IS_A5 1722
#define PAPER_SIZE_IS_A4 1723
#define PAPER_SIZE_IS_LETTER_L 1724
#define PAPER_SIZE_IS_LEGAL_L 1725
#define PAPER_SIZE_IS_A5_L 1726
#define PAPER_SIZE_IS_A4_L 1727
#define FORMHANDLER 1728
#define END_FORMHANDLER 1729
#define BEFORE_EVENT 1730
#define BEFORE_OPEN_FORM 1731
#define AFTER_EVENT 1732
#define BEFORE_CLOSE_FORM 1733
#define BEFORE_ANY 1734
#define AFTER_ANY 1735
#define MENUHANDLER 1736
#define END_MENUHANDLER 1737
#define BEFORE_SHOW_MENU 1738
#define DISABLE_PROGRAM 1739
#define DISABLE_ALL 1740
#define BUTTONS 1741
#define CHECK_MENUITEM 1742
#define DISABLE_FORM 1743
#define DISABLE_MENUITEMS 1744
#define DISABLE 1745
#define ENABLE_FORM 1746
#define ENABLE_MENUITEMS 1747
#define ENABLE 1748
#define KWFIELD 1749
#define ICON 1750
#define MESSAGEBOX 1751
#define TO_DEFAULTS 1752
#define UNCHECK_MENUITEM 1753
#define BEFORE 1754
#define KW_INPUT 1755
#define FINPUT 1756
#define END 1757
#define INT_TO_ID 1758
#define TIMEOUT 1759
#define KW_OFF 1760
#define WITH_1_DIMENSION 1761
#define WITH_2_DIMENSION 1762
#define WITH_3_DIMENSION 1763
#define TILDE 1764
#define ILIKE 1765
#define FGL_ISDYNARR_ALLOCATED 1766
#define FGL_DYNARR_EXTENTSIZE 1767
#define FILLFACTOR 1768
#define END_CLASS 1769
#define KW_CLASS 1770
#define EXTENDS 1771
#define KW_PIPE 1772
#define TIME 1773
#define KWBEGIN 1774
#define TRACE 1775
#define SITENAME 1776
#define DBSERVERNAME 1777
#define SYSTEM 1778
#define EXCEPTION 1779
#define KW_TODAY 1780
#define PGKW_ABORT_P 1781
#define PGKW_ABSOLUTE_P 1782
#define PGKW_ACCESS 1783
#define PGKW_ACTION 1784
#define PGKW_ADD 1785
#define PGKW_AFTER 1786
#define PGKW_AGGREGATE 1787
#define PGKW_ALL 1788
#define PGKW_ALTER 1789
#define PGKW_ANALYSE 1790
#define PGKW_ANALYZE 1791
#define PGKW_AND 1792
#define PGKW_ANY 1793
#define PGKW_ARRAY 1794
#define PGKW_AS 1795
#define PGKW_ASC 1796
#define PGKW_ASSERTION 1797
#define PGKW_ASSIGNMENT 1798
#define PGKW_AT 1799
#define PGKW_AUTHORIZATION 1800
#define PGKW_BACKWARD 1801
#define PGKW_BCONST 1802
#define PGKW_BEFORE 1803
#define PGKW_BEGIN_P 1804
#define PGKW_BETWEEN 1805
#define PGKW_BIGINT 1806
#define PGKW_BINARY 1807
#define PGKW_BIT 1808
#define PGKW_BOOLEAN_P 1809
#define PGKW_BOTH 1810
#define PGKW_BY 1811
#define PGKW_CACHE 1812
#define PGKW_CALLED 1813
#define PGKW_CARAT 1814
#define PGKW_CASCADE 1815
#define PGKW_CASE 1816
#define PGKW_CAST 1817
#define PGKW_CHAIN 1818
#define PGKW_CHARACTER 1819
#define PGKW_CHARACTERISTICS 1820
#define PGKW_CHAR_P 1821
#define PGKW_CHECK 1822
#define PGKW_CHECKPOINT 1823
#define PGKW_CLASS 1824
#define PGKW_CLOSE 1825
#define PGKW_CLOSE_BRACKET 1826
#define PGKW_CLOSE_SQUARE 1827
#define PGKW_CLUSTER 1828
#define PGKW_COALESCE 1829
#define PGKW_COLLATE 1830
#define PGKW_COLON 1831
#define PGKW_COLUMN 1832
#define PGKW_COMMA 1833
#define PGKW_COMMENT 1834
#define PGKW_COMMIT 1835
#define PGKW_COMMITTED 1836
#define PGKW_CONSTRAINT 1837
#define PGKW_CONSTRAINTS 1838
#define PGKW_CONVERSION_P 1839
#define PGKW_CONVERT 1840
#define PGKW_COPY 1841
#define PGKW_CREATE 1842
#define PGKW_CREATEDB 1843
#define PGKW_CREATEUSER 1844
#define PGKW_CROSS 1845
#define PGKW_CURRENT 1846
#define PGKW_CURRENT_DATE 1847
#define PGKW_CURRENT_TIME 1848
#define PGKW_CURRENT_TIMESTAMP 1849
#define PGKW_CURRENT_USER 1850
#define PGKW_CURSOR 1851
#define PGKW_CYCLE 1852
#define PGKW_DATABASE 1853
#define PGKW_DATETIME 1854
#define PGKW_DAY_P 1855
#define PGKW_DBA 1856
#define PGKW_DEALLOCATE 1857
#define PGKW_DEC 1858
#define PGKW_DECIMAL_P 1859
#define PGKW_DECLARE 1860
#define PGKW_DEFAULT 1861
#define PGKW_DEFAULTS 1862
#define PGKW_DEFERRABLE 1863
#define PGKW_DEFERRED 1864
#define PGKW_DEFINER 1865
#define PGKW_DELETE_P 1866
#define PGKW_DELIMITER 1867
#define PGKW_DELIMITERS 1868
#define PGKW_DESC 1869
#define PGKW_DISTINCT 1870
#define PGKW_DIVIDE 1871
#define PGKW_DO 1872
#define PGKW_DOMAIN_P 1873
#define PGKW_DOT 1874
#define PGKW_DOUBLE_P 1875
#define PGKW_DROP 1876
#define PGKW_EACH 1877
#define PGKW_ELSE 1878
#define PGKW_ENCODING 1879
#define PGKW_ENCRYPTED 1880
#define PGKW_END_P 1881
#define PGKW_EQUAL 1882
#define PGKW_ESCAPE 1883
#define PGKW_EXCEPT 1884
#define PGKW_EXCLUDING 1885
#define PGKW_EXCLUSIVE 1886
#define PGKW_EXECUTE 1887
#define PGKW_EXISTS 1888
#define PGKW_EXPLAIN 1889
#define PGKW_EXTEND 1890
#define PGKW_EXTERNAL 1891
#define PGKW_EXTRACT 1892
#define PGKW_FALSE_P 1893
#define PGKW_FETCH 1894
#define PGKW_FIRST_P 1895
#define PGKW_FLOAT_P 1896
#define PGKW_FOR 1897
#define PGKW_FORCE 1898
#define PGKW_FOREIGN 1899
#define PGKW_FORWARD 1900
#define PGKW_FREEZE 1901
#define PGKW_FROM 1902
#define PGKW_FULL 1903
#define PGKW_FUNCTION 1904
#define PGKW_GLOBAL 1905
#define PGKW_GRANT 1906
#define PGKW_GREATER_THAN 1907
#define PGKW_GROUP_P 1908
#define PGKW_HANDLER 1909
#define PGKW_HAVING 1910
#define PGKW_HOLD 1911
#define PGKW_HOUR_P 1912
#define PGKW_ILIKE 1913
#define PGKW_IMMEDIATE 1914
#define PGKW_IMMUTABLE 1915
#define PGKW_IMPLICIT_P 1916
#define PGKW_INCLUDING 1917
#define PGKW_INCREMENT 1918
#define PGKW_INDEX 1919
#define PGKW_INHERITS 1920
#define PGKW_INITIALLY 1921
#define PGKW_INNER_P 1922
#define PGKW_INOUT 1923
#define PGKW_IN_P 1924
#define PGKW_INPUT_P 1925
#define PGKW_INSENSITIVE 1926
#define PGKW_INSERT 1927
#define PGKW_INSTEAD 1928
#define PGKW_INTEGER 1929
#define PGKW_INTERSECT 1930
#define PGKW_INTERVAL 1931
#define PGKW_INTO 1932
#define PGKW_INT_P 1933
#define PGKW_INVOKER 1934
#define PGKW_IS 1935
#define PGKW_ISNULL 1936
#define PGKW_ISOLATION 1937
#define PGKW_JOIN 1938
#define PGKW_KEY 1939
#define PGKW_LANCOMPILER 1940
#define PGKW_LANGUAGE 1941
#define PGKW_LAST_P 1942
#define PGKW_LEADING 1943
#define PGKW_LEFT 1944
#define PGKW_LESS_THAN 1945
#define PGKW_LEVEL 1946
#define PGKW_LIKE 1947
#define PGKW_LIMIT 1948
#define PGKW_LISTEN 1949
#define PGKW_LOAD 1950
#define PGKW_LOCAL 1951
#define PGKW_LOCALTIME 1952
#define PGKW_LOCALTIMESTAMP 1953
#define PGKW_LOCATION 1954
#define PGKW_LOCK_P 1955
#define PGKW_MATCH 1956
#define PGKW_MAXVALUE 1957
#define PGKW_MINUS 1958
#define PGKW_MINUTE_P 1959
#define PGKW_MINVALUE 1960
#define PGKW_MODE 1961
#define PGKW_MODIFY 1962
#define PGKW_MONTH_P 1963
#define PGKW_MOVE 1964
#define PGKW_NAMES 1965
#define PGKW_NATIONAL 1966
#define PGKW_NATURAL 1967
#define PGKW_NCHAR 1968
#define PGKW_NEW 1969
#define PGKW_NEXT 1970
#define PGKW_NO 1971
#define PGKW_NOCREATEDB 1972
#define PGKW_NOCREATEUSER 1973
#define PGKW_NONE 1974
#define PGKW_NOT 1975
#define PGKW_NOTHING 1976
#define PGKW_NOTIFY 1977
#define PGKW_NOTNULL 1978
#define PGKW_NULLIF 1979
#define PGKW_NULL_P 1980
#define PGKW_NUMERIC 1981
#define PGKW_OF 1982
#define PGKW_OFF 1983
#define PGKW_OFFSET 1984
#define PGKW_OIDS 1985
#define PGKW_OLD 1986
#define PGKW_ON 1987
#define PGKW_ONLY 1988
#define PGKW_OPEN_BRACKET 1989
#define PGKW_OPEN_SQUARE 1990
#define PGKW_OPERATOR 1991
#define PGKW_OPTION 1992
#define PGKW_OR 1993
#define PGKW_ORDER 1994
#define PGKW_OUTER_P 1995
#define PGKW_OUT_P 1996
#define PGKW_OVERLAPS 1997
#define PGKW_OVERLAY 1998
#define PGKW_OWNER 1999
#define PGKW_PARAM 2000
#define PGKW_PARTIAL 2001
#define PGKW_PASSWORD 2002
#define PGKW_PATH_P 2003
#define PGKW_PENDANT 2004
#define PGKW_PERCENT 2005
#define PGKW_PLACING 2006
#define PGKW_PLUS 2007
#define PGKW_POSITION 2008
#define PGKW_POSTFIXOP 2009
#define PGKW_PRECISION 2010
#define PGKW_PREPARE 2011
#define PGKW_PRESERVE 2012
#define PGKW_PRIMARY 2013
#define PGKW_PRIOR 2014
#define PGKW_PRIVILEGES 2015
#define PGKW_PROCEDURAL 2016
#define PGKW_PROCEDURE 2017
#define PGKW_READ 2018
#define PGKW_REAL 2019
#define PGKW_RECHECK 2020
#define PGKW_REFERENCES 2021
#define PGKW_REINDEX 2022
#define PGKW_RELATIVE_P 2023
#define PGKW_RENAME 2024
#define PGKW_REPLACE 2025
#define PGKW_RESET 2026
#define PGKW_RESTART 2027
#define PGKW_RESTRICT 2028
#define PGKW_RETURNS 2029
#define PGKW_REVOKE 2030
#define PGKW_RIGHT 2031
#define PGKW_ROLLBACK 2032
#define PGKW_ROW 2033
#define PGKW_ROWS 2034
#define PGKW_RULE 2035
#define PGKW_SCHEMA 2036
#define PGKW_SCROLL 2037
#define PGKW_SECOND_P 2038
#define PGKW_SECURITY 2039
#define PGKW_SELECT 2040
#define PGKW_SEMICOLON 2041
#define PGKW_SEQUENCE 2042
#define PGKW_SERIALIZABLE 2043
#define PGKW_SESSION 2044
#define PGKW_SESSION_USER 2045
#define PGKW_SET 2046
#define PGKW_SETOF 2047
#define PGKW_SHARE 2048
#define PGKW_SHOW 2049
#define PGKW_SIMILAR 2050
#define PGKW_SIMPLE 2051
#define PGKW_SMALLINT 2052
#define PGKW_SOME 2053
#define PGKW_STABLE 2054
#define PGKW_STAR 2055
#define PGKW_START 2056
#define PGKW_STATEMENT 2057
#define PGKW_STATISTICS 2058
#define PGKW_STDIN 2059
#define PGKW_STDOUT 2060
#define PGKW_STORAGE 2061
#define PGKW_STRICT_P 2062
#define PGKW_SUBSTRING 2063
#define PGKW_SYSID 2064
#define PGKW_TABLE 2065
#define PGKW_TEMP 2066
#define PGKW_TEMPLATE 2067
#define PGKW_TEMPORARY 2068
#define PGKW_THEN 2069
#define PGKW_TIME 2070
#define PGKW_TIMESTAMP 2071
#define PGKW_TO 2072
#define PGKW_TOAST 2073
#define PGKW_TODAY_SYN 2074
#define PGKW_TRAILING 2075
#define PGKW_TRANSACTION 2076
#define PGKW_TREAT 2077
#define PGKW_TRIGGER 2078
#define PGKW_TRIM 2079
#define PGKW_TRUE_P 2080
#define PGKW_TRUNCATE 2081
#define PGKW_TRUSTED 2082
#define PGKW_TYPECAST 2083
#define PGKW_TYPE_P 2084
#define PGKW_UMINUS 2085
#define PGKW_UNENCRYPTED 2086
#define PGKW_UNION 2087
#define PGKW_UNIONJOIN 2088
#define PGKW_UNIQUE 2089
#define PGKW_UNKNOWN 2090
#define PGKW_UNLISTEN 2091
#define PGKW_UNLOAD 2092
#define PGKW_UNTIL 2093
#define PGKW_UPDATE 2094
#define PGKW_USAGE 2095
#define PGKW_USER 2096
#define PGKW_USING 2097
#define PGKW_VACUUM 2098
#define PGKW_VALID 2099
#define PGKW_VALIDATOR 2100
#define PGKW_VALUES 2101
#define PGKW_VARCHAR 2102
#define PGKW_VARYING 2103
#define PGKW_VERBOSE 2104
#define PGKW_VERSION 2105
#define PGKW_VIEW 2106
#define PGKW_VOLATILE 2107
#define PGKW_WHEN 2108
#define PGKW_WHERE 2109
#define PGKW_WITH 2110
#define PGKW_WITHOUT 2111
#define PGKW_WORK 2112
#define PGKW_WRITE 2113
#define PGKW_XCONST 2114
#define PGKW_YEAR_P 2115
#define PGKW_ZONE 2116
#define KW_TITLE 2117
#define KW_STYLE 2118
#define KW_ACTION 2119
#define KW_IDLE 2120
#define CANCEL_INSERT 2121
#define CANCEL_DELETE 2122
