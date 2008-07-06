
%.ao : %.4gl
	4glpc  -c $<

clear_window: clear_window.ao
	4glpc clear_window.ao -o $@

clean:
	-- rm *.o *.ao clear_window *.log *.c
