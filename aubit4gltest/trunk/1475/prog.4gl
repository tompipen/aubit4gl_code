DATABASE test1

MAIN
    DEFINE
        s, v CHAR(50),
        i INT
whenever error continue
drop table tst
whenever error stop

    CREATE TABLE tst (id INTEGER, val CHAR(50))

    LET s = 'TEST'

    INSERT INTO tst(id, val) VALUES (1, s)

    DECLARE c_equals CURSOR FOR SELECT id, val FROM tst WHERE val = 'TEST'
    FOREACH c_equals INTO i, v
        DISPLAY i USING "equals: #", " => ", v CLIPPED
    END FOREACH

    DECLARE c_like CURSOR FOR SELECT id, val FROM tst WHERE val like 'TEST'
    FOREACH c_like INTO i, v
        DISPLAY i USING "like: #", " => ", v CLIPPED
    END FOREACH

END MAIN
