{
IIRC,
Yes (sort of) - but only if the database has transaction logging on..

If transaction logging is off - it will work (and obviously outside of a transaction)

> Does insert cursor have to be in transaction?
> 
> 	prepare p1 from "insert into t_abc values(?,?)"
> 	declare c_ins cursor for p1
> 	open c_ins
> < -255
> < Err:Program stopped at 'put.4gl', line number 19.
> < Error status number -255.
> < Not in transaction..

}


{! PRAGMA EMULATE INSERT CURSOR FOR c_ins !}
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

        begin work 

	open c_ins

	put c_ins from abc.*

	let abc.a=abc.a+1

	put c_ins from abc.*
	close c_ins

        commit work

	initialize abc.* to null
	declare c1 cursor for select * from t_abc
	foreach c1 into abc.*
		display abc.a," ",abc.b
	end foreach

end main
