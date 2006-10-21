
arr3b.4ae: arr3b.4gl
	${FGLC} arr3b.4gl -o arr3b.4ae
	fcompile arr3b.per
	fcompile arr3b_1.per

compile: arr3b.4ae
	
run: arr3b.4ae
	sh ./run_arr3b

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

