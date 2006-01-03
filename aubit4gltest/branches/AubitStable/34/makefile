g1.4ae: g1.4gl g1.per
	${FGLC} g1.4gl -o g1.4ae
	fcompile g1.per

compile: g1.4ae 
	
run: g1.4ae
	sh ./run_g1

ansi_sql_compat:
	@echo "1"

desc:
	@echo "exit input in input array"
