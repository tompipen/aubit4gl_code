ibt.4ae: ibt.4gl
	${FGLC} ibt.4gl -o ibt.4ae
	fcompile ibt.per

compile: ibt.4ae
	
run: ibt.4ae
	sh ./run_ibt
	
clean:
	rm -f ibt.out.nodate


ansi_sql_compat:
	@echo "1"

