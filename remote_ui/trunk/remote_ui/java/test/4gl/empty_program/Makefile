
%.ao : %.4gl
	4glpc  -c $<

empty_program: empty_program.ao
	4glpc empty_program.ao -o empty_program 

clean:
	-- rm *.o *.ao empty_program *.log *.c
