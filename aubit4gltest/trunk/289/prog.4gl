DATABASE test1

MAIN

 DEFINE l_parm INT
     CREATE TEMP TABLE testfor (f1 int, f2 char(4))
     INSERT INTO testfor VALUES (1, "1a")
     INSERT INTO testfor VALUES (2, "2a")
     INSERT INTO testfor VALUES (2, "2b")
     DECLARE c_loop CURSOR FOR
         SELECT * FROM testfor WHERE f1 = l_parm
     LET l_parm = 1
     DISPLAY "With parm = ", l_parm
     CALL do_loop()
     LET l_parm = 2
     DISPLAY "With parm = ", l_parm
     CALL do_loop()
END MAIN

 FUNCTION do_loop()
 DEFINE w_f1 INT, w_f2 CHAR(4)
 FOREACH c_loop INTO w_f1, w_f2
     DISPLAY w_f1, w_f2
 END FOREACH
 END FUNCTION
