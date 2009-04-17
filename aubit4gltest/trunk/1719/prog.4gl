main
	define a float
define b float
	let a=0.0000000000000056456565
	let b=a*1000000000000000.0
	display b

	if a=0 then
		## Bad...
		display "a=0"
		exit program 1
	else
		## Good...
		display "A!=0"
		exit program 0
	end if
end main
