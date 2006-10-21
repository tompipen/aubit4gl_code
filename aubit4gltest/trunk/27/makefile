
arr3b.4ae: arr3b.4gl
	${FGLC} arr3b.4gl -o arr3b.4ae
	fcompile arr3b.per

compile: arr3b.4ae
	
run: arr3b.4ae
	sh ./run_arr3b

ansi_sql_compat:
	@echo "1"


desc:
	@echo "before field/next field in an input"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW "

