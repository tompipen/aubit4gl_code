

match.4ae: match.4gl
	$(FGLC) match.4gl -o match.4ae

compile: match.4ae
	
run: match.4ae
	sh ./run_match

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

