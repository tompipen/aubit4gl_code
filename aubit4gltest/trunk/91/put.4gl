database test1
define abc record
	a integer,
	b char(20)
end record


main

	let abc.a=1
	let abc.b="Hello"

	create temp table t_abc (a integer, b char(20))

	prepare p1 from "insert into t_abc values(?,?)"

	declare c_ins cursor for p1

	open c_ins

	put c_ins from abc.*

	let abc.a=abc.a+1

	put c_ins from abc.*
	close c_ins

	initialize abc.* to null
	declare c1 cursor for select * from t_abc
	foreach c1 into abc.*
		display abc.a," ",abc.b
	end foreach

end main
