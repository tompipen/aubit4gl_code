{!
PRAGMA SQL FEATURE SELECT_FIRST
!}
DATABASE test1

MAIN

DEFINE l_f2 CHAR(10)
    CREATE TEMP TABLE testfirst (campo1 int, campo2 char(10))
    INSERT INTO testfirst VALUES (1, "a")
    INSERT INTO testfirst VALUES (1, "b")
    LET l_f2="NOTSET"
    SQL
    	SELECT FIRST 1 campo2 INTO $l_f2 FROM testfirst WHERE campo1 = 1
    END SQL
    DISPLAY "f2=", l_f2
	
END MAIN

