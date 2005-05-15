struct s_kw {
    int id;
	   int mode;
    char *vals[20];
    char *name;
};
#define MEMBER_FUNCTION 1000
#define TRACE_PROCEDURE 1001
#define RAISE_EXCEPTION 1002
#define WITH_HOLD_FOR 1003
#define CREATE_PROCEDURE 1004
#define WITH_RESUME 1005
#define TRACE_ON 1006
#define END_PROCEDURE 1007
#define END_EXCEPTION 1008
#define REFERENCES_BYTE 1009
#define REFERENCES_TEXT 1010
#define TRACE_OFF 1011
#define EMULATE_INSERT_CURSOR_FOR 1012
#define DEFINE_GLOBAL 1013
#define MISC_INFX_SQL 1014
#define PRAGMA 1015
#define MDY 1016
#define WEEKDAY 1017
#define SYSTEM_4GL 1018
#define SQL_FEATURE 1019
#define CONVERTING_TO_PIPE 1020
#define CONVERTING_TO_FILE 1021
#define CONVERTING_TO_PRINTER 1022
#define CONVERTING_TO_EMAIL 1023
#define KW_CHANNEL_READ 1024
#define KW_CHANNEL_WRITE 1025
#define AS_CONVERTABLE 1026
#define FREE_REPORT 1027
#define CONVERTING_TO_MANY 1028
#define CONVERTING_TO 1029
#define CONVERT_REPORT 1030
#define DATETIME_VALUE 1031
#define INTERVAL_VALUE 1032
#define RECOVER_TABLE 1033
#define ROLLFORWARD_DATABASE 1034
#define IN_LINE_MODE 1035
#define IN_FORM_MODE 1036
#define FGL_SIZEOF 1037
#define FGL_ADDRESSOF 1038
#define IMPORT_PACKAGE 1039
#define DYNAMIC_ARRAY 1040
#define RESIZE_ARRAY 1041
#define ALLOCATE_ARRAY 1042
#define DEALLOCATE_ARRAY 1043
#define AFTER_INSERT_DELETE 1044
#define BEFORE_INSERT_DELETE 1045
#define BEFORE_INSERT 1046
#define CONCAT_PIPES 1047
#define BEFORE_DELETE 1048
#define DROP_TRIGGER 1049
#define DROP_AUDIT_FOR 1050
#define CREATE_AUDIT_FOR 1051
#define AFTER_INSERT 1052
#define AFTER_DELETE 1053
#define EXECUTE_IMMEDIATE 1054
#define DELETE_ROW_EQUAL_TRUE 1055
#define INSERT_ROW_EQUAL_TRUE 1056
#define DELETE_ROW_EQUAL_FALSE 1057
#define INSERT_ROW_EQUAL_FALSE 1058
#define CURRENT_ROW_DISPLAY_EQUAL 1059
#define MAXCOUNT 1060
#define ALTER_TABLE 1061
#define ALTER_INDEX 1062
#define NEXT_SIZE 1063
#define DISPLAY_ATTR_FORM 1064
#define DISPLAY_ATTR_WINDOW 1065
#define INPUT_ATTR_FORM 1066
#define INPUT_ATTR_WINDOW 1067
#define WHENEVER_ERROR_CONTINUE 1068
#define WHENEVER_ANY_ERROR_CONTINUE 1069
#define WHENEVER_WARNING_CONTINUE 1070
#define WHENEVER_SQLSUCCESS_CONTINUE 1071
#define WHENEVER_SQLWARNING_CONTINUE 1072
#define WHENEVER_NOT_FOUND_CONTINUE 1073
#define WHENEVER_SQLERROR_CONTINUE 1074
#define WHENEVER_SUCCESS_CONTINUE 1075
#define WHENEVER_ERROR_GOTO 1076
#define WHENEVER_ANY_ERROR_GOTO 1077
#define WHENEVER_WARNING_GOTO 1078
#define WHENEVER_SQLSUCCESS_GOTO 1079
#define WHENEVER_SQLWARNING_GOTO 1080
#define WHENEVER_NOT_FOUND_GOTO 1081
#define WHENEVER_SQLERROR_GOTO 1082
#define WHENEVER_SUCCESS_GOTO 1083
#define WHENEVER_ERROR_CALL 1084
#define WHENEVER_ANY_ERROR_CALL 1085
#define WHENEVER_WARNING_CALL 1086
#define WHENEVER_SQLSUCCESS_CALL 1087
#define WHENEVER_SQLWARNING_CALL 1088
#define WHENEVER_NOT_FOUND_CALL 1089
#define WHENEVER_SQLERROR_CALL 1090
#define WHENEVER_SUCCESS_CALL 1091
#define WHENEVER_ERROR_STOP 1092
#define WHENEVER_ANY_ERROR_STOP 1093
#define WHENEVER_WARNING_STOP 1094
#define WHENEVER_SQLSUCCESS_STOP 1095
#define WHENEVER_SQLWARNING_STOP 1096
#define WHENEVER_NOT_FOUND_STOP 1097
#define WHENEVER_SQLERROR_STOP 1098
#define WHENEVER_SUCCESS_STOP 1099
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1100
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1101
#define XSET_ident_DOT_MULTIPLY_EQUAL 1102
#define XSET_MULTIPLY_EQUAL 1103
#define XSET_OPEN_BRACKET 1104
#define NEWFORMATSHARED 1105
#define DEFINE_NEW_TYPE 1106
#define CREATE_DATABASE 1107
#define DROP_DATABASE 1108
#define IMPORT_LEGACY_FUNCTION 1109
#define ADD_CONSTRAINT 1110
#define DROP_CONSTRAINT 1111
#define DROP_SYNONYM 1112
#define CONSTRAINT 1113
#define AS_STATIC 1114
#define NOT_FIELD_TOUCHED 1115
#define LOCAL_FUNCTION 1116
#define EVERY_ROW 1117
#define ELIF 1118
#define DOUBLE_PRECISION 1119
#define COUNT_MULTIPLY 1120
#define WAIT_FOR_KEY 1121
#define AT_TERMINATION_CALL 1122
#define TERMINATE_REPORT 1123
#define TO_MAIN_CAPTION 1124
#define CLEARSTAT 1125
#define TO_MENUITEM 1126
#define ID_TO_INT 1127
#define TO_STATUSBOX 1128
#define ASCII_HEIGHT_ALL 1129
#define ASCII_WIDTH_ALL 1130
#define IMPORT_DATATYPE 1131
#define PAGE_TRAILER_SIZE 1132
#define PAGE_HEADER_SIZE 1133
#define FIRST_PAGE_HEADER_SIZE 1134
#define BYTES_USE_AS_IMAGE 1135
#define BYTES_USE_AS_ASCII 1136
#define KWUP_BY 1137
#define KWDOWN_BY 1138
#define CLOSE_STATUSBOX 1139
#define MODIFY_NEXT_SIZE 1140
#define LOCK_MODE_PAGE 1141
#define LOCK_MODE_ROW 1142
#define TO_PIPE 1143
#define TO_FILE 1144
#define TO_SCREEN 1145
#define TO_PRINTER 1146
#define TO_EMAIL 1147
#define STATUSBOX 1148
#define UNITS_YEAR 1149
#define UNITS_MONTH 1150
#define UNITS_DAY 1151
#define UNITS_HOUR 1152
#define UNITS_MINUTE 1153
#define UNITS_SECOND 1154
#define NO_NEW_LINES 1155
#define FIELDTOWIDGET 1156
#define WITH_HOLD 1157
#define SHOW_MENU 1158
#define TO_CLUSTER 1159
#define TO_NOT_CLUSTER 1160
#define CWIS 1161
#define CREATE_UC_IDX 1162
#define CREATE_U_IDX 1163
#define CREATE_C_IDX 1164
#define CREATE_IDX 1165
#define FORM_IS_COMPILED 1166
#define PDF_REPORT 1167
#define IMPORT_FUNCTION 1168
#define PROMPT_MANY 1169
#define KW_POINTS 1170
#define MM 1171
#define INCHES 1172
#define PREPEND 1173
#define MEMBER_OF 1174
#define APPEND 1175
#define TEMPLATE 1176
#define END_TEMPLATE 1177
#define SQLSICS 1178
#define CREATE_SCHEMA 1179
#define SQLSIRR 1180
#define UPDATESTATS_T 1181
#define SQLSICR 1182
#define WHENEVER_SQLSUCCESS 1183
#define WHENEVER_SQLWARNING 1184
#define WHENEVER_ANY_ERROR 1185
#define WHENEVER_NOT_FOUND 1186
#define WHENEVER_SQLERROR 1187
#define WHENEVER_SUCCESS 1188
#define WHENEVER_ERROR 1189
#define START_EXTERN 1190
#define CONTINUE_CONSTRUCT 1191
#define FOUNCONSTR 1192
#define SQLSIDR 1193
#define CREATE_TEMP_TABLE 1194
#define CURRENT_WINDOW_IS 1195
#define FIRST_PAGE_HEADER 1196
#define ORDER_EXTERNAL_BY 1197
#define SCROLL_CURSOR_FOR 1198
#define SCROLL_CURSOR 1199
#define SQL_INTERRUPT_OFF 1200
#define STOP_ALL_EXTERNAL 1201
#define WITH_CHECK_OPTION 1202
#define WITH_GRANT_OPTION 1203
#define SQLSLMNW 1204
#define ADDCONSTUNIQ 1205
#define CONTINUE_DISPLAY 1206
#define CONTINUE_FOREACH 1207
#define OUTPUT_TO_REPORT 1208
#define SQL_INTERRUPT_ON 1209
#define WHERE_CURRENT_OF 1210
#define WITHOUT_DEFAULTS 1211
#define FOCONSTR 1212
#define SCALED_BY 1213
#define CONTINUE_PROMPT 1214
#define PDF_FUNCTION 1215
#define DEFER_INTERRUPT 1216
#define DISPLAY_BY_NAME 1217
#define NOT_NULL_UNIQUE 1218
#define SKIP_TO_TOP 1219
#define TOP_OF_PAGE 1220
#define SKIP_TO 1221
#define SKIP_BY 1222
#define WITHOUT_WAITING 1223
#define BEFCONSTRUCT 1224
#define SQLSLMW 1225
#define AFTCONSTRUCT 1226
#define ALL_PRIVILEGES 1227
#define CLOSE_DATABASE 1228
#define CONTINUE_INPUT 1229
#define CONTINUE_WHILE 1230
#define CREATE_SYNONYM 1231
#define DROP_TABLE 1232
#define EXIT_CONSTRUCT 1233
#define INEXCLUSIVE 1234
#define REPORT_TO_PRINTER 1235
#define REPORT_TO_PIPE 1236
#define KW_RETURN 1237
#define SET_SESSION_TO 1238
#define UPDATESTATS 1239
#define WITHOUT_HEAD 1240
#define CLEARSCR 1241
#define WITH_B_LOG 1242
#define AUTHORIZATION 1243
#define BOTTOM_MARGIN 1244
#define CLOSE_SESSION 1245
#define CONTINUE_CASE 1246
#define CONTINUE_MENU 1247
#define DISPLAY_ARRAY 1248
#define END_SQL 1249
#define DOLLAR 1250
#define END_CONSTRUCT 1251
#define FIELD_TOUCHED 1252
#define FINISH_REPORT 1253
#define INFACC 1254
#define INPUT_NO_WRAP 1255
#define SETPMOFF 1256
#define UNCONSTRAINED 1257
#define PAGE_TRAILER 1258
#define SETPMON 1259
#define BEFGROUP 1260
#define CLOSE_WINDOW 1261
#define COMMENT_LINE 1262
#define CONTINUE_FOR 1263
#define CREATE_DB 1264
#define CREATE_TABLE 1265
#define DEFAULT_NULL 1266
#define DEFAULT_TODAY 1267
#define DEFAULT_USER 1268
#define DELETE_USING 1269
#define DISPLAY_FORM 1270
#define END_FUNCTION 1271
#define EXIT_DISPLAY 1272
#define EXIT_FOREACH 1273
#define EXIT_PROGRAM 1274
#define INFCOLS 1275
#define ON_EVERY_ROW 1276
#define OPEN_SESSION 1277
#define RIGHT_MARGIN 1278
#define SELECT_USING 1279
#define START_REPORT 1280
#define UNLOCK_TABLE 1281
#define UPDATE_USING 1282
#define ACL_BUILTIN 1283
#define AFTGROUP 1284
#define INFIDX 1285
#define INFSTAT 1286
#define LEFT_MARGIN 1287
#define PAGE_HEADER 1288
#define ROLLBACK_W 1289
#define SET_SESSION 1290
#define SQLSEOFF 1291
#define WITH_A_LOG 1292
#define BEFDISP 1293
#define BEFORE_MENU 1294
#define CREATE_VIEW 1295
#define DELETE_FROM 1296
#define END_DISPLAY 1297
#define END_REPORT 1298
#define END_FOREACH 1299
#define END_FOR 1300
#define END_GLOBALS 1301
#define EXIT_PROMPT 1302
#define EXTENT_SIZE 1303
#define FOREIGN_KEY 1304
#define HIDE_OPTION 1305
#define KW_HIDE_WINDOW 1306
#define INSERT_INTO 1307
#define IS_SERIAL 1308
#define IS_NOT_NULL 1309
#define MOVE_WINDOW 1310
#define NEXT_OPTION 1311
#define NOT_MATCHES 1312
#define ON_LAST_ROW 1313
#define OPEN_WINDOW 1314
#define OPEN_STATUSBOX 1315
#define PAGE_LENGTH 1316
#define PAGE_WIDTH 1317
#define PRIMARY_KEY 1318
#define PROMPT_LINE 1319
#define RECORD_LIKE 1320
#define ROLLFORWARD 1321
#define SHOW_OPTION 1322
#define SHOW_WINDOW 1323
#define SQLSEON 1324
#define TO_DATABASE 1325
#define USE_SESSION 1326
#define WITH_NO_LOG 1327
#define AFTDISP 1328
#define BEFFIELD 1329
#define INSHARE 1330
#define UNLOCKTAB 1331
#define AFTFIELD 1332
#define ATTRIBUTES 1333
#define BEFINP 1334
#define BEGIN_WORK 1335
#define CLEARWIN 1336
#define CLOSE_FORM 1337
#define DEFER_QUIT 1338
#define DESCENDING 1339
#define DROP_INDEX 1340
#define END_PROMPT 1341
#define END_RECORD 1342
#define ERROR_LINE 1343
#define EXIT_INPUT 1344
#define EXIT_WHILE 1345
#define FOR_UPDATE_OF 1346
#define FOR_UPDATE 1347
#define GET_FLDBUF 1348
#define INITIALIZE 1349
#define INPUT_WRAP 1350
#define LOCK_TABLE 1351
#define MSG_LINE 1352
#define NOT_EXISTS 1353
#define ON_ANY_KEY 1354
#define REFERENCES 1355
#define RENCOL 1356
#define SET_CURSOR 1357
#define SMALLFLOAT 1358
#define SQLSUCCESS 1359
#define TOP_MARGIN 1360
#define WITH_ARRAY 1361
#define ACCEPTKEY 1362
#define KW_ACCEPT 1363
#define AFTINP 1364
#define CLEARFORMTODEFAULTS 1365
#define CLEARFORM 1366
#define CLEAR_X_FORM 1367
#define COMMIT_W 1368
#define KW_NEXTPAGE 1369
#define KW_PREVPAGE 1370
#define KW_CTRL_KEY 1371
#define INFTABS 1372
#define NEXTFIELD 1373
#define NEXTFORM 1374
#define RENTAB 1375
#define ASCENDING 1376
#define ASSOCIATE 1377
#define KW_CHAR 1378
#define NCHAR 1379
#define NVARCHAR 1380
#define CONSTRUCT 1381
#define DELIMITER 1382
#define DOWNSHIFT 1383
#define DROP_VIEW 1384
#define END_INPUT 1385
#define END_WHILE 1386
#define EXCLUSIVE 1387
#define EXIT_CASE 1388
#define EXIT_MENU 1389
#define FORM_LINE 1390
#define GREATER_THAN_EQ 1391
#define KW_INTERRUPT 1392
#define INTO_TEMP 1393
#define INVISIBLE 1394
#define IN_MEMORY 1395
#define LINKED_TO 1396
#define LOAD_FROM 1397
#define LOCKTAB 1398
#define MENU_LINE 1399
#define OPEN_FORM 1400
#define OTHERWISE 1401
#define PRECISION 1402
#define KW_PRIOR 1403
#define PROCEDURE 1404
#define REPORT_TO 1405
#define RETURNING 1406
#define UNDERLINE 1407
#define UNLOAD_TO 1408
#define BEFROW 1409
#define UNLOAD_T 1410
#define VARIABLE 1411
#define KW_ABSOLUTE 1412
#define AFTROW 1413
#define BUFFERED 1414
#define KW_CONSTANT 1415
#define KW_CONST 1416
#define DATABASE 1417
#define DATETIME 1418
#define DEFAULTS 1419
#define DISTINCT 1420
#define END_CASE 1421
#define END_MAIN 1422
#define END_MENU 1423
#define END_TYPE 1424
#define EXIT_FOR 1425
#define EXTERNAL 1426
#define FRACTION 1427
#define FUNCTION 1428
#define GROUP_BY 1429
#define INTERVAL 1430
#define KWMESSAGE 1431
#define NOT_LIKE 1432
#define NOT_ILIKE 1433
#define NOT_NULL 1434
#define PASSWORD 1435
#define KW_PREVIOUS 1436
#define READONLY 1437
#define REGISTER 1438
#define KW_RELATIVE 1439
#define RESOURCE 1440
#define SMALLINT 1441
#define VALIDATE 1442
#define WITH_LOG 1443
#define WORDWRAP 1444
#define BY_NAME 1445
#define IN_FILE 1446
#define IS_NULL 1447
#define LESS_THAN_EQ 1448
#define AVERAGE 1449
#define BETWEEN 1450
#define CAPTION 1451
#define CLIPPED 1452
#define CLOSE_BRACKET 1453
#define COLUMNS 1454
#define COMMAND 1455
#define CONNECT 1456
#define KW_CURRENT 1457
#define DBYNAME 1458
#define KW_DECIMAL 1459
#define DECLARE 1460
#define DEFAULT 1461
#define KW_DISPLAY 1462
#define ENDCODE 1463
#define EXECUTE 1464
#define FOREACH 1465
#define FOREIGN 1466
#define GLOBALS 1467
#define INFIELD 1468
#define INTEGER 1469
#define KWWINDOW 1470
#define MAGENTA 1471
#define MATCHES 1472
#define OPTIONS 1473
#define PERCENT 1474
#define PREPARE 1475
#define PROGRAM 1476
#define RECOVER 1477
#define REVERSE 1478
#define SECTION 1479
#define SESSION 1480
#define SYNONYM 1481
#define THRU 1482
#define TRAILER 1483
#define UPSHIFT 1484
#define VARCHAR 1485
#define WAITING 1486
#define CLOSE_SHEV 1487
#define CLOSE_SQUARE 1488
#define GREATER_THAN 1489
#define KW_FALSE 1490
#define NOT_IN 1491
#define ONKEY 1492
#define OPEN_BRACKET 1493
#define BORDER 1494
#define BOTTOM 1495
#define COLUMN 1496
#define COMMIT 1497
#define CREATE 1498
#define CURSOR 1499
#define DEFINE 1500
#define KW_DELETE 1501
#define KW_DOUBLE 1502
#define END_IF 1503
#define KW_ESCAPE 1504
#define ESCAPE 1505
#define EXISTS 1506
#define EXTEND 1507
#define EXTENT 1508
#define FINISH 1509
#define FORMAT 1510
#define HAVING 1511
#define HEADER 1512
#define KW_INSERT 1513
#define LOCATE 1514
#define MARGIN 1515
#define MEMORY 1516
#define MINUTE 1517
#define MODIFY 1518
#define NORMAL 1519
#define EQUAL_EQUAL 1520
#define NOT_EQUAL 1521
#define OPEN_SHEV 1522
#define OPEN_SQUARE 1523
#define OPTION 1524
#define OUTPUT 1525
#define PROMPT 1526
#define PUBLIC 1527
#define RECORD 1528
#define REPORT 1529
#define REVOKE 1530
#define SCHEMA 1531
#define SCROLL_USING 1532
#define SCROLL 1533
#define SECOND 1534
#define KW_SELECT 1535
#define SERIAL 1536
#define SHARED 1537
#define SPACES 1538
#define UNIQUE 1539
#define UNLOCK 1540
#define KW_UPDATE 1541
#define VALUES 1542
#define YELLOW 1543
#define AFTER 1544
#define KWLINE 1545
#define KW_NULL 1546
#define KW_TRUE 1547
#define KW_SINGLE_KEY 1548
#define ALTER 1549
#define ARRAY 1550
#define ASCII 1551
#define AUDIT 1552
#define BLACK 1553
#define BLINK 1554
#define CHECK 1555
#define CLEAR 1556
#define CLOSE 1557
#define CODE_C 1558
#define COUNT 1559
#define DEFER 1560
#define KW_ERROR 1561
#define EVERY 1562
#define FETCH 1563
#define KW_FIRST 1564
#define KW_FLOAT 1565
#define FLUSH 1566
#define FOUND 1567
#define GRANT 1568
#define GREEN 1569
#define KW_GROUP 1570
#define INDEX 1571
#define KWFORM 1572
#define LABEL 1573
#define LESS_THAN 1574
#define LOCAL 1575
#define MONEY 1576
#define MONTH 1577
#define POWER 1578
#define MULTIPLY 1579
#define ORDER 1580
#define OUTER 1581
#define PAUSE 1582
#define PRINT_IMAGE 1583
#define PRINT_FILE 1584
#define PRINT 1585
#define KW_RIGHT 1586
#define DOUBLE_COLON 1587
#define SEMICOLON 1588
#define SLEEP 1589
#define TUPLE 1590
#define UNION 1591
#define KW_USING 1592
#define WHERE 1593
#define WHILE 1594
#define WHITE 1595
#define CCODE 1596
#define ANSI 1597
#define BLUE 1598
#define BOLD 1599
#define KW_BYTE 1600
#define FCALL 1601
#define CASE 1602
#define CYAN 1603
#define KW_DATE 1604
#define DESC 1605
#define DIVIDE 1606
#define KWDOWN 1607
#define KW_TAB 1608
#define DROP 1609
#define ELSE 1610
#define EXEC 1611
#define EXIT 1612
#define FREE 1613
#define FROM 1614
#define GOTO 1615
#define HELP_FILE 1616
#define LANG_FILE 1617
#define KW_HELP 1618
#define HIDE 1619
#define HOUR 1620
#define INTO 1621
#define KW_LAST 1622
#define KW_LEFT 1623
#define LIKE 1624
#define MAIN 1625
#define MENU 1626
#define MODE 1627
#define NEED 1628
#define KW_NEXT 1629
#define NOCR 1630
#define OPEN 1631
#define QUIT 1632
#define REAL 1633
#define ROWS 1634
#define SHOW 1635
#define KW_SIZE 1636
#define SKIP 1637
#define SOME 1638
#define STEP 1639
#define STOP 1640
#define TEMP 1641
#define KW_TEXT 1642
#define THEN 1643
#define USER 1644
#define WAIT 1645
#define WHEN 1646
#define WITH 1647
#define WORK 1648
#define YEAR 1649
#define KW_DOW 1650
#define EQUAL 1651
#define KW_IS 1652
#define XSET 1653
#define ADD 1654
#define ALL 1655
#define KW_AND 1656
#define ANY 1657
#define ASC 1658
#define AVG 1659
#define COLON 1660
#define KW_COMMA 1661
#define DAY 1662
#define DBA 1663
#define DEC 1664
#define DIM 1665
#define KW_FKEY 1666
#define FOR 1667
#define KEY 1668
#define KWNO 1669
#define LET 1670
#define LOG 1671
#define XMAX 1672
#define XMIN 1673
#define MINUS 1674
#define MOD 1675
#define NOT 1676
#define PAD 1677
#define PUT 1678
#define RED 1679
#define ROW 1680
#define KW_RUN 1681
#define SQL 1682
#define SUM 1683
#define TOP 1684
#define USE 1685
#define ATSIGN 1686
#define PLUS 1687
#define AS_TIFF 1688
#define AS_GIF 1689
#define AS_PNG 1690
#define AS_JPEG 1691
#define AS 1692
#define AT 1693
#define BY 1694
#define DOT 1695
#define GO 1696
#define IF 1697
#define KW_IN 1698
#define OF 1699
#define ON 1700
#define KW_OR 1701
#define TO 1702
#define KWUP 1703
#define FONT_NAME 1704
#define FONT_SIZE 1705
#define PAPER_SIZE_IS_LETTER 1706
#define PAPER_SIZE_IS_LEGAL 1707
#define PAPER_SIZE_IS_A5 1708
#define PAPER_SIZE_IS_A4 1709
#define PAPER_SIZE_IS_LETTER_L 1710
#define PAPER_SIZE_IS_LEGAL_L 1711
#define PAPER_SIZE_IS_A5_L 1712
#define PAPER_SIZE_IS_A4_L 1713
#define FORMHANDLER 1714
#define END_FORMHANDLER 1715
#define BEFORE_EVENT 1716
#define BEFORE_OPEN_FORM 1717
#define AFTER_EVENT 1718
#define BEFORE_CLOSE_FORM 1719
#define BEFORE_ANY 1720
#define AFTER_ANY 1721
#define MENUHANDLER 1722
#define END_MENUHANDLER 1723
#define BEFORE_SHOW_MENU 1724
#define DISABLE_PROGRAM 1725
#define DISABLE_ALL 1726
#define BUTTONS 1727
#define CHECK_MENUITEM 1728
#define DISABLE_FORM 1729
#define DISABLE_MENUITEMS 1730
#define DISABLE 1731
#define ENABLE_FORM 1732
#define ENABLE_MENUITEMS 1733
#define ENABLE 1734
#define KWFIELD 1735
#define ICON 1736
#define MESSAGEBOX 1737
#define TO_DEFAULTS 1738
#define UNCHECK_MENUITEM 1739
#define ABSOLUTE 1740
#define BEFORE 1741
#define KW_INPUT 1742
#define FINPUT 1743
#define END 1744
#define INT_TO_ID 1745
#define TIMEOUT 1746
#define KW_OFF 1747
#define WITH_1_DIMENSION 1748
#define WITH_2_DIMENSION 1749
#define WITH_3_DIMENSION 1750
#define TILDE 1751
#define ILIKE 1752
#define FGL_ISDYNARR_ALLOCATED 1753
#define FGL_DYNARR_EXTENTSIZE 1754
#define FILLFACTOR 1755
#define END_CLASS 1756
#define KW_CLASS 1757
#define EXTENDS 1758
#define KW_PIPE 1759
#define TIME 1760
#define KWBEGIN 1761
#define TRACE 1762
#define SITENAME 1763
#define DBSERVERNAME 1764
#define SYSTEM 1765
#define EXCEPTION 1766
#define KW_TODAY 1767
#define PGKW_ABORT_P 1768
#define PGKW_ABSOLUTE_P 1769
#define PGKW_ACCESS 1770
#define PGKW_ACTION 1771
#define PGKW_ADD 1772
#define PGKW_AFTER 1773
#define PGKW_AGGREGATE 1774
#define PGKW_ALL 1775
#define PGKW_ALTER 1776
#define PGKW_ANALYSE 1777
#define PGKW_ANALYZE 1778
#define PGKW_AND 1779
#define PGKW_ANY 1780
#define PGKW_ARRAY 1781
#define PGKW_AS 1782
#define PGKW_ASC 1783
#define PGKW_ASSERTION 1784
#define PGKW_ASSIGNMENT 1785
#define PGKW_AT 1786
#define PGKW_AUTHORIZATION 1787
#define PGKW_BACKWARD 1788
#define PGKW_BCONST 1789
#define PGKW_BEFORE 1790
#define PGKW_BEGIN_P 1791
#define PGKW_BETWEEN 1792
#define PGKW_BIGINT 1793
#define PGKW_BINARY 1794
#define PGKW_BIT 1795
#define PGKW_BOOLEAN_P 1796
#define PGKW_BOTH 1797
#define PGKW_BY 1798
#define PGKW_CACHE 1799
#define PGKW_CALLED 1800
#define PGKW_CARAT 1801
#define PGKW_CASCADE 1802
#define PGKW_CASE 1803
#define PGKW_CAST 1804
#define PGKW_CHAIN 1805
#define PGKW_CHARACTER 1806
#define PGKW_CHARACTERISTICS 1807
#define PGKW_CHAR_P 1808
#define PGKW_CHECK 1809
#define PGKW_CHECKPOINT 1810
#define PGKW_CLASS 1811
#define PGKW_CLOSE 1812
#define PGKW_CLOSE_BRACKET 1813
#define PGKW_CLOSE_SQUARE 1814
#define PGKW_CLUSTER 1815
#define PGKW_COALESCE 1816
#define PGKW_COLLATE 1817
#define PGKW_COLON 1818
#define PGKW_COLUMN 1819
#define PGKW_COMMA 1820
#define PGKW_COMMENT 1821
#define PGKW_COMMIT 1822
#define PGKW_COMMITTED 1823
#define PGKW_CONSTRAINT 1824
#define PGKW_CONSTRAINTS 1825
#define PGKW_CONVERSION_P 1826
#define PGKW_CONVERT 1827
#define PGKW_COPY 1828
#define PGKW_CREATE 1829
#define PGKW_CREATEDB 1830
#define PGKW_CREATEUSER 1831
#define PGKW_CROSS 1832
#define PGKW_CURRENT 1833
#define PGKW_CURRENT_DATE 1834
#define PGKW_CURRENT_TIME 1835
#define PGKW_CURRENT_TIMESTAMP 1836
#define PGKW_CURRENT_USER 1837
#define PGKW_CURSOR 1838
#define PGKW_CYCLE 1839
#define PGKW_DATABASE 1840
#define PGKW_DATETIME 1841
#define PGKW_DAY_P 1842
#define PGKW_DBA 1843
#define PGKW_DEALLOCATE 1844
#define PGKW_DEC 1845
#define PGKW_DECIMAL_P 1846
#define PGKW_DECLARE 1847
#define PGKW_DEFAULT 1848
#define PGKW_DEFAULTS 1849
#define PGKW_DEFERRABLE 1850
#define PGKW_DEFERRED 1851
#define PGKW_DEFINER 1852
#define PGKW_DELETE_P 1853
#define PGKW_DELIMITER 1854
#define PGKW_DELIMITERS 1855
#define PGKW_DESC 1856
#define PGKW_DISTINCT 1857
#define PGKW_DIVIDE 1858
#define PGKW_DO 1859
#define PGKW_DOMAIN_P 1860
#define PGKW_DOT 1861
#define PGKW_DOUBLE_P 1862
#define PGKW_DROP 1863
#define PGKW_EACH 1864
#define PGKW_ELSE 1865
#define PGKW_ENCODING 1866
#define PGKW_ENCRYPTED 1867
#define PGKW_END_P 1868
#define PGKW_EQUAL 1869
#define PGKW_ESCAPE 1870
#define PGKW_EXCEPT 1871
#define PGKW_EXCLUDING 1872
#define PGKW_EXCLUSIVE 1873
#define PGKW_EXECUTE 1874
#define PGKW_EXISTS 1875
#define PGKW_EXPLAIN 1876
#define PGKW_EXTEND 1877
#define PGKW_EXTERNAL 1878
#define PGKW_EXTRACT 1879
#define PGKW_FALSE_P 1880
#define PGKW_FETCH 1881
#define PGKW_FIRST_P 1882
#define PGKW_FLOAT_P 1883
#define PGKW_FOR 1884
#define PGKW_FORCE 1885
#define PGKW_FOREIGN 1886
#define PGKW_FORWARD 1887
#define PGKW_FREEZE 1888
#define PGKW_FROM 1889
#define PGKW_FULL 1890
#define PGKW_FUNCTION 1891
#define PGKW_GLOBAL 1892
#define PGKW_GRANT 1893
#define PGKW_GREATER_THAN 1894
#define PGKW_GROUP_P 1895
#define PGKW_HANDLER 1896
#define PGKW_HAVING 1897
#define PGKW_HOLD 1898
#define PGKW_HOUR_P 1899
#define PGKW_ILIKE 1900
#define PGKW_IMMEDIATE 1901
#define PGKW_IMMUTABLE 1902
#define PGKW_IMPLICIT_P 1903
#define PGKW_INCLUDING 1904
#define PGKW_INCREMENT 1905
#define PGKW_INDEX 1906
#define PGKW_INHERITS 1907
#define PGKW_INITIALLY 1908
#define PGKW_INNER_P 1909
#define PGKW_INOUT 1910
#define PGKW_IN_P 1911
#define PGKW_INPUT_P 1912
#define PGKW_INSENSITIVE 1913
#define PGKW_INSERT 1914
#define PGKW_INSTEAD 1915
#define PGKW_INTEGER 1916
#define PGKW_INTERSECT 1917
#define PGKW_INTERVAL 1918
#define PGKW_INTO 1919
#define PGKW_INT_P 1920
#define PGKW_INVOKER 1921
#define PGKW_IS 1922
#define PGKW_ISNULL 1923
#define PGKW_ISOLATION 1924
#define PGKW_JOIN 1925
#define PGKW_KEY 1926
#define PGKW_LANCOMPILER 1927
#define PGKW_LANGUAGE 1928
#define PGKW_LAST_P 1929
#define PGKW_LEADING 1930
#define PGKW_LEFT 1931
#define PGKW_LESS_THAN 1932
#define PGKW_LEVEL 1933
#define PGKW_LIKE 1934
#define PGKW_LIMIT 1935
#define PGKW_LISTEN 1936
#define PGKW_LOAD 1937
#define PGKW_LOCAL 1938
#define PGKW_LOCALTIME 1939
#define PGKW_LOCALTIMESTAMP 1940
#define PGKW_LOCATION 1941
#define PGKW_LOCK_P 1942
#define PGKW_MATCH 1943
#define PGKW_MAXVALUE 1944
#define PGKW_MINUS 1945
#define PGKW_MINUTE_P 1946
#define PGKW_MINVALUE 1947
#define PGKW_MODE 1948
#define PGKW_MODIFY 1949
#define PGKW_MONTH_P 1950
#define PGKW_MOVE 1951
#define PGKW_NAMES 1952
#define PGKW_NATIONAL 1953
#define PGKW_NATURAL 1954
#define PGKW_NCHAR 1955
#define PGKW_NEW 1956
#define PGKW_NEXT 1957
#define PGKW_NO 1958
#define PGKW_NOCREATEDB 1959
#define PGKW_NOCREATEUSER 1960
#define PGKW_NONE 1961
#define PGKW_NOT 1962
#define PGKW_NOTHING 1963
#define PGKW_NOTIFY 1964
#define PGKW_NOTNULL 1965
#define PGKW_NULLIF 1966
#define PGKW_NULL_P 1967
#define PGKW_NUMERIC 1968
#define PGKW_OF 1969
#define PGKW_OFF 1970
#define PGKW_OFFSET 1971
#define PGKW_OIDS 1972
#define PGKW_OLD 1973
#define PGKW_ON 1974
#define PGKW_ONLY 1975
#define PGKW_OPEN_BRACKET 1976
#define PGKW_OPEN_SQUARE 1977
#define PGKW_OPERATOR 1978
#define PGKW_OPTION 1979
#define PGKW_OR 1980
#define PGKW_ORDER 1981
#define PGKW_OUTER_P 1982
#define PGKW_OUT_P 1983
#define PGKW_OVERLAPS 1984
#define PGKW_OVERLAY 1985
#define PGKW_OWNER 1986
#define PGKW_PARAM 1987
#define PGKW_PARTIAL 1988
#define PGKW_PASSWORD 1989
#define PGKW_PATH_P 1990
#define PGKW_PENDANT 1991
#define PGKW_PERCENT 1992
#define PGKW_PLACING 1993
#define PGKW_PLUS 1994
#define PGKW_POSITION 1995
#define PGKW_POSTFIXOP 1996
#define PGKW_PRECISION 1997
#define PGKW_PREPARE 1998
#define PGKW_PRESERVE 1999
#define PGKW_PRIMARY 2000
#define PGKW_PRIOR 2001
#define PGKW_PRIVILEGES 2002
#define PGKW_PROCEDURAL 2003
#define PGKW_PROCEDURE 2004
#define PGKW_READ 2005
#define PGKW_REAL 2006
#define PGKW_RECHECK 2007
#define PGKW_REFERENCES 2008
#define PGKW_REINDEX 2009
#define PGKW_RELATIVE_P 2010
#define PGKW_RENAME 2011
#define PGKW_REPLACE 2012
#define PGKW_RESET 2013
#define PGKW_RESTART 2014
#define PGKW_RESTRICT 2015
#define PGKW_RETURNS 2016
#define PGKW_REVOKE 2017
#define PGKW_RIGHT 2018
#define PGKW_ROLLBACK 2019
#define PGKW_ROW 2020
#define PGKW_ROWS 2021
#define PGKW_RULE 2022
#define PGKW_SCHEMA 2023
#define PGKW_SCROLL 2024
#define PGKW_SECOND_P 2025
#define PGKW_SECURITY 2026
#define PGKW_SELECT 2027
#define PGKW_SEMICOLON 2028
#define PGKW_SEQUENCE 2029
#define PGKW_SERIALIZABLE 2030
#define PGKW_SESSION 2031
#define PGKW_SESSION_USER 2032
#define PGKW_SET 2033
#define PGKW_SETOF 2034
#define PGKW_SHARE 2035
#define PGKW_SHOW 2036
#define PGKW_SIMILAR 2037
#define PGKW_SIMPLE 2038
#define PGKW_SMALLINT 2039
#define PGKW_SOME 2040
#define PGKW_STABLE 2041
#define PGKW_STAR 2042
#define PGKW_START 2043
#define PGKW_STATEMENT 2044
#define PGKW_STATISTICS 2045
#define PGKW_STDIN 2046
#define PGKW_STDOUT 2047
#define PGKW_STORAGE 2048
#define PGKW_STRICT_P 2049
#define PGKW_SUBSTRING 2050
#define PGKW_SYSID 2051
#define PGKW_TABLE 2052
#define PGKW_TEMP 2053
#define PGKW_TEMPLATE 2054
#define PGKW_TEMPORARY 2055
#define PGKW_THEN 2056
#define PGKW_TIME 2057
#define PGKW_TIMESTAMP 2058
#define PGKW_TO 2059
#define PGKW_TOAST 2060
#define PGKW_TODAY_SYN 2061
#define PGKW_TRAILING 2062
#define PGKW_TRANSACTION 2063
#define PGKW_TREAT 2064
#define PGKW_TRIGGER 2065
#define PGKW_TRIM 2066
#define PGKW_TRUE_P 2067
#define PGKW_TRUNCATE 2068
#define PGKW_TRUSTED 2069
#define PGKW_TYPECAST 2070
#define PGKW_TYPE_P 2071
#define PGKW_UMINUS 2072
#define PGKW_UNENCRYPTED 2073
#define PGKW_UNION 2074
#define PGKW_UNIONJOIN 2075
#define PGKW_UNIQUE 2076
#define PGKW_UNKNOWN 2077
#define PGKW_UNLISTEN 2078
#define PGKW_UNLOAD 2079
#define PGKW_UNTIL 2080
#define PGKW_UPDATE 2081
#define PGKW_USAGE 2082
#define PGKW_USER 2083
#define PGKW_USING 2084
#define PGKW_VACUUM 2085
#define PGKW_VALID 2086
#define PGKW_VALIDATOR 2087
#define PGKW_VALUES 2088
#define PGKW_VARCHAR 2089
#define PGKW_VARYING 2090
#define PGKW_VERBOSE 2091
#define PGKW_VERSION 2092
#define PGKW_VIEW 2093
#define PGKW_VOLATILE 2094
#define PGKW_WHEN 2095
#define PGKW_WHERE 2096
#define PGKW_WITH 2097
#define PGKW_WITHOUT 2098
#define PGKW_WORK 2099
#define PGKW_WRITE 2100
#define PGKW_XCONST 2101
#define PGKW_YEAR_P 2102
#define PGKW_ZONE 2103
#define KW_TITLE 2104
#define KW_STYLE 2105
