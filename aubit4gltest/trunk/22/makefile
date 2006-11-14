
arr3.4ae: arr3.4gl
	${FGLC} arr3.4gl -o arr3.4ae
	fcompile arr3.per

compile: arr3.4ae
	
run: arr3.4ae
	sh ./run_arr3

ansi_sql_compat:
	@echo "1"


desc:
	@echo "Input array testing"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW   FIRST_PAGE_HEADER"

