

main
	define l_col varchar(40)

	let l_col='yellow'
	display "Hello" at 1,1 attribute(l_col)
	let l_col='cyan'
	#open window w1 at 4,5 with 6 rows,20 columns attribute(yellow,border)
	open window w1 at 4,5 with 6 rows,20 columns attribute(l_col,border)
	display "Hello" at 2,2
end main
