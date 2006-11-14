
p1.4ae: p1.4gl
	${FGLC} p1.4gl -o p1.4ae
	fcompile p1.per

compile: p1.4ae
	
run: p1.4ae
	sh ./run_p1

ansi_sql_compat:
	@echo "1"

desc:
	@echo "input without defaults"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW   FIRST_PAGE_HEADER"

