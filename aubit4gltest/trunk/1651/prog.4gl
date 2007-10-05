{**
 * @file
 * Basic serial8 usage
 * @process TEST_GENERAL
 *}
 
database test1

main
define lv_a int8, lv_b char(1)
create temp table ser8 (a serial8 (1234567890),b char(1))
insert into ser8 values (0, "x")
select * into lv_a, lv_b from ser8
if lv_a <> 1234567890 then display "bad ", lv_a exit program 1 end if
exit program 0
end main
