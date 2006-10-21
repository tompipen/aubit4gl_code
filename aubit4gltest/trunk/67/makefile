

fgldb.4ae: fgldb.4gl
	$(FGLC) fgldb.4gl -o fgldb.4ae

compile: fgldb.4ae
	
run: fgldb.4ae
	sh ./run_fgldb

ansi_sql_compat:
	@echo "1"


sql_features_used:		; @echo "DATABASE_USED DEFINE_CHAR DEFINE_SMALLINT DEFINE_INTEGER USES_FORM UI_DISPLAY_FORM CREATE_TEMP_TABLE ANSI_INSERT UI_CONSTRUCT MESSAGE EXIT_CONSTRUCT EXIT_PROGRAM_EXPR PREPARE CURSOR_SELECT FOREACH IF CLOSE_FORM "

