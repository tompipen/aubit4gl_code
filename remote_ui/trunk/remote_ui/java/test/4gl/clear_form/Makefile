
%.ao : %.4gl
	4glpc  -c $<

clear_form: clear_form.ao
	4glpc clear_form.ao -o $@

clean:
	-- rm *.o *.ao clear_form *.log *.c
