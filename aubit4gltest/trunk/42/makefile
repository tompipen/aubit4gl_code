test_265.4ae: test_265.4gl
	${FGLC} -g test_265.4gl -o test_265.4ae
	fcompile test_265.per

compile: test_265.4ae

run: compile
	sh run_test_265
	
clean:
	rm -f test_265.log.nodate




ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

