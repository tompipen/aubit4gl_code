DATABASE test1
MAIN
    DEFINE w_f2 datetime year to minute
    CREATE TEMP TABLE testupdate (f1 int, f2 datetime year to minute,
                                f3 char(4))
    INSERT INTO testupdate VALUES (1, "2000-01-01 01:01", "data")
    LET w_f2 = CURRENT
    UPDATE testupdate SET f2 = w_f2, f3 = "new" WHERE f1  = 1
    SELECT f2 INTO w_f2 FROM testupdate WHERE f1 = 1
    DISPLAY "f2=", w_f2
END MAIN
