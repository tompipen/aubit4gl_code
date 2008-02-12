{**
 * @file
 * select with arithmetics syntax error at C compile
 * @process TEST_GENERAL
 *}
 
database test1
main
define w_tipc, a_1, a_2 decimal(10,4)

create temp table abc(d1 decimal(10,4), d2 decimal(10,4))
insert into abc values (1012,2024)

let w_tipc = 10
select d1 / 10, d2 / w_tipc INTO a_1, a_2 from abc

if a_1 <> 101.2 then display "bad1 ", a_1 exit program 1 end if
if a_2 <> 202.4 then display "bad2 ", a_2 exit program 2 end if
end main
