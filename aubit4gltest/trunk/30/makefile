arr12.4ae: arr12.4gl arr12.per
	${FGLC} arr12.4gl -o arr12.4ae
	fcompile arr12.per

inp.4ae: inp.4gl arr12.per
	${FGLC} inp.4gl -o inp.4ae
	fcompile arr12.per

compile: arr12.4ae inp.4ae
	
run: arr12.4ae  inp.4ae
	sh ./run_arr_and_inp
