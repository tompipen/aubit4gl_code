{**
 * @file
 * use of updte set *=lr.* fails with -pg8
 * @process TEST_GENERAL
 *}
 
database test1
main
define lr record like uptest.*,
       lv_b char(1)

let lr.a = 1
let lr.b = "a"
whenever error continue
drop table uptest
create temp table uptest (a int, b char(1))
whenever error stop
insert into uptest values (lr.*)
let lr.b = "b"
update uptest set *=lr.* where a = lr.a
select b into lv_b from uptest
if lv_b <> lr.b then display "bad" exit program 2 end if
end main
