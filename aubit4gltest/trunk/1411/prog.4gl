DATABASE test1

MAIN

DEFINE w_a1, w_a2 INT,
       w_b1, w_b2 CHAR(3)

CREATE TEMP TABLE aliassub (a int, b char(7) )
INSERT INTO aliassub VALUES (1, "aaa BBB")
INSERT INTO aliassub VALUES (11, "bbb BBB")
INSERT INTO aliassub VALUES (12, "ccc CCC")
INSERT INTO aliassub VALUES (13, "ddd DDD")
DECLARE c_curs CURSOR FOR
    SELECT t1.a, t2.a, t1.b[1,3], t2.b[5,7]
        FROM aliassub t1, aliassub t2
            WHERE t2.a between t1.a * 10 AND t1.a * 10 + 9

FOREACH c_curs INTO w_a1, w_a2, w_b1, w_b2
    DISPLAY w_a1, w_a2, " ", w_b1, " ", w_b2
END FOREACH

END MAIN
