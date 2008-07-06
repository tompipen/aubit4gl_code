
%.ao : %.4gl
	4glpc  -c $<

attributes: attributes.ao
	4glpc attributes.ao -o $@

clean:
	-- rm *.o *.ao attributes *.log *.c
