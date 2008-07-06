
%.ao : %.4gl
	4glpc  -c $<

close_window: close_window.ao
	4glpc close_window.ao -o $@

clean:
	-- rm *.o *.ao *.log close_window *.c
