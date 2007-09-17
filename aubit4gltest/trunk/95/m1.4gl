database test1
main
define lv_cnt integer
define lv_arr array[5] of char(10)
define lv_a integer
define lv_b char(10)

	let lv_arr[1]="Line1"
	let lv_arr[2]="Line2"
	let lv_arr[3]="Line3"
	let lv_arr[4]="Line4"
	let lv_arr[5]="Line5"
	
	create temp table tmp_a1 (a integer, b char(10))
	insert into tmp_a1 values(1,"Hello")
	insert into tmp_a1 values(2,"World")
	
	let lv_cnt=1
	declare c1 cursor for select * from tmp_a1 for update  of b
	
        begin work

	foreach c1
		update tmp_a1 set b=lv_arr[lv_cnt]
			where current of c1
		let lv_cnt=lv_cnt+1
	end foreach

        commit work
	
	
	declare c2 cursor for
		select * from tmp_a1 order by a
	
	foreach c2 into lv_a,lv_b
		display lv_a," ",lv_b
	end foreach
end main


