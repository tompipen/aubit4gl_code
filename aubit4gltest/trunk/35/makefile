arith.4ae: arith.4gl
	${FGLC} arith.4gl -o arith.4ae

compile: arith.4ae 
	
run: arith.4ae
	sh ./run_arith

ansi_sql_compat:
	@echo "1"


desc:
	@echo "Check for an early arithmetic bug"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW   FIRST_PAGE_HEADER"

