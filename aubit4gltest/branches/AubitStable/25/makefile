
xrpt.4ae: xrpt.4gl
	${FGLC} xrpt.4gl -o xrpt.4ae

compile: xrpt.4ae
	
run: xrpt.4ae
	sh ./run_xrpt
	
clean:
	rm -f xjunk xok
	

ansi_sql_compat:
	@echo "1"

desc:
	@echo "Another simple report - with page header and page trailer"
