ibt.4ae: ibt.4gl
	${FGLC} ibt.4gl -o ibt.4ae
	fcompile ibt.per

compile: ibt.4ae
	
run: ibt.4ae
	sh ./run_ibt
	
clean:
	rm -f ibt.out.nodate


ansi_sql_compat:
	@echo "1"

desc:
	@echo  "Fairly comprehensive Input test"

sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_INTEGER IFX_SYSTABLES CURSOR_SELECT USE_REPORT FOREACH UI_DISPLAY_LINE_MODE DISPLAY IF EXIT_PROGRAM_EXPR REPORT_ORDER_BY REPORT_FIRST_PAGE_HEADER ON_EVERY_ROW   FIRST_PAGE_HEADER"

