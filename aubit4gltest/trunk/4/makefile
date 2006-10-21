

prompt_err.4ae: prompt_err.4gl
	${FGLC} prompt_err.4gl -o prompt_err.4ae

compile: prompt_err.4ae
	
run: prompt_err.4ae
	sh ./run_prompt_err

ansi_sql_compat:
	@echo "1"

desc:
	@echo "Simple PROMPT"

sql_features_used:		; @echo "DATABASE_USED DEFINE_LIKE DDL_DECIMAL DDL_DATE DDL_MONEY DDL_DATETIME CREATE_TEMP_TABLE ANSI_INSERT ANSI_DELETE DROP_TABLE DEFINE_CHAR DEFINE_SMALLINT DEFINE_INTEGER DEFINE_FLOAT DEFINE_DECIMAL DEFINE_DATE DEFINE_MONEY DEFINE_DATETIME STATUS IF UI_DISPLAY_LINE_MODE DISPLAY "

