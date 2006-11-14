

prompt.4ae: prompt.4gl prompt.per
	${FGLC} prompt.4gl -o prompt.4ae
	fcompile prompt.per


compile: prompt.4ae 
	
run: prompt.4ae
	sh ./run_prompt

ansi_sql_compat:
	@echo "1"


desc:
	@echo "Prompt testing"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW   FIRST_PAGE_HEADER"

