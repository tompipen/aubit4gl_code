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
#define REPLACE_STRING 1012
#define STOP_REPLACE_STRING 1013
#define IGNORE_FUNCTION 1014
#define EMULATE_INSERT_CURSOR_FOR 1015
#define DEFINE_GLOBAL 1016
#define SET_BUFFERED_LOG 1017
#define SET_LOG 1018
#define PRAGMA 1019
#define MDY 1020
#define WEEKDAY 1021
#define SYSTEM_4GL 1022
#define SQL_FEATURE 1023
#define MISC_INFX_SQL 1024
#define CONVERTING_TO_PIPE 1025
#define CONVERTING_TO_FILE 1026
#define CONVERTING_TO_PRINTER 1027
#define CONVERTING_TO_EMAIL 1028
#define KW_CHANNEL_READ 1029
#define KW_CHANNEL_WRITE 1030
#define AS_CONVERTABLE 1031
#define FREE_REPORT 1032
#define CONVERTING_TO_MANY 1033
#define CONVERTING_TO 1034
#define CONVERT_REPORT 1035
#define DATETIME_VALUE 1036
#define INTERVAL_VALUE 1037
#define RECOVER_TABLE 1038
#define ROLLFORWARD_DATABASE 1039
#define IN_LINE_MODE 1040
#define IN_FORM_MODE 1041
#define FGL_SIZEOF 1042
#define FGL_ADDRESSOF 1043
#define IMPORT_PACKAGE 1044
#define DYNAMIC_ARRAY 1045
#define RESIZE_ARRAY 1046
#define ALLOCATE_ARRAY 1047
#define DEALLOCATE_ARRAY 1048
#define AFTER_INSERT_DELETE 1049
#define BEFORE_INSERT_DELETE 1050
#define BEFORE_INSERT 1051
#define CONCAT_PIPES 1052
#define BEFORE_DELETE 1053
#define DROP_TRIGGER 1054
#define DROP_AUDIT_FOR 1055
#define CREATE_AUDIT_FOR 1056
#define AFTER_INSERT 1057
#define AFTER_DELETE 1058
#define EXECUTE_IMMEDIATE 1059
#define EXECUTE_PROCEDURE 1060
#define DELETE_ROW_EQUAL_TRUE 1061
#define INSERT_ROW_EQUAL_TRUE 1062
#define DELETE_ROW_EQUAL_FALSE 1063
#define INSERT_ROW_EQUAL_FALSE 1064
#define CURRENT_ROW_DISPLAY_EQUAL 1065
#define MAXCOUNT 1066
#define ALTER_TABLE 1067
#define ALTER_INDEX 1068
#define NEXT_SIZE 1069
#define DISPLAY_ATTR_FORM 1070
#define DISPLAY_ATTR_WINDOW 1071
#define INPUT_ATTR_FORM 1072
#define INPUT_ATTR_WINDOW 1073
#define WHENEVER_ERROR_CONTINUE 1074
#define WHENEVER_ANY_ERROR_CONTINUE 1075
#define WHENEVER_WARNING_CONTINUE 1076
#define WHENEVER_SQLSUCCESS_CONTINUE 1077
#define WHENEVER_SQLWARNING_CONTINUE 1078
#define WHENEVER_NOT_FOUND_CONTINUE 1079
#define WHENEVER_SQLERROR_CONTINUE 1080
#define WHENEVER_SUCCESS_CONTINUE 1081
#define WHENEVER_ERROR_GOTO 1082
#define WHENEVER_ANY_ERROR_GOTO 1083
#define WHENEVER_WARNING_GOTO 1084
#define WHENEVER_SQLSUCCESS_GOTO 1085
#define WHENEVER_SQLWARNING_GOTO 1086
#define WHENEVER_NOT_FOUND_GOTO 1087
#define WHENEVER_SQLERROR_GOTO 1088
#define WHENEVER_SUCCESS_GOTO 1089
#define WHENEVER_ERROR_CALL 1090
#define WHENEVER_ANY_ERROR_CALL 1091
#define WHENEVER_WARNING_CALL 1092
#define WHENEVER_SQLSUCCESS_CALL 1093
#define WHENEVER_SQLWARNING_CALL 1094
#define WHENEVER_NOT_FOUND_CALL 1095
#define WHENEVER_SQLERROR_CALL 1096
#define WHENEVER_SUCCESS_CALL 1097
#define WHENEVER_ERROR_STOP 1098
#define WHENEVER_ANY_ERROR_STOP 1099
#define WHENEVER_WARNING_STOP 1100
#define WHENEVER_SQLSUCCESS_STOP 1101
#define WHENEVER_SQLWARNING_STOP 1102
#define WHENEVER_NOT_FOUND_STOP 1103
#define WHENEVER_SQLERROR_STOP 1104
#define WHENEVER_SUCCESS_STOP 1105
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1106
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1107
#define XSET_ident_DOT_MULTIPLY_EQUAL 1108
#define XSET_MULTIPLY_EQUAL 1109
#define XSET_OPEN_BRACKET 1110
#define NEWFORMATSHARED 1111
#define DEFINE_NEW_TYPE 1112
#define CREATE_DATABASE 1113
#define DROP_DATABASE 1114
#define IMPORT_LEGACY_FUNCTION 1115
#define ADD_CONSTRAINT 1116
#define DROP_CONSTRAINT 1117
#define DROP_SYNONYM 1118
#define CONSTRAINT 1119
#define AS_STATIC 1120
#define NOT_FIELD_TOUCHED 1121
#define LOCAL_FUNCTION 1122
#define EVERY_ROW 1123
#define ELIF 1124
#define KW_ARG_VAL 1125
#define DOUBLE_PRECISION 1126
#define COUNT_MULTIPLY 1127
#define WAIT_FOR_KEY 1128
#define AT_TERMINATION_CALL 1129
#define TERMINATE_REPORT 1130
#define TO_MAIN_CAPTION 1131
#define CLEARSTAT 1132
#define TO_MENUITEM 1133
#define ID_TO_INT 1134
#define TO_STATUSBOX 1135
#define ASCII_HEIGHT_ALL 1136
#define ASCII_WIDTH_ALL 1137
#define IMPORT_DATATYPE 1138
#define PAGE_TRAILER_SIZE 1139
#define PAGE_HEADER_SIZE 1140
#define FIRST_PAGE_HEADER_SIZE 1141
#define BYTES_USE_AS_IMAGE 1142
#define BYTES_USE_AS_ASCII 1143
#define KWUP_BY 1144
#define KWDOWN_BY 1145
#define CLOSE_STATUSBOX 1146
#define MODIFY_NEXT_SIZE 1147
#define LOCK_MODE_PAGE 1148
#define LOCK_MODE_ROW 1149
#define TO_PIPE 1150
#define TO_FILE 1151
#define TO_SCREEN 1152
#define TO_PRINTER 1153
#define TO_EMAIL 1154
#define STATUSBOX 1155
#define UNITS_YEAR 1156
#define UNITS_MONTH 1157
#define UNITS_DAY 1158
#define UNITS_HOUR 1159
#define UNITS_MINUTE 1160
#define UNITS_SECOND 1161
#define NO_NEW_LINES 1162
#define FIELDTOWIDGET 1163
#define WITH_HOLD 1164
#define SHOW_MENU 1165
#define TO_CLUSTER 1166
#define TO_NOT_CLUSTER 1167
#define CWIS 1168
#define CREATE_UC_IDX 1169
#define CREATE_U_IDX 1170
#define CREATE_C_IDX 1171
#define CREATE_IDX 1172
#define FORM_IS_COMPILED 1173
#define PDF_REPORT 1174
#define IMPORT_FUNCTION 1175
#define PROMPT_MANY 1176
#define KW_POINTS 1177
#define MM 1178
#define INCHES 1179
#define PREPEND 1180
#define MEMBER_OF 1181
#define APPEND 1182
#define TEMPLATE 1183
#define END_TEMPLATE 1184
#define SQLSICS 1185
#define CREATE_SCHEMA 1186
#define SQLSIRR 1187
#define UPDATESTATS_T 1188
#define SQLSICR 1189
#define WHENEVER_SQLSUCCESS 1190
#define WHENEVER_SQLWARNING 1191
#define WHENEVER_ANY_ERROR 1192
#define WHENEVER_NOT_FOUND 1193
#define WHENEVER_SQLERROR 1194
#define WHENEVER_SUCCESS 1195
#define WHENEVER_ERROR 1196
#define START_EXTERN 1197
#define CONTINUE_CONSTRUCT 1198
#define FOUNCONSTR 1199
#define SQLSIDR 1200
#define CREATE_TEMP_TABLE 1201
#define CURRENT_WINDOW_IS 1202
#define FIRST_PAGE_HEADER 1203
#define ORDER_EXTERNAL_BY 1204
#define SCROLL_CURSOR_FOR 1205
#define SCROLL_CURSOR 1206
#define SQL_INTERRUPT_OFF 1207
#define STOP_ALL_EXTERNAL 1208
#define WITH_CHECK_OPTION 1209
#define WITH_GRANT_OPTION 1210
#define SQLSLMNW 1211
#define ADDCONSTUNIQ 1212
#define CONTINUE_DISPLAY 1213
#define CONTINUE_FOREACH 1214
#define OUTPUT_TO_REPORT 1215
#define SQL_INTERRUPT_ON 1216
#define WHERE_CURRENT_OF 1217
#define WITHOUT_DEFAULTS 1218
#define FOCONSTR 1219
#define SCALED_BY 1220
#define CONTINUE_PROMPT 1221
#define PDF_FUNCTION 1222
#define DEFER_INTERRUPT 1223
#define DISPLAY_BY_NAME 1224
#define NOT_NULL_UNIQUE 1225
#define SKIP_TO_TOP 1226
#define TOP_OF_PAGE 1227
#define SKIP_TO 1228
#define SKIP_BY 1229
#define WITHOUT_WAITING 1230
#define BEFCONSTRUCT 1231
#define SQLSLMW 1232
#define AFTCONSTRUCT 1233
#define ALL_PRIVILEGES 1234
#define CLOSE_DATABASE 1235
#define CONTINUE_INPUT 1236
#define CONTINUE_WHILE 1237
#define CREATE_SYNONYM 1238
#define DROP_TABLE 1239
#define EXIT_CONSTRUCT 1240
#define INEXCLUSIVE 1241
#define REPORT_TO_PRINTER 1242
#define REPORT_TO_PIPE 1243
#define KW_RETURN 1244
#define SET_SESSION_TO 1245
#define UPDATESTATS 1246
#define WITHOUT_HEAD 1247
#define CLEARSCR 1248
#define WITH_B_LOG 1249
#define AUTHORIZATION 1250
#define BOTTOM_MARGIN 1251
#define CLOSE_SESSION 1252
#define CONTINUE_CASE 1253
#define CONTINUE_MENU 1254
#define DISPLAY_ARRAY 1255
#define END_SQL 1256
#define DOLLAR 1257
#define END_CONSTRUCT 1258
#define FIELD_TOUCHED 1259
#define FINISH_REPORT 1260
#define INFACC 1261
#define INPUT_NO_WRAP 1262
#define SETPMOFF 1263
#define UNCONSTRAINED 1264
#define PAGE_TRAILER 1265
#define SETPMON 1266
#define BEFGROUP 1267
#define CLOSE_WINDOW 1268
#define COMMENT_LINE 1269
#define CONTINUE_FOR 1270
#define CREATE_DB 1271
#define CREATE_TABLE 1272
#define DEFAULT_NULL 1273
#define DEFAULT_TODAY 1274
#define DEFAULT_USER 1275
#define DELETE_USING 1276
#define DISPLAY_FORM 1277
#define END_FUNCTION 1278
#define EXIT_DISPLAY 1279
#define EXIT_FOREACH 1280
#define EXIT_PROGRAM 1281
#define INFCOLS 1282
#define ON_EVERY_ROW 1283
#define OPEN_SESSION 1284
#define RIGHT_MARGIN 1285
#define SELECT_USING 1286
#define START_REPORT 1287
#define UNLOCK_TABLE 1288
#define UPDATE_USING 1289
#define ACL_BUILTIN 1290
#define AFTGROUP 1291
#define INFIDX 1292
#define INFSTAT 1293
#define LEFT_MARGIN 1294
#define PAGE_HEADER 1295
#define ROLLBACK_W 1296
#define SET_SESSION 1297
#define SQLSEON 1298
#define SQLSEOFF 1299
#define WITH_A_LOG 1300
#define BEFDISP 1301
#define BEFORE_MENU 1302
#define CREATE_VIEW 1303
#define DELETE_FROM 1304
#define END_DISPLAY 1305
#define END_REPORT 1306
#define END_FOREACH 1307
#define END_FOR 1308
#define END_GLOBALS 1309
#define EXIT_PROMPT 1310
#define EXTENT_SIZE 1311
#define FOREIGN_KEY 1312
#define HIDE_OPTION 1313
#define KW_HIDE_WINDOW 1314
#define INSERT_INTO 1315
#define IS_SERIAL 1316
#define IS_NOT_NULL 1317
#define MOVE_WINDOW 1318
#define NEXT_OPTION 1319
#define NOT_MATCHES 1320
#define ON_LAST_ROW 1321
#define OPEN_WINDOW 1322
#define OPEN_STATUSBOX 1323
#define PAGE_LENGTH 1324
#define PAGE_WIDTH 1325
#define PRIMARY_KEY 1326
#define PROMPT_LINE 1327
#define RECORD_LIKE 1328
#define ROLLFORWARD 1329
#define SHOW_OPTION 1330
#define SHOW_WINDOW 1331
#define TO_DATABASE 1332
#define USE_SESSION 1333
#define WITH_NO_LOG 1334
#define AFTDISP 1335
#define BEFFIELD 1336
#define INSHARE 1337
#define UNLOCKTAB 1338
#define AFTFIELD 1339
#define ATTRIBUTES 1340
#define BEFINP 1341
#define BEFORE_DISPLAY 1342
#define BEGIN_WORK 1343
#define CLEARWIN 1344
#define CLOSE_FORM 1345
#define DEFER_QUIT 1346
#define DESCENDING 1347
#define DROP_INDEX 1348
#define END_PROMPT 1349
#define END_RECORD 1350
#define ERROR_LINE 1351
#define EXIT_INPUT 1352
#define EXIT_WHILE 1353
#define FOR_UPDATE_OF 1354
#define FOR_UPDATE 1355
#define GET_FLDBUF 1356
#define INITIALIZE 1357
#define INPUT_WRAP 1358
#define LOCK_TABLE 1359
#define MSG_LINE 1360
#define NOT_EXISTS 1361
#define ON_ANY_KEY 1362
#define REFERENCES 1363
#define RENCOL 1364
#define SET_CURSOR 1365
#define SMALLFLOAT 1366
#define SQLSUCCESS 1367
#define TOP_MARGIN 1368
#define WITH_ARRAY 1369
#define ACCEPTKEY 1370
#define KW_ACCEPT 1371
#define AFTINP 1372
#define AFTER_DISPLAY 1373
#define CLEARFORMTODEFAULTS 1374
#define CLEARFORM 1375
#define CLEAR_X_FORM 1376
#define COMMIT_W 1377
#define KW_NEXTPAGE 1378
#define KW_PREVPAGE 1379
#define KW_CTRL_KEY 1380
#define INFTABS 1381
#define NEXTFIELD 1382
#define NEXTFORM 1383
#define RENTAB 1384
#define ASCENDING 1385
#define ASSOCIATE 1386
#define KW_CHAR 1387
#define NCHAR 1388
#define NVARCHAR 1389
#define CONSTRUCT 1390
#define DELIMITER 1391
#define DOWNSHIFT 1392
#define DROP_VIEW 1393
#define END_INPUT 1394
#define END_WHILE 1395
#define EXCLUSIVE 1396
#define EXIT_CASE 1397
#define EXIT_MENU 1398
#define FORM_LINE 1399
#define GREATER_THAN_EQ 1400
#define KW_INTERRUPT 1401
#define INTO_TEMP 1402
#define INVISIBLE 1403
#define IN_MEMORY 1404
#define LINKED_TO 1405
#define LOAD_FROM 1406
#define LOCKTAB 1407
#define MENU_LINE 1408
#define OPEN_FORM 1409
#define OTHERWISE 1410
#define PRECISION 1411
#define KW_PRIOR 1412
#define PROCEDURE 1413
#define REPORT_TO 1414
#define RETURNING 1415
#define UNDERLINE 1416
#define UNLOAD_TO 1417
#define BEFROW 1418
#define UNLOAD_T 1419
#define VARIABLE_ATTRIBUTES 1420
#define VARIABLE 1421
#define KW_ABSOLUTE 1422
#define AFTROW 1423
#define BUFFERED 1424
#define KW_CONSTANT 1425
#define KW_CONST 1426
#define DATABASE 1427
#define DATETIME 1428
#define DEFAULTS 1429
#define DISTINCT 1430
#define END_CASE 1431
#define END_MAIN 1432
#define END_MENU 1433
#define END_TYPE 1434
#define EXIT_FOR 1435
#define EXTERNAL 1436
#define FRACTION 1437
#define FUNCTION 1438
#define GROUP_BY 1439
#define INTERVAL 1440
#define KWMESSAGE 1441
#define NOT_LIKE 1442
#define NOT_ILIKE 1443
#define NOT_NULL 1444
#define PASSWORD 1445
#define KW_PREVIOUS 1446
#define READONLY 1447
#define REGISTER 1448
#define KW_RELATIVE 1449
#define RESOURCE 1450
#define SMALLINT 1451
#define VALIDATE 1452
#define WITH_LOG 1453
#define WORDWRAP 1454
#define BY_NAME 1455
#define IN_FILE 1456
#define IS_NULL 1457
#define LESS_THAN_EQ 1458
#define AVERAGE 1459
#define BETWEEN 1460
#define CAPTION 1461
#define CLIPPED 1462
#define CLOSE_BRACKET 1463
#define COLUMNS 1464
#define COMMAND 1465
#define CONNECT 1466
#define KW_CURRENT 1467
#define DBYNAME 1468
#define KW_DECIMAL 1469
#define DECLARE 1470
#define DEFAULT 1471
#define KW_DISPLAY 1472
#define ENDCODE 1473
#define EXECUTE 1474
#define FOREACH 1475
#define FOREIGN 1476
#define GLOBALS 1477
#define INFIELD 1478
#define INTEGER 1479
#define KWWINDOW 1480
#define MAGENTA 1481
#define MATCHES 1482
#define OPTIONS 1483
#define PERCENT 1484
#define PREPARE 1485
#define PROGRAM 1486
#define RECOVER 1487
#define REVERSE 1488
#define SECTION 1489
#define SESSION 1490
#define SYNONYM 1491
#define THRU 1492
#define TRAILER 1493
#define UPSHIFT 1494
#define VARCHAR 1495
#define WAITING 1496
#define CLOSE_SHEV 1497
#define CLOSE_SQUARE 1498
#define GREATER_THAN 1499
#define KW_FALSE 1500
#define NOT_IN 1501
#define ONKEY 1502
#define OPEN_BRACKET 1503
#define BORDER 1504
#define BOTTOM 1505
#define COLUMN 1506
#define COMMIT 1507
#define CREATE 1508
#define CURSOR 1509
#define DEFINE 1510
#define KW_DELETE 1511
#define KW_DOUBLE 1512
#define END_IF 1513
#define KW_ESCAPE 1514
#define EXISTS 1515
#define EXTEND 1516
#define EXTENT 1517
#define FINISH 1518
#define FORMAT 1519
#define HAVING 1520
#define HEADER 1521
#define KW_INSERT 1522
#define LOCATE 1523
#define MARGIN 1524
#define MEMORY 1525
#define MINUTE 1526
#define MODIFY 1527
#define NORMAL 1528
#define EQUAL 1529
#define NOT_EQUAL 1530
#define OPEN_SHEV 1531
#define OPEN_SQUARE 1532
#define OPTION 1533
#define OUTPUT 1534
#define PROMPT 1535
#define PUBLIC 1536
#define RECORD 1537
#define REPORT 1538
#define REVOKE 1539
#define SCHEMA 1540
#define SCROLL_USING 1541
#define SCROLL 1542
#define SECOND 1543
#define IDLE_SECONDS 1544
#define IDLE_MINUTES 1545
#define IDLE_HOURS 1546
#define KW_SELECT 1547
#define SERIAL 1548
#define SHARED 1549
#define SPACES 1550
#define UNIQUE 1551
#define UNLOCK 1552
#define KW_UPDATE 1553
#define VALUES 1554
#define YELLOW 1555
#define AFTER 1556
#define KWLINE 1557
#define KW_NULL 1558
#define KW_TRUE 1559
#define KW_SINGLE_KEY 1560
#define ALTER 1561
#define ARRAY 1562
#define ASCII 1563
#define AUDIT 1564
#define BLACK 1565
#define BLINK 1566
#define CHECK 1567
#define CLEAR 1568
#define CLOSE 1569
#define CODE_C 1570
#define COUNT 1571
#define DEFER 1572
#define KW_ERROR 1573
#define EVERY 1574
#define FETCH 1575
#define KW_FIRST 1576
#define KW_FLOAT 1577
#define FLUSH 1578
#define FOUND 1579
#define GRANT 1580
#define GREEN 1581
#define KW_GROUP 1582
#define INDEX 1583
#define KWFORM 1584
#define LABEL 1585
#define LESS_THAN 1586
#define LOCAL 1587
#define MONEY 1588
#define MONTH 1589
#define POWER 1590
#define MULTIPLY 1591
#define ORDER 1592
#define OUTER 1593
#define PAUSE 1594
#define PRINT_IMAGE 1595
#define PRINT_FILE 1596
#define PRINT 1597
#define KW_RIGHT 1598
#define DOUBLE_COLON 1599
#define SEMICOLON 1600
#define SLEEP 1601
#define TUPLE 1602
#define UNION 1603
#define KW_USING 1604
#define WHERE 1605
#define WHILE 1606
#define WHITE 1607
#define CCODE 1608
#define ANSI 1609
#define BLUE 1610
#define BOLD 1611
#define KW_BYTE 1612
#define FCALL 1613
#define CASE 1614
#define CYAN 1615
#define KW_DATE 1616
#define DESC 1617
#define DIVIDE 1618
#define KWDOWN 1619
#define KW_TAB 1620
#define DROP 1621
#define ELSE 1622
#define EXEC 1623
#define EXIT 1624
#define FREE 1625
#define FROM 1626
#define GOTO 1627
#define HELP_FILE 1628
#define LANG_FILE 1629
#define KW_HELP 1630
#define HIDE 1631
#define HOUR 1632
#define INTO 1633
#define KW_LAST 1634
#define KW_LEFT 1635
#define LIKE 1636
#define MAIN 1637
#define MENU 1638
#define MODE 1639
#define NEED 1640
#define KW_NEXT 1641
#define NOCR 1642
#define OPEN 1643
#define QUIT 1644
#define REAL 1645
#define ROWS 1646
#define SHOW 1647
#define KW_SIZE 1648
#define SKIP 1649
#define SOME 1650
#define STEP 1651
#define STOP 1652
#define TEMP 1653
#define KW_TEXT 1654
#define THEN 1655
#define USER 1656
#define WAIT 1657
#define WHEN 1658
#define WITH 1659
#define WORK 1660
#define YEAR 1661
#define KW_DOW 1662
#define KW_IS 1663
#define XSET 1664
#define ADD 1665
#define ALL 1666
#define KW_AND 1667
#define ANY 1668
#define ASC 1669
#define AVG 1670
#define COLON 1671
#define KW_COMMA 1672
#define DAY 1673
#define DBA 1674
#define DEC 1675
#define DIM 1676
#define KW_FKEY 1677
#define FOR 1678
#define KEY 1679
#define KWNO 1680
#define LET 1681
#define LOG 1682
#define XMAX 1683
#define XMIN 1684
#define MINUS 1685
#define MOD 1686
#define NOT 1687
#define PAD 1688
#define PUT 1689
#define RED 1690
#define ROW 1691
#define KW_RUN 1692
#define SQL 1693
#define SUM 1694
#define TOP 1695
#define USE 1696
#define ATSIGN 1697
#define PLUS 1698
#define AS_TIFF 1699
#define AS_GIF 1700
#define AS_PNG 1701
#define AS_JPEG 1702
#define AS 1703
#define AT 1704
#define BY 1705
#define DOT 1706
#define GO 1707
#define IF 1708
#define KW_IN 1709
#define OF 1710
#define KW_ON 1711
#define KW_OR 1712
#define TO 1713
#define KWUP 1714
#define FONT_NAME 1715
#define FONT_SIZE 1716
#define PAPER_SIZE_IS_LETTER 1717
#define PAPER_SIZE_IS_LEGAL 1718
#define PAPER_SIZE_IS_A5 1719
#define PAPER_SIZE_IS_A4 1720
#define PAPER_SIZE_IS_LETTER_L 1721
#define PAPER_SIZE_IS_LEGAL_L 1722
#define PAPER_SIZE_IS_A5_L 1723
#define PAPER_SIZE_IS_A4_L 1724
#define FORMHANDLER 1725
#define END_FORMHANDLER 1726
#define BEFORE_EVENT 1727
#define BEFORE_OPEN_FORM 1728
#define AFTER_EVENT 1729
#define BEFORE_CLOSE_FORM 1730
#define BEFORE_ANY 1731
#define AFTER_ANY 1732
#define MENUHANDLER 1733
#define END_MENUHANDLER 1734
#define BEFORE_SHOW_MENU 1735
#define DISABLE_PROGRAM 1736
#define DISABLE_ALL 1737
#define BUTTONS 1738
#define CHECK_MENUITEM 1739
#define DISABLE_FORM 1740
#define DISABLE_MENUITEMS 1741
#define DISABLE 1742
#define ENABLE_FORM 1743
#define ENABLE_MENUITEMS 1744
#define ENABLE 1745
#define KWFIELD 1746
#define ICON 1747
#define MESSAGEBOX 1748
#define TO_DEFAULTS 1749
#define UNCHECK_MENUITEM 1750
#define ABSOLUTE 1751
#define BEFORE 1752
#define KW_INPUT 1753
#define FINPUT 1754
#define END 1755
#define INT_TO_ID 1756
#define TIMEOUT 1757
#define KW_OFF 1758
#define WITH_1_DIMENSION 1759
#define WITH_2_DIMENSION 1760
#define WITH_3_DIMENSION 1761
#define TILDE 1762
#define ILIKE 1763
#define FGL_ISDYNARR_ALLOCATED 1764
#define FGL_DYNARR_EXTENTSIZE 1765
#define FILLFACTOR 1766
#define END_CLASS 1767
#define KW_CLASS 1768
#define EXTENDS 1769
#define KW_PIPE 1770
#define TIME 1771
#define KWBEGIN 1772
#define TRACE 1773
#define SITENAME 1774
#define DBSERVERNAME 1775
#define SYSTEM 1776
#define EXCEPTION 1777
#define KW_TODAY 1778
#define PGKW_ABORT_P 1779
#define PGKW_ABSOLUTE_P 1780
#define PGKW_ACCESS 1781
#define PGKW_ACTION 1782
#define PGKW_ADD 1783
#define PGKW_AFTER 1784
#define PGKW_AGGREGATE 1785
#define PGKW_ALL 1786
#define PGKW_ALTER 1787
#define PGKW_ANALYSE 1788
#define PGKW_ANALYZE 1789
#define PGKW_AND 1790
#define PGKW_ANY 1791
#define PGKW_ARRAY 1792
#define PGKW_AS 1793
#define PGKW_ASC 1794
#define PGKW_ASSERTION 1795
#define PGKW_ASSIGNMENT 1796
#define PGKW_AT 1797
#define PGKW_AUTHORIZATION 1798
#define PGKW_BACKWARD 1799
#define PGKW_BCONST 1800
#define PGKW_BEFORE 1801
#define PGKW_BEGIN_P 1802
#define PGKW_BETWEEN 1803
#define PGKW_BIGINT 1804
#define PGKW_BINARY 1805
#define PGKW_BIT 1806
#define PGKW_BOOLEAN_P 1807
#define PGKW_BOTH 1808
#define PGKW_BY 1809
#define PGKW_CACHE 1810
#define PGKW_CALLED 1811
#define PGKW_CARAT 1812
#define PGKW_CASCADE 1813
#define PGKW_CASE 1814
#define PGKW_CAST 1815
#define PGKW_CHAIN 1816
#define PGKW_CHARACTER 1817
#define PGKW_CHARACTERISTICS 1818
#define PGKW_CHAR_P 1819
#define PGKW_CHECK 1820
#define PGKW_CHECKPOINT 1821
#define PGKW_CLASS 1822
#define PGKW_CLOSE 1823
#define PGKW_CLOSE_BRACKET 1824
#define PGKW_CLOSE_SQUARE 1825
#define PGKW_CLUSTER 1826
#define PGKW_COALESCE 1827
#define PGKW_COLLATE 1828
#define PGKW_COLON 1829
#define PGKW_COLUMN 1830
#define PGKW_COMMA 1831
#define PGKW_COMMENT 1832
#define PGKW_COMMIT 1833
#define PGKW_COMMITTED 1834
#define PGKW_CONSTRAINT 1835
#define PGKW_CONSTRAINTS 1836
#define PGKW_CONVERSION_P 1837
#define PGKW_CONVERT 1838
#define PGKW_COPY 1839
#define PGKW_CREATE 1840
#define PGKW_CREATEDB 1841
#define PGKW_CREATEUSER 1842
#define PGKW_CROSS 1843
#define PGKW_CURRENT 1844
#define PGKW_CURRENT_DATE 1845
#define PGKW_CURRENT_TIME 1846
#define PGKW_CURRENT_TIMESTAMP 1847
#define PGKW_CURRENT_USER 1848
#define PGKW_CURSOR 1849
#define PGKW_CYCLE 1850
#define PGKW_DATABASE 1851
#define PGKW_DATETIME 1852
#define PGKW_DAY_P 1853
#define PGKW_DBA 1854
#define PGKW_DEALLOCATE 1855
#define PGKW_DEC 1856
#define PGKW_DECIMAL_P 1857
#define PGKW_DECLARE 1858
#define PGKW_DEFAULT 1859
#define PGKW_DEFAULTS 1860
#define PGKW_DEFERRABLE 1861
#define PGKW_DEFERRED 1862
#define PGKW_DEFINER 1863
#define PGKW_DELETE_P 1864
#define PGKW_DELIMITER 1865
#define PGKW_DELIMITERS 1866
#define PGKW_DESC 1867
#define PGKW_DISTINCT 1868
#define PGKW_DIVIDE 1869
#define PGKW_DO 1870
#define PGKW_DOMAIN_P 1871
#define PGKW_DOT 1872
#define PGKW_DOUBLE_P 1873
#define PGKW_DROP 1874
#define PGKW_EACH 1875
#define PGKW_ELSE 1876
#define PGKW_ENCODING 1877
#define PGKW_ENCRYPTED 1878
#define PGKW_END_P 1879
#define PGKW_EQUAL 1880
#define PGKW_ESCAPE 1881
#define PGKW_EXCEPT 1882
#define PGKW_EXCLUDING 1883
#define PGKW_EXCLUSIVE 1884
#define PGKW_EXECUTE 1885
#define PGKW_EXISTS 1886
#define PGKW_EXPLAIN 1887
#define PGKW_EXTEND 1888
#define PGKW_EXTERNAL 1889
#define PGKW_EXTRACT 1890
#define PGKW_FALSE_P 1891
#define PGKW_FETCH 1892
#define PGKW_FIRST_P 1893
#define PGKW_FLOAT_P 1894
#define PGKW_FOR 1895
#define PGKW_FORCE 1896
#define PGKW_FOREIGN 1897
#define PGKW_FORWARD 1898
#define PGKW_FREEZE 1899
#define PGKW_FROM 1900
#define PGKW_FULL 1901
#define PGKW_FUNCTION 1902
#define PGKW_GLOBAL 1903
#define PGKW_GRANT 1904
#define PGKW_GREATER_THAN 1905
#define PGKW_GROUP_P 1906
#define PGKW_HANDLER 1907
#define PGKW_HAVING 1908
#define PGKW_HOLD 1909
#define PGKW_HOUR_P 1910
#define PGKW_ILIKE 1911
#define PGKW_IMMEDIATE 1912
#define PGKW_IMMUTABLE 1913
#define PGKW_IMPLICIT_P 1914
#define PGKW_INCLUDING 1915
#define PGKW_INCREMENT 1916
#define PGKW_INDEX 1917
#define PGKW_INHERITS 1918
#define PGKW_INITIALLY 1919
#define PGKW_INNER_P 1920
#define PGKW_INOUT 1921
#define PGKW_IN_P 1922
#define PGKW_INPUT_P 1923
#define PGKW_INSENSITIVE 1924
#define PGKW_INSERT 1925
#define PGKW_INSTEAD 1926
#define PGKW_INTEGER 1927
#define PGKW_INTERSECT 1928
#define PGKW_INTERVAL 1929
#define PGKW_INTO 1930
#define PGKW_INT_P 1931
#define PGKW_INVOKER 1932
#define PGKW_IS 1933
#define PGKW_ISNULL 1934
#define PGKW_ISOLATION 1935
#define PGKW_JOIN 1936
#define PGKW_KEY 1937
#define PGKW_LANCOMPILER 1938
#define PGKW_LANGUAGE 1939
#define PGKW_LAST_P 1940
#define PGKW_LEADING 1941
#define PGKW_LEFT 1942
#define PGKW_LESS_THAN 1943
#define PGKW_LEVEL 1944
#define PGKW_LIKE 1945
#define PGKW_LIMIT 1946
#define PGKW_LISTEN 1947
#define PGKW_LOAD 1948
#define PGKW_LOCAL 1949
#define PGKW_LOCALTIME 1950
#define PGKW_LOCALTIMESTAMP 1951
#define PGKW_LOCATION 1952
#define PGKW_LOCK_P 1953
#define PGKW_MATCH 1954
#define PGKW_MAXVALUE 1955
#define PGKW_MINUS 1956
#define PGKW_MINUTE_P 1957
#define PGKW_MINVALUE 1958
#define PGKW_MODE 1959
#define PGKW_MODIFY 1960
#define PGKW_MONTH_P 1961
#define PGKW_MOVE 1962
#define PGKW_NAMES 1963
#define PGKW_NATIONAL 1964
#define PGKW_NATURAL 1965
#define PGKW_NCHAR 1966
#define PGKW_NEW 1967
#define PGKW_NEXT 1968
#define PGKW_NO 1969
#define PGKW_NOCREATEDB 1970
#define PGKW_NOCREATEUSER 1971
#define PGKW_NONE 1972
#define PGKW_NOT 1973
#define PGKW_NOTHING 1974
#define PGKW_NOTIFY 1975
#define PGKW_NOTNULL 1976
#define PGKW_NULLIF 1977
#define PGKW_NULL_P 1978
#define PGKW_NUMERIC 1979
#define PGKW_OF 1980
#define PGKW_OFF 1981
#define PGKW_OFFSET 1982
#define PGKW_OIDS 1983
#define PGKW_OLD 1984
#define PGKW_ON 1985
#define PGKW_ONLY 1986
#define PGKW_OPEN_BRACKET 1987
#define PGKW_OPEN_SQUARE 1988
#define PGKW_OPERATOR 1989
#define PGKW_OPTION 1990
#define PGKW_OR 1991
#define PGKW_ORDER 1992
#define PGKW_OUTER_P 1993
#define PGKW_OUT_P 1994
#define PGKW_OVERLAPS 1995
#define PGKW_OVERLAY 1996
#define PGKW_OWNER 1997
#define PGKW_PARAM 1998
#define PGKW_PARTIAL 1999
#define PGKW_PASSWORD 2000
#define PGKW_PATH_P 2001
#define PGKW_PENDANT 2002
#define PGKW_PERCENT 2003
#define PGKW_PLACING 2004
#define PGKW_PLUS 2005
#define PGKW_POSITION 2006
#define PGKW_POSTFIXOP 2007
#define PGKW_PRECISION 2008
#define PGKW_PREPARE 2009
#define PGKW_PRESERVE 2010
#define PGKW_PRIMARY 2011
#define PGKW_PRIOR 2012
#define PGKW_PRIVILEGES 2013
#define PGKW_PROCEDURAL 2014
#define PGKW_PROCEDURE 2015
#define PGKW_READ 2016
#define PGKW_REAL 2017
#define PGKW_RECHECK 2018
#define PGKW_REFERENCES 2019
#define PGKW_REINDEX 2020
#define PGKW_RELATIVE_P 2021
#define PGKW_RENAME 2022
#define PGKW_REPLACE 2023
#define PGKW_RESET 2024
#define PGKW_RESTART 2025
#define PGKW_RESTRICT 2026
#define PGKW_RETURNS 2027
#define PGKW_REVOKE 2028
#define PGKW_RIGHT 2029
#define PGKW_ROLLBACK 2030
#define PGKW_ROW 2031
#define PGKW_ROWS 2032
#define PGKW_RULE 2033
#define PGKW_SCHEMA 2034
#define PGKW_SCROLL 2035
#define PGKW_SECOND_P 2036
#define PGKW_SECURITY 2037
#define PGKW_SELECT 2038
#define PGKW_SEMICOLON 2039
#define PGKW_SEQUENCE 2040
#define PGKW_SERIALIZABLE 2041
#define PGKW_SESSION 2042
#define PGKW_SESSION_USER 2043
#define PGKW_SET 2044
#define PGKW_SETOF 2045
#define PGKW_SHARE 2046
#define PGKW_SHOW 2047
#define PGKW_SIMILAR 2048
#define PGKW_SIMPLE 2049
#define PGKW_SMALLINT 2050
#define PGKW_SOME 2051
#define PGKW_STABLE 2052
#define PGKW_STAR 2053
#define PGKW_START 2054
#define PGKW_STATEMENT 2055
#define PGKW_STATISTICS 2056
#define PGKW_STDIN 2057
#define PGKW_STDOUT 2058
#define PGKW_STORAGE 2059
#define PGKW_STRICT_P 2060
#define PGKW_SUBSTRING 2061
#define PGKW_SYSID 2062
#define PGKW_TABLE 2063
#define PGKW_TEMP 2064
#define PGKW_TEMPLATE 2065
#define PGKW_TEMPORARY 2066
#define PGKW_THEN 2067
#define PGKW_TIME 2068
#define PGKW_TIMESTAMP 2069
#define PGKW_TO 2070
#define PGKW_TOAST 2071
#define PGKW_TODAY_SYN 2072
#define PGKW_TRAILING 2073
#define PGKW_TRANSACTION 2074
#define PGKW_TREAT 2075
#define PGKW_TRIGGER 2076
#define PGKW_TRIM 2077
#define PGKW_TRUE_P 2078
#define PGKW_TRUNCATE 2079
#define PGKW_TRUSTED 2080
#define PGKW_TYPECAST 2081
#define PGKW_TYPE_P 2082
#define PGKW_UMINUS 2083
#define PGKW_UNENCRYPTED 2084
#define PGKW_UNION 2085
#define PGKW_UNIONJOIN 2086
#define PGKW_UNIQUE 2087
#define PGKW_UNKNOWN 2088
#define PGKW_UNLISTEN 2089
#define PGKW_UNLOAD 2090
#define PGKW_UNTIL 2091
#define PGKW_UPDATE 2092
#define PGKW_USAGE 2093
#define PGKW_USER 2094
#define PGKW_USING 2095
#define PGKW_VACUUM 2096
#define PGKW_VALID 2097
#define PGKW_VALIDATOR 2098
#define PGKW_VALUES 2099
#define PGKW_VARCHAR 2100
#define PGKW_VARYING 2101
#define PGKW_VERBOSE 2102
#define PGKW_VERSION 2103
#define PGKW_VIEW 2104
#define PGKW_VOLATILE 2105
#define PGKW_WHEN 2106
#define PGKW_WHERE 2107
#define PGKW_WITH 2108
#define PGKW_WITHOUT 2109
#define PGKW_WORK 2110
#define PGKW_WRITE 2111
#define PGKW_XCONST 2112
#define PGKW_YEAR_P 2113
#define PGKW_ZONE 2114
#define KW_TITLE 2115
#define KW_STYLE 2116
#define KW_ACTION 2117
#define KW_IDLE 2118
#define CANCEL_INSERT 2119
#define CANCEL_DELETE 2120
