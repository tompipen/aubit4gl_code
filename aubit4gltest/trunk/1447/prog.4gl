{**
 * @file
 * Decribe the test here
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
database test1
main
define lv_a integer
define lv_b integer
define b integer

create temp table t_1 (a integer)
create temp table t_2 (a integer)
for b=1 to 10
	insert into t_1 values(b)
	insert into t_2 values(b)
end for


declare c1 cursor for select * from t_1
foreach c1 into lv_a

	declare c2 cursor for select * from t_2 where a=lv_a
	foreach c2 into lv_b
		update t_2 set a=0 where a= lv_a
	end foreach
end foreach


end main
