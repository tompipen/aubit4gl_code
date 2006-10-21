prompt.4ae: prompt.4gl
	${FGLC} prompt.4gl -o prompt.4ae
	fcompile prompt.per

compile: prompt.4ae 
	
run: prompt.4ae
	sh ./run_prompt

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

