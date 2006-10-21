
testk.4ae: k.4gl
	$(FGLC) k.4gl -o testk.4ae
	fcompile w.per

compile: testk.4ae
	
run: testk.4ae
	sh ./run_testk

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

