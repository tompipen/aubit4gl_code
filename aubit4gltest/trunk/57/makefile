
ia.4ae: ia.4gl ia.per
	$(FGLC) ia.4gl -o ia.4ae
	fcompile ia.per

compile: ia.4ae
	
run: ia.4ae
	sh ./run_ia

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

