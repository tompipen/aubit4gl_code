



ui_contrl.4ae: ui_contrl.4gl form.per
	${FGLC} ui_contrl.4gl -o ui_contrl.4ae
	fcompile form.per

compile: ui_contrl.4ae
	
run: ui_contrl.4ae
	sh ./run_ui_contrl

ansi_sql_compat:
	@echo "1"


desc:
	@echo "Simple combination of UI commands"

sql_features_used:			; @echo "DATABASE_USED DEFINE_LIKE DDL_DECIMAL DDL_DATE DDL_MONEY DDL_DATETIME CREATE_TEMP_TABLE ANSI_INSERT ANSI_DELETE DROP_TABLE DEFINE_CHAR DEFINE_SMALLINT DEFINE_INTEGER DEFINE_FLOAT DEFINE_DECIMAL DEFINE_DATE DEFINE_MONEY DEFINE_DATETIME STATUS IF UI_DISPLAY_LINE_MODE DISPLAY "

