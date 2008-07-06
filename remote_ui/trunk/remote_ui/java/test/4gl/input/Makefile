
%.ao : %.4gl
	4glpc  -c $<

%.afr.dat : %.per
	fcompile $<

input: input.ao my_form.afr.dat
	4glpc input.ao -o $@

clean:
	-- rm *.o *.ao *.afr.dat input *.log *.c
