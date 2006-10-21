
testdt_null.4ae: testdt_null.4gl
	${FGLC} -g testdt_null.4gl -o testdt_null.4ae

compile: testdt_null.4ae

run: compile
	sh run_testdt_null
	

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

