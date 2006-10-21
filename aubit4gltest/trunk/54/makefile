

w.4ae: w.4gl
	$(FGLC) w.4gl -o w.4ae
	fcompile w.per

compile: w.4ae
	
run: w.4ae
	sh ./run_w
	
clean:
	rm -f w.out.nodate
	

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

