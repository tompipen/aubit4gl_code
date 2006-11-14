m1.4ae: m1.4gl m1.per
	${FGLC} m1.4gl -o m1.4ae
	fcompile m1.per

compile: m1.4ae 
	
run: m1.4ae
	sh ./run_m1

ansi_sql_compat:
	@echo "1"

desc:
	@echo "INPUT from a wordwrap field"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW   FIRST_PAGE_HEADER"

