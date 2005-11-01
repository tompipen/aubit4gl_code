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
#define ON_ACTION 1276
#define ON_EVERY_ROW 1277
#define OPEN_SESSION 1278
#define RIGHT_MARGIN 1279
#define SELECT_USING 1280
#define START_REPORT 1281
#define UNLOCK_TABLE 1282
#define UPDATE_USING 1283
#define ACL_BUILTIN 1284
#define AFTGROUP 1285
#define INFIDX 1286
#define INFSTAT 1287
#define LEFT_MARGIN 1288
#define PAGE_HEADER 1289
#define ROLLBACK_W 1290
#define SET_SESSION 1291
#define SQLSEOFF 1292
#define WITH_A_LOG 1293
#define BEFDISP 1294
#define BEFORE_MENU 1295
#define CREATE_VIEW 1296
#define DELETE_FROM 1297
#define END_DISPLAY 1298
#define END_REPORT 1299
#define END_FOREACH 1300
#define END_FOR 1301
#define END_GLOBALS 1302
#define EXIT_PROMPT 1303
#define EXTENT_SIZE 1304
#define FOREIGN_KEY 1305
#define HIDE_OPTION 1306
#define KW_HIDE_WINDOW 1307
#define INSERT_INTO 1308
#define IS_SERIAL 1309
#define IS_NOT_NULL 1310
#define MOVE_WINDOW 1311
#define NEXT_OPTION 1312
#define NOT_MATCHES 1313
#define ON_LAST_ROW 1314
#define OPEN_WINDOW 1315
#define OPEN_STATUSBOX 1316
#define PAGE_LENGTH 1317
#define PAGE_WIDTH 1318
#define PRIMARY_KEY 1319
#define PROMPT_LINE 1320
#define RECORD_LIKE 1321
#define ROLLFORWARD 1322
#define SHOW_OPTION 1323
#define SHOW_WINDOW 1324
#define SQLSEON 1325
#define TO_DATABASE 1326
#define USE_SESSION 1327
#define WITH_NO_LOG 1328
#define AFTDISP 1329
#define BEFFIELD 1330
#define INSHARE 1331
#define UNLOCKTAB 1332
#define AFTFIELD 1333
#define ATTRIBUTES 1334
#define BEFINP 1335
#define BEFORE_DISPLAY 1336
#define BEGIN_WORK 1337
#define CLEARWIN 1338
#define CLOSE_FORM 1339
#define DEFER_QUIT 1340
#define DESCENDING 1341
#define DROP_INDEX 1342
#define END_PROMPT 1343
#define END_RECORD 1344
#define ERROR_LINE 1345
#define EXIT_INPUT 1346
#define EXIT_WHILE 1347
#define FOR_UPDATE_OF 1348
#define FOR_UPDATE 1349
#define GET_FLDBUF 1350
#define INITIALIZE 1351
#define INPUT_WRAP 1352
#define LOCK_TABLE 1353
#define MSG_LINE 1354
#define NOT_EXISTS 1355
#define ON_ANY_KEY 1356
#define REFERENCES 1357
#define RENCOL 1358
#define SET_CURSOR 1359
#define SMALLFLOAT 1360
#define SQLSUCCESS 1361
#define TOP_MARGIN 1362
#define WITH_ARRAY 1363
#define ACCEPTKEY 1364
#define KW_ACCEPT 1365
#define AFTINP 1366
#define AFTER_DISPLAY 1367
#define CLEARFORMTODEFAULTS 1368
#define CLEARFORM 1369
#define CLEAR_X_FORM 1370
#define COMMIT_W 1371
#define KW_NEXTPAGE 1372
#define KW_PREVPAGE 1373
#define KW_CTRL_KEY 1374
#define INFTABS 1375
#define NEXTFIELD 1376
#define NEXTFORM 1377
#define RENTAB 1378
#define ASCENDING 1379
#define ASSOCIATE 1380
#define KW_CHAR 1381
#define NCHAR 1382
#define NVARCHAR 1383
#define CONSTRUCT 1384
#define DELIMITER 1385
#define DOWNSHIFT 1386
#define DROP_VIEW 1387
#define END_INPUT 1388
#define END_WHILE 1389
#define EXCLUSIVE 1390
#define EXIT_CASE 1391
#define EXIT_MENU 1392
#define FORM_LINE 1393
#define GREATER_THAN_EQ 1394
#define KW_INTERRUPT 1395
#define INTO_TEMP 1396
#define INVISIBLE 1397
#define IN_MEMORY 1398
#define LINKED_TO 1399
#define LOAD_FROM 1400
#define LOCKTAB 1401
#define MENU_LINE 1402
#define OPEN_FORM 1403
#define OTHERWISE 1404
#define PRECISION 1405
#define KW_PRIOR 1406
#define PROCEDURE 1407
#define REPORT_TO 1408
#define RETURNING 1409
#define UNDERLINE 1410
#define UNLOAD_TO 1411
#define BEFROW 1412
#define UNLOAD_T 1413
#define VARIABLE_ATTRIBUTES 1414
#define VARIABLE 1415
#define KW_ABSOLUTE 1416
#define AFTROW 1417
#define BUFFERED 1418
#define KW_CONSTANT 1419
#define KW_CONST 1420
#define DATABASE 1421
#define DATETIME 1422
#define DEFAULTS 1423
#define DISTINCT 1424
#define END_CASE 1425
#define END_MAIN 1426
#define END_MENU 1427
#define END_TYPE 1428
#define EXIT_FOR 1429
#define EXTERNAL 1430
#define FRACTION 1431
#define FUNCTION 1432
#define GROUP_BY 1433
#define INTERVAL 1434
#define KWMESSAGE 1435
#define NOT_LIKE 1436
#define NOT_ILIKE 1437
#define NOT_NULL 1438
#define PASSWORD 1439
#define KW_PREVIOUS 1440
#define READONLY 1441
#define REGISTER 1442
#define KW_RELATIVE 1443
#define RESOURCE 1444
#define SMALLINT 1445
#define VALIDATE 1446
#define WITH_LOG 1447
#define WORDWRAP 1448
#define BY_NAME 1449
#define IN_FILE 1450
#define IS_NULL 1451
#define LESS_THAN_EQ 1452
#define AVERAGE 1453
#define BETWEEN 1454
#define CAPTION 1455
#define CLIPPED 1456
#define CLOSE_BRACKET 1457
#define COLUMNS 1458
#define COMMAND 1459
#define CONNECT 1460
#define KW_CURRENT 1461
#define DBYNAME 1462
#define KW_DECIMAL 1463
#define DECLARE 1464
#define DEFAULT 1465
#define KW_DISPLAY 1466
#define ENDCODE 1467
#define EXECUTE 1468
#define FOREACH 1469
#define FOREIGN 1470
#define GLOBALS 1471
#define INFIELD 1472
#define INTEGER 1473
#define KWWINDOW 1474
#define MAGENTA 1475
#define MATCHES 1476
#define OPTIONS 1477
#define PERCENT 1478
#define PREPARE 1479
#define PROGRAM 1480
#define RECOVER 1481
#define REVERSE 1482
#define SECTION 1483
#define SESSION 1484
#define SYNONYM 1485
#define THRU 1486
#define TRAILER 1487
#define UPSHIFT 1488
#define VARCHAR 1489
#define WAITING 1490
#define CLOSE_SHEV 1491
#define CLOSE_SQUARE 1492
#define GREATER_THAN 1493
#define KW_FALSE 1494
#define NOT_IN 1495
#define ONKEY 1496
#define OPEN_BRACKET 1497
#define BORDER 1498
#define BOTTOM 1499
#define COLUMN 1500
#define COMMIT 1501
#define CREATE 1502
#define CURSOR 1503
#define DEFINE 1504
#define KW_DELETE 1505
#define KW_DOUBLE 1506
#define END_IF 1507
#define KW_ESCAPE 1508
#define EXISTS 1509
#define EXTEND 1510
#define EXTENT 1511
#define FINISH 1512
#define FORMAT 1513
#define HAVING 1514
#define HEADER 1515
#define KW_INSERT 1516
#define LOCATE 1517
#define MARGIN 1518
#define MEMORY 1519
#define MINUTE 1520
#define MODIFY 1521
#define NORMAL 1522
#define EQUAL_EQUAL 1523
#define NOT_EQUAL 1524
#define OPEN_SHEV 1525
#define OPEN_SQUARE 1526
#define OPTION 1527
#define OUTPUT 1528
#define PROMPT 1529
#define PUBLIC 1530
#define RECORD 1531
#define REPORT 1532
#define REVOKE 1533
#define SCHEMA 1534
#define SCROLL_USING 1535
#define SCROLL 1536
#define SECOND 1537
#define KW_SELECT 1538
#define SERIAL 1539
#define SHARED 1540
#define SPACES 1541
#define UNIQUE 1542
#define UNLOCK 1543
#define KW_UPDATE 1544
#define VALUES 1545
#define YELLOW 1546
#define AFTER 1547
#define KWLINE 1548
#define KW_NULL 1549
#define KW_TRUE 1550
#define KW_SINGLE_KEY 1551
#define ALTER 1552
#define ARRAY 1553
#define ASCII 1554
#define AUDIT 1555
#define BLACK 1556
#define BLINK 1557
#define CHECK 1558
#define CLEAR 1559
#define CLOSE 1560
#define CODE_C 1561
#define COUNT 1562
#define DEFER 1563
#define KW_ERROR 1564
#define EVERY 1565
#define FETCH 1566
#define KW_FIRST 1567
#define KW_FLOAT 1568
#define FLUSH 1569
#define FOUND 1570
#define GRANT 1571
#define GREEN 1572
#define KW_GROUP 1573
#define INDEX 1574
#define KWFORM 1575
#define LABEL 1576
#define LESS_THAN 1577
#define LOCAL 1578
#define MONEY 1579
#define MONTH 1580
#define POWER 1581
#define MULTIPLY 1582
#define ORDER 1583
#define OUTER 1584
#define PAUSE 1585
#define PRINT_IMAGE 1586
#define PRINT_FILE 1587
#define PRINT 1588
#define KW_RIGHT 1589
#define DOUBLE_COLON 1590
#define SEMICOLON 1591
#define SLEEP 1592
#define TUPLE 1593
#define UNION 1594
#define KW_USING 1595
#define WHERE 1596
#define WHILE 1597
#define WHITE 1598
#define CCODE 1599
#define ANSI 1600
#define BLUE 1601
#define BOLD 1602
#define KW_BYTE 1603
#define FCALL 1604
#define CASE 1605
#define CYAN 1606
#define KW_DATE 1607
#define DESC 1608
#define DIVIDE 1609
#define KWDOWN 1610
#define KW_TAB 1611
#define DROP 1612
#define ELSE 1613
#define EXEC 1614
#define EXIT 1615
#define FREE 1616
#define FROM 1617
#define GOTO 1618
#define HELP_FILE 1619
#define LANG_FILE 1620
#define KW_HELP 1621
#define HIDE 1622
#define HOUR 1623
#define INTO 1624
#define KW_LAST 1625
#define KW_LEFT 1626
#define LIKE 1627
#define MAIN 1628
#define MENU 1629
#define MODE 1630
#define NEED 1631
#define KW_NEXT 1632
#define NOCR 1633
#define OPEN 1634
#define QUIT 1635
#define REAL 1636
#define ROWS 1637
#define SHOW 1638
#define KW_SIZE 1639
#define SKIP 1640
#define SOME 1641
#define STEP 1642
#define STOP 1643
#define TEMP 1644
#define KW_TEXT 1645
#define THEN 1646
#define USER 1647
#define WAIT 1648
#define WHEN 1649
#define WITH 1650
#define WORK 1651
#define YEAR 1652
#define KW_DOW 1653
#define EQUAL 1654
#define KW_IS 1655
#define XSET 1656
#define ADD 1657
#define ALL 1658
#define KW_AND 1659
#define ANY 1660
#define ASC 1661
#define AVG 1662
#define COLON 1663
#define KW_COMMA 1664
#define DAY 1665
#define DBA 1666
#define DEC 1667
#define DIM 1668
#define KW_FKEY 1669
#define FOR 1670
#define KEY 1671
#define KWNO 1672
#define LET 1673
#define LOG 1674
#define XMAX 1675
#define XMIN 1676
#define MINUS 1677
#define MOD 1678
#define NOT 1679
#define PAD 1680
#define PUT 1681
#define RED 1682
#define ROW 1683
#define KW_RUN 1684
#define SQL 1685
#define SUM 1686
#define TOP 1687
#define USE 1688
#define ATSIGN 1689
#define PLUS 1690
#define AS_TIFF 1691
#define AS_GIF 1692
#define AS_PNG 1693
#define AS_JPEG 1694
#define AS 1695
#define AT 1696
#define BY 1697
#define DOT 1698
#define GO 1699
#define IF 1700
#define KW_IN 1701
#define OF 1702
#define ON 1703
#define KW_OR 1704
#define TO 1705
#define KWUP 1706
#define FONT_NAME 1707
#define FONT_SIZE 1708
#define PAPER_SIZE_IS_LETTER 1709
#define PAPER_SIZE_IS_LEGAL 1710
#define PAPER_SIZE_IS_A5 1711
#define PAPER_SIZE_IS_A4 1712
#define PAPER_SIZE_IS_LETTER_L 1713
#define PAPER_SIZE_IS_LEGAL_L 1714
#define PAPER_SIZE_IS_A5_L 1715
#define PAPER_SIZE_IS_A4_L 1716
#define FORMHANDLER 1717
#define END_FORMHANDLER 1718
#define BEFORE_EVENT 1719
#define BEFORE_OPEN_FORM 1720
#define AFTER_EVENT 1721
#define BEFORE_CLOSE_FORM 1722
#define BEFORE_ANY 1723
#define AFTER_ANY 1724
#define MENUHANDLER 1725
#define END_MENUHANDLER 1726
#define BEFORE_SHOW_MENU 1727
#define DISABLE_PROGRAM 1728
#define DISABLE_ALL 1729
#define BUTTONS 1730
#define CHECK_MENUITEM 1731
#define DISABLE_FORM 1732
#define DISABLE_MENUITEMS 1733
#define DISABLE 1734
#define ENABLE_FORM 1735
#define ENABLE_MENUITEMS 1736
#define ENABLE 1737
#define KWFIELD 1738
#define ICON 1739
#define MESSAGEBOX 1740
#define TO_DEFAULTS 1741
#define UNCHECK_MENUITEM 1742
#define ABSOLUTE 1743
#define BEFORE 1744
#define KW_INPUT 1745
#define FINPUT 1746
#define END 1747
#define INT_TO_ID 1748
#define TIMEOUT 1749
#define KW_OFF 1750
#define WITH_1_DIMENSION 1751
#define WITH_2_DIMENSION 1752
#define WITH_3_DIMENSION 1753
#define TILDE 1754
#define ILIKE 1755
#define FGL_ISDYNARR_ALLOCATED 1756
#define FGL_DYNARR_EXTENTSIZE 1757
#define FILLFACTOR 1758
#define END_CLASS 1759
#define KW_CLASS 1760
#define EXTENDS 1761
#define KW_PIPE 1762
#define TIME 1763
#define KWBEGIN 1764
#define TRACE 1765
#define SITENAME 1766
#define DBSERVERNAME 1767
#define SYSTEM 1768
#define EXCEPTION 1769
#define KW_TODAY 1770
#define PGKW_ABORT_P 1771
#define PGKW_ABSOLUTE_P 1772
#define PGKW_ACCESS 1773
#define PGKW_ACTION 1774
#define PGKW_ADD 1775
#define PGKW_AFTER 1776
#define PGKW_AGGREGATE 1777
#define PGKW_ALL 1778
#define PGKW_ALTER 1779
#define PGKW_ANALYSE 1780
#define PGKW_ANALYZE 1781
#define PGKW_AND 1782
#define PGKW_ANY 1783
#define PGKW_ARRAY 1784
#define PGKW_AS 1785
#define PGKW_ASC 1786
#define PGKW_ASSERTION 1787
#define PGKW_ASSIGNMENT 1788
#define PGKW_AT 1789
#define PGKW_AUTHORIZATION 1790
#define PGKW_BACKWARD 1791
#define PGKW_BCONST 1792
#define PGKW_BEFORE 1793
#define PGKW_BEGIN_P 1794
#define PGKW_BETWEEN 1795
#define PGKW_BIGINT 1796
#define PGKW_BINARY 1797
#define PGKW_BIT 1798
#define PGKW_BOOLEAN_P 1799
#define PGKW_BOTH 1800
#define PGKW_BY 1801
#define PGKW_CACHE 1802
#define PGKW_CALLED 1803
#define PGKW_CARAT 1804
#define PGKW_CASCADE 1805
#define PGKW_CASE 1806
#define PGKW_CAST 1807
#define PGKW_CHAIN 1808
#define PGKW_CHARACTER 1809
#define PGKW_CHARACTERISTICS 1810
#define PGKW_CHAR_P 1811
#define PGKW_CHECK 1812
#define PGKW_CHECKPOINT 1813
#define PGKW_CLASS 1814
#define PGKW_CLOSE 1815
#define PGKW_CLOSE_BRACKET 1816
#define PGKW_CLOSE_SQUARE 1817
#define PGKW_CLUSTER 1818
#define PGKW_COALESCE 1819
#define PGKW_COLLATE 1820
#define PGKW_COLON 1821
#define PGKW_COLUMN 1822
#define PGKW_COMMA 1823
#define PGKW_COMMENT 1824
#define PGKW_COMMIT 1825
#define PGKW_COMMITTED 1826
#define PGKW_CONSTRAINT 1827
#define PGKW_CONSTRAINTS 1828
#define PGKW_CONVERSION_P 1829
#define PGKW_CONVERT 1830
#define PGKW_COPY 1831
#define PGKW_CREATE 1832
#define PGKW_CREATEDB 1833
#define PGKW_CREATEUSER 1834
#define PGKW_CROSS 1835
#define PGKW_CURRENT 1836
#define PGKW_CURRENT_DATE 1837
#define PGKW_CURRENT_TIME 1838
#define PGKW_CURRENT_TIMESTAMP 1839
#define PGKW_CURRENT_USER 1840
#define PGKW_CURSOR 1841
#define PGKW_CYCLE 1842
#define PGKW_DATABASE 1843
#define PGKW_DATETIME 1844
#define PGKW_DAY_P 1845
#define PGKW_DBA 1846
#define PGKW_DEALLOCATE 1847
#define PGKW_DEC 1848
#define PGKW_DECIMAL_P 1849
#define PGKW_DECLARE 1850
#define PGKW_DEFAULT 1851
#define PGKW_DEFAULTS 1852
#define PGKW_DEFERRABLE 1853
#define PGKW_DEFERRED 1854
#define PGKW_DEFINER 1855
#define PGKW_DELETE_P 1856
#define PGKW_DELIMITER 1857
#define PGKW_DELIMITERS 1858
#define PGKW_DESC 1859
#define PGKW_DISTINCT 1860
#define PGKW_DIVIDE 1861
#define PGKW_DO 1862
#define PGKW_DOMAIN_P 1863
#define PGKW_DOT 1864
#define PGKW_DOUBLE_P 1865
#define PGKW_DROP 1866
#define PGKW_EACH 1867
#define PGKW_ELSE 1868
#define PGKW_ENCODING 1869
#define PGKW_ENCRYPTED 1870
#define PGKW_END_P 1871
#define PGKW_EQUAL 1872
#define PGKW_ESCAPE 1873
#define PGKW_EXCEPT 1874
#define PGKW_EXCLUDING 1875
#define PGKW_EXCLUSIVE 1876
#define PGKW_EXECUTE 1877
#define PGKW_EXISTS 1878
#define PGKW_EXPLAIN 1879
#define PGKW_EXTEND 1880
#define PGKW_EXTERNAL 1881
#define PGKW_EXTRACT 1882
#define PGKW_FALSE_P 1883
#define PGKW_FETCH 1884
#define PGKW_FIRST_P 1885
#define PGKW_FLOAT_P 1886
#define PGKW_FOR 1887
#define PGKW_FORCE 1888
#define PGKW_FOREIGN 1889
#define PGKW_FORWARD 1890
#define PGKW_FREEZE 1891
#define PGKW_FROM 1892
#define PGKW_FULL 1893
#define PGKW_FUNCTION 1894
#define PGKW_GLOBAL 1895
#define PGKW_GRANT 1896
#define PGKW_GREATER_THAN 1897
#define PGKW_GROUP_P 1898
#define PGKW_HANDLER 1899
#define PGKW_HAVING 1900
#define PGKW_HOLD 1901
#define PGKW_HOUR_P 1902
#define PGKW_ILIKE 1903
#define PGKW_IMMEDIATE 1904
#define PGKW_IMMUTABLE 1905
#define PGKW_IMPLICIT_P 1906
#define PGKW_INCLUDING 1907
#define PGKW_INCREMENT 1908
#define PGKW_INDEX 1909
#define PGKW_INHERITS 1910
#define PGKW_INITIALLY 1911
#define PGKW_INNER_P 1912
#define PGKW_INOUT 1913
#define PGKW_IN_P 1914
#define PGKW_INPUT_P 1915
#define PGKW_INSENSITIVE 1916
#define PGKW_INSERT 1917
#define PGKW_INSTEAD 1918
#define PGKW_INTEGER 1919
#define PGKW_INTERSECT 1920
#define PGKW_INTERVAL 1921
#define PGKW_INTO 1922
#define PGKW_INT_P 1923
#define PGKW_INVOKER 1924
#define PGKW_IS 1925
#define PGKW_ISNULL 1926
#define PGKW_ISOLATION 1927
#define PGKW_JOIN 1928
#define PGKW_KEY 1929
#define PGKW_LANCOMPILER 1930
#define PGKW_LANGUAGE 1931
#define PGKW_LAST_P 1932
#define PGKW_LEADING 1933
#define PGKW_LEFT 1934
#define PGKW_LESS_THAN 1935
#define PGKW_LEVEL 1936
#define PGKW_LIKE 1937
#define PGKW_LIMIT 1938
#define PGKW_LISTEN 1939
#define PGKW_LOAD 1940
#define PGKW_LOCAL 1941
#define PGKW_LOCALTIME 1942
#define PGKW_LOCALTIMESTAMP 1943
#define PGKW_LOCATION 1944
#define PGKW_LOCK_P 1945
#define PGKW_MATCH 1946
#define PGKW_MAXVALUE 1947
#define PGKW_MINUS 1948
#define PGKW_MINUTE_P 1949
#define PGKW_MINVALUE 1950
#define PGKW_MODE 1951
#define PGKW_MODIFY 1952
#define PGKW_MONTH_P 1953
#define PGKW_MOVE 1954
#define PGKW_NAMES 1955
#define PGKW_NATIONAL 1956
#define PGKW_NATURAL 1957
#define PGKW_NCHAR 1958
#define PGKW_NEW 1959
#define PGKW_NEXT 1960
#define PGKW_NO 1961
#define PGKW_NOCREATEDB 1962
#define PGKW_NOCREATEUSER 1963
#define PGKW_NONE 1964
#define PGKW_NOT 1965
#define PGKW_NOTHING 1966
#define PGKW_NOTIFY 1967
#define PGKW_NOTNULL 1968
#define PGKW_NULLIF 1969
#define PGKW_NULL_P 1970
#define PGKW_NUMERIC 1971
#define PGKW_OF 1972
#define PGKW_OFF 1973
#define PGKW_OFFSET 1974
#define PGKW_OIDS 1975
#define PGKW_OLD 1976
#define PGKW_ON 1977
#define PGKW_ONLY 1978
#define PGKW_OPEN_BRACKET 1979
#define PGKW_OPEN_SQUARE 1980
#define PGKW_OPERATOR 1981
#define PGKW_OPTION 1982
#define PGKW_OR 1983
#define PGKW_ORDER 1984
#define PGKW_OUTER_P 1985
#define PGKW_OUT_P 1986
#define PGKW_OVERLAPS 1987
#define PGKW_OVERLAY 1988
#define PGKW_OWNER 1989
#define PGKW_PARAM 1990
#define PGKW_PARTIAL 1991
#define PGKW_PASSWORD 1992
#define PGKW_PATH_P 1993
#define PGKW_PENDANT 1994
#define PGKW_PERCENT 1995
#define PGKW_PLACING 1996
#define PGKW_PLUS 1997
#define PGKW_POSITION 1998
#define PGKW_POSTFIXOP 1999
#define PGKW_PRECISION 2000
#define PGKW_PREPARE 2001
#define PGKW_PRESERVE 2002
#define PGKW_PRIMARY 2003
#define PGKW_PRIOR 2004
#define PGKW_PRIVILEGES 2005
#define PGKW_PROCEDURAL 2006
#define PGKW_PROCEDURE 2007
#define PGKW_READ 2008
#define PGKW_REAL 2009
#define PGKW_RECHECK 2010
#define PGKW_REFERENCES 2011
#define PGKW_REINDEX 2012
#define PGKW_RELATIVE_P 2013
#define PGKW_RENAME 2014
#define PGKW_REPLACE 2015
#define PGKW_RESET 2016
#define PGKW_RESTART 2017
#define PGKW_RESTRICT 2018
#define PGKW_RETURNS 2019
#define PGKW_REVOKE 2020
#define PGKW_RIGHT 2021
#define PGKW_ROLLBACK 2022
#define PGKW_ROW 2023
#define PGKW_ROWS 2024
#define PGKW_RULE 2025
#define PGKW_SCHEMA 2026
#define PGKW_SCROLL 2027
#define PGKW_SECOND_P 2028
#define PGKW_SECURITY 2029
#define PGKW_SELECT 2030
#define PGKW_SEMICOLON 2031
#define PGKW_SEQUENCE 2032
#define PGKW_SERIALIZABLE 2033
#define PGKW_SESSION 2034
#define PGKW_SESSION_USER 2035
#define PGKW_SET 2036
#define PGKW_SETOF 2037
#define PGKW_SHARE 2038
#define PGKW_SHOW 2039
#define PGKW_SIMILAR 2040
#define PGKW_SIMPLE 2041
#define PGKW_SMALLINT 2042
#define PGKW_SOME 2043
#define PGKW_STABLE 2044
#define PGKW_STAR 2045
#define PGKW_START 2046
#define PGKW_STATEMENT 2047
#define PGKW_STATISTICS 2048
#define PGKW_STDIN 2049
#define PGKW_STDOUT 2050
#define PGKW_STORAGE 2051
#define PGKW_STRICT_P 2052
#define PGKW_SUBSTRING 2053
#define PGKW_SYSID 2054
#define PGKW_TABLE 2055
#define PGKW_TEMP 2056
#define PGKW_TEMPLATE 2057
#define PGKW_TEMPORARY 2058
#define PGKW_THEN 2059
#define PGKW_TIME 2060
#define PGKW_TIMESTAMP 2061
#define PGKW_TO 2062
#define PGKW_TOAST 2063
#define PGKW_TODAY_SYN 2064
#define PGKW_TRAILING 2065
#define PGKW_TRANSACTION 2066
#define PGKW_TREAT 2067
#define PGKW_TRIGGER 2068
#define PGKW_TRIM 2069
#define PGKW_TRUE_P 2070
#define PGKW_TRUNCATE 2071
#define PGKW_TRUSTED 2072
#define PGKW_TYPECAST 2073
#define PGKW_TYPE_P 2074
#define PGKW_UMINUS 2075
#define PGKW_UNENCRYPTED 2076
#define PGKW_UNION 2077
#define PGKW_UNIONJOIN 2078
#define PGKW_UNIQUE 2079
#define PGKW_UNKNOWN 2080
#define PGKW_UNLISTEN 2081
#define PGKW_UNLOAD 2082
#define PGKW_UNTIL 2083
#define PGKW_UPDATE 2084
#define PGKW_USAGE 2085
#define PGKW_USER 2086
#define PGKW_USING 2087
#define PGKW_VACUUM 2088
#define PGKW_VALID 2089
#define PGKW_VALIDATOR 2090
#define PGKW_VALUES 2091
#define PGKW_VARCHAR 2092
#define PGKW_VARYING 2093
#define PGKW_VERBOSE 2094
#define PGKW_VERSION 2095
#define PGKW_VIEW 2096
#define PGKW_VOLATILE 2097
#define PGKW_WHEN 2098
#define PGKW_WHERE 2099
#define PGKW_WITH 2100
#define PGKW_WITHOUT 2101
#define PGKW_WORK 2102
#define PGKW_WRITE 2103
#define PGKW_XCONST 2104
#define PGKW_YEAR_P 2105
#define PGKW_ZONE 2106
#define KW_TITLE 2107
#define KW_STYLE 2108