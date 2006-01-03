
main
	define a char(80)
	open window w1 at 2,2 with form "dff" attribute(border)

	let a="01234567890123456789012345678901234567890123456789012345678901234567890123456789"
	#display a to f0

	input a without defaults from f0

	if a!= "ABC34567890123456789012345678901234567890123456789012345678901234567890123456789" then
		display a
		exit program 1
	else
		exit program 0
	end if
end main
