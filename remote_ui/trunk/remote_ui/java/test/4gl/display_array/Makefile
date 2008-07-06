
%.ao : %.4gl
	4glpc  -c $<

%.afr.dat : %.per
	fcompile $<

display_array: display_array.ao my_form.afr.dat
	4glpc display_array.ao -o $@

clean:
	-- rm *.o *.ao *.afr.dat proxy.log display_array *.c
