

decassign.4ae: decassign.4gl
	$(FGLC) decassign.4gl -o decassign.4ae

compile: decassign.4ae
	
run: decassign.4ae
	sh ./run_decassign

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED CREATE_TEMP_TABLE CURSOR_SELECT FOREACH UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR CLOSE_CURSOR DROP_TABLE "

