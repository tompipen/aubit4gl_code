
%.ao : %.4gl
	4glpc  -c $<

%.afr.dat : %.per
	fcompile $<

input_array: input_array.ao my_form.afr.dat
	4glpc input_array.ao -o $@

clean:
	-- rm *.o *.ao *.afr.dat input_array *.log *.c
