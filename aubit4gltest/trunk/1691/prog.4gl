{**
 * @file
 * using in open fails with pg8
 * @process TEST_GENERAL
 *}
 
database test1
main
define w_sql char(100),
       w_id, w_a int,
       w_b char(10)
create temp table a_table (a int, b char(10))
insert into a_table values (1,"a")
insert into a_table values (2,"b")
let w_sql = "select a, b from a_table where a = ?"
let w_id = 1
prepare p_sql from w_sql
declare c_cur cursor for p_sql
open c_cur using w_id
foreach c_cur into w_a, w_b
    display w_a, w_b
end foreach
if w_a = 1 and w_b = "a" then exit program 0
else                          exit program 1
end if
end main
