
disp.4ae: disp.4gl disp.per
	${FGLC} disp.4gl -o disp.4ae
	fcompile disp.per

compile: disp.4ae
	
run: disp.4ae
	sh ./run_disp

ansi_sql_compat:
	@echo "1"

desc:
	@echo "Testing for memory corruption (obsolete ?)"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW   FIRST_PAGE_HEADER"

