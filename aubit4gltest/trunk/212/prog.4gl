
database test1
main
define a record like  dummy.*

	let a.tabname="AAA"
	whenever error continue
	validate a.* like dummy.*
	if status!=0 then
		exit program 1
	end if
	
	
	let a.tabname="CCC"
	whenever error continue
	validate a.* like dummy.*
	if status=0 then
		exit program 2
	end if
	
	exit program 0

end main
