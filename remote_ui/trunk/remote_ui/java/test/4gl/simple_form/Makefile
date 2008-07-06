
%.ao : %.4gl
	4glpc  -c $<

%.afr.dat : %.per
	fcompile $<

simple_form: simple_form.ao my_form.afr.dat
	4glpc simple_form.ao -o $@

clean:
	-- rm *.o *.ao *.afr.dat simple_form *.log *.c
