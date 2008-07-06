
%.ao : %.4gl
	4glpc  -c $<

current_window: current_window.ao
	4glpc current_window.ao -o $@

clean:
	-- rm *.o *.ao current_window *.log *.c
