
%.ao : %.4gl
	4glpc  -c $<

prompt: prompt.ao 
	4glpc prompt.ao -o $@

clean:
	-- rm *.o *.ao *.afr.dat prompt *.log *.c
