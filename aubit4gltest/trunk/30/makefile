arr12.4ae: arr12.4gl arr12.per
	${FGLC} arr12.4gl -o arr12.4ae
	fcompile arr12.per

inp.4ae: inp.4gl arr12.per
	${FGLC} inp.4gl -o inp.4ae
	fcompile arr12.per

compile: arr12.4ae inp.4ae
	
run: arr12.4ae  inp.4ae
	sh ./run_arr_and_inp

ansi_sql_compat:
	@echo "1"

desc:
	@echo "Checking field values in before clauses in Input array"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW "

