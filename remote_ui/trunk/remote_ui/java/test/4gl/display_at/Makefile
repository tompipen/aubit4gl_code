
%.ao : %.4gl
	4glpc  -c $<

display_at: display_at.ao
	4glpc $+ -o $@

clean:
	-- rm *.o *.ao *.log display_at *.c
