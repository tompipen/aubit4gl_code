database test1
main
define a_var char(10)
define b integer
	let b=1
	create temp table t1 (
		col_a char(10)
	)
	
	insert into t1 values("Hello")
	insert into t1 values("World")
	
	let a_var=""
	declare acur cursor for
	select col_a into a_var from t1
	
	foreach acur #instead of 'foreach acur into a_var'
		display a_var,":"  #shows null
		display b
	end foreach
	
end main


