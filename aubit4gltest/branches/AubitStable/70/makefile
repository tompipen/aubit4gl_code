

arr3a.4ae: arr3a.4gl
	$(FGLC) arr3a.4gl -o arr3a.4ae
	fcompile arr3a.per

compile: arr3a.4ae
	
run: arr3a.4ae
	sh ./run_arr3a
	
clean:
	rm -f out1
	

ansi_sql_compat:
	@echo "1"

