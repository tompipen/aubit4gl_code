
rep.4ae: rep.4gl
	${FGLC} rep.4gl -o rep.4ae

compile: rep.4ae

run: rep.4ae
	sh ./run_rep

ansi_sql_compat:
	@echo "1"

desc:
	@echo "Pretty empty report"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW "

