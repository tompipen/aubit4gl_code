
%.ao : %.4gl
	4glpc  -c $<

open_window: open_window.ao
	4glpc open_window.ao -o $@

clean:
	-- rm *.o *.ao open_window *.log *.c
