

g1.4ae: g1.4gl
	$(FGLC) g1.4gl -o g1.4ae
	fcompile g1.per

compile: g1.4ae
	
run: g1.4ae
	sh ./run_g1
	
clean:
	rm -f arr.out.nodate
	

ansi_sql_compat:
	@echo "1"

