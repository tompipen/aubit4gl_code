
disp.4ae: disp.4gl disp.per
	${FGLC} disp.4gl -o disp.4ae
	fcompile disp.per

compile: disp.4ae
	
run: disp.4ae
	sh ./run_disp

ansi_sql_compat:
	@echo "1"

