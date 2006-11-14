

decdiv.4ae: decdiv.4gl
	$(FGLC) decdiv.4gl -o decdiv.4ae
	$(FGLC) t1.4gl -o t1.4ae

compile: decdiv.4ae
	
run: decdiv.4ae
	sh ./run_decdiv

ansi_sql_compat:
	@echo "1"


sql_features_used:			; @echo "DATABASE_USED USES_FORM CREATE_TEMP_TABLE ANSI_INSERT CURSOR_SELECT DEFINE_CHAR DEFINE_SMALLINT DEFINE_INTEGER DISPLAY_FORM CONSTRUCT MESSAGE EXIT_CONSTRUCT EXIT_PROGRAM_EXPR PREPARE FOREACH IF CLOSE_FORM UI_DISPLAY_FORM UI_CONSTRUCT "

