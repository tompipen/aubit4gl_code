
m.4ae: m.4gl
	$(FGLC) m.4gl -o m.4ae
	fcompile m.per

compile: m.4ae
	
run: m.4ae
	sh ./run_m
	
clean:
	rm -f  m.log.expected.nodate  m.log.nodate
	
	

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

