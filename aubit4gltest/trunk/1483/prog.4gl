DATABASE 'test1'

MAIN

DEFINE
   i INT,
   v char(50)

CREATE TEMP TABLE tmp_tst (
    id int,
    val char(50)
    )

CREATE TEMP TABLE tmp_tst2 (
    id int,
    val char(50)
    )


INSERT INTO tmp_tst VALUES (1, 'test')
INSERT INTO tmp_tst VALUES (2, 'test2')

INSERT INTO tmp_tst2 VALUES (3, 'test3')
INSERT INTO tmp_tst2 VALUES (4, 'test4')

### crash here
INSERT INTO tmp_tst SELECT id, val FROM tmp_tst2
### crash here

DECLARE curs CURSOR FOR select id, val FROM tmp_tst

FOREACH curs INTO i, v
    DISPLAY i USING "<<<<<<<", " => ", v CLIPPED
END FOREACH

DROP TABLE tmp_tst
DROP TABLE tmp_tst2


END MAIN

