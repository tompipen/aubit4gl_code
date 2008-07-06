
%.ao : %.4gl
	4glpc  -c $<

display_form: display_form.ao
	4glpc display_form.ao -o $@

clean:
	-- rm *.o *.ao display_form *.log *.c
