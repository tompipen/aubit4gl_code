main
	define b integer
	call external localhost:inc_by_1[1] (1) returning b
	display "CLIENT : 1+1 =",b
	call external localhost:inc_by_2[1] (1) returning b
	display "CLIENT : 1+2 =",b
	call external localhost:all_done[1]()
	
end main
