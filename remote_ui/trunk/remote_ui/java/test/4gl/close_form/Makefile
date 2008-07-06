
%.ao : %.4gl
	4glpc  -c $<

close_form: close_form.ao
	4glpc close_form.ao -o $@

clean:
	-- rm *.o *.ao *.log close_form *.c
