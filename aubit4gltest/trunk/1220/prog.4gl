database test1

main
define a,b,c char(10)

#display "create temp table..."
	create temp table t1 ( 
		a char(10),
		b char(10)
	)
#display "insert..."
	insert into t1 values ("Hello","World")

#display "One to few"
	initialize a,b,c to null
	select * into a from t1
	call dodisplay(a,b,c)

#display "perfect"
	initialize a,b,c to null
	select * into a,b from t1
	call dodisplay(a,b,c)

#display "One to many"
	initialize a,b,c to null
	select * into a,b,c from t1
	call dodisplay(a,b,c)
#display "end."
end main
 
function dodisplay(a,b,c)
define a,b,c char(10)
define lv_str char(80)
	let lv_str=""
	if a is null then
		let lv_str=lv_str clipped,"A (NULL)"
	else
		let lv_str=lv_str clipped,"A:",a
	end if
	
	
	if b is null then
		let lv_str=lv_str clipped," B (NULL)"
	else
		let lv_str=lv_str clipped," B:",b
	end if
	
	
	if c is null then
		let lv_str=lv_str clipped," C (NULL)"
	else
		let lv_str=lv_str clipped," C:",c
	end if
	display lv_Str clipped
end function


