{**
 * @file
 * FOREACHing a CURSOR DECLAREd from but from FREEd PREPARE  -> segfaults
 * @process TEST_GENERAL
 *}
 

DATABASE test1
MAIN
DEFINE w_id int,
       w_prep CHAR(80)

create temp table mitabla (id int)
insert into mitabla values (1)
let w_prep = "select id from mitabla"
PREPARE ex_prep FROM w_prep
DECLARE c_pend CURSOR FOR ex_prep
FREE ex_prep
FOREACH c_pend INTO w_id 
END FOREACH
FREE c_pend
IF w_id <> 1 THEN DISPLAY "bad",w_id EXIT PROGRAM 1 END IF
DISPLAY "ok"
EXIT PROGRAM 0
END MAIN
