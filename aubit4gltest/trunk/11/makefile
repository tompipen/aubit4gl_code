
scr.4ae: scr.4gl
	${FGLC} scr.4gl -o scr.4ae
	fcompile x.per
	fcompile y.per

compile: scr.4ae
	
run: scr.4ae
	sh ./run_scr

ansi_sql_compat:
	@echo "1"
desc:
	@echo "Basic UI exercising"

sql_features_used:			; @echo "DATABASE_USED DEFINE_LIKE DDL_DECIMAL DDL_DATE DDL_MONEY DDL_DATETIME CREATE_TEMP_TABLE ANSI_INSERT ANSI_DELETE DROP_TABLE DEFINE_CHAR DEFINE_SMALLINT DEFINE_INTEGER DEFINE_FLOAT DEFINE_DECIMAL DEFINE_DATE DEFINE_MONEY DEFINE_DATETIME STATUS IF UI_DISPLAY_LINE_MODE DISPLAY "

