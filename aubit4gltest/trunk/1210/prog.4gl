DATABASE test1
MAIN
DEFINE m MONEY, d DECIMAL, i INT, s SMALLINT, f CHAR(12)
#LET f = "out.expected"
LET f = "out"
START REPORT pru_rp TO FILE f
LET m = -.01
LET d = -.01
LET i = -1
LET s = -1
OUTPUT TO REPORT pru_rp(m, d, i, s)
FINISH REPORT pru_rp
END MAIN
REPORT pru_rp(m, d, i, s)
DEFINE m MONEY, d DECIMAL, i INT, s SMALLINT
OUTPUT TOP MARGIN 0 BOTTOM  MARGIN 0 LEFT MARGIN 0 PAGE LENGTH 1
ORDER BY m
FORMAT
    ON EVERY ROW
        PRINT "m=", m USING "---.##", ",d=", d USING "---.##",
              ",i=", i USING "--#", ",s=", s USING "--#"
END REPORT
