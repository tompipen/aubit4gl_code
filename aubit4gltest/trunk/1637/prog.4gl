{**
 * @file
 * MID 997. gracefull exit if cursor is unavailable
 * @process TEST_GENERAL
 *}
 
database test1
define lv_date date, lv_int int
main
create temp table paso( id int, dt date)
call fun2()
end main

function fun1()
declare c_cur cursor for select * from paso where id = lv_int 
end function

function fun2()
foreach c_cur
end foreach
end function
