{**
 * @file
 * WHENEVER ERROR CONTINUE IGNORED if used in a REPORT
 * @process TEST_GENERAL
 *}
 
DATABASE test1
MAIN
DEFINE i SMALLINT
CREATE TEMP TABLE t1680 (id int)
CREATE UNIQUE INDEX u_t1680 ON t1680 (id)
INSERT INTO t1680 VALUES (1)
# If whenever error contnue is set here program runs ok"
START REPORT t1680_repor TO "out"
FOR i = 1 TO 10
    OUTPUT TO REPORT t1680_repor(i)
END FOR
FINISH REPORT t1680_repor
END MAIN

REPORT t1680_repor(h)
DEFINE  h SMALLINT

FORMAT
   ON EVERY ROW
      WHENEVER ERROR CONTINUE  # Here is ignored
      INSERT INTO t1680 VALUES (1) # duplicate value! should be ignored
      WHENEVER ERROR STOP
      PRINT COLUMN   1, "every=", h
END REPORT
