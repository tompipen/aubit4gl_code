
%.ao : %.4gl
	4glpc  -c $<

message: message.ao
	4glpc message.ao -o $@

clean:
	-- rm *.o *.ao message *.log *.c
