g1.4ae: g1.4gl g1.per
	${FGLC} g1.4gl -o g1.4ae
	fcompile g1.per

compile: g1.4ae 
	
run: g1.4ae
	sh ./run_g1

ansi_sql_compat:
	@echo "1"

desc:
	@echo "Next field in before row"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW "

