test_267.4ae: test_267.4gl
	${FGLC} -g test_267.4gl -o test_267.4ae
	fcompile test_267.per

compile: test_267.4ae

run: compile
	sh run_test_267
	

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

