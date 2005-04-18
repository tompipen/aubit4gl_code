database test1

main
	define rm record
		g1 char(4),
		g2 date,
		g3 dec(8,2)
		end record

define lv_y date
	create temp table t1(f1 char(4),f2 date)
let lv_y=mdy(1,1,2000)
	insert into t1 values('1',lv_y)
let lv_y=mdy(1,1,2001)
	insert into t1 values('2',lv_y)
let lv_y=mdy(1,1,2002)
	insert into t1 values('3',lv_y)
let lv_y=mdy(1,1,2003)
	insert into t1 values('4',lv_y)
let lv_y=mdy(1,1,2004)
	insert into t1 values('5',lv_y)



	create temp table t2(g1 char(4),g2 date,g3 dec(8,2))
let lv_y=mdy(6,30,2004)
	insert into t2 values('1',lv_y,1.23)
let lv_y=mdy(7,30,2004)
	insert into t2 values('2',lv_y,2.34)
let lv_y=mdy(8,30,2004)
	insert into t2 values('3',lv_y,3.45)
let lv_y=mdy(9,30,2004)
	insert into t2 values('4',lv_y,4.56)
let lv_y=mdy(10,30,2004)
	insert into t2 values('5',lv_y,5.67)
let lv_y=mdy(11,30,2004)
	insert into t2 values('5',lv_y,6.78)

	declare cc cursor for select t2.*
		from t1,t2
		where t1.f1=t2.g1
		  and year(t1.f2)>2001

	foreach cc into rm
		display 'HERE    ',rm.g1,' ',rm.g2 using "dd mmm yyyy",' ',rm.g3
	end foreach

	select t2.* from t1,t2
		where t1.f1=t2.g1
		  and year(t1.f2)>2001
		into temp a

	unload to "unl" select * from a

end main
