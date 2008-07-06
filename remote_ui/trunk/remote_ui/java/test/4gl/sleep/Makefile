
%.ao : %.4gl
	4glpc  -c $<

sleep: sleep.ao
	4glpc sleep.ao -o $@ 

clean:
	-- rm *.o *.ao sleep *.log *.c
